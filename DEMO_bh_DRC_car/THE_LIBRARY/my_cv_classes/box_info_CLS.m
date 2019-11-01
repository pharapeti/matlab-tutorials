 classdef box_info_CLS %#codegen
% ATTENTION:
% I want this class to be MATLAB CODER friendly, hence I have prepopulated
% some properties with NaNs

properties (SetAccess = protected)
    BW             ;
    pixIND_list    ;
    NUM_ROWS    = 0; 
    NUM_COLS    = 0;
    %---------------------------------
    left_edge_xy_col  = [0;0]; 
    right_edge_xy_col = [0;0]; 
    %---------------------------------
    centroid_xy_col   = [0;0];
    %---------------------------------
    tf_is_detected   = false;
end
%_#########################################################################
methods
function OBJ = box_info_CLS(BW, tf_found)
      OBJ.BW            = BW;
      
      OBJ.NUM_ROWS       = size(BW,1);
      OBJ.NUM_COLS       = size(BW,2);
      
      OBJ.tf_is_detected = tf_found;
      
      OBJ = OBJ.calc_info();
end
%--------------------------------------------------------------------------  
function tf_detected = is_detected(OBJ)   
         tf_detected = OBJ.tf_is_detected;
end % is_detected()
%-------------------------------------------------------------------------- 
function OBJ = calc_info(OBJ)
   if( ~OBJ.is_detected() ) 
       return
   end
       
   % OK: if we're here we have a box
   the_size = [OBJ.NUM_ROWS, OBJ.NUM_COLS];
   the_ind  = find(OBJ.BW);
   [y,x]    = ind2sub(the_size,the_ind); % convert INDS to SUBSCRIPTS
      
   % the LEFT edge will have the smallest X-co-ord
   the_left_edge_x  = 1;
   [~,tmp_I]        = min(x);
   the_left_edge_x  =  x(tmp_I(1));        % MATLAB CODER friendly
   tmp_II           = find(x==the_left_edge_x);
   yI               = y(tmp_II);
   the_left_edge_y  = min(yI);
   
   % the RIGHT edge will have the biggest X-co-ord
   the_right_edge_x  = 1;
   [~,tmp_I]         = max(x);
   the_right_edge_x  =  x(tmp_I(1));        % MATLAB CODER friendly
   tmp_RR            = find(x==the_right_edge_x);
   yR                = y(tmp_RR);
   the_right_edge_y  = min(yR);
   
   % calc the centroid
   xc = mean(x);
   yc = mean(y);
   
   % take care of the OUTPUTS
   OBJ.left_edge_xy_col   = [the_left_edge_x(1);  the_left_edge_y(1)   ]; % MATLAB CODER friendly
   OBJ.right_edge_xy_col  = [the_right_edge_x(1); the_right_edge_y(1)  ]; % MATLAB CODER friendly
  
   OBJ.centroid_xy_col    = [xc(1); yc(1) ]; % MATLAB CODER friendly

end % calc_info()
%--------------------------------------------------------------------------  
function xy = get_xy(OBJ)
    coder.varsize('xy', [2 1]);

    xy = [];
    if( ~OBJ.is_detected() ) 
       return
    end
   
    xy = OBJ.centroid_xy_col;
end % get_xy()
%--------------------------------------------------------------------------  
function my_S = convert_to_struct(OBJ)
  % ATTENTION(R2017b):
  % the following usage is NOT supported by the MATLAB Coder:
  %   >> struct(OBJ)
    
    my_S.BW                = OBJ.BW;
    my_S.NUM_ROWS          = OBJ.NUM_ROWS; 
    my_S.NUM_COLS          = OBJ.NUM_COLS;
    my_S.left_edge_xy_col  = OBJ.left_edge_xy_col;
    my_S.right_edge_xy_col = OBJ.right_edge_xy_col;
    my_S.centroid_xy_col   = OBJ.centroid_xy_col;
    my_S.tf_is_detected    = OBJ.tf_is_detected; 
end
%--------------------------------------------------------------------------  
end % methods()
%_#########################################################################

end % classdef()
%_#########################################################################
% END CLASSDEF
%_#########################################################################


