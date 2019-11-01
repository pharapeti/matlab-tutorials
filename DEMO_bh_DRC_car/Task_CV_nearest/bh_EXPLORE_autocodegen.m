function bh_EXPLORE_autocodegen()

clear all
%---------------------------------------------
% define IMAGE size
IMG_SIZE  = [240 320];

%---------------------------------------------
fprintf('\n starting MEX build: ');

LOC_do_mex_build(IMG_SIZE)
fprintf('\n -----> finished mex build !: ');
clc

%---------------------------------------------
fprintf('\n starting MATLAB run: ');
tic;LOC_do_ML_run(IMG_SIZE);  toc

%---------------------------------------------
fprintf('\n starting MEX run: ');
tic;LOC_do_MEX_run(IMG_SIZE); toc

end
%--------------------------------------------------------------------------
function LOC_do_ML_run(IMG_SIZE)
    %THE_MOV_FILE = 'Droid Racing Challenge 2017 - Test Video  Initial Section, 11 AM, Sunny.mp4';
    THE_MOV_FILE = 'Droid Racing Challenge 2017 - Test Video  Initial Section, 11 AM, REVERSE 2 2.mp4';
    v            = VideoReader(THE_MOV_FILE);
    fr_count = 0;
    while hasFrame(v)
        fr_count = 1 + fr_count;
        I = readFrame(v);

        I = imresize(I,IMG_SIZE);

        if(1==fr_count)
            tf_init = true;
            marker_OBJ = create_target_markers_CLS();
            marker_s   = marker_OBJ.get_struct();
        else
            tf_init = false;
        end

        % OK: call the algorithm
        [BLUE_s, YELL_s, PURP_s] = bh_my_detect_ALGORITHM_for_codegen(I,tf_init,marker_s);
    end
end
%--------------------------------------------------------------------------
function LOC_do_MEX_run(IMG_SIZE)
    %THE_MOV_FILE = 'Droid Racing Challenge 2017 - Test Video  Initial Section, 11 AM, Sunny.mp4';
    THE_MOV_FILE = 'Droid Racing Challenge 2017 - Test Video  Initial Section, 11 AM, REVERSE 2 2.mp4';
    v            = VideoReader(THE_MOV_FILE);
    fr_count = 0;
    while hasFrame(v)
        fr_count = 1 + fr_count;
        I = readFrame(v);

        I = imresize(I,IMG_SIZE);

        if(1==fr_count)
            tf_init = true;
            marker_OBJ = create_target_markers_CLS();
            marker_s   = marker_OBJ.get_struct();
        else
            tf_init = false;
        end

        % OK: call the algorithm
        [BLUE_s, YELL_s, PURP_s] = bh_my_detect_ALGORITHM_for_codegen_mex(I,tf_init,marker_s);
    end
end
%--------------------------------------------------------------------------
function LOC_do_mex_build(IMG_SIZE)
    % Create configuration object of class 'coder.MexCodeConfig'.
    cfg = coder.config('mex');
    cfg.MATLABSourceComments = true;
    cfg.GenerateReport = true;
    cfg.ReportPotentialDifferences = false;

    % Define argument types for entry-point 'bh_my_detect_ALGORITHM_for_codegen'.
    ARGS = cell(1,1);
    ARGS{1} = cell(3,1);
    ARGS{1}{1} = coder.typeof(uint8(0),[IMG_SIZE,  3]);
    ARGS{1}{2} = coder.typeof(false);
    ARGS_1_3 = struct;
    ARGS_1_3.nColors = coder.typeof(0);
    ARGS_1_3.color_labels = coder.typeof(0,[1 5]);
    ARGS_1_3.color_markers = coder.typeof(0,[5 2]);
    ARGS{1}{3} = coder.typeof(ARGS_1_3);

    % Invoke MATLAB Coder.
    codegen -config cfg bh_my_detect_ALGORITHM_for_codegen -args ARGS{1} -nargout 3
end

