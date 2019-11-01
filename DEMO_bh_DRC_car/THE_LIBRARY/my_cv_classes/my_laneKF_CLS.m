classdef my_laneKF_CLS
    
% ATTENTION:
% I want this class to be MATLAB CODER friendly, hence I have prepopulated
% some properties with NaNs

properties (SetAccess = protected)
   Initial_mc_col;
   Initial_mc_var_mat;
   Noise_proc_var_mat;
   Noise_meas_var_mat;
   %------------------------------
   KF;
   %------------------------------
   missed_detect_count = 0;
   %------------------------------
   mc_col = [0;0];
   %------------------------------
   %x_col_mat = [];
   %------------------------------
   img_num_rows = 0;
   img_num_cols = 0;
end
%--------------------------------------------------------------------------
properties
   plot_TAG = 'TAG_PLOT_KF'; % used in plot() 
end
%_#########################################################################
methods
function OBJ = my_laneKF_CLS( Initial_mc_col,     ...
                              Initial_mc_var_mat, ...
                              Noise_proc_var_mat, ...
                              Noise_meas_var_mat )
    if(1 ==coder.target('MATLAB') )
       validateattributes(Initial_mc_col,     {'double'}, {'column','numel',2});                         
       validateattributes(Initial_mc_var_mat, {'double'}, {'size',[2,2]});                         
       validateattributes(Noise_proc_var_mat, {'double'}, {'size',[2,2]});                         
       validateattributes(Noise_meas_var_mat, {'double'}, {'size',[2,2]});                         
    end
    %  x = [m,c]
    
    % KF = my_KF_general_CLS( A, B, C, Q, R, x0, P0 );

    A  = [1,0;
          0,1;];
    B  = [];
    C  = [1,0;
          0,1];
    Q  = Noise_proc_var_mat;
    R  = Noise_meas_var_mat;
    x0 = Initial_mc_col;
    P0 = Initial_mc_var_mat;
    
    OBJ.KF = my_KF_general_CLS( A, B, C, Q, R, x0, P0 );  
end % my_laneKF_CLS()
%-------------------------------------------------------------------------- 
function  OBJ = pred_and_correct(OBJ, BW, tf_found)
    
    % use KF to PREDICT
    OBJ.KF     = OBJ.KF.predict();

    % now do we have a measurement to allow a CORRECT
    lane_O = lane_info_CLS(BW, tf_found);
    if( lane_O.is_detected() )
        lane_O = lane_O.calc_info();
    
        [m,c]  = lane_O.get_mc();
        
        y_meas = [m;c];
        
        OBJ.KF = OBJ.KF.correct(y_meas);
    end
   
    OBJ.mc_col    = OBJ.KF.x;
    %OBJ.x_col_mat = [OBJ.x_col_mat, OBJ.mc_col];
    
    % and store the size of the image we're processing
    OBJ.img_num_rows = size(BW,1);
    OBJ.img_num_cols = size(BW,2);
end % pred_and_correct()
%-------------------------------------------------------------------------- 
function  mc_col = get_mc_col(OBJ)
          mc_col = OBJ.mc_col;
end
%-------------------------------------------------------------------------- 
function plot(OBJ, hax, linspec)
% ALLOWED usage:
%  >> OBJ.plot(hax)
%  >> OBJ.plot(hax,'.r')

    if(1 ==coder.target('MATLAB') )
        if( 2==nargin )
            linspec = '.r-';
        end

        mc_col = OBJ.mc_col;
        if( isempty(mc_col) )
            return
        end

        m = mc_col(1);
        c = mc_col(2);
        % OK: we have some m,c data
        %  y = m.x + c --->  x = (y-c)/m
        % I'm interested in 2 data points:
        %  a.) when y = 120, what is x ?
        %  b.) when y = 240, what is x ?

        y_HALF = OBJ.img_num_rows/2;
        y_MAX  = OBJ.img_num_rows;

        P1 = [(y_HALF-c)/m ; y_HALF];
        P2 = [(y_MAX-c)/m ;  y_MAX];

        x  = [P1(1); P2(1)];
        y  = [P1(2); P2(2)];

        TAG = OBJ.plot_TAG;
        hL = findall(hax,'Tag',TAG);

        if( isempty(hL) )
           hold(hax,'on');
           plot(hax,x,y,linspec,'MarkerSize',22, 'Tag',TAG);
        else
           hL.XData = x;
           hL.YData = y;
        end
    end % if(1 ==coder.target('MATLAB') )
    
end % plot()
%--------------------------------------------------------------------------
end % methods
%_#########################################################################

%-------------------------------------------------------------------------- 
%-------------------------------------------------------------------------- 
%-------------------------------------------------------------------------- 
%-------------------------------------------------------------------------- 
%-------------------------------------------------------------------------- 
end % classdef
%_#########################################################################
% END CLASSDEF
%_#########################################################################
