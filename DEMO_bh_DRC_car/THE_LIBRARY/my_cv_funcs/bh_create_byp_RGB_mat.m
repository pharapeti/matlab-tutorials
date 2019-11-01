function RGB_mat = bh_create_byp_RGB_mat(  num_ROWS, num_COLS, ...
                                           BLUE_PixelIdxList,  ...
                                           YELL_PixelIdxList,  ...
                                           PURP_PixelIdxList)

   % set the background to a light grey color
   RGB_mat = 0.65*255*ones(num_ROWS, num_COLS, 3,'uint8');
   
   % blue  has an RGB = [0,0,1]
   if( ~isempty(BLUE_PixelIdxList) )
      R = RGB_mat(:,:,1);
      G = RGB_mat(:,:,2);
      B = RGB_mat(:,:,3);
      R(BLUE_PixelIdxList) = 0;
      G(BLUE_PixelIdxList) = 0;
      B(BLUE_PixelIdxList) = 1*255;
      RGB_mat(:,:,1) = R;
      RGB_mat(:,:,2) = G;
      RGB_mat(:,:,3) = B;
   end
   
   % yellow  has an RGB = [1,1,0]
   if( ~isempty(YELL_PixelIdxList) )
      R = RGB_mat(:,:,1);
      G = RGB_mat(:,:,2);
      B = RGB_mat(:,:,3);
      R(YELL_PixelIdxList) = 1*255;
      G(YELL_PixelIdxList) = 1*255;
      B(YELL_PixelIdxList) = 0;
      RGB_mat(:,:,1) = R;
      RGB_mat(:,:,2) = G;
      RGB_mat(:,:,3) = B;
   end
   
   % purple (or magenta) has an RGB = [1,0,1]
   if( ~isempty(PURP_PixelIdxList) )
      R = RGB_mat(:,:,1);
      G = RGB_mat(:,:,2);
      B = RGB_mat(:,:,3);
      R(PURP_PixelIdxList) = 1*255;
      G(PURP_PixelIdxList) = 0;
      B(PURP_PixelIdxList) = 1*255;
      RGB_mat(:,:,1) = R;
      RGB_mat(:,:,2) = G;
      RGB_mat(:,:,3) = B;
   end
end % bh_create_byp_RGB_mat()
%--------------------------------------------------------------------------


