/*
 * xzggbal.c
 *
 * Code generation for function 'xzggbal'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "xzggbal.h"
#include "eml_int_forloop_overflow_check.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRSInfo sg_emlrtRSI = { 22, /* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo tg_emlrtRSI = { 26, /* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo ug_emlrtRSI = { 35, /* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo vg_emlrtRSI = { 39, /* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo wg_emlrtRSI = { 139,/* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo xg_emlrtRSI = { 76, /* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo yg_emlrtRSI = { 83, /* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo ah_emlrtRSI = { 101,/* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

static emlrtRSInfo bh_emlrtRSI = { 105,/* lineNo */
  "xzggbal",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbal.m"/* pathName */
};

/* Function Definitions */

/*
 *
 */
void xzggbal(const emlrtStack *sp, creal_T A[9], creal_T B[9], int32_T *ilo,
             int32_T *ihi, int32_T rscale[3])
{
  int32_T i;
  int32_T exitg2;
  int32_T j;
  boolean_T found;
  int32_T ii;
  boolean_T exitg3;
  int32_T nzcount;
  real_T atmp_re;
  real_T atmp_im;
  int32_T exitg1;
  int32_T jj;
  boolean_T exitg4;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  for (i = 0; i < 3; i++) {
    rscale[i] = 1;
  }

  *ilo = 1;
  *ihi = 3;
  do {
    exitg2 = 0;
    st.site = &sg_emlrtRSI;
    i = -1;
    j = -1;
    found = false;
    ii = *ihi - 1;
    exitg3 = false;
    while ((!exitg3) && (ii + 1 > 0)) {
      nzcount = 0;
      i = ii;
      j = *ihi - 1;
      b_st.site = &wg_emlrtRSI;
      if ((!(1 > *ihi)) && (*ihi > 2147483646)) {
        c_st.site = &h_emlrtRSI;
        d_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      jj = 0;
      exitg4 = false;
      while ((!exitg4) && (jj + 1 <= *ihi)) {
        if ((A[ii + 3 * jj].re != 0.0) || (A[ii + 3 * jj].im != 0.0) || ((B[ii +
              3 * jj].re != 0.0) || (B[ii + 3 * jj].im != 0.0))) {
          if (nzcount == 0) {
            j = jj;
            nzcount = 1;
            jj++;
          } else {
            nzcount = 2;
            exitg4 = true;
          }
        } else {
          jj++;
        }
      }

      if (nzcount < 2) {
        found = true;
        exitg3 = true;
      } else {
        ii--;
      }
    }

    if (!found) {
      exitg2 = 2;
    } else {
      st.site = &tg_emlrtRSI;
      if (i + 1 != *ihi) {
        for (ii = 0; ii < 3; ii++) {
          atmp_re = A[i + 3 * ii].re;
          atmp_im = A[i + 3 * ii].im;
          A[i + 3 * ii] = A[(*ihi + 3 * ii) - 1];
          A[(*ihi + 3 * ii) - 1].re = atmp_re;
          A[(*ihi + 3 * ii) - 1].im = atmp_im;
        }

        for (ii = 0; ii < 3; ii++) {
          atmp_re = B[i + 3 * ii].re;
          atmp_im = B[i + 3 * ii].im;
          B[i + 3 * ii] = B[(*ihi + 3 * ii) - 1];
          B[(*ihi + 3 * ii) - 1].re = atmp_re;
          B[(*ihi + 3 * ii) - 1].im = atmp_im;
        }
      }

      if (j + 1 != *ihi) {
        b_st.site = &xg_emlrtRSI;
        if ((!(1 > *ihi)) && (*ihi > 2147483646)) {
          c_st.site = &h_emlrtRSI;
          d_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (ii = 0; ii + 1 <= *ihi; ii++) {
          atmp_re = A[ii + 3 * j].re;
          atmp_im = A[ii + 3 * j].im;
          A[ii + 3 * j] = A[ii + 3 * (*ihi - 1)];
          A[ii + 3 * (*ihi - 1)].re = atmp_re;
          A[ii + 3 * (*ihi - 1)].im = atmp_im;
        }

        b_st.site = &yg_emlrtRSI;
        for (ii = 0; ii + 1 <= *ihi; ii++) {
          atmp_re = B[ii + 3 * j].re;
          atmp_im = B[ii + 3 * j].im;
          B[ii + 3 * j] = B[ii + 3 * (*ihi - 1)];
          B[ii + 3 * (*ihi - 1)].re = atmp_re;
          B[ii + 3 * (*ihi - 1)].im = atmp_im;
        }
      }

      rscale[*ihi - 1] = j + 1;
      (*ihi)--;
      if (*ihi == 1) {
        rscale[0] = 1;
        exitg2 = 1;
      }
    }
  } while (exitg2 == 0);

  if (exitg2 == 1) {
  } else {
    do {
      exitg1 = 0;
      st.site = &ug_emlrtRSI;
      i = -1;
      j = -1;
      found = false;
      b_st.site = &ah_emlrtRSI;
      if ((!(*ilo > *ihi)) && (*ihi > 2147483646)) {
        c_st.site = &h_emlrtRSI;
        d_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      jj = *ilo - 1;
      exitg3 = false;
      while ((!exitg3) && (jj + 1 <= *ihi)) {
        nzcount = 0;
        i = *ihi - 1;
        j = jj;
        b_st.site = &bh_emlrtRSI;
        if ((!(*ilo > *ihi)) && (*ihi > 2147483646)) {
          c_st.site = &h_emlrtRSI;
          d_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        ii = *ilo - 1;
        exitg4 = false;
        while ((!exitg4) && (ii + 1 <= *ihi)) {
          if ((A[ii + 3 * jj].re != 0.0) || (A[ii + 3 * jj].im != 0.0) || ((B[ii
                + 3 * jj].re != 0.0) || (B[ii + 3 * jj].im != 0.0))) {
            if (nzcount == 0) {
              i = ii;
              nzcount = 1;
              ii++;
            } else {
              nzcount = 2;
              exitg4 = true;
            }
          } else {
            ii++;
          }
        }

        if (nzcount < 2) {
          found = true;
          exitg3 = true;
        } else {
          jj++;
        }
      }

      if (!found) {
        exitg1 = 1;
      } else {
        st.site = &vg_emlrtRSI;
        if (i + 1 != *ilo) {
          for (ii = *ilo - 1; ii + 1 < 4; ii++) {
            atmp_re = A[i + 3 * ii].re;
            atmp_im = A[i + 3 * ii].im;
            A[i + 3 * ii] = A[(*ilo + 3 * ii) - 1];
            A[(*ilo + 3 * ii) - 1].re = atmp_re;
            A[(*ilo + 3 * ii) - 1].im = atmp_im;
          }

          for (ii = *ilo - 1; ii + 1 < 4; ii++) {
            atmp_re = B[i + 3 * ii].re;
            atmp_im = B[i + 3 * ii].im;
            B[i + 3 * ii] = B[(*ilo + 3 * ii) - 1];
            B[(*ilo + 3 * ii) - 1].re = atmp_re;
            B[(*ilo + 3 * ii) - 1].im = atmp_im;
          }
        }

        if (j + 1 != *ilo) {
          b_st.site = &xg_emlrtRSI;
          if ((!(1 > *ihi)) && (*ihi > 2147483646)) {
            c_st.site = &h_emlrtRSI;
            d_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          for (ii = 0; ii + 1 <= *ihi; ii++) {
            atmp_re = A[ii + 3 * j].re;
            atmp_im = A[ii + 3 * j].im;
            A[ii + 3 * j] = A[ii + 3 * (*ilo - 1)];
            A[ii + 3 * (*ilo - 1)].re = atmp_re;
            A[ii + 3 * (*ilo - 1)].im = atmp_im;
          }

          b_st.site = &yg_emlrtRSI;
          for (ii = 0; ii + 1 <= *ihi; ii++) {
            atmp_re = B[ii + 3 * j].re;
            atmp_im = B[ii + 3 * j].im;
            B[ii + 3 * j] = B[ii + 3 * (*ilo - 1)];
            B[ii + 3 * (*ilo - 1)].re = atmp_re;
            B[ii + 3 * (*ilo - 1)].im = atmp_im;
          }
        }

        rscale[*ilo - 1] = j + 1;
        (*ilo)++;
        if (*ilo == *ihi) {
          rscale[*ilo - 1] = *ilo;
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/* End of code generation (xzggbal.c) */
