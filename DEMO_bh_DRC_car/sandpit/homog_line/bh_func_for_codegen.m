function bh_func_for_codegen(u,v)


OBJ   = bh_line_homog_CLS(u,v);

if(1 == coder.target('MATLAB') )
   hax = OBJ.plot_simple(u,v);   axis equal; grid on;
end

ulim = [-5, 15];
vlim = [-10, 20];
ulim = [5, 10];
vlim = [-4, 10];

  [tf_is_valid, uv_bot, uv_top] = OBJ.get_roi_intersection_co_ords(ulim, vlim);

  
if(1 == coder.target('MATLAB') )
    OBJ.plot_intersection(hax, 'r', ulim, vlim, true);
end

end
