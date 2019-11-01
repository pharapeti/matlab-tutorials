/*
 * bh_my_lane_preprocess_mask.c
 *
 * Code generation for function 'bh_my_lane_preprocess_mask'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_emxutil.h"
#include "lane_info_CLS.h"
#include "ind2sub.h"
#include "find.h"
#include "bh_mask_fraction_of_BW_image.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Variable Definitions */
static emlrtRSInfo wd_emlrtRSI = { 13, /* lineNo */
  "max",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo wk_emlrtRSI = { 4,  /* lineNo */
  "bh_my_lane_preprocess_mask",        /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pathName */
};

static emlrtRSInfo xk_emlrtRSI = { 5,  /* lineNo */
  "bh_my_lane_preprocess_mask",        /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pathName */
};

static emlrtRSInfo yk_emlrtRSI = { 11, /* lineNo */
  "bh_my_lane_preprocess_mask",        /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pathName */
};

static emlrtRSInfo al_emlrtRSI = { 13, /* lineNo */
  "bh_my_lane_preprocess_mask",        /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pathName */
};

static emlrtRSInfo bl_emlrtRSI = { 14, /* lineNo */
  "bh_my_lane_preprocess_mask",        /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pathName */
};

static emlrtRSInfo cl_emlrtRSI = { 22, /* lineNo */
  "bh_my_lane_preprocess_mask",        /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pathName */
};

static emlrtRSInfo dl_emlrtRSI = { 24, /* lineNo */
  "bh_my_lane_preprocess_mask",        /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pathName */
};

static emlrtRSInfo el_emlrtRSI = { 25, /* lineNo */
  "bh_my_lane_preprocess_mask",        /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pathName */
};

static emlrtRSInfo fl_emlrtRSI = { 39, /* lineNo */
  "bh_my_lane_preprocess_mask",        /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pathName */
};

static emlrtRSInfo gl_emlrtRSI = { 40, /* lineNo */
  "bh_my_lane_preprocess_mask",        /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pathName */
};

static emlrtRSInfo hl_emlrtRSI = { 33, /* lineNo */
  "bh_my_lane_preprocess_mask",        /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pathName */
};

static emlrtRSInfo il_emlrtRSI = { 34, /* lineNo */
  "bh_my_lane_preprocess_mask",        /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pathName */
};

static emlrtRTEInfo wd_emlrtRTEI = { 11,/* lineNo */
  5,                                   /* colNo */
  "bh_my_lane_preprocess_mask",        /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = { 22,/* lineNo */
  5,                                   /* colNo */
  "bh_my_lane_preprocess_mask",        /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = { 2,/* lineNo */
  5,                                   /* colNo */
  "bh_my_lane_preprocess_mask",        /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_lane_preprocess_mask.m"/* pName */
};

/* Function Definitions */
void bh_my_lane_preprocess_mask(g_bh_my_detect_ALGORITHM_for_co *SD, const
  emlrtStack *sp, const struct3_T *BLUE_s, const struct3_T *YELL_s, real_T
  fract_for_top_mask, struct3_T *BLUE_out_s, struct3_T *YELL_out_s)
{
  boolean_T new_BLUE_BW[76800];
  boolean_T tf_is_detected_BLUE;
  real_T mask_Rmax;
  boolean_T new_YELL_BW[76800];
  emxArray_real_T *the_ind;
  emxArray_int32_T *ii;
  boolean_T tf_is_detected_YELL;
  int32_T ix;
  int32_T loop_ub;
  emxArray_int32_T *varargout_4;
  boolean_T b4;
  real_T vlim[2];
  int32_T n;
  int32_T mtmp;
  int32_T b_mtmp;
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
  memcpy(&new_BLUE_BW[0], &BLUE_s->BW[0], 76800U * sizeof(boolean_T));
  st.site = &wk_emlrtRSI;
  b_bh_mask_fraction_of_BW_image(&st, new_BLUE_BW, fract_for_top_mask,
    &tf_is_detected_BLUE, &mask_Rmax);
  memcpy(&new_YELL_BW[0], &YELL_s->BW[0], 76800U * sizeof(boolean_T));
  emxInit_real_T1(sp, &the_ind, 1, &wd_emlrtRTEI, true);
  emxInit_int32_T(sp, &ii, 1, &rb_emlrtRTEI, true);
  st.site = &xk_emlrtRSI;
  c_bh_mask_fraction_of_BW_image(&st, new_YELL_BW, fract_for_top_mask);
  tf_is_detected_BLUE = false;
  tf_is_detected_YELL = false;

  /*  can we detect BLUE things */
  st.site = &yk_emlrtRSI;
  b_st.site = &of_emlrtRSI;
  c_eml_find(&b_st, new_BLUE_BW, ii);
  ix = the_ind->size[0];
  the_ind->size[0] = ii->size[0];
  emxEnsureCapacity_real_T1(&st, the_ind, ix, &wd_emlrtRTEI);
  loop_ub = ii->size[0];
  for (ix = 0; ix < loop_ub; ix++) {
    the_ind->data[ix] = ii->data[ix];
  }

  emxInit_int32_T(sp, &varargout_4, 1, &ae_emlrtRTEI, true);
  if (!(the_ind->size[0] == 0)) {
    st.site = &al_emlrtRSI;
    b_st.site = &rd_emlrtRSI;
    ind2sub_indexClass(&b_st, the_ind, ii, varargout_4);
    ix = the_ind->size[0];
    the_ind->size[0] = ii->size[0];
    emxEnsureCapacity_real_T1(&st, the_ind, ix, &xd_emlrtRTEI);
    loop_ub = ii->size[0];
    for (ix = 0; ix < loop_ub; ix++) {
      the_ind->data[ix] = ii->data[ix];
    }

    /*  convert INDS to SUBSCRIPTS */
    st.site = &bl_emlrtRSI;
    b_st.site = &wd_emlrtRSI;
    c_st.site = &vd_emlrtRSI;
    if ((the_ind->size[0] == 1) || (the_ind->size[0] != 1)) {
      b4 = true;
    } else {
      b4 = false;
    }

    if (!b4) {
      emlrtErrorWithMessageIdR2012b(&c_st, &fg_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(the_ind->size[0] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &eg_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    n = the_ind->size[0];
    mtmp = (int32_T)the_ind->data[0];
    if ((the_ind->size[0] > 1) && (1 < the_ind->size[0])) {
      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int32_T)the_ind->data[ix] > mtmp) {
          mtmp = (int32_T)the_ind->data[ix];
        }
      }
    }

    st.site = &bl_emlrtRSI;
    b_st.site = &ud_emlrtRSI;
    c_st.site = &vd_emlrtRSI;
    if ((the_ind->size[0] == 1) || (the_ind->size[0] != 1)) {
      b4 = true;
    } else {
      b4 = false;
    }

    if (!b4) {
      emlrtErrorWithMessageIdR2012b(&c_st, &fg_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(the_ind->size[0] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &eg_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    n = the_ind->size[0];
    b_mtmp = (int32_T)the_ind->data[0];
    if ((the_ind->size[0] > 1) && (1 < the_ind->size[0])) {
      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int32_T)the_ind->data[ix] < b_mtmp) {
          b_mtmp = (int32_T)the_ind->data[ix];
        }
      }
    }

    n = 0;
    for (loop_ub = 0; loop_ub < 76800; loop_ub++) {
      if (new_BLUE_BW[loop_ub]) {
        n++;
      }
    }

    if ((n > 2) && ((real_T)mtmp - (real_T)b_mtmp > 10.0)) {
      tf_is_detected_BLUE = true;
    }
  }

  /*  can we detect YELLOW things */
  st.site = &cl_emlrtRSI;
  b_st.site = &of_emlrtRSI;
  c_eml_find(&b_st, new_YELL_BW, ii);
  ix = the_ind->size[0];
  the_ind->size[0] = ii->size[0];
  emxEnsureCapacity_real_T1(&st, the_ind, ix, &yd_emlrtRTEI);
  loop_ub = ii->size[0];
  for (ix = 0; ix < loop_ub; ix++) {
    the_ind->data[ix] = ii->data[ix];
  }

  if (!(the_ind->size[0] == 0)) {
    st.site = &dl_emlrtRSI;
    b_st.site = &rd_emlrtRSI;
    ind2sub_indexClass(&b_st, the_ind, ii, varargout_4);
    ix = the_ind->size[0];
    the_ind->size[0] = ii->size[0];
    emxEnsureCapacity_real_T1(&st, the_ind, ix, &xd_emlrtRTEI);
    loop_ub = ii->size[0];
    for (ix = 0; ix < loop_ub; ix++) {
      the_ind->data[ix] = ii->data[ix];
    }

    /*  convert INDS to SUBSCRIPTS */
    st.site = &el_emlrtRSI;
    b_st.site = &wd_emlrtRSI;
    c_st.site = &vd_emlrtRSI;
    if ((the_ind->size[0] == 1) || (the_ind->size[0] != 1)) {
      b4 = true;
    } else {
      b4 = false;
    }

    if (!b4) {
      emlrtErrorWithMessageIdR2012b(&c_st, &fg_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(the_ind->size[0] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &eg_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    n = the_ind->size[0];
    mtmp = (int32_T)the_ind->data[0];
    if ((the_ind->size[0] > 1) && (1 < the_ind->size[0])) {
      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int32_T)the_ind->data[ix] > mtmp) {
          mtmp = (int32_T)the_ind->data[ix];
        }
      }
    }

    st.site = &el_emlrtRSI;
    b_st.site = &ud_emlrtRSI;
    c_st.site = &vd_emlrtRSI;
    if ((the_ind->size[0] == 1) || (the_ind->size[0] != 1)) {
      b4 = true;
    } else {
      b4 = false;
    }

    if (!b4) {
      emlrtErrorWithMessageIdR2012b(&c_st, &fg_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(the_ind->size[0] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &eg_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    n = the_ind->size[0];
    b_mtmp = (int32_T)the_ind->data[0];
    if ((the_ind->size[0] > 1) && (1 < the_ind->size[0])) {
      for (ix = 1; ix + 1 <= n; ix++) {
        if ((int32_T)the_ind->data[ix] < b_mtmp) {
          b_mtmp = (int32_T)the_ind->data[ix];
        }
      }
    }

    n = 0;
    for (loop_ub = 0; loop_ub < 76800; loop_ub++) {
      if (new_YELL_BW[loop_ub]) {
        n++;
      }
    }

    if ((n > 2) && ((real_T)mtmp - (real_T)b_mtmp > 10.0)) {
      tf_is_detected_YELL = true;
    }
  }

  emxFree_int32_T(&varargout_4);
  emxFree_int32_T(&ii);
  emxFree_real_T(&the_ind);

  /*  create Lane info objects */
  st.site = &hl_emlrtRSI;
  b_lane_info_CLS_lane_info_CLS(&st, new_BLUE_BW, tf_is_detected_BLUE,
    &SD->u1.f0.BLUE_O);
  st.site = &il_emlrtRSI;
  b_lane_info_CLS_lane_info_CLS(&st, new_YELL_BW, tf_is_detected_YELL,
    &SD->u1.f0.YELL_O);
  vlim[0] = mask_Rmax + 1.0;
  vlim[1] = 240.0;
  st.site = &fl_emlrtRSI;
  b_lane_info_CLS_calc_info(&st, &SD->u1.f0.BLUE_O, vlim);
  st.site = &gl_emlrtRSI;
  b_lane_info_CLS_calc_info(&st, &SD->u1.f0.YELL_O, vlim);

  /*  take care of the outputs */
  lane_info_CLS_convert_to_struct(SD->u1.f0.BLUE_O.BW,
    SD->u1.f0.BLUE_O.tip_upper_xy_col, SD->u1.f0.BLUE_O.tip_lower_xy_col,
    SD->u1.f0.BLUE_O.m, SD->u1.f0.BLUE_O.c, SD->u1.f0.BLUE_O.tf_is_detected,
    BLUE_out_s->BW, &BLUE_out_s->NUM_ROWS, &BLUE_out_s->NUM_COLS,
    BLUE_out_s->tip_upper_xy_col, BLUE_out_s->tip_lower_xy_col, &BLUE_out_s->m,
    &BLUE_out_s->c, &BLUE_out_s->tf_is_detected);
  lane_info_CLS_convert_to_struct(SD->u1.f0.YELL_O.BW,
    SD->u1.f0.YELL_O.tip_upper_xy_col, SD->u1.f0.YELL_O.tip_lower_xy_col,
    SD->u1.f0.YELL_O.m, SD->u1.f0.YELL_O.c, SD->u1.f0.YELL_O.tf_is_detected,
    YELL_out_s->BW, &YELL_out_s->NUM_ROWS, &YELL_out_s->NUM_COLS,
    YELL_out_s->tip_upper_xy_col, YELL_out_s->tip_lower_xy_col, &YELL_out_s->m,
    &YELL_out_s->c, &YELL_out_s->tf_is_detected);

  /* -######################################################################### */
  /*  E N D    O F    M A I N    F U N C T I O N */
  /* -######################################################################### */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (bh_my_lane_preprocess_mask.c) */
