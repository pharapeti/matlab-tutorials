/*
 * xzgeqr2.h
 *
 * Code generation for function 'xzgeqr2'
 *
 */

#ifndef XZGEQR2_H
#define XZGEQR2_H

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
extern void xzgeqr2(const emlrtStack *sp, creal_T A[9], int32_T ijmin, int32_T
                    imax, creal_T tau[3]);

#endif

/* End of code generation (xzgeqr2.h) */
