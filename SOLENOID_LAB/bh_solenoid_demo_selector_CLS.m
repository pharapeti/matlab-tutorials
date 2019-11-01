classdef bh_solenoid_demo_selector_CLS
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        ROOT_FOLDER = '';
        REF_FOLDER  = '';
    end
    
methods
function OBJ = bh_solenoid_demo_selector_CLS()
    p = mfilename('fullpath');
    [pathstr,~,~] = fileparts(p);
    OBJ.REF_FOLDER  = pathstr;
    OBJ.ROOT_FOLDER = pathstr;
end
%------------------------------------------------------------------
%_#################################################################
%    H E L L O    T A B
%_#################################################################
function hello_open_pres(OBJ)
    pdf_the_file = [OBJ.ROOT_FOLDER, filesep, 'THE_PRES',filesep,'bh_solenoid_pres.pdf'];
    ppt_the_file = [OBJ.ROOT_FOLDER, filesep, 'THE_PRES',filesep,'bh_solenoid_pres.pptx'];
    
    try
          winopen(ppt_the_file)
    catch     
             open(pdf_the_file);
    end
end
%_#################################################################
%    D A T A     T A B
%_#################################################################
function data_load_params(OBJ)
    evalin('base', 'clc; bh_model_params');
end
%==========================================================================
function data_open_datasheet(OBJ)
    pdf_the_file = [OBJ.ROOT_FOLDER, filesep, 'DATA_FILES',filesep,'SOLENOID_DATA_SHEET_s-41-300h.pdf'];
    open(pdf_the_file);
end
%==========================================================================
function data_open_curvefit_script(OBJ)
        LOC_close_M_editor();
        edit('bh_explore_Fvs_S_data.mlx');
end
%_#################################################################
%    U T I L I T I E S   T A B
%_#################################################################
function utils_open_file(OBJ, file_str)
         edit(file_str);
end
%_#################################################################
%    M O D E L L I N G      T A B
%_#################################################################
function mod_finished_knob(OBJ, str)
   str = upper(  string(str)  );
   
   switch(str)
       case "NOTHING"
                return
       case "SIMULINK"
                LOC_clear_base();
                evalin('base', 'clc; bh_model_params');
                open('bh_solenoid_simulink.slx');
       case "SIMSCAPE ELECTRONICS"
                LOC_clear_base();
                evalin('base', 'clc; bh_model_params');
                open('bh_solenoid_simelectronics.slx');
       case "SIMSCAPE"
                LOC_clear_base();
                evalin('base', 'clc; bh_model_params');
                open('bh_solenoid_simscape.slx');
       case "COMPARE ALL"
                LOC_clear_base();
                evalin('base', 'clc; bh_model_params');
                open('bh_solenoid_ALL_MODELS.slx');
       otherwise
           error('###_ERROR:  UNknown choice for demo selector !');
   end 
end
%_#################################################################
%    M O D E L L I N G - M A T H     T A B
%_#################################################################
function mod_math_open_derivation(OBJ)
    pdf_the_file = [OBJ.ROOT_FOLDER, filesep, 'HAND_DERIVATION',filesep,'bh_solenoid_notes_HAND_DERIVATION.pdf'];
    open(pdf_the_file);
end
%_#################################################################
%    M O D E L L I N G - S I M U L I N K     T A B
%_#################################################################
function mod_simulink_knob(OBJ, str)
   str = upper(  string(str)  );
   
    LOC_clear_base();
    evalin('base', 'clc; bh_model_params');
   
    THE_FOLDER = [OBJ.ROOT_FOLDER, filesep, 'MODELS',filesep,'MODELS_AFTER_STEPS', filesep,'simulink'];
    
   switch(str)
       case "NOTHING"
                return
       case "BEGIN"
                open_system([THE_FOLDER, filesep,'bh_solenoid_simulink_BEGIN.slx']);
       case "STEP_01"
                open_system([THE_FOLDER, filesep,'bh_solenoid_simulink_step_01.slx']);
       case "STEP_02"
                open_system([THE_FOLDER, filesep,'bh_solenoid_simulink_step_02.slx']);
       case "STEP_03"
                open_system([THE_FOLDER, filesep,'bh_solenoid_simulink_step_03.slx']);
       case "STEP_04"
                open_system([THE_FOLDER, filesep,'bh_solenoid_simulink_step_04.slx']);
       case "FINISHED"
                open_system('bh_solenoid_simulink.slx');
       otherwise
           error('###_ERROR:  UNknown choice for demo selector !');
   end 
