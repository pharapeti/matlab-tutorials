/*
 * bh_mask_fraction_of_BW_image.c
 *
 * Code generation for function 'bh_mask_fraction_of_BW_image'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_mask_fraction_of_BW_image.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Function Definitions */
void bh_mask_fraction_of_BW_image(const emlrtStack *sp, emxArray_boolean_T *I_BW)
{
  int32_T R_max;
  int32_T i15;
  int32_T i16;

  /*   [I, tf_was_applied] = bh_mask_fraction_of_BW_image(I_BW, the_frac) */
  /* -------------------------------------------------------------------------       */
  /*  Apply a mask of 0's to the first "N" rows of an image matrix */
  /*  where N is determined by the fraction scalar provided by the user */
  /*   */
  /*  When you view this masked image, the TOP portion of the image will appear blacked out */
  /*   */
  /*  EXAMPLE:     if our input image has 9 rows,  */
  /*               and if we set the_frac = 2/3  */
  /*                */
  /*               then the desired effect would look something like this: */
  /*   */
  /*              0-------------------------->  u, x */
  /*   row #1     | 0 0 0 0 0 0 0 0  */
  /*   row #2     | 0 0 0 0 0 0 0 0  */
  /*   row #3     | 0 0 0 0 0 0 0 0  */
  /*   row #4     | 0 0 0 0 0 0 0 0  */
  /*   row #5     | 0 0 0 0 0 0 0 0  */
  /*   row #6     | 0 0 0 0 0 0 0 0  */
  /*   row #7     | . . . . . . . .  */
  /*   row #8     | . . . . . . . .  */
  /*   row #9     | . . . . . . . .  */
  /*          v, y */
  /* -------------------------------------------------------------------------       */
  /*  OK: now do your thing */
  /*  Mask the top portion of the image: */
  R_max = (int32_T)muDoubleScalarRound((real_T)I_BW->size[0] * 0.4);
  if ((R_max != I_BW->size[0]) && (R_max > 1)) {
    i15 = I_BW->size[0];
    if (!(R_max <= i15)) {
      emlrtDynamicBoundsCheckR2012b(R_max, 1, i15, &emlrtBCI, sp);
    }

    for (i15 = 0; i15 < 320; i15++) {
      for (i16 = 0; i16 < R_max; i16++) {
        I_BW->data[i16 + I_BW->size[0] * i15] = false;
      }
    }
  } else {
    /*  do nothing */
  }

  /*  bh_ignore_fraction_of_BW_image(I_BW, frac) */
}

/* End of code generation (bh_mask_fraction_of_BW_image.c) */
