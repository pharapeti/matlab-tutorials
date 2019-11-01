/*
 * File: abs.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "abs.h"

/* Function Definitions */

/*
 * Arguments    : const double x[3]
 *                double y[3]
 * Return Type  : void
 */
void b_abs(const double x[3], double y[3])
{
  int k;
  for (k = 0; k < 3; k++) {
    y[k] = fabs(x[k]);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
