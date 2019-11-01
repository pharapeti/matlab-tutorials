classdef my_KF_general_CLS
% MY_KF_GENERAL_CLS - a vanilla implementation of a Kalman Filter
%--------------------------------------------------------------------------
% REF: 
%  1.) https://cse.sc.edu/~terejanu/files/tutorialKF.pdf
%      - "Discrete Time Kalman Filter tutorial" - Gabriel A. Terejanu
%  2.) https://au.mathworks.com/videos/series/understanding-kalman-filters.html
%--------------------------------------------------------------------------
% Discrete plant:
%     x[k] = A.x[k-1]  +  B.u[k-1]   +  w[k-1]
%     y[k] = C.x[k]                  +  v[k]
%
%   where:
%           Q = cov(w) ==PROCESS_NOISE covariance matrix
%           R = cov(v) ==MEASUREMENT_NOISE covariance matrix
%--------------------------------------------------------------------------
% PREDICT:
%    xhat[k|k-1] = A.x[k-1|k-l]       +  B.u[k-1]
%       P[k|k-1] = A.P[k-1|k-1].(A')  +  Q
% CORRECT:
%       K[k]     = P[k|k-1].(C'). inv(  C.P[k|k-1].(C') + R  )
%    xhat[k|k]   = xhat[k|k-1]  +  K[k]*( y[k] - C.xhat[k|k-1]  )
%       P[k|k]   = (I-K[k].C). P[k|k-1] . (I-K[k].C)'   +  K[k]R.(K[k]')
%                = (I-K[k].C). P[k|k-1]
%--------------------------------------------------------------------------
% INITIAL conditions:
%     x[0] - state value at time ZERO
%     P[0] - covariance matrix of the state estimate
%--------------------------------------------------------------------------
% VECTOR description:
%     x[k] - Nx_x_1 , STATE  vector at time k
%     u[k] - Nu_x_1 , INPUT  vector at time k
%     y[k] - Ny_x_1 , OUTPUT vector at time k
% 
%     w[k] - Nx_x_1 , PROCESS_NOISE     vector at time k
%     v[k] - Ny_x_1 , MEASUREMENT_NOISE vector at time k
%--------------------------------------------------------------------------
% MATRIX description:
%     A    - Nx_x_Nx
%     B    - Nx_x_Nu
%     C    - Ny_x_Nx
% 
%     Q    - Nx_x_Nx, PROCESS_NOISE     covariance matrix
%     R    - Ny_x_Ny, MEASUREMENT_NOISE covariance matrix
%     P    - Nx_x_Nx, covariance matrix of the state estimate
%     K    - Nx_x_Ny, Kalman gain matrix
%--------------------------------------------------------------------------
% EXPECTED_USAGE_#1:
%   >> OBJ = my_KF_general_CLS( A, B, C, Q, R, x0, P0 );
%   >> OBJ = OBJ.predict(u_k_minus_1);
%   >> OBJ = OBJ.correct(y_k);
%--------------------------------------------------------------------------
% EXPECTED_USAGE_#2:
%   >> OBJ = my_KF_general_CLS( A, B, C, Q, R, x0, P0 );
%   >> [xo_mat, yo_mat] = OBJ.batch_step(u_mat, y_meas_mat, do_plots);
%--------------------------------------------------------------------------

properties (SetAccess = protected)
    A  = [];
    B  = [];
    C  = [];
    Q  = [];
    R  = [];
    x0 = [];
    P0 = [];
    %------------------------------
    Nx = 0;
    Nu = 0;
    Ny = 0;  
    %------------------------------
    x
    P
