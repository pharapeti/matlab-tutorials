/*
 * XYZToLAB.c
 *
 * Code generation for function 'XYZToLAB'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "XYZToLAB.h"

/* Function Definitions */
real_T f(real_T x)
{
  real_T y;
  if (x > 0.0088564516790356311) {
    y = muDoubleScalarPower(x, 0.33333333333333331);
  } else {
    y = (903.2962962962963 * x + 16.0) / 116.0;
  }

  return y;
}

/* End of code generation (XYZToLAB.c) */
