classdef bh_line_homog_CLS %#codegen
    
%  a.U + b.V + d = 0
    
    
properties (SetAccess = private)
    abd_col = [0;0;0];
    a
    b
    d
    line_type(1,1) string {mustBeMember(line_type,["HORZ","VERT","SLOPEY","UNKNOWN"])} = "UNKNOWN";
end

methods
function OBJ = bh_line_homog_CLS(u,v) 
    
u = u(:);
v = v(:);
A = [u,v, ones(size(u))];
B = [1,0,0;
     0,1,0];
[eVec_mat, eVal_mat] = eig(A'* A,  B'*B);

% for codegen
eVec_mat = real(eVec_mat);
eVal_mat = real(eVal_mat);

% where's the smallest eigenvalue
[~,ind]     = min(diag(eVal_mat));

THE_SOL_VEC = eVec_mat(:,ind);
normal_vec  = THE_SOL_VEC(1:2);

% classify the type of line
OBJ.line_type = LOC_classify_line_type(normal_vec);

switch(OBJ.line_type)
    case "SLOPEY"
          THE_SOL_VEC = THE_SOL_VEC / THE_SOL_VEC(2); 
    case "VERT"
          THE_SOL_VEC = THE_SOL_VEC / THE_SOL_VEC(1); 
    case "HORZ"
          THE_SOL_VEC = THE_SOL_VEC / THE_SOL_VEC(2); 
    otherwise
        error('###_ERROR:  unknown line type');
end

OBJ.abd_col = THE_SOL_VEC;
OBJ.a       = THE_SOL_VEC(1);
OBJ.b       = THE_SOL_VEC(2);
OBJ.d       = THE_SOL_VEC(3);
end   % bh_line_homog_CLS
%==========================================================================
function tf_val = isVert(OBJ)
         tf_val = OBJ.line_type == "VERT"; 
end
%==========================================================================
function tf_val = isHorz(OBJ)
         tf_val = OBJ.line_type == "HORZ"; 
end
%==========================================================================
function [u,v] = calc_uv(OBJ,u_meas, v_meas)  
    
    u_meas = u_meas(:);
    v_meas = v_meas(:);
    N      = length(u_meas);
    
    % a.U + b.V + d = 0
    if( OBJ.isVert() )
         % a.U + b.V + d = 0
         % then we have a VERTICAL ||| line
         v = linspace(min(v_meas), max(v_meas), N)'; % a COL       
         u = (-1*OBJ.d/OBJ.a)  *  ones(size(v));
    elseif(OBJ.isHorz())
         % a.U + b.V + d = 0
         % then we have a HORIZONTAL --- line
         u = linspace(min(u_meas), max(u_meas), N)'; % a COL
         v = (-OBJ.d/OBJ.b)  *  ones(size(u));
    else
         % a.U + b.V + d = 0
         % then we have a SLOPEY ///\\\ line
         u = u_meas;
         v = -1*(OBJ.d + OBJ.a*u_meas)/OBJ.b;
    end  
end
%========================================================================== 
function hax = plot_simple(OBJ,u_meas,v_meas)
    hax = [];
    % this is purely a visualization method
    % so NONE of it is releveant for a CODER deployment
    if(1 ==coder.target('MATLAB') )
        figure;
        hax = axes;
        plot(hax,u_meas,v_meas,'ro');  axis tight; grid on
          hold on

        [u,v] = OBJ.calc_uv(u_meas, v_meas); 
        plot(hax,u,v,'-b', 'LineWidth',2);

        tmp_c = ['Line type is ', char(OBJ.line_type)];
        title(hax,tmp_c); 
        axis(hax,'equal');
        hax.YDir = 'reverse';
    end
end
%==========================================================================
function [tf_is_valid, uv_bot, uv_top] = get_roi_intersection_co_ords(OBJ, ulim, vlim)
         [tf_is_valid, uv_bot, uv_top] = LOC_get_roi_intersection_co_ords(OBJ, ulim, vlim); 
