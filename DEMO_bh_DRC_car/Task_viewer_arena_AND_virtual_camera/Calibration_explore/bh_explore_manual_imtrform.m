%% EXAMPLE USAGE MODE_#4:    
    OBJ = bh_3dof_4wheel_vehicle_arena_CLS(  )
    OBJ = OBJ.plot_arena()
    OBJ.set_for_3D_camera_viewing()
    hax = OBJ.get_ax();
    
cam_OBJ = bh_virtual_car_camera_CLS( hax, ...
                                     'cam_pos',   [2,0,0.4], ...
                                     'tgt_pos',   [111,0,0.4], ...
                                     'cam_va',  45, ...
                                     'cam_proj',  'perspective', ...
                                     'pix_width',  408, ...
                                     'pix_height', 240);

 I = cam_OBJ.getframe();
 I = imresize(I,[240, 320]);

imtool(I)

%%

% T = maketform('projective',U,X) creates a TFORM struct T for a two-dimensional 
% projective transformation that maps each row of U to the corresponding 
% row of X. The U and X arguments are each 4-by-2 and define the corners of 
% input and output quadrilaterals. No three corners can be collinear.

% pnt_uv =   [ 256, 168;
%               63, 168;
%              122, 111;
%              201, 111; ];
%          
% pnt_xy =   [ 256, 168;
%               63, 168;
%               63, 111;
%              256, 111; ];

pnt_uv =   [ 314, 226;
               7, 226;
             138,  90;
             179,  90; ];
         
pnt_xy =   [ pnt_uv(1,:);
             pnt_uv(2,:);
             pnt_uv(2,1), pnt_uv(3,2);
             pnt_uv(1,1), pnt_uv(4,2); ];


T = maketform('projective',pnt_uv, pnt_xy);

I2 = imtransform(I,T);

figure;  imshow(I2);
