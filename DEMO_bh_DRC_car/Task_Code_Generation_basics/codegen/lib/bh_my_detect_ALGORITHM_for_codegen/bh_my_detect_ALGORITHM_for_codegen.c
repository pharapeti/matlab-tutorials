/*
 * File: bh_my_detect_ALGORITHM_for_codegen.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "box_info_CLS.h"
#include "lane_info_CLS.h"
#include "sort1.h"
#include "regionprops.h"
#include "ybp_finder_CLS.h"
#include "bh_mask_fraction_of_BW_image.h"
#include "bh_my_detect_ALGORITHM_for_codegen_rtwutil.h"

/* Variable Definitions */
static ybp_finder_CLS OBJ_ybp;
static boolean_T OBJ_ybp_not_empty;
static double fr_count;

/* Function Definitions */

/*
 * function [BLUE_s, YELL_s, PURP_s] = bh_my_detect_ALGORITHM_for_codegen(I, tf_do_init, marker_s)
 * ALLOWED USAGE:
 *   >> [BLUE_s, YELL_s, PURP_s] = bh_my_detect_ALGORITHM_for_codegen(I, tf_do_init, marker_s)
 * Arguments    : const unsigned char I[230400]
 *                boolean_T tf_do_init
 *                const struct0_T *marker_s
 *                struct1_T *BLUE_s
 *                struct1_T *YELL_s
 *                struct2_T *PURP_s
 * Return Type  : void
 */
