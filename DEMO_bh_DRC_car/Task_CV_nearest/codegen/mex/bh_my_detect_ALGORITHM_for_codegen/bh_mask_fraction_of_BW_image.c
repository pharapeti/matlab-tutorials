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

/*
 * function [I, tf_was_applied, R_max] = bh_mask_fraction_of_BW_image(I_BW, the_frac)
 */
void bh_mask_fraction_of_BW_image(const emlrtStack *sp, emxArray_boolean_T *I_BW)
{
  int32_T R_max;
  int32_T i17;
  int32_T i18;

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
  /* 'bh_mask_fraction_of_BW_image:27' if(1 ==coder.target('MATLAB') ) */
  /*  OK: now do your thing */
  /* 'bh_mask_fraction_of_BW_image:36' tf_was_applied = false; */
  /* 'bh_mask_fraction_of_BW_image:37' I              = I_BW; */
  /* 'bh_mask_fraction_of_BW_image:38' NUM_ROWS       = size(I,1); */
  /*  Mask the top portion of the image: */
  /* 'bh_mask_fraction_of_BW_image:41' R_max            = round(   NUM_ROWS * the_frac   ); */
  R_max = (int32_T)muDoubleScalarRound((real_T)I_BW->size[0] * 0.4);

  /* 'bh_mask_fraction_of_BW_image:43' if(R_max == NUM_ROWS) */
  if ((R_max != I_BW->size[0]) && (R_max > 1)) {
    /* 'bh_mask_fraction_of_BW_image:45' else */
    /* 'bh_mask_fraction_of_BW_image:46' if(R_max > 1) */
    /* 'bh_mask_fraction_of_BW_image:47' I(1:R_max, :)    = 0; */
    i17 = I_BW->size[0];
    if (!(R_max <= i17)) {
      emlrtDynamicBoundsCheckR2012b(R_max, 1, i17, &emlrtBCI, sp);
    }

    for (i17 = 0; i17 < 320; i17++) {
      for (i18 = 0; i18 < R_max; i18++) {
        I_BW->data[i18 + I_BW->size[0] * i17] = false;
      }
    }

    /* 'bh_mask_fraction_of_BW_image:48' tf_was_applied   = true; */
    /* 'bh_mask_fraction_of_BW_image:49' masked_row_range = 1:R_max; */
  } else {
    /*  do nothing */
  }

  /*  bh_ignore_fraction_of_BW_image(I_BW, frac) */
}

/* End of code generation (bh_mask_fraction_of_BW_image.c) */
