/*
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "power.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalexpAlloc.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRTEInfo l_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "power",                             /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 19,/* lineNo */
  24,                                  /* colNo */
  "scalexpAllocNoCheck",               /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAllocNoCheck.m"/* pName */
};

/* Function Definitions */

/*
 *
 */
void b_power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emxArray_real_T *z;
  emxArray_real_T *b_z;
  uint32_T a_idx_0;
  int32_T k;
  uint32_T b_a_idx_0;
  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &z, 1, &l_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_z, 1, &l_emlrtRTEI, true);
  st.site = &p_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  a_idx_0 = (uint32_T)a->size[0];
  k = b_z->size[0];
  b_z->size[0] = (int32_T)a_idx_0;
  emxEnsureCapacity_real_T1(&c_st, b_z, k, &kb_emlrtRTEI);
  a_idx_0 = (uint32_T)a->size[0];
  b_a_idx_0 = (uint32_T)a->size[0];
  k = z->size[0];
  z->size[0] = (int32_T)b_a_idx_0;
  emxEnsureCapacity_real_T1(&c_st, z, k, &j_emlrtRTEI);
  if (!b_dimagree(z, a)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxFree_real_T(&z);
  b_a_idx_0 = (uint32_T)a->size[0];
  k = y->size[0];
  y->size[0] = (int32_T)b_a_idx_0;
  emxEnsureCapacity_real_T1(&b_st, y, k, &k_emlrtRTEI);
  c_st.site = &x_emlrtRSI;
  d_st.site = &y_emlrtRSI;
  overflow = ((!(1 > b_z->size[0])) && (b_z->size[0] > 2147483646));
  emxFree_real_T(&b_z);
  if (overflow) {
    e_st.site = &h_emlrtRSI;
    f_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 0; k + 1 <= (int32_T)a_idx_0; k++) {
    y->data[k] = a->data[k] * a->data[k];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emxArray_real_T *z;
  int32_T nx;
  int16_T a_idx_0;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &z, 2, &l_emlrtRTEI, true);
  st.site = &p_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  nx = z->size[0] * z->size[1];
  z->size[0] = (int16_T)a->size[0];
  z->size[1] = 320;
  emxEnsureCapacity_real_T(&c_st, z, nx, &j_emlrtRTEI);
  if (!dimagree(z, a)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxFree_real_T(&z);
  nx = y->size[0] * y->size[1];
  y->size[0] = (int16_T)a->size[0];
  y->size[1] = 320;
  emxEnsureCapacity_real_T(&b_st, y, nx, &k_emlrtRTEI);
  c_st.site = &x_emlrtRSI;
  a_idx_0 = (int16_T)a->size[0];
  nx = a_idx_0 * 320;
  for (k = 0; k + 1 <= nx; k++) {
    y->data[k] = a->data[k] * a->data[k];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (power.c) */
