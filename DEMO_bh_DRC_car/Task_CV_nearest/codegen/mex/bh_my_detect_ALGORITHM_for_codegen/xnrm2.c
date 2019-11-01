/*
 * xnrm2.c
 *
 * Code generation for function 'xnrm2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "xnrm2.h"
#include "eml_int_forloop_overflow_check.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRSInfo nh_emlrtRSI = { 23, /* lineNo */
  "xnrm2",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xnrm2.m"/* pathName */
};

static emlrtRSInfo oh_emlrtRSI = { 38, /* lineNo */
  "xnrm2",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xnrm2.m"/* pathName */
};

/* Function Definitions */

/*
 *
 */
real_T xnrm2(const emlrtStack *sp, int32_T n, const creal_T x[9], int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T k;
  real_T absxk;
  real_T t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &nh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = muDoubleScalarHypot(x[ix0 - 1].re, x[ix0 - 1].im);
    } else {
      scale = 3.3121686421112381E-170;
      b_st.site = &oh_emlrtRSI;
      if ((!(ix0 > ix0 + 1)) && (ix0 + 1 > 2147483646)) {
        c_st.site = &h_emlrtRSI;
        d_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = ix0; k <= ix0 + 1; k++) {
        absxk = muDoubleScalarAbs(x[k - 1].re);
        if (absxk > scale) {
          t = scale / absxk;
          y = 1.0 + y * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }

        absxk = muDoubleScalarAbs(x[k - 1].im);
        if (absxk > scale) {
          t = scale / absxk;
          y = 1.0 + y * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * muDoubleScalarSqrt(y);
    }
  }

  return y;
}

/* End of code generation (xnrm2.c) */
