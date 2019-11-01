/*
 * xzlartg.h
 *
 * Code generation for function 'xzlartg'
 *
 */

#ifndef XZLARTG_H
#define XZLARTG_H

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
extern void b_xzlartg(const emlrtStack *sp, const creal_T b_f, const creal_T g,
                      real_T *cs, creal_T *sn);
extern void xzlartg(const emlrtStack *sp, const creal_T b_f, const creal_T g,
                    real_T *cs, creal_T *sn, creal_T *r);

#endif

/* End of code generation (xzlartg.h) */
