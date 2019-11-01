classdef bh_smd_demo_selector_CLS
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        ROOT_FOLDER = '';
        REF_FOLDER  = '';
    end
    
    methods
function OBJ = bh_smd_demo_selector_CLS()
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

%_#################################################################
%    1-DOF    T A B
%_#################################################################
function DK_1dof_numeric(OBJ,action_str)
   action_str = upper(string(action_str));

   LOC_clear_base();   LOC_close_M_editor
   cd([OBJ.ROOT_FOLDER,filesep,'THE_SMD_1_DOF']);

   switch(action_str)
       case "NOTHING"
           return;
       case "STEP_RESPONSE"
           edit('bh_EXAMPLE_ODE_1dof_mech_sys_NUM_only.mlx');
       otherwise
           error('###_ERR: UNknown action str <%s>',action_str);
   end
end
%------------------------------------------------------------------
function DK_1dof_symbolic(OBJ,action_str)
   action_str = upper(string(action_str));

   LOC_clear_base();   LOC_close_M_editor
   cd([OBJ.ROOT_FOLDER,filesep,'THE_SMD_1_DOF']);

   switch(action_str)
       case "NOTHING"
           return;
       case "HOMOG_AND_STEP"
           edit('bh_EXAMPLE_ODE_1dof_mech_sys_SYM_and_NUM.mlx');
       otherwise
           error('###_ERR: UNknown action str <%s>',action_str);
   end

end
%------------------------------------------------------------------
function DK_1dof_simulink(OBJ,action_str)
   action_str = upper(string(action_str));

   LOC_clear_base();   LOC_close_M_editor
   cd([OBJ.ROOT_FOLDER,filesep,'THE_SMD_1_DOF']);

   switch(action_str)
       case "NOTHING"
           return;
       case "3_WAYS"
             % load some parameters into the workspace
             evalin('base', 'bh_script_1dof_params')

             % open the model
             MODEL = 'bh_1dof_hello';
             open_system(MODEL);
             h_MD = bdroot;
       case "COMPARE"
             % load some parameters into the workspace
             evalin('base', 'bh_script_1dof_params')

             % open the model
             MODEL = 'bh_1dof_compare_models';
             open_system(MODEL);
             h_MD = bdroot;
       otherwise
           error('###_ERR: UNknown action str <%s>',action_str);
   end

end
%------------------------------------------------------------------
function DK_1dof_lab(OBJ,action_str)
    action_str = upper(string(action_str));

   LOC_clear_base();   LOC_close_M_editor
   cd([OBJ.ROOT_FOLDER,filesep,'THE_LAB']);

   switch(action_str)
       case "NOTHING"
           return;
       case "FUNCTION_HANDLES"
           edit('bh_function_handle_refresher.mlx');
       otherwise
           error('###_ERR: UNknown action str <%s>',action_str);
   end     
end
%_#################################################################
%    2-DOF    T A B
%_#################################################################
function DK_2dof_numeric(OBJ,action_str)
   action_str = upper(string(action_str));

   LOC_clear_base();   LOC_close_M_editor
   cd([OBJ.ROOT_FOLDER,filesep,'THE_SMD_2_DOF']);

   switch(action_str)
       case "NOTHING"
           return;
       case "STEP_RESPONSE"
           edit('bh_EXAMPLE_ODE_2dof_mech_sys_NUM_only.mlx');
       otherwise
           error('###_ERR: UNknown action str <%s>',action_str);
   end
end
%------------------------------------------------------------------ 
function DK_2dof_symbolic(OBJ,action_str)
   action_str = upper(string(action_str));

   LOC_clear_base();   LOC_close_M_editor
   cd([OBJ.ROOT_FOLDER,filesep,'THE_SMD_1_DOF']);

   switch(action_str)
       case "NOTHING"
           return;
       case "HOMOGENEOUS"
           edit('bh_SYM_2dof_example_homogeneous.mlx');
       case "STEP_RESPONSE"
           edit('bh_SYM_2dof_example_step_responses.mlx');
       case "BLOCK_CREATION"
           edit('bh_SYM_2dof_example_auto_create_block.mlx');
       otherwise
           error('###_ERR: UNknown action str <%s>',action_str);
   end

