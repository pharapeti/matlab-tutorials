/*
 * xzgeqr2.c
 *
 * Code generation for function 'xzgeqr2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "xzgeqr2.h"
#include "xdlapy3.h"
#include "eml_int_forloop_overflow_check.h"
#include "recip.h"
#include "xnrm2.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRSInfo ch_emlrtRSI = { 21, /* lineNo */
  "xzgeqr2",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgeqr2.m"/* pathName */
};

static emlrtRSInfo dh_emlrtRSI = { 31, /* lineNo */
  "xzgeqr2",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgeqr2.m"/* pathName */
};

static emlrtRSInfo eh_emlrtRSI = { 41, /* lineNo */
  "xzgeqr2",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgeqr2.m"/* pathName */
};

static emlrtRSInfo fh_emlrtRSI = { 20, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo gh_emlrtRSI = { 26, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo hh_emlrtRSI = { 41, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo ih_emlrtRSI = { 53, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo jh_emlrtRSI = { 58, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo kh_emlrtRSI = { 68, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo lh_emlrtRSI = { 71, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo mh_emlrtRSI = { 81, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo qh_emlrtRSI = { 31, /* lineNo */
  "xscal",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal.m"/* pathName */
};

static emlrtRSInfo rh_emlrtRSI = { 18, /* lineNo */
  "xscal",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xscal.m"/* pathName */
};

static emlrtRSInfo sh_emlrtRSI = { 75, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo th_emlrtRSI = { 68, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo uh_emlrtRSI = { 50, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo vh_emlrtRSI = { 103,/* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo wh_emlrtRSI = { 57, /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

static emlrtRSInfo xh_emlrtRSI = { 73, /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo yh_emlrtRSI = { 36, /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo ai_emlrtRSI = { 52, /* lineNo */
  "xgerc",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgerc.m"/* pathName */
};

static emlrtRSInfo bi_emlrtRSI = { 15, /* lineNo */
  "xgerc",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerc.m"/* pathName */
};

static emlrtRSInfo ci_emlrtRSI = { 41, /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo di_emlrtRSI = { 54, /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

/* Function Definitions */
void xzgeqr2(const emlrtStack *sp, creal_T A[9], int32_T ijmin, int32_T imax,
             creal_T tau[3])
{
  int32_T i;
  int32_T iA0;
  creal_T work[3];
  boolean_T overflow;
  int32_T subdiaglen;
  int32_T iAii;
  int32_T iSubdiag;
  creal_T alpha1;
  real_T tautmp_re;
  real_T tautmp_im;
  real_T xnorm;
  real_T beta1;
  int32_T knt;
  real_T atmp_im;
  int32_T b;
  int32_T lastc;
  int32_T k;
  boolean_T exitg2;
  real_T A_im;
  int32_T exitg1;
  int32_T ix;
  real_T c_im;
  creal_T b_alpha1;
  int32_T ia;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  for (i = 0; i < 3; i++) {
    work[i].re = 0.0;
    work[i].im = 0.0;
    tau[i].re = 0.0;
    tau[i].im = 0.0;
  }

  iA0 = (ijmin + 3 * (ijmin - 1)) - 1;
  st.site = &ch_emlrtRSI;
  overflow = ((!(ijmin > imax)) && (imax > 2147483646));
  if (overflow) {
    b_st.site = &h_emlrtRSI;
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (i = ijmin; i <= imax; i++) {
    subdiaglen = imax - i;
    iAii = iA0 + ((i - ijmin) << 2);
    if (i < 3) {
      iSubdiag = iAii + 1;
    } else {
      iSubdiag = iAii;
    }

    st.site = &dh_emlrtRSI;
    alpha1 = A[iAii];
    tautmp_re = 0.0;
    tautmp_im = 0.0;
    if (!(subdiaglen + 1 <= 0)) {
      b_st.site = &fh_emlrtRSI;
      xnorm = xnrm2(&b_st, subdiaglen, A, iSubdiag + 1);
      if ((xnorm != 0.0) || (A[iAii].im != 0.0)) {
        b_st.site = &gh_emlrtRSI;
        beta1 = xdlapy3(A[iAii].re, A[iAii].im, xnorm);
        if (A[iAii].re >= 0.0) {
          beta1 = -beta1;
        }

        if (muDoubleScalarAbs(beta1) < 1.0020841800044864E-292) {
          knt = 0;
          b = iSubdiag + subdiaglen;
          overflow = ((!(iSubdiag + 1 > b)) && (b > 2147483646));
          do {
            knt++;
            b_st.site = &hh_emlrtRSI;
            c_st.site = &qh_emlrtRSI;
            d_st.site = &rh_emlrtRSI;
            if (overflow) {
              e_st.site = &h_emlrtRSI;
              f_st.site = &h_emlrtRSI;
              check_forloop_overflow_error(&f_st);
            }

            for (k = iSubdiag; k + 1 <= b; k++) {
              xnorm = A[k].re;
              A_im = A[k].im;
              A[k].re = 9.9792015476736E+291 * xnorm - 0.0 * A_im;
              A[k].im = 9.9792015476736E+291 * A_im + 0.0 * xnorm;
            }

            beta1 *= 9.9792015476736E+291;
            alpha1.re *= 9.9792015476736E+291;
            alpha1.im *= 9.9792015476736E+291;
          } while (!(muDoubleScalarAbs(beta1) >= 1.0020841800044864E-292));

          b_st.site = &ih_emlrtRSI;
          xnorm = xnrm2(&b_st, subdiaglen, A, iSubdiag + 1);
          b_st.site = &jh_emlrtRSI;
          beta1 = xdlapy3(alpha1.re, alpha1.im, xnorm);
          if (alpha1.re >= 0.0) {
            beta1 = -beta1;
          }

          xnorm = beta1 - alpha1.re;
          if (0.0 - alpha1.im == 0.0) {
            tautmp_re = xnorm / beta1;
            tautmp_im = 0.0;
          } else if (xnorm == 0.0) {
            tautmp_re = 0.0;
            tautmp_im = (0.0 - alpha1.im) / beta1;
          } else {
            tautmp_re = xnorm / beta1;
            tautmp_im = (0.0 - alpha1.im) / beta1;
          }

          b_alpha1.re = alpha1.re - beta1;
          b_alpha1.im = alpha1.im;
          alpha1 = recip(b_alpha1);
          b_st.site = &kh_emlrtRSI;
          c_st.site = &qh_emlrtRSI;
          b = iSubdiag + subdiaglen;
          d_st.site = &rh_emlrtRSI;
          overflow = ((!(iSubdiag + 1 > b)) && (b > 2147483646));
          if (overflow) {
            e_st.site = &h_emlrtRSI;
            f_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          while (iSubdiag + 1 <= b) {
            xnorm = A[iSubdiag].re;
            A_im = A[iSubdiag].im;
            A[iSubdiag].re = alpha1.re * xnorm - alpha1.im * A_im;
            A[iSubdiag].im = alpha1.re * A_im + alpha1.im * xnorm;
            iSubdiag++;
          }

          b_st.site = &lh_emlrtRSI;
          overflow = ((!(1 > knt)) && (knt > 2147483646));
          if (overflow) {
            c_st.site = &h_emlrtRSI;
            d_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          for (k = 1; k <= knt; k++) {
            beta1 *= 1.0020841800044864E-292;
          }

          alpha1.re = beta1;
          alpha1.im = 0.0;
        } else {
          xnorm = beta1 - A[iAii].re;
          atmp_im = 0.0 - A[iAii].im;
          if (atmp_im == 0.0) {
            tautmp_re = xnorm / beta1;
            tautmp_im = 0.0;
          } else if (xnorm == 0.0) {
            tautmp_re = 0.0;
            tautmp_im = atmp_im / beta1;
          } else {
            tautmp_re = xnorm / beta1;
            tautmp_im = atmp_im / beta1;
          }

          alpha1.re = A[iAii].re - beta1;
          alpha1.im = A[iAii].im;
          alpha1 = recip(alpha1);
          b_st.site = &mh_emlrtRSI;
          c_st.site = &qh_emlrtRSI;
          b = iSubdiag + subdiaglen;
          d_st.site = &rh_emlrtRSI;
          overflow = ((!(iSubdiag + 1 > b)) && (b > 2147483646));
          if (overflow) {
            e_st.site = &h_emlrtRSI;
            f_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          while (iSubdiag + 1 <= b) {
            xnorm = A[iSubdiag].re;
            A_im = A[iSubdiag].im;
            A[iSubdiag].re = alpha1.re * xnorm - alpha1.im * A_im;
            A[iSubdiag].im = alpha1.re * A_im + alpha1.im * xnorm;
            iSubdiag++;
          }

          alpha1.re = beta1;
          alpha1.im = 0.0;
        }
      }
    }

    A[iAii] = alpha1;
    tau[i - ijmin].re = tautmp_re;
    tau[i - ijmin].im = tautmp_im;
    if (i < 3) {
      xnorm = A[iAii].re;
      atmp_im = A[iAii].im;
      A[iAii].re = 1.0;
      A[iAii].im = 0.0;
      tautmp_im = -tautmp_im;
      st.site = &eh_emlrtRSI;
      if ((tautmp_re != 0.0) || (tautmp_im != 0.0)) {
        iSubdiag = iAii + subdiaglen;
        while ((subdiaglen + 1 > 0) && ((A[iSubdiag].re == 0.0) && (A[iSubdiag].
                 im == 0.0))) {
          subdiaglen--;
          iSubdiag--;
        }

        b_st.site = &uh_emlrtRSI;
        lastc = 3 - i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          iSubdiag = (iAii + (lastc - 1) * 3) + 4;
          knt = iSubdiag + subdiaglen;
          c_st.site = &vh_emlrtRSI;
          overflow = ((!(iSubdiag > knt)) && (knt > 2147483646));
          if (overflow) {
            d_st.site = &h_emlrtRSI;
            e_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }

          do {
            exitg1 = 0;
            if (iSubdiag <= knt) {
              if ((A[iSubdiag - 1].re != 0.0) || (A[iSubdiag - 1].im != 0.0)) {
                exitg1 = 1;
              } else {
                iSubdiag++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        subdiaglen = -1;
        lastc = 0;
      }

      if (subdiaglen + 1 > 0) {
        b_st.site = &th_emlrtRSI;
        c_st.site = &wh_emlrtRSI;
        if (lastc != 0) {
          d_st.site = &yh_emlrtRSI;
          overflow = ((!(1 > lastc)) && (lastc > 2147483646));
          if (overflow) {
            e_st.site = &h_emlrtRSI;
            f_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }

          for (iSubdiag = 1; iSubdiag <= lastc; iSubdiag++) {
            work[iSubdiag - 1].re = 0.0;
            work[iSubdiag - 1].im = 0.0;
          }

          iSubdiag = 0;
          knt = (iAii + 3 * (lastc - 1)) + 4;
          for (k = iAii + 4; k <= knt; k += 3) {
            ix = iAii;
            beta1 = 0.0;
            c_im = 0.0;
            b = k + subdiaglen;
            d_st.site = &xh_emlrtRSI;
            overflow = ((!(k > b)) && (b > 2147483646));
            if (overflow) {
              e_st.site = &h_emlrtRSI;
              f_st.site = &h_emlrtRSI;
              check_forloop_overflow_error(&f_st);
            }

            for (ia = k - 1; ia + 1 <= b; ia++) {
              beta1 += A[ia].re * A[ix].re + A[ia].im * A[ix].im;
              c_im += A[ia].re * A[ix].im - A[ia].im * A[ix].re;
              ix++;
            }

            work[iSubdiag].re += beta1 - 0.0 * c_im;
            work[iSubdiag].im += c_im + 0.0 * beta1;
            iSubdiag++;
          }
        }

        b_st.site = &sh_emlrtRSI;
        c_st.site = &ai_emlrtRSI;
        d_st.site = &bi_emlrtRSI;
        if (!((-tautmp_re == 0.0) && (-tautmp_im == 0.0))) {
          iSubdiag = iAii + 3;
          knt = 0;
          e_st.site = &ci_emlrtRSI;
          for (k = 1; k <= lastc; k++) {
            if ((work[knt].re != 0.0) || (work[knt].im != 0.0)) {
              beta1 = work[knt].re * -tautmp_re + work[knt].im * -tautmp_im;
              c_im = work[knt].re * -tautmp_im - work[knt].im * -tautmp_re;
              ix = iAii;
              b = (subdiaglen + iSubdiag) + 1;
              e_st.site = &di_emlrtRSI;
              overflow = ((!(iSubdiag + 1 > b)) && (b > 2147483646));
              if (overflow) {
                f_st.site = &h_emlrtRSI;
                g_st.site = &h_emlrtRSI;
                check_forloop_overflow_error(&g_st);
              }

              for (ia = iSubdiag; ia + 1 <= b; ia++) {
                A_im = A[ix].re * c_im + A[ix].im * beta1;
                A[ia].re += A[ix].re * beta1 - A[ix].im * c_im;
                A[ia].im += A_im;
                ix++;
              }
            }

            knt++;
            iSubdiag += 3;
          }
        }
      }

      A[iAii].re = xnorm;
      A[iAii].im = atmp_im;
    }
  }
}

/* End of code generation (xzgeqr2.c) */
