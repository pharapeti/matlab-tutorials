
%% Part_0:  define the model to play with
THE_MODEL = 'bh_smd_for_param_sweep';
open_system(THE_MODEL)

%% Part_0.1:  NOTE the following:
% In the Simulink model we have "tagged" 2 signals to be logged during a
% simulation.  These signals are the:
%   a.) POSTION signal,  labelled as POS
%   b.) VELOCITY signal, labelled as VEL

%% PART_1a:  consider the model's response to some random parameter set

m = 3.6; % (kg)
k = 400; % (N/m)
b =  10; % (N.s/m)

% define some simulation attributes that we'll use - WHY ?
% NOTE:  we could have made these settings INTERACTIVELY in the Simulink 
%        model, but I wanted to show you how it can also be done
%        programmatically
simparams_S.SaveTime              = 'on';
simparams_S.TimeSaveName          = 'tout';
simparams_S.SignalLogging          = 'on';
simparams_S.SignalLoggingname      = 'logsout';
simparams_S.ReturnWorkspaceOutputs = 'on';

% the SIM command is the *NEW* thing that we're seeing here
A = sim(THE_MODEL, simparams_S )

%% PART_1b:  Explore the LOGGED data

% extract some data
THE_LOGGED_DATA = A.get('logsout')

t               = A.get('tout');
pos             = THE_LOGGED_DATA.get('POS').Values.Data;
vel             = THE_LOGGED_DATA.get('VEL').Values.Data;

% plot some data
figure;
subplot(2,1,1); plot(t, vel,'-r.'); 
                grid('on'); xlabel('TIME (secs)'); ylabel('VEL (m/sec)');
subplot(2,1,2); plot(t, pos,'-b.'); 
                grid('on'); xlabel('TIME (secs)'); ylabel('POS (m)');
                
%% PART_2a:  OK lets do a DAMPING value parameter sweep
 
% define the mechanical parameters that we'll use
m                  = 1;
k                  = 100;
damping_value_list = 2*10*[0.2, 0.4, 0.6, 0.8, 1];

% define some simulation attributes that we'll use - WHY ?
simparams_S.SaveTime              = 'on';
simparams_S.TimeSaveName          = 'tout';
simparams_S.SignalLogging          = 'on';
simparams_S.SignalLoggingname      = 'logsout';
simparams_S.ReturnWorkspaceOutputs = 'on';
simparams_S.SolverType             = 'Fixed-step';
simparams_S.Solver                 = 'ode4';
simparams_S.FixedStep              = '0.001';
simparams_S.StopTime               = '5';
simparams_S.LimitDataPoints        = 'off';

% Let's do the sweep
clear LOG_VEC
for count=1:length(damping_value_list)
    
    % what's my damping value
    b = damping_value_list(count);
    
    % run the sim
    LOG_VEC(count) = sim(THE_MODEL, simparams_S );
    
    fprintf('\n .. finished run for b = %6.2f', b);
end

%% PART_2b: extract the LOGGED data and plot

POS_MAT = [];
VEL_MAT = [];

for count =1:length(LOG_VEC)

    THE_LOGGED_DATA = LOG_VEC(count).get('logsout');

    pos             = THE_LOGGED_DATA.get('POS').Values.Data;
    vel             = THE_LOGGED_DATA.get('VEL').Values.Data;

    POS_MAT         = [POS_MAT, pos(:)];
    VEL_MAT         = [VEL_MAT, vel(:)];

    leg_str{count} = sprintf('b = %2.2f', damping_value_list(count) );
end

t               = LOG_VEC(end).get('tout');

% plot some data
figure;
subplot(2,1,1); plot(t, VEL_MAT, 'LineWidth', 2); 
                grid('on'); xlabel('TIME (secs)'); ylabel('VEL (m/sec)');
                legend(leg_str, 'Location','bestoutside')
subplot(2,1,2); plot(t, POS_MAT, 'LineWidth', 2); 
                grid('on'); xlabel('TIME (secs)'); ylabel('POS (m)');
                legend(leg_str, 'Location','bestoutside')

%% And good day
tf_i_will_save_changes_made_to_model = false;
close_system(THE_MODEL, tf_i_will_save_changes_made_to_model)