end
%==========================================================================
function plot_intersection(OBJ, hax, color_char, ulim, vlim, tf_plot_roi)
    % this is purely a visualization method
    % so NONE of it is releveant for a CODER deployment
    if(1 ==coder.target('MATLAB') )
           if(isempty(hax))
               figure;
               hax = axes();
               axis(hax,'equal');
               hax.YDir = 'reverse';
           end    

           if( true==tf_plot_roi )
               u = [ulim(1), ulim(2), ulim(2), ulim(1), ulim(1)];
               v = [vlim(1), vlim(1), vlim(2), vlim(2), vlim(1)];
               %plot(hax,u,v,'-m','LineWidth',2);
               hL = line(hax,'XData',u,'YData',v,'Color','m','LineStyle','-','LineWidth',2);
           end

           [tf_is_valid, uv_bot, uv_top] = get_roi_intersection_co_ords(OBJ, ulim, vlim);

           if(false==tf_is_valid)
               return
           end

           u = [uv_bot(1),uv_top(1)];
           v = [uv_bot(2),uv_top(2)];

           % plot the line   
           hL = line(hax,'XData',u,'YData',v,'Color',color_char, ...
                     'LineStyle','-','LineWidth',2 );

           % plot an o for the TOP point
           line(hax,'XData',uv_top(1),'YData',uv_top(2),'Color',color_char, ...
                     'Marker', 'o', 'MarkerSize',10,'MarkerfaceColor',color_char); 

           % plot an o for the BOT point      
           line(hax,'XData',uv_bot(1),'YData',uv_bot(2),'Color',color_char, ...
                     'Marker', 's', 'MarkerSize',10,'MarkerfaceColor',color_char); 
    end         
end
%==========================================================================

end % methods
%==========================================================================
    
end % classdef
%_#########################################################################
% Local HELPER functions
%_#########################################################################

function a_str = LOC_classify_line_type(normal_vec)

    normal_vec = normal_vec / norm(normal_vec);
    Y          = normal_vec(2); % V
    X          = normal_vec(1); % U
    
    theta_rad  = atan2(Y,X);          % [-pi , pi]
    theta_deg  = theta_rad * 180/pi;  % [-180, 180]

    % convert angle from [-180,180] to [0, 360]
    if(theta_deg<0)
        theta_deg = 360 + theta_deg;
    end    

    % first categorise the NORMAL to the line
    tf_the_normal_is_horz = false;
    tf_the_normal_is_vert = false;

    %  so we have   0 <= theta_deg <= 360
    TOL_DEG = 2; % a tolerence
    if(      (theta_deg <= TOL_DEG       )   || ...
             (theta_deg >= (360-TOL_DEG) )   || ...
         (   (theta_deg >= (180-TOL_DEG) )   && ...
             (theta_deg <= (180+TOL_DEG) )   ) ...
       )
           tf_the_normal_is_horz = true;

    elseif(    (theta_deg >= (90-TOL_DEG)  && (theta_deg <= (90+TOL_DEG))) || ...
               (theta_deg >= (270-TOL_DEG) && (theta_deg <= (270+TOL_DEG))) ...
          )
           tf_the_normal_is_vert = true;
    else
           % do NOTHING
    end

    % OK: so we know the orientation of the NORMAL vector
    %     now we can classify the actual LINE

    if(true==tf_the_normal_is_horz)
            a_str = "VERT";
    elseif(true==tf_the_normal_is_vert)
           a_str = "HORZ";
    else
           a_str = "SLOPEY";
    end
