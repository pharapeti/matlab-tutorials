/*
 * xzggev.c
 *
 * Code generation for function 'xzggev'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "xzggev.h"
#include "eml_int_forloop_overflow_check.h"
#include "xzlartg.h"
#include "xzlascl.h"
#include "xzggbak.h"
#include "xztgevc.h"
#include "xzhgeqz.h"
#include "xzgeqr2.h"
#include "xzggbal.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRSInfo lg_emlrtRSI = { 106,/* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo mg_emlrtRSI = { 101,/* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo ng_emlrtRSI = { 100,/* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo og_emlrtRSI = { 94, /* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo pg_emlrtRSI = { 92, /* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo qg_emlrtRSI = { 84, /* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo rg_emlrtRSI = { 39, /* lineNo */
  "xzggev",                            /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"/* pathName */
};

static emlrtRSInfo ei_emlrtRSI = { 14, /* lineNo */
  "xzunmqr",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzunmqr.m"/* pathName */
};

static emlrtRSInfo fi_emlrtRSI = { 16, /* lineNo */
  "xzunmqr",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzunmqr.m"/* pathName */
};

static emlrtRSInfo gi_emlrtRSI = { 21, /* lineNo */
  "xzunmqr",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzunmqr.m"/* pathName */
};

static emlrtRSInfo hi_emlrtRSI = { 44, /* lineNo */
  "xzgghrd",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"/* pathName */
};

static emlrtRSInfo ii_emlrtRSI = { 62, /* lineNo */
  "xzgghrd",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"/* pathName */
};

static emlrtRSInfo ji_emlrtRSI = { 64, /* lineNo */
  "xzgghrd",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"/* pathName */
};

static emlrtRSInfo ki_emlrtRSI = { 66, /* lineNo */
  "xzgghrd",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"/* pathName */
};

static emlrtRSInfo li_emlrtRSI = { 71, /* lineNo */
  "xzgghrd",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"/* pathName */
};

static emlrtRSInfo mi_emlrtRSI = { 73, /* lineNo */
  "xzgghrd",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"/* pathName */
};

static emlrtRSInfo ni_emlrtRSI = { 77, /* lineNo */
  "xzgghrd",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"/* pathName */
};

static emlrtRSInfo oi_emlrtRSI = { 79, /* lineNo */
  "xzgghrd",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"/* pathName */
};

/* Function Definitions */

/*
 *
 */
