%THE_MOV_FILE = 'Droid Racing Challenge 2017 - Test Video  Initial Section, 11 AM, Sunny.mp4';
THE_MOV_FILE = 'Droid Racing Challenge 2017 - Test Video  Initial Section, 11 AM, REVERSE 2 2.mp4';
v            = VideoReader(THE_MOV_FILE);

%% get a viewer ready
figure;
hax(1) = subplot(1,2,1);
hax(2) = subplot(1,2,2);

%% process the video
fr_count = 0;
while hasFrame(v)
    fr_count = 1 + fr_count;
    I = readFrame(v);
    
    % reduce the original 480x640 image
    % I = imresize(I,[240 320]);
      I = imresize(I,[180   240]);  % pretty good !
    %  I = imresize(I,[120   160]);  % pretty good !
      
    if(1==fr_count)
        tf_init = true;
        marker_OBJ = create_target_markers_CLS();
        marker_s   = marker_OBJ.get_struct();
    else
        tf_init = false;
    end
    
    % OK: call the algorithm
     [BLUE_s, YELL_s, PURP_s] = bh_my_ALGORITHM_for_codegen(I,tf_init,marker_s);
    % [BLUE_s, YELL_s, PURP_s] = bh_my_ALGORITHM_for_codegen_mex(I,tf_init,marker_s);

    % extract some things
    BW_b  = BLUE_s.BW;
    BW_y  = YELL_s.BW;
    BW_p  = PURP_s.BW;
    b_pix = find(true==BLUE_s.BW);
    y_pix = find(true==YELL_s.BW);
    p_pix = find(true==PURP_s.BW);
    
    % plot stuff - the if-else makes the plotting faster ! (DN tip)
    num_ROWS = size(I,1);
    num_COLS = size(I,2);
       
    RGB_mat  = bh_create_byp_RGB_mat(  num_ROWS, num_COLS, ...
                                       b_pix, y_pix, p_pix );
     
    if isempty(hax(1).Children)
         hi(1) = imshow(I,       'Parent', hax(1));
         hi(2) = imshow(RGB_mat, 'Parent', hax(2));
    else
         hi(1).CData = I;
         hi(2).CData = RGB_mat;
    end
    drawnow  
end


%% and you're done !
fprintf('\n ... we are finished here <%s> \n', mfilename);

