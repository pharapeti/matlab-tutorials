%% EXAMPLE USAGE MODE_#1:    
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

figure;  imshow(I);

%%    Camera Intrinsics
% Intrinsics
% ----------
% Focal length (pixels):   [2275.4421 +/- 1030.2099  2918.3718 +/- 1335.5143]
% Principal point (pixels):[  105.2177 +/- 16.0509     314.3134 +/- 179.8066]
focalLength =    [770,770]; %[2275, 2918];  %[38,38]*15;
principalPoint = [80,84];%[105, 314];  %[227, 80];
imageSize = [size(I,1), size(I,2)];
camIntrinsics = cameraIntrinsics(focalLength,principalPoint,imageSize);

sensor = monoCamera(camIntrinsics,0.4);
% Define bird's-eye-view transformation parameters: 
% Distance ahead of sensor (in meters). 
% Look 6 meters to the right and 6 meters to the left. 

distAheadOfSensor = 10;
spaceToOneSide = 3;
bottomOffset = 0;

%Set the outView argument.
outView = [bottomOffset,distAheadOfSensor,-spaceToOneSide,spaceToOneSide];

%Set the output image width in pixels. 
%Set to NaN to compute dimension automatically.

%outImageSize = [240,320];
outImageSize = [NaN,320];

%Create an object to use for birds eye view transforms.
birdsEye = birdsEyeView(sensor,outView,outImageSize);

%Transform the input image to bird's-eye-view image.
B = transformImage(birdsEye,I);

%Place a 5-meter marker ahead of the sensor in the bird's eye view.
imagePoint = vehicleToImage(birdsEye,[5,0]);
annotatedB = insertMarker(B,imagePoint - 5);
B = insertText(annotatedB,imagePoint,'5 meters');

figure
imshow(B)
title('Bird''s eye view')