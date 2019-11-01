/*
 * xztgevc.c
 *
 * Code generation for function 'xztgevc'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "xztgevc.h"

/* Variable Definitions */
static emlrtRTEInfo ig_emlrtRTEI = { 113,/* lineNo */
  13,                                  /* colNo */
  "xztgevc",                           /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xztgevc.m"/* pName */
};

/* Function Definitions */
void xztgevc(const emlrtStack *sp, const creal_T A[9], const creal_T B[9],
             creal_T V[9])
{
  int32_T i;
  real_T anorm;
  real_T rworka[3];
  int32_T j;
  real_T temp;
  real_T ascale;
  real_T y;
  real_T bnorm;
  real_T rworkb[3];
  real_T bscale;
  int32_T je;
  int32_T jr;
  real_T sbeta;
  real_T salpha_re;
  real_T salpha_im;
  real_T acoeff;
  real_T bcoeff_re;
  real_T bcoeff_im;
  boolean_T lscalea;
  boolean_T lscaleb;
  real_T scale;
  real_T acoefa;
  real_T bcoefa;
  creal_T work1[3];
  real_T dmin;
  int32_T b_j;
  creal_T work2[3];
  for (i = 0; i < 3; i++) {
    rworka[i] = 0.0;
  }

  anorm = muDoubleScalarAbs(A[0].re) + muDoubleScalarAbs(A[0].im);
  for (j = 0; j < 2; j++) {
    for (i = 0; i <= j; i++) {
      rworka[j + 1] += muDoubleScalarAbs(A[i + 3 * (j + 1)].re) +
        muDoubleScalarAbs(A[i + 3 * (j + 1)].im);
    }

    y = rworka[j + 1] + (muDoubleScalarAbs(A[(j + 3 * (j + 1)) + 1].re) +
                         muDoubleScalarAbs(A[(j + 3 * (j + 1)) + 1].im));
    if (y > anorm) {
      anorm = y;
    }
  }

  temp = anorm;
  if (2.2250738585072014E-308 > anorm) {
    temp = 2.2250738585072014E-308;
  }

  ascale = 1.0 / temp;
  for (i = 0; i < 3; i++) {
    rworkb[i] = 0.0;
  }

  bnorm = muDoubleScalarAbs(B[0].re) + muDoubleScalarAbs(B[0].im);
  for (j = 0; j < 2; j++) {
    for (i = 0; i <= j; i++) {
      rworkb[j + 1] += muDoubleScalarAbs(B[i + 3 * (j + 1)].re) +
        muDoubleScalarAbs(B[i + 3 * (j + 1)].im);
    }

    y = rworkb[j + 1] + (muDoubleScalarAbs(B[(j + 3 * (j + 1)) + 1].re) +
                         muDoubleScalarAbs(B[(j + 3 * (j + 1)) + 1].im));
    if (y > bnorm) {
      bnorm = y;
    }
  }

  temp = bnorm;
  if (2.2250738585072014E-308 > bnorm) {
    temp = 2.2250738585072014E-308;
  }

  bscale = 1.0 / temp;
  for (je = 0; je < 3; je++) {
    if ((muDoubleScalarAbs(A[(3 * (2 - je) - je) + 2].re) + muDoubleScalarAbs(A
          [(3 * (2 - je) - je) + 2].im) <= 2.2250738585072014E-308) &&
        (muDoubleScalarAbs(B[(3 * (2 - je) - je) + 2].re) <=
         2.2250738585072014E-308)) {
      for (jr = 0; jr < 3; jr++) {
        V[jr + 3 * (2 - je)].re = 0.0;
        V[jr + 3 * (2 - je)].im = 0.0;
      }

      V[(3 * (2 - je) - je) + 2].re = 1.0;
      V[(3 * (2 - je) - je) + 2].im = 0.0;
    } else {
      temp = (muDoubleScalarAbs(A[(3 * (2 - je) - je) + 2].re) +
              muDoubleScalarAbs(A[(3 * (2 - je) - je) + 2].im)) * ascale;
      y = muDoubleScalarAbs(B[(3 * (2 - je) - je) + 2].re) * bscale;
      if (y > temp) {
        temp = y;
      }

      if (2.2250738585072014E-308 > temp) {
        temp = 2.2250738585072014E-308;
      }

      temp = 1.0 / temp;
      sbeta = temp * B[(3 * (2 - je) - je) + 2].re * bscale;
      salpha_re = ascale * (temp * A[(3 * (2 - je) - je) + 2].re);
      salpha_im = ascale * (temp * A[(3 * (2 - je) - je) + 2].im);
      acoeff = sbeta * ascale;
      bcoeff_re = bscale * salpha_re;
      bcoeff_im = bscale * salpha_im;
      if ((muDoubleScalarAbs(sbeta) >= 2.2250738585072014E-308) &&
          (muDoubleScalarAbs(acoeff) < 3.0062525400134592E-292)) {
        lscalea = true;
      } else {
        lscalea = false;
      }

      if ((muDoubleScalarAbs(salpha_re) + muDoubleScalarAbs(salpha_im) >=
           2.2250738585072014E-308) && (muDoubleScalarAbs(bcoeff_re) +
           muDoubleScalarAbs(bcoeff_im) < 3.0062525400134592E-292)) {
        lscaleb = true;
      } else {
        lscaleb = false;
      }

      scale = 1.0;
      if (lscalea) {
        temp = anorm;
        if (3.3264005158911995E+291 < anorm) {
          temp = 3.3264005158911995E+291;
        }

        scale = 3.0062525400134592E-292 / muDoubleScalarAbs(sbeta) * temp;
      }

      if (lscaleb) {
        temp = bnorm;
        if (3.3264005158911995E+291 < bnorm) {
          temp = 3.3264005158911995E+291;
        }

        y = 3.0062525400134592E-292 / (muDoubleScalarAbs(salpha_re) +
          muDoubleScalarAbs(salpha_im)) * temp;
        if (y > scale) {
          scale = y;
        }
      }

      if (lscalea || lscaleb) {
        temp = muDoubleScalarAbs(acoeff);
        y = muDoubleScalarAbs(bcoeff_re) + muDoubleScalarAbs(bcoeff_im);
        if (1.0 > temp) {
          temp = 1.0;
        }

        if (y > temp) {
          temp = y;
        }

        y = 1.0 / (2.2250738585072014E-308 * temp);
        if (y < scale) {
          scale = y;
        }

        if (lscalea) {
          acoeff = ascale * (scale * sbeta);
        } else {
          acoeff *= scale;
        }

        if (lscaleb) {
          bcoeff_re = bscale * (scale * salpha_re);
          bcoeff_im = bscale * (scale * salpha_im);
        } else {
          bcoeff_re *= scale;
          bcoeff_im *= scale;
        }
      }

      acoefa = muDoubleScalarAbs(acoeff);
      bcoefa = muDoubleScalarAbs(bcoeff_re) + muDoubleScalarAbs(bcoeff_im);
      for (jr = 0; jr < 3; jr++) {
        work1[jr].re = 0.0;
        work1[jr].im = 0.0;
      }

      work1[2 - je].re = 1.0;
      work1[2 - je].im = 0.0;
      dmin = 2.2204460492503131E-16 * acoefa * anorm;
      y = 2.2204460492503131E-16 * bcoefa * bnorm;
      if (y > dmin) {
        dmin = y;
      }

      if (2.2250738585072014E-308 > dmin) {
        dmin = 2.2250738585072014E-308;
      }

      for (jr = 0; jr <= 1 - je; jr++) {
        work1[jr].re = acoeff * A[jr + 3 * (2 - je)].re - (bcoeff_re * B[jr + 3 *
          (2 - je)].re - bcoeff_im * B[jr + 3 * (2 - je)].im);
        work1[jr].im = acoeff * A[jr + 3 * (2 - je)].im - (bcoeff_re * B[jr + 3 *
          (2 - je)].im + bcoeff_im * B[jr + 3 * (2 - je)].re);
      }

      work1[2 - je].re = 1.0;
      work1[2 - je].im = 0.0;
      i = (int32_T)((1.0 + (-1.0 - ((3.0 + -(real_T)je) - 1.0))) / -1.0);
      emlrtForLoopVectorCheckR2012b((3.0 + -(real_T)je) - 1.0, -1.0, 1.0,
        mxDOUBLE_CLASS, i, &ig_emlrtRTEI, sp);
      for (j = 0; j < i; j++) {
        b_j = 1 - (je + j);
        salpha_re = acoeff * A[b_j + 3 * b_j].re - (bcoeff_re * B[b_j + 3 * b_j]
          .re - bcoeff_im * B[b_j + 3 * b_j].im);
        salpha_im = acoeff * A[b_j + 3 * b_j].im - (bcoeff_re * B[b_j + 3 * b_j]
          .im + bcoeff_im * B[b_j + 3 * b_j].re);
        if (muDoubleScalarAbs(salpha_re) + muDoubleScalarAbs(salpha_im) <= dmin)
        {
          salpha_re = dmin;
          salpha_im = 0.0;
        }

        if ((muDoubleScalarAbs(salpha_re) + muDoubleScalarAbs(salpha_im) < 1.0) &&
            (muDoubleScalarAbs(work1[b_j].re) + muDoubleScalarAbs(work1[b_j].im)
             >= 1.4980776123852632E+307 * (muDoubleScalarAbs(salpha_re) +
              muDoubleScalarAbs(salpha_im)))) {
          temp = 1.0 / (muDoubleScalarAbs(work1[b_j].re) + muDoubleScalarAbs
                        (work1[b_j].im));
          for (jr = 0; jr <= 2 - je; jr++) {
            work1[jr].re *= temp;
            work1[jr].im *= temp;
          }
        }

        y = -work1[b_j].re;
        if (salpha_im == 0.0) {
          if (-work1[b_j].im == 0.0) {
            work1[b_j].re = -work1[b_j].re / salpha_re;
            work1[b_j].im = 0.0;
          } else if (-work1[b_j].re == 0.0) {
            work1[b_j].re = 0.0;
            work1[b_j].im = -work1[b_j].im / salpha_re;
          } else {
            work1[b_j].re = -work1[b_j].re / salpha_re;
            work1[b_j].im = -work1[b_j].im / salpha_re;
          }
        } else if (salpha_re == 0.0) {
          if (-work1[b_j].re == 0.0) {
            work1[b_j].re = -work1[b_j].im / salpha_im;
            work1[b_j].im = 0.0;
          } else if (-work1[b_j].im == 0.0) {
            work1[b_j].re = 0.0;
            work1[b_j].im = -(y / salpha_im);
          } else {
            work1[b_j].re = -work1[b_j].im / salpha_im;
            work1[b_j].im = -(y / salpha_im);
          }
        } else {
          sbeta = muDoubleScalarAbs(salpha_re);
          scale = muDoubleScalarAbs(salpha_im);
          if (sbeta > scale) {
            scale = salpha_im / salpha_re;
            temp = salpha_re + scale * salpha_im;
            work1[b_j].re = (-work1[b_j].re + scale * -work1[b_j].im) / temp;
            work1[b_j].im = (-work1[b_j].im - scale * y) / temp;
          } else if (scale == sbeta) {
            if (salpha_re > 0.0) {
              temp = 0.5;
            } else {
              temp = -0.5;
            }

            if (salpha_im > 0.0) {
              scale = 0.5;
            } else {
              scale = -0.5;
            }

            work1[b_j].re = (-work1[b_j].re * temp + -work1[b_j].im * scale) /
              sbeta;
            work1[b_j].im = (-work1[b_j].im * temp - y * scale) / sbeta;
          } else {
            scale = salpha_re / salpha_im;
            temp = salpha_im + scale * salpha_re;
            work1[b_j].re = (scale * -work1[b_j].re + -work1[b_j].im) / temp;
            work1[b_j].im = (scale * -work1[b_j].im - y) / temp;
          }
        }

        if (b_j + 1 > 1) {
          if (muDoubleScalarAbs(work1[1].re) + muDoubleScalarAbs(work1[1].im) >
              1.0) {
            temp = 1.0 / (muDoubleScalarAbs(work1[1].re) + muDoubleScalarAbs
                          (work1[1].im));
            if (acoefa * rworka[1] + bcoefa * rworkb[1] >=
                1.4980776123852632E+307 * temp) {
              for (jr = 0; jr <= 2 - je; jr++) {
                work1[jr].re *= temp;
                work1[jr].im *= temp;
              }
            }
          }

          scale = acoeff * work1[1].re;
          temp = acoeff * work1[1].im;
          sbeta = bcoeff_re * work1[1].re - bcoeff_im * work1[1].im;
          y = bcoeff_re * work1[1].im + bcoeff_im * work1[1].re;
          work1[0].re = (work1[0].re + (scale * A[3].re - temp * A[3].im)) -
            (sbeta * B[3].re - y * B[3].im);
          work1[0].im = (work1[0].im + (scale * A[3].im + temp * A[3].re)) -
            (sbeta * B[3].im + y * B[3].re);
        }
      }

      for (jr = 0; jr < 3; jr++) {
        work2[jr].re = 0.0;
        work2[jr].im = 0.0;
      }

      for (i = 0; i <= 2 - je; i++) {
        for (jr = 0; jr < 3; jr++) {
          work2[jr].re += V[jr + 3 * i].re * work1[i].re - V[jr + 3 * i].im *
            work1[i].im;
          work2[jr].im += V[jr + 3 * i].re * work1[i].im + V[jr + 3 * i].im *
            work1[i].re;
        }
      }

      temp = muDoubleScalarAbs(work2[0].re) + muDoubleScalarAbs(work2[0].im);
      for (jr = 0; jr < 2; jr++) {
        y = muDoubleScalarAbs(work2[jr + 1].re) + muDoubleScalarAbs(work2[jr + 1]
          .im);
        if (y > temp) {
          temp = y;
        }
      }

      if (temp > 2.2250738585072014E-308) {
        temp = 1.0 / temp;
        for (jr = 0; jr < 3; jr++) {
          V[jr + 3 * (2 - je)].re = temp * work2[jr].re;
          V[jr + 3 * (2 - je)].im = temp * work2[jr].im;
        }
      } else {
        for (jr = 0; jr < 3; jr++) {
          V[jr + 3 * (2 - je)].re = 0.0;
          V[jr + 3 * (2 - je)].im = 0.0;
        }
      }
    }
  }
}

/* End of code generation (xztgevc.c) */
