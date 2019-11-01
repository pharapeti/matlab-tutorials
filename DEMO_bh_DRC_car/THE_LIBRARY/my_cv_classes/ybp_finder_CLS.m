classdef ybp_finder_CLS
% YBP_FINDER_CLS find YELLOW,BLUE,PURPLE things
%   contains algorithm for identifying the lane markings (blue, yellow)
%   and obstacles(purple) in a DRC image
%-------------------------------------------------------------------------- 
% ATTENTION:
%  1.) See the proof of concept script called <bh_LabColorSegmentationExample_DRC.mlx>
%-------------------------------------------------------------------------- 
% EXAMPLE USAGE #1:
%--------------------------------------------------------------------------    
% EXAMPLE USAGE #2:
%--------------------------------------------------------------------------   
% Author:  bradley.horton@mathworks.com.au
%--------------------------------------------------------------------------   
% History:
%  17-Nov-2017 : inspired by conversations and advice with Daryl
%--------------------------------------------------------------------------    

properties
    
    %----------------------------------------------------------------------
    % performed well for a 480x640
    E_tgt_for_lane                = 0.8; %0.97;  % eccentricity of pixel blobs
    A_tgt_for_lane                = 100;   %20;    % area of pixel blobs
    fraction_of_img_to_ignore     = 0.4; %0.5;   % fraction of TOP part of image
    %----------------------------------------------------------------------
end
%--------------------------------------------------------------------------    
properties (SetAccess = protected)    
    nColors                   = 5;
    color_labels              = 0:4;
    color_markers             = zeros([5, 2]);

        DRC_image             = []; % M_x_N_x_3
    lab_DRC_image             = []; % M_x_N_x_3 
    label                     = []; % M_x_N
end
%--------------------------------------------------------------------------    
%_#########################################################################
methods
function OBJ =  ybp_finder_CLS(marker_s, tf_do_plots)
% ALLOWED usage:
%  >> OBJ = ybp_finder_CLS(marker_s)
%  >> OBJ = ybp_finder_CLS(marker_s, tf_do_plots)

    if(1==nargin)
        tf_do_plots = false;
    end

   OBJ.nColors       =  marker_s.nColors;    
   OBJ.color_labels  =  marker_s.color_labels;        
   OBJ.color_markers =  marker_s.color_markers;         
           
end % ybp_finder_CLS
%--------------------------------------------------------------------------  
function OBJ = classify(OBJ, DRC_image)

    nColors       = OBJ.nColors;
    color_labels  = OBJ.color_labels;
    color_markers = OBJ.color_markers;
        
    % record initial size of the input image
    NUM_ROWS = size(DRC_image,1);
    NUM_COLS = size(DRC_image,2);
    
    % so what row range do I really want to process
    rmin      = round(NUM_ROWS*OBJ.fraction_of_img_to_ignore);
    rmax      = NUM_ROWS;
    row_range = rmin:rmax;
    
    
    % Perform classification on NEW image
    lab_DRC_image = rgb2lab( DRC_image(row_range,:,:) );
    a             = double(lab_DRC_image(:,:,2));
    b             = double(lab_DRC_image(:,:,3));
    distance      = zeros([size(a,1), size(a,2), nColors]);
    
    for count = 1:nColors
      distance(:,:,count) = ( (a - color_markers(count,1)).^2 + ...
                              (b - color_markers(count,2)).^2 ).^0.5;
    end
    
    % Now which 3rd dim "page" had the smallest distance for each pixel.
    % - REMEMBER that the ind variable will be an MxN matrix
    [~, ind] = min(distance,[],3);
    
    % Now create a label matrix, which is the same size as the DRC_image 
    % matrix ... but it contains label IDs for each pixel
    label      = color_labels(ind);
    
    % reset label to the ORIGINAL image size
    %  - use a label_ID of 100 to indicate "I don't care"
    if(rmin>1)
        label      = [ 100*ones((rmin-1),NUM_COLS);
                       label ];
    end
    
    % store the outputs
    OBJ.label         = label;    % a 2D matrix of label IDs for each pixel
