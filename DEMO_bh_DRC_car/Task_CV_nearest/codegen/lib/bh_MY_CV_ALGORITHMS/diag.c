/*
 * File: diag.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "diag.h"

/* Function Definitions */

/*
 * Arguments    : const double v[9]
 *                double d[3]
 * Return Type  : void
 */
void diag(const double v[9], double d[3])
{
  int j;
  for (j = 0; j < 3; j++) {
    d[j] = v[j << 2];
  }
}

/*
 * File trailer for diag.c
 *
 * [EOF]
 */
