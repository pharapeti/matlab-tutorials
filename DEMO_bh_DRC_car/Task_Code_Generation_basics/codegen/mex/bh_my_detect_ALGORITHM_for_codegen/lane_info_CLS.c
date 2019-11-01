/*
 * lane_info_CLS.c
 *
 * Code generation for function 'lane_info_CLS'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "lane_info_CLS.h"
#include "box_info_CLS.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "bh_line_homog_CLS.h"
#include "find.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mexutil.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRSInfo uf_emlrtRSI = { 30, /* lineNo */
  "lane_info_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\lane_info_CLS.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 49, /* lineNo */
  "lane_info_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\lane_info_CLS.m"/* pathName */
};

static emlrtRSInfo wf_emlrtRSI = { 50, /* lineNo */
  "lane_info_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\lane_info_CLS.m"/* pathName */
};

static emlrtRSInfo xf_emlrtRSI = { 55, /* lineNo */
  "lane_info_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\lane_info_CLS.m"/* pathName */
};

static emlrtRSInfo yf_emlrtRSI = { 53, /* lineNo */
  "lane_info_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\lane_info_CLS.m"/* pathName */
};

static emlrtRTEInfo gd_emlrtRTEI = { 22,/* lineNo */
  10,                                  /* colNo */
  "lane_info_CLS",                     /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\lane_info_CLS.m"/* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = { 50,/* lineNo */
  7,                                   /* colNo */
  "lane_info_CLS",                     /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\lane_info_CLS.m"/* pName */
};

static emlrtRTEInfo md_emlrtRTEI = { 50,/* lineNo */
  5,                                   /* colNo */
  "lane_info_CLS",                     /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\lane_info_CLS.m"/* pName */
};

