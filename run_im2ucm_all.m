%install
addpath('./pfe/');
addpath('./external/suitesparse/');
addpath('./external/bsr/')
%addpath('./external/sfedges/')
%addpath(genpath('./external/sfedges/toolbox-master'))
addpath('./external/vlfeat/')
addpath('./scripts')
addpath('./external/structured_forest/')
addpath('./datasets/')
addpath('./lib')

clear;clc;

[param_ini,param_s,param_ucm]=get_parameters('s',0.8,'w', 'journal');
database='BSDS500';
gt_set='test';

res_root = '/home/cwfang/Results/';
res_dir=fullfile(res_root,database,['DB' param_ini.flag  param_s.wtype 'PFEp' num2str(param_s.p) '_' param_s.version]);
version = ['re_multi_fq' num2str(param_ucm.fq) '_thr' num2str(param_ucm.thr) '_satsPb' num2str(param_s.sat_sPb) '_or' num2str(param_s.or2)];
im2ucmpnorm_all(database, gt_set,res_dir,version,param_s,param_ucm,param_ini);
