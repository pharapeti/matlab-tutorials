/*
 * sort1.c
 *
 * Code generation for function 'sort1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "sort1.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sortIdx.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRSInfo oe_emlrtRSI = { 19, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo pe_emlrtRSI = { 68, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 70, /* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 247,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo se_emlrtRSI = { 255,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo te_emlrtRSI = { 256,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo ue_emlrtRSI = { 264,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo ve_emlrtRSI = { 272,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo we_emlrtRSI = { 277,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo xe_emlrtRSI = { 329,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo ye_emlrtRSI = { 357,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo af_emlrtRSI = { 364,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo bf_emlrtRSI = { 524,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 526,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 554,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo kf_emlrtRSI = { 291,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo lf_emlrtRSI = { 300,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 247,/* lineNo */
  14,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 247,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

/* Function Declarations */
static void b_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T
                   *idx);

/* Function Definitions */

/*
 *
 */
static void b_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T
                   *idx)
{
  int32_T i;
  int32_T ib;
  int32_T n;
  int32_T b_n;
  emxArray_int32_T *iwork;
  real_T x4[4];
  int32_T idx4[4];
  emxArray_real_T *xwork;
  int32_T nNaNs;
  boolean_T overflow;
  int32_T k;
  int32_T wOffset;
  int8_T perm[4];
  int32_T p;
  int32_T nNonNaN;
  int32_T i4;
  int32_T nBlocks;
  int32_T bLen;
  int32_T bLen2;
  int32_T nPairs;
  int32_T b_iwork[256];
  real_T b_xwork[256];
  int32_T exitg1;
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
  st.site = &pe_emlrtRSI;
  i = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = x->size[1];
  emxEnsureCapacity_int32_T1(&st, idx, i, &mb_emlrtRTEI);
  ib = x->size[1];
  for (i = 0; i < ib; i++) {
    idx->data[i] = 0;
  }

  b_st.site = &qe_emlrtRSI;
  n = x->size[1];
  c_st.site = &re_emlrtRSI;
  b_n = x->size[1];
  for (i = 0; i < 4; i++) {
    x4[i] = 0.0;
    idx4[i] = 0;
  }

  emxInit_int32_T(&c_st, &iwork, 1, &hc_emlrtRTEI, true);
  ib = x->size[1];
  i = iwork->size[0];
  iwork->size[0] = ib;
  emxEnsureCapacity_int32_T(&c_st, iwork, i, &mb_emlrtRTEI);
  for (i = 0; i < ib; i++) {
    iwork->data[i] = 0;
  }

  emxInit_real_T1(&c_st, &xwork, 1, &ic_emlrtRTEI, true);
  ib = x->size[1];
  i = xwork->size[0];
  xwork->size[0] = ib;
  emxEnsureCapacity_real_T1(&c_st, xwork, i, &mb_emlrtRTEI);
  for (i = 0; i < ib; i++) {
    xwork->data[i] = 0.0;
  }

  nNaNs = 0;
  ib = 0;
  d_st.site = &xe_emlrtRSI;
  overflow = ((!(1 > x->size[1])) && (x->size[1] > 2147483646));
  if (overflow) {
    e_st.site = &h_emlrtRSI;
    f_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 0; k + 1 <= b_n; k++) {
    if (muDoubleScalarIsNaN(x->data[k])) {
      idx->data[(b_n - nNaNs) - 1] = k + 1;
      xwork->data[(b_n - nNaNs) - 1] = x->data[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = k + 1;
      x4[ib - 1] = x->data[k];
      if (ib == 4) {
        i = k - nNaNs;
        if (x4[0] >= x4[1]) {
          ib = 1;
          wOffset = 2;
        } else {
          ib = 2;
          wOffset = 1;
        }

        if (x4[2] >= x4[3]) {
          p = 3;
          i4 = 4;
        } else {
          p = 4;
          i4 = 3;
        }

        if (x4[ib - 1] >= x4[p - 1]) {
          if (x4[wOffset - 1] >= x4[p - 1]) {
            perm[0] = (int8_T)ib;
            perm[1] = (int8_T)wOffset;
            perm[2] = (int8_T)p;
            perm[3] = (int8_T)i4;
          } else if (x4[wOffset - 1] >= x4[i4 - 1]) {
            perm[0] = (int8_T)ib;
            perm[1] = (int8_T)p;
            perm[2] = (int8_T)wOffset;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)ib;
            perm[1] = (int8_T)p;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)wOffset;
          }
        } else if (x4[ib - 1] >= x4[i4 - 1]) {
          if (x4[wOffset - 1] >= x4[i4 - 1]) {
            perm[0] = (int8_T)p;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)wOffset;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)p;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)wOffset;
          }
        } else {
          perm[0] = (int8_T)p;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)ib;
          perm[3] = (int8_T)wOffset;
        }

        idx->data[i - 3] = idx4[perm[0] - 1];
        idx->data[i - 2] = idx4[perm[1] - 1];
        idx->data[i - 1] = idx4[perm[2] - 1];
        idx->data[i] = idx4[perm[3] - 1];
        x->data[i - 3] = x4[perm[0] - 1];
        x->data[i - 2] = x4[perm[1] - 1];
        x->data[i - 1] = x4[perm[2] - 1];
        x->data[i] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  wOffset = (b_n - nNaNs) - 1;
  if (ib > 0) {
    for (i = 0; i < 4; i++) {
      perm[i] = 0;
    }

    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] >= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] >= x4[1]) {
      if (x4[1] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    d_st.site = &ye_emlrtRSI;
    if (ib > 2147483646) {
      e_st.site = &h_emlrtRSI;
      f_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }

    for (k = 1; k <= ib; k++) {
      idx->data[(wOffset - ib) + k] = idx4[perm[k - 1] - 1];
      x->data[(wOffset - ib) + k] = x4[perm[k - 1] - 1];
    }
  }

  i = (nNaNs >> 1) + 1;
  d_st.site = &af_emlrtRSI;
  for (k = 1; k < i; k++) {
    ib = idx->data[wOffset + k];
    idx->data[wOffset + k] = idx->data[b_n - k];
    idx->data[b_n - k] = ib;
    x->data[wOffset + k] = xwork->data[b_n - k];
    x->data[b_n - k] = xwork->data[wOffset + k];
  }

  if ((nNaNs & 1) != 0) {
    x->data[wOffset + i] = xwork->data[wOffset + i];
  }

  nNonNaN = n - nNaNs;
  ib = 2;
  if (nNonNaN > 1) {
    if (n >= 256) {
      nBlocks = nNonNaN >> 8;
      if (nBlocks > 0) {
        c_st.site = &se_emlrtRSI;
        for (i4 = 1; i4 <= nBlocks; i4++) {
          c_st.site = &te_emlrtRSI;
          b_n = (i4 - 1) << 8;
          for (n = 0; n < 6; n++) {
            bLen = 1 << (n + 2);
            bLen2 = bLen << 1;
            nPairs = 256 >> (n + 3);
            d_st.site = &bf_emlrtRSI;
            for (k = 1; k <= nPairs; k++) {
              ib = b_n + (k - 1) * bLen2;
              d_st.site = &cf_emlrtRSI;
              for (i = 0; i + 1 <= bLen2; i++) {
                b_iwork[i] = idx->data[ib + i];
                b_xwork[i] = x->data[ib + i];
              }

              p = 0;
              wOffset = bLen;
              i = ib - 1;
              do {
                exitg1 = 0;
                i++;
                if (b_xwork[p] >= b_xwork[wOffset]) {
                  idx->data[i] = b_iwork[p];
                  x->data[i] = b_xwork[p];
                  if (p + 1 < bLen) {
                    p++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  idx->data[i] = b_iwork[wOffset];
                  x->data[i] = b_xwork[wOffset];
                  if (wOffset + 1 < bLen2) {
                    wOffset++;
                  } else {
                    i = (i - p) + 1;
                    d_st.site = &df_emlrtRSI;
                    while (p + 1 <= bLen) {
                      idx->data[i + p] = b_iwork[p];
                      x->data[i + p] = b_xwork[p];
                      p++;
                    }

                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }

        ib = nBlocks << 8;
        i = nNonNaN - ib;
        if (i > 0) {
          c_st.site = &ue_emlrtRSI;
          merge_block(&c_st, idx, x, ib, i, 2, iwork, xwork);
        }

        ib = 8;
      }
    }

    c_st.site = &ve_emlrtRSI;
    merge_block(&c_st, idx, x, 0, nNonNaN, ib, iwork, xwork);
  }

  if ((nNaNs > 0) && (nNonNaN > 0)) {
    c_st.site = &we_emlrtRSI;
    d_st.site = &kf_emlrtRSI;
    if (nNaNs > 2147483646) {
      e_st.site = &h_emlrtRSI;
      f_st.site = &h_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }

    for (k = 0; k + 1 <= nNaNs; k++) {
      xwork->data[k] = x->data[nNonNaN + k];
      iwork->data[k] = idx->data[nNonNaN + k];
    }

    for (k = nNonNaN - 1; k + 1 > 0; k--) {
      x->data[nNaNs + k] = x->data[k];
      idx->data[nNaNs + k] = idx->data[k];
    }

    d_st.site = &lf_emlrtRSI;
    for (k = 0; k + 1 <= nNaNs; k++) {
      x->data[k] = xwork->data[k];
      idx->data[k] = iwork->data[k];
    }
  }

  emxFree_real_T(&xwork);
  emxFree_int32_T(&iwork);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 *
 */
void sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oe_emlrtRSI;
  b_sort(&st, x, idx);
}

/* End of code generation (sort1.c) */
