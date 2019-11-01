/*
 * bh_my_detect_ALGORITHM_for_codegen.c
 *
 * Code generation for function 'bh_my_detect_ALGORITHM_for_codegen'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "box_info_CLS.h"
#include "lane_info_CLS.h"
#include "indexShapeCheck.h"
#include "sort1.h"
#include "regionprops.h"
#include "ybp_finder_CLS.h"
#include "bh_mask_fraction_of_BW_image.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static ybp_finder_CLS OBJ_ybp;
static boolean_T OBJ_ybp_not_empty;
static real_T fr_count;
static emlrtRSInfo emlrtRSI = { 31,    /* lineNo */
  "bh_my_detect_ALGORITHM_for_codegen",/* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_detect_ALGORITHM_for_codegen.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 33,  /* lineNo */
  "bh_my_detect_ALGORITHM_for_codegen",/* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_detect_ALGORITHM_for_codegen.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 193,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 198,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 206,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 207,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 208,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 145,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 146,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 149,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 150,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo of_emlrtRSI = { 176,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo pf_emlrtRSI = { 179,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 282,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo rf_emlrtRSI = { 296,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRSInfo sf_emlrtRSI = { 298,/* lineNo */
  "ybp_finder_CLS",                    /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 5,   /* lineNo */
  12,                                  /* colNo */
  "bh_my_detect_ALGORITHM_for_codegen",/* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_detect_ALGORITHM_for_codegen.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 21,/* lineNo */
  16,                                  /* colNo */
  "bh_my_detect_ALGORITHM_for_codegen",/* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_detect_ALGORITHM_for_codegen.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 1, /* lineNo */
  37,                                  /* colNo */
  "bh_my_detect_ALGORITHM_for_codegen",/* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_detect_ALGORITHM_for_codegen.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 140,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 141,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 282,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 291,/* lineNo */
  5,                                   /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 208,/* lineNo */
  16,                                  /* colNo */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  303,                                 /* lineNo */
  12,                                  /* colNo */
  "new_BW",                            /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  293,                                 /* lineNo */
  23,                                  /* colNo */
  "stats",                             /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  293,                                 /* lineNo */
  11,                                  /* colNo */
  "A",                                 /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  19,                                  /* colNo */
  "stats",                             /* aName */
  "ybp_finder_CLS",                    /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\ybp_finder_CLS.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */

/*
 * function [BLUE_s, YELL_s, PURP_s] = bh_my_detect_ALGORITHM_for_codegen(I, tf_do_init, marker_s)
 */
