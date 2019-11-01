classdef bh_3dof_4wheel_vehicle_viewer_CLS
%==========================================================================
% EXAMPLE USAGE:    
% 
%     OBJ = bh_3dof_4wheel_vehicle_viewer_CLS('init_xytheta',    [1,2,-pi/4], ...
%                                             'scale_factor',    0.5, ...
%                                             'color',           [0,1,0], ...
%                                             'road_z',          1, ...
%                                             'veh_ID_str',      'BRADS_CAR', ...
%                                             'tgt_tag_ax_name', 'TAG_AX_ARENA');
% 
%     %OBJ.plot_init()
% 
%     % animate the vehicle
%     xx_list = linspace(1,5,20);
%     th_list = linspace(0,2*pi,20);
% 
%     for kk=1:length(xx_list)
%         xx = xx_list(kk);
%         tt = th_list(kk);
% 
%         OBJ.plot(xx,2,tt)
% 
%         pause(0.1);
%         fprintf('\n ... xx=%6.2f',xx);
%     end    
%==========================================================================
properties
    scale_factor    = [];
    tgt_tag_ax_name = '';
    color           = [];
    road_z          = [];
    veh_ID_str      = [];
    init_xytheta    = [];
    hax             = [];
end

properties (SetAccess=private)
%     PXY_birth_unscaled = [ 0.5,  -0.5  -0.25, -0.5;
%                            0,     0.5,  0,    -0.5 ]'; % arrow shape
                       
    chas_PXY_birth_unscaled = [  0.2, -0.2, -0.2,  0.2,  0.3;
                                -0.1, -0.1,  0.1,  0.1,    0]';
                            
    wheel_PXY_birth_unscaled  = [    0.04,   0.04 , -0.04 , -0.04;
                                    -0.015,  0.015,  0.015, -0.015; ]';
                             
                                       % fR   fL    bR    bL
    wheel_centroids_birth_unscaled = [  0.2,  0.2, -0.2, -0.2;
                                       -0.1,  0.1, -0.1,  0.1;  ]';
                             
    chas_patch_tag_name     = '';
    line_tag_name           = '';
    wheel_fR_patch_tag_name = '';
    wheel_fL_patch_tag_name = '';
    wheel_bR_patch_tag_name = '';
    wheel_bL_patch_tag_name = '';
end
%==========================================================================
methods
    function OBJ = bh_3dof_4wheel_vehicle_viewer_CLS(varargin)
           out_T = LOC_parse_inputs(varargin{:});
           
           OBJ.scale_factor    = out_T.scale_factor;
           OBJ.tgt_tag_ax_name = out_T.tgt_tag_ax_name;
           OBJ.color           = out_T.color;
           OBJ.road_z          = out_T.road_z;
           OBJ.veh_ID_str      = out_T.veh_ID_str;
           OBJ.init_xytheta    = out_T.init_xytheta;
           OBJ.hax             = out_T.tgt_hax;
           
           OBJ.chas_patch_tag_name     = ['TAG_PATCH_4WH_VEHICLE_',OBJ.veh_ID_str];
           OBJ.line_tag_name           = ['TAG_LINE_DDR_VEHICLE_',OBJ.veh_ID_str];
           OBJ.wheel_fR_patch_tag_name = ['TAG_PATCH_4WH_WHEEL_fR_',OBJ.veh_ID_str];
           OBJ.wheel_fL_patch_tag_name = ['TAG_PATCH_4WH_WHEEL_fL_',OBJ.veh_ID_str];
           OBJ.wheel_bR_patch_tag_name = ['TAG_PATCH_4WH_WHEEL_bR_',OBJ.veh_ID_str];
           OBJ.wheel_bL_patch_tag_name = ['TAG_PATCH_4WH_WHEEL_bL_',OBJ.veh_ID_str];
           
    end
