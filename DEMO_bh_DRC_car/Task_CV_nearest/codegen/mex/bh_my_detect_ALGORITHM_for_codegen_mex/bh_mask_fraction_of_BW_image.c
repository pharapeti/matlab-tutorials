/*
 * bh_mask_fraction_of_BW_image.c
 *
 * Code generation for function 'bh_mask_fraction_of_BW_image'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "bh_mask_fraction_of_BW_image.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Variable Definitions */
static emlrtBCInfo le_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  47,                                  /* lineNo */
  12,                                  /* colNo */
  "I",                                 /* aName */
  "bh_mask_fraction_of_BW_image",      /* fName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_funcs\\bh_mask_fraction_of_BW_image.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void b_bh_mask_fraction_of_BW_image(const emlrtStack *sp, boolean_T I_BW[76800],
  real_T the_frac, boolean_T *tf_was_applied, real_T *R_max)
{
  int32_T i35;
  int32_T loop_ub;

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
  *tf_was_applied = false;

  /*  Mask the top portion of the image: */
  *R_max = muDoubleScalarRound(240.0 * the_frac);
  if ((!(*R_max == 240.0)) && (*R_max > 1.0)) {
    i35 = (int32_T)*R_max;
    if (!((i35 >= 1) && (i35 <= 240))) {
      emlrtDynamicBoundsCheckR2012b(i35, 1, 240, &le_emlrtBCI, sp);
    }

    loop_ub = (int32_T)*R_max;
    for (i35 = 0; i35 < 320; i35++) {
      if (0 <= loop_ub - 1) {
        memset(&I_BW[i35 * 240], 0, (uint32_T)(loop_ub * (int32_T)sizeof
                (boolean_T)));
      }
    }

    *tf_was_applied = true;
  } else {
    /*  do nothing */
  }

  /*  bh_ignore_fraction_of_BW_image(I_BW, frac) */
}

void bh_mask_fraction_of_BW_image(const emlrtStack *sp, emxArray_boolean_T *I_BW)
{
  int32_T R_max;
  int32_T i19;
  int32_T i20;

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
    i19 = I_BW->size[0];
    if (!(R_max <= i19)) {
      emlrtDynamicBoundsCheckR2012b(R_max, 1, i19, &emlrtBCI, sp);
    }

    for (i19 = 0; i19 < 320; i19++) {
      for (i20 = 0; i20 < R_max; i20++) {
        I_BW->data[i20 + I_BW->size[0] * i19] = false;
      }
    }
  } else {
    /*  do nothing */
  }

  /*  bh_ignore_fraction_of_BW_image(I_BW, frac) */
}

void c_bh_mask_fraction_of_BW_image(const emlrtStack *sp, boolean_T I_BW[76800],
  real_T the_frac)
{
  real_T R_max;
  int32_T i36;
  int32_T loop_ub;

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
  R_max = muDoubleScalarRound(240.0 * the_frac);
  if ((!(R_max == 240.0)) && (R_max > 1.0)) {
    i36 = (int32_T)R_max;
    if (!((i36 >= 1) && (i36 <= 240))) {
      emlrtDynamicBoundsCheckR2012b(i36, 1, 240, &le_emlrtBCI, sp);
    }

    loop_ub = (int32_T)R_max;
    for (i36 = 0; i36 < 320; i36++) {
      if (0 <= loop_ub - 1) {
        memset(&I_BW[i36 * 240], 0, (uint32_T)(loop_ub * (int32_T)sizeof
                (boolean_T)));
      }
    }
  } else {
    /*  do nothing */
  }

  /*  bh_ignore_fraction_of_BW_image(I_BW, frac) */
}

/* End of code generation (bh_mask_fraction_of_BW_image.c) */
