function bh_virtual_car_camera_sfun(block)
%==========================================================================
% Virtual Camera
%==========================================================================
%     Dialogue PARAMETERS:
%      1.) init_camera_pos - 1x2 matrix, xy in WORLD frame
%      2.) init_veh_THETA  - 1x1 scalar, VEHICLE angle theta_rad relative to WORLD frame
%      3.) height_of_cam   - 1x1 scalar, height of camera wrt VEHICLE frame
%      4.) horz_look_dist  - 1x1 scalar, horizontal plane lookahead distance wrt VEHICLE frame
%      5.) W               - 1x1 scalar, image WIDTH  in pixels
%      6.) H               - 1x1 scalar, image HEIGHT in pixels
%      7.) Ts              - 1x1 scalar, block sample time (secs) 
%      8.) va_of_cam       - 1x1 scalar, camera view angle (deg) 
%      9.) tf_obstacles_are_visible - 1x1 scalar, show obstacles OR not
%--------------------------------------------------------------------------
%     Block INPUTS:
%      1.) camera_pos      - 1x2 matrix, xy in WORLD frame
%      2.) veh_THETA       - 1x1 scalar, VEHICLE angle theta_rad relative to WORLD frame
%--------------------------------------------------------------------------
%     Block OUTPUTS:
%       1.) R              - HxW matrix
%       2.) G              - HxW matrix
%       3.) B              - HxW matrix
%==========================================================================
% 05-12-2017:      bradley.horton@mathworks.com.au
%==========================================================================

%%
%% The setup method is used to set up the basic attributes of the
%% S-function such as ports, parameters, etc. Do not add any other
%% calls to the main body of the function.
%%
setup(block);

%endfunction

%% Function: setup ===================================================
%% Abstract:
%%   Set up the basic characteristics of the S-function block such as:
%%   - Input ports
%%   - Output ports
%%   - Dialog parameters
%%   - Options
%%
%%   Required         : Yes
%%   C-Mex counterpart: mdlInitializeSizes
%%
function setup(block)

% Register number of ports
block.NumInputPorts  = 2;
block.NumOutputPorts = 3;

% Setup port properties to be inherited or dynamic
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

% Override input port properties
block.InputPort(1).Dimensions        = 2;
block.InputPort(1).DatatypeID        = 0;  % double
block.InputPort(1).Complexity        = 'Real';
block.InputPort(1).DirectFeedthrough = true;
block.InputPort(1).SamplingMode      = 'Sample';

block.InputPort(2).Dimensions        = 1;
block.InputPort(2).DatatypeID        = 0;  % double
block.InputPort(2).Complexity        = 'Real';
block.InputPort(2).DirectFeedthrough = true;
block.InputPort(2).SamplingMode      = 'Sample';

% Register parameters
block.NumDialogPrms     = 9;

% Register sample times
%  [0 offset]            : Continuous sample time
%  [positive_num offset] : Discrete sample time
%
%  [-1, 0]               : Inherited sample time
%  [-2, 0]               : Variable sample time
Ts = LOC_get_dp(block,'dp_Ts');
block.SampleTimes = [Ts 0];

% Override OUTPUT port properties
dp_pix_W              = LOC_get_dp(block,'dp_pix_W');
dp_pix_H              = LOC_get_dp(block,'dp_pix_H');

% ATTENTION:  See this REF for the dataType IDs:  
%    web(fullfile(docroot, 'simulink/sfg/sssetinputportdatatype.html'))

block.OutputPort(1).DatatypeID        = 3;  % uint8
block.OutputPort(1).Complexity        = 'Real';
block.OutputPort(1).Dimensions        = [dp_pix_H, dp_pix_W];
block.OutputPort(1).SamplingMode      = 'Sample';

block.OutputPort(2).DatatypeID        = 3;  % uint8
block.OutputPort(2).Complexity        = 'Real';
block.OutputPort(2).Dimensions        = [dp_pix_H, dp_pix_W];
block.OutputPort(2).SamplingMode      = 'Sample';

block.OutputPort(3).DatatypeID        = 3;  % uint8
block.OutputPort(3).Complexity        = 'Real';
block.OutputPort(3).Dimensions        = [dp_pix_H, dp_pix_W];
block.OutputPort(3).SamplingMode      = 'Sample';