end
%------------------------------------------------------------------
function DK_2dof_simulink(OBJ,action_str)
   action_str = upper(string(action_str));

   LOC_clear_base();   LOC_close_M_editor
   cd([OBJ.ROOT_FOLDER,filesep,'THE_SMD_1_DOF']);

   switch(action_str)
       case "NOTHING"
           return;
       case "SIMULINK"
             % load some parameters into the workspace
             evalin('base', 'bh_script_2dof_params')
             edit('bh_script_2dof_params');
             
             % open the model
             MODEL = 'bh_2dof_ODE_model';
             open_system(MODEL);
             h_MD = bdroot;
       case "SIMSCAPE"
             % load some parameters into the workspace
             evalin('base', 'bh_script_2dof_params')
             edit('bh_script_2dof_params');
             
             % open the model
             MODEL = 'bh_2dof_simscape_model';
             open_system(MODEL);
             h_MD = bdroot;
       case "COMPARE"
             % load some parameters into the workspace
             evalin('base', 'bh_script_2dof_params')
             edit('bh_script_2dof_params');
             
             % open the model
             MODEL = 'bh_2dof_compare_models';
             open_system(MODEL);
             h_MD = bdroot;           
       otherwise
           error('###_ERR: UNknown action str <%s>',action_str);
   end

end
%------------------------------------------------------------------
function DK_2dof_lab(OBJ,action_str)
   action_str = upper(string(action_str));

   LOC_clear_base();   LOC_close_M_editor
   cd([OBJ.ROOT_FOLDER,filesep,'THE_LAB']);

   switch(action_str)
       case "NOTHING"
           return;
       case "INTEGRATION_CONCEPT"
             % open the model
             MODEL = 'bh_integration_concept';
             open_system(MODEL);           
       case "SIMULINK_MODEL"
             % load some parameters into the workspace
             evalin('base', 'bh_script_2dof_params')
             edit('bh_script_2dof_params');
             
             % open the model
             MODEL = 'bh_2dof_STARTING_POINT_MODEL_SIMULINK';
             open_system(MODEL);
             h_MD = bdroot;
       case "SIMSCAPE_MODEL"
             % load some parameters into the workspace
             evalin('base', 'bh_script_2dof_params')
             edit('bh_script_2dof_params');
             
             % open the model
             MODEL = 'bh_2dof_STARTING_POINT_MODEL_SIMSCAPE';
             open_system(MODEL);
             h_MD = bdroot;
       otherwise
           error('###_ERR: UNknown action str <%s>',action_str);
   end

end
%------------------------------------------------------------------
end % methods  
end  % CLASSDEF
%_#########################################################################
function LOC_clear_base()
   evalin('base', 'clear all; clc')
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
% function LOC_2dof_lab_file_transfer(OBJ,action_str)
% 
%    switch(action_str)
%        case "SIMULINK_MODEL"
%            source_file    = 'bh_2dof_STARTING_POINT_MODEL_SIMULINK.slx';
%            tmp_str        = [OBJ.ROOT_FOLDER,filesep,'THE_SMD_2_DOF'];
%            tmp_str        = [tmp_str, filesep,'STARTING_MODEL_TEMPLATES'];
%            source_file_fp = [tmp_str, filesep, source_file];
%            dest_file      = 'my_2dof_slink_model.slx';
%        case "SIMSCAPE_MODEL"
%            source_file    = 'bh_2dof_STARTING_POINT_MODEL_SIMSCAPE.slx';
%            tmp_str        = [OBJ.ROOT_FOLDER,filesep,'THE_SMD_2_DOF'];
%            tmp_str        = [tmp_str, filesep,'STARTING_MODEL_TEMPLATES'];
%            source_file_fp = [tmp_str, filesep, source_file];
%            dest_file      = 'my_2dof_scape_model.slx';           
%        otherwise
%            error('###_ERR: UNknown action str <%s>',action_str);
%    end
% 
%    DEST_folder    = [OBJ.ROOT_FOLDER,filesep,'THE_LAB'];
%    DEST_file_fp   = [DEST_folder, filesep, dest_file];
%    
%    % does the destination file already exist ?
%    tf_it_exists = ls(DEST_file_fp);
%    if(true==tf_it_exists)
%        a_str = LOC_get_datestr();
%        [~,name,ext] = fileparts(dest_file);
%        dest_file = [name,'_', a_str, ext];
%        DEST_file_fp = [DEST_folder, filesep, dest_file];
%    end
%    
%    % now copy the source file to the destination file
%    my_status = copyfile(source_file_fp, DEST_file_fp);
%    if(false==my_status)
%        tmp_str = sprintf('HEY!: I could NOT copy the file\n<%s>',dest_file);
%        warndlg(tmp_str)
%    end
% end
% %**************************************************************************
% function a_str = LOC_get_datestr()
%   a_str = datestr(now,31);
%   a_str = strrep(a_str,'-','_');
%   a_str = strrep(a_str,' ','_');
%   a_str = strrep(a_str,':','_');
% end
% %**************************************************************************

