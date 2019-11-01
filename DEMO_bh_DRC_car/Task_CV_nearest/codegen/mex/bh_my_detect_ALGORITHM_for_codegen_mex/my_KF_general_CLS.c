/*
 * my_KF_general_CLS.c
 *
 * Code generation for function 'my_KF_general_CLS'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "my_KF_general_CLS.h"
#include "error1.h"
#include "warning.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_mexutil.h"

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = { 76,  /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo pl_emlrtRSI = { 150,/* lineNo */
  "my_KF_general_CLS",                 /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\my_KF_general_CLS.m"/* pathName */
};

static emlrtRSInfo ql_emlrtRSI = { 161,/* lineNo */
  "my_KF_general_CLS",                 /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\my_KF_general_CLS.m"/* pathName */
};

static emlrtRSInfo rl_emlrtRSI = { 94, /* lineNo */
  "eye",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\eye.m"/* pathName */
};

static emlrtRSInfo sl_emlrtRSI = { 49, /* lineNo */
  "eye",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\eye.m"/* pathName */
};

static emlrtRSInfo tl_emlrtRSI = { 18, /* lineNo */
  "checkAndSaturateExpandSize",        /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\checkAndSaturateExpandSize.m"/* pathName */
};

static emlrtRSInfo ul_emlrtRSI = { 1,  /* lineNo */
  "mrdivide",                          /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p"/* pathName */
};