end % classify(OBJ)
%--------------------------------------------------------------------------
function plot_labels(OBJ, I)
    if(1 ==coder.target('MATLAB') )
        nColors           = OBJ.nColors;
        color_labels      = OBJ.color_labels;

        rgb_label        = repmat(OBJ.label,[1 1 3]);
        segmented_images = zeros([size(I), nColors],'uint8');  % a 4D matrix

        for count = 1:nColors
          color = I;
          color(rgb_label ~= color_labels(count)) = 0;
          segmented_images(:,:,:,count) = color;
        end 

        figure
        for kk=1:nColors   
            I     = segmented_images(:,:,:,kk);
            tmp_str = sprintf('Color_%d',kk);
            subplot(2,3,kk);  imshow(I),title(tmp_str, 'Interpreter', 'none');
        end
    end % if(1 ==coder.target('MATLAB') )
end % plot_labels(OBJ)
%-------------------------------------------------------------------------- 
function [ new_BW_blue,       ...
           new_BW_yell,       ...
           tf_found_blue_lane,   ...
           tf_found_yell_lane] = find_thin_lane_markings(OBJ, varargin)
% ALLOWED usage:
%  >> [BW_b, BW_y, tf_found_blue_lane, tf_found_yell_lane] = OBJ.find_thin_lane_markings()
%  >> [BW_b, BW_y, tf_found_blue_lane, tf_found_yell_lane] = OBJ.find_thin_lane_markings('do_plots')

    if(isempty(varargin) )
        tf_do_plots = false;
    else
        tf_do_plots = true;
    end

    %Let's look for the BLUE and YELLOW lane markings:
    BW_blue   = OBJ.label == 0; % blue has a label ID of 0
    BW_yellow = OBJ.label == 1; % yellow has a label ID of 1
    
    %Ignore the top half of the image:
    THE_FRACT = OBJ.fraction_of_img_to_ignore;
    BW_blue   = bh_mask_fraction_of_BW_image(BW_blue,   THE_FRACT);
    BW_yellow = bh_mask_fraction_of_BW_image(BW_yellow, THE_FRACT);
    
    % Process the BLUE and YELLOW BW images:
    [new_BW_blue, tf_found_blue_lane] = LOC_find_thin_lane_marking(OBJ, BW_blue);
    [new_BW_yell, tf_found_yell_lane] = LOC_find_thin_lane_marking(OBJ, BW_yellow);
    
    if(1 ==coder.target('MATLAB') )
        if(tf_do_plots)
           figure; 
           subplot(1,2,1); imshow(new_BW_blue);   title('BLUE   lane')
           subplot(1,2,2); imshow(new_BW_yellow); title('YELLOW lane')
        end
    end % if(1 ==coder.target('MATLAB') )
end %find_thin_lane_markings(OBJ)
%-------------------------------------------------------------------------- 
function [ new_BW_purp, tf_found_purp_blob] = find_purp_boxes(OBJ, varargin)
% ALLOWED usage:
%  >> [ new_BW_purple, tf_found_purp_blob] = OBJ.find_purp_boxes()
%  >> [ new_BW_purple, tf_found_purp_blob] = OBJ.find_purp_boxes('do_plots')

    if(isempty(varargin) )
        tf_do_plots = false;
    else
        tf_do_plots = true;
    end
    
    BW_purple   = OBJ.label == 2;
    
    %Ignore the top half of the image:
    THE_FRACT = OBJ.fraction_of_img_to_ignore;
    BW_purple = bh_mask_fraction_of_BW_image(BW_purple, THE_FRACT);
    
    % Process the PURPLE BW images:
    [new_BW_purp, tf_found_purp_blob] = LOC_find_purp_boxes(OBJ, BW_purple);
        
    if(1 ==coder.target('MATLAB') )
        if(tf_do_plots)
           figure; 
           imshow(new_BW_purple); title('PURPLE   obstacle')
        end
    end % if(1 ==coder.target('MATLAB') )
