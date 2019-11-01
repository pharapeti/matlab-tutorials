/*
 * ybp_finder_CLS.c
 *
 * Code generation for function 'ybp_finder_CLS'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "ybp_finder_CLS.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sort1.h"
#include "regionprops.h"
#include "linearizeSRGB.h"
#include "XYZToLAB.h"
#include "error.h"
#include "scalexpAlloc.h"
#include "power.h"
#include "indexShapeCheck.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRSInfo c_emlrtRSI = { 89,  /* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 85,  /* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 79,  /* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 80,  /* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 73,  /* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 80,  /* lineNo */
  "rgb2lab",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\colorspaces\\eml\\rgb2lab.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 243, /* lineNo */
  "rgb2lab",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\colorspaces\\eml\\rgb2lab.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 266, /* lineNo */
  "rgb2lab",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\colorspaces\\eml\\rgb2lab.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 20,  /* lineNo */
  "linearizeSRGB",                     /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\colorspaces\\+images\\+color\\+internal\\+coder\\linearizeSRGB.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 21,  /* lineNo */
  "linearizeSRGB",                     /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\colorspaces\\+images\\+color\\+internal\\+coder\\linearizeSRGB.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 22,  /* lineNo */
  "linearizeSRGB",                     /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\colorspaces\\+images\\+color\\+internal\\+coder\\linearizeSRGB.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 61,  /* lineNo */
  "power",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 36,  /* lineNo */
  "XYZToLAB",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\colorspaces\\+images\\+color\\+internal\\+coder\\XYZToLAB.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 37,  /* lineNo */
  "XYZToLAB",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\colorspaces\\+images\\+color\\+internal\\+coder\\XYZToLAB.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 38,  /* lineNo */
  "XYZToLAB",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\colorspaces\\+images\\+color\\+internal\\+coder\\XYZToLAB.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 60, /* lineNo */
  "power",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 190,/* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 118,/* lineNo */
  "power",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 80, /* lineNo */
  "power",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 36, /* lineNo */
  "vAllOrAny",                         /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 96, /* lineNo */
  "vAllOrAny",                         /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\vAllOrAny.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 210,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 213,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 214,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 376,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 348,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 228,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 242,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 264,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo nf_emlrtRSI = { 234,/* lineNo */
  "find",                              /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRTEInfo s_emlrtRTEI = { 56,/* lineNo */
  16,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 224,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 238,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 243,/* lineNo */
  15,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 243,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 245,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 246,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 247,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 264,/* lineNo */
  18,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 265,/* lineNo */
  18,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 266,/* lineNo */
  20,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 266,/* lineNo */
  29,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 266,/* lineNo */
  40,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 266,/* lineNo */
  50,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 266,/* lineNo */
  19,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 44,/* lineNo */
  10,                                  /* colNo */
  "find",                              /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 264,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 270,/* lineNo */
  23,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 272,/* lineNo */
  15,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 228,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 222,/* lineNo */
  34,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = { 73,/* lineNo */
  30,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = { 73,/* lineNo */
  21,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = { 74,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo be_emlrtRTEI = { 75,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = { 76,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo de_emlrtRTEI = { 79,/* lineNo */
  32,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = { 132,/* lineNo */
  1,                                   /* colNo */
  "minOrMax",                          /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = { 80,/* lineNo */
  32,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "minOrMax",                          /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

static emlrtRTEInfo he_emlrtRTEI = { 79,/* lineNo */
  31,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = { 99,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo je_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  271,                                 /* lineNo */
  29,                                  /* colNo */
  "stats",                             /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  264,                                 /* lineNo */
  18,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { 2,   /* nDims */
  266,                                 /* lineNo */
  19,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { 2,   /* nDims */
  266,                                 /* lineNo */
  40,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { 2,   /* nDims */
  266,                                 /* lineNo */
  20,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  272,                                 /* lineNo */
  15,                                  /* colNo */
  "new_BW",                            /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  249,                                 /* lineNo */
  17,                                  /* colNo */
  "stats",                             /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  249,                                 /* lineNo */
  9,                                   /* colNo */
  "A",                                 /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  250,                                 /* lineNo */
  17,                                  /* colNo */
  "stats",                             /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  250,                                 /* lineNo */
  9,                                   /* colNo */
  "E",                                 /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  251,                                 /* lineNo */
  17,                                  /* colNo */
  "stats",                             /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  251,                                 /* lineNo */
  9,                                   /* colNo */
  "O",                                 /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  21,                                  /* colNo */
  "stats",                             /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  240,                                 /* lineNo */
  9,                                   /* colNo */
  "tmp_E",                             /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  243,                                 /* lineNo */
  5,                                   /* colNo */
  "stats",                             /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo yf_emlrtRTEI = { 19,/* lineNo */
  19,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = { 78,/* lineNo */
  17,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtECInfo e_emlrtECI = { 2,   /* nDims */
  79,                                  /* lineNo */
  31,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  20,                                  /* colNo */
  "distance",                          /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  79,                                  /* lineNo */
  7,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtDCInfo e_emlrtDCI = { 76,  /* lineNo */
  27,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 76,  /* lineNo */
  27,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { 1,  /* iFirst */
  5,                                   /* iLast */
  89,                                  /* lineNo */
  31,                                  /* colNo */
  "color_labels",                      /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { 1,  /* iFirst */
  5,                                   /* iLast */
  79,                                  /* lineNo */
  36,                                  /* colNo */
  "color_markers",                     /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void LOC_find_thin_lane_marking(const emlrtStack *sp, const emxArray_boolean_T
  *BW, emxArray_boolean_T *new_BW, boolean_T *tf_found_it)
{
  int32_T i2;
  int16_T iv1[2];
  int32_T nx;
  b_emxArray_struct_T *stats;
  boolean_T b_tf_found_it;
  emxArray_real_T *tmp_E;
  int32_T kk;
  emxArray_int32_T *ii;
  b_emxArray_struct_T *b_stats;
  int32_T idx;
  emxArray_real_T *E;
  emxArray_real_T *O;
  emxArray_boolean_T *x;
  real_T A_min;
  emxArray_boolean_T *r1;
  int32_T b_x[2];
  emxArray_boolean_T *r2;
  int32_T iv2[2];
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r4;
  emxArray_boolean_T *r5;
  boolean_T overflow;
  boolean_T exitg1;
  emxArray_int32_T *r6;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  for (i2 = 0; i2 < 2; i2++) {
    iv1[i2] = (int16_T)BW->size[i2];
  }

  i2 = new_BW->size[0] * new_BW->size[1];
  new_BW->size[0] = iv1[0];
  new_BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(sp, new_BW, i2, &v_emlrtRTEI);
  nx = iv1[0] * 320;
  for (i2 = 0; i2 < nx; i2++) {
    new_BW->data[i2] = false;
  }

  emxInit_struct_T1(sp, &stats, 1, &pb_emlrtRTEI, true);
  b_tf_found_it = false;
  st.site = &ac_emlrtRSI;
  regionprops(&st, BW, stats);
  if (stats->size[0] != 0) {
    emxInit_real_T(sp, &tmp_E, 2, &w_emlrtRTEI, true);
    i2 = tmp_E->size[0] * tmp_E->size[1];
    tmp_E->size[0] = 1;
    tmp_E->size[1] = stats->size[0];
    emxEnsureCapacity_real_T(sp, tmp_E, i2, &w_emlrtRTEI);
    nx = stats->size[0];
    for (i2 = 0; i2 < nx; i2++) {
      tmp_E->data[i2] = 0.0;
    }

    kk = 1;
    while (kk - 1 <= stats->size[0] - 1) {
      i2 = stats->size[0];
      if (!((kk >= 1) && (kk <= i2))) {
        emlrtDynamicBoundsCheckR2012b(kk, 1, i2, &n_emlrtBCI, sp);
      }

      i2 = tmp_E->size[1];
      if (!((kk >= 1) && (kk <= i2))) {
        emlrtDynamicBoundsCheckR2012b(kk, 1, i2, &o_emlrtBCI, sp);
      }

      tmp_E->data[kk - 1] = stats->data[kk - 1].Eccentricity;
      kk++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxInit_int32_T1(sp, &ii, 2, &rb_emlrtRTEI, true);
    emxInit_struct_T1(sp, &b_stats, 1, &x_emlrtRTEI, true);
    st.site = &bc_emlrtRSI;
    b_st.site = &ne_emlrtRSI;
    sort(&b_st, tmp_E, ii);
    kk = stats->size[0];
    i2 = b_stats->size[0];
    b_stats->size[0] = ii->size[1];
    emxEnsureCapacity_struct_T1(sp, b_stats, i2, &x_emlrtRTEI);
    nx = ii->size[1];
    for (i2 = 0; i2 < nx; i2++) {
      idx = ii->data[ii->size[0] * i2];
      if (!((idx >= 1) && (idx <= kk))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, kk, &p_emlrtBCI, sp);
      }

      emxCopyStruct_struct_T1(sp, &b_stats->data[i2], &stats->data[idx - 1],
        &x_emlrtRTEI);
    }

    i2 = stats->size[0];
    stats->size[0] = b_stats->size[0];
    emxEnsureCapacity_struct_T1(sp, stats, i2, &y_emlrtRTEI);
    nx = b_stats->size[0];
    for (i2 = 0; i2 < nx; i2++) {
      emxCopyStruct_struct_T1(sp, &stats->data[i2], &b_stats->data[i2],
        &y_emlrtRTEI);
    }

    emxFree_struct_T1(&b_stats);
    i2 = tmp_E->size[0] * tmp_E->size[1];
    tmp_E->size[0] = 1;
    tmp_E->size[1] = stats->size[0];
    emxEnsureCapacity_real_T(sp, tmp_E, i2, &ab_emlrtRTEI);
    nx = stats->size[0];
    for (i2 = 0; i2 < nx; i2++) {
      tmp_E->data[i2] = 0.0;
    }

    emxInit_real_T(sp, &E, 2, &bb_emlrtRTEI, true);
    i2 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = stats->size[0];
    emxEnsureCapacity_real_T(sp, E, i2, &bb_emlrtRTEI);
    nx = stats->size[0];
    for (i2 = 0; i2 < nx; i2++) {
      E->data[i2] = 0.0;
    }

    emxInit_real_T(sp, &O, 2, &cb_emlrtRTEI, true);
    i2 = O->size[0] * O->size[1];
    O->size[0] = 1;
    O->size[1] = stats->size[0];
    emxEnsureCapacity_real_T(sp, O, i2, &cb_emlrtRTEI);
    nx = stats->size[0];
    for (i2 = 0; i2 < nx; i2++) {
      O->data[i2] = 0.0;
    }

    kk = 1;
    while (kk - 1 <= stats->size[0] - 1) {
      i2 = stats->size[0];
      if (!((kk >= 1) && (kk <= i2))) {
        emlrtDynamicBoundsCheckR2012b(kk, 1, i2, &h_emlrtBCI, sp);
      }

      i2 = tmp_E->size[1];
      if (!((kk >= 1) && (kk <= i2))) {
        emlrtDynamicBoundsCheckR2012b(kk, 1, i2, &i_emlrtBCI, sp);
      }

      tmp_E->data[kk - 1] = stats->data[kk - 1].Area;
      i2 = stats->size[0];
      if (!((kk >= 1) && (kk <= i2))) {
        emlrtDynamicBoundsCheckR2012b(kk, 1, i2, &j_emlrtBCI, sp);
      }

      i2 = E->size[1];
      if (!((kk >= 1) && (kk <= i2))) {
        emlrtDynamicBoundsCheckR2012b(kk, 1, i2, &k_emlrtBCI, sp);
      }

      E->data[kk - 1] = stats->data[kk - 1].Eccentricity;
      i2 = stats->size[0];
      if (!((kk >= 1) && (kk <= i2))) {
        emlrtDynamicBoundsCheckR2012b(kk, 1, i2, &l_emlrtBCI, sp);
      }

      i2 = O->size[1];
      if (!((kk >= 1) && (kk <= i2))) {
        emlrtDynamicBoundsCheckR2012b(kk, 1, i2, &m_emlrtBCI, sp);
      }

      O->data[kk - 1] = stats->data[kk - 1].Orientation;
      kk++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxInit_boolean_T(sp, &x, 2, &db_emlrtRTEI, true);
    A_min = 100.0 * (real_T)BW->size[0] / 480.0;
    i2 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = E->size[1];
    emxEnsureCapacity_boolean_T(sp, x, i2, &db_emlrtRTEI);
    nx = E->size[0] * E->size[1];
    for (i2 = 0; i2 < nx; i2++) {
      x->data[i2] = (E->data[i2] > 0.8);
    }

    emxFree_real_T(&E);
    emxInit_boolean_T(sp, &r1, 2, &qb_emlrtRTEI, true);
    i2 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = tmp_E->size[1];
    emxEnsureCapacity_boolean_T(sp, r1, i2, &eb_emlrtRTEI);
    nx = tmp_E->size[0] * tmp_E->size[1];
    for (i2 = 0; i2 < nx; i2++) {
      r1->data[i2] = (tmp_E->data[i2] > A_min);
    }

    for (i2 = 0; i2 < 2; i2++) {
      b_x[i2] = x->size[i2];
    }

    for (i2 = 0; i2 < 2; i2++) {
      iv2[i2] = r1->size[i2];
    }

    emxInit_boolean_T(sp, &r2, 2, &qb_emlrtRTEI, true);
    if ((b_x[0] != iv2[0]) || (b_x[1] != iv2[1])) {
      emlrtSizeEqCheckNDR2012b(&b_x[0], &iv2[0], &emlrtECI, sp);
    }

    i2 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = O->size[1];
    emxEnsureCapacity_boolean_T(sp, r2, i2, &fb_emlrtRTEI);
    nx = O->size[0] * O->size[1];
    for (i2 = 0; i2 < nx; i2++) {
      r2->data[i2] = (O->data[i2] > 10.0);
    }

    emxInit_boolean_T(sp, &r3, 2, &qb_emlrtRTEI, true);
    i2 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = O->size[1];
    emxEnsureCapacity_boolean_T(sp, r3, i2, &gb_emlrtRTEI);
    nx = O->size[0] * O->size[1];
    for (i2 = 0; i2 < nx; i2++) {
      r3->data[i2] = (O->data[i2] < 80.0);
    }

    for (i2 = 0; i2 < 2; i2++) {
      iv2[i2] = r2->size[i2];
    }

    for (i2 = 0; i2 < 2; i2++) {
      b_x[i2] = r3->size[i2];
    }

    emxInit_boolean_T(sp, &r4, 2, &qb_emlrtRTEI, true);
    if ((iv2[0] != b_x[0]) || (iv2[1] != b_x[1])) {
      emlrtSizeEqCheckNDR2012b(&iv2[0], &b_x[0], &d_emlrtECI, sp);
    }

    i2 = r4->size[0] * r4->size[1];
    r4->size[0] = 1;
    r4->size[1] = O->size[1];
    emxEnsureCapacity_boolean_T(sp, r4, i2, &hb_emlrtRTEI);
    nx = O->size[0] * O->size[1];
    for (i2 = 0; i2 < nx; i2++) {
      r4->data[i2] = (O->data[i2] < -10.0);
    }

    emxInit_boolean_T(sp, &r5, 2, &qb_emlrtRTEI, true);
    i2 = r5->size[0] * r5->size[1];
    r5->size[0] = 1;
    r5->size[1] = O->size[1];
    emxEnsureCapacity_boolean_T(sp, r5, i2, &ib_emlrtRTEI);
    nx = O->size[0] * O->size[1];
    for (i2 = 0; i2 < nx; i2++) {
      r5->data[i2] = (O->data[i2] > -80.0);
    }

    emxFree_real_T(&O);
    for (i2 = 0; i2 < 2; i2++) {
      iv2[i2] = r4->size[i2];
    }

    for (i2 = 0; i2 < 2; i2++) {
      b_x[i2] = r5->size[i2];
    }

    if ((iv2[0] != b_x[0]) || (iv2[1] != b_x[1])) {
      emlrtSizeEqCheckNDR2012b(&iv2[0], &b_x[0], &c_emlrtECI, sp);
    }

    i2 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    emxEnsureCapacity_boolean_T(sp, r2, i2, &fb_emlrtRTEI);
    i2 = r2->size[0];
    idx = r2->size[1];
    nx = i2 * idx;
    for (i2 = 0; i2 < nx; i2++) {
      r2->data[i2] = (r2->data[i2] && r3->data[i2]);
    }

    emxFree_boolean_T(&r3);
    i2 = r4->size[0] * r4->size[1];
    r4->size[0] = 1;
    emxEnsureCapacity_boolean_T(sp, r4, i2, &hb_emlrtRTEI);
    i2 = r4->size[0];
    idx = r4->size[1];
    nx = i2 * idx;
    for (i2 = 0; i2 < nx; i2++) {
      r4->data[i2] = (r4->data[i2] && r5->data[i2]);
    }

    emxFree_boolean_T(&r5);
    for (i2 = 0; i2 < 2; i2++) {
      iv2[i2] = r2->size[i2];
    }

    for (i2 = 0; i2 < 2; i2++) {
      b_x[i2] = r4->size[i2];
    }

    if ((iv2[0] != b_x[0]) || (iv2[1] != b_x[1])) {
      emlrtSizeEqCheckNDR2012b(&iv2[0], &b_x[0], &b_emlrtECI, sp);
    }

    i2 = x->size[0] * x->size[1];
    x->size[0] = 1;
    emxEnsureCapacity_boolean_T(sp, x, i2, &db_emlrtRTEI);
    kk = x->size[0];
    nx = x->size[1];
    nx *= kk;
    for (i2 = 0; i2 < nx; i2++) {
      x->data[i2] = (x->data[i2] && r1->data[i2]);
    }

    emxFree_boolean_T(&r1);
    i2 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    emxEnsureCapacity_boolean_T(sp, r2, i2, &jb_emlrtRTEI);
    i2 = r2->size[0];
    idx = r2->size[1];
    nx = i2 * idx;
    for (i2 = 0; i2 < nx; i2++) {
      r2->data[i2] = (r2->data[i2] || r4->data[i2]);
    }

    emxFree_boolean_T(&r4);
    for (i2 = 0; i2 < 2; i2++) {
      b_x[i2] = x->size[i2];
    }

    for (i2 = 0; i2 < 2; i2++) {
      iv2[i2] = r2->size[i2];
    }

    if ((b_x[0] != iv2[0]) || (b_x[1] != iv2[1])) {
      emlrtSizeEqCheckNDR2012b(&b_x[0], &iv2[0], &emlrtECI, sp);
    }

    st.site = &cc_emlrtRSI;
    i2 = x->size[0] * x->size[1];
    x->size[0] = 1;
    emxEnsureCapacity_boolean_T(&st, x, i2, &db_emlrtRTEI);
    kk = x->size[0];
    nx = x->size[1];
    nx *= kk;
    for (i2 = 0; i2 < nx; i2++) {
      x->data[i2] = (x->data[i2] && r2->data[i2]);
    }

    emxFree_boolean_T(&r2);
    b_st.site = &mf_emlrtRSI;
    nx = x->size[1];
    idx = 0;
    i2 = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = x->size[1];
    emxEnsureCapacity_int32_T1(&b_st, ii, i2, &kb_emlrtRTEI);
    c_st.site = &nf_emlrtRSI;
    overflow = ((!(1 > x->size[1])) && (x->size[1] > 2147483646));
    if (overflow) {
      d_st.site = &h_emlrtRSI;
      e_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    kk = 1;
    exitg1 = false;
    while ((!exitg1) && (kk <= nx)) {
      if (x->data[kk - 1]) {
        idx++;
        ii->data[idx - 1] = kk;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          kk++;
        }
      } else {
        kk++;
      }
    }

    if (!(idx <= x->size[1])) {
      emlrtErrorWithMessageIdR2012b(&b_st, &pf_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (x->size[1] == 1) {
      if (idx == 0) {
        i2 = ii->size[0] * ii->size[1];
        ii->size[0] = 1;
        ii->size[1] = 0;
        emxEnsureCapacity_int32_T1(&b_st, ii, i2, &lb_emlrtRTEI);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }

      i2 = ii->size[0] * ii->size[1];
      ii->size[1] = idx;
      emxEnsureCapacity_int32_T1(&b_st, ii, i2, &lb_emlrtRTEI);
    }

    emxFree_boolean_T(&x);
    i2 = tmp_E->size[0] * tmp_E->size[1];
    tmp_E->size[0] = 1;
    tmp_E->size[1] = ii->size[1];
    emxEnsureCapacity_real_T(&st, tmp_E, i2, &mb_emlrtRTEI);
    nx = ii->size[0] * ii->size[1];
    for (i2 = 0; i2 < nx; i2++) {
      tmp_E->data[i2] = ii->data[i2];
    }

    if (!(tmp_E->size[1] == 0)) {
      i2 = stats->size[0];
      idx = (int32_T)tmp_E->data[0];
      if (!((idx >= 1) && (idx <= i2))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i2, &f_emlrtBCI, sp);
      }

      i2 = ii->size[0] * ii->size[1];
      ii->size[0] = 1;
      ii->size[1] = tmp_E->size[1];
      emxEnsureCapacity_int32_T1(sp, ii, i2, &nb_emlrtRTEI);
      nx = tmp_E->size[1];
      for (i2 = 0; i2 < nx; i2++) {
        ii->data[ii->size[0] * i2] = (int32_T)tmp_E->data[tmp_E->size[0] * i2];
      }

      emxInit_int32_T(sp, &r6, 1, &qb_emlrtRTEI, true);
      i2 = iv1[0] * 320;
      idx = r6->size[0];
      r6->size[0] = stats->data[ii->data[0] - 1].PixelIdxList->size[0];
      emxEnsureCapacity_int32_T(sp, r6, idx, &ob_emlrtRTEI);
      nx = stats->data[ii->data[0] - 1].PixelIdxList->size[0];
      for (idx = 0; idx < nx; idx++) {
        kk = (int32_T)stats->data[ii->data[0] - 1].PixelIdxList->data[idx];
        if (!((kk >= 1) && (kk <= i2))) {
          emlrtDynamicBoundsCheckR2012b(kk, 1, i2, &g_emlrtBCI, sp);
        }

        r6->data[idx] = kk;
      }

      nx = r6->size[0];
      for (i2 = 0; i2 < nx; i2++) {
        new_BW->data[r6->data[i2] - 1] = true;
      }

      emxFree_int32_T(&r6);
      b_tf_found_it = true;
    }

    emxFree_int32_T(&ii);
    emxFree_real_T(&tmp_E);
  }

  emxFree_struct_T1(&stats);
  *tf_found_it = b_tf_found_it;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void ybp_finder_CLS_classify(const emlrtStack *sp, ybp_finder_CLS *OBJ, const
  uint8_T DRC_image[230400])
{
  emxArray_uint8_T *rgb;
  boolean_T overflow;
  int32_T ixstart;
  emxArray_real_T *lab_DRC_image;
  int32_T ixstop;
  int32_T nx;
  int32_T k;
  emxArray_real_T *a;
  real_T fz;
  real_T linearG;
  real_T linearB;
  emxArray_real_T *b;
  real_T fx;
  real_T fy;
  emxArray_real_T *distance;
  int32_T cindx;
  emxArray_real_T *indx;
  emxArray_real_T *b_a;
  emxArray_real_T *b_b;
  uint8_T tmp_data[145];
  emxArray_int32_T *iindx;
  int32_T n;
  int32_T vstride;
  int32_T c_a[2];
  int32_T b_indx[2];
  int32_T d_a;
  boolean_T exitg1;
  int16_T a_idx_0;
  boolean_T p;
  int32_T iv15[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_uint8_T(sp, &rgb, 3, &xd_emlrtRTEI, true);
  overflow = false;
  st.site = &g_emlrtRSI;
  ixstart = rgb->size[0] * rgb->size[1] * rgb->size[2];
  rgb->size[0] = 145;
  rgb->size[1] = 320;
  rgb->size[2] = 3;
  emxEnsureCapacity_uint8_T(&st, rgb, ixstart, &xd_emlrtRTEI);
  for (ixstart = 0; ixstart < 3; ixstart++) {
    for (ixstop = 0; ixstop < 320; ixstop++) {
      for (nx = 0; nx < 145; nx++) {
        rgb->data[(nx + rgb->size[0] * ixstop) + rgb->size[0] * rgb->size[1] *
          ixstart] = DRC_image[((nx + 240 * ixstop) + 76800 * ixstart) + 95];
      }
    }
  }

  emxInit_real_T2(&st, &lab_DRC_image, 3, &je_emlrtRTEI, true);
  ixstart = lab_DRC_image->size[0] * lab_DRC_image->size[1] *
    lab_DRC_image->size[2];
  lab_DRC_image->size[0] = 145;
  lab_DRC_image->size[1] = 320;
  lab_DRC_image->size[2] = 3;
  emxEnsureCapacity_real_T2(&st, lab_DRC_image, ixstart, &yd_emlrtRTEI);
  for (nx = 0; nx < 320; nx++) {
    for (k = 0; k < 145; k++) {
      b_st.site = &i_emlrtRSI;
      c_st.site = &j_emlrtRSI;
      d_st.site = &l_emlrtRSI;
      fz = parametricCurveA((real_T)rgb->data[k + 145 * nx] / 255.0);
      d_st.site = &m_emlrtRSI;
      linearG = parametricCurveA((real_T)rgb->data[(k + 145 * nx) + 46400] /
        255.0);
      d_st.site = &n_emlrtRSI;
      linearB = parametricCurveA((real_T)rgb->data[(k + 145 * nx) + 92800] /
        255.0);
      c_st.site = &k_emlrtRSI;
      d_st.site = &r_emlrtRSI;
      fx = f(((0.41245643908969215 * fz + 0.35757607764390892 * linearG) +
              0.18043748326639891 * linearB) / 0.95047);
      d_st.site = &s_emlrtRSI;
      fy = f((0.2126728514056225 * fz + 0.71515215528781784 * linearG) +
             0.072174993306559562 * linearB);
      d_st.site = &t_emlrtRSI;
      fz = f(((0.0193338955823293 * fz + 0.11919202588130294 * linearG) +
              0.95030407853636767 * linearB) / 1.08883);
      lab_DRC_image->data[k + 145 * nx] = 116.0 * fy - 16.0;
      lab_DRC_image->data[(k + 145 * nx) + 46400] = 500.0 * (fx - fy);
      lab_DRC_image->data[(k + 145 * nx) + 92800] = 200.0 * (fy - fz);
    }
  }

  emxFree_uint8_T(&rgb);
  emxInit_real_T(&st, &a, 2, &ae_emlrtRTEI, true);
  ixstart = a->size[0] * a->size[1];
  a->size[0] = 145;
  a->size[1] = 320;
  emxEnsureCapacity_real_T(sp, a, ixstart, &ae_emlrtRTEI);
  for (ixstart = 0; ixstart < 320; ixstart++) {
    for (ixstop = 0; ixstop < 145; ixstop++) {
      a->data[ixstop + a->size[0] * ixstart] = lab_DRC_image->data[(ixstop +
        lab_DRC_image->size[0] * ixstart) + lab_DRC_image->size[0] *
        lab_DRC_image->size[1]];
    }
  }

  emxInit_real_T(sp, &b, 2, &be_emlrtRTEI, true);
  ixstart = b->size[0] * b->size[1];
  b->size[0] = 145;
  b->size[1] = 320;
  emxEnsureCapacity_real_T(sp, b, ixstart, &be_emlrtRTEI);
  for (ixstart = 0; ixstart < 320; ixstart++) {
    for (ixstop = 0; ixstop < 145; ixstop++) {
      b->data[ixstop + b->size[0] * ixstart] = lab_DRC_image->data[(ixstop +
        lab_DRC_image->size[0] * ixstart) + ((lab_DRC_image->size[0] *
        lab_DRC_image->size[1]) << 1)];
    }
  }

  emxFree_real_T(&lab_DRC_image);
  emxInit_real_T2(sp, &distance, 3, &ce_emlrtRTEI, true);
  fz = OBJ->nColors;
  if (!(fz >= 0.0)) {
    emlrtNonNegativeCheckR2012b(fz, &e_emlrtDCI, sp);
  }

  if (fz != (int32_T)muDoubleScalarFloor(fz)) {
    emlrtIntegerCheckR2012b(fz, &f_emlrtDCI, sp);
  }

  ixstart = distance->size[0] * distance->size[1] * distance->size[2];
  distance->size[0] = 145;
  distance->size[1] = 320;
  distance->size[2] = (int32_T)fz;
  emxEnsureCapacity_real_T2(sp, distance, ixstart, &ce_emlrtRTEI);
  k = 46400 * (int32_T)fz;
  for (ixstart = 0; ixstart < k; ixstart++) {
    distance->data[ixstart] = 0.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, OBJ->nColors, mxDOUBLE_CLASS, (int32_T)
    OBJ->nColors, &bg_emlrtRTEI, sp);
  cindx = 0;
  emxInit_real_T(sp, &indx, 2, &t_emlrtRTEI, true);
  emxInit_real_T(sp, &b_a, 2, &he_emlrtRTEI, true);
  emxInit_real_T(sp, &b_b, 2, &fe_emlrtRTEI, true);
  if (0 <= (int32_T)OBJ->nColors - 1) {
    for (ixstart = 0; ixstart < 145; ixstart++) {
      tmp_data[ixstart] = (uint8_T)ixstart;
    }
  }

  while (cindx <= (int32_T)OBJ->nColors - 1) {
    ixstart = indx->size[0] * indx->size[1];
    indx->size[0] = a->size[0];
    indx->size[1] = 320;
    emxEnsureCapacity_real_T(sp, indx, ixstart, &de_emlrtRTEI);
    if (!((cindx + 1 >= 1) && (cindx + 1 <= 5))) {
      emlrtDynamicBoundsCheckR2012b(cindx + 1, 1, 5, &cd_emlrtBCI, sp);
    }

    fz = OBJ->color_markers[cindx];
    k = a->size[0] * a->size[1];
    for (ixstart = 0; ixstart < k; ixstart++) {
      indx->data[ixstart] = a->data[ixstart] - fz;
    }

    st.site = &e_emlrtRSI;
    power(&st, indx, b_a);
    ixstart = b_b->size[0] * b_b->size[1];
    b_b->size[0] = b->size[0];
    b_b->size[1] = 320;
    emxEnsureCapacity_real_T(sp, b_b, ixstart, &fe_emlrtRTEI);
    fz = OBJ->color_markers[5 + cindx];
    k = b->size[0] * b->size[1];
    for (ixstart = 0; ixstart < k; ixstart++) {
      b_b->data[ixstart] = b->data[ixstart] - fz;
    }

    st.site = &f_emlrtRSI;
    power(&st, b_b, indx);
    for (ixstart = 0; ixstart < 2; ixstart++) {
      c_a[ixstart] = b_a->size[ixstart];
    }

    for (ixstart = 0; ixstart < 2; ixstart++) {
      b_indx[ixstart] = indx->size[ixstart];
    }

    if ((c_a[0] != b_indx[0]) || (c_a[1] != b_indx[1])) {
      emlrtSizeEqCheckNDR2012b(&c_a[0], &b_indx[0], &e_emlrtECI, sp);
    }

    ixstart = distance->size[2];
    ixstop = cindx + 1;
    if (!((ixstop >= 1) && (ixstop <= ixstart))) {
      emlrtDynamicBoundsCheckR2012b(ixstop, 1, ixstart, &ad_emlrtBCI, sp);
    }

    st.site = &e_emlrtRSI;
    ixstart = b_a->size[0] * b_a->size[1];
    b_a->size[1] = 320;
    emxEnsureCapacity_real_T(&st, b_a, ixstart, &he_emlrtRTEI);
    d_a = b_a->size[0];
    nx = b_a->size[1];
    k = d_a * nx;
    for (ixstart = 0; ixstart < k; ixstart++) {
      b_a->data[ixstart] += indx->data[ixstart];
    }

    b_st.site = &p_emlrtRSI;
    c_st.site = &v_emlrtRSI;
    d_st.site = &w_emlrtRSI;
    ixstart = indx->size[0] * indx->size[1];
    indx->size[0] = (int16_T)b_a->size[0];
    indx->size[1] = 320;
    emxEnsureCapacity_real_T(&d_st, indx, ixstart, &t_emlrtRTEI);
    if (!dimagree(indx, b_a)) {
      emlrtErrorWithMessageIdR2012b(&d_st, &nf_emlrtRTEI, "MATLAB:dimagree", 0);
    }

    ixstart = indx->size[0] * indx->size[1];
    indx->size[0] = (int16_T)b_a->size[0];
    indx->size[1] = 320;
    emxEnsureCapacity_real_T(&c_st, indx, ixstart, &u_emlrtRTEI);
    d_st.site = &x_emlrtRSI;
    a_idx_0 = (int16_T)b_a->size[0];
    nx = a_idx_0 * 320;
    e_st.site = &y_emlrtRSI;
    for (k = 0; k + 1 <= nx; k++) {
      e_st.site = &bb_emlrtRSI;
      f_st.site = &cb_emlrtRSI;
      p = (b_a->data[k] < 0.0);
      if (p) {
        g_st.site = &db_emlrtRSI;
        h_st.site = &db_emlrtRSI;
        b_error(&h_st);
      }

      indx->data[k] = muDoubleScalarSqrt(b_a->data[k]);
    }

    c_st.site = &ab_emlrtRSI;
    d_st.site = &eb_emlrtRSI;
    e_st.site = &fb_emlrtRSI;
    nx = b_a->size[0] * 320;
    p = false;
    f_st.site = &gb_emlrtRSI;
    for (k = 1; k <= nx; k++) {
      if (p || (b_a->data[k - 1] < 0.0)) {
        p = true;
      } else {
        p = false;
      }
    }

    if (p) {
      c_st.site = &q_emlrtRSI;
      d_st.site = &q_emlrtRSI;
      error(&d_st);
    }

    if (!overflow) {
      iv15[0] = 145;
      iv15[1] = 320;
      overflow = true;
    }

    emlrtSubAssignSizeCheckR2012b(&iv15[0], 2, &(*(int32_T (*)[2])indx->size)[0],
      2, &f_emlrtECI, sp);
    for (ixstart = 0; ixstart < 320; ixstart++) {
      k = indx->size[0];
      for (ixstop = 0; ixstop < k; ixstop++) {
        distance->data[(tmp_data[ixstop] + distance->size[0] * ixstart) +
          distance->size[0] * distance->size[1] * cindx] = indx->data[ixstop +
          indx->size[0] * ixstart];
      }
    }

    cindx++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_b);
  emxFree_real_T(&b_a);
  emxFree_real_T(&b);
  emxFree_real_T(&a);
  st.site = &d_emlrtRSI;
  b_st.site = &hb_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  if (!(distance->size[2] > 0)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &ag_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  emxInit_int32_T1(&c_st, &iindx, 2, &s_emlrtRTEI, true);
  ixstart = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 145;
  iindx->size[1] = 320;
  emxEnsureCapacity_int32_T1(&c_st, iindx, ixstart, &ee_emlrtRTEI);
  for (ixstart = 0; ixstart < 46400; ixstart++) {
    iindx->data[ixstart] = 1;
  }

  n = distance->size[2];
  k = 3;
  while ((k > 2) && (distance->size[2] == 1)) {
    k = 2;
  }

  if (3 > k) {
    vstride = 46400 * distance->size[2];
  } else {
    vstride = 1;
    for (k = 0; k < 2; k++) {
      vstride *= distance->size[k];
    }
  }

  d_st.site = &jb_emlrtRSI;
  d_st.site = &kb_emlrtRSI;
  overflow = ((!(1 > vstride)) && (vstride > 2147483646));
  if (overflow) {
    e_st.site = &h_emlrtRSI;
    f_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (nx = 1; nx <= vstride; nx++) {
    d_st.site = &lb_emlrtRSI;
    ixstart = nx;
    ixstop = nx + (n - 1) * vstride;
    fz = distance->data[nx - 1];
    k = 1;
    if (n > 1) {
      cindx = 1;
      if (muDoubleScalarIsNaN(distance->data[nx - 1])) {
        d_a = nx + vstride;
        e_st.site = &nb_emlrtRSI;
        if ((vstride == 0) || ((vstride > 0) && (d_a > ixstop)) || ((vstride < 0)
             && (d_a < ixstop))) {
          overflow = false;
        } else if (vstride > 0) {
          overflow = (ixstop > MAX_int32_T - vstride);
        } else {
          overflow = (ixstop < MIN_int32_T - vstride);
        }

        if (vstride == 0) {
          emlrtErrorWithMessageIdR2012b(&e_st, &yf_emlrtRTEI,
            "Coder:builtins:VectorStride", 0);
        }

        if (overflow) {
          f_st.site = &h_emlrtRSI;
          g_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        exitg1 = false;
        while ((!exitg1) && (((vstride > 0) && (d_a <= ixstop)) || ((vstride < 0)
                 && (d_a >= ixstop)))) {
          cindx++;
          ixstart = d_a;
          if (!muDoubleScalarIsNaN(distance->data[d_a - 1])) {
            fz = distance->data[d_a - 1];
            k = cindx;
            exitg1 = true;
          } else {
            d_a += vstride;
          }
        }
      }

      if (ixstart < ixstop) {
        d_a = ixstart + vstride;
        e_st.site = &mb_emlrtRSI;
        if ((vstride == 0) || ((vstride > 0) && (d_a > ixstop)) || ((vstride < 0)
             && (d_a < ixstop))) {
          overflow = false;
        } else if (vstride > 0) {
          overflow = (ixstop > MAX_int32_T - vstride);
        } else {
          overflow = (ixstop < MIN_int32_T - vstride);
        }

        if (vstride == 0) {
          emlrtErrorWithMessageIdR2012b(&e_st, &yf_emlrtRTEI,
            "Coder:builtins:VectorStride", 0);
        }

        if (overflow) {
          f_st.site = &h_emlrtRSI;
          g_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        while (((vstride > 0) && (d_a <= ixstop)) || ((vstride < 0) && (d_a >=
                 ixstop))) {
          cindx++;
          if (distance->data[d_a - 1] < fz) {
            fz = distance->data[d_a - 1];
            k = cindx;
          }

          d_a += vstride;
        }
      }
    }

    iindx->data[nx - 1] = k;
  }

  emxFree_real_T(&distance);
  ixstart = indx->size[0] * indx->size[1];
  indx->size[0] = iindx->size[0];
  indx->size[1] = 320;
  emxEnsureCapacity_real_T(&b_st, indx, ixstart, &ge_emlrtRTEI);
  k = iindx->size[0] * iindx->size[1];
  for (ixstart = 0; ixstart < k; ixstart++) {
    indx->data[ixstart] = iindx->data[ixstart];
  }

  emxFree_int32_T(&iindx);
  st.site = &c_emlrtRSI;
  indexShapeCheck(&st, *(int32_T (*)[2])indx->size);
  k = indx->size[0] * indx->size[1];
  for (ixstart = 0; ixstart < k; ixstart++) {
    ixstop = (int32_T)indx->data[ixstart];
    if (!((ixstop >= 1) && (ixstop <= 5))) {
      emlrtDynamicBoundsCheckR2012b(ixstop, 1, 5, &bd_emlrtBCI, sp);
    }
  }

  ixstart = OBJ->label->size[0] * OBJ->label->size[1];
  OBJ->label->size[0] = 95 + indx->size[0];
  OBJ->label->size[1] = 320;
  emxEnsureCapacity_real_T(sp, OBJ->label, ixstart, &ie_emlrtRTEI);
  for (ixstart = 0; ixstart < 320; ixstart++) {
    for (ixstop = 0; ixstop < 95; ixstop++) {
      OBJ->label->data[ixstop + OBJ->label->size[0] * ixstart] = 100.0;
    }
  }

  for (ixstart = 0; ixstart < 320; ixstart++) {
    k = indx->size[0];
    for (ixstop = 0; ixstop < k; ixstop++) {
      OBJ->label->data[(ixstop + OBJ->label->size[0] * ixstart) + 95] =
        OBJ->color_labels[(int32_T)indx->data[ixstop + indx->size[0] * ixstart]
        - 1];
    }
  }

  emxFree_real_T(&indx);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (ybp_finder_CLS.c) */
