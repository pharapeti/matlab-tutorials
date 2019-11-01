/*
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "find.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_emxutil.h"
#include "indexShapeCheck.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Variable Definitions */
static emlrtRSInfo cg_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRTEInfo nd_emlrtRTEI = { 50,/* lineNo */
  20,                                  /* colNo */
  "find",                              /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo od_emlrtRTEI = { 253,/* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = { 249,/* lineNo */
  21,                                  /* colNo */
  "find",                              /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = { 126,/* lineNo */
  19,                                  /* colNo */
  "find",                              /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

/* Function Definitions */
void b_eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
                emxArray_int32_T *i)
{
  int32_T nx;
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  int32_T iv12[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  nx = x->size[0];
  idx = 0;
  ii = i->size[0];
  i->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(sp, i, ii, &nd_emlrtRTEI);
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx)) {
    if (x->data[ii - 1]) {
      idx++;
      i->data[idx - 1] = ii;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (!(idx <= x->size[0])) {
    emlrtErrorWithMessageIdR2012b(sp, &uf_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      ii = i->size[0];
      i->size[0] = 0;
      emxEnsureCapacity_int32_T(sp, i, ii, &vd_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }

    iv12[0] = 1;
    iv12[1] = idx;
    st.site = &cg_emlrtRSI;
    b_indexShapeCheck(&st, i->size[0], iv12);
    ii = i->size[0];
    i->size[0] = idx;
    emxEnsureCapacity_int32_T(sp, i, ii, &od_emlrtRTEI);
  }
}

void c_eml_find(const emlrtStack *sp, const boolean_T x[76800], emxArray_int32_T
                *i)
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  int32_T iv13[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  idx = 0;
  ii = i->size[0];
  i->size[0] = 76800;
  emxEnsureCapacity_int32_T(sp, i, ii, &nd_emlrtRTEI);
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 76801)) {
    if (x[ii - 1]) {
      idx++;
      i->data[idx - 1] = ii;
      if (idx >= 76800) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  iv13[0] = 1;
  iv13[1] = idx;
  st.site = &cg_emlrtRSI;
  b_indexShapeCheck(&st, 76800, iv13);
  ii = i->size[0];
  i->size[0] = idx;
  emxEnsureCapacity_int32_T(sp, i, ii, &od_emlrtRTEI);
}

void eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
              emxArray_int32_T *i)
{
  int32_T nx;
  int32_T idx;
  boolean_T b3;
  int32_T ii;
  boolean_T exitg1;
  int32_T iv6[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  nx = x->size[0] * 320;
  idx = 0;
  b3 = !(x->size[0] == 1);
  if (!b3) {
    emlrtErrorWithMessageIdR2012b(sp, &bg_emlrtRTEI,
      "Coder:toolbox:find_incompatibleShape", 0);
  }

  ii = i->size[0];
  i->size[0] = nx;
  emxEnsureCapacity_int32_T(sp, i, ii, &nd_emlrtRTEI);
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx)) {
    if (x->data[ii - 1]) {
      idx++;
      i->data[idx - 1] = ii;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (!(idx <= nx)) {
    emlrtErrorWithMessageIdR2012b(sp, &uf_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > idx) {
    idx = 0;
  }

  iv6[0] = 1;
  iv6[1] = idx;
  st.site = &cg_emlrtRSI;
  b_indexShapeCheck(&st, i->size[0], iv6);
  ii = i->size[0];
  i->size[0] = idx;
  emxEnsureCapacity_int32_T(sp, i, ii, &od_emlrtRTEI);
}

/* End of code generation (find.c) */
