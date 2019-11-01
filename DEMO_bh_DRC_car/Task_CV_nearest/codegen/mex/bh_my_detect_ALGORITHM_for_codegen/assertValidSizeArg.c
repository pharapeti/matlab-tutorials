/*
 * assertValidSizeArg.c
 *
 * Code generation for function 'assertValidSizeArg'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "assertValidSizeArg.h"

/* Variable Definitions */
static emlrtRTEInfo qc_emlrtRTEI = { 53,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = { 59,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

/* Function Definitions */

/*
 *
 */
void assertValidSizeArg(const emlrtStack *sp, real_T varargin_1)
{
  boolean_T p;
  real_T b_varargin_1;
  if ((varargin_1 != varargin_1) || muDoubleScalarIsInf(varargin_1)) {
    p = false;
  } else {
    p = true;
  }

  if (p && (!(2.147483647E+9 < varargin_1))) {
    p = true;
  } else {
    p = false;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(sp, &qc_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_1 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_1;
  }

  if (!(2.147483647E+9 >= b_varargin_1)) {
    emlrtErrorWithMessageIdR2012b(sp, &rc_emlrtRTEI, "Coder:MATLAB:pmaxsize", 0);
  }
}

/* End of code generation (assertValidSizeArg.c) */
