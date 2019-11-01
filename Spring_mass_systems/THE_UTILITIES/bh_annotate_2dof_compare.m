function bh_annotate_2dof_compare( hax, X_LAB, Y_LAB)

axes(hax)
xlabel( X_LAB); 
ylabel( Y_LAB ); 
grid('on'); 
axis('tight');                       
legend({'Numeric','Analytic'}, 'Location','best');

end