static emlrtRSInfo vl_emlrtRSI = { 54, /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo wl_emlrtRSI = { 170,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtMCInfo d_emlrtMCI = { 142, /* lineNo */
  5,                                   /* colNo */
  "my_KF_general_CLS",                 /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\my_KF_general_CLS.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  162,                                 /* lineNo */
  16,                                  /* colNo */
  "my_KF_general_CLS",                 /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\my_KF_general_CLS.m"/* pName */
};

static emlrtRSInfo yl_emlrtRSI = { 142,/* lineNo */
  "my_KF_general_CLS",                 /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\my_KF_general_CLS.m"/* pathName */
};

/* Function Definitions */
void my_KF_general_CLS_correct(const emlrtStack *sp, my_KF_general_CLS *OBJ,
  const real_T y_data[], const int32_T y_size[2])
{
  const mxArray *y;
  const mxArray *m8;
  static const int32_T iv25[2] = { 1, 61 };

  static const char_T u[61] = { '#', '#', '#', '_', 'E', 'R', 'R', 'O', 'R', ':',
    ' ', ' ', 'h', 'e', 'y', ' ', 'y', 'o', 'u', 'r', ' ', 'y', ' ', 'a', 'n',
    'd', ' ', 'C', ' ', 'h', 'a', 'v', 'e', ' ', 'a', ' ', 'd', 'i', 'm', 'e',
    'n', 's', 'i', 'o', 'n', ' ', 'I', 'N', 'c', 'o', 'n', 's', 'i', 's', 't',
    'e', 'n', 'c', 'y', ' ', '!' };

  int32_T k;
  int8_T I_data[4];
  int32_T r1;
  real_T A[4];
  int32_T r2;
  real_T B[4];
  real_T b_OBJ[4];
  real_T a21;
  real_T a22;
  real_T K[4];
  real_T b_y[2];
  int8_T b_I_data[4];
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

  /*  predict() */
  /* --------------------------------------------------------------------------  */
  if (y_size[1] << 1 != 2) {
    y = NULL;
    m8 = emlrtCreateCharArray(2, iv25);
    emlrtInitCharArrayR2013a(sp, 61, m8, &u[0]);
    emlrtAssign(&y, m8);
    st.site = &yl_emlrtRSI;
    d_error(&st, y, &d_emlrtMCI);
  }

  st.site = &pl_emlrtRSI;
  b_st.site = &sl_emlrtRSI;
  c_st.site = &tl_emlrtRSI;
  for (k = 0; k < 4; k++) {
    I_data[k] = 0;
  }

  b_st.site = &rl_emlrtRSI;
  for (k = 0; k < 2; k++) {
    I_data[k + (k << 1)] = 1;
  }

  /*  Recall the BACK and FORWARD slash operators */
  /*   A.X=B ---> X=inv(A)*B ---> X = A\B */
  /*   X.A=B ---> X=B*inv(A) ---> X = B/A */
  /*      K[k]     = P[k|k-1].(C'). inv(  C.P[k|k-1].(C') + R  ) */
  /*   xhat[k|k]   = xhat[k|k-1]  +  K[k]*( y[k] - C.xhat[k|k-1]  ) */
  /*      P[k|k]   = (I-K[k].C). P[k|k-1] . (I-K[k].C)'   +  K[k]R.(K[k]') */
  /*                 = (I-K[k].C). P[k|k-1] */
  for (k = 0; k < 2; k++) {
    for (r1 = 0; r1 < 2; r1++) {
      A[k + (r1 << 1)] = 0.0;
      for (r2 = 0; r2 < 2; r2++) {
        A[k + (r1 << 1)] += OBJ->P[k + (r2 << 1)] * OBJ->C[r1 + (r2 << 1)];
      }
    }
  }

  st.site = &ql_emlrtRSI;
  for (k = 0; k < 2; k++) {
    for (r1 = 0; r1 < 2; r1++) {
      b_OBJ[k + (r1 << 1)] = 0.0;
      for (r2 = 0; r2 < 2; r2++) {
        b_OBJ[k + (r1 << 1)] += OBJ->C[k + (r2 << 1)] * OBJ->P[r2 + (r1 << 1)];
      }
    }

    for (r1 = 0; r1 < 2; r1++) {
      a21 = 0.0;
      for (r2 = 0; r2 < 2; r2++) {
        a21 += b_OBJ[k + (r2 << 1)] * OBJ->C[r1 + (r2 << 1)];
      }

      B[k + (r1 << 1)] = a21 + OBJ->R[k + (r1 << 1)];
    }
  }

  b_st.site = &ul_emlrtRSI;
  c_st.site = &vl_emlrtRSI;
  if (muDoubleScalarAbs(B[1]) > muDoubleScalarAbs(B[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  a21 = B[r2] / B[r1];
  a22 = B[2 + r2] - a21 * B[2 + r1];
  if ((a22 == 0.0) || (B[r1] == 0.0)) {
    d_st.site = &wl_emlrtRSI;
    e_st.site = &j_emlrtRSI;
    warning(&e_st);
  }

  for (k = 0; k < 2; k++) {
    K[k + (r1 << 1)] = A[k] / B[r1];
    K[k + (r2 << 1)] = (A[2 + k] - K[k + (r1 << 1)] * B[2 + r1]) / a22;
    K[k + (r1 << 1)] -= K[k + (r2 << 1)] * a21;
  }

  k = y_size[1] << 1;
  if (k != 2) {
    emlrtSizeEqCheck1DR2012b(k, 2, &h_emlrtECI, sp);
  }

  for (k = 0; k < 2; k++) {
    a21 = 0.0;
    for (r1 = 0; r1 < 2; r1++) {
      a21 += OBJ->C[k + (r1 << 1)] * OBJ->x[r1];
    }

    b_y[k] = y_data[k] - a21;
  }

  for (k = 0; k < 2; k++) {
    a21 = 0.0;
    for (r1 = 0; r1 < 2; r1++) {
      a21 += K[k + (r1 << 1)] * b_y[r1];
      b_I_data[r1 + (k << 1)] = I_data[r1 + (k << 1)];
    }

    OBJ->x[k] += a21;
  }

  for (k = 0; k < 2; k++) {
    for (r1 = 0; r1 < 2; r1++) {
      a21 = 0.0;
      for (r2 = 0; r2 < 2; r2++) {
        a21 += K[k + (r2 << 1)] * OBJ->C[r2 + (r1 << 1)];
      }

      b_OBJ[k + (r1 << 1)] = (real_T)b_I_data[k + (r1 << 1)] - a21;
    }

    for (r1 = 0; r1 < 2; r1++) {
      A[k + (r1 << 1)] = 0.0;
      for (r2 = 0; r2 < 2; r2++) {
        A[k + (r1 << 1)] += b_OBJ[k + (r2 << 1)] * OBJ->P[r2 + (r1 << 1)];
      }
    }
  }

  for (k = 0; k < 2; k++) {
    for (r1 = 0; r1 < 2; r1++) {
      OBJ->P[r1 + (k << 1)] = A[r1 + (k << 1)];
    }
  }
}

void my_KF_general_CLS_predict(my_KF_general_CLS *OBJ)
{
  int32_T i38;
  real_T b_OBJ[2];
  int32_T i39;
  real_T c_OBJ[4];
  real_T d0;
  int32_T i40;

  /*  my_KF_general_CLS() */
  /* --------------------------------------------------------------------------  */
  /*  ALLOWED USAGE: */
  /*  >> OBJ = OBJ.predict() */
  /*  >> OBJ = OBJ.predict(u) */
  /*     xhat[k|k-1] = A.x[k-1]  +  B.u[k-1] */
  /*        P[k|k-1] = A.P[k-1|k-1].(A')  +  Q */
  for (i38 = 0; i38 < 2; i38++) {
    b_OBJ[i38] = 0.0;
    for (i39 = 0; i39 < 2; i39++) {
      b_OBJ[i38] += OBJ->A[i38 + (i39 << 1)] * OBJ->x[i39];
    }
  }

  for (i38 = 0; i38 < 2; i38++) {
    OBJ->x[i38] = b_OBJ[i38];
    for (i39 = 0; i39 < 2; i39++) {
      c_OBJ[i38 + (i39 << 1)] = 0.0;
      for (i40 = 0; i40 < 2; i40++) {
        c_OBJ[i38 + (i39 << 1)] += OBJ->A[i38 + (i40 << 1)] * OBJ->P[i40 + (i39 <<
          1)];
      }
    }
  }

  for (i38 = 0; i38 < 2; i38++) {
    for (i39 = 0; i39 < 2; i39++) {
      d0 = 0.0;
      for (i40 = 0; i40 < 2; i40++) {
        d0 += c_OBJ[i38 + (i40 << 1)] * OBJ->A[i39 + (i40 << 1)];
      }

      OBJ->P[i38 + (i39 << 1)] = d0 + OBJ->Q[i38 + (i39 << 1)];
    }
  }
}

/* End of code generation (my_KF_general_CLS.c) */
