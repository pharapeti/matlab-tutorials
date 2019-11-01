/*
 * File: linearizeSRGB.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "linearizeSRGB.h"
#include "regionprops.h"
#include "bh_my_detect_ALGORITHM_for_codegen_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : double x
 * Return Type  : double
 */
double parametricCurveA(double x)
{
  double y;
  if (x < 0.04045) {
    y = 0.077399380804953566 * x;
  } else {
    y = rt_powd_snf(0.94786729857819907 * x + 0.052132701421800952, 2.4);
  }

  return y;
}

/*
 * File trailer for linearizeSRGB.c
 *
 * [EOF]
 */
