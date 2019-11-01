%% Transform Road Image to Bird's-Eye-View Image
%
%%
% Define the camera intrinics.
focalLength = [309.4362 344.2161];
principalPoint = [318.9034 257.5352];
imageSize = [480 640];
%%
% Create an object containing the camera's intrinsics.
camIntrinsics = cameraIntrinsics(focalLength,principalPoint,imageSize);
%%
% Set the height of the camera to about 2 meters above the ground. Set the
% pitch to 14 degrees toward the ground.
height = 2.1798;
pitch = 14;
%%
% Create an object containing the camera's configuration.
sensor = monoCamera(camIntrinsics,height,'Pitch',pitch);
%%
% Define bird's-eye-view transformation parameters:
% Distance ahead of sensor (in meters). Look 6 meters to the right 
% and 6 meters to the left. Look 3 meters ahead of the sensor.
distAheadOfSensor = 30;
spaceToOneSide = 6;
bottomOffset = 3;
%%
% Set the |outView| argument.
outView = [bottomOffset,distAheadOfSensor,-spaceToOneSide,spaceToOneSide];
%%
% Set the output image width in pixels. Set to NaN to compute dimension
% automatically.
outImageSize = [NaN,250];
%%
% Create an object to use for birds eye view transforms.
birdsEye = birdsEyeView(sensor,outView,outImageSize);
%%
% Load an image that was captured by the sensor.
I = imread('road.png');
figure
imshow(I)
title('Original image')
%%
% Transform the input image to bird's-eye-view image.
B = transformImage(birdsEye,I);
%%
% Place a 20-meter marker ahead of the sensor in the bird's eye view.
imagePoint = vehicleToImage(birdsEye,[20,0]);
annotatedB = insertMarker(B,imagePoint - 5);
annotatedB = insertText(annotatedB,imagePoint,'20 meters');

figure
imshow(annotatedB)
title('Bird''s eye view')