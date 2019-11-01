classdef bh_exp_units_of_trans_speed_ENUM
% ATTENTION:
% This Enumeration class is used inside the class <bh_unit_converter_CLS>
 enumeration
      %              TO_BASE            FROM_BASE  
      m_per_sec     (@(x)x             , @(x)x              )
      cm_per_sec    (@(x)x/100         , @(x)x*100          )
      km_per_hr     (@(x)x*1000/3600   , @(x)x/(1000/3600) )
end
properties
    ToBaseUnits
    FromBaseUnits
end
%-#########################################################################    
methods
%--------------------------------------------------------------------------
function obj = bh_exp_units_of_trans_speed_ENUM(toFct, fromFct)
         obj.ToBaseUnits   = toFct;
         obj.FromBaseUnits = fromFct;
end
%--------------------------------------------------------------------------
end % methods
%-#########################################################################    
end % classdef

