function my_dL = bh_func_calc_my_dLdy(C1,C2,C3, y)
         my_dL = -1 * C2 * (C1/C2) ./ ( (C2*y + C3).^2 );
end