void bh_my_detect_ALGORITHM_for_codegen(const unsigned char I[230400], boolean_T
  tf_do_init, const struct0_T *marker_s, struct1_T *BLUE_s, struct1_T *YELL_s,
  struct2_T *PURP_s)
{
  emxArray_boolean_T *BW_blue;
  int i;
  int loop_ub;
  emxArray_boolean_T *BW_yellow;
  emxArray_boolean_T *new_BW_blue;
  emxArray_boolean_T *new_BW_yell;
  boolean_T tf_found_b;
  boolean_T tf_found_y;
  int R_max;
  signed char tmp_data[96];
  short iv0[2];
  signed char b_tmp_data[96];
  int i0;
  emxArray_struct_T *stats;
  boolean_T tf_found_purp_blob;
  emxArray_real_T *A;
  emxArray_boolean_T *BLUE_O_BW;
  lane_info_CLS expl_temp;
  emxArray_int32_T *iidx;
  double BLUE_O_NUM_ROWS;
  emxArray_boolean_T *YELL_O_BW;
  double BLUE_O_tip_upper_xy_col[2];
  double BLUE_O_m;
  double BLUE_O_tip_lower_xy_col[2];
  double BLUE_O_c;
  boolean_T BLUE_O_tf_is_detected;
  emxArray_struct_T *b_stats;
  double YELL_O_NUM_ROWS;
  emxArray_boolean_T *PURP_O_BW;
  double YELL_O_tip_upper_xy_col[2];
  box_info_CLS b_expl_temp;
  double YELL_O_tip_lower_xy_col[2];
  double YELL_O_m;
  double YELL_O_c;
  emxArray_int32_T *r0;
  emxArray_int32_T *r1;
  double PURP_O_left_edge_xy_col[2];
  double PURP_O_right_edge_xy_col[2];
  double PURP_O_centroid_xy_col[2];

  /* 'bh_my_detect_ALGORITHM_for_codegen:10' if(isempty(fr_count)) */
  /*  ************************************************************************* */
  /*       do OBJECT INITIALIZATION */
  /*  ************************************************************************* */
  /* 'bh_my_detect_ALGORITHM_for_codegen:17' if(true==tf_do_init || isempty(OBJ_ybp) ) */
  if (tf_do_init || (!OBJ_ybp_not_empty)) {
    /* 'bh_my_detect_ALGORITHM_for_codegen:18' fr_count = 0; */
    fr_count = 0.0;

    /*  create an instance of the ybp finder */
    /* 'bh_my_detect_ALGORITHM_for_codegen:21' OBJ_ybp  = ybp_finder_CLS(marker_s); */
    ybp_finder_CLS_ybp_finder_CLS(marker_s->nColors, marker_s->color_labels,
      marker_s->color_markers, &OBJ_ybp.E_tgt_for_lane, &OBJ_ybp.A_tgt_for_lane,
      &OBJ_ybp.fraction_of_img_to_ignore, &OBJ_ybp.nColors, OBJ_ybp.color_labels,
      OBJ_ybp.color_markers, OBJ_ybp.label);
    OBJ_ybp_not_empty = true;
  }

  emxInit_boolean_T(&BW_blue, 2);

  /*  if(true==tf_do_init) */
  /*  update the frame counter */
  /* 'bh_my_detect_ALGORITHM_for_codegen:26' fr_count = fr_count + 1; */
  fr_count++;

  /*  ************************************************************************* */
  /*       CLASSIFY stuff */
  /*  ************************************************************************* */
  /* 'bh_my_detect_ALGORITHM_for_codegen:31' OBJ_ybp = OBJ_ybp.classify(I); */
  ybp_finder_CLS_classify(&OBJ_ybp, I);

  /* 'bh_my_detect_ALGORITHM_for_codegen:33' [ BLUE_s, YELL_s, PURP_s ] = OBJ_ybp.find_all_stuff(); */
  /* 'ybp_finder_CLS:193' [ BW_b,                ... */
  /* 'ybp_finder_CLS:194'      BW_y,                ... */
  /* 'ybp_finder_CLS:195'      tf_found_b,          ... */
  /* 'ybp_finder_CLS:196'      tf_found_y] = OBJ.find_thin_lane_markings(); */
  /* 'ybp_finder_CLS:133' if(isempty(varargin) ) */
  /* 'ybp_finder_CLS:134' tf_do_plots = false; */
  /* 'ybp_finder_CLS:140' BW_blue   = OBJ.label == 0; */
  /* 'ybp_finder_CLS:141' BW_yellow = OBJ.label == 1; */
  /* 'ybp_finder_CLS:144' THE_FRACT = OBJ.fraction_of_img_to_ignore; */
  /* 'ybp_finder_CLS:145' BW_blue   = bh_mask_fraction_of_BW_image(BW_blue,   THE_FRACT); */
  i = BW_blue->size[0] * BW_blue->size[1];
  BW_blue->size[1] = 320;
  BW_blue->size[0] = OBJ_ybp.label->size[0];
  emxEnsureCapacity_boolean_T(BW_blue, i);
  loop_ub = OBJ_ybp.label->size[1] * OBJ_ybp.label->size[0];
  for (i = 0; i < loop_ub; i++) {
    BW_blue->data[i] = (OBJ_ybp.label->data[i] == 0.0);
  }

  emxInit_boolean_T(&BW_yellow, 2);
  bh_mask_fraction_of_BW_image(BW_blue);

  /* 'ybp_finder_CLS:146' BW_yellow = bh_mask_fraction_of_BW_image(BW_yellow, THE_FRACT); */
  i = BW_yellow->size[0] * BW_yellow->size[1];
  BW_yellow->size[1] = 320;
  BW_yellow->size[0] = OBJ_ybp.label->size[0];
  emxEnsureCapacity_boolean_T(BW_yellow, i);
  loop_ub = OBJ_ybp.label->size[1] * OBJ_ybp.label->size[0];
  for (i = 0; i < loop_ub; i++) {
    BW_yellow->data[i] = (OBJ_ybp.label->data[i] == 1.0);
  }

  emxInit_boolean_T(&new_BW_blue, 2);
  emxInit_boolean_T(&new_BW_yell, 2);
  bh_mask_fraction_of_BW_image(BW_yellow);

  /* 'ybp_finder_CLS:149' [new_BW_blue, tf_found_blue_lane] = LOC_find_thin_lane_marking(OBJ, BW_blue); */
  LOC_find_thin_lane_marking(BW_blue, new_BW_blue, &tf_found_b);

  /* 'ybp_finder_CLS:150' [new_BW_yell, tf_found_yell_lane] = LOC_find_thin_lane_marking(OBJ, BW_yellow); */
  LOC_find_thin_lane_marking(BW_yellow, new_BW_yell, &tf_found_y);

  /* 'ybp_finder_CLS:152' if(1 ==coder.target('MATLAB') ) */
  /* 'ybp_finder_CLS:198' [ BW_p, tf_found_p] = OBJ.find_purp_boxes(); */
  /* 'ybp_finder_CLS:166' if(isempty(varargin) ) */
  /* 'ybp_finder_CLS:167' tf_do_plots = false; */
  /* 'ybp_finder_CLS:172' BW_purple   = OBJ.label == 2; */
  i = BW_blue->size[0] * BW_blue->size[1];
  BW_blue->size[1] = 320;
  BW_blue->size[0] = OBJ_ybp.label->size[0];
  emxEnsureCapacity_boolean_T(BW_blue, i);
  loop_ub = OBJ_ybp.label->size[1] * OBJ_ybp.label->size[0];
  for (i = 0; i < loop_ub; i++) {
    BW_blue->data[i] = (OBJ_ybp.label->data[i] == 2.0);
  }

  /* 'ybp_finder_CLS:175' THE_FRACT = OBJ.fraction_of_img_to_ignore; */
  /* 'ybp_finder_CLS:176' BW_purple = bh_mask_fraction_of_BW_image(BW_purple, THE_FRACT); */
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
  R_max = (int)rt_roundd_snf((double)BW_blue->size[0] * 0.4);

  /* 'bh_mask_fraction_of_BW_image:43' if(R_max == NUM_ROWS) */
  if ((R_max != BW_blue->size[0]) && (R_max > 1)) {
    /* 'bh_mask_fraction_of_BW_image:45' else */
    /* 'bh_mask_fraction_of_BW_image:46' if(R_max > 1) */
    /* 'bh_mask_fraction_of_BW_image:47' I(1:R_max, :)    = 0; */
    loop_ub = (signed char)R_max - 1;
    for (i = 0; i <= loop_ub; i++) {
      tmp_data[i] = (signed char)i;
    }

    loop_ub = (signed char)R_max;
    for (i = 0; i < loop_ub; i++) {
      b_tmp_data[i] = tmp_data[i];
    }

    for (i = 0; i < R_max; i++) {
      for (i0 = 0; i0 < 320; i0++) {
        BW_blue->data[i0 + BW_blue->size[1] * b_tmp_data[i]] = false;
      }
    }

    /* 'bh_mask_fraction_of_BW_image:48' tf_was_applied   = true; */
    /* 'bh_mask_fraction_of_BW_image:49' masked_row_range = 1:R_max; */
  } else {
    /*  do nothing */
  }

  /*  bh_ignore_fraction_of_BW_image(I_BW, frac) */
  /* 'ybp_finder_CLS:179' [new_BW_purp, tf_found_purp_blob] = LOC_find_purp_boxes(OBJ, BW_purple); */
  /* 'ybp_finder_CLS:279' new_BW      = false( size(BW) ); */
  for (i = 0; i < 2; i++) {
    iv0[i] = (short)BW_blue->size[i];
  }

  i = BW_yellow->size[0] * BW_yellow->size[1];
  BW_yellow->size[1] = 320;
  BW_yellow->size[0] = iv0[0];
  emxEnsureCapacity_boolean_T(BW_yellow, i);
  loop_ub = 320 * iv0[0];
  for (i = 0; i < loop_ub; i++) {
    BW_yellow->data[i] = false;
  }

  emxInit_struct_T(&stats, 1);

  /* 'ybp_finder_CLS:280' tf_found_it = false; */
  tf_found_purp_blob = false;

  /* 'ybp_finder_CLS:282' stats = regionprops( BW, 'Area','Eccentricity','PixelIdxList' ); */
  b_regionprops(BW_blue, stats);

  /* 'ybp_finder_CLS:284' if( isempty(stats) ) */
  emxFree_boolean_T(&BW_blue);
  if (stats->size[0] != 0) {
    emxInit_real_T(&A, 2);

    /* 'ybp_finder_CLS:291' A = zeros(1, length(stats)); */
    i = A->size[0] * A->size[1];
    A->size[1] = stats->size[0];
    A->size[0] = 1;
    emxEnsureCapacity_real_T(A, i);
    loop_ub = stats->size[0];
    for (i = 0; i < loop_ub; i++) {
      A->data[i] = 0.0;
    }

    /* 'ybp_finder_CLS:292' for kk=1:length(stats) */
    for (i = 0; i < stats->size[0]; i++) {
      /* 'ybp_finder_CLS:293' A(kk) = stats(kk).Area; */
      A->data[i] = stats->data[i].Area;
    }

    emxInit_int32_T1(&iidx, 2);

    /* 'ybp_finder_CLS:296' [~,ind] = sort(A,'descend'); */
    b_sort(A, iidx);
    i = A->size[0] * A->size[1];
    A->size[1] = iidx->size[1];
    A->size[0] = 1;
    emxEnsureCapacity_real_T(A, i);
    loop_ub = iidx->size[1] * iidx->size[0];
    for (i = 0; i < loop_ub; i++) {
      A->data[i] = iidx->data[i];
    }

    emxFree_int32_T(&iidx);
    emxInit_struct_T(&b_stats, 1);

    /* 'ybp_finder_CLS:296' ~ */
    /* 'ybp_finder_CLS:298' stats = stats(ind); */
    loop_ub = A->size[1];
    i = b_stats->size[0];
    b_stats->size[0] = loop_ub;
    emxEnsureCapacity_struct_T(b_stats, i);
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_struct_T(&b_stats->data[i], &stats->data[(int)A->data[i] - 1]);
    }

    emxFree_real_T(&A);
    i = stats->size[0];
    stats->size[0] = b_stats->size[0];
    emxEnsureCapacity_struct_T(stats, i);
    loop_ub = b_stats->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_struct_T(&stats->data[i], &b_stats->data[i]);
    }

    emxFree_struct_T(&b_stats);
    emxInit_int32_T(&r0, 1);

    /* 'ybp_finder_CLS:301' IND = 1; */
    /* 'ybp_finder_CLS:302' PixelIdxList = stats(IND).PixelIdxList; */
    /* 'ybp_finder_CLS:303' new_BW(PixelIdxList) = true; */
    i = r0->size[0];
    r0->size[0] = stats->data[0].PixelIdxList->size[0];
    emxEnsureCapacity_int32_T(r0, i);
    loop_ub = stats->data[0].PixelIdxList->size[0];
    for (i = 0; i < loop_ub; i++) {
      r0->data[i] = (int)stats->data[0].PixelIdxList->data[i];
    }

    emxInit_int32_T(&r1, 1);
    i = r1->size[0];
    r1->size[0] = r0->size[0];
    emxEnsureCapacity_int32_T(r1, i);
    loop_ub = r0->size[0];
    for (i = 0; i < loop_ub; i++) {
      r1->data[i] = r0->data[i] - 1;
    }

    i = iv0[0];
    loop_ub = r0->size[0];
    emxFree_int32_T(&r0);
    for (i0 = 0; i0 < loop_ub; i0++) {
      BW_yellow->data[r1->data[i0] % i * 320 + r1->data[i0] / i] = true;
    }

    emxFree_int32_T(&r1);

    /* 'ybp_finder_CLS:304' tf_found_it          = true; */
    tf_found_purp_blob = true;
  }

  emxFree_struct_T(&stats);
  emxInit_boolean_T(&BLUE_O_BW, 2);
  emxInitStruct_lane_info_CLS(&expl_temp);

  /* 'ybp_finder_CLS:181' if(1 ==coder.target('MATLAB') ) */
  /* 'ybp_finder_CLS:201' if(1 ==coder.target('MATLAB') ) */
  /* 'ybp_finder_CLS:206' BLUE_O = lane_info_CLS(BW_b, tf_found_b); */
  lane_info_CLS_lane_info_CLS(new_BW_blue, tf_found_b, &expl_temp);
  i = BLUE_O_BW->size[0] * BLUE_O_BW->size[1];
  BLUE_O_BW->size[1] = 320;
  BLUE_O_BW->size[0] = expl_temp.BW->size[0];
  emxEnsureCapacity_boolean_T(BLUE_O_BW, i);
  loop_ub = expl_temp.BW->size[1] * expl_temp.BW->size[0];
  emxFree_boolean_T(&new_BW_blue);
  for (i = 0; i < loop_ub; i++) {
    BLUE_O_BW->data[i] = expl_temp.BW->data[i];
  }

  BLUE_O_NUM_ROWS = expl_temp.NUM_ROWS;
  for (i = 0; i < 2; i++) {
    BLUE_O_tip_upper_xy_col[i] = expl_temp.tip_upper_xy_col[i];
    BLUE_O_tip_lower_xy_col[i] = expl_temp.tip_lower_xy_col[i];
  }

  emxInit_boolean_T(&YELL_O_BW, 2);
  BLUE_O_m = expl_temp.m;
  BLUE_O_c = expl_temp.c;
  BLUE_O_tf_is_detected = expl_temp.tf_is_detected;

  /* 'ybp_finder_CLS:207' YELL_O = lane_info_CLS(BW_y, tf_found_y); */
  lane_info_CLS_lane_info_CLS(new_BW_yell, tf_found_y, &expl_temp);
  i = YELL_O_BW->size[0] * YELL_O_BW->size[1];
  YELL_O_BW->size[1] = 320;
  YELL_O_BW->size[0] = expl_temp.BW->size[0];
  emxEnsureCapacity_boolean_T(YELL_O_BW, i);
  loop_ub = expl_temp.BW->size[1] * expl_temp.BW->size[0];
  emxFree_boolean_T(&new_BW_yell);
  for (i = 0; i < loop_ub; i++) {
    YELL_O_BW->data[i] = expl_temp.BW->data[i];
  }

  YELL_O_NUM_ROWS = expl_temp.NUM_ROWS;
  for (i = 0; i < 2; i++) {
    YELL_O_tip_upper_xy_col[i] = expl_temp.tip_upper_xy_col[i];
    YELL_O_tip_lower_xy_col[i] = expl_temp.tip_lower_xy_col[i];
  }

  emxInit_boolean_T(&PURP_O_BW, 2);
  emxInitStruct_box_info_CLS(&b_expl_temp);
  YELL_O_m = expl_temp.m;
  YELL_O_c = expl_temp.c;
  tf_found_b = expl_temp.tf_is_detected;

  /* 'ybp_finder_CLS:208' PURP_O = box_info_CLS( BW_p, tf_found_p); */
  box_info_CLS_box_info_CLS(BW_yellow, tf_found_purp_blob, &b_expl_temp);
  i = PURP_O_BW->size[0] * PURP_O_BW->size[1];
  PURP_O_BW->size[1] = 320;
  PURP_O_BW->size[0] = b_expl_temp.BW->size[0];
  emxEnsureCapacity_boolean_T(PURP_O_BW, i);
  loop_ub = b_expl_temp.BW->size[1] * b_expl_temp.BW->size[0];
  emxFreeStruct_lane_info_CLS(&expl_temp);
  emxFree_boolean_T(&BW_yellow);
  for (i = 0; i < loop_ub; i++) {
    PURP_O_BW->data[i] = b_expl_temp.BW->data[i];
  }

  for (i = 0; i < 2; i++) {
    PURP_O_left_edge_xy_col[i] = b_expl_temp.left_edge_xy_col[i];
    PURP_O_right_edge_xy_col[i] = b_expl_temp.right_edge_xy_col[i];
    PURP_O_centroid_xy_col[i] = b_expl_temp.centroid_xy_col[i];
  }

  /* 'ybp_finder_CLS:210' BLUE_s   = BLUE_O.convert_to_struct(); */
  lane_info_CLS_convert_to_struct(BLUE_O_BW, BLUE_O_NUM_ROWS,
    BLUE_O_tip_upper_xy_col, BLUE_O_tip_lower_xy_col, BLUE_O_m, BLUE_O_c,
    BLUE_O_tf_is_detected, BLUE_s->BW, &BLUE_s->NUM_ROWS, &BLUE_s->NUM_COLS,
    BLUE_s->tip_upper_xy_col, BLUE_s->tip_lower_xy_col, &BLUE_s->m, &BLUE_s->c,
    &BLUE_s->tf_is_detected);

  /* 'ybp_finder_CLS:211' YELLOW_s = YELL_O.convert_to_struct(); */
  lane_info_CLS_convert_to_struct(YELL_O_BW, YELL_O_NUM_ROWS,
    YELL_O_tip_upper_xy_col, YELL_O_tip_lower_xy_col, YELL_O_m, YELL_O_c,
    tf_found_b, YELL_s->BW, &YELL_s->NUM_ROWS, &YELL_s->NUM_COLS,
    YELL_s->tip_upper_xy_col, YELL_s->tip_lower_xy_col, &YELL_s->m, &YELL_s->c,
    &YELL_s->tf_is_detected);

  /* 'ybp_finder_CLS:212' PURP_s   = PURP_O.convert_to_struct(); */
  box_info_CLS_convert_to_struct(PURP_O_BW, b_expl_temp.NUM_ROWS,
    PURP_O_left_edge_xy_col, PURP_O_right_edge_xy_col, PURP_O_centroid_xy_col,
    b_expl_temp.tf_is_detected, PURP_s->BW, &PURP_s->NUM_ROWS, &PURP_s->NUM_COLS,
    PURP_s->left_edge_xy_col, PURP_s->right_edge_xy_col, PURP_s->centroid_xy_col,
    &PURP_s->tf_is_detected);

  /*  bh_roipoly() */
  /* -------------------------------------------------------------------------- */
  /*  ************************************************************************* */
  /*       VISUALIZE  stuff */
  /*  ************************************************************************* */
  /* 'bh_my_detect_ALGORITHM_for_codegen:39' if(1 ==coder.target('MATLAB') ) */
  /*  bh_my_ALGORITHM_for_codegen(I) */
  /* -######################################################################### */
  /*  E N D    O F    M A I N    F U N C T I O N */
  /* -######################################################################### */
  emxFreeStruct_box_info_CLS(&b_expl_temp);
  emxFree_boolean_T(&PURP_O_BW);
  emxFree_boolean_T(&YELL_O_BW);
  emxFree_boolean_T(&BLUE_O_BW);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void c_bh_my_detect_ALGORITHM_for_co(void)
{
  emxInitStruct_ybp_finder_CLS(&OBJ_ybp);
  OBJ_ybp_not_empty = false;

  /* 'bh_my_detect_ALGORITHM_for_codegen:11' fr_count = 0; */
  fr_count = 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void d_bh_my_detect_ALGORITHM_for_co(void)
{
  emxFreeStruct_ybp_finder_CLS(&OBJ_ybp);
}

/*
 * File trailer for bh_my_detect_ALGORITHM_for_codegen.c
 *
 * [EOF]
 */
