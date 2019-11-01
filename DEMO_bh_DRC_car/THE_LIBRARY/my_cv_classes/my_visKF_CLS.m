classdef my_visKF_CLS
properties (SetAccess = protected)
   MotionModel          = 'ConstantVelocity'; %'ConstantAcceleration';
   InitialLocation;
   InitialEstimateError;
   MotionNoise;
   MeasurementNoise;
   %------------------------------
   KF;
   %------------------------------
   missed_detect_count = 0;
   %------------------------------
   xy = [];
   %------------------------------
   xs_col_mat = [];
end
%--------------------------------------------------------------------------
properties
   plot_TAG = 'TAG_PLOT_KF'; % used in plot() 
end
%_#########################################################################
methods
function OBJ = my_visKF_CLS( InitialLocation,      ...
                             InitialEstimateError, ...
                             MotionNoise,          ...
                             MeasurementNoise )

    validateattributes(InitialLocation,     {'double'}, {'vector','numel',2});                         
    validateattributes(InitialEstimateError,{'double'}, {'vector','numel',2});                         
    validateattributes(MotionNoise,         {'double'}, {'vector','numel',2});                         
    validateattributes(MeasurementNoise,    {'double'}, {'scalar'});                         

    OBJ.KF = configureKalmanFilter( OBJ.MotionModel, ...
                                    InitialLocation, ...
                                    InitialEstimateError, ...
                                    MotionNoise, ...
                                    MeasurementNoise);
                                
    OBJ.InitialLocation      = InitialLocation;
    OBJ.InitialEstimateError = InitialEstimateError;
    OBJ.MotionNoise          = MotionNoise;
    OBJ.MeasurementNoise     = MeasurementNoise;
end % my_visKF_CLS()
%-------------------------------------------------------------------------- 
function  OBJ = pred_and_correct(OBJ, BW, pixIND_list)
    
    % use KF to predict
    xy_pred = OBJ.KF.predict();
    xy      = xy_pred;
    % now do we have a measurement to allow a correction
    lane_O = lane_info_CLS(BW, pixIND_list);
    if( lane_O.is_detected() )
        lane_O = lane_O.calc_info();
        xy     = lane_O.get_xy();
        
        xy_corr = OBJ.KF.correct(xy);
        xy      = xy_corr;
    end
    
    % take care of the OUTPUTS
    OBJ.xy = xy;
    
    OBJ.xs_col_mat = [OBJ.xs_col_mat, OBJ.KF.State];
end % pred_and_correct()
%-------------------------------------------------------------------------- 
function xy = get_xy(OBJ)
         xy = OBJ.xy;
end % get_xy()
%--------------------------------------------------------------------------
function plot(OBJ, hax, linspec)
% ALLOWED usage:
%  >> OBJ.plot(hax)
%  >> OBJ.plot(hax,'.r')
   
    if( 2==nargin )
        linspec = '.r';
    end

    xy = OBJ.xy;
    if( isempty(xy) )
        return
    end
    
    % OK: we have some xy data
    TAG = OBJ.plot_TAG;
    hL = findall(hax,'Tag',TAG);
    
    if( isempty(hL) )
       hold(hax,'on');
       plot(hax,xy(1), xy(2),linspec,'MarkerSize',22, 'Tag',TAG);
    else
       hL.XData = xy(1);
       hL.YData = xy(2);
    end
end
%--------------------------------------------------------------------------

end % methods
%_#########################################################################

%-------------------------------------------------------------------------- 
%-------------------------------------------------------------------------- 
%-------------------------------------------------------------------------- 
%-------------------------------------------------------------------------- 
%-------------------------------------------------------------------------- 
end % classdef
%_#########################################################################
% END CLASSDEF
%_#########################################################################
