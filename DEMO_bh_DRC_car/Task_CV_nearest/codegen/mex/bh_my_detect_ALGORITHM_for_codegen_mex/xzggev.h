/*
 * xzggev.h
 *
 * Code generation for function 'xzggev'
 *
 */

#ifndef XZGGEV_H
#define XZGGEV_H

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
extern void xzggev(const emlrtStack *sp, creal_T A[9], creal_T B[9], int32_T
                   *info, creal_T alpha1[3], creal_T beta1[3], creal_T V[9]);

#endif

/* End of code generation (xzggev.h) */
