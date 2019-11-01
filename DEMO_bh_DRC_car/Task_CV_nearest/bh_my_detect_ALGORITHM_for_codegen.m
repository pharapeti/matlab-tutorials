function [BLUE_s, YELL_s, PURP_s] = bh_my_detect_ALGORITHM_for_codegen(I, tf_do_init, marker_s) %#codegen
% ALLOWED USAGE:
%  >> [BLUE_s, YELL_s, PURP_s] = bh_my_detect_ALGORITHM_for_codegen(I, tf_do_init, marker_s)

persistent OBJ_ybp
persistent fr_count
persistent hax
persistent hi

if(isempty(fr_count))
    fr_count = 0;
end

% *************************************************************************
%      do OBJECT INITIALIZATION
% *************************************************************************
if(true==tf_do_init || isempty(OBJ_ybp) )
    fr_count = 0;
    
    % create an instance of the ybp finder
    OBJ_ybp  = ybp_finder_CLS(marker_s);
    
end % if(true==tf_do_init)

% update the frame counter
fr_count = fr_count + 1;

% *************************************************************************
%      CLASSIFY stuff
% *************************************************************************
OBJ_ybp = OBJ_ybp.classify(I);

[ BLUE_s, YELL_s, PURP_s ] = OBJ_ybp.find_all_stuff();

% *************************************************************************
%      VISUALIZE  stuff
% *************************************************************************

if(1 ==coder.target('MATLAB') )

    % close any open figures that we want to target
    if(true==tf_do_init)
       hf = findobj('Type', 'figure', 'Tag', 'TAG_FIG_BH_MY_CV');
      if( ~isempty(hf) )
          close(hf);
      end
    end
    
    num_ROWS = size(I,1);
    num_COLS = size(I,2);
       
    BW = BLUE_s.BW | YELL_s.BW | PURP_s.BW;
    b_pix = find(true==BLUE_s.BW);
    y_pix = find(true==YELL_s.BW);
    p_pix = find(true==PURP_s.BW);
    
    RGB_mat  = bh_create_byp_RGB_mat(  num_ROWS, num_COLS, ...
                                          b_pix,  ...
                                          y_pix,  ...
                                          p_pix);
    
    hf = findobj('Type', 'figure', 'Tag', 'TAG_FIG_BH_MY_CV');
    if( isempty(hf) )
        figure('Tag', 'TAG_FIG_BH_MY_CV', 'Name', 'FIG_BH_MY_CV');
        THE_hax(1) = subplot(2,2,1, 'Tag', 'TAG_HX_1');
        THE_hax(2) = subplot(2,2,2, 'Tag', 'TAG_HX_2');
        THE_hax(3) = subplot(2,2,3, 'Tag', 'TAG_HX_3_TGT_FOR_LINE_TRACK');
        THE_hax(4) = subplot(2,2,4, 'Tag', 'TAG_HX_4'); 
        hax = THE_hax;
    end
        
    % plot stuff - the if-else makes the plotting faster ! (DN tip)
    if isempty(get(hax(1),'Children'))
         THE_hi(1) = imshow(I,       'Parent', hax(1));
         THE_hi(2) = imshow(RGB_mat, 'Parent', hax(2));
         THE_hi(3) = imshow(RGB_mat, 'Parent', hax(3));
         THE_hi(4) = imshow(BW,      'Parent', hax(4));   
         
         % and of course the TAGs will be cleared .. so reassign
         hax(3).Tag = 'TAG_HX_3_TGT_FOR_LINE_TRACK';
         
         hi = THE_hi;
    else
         hi(1).CData = I;
         hi(2).CData = RGB_mat;
         hi(3).CData = RGB_mat;
         hi(4).CData = BW;
    end
    
    %title( hax(1), sprintf('FRAME = %3d',fr_count) )

    drawnow
end


end % bh_my_ALGORITHM_for_codegen(I)
%-#########################################################################
% E N D    O F    M A I N    F U N C T I O N
%-#########################################################################

