/*
 * bh_mask_fraction_of_BW_image.h
 *
 * Code generation for function 'bh_mask_fraction_of_BW_image'
 *
 */

#ifndef BH_MASK_FRACTION_OF_BW_IMAGE_H
#define BH_MASK_FRACTION_OF_BW_IMAGE_H

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
extern void b_bh_mask_fraction_of_BW_image(const emlrtStack *sp, boolean_T I_BW
  [76800], real_T the_frac, boolean_T *tf_was_applied, real_T *R_max);
extern void bh_mask_fraction_of_BW_image(const emlrtStack *sp,
  emxArray_boolean_T *I_BW);
extern void c_bh_mask_fraction_of_BW_image(const emlrtStack *sp, boolean_T I_BW
  [76800], real_T the_frac);

#endif

/* End of code generation (bh_mask_fraction_of_BW_image.h) */
