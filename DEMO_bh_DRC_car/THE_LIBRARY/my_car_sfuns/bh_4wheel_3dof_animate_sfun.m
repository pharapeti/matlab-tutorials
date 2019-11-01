function bh_4wheel_3dof_animate_sfun(block)
%==========================================================================
% 4 wheel, 3-dof s-function for ANIMATION
%==========================================================================
% 
%     Dialogue PARAMETERS:
%       1.) Sample time                     (secs)
%       2.) waypoint matrix [x_col, y_col]  (m)
%       3.) Vehicle ID number               (-)
%       4.) Initial vehicle (x,y,theta)
% 
%     Block INPUTS:
%       1.) a 3 element vector (x,y,theta)
%   
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
block.NumInputPorts  = 1;
block.NumOutputPorts = 0;

% Setup port properties to be inherited or dynamic
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

% Override input port properties
block.InputPort(1).Dimensions        = 3;
block.InputPort(1).DatatypeID        = 0;  % double
block.InputPort(1).Complexity        = 'Real';
block.InputPort(1).DirectFeedthrough = true;

% Register parameters
block.NumDialogPrms     = 4;

% Register sample times
%  [0 offset]            : Continuous sample time
%  [positive_num offset] : Discrete sample time
%
%  [-1, 0]               : Inherited sample time
%  [-2, 0]               : Variable sample time
Ts = block.DialogPrm(1).Data;
block.SampleTimes = [Ts 0];

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
dp_waypoint_mat    = block.DialogPrm(2).Data;
dp_veh_ID_num      = block.DialogPrm(3).Data;
dp_veh_initxytheta = block.DialogPrm(4).Data;

% determine the vehicle color
switch dp_veh_ID_num
    case {1}
              veh_RGB = [0,  1,   0]; % green
    case {2}
              veh_RGB = [1, 0.2,  1]; % magenta like
    case {3}
              veh_RGB = [0.2, 1,  1];  % CYAN like
    otherwise
              veh_RGB = [0,1,0];     % black
end

tgt_tag_ax = 'TAG_AX_4WHEEL_3DOF_SIMPLE';

% create an axes
tmp_hax = findobj('Type','Axes','Tag', tgt_tag_ax);

if(~isempty(tmp_hax) )
    h_par = tmp_hax.Parent; 
    delete(tmp_hax);
    try
         delete(h_par);     
    catch
    end
end
    
    
figure;
hax = axes('Tag', tgt_tag_ax);
grid(hax,'on')
xlim(hax, [min(dp_waypoint_mat(:,1)), max(dp_waypoint_mat(:,1))]);
ylim(hax, [min(dp_waypoint_mat(:,2)), max(dp_waypoint_mat(:,2))]);
axis(hax,'equal');   

path_height = 0;
scale_fact  = 1;
veh_id_str  = ['4WHEEL_CAR_', num2str(dp_veh_ID_num) ]; 

% consult the block's UserData for any existing stored data
bh_UD_T = get_param(block.BlockHandle,'UserData');
if(~isempty(bh_UD_T) && isstruct(bh_UD_T) && isfield(bh_UD_T, 'veh_OBJ'))
  bh_UD_T.veh_OBJ.clear();
  rmfield(bh_UD_T,'veh_OBJ');
end

veh_OBJ = bh_3dof_4wheel_vehicle_viewer_CLS('init_xytheta',    dp_veh_initxytheta, ...
                                            'scale_factor',    scale_fact, ...
                                            'color',           veh_RGB , ...
                                            'road_z',          path_height, ...
                                            'veh_ID_str',      veh_id_str, ...
                                            'tgt_tag_ax_name', tgt_tag_ax);

% plot the vehicle
veh_OBJ.plot(dp_veh_initxytheta(1), ...
             dp_veh_initxytheta(2), ...
             dp_veh_initxytheta(3) );

% now save data to the block's USER data         
bh_UD_T.veh_OBJ   = veh_OBJ;

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
veh_OBJ = bh_UD_T.veh_OBJ;

xytheta   = block.InputPort(1).Data;

x         = xytheta(1);
y         = xytheta(2);
theta     = xytheta(3);

veh_OBJ.plot(x,y,theta)

% adjust axes limits if required
hax = veh_OBJ.get_tgt_ax_handle();
if(isempty(hax))
    return
end

XL = xlim(hax);
YL = ylim(hax);

if(x>XL(2))
    XL(2) = x+2;
end
if(x<XL(1))
    XL(1) = x-2;
end
if(y>YL(2))
    YL(2) = y+2;
end
if(y<YL(1))
    YL(1) = y-2;
end

xlim(hax, XL);
ylim(hax, YL);
%axis(hax,'equal');   



%end Outputs

%%
%% Terminate:
%%   Functionality    : Called at the end of simulation for cleanup
%%   Required         : Yes
%%   C-MEX counterpart: mdlTerminate
%%
function Terminate(block)

%end Terminate

