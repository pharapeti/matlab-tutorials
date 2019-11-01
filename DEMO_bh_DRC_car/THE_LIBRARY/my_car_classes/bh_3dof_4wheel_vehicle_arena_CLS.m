classdef bh_3dof_4wheel_vehicle_arena_CLS
%==========================================================================
% EXAMPLE USAGE MODE_#1:    
%     OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  );
%     OBJ = OBJ.plot_arena()
%     hax = OBJ.get_ax()
%     
% EXAMPLE USAGE MODE_#2:    
%     OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  );
%     hax = axes;
%     OBJ = OBJ.plot_arena(hax)
%     hax = OBJ.get_ax()
%
% EXAMPLE USAGE MODE_#3:    
%     OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  )
%     OBJ = OBJ.plot_arena()
%     OBJ.set_for_2D_viewing()
%
% EXAMPLE USAGE MODE_#4:    
%     OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  )
%     OBJ = OBJ.plot_arena()
%     OBJ.set_for_3D_camera_viewing()
%
% EXAMPLE USAGE MODE_#5:    
%     OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  )
%     OBJ = OBJ.plot_arena()
%     OBJ.do_drive_through()
%
% EXAMPLE USAGE MODE_#6:    
%     OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  )
%     OBJ = OBJ.plot_arena()
%     OBJ.set_for_3D_viewing()
%
%==========================================================================    
    properties
    end
    
    properties (GetAccess = private)
       hax 
    end
%==========================================================================
methods
function OBJ = bh_3dof_4wheel_vehicle_arena_CLS()
% Usage:
%   OBJ = bh_3dof_4wheel_vehicle_arena_CLS()
    
end % bh_3dof_4wheel_vehicle_arena_CLS
%--------------------------------------------------------------------------
function OBJ = plot_arena(OBJ, hax)
    if(1==nargin)
        hf  = figure;
        hax = axes(hf);
    end
    
    OBJ.hax = hax;
    
    LOC_plot_arena(hax)    
    
    OBJ.set_for_2D_viewing();
    
end % plot_arena
%--------------------------------------------------------------------------
function set_obstacle_visibility(OBJ, str)
    %   ALLOWED_USAGE:  
    %     >> OBJ.set_obstacle_visibility("hide")
    %     >> OBJ.set_obstacle_visibility("show")

    str    = lower( string(str)  );
    tf_mem = ismember(str, ["hide","show"])
    assert(tf_mem,'###_ERROR:  Unknown string supplied .. should be a member of ["hide","show"]');

    % get all obstacle hg handles
    hg_list = findobj(OBJ.hax, 'Tag', 'TAG_ARENA_OBSTACLE');
    if(isempty(hg_list))
        return
    end

    % now either hide or show
    switch str
        case "show"
             set(hg_list, 'Visible', 'on');
        case "hide"
             set(hg_list, 'Visible', 'off');
        otherwise
            error('###_ERROR: unknown string !');
    end
end % set_obstacle_visibility()
%--------------------------------------------------------------------------

function set_for_2D_viewing(OBJ)

    if( ~OBJ.isvalid() )
        return
    end
    
    % OK so we have a valid axes
    hax = OBJ.hax;
    view(OBJ.hax,2);
     xlim(OBJ.hax, [-2.5, 25]);
     ylim(OBJ.hax, [-2.5, 25]);
    
    hL_b = findobj(hax, 'Tag', 'TAG_BLUE_LANE');
    hL_y = findobj(hax, 'Tag', 'TAG_YELL_LANE');
    
    hL_b.LineWidth = 2;
    hL_y.LineWidth = 2;
    
    set(hax,'CameraPositionMode',   'auto');
    set(hax,'CameraTargetMode',     'auto');
    set(hax,'CameraViewAngleMode',  'auto');
end % set_for_2D_viewing()
%--------------------------------------------------------------------------
function set_for_3D_viewing(OBJ)
    % do we have a valid axes handle ... or was the axes deleted
    if( ~OBJ.isvalid() )
        return
    end
    
    % OK so we have a valid axes
    hax = OBJ.hax;
    hL_b = findobj(hax, 'Tag', 'TAG_BLUE_LANE');
    hL_y = findobj(hax, 'Tag', 'TAG_YELL_LANE');
    hL_b.LineWidth = 5;
    hL_y.LineWidth = 5;