end % find_purp_boxes()
%-------------------------------------------------------------------------- 
function [  BLUE_s, YELLOW_s, PURP_s ] = find_all_stuff(OBJ, varargin)
% ALLOWED usage:
%  >> [     BLUE_s, YELLOW_s, PURP_s ] = OBJ.find_all_stuff()

   [ BW_b,                ...
     BW_y,                ...
     tf_found_b,          ...
     tf_found_y] = OBJ.find_thin_lane_markings();

   [ BW_p, tf_found_p] = OBJ.find_purp_boxes(); 
   
   % disable the warning about converting an OBJ to a STRUCT
    if(1 ==coder.target('MATLAB') )
       warning('off', 'MATLAB:structOnObject');
    end
   
   % take care of the OUTPUTS:    USAGE MODE #1
      BLUE_O = lane_info_CLS(BW_b, tf_found_b);
      YELL_O = lane_info_CLS(BW_y, tf_found_y);
      PURP_O = box_info_CLS( BW_p, tf_found_p);
       
      BLUE_s   = BLUE_O.convert_to_struct();
      YELLOW_s = YELL_O.convert_to_struct();
      PURP_s   = PURP_O.convert_to_struct();  
  
end % find_all_stuff()
%-------------------------------------------------------------------------- 
end % methods

end % classdef
%_#########################################################################
% END CLASSDEF
%_#########################################################################
function [new_BW, tf_found_it] = LOC_find_thin_lane_marking(OBJ, BW)

    new_BW      = false( size(BW) );
    tf_found_it = false;
    
    % Process the BLUE BW image:
    stats = regionprops('struct', BW, 'Orientation','Eccentricity','Area','PixelIdxList' );
    if( isempty(stats) )
        return
    end
    
    % sort based on Eccentricity

    % I want the code to be MATLAB Coder friendly
    %     [~,ind] = sort( [stats.Eccentricity], 'descend' );

    tmp_E = zeros(1, length(stats));
    for kk=1:length(stats)
        tmp_E(kk) = stats(kk).Eccentricity;
    end
    [~,ind] = sort( tmp_E, 'descend' );
    stats   = stats(ind,:);
    
    A = zeros(1, length(stats));
    E = zeros(1, length(stats));
    O = zeros(1, length(stats));
    for kk=1:length(stats)
        A(kk) = stats(kk).Area;
        E(kk) = stats(kk).Eccentricity;
        O(kk) = stats(kk).Orientation;
    end
    
%     A     = stats.Area;
%     E     = stats.Eccentricity;
%     O     = stats.Orientation;

    A_min = OBJ.A_tgt_for_lane * size(BW,1)/480;

%     ind   = find(E > OBJ.E_tgt_for_lane  & ...
%                  A > A_min &  ...
%                  ((O > 10 & O < 70) | (O < -10 & O > -70)) ...
%                  );
    ind   = find(E > OBJ.E_tgt_for_lane  & ...
                 A > A_min &  ...
                 ((O > 10 & O < 80) | (O < -10 & O > -80)) ...
                 );

    if( ~isempty(ind) )         
       IND          = ind(1);
       PixelIdxList = stats(IND).PixelIdxList;
       new_BW(PixelIdxList) = true;
       tf_found_it          = true;
    end
end % LOC_find_thin_lane_marking
%--------------------------------------------------------------------------
function [new_BW, tf_found_it] = LOC_find_purp_boxes(OBJ, BW)

    new_BW      = false( size(BW) );
    tf_found_it = false;
    
    stats = regionprops( BW, 'Area','Eccentricity','PixelIdxList' );

    if( isempty(stats) )
        return
    end
  
    % I want the code to be MATLAB Coder friendly
    %     A     = [stats.Area]';

    A = zeros(1, length(stats));
    for kk=1:length(stats)
        A(kk) = stats(kk).Area;
    end
    
    [~,ind] = sort(A,'descend');

    stats = stats(ind);

    % take the BIGGEST purple blob you can see
    IND = 1;
    PixelIdxList = stats(IND).PixelIdxList;
    new_BW(PixelIdxList) = true;    
    tf_found_it          = true;

