function [BLUE_mc_col, YELL_mc_col] = ...
     bh_my_track_ALGORITHM_for_codegen(BLUE_s, YELL_s, tf_do_init) %#codegen
% ALLOWED USAGE:
%  >> [BLUE_LT_s, YELL_LT_s] = bh_my_track_ALGORITHM_for_codegen(BLUE_s, YELL_s, tf_do_init)

persistent KF_b_OBJ
persistent KF_y_OBJ
persistent hax

% *************************************************************************
%      do OBJECT INITIALIZATION
% *************************************************************************
if(true==tf_do_init || isempty(KF_b_OBJ) || isempty(KF_y_OBJ) )
    
    % create an instance of the Kalman filter
    Initial_mc_col      = [0;120];  % [x,y]
    Initial_mc_var_mat  = [10,0; 0,10].^2; % variance of initial estimates
    Noise_proc_var_mat  = [10,0; 0,10].^2; % process noise covariance matrix
    Noise_meas_var_mat  = [ 2,0; 0, 2].^2; % measurement noise covariance matrix
    %Noise_meas_var_mat  = [ 1,0; 0, 1].^2; % measurement noise covariance matrix

    KF_b_OBJ = my_laneKF_CLS( Initial_mc_col,      ...
                              Initial_mc_var_mat, ...
                              Noise_proc_var_mat, ...
                              Noise_meas_var_mat );
    KF_b_OBJ.plot_TAG = 'TAG_KF_b';

    KF_y_OBJ = my_laneKF_CLS( Initial_mc_col,      ...
                              Initial_mc_var_mat, ...
                              Noise_proc_var_mat, ...
                              Noise_meas_var_mat );

    KF_y_OBJ.plot_TAG = 'TAG_KF_y';
    
end % if(true==tf_do_init)

% *************************************************************************
%      FILTER stuff
% *************************************************************************

%  propagate the Kalman Filter
KF_b_OBJ = KF_b_OBJ.pred_and_correct(BLUE_s.BW, BLUE_s.tf_is_detected);
KF_y_OBJ = KF_y_OBJ.pred_and_correct(YELL_s.BW, YELL_s.tf_is_detected);

% *************************************************************************
%      Take care of the outputs
% *************************************************************************

BLUE_mc_col = KF_b_OBJ.get_mc_col(); 
YELL_mc_col = KF_y_OBJ.get_mc_col();

% *************************************************************************
%      VISUALIZE  stuff
% *************************************************************************
if(1 ==coder.target('MATLAB') )
   
    the_hax = findobj('Tag', 'TAG_HX_3_TGT_FOR_LINE_TRACK');
    
    if(~isempty(the_hax))
        KF_b_OBJ.plot(the_hax, '.r-');
        KF_y_OBJ.plot(the_hax, '.g-');
        
        % refresh the plots
        drawnow
    end
end


end % bh_my_track_ALGORITHM_for_codegen()
%-#########################################################################
% E N D    O F    M A I N    F U N C T I O N
%-#########################################################################

