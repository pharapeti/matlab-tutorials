/*
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "mean.h"
#include "combineVectorElements.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRTEInfo tf_emlrtRTEI = { 17,/* lineNo */
  15,                                  /* colNo */
  "mean",                              /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"/* pName */
};

/* Function Definitions */
real_T mean(const emlrtStack *sp, const emxArray_real_T *x)
{
  real_T y;
  boolean_T b1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((x->size[0] == 1) || (x->size[0] != 1)) {
    b1 = true;
  } else {
    b1 = false;
  }

  if (!b1) {
    emlrtErrorWithMessageIdR2012b(sp, &tf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  st.site = &yd_emlrtRSI;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    b_st.site = &bd_emlrtRSI;
    y = colMajorFlatIter(&b_st, x, x->size[0]);
  }

  y /= (real_T)x->size[0];
  return y;
}

/* End of code generation (mean.c) */
