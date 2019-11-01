/*
 * _coder_bh_my_detect_ALGORITHM_for_codegen_mex_api.h
 *
 * Code generation for function '_coder_bh_my_detect_ALGORITHM_for_codegen_mex_api'
 *
 */

#ifndef _CODER_BH_MY_DETECT_ALGORITHM_FOR_CODEGEN_MEX_API_H
#define _CODER_BH_MY_DETECT_ALGORITHM_FOR_CODEGEN_MEX_API_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_types.h"

/* Function Declarations */
extern void bh_my_detect_ALGORITHM_for_codegen_api(const mxArray * const prhs[3],
  const mxArray *plhs[3]);
extern void bh_my_lane_preprocess_mask_api(g_bh_my_detect_ALGORITHM_for_co *SD,
  const mxArray * const prhs[3], const mxArray *plhs[2]);
extern void bh_my_track_ALGORITHM_for_codegen_api
  (g_bh_my_detect_ALGORITHM_for_co *SD, const mxArray * const prhs[3], const
   mxArray *plhs[2]);

#endif

/* End of code generation (_coder_bh_my_detect_ALGORITHM_for_codegen_mex_api.h) */
