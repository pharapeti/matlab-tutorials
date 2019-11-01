/*
 * File: bh_mask_fraction_of_BW_image.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef BH_MASK_FRACTION_OF_BW_IMAGE_H
#define BH_MASK_FRACTION_OF_BW_IMAGE_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "bh_MY_CV_ALGORITHMS_types.h"

/* Function Declarations */
extern void b_bh_mask_fraction_of_BW_image(boolean_T I_BW[76800], double
  the_frac, boolean_T *tf_was_applied, double *R_max);
extern void bh_mask_fraction_of_BW_image(emxArray_boolean_T *I_BW);
extern void c_bh_mask_fraction_of_BW_image(boolean_T I_BW[76800], double
  the_frac);

#endif

/*
 * File trailer for bh_mask_fraction_of_BW_image.h
 *
 * [EOF]
 */
