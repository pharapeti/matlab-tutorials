/*
 * xzggbak.c
 *
 * Code generation for function 'xzggbak'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "xzggbak.h"

/* Function Definitions */
void xzggbak(creal_T V[9], int32_T ilo, int32_T ihi, const int32_T rscale[3])
{
  int32_T i;
  int32_T k;
  int32_T j;
  real_T tmp_re;
  real_T tmp_im;
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

/* End of code generation (xzggbak.c) */
