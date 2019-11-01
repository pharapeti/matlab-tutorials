function bh_solenoid_startup()
    
    % Add some folders to the MATLAB search path
    p = mfilename('fullpath');
    [folder,name,ext] = fileparts(p);

    addpath([folder],                              '-begin');
    addpath([folder,filesep,'THE_PICS'],           '-begin');
    addpath([folder,filesep,'THE_PRES'],           '-begin');
    addpath([folder,filesep,'THE_LIBRARY'],        '-begin');
    addpath([folder,filesep,'MODELS'],             '-begin');
    addpath([folder,filesep,'DATA_FILES'],         '-begin');
    addpath([folder,filesep,'HAND_DERIVATION'],    '-begin');  
    
    % echo the first few elements of our search path
    sp             = path;
    TGT_SPLIT_CHAR = pathsep;
    C              = strsplit(sp, TGT_SPLIT_CHAR);
    
    clc
    fprintf('\n %s', repmat('*',1,50) );
    fprintf('\n Just added the following folders to the ');
    fprintf('\n HEAD of your search path: \n');
    fprintf('\n    ---> %s', C{1:7});
    fprintf('\n %s', repmat('*',1,50) );
    fprintf('\n ... we are finished HERE ---> %s\n',mfilename);
        
    % assert that we have a new enough version to run this demo
    % R2016b is the minimum release and corresponds to MATLAB 
    % version 9.1
    MIN_required_ML_version = '9.1';
    if(verLessThan('MATLAB',MIN_required_ML_version))
          % inform the user that he needs a NEWER release and then exit
          error('###_ERROR:  you need at least R2016b to run this demo');
    end
       
    % If we get to here, then launch the demo selector APP
    h = findall(0,'Tag', 'TAG_APP_FIGURE_SOLENOID');
    if(isempty(h))
       bh_solenoid_app
    end
end
%_#########################################################################
