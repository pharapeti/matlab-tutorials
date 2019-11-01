/*
 * box_info_CLS.c
 *
 * Code generation for function 'box_info_CLS'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "box_info_CLS.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_emxutil.h"
#include "mean.h"
#include "find.h"
#include "ind2sub.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_mexutil.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Variable Definitions */
static emlrtRSInfo xd_emlrtRSI = { 140,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo kk_emlrtRSI = { 29, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo lk_emlrtRSI = { 43, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo mk_emlrtRSI = { 44, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo nk_emlrtRSI = { 48, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo ok_emlrtRSI = { 50, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo pk_emlrtRSI = { 52, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo qk_emlrtRSI = { 56, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo rk_emlrtRSI = { 58, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo sk_emlrtRSI = { 60, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo tk_emlrtRSI = { 63, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo uk_emlrtRSI = { 64, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo vk_emlrtRSI = { 15, /* lineNo */
  "max",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRTEInfo td_emlrtRTEI = { 22,/* lineNo */
  7,                                   /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = { 36,/* lineNo */
  16,                                  /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtRTEInfo jf_emlrtRTEI = { 44,/* lineNo */
  7,                                   /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtRTEInfo kf_emlrtRTEI = { 50,/* lineNo */
  28,                                  /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtRTEInfo lf_emlrtRTEI = { 50,/* lineNo */
  4,                                   /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtRTEInfo mf_emlrtRTEI = { 51,/* lineNo */
  4,                                   /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = { 58,/* lineNo */
  29,                                  /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtRTEInfo of_emlrtRTEI = { 58,/* lineNo */
  4,                                   /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtRTEInfo pf_emlrtRTEI = { 59,/* lineNo */
  4,                                   /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtBCInfo he_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  27,                                  /* colNo */
  "x",                                 /* aName */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  26,                                  /* colNo */
  "x",                                 /* aName */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  25,                                  /* colNo */
  "y",                                 /* aName */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  26,                                  /* colNo */
  "y",                                 /* aName */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void box_info_CLS_calc_info(const emlrtStack *sp, box_info_CLS *OBJ);

/* Function Definitions */
static void box_info_CLS_calc_info(const emlrtStack *sp, box_info_CLS *OBJ)
{
  emxArray_int32_T *ii;
  emxArray_int32_T *idx;
  real_T the_size_idx_0;
  int32_T mtmp;
  int32_T loop_ub;
  int32_T cpsiz;
  emxArray_int32_T *vk;
  emxArray_real_T *y;
  emxArray_real_T *x;
  emxArray_int32_T *b_x;
  boolean_T b6;
  int32_T b_mtmp;
  int32_T itmp;
  emxArray_boolean_T *c_x;
  int32_T ix;
  emxArray_int32_T *tmp_II;
  emxArray_int32_T *yI;
  int32_T b_itmp;
  real_T yc;
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

  /*  is_detected() */
  /* --------------------------------------------------------------------------  */
  /* --------------------------------------------------------------------------   */
  if (OBJ->tf_is_detected) {
    emxInit_int32_T(sp, &ii, 1, &rb_emlrtRTEI, true);
    emxInit_int32_T(sp, &idx, 1, &hd_emlrtRTEI, true);

    /*  OK: if we're here we have a box */
    the_size_idx_0 = OBJ->NUM_ROWS;
    st.site = &lk_emlrtRSI;
    b_st.site = &of_emlrtRSI;
    eml_find(&b_st, OBJ->BW, ii);
    st.site = &mk_emlrtRSI;
    b_st.site = &rd_emlrtRSI;
    mtmp = idx->size[0];
    idx->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&b_st, idx, mtmp, &hd_emlrtRTEI);
    loop_ub = ii->size[0];
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      idx->data[mtmp] = ii->data[mtmp];
    }

    cpsiz = (int32_T)OBJ->NUM_ROWS;
    if (!allinrange(idx, cpsiz * 320)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &ag_emlrtRTEI,
        "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
    }

    mtmp = idx->size[0];
    emxEnsureCapacity_int32_T(&b_st, idx, mtmp, &id_emlrtRTEI);
    loop_ub = idx->size[0];
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      idx->data[mtmp]--;
    }

    emxInit_int32_T(&b_st, &vk, 1, &jd_emlrtRTEI, true);
    mtmp = vk->size[0];
    vk->size[0] = idx->size[0];
    emxEnsureCapacity_int32_T(&b_st, vk, mtmp, &jd_emlrtRTEI);
    loop_ub = idx->size[0];
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      c_st.site = &bm_emlrtRSI;
      vk->data[mtmp] = div_s32(&c_st, idx->data[mtmp], (int32_T)the_size_idx_0);
    }

    mtmp = idx->size[0];
    emxEnsureCapacity_int32_T(&b_st, idx, mtmp, &kd_emlrtRTEI);
    loop_ub = idx->size[0];
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      idx->data[mtmp] -= vk->data[mtmp] * cpsiz;
    }

    emxInit_real_T1(&b_st, &y, 1, &ud_emlrtRTEI, true);
    mtmp = y->size[0];
    y->size[0] = idx->size[0];
    emxEnsureCapacity_real_T1(&st, y, mtmp, &xd_emlrtRTEI);
    loop_ub = idx->size[0];
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      y->data[mtmp] = idx->data[mtmp] + 1;
    }

    emxFree_int32_T(&idx);
    emxInit_real_T1(&st, &x, 1, &ud_emlrtRTEI, true);
    mtmp = x->size[0];
    x->size[0] = vk->size[0];
    emxEnsureCapacity_real_T1(&st, x, mtmp, &xd_emlrtRTEI);
    loop_ub = vk->size[0];
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      x->data[mtmp] = vk->data[mtmp] + 1;
    }

    emxInit_int32_T(&st, &b_x, 1, &jf_emlrtRTEI, true);
    mtmp = b_x->size[0];
    b_x->size[0] = vk->size[0];
    emxEnsureCapacity_int32_T(sp, b_x, mtmp, &jf_emlrtRTEI);
    loop_ub = vk->size[0];
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      b_x->data[mtmp] = vk->data[mtmp] + 1;
    }

    emxFree_int32_T(&vk);

    /*  convert INDS to SUBSCRIPTS */
    /*  the LEFT edge will have the smallest X-co-ord */
    st.site = &nk_emlrtRSI;
    b_st.site = &ib_emlrtRSI;
    c_st.site = &jb_emlrtRSI;
    if ((x->size[0] == 1) || (x->size[0] != 1)) {
      b6 = true;
    } else {
      b6 = false;
    }

    if (!b6) {
      emlrtErrorWithMessageIdR2012b(&c_st, &fg_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(x->size[0] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &eg_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &xd_emlrtRSI;
    cpsiz = b_x->size[0];
    b_mtmp = b_x->data[0];
    itmp = 0;
    if (x->size[0] > 1) {
      for (ix = 1; ix + 1 <= cpsiz; ix++) {
        if (b_x->data[ix] < b_mtmp) {
          b_mtmp = b_x->data[ix];
          itmp = ix;
        }
      }
    }

    emxInit_boolean_T1(&d_st, &c_x, 1, &kf_emlrtRTEI, true);
    mtmp = x->size[0];
    cpsiz = itmp + 1;
    if (!((cpsiz >= 1) && (cpsiz <= mtmp))) {
      emlrtDynamicBoundsCheckR2012b(cpsiz, 1, mtmp, &ie_emlrtBCI, sp);
    }

    /*  MATLAB CODER friendly */
    st.site = &ok_emlrtRSI;
    cpsiz = (int32_T)x->data[itmp];
    mtmp = c_x->size[0];
    c_x->size[0] = b_x->size[0];
    emxEnsureCapacity_boolean_T1(&st, c_x, mtmp, &kf_emlrtRTEI);
    loop_ub = b_x->size[0];
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      c_x->data[mtmp] = (b_x->data[mtmp] == cpsiz);
    }

    emxInit_int32_T(&st, &tmp_II, 1, &lf_emlrtRTEI, true);
    b_st.site = &of_emlrtRSI;
    b_eml_find(&b_st, c_x, ii);
    mtmp = tmp_II->size[0];
    tmp_II->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&st, tmp_II, mtmp, &lf_emlrtRTEI);
    loop_ub = ii->size[0];
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      tmp_II->data[mtmp] = ii->data[mtmp];
    }

    emxInit_int32_T(&st, &yI, 1, &mf_emlrtRTEI, true);
    ix = y->size[0];
    mtmp = yI->size[0];
    yI->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(sp, yI, mtmp, &mf_emlrtRTEI);
    loop_ub = ii->size[0];
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      cpsiz = ii->data[mtmp];
      if (!((cpsiz >= 1) && (cpsiz <= ix))) {
        emlrtDynamicBoundsCheckR2012b(cpsiz, 1, ix, &je_emlrtBCI, sp);
      }

      yI->data[mtmp] = (int32_T)y->data[cpsiz - 1];
    }

    st.site = &pk_emlrtRSI;
    b_st.site = &ud_emlrtRSI;
    c_st.site = &vd_emlrtRSI;
    if ((ii->size[0] == 1) || (ii->size[0] != 1)) {
      b6 = true;
    } else {
      b6 = false;
    }

    if (!b6) {
      emlrtErrorWithMessageIdR2012b(&c_st, &fg_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(ii->size[0] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &eg_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    cpsiz = ii->size[0];
    b_mtmp = yI->data[0];
    if ((tmp_II->size[0] > 1) && (1 < tmp_II->size[0])) {
      for (ix = 1; ix + 1 <= cpsiz; ix++) {
        if (yI->data[ix] < b_mtmp) {
          b_mtmp = yI->data[ix];
        }
      }
    }

    /*  the RIGHT edge will have the biggest X-co-ord */
    st.site = &qk_emlrtRSI;
    b_st.site = &vk_emlrtRSI;
    c_st.site = &jb_emlrtRSI;
    if ((x->size[0] == 1) || (x->size[0] != 1)) {
      b6 = true;
    } else {
      b6 = false;
    }

    if (!b6) {
      emlrtErrorWithMessageIdR2012b(&c_st, &fg_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(x->size[0] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &eg_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    cpsiz = b_x->size[0];
    mtmp = b_x->data[0];
    b_itmp = 0;
    if (x->size[0] > 1) {
      for (ix = 1; ix + 1 <= cpsiz; ix++) {
        if (b_x->data[ix] > mtmp) {
          mtmp = b_x->data[ix];
          b_itmp = ix;
        }
      }
    }

    mtmp = x->size[0];
    cpsiz = b_itmp + 1;
    if (!((cpsiz >= 1) && (cpsiz <= mtmp))) {
      emlrtDynamicBoundsCheckR2012b(cpsiz, 1, mtmp, &he_emlrtBCI, sp);
    }

    /*  MATLAB CODER friendly */
    st.site = &rk_emlrtRSI;
    cpsiz = (int32_T)x->data[b_itmp];
    mtmp = c_x->size[0];
    c_x->size[0] = b_x->size[0];
    emxEnsureCapacity_boolean_T1(&st, c_x, mtmp, &nf_emlrtRTEI);
    loop_ub = b_x->size[0];
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      c_x->data[mtmp] = (b_x->data[mtmp] == cpsiz);
    }

    b_st.site = &of_emlrtRSI;
    b_eml_find(&b_st, c_x, ii);
    mtmp = tmp_II->size[0];
    tmp_II->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&st, tmp_II, mtmp, &of_emlrtRTEI);
    loop_ub = ii->size[0];
    emxFree_boolean_T(&c_x);
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      tmp_II->data[mtmp] = ii->data[mtmp];
    }

    ix = y->size[0];
    mtmp = yI->size[0];
    yI->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(sp, yI, mtmp, &pf_emlrtRTEI);
    loop_ub = ii->size[0];
    for (mtmp = 0; mtmp < loop_ub; mtmp++) {
      cpsiz = ii->data[mtmp];
      if (!((cpsiz >= 1) && (cpsiz <= ix))) {
        emlrtDynamicBoundsCheckR2012b(cpsiz, 1, ix, &ke_emlrtBCI, sp);
      }

      yI->data[mtmp] = (int32_T)y->data[cpsiz - 1];
    }

    st.site = &sk_emlrtRSI;
    b_st.site = &ud_emlrtRSI;
    c_st.site = &vd_emlrtRSI;
    if ((ii->size[0] == 1) || (ii->size[0] != 1)) {
      b6 = true;
    } else {
      b6 = false;
    }

    if (!b6) {
      emlrtErrorWithMessageIdR2012b(&c_st, &fg_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(ii->size[0] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &eg_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    cpsiz = ii->size[0];
    mtmp = yI->data[0];
    emxFree_int32_T(&ii);
    if ((tmp_II->size[0] > 1) && (1 < tmp_II->size[0])) {
      for (ix = 1; ix + 1 <= cpsiz; ix++) {
        if (yI->data[ix] < mtmp) {
          mtmp = yI->data[ix];
        }
      }
    }

    emxFree_int32_T(&yI);
    emxFree_int32_T(&tmp_II);

    /*  calc the centroid */
    st.site = &tk_emlrtRSI;
    the_size_idx_0 = mean(&st, x);
    st.site = &uk_emlrtRSI;
    yc = mean(&st, y);

    /*  take care of the OUTPUTS */
    OBJ->left_edge_xy_col[0] = b_x->data[itmp];
    OBJ->left_edge_xy_col[1] = b_mtmp;

    /*  MATLAB CODER friendly */
    OBJ->right_edge_xy_col[0] = b_x->data[b_itmp];
    OBJ->right_edge_xy_col[1] = mtmp;

    /*  MATLAB CODER friendly */
    OBJ->centroid_xy_col[0] = the_size_idx_0;
    OBJ->centroid_xy_col[1] = yc;

    /*  MATLAB CODER friendly */
    emxFree_real_T(&x);
    emxFree_real_T(&y);
    emxFree_int32_T(&b_x);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void box_info_CLS_box_info_CLS(const emlrtStack *sp, const emxArray_boolean_T
  *BW, boolean_T tf_found, box_info_CLS *OBJ)
{
  int32_T i;
  int32_T loop_ub;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i = 0; i < 2; i++) {
    OBJ->left_edge_xy_col[i] = 0.0;
  }

  for (i = 0; i < 2; i++) {
    OBJ->right_edge_xy_col[i] = 0.0;
  }

  for (i = 0; i < 2; i++) {
    OBJ->centroid_xy_col[i] = 0.0;
  }

  /*  ATTENTION: */
  /*  I want this class to be MATLAB CODER friendly, hence I have prepopulated */
  /*  some properties with NaNs */
  /* --------------------------------- */
  /* --------------------------------- */
  /* --------------------------------- */
  /* _######################################################################### */
  i = OBJ->BW->size[0] * OBJ->BW->size[1];
  OBJ->BW->size[0] = BW->size[0];
  OBJ->BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(sp, OBJ->BW, i, &td_emlrtRTEI);
  loop_ub = BW->size[0] * BW->size[1];
  for (i = 0; i < loop_ub; i++) {
    OBJ->BW->data[i] = BW->data[i];
  }

  OBJ->NUM_ROWS = BW->size[0];
  OBJ->NUM_COLS = 320.0;
  OBJ->tf_is_detected = tf_found;
  st.site = &kk_emlrtRSI;
  box_info_CLS_calc_info(&st, OBJ);
}

/* End of code generation (box_info_CLS.c) */
