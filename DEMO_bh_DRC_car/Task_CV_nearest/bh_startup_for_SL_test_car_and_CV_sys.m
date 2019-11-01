
% run script to load params into BASE workspace
bh_3dof_4wheel_car_sim_params

% open SIMULINK model
bh_SL_test_car_and_CV_sys

% create some BUS objects needed by the model
bh_create_cv_neareset_BUS_OBJ_for_simulink();

% and we're done
fprintf('\n\n### just did a preload TASK !');
