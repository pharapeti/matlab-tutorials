/*
 * lane_info_CLS.c
 *
 * Code generation for function 'lane_info_CLS'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "lane_info_CLS.h"
#include "box_info_CLS.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_emxutil.h"
#include "bh_line_homog_CLS.h"
#include "ind2sub.h"
#include "find.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_mexutil.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Variable Definitions */
static emlrtRSInfo wf_emlrtRSI = { 30, /* lineNo */
  "lane_info_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\lane_info_CLS.m"/* pathName */
};

static emlrtRSInfo xf_emlrtRSI = { 49, /* lineNo */
  "lane_info_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\lane_info_CLS.m"/* pathName */
};

static emlrtRSInfo yf_emlrtRSI = { 50, /* lineNo */
  "lane_info_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\lane_info_CLS.m"/* pathName */
};

static emlrtRSInfo ag_emlrtRSI = { 55, /* lineNo */
  "lane_info_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\lane_info_CLS.m"/* pathName */
};

static emlrtRSInfo bg_emlrtRSI = { 53, /* lineNo */
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
void b_lane_info_CLS_calc_info(const emlrtStack *sp, lane_info_CLS_1 *OBJ, const
  real_T vlim[2])
{
  emxArray_int32_T *ii;
  emxArray_int32_T *idx;
  int32_T i;
  int32_T loop_ub;
  emxArray_int32_T *vk;
  emxArray_real_T *b_vk;
  emxArray_real_T *b_idx;
  real_T LO_OBJ_a;
  real_T LO_OBJ_b;
  real_T LO_OBJ_d;
  char_T LO_OBJ_line_type_data[6];
  int32_T LO_OBJ_line_type_size[2];
  boolean_T tf_is_valid;
  real_T mc_col[2];
  real_T uv_top[2];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  is_detected() */
  /* --------------------------------------------------------------------------  */
  /* --------------------------------------------------------------------------   */
  if (OBJ->tf_is_detected) {
    emxInit_int32_T(sp, &ii, 1, &rb_emlrtRTEI, true);
    emxInit_int32_T(sp, &idx, 1, &hd_emlrtRTEI, true);

    /*  OK: if we're here we have a lane */
    st.site = &xf_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    c_eml_find(&b_st, OBJ->BW, ii);
    st.site = &yf_emlrtRSI;
    b_st.site = &rd_emlrtRSI;
    i = idx->size[0];
    idx->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&b_st, idx, i, &hd_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      idx->data[i] = ii->data[i];
    }

    emxFree_int32_T(&ii);
    if (!allinrange(idx, 76800)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &ag_emlrtRTEI,
        "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
    }

    i = idx->size[0];
    emxEnsureCapacity_int32_T(&b_st, idx, i, &id_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i = 0; i < loop_ub; i++) {
      idx->data[i]--;
    }

    emxInit_int32_T(&b_st, &vk, 1, &jd_emlrtRTEI, true);
    i = vk->size[0];
    vk->size[0] = idx->size[0];
    emxEnsureCapacity_int32_T(&b_st, vk, i, &jd_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i = 0; i < loop_ub; i++) {
      vk->data[i] = idx->data[i] / 240;
    }

    i = idx->size[0];
    emxEnsureCapacity_int32_T(&b_st, idx, i, &kd_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i = 0; i < loop_ub; i++) {
      idx->data[i] -= vk->data[i] * 240;
    }

    emxInit_real_T1(&b_st, &b_vk, 1, &ld_emlrtRTEI, true);

    /*  convert INDS to SUBSCRIPTS */
    /*  create a homogenous line object */
    i = b_vk->size[0];
    b_vk->size[0] = vk->size[0];
    emxEnsureCapacity_real_T1(sp, b_vk, i, &ld_emlrtRTEI);
    loop_ub = vk->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_vk->data[i] = (real_T)vk->data[i] + 1.0;
    }

    emxFree_int32_T(&vk);
    emxInit_real_T1(sp, &b_idx, 1, &md_emlrtRTEI, true);
    i = b_idx->size[0];
    b_idx->size[0] = idx->size[0];
    emxEnsureCapacity_real_T1(sp, b_idx, i, &md_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_idx->data[i] = idx->data[i] + 1;
    }

    emxFree_int32_T(&idx);
    st.site = &bg_emlrtRSI;
    c_bh_line_homog_CLS_bh_line_hom(&st, b_vk, b_idx, &LO_OBJ_a, &LO_OBJ_b,
      &LO_OBJ_d, LO_OBJ_line_type_data, LO_OBJ_line_type_size);
    st.site = &ag_emlrtRSI;
    c_bh_line_homog_CLS_get_roi_int(&st, LO_OBJ_a, LO_OBJ_b, LO_OBJ_d,
      LO_OBJ_line_type_data, LO_OBJ_line_type_size, vlim, &tf_is_valid, mc_col,
      uv_top);

    /*  take care of the OUTPUTS */
    emxFree_real_T(&b_idx);
    emxFree_real_T(&b_vk);
    for (i = 0; i < 2; i++) {
      OBJ->tip_upper_xy_col[i] = uv_top[i];
      OBJ->tip_lower_xy_col[i] = mc_col[i];
    }

    /*  get equation of the line */
    /*  :  y = mx + c */
    bh_line_homog_CLS_get_mc(LO_OBJ_a, LO_OBJ_b, LO_OBJ_d, LO_OBJ_line_type_data,
      LO_OBJ_line_type_size, mc_col);

    /* OBJ.fh_line = @(x) (m*x + c); */
    OBJ->m = mc_col[0];
    OBJ->c = mc_col[1];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void b_lane_info_CLS_lane_info_CLS(const emlrtStack *sp, const boolean_T BW
  [76800], boolean_T tf_found, lane_info_CLS_1 *OBJ)
{
  int32_T i;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i = 0; i < 2; i++) {
    OBJ->tip_upper_xy_col[i] = 0.0;
    OBJ->tip_lower_xy_col[i] = 0.0;
  }

  OBJ->m = 0.0;
  OBJ->c = 0.0;

  /*  ATTENTION: */
  /*  I want this class to be MATLAB CODER friendly, hence I have prepopulated */
  /*  some properties with NaNs */
  /* --------------------------------- */
  /*  closest to TOP of image */
  /*  closest to BOTTOM of image */
  /* fh_line; */
  /* --------------------------------- */
  /* _######################################################################### */
  memcpy(&OBJ->BW[0], &BW[0], 76800U * sizeof(boolean_T));
  OBJ->NUM_ROWS = 240.0;
  OBJ->NUM_COLS = 320.0;
  OBJ->tf_is_detected = tf_found;
  st.site = &wf_emlrtRSI;
  lane_info_CLS_calc_info(&st, OBJ);
}