end % LOC_find_purp_boxes
%--------------------------------------------------------------------------
function A_tab = LOC_get_init_region_polygons()

% ATTENTION: 
%   I want this to be MATLAB Coder friendly ... which means I canNOT use
%     a.) the readtatble() function
%     b.) dynamic field names

    % read color database
    % XLS_file = OBJ.ref_color_database_XLS_file;
    % A_tab    = readtable(XLS_file, 'Sheet', 'ALL');
    
    
my_field_names = {'blue_x',	'blue_y',	'yellow_x',	'yellow_y',	'purple_x',	'purple_y',	'green_x',	'green_y',	'grey_rim_x',	'grey_rim_y',	'pavers_x',	'pavers_y'};
my_data_mat = [ ...
    71.71697553	353.0669119	524.0815555	337.9827771	195.7952169	256.6447939	596.4460635	281.4453386	551.8817602	308.1842461	334.653703	365.3371908;
    73.03604728	357.0974089	571.3142281	366.6002199	218.9600644	307.9669129	616.2111788	292.4414238	610.4835932	336.965028	341.6691441	404.3605818;
    104.4006423	348.5234425	575.8985757	360.4877564	244.9206694	282.2060049	637.3682036	293.6941424	612.7953026	310.4959555	398.0849827	409.7683176;
    103.1548523	344.639509	518.2469312	328.5362426	224.5515793	241.0684309	638.2033493	280.6101928	546.7959995	290.9620112	403.4927185	364.1679507;
    71.71697553	353.0669119	524.0815555	337.9827771	195.7952169	256.6447939	596.4460635	281.4453386	551.8817602	308.1842461	334.653703	365.3371908;
    ];

    A_tab.blue_x	  = my_data_mat(:,1);
    A_tab.blue_y	  = my_data_mat(:,2);
    A_tab.yellow_x	  = my_data_mat(:,3);
    A_tab.yellow_y	  = my_data_mat(:,4);
    A_tab.purple_x	  = my_data_mat(:,5);
    A_tab.purple_y	  = my_data_mat(:,6);
    A_tab.green_x	  = my_data_mat(:,7);
    A_tab.green_y	  = my_data_mat(:,8);
    A_tab.grey_rim_x  = my_data_mat(:,9);	
    A_tab.grey_rim_y  = my_data_mat(:,10);
    A_tab.pavers_x	  = my_data_mat(:,11);
    A_tab.pavers_y    = my_data_mat(:,12);
end
%--------------------------------------------------------------------------
function my_BW = bh_roipoly(I,cv,rv)

    % the INPOLYGON approach
    % in = inpolygon(xq,yq,xv,yv)

    [NUM_IM_ROWS, NUM_IM_COLS,~] = size(I);

    % generate a list of x and y corordinates
    uq_list  = zeros(NUM_IM_ROWS*NUM_IM_COLS, 1);
    vq_list  = zeros(NUM_IM_ROWS*NUM_IM_COLS, 1);

    my_count =0;
    for kr=1:NUM_IM_ROWS
        for kc=1:NUM_IM_COLS
            my_count =  my_count +1;

            uq_list(my_count) = kc;
            vq_list(my_count) = kr;       
        end 
    end

    % which query co-ordinates are inside the polygon
    tf_in = inpolygon(uq_list, vq_list, cv,rv);

    % now create the logical mask
    my_BW        = false(NUM_IM_ROWS, NUM_IM_COLS);
    my_count =0;
    for kr=1:NUM_IM_ROWS
        for kc=1:NUM_IM_COLS
            my_count =  my_count +1;

            if(tf_in(my_count))
                my_BW(kr,kc) = true;
            end
        end 
    end

end % bh_roipoly()
%--------------------------------------------------------------------------
