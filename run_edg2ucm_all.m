install
database='VOCContext';
gt_set='test';
res_root = '/home2/cwfang/Results/';
res_dir=fullfile(res_root,database,'DB-UCM');
paras =struct('thr',0.5,'fq',8);

edg2ucm_all(database, gt_set,res_dir,paras)