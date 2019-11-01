classdef bh_exp_accel_CLS

properties
    Property1
end
%-#########################################################################    
methods
function obj = bh_exp_accel_CLS()
end
%--------------------------------------------------------------------------
function outputArg = do_const_acceleration(obj, hax, num_motors, mass, wheel_rad_cm, Tgoal, Vmax_cm_per_sec)
    
    if(isempty(hax))
        hax = uiaxes();
    end
    
    cla(hax)
    
    % create a list of target terminal velocities  in cm/sec
    %v_cmpersec_list = linspace(0, Vmax_cm_per_sec, 6);
    v_cmpersec_list = Vmax_cm_per_sec;
    
    % convert cm/sec to m/sec
    v_mpersec_list  = v_cmpersec_list/100;
    
    % convert cm to m    
    r_m             = wheel_rad_cm/100;
    
    % the model:
    %  v = a*t
    
    leg_str = {};
    t_vec = linspace(0, Tgoal, 100);
    for kk=1:length(v_cmpersec_list)
        
       v            =   v_mpersec_list(kk);
       a            = v/Tgoal;
       F            = mass*a;
       F_per_motor  = F/num_motors;
       TQ_per_motor = F_per_motor*r_m;
       
       v   = a*t_vec;
       vcm = v * 100;
       
       plot(hax, t_vec, vcm)
       
       leg_str{kk} = sprintf('TQ per motor = %.3f [N.m]', TQ_per_motor);
       
       if(1==kk)
           hold(hax,'on')
       end
    end
    
    legend(hax,leg_str,'Location','best');
    %legend(hax,leg_str,'Location','bestoutside');
    grid(hax,'on');
    axis(hax,'tight');
    xlabel(hax,'(time (secs)');
    ylabel(hax,'VELOCITY  (cm / sec)');
    title(hax,'Torque per motor')
end
%--------------------------------------------------------------------------
end % methods
%-#########################################################################    
end % classdef


