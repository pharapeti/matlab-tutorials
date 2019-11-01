
%% Define MASS, STIFFNESS and DAMPING parameters
m1 = 10;
k1 = 1000;
c1 = 20; %7; %140;
m2 = 1;
k2 = 500;
c2 = 50; %40;
k3 = 100;
c3 = 10; %10; %20;

M_mat = [      m1,       0
                0,       m2       ];
      
K_mat = [ (k1 + k2),    -k2;
               -k2 ,    (k2 + k3) ];
          
C_mat = [ (c1 + c2),    -c2;
               -c2 ,    (c2 + c3) ];          

%% Compute the UNdamped Natural frequencies
% We solve the classical Eigenvalue problem for a Mechanical system:
%
%    -w^2.M.X + K.X = 0
%
%    -w^2.X   + inv(M).K.X = 0           
%  
%     ( inv(M)*K  - LAMBDA.I  ).X = 0

A             = inv(M_mat)*K_mat;
[eVec, eVals] = eig(A);

wsq_vec = diag(eVals);
w_vec   = sqrt(wsq_vec);
fhz_vec = w_vec/(2*pi); 

% Look at the UNdamped Natural frequencies
fprintf('\n UNdamped natural frequencies are:')
fprintf('\n %8.4f (hz)',fhz_vec);
fprintf('\n');

fprintf('\n UNdamped MODE shapes:')
eVec

% Note that these eigenvectors are already normalised:
sum(eVec .* eVec)

%% Look at the DIAGONALISED M and K matrices

TT   = eVec;
dg_M = TT' * M_mat * TT
dg_K = TT' * K_mat * TT

%% Define the Excitation functions

%            bh_step_func( t,   t_of_step, y_before_step,  y_after_step )
F1_fh = @(t) bh_step_func( t,       1,          0,            500 );
F2_fh = @(t) bh_step_func( t,       5,          0,           1000 );

figure;
tvec = 0:0.01:10;
plot(tvec, F1_fh(tvec), '-r', 'LineWidth', 3);
     hold on
plot(tvec, F2_fh(tvec), '-b', 'LineWidth', 3);
     xlabel('t (secs)'); ylabel('F (Newtons)'); axis('tight'); grid('on');
     legend({'F1','F2'});

%% Solve the system
% The MATLAB ODE solvers require systems of 1st order equations.
% So we need to convert our Mechanical system of 2nd order ODEs into a new
% system of 1st order ODEs.  This is actually pretty straigt forward to do:
% ---------------------------------------------------------------------
%  M.XDD + C.XD + K.X = F
%
%  [ M 0 ].(XDD)  +  [C  K].(XD)  = (F)  
%  [ 0 I ] (XD )     [-I 0] (X )    (0)
%
%          (XDD)   = [-inv(M)*C, -inv(M)*K].[XD]   +  [inv(M)*F] 
%          (XD )     [        I,     0    ] [X]       [   0    ]
%
%           ZD     =   A * Z + G
%
%  where:        Z = [XD] = [x1_dot] 
%                    [X ]   [x2_dot]
%                           [x1    ]
%                           [x2    ]
% ---------------------------------------------------------------------
%
% We implement the above transformation in the function *bh_mech_to_1st_order()*
%

% Define your INITIAL conditions
n      = size(M_mat, 1);
N      = 2*n;
z_init = zeros(N,1);   
z_init = [0,5,1,-0.5]';  %[0,0,1,0.5]';
% define the SYSTEM to solve
%Fh_col    = {F1_fh, F2_fh};
Fh_col    = @(t) ([0;0]);
MY_SYSTEM = @(t, z) bh_mech_to_1st_order(M_mat, K_mat, C_mat, Fh_col,t,z);

% Define some ODE solver settings
t_span     = [0 10];
my_options = odeset('RelTol', 1e-7, 'AbsTol', 1e-7);

% use ODE45 to numerically solve your system
%[T,Y] = solver(odefun,   tspan,  y0,     options)
[T,Z]  = ode45(MY_SYSTEM, t_span, z_init, my_options);

%% Calculate the accelerations

%    M.Xdd + C.Xd + K.X = F
%      
%    M.Xdd = F - K.X - C.Xd
%      
%      Xdd = inv(M) * (F - K.X - C.Xd)

X1_dot = Z(:,1);  % P_x_1
X2_dot = Z(:,2);  
X1     = Z(:,3);  
X2     = Z(:,4);

Xd    = [ X1_dot.';
          X2_dot.' ];      % 2_x_P
     
X     = [ X1.';
          X2.'   ];        % 2_x_P

F     = [ F1_fh(T.');
          F2_fh(T.');  ];  % 2_x_P
     
Xdd   = inv(M_mat) * (F - K_mat*Xd - C_mat*X);  % 2_x_P    
      
X1_dot_dot = Xdd(1,:).';  % P_x_1
X2_dot_dot = Xdd(2,:).';  % P_x_1

%% PLOT the system response

figure;
subplot(3,2,1);
   plot(T,X1,'-r');  
   xlabel('t (secs)'); ylabel('X1 (m)'); grid('on'); axis('tight');
   legend('X1', 'Location', 'best');
subplot(3,2,3);
   plot(T,X1_dot,'-r');  
   xlabel('t (secs)'); ylabel('X1 dot (m/sec)'); grid('on'); axis('tight');
   legend('X1 dot', 'Location', 'best');
subplot(3,2,5);
   plot(T,X1_dot_dot,'-r');  
   xlabel('t (secs)');ylabel('X1 dot dot(m/sec)');grid('on');axis('tight');
   legend('X1 dot dot', 'Location', 'best');
   %----------------------------------------------------------------------- 
subplot(3,2,2);
   plot(T,X2,'-b');  
   xlabel('t (secs)'); ylabel('X2 (m)'); grid('on'); axis('tight');
   legend('X2', 'Location', 'best');
subplot(3,2,4);
   plot(T,X2_dot,'-b');  
   xlabel('t (secs)'); ylabel('X2 dot (m/sec)'); grid('on'); axis('tight');
   legend('X2 dot', 'Location', 'best');
subplot(3,2,6);
   plot(T,X2_dot_dot,'-r');  
   xlabel('t (secs)');ylabel('X2 dot dot(m/sec)');grid('on');axis('tight');
   legend('X2 dot dot', 'Location', 'best');


