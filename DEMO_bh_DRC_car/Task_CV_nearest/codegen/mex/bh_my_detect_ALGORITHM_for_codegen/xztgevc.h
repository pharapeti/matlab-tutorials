/*
 * xztgevc.h
 *
 * Code generation for function 'xztgevc'
 *
 */

#ifndef XZTGEVC_H
#define XZTGEVC_H

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
extern void xztgevc(const emlrtStack *sp, const creal_T A[9], const creal_T B[9],
                    creal_T V[9]);

#endif

/* End of code generation (xztgevc.h) */
