/*
 * my_KF_general_CLS.h
 *
 * Code generation for function 'my_KF_general_CLS'
 *
 */

#ifndef MY_KF_GENERAL_CLS_H
#define MY_KF_GENERAL_CLS_H

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
extern void my_KF_general_CLS_correct(const emlrtStack *sp, my_KF_general_CLS
  *OBJ, const real_T y_data[], const int32_T y_size[2]);
extern void my_KF_general_CLS_predict(my_KF_general_CLS *OBJ);

#endif

/* End of code generation (my_KF_general_CLS.h) */
