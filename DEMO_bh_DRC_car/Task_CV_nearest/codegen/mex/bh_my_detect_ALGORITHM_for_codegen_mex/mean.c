/*
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "mean.h"
#include "combineVectorElements.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Variable Definitions */
static emlrtRTEInfo yf_emlrtRTEI = { 17,/* lineNo */
  15,                                  /* colNo */
  "mean",                              /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"/* pName */
};

/* Function Definitions */
real_T mean(const emlrtStack *sp, const emxArray_real_T *x)
{
  real_T y;
  boolean_T b2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((x->size[0] == 1) || (x->size[0] != 1)) {
    b2 = true;
  } else {
    b2 = false;
  }

  if (!b2) {
    emlrtErrorWithMessageIdR2012b(sp, &yf_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  st.site = &be_emlrtRSI;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    b_st.site = &cd_emlrtRSI;
    y = colMajorFlatIter(&b_st, x, x->size[0]);
  }

  y /= (real_T)x->size[0];
  return y;
}

/* End of code generation (mean.c) */
