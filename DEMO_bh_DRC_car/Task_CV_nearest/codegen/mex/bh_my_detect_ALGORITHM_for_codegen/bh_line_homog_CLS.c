/*
 * bh_line_homog_CLS.c
 *
 * Code generation for function 'bh_line_homog_CLS'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_line_homog_CLS.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "error1.h"
#include "diag.h"
#include "eig.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo bg_emlrtRSI = { 35, /* lineNo */
  "bh_line_homog_CLS",                 /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m"/* pathName */
};

static emlrtRSInfo cg_emlrtRSI = { 38, /* lineNo */
  "bh_line_homog_CLS",                 /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m"/* pathName */
};

static emlrtRSInfo dg_emlrtRSI = { 61, /* lineNo */
  "bh_line_homog_CLS",                 /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m"/* pathName */
};

static emlrtRSInfo eg_emlrtRSI = { 68, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo fg_emlrtRSI = { 21, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo gg_emlrtRSI = { 86, /* lineNo */
  "xgemm",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"/* pathName */
};

static emlrtRSInfo hg_emlrtRSI = { 87, /* lineNo */
  "xgemm",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"/* pathName */
};

static emlrtRSInfo hk_emlrtRSI = { 128,/* lineNo */
  "bh_line_homog_CLS",                 /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m"/* pathName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 31,/* lineNo */
  16,                                  /* colNo */
  "bh_line_homog_CLS",                 /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 35,/* lineNo */
  1,                                   /* colNo */
  "bh_line_homog_CLS",                 /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 104,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  295,                                 /* lineNo */
  29,                                  /* colNo */
  "THE_SOL_UV_mat",                    /* aName */
  "bh_line_homog_CLS",                 /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  296,                                 /* lineNo */
  29,                                  /* colNo */
  "THE_SOL_UV_mat",                    /* aName */
  "bh_line_homog_CLS",                 /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */

/*
 * function OBJ = bh_line_homog_CLS(u,v)
 */
void c_bh_line_homog_CLS_bh_line_hom(const emlrtStack *sp, emxArray_real_T *u,
  emxArray_real_T *v, real_T *OBJ_a, real_T *OBJ_b, real_T *OBJ_d, char_T
  OBJ_line_type_data[], int32_T OBJ_line_type_size[2])
{
  int32_T ixstart;
  int32_T i12;
  real_T normal_vec[2];
  boolean_T tf_the_normal_is_horz;
  emxArray_real_T *A;
  emxArray_real_T *a;
  int32_T ix;
  real_T eVec_mat[9];
  creal_T b_eVec_mat[9];
  creal_T eVal_mat[9];
  int32_T itmp;
  real_T theta_deg;
  real_T scale;
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T b_eVal_mat[9];
  real_T THE_SOL_VEC[3];
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  real_T y[3];
  ptrdiff_t ldc_t;
  boolean_T exitg1;
  real_T absxk;
  real_T t;
  boolean_T tf_the_normal_is_vert;
  static const char_T b[4] = { 'V', 'E', 'R', 'T' };

  static const char_T b_b[6] = { 'S', 'L', 'O', 'P', 'E', 'Y' };

  static const char_T c_b[4] = { 'H', 'O', 'R', 'Z' };

  int32_T exitg2;
  static const char_T cv1[6] = { 'S', 'L', 'O', 'P', 'E', 'Y' };

  static const char_T cv2[4] = { 'V', 'E', 'R', 'T' };

  static const char_T cv3[4] = { 'H', 'O', 'R', 'Z' };

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

  /* 'bh_line_homog_CLS:33' u = u(:); */
  ixstart = u->size[0];
  i12 = u->size[0];
  u->size[0] = ixstart;
  emxEnsureCapacity_real_T1(sp, u, i12, &sb_emlrtRTEI);

  /* 'bh_line_homog_CLS:34' v = v(:); */
  ixstart = v->size[0];
  i12 = v->size[0];
  v->size[0] = ixstart;
  emxEnsureCapacity_real_T1(sp, v, i12, &sb_emlrtRTEI);

  /* 'bh_line_homog_CLS:35' A = [u,v, ones(size(u))]; */
  normal_vec[0] = u->size[0];
  st.site = &bg_emlrtRSI;
  b_st.site = &rd_emlrtRSI;
  c_st.site = &sd_emlrtRSI;
  tf_the_normal_is_horz = true;
  if (v->size[0] != u->size[0]) {
    tf_the_normal_is_horz = false;
  }

  if (!tf_the_normal_is_horz) {
    emlrtErrorWithMessageIdR2012b(&c_st, &xc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((int32_T)normal_vec[0] != u->size[0]) {
    tf_the_normal_is_horz = false;
  }

  if (!tf_the_normal_is_horz) {
    emlrtErrorWithMessageIdR2012b(&c_st, &xc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T(&c_st, &A, 2, &tb_emlrtRTEI, true);
  i12 = A->size[0] * A->size[1];
  A->size[0] = u->size[0];
  A->size[1] = 3;
  emxEnsureCapacity_real_T(&b_st, A, i12, &sb_emlrtRTEI);
  ixstart = u->size[0];
  for (i12 = 0; i12 < ixstart; i12++) {
    A->data[i12] = u->data[i12];
  }

  ixstart = v->size[0];
  for (i12 = 0; i12 < ixstart; i12++) {
    A->data[i12 + A->size[0]] = v->data[i12];
  }

  ixstart = (int32_T)normal_vec[0];
  for (i12 = 0; i12 < ixstart; i12++) {
    A->data[i12 + (A->size[0] << 1)] = 1.0;
  }

  emxInit_real_T(&b_st, &a, 2, &sb_emlrtRTEI, true);

  /* 'bh_line_homog_CLS:36' B = [1,0,0; */
  /* 'bh_line_homog_CLS:37'      0,1,0]; */
  /* 'bh_line_homog_CLS:38' [eVec_mat, eVal_mat] = eig(A'* A,  B'*B); */
  st.site = &cg_emlrtRSI;
  i12 = a->size[0] * a->size[1];
  a->size[0] = 3;
  a->size[1] = A->size[0];
  emxEnsureCapacity_real_T(&st, a, i12, &sb_emlrtRTEI);
  ixstart = A->size[0];
  for (i12 = 0; i12 < ixstart; i12++) {
    for (ix = 0; ix < 3; ix++) {
      a->data[ix + a->size[0] * i12] = A->data[i12 + A->size[0] * ix];
    }
  }

  b_st.site = &fg_emlrtRSI;
  if (!(a->size[1] == A->size[0])) {
    emlrtErrorWithMessageIdR2012b(&b_st, &wc_emlrtRTEI, "Coder:MATLAB:innerdim",
      0);
  }

  if ((a->size[1] == 1) || (A->size[0] == 1)) {
    for (i12 = 0; i12 < 3; i12++) {
      for (ix = 0; ix < 3; ix++) {
        eVec_mat[i12 + 3 * ix] = 0.0;
        ixstart = a->size[1];
        for (itmp = 0; itmp < ixstart; itmp++) {
          eVec_mat[i12 + 3 * ix] += a->data[i12 + a->size[0] * itmp] * A->
            data[itmp + A->size[0] * ix];
        }
      }
    }
  } else {
    b_st.site = &eg_emlrtRSI;
    memset(&eVec_mat[0], 0, 9U * sizeof(real_T));
    if (!(a->size[1] < 1)) {
      c_st.site = &gg_emlrtRSI;
      c_st.site = &hg_emlrtRSI;
      theta_deg = 1.0;
      scale = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)3;
      n_t = (ptrdiff_t)3;
      k_t = (ptrdiff_t)a->size[1];
      lda_t = (ptrdiff_t)3;
      ldb_t = (ptrdiff_t)a->size[1];
      ldc_t = (ptrdiff_t)3;
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &theta_deg, &a->data[0], &lda_t,
            &A->data[0], &ldb_t, &scale, &eVec_mat[0], &ldc_t);
    }
  }

  emxFree_real_T(&a);
  emxFree_real_T(&A);
  st.site = &cg_emlrtRSI;
  eig(&st, eVec_mat, b_eVec_mat, eVal_mat);

  /* 'bh_line_homog_CLS:41' eVec_mat = real(eVec_mat); */
  /* 'bh_line_homog_CLS:42' eVal_mat = real(eVal_mat); */
  /* 'bh_line_homog_CLS:45' [~,ind]     = min(abs(diag(eVal_mat))); */
  for (i12 = 0; i12 < 9; i12++) {
    eVec_mat[i12] = b_eVec_mat[i12].re;
    b_eVal_mat[i12] = eVal_mat[i12].re;
  }

  diag(b_eVal_mat, THE_SOL_VEC);
  for (ixstart = 0; ixstart < 3; ixstart++) {
    y[ixstart] = muDoubleScalarAbs(THE_SOL_VEC[ixstart]);
  }

  ixstart = 1;
  theta_deg = y[0];
  itmp = 0;
  if (muDoubleScalarIsNaN(y[0])) {
    ix = 1;
    exitg1 = false;
    while ((!exitg1) && (ix + 1 < 4)) {
      ixstart = ix + 1;
      if (!muDoubleScalarIsNaN(y[ix])) {
        theta_deg = y[ix];
        itmp = ix;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 3) {
    while (ixstart + 1 < 4) {
      if (y[ixstart] < theta_deg) {
        theta_deg = y[ixstart];
        itmp = ixstart;
      }

      ixstart++;
    }
  }

  /* 'bh_line_homog_CLS:45' ~ */
  /* 'bh_line_homog_CLS:47' THE_SOL_VEC = eVec_mat(:,ind); */
  for (i12 = 0; i12 < 3; i12++) {
    THE_SOL_VEC[i12] = b_eVec_mat[i12 + 3 * itmp].re;
  }

  /* 'bh_line_homog_CLS:48' normal_vec  = THE_SOL_VEC(1:2); */
  /* 'bh_line_homog_CLS:51' OBJ.line_type = LOC_classify_line_type(normal_vec); */
  /* 'bh_line_homog_CLS:197' normal_vec = normal_vec / norm(normal_vec); */
  theta_deg = 0.0;
  scale = 3.3121686421112381E-170;
  for (ixstart = 0; ixstart < 2; ixstart++) {
    absxk = muDoubleScalarAbs(eVec_mat[ixstart + 3 * itmp]);
    if (absxk > scale) {
      t = scale / absxk;
      theta_deg = 1.0 + theta_deg * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      theta_deg += t * t;
    }
  }

  theta_deg = scale * muDoubleScalarSqrt(theta_deg);
  for (ixstart = 0; ixstart < 2; ixstart++) {
    normal_vec[ixstart] = THE_SOL_VEC[ixstart] / theta_deg;
  }

  /* 'bh_line_homog_CLS:198' Y          = normal_vec(2); */
  /* 'bh_line_homog_CLS:199' X          = normal_vec(1); */
  /* 'bh_line_homog_CLS:201' theta_rad  = atan2(Y,X); */
  /* 'bh_line_homog_CLS:202' theta_deg  = theta_rad * 180/pi; */
  theta_deg = muDoubleScalarAtan2(normal_vec[1], normal_vec[0]) * 180.0 /
    3.1415926535897931;

  /* 'bh_line_homog_CLS:205' if(theta_deg<0) */
  if (theta_deg < 0.0) {
    /* 'bh_line_homog_CLS:206' theta_deg = 360 + theta_deg; */
    theta_deg += 360.0;
  }

  /* 'bh_line_homog_CLS:210' tf_the_normal_is_horz = false; */
  tf_the_normal_is_horz = false;

  /* 'bh_line_homog_CLS:211' tf_the_normal_is_vert = false; */
  tf_the_normal_is_vert = false;

  /* 'bh_line_homog_CLS:214' TOL_DEG = 2; */
  /* 'bh_line_homog_CLS:215' if(      (theta_deg <= TOL_DEG       )   || ... */
  /* 'bh_line_homog_CLS:216'              (theta_deg >= (360-TOL_DEG) )   || ... */
  /* 'bh_line_homog_CLS:217'          (   (theta_deg >= (180-TOL_DEG) )   && ... */
  /* 'bh_line_homog_CLS:218'              (theta_deg <= (180+TOL_DEG) )   ) ... */
  /* 'bh_line_homog_CLS:219'        ) */
  if ((theta_deg <= 2.0) || (theta_deg >= 358.0) || ((theta_deg >= 178.0) &&
       (theta_deg <= 182.0))) {
    /* 'bh_line_homog_CLS:220' tf_the_normal_is_horz = true; */
    tf_the_normal_is_horz = true;
  } else if (((theta_deg >= 88.0) && (theta_deg <= 92.0)) || ((theta_deg >=
               268.0) && (theta_deg <= 272.0))) {
    /* 'bh_line_homog_CLS:222' elseif(    (theta_deg >= (90-TOL_DEG)  && (theta_deg <= (90+TOL_DEG))) || ... */
    /* 'bh_line_homog_CLS:223'                (theta_deg >= (270-TOL_DEG) && (theta_deg <= (270+TOL_DEG))) ... */
    /* 'bh_line_homog_CLS:224'           ) */
    /* 'bh_line_homog_CLS:225' tf_the_normal_is_vert = true; */
    tf_the_normal_is_vert = true;
  } else {
    /* 'bh_line_homog_CLS:226' else */
  }

  /* 'bh_line_homog_CLS:233' if(true==tf_the_normal_is_horz) */
  if (tf_the_normal_is_horz) {
    /* 'bh_line_homog_CLS:234' a_str = 'VERT'; */
    OBJ_line_type_size[0] = 1;
    OBJ_line_type_size[1] = 4;
    for (i12 = 0; i12 < 4; i12++) {
      OBJ_line_type_data[i12] = b[i12];
    }
  } else if (tf_the_normal_is_vert) {
    /* 'bh_line_homog_CLS:235' elseif(true==tf_the_normal_is_vert) */
    /* 'bh_line_homog_CLS:236' a_str = 'HORZ'; */
    OBJ_line_type_size[0] = 1;
    OBJ_line_type_size[1] = 4;
    for (i12 = 0; i12 < 4; i12++) {
      OBJ_line_type_data[i12] = c_b[i12];
    }
  } else {
    /* 'bh_line_homog_CLS:237' else */
    /* 'bh_line_homog_CLS:238' a_str = 'SLOPEY'; */
    OBJ_line_type_size[0] = 1;
    OBJ_line_type_size[1] = 6;
    for (i12 = 0; i12 < 6; i12++) {
      OBJ_line_type_data[i12] = b_b[i12];
    }
  }

  /* 'bh_line_homog_CLS:53' switch(OBJ.line_type) */
  tf_the_normal_is_horz = false;
  if (OBJ_line_type_size[1] == 6) {
    ixstart = 0;
    do {
      exitg2 = 0;
      if (ixstart + 1 < 7) {
        if (OBJ_line_type_data[ixstart] != cv1[ixstart]) {
          exitg2 = 1;
        } else {
          ixstart++;
        }
      } else {
        tf_the_normal_is_horz = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }

  if (tf_the_normal_is_horz) {
    ixstart = 0;
  } else {
    tf_the_normal_is_horz = false;
    if (OBJ_line_type_size[1] == 4) {
      ixstart = 0;
      do {
        exitg2 = 0;
        if (ixstart + 1 < 5) {
          if (OBJ_line_type_data[ixstart] != cv2[ixstart]) {
            exitg2 = 1;
          } else {
            ixstart++;
          }
        } else {
          tf_the_normal_is_horz = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }

    if (tf_the_normal_is_horz) {
      ixstart = 1;
    } else {
      tf_the_normal_is_horz = false;
      if (OBJ_line_type_size[1] == 4) {
        ixstart = 0;
        do {
          exitg2 = 0;
          if (ixstart + 1 < 5) {
            if (OBJ_line_type_data[ixstart] != cv3[ixstart]) {
              exitg2 = 1;
            } else {
              ixstart++;
            }
          } else {
            tf_the_normal_is_horz = true;
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }

      if (tf_the_normal_is_horz) {
        ixstart = 2;
      } else {
        ixstart = -1;
      }
    }
  }

  switch (ixstart) {
   case 0:
    /* 'bh_line_homog_CLS:54' case 'SLOPEY' */
    /* 'bh_line_homog_CLS:55' THE_SOL_VEC = THE_SOL_VEC / THE_SOL_VEC(2); */
    theta_deg = THE_SOL_VEC[1];
    for (i12 = 0; i12 < 3; i12++) {
      THE_SOL_VEC[i12] = eVec_mat[i12 + 3 * itmp] / theta_deg;
    }
    break;

   case 1:
    /* 'bh_line_homog_CLS:56' case 'VERT' */
    /* 'bh_line_homog_CLS:57' THE_SOL_VEC = THE_SOL_VEC / THE_SOL_VEC(1); */
    theta_deg = THE_SOL_VEC[0];
    for (i12 = 0; i12 < 3; i12++) {
      THE_SOL_VEC[i12] = eVec_mat[i12 + 3 * itmp] / theta_deg;
    }
    break;

   case 2:
    /* 'bh_line_homog_CLS:58' case 'HORZ' */
    /* 'bh_line_homog_CLS:59' THE_SOL_VEC = THE_SOL_VEC / THE_SOL_VEC(2); */
    theta_deg = THE_SOL_VEC[1];
    for (i12 = 0; i12 < 3; i12++) {
      THE_SOL_VEC[i12] = eVec_mat[i12 + 3 * itmp] / theta_deg;
    }
    break;

   default:
    /* 'bh_line_homog_CLS:60' otherwise */
    /* 'bh_line_homog_CLS:61' error('###_ERROR:  unknown line type'); */
    st.site = &dg_emlrtRSI;
    c_error(&st);
    break;
  }

  /* 'bh_line_homog_CLS:64' OBJ.abd_col = THE_SOL_VEC; */
  /* 'bh_line_homog_CLS:65' OBJ.a       = THE_SOL_VEC(1); */
  *OBJ_a = THE_SOL_VEC[0];

  /* 'bh_line_homog_CLS:66' OBJ.b       = THE_SOL_VEC(2); */
  *OBJ_b = THE_SOL_VEC[1];

  /* 'bh_line_homog_CLS:67' OBJ.d       = THE_SOL_VEC(3); */
  *OBJ_d = THE_SOL_VEC[2];
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 * function [tf_is_valid, uv_bot, uv_top] = get_roi_intersection_co_ords(OBJ, ulim, vlim)
 */
void c_bh_line_homog_CLS_get_roi_int(const emlrtStack *sp, real_T OBJ_a, real_T
  OBJ_b, real_T OBJ_d, const char_T OBJ_line_type_data[], const int32_T
  OBJ_line_type_size[2], const real_T vlim[2], boolean_T *tf_is_valid, real_T
  uv_bot[2], real_T uv_top[2])
{
  int32_T i;
  boolean_T b_bool;
  int32_T exitg1;
  static const char_T cv4[4] = { 'V', 'E', 'R', 'T' };

  real_T u;
  real_T v;
  static const char_T cv5[4] = { 'H', 'O', 'R', 'Z' };

  boolean_T tf_east;
  real_T b_v;
  boolean_T tf_north;
  boolean_T tf_south;
  real_T b_u;
  boolean_T the_tf_mat[4];
  real_T the_UV_mat[8];
  int32_T k;
  int32_T trueCount;
  int32_T tmp_data[4];
  real_T the_UV_mat_data[8];
  int32_T b_trueCount;
  int32_T b_tmp_data[4];
  real_T UV_B[2];
  real_T b_the_UV_mat_data[8];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /* 'bh_line_homog_CLS:128' [tf_is_valid, uv_bot, uv_top] = LOC_get_roi_intersection_co_ords(OBJ, ulim, vlim); */
  st.site = &hk_emlrtRSI;

  /* 'bh_line_homog_CLS:244' if(1 == coder.target('MATLAB') ) */
  /* 'bh_line_homog_CLS:249' tf_is_valid = false; */
  *tf_is_valid = false;

  /* 'bh_line_homog_CLS:250' uv_bot = [NaN;NaN]; */
  /* 'bh_line_homog_CLS:251' uv_top = [NaN;NaN]; */
  for (i = 0; i < 2; i++) {
    uv_bot[i] = rtNaN;
    uv_top[i] = rtNaN;
  }

  /* 'bh_line_homog_CLS:253' switch(OBJ.line_type) */
  b_bool = false;
  if (OBJ_line_type_size[1] == 4) {
    i = 0;
    do {
      exitg1 = 0;
      if (i + 1 < 5) {
        if (OBJ_line_type_data[i] != cv4[i]) {
          exitg1 = 1;
        } else {
          i++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    i = 0;
  } else {
    b_bool = false;
    if (OBJ_line_type_size[1] == 4) {
      i = 0;
      do {
        exitg1 = 0;
        if (i + 1 < 5) {
          if (OBJ_line_type_data[i] != cv5[i]) {
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      i = 1;
    } else {
      i = -1;
    }
  }

  switch (i) {
   case 0:
    /* 'bh_line_homog_CLS:254' case 'VERT' */
    /* 'bh_line_homog_CLS:255' u = (-1*OBJ.d/OBJ.a); */
    u = -OBJ_d / OBJ_a;

    /* 'bh_line_homog_CLS:256' if( (u <= ulim(2)) && (u>=ulim(1)) ) */
    if ((u <= 320.0) && (u >= 1.0)) {
      /* 'bh_line_homog_CLS:257' uv_bot = [u;vlim(2)]; */
      uv_bot[0] = u;
      uv_bot[1] = vlim[1];

      /* 'bh_line_homog_CLS:258' uv_top = [u;vlim(1)]; */
      uv_top[0] = u;
      uv_top[1] = 1.0;

      /* 'bh_line_homog_CLS:259' tf_is_valid = true; */
      *tf_is_valid = true;
    }
    break;

   case 1:
    /* 'bh_line_homog_CLS:263' case 'HORZ' */
    /* 'bh_line_homog_CLS:264' v = (-OBJ.d/OBJ.b); */
    v = -OBJ_d / OBJ_b;

    /* 'bh_line_homog_CLS:265' if( (v <= vlim(2)) && (v>=vlim(1)) ) */
    if ((v <= vlim[1]) && (v >= 1.0)) {
      /* 'bh_line_homog_CLS:266' uv_bot = [ulim(1);v]; */
      uv_bot[0] = 1.0;
      uv_bot[1] = v;

      /* 'bh_line_homog_CLS:267' uv_top = [ulim(2);v]; */
      uv_top[0] = 320.0;
      uv_top[1] = v;

      /* 'bh_line_homog_CLS:268' tf_is_valid = true; */
      *tf_is_valid = true;
    }
    break;

   default:
    /* 'bh_line_homog_CLS:276' my_Vf = @(U) (-1*(OBJ.d + OBJ.a*U)/OBJ.b); */
    /* 'bh_line_homog_CLS:277' my_Uf = @(V) (-1*(OBJ.d + OBJ.b*V)/OBJ.a); */
    /* 'bh_line_homog_CLS:279' [tf_west,  UV_west ] = LOC_get_side_intersect_point('WEST',  my_Vf, my_Uf, ulim, vlim); */
    /*  BH_LINE_HOMOG_CLS - Regression fit for Homogeneous co-ordinate representation of a line */
    /* ========================================================================== */
    /*  The Homogeneous representation of a line is: */
    /*  */
    /*      a.U + b.V + d = 0 */
    /* ========================================================================== */
    /*  USAGE: */
    /*     OBJ   = bh_line_homog_CLS(u,v); */
    /*   */
    /*     hax = OBJ.plot_simple(u,v);   axis equal; grid on; */
    /*   */
    /*     ulim = [5, 10]; */
    /*     vlim = [-4, 10]; */
    /*   */
    /*     [tf_is_valid, uv_bot, uv_top] = OBJ.get_roi_intersection_co_ords(ulim, vlim); */
    /*   */
    /*     */
    /*     OBJ.plot_intersection(hax, 'r', ulim, vlim, true); */
    /* ========================================================================== */
    /* char {mustBeMember(line_type,{'HORZ','VERT','SLOPEY','UNKNOWN'})} = 'UNKNOWN'; */
    /*  for codegen */
    /*  where's the smallest eigenvalue */
    /*  classify the type of line */
    /*  bh_line_homog_CLS */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*  a.U + b.V + d = 0 */
    /*  then we have a VERTICAL ||| line */
    /*  a COL        */
    /*  a.U + b.V + d = 0 */
    /*  then we have a HORIZONTAL --- line */
    /*  a COL */
    /*  a.U + b.V + d = 0 */
    /*  then we have a SLOPEY ///\\\ line */
    /* ==========================================================================  */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* plot(hax,u,v,'-m','LineWidth',2); */
    /*  plot the line    */
    /*  plot an o for the TOP point */
    /*  plot an o for the BOT point       */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*   b.V = -a.U + -d */
    /*  m */
    /*  c */
    /* ========================================================================== */
    /*  methods */
    /* ========================================================================== */
    /*  classdef */
    /* _######################################################################### */
    /*  Local HELPER functions */
    /* _######################################################################### */
    /*  V */
    /*  U */
    /*  [-pi , pi] */
    /*  [-180, 180] */
    /*  convert angle from [-180,180] to [0, 360] */
    /*  first categorise the NORMAL to the line */
    /*   so we have   0 <= theta_deg <= 360 */
    /*  a tolerence */
    /*  do NOTHING */
    /*  OK: so we know the orientation of the NORMAL vector */
    /*      now we can classify the actual LINE */
    /* LOC_classify_line_type */
    /* ========================================================================== */
    /*  RETURN */
    /*  RETURN */
    /*  so if we made it to here then we have a SLOPEY line */
    /*   a.U + b.V + d = 0 */
    /*  OK: so our line has intersected our ROI box */
    /*  LOC_get_roi_intersection_co_ords() */
    /* ========================================================================== */
    /*  LOC_UV_is_in_box(() */
    /* ========================================================================== */
    /*  SUMMARY: */
    /*    for a specified side of an ROI box, where (if at all) */
    /*    does our line intersect that side of teh ROI box */
    /* 'bh_line_homog_CLS:332' UV = [0;0]; */
    /* 'bh_line_homog_CLS:333' tf_valid_intersection = false; */
    b_bool = false;

    /*  assert that our side_str INPUT argument is a valid */
    /* mustBeMember(side_str, ["NORTH","SOUTH","EAST","WEST"] ); */
    /*   */
    /*           0------------------------------> U */
    /*           | */
    /*           |               NORTH */
    /*           |           *-------------* */
    /*           |          |              | */
    /*           |          |              | */
    /*           |    WEST  |              |  EAST */
    /*           |          |              |  */
    /*           |          |              | */
    /*           |          *--------------* */
    /*           |               SOUTH     */
    /*       V   V    */
    /* 'bh_line_homog_CLS:352' FH_in_V_zone = @(V) ( (V <= vlim(2)) & (V >= vlim(1)) ); */
    /* 'bh_line_homog_CLS:353' FH_in_U_zone = @(U) ( (U <= ulim(2)) & (U >= ulim(1)) ); */
    /* 'bh_line_homog_CLS:355' switch(side_str) */
    /* 'bh_line_homog_CLS:356' case 'WEST' */
    /* 'bh_line_homog_CLS:357' u = ulim(1); */
    /* 'bh_line_homog_CLS:357' v = my_Vf(u); */
    v = -(OBJ_d + OBJ_a) / OBJ_b;

    /* 'bh_line_homog_CLS:358' UV = [u;v]; */
    /* 'bh_line_homog_CLS:359' if( FH_in_V_zone(v) ) */
    if ((v <= vlim[1]) && (v >= 1.0)) {
      /* 'bh_line_homog_CLS:360' tf_valid_intersection = true; */
      b_bool = true;
    }

    /* 'bh_line_homog_CLS:280' [tf_east,  UV_east ] = LOC_get_side_intersect_point('EAST',  my_Vf, my_Uf, ulim, vlim); */
    /*  BH_LINE_HOMOG_CLS - Regression fit for Homogeneous co-ordinate representation of a line */
    /* ========================================================================== */
    /*  The Homogeneous representation of a line is: */
    /*  */
    /*      a.U + b.V + d = 0 */
    /* ========================================================================== */
    /*  USAGE: */
    /*     OBJ   = bh_line_homog_CLS(u,v); */
    /*   */
    /*     hax = OBJ.plot_simple(u,v);   axis equal; grid on; */
    /*   */
    /*     ulim = [5, 10]; */
    /*     vlim = [-4, 10]; */
    /*   */
    /*     [tf_is_valid, uv_bot, uv_top] = OBJ.get_roi_intersection_co_ords(ulim, vlim); */
    /*   */
    /*     */
    /*     OBJ.plot_intersection(hax, 'r', ulim, vlim, true); */
    /* ========================================================================== */
    /* char {mustBeMember(line_type,{'HORZ','VERT','SLOPEY','UNKNOWN'})} = 'UNKNOWN'; */
    /*  for codegen */
    /*  where's the smallest eigenvalue */
    /*  classify the type of line */
    /*  bh_line_homog_CLS */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*  a.U + b.V + d = 0 */
    /*  then we have a VERTICAL ||| line */
    /*  a COL        */
    /*  a.U + b.V + d = 0 */
    /*  then we have a HORIZONTAL --- line */
    /*  a COL */
    /*  a.U + b.V + d = 0 */
    /*  then we have a SLOPEY ///\\\ line */
    /* ==========================================================================  */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* plot(hax,u,v,'-m','LineWidth',2); */
    /*  plot the line    */
    /*  plot an o for the TOP point */
    /*  plot an o for the BOT point       */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*   b.V = -a.U + -d */
    /*  m */
    /*  c */
    /* ========================================================================== */
    /*  methods */
    /* ========================================================================== */
    /*  classdef */
    /* _######################################################################### */
    /*  Local HELPER functions */
    /* _######################################################################### */
    /*  V */
    /*  U */
    /*  [-pi , pi] */
    /*  [-180, 180] */
    /*  convert angle from [-180,180] to [0, 360] */
    /*  first categorise the NORMAL to the line */
    /*   so we have   0 <= theta_deg <= 360 */
    /*  a tolerence */
    /*  do NOTHING */
    /*  OK: so we know the orientation of the NORMAL vector */
    /*      now we can classify the actual LINE */
    /* LOC_classify_line_type */
    /* ========================================================================== */
    /*  RETURN */
    /*  RETURN */
    /*  so if we made it to here then we have a SLOPEY line */
    /*   a.U + b.V + d = 0 */
    /*  OK: so our line has intersected our ROI box */
    /*  LOC_get_roi_intersection_co_ords() */
    /* ========================================================================== */
    /*  LOC_UV_is_in_box(() */
    /* ========================================================================== */
    /*  SUMMARY: */
    /*    for a specified side of an ROI box, where (if at all) */
    /*    does our line intersect that side of teh ROI box */
    /* 'bh_line_homog_CLS:332' UV = [0;0]; */
    /* 'bh_line_homog_CLS:333' tf_valid_intersection = false; */
    tf_east = false;

    /*  assert that our side_str INPUT argument is a valid */
    /* mustBeMember(side_str, ["NORTH","SOUTH","EAST","WEST"] ); */
    /*   */
    /*           0------------------------------> U */
    /*           | */
    /*           |               NORTH */
    /*           |           *-------------* */
    /*           |          |              | */
    /*           |          |              | */
    /*           |    WEST  |              |  EAST */
    /*           |          |              |  */
    /*           |          |              | */
    /*           |          *--------------* */
    /*           |               SOUTH     */
    /*       V   V    */
    /* 'bh_line_homog_CLS:352' FH_in_V_zone = @(V) ( (V <= vlim(2)) & (V >= vlim(1)) ); */
    /* 'bh_line_homog_CLS:353' FH_in_U_zone = @(U) ( (U <= ulim(2)) & (U >= ulim(1)) ); */
    /* 'bh_line_homog_CLS:355' switch(side_str) */
    /* 'bh_line_homog_CLS:362' case 'EAST' */
    /* 'bh_line_homog_CLS:363' u = ulim(2); */
    /* 'bh_line_homog_CLS:363' v = my_Vf(u); */
    b_v = -(OBJ_d + OBJ_a * 320.0) / OBJ_b;

    /* 'bh_line_homog_CLS:364' UV = [u;v]; */
    /* 'bh_line_homog_CLS:365' if( FH_in_V_zone(v) ) */
    if ((b_v <= vlim[1]) && (b_v >= 1.0)) {
      /* 'bh_line_homog_CLS:366' tf_valid_intersection = true; */
      tf_east = true;
    }

    /* 'bh_line_homog_CLS:281' [tf_north, UV_north] = LOC_get_side_intersect_point('NORTH', my_Vf, my_Uf, ulim, vlim); */
    /*  BH_LINE_HOMOG_CLS - Regression fit for Homogeneous co-ordinate representation of a line */
    /* ========================================================================== */
    /*  The Homogeneous representation of a line is: */
    /*  */
    /*      a.U + b.V + d = 0 */
    /* ========================================================================== */
    /*  USAGE: */
    /*     OBJ   = bh_line_homog_CLS(u,v); */
    /*   */
    /*     hax = OBJ.plot_simple(u,v);   axis equal; grid on; */
    /*   */
    /*     ulim = [5, 10]; */
    /*     vlim = [-4, 10]; */
    /*   */
    /*     [tf_is_valid, uv_bot, uv_top] = OBJ.get_roi_intersection_co_ords(ulim, vlim); */
    /*   */
    /*     */
    /*     OBJ.plot_intersection(hax, 'r', ulim, vlim, true); */
    /* ========================================================================== */
    /* char {mustBeMember(line_type,{'HORZ','VERT','SLOPEY','UNKNOWN'})} = 'UNKNOWN'; */
    /*  for codegen */
    /*  where's the smallest eigenvalue */
    /*  classify the type of line */
    /*  bh_line_homog_CLS */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*  a.U + b.V + d = 0 */
    /*  then we have a VERTICAL ||| line */
    /*  a COL        */
    /*  a.U + b.V + d = 0 */
    /*  then we have a HORIZONTAL --- line */
    /*  a COL */
    /*  a.U + b.V + d = 0 */
    /*  then we have a SLOPEY ///\\\ line */
    /* ==========================================================================  */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* plot(hax,u,v,'-m','LineWidth',2); */
    /*  plot the line    */
    /*  plot an o for the TOP point */
    /*  plot an o for the BOT point       */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*   b.V = -a.U + -d */
    /*  m */
    /*  c */
    /* ========================================================================== */
    /*  methods */
    /* ========================================================================== */
    /*  classdef */
    /* _######################################################################### */
    /*  Local HELPER functions */
    /* _######################################################################### */
    /*  V */
    /*  U */
    /*  [-pi , pi] */
    /*  [-180, 180] */
    /*  convert angle from [-180,180] to [0, 360] */
    /*  first categorise the NORMAL to the line */
    /*   so we have   0 <= theta_deg <= 360 */
    /*  a tolerence */
    /*  do NOTHING */
    /*  OK: so we know the orientation of the NORMAL vector */
    /*      now we can classify the actual LINE */
    /* LOC_classify_line_type */
    /* ========================================================================== */
    /*  RETURN */
    /*  RETURN */
    /*  so if we made it to here then we have a SLOPEY line */
    /*   a.U + b.V + d = 0 */
    /*  OK: so our line has intersected our ROI box */
    /*  LOC_get_roi_intersection_co_ords() */
    /* ========================================================================== */
    /*  LOC_UV_is_in_box(() */
    /* ========================================================================== */
    /*  SUMMARY: */
    /*    for a specified side of an ROI box, where (if at all) */
    /*    does our line intersect that side of teh ROI box */
    /* 'bh_line_homog_CLS:332' UV = [0;0]; */
    /* 'bh_line_homog_CLS:333' tf_valid_intersection = false; */
    tf_north = false;

    /*  assert that our side_str INPUT argument is a valid */
    /* mustBeMember(side_str, ["NORTH","SOUTH","EAST","WEST"] ); */
    /*   */
    /*           0------------------------------> U */
    /*           | */
    /*           |               NORTH */
    /*           |           *-------------* */
    /*           |          |              | */
    /*           |          |              | */
    /*           |    WEST  |              |  EAST */
    /*           |          |              |  */
    /*           |          |              | */
    /*           |          *--------------* */
    /*           |               SOUTH     */
    /*       V   V    */
    /* 'bh_line_homog_CLS:352' FH_in_V_zone = @(V) ( (V <= vlim(2)) & (V >= vlim(1)) ); */
    /* 'bh_line_homog_CLS:353' FH_in_U_zone = @(U) ( (U <= ulim(2)) & (U >= ulim(1)) ); */
    /* 'bh_line_homog_CLS:355' switch(side_str) */
    /* 'bh_line_homog_CLS:368' case 'NORTH' */
    /* 'bh_line_homog_CLS:369' v = vlim(1); */
    /* 'bh_line_homog_CLS:369' u = my_Uf(v); */
    u = -(OBJ_d + OBJ_b) / OBJ_a;

    /* 'bh_line_homog_CLS:370' UV = [u;v]; */
    /* 'bh_line_homog_CLS:371' if( FH_in_U_zone(u) ) */
    if ((u <= 320.0) && (u >= 1.0)) {
      /* 'bh_line_homog_CLS:372' tf_valid_intersection = true; */
      tf_north = true;
    }

    /* 'bh_line_homog_CLS:282' [tf_south, UV_south] = LOC_get_side_intersect_point('SOUTH', my_Vf, my_Uf, ulim, vlim); */
    /*  BH_LINE_HOMOG_CLS - Regression fit for Homogeneous co-ordinate representation of a line */
    /* ========================================================================== */
    /*  The Homogeneous representation of a line is: */
    /*  */
    /*      a.U + b.V + d = 0 */
    /* ========================================================================== */
    /*  USAGE: */
    /*     OBJ   = bh_line_homog_CLS(u,v); */
    /*   */
    /*     hax = OBJ.plot_simple(u,v);   axis equal; grid on; */
    /*   */
    /*     ulim = [5, 10]; */
    /*     vlim = [-4, 10]; */
    /*   */
    /*     [tf_is_valid, uv_bot, uv_top] = OBJ.get_roi_intersection_co_ords(ulim, vlim); */
    /*   */
    /*     */
    /*     OBJ.plot_intersection(hax, 'r', ulim, vlim, true); */
    /* ========================================================================== */
    /* char {mustBeMember(line_type,{'HORZ','VERT','SLOPEY','UNKNOWN'})} = 'UNKNOWN'; */
    /*  for codegen */
    /*  where's the smallest eigenvalue */
    /*  classify the type of line */
    /*  bh_line_homog_CLS */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*  a.U + b.V + d = 0 */
    /*  then we have a VERTICAL ||| line */
    /*  a COL        */
    /*  a.U + b.V + d = 0 */
    /*  then we have a HORIZONTAL --- line */
    /*  a COL */
    /*  a.U + b.V + d = 0 */
    /*  then we have a SLOPEY ///\\\ line */
    /* ==========================================================================  */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* plot(hax,u,v,'-m','LineWidth',2); */
    /*  plot the line    */
    /*  plot an o for the TOP point */
    /*  plot an o for the BOT point       */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*   b.V = -a.U + -d */
    /*  m */
    /*  c */
    /* ========================================================================== */
    /*  methods */
    /* ========================================================================== */
    /*  classdef */
    /* _######################################################################### */
    /*  Local HELPER functions */
    /* _######################################################################### */
    /*  V */
    /*  U */
    /*  [-pi , pi] */
    /*  [-180, 180] */
    /*  convert angle from [-180,180] to [0, 360] */
    /*  first categorise the NORMAL to the line */
    /*   so we have   0 <= theta_deg <= 360 */
    /*  a tolerence */
    /*  do NOTHING */
    /*  OK: so we know the orientation of the NORMAL vector */
    /*      now we can classify the actual LINE */
    /* LOC_classify_line_type */
    /* ========================================================================== */
    /*  RETURN */
    /*  RETURN */
    /*  so if we made it to here then we have a SLOPEY line */
    /*   a.U + b.V + d = 0 */
    /*  OK: so our line has intersected our ROI box */
    /*  LOC_get_roi_intersection_co_ords() */
    /* ========================================================================== */
    /*  LOC_UV_is_in_box(() */
    /* ========================================================================== */
    /*  SUMMARY: */
    /*    for a specified side of an ROI box, where (if at all) */
    /*    does our line intersect that side of teh ROI box */
    /* 'bh_line_homog_CLS:332' UV = [0;0]; */
    /* 'bh_line_homog_CLS:333' tf_valid_intersection = false; */
    tf_south = false;

    /*  assert that our side_str INPUT argument is a valid */
    /* mustBeMember(side_str, ["NORTH","SOUTH","EAST","WEST"] ); */
    /*   */
    /*           0------------------------------> U */
    /*           | */
    /*           |               NORTH */
    /*           |           *-------------* */
    /*           |          |              | */
    /*           |          |              | */
    /*           |    WEST  |              |  EAST */
    /*           |          |              |  */
    /*           |          |              | */
    /*           |          *--------------* */
    /*           |               SOUTH     */
    /*       V   V    */
    /* 'bh_line_homog_CLS:352' FH_in_V_zone = @(V) ( (V <= vlim(2)) & (V >= vlim(1)) ); */
    /* 'bh_line_homog_CLS:353' FH_in_U_zone = @(U) ( (U <= ulim(2)) & (U >= ulim(1)) ); */
    /* 'bh_line_homog_CLS:355' switch(side_str) */
    /* 'bh_line_homog_CLS:374' case 'SOUTH' */
    /* 'bh_line_homog_CLS:375' v = vlim(2); */
    /* 'bh_line_homog_CLS:375' u = my_Uf(v); */
    b_u = -(OBJ_d + OBJ_b * vlim[1]) / OBJ_a;

    /* 'bh_line_homog_CLS:376' UV = [u;v]; */
    /* 'bh_line_homog_CLS:377' if( FH_in_U_zone(u) ) */
    if ((b_u <= 320.0) && (b_u >= 1.0)) {
      /* 'bh_line_homog_CLS:378' tf_valid_intersection = true; */
      tf_south = true;
    }

    /* 'bh_line_homog_CLS:284' the_tf_mat = [tf_west, tf_east, tf_north, tf_south]; */
    the_tf_mat[0] = b_bool;
    the_tf_mat[1] = tf_east;
    the_tf_mat[2] = tf_north;
    the_tf_mat[3] = tf_south;

    /* 'bh_line_homog_CLS:285' the_UV_mat = [UV_west, UV_east, UV_north, UV_south]; */
    the_UV_mat[0] = 1.0;
    the_UV_mat[1] = v;
    the_UV_mat[2] = 320.0;
    the_UV_mat[3] = b_v;
    the_UV_mat[4] = u;
    the_UV_mat[5] = 1.0;
    the_UV_mat[6] = b_u;
    the_UV_mat[7] = vlim[1];

    /* 'bh_line_homog_CLS:287' if(2 ~= nnz(the_tf_mat) ) */
    i = 0;
    for (k = 0; k < 4; k++) {
      if (the_tf_mat[k]) {
        i++;
      }
    }

    if (2 == i) {
      /* 'bh_line_homog_CLS:293' THE_SOL_UV_mat = the_UV_mat(:,the_tf_mat ); */
      /* 'bh_line_homog_CLS:295' UV_A = THE_SOL_UV_mat(:,1); */
      trueCount = 0;
      for (i = 0; i < 4; i++) {
        if (the_tf_mat[i]) {
          trueCount++;
        }
      }

      if (!(1 <= trueCount)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, trueCount, &yc_emlrtBCI, &st);
      }

      trueCount = 0;
      for (i = 0; i < 4; i++) {
        if (the_tf_mat[i]) {
          trueCount++;
        }
      }

      k = 0;
      for (i = 0; i < 4; i++) {
        if (the_tf_mat[i]) {
          tmp_data[k] = i + 1;
          k++;
        }
      }

      for (k = 0; k < trueCount; k++) {
        for (i = 0; i < 2; i++) {
          the_UV_mat_data[i + (k << 1)] = the_UV_mat[i + ((tmp_data[k] - 1) << 1)];
        }
      }

      for (k = 0; k < 2; k++) {
        uv_top[k] = the_UV_mat_data[k];
      }

      /* 'bh_line_homog_CLS:296' UV_B = THE_SOL_UV_mat(:,2); */
      b_trueCount = 0;
      for (i = 0; i < 4; i++) {
        if (the_tf_mat[i]) {
          b_trueCount++;
        }
      }

      if (!(2 <= b_trueCount)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_trueCount, &ad_emlrtBCI, &st);
      }

      b_trueCount = 0;
      for (i = 0; i < 4; i++) {
        if (the_tf_mat[i]) {
          b_trueCount++;
        }
      }

      k = 0;
      for (i = 0; i < 4; i++) {
        if (the_tf_mat[i]) {
          b_tmp_data[k] = i + 1;
          k++;
        }
      }

      for (k = 0; k < b_trueCount; k++) {
        for (i = 0; i < 2; i++) {
          the_UV_mat_data[i + (k << 1)] = the_UV_mat[i + ((b_tmp_data[k] - 1) <<
            1)];
        }
      }

      for (k = 0; k < 2; k++) {
        UV_B[k] = the_UV_mat_data[k + 2];
      }

      /* 'bh_line_homog_CLS:298' if( UV_A(2) > UV_B(2)) */
      for (k = 0; k < trueCount; k++) {
        for (i = 0; i < 2; i++) {
          the_UV_mat_data[i + (k << 1)] = the_UV_mat[i + ((tmp_data[k] - 1) << 1)];
        }
      }

      for (k = 0; k < b_trueCount; k++) {
        for (i = 0; i < 2; i++) {
          b_the_UV_mat_data[i + (k << 1)] = the_UV_mat[i + ((b_tmp_data[k] - 1) <<
            1)];
        }
      }

      if (the_UV_mat_data[1] > b_the_UV_mat_data[3]) {
        /* 'bh_line_homog_CLS:299' uv_bot = UV_A; */
        /* 'bh_line_homog_CLS:300' uv_top = UV_B; */
        for (i = 0; i < 2; i++) {
          uv_bot[i] = uv_top[i];
          uv_top[i] = UV_B[i];
        }
      } else {
        /* 'bh_line_homog_CLS:301' else */
        /* 'bh_line_homog_CLS:302' uv_bot = UV_B; */
        for (i = 0; i < 2; i++) {
          uv_bot[i] = UV_B[i];
        }

        /* 'bh_line_homog_CLS:303' uv_top = UV_A; */
      }

      /* 'bh_line_homog_CLS:305' tf_is_valid = true; */
      *tf_is_valid = true;
    }
    break;
  }
}

/* End of code generation (bh_line_homog_CLS.c) */
