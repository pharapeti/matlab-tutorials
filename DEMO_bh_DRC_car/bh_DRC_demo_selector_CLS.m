classdef bh_DRC_demo_selector_CLS
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        ROOT_FOLDER = '';
        REF_FOLDER  = '';
    end
    
    methods
        function OBJ = bh_DRC_demo_selector_CLS()
            p = mfilename('fullpath');
            [pathstr,~,~] = fileparts(p);
            OBJ.ROOT_FOLDER = pathstr;
            OBJ.REF_FOLDER  = pathstr;
        end
        %------------------------------------------------------------------
        function clear_base(OBJ)
            LOC_clear_base();
        end
        %------------------------------------------------------------------
        function close_editor(OBJ)
            LOC_close_M_editor();
        end
        %------------------------------------------------------------------
        function open_pres(OBJ)
            PPT_FILE = [OBJ.ROOT_FOLDER, filesep, 'bh_droid_racing_demo_GUIDE.pptx'];
            PDF_FILE = [OBJ.ROOT_FOLDER, filesep, 'bh_droid_racing_demo_GUIDE.pdf'];
            
            if exist(PPT_FILE)
                open(PPT_FILE);
                return
            end
            if exist(PDF_FILE)
                open(PDF_FILE);
                return
            end
                       
        end % open_pres
        %------------------------------------------------------------------ 
        function position_all_MD_on_screen(OBJ)
            h_MD_list = find_system('type','block_diagram');
            % don't preocess library blockdiagrams
            isLib     = bdIsLibrary(h_MD_list);
            h_MD_list = h_MD_list(~isLib);
            %OK, so we should only have models (NOT libraries) left.
            for kk=1:length(h_MD_list)
                hMD = h_MD_list(kk);
                if(iscell(hMD))
                    hMD = hMD{1};
                end
                LOC_place_SLMODEL_onscreen(hMD)
            end
        end
        %------------------------------------------------------------------
       function task_button_play_movie(OBJ,ID_STR)
            ID_STR = string(ID_STR);
            ID_STR = upper(ID_STR);
            
            switch(ID_STR)
                case "TEASER"
                    fname = 'my_car_teaser.mp4';
                otherwise
                    error('###_ERROR: UNknown ID_STR !');
            end
                       
            % now play the VIDEO file
            try
                   if(ispc)
                       winopen(fname);
                   else
                       error('ERR: perhaps linux OR a mac');
                   end
            catch
                   % try playing it using Image proc tbox function
                   implay(fname);
            end
            
        end        
        %------------------------------------------------------------------
        %_#################################################################
        %    C A R     M O D E L     T A B
        %_#################################################################
        %------------------------------------------------------------------
        function task_car_derivation(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_car_eom_4wheel_3dof']);

                 edit('bh_3dof_4wheel_car_EOM_derive.mlx');
        end
        %------------------------------------------------------------------
        function task_car_model_eom(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_car_eom_4wheel_3dof']);

                 open_system('bh_COMPONENT_3dof_4wheel_car_model')
        end
        %------------------------------------------------------------------ 
        function task_car_model_parameters(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_car_eom_4wheel_3dof']);

                  edit('bh_3dof_4wheel_car_sim_params.mlx')
        end
        %------------------------------------------------------------------ 
        function task_car_model_simulate(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_car_eom_4wheel_3dof']);

                  evalin('base', 'bh_startup_for_explore_car_eom')
        end
        %------------------------------------------------------------------ 
        function task_car_model_evassive_mans(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_car_eom_4wheel_3dof']);

                  evalin('base', 'bh_startup_for_explore_speed_control_AND_manoeuvres')
        end
        %------------------------------------------------------------------
        function task_car_automate_evassive_mans(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_car_eom_4wheel_3dof']);

                 edit('bh_explore_evasive_manoeuvre.mlx');
        end
        %------------------------------------------------------------------
        %_#################################################################
        %    C O M P     V I S I O N     T A B
        %_#################################################################
        function task_cv_nn_concept(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_CV_nearest']);

                 edit('bh_near_algorithm_CONCEPT_DRC.mlx');
        end
        %------------------------------------------------------------------
        function task_cv_nn_prototype(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_CV_nearest']);

                 edit('bh_test_kf_video_for_CODEGEN.m', ...
                      'bh_my_detect_ALGORITHM_for_codegen.m', ...
                      'bh_my_lane_preprocess_mask.m', ...
                      'bh_my_track_ALGORITHM_for_codegen.m' );
                  
                  % bring focus to this one
                  edit('bh_test_kf_video_for_CODEGEN')
        end
        %------------------------------------------------------------------
        function task_cv_nn_codegen(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_CV_nearest']);

                 open bh_my_detect_ALGORITHM_for_codegen.prj
        end
        %------------------------------------------------------------------
        function task_cv_nn_system_model(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_CV_nearest']);

                 evalin('base', 'bh_startup_for_SL_test_car_and_CV_sys')
        end
        %------------------------------------------------------------------
        %_#################################################################
        %    V I E W E R S       T A B
        %_#################################################################
        function task_viewers_car_concept(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_viewer_4wheel_3dof']);

                 edit('bh_test_bh_3dof_4wheel_vehicle_viewer.m', ...
                      'bh_3dof_4wheel_vehicle_viewer_CLS.m');
                 
                 edit('bh_test_bh_3dof_4wheel_vehicle_viewer.m');
        end
        %------------------------------------------------------------------
        function task_viewers_car_SL(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_viewer_4wheel_3dof']);
                 
                 % open simulink model
                 evalin('base', 'bh_test_car_viewer');
        end
        %------------------------------------------------------------------
        function task_viewers_arena_concept(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_viewer_arena_AND_virtual_camera']);
                 
                 % open simulink model
                 edit('bh_test_arena.m', 'bh_3dof_4wheel_vehicle_arena_CLS.m');
                 edit('bh_test_arena.m');
                 
        end
        %------------------------------------------------------------------
        function task_viewers_camera_concept(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_viewer_arena_AND_virtual_camera']);
                 
                 % open simulink model
                 edit('bh_test_arena_and_cam.m', ...
                      'bh_virtual_car_camera_CLS.m', ...
                      'bh_3dof_4wheel_vehicle_arena_CLS.m' );
                  
                 edit('bh_test_arena_and_cam.m') 
        end
        %------------------------------------------------------------------
        function task_viewers_camera_SL(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_viewer_arena_AND_virtual_camera']);
                 
                 % open simulink model
                 evalin('base', 'bh_test_virtual_camera_model');
        end
        %------------------------------------------------------------------
        %_#################################################################
        %    F I L T E R_KF       T A B
        %_#################################################################
        function task_filter_kf_concept(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_KF_develop']);

                 edit('bh_test_vanilla_KF_2dof_mech.mlx', ...
                      'my_KF_general_CLS.m');
                 
                 edit('bh_test_vanilla_KF_2dof_mech.mlx'); 
        end
        %------------------------------------------------------------------
        function task_filter_kf_ROUND_wheel(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_KF_develop']);

                 % launch HELP browser
                 doc
                 doc kalman filter
        end
        %------------------------------------------------------------------
        %_#################################################################
        %    C O D E G E N       T A B
        %_#################################################################
        function task_codegen_algorithm(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_Code_Generation_basics']);

                 edit('bh_test_harness_for_algorithm.m', ...
                      'bh_my_detect_ALGORITHM_for_codegen.m');
                 
                 edit('bh_test_harness_for_algorithm.m'); 
        end
        %------------------------------------------------------------------
         function task_codegen_using_cg(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_Code_Generation_basics']);

                 edit('bh_do_code_generation_using_CODEGEN.m');
        end
        %------------------------------------------------------------------
         function task_codegen_using_app(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_Code_Generation_basics']);

                 edit('bh_do_code_generation_using_APP.m');
        end
        %------------------------------------------------------------------
         function task_codegen_getting_started(OBJ)
               web(fullfile(docroot, 'coder/getting-started-with-matlab-coder.html'))                
        end
        %------------------------------------------------------------------
         function task_codegen_using_inside_your_software(OBJ)
               web(fullfile(docroot, 'coder/ug/using-cc-code-that-matlab-coder-generates.html'));             
        end
        %------------------------------------------------------------------
        %_#################################################################
        %    H E L P       T A B
        %_#################################################################
        function open_DRC_SLIDE(OBJ)
            cd([OBJ.ROOT_FOLDER]);
            open('bh_DRC_comp_slide.pdf')
        end
        %------------------------------------------------------------------
    end % METHODS
    
end  % CLASSDEF
%_#########################################################################
function LOC_clear_base()
   evalin('base', 'clear all; clc');
   
   % close any open figures
   close all
end
%**************************************************************************
function LOC_close_M_editor
%close the M-file Editor
  evalin('base',['com.mathworks.mlservices.MatlabDesktopServices.getDesktop().closeGroup(''Editor'')']);
end
%**************************************************************************
function LOC_place_SLMODEL_onscreen(hMD)

    % what is the maxscreensize of the COMPUTER
    scr_max_pos    = get(0,'ScreenSize');
    scr_max_width  = scr_max_pos(3);
    scr_max_height = scr_max_pos(4);

    tgt_md_width  = 0.8*scr_max_width;
    tgt_md_height = 0.8*scr_max_height;

    % what is current MODEL window location
    md_Loc = get_param(hMD,'Location');

    % set the new MODEl location
    set_param(hMD,'Location',[20 20 tgt_md_width tgt_md_height]);
end
%**************************************************************************
function  LOC_place_scope_on_screen( scope_name )
    h = findall(0,'Type', 'figure', 'Name', scope_name);
    if(isempty(h))
        return
    end
    
    h(1).Position = [2 41 647 634];   
end
%**************************************************************************
function  LOC_close_all_but_root_level_of_model(THE_MODEL)
    Blocks_List = find_system(THE_MODEL);
    Blocks_To_Close = Blocks_List;

    for III=length(Blocks_List):-1:1
        if isempty(strfind(Blocks_List{III},'/'))
            Blocks_To_Close(III)=[];
        end
    end

    close_system(Blocks_To_Close)
end
%**************************************************************************

