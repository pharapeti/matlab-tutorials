function my_F = bh_func_calc_my_F(C1,C2,C3, i, y)
         my_F = 0.5 * (i^2) * C1 ./ ( (C2*y + C3).^2 );
end