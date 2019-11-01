/*
 * error1.c
 *
 * Code generation for function 'error1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "error1.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_mexutil.h"

/* Variable Definitions */
static emlrtMCInfo c_emlrtMCI = { 27,  /* lineNo */
  5,                                   /* colNo */
  "error",                             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\lang\\error.m"/* pName */
};

static emlrtRSInfo am_emlrtRSI = { 27, /* lineNo */
  "error",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\lang\\error.m"/* pathName */
};

/* Function Definitions */
void c_error(const emlrtStack *sp)
{
  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv11[2] = { 1, 29 };

  static const char_T varargin_1[29] = { '#', '#', '#', '_', 'E', 'R', 'R', 'O',
    'R', ':', ' ', ' ', 'u', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'l', 'i', 'n',
    'e', ' ', 't', 'y', 'p', 'e' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m2 = emlrtCreateCharArray(2, iv11);
  emlrtInitCharArrayR2013a(sp, 29, m2, &varargin_1[0]);
  emlrtAssign(&y, m2);
  st.site = &am_emlrtRSI;
  d_error(&st, y, &c_emlrtMCI);
}

/* End of code generation (error1.c) */
