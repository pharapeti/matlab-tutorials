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
 
%% create checkerboard
SS_M = 70/1000;  % square size (m)

x_TEMP = 4*[1,1,1,1];
y_TEMP =   [0, SS_M,  SS_M,     0];
z_TEMP =   [0,    0,  SS_M,  SS_M] + 0.05;
% x = y_TEMP;
% y = z_TEMP;
% z = x_TEMP;
% patch(x,y,z,[1 0 0])
% hold on
% plot3(x,y,z, '-ro');
% grid on
%
face_color_b = [0,0,0];
face_color_w = [1,1,1];


face_color_str = "WHITE";
for rr_kk=1:4
%         % change face color
%         if("BLACK"==face_color_str)
%             face_color_str = "WHITE";
%         else
%             face_color_str = "BLACK";
%         end
    for cc_kk=1:9
        
        if("BLACK"==face_color_str)
            face_color = face_color_b;
        else
            face_color = face_color_w;
        end

        % start with the template
        x = x_TEMP;
        y = y_TEMP;
        z = z_TEMP;

        % now offset it
        z_off = (rr_kk -1)*SS_M;
        y_off = (cc_kk -1)*SS_M;
        
        y = y + y_off;
        z = z + z_off;
        
        % draw the patch
        patch(hax,x,y,z,face_color,'Tag','TAG_PATCH_CHECK')
        
        % change face color
        if("BLACK"==face_color_str)
            face_color_str = "WHITE";
        else
            face_color_str = "BLACK";
        end
    end % cc_kk 
end % rr_kk

%% rotate

hp = findobj(hax,'Tag','TAG_PATCH_CHECK');

hgt = hgtransform('Parent',hax);
set(hp,'Parent',hgt)

for theta_deg=-20:5:20

 Rx = makehgtform('xrotate',theta_deg*pi/180);
 Tz = makehgtform('translate',[0,0,0.2]);
%  set(hgt,'Matrix',Rx)
%  drawnow
 set(hgt,'Matrix',Tz*Rx)
drawnow
 
 I = cam_OBJ.getframe();
 I = imresize(I,[240, 320]);
 
 if(theta_deg<0)
     sign_char = 'm';
 else
     sign_char = 'p';
 end
 tmp_fname_str = sprintf('bh_checkbrd_%c%d.JPG',sign_char, abs(theta_deg));
 imwrite(I,tmp_fname_str);
 
 hf = figure;
 imshow(I)
 close(hf)
end
 

