function dZdt_col = bh_mech_to_1st_order( Mass_mat,   ...
                                          Kstiff_mat, ...
                                          Cdamp_mat,  ...
                                          Fh_col,     ...
                                          t,          ...
                                          Z_col )
   % M_mat  is  n_x_n
   % Fh_col is  n_x_1
   % Z_col  is 2n_x_1
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
   
    n = size(Mass_mat, 1); 
    N = 2*n;

    dZdt_col = zeros(N,1);

    I_n    = eye(n);
    O_n    = zeros(n);
    A_mat  = [ -1*inv(Mass_mat)*Cdamp_mat,   -1*inv(Mass_mat)*Kstiff_mat;
                                      I_n,    O_n];
    F_col = Fh_col(t);

    G_col = [inv(Mass_mat)*F_col;
             zeros(n,1)];
    
    dZdt_col = A_mat*Z_col + G_col;
end

