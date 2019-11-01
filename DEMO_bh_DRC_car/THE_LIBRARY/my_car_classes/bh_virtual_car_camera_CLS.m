classdef bh_virtual_car_camera_CLS

properties (SetAccess = protected)
    hax          = [];
    cam_pos_xyz  = [];
    cam_tgt_xyz  = [];
    cam_va_deg   = [];
    cam_proj_str = '';
    width_pix    = [];
    height_pix   = [];
end

methods
function OBJ = bh_virtual_car_camera_CLS(hax, varargin)

  assert(nargin >=1, 'ERROR: at least 1 INPUT argument is required');  
    
  % validate that we have an axes handle  
  assert( ishghandle(hax),          'ERROR:  hax is NOT a valid HG handle' );  
  assert( string(hax.Type)=="axes", 'ERROR:  hax is NOT a valid HG handle' );  
  
  OBJ.hax = hax;
  

  % assign optional params
  out_T = LOC_parse_inputs(varargin{:});

  OBJ.cam_pos_xyz  = out_T.cam_pos;
  OBJ.cam_tgt_xyz  = out_T.tgt_pos;
  OBJ.cam_va_deg   = out_T.cam_va;
  OBJ.cam_proj_str = out_T.cam_proj;
  
  OBJ.width_pix   = out_T.pix_width;
  OBJ.height_pix  = out_T.pix_height;
   
  % set axes
  hax.Units = 'Pixels';
%   tmp_pos = hax.Position;
%   hax.Position = [tmp_pos(1:2), out_T.pix_width, out_T.pix_height];
  axis(hax,'equal')
 
    % set figure
  hfig      = hax.Parent;
  hfig.Units = 'Pixels';
  tmp_pos = hfig.Position;
  hfig.Position = [tmp_pos(1:2), out_T.pix_width, out_T.pix_height];
  
  % set the camera
  campos(   hax, OBJ.cam_pos_xyz);
  camtarget(hax, OBJ.cam_tgt_xyz);
  camproj(  hax, OBJ.cam_proj_str) 
  camva(    hax, OBJ.cam_va_deg)
  
  
end
%--------------------------------------------------------------------------
function OBJ = update_cam_pos(OBJ, cam_pos, tgt_pos)
    if(~OBJ.isOn())
        return
    end
    
    validateattributes(cam_pos,{'numeric'}, {'vector', 'numel',3});
    validateattributes(tgt_pos,{'numeric'}, {'vector', 'numel',3});
    
    OBJ.cam_pos_xyz = [cam_pos(:)]'; 
    OBJ.cam_tgt_xyz = [tgt_pos(:)]';
    
     set(OBJ.hax,'CameraPosition', OBJ.cam_pos_xyz, ...
                 'CameraTarget',   OBJ.cam_tgt_xyz );
     drawnow        
end
%--------------------------------------------------------------------------
function OBJ = update_cam_va(OBJ, va)
    if(~OBJ.isOn())
        return
    end
   
    OBJ.cam_va_deg = va;
    camva(OBJ.hax, va);
end
%--------------------------------------------------------------------------
function tf_val = isOn(OBJ)
         tf_val = ishghandle(OBJ.hax);
end
%--------------------------------------------------------------------------
function varargout = getframe(OBJ)
   % ALLOWED_USAGE:
   %       I  = getframe(OBJ)
   %  [R,G,B] = getframe(OBJ)
    try
        if(OBJ.isOn())
            hfig = OBJ.hax.Parent;
             %F = getframe(OBJ.hax);
             F = getframe(hfig);
             I = F.cdata;
             I = imresize(I,[OBJ.height_pix, OBJ.width_pix]);
             %I = im2double(I); % this also will rescaling the data
         else
             I = zeros([OBJ.height_pix, OBJ.width_pix,3]);
         end
    catch
        I = zeros([OBJ.height_pix, OBJ.width_pix,3]);
    end
    
    % enforce a specific data type  UINT8
    % our S-functions will want this
    I = uint8(I);
    
    % take care of the output arguments
    if(1==nargout)
         varargout{1} = I;
    elseif(3==nargout)
         varargout{1} = I(:,:,1);
         varargout{2} = I(:,:,2);
         varargout{3} = I(:,:,3);
    end
end
%--------------------------------------------------------------------------
function clear(OBJ)
    if(~OBJ.isOn())
        return
    end
    
    % clear the axes
    cla(OBJ.hax);
end
%--------------------------------------------------------------------------
function delete(OBJ)
    if(~OBJ.isOn())
        return
    end
    
    % clear the axes
    delete(OBJ.hax);
end
%--------------------------------------------------------------------------


end % methods
%==========================================================================

end % classdef
%==========================================================================
function out_T = LOC_parse_inputs(varargin)

p = inputParser;
p.FunctionName = mfilename();

% Inputs added with addParameter are not positional, so you can pass values 
% for height before or after values for width. However, parameter value 
% inputs require that you pass the input name ('height' or 'width') along 
% with the value of the input.

def_cam_pos   = [  0, 0, 0.4];
def_cam_tgt   = [111, 0, 1  ];
def_cam_va    = 45;
def_cam_proj  = 'perspective'; 
def_pix_width = 320;
def_pix_hgt   = 240;


fh_check3elevec = @(x) validateattributes(x,{'numeric'}, {'vector', 'numel',3});
fh_checkscalar  = @(x) validateattributes(x,{'numeric'}, {'scalar', '>',0});
fh_checkstr     = @(x) LOC_validatestring(lower(x), {'perspective','orthographic '});

addParameter(p,'cam_pos',          def_cam_pos,           fh_check3elevec);
addParameter(p,'tgt_pos',          def_cam_tgt,           fh_check3elevec);
addParameter(p,'cam_va',           def_cam_va,            fh_checkscalar);
addParameter(p,'cam_proj',         def_cam_proj,          fh_checkstr);

addParameter(p,'pix_width',        def_pix_width,         fh_checkscalar);
addParameter(p,'pix_height',       def_pix_hgt,           fh_checkscalar);

% Within your function, call the parse method. Pass the values of all of 
% the function inputs.
parse(p, varargin{:} )

% Access parsed inputs using these properties of the inputParser object:
% 
% Results ? Structure array with names and values of all inputs in the scheme.
% Unmatched ? Structure array with parameter names and values that are 
%             passed to the function, but are not in the scheme 
%             (when KeepUnmatched is true).
% UsingDefaults ? Cell array with names of optional inputs that are assigned 
%                 their default values because they are not passed to the function.

out_T = p.Results;

end
%==========================================================================
function LOC_validatestring(tgt_str, cell_list)
% ATTENTION:
% I had to write this function because the "validatestring()" function
% returns an OUTPUT that is NOT consistent with what the VALIDATION
% function is requirde to do, see here:
%    https://www.mathworks.com/help/releases/R2017b/matlab/ref/inputparser.addparameter.html#inputarg_validationFcn

   junk = validatestring(tgt_str, cell_list );
end
