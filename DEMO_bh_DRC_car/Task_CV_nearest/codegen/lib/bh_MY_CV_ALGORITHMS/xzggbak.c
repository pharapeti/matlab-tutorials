/*
 * File: xzggbak.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "xzggbak.h"

/* Function Definitions */

/*
 * Arguments    : creal_T V[9]
 *                int ilo
 *                int ihi
 *                const int rscale[3]
 * Return Type  : void
 */
void xzggbak(creal_T V[9], int ilo, int ihi, const int rscale[3])
{
  int i;
  int k;
  int j;
  double tmp_re;
  double tmp_im;
  if (ilo > 1) {
    for (i = ilo - 2; i + 1 >= 1; i--) {
      k = rscale[i] - 1;
      if (rscale[i] != i + 1) {
        for (j = 0; j < 3; j++) {
          tmp_re = V[i + 3 * j].re;
          tmp_im = V[i + 3 * j].im;
          V[i + 3 * j] = V[k + 3 * j];
          V[k + 3 * j].re = tmp_re;
          V[k + 3 * j].im = tmp_im;
        }
      }
    }
  }

  if (ihi < 3) {
    for (i = ihi; i + 1 < 4; i++) {
      k = rscale[i] - 1;
      if (rscale[i] != i + 1) {
        for (j = 0; j < 3; j++) {
          tmp_re = V[i + 3 * j].re;
          tmp_im = V[i + 3 * j].im;
          V[i + 3 * j] = V[k + 3 * j];
          V[k + 3 * j].re = tmp_re;
          V[k + 3 * j].im = tmp_im;
        }
      }
    }
  }
}

/*
 * File trailer for xzggbak.c
 *
 * [EOF]
 */
