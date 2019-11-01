function [BLUE_s, YELL_s, PURP_s] = bh_my_ALGORITHM_for_codegen(I, tf_do_init, marker_s) %#codegen
% ALLOWED USAGE:
%  >> [BLUE_s, YELL_s, PURP_s] = bh_my_ALGORITHM_for_codegen(I, tf_do_init, marker_s)

persistent OBJ_ybp
persistent KF_b_OBJ
persistent KF_y_OBJ
persistent fr_count
persistent hax
persistent hi

if(isempty(fr_count))
    fr_count = 0;
end

% *************************************************************************
%      do OBJECT INITIALIZATION
% *************************************************************************
if(true==tf_do_init || isempty(OBJ_ybp) || isempty(KF_b_OBJ) || isempty(KF_y_OBJ) )
    fr_count = 0;
    
    % create an instance of the ybp finder
    OBJ_ybp  = ybp_finder_CLS(marker_s);

    % create an instance of the Kalman filter
    Initial_mc_col      = [0;120];  % [x,y]
    Initial_mc_var_mat  = [10,0; 0,10].^2; % variance of initial estimates
    Noise_proc_var_mat  = [10,0; 0,10].^2; % process noise covariance matrix
    Noise_meas_var_mat  = [ 2,0; 0, 2].^2; % measurement noise covariance matrix

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

% update the frame counter
fr_count = fr_count + 1;

% *************************************************************************
%      CLASSIFY stuff
% *************************************************************************
OBJ_ybp = OBJ_ybp.classify(I);
%OBJ_ybp = OBJ_ybp.classify_version2(I);


[ BLUE_s, YELL_s, PURP_s ] = OBJ_ybp.find_all_stuff();

%  propagate the Kalman Filter
KF_b_OBJ = KF_b_OBJ.pred_and_correct(BLUE_s.BW, BLUE_s.tf_is_detected);
KF_y_OBJ = KF_y_OBJ.pred_and_correct(YELL_s.BW, YELL_s.tf_is_detected);

% *************************************************************************
%      Take care of the outputs
% *************************************************************************

% *************************************************************************
%      VISUALIZE  stuff
% *************************************************************************
if(1 ==coder.target('MATLAB') )
    
    num_ROWS = size(I,1);
    num_COLS = size(I,2);
       
    BW = BLUE_s.BW | YELL_s.BW | PURP_s.BW;
    b_pix = find(true==BLUE_s.BW);
    y_pix = find(true==YELL_s.BW);
    p_pix = find(true==PURP_s.BW);
    
    RGB_mat  = bh_create_byp_RGB_mat(  num_ROWS, num_COLS, ...
                                          b_pix,  ...
                                          y_pix,  ...
                                          p_pix);
    
    hf = findobj('Type', 'figure', 'Tag', 'TAG_FIG_BH_MY_CV');
    if( isempty(hf) )
        figure('Tag', 'TAG_FIG_BH_MY_CV');
        THE_hax(1) = subplot(2,2,1, 'Tag', 'TAG_HX_1');
        THE_hax(2) = subplot(2,2,2, 'Tag', 'TAG_HX_2');
        THE_hax(3) = subplot(2,2,3, 'Tag', 'TAG_HX_3');
        THE_hax(4) = subplot(2,2,4, 'Tag', 'TAG_HX_4'); 
        hax = THE_hax;
    end
        
    % plot stuff - the if-else makes the plotting faster ! (DN tip)
    if isempty(get(hax(1),'Children'))
         THE_hi(1) = imshow(I,       'Parent', hax(1));
         THE_hi(2) = imshow(RGB_mat, 'Parent', hax(2));
         THE_hi(3) = imshow(RGB_mat, 'Parent', hax(3));
         THE_hi(4) = imshow(BW,      'Parent', hax(4));   
         
         hi = THE_hi;
    else
         hi(1).CData = I;
         hi(2).CData = RGB_mat;
         hi(3).CData = RGB_mat;
         hi(4).CData = BW;
    end
    drawnow

    % refresh the plots
    KF_b_OBJ.plot(hax(3), '.r-');
    KF_y_OBJ.plot(hax(3), '.g-');
    title( hax(1), sprintf('FRAME = %3d',fr_count) )
end


end % bh_my_ALGORITHM_for_codegen(I)
%-#########################################################################
% E N D    O F    M A I N    F U N C T I O N
%-#########################################################################

