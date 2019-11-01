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

static emlrtRTEInfo pd_emlrtRTEI = { 33,/* lineNo */
  1,                                   /* colNo */
  "bh_line_homog_CLS",                 /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m"/* pName */
};

static emlrtRTEInfo qd_emlrtRTEI = { 34,/* lineNo */
  1,                                   /* colNo */
  "bh_line_homog_CLS",                 /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m"/* pName */
};

static emlrtRTEInfo rd_emlrtRTEI = { 35,/* lineNo */
  1,                                   /* colNo */
  "bh_line_homog_CLS",                 /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m"/* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = { 38,/* lineNo */
  28,                                  /* colNo */
  "bh_line_homog_CLS",                 /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m"/* pName */
};

static emlrtRTEInfo wf_emlrtRTEI = { 104,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  295,                                 /* lineNo */
  29,                                  /* colNo */
  "THE_SOL_UV_mat",                    /* aName */
  "bh_line_homog_CLS",                 /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  296,                                 /* lineNo */
  29,                                  /* colNo */
  "THE_SOL_UV_mat",                    /* aName */
  "bh_line_homog_CLS",                 /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\bh_line_homog_CLS.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void c_bh_line_homog_CLS_bh_line_hom(const emlrtStack *sp, emxArray_real_T *u,
  emxArray_real_T *v, real_T *OBJ_a, real_T *OBJ_b, real_T *OBJ_d, char_T
  OBJ_line_type_data[], int32_T OBJ_line_type_size[2])
{
  int32_T ixstart;
  int32_T i11;
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
  real_T b_eVal_mat[9];
  real_T THE_SOL_VEC[3];
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T y[3];
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
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
  ixstart = u->size[0];
  i11 = u->size[0];
  u->size[0] = ixstart;
  emxEnsureCapacity_real_T1(sp, u, i11, &pd_emlrtRTEI);
  ixstart = v->size[0];
  i11 = v->size[0];
  v->size[0] = ixstart;
  emxEnsureCapacity_real_T1(sp, v, i11, &qd_emlrtRTEI);
  normal_vec[0] = u->size[0];
  st.site = &bg_emlrtRSI;
  b_st.site = &rd_emlrtRSI;
  c_st.site = &sd_emlrtRSI;
  tf_the_normal_is_horz = true;
  if (v->size[0] != u->size[0]) {
    tf_the_normal_is_horz = false;
  }

  if (!tf_the_normal_is_horz) {
    emlrtErrorWithMessageIdR2012b(&c_st, &xf_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((int32_T)normal_vec[0] != u->size[0]) {
    tf_the_normal_is_horz = false;
  }

  if (!tf_the_normal_is_horz) {
    emlrtErrorWithMessageIdR2012b(&c_st, &xf_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T(&c_st, &A, 2, &rd_emlrtRTEI, true);
  i11 = A->size[0] * A->size[1];
  A->size[0] = u->size[0];
  A->size[1] = 3;
  emxEnsureCapacity_real_T(&b_st, A, i11, &rd_emlrtRTEI);
  ixstart = u->size[0];
  for (i11 = 0; i11 < ixstart; i11++) {
    A->data[i11] = u->data[i11];
  }

  ixstart = v->size[0];
  for (i11 = 0; i11 < ixstart; i11++) {
    A->data[i11 + A->size[0]] = v->data[i11];
  }

  ixstart = (int32_T)normal_vec[0];
  for (i11 = 0; i11 < ixstart; i11++) {
    A->data[i11 + (A->size[0] << 1)] = 1.0;
  }

  emxInit_real_T(&b_st, &a, 2, &sd_emlrtRTEI, true);
  st.site = &cg_emlrtRSI;
  i11 = a->size[0] * a->size[1];
  a->size[0] = 3;
  a->size[1] = A->size[0];
  emxEnsureCapacity_real_T(&st, a, i11, &sd_emlrtRTEI);
  ixstart = A->size[0];
  for (i11 = 0; i11 < ixstart; i11++) {
    for (ix = 0; ix < 3; ix++) {
      a->data[ix + a->size[0] * i11] = A->data[i11 + A->size[0] * ix];
    }
  }

  b_st.site = &fg_emlrtRSI;
  if (!(a->size[1] == A->size[0])) {
    emlrtErrorWithMessageIdR2012b(&b_st, &wf_emlrtRTEI, "Coder:MATLAB:innerdim",
      0);
  }

  if ((a->size[1] == 1) || (A->size[0] == 1)) {
    for (i11 = 0; i11 < 3; i11++) {
      for (ix = 0; ix < 3; ix++) {
        eVec_mat[i11 + 3 * ix] = 0.0;
        ixstart = a->size[1];
        for (itmp = 0; itmp < ixstart; itmp++) {
          eVec_mat[i11 + 3 * ix] += a->data[i11 + a->size[0] * itmp] * A->
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
  for (i11 = 0; i11 < 9; i11++) {
    eVec_mat[i11] = b_eVec_mat[i11].re;
    b_eVal_mat[i11] = eVal_mat[i11].re;
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

  for (i11 = 0; i11 < 3; i11++) {
    THE_SOL_VEC[i11] = b_eVec_mat[i11 + 3 * itmp].re;
  }

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

  theta_deg = muDoubleScalarAtan2(normal_vec[1], normal_vec[0]) * 180.0 /
    3.1415926535897931;
  if (theta_deg < 0.0) {
    theta_deg += 360.0;
  }

  tf_the_normal_is_horz = false;
  tf_the_normal_is_vert = false;
  if ((theta_deg <= 2.0) || (theta_deg >= 358.0) || ((theta_deg >= 178.0) &&
       (theta_deg <= 182.0))) {
    tf_the_normal_is_horz = true;
  } else {
    if (((theta_deg >= 88.0) && (theta_deg <= 92.0)) || ((theta_deg >= 268.0) &&
         (theta_deg <= 272.0))) {
      tf_the_normal_is_vert = true;
    }
  }

  if (tf_the_normal_is_horz) {
    OBJ_line_type_size[0] = 1;
    OBJ_line_type_size[1] = 4;
    for (i11 = 0; i11 < 4; i11++) {
      OBJ_line_type_data[i11] = b[i11];
    }
  } else if (tf_the_normal_is_vert) {
    OBJ_line_type_size[0] = 1;
    OBJ_line_type_size[1] = 4;
    for (i11 = 0; i11 < 4; i11++) {
      OBJ_line_type_data[i11] = c_b[i11];
    }
  } else {
    OBJ_line_type_size[0] = 1;
    OBJ_line_type_size[1] = 6;
    for (i11 = 0; i11 < 6; i11++) {
      OBJ_line_type_data[i11] = b_b[i11];
    }
  }

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
    theta_deg = THE_SOL_VEC[1];
    for (i11 = 0; i11 < 3; i11++) {
      THE_SOL_VEC[i11] = eVec_mat[i11 + 3 * itmp] / theta_deg;
    }
    break;

   case 1:
    theta_deg = THE_SOL_VEC[0];
    for (i11 = 0; i11 < 3; i11++) {
      THE_SOL_VEC[i11] = eVec_mat[i11 + 3 * itmp] / theta_deg;
    }
    break;

   case 2:
    theta_deg = THE_SOL_VEC[1];
    for (i11 = 0; i11 < 3; i11++) {
      THE_SOL_VEC[i11] = eVec_mat[i11 + 3 * itmp] / theta_deg;
    }
    break;

   default:
    st.site = &dg_emlrtRSI;
    c_error(&st);
    break;
  }

  *OBJ_a = THE_SOL_VEC[0];
  *OBJ_b = THE_SOL_VEC[1];
  *OBJ_d = THE_SOL_VEC[2];
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

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
  int32_T b_trueCount;
  real_T the_UV_mat_data[8];
  int32_T b_tmp_data[4];
  real_T UV_B[2];
  real_T b_the_UV_mat_data[8];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hk_emlrtRSI;
  *tf_is_valid = false;
  for (i = 0; i < 2; i++) {
    uv_bot[i] = rtNaN;
    uv_top[i] = rtNaN;
  }

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
    u = -OBJ_d / OBJ_a;
    if ((u <= 320.0) && (u >= 1.0)) {
      uv_bot[0] = u;
      uv_bot[1] = vlim[1];
      uv_top[0] = u;
      uv_top[1] = 1.0;
      *tf_is_valid = true;
    }
    break;

   case 1:
    v = -OBJ_d / OBJ_b;
    if ((v <= vlim[1]) && (v >= 1.0)) {
      uv_bot[0] = 1.0;
      uv_bot[1] = v;
      uv_top[0] = 320.0;
      uv_top[1] = v;
      *tf_is_valid = true;
    }
    break;

   default:
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
    v = -(OBJ_d + OBJ_a) / OBJ_b;
    if ((v <= vlim[1]) && (v >= 1.0)) {
      b_bool = true;
    }

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
    b_v = -(OBJ_d + OBJ_a * 320.0) / OBJ_b;
    if ((b_v <= vlim[1]) && (b_v >= 1.0)) {
      tf_east = true;
    }

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
    u = -(OBJ_d + OBJ_b) / OBJ_a;
    if ((u <= 320.0) && (u >= 1.0)) {
      tf_north = true;
    }

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
    b_u = -(OBJ_d + OBJ_b * vlim[1]) / OBJ_a;
    if ((b_u <= 320.0) && (b_u >= 1.0)) {
      tf_south = true;
    }

    the_tf_mat[0] = b_bool;
    the_tf_mat[1] = tf_east;
    the_tf_mat[2] = tf_north;
    the_tf_mat[3] = tf_south;
    the_UV_mat[0] = 1.0;
    the_UV_mat[1] = v;
    the_UV_mat[2] = 320.0;
    the_UV_mat[3] = b_v;
    the_UV_mat[4] = u;
    the_UV_mat[5] = 1.0;
    the_UV_mat[6] = b_u;
    the_UV_mat[7] = vlim[1];
    i = 0;
    for (k = 0; k < 4; k++) {
      if (the_tf_mat[k]) {
        i++;
      }
    }

    if (2 == i) {
      trueCount = 0;
      for (i = 0; i < 4; i++) {
        if (the_tf_mat[i]) {
          trueCount++;
        }
      }

      if (!(1 <= trueCount)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, trueCount, &xc_emlrtBCI, &st);
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

      b_trueCount = 0;
      for (i = 0; i < 4; i++) {
        if (the_tf_mat[i]) {
          b_trueCount++;
        }
      }

      if (!(2 <= b_trueCount)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, b_trueCount, &yc_emlrtBCI, &st);
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
        for (i = 0; i < 2; i++) {
          uv_bot[i] = uv_top[i];
          uv_top[i] = UV_B[i];
        }
      } else {
        for (i = 0; i < 2; i++) {
          uv_bot[i] = UV_B[i];
        }
      }

      *tf_is_valid = true;
    }
    break;
  }
}

/* End of code generation (bh_line_homog_CLS.c) */