end
%_#################################################################
%    M O D E L L I N G - S I M E L EC T R O N IC S     T A B
%_#################################################################
function mod_simelectronics_knob(OBJ, str)
   str = upper(  string(str)  );
   
    LOC_clear_base();
    evalin('base', 'clc; bh_model_params');
   
    THE_FOLDER = [OBJ.ROOT_FOLDER, filesep, 'MODELS',filesep,'MODELS_AFTER_STEPS', filesep,'simscape_electronics'];
    
   switch(str)
       case "NOTHING"
                return
       case "BEGIN"
                open_system([THE_FOLDER, filesep,'bh_solenoid_simelectronics_BEGIN.slx']);
       case "STEP_01"
                open_system([THE_FOLDER, filesep,'bh_solenoid_simelectronics_step_01.slx']);
       case "STEP_02"
                open_system([THE_FOLDER, filesep,'bh_solenoid_simelectronics_step_02.slx']);
       case "FINISHED"
                open_system('bh_solenoid_simelectronics.slx');
       otherwise
           error('###_ERROR:  UNknown choice for demo selector !');
   end 
end
%_#################################################################
%    M O D E L L I N G - S I M S C A P E - M E C H
%_#################################################################
function mod_simscape_mech_knob(OBJ, str)
   str = upper(  string(str)  );
   
    LOC_clear_base();
    evalin('base', 'clc; bh_model_params');
   
    THE_FOLDER = [OBJ.ROOT_FOLDER, filesep, 'MODELS',filesep,'MODELS_AFTER_STEPS', filesep,'simscape'];
    
   switch(str)
       case "NOTHING"
                return
       case "BEGIN"
                open_system([THE_FOLDER, filesep,'bh_ssc_mech_BEGIN.slx']);
       case "STEP_01"
                open_system([THE_FOLDER, filesep,'bh_ssc_mech_step_01.slx']);
       case "STEP_02"
                open_system([THE_FOLDER, filesep,'bh_ssc_mech_step_02.slx']);
       case "STEP_03"
                open_system([THE_FOLDER, filesep,'bh_ssc_mech_step_03.slx']);              
       case "FINISHED"
                open_system([THE_FOLDER, filesep,'bh_ssc_mech_FINAL.slx']);
       otherwise
           error('###_ERROR:  UNknown choice for demo selector !');
   end 
end
%_#################################################################
%    M O D E L L I N G - S I M S C A P E - E L E C
%_#################################################################
function mod_simscape_elec_knob(OBJ, str)
   str = upper(  string(str)  );
   
    LOC_clear_base();
    evalin('base', 'clc; bh_model_params');
   
    THE_FOLDER = [OBJ.ROOT_FOLDER, filesep, 'MODELS',filesep,'MODELS_AFTER_STEPS', filesep,'simscape'];
    
   switch(str)
       case "NOTHING"
                return
       case "BEGIN"
                open_system([THE_FOLDER, filesep,'bh_ssc_elec_BEGIN.slx']);
       case "STEP_01"
                open_system([THE_FOLDER, filesep,'bh_ssc_elec_step_01.slx']);
       case "STEP_02"
                open_system([THE_FOLDER, filesep,'bh_ssc_elec_step_02.slx']);
       case "STEP_03"
                open_system([THE_FOLDER, filesep,'bh_ssc_elec_step_03.slx']);              
       case "FINISHED"
                open_system([THE_FOLDER, filesep,'bh_ssc_elec_FINAL.slx']);
       otherwise
           error('###_ERROR:  UNknown choice for demo selector !');
   end 
end
%_#################################################################
%    M O D E L L I N G - S I M S C A P E - C O M B I N E D
%_#################################################################
function mod_simscape_compined_knob(OBJ, str)
   str = upper(  string(str)  );
   
    LOC_clear_base();
    evalin('base', 'clc; bh_model_params');
   
    THE_FOLDER = [OBJ.ROOT_FOLDER, filesep, 'MODELS',filesep,'MODELS_AFTER_STEPS', filesep,'simscape'];
    
   switch(str)
       case "NOTHING"
                return
       case "BEGIN"
                open_system([THE_FOLDER, filesep,'bh_solenoid_simscape_BEGIN.slx']);
       case "STEP_01"
                open_system([THE_FOLDER, filesep,'bh_solenoid_simscape_step_01.slx']);
       case "FINISHED"
                open_system('bh_solenoid_simscape.slx');
       otherwise
           error('###_ERROR:  UNknown choice for demo selector !');
   end 
end



%------------------------------------------------------------------
end % methods  
end  % CLASSDEF
%_#########################################################################
function LOC_clear_base()
   evalin('base', 'clear; clc')
end
%**************************************************************************
function LOC_close_M_editor
%close the M-file Editor
  evalin('base',['com.mathworks.mlservices.MatlabDesktopServices.getDesktop().closeGroup(''Editor'')']);
end
%**************************************************************************

