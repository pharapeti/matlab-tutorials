/*
 * File: linearizeSRGB.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "linearizeSRGB.h"
#include "XYZToLAB.h"
#include "bh_MY_CV_ALGORITHMS_rtwutil.h"

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