end
%--------------------------------------------------------------------------
%_#########################################################################
methods
function OBJ = my_KF_general_CLS( A, B, C, Q, R, x0, P0 )
    if(1 ==coder.target('MATLAB') )
       validateattributes(A,{'numeric'},{'square'})
       validateattributes(Q,{'numeric'},{'square'})
       validateattributes(R,{'numeric'},{'square'})
       validateattributes(P0,{'numeric'},{'square'})
    end
    Nx     = size(A,1);
    Nu     = size(B,2);
    Ny     = size(C,1);
       
    OBJ.A  = A;
    OBJ.B  = B;
    OBJ.C  = C;
    OBJ.Q  = Q;
    OBJ.R  = R;
    OBJ.x0 = x0(:);
    OBJ.P0 = P0;
    
    OBJ.Nx = Nx;
    OBJ.Ny = Ny;
    OBJ.Nu = Nu;  
    
    OBJ.x  = OBJ.x0;
    OBJ.P  = P0;
end % my_KF_general_CLS()
%-------------------------------------------------------------------------- 
function  OBJ = predict(OBJ, varargin)
    % ALLOWED USAGE:
    % >> OBJ = OBJ.predict()
    % >> OBJ = OBJ.predict(u)
    
    if(2==nargin)
      u = varargin{1};
      u = u(:);
      assert( ~isempty(OBJ.B),  '###ERROR:  hey! you gave me a U, but your B is empty !');
      
      assert(length(u)==size(OBJ.B,2), '###_ERROR:  hey your u and B have a dimension INconsistency !')
    end
    
    %    xhat[k|k-1] = A.x[k-1]  +  B.u[k-1]
    %       P[k|k-1] = A.P[k-1|k-1].(A')  +  Q
    
    x = OBJ.x;
    A = OBJ.A;
    P = OBJ.P;
    Q = OBJ.Q;
    if(isempty(OBJ.B))
        x = A*x;
    else
        B = OBJ.B;
        x = A*x  +  B*u;
    end
    
    OBJ.x = x;
    OBJ.P = A*P*(A.') + Q;
end % predict()
%-------------------------------------------------------------------------- 
function  OBJ = correct(OBJ, y)
    if(1 ==coder.target('MATLAB') )
       validateattributes(y,{'numeric'},{'vector'});
    end
    
    y = y(:);
    
    assert(length(y)==size(OBJ.C,1), '###_ERROR:  hey your y and C have a dimension INconsistency !')

    x = OBJ.x; %#ok<*PROPLC>
    A = OBJ.A; %#ok<*NASGU>
    C = OBJ.C;
    P = OBJ.P;
    Q = OBJ.Q;
    R = OBJ.R;
    I = eye(OBJ.Nx);
    
    % Recall the BACK and FORWARD slash operators
    %  A.X=B ---> X=inv(A)*B ---> X = A\B
    %  X.A=B ---> X=B*inv(A) ---> X = B/A
    
    %     K[k]     = P[k|k-1].(C'). inv(  C.P[k|k-1].(C') + R  )
    %  xhat[k|k]   = xhat[k|k-1]  +  K[k]*( y[k] - C.xhat[k|k-1]  )
    %     P[k|k]   = (I-K[k].C). P[k|k-1] . (I-K[k].C)'   +  K[k]R.(K[k]')
    %                = (I-K[k].C). P[k|k-1]
    
    K = (P* (C.')) / (C*P*(C.') + R);
    x = x + K*(y - C*x);
    P = (I - K*C)*P;
    
    OBJ.x = x;
    OBJ.P = P;
end % correct()
%-------------------------------------------------------------------------- 
function x = get_state(OBJ)
         x = OBJ.x;
