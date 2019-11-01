
%% PURPOSE:
%  Test the class file <bh_3dof_4wheel_vehicle_viewer_CLS>

%% create OBJECT
OBJ = bh_3dof_4wheel_vehicle_viewer_CLS('init_xytheta',    [1,2,-pi/4], ...
                                 'scale_factor',    0.5, ...
                                 'color',           [0,1,0], ...
                                 'road_z',          1, ...
                                 'veh_ID_str',      'BRADS_CAR', ...
                                 'tgt_tag_ax_name', 'TAG_AX_ARENA');
%% Initialise the plot
OBJ.plot_init()

%% animate the vehicle
xx_list = linspace(1,2.5,20);
th_list = linspace(0,2*pi,20);

for kk=1:length(xx_list)
    xx = xx_list(kk);
    tt = th_list(kk);

    OBJ.plot(xx,2,tt)

    pause(0.1);
    fprintf('\n ... xx=%6.2f',xx);
end    

%% and we're done
fprintf('\n \n ... we are finished HERE !');
