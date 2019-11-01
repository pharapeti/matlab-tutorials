
%% Here is our algorithm - test it in MATLAB

%% read test image
DRC_image = imread('bh_ref_11am_reverse.bmp');
figure;
imshow(DRC_image); title('DRC_image', 'Interpreter', 'none');

% reduce the original 480x640 image
I = imresize(DRC_image,[240 320]);

% do one off tasks
marker_OBJ = create_target_markers_CLS();
marker_s   = marker_OBJ.get_struct();
tf_init    = true;
%++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
% START:  my algorithm
[BLUE_s, YELL_s, PURP_s] = bh_my_detect_ALGORITHM_for_codegen(I, tf_init, marker_s);
% END:    my algorithm
%++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

% VISUALIZATIONS    
figure;
subplot(1,4,1); imshow( I  );
subplot(1,4,2); imshow( BLUE_s.BW );
subplot(1,4,3); imshow( YELL_s.BW );
subplot(1,4,4); imshow( PURP_s.BW );

%% and you're done !
fprintf('\n ... we are finished here <%s> \n', mfilename);

