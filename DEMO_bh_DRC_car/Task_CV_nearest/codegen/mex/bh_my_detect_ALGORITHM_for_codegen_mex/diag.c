/*
 * diag.c
 *
 * Code generation for function 'diag'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "diag.h"

/* Function Definitions */
void diag(const real_T v[9], real_T d[3])
{
  int32_T j;
  for (j = 0; j < 3; j++) {
    d[j] = v[j << 2];
  }
}

/* End of code generation (diag.c) */
