/*
 * File: abs.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
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
