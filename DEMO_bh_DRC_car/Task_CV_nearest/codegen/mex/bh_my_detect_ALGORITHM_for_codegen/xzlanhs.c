/*
 * xzlanhs.c
 *
 * Code generation for function 'xzlanhs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "xzlanhs.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRSInfo ek_emlrtRSI = { 20, /* lineNo */
  "xzlanhs",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlanhs.m"/* pathName */
};

static emlrtRSInfo fk_emlrtRSI = { 21, /* lineNo */
  "xzlanhs",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlanhs.m"/* pathName */
};

static emlrtRSInfo gk_emlrtRSI = { 57, /* lineNo */
  "xzlanhs",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlanhs.m"/* pathName */
};

/* Function Definitions */

/*
 *
 */
real_T xzlanhs(const emlrtStack *sp, const creal_T A[9], int32_T ilo, int32_T
               ihi)
{
  real_T b_f;
  real_T scale;
  real_T sumsq;
  boolean_T firstNonZero;
  int32_T j;
  int32_T b;
  int32_T i;
  real_T reAij;
  real_T imAij;
  real_T temp2;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_f = 0.0;
  if (!(ilo > ihi)) {
    scale = 0.0;
    sumsq = 0.0;
    firstNonZero = true;
    st.site = &ek_emlrtRSI;
    if ((!(ilo > ihi)) && (ihi > 2147483646)) {
      b_st.site = &h_emlrtRSI;
      c_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (j = ilo; j <= ihi; j++) {
      b = j + 1;
      if (ihi < j + 1) {
        b = ihi;
      }

      st.site = &fk_emlrtRSI;
      if ((!(ilo > b)) && (b > 2147483646)) {
        b_st.site = &h_emlrtRSI;
        c_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (i = ilo; i <= b; i++) {
        reAij = A[(i + 3 * (j - 1)) - 1].re;
        imAij = A[(i + 3 * (j - 1)) - 1].im;
        if (reAij != 0.0) {
          reAij = muDoubleScalarAbs(reAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = reAij;
            firstNonZero = false;
          } else if (scale < reAij) {
            temp2 = scale / reAij;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            scale = reAij;
          } else {
            temp2 = reAij / scale;
            sumsq += temp2 * temp2;
          }
        }

        if (imAij != 0.0) {
          reAij = muDoubleScalarAbs(imAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = reAij;
            firstNonZero = false;
          } else if (scale < reAij) {
            temp2 = scale / reAij;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            scale = reAij;
          } else {
            temp2 = reAij / scale;
            sumsq += temp2 * temp2;
          }
        }
      }
    }

    st.site = &gk_emlrtRSI;
    if (sumsq < 0.0) {
      b_st.site = &db_emlrtRSI;
      c_st.site = &db_emlrtRSI;
      b_error(&c_st);
    }

    b_f = scale * muDoubleScalarSqrt(sumsq);
  }

  return b_f;
}

/* End of code generation (xzlanhs.c) */
