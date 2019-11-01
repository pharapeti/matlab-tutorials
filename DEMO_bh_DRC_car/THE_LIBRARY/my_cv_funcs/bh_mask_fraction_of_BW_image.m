function [I, tf_was_applied, R_max] = bh_mask_fraction_of_BW_image(I_BW, the_frac)
%  [I, tf_was_applied] = bh_mask_fraction_of_BW_image(I_BW, the_frac)
%-------------------------------------------------------------------------      
% Apply a mask of 0's to the first "N" rows of an image matrix
% where N is determined by the fraction scalar provided by the user
% 
% When you view this masked image, the TOP portion of the image will appear blacked out
% 
% EXAMPLE:     if our input image has 9 rows, 
%              and if we set the_frac = 2/3 
%              
%              then the desired effect would look something like this:
% 
%             0-------------------------->  u, x
%  row #1     | 0 0 0 0 0 0 0 0 
%  row #2     | 0 0 0 0 0 0 0 0 
%  row #3     | 0 0 0 0 0 0 0 0 
%  row #4     | 0 0 0 0 0 0 0 0 
%  row #5     | 0 0 0 0 0 0 0 0 
%  row #6     | 0 0 0 0 0 0 0 0 
%  row #7     | . . . . . . . . 
%  row #8     | . . . . . . . . 
%  row #9     | . . . . . . . . 
%         v, y
%-------------------------------------------------------------------------      

if(1 ==coder.target('MATLAB') )
    % make sure fraction is in the range:  0 < fract <= 1
    validateattributes(the_frac,{'double'},{'scalar', '<=',1, '>',0})

    % make sure we have a 2d matrix
    validateattributes(I_BW,{'numeric','logical'},{'2d'})
end

% OK: now do your thing
tf_was_applied = false;
I              = I_BW;
NUM_ROWS       = size(I,1);

% Mask the top portion of the image:
R_max            = round(   NUM_ROWS * the_frac   );

if(R_max == NUM_ROWS)
    % do nothing
else
    if(R_max > 1)
       I(1:R_max, :)    = 0;
       tf_was_applied   = true;
       masked_row_range = 1:R_max;
    end
end

end % bh_ignore_fraction_of_BW_image(I_BW, frac)

