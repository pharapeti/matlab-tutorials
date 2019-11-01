/*
 * xzggbal.h
 *
 * Code generation for function 'xzggbal'
 *
 */

#ifndef XZGGBAL_H
#define XZGGBAL_H

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
extern void xzggbal(const emlrtStack *sp, creal_T A[9], creal_T B[9], int32_T
                    *ilo, int32_T *ihi, int32_T rscale[3]);

#endif

/* End of code generation (xzggbal.h) */
