/*
 * File: bh_mask_fraction_of_BW_image.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_mask_fraction_of_BW_image.h"
#include "bh_my_detect_ALGORITHM_for_codegen_rtwutil.h"

/* Function Definitions */

/*
 * function [I, tf_was_applied, R_max] = bh_mask_fraction_of_BW_image(I_BW, the_frac)
 * [I, tf_was_applied] = bh_mask_fraction_of_BW_image(I_BW, the_frac)
 * -------------------------------------------------------------------------
 *  Apply a mask of 0's to the first "N" rows of an image matrix
 *  where N is determined by the fraction scalar provided by the user
 *
 *  When you view this masked image, the TOP portion of the image will appear blacked out
 *
 *  EXAMPLE:     if our input image has 9 rows,
 *               and if we set the_frac = 2/3
 *
 *               then the desired effect would look something like this:
 *
 *              0-------------------------->  u, x
 *   row #1     | 0 0 0 0 0 0 0 0
 *   row #2     | 0 0 0 0 0 0 0 0
 *   row #3     | 0 0 0 0 0 0 0 0
 *   row #4     | 0 0 0 0 0 0 0 0
 *   row #5     | 0 0 0 0 0 0 0 0
 *   row #6     | 0 0 0 0 0 0 0 0
 *   row #7     | . . . . . . . .
 *   row #8     | . . . . . . . .
 *   row #9     | . . . . . . . .
 *          v, y
 * -------------------------------------------------------------------------
 * Arguments    : emxArray_boolean_T *I_BW
 * Return Type  : void
 */
void bh_mask_fraction_of_BW_image(emxArray_boolean_T *I_BW)
{
  int R_max;
  int loop_ub;
  int i11;
  signed char tmp_data[96];
  signed char b_tmp_data[96];

  /* 'bh_mask_fraction_of_BW_image:27' if(1 ==coder.target('MATLAB') ) */
  /*  OK: now do your thing */
  /* 'bh_mask_fraction_of_BW_image:36' tf_was_applied = false; */
  /* 'bh_mask_fraction_of_BW_image:37' I              = I_BW; */
  /* 'bh_mask_fraction_of_BW_image:38' NUM_ROWS       = size(I,1); */
  /*  Mask the top portion of the image: */
  /* 'bh_mask_fraction_of_BW_image:41' R_max            = round(   NUM_ROWS * the_frac   ); */
  R_max = (int)rt_roundd_snf((double)I_BW->size[0] * 0.4);

  /* 'bh_mask_fraction_of_BW_image:43' if(R_max == NUM_ROWS) */
  if ((R_max != I_BW->size[0]) && (R_max > 1)) {
    /* 'bh_mask_fraction_of_BW_image:45' else */
    /* 'bh_mask_fraction_of_BW_image:46' if(R_max > 1) */
    /* 'bh_mask_fraction_of_BW_image:47' I(1:R_max, :)    = 0; */
    loop_ub = (signed char)R_max - 1;
    for (i11 = 0; i11 <= loop_ub; i11++) {
      tmp_data[i11] = (signed char)i11;
    }

    loop_ub = (signed char)R_max;
    for (i11 = 0; i11 < loop_ub; i11++) {
      b_tmp_data[i11] = tmp_data[i11];
    }

    for (i11 = 0; i11 < R_max; i11++) {
      for (loop_ub = 0; loop_ub < 320; loop_ub++) {
        I_BW->data[loop_ub + I_BW->size[1] * b_tmp_data[i11]] = false;
      }
    }

    /* 'bh_mask_fraction_of_BW_image:48' tf_was_applied   = true; */
    /* 'bh_mask_fraction_of_BW_image:49' masked_row_range = 1:R_max; */
  } else {
    /*  do nothing */
  }

  /*  bh_ignore_fraction_of_BW_image(I_BW, frac) */
}

/*
 * File trailer for bh_mask_fraction_of_BW_image.c
 *
 * [EOF]
 */
