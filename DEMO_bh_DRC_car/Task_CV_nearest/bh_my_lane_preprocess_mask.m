function [BLUE_out_s, YELL_out_s] = ...
    bh_my_lane_preprocess_mask(BLUE_s, YELL_s, fract_for_top_mask)  %#codegen

     [new_BLUE_BW, tmp,mask_Rmax] =  bh_mask_fraction_of_BW_image(BLUE_s.BW, fract_for_top_mask);
      new_YELL_BW                 =  bh_mask_fraction_of_BW_image(YELL_s.BW, fract_for_top_mask);
          
    tf_is_detected_BLUE = false;
    tf_is_detected_YELL = false;

    % can we detect BLUE things
    the_ind   = find(new_BLUE_BW);
    if( ~isempty(the_ind) )
       [B_y,~]   = ind2sub(size( new_BLUE_BW),the_ind); % convert INDS to SUBSCRIPTS
       B_y_range = max(B_y) - min(B_y);  
    
       if( (nnz(new_BLUE_BW) > 2) &  (B_y_range > 10)  )
          tf_is_detected_BLUE = true;
       end
    end
    
    % can we detect YELLOW things
    the_ind   = find(new_YELL_BW);
    if( ~isempty(the_ind) )
       [Y_y,~] = ind2sub(size( new_YELL_BW),the_ind); % convert INDS to SUBSCRIPTS
       Y_y_range = max(Y_y) - min(Y_y);  
    
       if( (nnz(new_YELL_BW) > 2) &  (Y_y_range > 10)  )
          tf_is_detected_YELL = true;
       end
    end
    
    % create Lane info objects
    BLUE_O     = lane_info_CLS(new_BLUE_BW, tf_is_detected_BLUE);
    YELL_O     = lane_info_CLS(new_YELL_BW, tf_is_detected_YELL);

    ulim       = [1, BLUE_O.NUM_COLS];
    vlim       = [(mask_Rmax+1), BLUE_O.NUM_ROWS];

    BLUE_O     = BLUE_O.calc_info(ulim, vlim);
    YELL_O     = YELL_O.calc_info(ulim, vlim);
    
    % take care of the outputs
    BLUE_out_s = BLUE_O.convert_to_struct();
    YELL_out_s = YELL_O.convert_to_struct();
end
%-#########################################################################
% E N D    O F    M A I N    F U N C T I O N
%-#########################################################################