void lane_info_CLS_calc_info(const emlrtStack *sp, lane_info_CLS_1 *OBJ)
{
  emxArray_int32_T *ii;
  emxArray_int32_T *idx;
  int32_T i;
  int32_T loop_ub;
  emxArray_int32_T *vk;
  emxArray_real_T *b_vk;
  emxArray_real_T *b_idx;
  real_T LO_OBJ_a;
  real_T LO_OBJ_b;
  real_T LO_OBJ_d;
  char_T LO_OBJ_line_type_data[6];
  int32_T LO_OBJ_line_type_size[2];
  real_T dv1[2];
  boolean_T tf_is_valid;
  real_T mc_col[2];
  real_T uv_top[2];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  is_detected() */
  /* --------------------------------------------------------------------------  */
  /* --------------------------------------------------------------------------   */
  if (OBJ->tf_is_detected) {
    emxInit_int32_T(sp, &ii, 1, &rb_emlrtRTEI, true);
    emxInit_int32_T(sp, &idx, 1, &hd_emlrtRTEI, true);

    /*  OK: if we're here we have a lane */
    st.site = &xf_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    c_eml_find(&b_st, OBJ->BW, ii);
    st.site = &yf_emlrtRSI;
    b_st.site = &rd_emlrtRSI;
    i = idx->size[0];
    idx->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&b_st, idx, i, &hd_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      idx->data[i] = ii->data[i];
    }

    emxFree_int32_T(&ii);
    if (!allinrange(idx, 76800)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &ag_emlrtRTEI,
        "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
    }

    i = idx->size[0];
    emxEnsureCapacity_int32_T(&b_st, idx, i, &id_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i = 0; i < loop_ub; i++) {
      idx->data[i]--;
    }

    emxInit_int32_T(&b_st, &vk, 1, &jd_emlrtRTEI, true);
    i = vk->size[0];
    vk->size[0] = idx->size[0];
    emxEnsureCapacity_int32_T(&b_st, vk, i, &jd_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i = 0; i < loop_ub; i++) {
      vk->data[i] = idx->data[i] / 240;
    }

    i = idx->size[0];
    emxEnsureCapacity_int32_T(&b_st, idx, i, &kd_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i = 0; i < loop_ub; i++) {
      idx->data[i] -= vk->data[i] * 240;
    }

    emxInit_real_T1(&b_st, &b_vk, 1, &ld_emlrtRTEI, true);

    /*  convert INDS to SUBSCRIPTS */
    /*  create a homogenous line object */
    i = b_vk->size[0];
    b_vk->size[0] = vk->size[0];
    emxEnsureCapacity_real_T1(sp, b_vk, i, &ld_emlrtRTEI);
    loop_ub = vk->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_vk->data[i] = (real_T)vk->data[i] + 1.0;
    }

    emxFree_int32_T(&vk);
    emxInit_real_T1(sp, &b_idx, 1, &md_emlrtRTEI, true);
    i = b_idx->size[0];
    b_idx->size[0] = idx->size[0];
    emxEnsureCapacity_real_T1(sp, b_idx, i, &md_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_idx->data[i] = idx->data[i] + 1;
    }

    emxFree_int32_T(&idx);
    st.site = &bg_emlrtRSI;
    c_bh_line_homog_CLS_bh_line_hom(&st, b_vk, b_idx, &LO_OBJ_a, &LO_OBJ_b,
      &LO_OBJ_d, LO_OBJ_line_type_data, LO_OBJ_line_type_size);
    emxFree_real_T(&b_idx);
    emxFree_real_T(&b_vk);
    for (i = 0; i < 2; i++) {
      dv1[i] = 1.0 + 239.0 * (real_T)i;
    }

    st.site = &ag_emlrtRSI;
    c_bh_line_homog_CLS_get_roi_int(&st, LO_OBJ_a, LO_OBJ_b, LO_OBJ_d,
      LO_OBJ_line_type_data, LO_OBJ_line_type_size, dv1, &tf_is_valid, mc_col,
      uv_top);

    /*  take care of the OUTPUTS */
    for (i = 0; i < 2; i++) {
      OBJ->tip_upper_xy_col[i] = uv_top[i];
      OBJ->tip_lower_xy_col[i] = mc_col[i];
    }

    /*  get equation of the line */
    /*  :  y = mx + c */
    bh_line_homog_CLS_get_mc(LO_OBJ_a, LO_OBJ_b, LO_OBJ_d, LO_OBJ_line_type_data,
      LO_OBJ_line_type_size, mc_col);

    /* OBJ.fh_line = @(x) (m*x + c); */
    OBJ->m = mc_col[0];
    OBJ->c = mc_col[1];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void lane_info_CLS_convert_to_struct(const boolean_T OBJ_BW[76800], const real_T
  OBJ_tip_upper_xy_col[2], const real_T OBJ_tip_lower_xy_col[2], real_T OBJ_m,
  real_T OBJ_c, boolean_T OBJ_tf_is_detected, boolean_T my_S_BW[76800], real_T
  *my_S_NUM_ROWS, real_T *my_S_NUM_COLS, real_T my_S_tip_upper_xy_col[2], real_T
  my_S_tip_lower_xy_col[2], real_T *my_S_m, real_T *my_S_c, boolean_T
  *my_S_tf_is_detected)
{
  int32_T i;

  /* --------------------------------------------------------------------------   */
  /*  ATTENTION(R2017b): */
  /*  the following usage is NOT supported by the MATLAB Coder: */
  /*    >> struct(OBJ) */
  memcpy(&my_S_BW[0], &OBJ_BW[0], 76800U * sizeof(boolean_T));
  *my_S_NUM_ROWS = 240.0;
  *my_S_NUM_COLS = 320.0;
  for (i = 0; i < 2; i++) {
    my_S_tip_upper_xy_col[i] = OBJ_tip_upper_xy_col[i];
    my_S_tip_lower_xy_col[i] = OBJ_tip_lower_xy_col[i];
  }

  *my_S_m = OBJ_m;
  *my_S_c = OBJ_c;
  *my_S_tf_is_detected = OBJ_tf_is_detected;

  /* --------------------------------------------------------------------------   */
  /*  methods() */
  /* _######################################################################### */
  /*  classdef() */
  /* _######################################################################### */
  /*  END CLASSDEF */
  /* _######################################################################### */
}

