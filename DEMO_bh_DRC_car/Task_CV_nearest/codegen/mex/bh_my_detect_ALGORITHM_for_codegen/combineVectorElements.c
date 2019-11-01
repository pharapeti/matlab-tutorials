/*
 * combineVectorElements.c
 *
 * Code generation for function 'combineVectorElements'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "combineVectorElements.h"
#include "eml_int_forloop_overflow_check.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Function Definitions */

/*
 *
 */
real_T colMajorFlatIter(const emlrtStack *sp, const emxArray_real_T *x, int32_T
  vlen)
{
  real_T y;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = x->data[0];
  st.site = &cd_emlrtRSI;
  if ((!(2 > vlen)) && (vlen > 2147483646)) {
    b_st.site = &h_emlrtRSI;
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 2; k <= vlen; k++) {
    y += x->data[k - 1];
  }

  return y;
}

/* End of code generation (combineVectorElements.c) */
