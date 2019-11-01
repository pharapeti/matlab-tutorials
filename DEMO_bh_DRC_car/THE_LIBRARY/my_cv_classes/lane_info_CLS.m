classdef lane_info_CLS %#codegen

% ATTENTION:
% I want this class to be MATLAB CODER friendly, hence I have prepopulated
% some properties with NaNs

properties (SetAccess = protected)
    BW             ;
    NUM_ROWS    = 0; 
    NUM_COLS    = 0;
    %---------------------------------
    tip_upper_xy_col = [0;0]; % closest to TOP of image
    tip_lower_xy_col = [0;0]; % closest to BOTTOM of image
    %fh_line;
    m                = [0];
    c                = [0];
    %---------------------------------
    tf_is_detected   = false;
end
%_#########################################################################
methods
function OBJ = lane_info_CLS(BW, tf_found)
      OBJ.BW             = BW;
      
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
function OBJ = calc_info(OBJ, ulim, vlim)
   if( ~OBJ.is_detected() ) 
       return
   end
       
   if(1==nargin)
      ulim = [1, OBJ.NUM_COLS];
      vlim = [1, OBJ.NUM_ROWS];  
   end
   
   % OK: if we're here we have a lane
   the_size = [OBJ.NUM_ROWS, OBJ.NUM_COLS];
   the_ind  = find(OBJ.BW);
   [y,x]    = ind2sub(the_size,the_ind); % convert INDS to SUBSCRIPTS
   
   % create a homogenous line object
   LO_OBJ   = bh_line_homog_CLS(x,y);

   [tf_is_valid, uv_bot, uv_top] = LO_OBJ.get_roi_intersection_co_ords(ulim, vlim);
   
   % take care of the OUTPUTS
   OBJ.tip_upper_xy_col  = uv_top;
   OBJ.tip_lower_xy_col  = uv_bot;
   
   % get equation of the line
   % :  y = mx + c
   mc_col = LO_OBJ.get_mc();
   
   %OBJ.fh_line = @(x) (m*x + c);
   OBJ.m       = mc_col(1);
   OBJ.c       = mc_col(2);
end % calc_info()
%--------------------------------------------------------------------------  
function xy = get_xy(OBJ)
    
    coder.varsize('xy', [2 1]);

    xy = [];
    if( ~OBJ.is_detected() ) 
       return
    end
   
    xy = OBJ.tip_upper_xy_col;
end % get_xy()
%--------------------------------------------------------------------------  
function [m,c] = get_mc(OBJ)
    %coder.varsize('m','c', [1 1]);
     
    m = zeros(1,0);  % []
    c = zeros(1,0);  % []
    
    if( ~OBJ.is_detected() ) 
       return
    end
    
    m = OBJ.m;
    c = OBJ.c;    
end
%--------------------------------------------------------------------------  
function my_S = convert_to_struct(OBJ)
  % ATTENTION(R2017b):
  % the following usage is NOT supported by the MATLAB Coder:
  %   >> struct(OBJ)
    
    my_S.BW               = OBJ.BW;
    my_S.NUM_ROWS         = OBJ.NUM_ROWS; 
    my_S.NUM_COLS         = OBJ.NUM_COLS;
    my_S.tip_upper_xy_col = OBJ.tip_upper_xy_col;
    my_S.tip_lower_xy_col = OBJ.tip_lower_xy_col;
    my_S.m                = OBJ.m;
    my_S.c                = OBJ.c;
    my_S.tf_is_detected   = OBJ.tf_is_detected; 
end
%--------------------------------------------------------------------------  

end % methods()
%_#########################################################################

end % classdef()
%_#########################################################################
% END CLASSDEF
%_#########################################################################


