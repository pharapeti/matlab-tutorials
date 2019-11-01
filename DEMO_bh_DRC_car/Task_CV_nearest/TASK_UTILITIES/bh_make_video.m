THE_MOV_FILE = 'Droid Racing Challenge 2017 - Test Video  Initial Section, 11 AM, REVERSE 2 2.mp4';
v            = VideoReader(THE_MOV_FILE);
vw           = VideoWriter('bh_results_video.mp4');

open(vw)
%% Echo some information about the video
get(v)

%% create an instance
OBJ =  ybp_finder_CLS();
OBJ  = OBJ.init();

%% process the video
hfig = figure('Position',[285   121   976   635]);
hax(1) = subplot(1,3,1);
hax(2) = subplot(1,3,2);
hax(3) = subplot(1,3,3);
while hasFrame(v)
    I = readFrame(v);
    
    I = imresize(I,[240 320]);
    
    % classify stuff
    OBJ = OBJ.classify(I);
    
    % find stuff
    [ RGB_mat, BW_b, BW_y, BW_p ] = OBJ.find_all_stuff();
   
    BW = BW_b | BW_y | BW_p;

    % plot stuff - the if-else makes the plotting faster ! (DN tip)
    if isempty(hax(1).Children)
         imshow(BW,      'Parent', hax(1));   
         imshow(I,       'Parent', hax(2));
         imshow(RGB_mat, 'Parent', hax(3));
    else
        hax(1).Children.CData = BW;
        hax(2).Children.CData = I;
        hax(3).Children.CData = RGB_mat;
    end
    drawnow
    
    % grab a picture of the figure
    F = getframe(hfig);
    
    % write it to our video
    writeVideo(vw,F)
end

%% close the videowriter
close(vw)
close all
%% and you're done !
fprintf('\n ... we are finished here <%s> \n', mfilename);