%--------------------------------------------------------------------------
function hax = get_tgt_ax_handle(OBJ)
    hax = [];
    
    if( ~isempty(OBJ.hax) && isvalid(OBJ.hax) )
        h = OBJ.hax;
    else
        h   = findobj('Type','Axes','Tag',OBJ.tgt_tag_ax_name);
    end
    
    assert(length(h)<=1, 'ERR: only 1 target axes is allowed');
    if(~isempty(h))
       hax = h;
    end
end
%--------------------------------------------------------------------------
function hp = get_veh_handle(OBJ)
    hp  = [];
    h   = findobj('Type','patch', 'Tag', OBJ.chas_patch_tag_name);
    
    assert(length(h)<=1, 'ERR: only 1 patch allowed with name ---> <%s>',OBJ.chas_patch_tag_name);
    if(~isempty(h))
       hp = h;
    end
end
%--------------------------------------------------------------------------
function hp = get_wheel_handle(OBJ, WHEEL_STR)
    WHEEL_STR = upper(WHEEL_STR);
    switch WHEEL_STR
        case "FR"
                  tgt_tag_name = OBJ.wheel_fR_patch_tag_name;
        case "FL"
                  tgt_tag_name = OBJ.wheel_fL_patch_tag_name;
        case "BR"
                  tgt_tag_name = OBJ.wheel_bR_patch_tag_name;
        case "BL"
                  tgt_tag_name = OBJ.wheel_bL_patch_tag_name;
        otherwise
            error('UNKNOWN WHEEL ID !!');
    end
        
    hp  = [];
    h   = findobj('Type','patch', 'Tag', tgt_tag_name);
    
    assert(length(h)<=1, 'ERR: only 1 patch allowed with name ---> <%s>',tgt_tag_name);
    if(~isempty(h))
       hp = h;
    end
end
%--------------------------------------------------------------------------
function hL = get_line_handle(OBJ)
    hL  = [];
    h   = findobj('Type','animatedline', 'Tag', OBJ.line_tag_name);
    
    assert(length(h)<=1, 'ERR: only 1 animatedline allowed with name ---> <%s>',OBJ.line_tag_name);
    if(~isempty(h))
       hL = h;
    end
end
%--------------------------------------------------------------------------
function [X,Y,Z] = get_birth_XYZ(OBJ, component_str)
    % ATTENTION:
    %  Birth config will have the patch with centroid at origin and
    %  theta=0
    
    switch upper(component_str)
        case "CHASIS"
              PXY_mat = OBJ.chas_PXY_birth_unscaled;
        case "WHEEL"
              PXY_mat = OBJ.wheel_PXY_birth_unscaled;
        case "FR_CENT"
              PXY_mat = OBJ.wheel_centroids_birth_unscaled(1,:);
        case "FL_CENT"
              PXY_mat = OBJ.wheel_centroids_birth_unscaled(2,:);
        case "BR_CENT"
              PXY_mat = OBJ.wheel_centroids_birth_unscaled(3,:);
        case "BL_CENT"
              PXY_mat = OBJ.wheel_centroids_birth_unscaled(4,:);
        otherwise
            error('###_ERROR: Unknown component !!');
    end
    
    X = (PXY_mat(:,1) * OBJ.scale_factor); 
    Y = (PXY_mat(:,2) * OBJ.scale_factor); 
    Z = OBJ.road_z * ones(size(X));
