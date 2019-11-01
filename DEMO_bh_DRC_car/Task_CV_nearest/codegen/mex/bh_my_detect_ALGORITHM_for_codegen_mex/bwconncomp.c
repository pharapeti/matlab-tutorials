/*
 * bwconncomp.c
 *
 * Code generation for function 'bwconncomp'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "bwconncomp.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Variable Definitions */
static emlrtRSInfo mc_emlrtRSI = { 9,  /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 30, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 43, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 55, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 56, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 57, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 65, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 33, /* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 51, /* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 114,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 149,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 150,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 153,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 1,/* lineNo */
  15,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = { 18,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 41,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 56,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = { 56,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 75,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = { 76,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 25,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = { 51,/* lineNo */
  57,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = { 51,/* lineNo */
  64,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  65,                                  /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  65,                                  /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 55,    /* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 55,  /* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  200,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  206,                                 /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  206,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 48,  /* lineNo */
  33,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  231,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  235,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  236,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  237,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  171,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  183,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 41,  /* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void bwconncomp(const emlrtStack *sp, const emxArray_boolean_T *varargin_1,
                real_T *CC_Connectivity, real_T CC_ImageSize[2], real_T
                *CC_NumObjects, emxArray_real_T *CC_RegionIndices,
                emxArray_int32_T *CC_RegionLengths)
{
  int32_T numRuns;
  int32_T firstRunOnPreviousColumn;
  int32_T lastRunOnPreviousColumn;
  int32_T offset;
  emxArray_int32_T *regionLengths;
  int32_T i4;
  emxArray_int32_T *startRow;
  emxArray_int32_T *endRow;
  emxArray_int32_T *startCol;
  int32_T k;
  int32_T runCounter;
  int32_T i5;
  emxArray_int32_T *labelsRenumbered;
  int32_T row;
  real_T numComponents;
  boolean_T exitg1;
  int32_T p;
  real_T y;
  emxArray_real_T *pixelIdxList;
  boolean_T overflow;
  emxArray_int32_T *x;
  int32_T root_k;
  int32_T exitg2;
  emxArray_int32_T *idxCount;
  int32_T root_p;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &mc_emlrtRSI;
  b_st.site = &tc_emlrtRSI;
  numRuns = 0;
  firstRunOnPreviousColumn = varargin_1->size[0];
  for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < 320;
       lastRunOnPreviousColumn++) {
    offset = lastRunOnPreviousColumn * firstRunOnPreviousColumn + 1;
    i4 = varargin_1->size[0] * 320;
    if (!((offset >= 1) && (offset <= i4))) {
      emlrtDynamicBoundsCheckR2012b(offset, 1, i4, &v_emlrtBCI, &b_st);
    }

    if (varargin_1->data[offset - 1]) {
      numRuns++;
    }

    i4 = (firstRunOnPreviousColumn + offset) - offset;
    for (k = 0; k <= i4 - 2; k++) {
      runCounter = offset + k;
      i5 = varargin_1->size[0] * 320;
      if (!((runCounter + 1 >= 1) && (runCounter + 1 <= i5))) {
        emlrtDynamicBoundsCheckR2012b(runCounter + 1, 1, i5, &w_emlrtBCI, &b_st);
      }

      if (varargin_1->data[runCounter]) {
        i5 = varargin_1->size[0] * 320;
        if (!((runCounter >= 1) && (runCounter <= i5))) {
          emlrtDynamicBoundsCheckR2012b(runCounter, 1, i5, &x_emlrtBCI, &b_st);
        }

        if (!varargin_1->data[runCounter - 1]) {
          numRuns++;
        }
      }
    }
  }

  emxInit_int32_T(&st, &regionLengths, 1, &ic_emlrtRTEI, true);
  emxInit_int32_T(&st, &startRow, 1, &pc_emlrtRTEI, true);
  emxInit_int32_T(&st, &endRow, 1, &qc_emlrtRTEI, true);
  emxInit_int32_T(&st, &startCol, 1, &rc_emlrtRTEI, true);
  if (numRuns == 0) {
    i4 = startRow->size[0];
    startRow->size[0] = 0;
    emxEnsureCapacity_int32_T(&st, startRow, i4, &yb_emlrtRTEI);
    i4 = endRow->size[0];
    endRow->size[0] = 0;
    emxEnsureCapacity_int32_T(&st, endRow, i4, &bc_emlrtRTEI);
    i4 = startCol->size[0];
    startCol->size[0] = 0;
    emxEnsureCapacity_int32_T(&st, startCol, i4, &cc_emlrtRTEI);
    i4 = regionLengths->size[0];
    regionLengths->size[0] = 0;
    emxEnsureCapacity_int32_T(&st, regionLengths, i4, &dc_emlrtRTEI);
  } else {
    i4 = startRow->size[0];
    if (!(numRuns >= 0)) {
      emlrtNonNegativeCheckR2012b(numRuns, &c_emlrtDCI, &st);
    }

    startRow->size[0] = numRuns;
    emxEnsureCapacity_int32_T(&st, startRow, i4, &ac_emlrtRTEI);
    i4 = endRow->size[0];
    endRow->size[0] = numRuns;
    emxEnsureCapacity_int32_T(&st, endRow, i4, &ac_emlrtRTEI);
    i4 = startCol->size[0];
    startCol->size[0] = numRuns;
    emxEnsureCapacity_int32_T(&st, startCol, i4, &ac_emlrtRTEI);
    b_st.site = &uc_emlrtRSI;
    firstRunOnPreviousColumn = varargin_1->size[0];
    runCounter = 1;
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < 320;
         lastRunOnPreviousColumn++) {
      offset = lastRunOnPreviousColumn * firstRunOnPreviousColumn;
      row = 1;
      while (row <= firstRunOnPreviousColumn) {
        exitg1 = false;
        while ((!exitg1) && (row <= firstRunOnPreviousColumn)) {
          i4 = varargin_1->size[0] * 320;
          i5 = row + offset;
          if (!((i5 >= 1) && (i5 <= i4))) {
            emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &y_emlrtBCI, &b_st);
          }

          if (!varargin_1->data[i5 - 1]) {
            row++;
          } else {
            exitg1 = true;
          }
        }

        if (row <= firstRunOnPreviousColumn) {
          i4 = varargin_1->size[0] * 320;
          i5 = row + offset;
          if (!((i5 >= 1) && (i5 <= i4))) {
            emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ab_emlrtBCI, &b_st);
          }

          if (varargin_1->data[i5 - 1]) {
            i4 = startCol->size[0];
            if (!((runCounter >= 1) && (runCounter <= i4))) {
              emlrtDynamicBoundsCheckR2012b(runCounter, 1, i4, &bb_emlrtBCI,
                &b_st);
            }

            startCol->data[runCounter - 1] = lastRunOnPreviousColumn + 1;
            i4 = startRow->size[0];
            if (!((runCounter >= 1) && (runCounter <= i4))) {
              emlrtDynamicBoundsCheckR2012b(runCounter, 1, i4, &cb_emlrtBCI,
                &b_st);
            }

            startRow->data[runCounter - 1] = row;
            exitg1 = false;
            while ((!exitg1) && (row <= firstRunOnPreviousColumn)) {
              i4 = varargin_1->size[0] * 320;
              i5 = row + offset;
              if (!((i5 >= 1) && (i5 <= i4))) {
                emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &db_emlrtBCI, &b_st);
              }

              if (varargin_1->data[i5 - 1]) {
                row++;
              } else {
                exitg1 = true;
              }
            }

            i4 = endRow->size[0];
            if (!((runCounter >= 1) && (runCounter <= i4))) {
              emlrtDynamicBoundsCheckR2012b(runCounter, 1, i4, &eb_emlrtBCI,
                &b_st);
            }

            endRow->data[runCounter - 1] = row - 1;
            runCounter++;
          }
        }
      }
    }

    i4 = regionLengths->size[0];
    regionLengths->size[0] = numRuns;
    emxEnsureCapacity_int32_T(&st, regionLengths, i4, &gc_emlrtRTEI);
    for (i4 = 0; i4 < numRuns; i4++) {
      regionLengths->data[i4] = 0;
    }

    k = 1;
    runCounter = 1;
    row = 1;
    firstRunOnPreviousColumn = -1;
    lastRunOnPreviousColumn = -1;
    offset = 1;
    while (k <= numRuns) {
      i4 = startCol->size[0];
      if (!((k >= 1) && (k <= i4))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i4, &fb_emlrtBCI, &st);
      }

      if (startCol->data[k - 1] == runCounter + 1) {
        firstRunOnPreviousColumn = offset;
        offset = k;
        lastRunOnPreviousColumn = k - 1;
        i4 = startCol->size[0];
        if (!((k >= 1) && (k <= i4))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i4, &ib_emlrtBCI, &st);
        }

        runCounter = startCol->data[k - 1];
      } else {
        i4 = startCol->size[0];
        if (!((k >= 1) && (k <= i4))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i4, &gb_emlrtBCI, &st);
        }

        if (startCol->data[k - 1] > runCounter + 1) {
          firstRunOnPreviousColumn = -1;
          lastRunOnPreviousColumn = -1;
          offset = k;
          i4 = startCol->size[0];
          if (!((k >= 1) && (k <= i4))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i4, &hb_emlrtBCI, &st);
          }

          runCounter = startCol->data[k - 1];
        }
      }

      if (firstRunOnPreviousColumn >= 0) {
        for (p = firstRunOnPreviousColumn; p <= lastRunOnPreviousColumn; p++) {
          i4 = endRow->size[0];
          if (!((k >= 1) && (k <= i4))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i4, &lb_emlrtBCI, &st);
          }

          i4 = startRow->size[0];
          if (!((p >= 1) && (p <= i4))) {
            emlrtDynamicBoundsCheckR2012b(p, 1, i4, &mb_emlrtBCI, &st);
          }

          if (endRow->data[k - 1] >= startRow->data[p - 1] - 1) {
            i4 = startRow->size[0];
            if (!((k >= 1) && (k <= i4))) {
              emlrtDynamicBoundsCheckR2012b(k, 1, i4, &nb_emlrtBCI, &st);
            }

            i4 = endRow->size[0];
            if (!((p >= 1) && (p <= i4))) {
              emlrtDynamicBoundsCheckR2012b(p, 1, i4, &ob_emlrtBCI, &st);
            }

            if (startRow->data[k - 1] <= endRow->data[p - 1] + 1) {
              i4 = regionLengths->size[0];
              if (!((k >= 1) && (k <= i4))) {
                emlrtDynamicBoundsCheckR2012b(k, 1, i4, &pb_emlrtBCI, &st);
              }

              if (regionLengths->data[k - 1] == 0) {
                i4 = regionLengths->size[0];
                if (!((p >= 1) && (p <= i4))) {
                  emlrtDynamicBoundsCheckR2012b(p, 1, i4, &bc_emlrtBCI, &st);
                }

                i4 = regionLengths->size[0];
                if (!((k >= 1) && (k <= i4))) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, i4, &cc_emlrtBCI, &st);
                }

                regionLengths->data[k - 1] = regionLengths->data[p - 1];
                row++;
              } else {
                i4 = regionLengths->size[0];
                if (!((k >= 1) && (k <= i4))) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, i4, &qb_emlrtBCI, &st);
                }

                i4 = regionLengths->size[0];
                if (!((p >= 1) && (p <= i4))) {
                  emlrtDynamicBoundsCheckR2012b(p, 1, i4, &rb_emlrtBCI, &st);
                }

                if (regionLengths->data[k - 1] != regionLengths->data[p - 1]) {
                  b_st.site = &vc_emlrtRSI;
                  c_st.site = &wc_emlrtRSI;
                  root_k = k;
                  do {
                    exitg2 = 0;
                    i4 = regionLengths->size[0];
                    if (!((root_k >= 1) && (root_k <= i4))) {
                      emlrtDynamicBoundsCheckR2012b(root_k, 1, i4, &sb_emlrtBCI,
                        &c_st);
                    }

                    if (root_k != regionLengths->data[root_k - 1]) {
                      i4 = regionLengths->size[0];
                      i5 = regionLengths->size[0];
                      if (!((root_k >= 1) && (root_k <= i5))) {
                        emlrtDynamicBoundsCheckR2012b(root_k, 1, i5,
                          &xb_emlrtBCI, &c_st);
                      }

                      i5 = regionLengths->data[root_k - 1];
                      if (!((i5 >= 1) && (i5 <= i4))) {
                        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xb_emlrtBCI,
                          &c_st);
                      }

                      i4 = regionLengths->size[0];
                      if (!((root_k >= 1) && (root_k <= i4))) {
                        emlrtDynamicBoundsCheckR2012b(root_k, 1, i4,
                          &yb_emlrtBCI, &c_st);
                      }

                      regionLengths->data[root_k - 1] = regionLengths->data[i5 -
                        1];
                      i4 = regionLengths->size[0];
                      if (!((root_k >= 1) && (root_k <= i4))) {
                        emlrtDynamicBoundsCheckR2012b(root_k, 1, i4,
                          &ac_emlrtBCI, &c_st);
                      }

                      root_k = regionLengths->data[root_k - 1];
                    } else {
                      exitg2 = 1;
                    }
                  } while (exitg2 == 0);

                  c_st.site = &xc_emlrtRSI;
                  root_p = p;
                  do {
                    exitg2 = 0;
                    i4 = regionLengths->size[0];
                    if (!((root_p >= 1) && (root_p <= i4))) {
                      emlrtDynamicBoundsCheckR2012b(root_p, 1, i4, &sb_emlrtBCI,
                        &c_st);
                    }

                    if (root_p != regionLengths->data[root_p - 1]) {
                      i4 = regionLengths->size[0];
                      i5 = regionLengths->size[0];
                      if (!((root_p >= 1) && (root_p <= i5))) {
                        emlrtDynamicBoundsCheckR2012b(root_p, 1, i5,
                          &xb_emlrtBCI, &c_st);
                      }

                      i5 = regionLengths->data[root_p - 1];
                      if (!((i5 >= 1) && (i5 <= i4))) {
                        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xb_emlrtBCI,
                          &c_st);
                      }

                      i4 = regionLengths->size[0];
                      if (!((root_p >= 1) && (root_p <= i4))) {
                        emlrtDynamicBoundsCheckR2012b(root_p, 1, i4,
                          &yb_emlrtBCI, &c_st);
                      }

                      regionLengths->data[root_p - 1] = regionLengths->data[i5 -
                        1];
                      i4 = regionLengths->size[0];
                      if (!((root_p >= 1) && (root_p <= i4))) {
                        emlrtDynamicBoundsCheckR2012b(root_p, 1, i4,
                          &ac_emlrtBCI, &c_st);
                      }

                      root_p = regionLengths->data[root_p - 1];
                    } else {
                      exitg2 = 1;
                    }
                  } while (exitg2 == 0);

                  if (root_k != root_p) {
                    c_st.site = &yc_emlrtRSI;
                    if (root_p < root_k) {
                      i4 = regionLengths->size[0];
                      if (!((root_k >= 1) && (root_k <= i4))) {
                        emlrtDynamicBoundsCheckR2012b(root_k, 1, i4,
                          &vb_emlrtBCI, &c_st);
                      }

                      regionLengths->data[root_k - 1] = root_p;
                      i4 = regionLengths->size[0];
                      if (!((k >= 1) && (k <= i4))) {
                        emlrtDynamicBoundsCheckR2012b(k, 1, i4, &wb_emlrtBCI,
                          &c_st);
                      }

                      regionLengths->data[k - 1] = root_p;
                    } else {
                      i4 = regionLengths->size[0];
                      if (!((root_p >= 1) && (root_p <= i4))) {
                        emlrtDynamicBoundsCheckR2012b(root_p, 1, i4,
                          &tb_emlrtBCI, &c_st);
                      }

                      regionLengths->data[root_p - 1] = root_k;
                      i4 = regionLengths->size[0];
                      if (!((p >= 1) && (p <= i4))) {
                        emlrtDynamicBoundsCheckR2012b(p, 1, i4, &ub_emlrtBCI,
                          &c_st);
                      }

                      regionLengths->data[p - 1] = root_k;
                    }
                  }
                }
              }
            }
          }
        }
      }

      i4 = regionLengths->size[0];
      if (!((k >= 1) && (k <= i4))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i4, &jb_emlrtBCI, &st);
      }

      if (regionLengths->data[k - 1] == 0) {
        i4 = regionLengths->size[0];
        if (!((k >= 1) && (k <= i4))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i4, &kb_emlrtBCI, &st);
        }

        regionLengths->data[k - 1] = row;
        row++;
      }

      k++;
    }
  }

  if (numRuns == 0) {
    for (i4 = 0; i4 < 2; i4++) {
      CC_ImageSize[i4] = varargin_1->size[i4];
    }

    numComponents = 0.0;
    i4 = CC_RegionIndices->size[0];
    CC_RegionIndices->size[0] = 0;
    emxEnsureCapacity_real_T1(sp, CC_RegionIndices, i4, &fc_emlrtRTEI);
    i4 = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = 1;
    emxEnsureCapacity_int32_T(sp, CC_RegionLengths, i4, &hc_emlrtRTEI);
    CC_RegionLengths->data[0] = 0;
  } else {
    emxInit_int32_T(sp, &labelsRenumbered, 1, &nc_emlrtRTEI, true);
    i4 = labelsRenumbered->size[0];
    labelsRenumbered->size[0] = regionLengths->size[0];
    emxEnsureCapacity_int32_T(sp, labelsRenumbered, i4, &ec_emlrtRTEI);
    numComponents = 0.0;
    st.site = &nc_emlrtRSI;
    for (k = 1; k <= numRuns; k++) {
      i4 = regionLengths->size[0];
      if (!(k <= i4)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i4, &kc_emlrtBCI, sp);
      }

      if (regionLengths->data[k - 1] == k) {
        numComponents++;
        i4 = labelsRenumbered->size[0];
        if (!(k <= i4)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i4, &lc_emlrtBCI, sp);
        }

        labelsRenumbered->data[k - 1] = (int32_T)numComponents;
      }

      i4 = labelsRenumbered->size[0];
      i5 = regionLengths->size[0];
      if (!(k <= i5)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i5, &mc_emlrtBCI, sp);
      }

      i5 = regionLengths->data[k - 1];
      if (!((i5 >= 1) && (i5 <= i4))) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &mc_emlrtBCI, sp);
      }

      i4 = labelsRenumbered->size[0];
      if (!(k <= i4)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i4, &nc_emlrtBCI, sp);
      }

      labelsRenumbered->data[k - 1] = labelsRenumbered->data[i5 - 1];
    }

    i4 = regionLengths->size[0];
    if (numComponents != (int32_T)numComponents) {
      emlrtIntegerCheckR2012b(numComponents, &d_emlrtDCI, sp);
    }

    regionLengths->size[0] = (int32_T)numComponents;
    emxEnsureCapacity_int32_T(sp, regionLengths, i4, &ic_emlrtRTEI);
    if (numComponents != (int32_T)numComponents) {
      emlrtIntegerCheckR2012b(numComponents, &d_emlrtDCI, sp);
    }

    row = (int32_T)numComponents;
    for (i4 = 0; i4 < row; i4++) {
      regionLengths->data[i4] = 0;
    }

    st.site = &oc_emlrtRSI;
    for (k = 1; k <= numRuns; k++) {
      i4 = labelsRenumbered->size[0];
      if (!(k <= i4)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i4, &u_emlrtBCI, sp);
      }

      if (labelsRenumbered->data[k - 1] > 0) {
        i4 = regionLengths->size[0];
        i5 = labelsRenumbered->data[k - 1];
        if (!((i5 >= 1) && (i5 <= i4))) {
          emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gc_emlrtBCI, sp);
        }

        i4 = endRow->size[0];
        if (!(k <= i4)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i4, &hc_emlrtBCI, sp);
        }

        i4 = startRow->size[0];
        if (!(k <= i4)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i4, &ic_emlrtBCI, sp);
        }

        i4 = regionLengths->size[0];
        row = labelsRenumbered->data[k - 1];
        if (!((row >= 1) && (row <= i4))) {
          emlrtDynamicBoundsCheckR2012b(row, 1, i4, &jc_emlrtBCI, sp);
        }

        regionLengths->data[row - 1] = ((regionLengths->data[i5 - 1] +
          endRow->data[k - 1]) - startRow->data[k - 1]) + 1;
      }
    }

    st.site = &pc_emlrtRSI;
    b_st.site = &ad_emlrtRSI;
    c_st.site = &bd_emlrtRSI;
    if (regionLengths->size[0] == 0) {
      y = 0.0;
    } else {
      d_st.site = &cd_emlrtRSI;
      y = regionLengths->data[0];
      e_st.site = &dd_emlrtRSI;
      overflow = ((!(2 > regionLengths->size[0])) && (regionLengths->size[0] >
        2147483646));
      if (overflow) {
        f_st.site = &h_emlrtRSI;
        g_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      for (k = 2; k <= regionLengths->size[0]; k++) {
        y += (real_T)regionLengths->data[k - 1];
      }
    }

    emxInit_real_T1(&c_st, &pixelIdxList, 1, &oc_emlrtRTEI, true);
    emxInit_int32_T(&c_st, &x, 1, &jc_emlrtRTEI, true);
    if (!(y >= 0.0)) {
      emlrtNonNegativeCheckR2012b(y, &b_emlrtDCI, sp);
    }

    if (y != (int32_T)y) {
      emlrtIntegerCheckR2012b(y, &emlrtDCI, sp);
    }

    i4 = pixelIdxList->size[0];
    pixelIdxList->size[0] = (int32_T)y;
    emxEnsureCapacity_real_T1(sp, pixelIdxList, i4, &ec_emlrtRTEI);
    st.site = &qc_emlrtRSI;
    i4 = x->size[0];
    x->size[0] = regionLengths->size[0];
    emxEnsureCapacity_int32_T(&st, x, i4, &jc_emlrtRTEI);
    row = regionLengths->size[0];
    for (i4 = 0; i4 < row; i4++) {
      x->data[i4] = regionLengths->data[i4];
    }

    b_st.site = &ed_emlrtRSI;
    row = 2;
    if (regionLengths->size[0] != 1) {
      row = 1;
    }

    c_st.site = &fd_emlrtRSI;
    if (row <= 1) {
      i4 = regionLengths->size[0];
    } else {
      i4 = 1;
    }

    if ((!(regionLengths->size[0] == 0)) && (i4 > 1)) {
      d_st.site = &gd_emlrtRSI;
      runCounter = 1;
      e_st.site = &jd_emlrtRSI;
      k = 1;
      while (k <= row - 1) {
        runCounter *= regionLengths->size[0];
        k = 2;
      }

      d_st.site = &hd_emlrtRSI;
      overflow = ((!(1 > runCounter)) && (runCounter > 2147483646));
      if (overflow) {
        e_st.site = &h_emlrtRSI;
        f_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (row = 0; row + 1 <= runCounter; row++) {
        d_st.site = &id_emlrtRSI;
        for (k = 1; k < i4; k++) {
          x->data[row + k * runCounter] += x->data[row + (k - 1) * runCounter];
        }
      }
    }

    emxInit_int32_T(&c_st, &idxCount, 1, &kc_emlrtRTEI, true);
    i4 = idxCount->size[0];
    idxCount->size[0] = 1 + x->size[0];
    emxEnsureCapacity_int32_T(sp, idxCount, i4, &kc_emlrtRTEI);
    idxCount->data[0] = 0;
    row = x->size[0];
    for (i4 = 0; i4 < row; i4++) {
      idxCount->data[i4 + 1] = x->data[i4];
    }

    emxFree_int32_T(&x);
    st.site = &rc_emlrtRSI;
    for (k = 1; k <= numRuns; k++) {
      i4 = startCol->size[0];
      if (!(k <= i4)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i4, &t_emlrtBCI, sp);
      }

      row = (startCol->data[k - 1] - 1) * varargin_1->size[0];
      i4 = labelsRenumbered->size[0];
      if (!(k <= i4)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i4, &dc_emlrtBCI, sp);
      }

      runCounter = labelsRenumbered->data[k - 1];
      if (labelsRenumbered->data[k - 1] > 0) {
        i4 = startRow->size[0];
        if (!(k <= i4)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i4, &s_emlrtBCI, sp);
        }

        i4 = endRow->size[0];
        if (!(k <= i4)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i4, &r_emlrtBCI, sp);
        }

        st.site = &sc_emlrtRSI;
        for (firstRunOnPreviousColumn = startRow->data[k - 1];
             firstRunOnPreviousColumn <= endRow->data[k - 1];
             firstRunOnPreviousColumn++) {
          i4 = idxCount->size[0];
          if (!((runCounter >= 1) && (runCounter <= i4))) {
            emlrtDynamicBoundsCheckR2012b(runCounter, 1, i4, &q_emlrtBCI, sp);
          }

          i4 = idxCount->size[0];
          if (!((runCounter >= 1) && (runCounter <= i4))) {
            emlrtDynamicBoundsCheckR2012b(runCounter, 1, i4, &ec_emlrtBCI, sp);
          }

          idxCount->data[runCounter - 1]++;
          i4 = pixelIdxList->size[0];
          i5 = idxCount->size[0];
          if (!((runCounter >= 1) && (runCounter <= i5))) {
            emlrtDynamicBoundsCheckR2012b(runCounter, 1, i5, &fc_emlrtBCI, sp);
          }

          i5 = idxCount->data[runCounter - 1];
          if (!((i5 >= 1) && (i5 <= i4))) {
            emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fc_emlrtBCI, sp);
          }

          pixelIdxList->data[i5 - 1] = firstRunOnPreviousColumn + row;
        }
      }
    }

    emxFree_int32_T(&idxCount);
    emxFree_int32_T(&labelsRenumbered);
    for (i4 = 0; i4 < 2; i4++) {
      CC_ImageSize[i4] = varargin_1->size[i4];
    }

    i4 = CC_RegionIndices->size[0];
    CC_RegionIndices->size[0] = pixelIdxList->size[0];
    emxEnsureCapacity_real_T1(sp, CC_RegionIndices, i4, &lc_emlrtRTEI);
    row = pixelIdxList->size[0];
    for (i4 = 0; i4 < row; i4++) {
      CC_RegionIndices->data[i4] = pixelIdxList->data[i4];
    }

    emxFree_real_T(&pixelIdxList);
    i4 = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = regionLengths->size[0];
    emxEnsureCapacity_int32_T(sp, CC_RegionLengths, i4, &mc_emlrtRTEI);
    row = regionLengths->size[0];
    for (i4 = 0; i4 < row; i4++) {
      CC_RegionLengths->data[i4] = regionLengths->data[i4];
    }
  }

  emxFree_int32_T(&startCol);
  emxFree_int32_T(&endRow);
  emxFree_int32_T(&startRow);
  emxFree_int32_T(&regionLengths);
  *CC_Connectivity = 8.0;
  *CC_NumObjects = numComponents;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (bwconncomp.c) */