end % get_state()
%-------------------------------------------------------------------------- 
function [xo_mat, yo_mat, varargout] = batch_step(OBJ, u_mat, y_mat, tf_do_plots)
% ALLOWED_USAGE:
%  >> [xo_mat, yo_mat]      = batch_step(OBJ, u_mat, y_mat)
%  >> [xo_mat, yo_mat]      = batch_step(OBJ, u_mat, y_mat, true)
%  >> [xo_mat, yo_mat, hax] = batch_step(OBJ, u_mat, y_mat, true)    
%
% EXPECTED INPUTS: (please see ATTENTION note below)
%   y_mat = Ny_x_Nsteps
%   u_mat = Nu_x_(Nsteps-1) or EMPTY
%-----------------------------------------------------------
%   ***ATTENTION***:
%                    ycol_at_time_k         = y_mat(:,k)
%                    ucol_at_time_k_minus_1 = u_mat(:,k)
%
% By packing y_mat and u_mat in this fashion it makes it pretty easy to
% cycle through each time step within a FOR loop (see below)
%-----------------------------------------------------------
% OUTPUTS:
%   xo_mat =  Nx_x_Nsteps
%   yo_mat =  Ny_x_Nsteps
%-----------------------------------------------------------
      
    % check the inputs
    assert(size(y_mat,1)==OBJ.Ny, 'ERR: your y_mat has INcompatable dimensions');
    assert(size(u_mat,1)==OBJ.Nu, 'ERR: your u_mat has INcompatable dimensions')

    N_steps  = size(y_mat,2);
    Nx       = OBJ.Nx;
    Ny       = OBJ.Ny;
    xo_mat   = zeros(Nx, N_steps);
    yo_mat   = zeros(Ny, N_steps);
    
    % step through each time instance
    for k=1:N_steps
       if(isempty(u_mat))
           u = [];
       else
           % this is u_at_k_minus_1
           u = u_mat(:,k);
       end
       
       % this is y_at_k
       y   = y_mat(:,k);
       
       OBJ = OBJ.predict(u);
       
       if(any(isnan(y)))
           % do NOT correct
       else
          OBJ = OBJ.correct(y);
       end
       
       xo_mat(:,k) = OBJ.x;
       
       yo_mat(:,k) = OBJ.C*OBJ.x;
    end % for loop
    
    % should we do any plots ?
    if(nargin==3)
        % NOPE: do NOT do any plotting
      return
    elseif( 4==nargin && false==tf_do_plots)
        % NOPE: do NOT do any plotting
        return
    end
    
    % OK: if we made it to here then PLOT stuff
    hax = [];
    
    if(1 ==coder.target('MATLAB') )
        hax = OBJ.plot(y_mat, yo_mat, xo_mat);
    end
    
    % take care of any OPTIONAL outputs
    if(3==nargout)
       varargout{1} = hax; 
    end
    
end % batch_step()
%--------------------------------------------------------------------------
function hax = plot(OBJ, y_mat, yo_mat, xo_mat)
    
    % check the inputs
    assert(size(y_mat,1)==OBJ.Ny, 'ERR: your y_mat has INcompatable dimensions');
   
    hax      = [];
    
    Nx       = OBJ.Nx;
    Ny       = OBJ.Ny;

    if(1 ==coder.target('MATLAB') )
           % plot the STATES 
           figure;
           hax = [];
           for kx=1:OBJ.Nx
                hax(kx) = subplot(Nx,1,kx); 
                plot(xo_mat(kx,:),'-k','LineWidth',2); grid('on'); axis('tight');
                tmpstr = sprintf('X(%d) EST',kx);
                legend({tmpstr},'Location','Best');
           end

           % plot the OUTPUTS
           figure;
           Ny = OBJ.Ny;
           for ky=1:Ny
              subplot(Ny,1,ky); 
                plot( y_mat(ky,:),'-r');  hold on
                plot(yo_mat(ky,:),'-k','LineWidth',2); 
                  grid('on'); axis('tight');
                  tmpCSE{1} = sprintf('Y meas');
                  tmpCSE{2} = sprintf('Y(%d) EST',ky);
                  legend(tmpCSE,'Location','Best');
           end       
    end % if(1 ==coder.target('MATLAB') )
end
%--------------------------------------------------------------------------
end % methods
%_#########################################################################

%-------------------------------------------------------------------------- 
end % classdef
%_#########################################################################
% END CLASSDEF
%_#########################################################################
