my_sol_OBJ = bh_solenoid;


Mech.K             = my_sol_OBJ.stiffness;    % N/m
Mech.C             = my_sol_OBJ.damping;      % N.sec/m
Mech.M             = my_sol_OBJ.mass;         % kg
Mech.x_0           = 0;                       % m
Mech.xdot_0        = 0;                       % m/sec
Mech.x_min         = 0;                       % m
Mech.x_max         = my_sol_OBJ.MAX_y_airgap; % m
Mech.MAX_y_airgap  = my_sol_OBJ.MAX_y_airgap; % m



%Elec.L_initial = my_sol_OBJ.get_L_at_max_gap();  % (Henry)
Elec.R         = my_sol_OBJ.resistance;          % (ohms)


Coeffs.C123 = my_sol_OBJ.get_the_C_coeffs();

solen.v_rated = my_sol_OBJ.volts_rated;
solen.i_rated = my_sol_OBJ.current_rated;

[tmp_F_mag, tmp_y_m]  = my_sol_OBJ.get_Fmag_vs_stroke_datasheet();

solen.F_mag_12 = tmp_F_mag(1:2);
solen.y_m_12   = tmp_y_m(1:2);
% solen.F_mag_12 = tmp_F_mag([1, 4]);
% solen.y_m_12   = tmp_y_m(  [1, 4]);

solen.F_mag    = tmp_F_mag;
solen.y_m     = tmp_y_m;

