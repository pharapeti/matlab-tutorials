/*
 * File: XYZToLAB.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "XYZToLAB.h"
#include "regionprops.h"
#include "bh_my_detect_ALGORITHM_for_codegen_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : double x
 * Return Type  : double
 */
double f(double x)
{
  double y;
  if (x > 0.0088564516790356311) {
    y = rt_powd_snf(x, 0.33333333333333331);
  } else {
    y = (903.2962962962963 * x + 16.0) / 116.0;
  }

  return y;
}

/*
 * File trailer for XYZToLAB.c
 *
 * [EOF]
 */
