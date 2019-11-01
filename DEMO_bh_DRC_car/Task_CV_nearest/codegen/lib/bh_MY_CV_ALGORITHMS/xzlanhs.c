/*
 * File: xzlanhs.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "xzlanhs.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T A[9]
 *                int ilo
 *                int ihi
 * Return Type  : double
 */
double xzlanhs(const creal_T A[9], int ilo, int ihi)
{
  double b_f;
  double scale;
  double sumsq;
  boolean_T firstNonZero;
  int j;
  int i9;
  int i;
  double reAij;
  double imAij;
  double temp2;
  b_f = 0.0;
  if (!(ilo > ihi)) {
    scale = 0.0;
    sumsq = 0.0;
    firstNonZero = true;
    for (j = ilo; j <= ihi; j++) {
      i9 = j + 1;
      if (ihi < j + 1) {
        i9 = ihi;
      }

      for (i = ilo; i <= i9; i++) {
        reAij = A[(i + 3 * (j - 1)) - 1].re;
        imAij = A[(i + 3 * (j - 1)) - 1].im;
        if (reAij != 0.0) {
          reAij = fabs(reAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = reAij;
            firstNonZero = false;
          } else if (scale < reAij) {
            temp2 = scale / reAij;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            scale = reAij;
          } else {
            temp2 = reAij / scale;
            sumsq += temp2 * temp2;
          }
        }

        if (imAij != 0.0) {
          reAij = fabs(imAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = reAij;
            firstNonZero = false;
          } else if (scale < reAij) {
            temp2 = scale / reAij;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            scale = reAij;
          } else {
            temp2 = reAij / scale;
            sumsq += temp2 * temp2;
          }
        }
      }
    }

    b_f = scale * sqrt(sumsq);
  }

  return b_f;
}

/*
 * File trailer for xzlanhs.c
 *
 * [EOF]
 */