end % set_for_2D_viewing()
%--------------------------------------------------------------------------
function set_for_3D_camera_viewing(OBJ)
    % do we have a valid axes handle ... or was the axes deleted
    if( ~OBJ.isvalid() )
        return
    end
    
    hax = OBJ.hax;
    
      % set figure
      hfig      = hax.Parent;
      hfig.Units = 'Pixels';
      tmp_pos = hfig.Position;
      hfig.Position = [tmp_pos(1:2), 320, 240];

      % set axes
      hax.Units = 'Pixels';
      tmp_pos = hax.Position;
      hax.Position = [tmp_pos(1:2), 320, 240];
    
    
    % OK so we have a valid axes
    hax = OBJ.hax;
    hL_b = findobj(hax, 'Tag', 'TAG_BLUE_LANE');
    hL_y = findobj(hax, 'Tag', 'TAG_YELL_LANE');
    hL_b.LineWidth = 5;
    hL_y.LineWidth = 5;
    
    % set the camera
    campos(   hax, [2,0,0.4]);
    camtarget(hax, [111,0,1]);
    camtarget(hax, [20,0,1]);
    camproj(  hax, 'perspective') 
    %camproj(hax, 'orthographic') 
    camva(hax, 45)
end % set_for_3D_viewing()
%--------------------------------------------------------------------------
function tf_isvalid = isvalid(OBJ)
    [~, tf_isvalid] = get_ax(OBJ);
end % isvalid
%--------------------------------------------------------------------------
function delete(OBJ)
    if( OBJ.isvalid() )
        delete( OBJ.hax );
    end
end % delete
%--------------------------------------------------------------------------
function clear(OBJ)
    if( OBJ.isvalid() )
        cla( OBJ.hax );
    end
end % clear
%--------------------------------------------------------------------------
function [hax, tf_isvalid] = get_ax(OBJ)
    % do we have a valid axes handle ... or was the axes deleted
    tf_isvalid = isvalid(OBJ.hax);
    
    if( tf_isvalid )
        hax = OBJ.hax;
    else
        hax = [];
    end
end % get_ax
%--------------------------------------------------------------------------
function do_drive_through(OBJ)
    % do we have a valid axes handle ... or was the axes deleted
    if( ~OBJ.isvalid() )
        return
    end
    
    OBJ.set_for_3D_camera_viewing();
    
    LOC_do_drive_through(OBJ.hax);
    
    % set back to default view
    OBJ.set_for_3D_camera_viewing();

end % do_drive_through
%--------------------------------------------------------------------------
end % methods
%==========================================================================

end % classdef
%##########################################################################
function LOC_plot_arena(hax)
    tab = readtable('bh_yb_track.xlsx', 'Sheet','tmp_SHEET');
    XR = tab.XR;           XL = tab.XL;
    YR = tab.YR;           YL = tab.YL;
    ZR = zeros(size(XR));  ZL = zeros(size(XL));

    XC = [1*linspace(0,22,22), (22+0*linspace(0,22,22)), linspace(22,0,22), 0*linspace(0,22,22)];
    YC = [0*linspace(0,22,22), 1*linspace(0,22,22),  (22+0*linspace(0,22,22)), linspace(22,0,22)];
    ZC = zeros(size(XC));