end
%--------------------------------------------------------------------------
function plot(OBJ, xc, yc, theta_rad)
    
    % we will NOT plot unless our target axes exists
    hax = OBJ.get_tgt_ax_handle();
    if(isempty(hax))
        return
    end
    
    % get the CHASIS patch
    hp = OBJ.get_veh_handle();

    if(isempty(hp))
        [hp, hp_wh_vec] = OBJ.plot_birth();
    end
    
    [Xb,Yb,Zb] = OBJ.get_birth_XYZ("CHASIS");
    [X,Y,Z]    = LOC_rotate_patch(Xb,Yb,Zb,theta_rad);

    % now update the patch
    hp.XData   = X + xc;
    hp.YData   = Y + yc;
    hp.ZData   = OBJ.road_z*ones(size(X));
    
    % Get the BIRTH WHEEL and rotate it       
    [Xbw,Ybw,Zbw] = OBJ.get_birth_XYZ("WHEEL");
    [gXw_birth,gYw_birth,gZw_birth] = LOC_rotate_patch(Xbw,Ybw,Zbw,theta_rad);
    
    % plot the WHEELS 
    clear bXwc  bYwc bZwc   gXwc  gYwc gZwc   X  Y  Z
    tmp_list_str       = ["FR_CENT", "FL_CENT", "BR_CENT", "BL_CENT"];
    tmp_list_ID_for_hw = ["FR",      "FL",      "BR",      "BL"]; 
    for kk=1:length(tmp_list_str)
           cent_STR         = tmp_list_str(kk);
           
        [bXwc,  bYwc, bZwc] = OBJ.get_birth_XYZ(cent_STR);
        [gXwc,  gYwc, gZwc] = LOC_conv_B_to_G(bXwc,  bYwc, bZwc, theta_rad);

        w_str    = tmp_list_ID_for_hw(kk);
        hp       = OBJ.get_wheel_handle(w_str);
        hp.XData = xc + gXwc + gXw_birth;
        hp.YData = yc + gYwc + gYw_birth;
        hp.ZData =             gZw_birth;
    end    
        
    % get the line
    hL = OBJ.get_line_handle();
    
    if(isempty(hL))
        hL = animatedline('Tag',       OBJ.line_tag_name, ...
                          'Parent',    hax, ...
                          'LineStyle', '-',...
                          'LineWidth', 2,...
                          'Color',     OBJ.color);
    end
    % now update the line
    zc = OBJ.road_z;
    
    addpoints(hL, xc, yc, zc );
    
    drawnow;
end
%--------------------------------------------------------------------------
function [varargout] = plot_birth(OBJ)
    % ALLOWED USAGE:
    %   >>                   plot_birth(OBJ)
    %   >> [hp, hp_wh_vec] = plot_birth(OBJ);
    hax = OBJ.get_tgt_ax_handle();
    if(isempty(hax))
        hax = axes('Tag',OBJ.tgt_tag_ax_name);
        axis(hax,'equal');
    end
    
    % plot the CHASIS
    [Xb,Yb,Zb] = OBJ.get_birth_XYZ("CHASIS");
    
    hp = patch(hax, Xb,Yb,Zb, ...
               'FaceColor', OBJ.color, ...
               'Tag'     ,  OBJ.chas_patch_tag_name ); 
           
    % plot the WHEEL -- FR       
    [Xbw,Ybw,Zbw] = OBJ.get_birth_XYZ("WHEEL");
    [xc,  yc, zc] = OBJ.get_birth_XYZ("FR_CENT");
    
    Xb = Xbw + xc;       Yb = Ybw + yc;     Zb = Zbw + zc;
    hp_wh(1)= patch(hax, Xb,Yb,Zb, 'FaceColor', 'black', 'Tag',  OBJ.wheel_fR_patch_tag_name ); 
    
    % plot the WHEEL -- FL       
    [xc,yc, ~] = OBJ.get_birth_XYZ("FL_CENT");
    
    Xb = Xbw + xc;       Yb = Ybw + yc;     Zb = Zbw + zc;
    hp_wh(2)= patch(hax, Xb,Yb,Zb, 'FaceColor', 'black', 'Tag',  OBJ.wheel_fL_patch_tag_name ); 
           
     % plot the WHEEL -- BR       
    [xc,yc, ~] = OBJ.get_birth_XYZ("BR_CENT");
    
    Xb = Xbw + xc;       Yb = Ybw + yc;     Zb = Zbw + zc;
    hp_wh(3)= patch(hax, Xb,Yb,Zb, 'FaceColor', 'black', 'Tag',  OBJ.wheel_bR_patch_tag_name ); 
    
     % plot the WHEEL -- BL       
    [xc,yc, ~] = OBJ.get_birth_XYZ("BL_CENT");
    
    Xb = Xbw + xc;       Yb = Ybw + yc;     Zb = Zbw + zc;
    hp_wh(4)= patch(hax, Xb,Yb,Zb, 'FaceColor', 'black', 'Tag',  OBJ.wheel_bL_patch_tag_name ); 
          
    if(2==nargout)
        varargout{1} = hp;
        varargout{2} = hp_wh;
    end
