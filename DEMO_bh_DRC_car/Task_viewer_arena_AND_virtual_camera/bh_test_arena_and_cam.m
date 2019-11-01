%% Purpose:
%  Test the classes:
%    a.) bh_3dof_4wheel_vehicle_arena_CLS.m
%    b.) bh_virtual_car_camera_CLS.m

%% EXAMPLE USAGE MODE_#1:    
OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  );
OBJ = OBJ.plot_arena()

%% EXAMPLE USAGE MODE_#4:    
OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  )
OBJ = OBJ.plot_arena()
OBJ.set_for_3D_camera_viewing()
hax = OBJ.get_ax();
      
cam_OBJ = bh_virtual_car_camera_CLS( hax, ...
                                     'cam_pos',   [2,0,0.4], ...
                                     'tgt_pos',   [50,0,0.4], ...
                                     'cam_va',  65, ...
                                     'cam_proj',  'perspective', ...
                                     'pix_width',  408, ...
                                     'pix_height', 240);
 
%%
cam_OBJ = cam_OBJ.update_cam_va(75)

%% 
cam_OBJ = cam_OBJ.update_cam_pos([18,0,0.4], [20,0,0])