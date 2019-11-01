%% PURPOSE:
% We'll use the MATLAB Coder app to convert our MATLAB functions
% into standalone C-code

%% Open an existing saved PROJECT with the Coder app
proj_file = 'bh_my_detect_ALGORITHM_for_codegen.prj';

coder('-open', proj_file)

%% Open a previously created codegen report
open([pwd, filesep, 'codegen', filesep,'lib', filesep, 'bh_my_detect_ALGORITHM_for_codegen', filesep, 'html', filesep,'report.mldatx'])