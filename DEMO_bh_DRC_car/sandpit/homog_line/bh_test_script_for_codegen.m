%% test data
rng(0)

NOISE_MAG = 0.1; %0.25;

slopey.u = 1:0.5:10;
slopey.v = 0.8*slopey.u + 3 + NOISE_MAG*randn(size(slopey.u));

vert.v   = -5:1:5;
vert.u   = 3*ones(size(vert.v)) + NOISE_MAG*randn(size(vert.v)); 

horz.u   = -5:1:5;
horz.v   = 3*ones(size(horz.u)) + NOISE_MAG*randn(size(horz.u));  

DATA_fh = @(source) deal(source.u, source.v);

%% test 4 - ROI plot
[u,v] = DATA_fh(slopey);

bh_func_for_codegen(u,v)