% Specify the block simStateCompliance. The allowed values are:
%    'UnknownSimState', < The default setting; warn and assume DefaultSimState
%    'DefaultSimState', < Same sim state as a built-in block
%    'HasNoSimState',   < No sim state
%    'CustomSimState',  < Has GetSimState and SetSimState methods
%    'DisallowSimState' < Error out when saving or restoring the model sim state
block.SimStateCompliance = 'DefaultSimState';

%% -----------------------------------------------------------------
%% The MATLAB S-function uses an internal registry for all
%% block methods. You should register all relevant methods
%% (optional and required) as illustrated below. You may choose
%% any suitable name for the methods and implement these methods
%% as local functions within the same file. See comments
%% provided for each function for more information.
%% -----------------------------------------------------------------

block.RegBlockMethod('PostPropagationSetup',    @DoPostPropSetup);
block.RegBlockMethod('InitializeConditions', @InitializeConditions);
block.RegBlockMethod('Start', @Start);
block.RegBlockMethod('Outputs', @Outputs);     % Required
block.RegBlockMethod('Terminate', @Terminate); % Required

%end setup

%%
%% PostPropagationSetup:
%%   Functionality    : Setup work areas and state variables. Can
%%                      also register run-time methods here
%%   Required         : No
%%   C-Mex counterpart: mdlSetWorkWidths
%%
function DoPostPropSetup(block)
block.NumDworks = 0;
  
%%
%% InitializeConditions:
%%   Functionality    : Called at the start of simulation and if it is 
%%                      present in an enabled subsystem configured to reset 
%%                      states, it will be called when the enabled subsystem
%%                      restarts execution to reset the states.
%%   Required         : No
%%   C-MEX counterpart: mdlInitializeConditions
%%
function InitializeConditions(block)

%end InitializeConditions

%%
%% Start:
%%   Functionality    : Called once at start of model execution. If you
%%                      have states that should be initialized once, this 
%%                      is the place to do it.
%%   Required         : No
%%   C-MEX counterpart: mdlStart
%%
function Start(block)

% consult the block's UserData for any existing stored data
% delete any ARENA windows.
bh_UD_T = get_param(block.BlockHandle,'UserData');
if(~isempty(bh_UD_T) && isstruct(bh_UD_T) && isfield(bh_UD_T, 'arena_OBJ'))
  bh_UD_T.arena_OBJ.delete();
  rmfield(bh_UD_T,'arena_OBJ');
end
% delete any CAMERA windows.
if(~isempty(bh_UD_T) && isstruct(bh_UD_T) && isfield(bh_UD_T, 'cam_OBJ'))
  bh_UD_T.cam_OBJ.clear();
  rmfield(bh_UD_T,'cam_OBJ');
end

% grab the dialogue parameters
dp_init_cam_pos       = LOC_get_dp(block,'dp_init_cam_pos');
dp_init_veh_theta_rad = LOC_get_dp(block,'dp_init_veh_theta_rad');
dp_height_of_cam      = LOC_get_dp(block,'dp_height_of_cam');
dp_horz_look_dist     = LOC_get_dp(block,'dp_horz_look_dist');
dp_pix_W              = LOC_get_dp(block,'dp_pix_W');
dp_pix_H              = LOC_get_dp(block,'dp_pix_H');
dp_Ts                 = LOC_get_dp(block,'dp_Ts');
dp_va_of_cam          = LOC_get_dp(block,'dp_va_of_cam');
dp_tf_obstacles_are_visible = LOC_get_dp(block,'tf_obstacles_are_visible');

% look for a particular figure and CLOSE it if you find it
hfig = findobj('Tag', 'TAG_FIG_VIRTUAL_CAM_SFUN');
if(~isempty(hfig))
    close(hfig)
end

% create a specific figure
hfig = figure('Tag', 'TAG_FIG_VIRTUAL_CAM_SFUN', 'Name', 'FIG_VIRTUAL_CAM_SFUN');
hax  = axes('Parent', hfig);

% create an ARENA object
arena_OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  );
arena_OBJ = arena_OBJ.plot_arena(hax);
arena_OBJ.set_for_3D_camera_viewing();

if(true == dp_tf_obstacles_are_visible)
    arena_OBJ.set_obstacle_visibility("show") 
else
    arena_OBJ.set_obstacle_visibility("hide") 
end

hax = arena_OBJ.get_ax();
% hax.Units = 'Pixels';
% tmp_pos = hax.Position;
% hax.Position = [tmp_pos(1:2), dp_pix_W, dp_pix_H];

