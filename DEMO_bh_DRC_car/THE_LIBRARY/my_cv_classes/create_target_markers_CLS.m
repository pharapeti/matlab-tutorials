classdef create_target_markers_CLS
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
    %ref_image_file                = 'bh_ref_11am_reverse.bmp';
    ref_image_file                = 'bh_ref_11am_reverse.jpg';
    ref_color_database_XLS_file   = 'bh_color_lookup_bh_ref_11am_reverse.xlsx';
end
%--------------------------------------------------------------------------    
properties (SetAccess = protected)
    
    %----------------------------------------------------------
    % DATE:  06-Jul-2017:  noticed that removing GREEN from tgt list
    %                      improved recognition of YELLOW 
    %     nColors                   = 6;
    %     color_labels_list         = {'blue', 'yellow','purple','green','grey_rim', 'pavers'};
    %     color_labels              = 0:5;
    %----------------------------------------------------------
    
    nColors                   = 5;
    color_labels_list         = {'blue', 'yellow','purple','grey_rim', 'pavers'};
    color_labels              = 0:4;
    color_markers             = zeros([5, 2]);
end
%--------------------------------------------------------------------------    
%_#########################################################################
methods
function OBJ =  create_target_markers_CLS(varargin)
% ALLOWED usage:
%  >> OBJ = create_target_markers_CLS()
%  >> OBJ = create_target_markers_CLS('do_plots')

    if(isempty(varargin) )
        tf_do_plots = false;
    else
        tf_do_plots = true;
    end

    nColors           = OBJ.nColors;
    color_labels_list = OBJ.color_labels_list;
    
    % read reference image
    ref_DRC_image = imread(OBJ.ref_image_file); 
        
    % read color database
    XLS_file = OBJ.ref_color_database_XLS_file;
    A_tab    = readtable(XLS_file, 'Sheet', 'ALL');
    
    % get x,y co-ords of polygon that encloses each colored REGION
    region_coordinates        = zeros( length(A_tab.blue_x), 2, 5);
    region_coordinates(:,:,1) = [A_tab.blue_x,     A_tab.blue_y];
    region_coordinates(:,:,2) = [A_tab.yellow_x,   A_tab.yellow_y];
    region_coordinates(:,:,3) = [A_tab.purple_x,   A_tab.purple_y];
    region_coordinates(:,:,4) = [A_tab.grey_rim_x, A_tab.grey_rim_y];
    region_coordinates(:,:,5) = [A_tab.pavers_x,   A_tab.pavers_y];
    %----------------------------------------------------------
    % DATE:  06-Jul-2017:  noticed that removing GREEN from tgt list
    %                      improved recognition of YELLOW.
    %     region_coordinates        = [];
    %     region_coordinates(:,:,1) = [A_tab.blue_x,     A_tab.blue_y];
    %     region_coordinates(:,:,2) = [A_tab.yellow_x,   A_tab.yellow_y];
    %     region_coordinates(:,:,3) = [A_tab.purple_x,   A_tab.purple_y];
    %     region_coordinates(:,:,4) = [A_tab.green_x,    A_tab.green_y];
    %     region_coordinates(:,:,5) = [A_tab.grey_rim_x, A_tab.grey_rim_y];
    %     region_coordinates(:,:,6) = [A_tab.pavers_x,   A_tab.pavers_y];
    %----------------------------------------------------------
    
    % create the BW mask for each region
    % - the 3rd dim of the matrix is for each color region, ie:
    %   page #1 is for the 1st color region
    %   page #2 is for the 2nd color region, etc
    BW_sample_regions    = false([ size(ref_DRC_image,1), ...
                                   size(ref_DRC_image,2), ...
                                   nColors]);
    for count = 1:OBJ.nColors
      %ATTENTION: ROIPOLY() is NOT MATLAb Coder friendly
      BW_sample_regions(:,:,count) = roipoly(ref_DRC_image,...
                                            region_coordinates(:,1,count),...
                                            region_coordinates(:,2,count));
                                         
%       BW_sample_regions(:,:,count) = bh_roipoly(ref_DRC_image,...
%                                              region_coordinates(:,1,count),...
%                                              region_coordinates(:,2,count));                                      
    end
 
    % Convert REFERENCE DRC_image RGB image into an L*a*b* image 
    ref_lab_DRC_image = rgb2lab(ref_DRC_image);    
    
    % Regarding our REFERENCE image: 
    %  - Calculate the mean 'a*' and 'b*' value for each color region
    a_ref         = ref_lab_DRC_image(:,:,2);
    b_ref         = ref_lab_DRC_image(:,:,3);
    color_markers = zeros([nColors, 2]);

    for count = 1:OBJ.nColors
                    BW_mask  = BW_sample_regions(:,:,count);

      color_markers(count,1) = mean2( a_ref(BW_mask) );
      color_markers(count,2) = mean2( b_ref(BW_mask) );
    end
       
    % store the outputs
    OBJ.color_markers = color_markers;
    
    % ******************* PLOTTING ***********************
        if(tf_do_plots)
           % plot the REFERENCE image and show our target color regions 
           figure;  
              imshow(ref_DRC_image); 
              title('DRC_image', 'Interpreter', 'none');  
              hold on
              for kk=1:nColors
                  A_mat = region_coordinates(:,:,kk);
                  x     = A_mat(:,1);
                  y     = A_mat(:,2);
                  plot(x,y,'-g', 'LineWidth',2)
              end

           % plot the REFERENCE image AND use the BW masks to show each color
           figure;
           for kk=1:nColors    
                I     = zeros(size(ref_DRC_image,1), size(ref_DRC_image,2), 3, 'uint8');

                BW    = BW_sample_regions(:,:,kk);  % a    2D    matrix
                BW    = repmat(BW,1,1,3);           % a ***3D*** matrix
                I(BW) = ref_DRC_image(BW);

                subplot(2,3,kk);  imshow(I),title(color_labels_list{kk});        
            end
        end  %if(tf_do_plots)
        % ******************* PLOTTING ***********************  
end % create_target_labels_CLS()
%-------------------------------------------------------------------------- 
function marker_s = get_struct(OBJ)
         marker_s.nColors            = OBJ.nColors;        
         marker_s.color_labels       = OBJ.color_labels;        
         marker_s.color_markers      = OBJ.color_markers;         
end
%-------------------------------------------------------------------------- 
end % methods()
%_=========================================================================
end % classdef()
%_#########################################################################
% END CLASSDEF
%_#########################################################################
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
