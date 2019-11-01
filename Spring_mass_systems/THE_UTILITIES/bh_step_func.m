function y = bh_step_func( t, t_of_step, y_before_step, y_after_step )

    y      = y_before_step * ones(  size(t)  );

    ind    = (t >= t_of_step);

    y(ind) = y_after_step;


end