%     % set current axes
%     axes(hax)
%     hax.Units = 'Pixels';
    
  axis(hax,'equal')
    
    
    plot3(XR,YR,ZR,'-b', 'LineWidth', 5, 'Tag', 'TAG_BLUE_LANE', 'Color', [50,145,205]/255); hold on
    plot3(XL,YL,ZL,'-y', 'LineWidth', 5, 'Tag', 'TAG_YELL_LANE'); hold on
    plot3(XC,YC,ZC,'-k', 'LineWidth', 5, 'Tag', 'TAG_CENT_LANE', 'Visible', 'off');
    
    grid on
    xlabel('X', 'FontSize',16);
    ylabel('Y', 'FontSize',16);
    axis equal

    % put down GREEN grid lines every 5 metres
    plot3([ 5, 5],[-0.5,22.5],[0,0],'-k', 'LineWidth', 2);
    plot3([10,10],[-0.5,22.5],[0,0],'-k', 'LineWidth', 2);
    plot3([15,15],[-0.5,22.5],[0,0],'-k', 'LineWidth', 2);
    plot3([20,20],[-0.5,22.5],[0,0],'-k', 'LineWidth', 2);
    
    plot3([ 2.5, 2.5],[-0.5,22.5],[0,0],'--k', 'LineWidth', 2);
    plot3([ 7.5, 7.5],[-0.5,22.5],[0,0],'--k', 'LineWidth', 2);
    plot3([12.5,12.5],[-0.5,22.5],[0,0],'--k', 'LineWidth', 2);
    plot3([17.,17.5],[-0.5,22.5],[0,0],'--k', 'LineWidth', 2);
    plot3([20,20],[-0.5,22.5],[0,0],'--k', 'LineWidth', 2);
    
       
    plot3([-0.5,22.5],[ 5, 5],[0,0],'-k', 'LineWidth', 2);
    plot3([-0.5,22.5],[10,10],[0,0],'-k', 'LineWidth', 2);
    plot3([-0.5,22.5],[15,15],[0,0],'-k', 'LineWidth', 2);
    plot3([-0.5,22.5],[20,20],[0,0],'-k', 'LineWidth', 2);
    
    plot3([-0.5,22.5],[ 2.5, 2.5],[0,0],'--k', 'LineWidth', 2);
    plot3([-0.5,22.5],[ 7.5, 7.5],[0,0],'--k', 'LineWidth', 2);
    plot3([-0.5,22.5],[12.5,12.5],[0,0],'--k', 'LineWidth', 2);
    plot3([-0.5,22.5],[17.5,17.5],[0,0],'--k', 'LineWidth', 2);
    plot3([-0.5,22.5],[20,20],[0,0],'--k', 'LineWidth', 2);
    
    
    %****************************************
    % add island
    %****************************************
    island_rgb = 0.5*[1,1,1];  %[0.8 0.8 0.8];
    island_floor_Z = -0.1;
    %roof
    tmp_X = [  1.5,  20.5,   20.5,   1.5];
    tmp_Y = [  1.5,   1.5,   20.5,  20.5];
    tmp_Z = 0.3*ones(size(tmp_X));
    hp = patch(tmp_X, tmp_Y, tmp_Z, island_rgb); %,'FaceColor', 'g')
    %****************************************
    %floor
    %****************************************
    tmp_X = [  1.5,  20.5,   20.5,   1.5];
    tmp_Y = [  1.5,   1.5,   20.5,  20.5];
    tmp_Z = island_floor_Z*ones(size(tmp_X));
    hp = patch(tmp_X, tmp_Y, tmp_Z, island_rgb); %,'FaceColor', 'g')
    %****************************************
    % wall #1
    %****************************************
    tmp_X = [  1.5,  20.5,   20.5,  1.5];
    tmp_Y = [  1.5,   1.5,    1.5,  1.5];
    tmp_Z = [    island_floor_Z,     island_floor_Z,    0.3,  0.3 ];
    hp = patch(tmp_X, tmp_Y, tmp_Z, island_rgb); %,'FaceColor', 'g')
    %****************************************
    % wall #2
    %****************************************
    tmp_X = [  20.5,  20.5,   20.5,  20.5];
    tmp_Y = [  1.5,   20.5,    20.5,  1.5];
    tmp_Z = [    island_floor_Z,     island_floor_Z,    0.3,  0.3 ];
    hp = patch(tmp_X, tmp_Y, tmp_Z, island_rgb); %,'FaceColor', 'g')
    %****************************************
    % wall #3
    %****************************************
    tmp_X = [ 20.5,   1.5,    1.5,  20.5];
    tmp_Y = [  20.5,  20.5,   20.5,  20.5];
    tmp_Z = [    island_floor_Z,     island_floor_Z,    0.3,  0.3 ];
    hp = patch(tmp_X, tmp_Y, tmp_Z, island_rgb); %,'FaceColor', 'g')
    %****************************************
    % wall #4
    %****************************************
    tmp_X = [   1.5,   1.5,    1.5,   1.5];
    tmp_Y = [  20.5,   1.5,    1.5,   20.5];
    tmp_Z = [    0,     0,    0.3,  0.3 ];
    hp = patch(tmp_X, tmp_Y, tmp_Z, island_rgb); %,'FaceColor', 'g')

    % add layers
    tmp_X = [  40,  40, -20, -20];
    tmp_Y = [ -20,  40,  40, -20];
    tmp_Z = -0.2*ones(size(tmp_X));
    hp = patch(tmp_X, tmp_Y, tmp_Z, [0.8 0.8 0.8]); %,'FaceColor', 'g')

    % add the purple obstacles/CYLINDERS
    [tmp_X, tmp_Y, tmp_Z] = cylinder(0.2);
    tmp_Z = 0.5*tmp_Z;
    TAG_FOR_OBSTACLES = 'TAG_ARENA_OBSTACLE';
    
    surf(10+tmp_X,-0.3+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    surf(18+tmp_X, 0.3+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    patch(10+tmp_X(1,:), -0.3+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    patch(18+tmp_X(1,:),  0.3+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    
    surf(21.8+tmp_X,  8+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    surf(22.2+tmp_X, 15+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    patch(21.8+tmp_X(1,:), 8+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    patch(22.2+tmp_X(1,:),  15+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  

    surf(10+tmp_X,21.8+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    surf(18+tmp_X,22.3+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    patch(10+tmp_X(1,:), 21.8+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    patch(18+tmp_X(1,:),  22.3+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
       
    surf(-0.3+tmp_X,  8+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    surf( 0.3+tmp_X, 15+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    patch(-0.3+tmp_X(1,:), 8+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    patch( 0.3+tmp_X(1,:),  15+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    %----------------------------------------------------------------------
%     surf(10+tmp_X,-0.5+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     surf(18+tmp_X, 0.5+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     patch(10+tmp_X(1,:), -0.5+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     patch(18+tmp_X(1,:),  0.5+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     
%     surf(21.5+tmp_X,  8+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     surf(22.5+tmp_X, 15+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     patch(21.5+tmp_X(1,:), 8+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     patch(22.5+tmp_X(1,:),  15+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
% 
%     surf(10+tmp_X,21.5+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     surf(18+tmp_X,22.5+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     patch(10+tmp_X(1,:), 21.5+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     patch(18+tmp_X(1,:),  22.5+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%        
%     surf(-0.5+tmp_X,  8+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     surf( 0.5+tmp_X, 15+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     patch(-0.5+tmp_X(1,:), 8+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
%     patch( 0.5+tmp_X(1,:),  15+tmp_Y(1,:), tmp_Z(2,:), [1 0 1], 'EdgeColor',  [1 0 1], 'Tag', TAG_FOR_OBSTACLES);  
    
end % LOC_plot_arena()
%==========================================================================
function LOC_do_drive_through(hax)

  hL = findobj(hax, 'Tag', 'TAG_CENT_LANE');

  XC = hL.XData;
  YC = hL.YData;

  N  = length(XC);
  dt = 1; 
  hax_cam = hax;
  for kk=2:N 
        xd = XC(kk) - XC(kk-1); 
        yd = YC(kk) - YC(kk-1);
        v  = [xd, yd]/dt;

        v_norm = norm(v);

        if (v_norm ~= 0)
          pos_tgt = [XC(kk),  YC(kk)] + 10*v/v_norm;
          pos_tgt = [pos_tgt,0]; % + [0,-5,0];
          
        end
        pos_cam = [XC(kk),  YC(kk),0.4];
        % pos_tgt = [XC(kk),YC(kk),0];
        
        % just make sure our AXES still exists
        if(~isgraphics(hax_cam))
            break
        end
        
        set(hax_cam,'CameraPosition',pos_cam, 'CameraTarget',pos_tgt);

        pause(0.3) 
  end % for kk
end % LOC_do_drive_through
%==========================================================================
