tab = readtable('bh_yb_track.xlsx', 'Sheet','tmp_SHEET');
XR = tab.XR;           XL = tab.XL;
YR = tab.YR;           YL = tab.YL;
ZR = zeros(size(XR));  ZL = zeros(size(XL));

% XC = tab.XC;
% YC = tab.YC;
% ZC = zeros(size(XC));
% N = length(XC);
% TC = [1:N]';
% 
% XC = interp1(TC,XC, linspace(1,N,200));
% YC = interp1(TC,YC, linspace(1,N,200));
% ZC = interp1(TC,ZC, linspace(1,N,200));

XC = [1*linspace(0,22,22), (22+0*linspace(0,22,22)), linspace(22,0,22), 0*linspace(0,22,22)];
YC = [0*linspace(0,22,22), 1*linspace(0,22,22),  (22+0*linspace(0,22,22)), linspace(22,0,22)];
ZC = zeros(size(XC));

figure
plot3(XR,YR,ZR,'-b', 'LineWidth', 5); hold on
plot3(XL,YL,ZL,'-y', 'LineWidth', 5); hold on

grid on
xlabel('X', 'FontSize',16);
ylabel('Y', 'FontSize',16);
axis equal

%% add island
island_rgb = 0.5*[1,1,1];  %[0.8 0.8 0.8];
%roof
tmp_X = [  1.5,  20.5,   20.5,   1.5];
tmp_Y = [  1.5,   1.5,   20.5,  20.5];
tmp_Z = 0.3*ones(size(tmp_X));
hp = patch(tmp_X, tmp_Y, tmp_Z, island_rgb); %,'FaceColor', 'g')

%floor
tmp_X = [  1.5,  20.5,   20.5,   1.5];
tmp_Y = [  1.5,   1.5,   20.5,  20.5];
tmp_Z = 0*ones(size(tmp_X));
hp = patch(tmp_X, tmp_Y, tmp_Z, island_rgb); %,'FaceColor', 'g')

% wall #1
tmp_X = [  1.5,  20.5,   20.5,  1.5];
tmp_Y = [  1.5,   1.5,    1.5,  1.5];
tmp_Z = [    0,     0,    0.3,  0.3 ];
hp = patch(tmp_X, tmp_Y, tmp_Z, island_rgb); %,'FaceColor', 'g')

% wall #2
tmp_X = [  20.5,  20.5,   20.5,  20.5];
tmp_Y = [  1.5,   20.5,    20.5,  1.5];
tmp_Z = [    0,     0,    0.3,  0.3 ];
hp = patch(tmp_X, tmp_Y, tmp_Z, island_rgb); %,'FaceColor', 'g')

% wall #3
tmp_X = [ 20.5,   1.5,    1.5,  20.5];
tmp_Y = [  20.5,  20.5,   20.5,  20.5];
tmp_Z = [    0,     0,    0.3,  0.3 ];
hp = patch(tmp_X, tmp_Y, tmp_Z, island_rgb); %,'FaceColor', 'g')

% wall #4
tmp_X = [   1.5,   1.5,    1.5,   1.5];
tmp_Y = [  20.5,   1.5,    1.5,   20.5];
tmp_Z = [    0,     0,    0.3,  0.3 ];
hp = patch(tmp_X, tmp_Y, tmp_Z, island_rgb); %,'FaceColor', 'g')

%% add layers
tmp_X = [  40,  40, -20, -20];
tmp_Y = [ -20,  40,  40, -20];
tmp_Z = -0.2*ones(size(tmp_X));
hp = patch(tmp_X, tmp_Y, tmp_Z, [0.8 0.8 0.8]); %,'FaceColor', 'g')

% tmp_X = [  10,  10, -10, -10];
% tmp_Y = [ -10,  10,  10, -10];
% tmp_Z = -0.1*ones(size(tmp_X));
% hp = patch(tmp_X, tmp_Y, tmp_Z, [255,255, 194]/255); %,'FaceColor', 'g')

[tmp_X, tmp_Y, tmp_Z] = cylinder(0.3);
tmp_Z = 0.6*tmp_Z;

surf(10+tmp_X,-0.5+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1])  %[1 0 1]
surf(18+tmp_X, 0.5+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1])

surf(21.5+tmp_X,  8+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1])
surf(22.5+tmp_X, 15+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1])

surf(10+tmp_X,21.5+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1])  %[1 0 1]
surf(18+tmp_X,22.5+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1])

surf(-0.5+tmp_X,  8+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1])
surf( 0.5+tmp_X, 15+tmp_Y, tmp_Z,'EdgeColor','none','FaceColor', [1 0 1])

%%
%xlim([-100,100]);
%ylim([-100,100])

campos([2,0,0.4]);
camtarget([10,0,0])
camproj('perspective') 
%camproj('orthographic') 
camva(77)


%% animate
N  = length(XC);
dt = 1; 
hax_cam = gca;
for kk=2:N %(N-8)

    xd = XC(kk) - XC(kk-1); 
    yd = YC(kk) - YC(kk-1);

    v = [xd, yd]/dt;

    v_norm = norm(v);

    if (v_norm ~= 0)
      %pos_tgt = [XC(kk),  YC(kk)]; % + 0.2*v/v_norm;
      pos_tgt = [XC(kk),  YC(kk)] + 10*v/v_norm;
      pos_tgt = [pos_tgt,0];
    end
    pos_cam = [XC(kk),  YC(kk),0.4];
    % pos_tgt = [XC(kk),YC(kk),0];

    %campos( pos_cam  )
    %camtarget( pos_tgt )
    %camtarget(pos_tgt)
    %camva(20)

    set(hax_cam,'CameraPosition',pos_cam, 'CameraTarget',pos_tgt);
    
    pause(0.3) 
end
