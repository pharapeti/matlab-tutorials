/*
 * File: eig.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "eig.h"
#include "xzggev.h"

/* Function Definitions */

/*
 * Arguments    : const double A[9]
 *                creal_T V[9]
 *                creal_T D[9]
 * Return Type  : void
 */
void eig(const double A[9], creal_T V[9], creal_T D[9])
{
  boolean_T p;
  int k;
  creal_T At[9];
  creal_T Bt[9];
  creal_T alpha1[3];
  creal_T beta1[3];
  static const signed char iv2[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 0 };

  double brm;
  double bim;
  double d;
  p = true;
  for (k = 0; k < 9; k++) {
    if (p && ((!rtIsInf(A[k])) && (!rtIsNaN(A[k])))) {
      p = true;
    } else {
      p = false;
    }
  }

  if (!p) {
    for (k = 0; k < 9; k++) {
      V[k].re = rtNaN;
      V[k].im = 0.0;
      D[k].re = 0.0;
      D[k].im = 0.0;
    }

    for (k = 0; k < 3; k++) {
      D[k + 3 * k].re = rtNaN;
      D[k + 3 * k].im = 0.0;
    }
  } else {
    for (k = 0; k < 9; k++) {
      At[k].re = A[k];
      At[k].im = 0.0;
      Bt[k].re = iv2[k];
      Bt[k].im = 0.0;
    }

    xzggev(At, Bt, &k, alpha1, beta1, V);
    for (k = 0; k < 9; k++) {
      D[k].re = 0.0;
      D[k].im = 0.0;
    }

    for (k = 0; k < 3; k++) {
      if (beta1[k].im == 0.0) {
        if (alpha1[k].im == 0.0) {
          D[k + 3 * k].re = alpha1[k].re / beta1[k].re;
          D[k + 3 * k].im = 0.0;
        } else if (alpha1[k].re == 0.0) {
          D[k + 3 * k].re = 0.0;
          D[k + 3 * k].im = alpha1[k].im / beta1[k].re;
        } else {
          D[k + 3 * k].re = alpha1[k].re / beta1[k].re;
          D[k + 3 * k].im = alpha1[k].im / beta1[k].re;
        }
      } else if (beta1[k].re == 0.0) {
        if (alpha1[k].re == 0.0) {
          D[k + 3 * k].re = alpha1[k].im / beta1[k].im;
          D[k + 3 * k].im = 0.0;
        } else if (alpha1[k].im == 0.0) {
          D[k + 3 * k].re = 0.0;
          D[k + 3 * k].im = -(alpha1[k].re / beta1[k].im);
        } else {
          D[k + 3 * k].re = alpha1[k].im / beta1[k].im;
          D[k + 3 * k].im = -(alpha1[k].re / beta1[k].im);
        }
      } else {
        brm = fabs(beta1[k].re);
        bim = fabs(beta1[k].im);
        if (brm > bim) {
          bim = beta1[k].im / beta1[k].re;
          d = beta1[k].re + bim * beta1[k].im;
          D[k + 3 * k].re = (alpha1[k].re + bim * alpha1[k].im) / d;
          D[k + 3 * k].im = (alpha1[k].im - bim * alpha1[k].re) / d;
        } else if (bim == brm) {
          if (beta1[k].re > 0.0) {
            bim = 0.5;
          } else {
            bim = -0.5;
          }

          if (beta1[k].im > 0.0) {
            d = 0.5;
          } else {
            d = -0.5;
          }

          D[k + 3 * k].re = (alpha1[k].re * bim + alpha1[k].im * d) / brm;
          D[k + 3 * k].im = (alpha1[k].im * bim - alpha1[k].re * d) / brm;
        } else {
          bim = beta1[k].re / beta1[k].im;
          d = beta1[k].im + bim * beta1[k].re;
          D[k + 3 * k].re = (bim * alpha1[k].re + alpha1[k].im) / d;
          D[k + 3 * k].im = (bim * alpha1[k].im - alpha1[k].re) / d;
        }
      }
    }
  }
}

/*
 * File trailer for eig.c
 *
 * [EOF]
 */
