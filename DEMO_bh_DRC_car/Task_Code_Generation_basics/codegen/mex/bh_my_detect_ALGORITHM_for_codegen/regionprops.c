/*
 * regionprops.c
 *
 * Code generation for function 'regionprops'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "regionprops.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "error.h"
#include "sum.h"
#include "power.h"
#include "eml_int_forloop_overflow_check.h"
#include "box_info_CLS.h"
#include "assertValidSizeArg.h"
#include "bwconncomp.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mexutil.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  boolean_T Area;
  boolean_T Centroid;
  boolean_T BoundingBox;
  boolean_T MajorAxisLength;
  boolean_T MinorAxisLength;
  boolean_T Eccentricity;
  boolean_T Orientation;
  boolean_T Image;
  boolean_T FilledImage;
  boolean_T FilledArea;
  boolean_T EulerNumber;
  boolean_T Extrema;
  boolean_T EquivDiameter;
  boolean_T Extent;
  boolean_T PixelIdxList;
  boolean_T PixelList;
  boolean_T Perimeter;
  boolean_T PixelValues;
  boolean_T WeightedCentroid;
  boolean_T MeanIntensity;
  boolean_T MinIntensity;
  boolean_T MaxIntensity;
  boolean_T SubarrayIdx;
} struct_T;

#endif                                 /*typedef_struct_T*/