/* Function Definitions */
void lane_info_CLS_lane_info_CLS(const emlrtStack *sp, const emxArray_boolean_T *
  BW, boolean_T tf_found, emxArray_boolean_T *OBJ_BW, real_T *OBJ_NUM_ROWS,
  real_T *OBJ_NUM_COLS, real_T OBJ_tip_upper_xy_col[2], real_T
  OBJ_tip_lower_xy_col[2], real_T *OBJ_m, real_T *OBJ_c, boolean_T
  *OBJ_tf_is_detected)
{
  int32_T i;
  real_T b_OBJ_m;
  real_T b_OBJ_c;
  int32_T loop_ub;
  int32_T b_OBJ_NUM_ROWS;
  emxArray_int32_T *ii;
  emxArray_int32_T *idx;
  real_T the_size[2];
  int16_T BW_idx_0;
  int32_T exitg1;
  boolean_T p;
  emxArray_int32_T *vk;
  emxArray_real_T *b_vk;
  emxArray_real_T *b_idx;
  real_T LO_OBJ_d;
  char_T LO_OBJ_line_type_data[6];
  int32_T LO_OBJ_line_type_size[2];
  real_T dv0[2];
  real_T uv_top[2];
  real_T mc_col[2];
  static const char_T cv0[6] = { 'S', 'L', 'O', 'P', 'E', 'Y' };

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
  for (i = 0; i < 2; i++) {
    OBJ_tip_upper_xy_col[i] = 0.0;
  }

  for (i = 0; i < 2; i++) {
    OBJ_tip_lower_xy_col[i] = 0.0;
  }

  b_OBJ_m = 0.0;
  b_OBJ_c = 0.0;

  /*  ATTENTION: */
  /*  I want this class to be MATLAB CODER friendly, hence I have prepopulated */
  /*  some properties with NaNs */
  /* --------------------------------- */
  /*  closest to TOP of image */
  /*  closest to BOTTOM of image */
  /* fh_line; */
  /* --------------------------------- */
  /* _######################################################################### */
  i = OBJ_BW->size[0] * OBJ_BW->size[1];
  OBJ_BW->size[0] = BW->size[0];
  OBJ_BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(sp, OBJ_BW, i, &gd_emlrtRTEI);
  loop_ub = BW->size[0] * BW->size[1];
  for (i = 0; i < loop_ub; i++) {
    OBJ_BW->data[i] = BW->data[i];
  }

  b_OBJ_NUM_ROWS = BW->size[0];
  st.site = &uf_emlrtRSI;

  /*  is_detected() */
  /* --------------------------------------------------------------------------  */
  /* --------------------------------------------------------------------------   */
  if (tf_found) {
    emxInit_int32_T(&st, &ii, 1, &rb_emlrtRTEI, true);
    emxInit_int32_T(&st, &idx, 1, &hd_emlrtRTEI, true);

    /*  OK: if we're here we have a lane */
    the_size[0] = BW->size[0];
    b_st.site = &vf_emlrtRSI;
    c_st.site = &mf_emlrtRSI;
    eml_find(&c_st, BW, ii);
    b_st.site = &wf_emlrtRSI;
    c_st.site = &qd_emlrtRSI;
    i = idx->size[0];
    idx->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&c_st, idx, i, &hd_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      idx->data[i] = ii->data[i];
    }

    emxFree_int32_T(&ii);
    BW_idx_0 = (int16_T)BW->size[0];
    i = (int16_T)the_size[0] * 320;
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub <= idx->size[0] - 1) {
        if ((idx->data[loop_ub] >= 1) && (idx->data[loop_ub] <= i)) {
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
      emlrtErrorWithMessageIdR2012b(&c_st, &uf_emlrtRTEI,
        "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
    }

    i = idx->size[0];
    emxEnsureCapacity_int32_T(&c_st, idx, i, &id_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i = 0; i < loop_ub; i++) {
      idx->data[i]--;
    }

    emxInit_int32_T(&c_st, &vk, 1, &jd_emlrtRTEI, true);
    i = vk->size[0];
    vk->size[0] = idx->size[0];
    emxEnsureCapacity_int32_T(&c_st, vk, i, &jd_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i = 0; i < loop_ub; i++) {
      d_st.site = &wk_emlrtRSI;
      vk->data[i] = div_s32(&d_st, idx->data[i], (int16_T)the_size[0]);
    }

    i = idx->size[0];
    emxEnsureCapacity_int32_T(&c_st, idx, i, &kd_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i = 0; i < loop_ub; i++) {
      idx->data[i] -= vk->data[i] * BW_idx_0;
    }

    emxInit_real_T1(&c_st, &b_vk, 1, &ld_emlrtRTEI, true);

    /*  convert INDS to SUBSCRIPTS */
    /*  create a homogenous line object */
    i = b_vk->size[0];
    b_vk->size[0] = vk->size[0];
    emxEnsureCapacity_real_T1(&st, b_vk, i, &ld_emlrtRTEI);
    loop_ub = vk->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_vk->data[i] = vk->data[i] + 1;
    }

    emxFree_int32_T(&vk);
    emxInit_real_T1(&st, &b_idx, 1, &md_emlrtRTEI, true);
    i = b_idx->size[0];
    b_idx->size[0] = idx->size[0];
    emxEnsureCapacity_real_T1(&st, b_idx, i, &md_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_idx->data[i] = idx->data[i] + 1;
    }

    emxFree_int32_T(&idx);
    b_st.site = &yf_emlrtRSI;
    c_bh_line_homog_CLS_bh_line_hom(&b_st, b_vk, b_idx, &b_OBJ_m, &b_OBJ_c,
      &LO_OBJ_d, LO_OBJ_line_type_data, LO_OBJ_line_type_size);
    emxFree_real_T(&b_idx);
    emxFree_real_T(&b_vk);
    dv0[0] = 1.0;
    dv0[1] = BW->size[0];
    b_st.site = &xf_emlrtRSI;
    c_bh_line_homog_CLS_get_roi_int(&b_st, b_OBJ_m, b_OBJ_c, LO_OBJ_d,
      LO_OBJ_line_type_data, LO_OBJ_line_type_size, dv0, &p, the_size, uv_top);

    /*  take care of the OUTPUTS */
    for (i = 0; i < 2; i++) {
      OBJ_tip_upper_xy_col[i] = uv_top[i];
    }

    for (i = 0; i < 2; i++) {
      OBJ_tip_lower_xy_col[i] = the_size[i];
    }

    /*  get equation of the line */
    /*  :  y = mx + c */
    p = false;
    if (LO_OBJ_line_type_size[1] == 6) {
      i = 0;
      do {
        exitg1 = 0;
        if (i + 1 < 7) {
          if (LO_OBJ_line_type_data[i] != cv0[i]) {
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          p = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (p) {
      mc_col[0] = -b_OBJ_m / b_OBJ_c;
      mc_col[1] = -LO_OBJ_d / b_OBJ_c;
    } else {
      for (i = 0; i < 2; i++) {
        mc_col[i] = rtNaN;
      }
    }

    /* LOC_get_side_intersect_point */
    /* ========================================================================== */
    /* OBJ.fh_line = @(x) (m*x + c); */
    b_OBJ_m = mc_col[0];
    b_OBJ_c = mc_col[1];
  }

  *OBJ_NUM_ROWS = b_OBJ_NUM_ROWS;
  *OBJ_NUM_COLS = 320.0;
  *OBJ_m = b_OBJ_m;
  *OBJ_c = b_OBJ_c;
  *OBJ_tf_is_detected = tf_found;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (lane_info_CLS.c) */
