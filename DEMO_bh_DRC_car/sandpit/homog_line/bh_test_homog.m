%% test data
rng(0)

NOISE_MAG = 0.1; %0.25;

slopey.u = 1:0.5:10;
slopey.v = -1*slopey.u + 3 + NOISE_MAG*randn(size(slopey.u));

vert.v   = -5:1:5;
vert.u   = 3*ones(size(vert.v)) + NOISE_MAG*randn(size(vert.v)); 

horz.u   = -5:1:5;
horz.v   = 3*ones(size(horz.u)) + NOISE_MAG*randn(size(horz.u));  

DATA_fh = @(source) deal(source.u, source.v);

%% Test 1 - a SLOPEY line
[u,v] = DATA_fh(slopey);

OBJ   = bh_line_homog_CLS(u,v)

OBJ.plot_simple(u,v); axis equal; %xlim([1,10]); ylim([1,8])


%% test 2 - VERTICAL line
[u,v] = DATA_fh(vert);

OBJ   = bh_line_homog_CLS(u,v)

OBJ.plot_simple(u,v); axis equal; xlim([-7,7]); ylim([-20,20])

%% test 3 - HORIZONTAL line
[u,v] = DATA_fh(horz);

OBJ   = bh_line_homog_CLS(u,v)

OBJ.plot_simple(u,v);  axis equal; xlim([-7,7]); ylim([-20,20])

%% test 4 - ROI plot
[u,v] = DATA_fh(slopey);

OBJ   = bh_line_homog_CLS(u,v)

hax = OBJ.plot_simple(u,v);   axis equal; grid on;

ulim = [-5, 15];
vlim = [-10, 20];
ulim = [5, 10];
vlim = [-4, 10];

plot_intersection(OBJ, hax, 'r', ulim, vlim, true)
