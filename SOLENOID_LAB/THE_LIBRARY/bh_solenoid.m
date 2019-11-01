classdef bh_solenoid

properties
    mass       % kg
    damping    % N.s/m 
    stiffness  % N/m
    %-------------------------------------------------------
    volts_rated    % volts
    current_rated  % current
    resistance     % ohms
    %-------------------------------------------------------
    F_mag_datasheet   % N
    y_m_datasheet     % m
    %-------------------------------------------------------
    MAX_y_airgap   % m
    %-------------------------------------------------------
    C1
    C2
    C3
end

methods
function OBJ = bh_solenoid
    
    OBJ.volts_rated   = 7.6;
    OBJ.resistance    = 1.9;
    OBJ.current_rated = OBJ.volts_rated / OBJ.resistance;
    
    OBJ.mass      = 0.6;
    OBJ.stiffness = 17;
    OBJ.damping   = 2*0.5*sqrt(OBJ.stiffness/OBJ.mass);
    
    OBJ.MAX_y_airgap = 0.06; % m
    
    % read the datasheet data
    [the_F_mag, the_y_m]  = get_Fmag_vs_stroke_datasheet(OBJ, false);
    
    OBJ.F_mag_datasheet = the_F_mag;
    OBJ.y_m_datasheet   = the_y_m;
    
    % do the curve fit
    my_fit_obj = do_curve_fit(OBJ);
    
    OBJ.C1 = my_fit_obj.C1;
    OBJ.C2 = my_fit_obj.C2;
    OBJ.C3 = my_fit_obj.C3;
end % bh_solenoid()
%==========================================================================
function [F_mag, y_m]  = get_Fmag_vs_stroke_datasheet(OBJ, tf_do_plot)
    if(1==nargin)
        tf_do_plot = false;
    end
    
    my_table = readtable('bh_Fe_vs_stroke_data.xlsx','Sheet','2870@100%');

    F_mag    = my_table.Force_N;
    y_m      = my_table.Stroke_m;
    
    % maybe plot it
    if(tf_do_plot)
       figure;
       plot(y_m, F_mag, 'r.', 'MarkerSize', 12);
       grid on, xlabel('STROKE y (m)'); 
                ylabel('F_{mag} (N)');
       title('Magnetization Force versus STROKE (air gap)')
    end
end % get_Fmag_vs_stroke_data()
%==========================================================================
function THE_FIT_OBJ = do_curve_fit(OBJ, tf_do_plot)
if(1==nargin)
    tf_do_plot = false;
end
    
 y_m   = OBJ.y_m_datasheet;
 F_mag = OBJ.F_mag_datasheet;   

 my_i  = OBJ.volts_rated / OBJ.resistance;
 
% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( y_m, F_mag );

% Set up fittype and options.
my_f = @(C1,C2,C3,y) bh_func_calc_my_F(C1,C2,C3, my_i, y);

ft   = fittype( my_f, 'independent', 'y','dependent', 'F');
opts = fitoptions( 'Method', 'NonlinearLeastSquares' );
opts.Display    = 'Off';
opts.Lower      = [0 0 0];
opts.StartPoint = [1 1 1];

% Fit model to data.
[THE_FIT_OBJ, gof] = fit( xData, yData, ft, opts );

% maybe plot it
if(tf_do_plot)
    figure( 'Name', 'Datasheet FIT' );
    h = plot( THE_FIT_OBJ, xData, yData );
    lgd = legend( h, 'data', 'our_FIT', 'Location', 'NorthEast');
    lgd.Interpreter = 'none';
       grid on, xlabel('STROKE y (m)'); 
                ylabel('F_{mag} (N)');
end
end % do_curve_fit()
%==========================================================================
function varargout = get_the_C_coeffs(OBJ)
    %  allowed usage:
    % [C1,C2,C3] = get_the_C_coeffs(OBJ)
    %     C_vec = get_the_C_coeffs(OBJ)
         
          C1 = OBJ.C1;
          C2 = OBJ.C2;
          C3 = OBJ.C3;
          
    switch(nargout)
        case 3
            varargout{1} = C1;
            varargout{2} = C2;
            varargout{3} = C3;
        case 1
            varargout{1} = [C1,C2,C3];
        otherwise
            error('UNknown usage mode !');
    end
end % get_the_C_coeffs()
%==========================================================================
function L = get_L_at_max_gap(OBJ)
          C1 = OBJ.C1;
          C2 = OBJ.C2;
          C3 = OBJ.C3;
          
          max_y_gap = OBJ.MAX_y_airgap;
          
          L = bh_func_calc_my_L(C1,C2,C3, max_y_gap);
end % get_L_at_max_gap()
%==========================================================================


end % METHODS
end % CLASSDEF
%==========================================================================
% LOCAL functions
%==========================================================================


