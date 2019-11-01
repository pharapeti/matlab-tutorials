/*
 * xzlartg.c
 *
 * Code generation for function 'xzlartg'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "xzlartg.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Variable Definitions */
static emlrtRSInfo pi_emlrtRSI = { 67, /* lineNo */
  "xzlartg",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlartg.m"/* pathName */
};

static emlrtRSInfo qi_emlrtRSI = { 93, /* lineNo */
  "xzlartg",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlartg.m"/* pathName */
};

static emlrtRSInfo ri_emlrtRSI = { 102,/* lineNo */
  "xzlartg",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlartg.m"/* pathName */
};

static emlrtRSInfo si_emlrtRSI = { 106,/* lineNo */
  "xzlartg",                           /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlartg.m"/* pathName */
};

/* Function Definitions */
void b_xzlartg(const emlrtStack *sp, const creal_T b_f, const creal_T g, real_T *
               cs, creal_T *sn)
{
  real_T scale;
  real_T f2s;
  real_T x;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  int32_T count;
  int32_T rescaledir;
  boolean_T guard1 = false;
  real_T g2;
  boolean_T overflow;
  real_T g2s;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  scale = muDoubleScalarAbs(b_f.re);
  f2s = muDoubleScalarAbs(b_f.im);
  if (f2s > scale) {
    scale = f2s;
  }

  x = muDoubleScalarAbs(g.re);
  f2s = muDoubleScalarAbs(g.im);
  if (f2s > x) {
    x = f2s;
  }

  if (x > scale) {
    scale = x;
  }

  fs_re = b_f.re;
  fs_im = b_f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    x = g2;
    if (1.0 > g2) {
      x = 1.0;
    }

    if (scale <= x * 2.0041683600089728E-292) {
      if ((b_f.re == 0.0) && (b_f.im == 0.0)) {
        *cs = 0.0;
        g2 = muDoubleScalarHypot(gs_re, gs_im);
        sn->re = gs_re / g2;
        sn->im = -gs_im / g2;
      } else {
        st.site = &pi_emlrtRSI;
        overflow = (g2 < 0.0);
        if (overflow) {
          b_st.site = &db_emlrtRSI;
          c_st.site = &db_emlrtRSI;
          b_error(&c_st);
        }

        g2s = muDoubleScalarSqrt(g2);
        *cs = muDoubleScalarHypot(fs_re, fs_im) / g2s;
        x = muDoubleScalarAbs(b_f.re);
        f2s = muDoubleScalarAbs(b_f.im);
        if (f2s > x) {
          x = f2s;
        }

        if (x > 1.0) {
          g2 = muDoubleScalarHypot(b_f.re, b_f.im);
          fs_re = b_f.re / g2;
          fs_im = b_f.im / g2;
        } else {
          scale = 7.4428285367870146E+137 * b_f.re;
          f2s = 7.4428285367870146E+137 * b_f.im;
          g2 = muDoubleScalarHypot(scale, f2s);
          fs_re = scale / g2;
          fs_im = f2s / g2;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
      }
    } else {
      st.site = &qi_emlrtRSI;
      x = 1.0 + g2 / scale;
      overflow = (x < 0.0);
      if (overflow) {
        b_st.site = &db_emlrtRSI;
        c_st.site = &db_emlrtRSI;
        b_error(&c_st);
      }

      f2s = muDoubleScalarSqrt(x);
      fs_re *= f2s;
      fs_im *= f2s;
      *cs = 1.0 / f2s;
      g2 += scale;
      fs_re /= g2;
      fs_im /= g2;
      sn->re = fs_re * gs_re - fs_im * -gs_im;
      sn->im = fs_re * -gs_im + fs_im * gs_re;
      if (rescaledir > 0) {
        st.site = &ri_emlrtRSI;
        overflow = ((!(1 > count)) && (count > 2147483646));
        if (overflow) {
          b_st.site = &h_emlrtRSI;
          c_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
      } else {
        if (rescaledir < 0) {
          st.site = &si_emlrtRSI;
          overflow = ((!(1 > count)) && (count > 2147483646));
          if (overflow) {
            b_st.site = &h_emlrtRSI;
            c_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
        }
      }
    }
  }
}

void xzlartg(const emlrtStack *sp, const creal_T b_f, const creal_T g, real_T
             *cs, creal_T *sn, creal_T *r)
{
  real_T scale;
  real_T f2s;
  real_T x;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  int32_T count;
  int32_T rescaledir;
  boolean_T guard1 = false;
  real_T g2;
  boolean_T overflow;
  real_T g2s;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  scale = muDoubleScalarAbs(b_f.re);
  f2s = muDoubleScalarAbs(b_f.im);
  if (f2s > scale) {
    scale = f2s;
  }

  x = muDoubleScalarAbs(g.re);
  f2s = muDoubleScalarAbs(g.im);
  if (f2s > x) {
    x = f2s;
  }

  if (x > scale) {
    scale = x;
  }

  fs_re = b_f.re;
  fs_im = b_f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
      *r = b_f;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    x = g2;
    if (1.0 > g2) {
      x = 1.0;
    }

    if (scale <= x * 2.0041683600089728E-292) {
      if ((b_f.re == 0.0) && (b_f.im == 0.0)) {
        *cs = 0.0;
        r->re = muDoubleScalarHypot(g.re, g.im);
        r->im = 0.0;
        g2 = muDoubleScalarHypot(gs_re, gs_im);
        sn->re = gs_re / g2;
        sn->im = -gs_im / g2;
      } else {
        st.site = &pi_emlrtRSI;
        overflow = (g2 < 0.0);
        if (overflow) {
          b_st.site = &db_emlrtRSI;
          c_st.site = &db_emlrtRSI;
          b_error(&c_st);
        }

        g2s = muDoubleScalarSqrt(g2);
        *cs = muDoubleScalarHypot(fs_re, fs_im) / g2s;
        x = muDoubleScalarAbs(b_f.re);
        f2s = muDoubleScalarAbs(b_f.im);
        if (f2s > x) {
          x = f2s;
        }

        if (x > 1.0) {
          g2 = muDoubleScalarHypot(b_f.re, b_f.im);
          fs_re = b_f.re / g2;
          fs_im = b_f.im / g2;
        } else {
          scale = 7.4428285367870146E+137 * b_f.re;
          f2s = 7.4428285367870146E+137 * b_f.im;
          g2 = muDoubleScalarHypot(scale, f2s);
          fs_re = scale / g2;
          fs_im = f2s / g2;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
        r->re = *cs * b_f.re + (sn->re * g.re - sn->im * g.im);
        r->im = *cs * b_f.im + (sn->re * g.im + sn->im * g.re);
      }
    } else {
      st.site = &qi_emlrtRSI;
      x = 1.0 + g2 / scale;
      overflow = (x < 0.0);
      if (overflow) {
        b_st.site = &db_emlrtRSI;
        c_st.site = &db_emlrtRSI;
        b_error(&c_st);
      }

      f2s = muDoubleScalarSqrt(x);
      r->re = f2s * fs_re;
      r->im = f2s * fs_im;
      *cs = 1.0 / f2s;
      g2 += scale;
      scale = r->re / g2;
      f2s = r->im / g2;
      sn->re = scale * gs_re - f2s * -gs_im;
      sn->im = scale * -gs_im + f2s * gs_re;
      if (rescaledir > 0) {
        st.site = &ri_emlrtRSI;
        overflow = ((!(1 > count)) && (count > 2147483646));
        if (overflow) {
          b_st.site = &h_emlrtRSI;
          c_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (rescaledir = 1; rescaledir <= count; rescaledir++) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
        }
      } else {
        if (rescaledir < 0) {
          st.site = &si_emlrtRSI;
          overflow = ((!(1 > count)) && (count > 2147483646));
          if (overflow) {
            b_st.site = &h_emlrtRSI;
            c_st.site = &h_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (rescaledir = 1; rescaledir <= count; rescaledir++) {
            r->re *= 1.3435752215134178E-138;
            r->im *= 1.3435752215134178E-138;
          }
        }
      }
    }
  }
}

/* End of code generation (xzlartg.c) */
