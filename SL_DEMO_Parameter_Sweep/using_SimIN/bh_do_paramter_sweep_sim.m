%% ATTENTION:  good resources:
% web(fullfile(docroot, 'simulink/examples/multiple-simulations-workflow-tips.html'))
% web(fullfile(docroot, 'simulink/ug/optimize-estimate-and-sweep-block-parameter-values.html'))

%% now LOAD parameters into the model's workspace
THE_MODEL = 'bh_f14';
open_system(THE_MODEL)
hws = get_param(THE_MODEL,'modelworkspace');
hws.DataSource = 'MATLAB Code'
hws.MATLABCode = 'bh_f14_params'
hws.reload

%% define a list of values to sweep over

my_sweep_vals = [1,3,5];
%% Create a |Simulink.SimulationInput| object
% for each simulation that you want to run ). Store the
% objects in a single array variable, |simIn|. Use the |setVariable| method of each
% object to identify each of the two experimentation values.
for i = 1:length(my_sweep_vals)
    
    % first configure the variables
    simIn(i) = Simulink.SimulationInput(THE_MODEL);
    simIn(i) = simIn(i).setVariable('A.x',my_sweep_vals(i), 'Workspace', THE_MODEL);
    
    % next configure the Model parameters
    simIn(i) = simIn(i).setModelParameter('SaveOutput',     'on');
    simIn(i) = simIn(i).setModelParameter('OutputSaveName', 'brads_yout');
    simIn(i) = simIn(i).setModelParameter('SaveFormat',     'Dataset');
    simIn(i) = simIn(i).setModelParameter('StopTime',       '1');
end

%% now do the sweep
simOut = sim( simIn );

%% close the model - do NOT save any changes
tf_save_stuff = false;
close_system(THE_MODEL, tf_save_stuff)

%% now plot the 3rd ORANGE output

an_RGB_mat = jet(length(simOut))
figure
hax = axes;
hold(hax, 'on');  grid(hax, 'on');  xlabel('Time (secs)'); ylabel('Volts (V)')
for i=1:length(simOut)
 t = simOut(i).brads_yout{3}.Values.Time;
 y = simOut(i).brads_yout{3}.Values.Data;
 plot(t,y,'-', 'Color', an_RGB_mat(i,:));
end
hold(hax, 'off');