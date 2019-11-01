/*
 * my_laneKF_CLS.h
 *
 * Code generation for function 'my_laneKF_CLS'
 *
 */

#ifndef MY_LANEKF_CLS_H
#define MY_LANEKF_CLS_H

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
extern void my_laneKF_CLS_pred_and_correct(const emlrtStack *sp, my_laneKF_CLS
  *OBJ, const boolean_T BW[76800], boolean_T tf_found);

#endif

/* End of code generation (my_laneKF_CLS.h) */
