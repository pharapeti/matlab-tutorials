THE_MOV_FILE = 'Droid Racing Challenge 2017 - Test Video  Initial Section, 11 AM, REVERSE 2 2.mp4';
v            = VideoReader(THE_MOV_FILE);
vw           = VideoWriter('bh_results_video.mp4');

open(vw)
%% Echo some information about the video
get(v)

%% process the video
while hasFrame(v)
    I = readFrame(v);
    
    I = imresize(I,[240 320]);
    
    % write it to our video
    writeVideo(vw,I)
end

%% close the videowriter
close(vw)
close all
%% and you're done !
fprintf('\n ... we are finished here <%s> \n', mfilename);

