/*
 * find.h
 *
 * Code generation for function 'find'
 *
 */

#ifndef FIND_H
#define FIND_H

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
extern void b_eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
  emxArray_int32_T *i);
extern void eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
                     emxArray_int32_T *i);

#endif

/* End of code generation (find.h) */
