
%% HELLO:
% this script creates some MATLAB variables that are used by the Simulink
% model call <bh_1dof_hello.slx>

m = 1;       % (kg)
c = 2*0.2*3; % (N/(m/sec))
k = 9;       % (N/m)

x0    = 1;
xR0   = 0;
xC0   = x0;
xDEF0 = xR0 - xC0;

xdot_0 = 0;

clc
fprintf('\n ... just finished running <%s>', mfilename);
whos

