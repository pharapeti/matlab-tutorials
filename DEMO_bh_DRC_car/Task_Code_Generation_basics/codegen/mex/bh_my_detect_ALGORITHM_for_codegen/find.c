/*
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "find.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "indexShapeCheck.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRSInfo ag_emlrtRSI = { 253,/* lineNo */
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

static emlrtRTEInfo vf_emlrtRTEI = { 126,/* lineNo */
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
  int32_T iv9[2];
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
    emlrtErrorWithMessageIdR2012b(sp, &pf_emlrtRTEI,
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

    iv9[0] = 1;
    iv9[1] = idx;
    st.site = &ag_emlrtRSI;
    b_indexShapeCheck(&st, i->size[0], iv9);
    ii = i->size[0];
    i->size[0] = idx;
    emxEnsureCapacity_int32_T(sp, i, ii, &od_emlrtRTEI);
  }
}

void eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
              emxArray_int32_T *i)
{
  int32_T nx;
  int32_T idx;
  boolean_T b2;
  int32_T ii;
  boolean_T exitg1;
  int32_T iv3[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  nx = x->size[0] * 320;
  idx = 0;
  b2 = !(x->size[0] == 1);
  if (!b2) {
    emlrtErrorWithMessageIdR2012b(sp, &vf_emlrtRTEI,
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
    emlrtErrorWithMessageIdR2012b(sp, &pf_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > idx) {
    idx = 0;
  }

  iv3[0] = 1;
  iv3[1] = idx;
  st.site = &ag_emlrtRSI;
  b_indexShapeCheck(&st, i->size[0], iv3);
  ii = i->size[0];
  i->size[0] = idx;
  emxEnsureCapacity_int32_T(sp, i, ii, &od_emlrtRTEI);
}

/* End of code generation (find.c) */
