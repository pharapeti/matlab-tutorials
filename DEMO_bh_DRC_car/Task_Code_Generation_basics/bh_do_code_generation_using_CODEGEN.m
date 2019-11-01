%% PURPOSE:
% We'll use the MATLAB Coder to convert our MATLAB functions
% into standalone C-code
%
% ATTENTION:  This script takes 45 seconds to run

%% STEP_01:  Run MATLAB algorithm test harness
bh_test_harness_for_algorithm

% the test harness creates INPUTS for the function that we want to 
% convert to C, ie:
%
%  [BLUE_s, YELL_s, PURP_s] = ...
%               bh_my_detect_ALGORITHM_for_codegen(I, tf_init, marker_s);
%
%   Name            Size                Bytes  Class      Attributes
% 
%   I             240x320x3            230400  uint8                
%   marker_s        1x1                   656  struct               
%   tf_init         1x1                     1  logical              

%% STEP_02:  configure and invoke the MATLAB Coder

% Create configuration object 
cfg = coder.config('lib','ecoder',true);
cfg.GenerateCodeMetricsReport = true;
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = false;
cfg.MATLABSourceComments = true;
cfg.GenCodeOnly = true;

% Define argument types for entry-point 'bh_my_detect_ALGORITHM_for_codegen'
my_example_ARGS = {I, tf_init, marker_s};

% Invoke MATLAB Coder.
codegen -config cfg bh_my_detect_ALGORITHM_for_codegen -args my_example_ARGS -nargout 3  -launchreport

%% and we're done
fprintf('\n ... we are finished here');