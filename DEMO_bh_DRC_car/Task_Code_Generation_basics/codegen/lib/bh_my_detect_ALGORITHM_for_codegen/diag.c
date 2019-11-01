/*
 * File: diag.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "diag.h"

/* Function Definitions */

/*
 * Arguments    : const double v[9]
 *                double d[3]
 * Return Type  : void
 */
void diag(const double v[9], double d[3])
{
  int k;
  for (k = 0; k < 3; k++) {
    d[k] = v[k + 3 * k];
  }
}

/*
 * File trailer for diag.c
 *
 * [EOF]
 */
