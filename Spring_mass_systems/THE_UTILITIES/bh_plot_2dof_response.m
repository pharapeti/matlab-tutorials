function bh_plot_2dof_response( t, x1, x2, x1_dot, x2_dot, LIN_SPEC )


figure;
subplot(2,2,1);
   plot(t, x1, LIN_SPEC);       xlabel('t (secs)'); 
                               ylabel('X1 (m)'); grid('on'); 
                               axis('tight');
                               legend('X1', 'Location', 'best');
%----------------------------------------------------------------------- 
subplot(2,2,2);
   plot(t, x2, LIN_SPEC);  
                               xlabel('t (secs)'); 
                               ylabel('X2 (m)'); 
                               grid('on'); axis('tight');
                               legend('X2', 'Location', 'best');
%-----------------------------------------------------------------------                               
subplot(2,2,3);
   plot(t, x1_dot, LIN_SPEC);  
                               xlabel('t (secs)'); 
                               ylabel('X1 dot (m/s)'); 
                               grid('on'); axis('tight');
                               legend('X1 DOT', 'Location', 'best');
%----------------------------------------------------------------------- 
subplot(2,2,4);
   plot(t, x2_dot, LIN_SPEC);  
                               xlabel('t (secs)'); 
                               ylabel('X2 dot (m/s)'); 
                               grid('on'); axis('tight');
                               legend('X2 DOT', 'Location', 'best');
%----------------------------------------------------------------------- 
                               
end

