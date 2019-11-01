classdef bh_exp_roll_resist_CLS

properties
    
end
%-#########################################################################    
methods
function obj = bh_exp_roll_resist_CLS()
end
%--------------------------------------------------------------------------
function outputArg = do_const_deceleration(obj, hax, num_wheels, mass, Tstop, Vmax_cm_per_sec)
    
    if(isempty(hax))
        hax = uiaxes();
    end
    
    cla(hax)
    
    %v0_cmpersec_list = linspace(0, Vmax_cm_per_sec, 6);
    v0_cmpersec_list = Vmax_cm_per_sec;
    
    % convert cm/sec to m/sec
    v0_mpersec_list  = v0_cmpersec_list/100;
    
    % the model:
    %  v = v0 + a*t
    
    leg_str = {};
    t_vec = linspace(0, Tstop, 100);
    for kk=1:length(v0_mpersec_list)
        
       v0          =   v0_mpersec_list(kk);
       a           = (0 - v0)/Tstop;
       F           = mass*a;
       F_per_wheel = F/num_wheels;
       
       v   = v0 + a*t_vec;
       vcm = v * 100;
       
       plot(hax, t_vec, vcm)
       
       leg_str{kk} = sprintf('F per wheel = %.3f [N]', F_per_wheel);
       
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
    title(hax,'Rolling Resistance FORCE per wheel')
end
%--------------------------------------------------------------------------
end % methods
%-#########################################################################    
end % classdef