void lane_info_CLS_get_mc(real_T OBJ_m, real_T OBJ_c, boolean_T
  OBJ_tf_is_detected, real_T m_data[], int32_T m_size[2], real_T c_data[],
  int32_T c_size[2])
{
  /*  get_xy() */
  /* --------------------------------------------------------------------------   */
  /* coder.varsize('m','c', [1 1]); */
  m_size[0] = 1;
  m_size[1] = 0;

  /*  [] */
  c_size[0] = 1;
  c_size[1] = 0;

  /*  [] */
  /* --------------------------------------------------------------------------   */
  if (OBJ_tf_is_detected) {
    m_size[0] = 1;
    m_size[1] = 1;
    m_data[0] = OBJ_m;
    c_size[0] = 1;
    c_size[1] = 1;
    c_data[0] = OBJ_c;
  }
}

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
  emxArray_int32_T *vk;
  emxArray_real_T *b_vk;
  emxArray_real_T *b_idx;
  real_T LO_OBJ_d;
  char_T LO_OBJ_line_type_data[6];
  int32_T LO_OBJ_line_type_size[2];
  real_T dv0[2];
  boolean_T tf_is_valid;
  real_T uv_top[2];
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
  st.site = &wf_emlrtRSI;

  /*  is_detected() */
  /* --------------------------------------------------------------------------  */
  /* --------------------------------------------------------------------------   */
  if (tf_found) {
    emxInit_int32_T(&st, &ii, 1, &rb_emlrtRTEI, true);
    emxInit_int32_T(&st, &idx, 1, &hd_emlrtRTEI, true);

    /*  OK: if we're here we have a lane */
    the_size[0] = BW->size[0];
    b_st.site = &xf_emlrtRSI;
    c_st.site = &of_emlrtRSI;
    eml_find(&c_st, BW, ii);
    b_st.site = &yf_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    i = idx->size[0];
    idx->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&c_st, idx, i, &hd_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      idx->data[i] = ii->data[i];
    }

    emxFree_int32_T(&ii);
    BW_idx_0 = (int16_T)BW->size[0];
    if (!allinrange(idx, BW_idx_0 * 320)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &ag_emlrtRTEI,
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
      d_st.site = &bm_emlrtRSI;
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
    b_st.site = &bg_emlrtRSI;
    c_bh_line_homog_CLS_bh_line_hom(&b_st, b_vk, b_idx, &b_OBJ_m, &b_OBJ_c,
      &LO_OBJ_d, LO_OBJ_line_type_data, LO_OBJ_line_type_size);
    emxFree_real_T(&b_idx);
    emxFree_real_T(&b_vk);
    dv0[0] = 1.0;
    dv0[1] = BW->size[0];
    b_st.site = &ag_emlrtRSI;
    c_bh_line_homog_CLS_get_roi_int(&b_st, b_OBJ_m, b_OBJ_c, LO_OBJ_d,
      LO_OBJ_line_type_data, LO_OBJ_line_type_size, dv0, &tf_is_valid, the_size,
      uv_top);

    /*  take care of the OUTPUTS */
    for (i = 0; i < 2; i++) {
      OBJ_tip_upper_xy_col[i] = uv_top[i];
    }

    for (i = 0; i < 2; i++) {
      OBJ_tip_lower_xy_col[i] = the_size[i];
    }

    /*  get equation of the line */
    /*  :  y = mx + c */
    bh_line_homog_CLS_get_mc(b_OBJ_m, b_OBJ_c, LO_OBJ_d, LO_OBJ_line_type_data,
      LO_OBJ_line_type_size, dv0);
    for (i = 0; i < 2; i++) {
      the_size[i] = dv0[i];
    }

    /* OBJ.fh_line = @(x) (m*x + c); */
    b_OBJ_m = the_size[0];
    b_OBJ_c = the_size[1];
  }

  *OBJ_NUM_ROWS = b_OBJ_NUM_ROWS;
  *OBJ_NUM_COLS = 320.0;
  *OBJ_m = b_OBJ_m;
  *OBJ_c = b_OBJ_c;
  *OBJ_tf_is_detected = tf_found;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (lane_info_CLS.c) */
