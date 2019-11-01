/*
 * ind2sub.c
 *
 * Code generation for function 'ind2sub'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "ind2sub.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_emxutil.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Variable Definitions */
static emlrtRTEInfo be_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

/* Function Definitions */
boolean_T allinrange(const emxArray_int32_T *x, int32_T hi)
{
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  boolean_T b0;
  k = 0;
  do {
    exitg1 = 0;
    if (k <= x->size[0] - 1) {
      if ((x->data[k] >= 1) && (x->data[k] <= hi)) {
        b0 = true;
      } else {
        b0 = false;
      }

      if (!b0) {
        p = false;
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return p;
}

void ind2sub_indexClass(const emlrtStack *sp, const emxArray_real_T *ndx,
  emxArray_int32_T *varargout_1, emxArray_int32_T *varargout_2)
{
  int32_T i12;
  int32_T loop_ub;
  i12 = varargout_1->size[0];
  varargout_1->size[0] = ndx->size[0];
  emxEnsureCapacity_int32_T(sp, varargout_1, i12, &hd_emlrtRTEI);
  loop_ub = ndx->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    varargout_1->data[i12] = (int32_T)ndx->data[i12];
  }

  if (!allinrange(varargout_1, 76800)) {
    emlrtErrorWithMessageIdR2012b(sp, &ag_emlrtRTEI,
      "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
  }

  i12 = varargout_1->size[0];
  emxEnsureCapacity_int32_T(sp, varargout_1, i12, &id_emlrtRTEI);
  loop_ub = varargout_1->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    varargout_1->data[i12]--;
  }

  i12 = varargout_2->size[0];
  varargout_2->size[0] = varargout_1->size[0];
  emxEnsureCapacity_int32_T(sp, varargout_2, i12, &be_emlrtRTEI);
  loop_ub = varargout_1->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    varargout_2->data[i12] = varargout_1->data[i12] / 240 + 1;
  }

  i12 = varargout_1->size[0];
  emxEnsureCapacity_int32_T(sp, varargout_1, i12, &kd_emlrtRTEI);
  loop_ub = varargout_1->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    varargout_1->data[i12] -= varargout_1->data[i12] / 240 * 240;
  }

  i12 = varargout_1->size[0];
  emxEnsureCapacity_int32_T(sp, varargout_1, i12, &ce_emlrtRTEI);
  loop_ub = varargout_1->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    varargout_1->data[i12]++;
  }
}

/* End of code generation (ind2sub.c) */
