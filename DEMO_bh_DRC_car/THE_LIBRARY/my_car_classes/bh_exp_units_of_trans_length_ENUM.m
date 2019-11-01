classdef bh_exp_units_of_trans_length_ENUM
% ATTENTION:
% This Enumeration class is used inside the class <bh_unit_converter_CLS>
 enumeration
      %     TO_BASE         FROM_BASE  
      m     (@(x)x        , @(x)x      )
      cm    (@(x)x/100    , @(x)x*100  )
      km    (@(x)x*1000   , @(x)x/1000 )
end
properties
    ToBaseUnits
    FromBaseUnits
end
%-#########################################################################    
methods
%--------------------------------------------------------------------------
function obj = bh_exp_units_of_trans_length_ENUM(toFct, fromFct)
         obj.ToBaseUnits   = toFct;
         obj.FromBaseUnits = fromFct;
end
%--------------------------------------------------------------------------
end % methods
%-#########################################################################    
end % classdef

