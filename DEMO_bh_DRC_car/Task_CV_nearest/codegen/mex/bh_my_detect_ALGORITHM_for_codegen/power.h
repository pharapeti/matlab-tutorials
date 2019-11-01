/*
 * power.h
 *
 * Code generation for function 'power'
 *
 */

#ifndef POWER_H
#define POWER_H

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
#include "bh_my_detect_ALGORITHM_for_codegen_types.h"

/* Function Declarations */
extern void b_power(const emlrtStack *sp, const emxArray_real_T *a,
                    emxArray_real_T *y);
extern void power(const emlrtStack *sp, const emxArray_real_T *a,
                  emxArray_real_T *y);

#endif

/* End of code generation (power.h) */
