function bh_plot_2dof_R_and_I( t_vec, X1_R, X1_I, X2_R, X2_I, leg_X1, leg_X2)

figure
    subplot(2,2,1);
        plot(t_vec, X1_R, '.-b' );  legend(['REAL(', leg_X1,')']);
        grid('on'); axis('tight');
    subplot(2,2,3);
        plot(t_vec, X1_I, '.-k' );  xlabel('time (secs)');  legend(['IMAG(', leg_X1,')']);
        grid('on'); axis('tight');
    subplot(2,2,2);
        title('x2(t)');
        plot(t_vec, X2_R, '.-b' );  legend(['REAL(', leg_X2,')']);
        grid('on'); axis('tight');
    subplot(2,2,4);
        plot(t_vec, X2_I, '.-k' );   xlabel('time (secs)'); legend(['IMAG(', leg_X2,')']); 
        grid('on'); axis('tight');

end

