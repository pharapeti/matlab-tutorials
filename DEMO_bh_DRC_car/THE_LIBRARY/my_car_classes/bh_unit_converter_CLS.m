classdef bh_unit_converter_CLS
%-#########################################################################    
methods
function OBJ = bh_unit_converter_CLS()
end
%--------------------------------------------------------------------------
function B_values = convert_A_to_B_trans_vel(obj, A_str, B_str, A_values)
    
    % check that allowed unit strings have been supplied:
    [~, mems_CESTR] = enumeration('bh_exp_units_of_trans_speed_ENUM');
    if( any(ismember(mems_CESTR,A_str)) &  any(ismember(mems_CESTR,B_str)))
        % good
    else
        %bad
        clc
        fprintf('\n ... UNknown unit string supplied:  <%s> or <%s>', A_str, B_str);
        fprintf('\n ... allowed unit strings are: ');
        fprintf('\n -----> %s', mems_CESTR{:});
        fprintf('\n\n')
        % throw ERROR()
        error('###_ERROR: calling convert_A_to_B_trans_vel()')
    end
        
    % first convert the A_values into BASE values
    A = bh_exp_units_of_trans_speed_ENUM.(A_str);
    
    base_unit_values = A.ToBaseUnits(A_values);
    
    % then convert BASE values into B_balues
    B = bh_exp_units_of_trans_speed_ENUM.(B_str);
    
    B_values = B.FromBaseUnits(base_unit_values);   
end
%--------------------------------------------------------------------------
function B_values = convert_A_to_B_rotat_vel(obj, A_str, B_str, A_values)
    
    % check that allowed unit strings have been supplied:
    [~, mems_CESTR] = enumeration('bh_exp_units_of_rotat_speed_ENUM');
    if( any(ismember(mems_CESTR,A_str)) &  any(ismember(mems_CESTR,B_str)))
        % good
    else
        %bad
        clc
        fprintf('\n ... UNknown unit string supplied:  <%s> or <%s>', A_str, B_str);
        fprintf('\n ... allowed unit strings are: ');
        fprintf('\n -----> %s', mems_CESTR{:});
        fprintf('\n\n')
        % throw ERROR()
        error('###_ERROR: calling convert_A_to_B_trans_vel()')
    end
        
    % first convert the A_values into BASE values
    A = bh_exp_units_of_rotat_speed_ENUM.(A_str);
    
    base_unit_values = A.ToBaseUnits(A_values);
    
    % then convert BASE values into B_balues
    B = bh_exp_units_of_rotat_speed_ENUM.(B_str);
    
    B_values = B.FromBaseUnits(base_unit_values);   
end
%--------------------------------------------------------------------------
function B_values = convert_A_to_B_trans_len(obj, A_str, B_str, A_values)
    
    % check that allowed unit strings have been supplied:
    [~, mems_CESTR] = enumeration('bh_exp_units_of_trans_length_ENUM');
    if( any(ismember(mems_CESTR,A_str)) &  any(ismember(mems_CESTR,B_str)))
        % good
    else
        %bad
        clc
        fprintf('\n ... UNknown unit string supplied:  <%s> or <%s>', A_str, B_str);
        fprintf('\n ... allowed unit strings are: ');
        fprintf('\n -----> %s', mems_CESTR{:});
        fprintf('\n\n')
        % throw ERROR()
        error('###_ERROR: calling convert_A_to_B_trans_len()')
    end
        
    % first convert the A_values into BASE values
    A = bh_exp_units_of_trans_length_ENUM.(A_str);
    
    base_unit_values = A.ToBaseUnits(A_values);
    
    % then convert BASE values into B_balues
    B = bh_exp_units_of_trans_length_ENUM.(B_str);
    
    B_values = B.FromBaseUnits(base_unit_values);   
end
%--------------------------------------------------------------------------


end % methods
%-#########################################################################    
end % classdef