/* Variable Definitions */
static emlrtRSInfo dc_emlrtRSI = { 189,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 131,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 127,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 83, /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 74, /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 71, /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 69, /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 32, /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 1183,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 1350,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 18, /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 1705,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 242,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 674,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 676,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 327,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo xd_emlrtRSI = { 331,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 513,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo be_emlrtRSI = { 515,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo ce_emlrtRSI = { 542,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo de_emlrtRSI = { 543,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo ee_emlrtRSI = { 544,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo fe_emlrtRSI = { 547,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo ge_emlrtRSI = { 548,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo he_emlrtRSI = { 549,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo ie_emlrtRSI = { 550,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo je_emlrtRSI = { 551,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo ke_emlrtRSI = { 556,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 560,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo me_emlrtRSI = { 40, /* lineNo */
  "mpower",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\mpower.m"/* pathName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 1305,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 189,/* lineNo */
  2,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 1,/* lineNo */
  23,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 71,/* lineNo */
  2,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 1270,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = { 1614,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 1618,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 1637,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = { 1641,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 1655,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 1700,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 1705,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 1593,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 321,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = { 1754,/* lineNo */
  30,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 1350,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = { 189,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = { 239,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo le_emlrtRTEI = { 242,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo me_emlrtRTEI = { 244,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = { 212,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = { 226,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = { 678,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo re_emlrtRTEI = { 676,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo se_emlrtRTEI = { 674,/* lineNo */
  14,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo te_emlrtRTEI = { 674,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = { 327,/* lineNo */
  6,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = { 533,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo we_emlrtRTEI = { 534,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo xe_emlrtRTEI = { 544,/* lineNo */
  23,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1763,                                /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1763,                                /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1762,                                /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1761,                                /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1761,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1763,                                /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1763,                                /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  189,                                 /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1761,                                /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  244,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  244,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  244,                                 /* lineNo */
  70,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  244,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  244,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  260,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  260,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  673,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  674,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  678,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  676,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  331,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  331,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  550,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  544,                                 /* lineNo */
  23,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  531,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  530,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  519,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  548,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  549,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  550,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  565,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  563,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  521,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  522,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  523,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  524,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1761,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void ComputeArea(const emlrtStack *sp, c_emxArray_struct_T *stats,
  struct_T *statsAlreadyComputed);
static void ComputeCentroid(const emlrtStack *sp, const real_T imageSize[2],
  c_emxArray_struct_T *stats, struct_T *statsAlreadyComputed);
static void ComputeEllipseParams(const emlrtStack *sp, const real_T imageSize[2],
  c_emxArray_struct_T *stats, struct_T *statsAlreadyComputed);
static void ComputePixelIdxList(const emlrtStack *sp, const emxArray_real_T
  *CC_RegionIndices, const emxArray_int32_T *CC_RegionLengths, real_T numObjs,
  c_emxArray_struct_T *stats, struct_T *statsAlreadyComputed);
static void ComputePixelList(const emlrtStack *sp, const real_T imageSize[2],
  c_emxArray_struct_T *stats, struct_T *statsAlreadyComputed);
static void initializeStatsStruct(const emlrtStack *sp, real_T numObjs,
  c_emxArray_struct_T *stats, struct_T *statsAlreadyComputed);
static void populateOutputStatsStructure(const emlrtStack *sp,
  b_emxArray_struct_T *outstats, const c_emxArray_struct_T *stats);

/* Function Definitions */
static void ComputeArea(const emlrtStack *sp, c_emxArray_struct_T *stats,
  struct_T *statsAlreadyComputed)
{
  int32_T i20;
  int32_T k;
  int32_T i21;
  int32_T i22;
  if (!statsAlreadyComputed->Area) {
    statsAlreadyComputed->Area = true;
    i20 = stats->size[0];
    for (k = 0; k < i20; k++) {
      i21 = stats->size[0];
      i22 = k + 1;
      if (!((i22 >= 1) && (i22 <= i21))) {
        emlrtDynamicBoundsCheckR2012b(i22, 1, i21, &id_emlrtBCI, sp);
      }

      i21 = stats->size[0];
      if (!((k + 1 >= 1) && (k + 1 <= i21))) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, i21, &jd_emlrtBCI, sp);
      }

      stats->data[k].Area = stats->data[k].PixelIdxList->size[0];
    }
  }
}

static void ComputeCentroid(const emlrtStack *sp, const real_T imageSize[2],
  c_emxArray_struct_T *stats, struct_T *statsAlreadyComputed)
{
  c_emxArray_struct_T *b_stats;
  int32_T xpageoffset;
  int32_T vlen;
  int32_T k;
  boolean_T overflow;
  int32_T i;
  real_T y[2];
  int32_T b_k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (!statsAlreadyComputed->Centroid) {
    emxInit_struct_T2(sp, &b_stats, 1, &bd_emlrtRTEI, true);
    statsAlreadyComputed->Centroid = true;
    xpageoffset = b_stats->size[0];
    b_stats->size[0] = stats->size[0];
    emxEnsureCapacity_struct_T2(sp, b_stats, xpageoffset, &ue_emlrtRTEI);
    vlen = stats->size[0];
    for (xpageoffset = 0; xpageoffset < vlen; xpageoffset++) {
      emxCopyStruct_struct_T2(sp, &b_stats->data[xpageoffset], &stats->
        data[xpageoffset], &bd_emlrtRTEI);
    }

    st.site = &wd_emlrtRSI;
    ComputePixelList(&st, imageSize, b_stats, statsAlreadyComputed);
    xpageoffset = stats->size[0];
    stats->size[0] = b_stats->size[0];
    emxEnsureCapacity_struct_T2(sp, stats, xpageoffset, &ue_emlrtRTEI);
    vlen = b_stats->size[0];
    for (xpageoffset = 0; xpageoffset < vlen; xpageoffset++) {
      emxCopyStruct_struct_T2(sp, &stats->data[xpageoffset], &b_stats->
        data[xpageoffset], &ue_emlrtRTEI);
    }

    for (k = 0; k < b_stats->size[0]; k++) {
      st.site = &xd_emlrtRSI;
      xpageoffset = stats->size[0];
      vlen = k + 1;
      if (!((vlen >= 1) && (vlen <= xpageoffset))) {
        emlrtDynamicBoundsCheckR2012b(vlen, 1, xpageoffset, &od_emlrtBCI, &st);
      }

      b_st.site = &yd_emlrtRSI;
      vlen = stats->data[k].PixelList->size[0];
      if (stats->data[k].PixelList->size[0] == 0) {
        for (xpageoffset = 0; xpageoffset < 2; xpageoffset++) {
          y[xpageoffset] = 0.0;
        }
      } else {
        c_st.site = &bd_emlrtRSI;
        overflow = ((!(2 > vlen)) && (vlen > 2147483646));
        for (i = 0; i < 2; i++) {
          xpageoffset = i * stats->data[k].PixelList->size[0];
          y[i] = stats->data[k].PixelList->data[xpageoffset];
          d_st.site = &cd_emlrtRSI;
          if (overflow) {
            e_st.site = &h_emlrtRSI;
            f_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          for (b_k = 2; b_k <= vlen; b_k++) {
            y[i] += stats->data[k].PixelList->data[(xpageoffset + b_k) - 1];
          }
        }
      }

      vlen = stats->data[k].PixelList->size[0];
      i = stats->size[0];
      for (xpageoffset = 0; xpageoffset < 2; xpageoffset++) {
        if (!((k + 1 >= 1) && (k + 1 <= i))) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, i, &pd_emlrtBCI, &st);
        }

        stats->data[k].Centroid[xpageoffset] = y[xpageoffset] / (real_T)vlen;
      }
    }

    emxFree_struct_T2(&b_stats);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void ComputeEllipseParams(const emlrtStack *sp, const real_T imageSize[2],
  c_emxArray_struct_T *stats, struct_T *statsAlreadyComputed)
{
  boolean_T p;
  int32_T i25;
  int32_T k;
  emxArray_real_T *x;
  emxArray_real_T *y;
  emxArray_real_T *b_x;
  int32_T i26;
  int32_T loop_ub;
  real_T common;
  real_T c_x;
  real_T b_y;
  real_T c_y;
  real_T uxy;
  real_T num;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (statsAlreadyComputed->MajorAxisLength &&
      statsAlreadyComputed->MinorAxisLength && statsAlreadyComputed->Orientation
      && statsAlreadyComputed->Eccentricity) {
    p = true;
  } else {
    p = false;
  }

  if (!p) {
    statsAlreadyComputed->MajorAxisLength = true;
    statsAlreadyComputed->MinorAxisLength = true;
    statsAlreadyComputed->Eccentricity = true;
    statsAlreadyComputed->Orientation = true;
    st.site = &ae_emlrtRSI;
    ComputePixelList(&st, imageSize, stats, statsAlreadyComputed);
    st.site = &be_emlrtRSI;
    ComputeCentroid(&st, imageSize, stats, statsAlreadyComputed);
    i25 = stats->size[0];
    k = 0;
    emxInit_real_T1(sp, &x, 1, &ve_emlrtRTEI, true);
    emxInit_real_T1(sp, &y, 1, &we_emlrtRTEI, true);
    emxInit_real_T1(sp, &b_x, 1, &xe_emlrtRTEI, true);
    while (k <= i25 - 1) {
      i26 = stats->size[0];
      loop_ub = k + 1;
      if (!((loop_ub >= 1) && (loop_ub <= i26))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i26, &vd_emlrtBCI, sp);
      }

      if (stats->data[k].PixelList->size[0] == 0) {
        i26 = stats->size[0];
        if (!((k + 1 >= 1) && (k + 1 <= i26))) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, i26, &ce_emlrtBCI, sp);
        }

        stats->data[k].MajorAxisLength = 0.0;
        i26 = stats->size[0];
        if (!((k + 1 >= 1) && (k + 1 <= i26))) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, i26, &de_emlrtBCI, sp);
        }

        stats->data[k].MinorAxisLength = 0.0;
        i26 = stats->size[0];
        if (!((k + 1 >= 1) && (k + 1 <= i26))) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, i26, &ee_emlrtBCI, sp);
        }

        stats->data[k].Eccentricity = 0.0;
        i26 = stats->size[0];
        if (!((k + 1 >= 1) && (k + 1 <= i26))) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, i26, &fe_emlrtBCI, sp);
        }

        stats->data[k].Orientation = 0.0;
      } else {
        i26 = stats->size[0];
        loop_ub = k + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i26))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i26, &ud_emlrtBCI, sp);
        }

        i26 = stats->size[0];
        loop_ub = k + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i26))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i26, &td_emlrtBCI, sp);
        }

        loop_ub = stats->data[k].PixelList->size[0];
        common = stats->data[k].Centroid[0];
        i26 = x->size[0];
        x->size[0] = loop_ub;
        emxEnsureCapacity_real_T1(sp, x, i26, &ve_emlrtRTEI);
        for (i26 = 0; i26 < loop_ub; i26++) {
          x->data[i26] = stats->data[k].PixelList->data[i26] - common;
        }

        loop_ub = stats->data[k].PixelList->size[0];
        common = stats->data[k].Centroid[1];
        i26 = y->size[0];
        y->size[0] = loop_ub;
        emxEnsureCapacity_real_T1(sp, y, i26, &we_emlrtRTEI);
        for (i26 = 0; i26 < loop_ub; i26++) {
          y->data[i26] = -(stats->data[k].PixelList->data[i26 + stats->data[k].
                           PixelList->size[0]] - common);
        }

        st.site = &ce_emlrtRSI;
        b_power(&st, x, b_x);
        st.site = &ce_emlrtRSI;
        c_x = sum(&st, b_x);
        b_y = c_x / (real_T)x->size[0];
        st.site = &de_emlrtRSI;
        b_power(&st, y, b_x);
        st.site = &de_emlrtRSI;
        c_x = sum(&st, b_x);
        c_y = c_x / (real_T)x->size[0];
        i26 = x->size[0];
        loop_ub = y->size[0];
        if (i26 != loop_ub) {
          emlrtSizeEqCheck1DR2012b(i26, loop_ub, &g_emlrtECI, sp);
        }

        i26 = b_x->size[0];
        b_x->size[0] = x->size[0];
        emxEnsureCapacity_real_T1(sp, b_x, i26, &xe_emlrtRTEI);
        loop_ub = x->size[0];
        for (i26 = 0; i26 < loop_ub; i26++) {
          b_x->data[i26] = x->data[i26] * y->data[i26];
        }

        st.site = &ee_emlrtRSI;
        c_x = sum(&st, b_x);
        uxy = c_x / (real_T)x->size[0];
        st.site = &fe_emlrtRSI;
        c_x = (b_y + 0.083333333333333329) - (c_y + 0.083333333333333329);
        b_st.site = &me_emlrtRSI;
        st.site = &fe_emlrtRSI;
        b_st.site = &me_emlrtRSI;
        st.site = &fe_emlrtRSI;
        c_x = c_x * c_x + 4.0 * (uxy * uxy);
        p = (c_x < 0.0);
        if (p) {
          b_st.site = &db_emlrtRSI;
          c_st.site = &db_emlrtRSI;
          b_error(&c_st);
        }

        common = muDoubleScalarSqrt(c_x);
        st.site = &ge_emlrtRSI;
        st.site = &ge_emlrtRSI;
        c_x = ((b_y + 0.083333333333333329) + (c_y + 0.083333333333333329)) +
          common;
        p = (c_x < 0.0);
        if (p) {
          b_st.site = &db_emlrtRSI;
          c_st.site = &db_emlrtRSI;
          b_error(&c_st);
        }

        i26 = stats->size[0];
        if (!((k + 1 >= 1) && (k + 1 <= i26))) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, i26, &wd_emlrtBCI, sp);
        }

        stats->data[k].MajorAxisLength = 2.8284271247461903 * muDoubleScalarSqrt
          (c_x);
        st.site = &he_emlrtRSI;
        st.site = &he_emlrtRSI;
        c_x = ((b_y + 0.083333333333333329) + (c_y + 0.083333333333333329)) -
          common;
        p = (c_x < 0.0);
        if (p) {
          b_st.site = &db_emlrtRSI;
          c_st.site = &db_emlrtRSI;
          b_error(&c_st);
        }

        i26 = stats->size[0];
        if (!((k + 1 >= 1) && (k + 1 <= i26))) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, i26, &xd_emlrtBCI, sp);
        }

        stats->data[k].MinorAxisLength = 2.8284271247461903 * muDoubleScalarSqrt
          (c_x);
        i26 = stats->size[0];
        loop_ub = k + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i26))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i26, &sd_emlrtBCI, sp);
        }

        c_x = stats->data[k].MajorAxisLength / 2.0;
        i26 = stats->size[0];
        loop_ub = k + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i26))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i26, &rd_emlrtBCI, sp);
        }

        common = stats->data[k].MinorAxisLength / 2.0;
        st.site = &ie_emlrtRSI;
        b_st.site = &me_emlrtRSI;
        st.site = &je_emlrtRSI;
        b_st.site = &me_emlrtRSI;
        st.site = &ie_emlrtRSI;
        c_x = c_x * c_x - common * common;
        p = (c_x < 0.0);
        if (p) {
          b_st.site = &db_emlrtRSI;
          c_st.site = &db_emlrtRSI;
          b_error(&c_st);
        }

        i26 = stats->size[0];
        loop_ub = k + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i26))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i26, &qd_emlrtBCI, sp);
        }

        i26 = stats->size[0];
        if (!((k + 1 >= 1) && (k + 1 <= i26))) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, i26, &yd_emlrtBCI, sp);
        }

        stats->data[k].Eccentricity = 2.0 * muDoubleScalarSqrt(c_x) /
          stats->data[k].MajorAxisLength;
        if (c_y + 0.083333333333333329 > b_y + 0.083333333333333329) {
          st.site = &ke_emlrtRSI;
          c_x = (c_y + 0.083333333333333329) - (b_y + 0.083333333333333329);
          b_st.site = &me_emlrtRSI;
          st.site = &ke_emlrtRSI;
          b_st.site = &me_emlrtRSI;
          st.site = &ke_emlrtRSI;
          c_x = c_x * c_x + 4.0 * (uxy * uxy);
          p = (c_x < 0.0);
          if (p) {
            b_st.site = &db_emlrtRSI;
            c_st.site = &db_emlrtRSI;
            b_error(&c_st);
          }

          num = ((c_y + 0.083333333333333329) - (b_y + 0.083333333333333329)) +
            muDoubleScalarSqrt(c_x);
          common = 2.0 * uxy;
        } else {
          num = 2.0 * uxy;
          st.site = &le_emlrtRSI;
          c_x = (b_y + 0.083333333333333329) - (c_y + 0.083333333333333329);
          b_st.site = &me_emlrtRSI;
          st.site = &le_emlrtRSI;
          b_st.site = &me_emlrtRSI;
          st.site = &le_emlrtRSI;
          c_x = c_x * c_x + 4.0 * (uxy * uxy);
          p = (c_x < 0.0);
          if (p) {
            b_st.site = &db_emlrtRSI;
            c_st.site = &db_emlrtRSI;
            b_error(&c_st);
          }

          common = ((b_y + 0.083333333333333329) - (c_y + 0.083333333333333329))
            + muDoubleScalarSqrt(c_x);
        }

        if ((num == 0.0) && (common == 0.0)) {
          i26 = stats->size[0];
          if (!((k + 1 >= 1) && (k + 1 <= i26))) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, i26, &be_emlrtBCI, sp);
          }

          stats->data[k].Orientation = 0.0;
        } else {
          i26 = stats->size[0];
          if (!((k + 1 >= 1) && (k + 1 <= i26))) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, i26, &ae_emlrtBCI, sp);
          }

          stats->data[k].Orientation = 57.295779513082323 * muDoubleScalarAtan
            (num / common);
        }
      }

      k++;
    }

    emxFree_real_T(&b_x);
    emxFree_real_T(&y);
    emxFree_real_T(&x);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void ComputePixelIdxList(const emlrtStack *sp, const emxArray_real_T
  *CC_RegionIndices, const emxArray_int32_T *CC_RegionLengths, real_T numObjs,
  c_emxArray_struct_T *stats, struct_T *statsAlreadyComputed)
{
  emxArray_int32_T *regionLengths;
  int32_T i17;
  int32_T loop_ub;
  emxArray_int32_T *idxCount;
  int32_T vstride;
  int32_T k;
  boolean_T overflow;
  int32_T i18;
  int32_T i19;
  int32_T b_stats;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  statsAlreadyComputed->PixelIdxList = true;
  if (numObjs != 0.0) {
    emxInit_int32_T(sp, &regionLengths, 1, &ne_emlrtRTEI, true);
    i17 = regionLengths->size[0];
    regionLengths->size[0] = CC_RegionLengths->size[0];
    emxEnsureCapacity_int32_T(sp, regionLengths, i17, &ke_emlrtRTEI);
    loop_ub = CC_RegionLengths->size[0];
    for (i17 = 0; i17 < loop_ub; i17++) {
      regionLengths->data[i17] = CC_RegionLengths->data[i17];
    }

    st.site = &nd_emlrtRSI;
    b_st.site = &dd_emlrtRSI;
    loop_ub = 2;
    if (CC_RegionLengths->size[0] != 1) {
      loop_ub = 1;
    }

    c_st.site = &ed_emlrtRSI;
    if (loop_ub <= 1) {
      i17 = CC_RegionLengths->size[0];
    } else {
      i17 = 1;
    }

    if ((!(CC_RegionLengths->size[0] == 0)) && (i17 > 1)) {
      d_st.site = &fd_emlrtRSI;
      vstride = 1;
      e_st.site = &id_emlrtRSI;
      k = 1;
      while (k <= loop_ub - 1) {
        vstride *= CC_RegionLengths->size[0];
        k = 2;
      }

      d_st.site = &gd_emlrtRSI;
      overflow = ((!(1 > vstride)) && (vstride > 2147483646));
      if (overflow) {
        e_st.site = &h_emlrtRSI;
        f_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (loop_ub = 0; loop_ub + 1 <= vstride; loop_ub++) {
        d_st.site = &hd_emlrtRSI;
        for (k = 1; k < i17; k++) {
          regionLengths->data[loop_ub + k * vstride] += regionLengths->
            data[loop_ub + (k - 1) * vstride];
        }
      }
    }

    emxInit_int32_T(&c_st, &idxCount, 1, &oe_emlrtRTEI, true);
    i17 = idxCount->size[0];
    idxCount->size[0] = 1 + regionLengths->size[0];
    emxEnsureCapacity_int32_T(sp, idxCount, i17, &le_emlrtRTEI);
    idxCount->data[0] = 0;
    loop_ub = regionLengths->size[0];
    for (i17 = 0; i17 < loop_ub; i17++) {
      idxCount->data[i17 + 1] = regionLengths->data[i17];
    }

    emxFree_int32_T(&regionLengths);
    i17 = stats->size[0];
    for (k = 0; k < i17; k++) {
      i18 = idxCount->size[0];
      i19 = k + 1;
      if (!((i19 >= 1) && (i19 <= i18))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, i18, &gd_emlrtBCI, sp);
      }

      i18 = idxCount->size[0];
      i19 = (int32_T)((1.0 + (real_T)k) + 1.0);
      if (!((i19 >= 1) && (i19 <= i18))) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, i18, &fd_emlrtBCI, sp);
      }

      if (idxCount->data[k] + 1 > idxCount->data[(int32_T)((1.0 + (real_T)k) +
           1.0) - 1]) {
        i18 = 0;
        vstride = 0;
      } else {
        i18 = CC_RegionIndices->size[0];
        i19 = idxCount->data[k] + 1;
        if (!((i19 >= 1) && (i19 <= i18))) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, i18, &ed_emlrtBCI, sp);
        }

        i18 = i19 - 1;
        i19 = CC_RegionIndices->size[0];
        vstride = idxCount->data[(int32_T)((1.0 + (real_T)k) + 1.0) - 1];
        if (!((vstride >= 1) && (vstride <= i19))) {
          emlrtDynamicBoundsCheckR2012b(vstride, 1, i19, &dd_emlrtBCI, sp);
        }
      }

      b_stats = stats->size[0];
      if (!((k + 1 >= 1) && (k + 1 <= b_stats))) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_stats, &hd_emlrtBCI, sp);
      }

      i19 = stats->data[k].PixelIdxList->size[0];
      stats->data[k].PixelIdxList->size[0] = vstride - i18;
      emxEnsureCapacity_real_T1(sp, stats->data[k].PixelIdxList, i19,
        &me_emlrtRTEI);
      loop_ub = vstride - i18;
      for (i19 = 0; i19 < loop_ub; i19++) {
        if (!((k + 1 >= 1) && (k + 1 <= b_stats))) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_stats, &hd_emlrtBCI, sp);
        }

        stats->data[k].PixelIdxList->data[i19] = CC_RegionIndices->data[i18 +
          i19];
      }
    }

    emxFree_int32_T(&idxCount);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void ComputePixelList(const emlrtStack *sp, const real_T imageSize[2],
  c_emxArray_struct_T *stats, struct_T *statsAlreadyComputed)
{
  int32_T i23;
  int32_T k;
  emxArray_int32_T *i;
  emxArray_int32_T *j;
  emxArray_int32_T *idx;
  emxArray_int32_T *vk;
  int32_T i24;
  int32_T maxndx;
  int32_T loop_ub;
  int32_T exitg1;
  boolean_T p;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (!statsAlreadyComputed->PixelList) {
    statsAlreadyComputed->PixelList = true;
    i23 = stats->size[0];
    k = 1;
    emxInit_int32_T(sp, &i, 1, &se_emlrtRTEI, true);
    emxInit_int32_T(sp, &j, 1, &te_emlrtRTEI, true);
    emxInit_int32_T(sp, &idx, 1, &hd_emlrtRTEI, true);
    emxInit_int32_T(sp, &vk, 1, &jd_emlrtRTEI, true);
    while (k - 1 <= i23 - 1) {
      i24 = stats->size[0];
      maxndx = (k - 1) + 1;
      if (!((maxndx >= 1) && (maxndx <= i24))) {
        emlrtDynamicBoundsCheckR2012b(maxndx, 1, i24, &kd_emlrtBCI, sp);
      }

      if (!(stats->data[k - 1].PixelIdxList->size[0] == 0)) {
        st.site = &od_emlrtRSI;
        i24 = stats->size[0];
        maxndx = (k - 1) + 1;
        if (!((maxndx >= 1) && (maxndx <= i24))) {
          emlrtDynamicBoundsCheckR2012b(maxndx, 1, i24, &ld_emlrtBCI, &st);
        }

        b_st.site = &qd_emlrtRSI;
        i24 = idx->size[0];
        idx->size[0] = stats->data[k - 1].PixelIdxList->size[0];
        emxEnsureCapacity_int32_T(&b_st, idx, i24, &hd_emlrtRTEI);
        loop_ub = stats->data[k - 1].PixelIdxList->size[0];
        for (i24 = 0; i24 < loop_ub; i24++) {
          idx->data[i24] = (int32_T)stats->data[k - 1].PixelIdxList->data[i24];
        }

        maxndx = (int32_T)imageSize[0] * 320;
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub <= idx->size[0] - 1) {
            if ((idx->data[loop_ub] >= 1) && (idx->data[loop_ub] <= maxndx)) {
              p = true;
            } else {
              p = false;
            }

            if (!p) {
              p = false;
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            p = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);

        if (!p) {
          emlrtErrorWithMessageIdR2012b(&b_st, &uf_emlrtRTEI,
            "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
        }

        i24 = idx->size[0];
        emxEnsureCapacity_int32_T(&b_st, idx, i24, &id_emlrtRTEI);
        loop_ub = idx->size[0];
        for (i24 = 0; i24 < loop_ub; i24++) {
          idx->data[i24]--;
        }

        i24 = vk->size[0];
        vk->size[0] = idx->size[0];
        emxEnsureCapacity_int32_T(&b_st, vk, i24, &jd_emlrtRTEI);
        loop_ub = idx->size[0];
        for (i24 = 0; i24 < loop_ub; i24++) {
          c_st.site = &wk_emlrtRSI;
          vk->data[i24] = div_s32(&c_st, idx->data[i24], (int32_T)imageSize[0]);
        }

        i24 = idx->size[0];
        emxEnsureCapacity_int32_T(&b_st, idx, i24, &kd_emlrtRTEI);
        loop_ub = idx->size[0];
        for (i24 = 0; i24 < loop_ub; i24++) {
          idx->data[i24] -= vk->data[i24] * (int32_T)imageSize[0];
        }

        i24 = i->size[0];
        i->size[0] = idx->size[0];
        emxEnsureCapacity_int32_T(&st, i, i24, &qe_emlrtRTEI);
        loop_ub = idx->size[0];
        for (i24 = 0; i24 < loop_ub; i24++) {
          i->data[i24] = idx->data[i24] + 1;
        }

        i24 = j->size[0];
        j->size[0] = vk->size[0];
        emxEnsureCapacity_int32_T(&st, j, i24, &qe_emlrtRTEI);
        loop_ub = vk->size[0];
        for (i24 = 0; i24 < loop_ub; i24++) {
          j->data[i24] = vk->data[i24] + 1;
        }

        st.site = &pd_emlrtRSI;
        b_st.site = &rd_emlrtRSI;
        c_st.site = &sd_emlrtRSI;
        p = true;
        if (i->size[0] != j->size[0]) {
          p = false;
        }

        if (!p) {
          emlrtErrorWithMessageIdR2012b(&c_st, &xf_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        maxndx = stats->size[0];
        if (!((k >= 1) && (k <= maxndx))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, maxndx, &nd_emlrtBCI, &b_st);
        }

        i24 = stats->data[k - 1].PixelList->size[0] * stats->data[k - 1].
          PixelList->size[1];
        stats->data[k - 1].PixelList->size[0] = j->size[0];
        if (!((k >= 1) && (k <= maxndx))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, maxndx, &nd_emlrtBCI, &b_st);
        }

        stats->data[k - 1].PixelList->size[1] = 2;
        emxEnsureCapacity_real_T(&b_st, stats->data[k - 1].PixelList, i24,
          &re_emlrtRTEI);
        loop_ub = j->size[0];
        for (i24 = 0; i24 < loop_ub; i24++) {
          if (!((k >= 1) && (k <= maxndx))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, maxndx, &nd_emlrtBCI, &b_st);
            emlrtDynamicBoundsCheckR2012b(k, 1, maxndx, &nd_emlrtBCI, &b_st);
          }

          stats->data[k - 1].PixelList->data[i24] = j->data[i24];
        }

        loop_ub = i->size[0];
        for (i24 = 0; i24 < loop_ub; i24++) {
          if (!((k >= 1) && (k <= maxndx))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, maxndx, &nd_emlrtBCI, &b_st);
            emlrtDynamicBoundsCheckR2012b(k, 1, maxndx, &nd_emlrtBCI, &b_st);
          }

          stats->data[k - 1].PixelList->data[i24 + stats->data[k - 1].
            PixelList->size[0]] = i->data[i24];
        }
      } else {
        i24 = stats->size[0];
        if (!((k >= 1) && (k <= i24))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i24, &md_emlrtBCI, sp);
        }

        i24 = k - 1;
        maxndx = stats->data[i24].PixelList->size[0] * stats->data[i24].
          PixelList->size[1];
        stats->data[i24].PixelList->size[0] = 0;
        i24 = stats->size[0];
        if (!((k >= 1) && (k <= i24))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i24, &md_emlrtBCI, sp);
        }

        i24 = k - 1;
        stats->data[i24].PixelList->size[1] = 2;
        emxEnsureCapacity_real_T(sp, stats->data[i24].PixelList, maxndx,
          &pe_emlrtRTEI);
        maxndx = stats->size[0];
        if (!((k >= 1) && (k <= maxndx))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, maxndx, &md_emlrtBCI, sp);
        }

        maxndx = stats->size[0];
        if (!((k >= 1) && (k <= maxndx))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, maxndx, &md_emlrtBCI, sp);
        }
      }

      k++;
    }

    emxFree_int32_T(&vk);
    emxFree_int32_T(&idx);
    emxFree_int32_T(&j);
    emxFree_int32_T(&i);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void initializeStatsStruct(const emlrtStack *sp, real_T numObjs,
  c_emxArray_struct_T *stats, struct_T *statsAlreadyComputed)
{
  d_struct_T statsOneObj;
  int32_T i6;
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInitStruct_struct_T2(sp, &statsOneObj, &ad_emlrtRTEI, true);
  statsAlreadyComputed->Area = false;
  statsOneObj.Area = 0.0;
  statsAlreadyComputed->Centroid = false;
  for (i6 = 0; i6 < 2; i6++) {
    statsOneObj.Centroid[i6] = 0.0;
  }

  statsAlreadyComputed->BoundingBox = false;
  for (i6 = 0; i6 < 4; i6++) {
    statsOneObj.BoundingBox[i6] = 0.0;
  }

  statsAlreadyComputed->MajorAxisLength = false;
  statsOneObj.MajorAxisLength = 0.0;
  statsAlreadyComputed->MinorAxisLength = false;
  statsOneObj.MinorAxisLength = 0.0;
  statsAlreadyComputed->Eccentricity = false;
  statsOneObj.Eccentricity = 0.0;
  statsAlreadyComputed->Orientation = false;
  statsOneObj.Orientation = 0.0;
  statsAlreadyComputed->Image = false;
  i6 = statsOneObj.Image->size[0] * statsOneObj.Image->size[1];
  statsOneObj.Image->size[0] = 0;
  statsOneObj.Image->size[1] = 0;
  emxEnsureCapacity_boolean_T(sp, statsOneObj.Image, i6, &sc_emlrtRTEI);
  statsAlreadyComputed->FilledImage = false;
  i6 = statsOneObj.FilledImage->size[0] * statsOneObj.FilledImage->size[1];
  statsOneObj.FilledImage->size[0] = 0;
  statsOneObj.FilledImage->size[1] = 0;
  emxEnsureCapacity_boolean_T(sp, statsOneObj.FilledImage, i6, &tc_emlrtRTEI);
  statsAlreadyComputed->FilledArea = false;
  statsOneObj.FilledArea = 0.0;
  statsAlreadyComputed->EulerNumber = false;
  statsOneObj.EulerNumber = 0.0;
  statsAlreadyComputed->Extrema = false;
  memset(&statsOneObj.Extrema[0], 0, sizeof(real_T) << 4);
  statsAlreadyComputed->EquivDiameter = false;
  statsOneObj.EquivDiameter = 0.0;
  statsAlreadyComputed->Extent = false;
  statsOneObj.Extent = 0.0;
  statsAlreadyComputed->PixelIdxList = false;
  i6 = statsOneObj.PixelIdxList->size[0];
  statsOneObj.PixelIdxList->size[0] = 0;
  emxEnsureCapacity_real_T1(sp, statsOneObj.PixelIdxList, i6, &uc_emlrtRTEI);
  statsAlreadyComputed->PixelList = false;
  i6 = statsOneObj.PixelList->size[0] * statsOneObj.PixelList->size[1];
  statsOneObj.PixelList->size[0] = 0;
  statsOneObj.PixelList->size[1] = 2;
  emxEnsureCapacity_real_T(sp, statsOneObj.PixelList, i6, &vc_emlrtRTEI);
  statsAlreadyComputed->Perimeter = false;
  statsOneObj.Perimeter = 0.0;
  statsAlreadyComputed->PixelValues = false;
  i6 = statsOneObj.PixelValues->size[0];
  statsOneObj.PixelValues->size[0] = 0;
  emxEnsureCapacity_real_T1(sp, statsOneObj.PixelValues, i6, &wc_emlrtRTEI);
  statsAlreadyComputed->WeightedCentroid = false;
  for (i6 = 0; i6 < 2; i6++) {
    statsOneObj.WeightedCentroid[i6] = 0.0;
  }

  statsAlreadyComputed->MeanIntensity = false;
  statsOneObj.MeanIntensity = 0.0;
  statsAlreadyComputed->MinIntensity = false;
  statsOneObj.MinIntensity = 0.0;
  statsAlreadyComputed->MaxIntensity = false;
  statsOneObj.MaxIntensity = 0.0;
  statsAlreadyComputed->SubarrayIdx = false;
  i6 = statsOneObj.SubarrayIdx->size[0] * statsOneObj.SubarrayIdx->size[1];
  statsOneObj.SubarrayIdx->size[0] = 1;
  statsOneObj.SubarrayIdx->size[1] = 0;
  emxEnsureCapacity_real_T(sp, statsOneObj.SubarrayIdx, i6, &xc_emlrtRTEI);
  for (i6 = 0; i6 < 2; i6++) {
    statsOneObj.SubarrayIdxLengths[i6] = 0.0;
  }

  st.site = &md_emlrtRSI;
  b_st.site = &ld_emlrtRSI;
  assertValidSizeArg(&b_st, numObjs);
  i6 = stats->size[0];
  stats->size[0] = (int32_T)numObjs;
  emxEnsureCapacity_struct_T2(&st, stats, i6, &yc_emlrtRTEI);
  loop_ub = (int32_T)numObjs;
  for (i6 = 0; i6 < loop_ub; i6++) {
    emxCopyStruct_struct_T2(&st, &stats->data[i6], &statsOneObj, &yc_emlrtRTEI);
  }

  emxFreeStruct_struct_T2(&statsOneObj);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void populateOutputStatsStructure(const emlrtStack *sp,
  b_emxArray_struct_T *outstats, const c_emxArray_struct_T *stats)
{
  int32_T k;
  int32_T i27;
  int32_T b_stats;
  int32_T b_outstats;
  int32_T i28;
  for (k = 0; k < stats->size[0]; k++) {
    i27 = stats->size[0];
    b_stats = k + 1;
    if (!((b_stats >= 1) && (b_stats <= i27))) {
      emlrtDynamicBoundsCheckR2012b(b_stats, 1, i27, &sc_emlrtBCI, sp);
    }

    i27 = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i27, &rc_emlrtBCI, sp);
    }

    i27 = outstats->size[0];
    b_stats = k + 1;
    if (!((b_stats >= 1) && (b_stats <= i27))) {
      emlrtDynamicBoundsCheckR2012b(b_stats, 1, i27, &qc_emlrtBCI, sp);
    }

    i27 = stats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i27, &tc_emlrtBCI, sp);
    }

    i27 = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i27, &uc_emlrtBCI, sp);
    }

    outstats->data[k].Orientation = stats->data[k].Orientation;
    i27 = stats->size[0];
    b_stats = k + 1;
    if (!((b_stats >= 1) && (b_stats <= i27))) {
      emlrtDynamicBoundsCheckR2012b(b_stats, 1, i27, &sc_emlrtBCI, sp);
    }

    i27 = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i27, &rc_emlrtBCI, sp);
    }

    i27 = outstats->size[0];
    b_stats = k + 1;
    if (!((b_stats >= 1) && (b_stats <= i27))) {
      emlrtDynamicBoundsCheckR2012b(b_stats, 1, i27, &qc_emlrtBCI, sp);
    }

    i27 = stats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i27, &tc_emlrtBCI, sp);
    }

    i27 = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i27, &uc_emlrtBCI, sp);
    }

    outstats->data[k].Eccentricity = stats->data[k].Eccentricity;
    i27 = stats->size[0];
    b_stats = k + 1;
    if (!((b_stats >= 1) && (b_stats <= i27))) {
      emlrtDynamicBoundsCheckR2012b(b_stats, 1, i27, &sc_emlrtBCI, sp);
    }

    i27 = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i27, &rc_emlrtBCI, sp);
    }

    i27 = outstats->size[0];
    b_stats = k + 1;
    if (!((b_stats >= 1) && (b_stats <= i27))) {
      emlrtDynamicBoundsCheckR2012b(b_stats, 1, i27, &qc_emlrtBCI, sp);
    }

    i27 = stats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i27, &tc_emlrtBCI, sp);
    }

    i27 = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i27))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i27, &uc_emlrtBCI, sp);
    }

    outstats->data[k].Area = stats->data[k].Area;
    b_stats = stats->size[0];
    b_outstats = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= b_stats))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_stats, &wc_emlrtBCI, sp);
    }

    b_stats = stats->data[k].PixelIdxList->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= b_outstats))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_outstats, &ge_emlrtBCI, sp);
    }

    i27 = outstats->data[k].PixelIdxList->size[0];
    outstats->data[k].PixelIdxList->size[0] = b_stats;
    emxEnsureCapacity_real_T1(sp, outstats->data[k].PixelIdxList, i27,
      &dd_emlrtRTEI);
    i27 = outstats->size[0];
    b_stats = k + 1;
    if (!((b_stats >= 1) && (b_stats <= i27))) {
      emlrtDynamicBoundsCheckR2012b(b_stats, 1, i27, &qc_emlrtBCI, sp);
    }

    i27 = outstats->data[k].PixelIdxList->size[0];
    for (b_outstats = 1; b_outstats - 1 < i27; b_outstats++) {
      b_stats = stats->size[0];
      i28 = k + 1;
      if (!((i28 >= 1) && (i28 <= b_stats))) {
        emlrtDynamicBoundsCheckR2012b(i28, 1, b_stats, &pc_emlrtBCI, sp);
      }

      b_stats = outstats->size[0];
      i28 = k + 1;
      if (!((i28 >= 1) && (i28 <= b_stats))) {
        emlrtDynamicBoundsCheckR2012b(i28, 1, b_stats, &oc_emlrtBCI, sp);
      }

      b_stats = stats->data[k].PixelIdxList->size[0];
      if (!((b_outstats >= 1) && (b_outstats <= b_stats))) {
        emlrtDynamicBoundsCheckR2012b(b_outstats, 1, b_stats, &tc_emlrtBCI, sp);
      }

      b_stats = outstats->data[k].PixelIdxList->size[0];
      if (!((b_outstats >= 1) && (b_outstats <= b_stats))) {
        emlrtDynamicBoundsCheckR2012b(b_outstats, 1, b_stats, &uc_emlrtBCI, sp);
      }

      outstats->data[k].PixelIdxList->data[b_outstats - 1] = stats->data[k].
        PixelIdxList->data[b_outstats - 1];
    }
  }
}

