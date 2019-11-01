classdef bh_exp_speed_radius_CLS

properties
    wheel_rad_cm
    trans_limit_kmper_hr
    units_rotat_str
    units_trans_str
end
%-#########################################################################    
methods
function OBJ = bh_exp_speed_radius_CLS(inp_S)
   OBJ.wheel_rad_cm         = inp_S.wheel_rad_cm;
   OBJ.trans_limit_kmper_hr = inp_S.trans_limit_kmper_hr;
   OBJ.units_rotat_str      = inp_S.units_rotat_str;
   OBJ.units_trans_str      = inp_S.units_trans_str;
end
%--------------------------------------------------------------------------
function do_plot(OBJ, hax)
    
    if(isempty(hax))
        hax = uiaxes();
    end
    
    cla(hax)
    
    OBJ_UC = bh_unit_converter_CLS();
    
    wheel_rad_m           = OBJ_UC.convert_A_to_B_trans_len('cm','m', OBJ.wheel_rad_cm);
    speed_limit_m_per_sec = OBJ_UC.convert_A_to_B_trans_vel('km_per_hr', 'm_per_sec', OBJ.trans_limit_kmper_hr);
    
    % DO calculations in base SI unite:
    %   v = w.r
    
    v = linspace(0,speed_limit_m_per_sec, 100);
    w = v ./ wheel_rad_m;
    
    % convert to requested display units
    
    v_tgt = OBJ_UC.convert_A_to_B_trans_vel('m_per_sec',   OBJ.units_trans_str, v);
    w_tgt = OBJ_UC.convert_A_to_B_rotat_vel('rad_per_sec', OBJ.units_rotat_str, w);
    
    % now do the plot
    plot(hax, w_tgt, v_tgt)
          
    grid(hax,'on');
    axis(hax,'tight');
    xlabel(hax,OBJ.units_rotat_str,'Interpreter', 'none');
    ylabel(hax,OBJ.units_trans_str,'Interpreter', 'none');
    title(hax,'Rotational vs Translational velocity')
end
%--------------------------------------------------------------------------
end % methods
%-#########################################################################    
end % classdef


