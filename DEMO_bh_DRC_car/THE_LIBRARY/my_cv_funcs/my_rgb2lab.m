function I_out = rgb2lab(I_in) %#codegen

% REFERENCES:
% 1.) https://en.wikipedia.org/wiki/CIE_1931_color_space
% 2.) https://en.wikipedia.org/wiki/Lab_color_space
% 3.) http://www.brucelindbloom.com/index.html?Eqn_RGB_XYZ_Matrix.html

assert( isa(I_in, 'uint8'), '###: I need a UINT8 for <rgb2lab.m>')

% convert to double

R = double(I_in(:,:,1));
G = double(I_in(:,:,2));
B = double(I_in(:,:,3));

% normalise pixel values to the range 0 to 1
R = R / 255;
G = G / 255;
B = B / 255;

% calculate the XYZ for each pixel
[M, N] = size(R);

% ref: http://www.brucelindbloom.com/index.html?Eqn_RGB_XYZ_Matrix.html
k_mat = [ 0.4124564  0.3575761  0.1804375;
          0.2126729  0.7151522  0.0721750;
          0.0193339  0.1191920  0.9503041; ];
 
the_delta    = 6/29;
the_delta_SQ = the_delta^2;
the_delta_3  = the_delta^3;

fh_1 = @(t) ( t.^(1/3)                   );
fh_2 = @(t) ( t./(3*the_delta_SQ) + 4/29 );

I_out = zeros(M,N,3);


xyz_mat = k_mat * [ R(:)'; G(:)'; B(:)' ];

X = reshape(xyz_mat(1,:), M, N) / 0.95047;
Y = reshape(xyz_mat(2,:), M, N);
Z = reshape(xyz_mat(3,:), M, N) / 1.08883;

X_tf_mask = X > the_delta_3;
Y_tf_mask = Y > the_delta_3;
Z_tf_mask = Z > the_delta_3;


I_out(:,:,1) = Y_tf_mask .* ( 116*fh_1(Y) -16 ) + ...
               Y_tf_mask .* ( 116*fh_2(Y) -16 ) ;
           
           
I_out(:,:,2) = 500*( ...
                      X_tf_mask .* fh_1(X)  + X_tf_mask .* fh_2(X) - ...
                      Y_tf_mask .* fh_1(Y)  - Y_tf_mask .* fh_2(Y) ...
                    );
    
I_out(:,:,3) = 200*( ...
                      Y_tf_mask .* fh_1(Y)  + Y_tf_mask .* fh_2(Y) - ...
                      Z_tf_mask .* fh_1(Z)  - Z_tf_mask .* fh_2(Z)   ...
                    );
           
end % rgb2lab
%_#########################################################################
% the_delta    = 6/29;
% the_delta_SQ = the_delta^2;
% the_delta_3  = the_delta^3;
% 
% fh_1 = @(t) ( t.^(1/3)                   );
% fh_2 = @(t) ( t./(3*the_delta_SQ) + 4/29 );
% 
% I_out = zeros(M,N,3);
% 
% 
% for ii=1:M
%  for jj=1:N
%     rgb_col = [R(ii,jj); G(ii,jj); B(ii,jj); ];
%     
%     xyz_col = k_mat * rgb_col;
%      
%     % and normalise for the d65 whitepoint
%     x = xyz_col(1) / 0.95047;
%     y = xyz_col(2);
%     z = xyz_col(3) / 1.08883;
%     
%     fx = 0;
%     if(x > the_delta_3)
%          fx =  fh_1(x);
%     else
%          fx =  fh_2(x);
%     end
%     
%     fy = 0;
%     if(y > the_delta_3)
%          fy =  fh_1(y);
%     else
%          fy =  fh_2(y);
%     end
%     
%     fz = 0;
%     if(z > the_delta_3)
%          fz =  fh_1(z);
%     else
%          fz =  fh_2(z);
%     end
%     
%     I_out(ii,jj,1) = 116*fy - 16;
%     I_out(ii,jj,2) = 500 * ( fx - fy );
%     I_out(ii,jj,3) = 200 * ( fy - fz );
%  end % ii
% end % jj