end %LOC_classify_line_type
%==========================================================================
function [tf_is_valid, uv_bot, uv_top] = LOC_get_roi_intersection_co_ords(OBJ, ulim, vlim)

    validateattributes(ulim,{'numeric'},{'vector','numel',2});
    validateattributes(ulim,{'numeric'},{'vector','numel',2});

    tf_is_valid = false;    
    uv_bot = [NaN;NaN];
    uv_top = [NaN;NaN];

    switch(OBJ.line_type)
        case "VERT"
             u = (-1*OBJ.d/OBJ.a);
             if( (u <= ulim(2)) && (u>=ulim(1)) )
                  uv_bot = [u;vlim(2)];
                  uv_top = [u;vlim(1)];
                  tf_is_valid = true;    
             end

             return % RETURN
        case "HORZ"
             v = (-OBJ.d/OBJ.b);
             if( (v <= vlim(2)) && (v>=vlim(1)) )
                  uv_bot = [ulim(1);v];
                  uv_top = [ulim(2);v];
                  tf_is_valid = true;    
             end
             return % RETURN
    end

    % so if we made it to here then we have a SLOPEY line
    %  a.U + b.V + d = 0

    my_Vf = @(U) (-1*(OBJ.d + OBJ.a*U)/OBJ.b);
    my_Uf = @(V) (-1*(OBJ.d + OBJ.b*V)/OBJ.a);

    [tf_west,  UV_west ] = LOC_get_side_intersect_point("WEST",  my_Vf, my_Uf, ulim, vlim);
    [tf_east,  UV_east ] = LOC_get_side_intersect_point("EAST",  my_Vf, my_Uf, ulim, vlim);
    [tf_north, UV_north] = LOC_get_side_intersect_point("NORTH", my_Vf, my_Uf, ulim, vlim);
    [tf_south, UV_south] = LOC_get_side_intersect_point("SOUTH", my_Vf, my_Uf, ulim, vlim);

    the_tf_mat = [tf_west, tf_east, tf_north, tf_south];
    the_UV_mat = [UV_west, UV_east, UV_north, UV_south];

    if(2 ~= nnz(the_tf_mat) )
       return
    end

    % OK: so our line has intersected our ROI box

    THE_SOL_UV_mat = the_UV_mat(:,the_tf_mat ); 

    UV_A = THE_SOL_UV_mat(:,1);
    UV_B = THE_SOL_UV_mat(:,2);

    if( UV_A(2) > UV_B(2))
        uv_bot = UV_A;
        uv_top = UV_B;
    else
        uv_bot = UV_B;
        uv_top = UV_A;
    end
    tf_is_valid = true;    

end % LOC_get_roi_intersection_co_ords()
%==========================================================================
function tf_val = LOC_UV_is_in_box(UV, ulim, vlim)

    tf_val = false;
    u      = UV(1);
    v      = UV(2);

    if( (u <= ulim(2)) && (u >= ulim(1)) && ...
        (v <= vlim(2)) && (v >= vlim(1))   ...
       )
         tf_val = true;
    else
         tf_val = false;
    end

end % LOC_UV_is_in_box(()
%==========================================================================
function [tf_valid_intersection, UV] = ...
    LOC_get_side_intersect_point(side_str, my_Vf, my_Uf, ulim, vlim)
 
    % SUMMARY:
    %   for a specified side of an ROI box, where (if at all)
    %   does our line intersect that side of teh ROI box

    UV = [0;0];
    tf_valid_intersection = false;
    
    % assert that our side_str INPUT argument is a valid
    %mustBeMember(side_str, ["NORTH","SOUTH","EAST","WEST"] );

    % 
    %          0------------------------------> U
    %          |
    %          |               NORTH
    %          |           *-------------*
    %          |          |              |
    %          |          |              |
    %          |    WEST  |              |  EAST
    %          |          |              | 
    %          |          |              |
    %          |          *--------------*
    %          |               SOUTH    
    %      V   V   

    FH_in_V_zone = @(V) ( (V <= vlim(2)) & (V >= vlim(1)) );
    FH_in_U_zone = @(U) ( (U <= ulim(2)) & (U >= ulim(1)) );

    switch(side_str)
        case "WEST"
                   u = ulim(1);  v = my_Vf(u);
                   UV = [u;v];
                   if( FH_in_V_zone(v) )
                       tf_valid_intersection = true;
                   end
        case "EAST"
                   u = ulim(2);  v = my_Vf(u);
                   UV = [u;v];
                   if( FH_in_V_zone(v) )
                       tf_valid_intersection = true;
                   end
        case "NORTH"
                   v = vlim(1);  u = my_Uf(v);
                   UV = [u;v];
                   if( FH_in_U_zone(u) )
                       tf_valid_intersection = true;
                   end
        case "SOUTH"
                   v = vlim(2);  u = my_Uf(v);
                   UV = [u;v];
                   if( FH_in_U_zone(u) )
                       tf_valid_intersection = true;
                   end
        otherwise
            error('###_ERROR:  UNknown BOX side string');
    end
end %LOC_get_side_intersect_point
%==========================================================================