void bh_my_detect_ALGORITHM_for_codegen(const emlrtStack *sp, const uint8_T I
  [230400], boolean_T tf_do_init, const struct0_T *marker_s, struct1_T *BLUE_s,
  struct1_T *YELL_s, struct2_T *PURP_s)
{
  ybp_finder_CLS OBJ;
  emxArray_boolean_T *BW_blue;
  int32_T i0;
  int32_T loop_ub;
  emxArray_boolean_T *BW_yellow;
  emxArray_boolean_T *new_BW_blue;
  emxArray_boolean_T *new_BW_yell;
  boolean_T tf_found_b;
  boolean_T tf_found_y;
  int32_T R_max;
  int32_T i1;
  int16_T iv0[2];
  emxArray_struct_T *stats;
  boolean_T tf_found_purp_blob;
  emxArray_real_T *A;
  emxArray_boolean_T *BLUE_O_BW;
  emxArray_boolean_T *PURP_O_BW;
  box_info_CLS expl_temp;
  real_T BLUE_O_NUM_ROWS;
  real_T b_expl_temp;
  real_T BLUE_O_tip_upper_xy_col[2];
  real_T BLUE_O_tip_lower_xy_col[2];
  real_T BLUE_O_m;
  real_T BLUE_O_c;
  boolean_T BLUE_O_tf_is_detected;
  real_T YELL_O_NUM_ROWS;
  real_T YELL_O_tip_upper_xy_col[2];
  real_T YELL_O_tip_lower_xy_col[2];
  real_T YELL_O_m;
  real_T YELL_O_c;
  boolean_T YELL_O_tf_is_detected;
  emxArray_int32_T *iidx;
  emxArray_struct_T *b_stats;
  real_T PURP_O_left_edge_xy_col[2];
  real_T PURP_O_right_edge_xy_col[2];
  real_T PURP_O_centroid_xy_col[2];
  emxArray_int32_T *r0;
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

  /*  ALLOWED USAGE: */
  /*   >> [BLUE_s, YELL_s, PURP_s] = bh_my_detect_ALGORITHM_for_codegen(I, tf_do_init, marker_s) */
  /* 'bh_my_detect_ALGORITHM_for_codegen:10' if(isempty(fr_count)) */
  /*  ************************************************************************* */
  /*       do OBJECT INITIALIZATION */
  /*  ************************************************************************* */
  /* 'bh_my_detect_ALGORITHM_for_codegen:17' if(true==tf_do_init || isempty(OBJ_ybp) ) */
  if (tf_do_init || (!OBJ_ybp_not_empty)) {
    /* 'bh_my_detect_ALGORITHM_for_codegen:18' fr_count = 0; */
    fr_count = 0.0;

    /*  create an instance of the ybp finder */
    /* 'bh_my_detect_ALGORITHM_for_codegen:21' OBJ_ybp  = ybp_finder_CLS(marker_s); */
    i0 = OBJ_ybp.label->size[0] * OBJ_ybp.label->size[1];
    OBJ_ybp.label->size[0] = 0;
    OBJ_ybp.label->size[1] = 320;
    emxEnsureCapacity_real_T(sp, OBJ_ybp.label, i0, &b_emlrtRTEI);
    OBJ_ybp.E_tgt_for_lane = 0.8;
    OBJ_ybp.A_tgt_for_lane = 100.0;
    OBJ_ybp.fraction_of_img_to_ignore = 0.4;

    /* 'ybp_finder_CLS:46' if(1==nargin) */
    /* 'ybp_finder_CLS:47' tf_do_plots = false; */
    /* 'ybp_finder_CLS:50' OBJ.nColors       =  marker_s.nColors; */
    OBJ_ybp.nColors = marker_s->nColors;

    /* 'ybp_finder_CLS:51' OBJ.color_labels  =  marker_s.color_labels; */
    for (i0 = 0; i0 < 5; i0++) {
      OBJ_ybp.color_labels[i0] = marker_s->color_labels[i0];
    }

    /* 'ybp_finder_CLS:52' OBJ.color_markers =  marker_s.color_markers; */
    memcpy(&OBJ_ybp.color_markers[0], &marker_s->color_markers[0], 10U * sizeof
           (real_T));
    OBJ_ybp_not_empty = true;
  }

  emxInitStruct_ybp_finder_CLS(sp, &OBJ, &c_emlrtRTEI, true);
  emxInit_boolean_T(sp, &BW_blue, 2, &d_emlrtRTEI, true);

  /*  if(true==tf_do_init) */
  /*  update the frame counter */
  /* 'bh_my_detect_ALGORITHM_for_codegen:26' fr_count = fr_count + 1; */
  fr_count++;

  /*  ************************************************************************* */
  /*       CLASSIFY stuff */
  /*  ************************************************************************* */
  /* 'bh_my_detect_ALGORITHM_for_codegen:31' OBJ_ybp = OBJ_ybp.classify(I); */
  emxCopyStruct_ybp_finder_CLS(sp, &OBJ, &OBJ_ybp, &c_emlrtRTEI);
  st.site = &emlrtRSI;
  ybp_finder_CLS_classify(&st, &OBJ, I);
  emxCopyStruct_ybp_finder_CLS(sp, &OBJ_ybp, &OBJ, &c_emlrtRTEI);

  /* 'bh_my_detect_ALGORITHM_for_codegen:33' [ BLUE_s, YELL_s, PURP_s ] = OBJ_ybp.find_all_stuff(); */
  st.site = &b_emlrtRSI;

  /* 'ybp_finder_CLS:193' [ BW_b,                ... */
  /* 'ybp_finder_CLS:194'      BW_y,                ... */
  /* 'ybp_finder_CLS:195'      tf_found_b,          ... */
  /* 'ybp_finder_CLS:196'      tf_found_y] = OBJ.find_thin_lane_markings(); */
  b_st.site = &qb_emlrtRSI;

  /* 'ybp_finder_CLS:133' if(isempty(varargin) ) */
  /* 'ybp_finder_CLS:134' tf_do_plots = false; */
  /* 'ybp_finder_CLS:140' BW_blue   = OBJ.label == 0; */
  i0 = BW_blue->size[0] * BW_blue->size[1];
  BW_blue->size[0] = OBJ_ybp.label->size[0];
  BW_blue->size[1] = 320;
  emxEnsureCapacity_boolean_T(&b_st, BW_blue, i0, &c_emlrtRTEI);
  loop_ub = OBJ_ybp.label->size[0] * OBJ_ybp.label->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    BW_blue->data[i0] = (OBJ_ybp.label->data[i0] == 0.0);
  }

  emxInit_boolean_T(&b_st, &BW_yellow, 2, &e_emlrtRTEI, true);

  /* 'ybp_finder_CLS:141' BW_yellow = OBJ.label == 1; */
  i0 = BW_yellow->size[0] * BW_yellow->size[1];
  BW_yellow->size[0] = OBJ_ybp.label->size[0];
  BW_yellow->size[1] = 320;
  emxEnsureCapacity_boolean_T(&b_st, BW_yellow, i0, &c_emlrtRTEI);
  loop_ub = OBJ_ybp.label->size[0] * OBJ_ybp.label->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    BW_yellow->data[i0] = (OBJ_ybp.label->data[i0] == 1.0);
  }

  emxInit_boolean_T(&b_st, &new_BW_blue, 2, &c_emlrtRTEI, true);
  emxInit_boolean_T(&b_st, &new_BW_yell, 2, &c_emlrtRTEI, true);

  /* 'ybp_finder_CLS:144' THE_FRACT = OBJ.fraction_of_img_to_ignore; */
  /* 'ybp_finder_CLS:145' BW_blue   = bh_mask_fraction_of_BW_image(BW_blue,   THE_FRACT); */
  c_st.site = &vb_emlrtRSI;
  bh_mask_fraction_of_BW_image(&c_st, BW_blue);

  /* 'ybp_finder_CLS:146' BW_yellow = bh_mask_fraction_of_BW_image(BW_yellow, THE_FRACT); */
  c_st.site = &wb_emlrtRSI;
  bh_mask_fraction_of_BW_image(&c_st, BW_yellow);

  /* 'ybp_finder_CLS:149' [new_BW_blue, tf_found_blue_lane] = LOC_find_thin_lane_marking(OBJ, BW_blue); */
  c_st.site = &xb_emlrtRSI;
  LOC_find_thin_lane_marking(&c_st, BW_blue, new_BW_blue, &tf_found_b);

  /* 'ybp_finder_CLS:150' [new_BW_yell, tf_found_yell_lane] = LOC_find_thin_lane_marking(OBJ, BW_yellow); */
  c_st.site = &yb_emlrtRSI;
  LOC_find_thin_lane_marking(&c_st, BW_yellow, new_BW_yell, &tf_found_y);

  /* 'ybp_finder_CLS:152' if(1 ==coder.target('MATLAB') ) */
  /* 'ybp_finder_CLS:198' [ BW_p, tf_found_p] = OBJ.find_purp_boxes(); */
  b_st.site = &rb_emlrtRSI;

  /* 'ybp_finder_CLS:166' if(isempty(varargin) ) */
  /* 'ybp_finder_CLS:167' tf_do_plots = false; */
  /* 'ybp_finder_CLS:172' BW_purple   = OBJ.label == 2; */
  i0 = BW_blue->size[0] * BW_blue->size[1];
  BW_blue->size[0] = OBJ.label->size[0];
  BW_blue->size[1] = 320;
  emxEnsureCapacity_boolean_T(&b_st, BW_blue, i0, &c_emlrtRTEI);
  loop_ub = OBJ.label->size[0] * OBJ.label->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    BW_blue->data[i0] = (OBJ.label->data[i0] == 2.0);
  }

  emxFreeStruct_ybp_finder_CLS(&OBJ);

  /* 'ybp_finder_CLS:175' THE_FRACT = OBJ.fraction_of_img_to_ignore; */
  /* 'ybp_finder_CLS:176' BW_purple = bh_mask_fraction_of_BW_image(BW_purple, THE_FRACT); */
  c_st.site = &of_emlrtRSI;

  /*   [I, tf_was_applied] = bh_mask_fraction_of_BW_image(I_BW, the_frac) */
  /* -------------------------------------------------------------------------       */
  /*  Apply a mask of 0's to the first "N" rows of an image matrix */
  /*  where N is determined by the fraction scalar provided by the user */
  /*   */
  /*  When you view this masked image, the TOP portion of the image will appear blacked out */
  /*   */
  /*  EXAMPLE:     if our input image has 9 rows,  */
  /*               and if we set the_frac = 2/3  */
  /*                */
  /*               then the desired effect would look something like this: */
  /*   */
  /*              0-------------------------->  u, x */
  /*   row #1     | 0 0 0 0 0 0 0 0  */
  /*   row #2     | 0 0 0 0 0 0 0 0  */
  /*   row #3     | 0 0 0 0 0 0 0 0  */
  /*   row #4     | 0 0 0 0 0 0 0 0  */
  /*   row #5     | 0 0 0 0 0 0 0 0  */
  /*   row #6     | 0 0 0 0 0 0 0 0  */
  /*   row #7     | . . . . . . . .  */
  /*   row #8     | . . . . . . . .  */
  /*   row #9     | . . . . . . . .  */
  /*          v, y */
  /* -------------------------------------------------------------------------       */
  /* 'bh_mask_fraction_of_BW_image:27' if(1 ==coder.target('MATLAB') ) */
  /*  OK: now do your thing */
  /* 'bh_mask_fraction_of_BW_image:36' tf_was_applied = false; */
  /* 'bh_mask_fraction_of_BW_image:37' I              = I_BW; */
  /* 'bh_mask_fraction_of_BW_image:38' NUM_ROWS       = size(I,1); */
  /*  Mask the top portion of the image: */
  /* 'bh_mask_fraction_of_BW_image:41' R_max            = round(   NUM_ROWS * the_frac   ); */
  R_max = (int32_T)muDoubleScalarRound((real_T)BW_blue->size[0] * 0.4);

  /* 'bh_mask_fraction_of_BW_image:43' if(R_max == NUM_ROWS) */
  if ((R_max != BW_blue->size[0]) && (R_max > 1)) {
    /* 'bh_mask_fraction_of_BW_image:45' else */
    /* 'bh_mask_fraction_of_BW_image:46' if(R_max > 1) */
    /* 'bh_mask_fraction_of_BW_image:47' I(1:R_max, :)    = 0; */
    i0 = BW_blue->size[0];
    if (!(R_max <= i0)) {
      emlrtDynamicBoundsCheckR2012b(R_max, 1, i0, &emlrtBCI, &c_st);
    }

    for (i0 = 0; i0 < 320; i0++) {
      for (i1 = 0; i1 < R_max; i1++) {
        BW_blue->data[i1 + BW_blue->size[0] * i0] = false;
      }
    }

    /* 'bh_mask_fraction_of_BW_image:48' tf_was_applied   = true; */
    /* 'bh_mask_fraction_of_BW_image:49' masked_row_range = 1:R_max; */
  } else {
    /*  do nothing */
  }

  /*  bh_ignore_fraction_of_BW_image(I_BW, frac) */
  /* 'ybp_finder_CLS:179' [new_BW_purp, tf_found_purp_blob] = LOC_find_purp_boxes(OBJ, BW_purple); */
  c_st.site = &pf_emlrtRSI;

  /* 'ybp_finder_CLS:279' new_BW      = false( size(BW) ); */
  for (i0 = 0; i0 < 2; i0++) {
    iv0[i0] = (int16_T)BW_blue->size[i0];
  }

  i0 = BW_yellow->size[0] * BW_yellow->size[1];
  BW_yellow->size[0] = iv0[0];
  BW_yellow->size[1] = 320;
  emxEnsureCapacity_boolean_T(&c_st, BW_yellow, i0, &c_emlrtRTEI);
  loop_ub = iv0[0] * 320;
  for (i0 = 0; i0 < loop_ub; i0++) {
    BW_yellow->data[i0] = false;
  }

  emxInit_struct_T(&c_st, &stats, 1, &f_emlrtRTEI, true);

  /* 'ybp_finder_CLS:280' tf_found_it = false; */
  tf_found_purp_blob = false;

  /* 'ybp_finder_CLS:282' stats = regionprops( BW, 'Area','Eccentricity','PixelIdxList' ); */
  d_st.site = &qf_emlrtRSI;
  b_regionprops(&d_st, BW_blue, stats);

  /* 'ybp_finder_CLS:284' if( isempty(stats) ) */
  if (stats->size[0] != 0) {
    emxInit_real_T(&c_st, &A, 2, &g_emlrtRTEI, true);

    /* 'ybp_finder_CLS:291' A = zeros(1, length(stats)); */
    i0 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = stats->size[0];
    emxEnsureCapacity_real_T(&c_st, A, i0, &c_emlrtRTEI);
    loop_ub = stats->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      A->data[i0] = 0.0;
    }

    /* 'ybp_finder_CLS:292' for kk=1:length(stats) */
    R_max = 1;
    while (R_max - 1 <= stats->size[0] - 1) {
      /* 'ybp_finder_CLS:293' A(kk) = stats(kk).Area; */
      i0 = stats->size[0];
      if (!((R_max >= 1) && (R_max <= i0))) {
        emlrtDynamicBoundsCheckR2012b(R_max, 1, i0, &c_emlrtBCI, &c_st);
      }

      i0 = A->size[1];
      if (!((R_max >= 1) && (R_max <= i0))) {
        emlrtDynamicBoundsCheckR2012b(R_max, 1, i0, &d_emlrtBCI, &c_st);
      }

      A->data[R_max - 1] = stats->data[R_max - 1].Area;
      R_max++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&c_st);
      }
    }

    emxInit_int32_T1(&c_st, &iidx, 2, &c_emlrtRTEI, true);

    /* 'ybp_finder_CLS:296' [~,ind] = sort(A,'descend'); */
    d_st.site = &rf_emlrtRSI;
    e_st.site = &ne_emlrtRSI;
    sort(&e_st, A, iidx);
    i0 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = iidx->size[1];
    emxEnsureCapacity_real_T(&d_st, A, i0, &c_emlrtRTEI);
    loop_ub = iidx->size[0] * iidx->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      A->data[i0] = iidx->data[i0];
    }

    emxFree_int32_T(&iidx);
    emxInit_struct_T(&d_st, &b_stats, 1, &c_emlrtRTEI, true);

    /* 'ybp_finder_CLS:296' ~ */
    /* 'ybp_finder_CLS:298' stats = stats(ind); */
    d_st.site = &sf_emlrtRSI;
    b_indexShapeCheck(&d_st, stats->size[0], *(int32_T (*)[2])A->size);
    R_max = stats->size[0];
    i0 = b_stats->size[0];
    b_stats->size[0] = A->size[1];
    emxEnsureCapacity_struct_T(&c_st, b_stats, i0, &c_emlrtRTEI);
    loop_ub = A->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = (int32_T)A->data[A->size[0] * i0];
      if (!((i1 >= 1) && (i1 <= R_max))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, R_max, &e_emlrtBCI, &c_st);
      }

      emxCopyStruct_struct_T(&c_st, &b_stats->data[i0], &stats->data[i1 - 1],
        &c_emlrtRTEI);
    }

    emxFree_real_T(&A);
    i0 = stats->size[0];
    stats->size[0] = b_stats->size[0];
    emxEnsureCapacity_struct_T(&c_st, stats, i0, &c_emlrtRTEI);
    loop_ub = b_stats->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      emxCopyStruct_struct_T(&c_st, &stats->data[i0], &b_stats->data[i0],
        &c_emlrtRTEI);
    }

    emxFree_struct_T(&b_stats);
    emxInit_int32_T(&c_st, &r0, 1, &c_emlrtRTEI, true);

    /* 'ybp_finder_CLS:301' IND = 1; */
    /* 'ybp_finder_CLS:302' PixelIdxList = stats(IND).PixelIdxList; */
    /* 'ybp_finder_CLS:303' new_BW(PixelIdxList) = true; */
    i0 = iv0[0] * 320;
    i1 = r0->size[0];
    r0->size[0] = stats->data[0].PixelIdxList->size[0];
    emxEnsureCapacity_int32_T(&c_st, r0, i1, &c_emlrtRTEI);
    loop_ub = stats->data[0].PixelIdxList->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      R_max = (int32_T)stats->data[0].PixelIdxList->data[i1];
      if (!((R_max >= 1) && (R_max <= i0))) {
        emlrtDynamicBoundsCheckR2012b(R_max, 1, i0, &b_emlrtBCI, &c_st);
      }

      r0->data[i1] = R_max;
    }

    loop_ub = r0->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      BW_yellow->data[r0->data[i0] - 1] = true;
    }

    emxFree_int32_T(&r0);

    /* 'ybp_finder_CLS:304' tf_found_it          = true; */
    tf_found_purp_blob = true;
  }

  emxFree_struct_T(&stats);
  emxInit_boolean_T(&c_st, &BLUE_O_BW, 2, &c_emlrtRTEI, true);
  emxInit_boolean_T(&c_st, &PURP_O_BW, 2, &c_emlrtRTEI, true);
  emxInitStruct_box_info_CLS(&c_st, &expl_temp, &h_emlrtRTEI, true);

  /* 'ybp_finder_CLS:181' if(1 ==coder.target('MATLAB') ) */
  /* 'ybp_finder_CLS:201' if(1 ==coder.target('MATLAB') ) */
  /* 'ybp_finder_CLS:206' BLUE_O = lane_info_CLS(BW_b, tf_found_b); */
  b_st.site = &sb_emlrtRSI;
  lane_info_CLS_lane_info_CLS(&b_st, new_BW_blue, tf_found_b, BLUE_O_BW,
    &BLUE_O_NUM_ROWS, &b_expl_temp, BLUE_O_tip_upper_xy_col,
    BLUE_O_tip_lower_xy_col, &BLUE_O_m, &BLUE_O_c, &BLUE_O_tf_is_detected);

  /* 'ybp_finder_CLS:207' YELL_O = lane_info_CLS(BW_y, tf_found_y); */
  b_st.site = &tb_emlrtRSI;
  lane_info_CLS_lane_info_CLS(&b_st, new_BW_yell, tf_found_y, BW_blue,
    &YELL_O_NUM_ROWS, &b_expl_temp, YELL_O_tip_upper_xy_col,
    YELL_O_tip_lower_xy_col, &YELL_O_m, &YELL_O_c, &YELL_O_tf_is_detected);

  /* 'ybp_finder_CLS:208' PURP_O = box_info_CLS( BW_p, tf_found_p); */
  b_st.site = &ub_emlrtRSI;
  box_info_CLS_box_info_CLS(&b_st, BW_yellow, tf_found_purp_blob, &expl_temp);
  i0 = PURP_O_BW->size[0] * PURP_O_BW->size[1];
  PURP_O_BW->size[0] = expl_temp.BW->size[0];
  PURP_O_BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(&st, PURP_O_BW, i0, &c_emlrtRTEI);
  loop_ub = expl_temp.BW->size[0] * expl_temp.BW->size[1];
  emxFree_boolean_T(&new_BW_yell);
  emxFree_boolean_T(&new_BW_blue);
  emxFree_boolean_T(&BW_yellow);
  for (i0 = 0; i0 < loop_ub; i0++) {
    PURP_O_BW->data[i0] = expl_temp.BW->data[i0];
  }

  b_expl_temp = expl_temp.NUM_ROWS;
  for (R_max = 0; R_max < 2; R_max++) {
    PURP_O_left_edge_xy_col[R_max] = expl_temp.left_edge_xy_col[R_max];
    PURP_O_right_edge_xy_col[R_max] = expl_temp.right_edge_xy_col[R_max];
    PURP_O_centroid_xy_col[R_max] = expl_temp.centroid_xy_col[R_max];
  }

  tf_found_b = expl_temp.tf_is_detected;

  /* 'ybp_finder_CLS:210' BLUE_s   = BLUE_O.convert_to_struct(); */
  /* --------------------------------------------------------------------------   */
  /*  ATTENTION(R2017b): */
  /*  the following usage is NOT supported by the MATLAB Coder: */
  /*    >> struct(OBJ) */
  /* 'lane_info_CLS:101' my_S.BW               = OBJ.BW; */
  i0 = BLUE_s->BW->size[0] * BLUE_s->BW->size[1];
  BLUE_s->BW->size[0] = BLUE_O_BW->size[0];
  BLUE_s->BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(&st, BLUE_s->BW, i0, &c_emlrtRTEI);
  loop_ub = BLUE_O_BW->size[0] * BLUE_O_BW->size[1];
  emxFreeStruct_box_info_CLS(&expl_temp);
  for (i0 = 0; i0 < loop_ub; i0++) {
    BLUE_s->BW->data[i0] = BLUE_O_BW->data[i0];
  }

  emxFree_boolean_T(&BLUE_O_BW);

  /* 'lane_info_CLS:102' my_S.NUM_ROWS         = OBJ.NUM_ROWS; */
  BLUE_s->NUM_ROWS = BLUE_O_NUM_ROWS;

  /* 'lane_info_CLS:103' my_S.NUM_COLS         = OBJ.NUM_COLS; */
  BLUE_s->NUM_COLS = 320.0;

  /* 'lane_info_CLS:104' my_S.tip_upper_xy_col = OBJ.tip_upper_xy_col; */
  for (R_max = 0; R_max < 2; R_max++) {
    BLUE_s->tip_upper_xy_col[R_max] = BLUE_O_tip_upper_xy_col[R_max];
  }

  /* 'lane_info_CLS:105' my_S.tip_lower_xy_col = OBJ.tip_lower_xy_col; */
  for (R_max = 0; R_max < 2; R_max++) {
    BLUE_s->tip_lower_xy_col[R_max] = BLUE_O_tip_lower_xy_col[R_max];
  }

  /* 'lane_info_CLS:106' my_S.m                = OBJ.m; */
  BLUE_s->m = BLUE_O_m;

  /* 'lane_info_CLS:107' my_S.c                = OBJ.c; */
  BLUE_s->c = BLUE_O_c;

  /* 'lane_info_CLS:108' my_S.tf_is_detected   = OBJ.tf_is_detected; */
  BLUE_s->tf_is_detected = BLUE_O_tf_is_detected;

  /* --------------------------------------------------------------------------   */
  /*  methods() */
  /* _######################################################################### */
  /*  classdef() */
  /* _######################################################################### */
  /*  END CLASSDEF */
  /* _######################################################################### */
  /* 'ybp_finder_CLS:211' YELLOW_s = YELL_O.convert_to_struct(); */
  /* --------------------------------------------------------------------------   */
  /*  ATTENTION(R2017b): */
  /*  the following usage is NOT supported by the MATLAB Coder: */
  /*    >> struct(OBJ) */
  /* 'lane_info_CLS:101' my_S.BW               = OBJ.BW; */
  i0 = YELL_s->BW->size[0] * YELL_s->BW->size[1];
  YELL_s->BW->size[0] = BW_blue->size[0];
  YELL_s->BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(&st, YELL_s->BW, i0, &c_emlrtRTEI);
  loop_ub = BW_blue->size[0] * BW_blue->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    YELL_s->BW->data[i0] = BW_blue->data[i0];
  }

  emxFree_boolean_T(&BW_blue);

  /* 'lane_info_CLS:102' my_S.NUM_ROWS         = OBJ.NUM_ROWS; */
  YELL_s->NUM_ROWS = YELL_O_NUM_ROWS;

  /* 'lane_info_CLS:103' my_S.NUM_COLS         = OBJ.NUM_COLS; */
  YELL_s->NUM_COLS = 320.0;

  /* 'lane_info_CLS:104' my_S.tip_upper_xy_col = OBJ.tip_upper_xy_col; */
  for (R_max = 0; R_max < 2; R_max++) {
    YELL_s->tip_upper_xy_col[R_max] = YELL_O_tip_upper_xy_col[R_max];
  }

  /* 'lane_info_CLS:105' my_S.tip_lower_xy_col = OBJ.tip_lower_xy_col; */
  for (R_max = 0; R_max < 2; R_max++) {
    YELL_s->tip_lower_xy_col[R_max] = YELL_O_tip_lower_xy_col[R_max];
  }

  /* 'lane_info_CLS:106' my_S.m                = OBJ.m; */
  YELL_s->m = YELL_O_m;

  /* 'lane_info_CLS:107' my_S.c                = OBJ.c; */
  YELL_s->c = YELL_O_c;

  /* 'lane_info_CLS:108' my_S.tf_is_detected   = OBJ.tf_is_detected; */
  YELL_s->tf_is_detected = YELL_O_tf_is_detected;

  /* --------------------------------------------------------------------------   */
  /*  methods() */
  /* _######################################################################### */
  /*  classdef() */
  /* _######################################################################### */
  /*  END CLASSDEF */
  /* _######################################################################### */
  /* 'ybp_finder_CLS:212' PURP_s   = PURP_O.convert_to_struct(); */
  /*  get_xy() */
  /* --------------------------------------------------------------------------   */
  /*  ATTENTION(R2017b): */
  /*  the following usage is NOT supported by the MATLAB Coder: */
  /*    >> struct(OBJ) */
  /* 'box_info_CLS:90' my_S.BW                = OBJ.BW; */
  i0 = PURP_s->BW->size[0] * PURP_s->BW->size[1];
  PURP_s->BW->size[0] = PURP_O_BW->size[0];
  PURP_s->BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(&st, PURP_s->BW, i0, &c_emlrtRTEI);
  loop_ub = PURP_O_BW->size[0] * PURP_O_BW->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    PURP_s->BW->data[i0] = PURP_O_BW->data[i0];
  }

  emxFree_boolean_T(&PURP_O_BW);

  /* 'box_info_CLS:91' my_S.NUM_ROWS          = OBJ.NUM_ROWS; */
  PURP_s->NUM_ROWS = b_expl_temp;

  /* 'box_info_CLS:92' my_S.NUM_COLS          = OBJ.NUM_COLS; */
  PURP_s->NUM_COLS = 320.0;

  /* 'box_info_CLS:93' my_S.left_edge_xy_col  = OBJ.left_edge_xy_col; */
  for (R_max = 0; R_max < 2; R_max++) {
    PURP_s->left_edge_xy_col[R_max] = PURP_O_left_edge_xy_col[R_max];
  }

  /* 'box_info_CLS:94' my_S.right_edge_xy_col = OBJ.right_edge_xy_col; */
  for (R_max = 0; R_max < 2; R_max++) {
    PURP_s->right_edge_xy_col[R_max] = PURP_O_right_edge_xy_col[R_max];
  }

  /* 'box_info_CLS:95' my_S.centroid_xy_col   = OBJ.centroid_xy_col; */
  for (R_max = 0; R_max < 2; R_max++) {
    PURP_s->centroid_xy_col[R_max] = PURP_O_centroid_xy_col[R_max];
  }

  /* 'box_info_CLS:96' my_S.tf_is_detected    = OBJ.tf_is_detected; */
  PURP_s->tf_is_detected = tf_found_b;

  /* --------------------------------------------------------------------------   */
  /*  methods() */
  /* _######################################################################### */
  /*  classdef() */
  /* _######################################################################### */
  /*  END CLASSDEF */
  /* _######################################################################### */
  /*  bh_roipoly() */
  /* -------------------------------------------------------------------------- */
  /*  ************************************************************************* */
  /*       VISUALIZE  stuff */
  /*  ************************************************************************* */
  /* 'bh_my_detect_ALGORITHM_for_codegen:39' if(1 ==coder.target('MATLAB') ) */
  /*  bh_my_ALGORITHM_for_codegen(I) */
  /* -######################################################################### */
  /*  E N D    O F    M A I N    F U N C T I O N */
  /* -######################################################################### */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void d_bh_my_detect_ALGORITHM_for_co(const emlrtStack *sp)
{
  emxInitStruct_ybp_finder_CLS(sp, &OBJ_ybp, &emlrtRTEI, false);
  OBJ_ybp_not_empty = false;

  /* 'bh_my_detect_ALGORITHM_for_codegen:11' fr_count = 0; */
  fr_count = 0.0;
}

void e_bh_my_detect_ALGORITHM_for_co(void)
{
  emxFreeStruct_ybp_finder_CLS(&OBJ_ybp);
}

void fr_count_not_empty_init(void)
{
}

/* End of code generation (bh_my_detect_ALGORITHM_for_codegen.c) */
