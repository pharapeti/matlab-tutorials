function bh_car_startup()
    
    % Add some folders to the MATLAB search path
    p = mfilename('fullpath');
    [folder,name,ext] = fileparts(p);

    addpath([folder],                        '-begin');
    addpath([folder,filesep,'THE_LIBRARY'],  '-begin');
    addpath([folder,filesep,'THE_LIBRARY',filesep,'my_apps'],         '-begin');
    addpath([folder,filesep,'THE_LIBRARY',filesep,'my_car_classes'],  '-begin');
    addpath([folder,filesep,'THE_LIBRARY',filesep,'my_car_sfuns'],    '-begin');
    addpath([folder,filesep,'THE_LIBRARY',filesep,'my_car_funcs'],    '-begin');
    addpath([folder,filesep,'THE_LIBRARY',filesep,'my_cv_classes'],   '-begin');
    addpath([folder,filesep,'THE_LIBRARY',filesep,'my_cv_funcs'],     '-begin');
    addpath([folder,filesep,'THE_LIBRARY',filesep,'my_SL_models'],    '-begin');
    addpath([folder,filesep,'THE_PICS',filesep,'car'],                '-begin');
    addpath([folder,filesep,'THE_PICS',filesep,'cv'],                 '-begin');
    addpath([folder,filesep,'THE_MOVIES'],                            '-begin');
    addpath([folder,filesep,'THE_UTILITIES'],'-begin');
    addpath([folder,filesep,'THE_DATA'],     '-begin');
    addpath([folder,filesep,'THE_REFS'],     '-begin');

    % echo the first few elements of our search path
    sp             = path;
    TGT_SPLIT_CHAR = pathsep;
    C              = strsplit(sp, TGT_SPLIT_CHAR);
    
    fprintf('\n %s', repmat('*',1,50) );
    fprintf('\n Just added the following folders to the ');
    fprintf('\n HEAD of your search path: \n');
    fprintf('\n    ---> %s', C{1:15});
    fprintf('\n %s', repmat('*',1,50) );
    fprintf('\n ... we are finished HERE ---> %s\n',mfilename);
        
    % assert that we have a new enough version to run this demo
    % R2017b is the minimum release and corresponds to MATLAB 
    % version 9.3
    MIN_required_ML_version = '9.3';
    if(verLessThan('MATLAB',MIN_required_ML_version))
          % inform the user that he needs a NEWER release and then exit
          error('###_ERROR:  you need at least R2017b to run this demo');
    end
       
    %% launch the DEMO selector app
    bh_DRC_demo_app
    
end
%_#########################################################################
% function LOC_assert_version(your_version_str)
%   %your_version_str   = version('-release');
%   is_too_old_version = verLessThan('matlab', 'R2016a');
%   if(is_too_old_version)
%       tmp_str = sprintf('Your MATLAB release is: <%s>\n But this DEMO needs at least <R2016a>',your_version_str);
%       errordlg(tmp_str,'RELEASE CHECK', 'modal');
%       % throw an error
%       error('###_ERROR:  you need at least R2016a to run this demo');
%   end
% end
%--------------------------------------------------------------------------

