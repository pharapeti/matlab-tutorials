classdef bh_exp_units_of_rotat_speed_ENUM
% ATTENTION:
% This Enumeration class is used inside the class <bh_unit_converter_CLS>
        
 enumeration
      %               TO_BASE            FROM_BASE  
      rad_per_sec     (@(x)x            , @(x)x           )
      RPS             (@(x)x*2*pi       , @(x)x/(2*pi)    )
      RPM             (@(x)x*2*pi/60    , @(x)x/(2*pi/60) )
      deg_per_sec     (@(x)x*pi/180     , @(x)x/(pi/180)  )
end
properties
    ToBaseUnits
    FromBaseUnits
end
%-#########################################################################    
methods
%--------------------------------------------------------------------------
function obj = bh_exp_units_of_rotat_speed_ENUM(toFct, fromFct)
         obj.ToBaseUnits   = toFct;
         obj.FromBaseUnits = fromFct;
end
%--------------------------------------------------------------------------
end % methods
%-#########################################################################    
end % classdef

