/*
 * linearizeSRGB.c
 *
 * Code generation for function 'linearizeSRGB'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "linearizeSRGB.h"

/* Function Definitions */
real_T parametricCurveA(real_T x)
{
  real_T y;
  if (x < 0.04045) {
    y = 0.077399380804953566 * x;
  } else {
    y = muDoubleScalarPower(0.94786729857819907 * x + 0.052132701421800952, 2.4);
  }

  return y;
}

/* End of code generation (linearizeSRGB.c) */