end
%--------------------------------------------------------------------------
function [varargout] = plot_init(OBJ)
    
    % do teh BIRTH plot
    OBJ.plot_birth();
    
    % now update
    xc        =  OBJ.init_xytheta(1);
    yc        =  OBJ.init_xytheta(2);
    theta_rad =  OBJ.init_xytheta(3);
    
    OBJ.plot(xc, yc, theta_rad);
    
end
%--------------------------------------------------------------------------
function clear(OBJ)
   hL = OBJ.get_line_handle();
   hp = OBJ.get_veh_handle();
      
   if(~isempty(hp))
       delete(hp);
   end
   
   if(~isempty(hL))
       delete(hL);
   end
   
   delete( get_wheel_handle(OBJ, "FR")  );
   delete( get_wheel_handle(OBJ, "FL")  );
   delete( get_wheel_handle(OBJ, "BR")  );
   delete( get_wheel_handle(OBJ, "BL")  );

end
%--------------------------------------------------------------------------
end % methods
%==========================================================================
end %classdef
%==========================================================================
function out_T = LOC_parse_inputs(varargin)

p = inputParser;
p.FunctionName = mfilename();

% Inputs added with addParameter are not positional, so you can pass values 
% for height before or after values for width. However, parameter value 
% inputs require that you pass the input name ('height' or 'width') along 
% with the value of the input.

def_color            = [0,1,0];
def_road_z           = 1;
def_scale_factor     = 1;
%def_veh_ID_str      = 'TAG_PATCH_DDR_VEHICLE';
def_veh_ID_str      = 'xxx';

def_tgt_tag_ax_name  = 'xxx';
def_init_xytheta     = [0,0,0];

fh_checkColor       = @(x) validateattributes(x,{'numeric'}, {'vector', 'numel',3});
fh_checkRoadZ       = @(x) validateattributes(x,{'numeric'}, {'scalar'});
fh_checkScaleFactor = @(x) validateattributes(x,{'numeric'}, {'scalar'});
fh_checkName        = @(x) validateattributes(x,{'char'},    {'row'});
fh_checkINITXYTHETA = @(x) validateattributes(x,{'numeric'}, {'vector', 'numel',3});

addParameter(p,'color',          def_color,           fh_checkColor);
addParameter(p,'road_z',         def_road_z,          fh_checkRoadZ );
addParameter(p,'scale_factor',   def_scale_factor,    fh_checkScaleFactor);
addParameter(p,'veh_ID_str',     def_veh_ID_str,      fh_checkName );
addParameter(p,'tgt_tag_ax_name',def_tgt_tag_ax_name, fh_checkName );
addParameter(p,'tgt_hax',[]);

addParameter(p,'init_xytheta',   def_init_xytheta,    fh_checkINITXYTHETA);

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
function [X,Y,Z] = LOC_rotate_patch(xi,yi,zi,theta)

 xi = xi(:);
 yi = yi(:);
 zi = zi(:);
 
 R = [ cos(theta), -sin(theta);
       sin(theta),  cos(theta); ];
 
 bP = [ xi.';
        yi.'; ];
    
    
 gP = R * bP;   
 
  X =  gP(1,:).';
  Y =  gP(2,:).';
  Z = zi;
end
%==========================================================================
function [X,Y,Z] = LOC_conv_B_to_G(xi,yi,zi,theta)

 xi = xi(:);
 yi = yi(:);
 zi = zi(:);
 
 R = [ cos(theta), -sin(theta);
       sin(theta),  cos(theta); ];
 
 bP = [ xi.';
        yi.'; ];
    
    
 gP = R * bP;   
 
  X =  gP(1,:).';
  Y =  gP(2,:).';
  Z = zi;
end
%==========================================================================





