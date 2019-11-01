%% PURPOSE:
%  test the class bh_3dof_4wheel_vehicle_arena_CLS.m

%% EXAMPLE USAGE MODE_#1:    
    OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  );
    OBJ = OBJ.plot_arena()
    hax = OBJ.get_ax()
    
%% EXAMPLE USAGE MODE_#2:    
    OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  );
    hax = axes;
    OBJ = OBJ.plot_arena(hax)
    hax = OBJ.get_ax()

%% EXAMPLE USAGE MODE_#3:    
    OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  )
    OBJ = OBJ.plot_arena()
    OBJ.set_for_2D_viewing()

%% EXAMPLE USAGE MODE_#4:    
    OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  )
    OBJ = OBJ.plot_arena()
    OBJ.set_for_3D_camera_viewing()

%% EXAMPLE USAGE MODE_#5:    
    OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  )
    OBJ = OBJ.plot_arena()
    OBJ.do_drive_through()

%% EXAMPLE USAGE MODE_#6:    
    OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  )
    OBJ = OBJ.plot_arena()
    OBJ.set_for_3D_viewing()
    
  %% EXAMPLE USAGE MODE_#7:    
    OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  )
    OBJ = OBJ.plot_arena()
    OBJ.set_for_3D_camera_viewing()
  
    OBJ.set_obstacle_visibility("hide")  % "show" , "hide"
    
  %% EXAMPLE USAGE MODE_#8:    
    OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  )
    OBJ = OBJ.plot_arena()
    OBJ.set_for_3D_camera_viewing()
  
    OBJ.set_obstacle_visibility("hide")  % "show" , "hide"
    
    OBJ.do_drive_through()