% orientate vectors
dp_init_cam_pos = [dp_init_cam_pos(:)]';                % a 1x2 ROW
   init_cam_pos = [dp_init_cam_pos, dp_height_of_cam ]; % a 1x3 ROW

% create an VIRTUAL CAMERA object
dx           = dp_horz_look_dist*cos(dp_init_veh_theta_rad);
dy           = dp_horz_look_dist*sin(dp_init_veh_theta_rad);
init_tgt_pos = [dp_init_cam_pos(1:2),0] + [ dx, dy, 0]; % a 1x3 ROW

cam_OBJ = bh_virtual_car_camera_CLS( hax, ...
                                     'cam_pos',   init_cam_pos, ...
                                     'tgt_pos',   init_tgt_pos, ...
                                     'cam_va',    dp_va_of_cam, ...
                                     'pix_width',  dp_pix_W, ...
                                     'pix_height', dp_pix_H);
                                 
%cam_OBJ = cam_OBJ.update_cam_pos(init_cam_pos, init_tgt_pos); 

% now save data to the block's USER data         
bh_UD_T.cam_OBJ   = cam_OBJ;
bh_UD_T.arena_OBJ = arena_OBJ;

set_param(block.BlockHandle,'UserData', bh_UD_T)

%end Start

%%
%% Outputs:
%%   Functionality    : Called to generate block outputs in
%%                      simulation step
%%   Required         : Yes
%%   C-MEX counterpart: mdlOutputs
%%
function Outputs(block)

bh_UD_T = get_param(block.BlockHandle,'UserData');
cam_OBJ = bh_UD_T.cam_OBJ;

% RECALL the input PORTS:
%      1.) camera_pos      - 1x2 matrix, xy in WORLD frame
%      2.) veh_THETA       - 1x1 scalar, VEHICLE angle theta_rad relative to WORLD frame

pos_cam_xy        = block.InputPort(1).Data;
pos_cam_xy        = [pos_cam_xy(:)]';  % 1x2 ROW
veh_theta         = block.InputPort(2).Data;

dp_horz_look_dist = LOC_get_dp(block,'dp_horz_look_dist');
dp_height_of_cam  = LOC_get_dp(block,'dp_height_of_cam');

% define the CAMERA (x,y,z) position
pos_cam = [pos_cam_xy, dp_height_of_cam ]; % a 1x3 ROW

% define the TARGET (x,y,z) position
dx      = dp_horz_look_dist*cos(veh_theta);
dy      = dp_horz_look_dist*sin(veh_theta);
pos_tgt = [pos_cam(1:2),0] + [ dx, dy, 0];

% update the VIRTUAL camera
cam_OBJ = cam_OBJ.update_cam_pos(pos_cam, pos_tgt);

[R,G,B] = cam_OBJ.getframe();

block.OutputPort(1).Data = R; %double(R); %[1,2,3; 4,5,6]; %I;
block.OutputPort(2).Data = G; %double(G); %[1,2,3; 4,5,6]; %I;
block.OutputPort(3).Data = B; %double(B); %[1,2,3; 4,5,6]; %I;

%end Outputs

%%
%% Terminate:
%%   Functionality    : Called at the end of simulation for cleanup
%%   Required         : Yes
%%   C-MEX counterpart: mdlTerminate
%%
function Terminate(block)
% bh_UD_T = get_param(block.BlockHandle,'UserData');
% cam_OBJ = bh_UD_T.cam_OBJ;
% 
% cam_OBJ.clear();
%end Terminate

function dp_data = LOC_get_dp(block,dp_Name)

% a simple lookup table for the DIALOG parameters

% the ORDER that the dialogue params are provided to the S-function
% So? - So if the order changes you *MUST* update this lookup table
dp_LUT = { ...  
    'dp_init_cam_pos',        1; 
    'dp_init_veh_theta_rad',  2;
    'dp_height_of_cam',       3;
    'dp_horz_look_dist',      4;
    'dp_pix_W',               5;
    'dp_pix_H',               6;
    'dp_Ts',                  7;
    'dp_va_of_cam',           8;
    'tf_obstacles_are_visible', 9;
};

tf_vec = strcmp(dp_LUT(:,1), dp_Name);

if(all(~tf_vec))
    error('###_ERROR: unknown NAME given for dialogue param !');
end

kk = find(tf_vec);
assert(isscalar(kk));

ind = dp_LUT{kk,2};

% now get the dialogue parameter data
dp_data = block.DialogPrm(ind).Data;


