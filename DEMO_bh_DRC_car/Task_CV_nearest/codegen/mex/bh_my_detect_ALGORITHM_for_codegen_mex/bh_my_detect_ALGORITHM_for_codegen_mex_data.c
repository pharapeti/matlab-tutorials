/*
 * bh_my_detect_ALGORITHM_for_codegen_mex_data.c
 *
 * Code generation for function 'bh_my_detect_ALGORITHM_for_codegen_mex_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131451U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "bh_my_detect_ALGORITHM_for_codegen_mex",/* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 1858410525U, 2505464270U, 328108647U, 1256672073U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo h_emlrtRSI = { 21,         /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo p_emlrtRSI = { 42,         /* lineNo */
  "linearizeSRGB",                     /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\colorspaces\\+images\\+color\\+internal\\+coder\\linearizeSRGB.m"/* pathName */
};

emlrtRSInfo q_emlrtRSI = { 49,         /* lineNo */
  "power",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 51,         /* lineNo */
  "XYZToLAB",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\colorspaces\\+images\\+color\\+internal\\+coder\\XYZToLAB.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 58,         /* lineNo */
  "power",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

emlrtRSInfo x_emlrtRSI = { 45,         /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

emlrtRSInfo y_emlrtRSI = { 65,         /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

emlrtRSInfo ab_emlrtRSI = { 189,       /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

emlrtRSInfo eb_emlrtRSI = { 12,        /* lineNo */
  "sqrt",                              /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pathName */
};

emlrtRSInfo ib_emlrtRSI = { 15,        /* lineNo */
  "min",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pathName */
};

emlrtRSInfo jb_emlrtRSI = { 16,        /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

emlrtRSInfo ad_emlrtRSI = { 9,         /* lineNo */
  "sum",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

emlrtRSInfo bd_emlrtRSI = { 58,        /* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

emlrtRSInfo cd_emlrtRSI = { 106,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 166,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

emlrtRSInfo ed_emlrtRSI = { 14,        /* lineNo */
  "cumsum",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\cumsum.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 23,        /* lineNo */
  "cumop",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 121,       /* lineNo */
  "cumop",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

emlrtRSInfo hd_emlrtRSI = { 126,       /* lineNo */
  "cumop",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

emlrtRSInfo id_emlrtRSI = { 128,       /* lineNo */
  "cumop",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

emlrtRSInfo jd_emlrtRSI = { 49,        /* lineNo */
  "prodsize",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\prodsize.m"/* pathName */
};

emlrtRSInfo rd_emlrtRSI = { 19,        /* lineNo */
  "ind2sub",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pathName */
};

emlrtRSInfo sd_emlrtRSI = { 20,        /* lineNo */
  "cat",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

emlrtRSInfo td_emlrtRSI = { 100,       /* lineNo */
  "cat",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

emlrtRSInfo ud_emlrtRSI = { 13,        /* lineNo */
  "min",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pathName */
};

emlrtRSInfo vd_emlrtRSI = { 19,        /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

emlrtRSInfo be_emlrtRSI = { 38,        /* lineNo */
  "mean",                              /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"/* pathName */
};

emlrtRSInfo pe_emlrtRSI = { 26,        /* lineNo */
  "sort",                              /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

emlrtRSInfo hf_emlrtRSI = { 443,       /* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

emlrtRSInfo of_emlrtRSI = { 44,        /* lineNo */
  "find",                              /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

emlrtRSInfo rh_emlrtRSI = { 24,        /* lineNo */
  "xdlapy3",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\xdlapy3.m"/* pathName */
};

emlrtRSInfo vi_emlrtRSI = { 10,        /* lineNo */
  "xzrot_rows",                        /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzrot_rows.m"/* pathName */
};

emlrtRSInfo wi_emlrtRSI = { 10,        /* lineNo */
  "xzrot_cols",                        /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzrot_cols.m"/* pathName */
};

emlrtRTEInfo t_emlrtRTEI = { 45,       /* lineNo */
  6,                                   /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pName */
};

emlrtRTEInfo u_emlrtRTEI = { 58,       /* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

emlrtRTEInfo rb_emlrtRTEI = { 36,      /* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

emlrtRTEInfo hd_emlrtRTEI = { 30,      /* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

emlrtRTEInfo id_emlrtRTEI = { 40,      /* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

emlrtRTEInfo jd_emlrtRTEI = { 42,      /* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

emlrtRTEInfo kd_emlrtRTEI = { 44,      /* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

emlrtRTEInfo xd_emlrtRTEI = { 21,      /* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

emlrtBCInfo emlrtBCI = { -1,           /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  12,                                  /* colNo */
  "I",                                 /* aName */
  "bh_mask_fraction_of_BW_image",      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_funcs\\bh_mask_fraction_of_BW_image.m",/* pName */
  0                                    /* checkKind */
};

emlrtRTEInfo sf_emlrtRTEI = { 17,      /* lineNo */
  19,                                  /* colNo */
  "scalexpAlloc",                      /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"/* pName */
};

emlrtRTEInfo uf_emlrtRTEI = { 243,     /* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

emlrtRTEInfo ag_emlrtRTEI = { 38,      /* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

emlrtRTEInfo dg_emlrtRTEI = { 281,     /* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

emlrtRTEInfo eg_emlrtRTEI = { 121,     /* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

emlrtRTEInfo fg_emlrtRTEI = { 39,      /* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

emlrtRSInfo bm_emlrtRSI = { 18,        /* lineNo */
  "indexDivide",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexDivide.m"/* pathName */
};

/* End of code generation (bh_my_detect_ALGORITHM_for_codegen_mex_data.c) */
