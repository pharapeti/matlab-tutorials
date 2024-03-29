/*
 * box_info_CLS.c
 *
 * Code generation for function 'box_info_CLS'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "box_info_CLS.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "mean.h"
#include "find.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mexutil.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRSInfo td_emlrtRSI = { 13, /* lineNo */
  "min",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pathName */
};

static emlrtRSInfo ud_emlrtRSI = { 19, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 140,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo ik_emlrtRSI = { 29, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo jk_emlrtRSI = { 43, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo kk_emlrtRSI = { 44, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo lk_emlrtRSI = { 48, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo mk_emlrtRSI = { 50, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo nk_emlrtRSI = { 52, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo ok_emlrtRSI = { 56, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo pk_emlrtRSI = { 58, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo qk_emlrtRSI = { 60, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo rk_emlrtRSI = { 63, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo sk_emlrtRSI = { 64, /* lineNo */
  "box_info_CLS",                      /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pathName */
};

static emlrtRSInfo tk_emlrtRSI = { 15, /* lineNo */
  "max",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 21,/* lineNo */
  16,                                  /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 36,/* lineNo */
  16,                                  /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 50,/* lineNo */
  4,                                   /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = { 51,/* lineNo */
  4,                                   /* colNo */
  "box_info_CLS",                      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\box_info_CLS.m"/* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = { 39,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
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

/*
 * function OBJ = calc_info(OBJ)
 */
static void box_info_CLS_calc_info(const emlrtStack *sp, box_info_CLS *OBJ)
{
  emxArray_int32_T *ii;
  emxArray_int32_T *idx;
  real_T the_size_idx_0;
  int32_T i33;
  int32_T loop_ub;
  int32_T cpsiz;
  int32_T maxndx;
  int32_T k;
  int32_T exitg1;
  boolean_T p;
  emxArray_int32_T *vk;
  emxArray_real_T *y;
  emxArray_real_T *x;
  emxArray_int32_T *b_x;
  int32_T mtmp;
  int32_T itmp;
  emxArray_boolean_T *c_x;
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
  /* 'box_info_CLS:37' if( ~OBJ.is_detected() ) */
  /* --------------------------------------------------------------------------   */
  /* 'box_info_CLS:33' tf_detected = OBJ.tf_is_detected; */
  if (OBJ->tf_is_detected) {
    emxInit_int32_T(sp, &ii, 1, &t_emlrtRTEI, true);
    emxInit_int32_T(sp, &idx, 1, &pb_emlrtRTEI, true);

    /*  OK: if we're here we have a box */
    /* 'box_info_CLS:42' the_size = [OBJ.NUM_ROWS, OBJ.NUM_COLS]; */
    the_size_idx_0 = OBJ->NUM_ROWS;

    /* 'box_info_CLS:43' the_ind  = find(OBJ.BW); */
    st.site = &jk_emlrtRSI;
    b_st.site = &mf_emlrtRSI;
    eml_find(&b_st, OBJ->BW, ii);

    /* 'box_info_CLS:44' [y,x]    = ind2sub(the_size,the_ind); */
    st.site = &kk_emlrtRSI;
    b_st.site = &qd_emlrtRSI;
    i33 = idx->size[0];
    idx->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&b_st, idx, i33, &vb_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i33 = 0; i33 < loop_ub; i33++) {
      idx->data[i33] = ii->data[i33];
    }

    cpsiz = (int32_T)OBJ->NUM_ROWS;
    maxndx = (int32_T)the_size_idx_0 * 320;
    k = 0;
    do {
      exitg1 = 0;
      if (k <= idx->size[0] - 1) {
        if ((idx->data[k] >= 1) && (idx->data[k] <= maxndx)) {
          p = true;
        } else {
          p = false;
        }

        if (!p) {
          p = false;
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        p = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (!p) {
      emlrtErrorWithMessageIdR2012b(&b_st, &uc_emlrtRTEI,
        "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
    }

    i33 = idx->size[0];
    emxEnsureCapacity_int32_T(&b_st, idx, i33, &vb_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i33 = 0; i33 < loop_ub; i33++) {
      idx->data[i33]--;
    }

    emxInit_int32_T(&b_st, &vk, 1, &qb_emlrtRTEI, true);
    i33 = vk->size[0];
    vk->size[0] = idx->size[0];
    emxEnsureCapacity_int32_T(&b_st, vk, i33, &vb_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i33 = 0; i33 < loop_ub; i33++) {
      c_st.site = &wk_emlrtRSI;
      vk->data[i33] = div_s32(&c_st, idx->data[i33], (int32_T)the_size_idx_0);
    }

    i33 = idx->size[0];
    emxEnsureCapacity_int32_T(&b_st, idx, i33, &vb_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i33 = 0; i33 < loop_ub; i33++) {
      idx->data[i33] -= vk->data[i33] * cpsiz;
    }

    emxInit_real_T1(&b_st, &y, 1, &vb_emlrtRTEI, true);
    i33 = y->size[0];
    y->size[0] = idx->size[0];
    emxEnsureCapacity_real_T1(&st, y, i33, &vb_emlrtRTEI);
    loop_ub = idx->size[0];
    for (i33 = 0; i33 < loop_ub; i33++) {
      y->data[i33] = idx->data[i33] + 1;
    }

    emxFree_int32_T(&idx);
    emxInit_real_T1(&st, &x, 1, &vb_emlrtRTEI, true);
    i33 = x->size[0];
    x->size[0] = vk->size[0];
    emxEnsureCapacity_real_T1(&st, x, i33, &vb_emlrtRTEI);
    loop_ub = vk->size[0];
    for (i33 = 0; i33 < loop_ub; i33++) {
      x->data[i33] = vk->data[i33] + 1;
    }

    emxInit_int32_T(&st, &b_x, 1, &vb_emlrtRTEI, true);
    i33 = b_x->size[0];
    b_x->size[0] = vk->size[0];
    emxEnsureCapacity_int32_T(sp, b_x, i33, &vb_emlrtRTEI);
    loop_ub = vk->size[0];
    for (i33 = 0; i33 < loop_ub; i33++) {
      b_x->data[i33] = vk->data[i33] + 1;
    }

    emxFree_int32_T(&vk);

    /*  convert INDS to SUBSCRIPTS */
    /*  the LEFT edge will have the smallest X-co-ord */
    /* 'box_info_CLS:47' the_left_edge_x  = 1; */
    /* 'box_info_CLS:48' [~,tmp_I]        = min(x); */
    st.site = &lk_emlrtRSI;
    b_st.site = &hb_emlrtRSI;
    c_st.site = &ib_emlrtRSI;
    if ((x->size[0] == 1) || (x->size[0] != 1)) {
      p = true;
    } else {
      p = false;
    }

    if (!p) {
      emlrtErrorWithMessageIdR2012b(&c_st, &dd_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(x->size[0] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &ad_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &vd_emlrtRSI;
    maxndx = b_x->size[0];
    mtmp = b_x->data[0];
    itmp = 0;
    if (x->size[0] > 1) {
      for (k = 1; k + 1 <= maxndx; k++) {
        if (b_x->data[k] < mtmp) {
          mtmp = b_x->data[k];
          itmp = k;
        }
      }
    }

    emxInit_boolean_T1(&d_st, &c_x, 1, &vb_emlrtRTEI, true);

    /* 'box_info_CLS:48' ~ */
    /* 'box_info_CLS:49' the_left_edge_x  =  x(tmp_I(1)); */
    i33 = x->size[0];
    maxndx = itmp + 1;
    if (!((maxndx >= 1) && (maxndx <= i33))) {
      emlrtDynamicBoundsCheckR2012b(maxndx, 1, i33, &ie_emlrtBCI, sp);
    }

    /*  MATLAB CODER friendly */
    /* 'box_info_CLS:50' tmp_II           = find(x==the_left_edge_x); */
    st.site = &mk_emlrtRSI;
    maxndx = (int32_T)x->data[itmp];
    i33 = c_x->size[0];
    c_x->size[0] = b_x->size[0];
    emxEnsureCapacity_boolean_T1(&st, c_x, i33, &vb_emlrtRTEI);
    loop_ub = b_x->size[0];
    for (i33 = 0; i33 < loop_ub; i33++) {
      c_x->data[i33] = (b_x->data[i33] == maxndx);
    }

    emxInit_int32_T(&st, &tmp_II, 1, &jc_emlrtRTEI, true);
    b_st.site = &mf_emlrtRSI;
    b_eml_find(&b_st, c_x, ii);
    i33 = tmp_II->size[0];
    tmp_II->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&st, tmp_II, i33, &vb_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i33 = 0; i33 < loop_ub; i33++) {
      tmp_II->data[i33] = ii->data[i33];
    }

    emxInit_int32_T(&st, &yI, 1, &kc_emlrtRTEI, true);

    /* 'box_info_CLS:51' yI               = y(tmp_II); */
    k = y->size[0];
    i33 = yI->size[0];
    yI->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(sp, yI, i33, &vb_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i33 = 0; i33 < loop_ub; i33++) {
      maxndx = ii->data[i33];
      if (!((maxndx >= 1) && (maxndx <= k))) {
        emlrtDynamicBoundsCheckR2012b(maxndx, 1, k, &je_emlrtBCI, sp);
      }

      yI->data[i33] = (int32_T)y->data[maxndx - 1];
    }

    /* 'box_info_CLS:52' the_left_edge_y  = min(yI); */
    st.site = &nk_emlrtRSI;
    b_st.site = &td_emlrtRSI;
    c_st.site = &ud_emlrtRSI;
    if ((ii->size[0] == 1) || (ii->size[0] != 1)) {
      p = true;
    } else {
      p = false;
    }

    if (!p) {
      emlrtErrorWithMessageIdR2012b(&c_st, &dd_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(ii->size[0] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &ad_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    maxndx = ii->size[0];
    mtmp = yI->data[0];
    if ((tmp_II->size[0] > 1) && (1 < tmp_II->size[0])) {
      for (k = 1; k + 1 <= maxndx; k++) {
        if (yI->data[k] < mtmp) {
          mtmp = yI->data[k];
        }
      }
    }

    /*  the RIGHT edge will have the biggest X-co-ord */
    /* 'box_info_CLS:55' the_right_edge_x  = 1; */
    /* 'box_info_CLS:56' [~,tmp_I]         = max(x); */
    st.site = &ok_emlrtRSI;
    b_st.site = &tk_emlrtRSI;
    c_st.site = &ib_emlrtRSI;
    if ((x->size[0] == 1) || (x->size[0] != 1)) {
      p = true;
    } else {
      p = false;
    }

    if (!p) {
      emlrtErrorWithMessageIdR2012b(&c_st, &dd_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(x->size[0] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &ad_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    maxndx = b_x->size[0];
    cpsiz = b_x->data[0];
    b_itmp = 0;
    if (x->size[0] > 1) {
      for (k = 1; k + 1 <= maxndx; k++) {
        if (b_x->data[k] > cpsiz) {
          cpsiz = b_x->data[k];
          b_itmp = k;
        }
      }
    }

    /* 'box_info_CLS:56' ~ */
    /* 'box_info_CLS:57' the_right_edge_x  =  x(tmp_I(1)); */
    i33 = x->size[0];
    maxndx = b_itmp + 1;
    if (!((maxndx >= 1) && (maxndx <= i33))) {
      emlrtDynamicBoundsCheckR2012b(maxndx, 1, i33, &he_emlrtBCI, sp);
    }

    /*  MATLAB CODER friendly */
    /* 'box_info_CLS:58' tmp_RR            = find(x==the_right_edge_x); */
    st.site = &pk_emlrtRSI;
    maxndx = (int32_T)x->data[b_itmp];
    i33 = c_x->size[0];
    c_x->size[0] = b_x->size[0];
    emxEnsureCapacity_boolean_T1(&st, c_x, i33, &vb_emlrtRTEI);
    loop_ub = b_x->size[0];
    for (i33 = 0; i33 < loop_ub; i33++) {
      c_x->data[i33] = (b_x->data[i33] == maxndx);
    }

    b_st.site = &mf_emlrtRSI;
    b_eml_find(&b_st, c_x, ii);
    i33 = tmp_II->size[0];
    tmp_II->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&st, tmp_II, i33, &vb_emlrtRTEI);
    loop_ub = ii->size[0];
    emxFree_boolean_T(&c_x);
    for (i33 = 0; i33 < loop_ub; i33++) {
      tmp_II->data[i33] = ii->data[i33];
    }

    /* 'box_info_CLS:59' yR                = y(tmp_RR); */
    k = y->size[0];
    i33 = yI->size[0];
    yI->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(sp, yI, i33, &vb_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i33 = 0; i33 < loop_ub; i33++) {
      maxndx = ii->data[i33];
      if (!((maxndx >= 1) && (maxndx <= k))) {
        emlrtDynamicBoundsCheckR2012b(maxndx, 1, k, &ke_emlrtBCI, sp);
      }

      yI->data[i33] = (int32_T)y->data[maxndx - 1];
    }

    /* 'box_info_CLS:60' the_right_edge_y  = min(yR); */
    st.site = &qk_emlrtRSI;
    b_st.site = &td_emlrtRSI;
    c_st.site = &ud_emlrtRSI;
    if ((ii->size[0] == 1) || (ii->size[0] != 1)) {
      p = true;
    } else {
      p = false;
    }

    if (!p) {
      emlrtErrorWithMessageIdR2012b(&c_st, &dd_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (!(ii->size[0] > 0)) {
      emlrtErrorWithMessageIdR2012b(&c_st, &ad_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    maxndx = ii->size[0];
    cpsiz = yI->data[0];
    emxFree_int32_T(&ii);
    if ((tmp_II->size[0] > 1) && (1 < tmp_II->size[0])) {
      for (k = 1; k + 1 <= maxndx; k++) {
        if (yI->data[k] < cpsiz) {
          cpsiz = yI->data[k];
        }
      }
    }

    emxFree_int32_T(&yI);
    emxFree_int32_T(&tmp_II);

    /*  calc the centroid */
    /* 'box_info_CLS:63' xc = mean(x); */
    st.site = &rk_emlrtRSI;
    the_size_idx_0 = mean(&st, x);

    /* 'box_info_CLS:64' yc = mean(y); */
    st.site = &sk_emlrtRSI;
    yc = mean(&st, y);

    /*  take care of the OUTPUTS */
    /* 'box_info_CLS:67' OBJ.left_edge_xy_col   = [the_left_edge_x(1);  the_left_edge_y(1)   ]; */
    OBJ->left_edge_xy_col[0] = b_x->data[itmp];
    OBJ->left_edge_xy_col[1] = mtmp;

    /*  MATLAB CODER friendly */
    /* 'box_info_CLS:68' OBJ.right_edge_xy_col  = [the_right_edge_x(1); the_right_edge_y(1)  ]; */
    OBJ->right_edge_xy_col[0] = b_x->data[b_itmp];
    OBJ->right_edge_xy_col[1] = cpsiz;

    /*  MATLAB CODER friendly */
    /* 'box_info_CLS:70' OBJ.centroid_xy_col    = [xc(1); yc(1) ]; */
    OBJ->centroid_xy_col[0] = the_size_idx_0;
    OBJ->centroid_xy_col[1] = yc;

    /*  MATLAB CODER friendly */
    emxFree_real_T(&x);
    emxFree_real_T(&y);
    emxFree_int32_T(&b_x);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 * function OBJ = box_info_CLS(BW, tf_found)
 */
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
  /* 'box_info_CLS:22' OBJ.BW            = BW; */
  i = OBJ->BW->size[0] * OBJ->BW->size[1];
  OBJ->BW->size[0] = BW->size[0];
  OBJ->BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(sp, OBJ->BW, i, &ub_emlrtRTEI);
  loop_ub = BW->size[0] * BW->size[1];
  for (i = 0; i < loop_ub; i++) {
    OBJ->BW->data[i] = BW->data[i];
  }

  /* 'box_info_CLS:24' OBJ.NUM_ROWS       = size(BW,1); */
  OBJ->NUM_ROWS = BW->size[0];

  /* 'box_info_CLS:25' OBJ.NUM_COLS       = size(BW,2); */
  OBJ->NUM_COLS = 320.0;

  /* 'box_info_CLS:27' OBJ.tf_is_detected = tf_found; */
  OBJ->tf_is_detected = tf_found;

  /* 'box_info_CLS:29' OBJ = OBJ.calc_info(); */
  st.site = &ik_emlrtRSI;
  box_info_CLS_calc_info(&st, OBJ);
}

/* End of code generation (box_info_CLS.c) */
