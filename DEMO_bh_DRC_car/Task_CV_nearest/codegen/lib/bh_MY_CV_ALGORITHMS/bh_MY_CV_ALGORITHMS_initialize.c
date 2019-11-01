/*
 * File: bh_MY_CV_ALGORITHMS_initialize.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "bh_MY_CV_ALGORITHMS_initialize.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void bh_MY_CV_ALGORITHMS_initialize(void)
{
  rt_InitInfAndNaN(8U);
  c_bh_my_detect_ALGORITHM_for_co();
  c_bh_my_track_ALGORITHM_for_cod();
}

/*
 * File trailer for bh_MY_CV_ALGORITHMS_initialize.c
 *
 * [EOF]
 */
