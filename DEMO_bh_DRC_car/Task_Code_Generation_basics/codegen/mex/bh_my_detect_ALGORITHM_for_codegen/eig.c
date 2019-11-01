/*
 * eig.c
 *
 * Code generation for function 'eig'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "eig.h"
#include "warning.h"
#include "xzggev.h"

/* Variable Definitions */
static emlrtRSInfo ig_emlrtRSI = { 108,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo jg_emlrtRSI = { 180,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo kg_emlrtRSI = { 35, /* lineNo */
  "xggev",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xggev.m"/* pathName */
};

/* Function Definitions */
void eig(const emlrtStack *sp, const real_T A[9], creal_T V[9], creal_T D[9])
{
  boolean_T p;
  int32_T k;
  creal_T At[9];
  creal_T Bt[9];
  int32_T info;
  creal_T alpha1[3];
  creal_T beta1[3];
  static const int8_T iv4[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 0 };

  real_T brm;
  real_T bim;
  real_T d;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  p = true;
  for (k = 0; k < 9; k++) {
    if (p && ((!muDoubleScalarIsInf(A[k])) && (!muDoubleScalarIsNaN(A[k])))) {
      p = true;
    } else {
      p = false;
    }
  }

  if (!p) {
    for (k = 0; k < 9; k++) {
      V[k].re = rtNaN;
      V[k].im = 0.0;
      D[k].re = 0.0;
      D[k].im = 0.0;
    }

    for (k = 0; k < 3; k++) {
      D[k + 3 * k].re = rtNaN;
      D[k + 3 * k].im = 0.0;
    }
  } else {
    st.site = &ig_emlrtRSI;
    for (k = 0; k < 9; k++) {
      At[k].re = A[k];
      At[k].im = 0.0;
      Bt[k].re = iv4[k];
      Bt[k].im = 0.0;
    }

    b_st.site = &kg_emlrtRSI;
    xzggev(&b_st, At, Bt, &info, alpha1, beta1, V);
    for (k = 0; k < 9; k++) {
      D[k].re = 0.0;
      D[k].im = 0.0;
    }

    for (k = 0; k < 3; k++) {
      if (beta1[k].im == 0.0) {
        if (alpha1[k].im == 0.0) {
          D[k + 3 * k].re = alpha1[k].re / beta1[k].re;
          D[k + 3 * k].im = 0.0;
        } else if (alpha1[k].re == 0.0) {
          D[k + 3 * k].re = 0.0;
          D[k + 3 * k].im = alpha1[k].im / beta1[k].re;
        } else {
          D[k + 3 * k].re = alpha1[k].re / beta1[k].re;
          D[k + 3 * k].im = alpha1[k].im / beta1[k].re;
        }
      } else if (beta1[k].re == 0.0) {
        if (alpha1[k].re == 0.0) {
          D[k + 3 * k].re = alpha1[k].im / beta1[k].im;
          D[k + 3 * k].im = 0.0;
        } else if (alpha1[k].im == 0.0) {
          D[k + 3 * k].re = 0.0;
          D[k + 3 * k].im = -(alpha1[k].re / beta1[k].im);
        } else {
          D[k + 3 * k].re = alpha1[k].im / beta1[k].im;
          D[k + 3 * k].im = -(alpha1[k].re / beta1[k].im);
        }
      } else {
        brm = muDoubleScalarAbs(beta1[k].re);
        bim = muDoubleScalarAbs(beta1[k].im);
        if (brm > bim) {
          bim = beta1[k].im / beta1[k].re;
          d = beta1[k].re + bim * beta1[k].im;
          D[k + 3 * k].re = (alpha1[k].re + bim * alpha1[k].im) / d;
          D[k + 3 * k].im = (alpha1[k].im - bim * alpha1[k].re) / d;
        } else if (bim == brm) {
          if (beta1[k].re > 0.0) {
            bim = 0.5;
          } else {
            bim = -0.5;
          }

          if (beta1[k].im > 0.0) {
            d = 0.5;
          } else {
            d = -0.5;
          }

          D[k + 3 * k].re = (alpha1[k].re * bim + alpha1[k].im * d) / brm;
          D[k + 3 * k].im = (alpha1[k].im * bim - alpha1[k].re * d) / brm;
        } else {
          bim = beta1[k].re / beta1[k].im;
          d = beta1[k].im + bim * beta1[k].re;
          D[k + 3 * k].re = (bim * alpha1[k].re + alpha1[k].im) / d;
          D[k + 3 * k].im = (bim * alpha1[k].im - alpha1[k].re) / d;
        }
      }
    }

    if (info != 0) {
      st.site = &jg_emlrtRSI;
      warning(&st);
    }
  }
}

/* End of code generation (eig.c) */
