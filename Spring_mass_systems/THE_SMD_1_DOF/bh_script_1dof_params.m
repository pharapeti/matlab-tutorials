
%% HELLO:
% this script creates some MATLAB variables that are used by the Simulink
% model call <bh_1dof_hello.slx>

m = 1;       % (kg)
c = 2*0.2*3; % (N/(m/sec))
k = 9;       % (N/m)

% INITIAL Conditions used by the SIMULINK integrators
x0     = 1;
xdot_0 = 0;

% INITIAL deflections used by teh SIMSCAPE springs, etc
def_k       = [];
def_k.xR    = 0;        def_k.vR    = 0;
def_k.xC    = x0;       def_k.vC    = xdot_0;

def_k.x_def = def_k.xR  - def_k.xC;    % delta = xR - xC 

clc
fprintf('\n ... just finished running <%s>', mfilename);
whos