void b_regionprops(const emlrtStack *sp, const emxArray_boolean_T *varargin_1,
                   emxArray_struct_T *outstats)
{
  emxArray_real_T *CC_RegionIndices;
  emxArray_int32_T *CC_RegionLengths;
  b_struct_T statsOneObj;
  real_T expl_temp;
  real_T CC_ImageSize[2];
  real_T CC_NumObjects;
  int32_T i9;
  int32_T loop_ub;
  c_emxArray_struct_T *stats;
  struct_T statsAlreadyComputed;
  int32_T k;
  int32_T vIdx;
  int32_T i10;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &CC_RegionIndices, 1, &vb_emlrtRTEI, true);
  emxInit_int32_T(sp, &CC_RegionLengths, 1, &vb_emlrtRTEI, true);
  emxInitStruct_struct_T(sp, &statsOneObj, &xb_emlrtRTEI, true);
  st.site = &kc_emlrtRSI;
  bwconncomp(&st, varargin_1, &expl_temp, CC_ImageSize, &CC_NumObjects,
             CC_RegionIndices, CC_RegionLengths);
  st.site = &jc_emlrtRSI;
  b_st.site = &jd_emlrtRSI;
  statsOneObj.Area = 0.0;
  statsOneObj.Eccentricity = 0.0;
  i9 = statsOneObj.PixelIdxList->size[0];
  statsOneObj.PixelIdxList->size[0] = 0;
  emxEnsureCapacity_real_T1(&b_st, statsOneObj.PixelIdxList, i9, &sb_emlrtRTEI);
  c_st.site = &kd_emlrtRSI;
  d_st.site = &ld_emlrtRSI;
  assertValidSizeArg(&d_st, CC_NumObjects);
  i9 = outstats->size[0];
  outstats->size[0] = (int32_T)CC_NumObjects;
  emxEnsureCapacity_struct_T(&c_st, outstats, i9, &ed_emlrtRTEI);
  loop_ub = (int32_T)CC_NumObjects;
  for (i9 = 0; i9 < loop_ub; i9++) {
    emxCopyStruct_struct_T(&c_st, &outstats->data[i9], &statsOneObj,
      &ed_emlrtRTEI);
  }

  emxFreeStruct_struct_T(&statsOneObj);
  emxInit_struct_T2(&c_st, &stats, 1, &wb_emlrtRTEI, true);
  st.site = &ic_emlrtRSI;
  initializeStatsStruct(&st, CC_NumObjects, stats, &statsAlreadyComputed);
  st.site = &hc_emlrtRSI;
  ComputePixelIdxList(&st, CC_RegionIndices, CC_RegionLengths, CC_NumObjects,
                      stats, &statsAlreadyComputed);
  st.site = &gc_emlrtRSI;
  ComputeArea(&st, stats, &statsAlreadyComputed);
  st.site = &ec_emlrtRSI;
  ComputeEllipseParams(&st, CC_ImageSize, stats, &statsAlreadyComputed);
  st.site = &dc_emlrtRSI;
  k = 0;
  emxFree_int32_T(&CC_RegionLengths);
  emxFree_real_T(&CC_RegionIndices);
  while (k <= stats->size[0] - 1) {
    i9 = stats->size[0];
    loop_ub = k + 1;
    if (!((loop_ub >= 1) && (loop_ub <= i9))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i9, &sc_emlrtBCI, &st);
    }

    i9 = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i9, &rc_emlrtBCI, &st);
    }

    i9 = outstats->size[0];
    loop_ub = k + 1;
    if (!((loop_ub >= 1) && (loop_ub <= i9))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i9, &qc_emlrtBCI, &st);
    }

    i9 = stats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i9, &tc_emlrtBCI, &st);
    }

    i9 = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i9, &uc_emlrtBCI, &st);
    }

    outstats->data[k].Area = stats->data[k].Area;
    i9 = stats->size[0];
    loop_ub = k + 1;
    if (!((loop_ub >= 1) && (loop_ub <= i9))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i9, &sc_emlrtBCI, &st);
    }

    i9 = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i9, &rc_emlrtBCI, &st);
    }

    i9 = outstats->size[0];
    loop_ub = k + 1;
    if (!((loop_ub >= 1) && (loop_ub <= i9))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i9, &qc_emlrtBCI, &st);
    }

    i9 = stats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i9, &tc_emlrtBCI, &st);
    }

    i9 = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i9, &uc_emlrtBCI, &st);
    }

    outstats->data[k].Eccentricity = stats->data[k].Eccentricity;
    loop_ub = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= loop_ub))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, loop_ub, &vc_emlrtBCI, &st);
    }

    i9 = outstats->data[k].PixelIdxList->size[0];
    loop_ub = stats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= loop_ub))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, loop_ub, &wc_emlrtBCI, &st);
    }

    outstats->data[k].PixelIdxList->size[0] = stats->data[k].PixelIdxList->size
      [0];
    emxEnsureCapacity_real_T1(&st, outstats->data[k].PixelIdxList, i9,
      &fd_emlrtRTEI);
    i9 = outstats->size[0];
    loop_ub = k + 1;
    if (!((loop_ub >= 1) && (loop_ub <= i9))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i9, &qc_emlrtBCI, &st);
    }

    i9 = outstats->data[k].PixelIdxList->size[0];
    for (vIdx = 1; vIdx - 1 < i9; vIdx++) {
      loop_ub = stats->size[0];
      i10 = k + 1;
      if (!((i10 >= 1) && (i10 <= loop_ub))) {
        emlrtDynamicBoundsCheckR2012b(i10, 1, loop_ub, &pc_emlrtBCI, &st);
      }

      loop_ub = outstats->size[0];
      i10 = k + 1;
      if (!((i10 >= 1) && (i10 <= loop_ub))) {
        emlrtDynamicBoundsCheckR2012b(i10, 1, loop_ub, &oc_emlrtBCI, &st);
      }

      loop_ub = stats->data[k].PixelIdxList->size[0];
      if (!((vIdx >= 1) && (vIdx <= loop_ub))) {
        emlrtDynamicBoundsCheckR2012b(vIdx, 1, loop_ub, &tc_emlrtBCI, &st);
      }

      loop_ub = outstats->data[k].PixelIdxList->size[0];
      if (!((vIdx >= 1) && (vIdx <= loop_ub))) {
        emlrtDynamicBoundsCheckR2012b(vIdx, 1, loop_ub, &uc_emlrtBCI, &st);
      }

      outstats->data[k].PixelIdxList->data[vIdx - 1] = stats->data[k].
        PixelIdxList->data[vIdx - 1];
    }

    k++;
  }

  emxFree_struct_T2(&stats);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void regionprops(const emlrtStack *sp, const emxArray_boolean_T *varargin_2,
                 b_emxArray_struct_T *outstats)
{
  emxArray_real_T *CC_RegionIndices;
  emxArray_int32_T *CC_RegionLengths;
  c_struct_T statsOneObj;
  real_T expl_temp;
  real_T CC_ImageSize[2];
  real_T CC_NumObjects;
  int32_T i3;
  c_emxArray_struct_T *stats;
  struct_T statsAlreadyComputed;
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &CC_RegionIndices, 1, &vb_emlrtRTEI, true);
  emxInit_int32_T(sp, &CC_RegionLengths, 1, &vb_emlrtRTEI, true);
  emxInitStruct_struct_T1(sp, &statsOneObj, &xb_emlrtRTEI, true);
  st.site = &kc_emlrtRSI;
  bwconncomp(&st, varargin_2, &expl_temp, CC_ImageSize, &CC_NumObjects,
             CC_RegionIndices, CC_RegionLengths);
  st.site = &jc_emlrtRSI;
  b_st.site = &jd_emlrtRSI;
  statsOneObj.Orientation = 0.0;
  statsOneObj.Eccentricity = 0.0;
  statsOneObj.Area = 0.0;
  i3 = statsOneObj.PixelIdxList->size[0];
  statsOneObj.PixelIdxList->size[0] = 0;
  emxEnsureCapacity_real_T1(&b_st, statsOneObj.PixelIdxList, i3, &sb_emlrtRTEI);
  c_st.site = &kd_emlrtRSI;
  d_st.site = &ld_emlrtRSI;
  assertValidSizeArg(&d_st, CC_NumObjects);
  emxInit_struct_T2(&c_st, &stats, 1, &wb_emlrtRTEI, true);
  st.site = &ic_emlrtRSI;
  initializeStatsStruct(&st, CC_NumObjects, stats, &statsAlreadyComputed);
  st.site = &hc_emlrtRSI;
  ComputePixelIdxList(&st, CC_RegionIndices, CC_RegionLengths, CC_NumObjects,
                      stats, &statsAlreadyComputed);
  st.site = &fc_emlrtRSI;
  ComputeEllipseParams(&st, CC_ImageSize, stats, &statsAlreadyComputed);
  st.site = &ec_emlrtRSI;
  ComputeEllipseParams(&st, CC_ImageSize, stats, &statsAlreadyComputed);
  st.site = &gc_emlrtRSI;
  ComputeArea(&st, stats, &statsAlreadyComputed);
  i3 = outstats->size[0];
  outstats->size[0] = (int32_T)CC_NumObjects;
  emxEnsureCapacity_struct_T1(sp, outstats, i3, &tb_emlrtRTEI);
  loop_ub = (int32_T)CC_NumObjects;
  emxFree_int32_T(&CC_RegionLengths);
  emxFree_real_T(&CC_RegionIndices);
  for (i3 = 0; i3 < loop_ub; i3++) {
    emxCopyStruct_struct_T1(sp, &outstats->data[i3], &statsOneObj, &ub_emlrtRTEI);
  }

  emxFreeStruct_struct_T1(&statsOneObj);
  st.site = &dc_emlrtRSI;
  populateOutputStatsStructure(&st, outstats, stats);
  emxFree_struct_T2(&stats);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (regionprops.c) */
