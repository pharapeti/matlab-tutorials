/*
 * File: bh_my_lane_preprocess_mask.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "lane_info_CLS.h"
#include "bh_MY_CV_ALGORITHMS_emxutil.h"
#include "bh_mask_fraction_of_BW_image.h"

/* Function Definitions */

/*
 * function [BLUE_out_s, YELL_out_s] = ...
 *     bh_my_lane_preprocess_mask(BLUE_s, YELL_s, fract_for_top_mask)
 * Arguments    : const struct3_T *BLUE_s
 *                const struct3_T *YELL_s
 *                double fract_for_top_mask
 *                struct3_T *BLUE_out_s
 *                struct3_T *YELL_out_s
 * Return Type  : void
 */
void bh_my_lane_preprocess_mask(const struct3_T *BLUE_s, const struct3_T *YELL_s,
  double fract_for_top_mask, struct3_T *BLUE_out_s, struct3_T *YELL_out_s)
{
  boolean_T new_BLUE_BW[76800];
  boolean_T tf_is_detected_BLUE;
  double mask_Rmax;
  boolean_T new_YELL_BW[76800];
  emxArray_int32_T *ii;
  boolean_T tf_is_detected_YELL;
  int idx;
  int mtmp;
  int b_ii;
  boolean_T exitg1;
  emxArray_int32_T *the_ind;
  int b_mtmp;
  static lane_info_CLS_1 BLUE_O;
  static lane_info_CLS_1 YELL_O;
  double vlim[2];

  /* 'bh_my_lane_preprocess_mask:4' [new_BLUE_BW, tmp,mask_Rmax] =  bh_mask_fraction_of_BW_image(BLUE_s.BW, fract_for_top_mask); */
  memcpy(&new_BLUE_BW[0], &BLUE_s->BW[0], 76800U * sizeof(boolean_T));
  b_bh_mask_fraction_of_BW_image(new_BLUE_BW, fract_for_top_mask,
    &tf_is_detected_BLUE, &mask_Rmax);

  /* 'bh_my_lane_preprocess_mask:5' new_YELL_BW                 =  bh_mask_fraction_of_BW_image(YELL_s.BW, fract_for_top_mask); */
  memcpy(&new_YELL_BW[0], &YELL_s->BW[0], 76800U * sizeof(boolean_T));
  emxInit_int32_T(&ii, 1);
  c_bh_mask_fraction_of_BW_image(new_YELL_BW, fract_for_top_mask);

  /* 'bh_my_lane_preprocess_mask:7' tf_is_detected_BLUE = false; */
  tf_is_detected_BLUE = false;

  /* 'bh_my_lane_preprocess_mask:8' tf_is_detected_YELL = false; */
  tf_is_detected_YELL = false;

  /*  can we detect BLUE things */
  /* 'bh_my_lane_preprocess_mask:11' the_ind   = find(new_BLUE_BW); */
  idx = 0;
  mtmp = ii->size[0];
  ii->size[0] = 76800;
  emxEnsureCapacity_int32_T(ii, mtmp);
  b_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 76801)) {
    if (new_BLUE_BW[b_ii - 1]) {
      idx++;
      ii->data[idx - 1] = b_ii;
      if (idx >= 76800) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }

  emxInit_int32_T(&the_ind, 1);
  mtmp = ii->size[0];
  if (1 > idx) {
    ii->size[0] = 0;
  } else {
    ii->size[0] = idx;
  }

  emxEnsureCapacity_int32_T(ii, mtmp);
  mtmp = the_ind->size[0];
  the_ind->size[0] = ii->size[0];
  emxEnsureCapacity_int32_T(the_ind, mtmp);
  b_ii = ii->size[0];
  for (mtmp = 0; mtmp < b_ii; mtmp++) {
    the_ind->data[mtmp] = ii->data[mtmp];
  }

  /* 'bh_my_lane_preprocess_mask:12' if( ~isempty(the_ind) ) */
  if (!(the_ind->size[0] == 0)) {
    /* 'bh_my_lane_preprocess_mask:13' [B_y,~]   = ind2sub(size( new_BLUE_BW),the_ind); */
    mtmp = ii->size[0];
    ii->size[0] = the_ind->size[0];
    emxEnsureCapacity_int32_T(ii, mtmp);
    b_ii = the_ind->size[0];
    for (mtmp = 0; mtmp < b_ii; mtmp++) {
      ii->data[mtmp] = the_ind->data[mtmp] - 1;
    }

    mtmp = ii->size[0];
    emxEnsureCapacity_int32_T(ii, mtmp);
    b_ii = ii->size[0];
    for (mtmp = 0; mtmp < b_ii; mtmp++) {
      ii->data[mtmp] -= ii->data[mtmp] / 240 * 240;
    }

    mtmp = the_ind->size[0];
    the_ind->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(the_ind, mtmp);
    b_ii = ii->size[0];
    for (mtmp = 0; mtmp < b_ii; mtmp++) {
      the_ind->data[mtmp] = ii->data[mtmp] + 1;
    }

    /* 'bh_my_lane_preprocess_mask:13' ~ */
    /*  convert INDS to SUBSCRIPTS */
    /* 'bh_my_lane_preprocess_mask:14' B_y_range = max(B_y) - min(B_y); */
    idx = the_ind->size[0];
    mtmp = the_ind->data[0];
    if ((the_ind->size[0] > 1) && (1 < the_ind->size[0])) {
      for (b_ii = 1; b_ii + 1 <= idx; b_ii++) {
        if (the_ind->data[b_ii] > mtmp) {
          mtmp = the_ind->data[b_ii];
        }
      }
    }

    idx = the_ind->size[0];
    b_mtmp = the_ind->data[0];
    if ((the_ind->size[0] > 1) && (1 < the_ind->size[0])) {
      for (b_ii = 1; b_ii + 1 <= idx; b_ii++) {
        if (the_ind->data[b_ii] < b_mtmp) {
          b_mtmp = the_ind->data[b_ii];
        }
      }
    }

    /* 'bh_my_lane_preprocess_mask:16' if( (nnz(new_BLUE_BW) > 2) &  (B_y_range > 10)  ) */
    idx = 0;
    for (b_ii = 0; b_ii < 76800; b_ii++) {
      if (new_BLUE_BW[b_ii]) {
        idx++;
      }
    }

    if ((idx > 2) && ((double)mtmp - (double)b_mtmp > 10.0)) {
      /* 'bh_my_lane_preprocess_mask:17' tf_is_detected_BLUE = true; */
      tf_is_detected_BLUE = true;
    }
  }

  /*  can we detect YELLOW things */
  /* 'bh_my_lane_preprocess_mask:22' the_ind   = find(new_YELL_BW); */
  idx = 0;
  mtmp = ii->size[0];
  ii->size[0] = 76800;
  emxEnsureCapacity_int32_T(ii, mtmp);
  b_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 76801)) {
    if (new_YELL_BW[b_ii - 1]) {
      idx++;
      ii->data[idx - 1] = b_ii;
      if (idx >= 76800) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }

  mtmp = ii->size[0];
  if (1 > idx) {
    ii->size[0] = 0;
  } else {
    ii->size[0] = idx;
  }

  emxEnsureCapacity_int32_T(ii, mtmp);
  mtmp = the_ind->size[0];
  the_ind->size[0] = ii->size[0];
  emxEnsureCapacity_int32_T(the_ind, mtmp);
  b_ii = ii->size[0];
  for (mtmp = 0; mtmp < b_ii; mtmp++) {
    the_ind->data[mtmp] = ii->data[mtmp];
  }

  /* 'bh_my_lane_preprocess_mask:23' if( ~isempty(the_ind) ) */
  if (!(the_ind->size[0] == 0)) {
    /* 'bh_my_lane_preprocess_mask:24' [Y_y,~] = ind2sub(size( new_YELL_BW),the_ind); */
    mtmp = ii->size[0];
    ii->size[0] = the_ind->size[0];
    emxEnsureCapacity_int32_T(ii, mtmp);
    b_ii = the_ind->size[0];
    for (mtmp = 0; mtmp < b_ii; mtmp++) {
      ii->data[mtmp] = the_ind->data[mtmp] - 1;
    }

    mtmp = ii->size[0];
    emxEnsureCapacity_int32_T(ii, mtmp);
    b_ii = ii->size[0];
    for (mtmp = 0; mtmp < b_ii; mtmp++) {
      ii->data[mtmp] -= ii->data[mtmp] / 240 * 240;
    }

    mtmp = the_ind->size[0];
    the_ind->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(the_ind, mtmp);
    b_ii = ii->size[0];
    for (mtmp = 0; mtmp < b_ii; mtmp++) {
      the_ind->data[mtmp] = ii->data[mtmp] + 1;
    }

    /* 'bh_my_lane_preprocess_mask:24' ~ */
    /*  convert INDS to SUBSCRIPTS */
    /* 'bh_my_lane_preprocess_mask:25' Y_y_range = max(Y_y) - min(Y_y); */
    idx = the_ind->size[0];
    mtmp = the_ind->data[0];
    if ((the_ind->size[0] > 1) && (1 < the_ind->size[0])) {
      for (b_ii = 1; b_ii + 1 <= idx; b_ii++) {
        if (the_ind->data[b_ii] > mtmp) {
          mtmp = the_ind->data[b_ii];
        }
      }
    }

    idx = the_ind->size[0];
    b_mtmp = the_ind->data[0];
    if ((the_ind->size[0] > 1) && (1 < the_ind->size[0])) {
      for (b_ii = 1; b_ii + 1 <= idx; b_ii++) {
        if (the_ind->data[b_ii] < b_mtmp) {
          b_mtmp = the_ind->data[b_ii];
        }
      }
    }

    /* 'bh_my_lane_preprocess_mask:27' if( (nnz(new_YELL_BW) > 2) &  (Y_y_range > 10)  ) */
    idx = 0;
    for (b_ii = 0; b_ii < 76800; b_ii++) {
      if (new_YELL_BW[b_ii]) {
        idx++;
      }
    }

    if ((idx > 2) && ((double)mtmp - (double)b_mtmp > 10.0)) {
      /* 'bh_my_lane_preprocess_mask:28' tf_is_detected_YELL = true; */
      tf_is_detected_YELL = true;
    }
  }

  emxFree_int32_T(&ii);
  emxFree_int32_T(&the_ind);

  /*  create Lane info objects */
  /* 'bh_my_lane_preprocess_mask:33' BLUE_O     = lane_info_CLS(new_BLUE_BW, tf_is_detected_BLUE); */
  b_lane_info_CLS_lane_info_CLS(new_BLUE_BW, tf_is_detected_BLUE, &BLUE_O);

  /* 'bh_my_lane_preprocess_mask:34' YELL_O     = lane_info_CLS(new_YELL_BW, tf_is_detected_YELL); */
  b_lane_info_CLS_lane_info_CLS(new_YELL_BW, tf_is_detected_YELL, &YELL_O);

  /* 'bh_my_lane_preprocess_mask:36' ulim       = [1, BLUE_O.NUM_COLS]; */
  /* 'bh_my_lane_preprocess_mask:37' vlim       = [(mask_Rmax+1), BLUE_O.NUM_ROWS]; */
  vlim[0] = mask_Rmax + 1.0;
  vlim[1] = 240.0;

  /* 'bh_my_lane_preprocess_mask:39' BLUE_O     = BLUE_O.calc_info(ulim, vlim); */
  b_lane_info_CLS_calc_info(&BLUE_O, vlim);

  /* 'bh_my_lane_preprocess_mask:40' YELL_O     = YELL_O.calc_info(ulim, vlim); */
  b_lane_info_CLS_calc_info(&YELL_O, vlim);

  /*  take care of the outputs */
  /* 'bh_my_lane_preprocess_mask:43' BLUE_out_s = BLUE_O.convert_to_struct(); */
  b_lane_info_CLS_convert_to_stru(BLUE_O.BW, BLUE_O.tip_upper_xy_col,
    BLUE_O.tip_lower_xy_col, BLUE_O.m, BLUE_O.c, BLUE_O.tf_is_detected,
    BLUE_out_s->BW, &BLUE_out_s->NUM_ROWS, &BLUE_out_s->NUM_COLS,
    BLUE_out_s->tip_upper_xy_col, BLUE_out_s->tip_lower_xy_col, &BLUE_out_s->m,
    &BLUE_out_s->c, &BLUE_out_s->tf_is_detected);

  /* 'bh_my_lane_preprocess_mask:44' YELL_out_s = YELL_O.convert_to_struct(); */
  b_lane_info_CLS_convert_to_stru(YELL_O.BW, YELL_O.tip_upper_xy_col,
    YELL_O.tip_lower_xy_col, YELL_O.m, YELL_O.c, YELL_O.tf_is_detected,
    YELL_out_s->BW, &YELL_out_s->NUM_ROWS, &YELL_out_s->NUM_COLS,
    YELL_out_s->tip_upper_xy_col, YELL_out_s->tip_lower_xy_col, &YELL_out_s->m,
    &YELL_out_s->c, &YELL_out_s->tf_is_detected);

  /* -######################################################################### */
  /*  E N D    O F    M A I N    F U N C T I O N */
  /* -######################################################################### */
}

/*
 * File trailer for bh_my_lane_preprocess_mask.c
 *
 * [EOF]
 */