void xzggev(const emlrtStack *sp, creal_T A[9], creal_T B[9], int32_T *info,
            creal_T alpha1[3], creal_T beta1[3], creal_T V[9])
{
  real_T anrm;
  int32_T jcol;
  boolean_T exitg1;
  real_T absxk;
  boolean_T ilascl;
  int32_T i;
  real_T anrmto;
  boolean_T ilbscl;
  real_T bnrm;
  real_T bnrmto;
  int32_T ilo;
  int32_T ihi;
  int32_T rscale[3];
  creal_T tau[3];
  creal_T taui;
  int8_T I[9];
  int32_T j;
  real_T stemp_re;
  real_T stemp_im;
  real_T c;
  creal_T dc0;
  real_T A_re;
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
  *info = 0;
  st.site = &rg_emlrtRSI;
  anrm = 0.0;
  jcol = 0;
  exitg1 = false;
  while ((!exitg1) && (jcol < 9)) {
    absxk = muDoubleScalarHypot(A[jcol].re, A[jcol].im);
    if (muDoubleScalarIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }

      jcol++;
    }
  }

  if (!((!muDoubleScalarIsInf(anrm)) && (!muDoubleScalarIsNaN(anrm)))) {
    for (i = 0; i < 3; i++) {
      alpha1[i].re = rtNaN;
      alpha1[i].im = 0.0;
      beta1[i].re = rtNaN;
      beta1[i].im = 0.0;
    }

    for (jcol = 0; jcol < 9; jcol++) {
      V[jcol].re = rtNaN;
      V[jcol].im = 0.0;
    }
  } else {
    ilascl = false;
    anrmto = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      anrmto = 6.7178761075670888E-139;
      ilascl = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
      }
    }

    if (ilascl) {
      xzlascl(anrm, anrmto, A);
    }

    ilbscl = false;
    bnrm = 0.0;
    jcol = 0;
    exitg1 = false;
    while ((!exitg1) && (jcol < 9)) {
      absxk = muDoubleScalarHypot(B[jcol].re, B[jcol].im);
      if (muDoubleScalarIsNaN(absxk)) {
        bnrm = rtNaN;
        exitg1 = true;
      } else {
        if (absxk > bnrm) {
          bnrm = absxk;
        }

        jcol++;
      }
    }

    bnrmto = bnrm;
    if ((bnrm > 0.0) && (bnrm < 6.7178761075670888E-139)) {
      bnrmto = 6.7178761075670888E-139;
      ilbscl = true;
    }

    if (ilbscl) {
      xzlascl(bnrm, bnrmto, B);
    }

    st.site = &qg_emlrtRSI;
    xzggbal(&st, A, B, &ilo, &ihi, rscale);
    st.site = &pg_emlrtRSI;
    xzgeqr2(&st, B, ilo, ihi, tau);
    st.site = &og_emlrtRSI;
    for (i = ilo - 1; i + 1 <= ihi; i++) {
      taui.re = tau[(i - ilo) + 1].re;
      taui.im = -tau[(i - ilo) + 1].im;
      b_st.site = &ei_emlrtRSI;
      for (j = ilo - 1; j + 1 < 4; j++) {
        stemp_re = A[i + 3 * j].re;
        stemp_im = -A[i + 3 * j].im;
        b_st.site = &fi_emlrtRSI;
        if ((!(i + 2 > ihi)) && (ihi > 2147483646)) {
          c_st.site = &h_emlrtRSI;
          d_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (jcol = i + 1; jcol + 1 <= ihi; jcol++) {
          stemp_re += A[jcol + 3 * j].re * B[jcol + 3 * i].re + A[jcol + 3 * j].
            im * B[jcol + 3 * i].im;
          stemp_im += A[jcol + 3 * j].re * B[jcol + 3 * i].im - A[jcol + 3 * j].
            im * B[jcol + 3 * i].re;
        }

        absxk = stemp_re;
        stemp_re = taui.re * stemp_re - taui.im * -stemp_im;
        stemp_im = taui.re * -stemp_im + taui.im * absxk;
        A[i + 3 * j].re -= stemp_re;
        A[i + 3 * j].im -= stemp_im;
        b_st.site = &gi_emlrtRSI;
        for (jcol = i + 1; jcol + 1 <= ihi; jcol++) {
          A[jcol + 3 * j].re -= B[jcol + 3 * i].re * stemp_re - B[jcol + 3 * i].
            im * stemp_im;
          A[jcol + 3 * j].im -= B[jcol + 3 * i].re * stemp_im + B[jcol + 3 * i].
            im * stemp_re;
        }
      }
    }

    st.site = &ng_emlrtRSI;
    for (jcol = 0; jcol < 9; jcol++) {
      I[jcol] = 0;
    }

    for (jcol = 0; jcol < 3; jcol++) {
      I[jcol + 3 * jcol] = 1;
    }

    for (jcol = 0; jcol < 9; jcol++) {
      V[jcol].re = I[jcol];
      V[jcol].im = 0.0;
    }

    for (jcol = ilo; jcol < ihi; jcol++) {
      b_st.site = &hi_emlrtRSI;
      for (j = jcol; j + 1 <= ihi; j++) {
        B[j + 3 * (jcol - 1)].re = 0.0;
        B[j + 3 * (jcol - 1)].im = 0.0;
      }
    }

    if (!(ihi < ilo + 2)) {
      jcol = ilo;
      while (jcol < 2) {
        b_st.site = &ii_emlrtRSI;
        xzlartg(&b_st, A[1], A[2], &c, &taui, &dc0);
        A[1] = dc0;
        A[2].re = 0.0;
        A[2].im = 0.0;
        b_st.site = &ji_emlrtRSI;
        c_st.site = &ti_emlrtRSI;
        for (j = 0; j < 2; j++) {
          stemp_re = c * A[1 + 3 * (j + 1)].re + (taui.re * A[2 + 3 * (j + 1)].
            re - taui.im * A[2 + 3 * (j + 1)].im);
          stemp_im = c * A[1 + 3 * (j + 1)].im + (taui.re * A[2 + 3 * (j + 1)].
            im + taui.im * A[2 + 3 * (j + 1)].re);
          absxk = A[1 + 3 * (j + 1)].im;
          A_re = A[1 + 3 * (j + 1)].re;
          A[2 + 3 * (j + 1)].re = c * A[2 + 3 * (j + 1)].re - (taui.re * A[1 + 3
            * (j + 1)].re + taui.im * A[1 + 3 * (j + 1)].im);
          A[2 + 3 * (j + 1)].im = c * A[2 + 3 * (j + 1)].im - (taui.re * absxk -
            taui.im * A_re);
          A[1 + 3 * (j + 1)].re = stemp_re;
          A[1 + 3 * (j + 1)].im = stemp_im;
        }

        b_st.site = &ki_emlrtRSI;
        c_st.site = &ti_emlrtRSI;
        for (j = 0; j < 2; j++) {
          stemp_re = c * B[1 + 3 * (j + 1)].re + (taui.re * B[2 + 3 * (j + 1)].
            re - taui.im * B[2 + 3 * (j + 1)].im);
          stemp_im = c * B[1 + 3 * (j + 1)].im + (taui.re * B[2 + 3 * (j + 1)].
            im + taui.im * B[2 + 3 * (j + 1)].re);
          absxk = B[1 + 3 * (j + 1)].im;
          A_re = B[1 + 3 * (j + 1)].re;
          B[2 + 3 * (j + 1)].re = c * B[2 + 3 * (j + 1)].re - (taui.re * B[1 + 3
            * (j + 1)].re + taui.im * B[1 + 3 * (j + 1)].im);
          B[2 + 3 * (j + 1)].im = c * B[2 + 3 * (j + 1)].im - (taui.re * absxk -
            taui.im * A_re);
          B[1 + 3 * (j + 1)].re = stemp_re;
          B[1 + 3 * (j + 1)].im = stemp_im;
        }

        b_st.site = &li_emlrtRSI;
        xzlartg(&b_st, B[8], B[5], &c, &taui, &dc0);
        B[8] = dc0;
        B[5].re = 0.0;
        B[5].im = 0.0;
        b_st.site = &mi_emlrtRSI;
        c_st.site = &ui_emlrtRSI;
        for (i = 0; i < 2; i++) {
          stemp_re = c * B[6 + i].re + (taui.re * B[3 + i].re - taui.im * B[3 +
            i].im);
          stemp_im = c * B[6 + i].im + (taui.re * B[3 + i].im + taui.im * B[3 +
            i].re);
          absxk = B[6 + i].im;
          A_re = B[6 + i].re;
          B[3 + i].re = c * B[3 + i].re - (taui.re * B[6 + i].re + taui.im * B[6
            + i].im);
          B[3 + i].im = c * B[3 + i].im - (taui.re * absxk - taui.im * A_re);
          B[6 + i].re = stemp_re;
          B[6 + i].im = stemp_im;
        }

        b_st.site = &ni_emlrtRSI;
        c_st.site = &ui_emlrtRSI;
        for (i = 0; i < 3; i++) {
          stemp_re = c * A[6 + i].re + (taui.re * A[3 + i].re - taui.im * A[3 +
            i].im);
          stemp_im = c * A[6 + i].im + (taui.re * A[3 + i].im + taui.im * A[3 +
            i].re);
          absxk = A[6 + i].im;
          A_re = A[6 + i].re;
          A[3 + i].re = c * A[3 + i].re - (taui.re * A[6 + i].re + taui.im * A[6
            + i].im);
          A[3 + i].im = c * A[3 + i].im - (taui.re * absxk - taui.im * A_re);
          A[6 + i].re = stemp_re;
          A[6 + i].im = stemp_im;
        }

        b_st.site = &oi_emlrtRSI;
        c_st.site = &ui_emlrtRSI;
        for (i = 0; i < 3; i++) {
          stemp_re = c * V[6 + i].re + (taui.re * V[3 + i].re - taui.im * V[3 +
            i].im);
          stemp_im = c * V[6 + i].im + (taui.re * V[3 + i].im + taui.im * V[3 +
            i].re);
          absxk = V[6 + i].re;
          V[3 + i].re = c * V[3 + i].re - (taui.re * V[6 + i].re + taui.im * V[6
            + i].im);
          V[3 + i].im = c * V[3 + i].im - (taui.re * V[6 + i].im - taui.im *
            absxk);
          V[6 + i].re = stemp_re;
          V[6 + i].im = stemp_im;
        }

        jcol = 2;
      }
    }

    st.site = &mg_emlrtRSI;
    xzhgeqz(&st, A, B, ilo, ihi, V, info, alpha1, beta1);
    if (*info == 0) {
      st.site = &lg_emlrtRSI;
      xztgevc(&st, A, B, V);
      xzggbak(V, ilo, ihi, rscale);
      for (jcol = 0; jcol < 3; jcol++) {
        absxk = muDoubleScalarAbs(V[3 * jcol].re) + muDoubleScalarAbs(V[3 * jcol]
          .im);
        for (j = 0; j < 2; j++) {
          A_re = muDoubleScalarAbs(V[(j + 3 * jcol) + 1].re) + muDoubleScalarAbs
            (V[(j + 3 * jcol) + 1].im);
          if (A_re > absxk) {
            absxk = A_re;
          }
        }

        if (absxk >= 6.7178761075670888E-139) {
          absxk = 1.0 / absxk;
          for (j = 0; j < 3; j++) {
            V[j + 3 * jcol].re *= absxk;
            V[j + 3 * jcol].im *= absxk;
          }
        }
      }

      if (ilascl) {
        b_xzlascl(anrmto, anrm, alpha1);
      }

      if (ilbscl) {
        b_xzlascl(bnrmto, bnrm, beta1);
      }
    }
  }
}

/* End of code generation (xzggev.c) */
