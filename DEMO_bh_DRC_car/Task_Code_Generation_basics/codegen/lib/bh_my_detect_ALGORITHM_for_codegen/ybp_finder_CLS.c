/*
 * File: ybp_finder_CLS.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "ybp_finder_CLS.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "sort1.h"
#include "regionprops.h"
#include "power.h"
#include "XYZToLAB.h"
#include "linearizeSRGB.h"
#include "bh_my_detect_ALGORITHM_for_codegen_rtwutil.h"

/* Function Definitions */

/*
 * function [new_BW, tf_found_it] = LOC_find_thin_lane_marking(OBJ, BW)
 * Arguments    : const emxArray_boolean_T *BW
 *                emxArray_boolean_T *new_BW
 *                boolean_T *tf_found_it
 * Return Type  : void
 */
void LOC_find_thin_lane_marking(const emxArray_boolean_T *BW, emxArray_boolean_T
  *new_BW, boolean_T *tf_found_it)
{
  int i2;
  short iv2[2];
  int loop_ub;
  b_emxArray_struct_T *stats;
  emxArray_real_T *tmp_E;
  emxArray_int32_T *ii;
  emxArray_real_T *E;
  unsigned int b_stats[2];
  int c_stats[2];
  b_emxArray_struct_T *r2;
  emxArray_real_T *O;
  emxArray_boolean_T *x;
  double A_min;
  int nx;
  int idx;
  unsigned int unnamed_idx_1;
  boolean_T exitg1;
  emxArray_int32_T *r3;
  emxArray_int32_T *b_ii;
  emxArray_int32_T *r4;

  /* 'ybp_finder_CLS:224' new_BW      = false( size(BW) ); */
  for (i2 = 0; i2 < 2; i2++) {
    iv2[i2] = (short)BW->size[i2];
  }

  i2 = new_BW->size[0] * new_BW->size[1];
  new_BW->size[1] = 320;
  new_BW->size[0] = iv2[0];
  emxEnsureCapacity_boolean_T(new_BW, i2);
  loop_ub = 320 * iv2[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    new_BW->data[i2] = false;
  }

  emxInit_struct_T1(&stats, 1);

  /* 'ybp_finder_CLS:225' tf_found_it = false; */
  *tf_found_it = false;

  /* 'ybp_finder_CLS:228' stats = regionprops('struct', BW, 'Orientation','Eccentricity','Area','PixelIdxList' ); */
  regionprops(BW, stats);

  /* 'ybp_finder_CLS:229' if( isempty(stats) ) */
  if (stats->size[0] != 0) {
    emxInit_real_T(&tmp_E, 2);

    /* 'ybp_finder_CLS:238' tmp_E = zeros(1, length(stats)); */
    i2 = tmp_E->size[0] * tmp_E->size[1];
    tmp_E->size[1] = stats->size[0];
    tmp_E->size[0] = 1;
    emxEnsureCapacity_real_T(tmp_E, i2);
    loop_ub = stats->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      tmp_E->data[i2] = 0.0;
    }

    /* 'ybp_finder_CLS:239' for kk=1:length(stats) */
    for (loop_ub = 0; loop_ub < stats->size[0]; loop_ub++) {
      /* 'ybp_finder_CLS:240' tmp_E(kk) = stats(kk).Eccentricity; */
      tmp_E->data[loop_ub] = stats->data[loop_ub].Eccentricity;
    }

    emxInit_int32_T1(&ii, 2);

    /* 'ybp_finder_CLS:242' [~,ind] = sort( tmp_E, 'descend' ); */
    b_sort(tmp_E, ii);
    i2 = tmp_E->size[0] * tmp_E->size[1];
    tmp_E->size[1] = ii->size[1];
    tmp_E->size[0] = 1;
    emxEnsureCapacity_real_T(tmp_E, i2);
    loop_ub = ii->size[1] * ii->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      tmp_E->data[i2] = ii->data[i2];
    }

    emxInit_real_T(&E, 2);

    /* 'ybp_finder_CLS:242' ~ */
    /* 'ybp_finder_CLS:243' stats   = stats(ind,:); */
    i2 = E->size[0] * E->size[1];
    E->size[1] = ii->size[1];
    E->size[0] = 1;
    emxEnsureCapacity_real_T(E, i2);
    loop_ub = ii->size[1] * ii->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      E->data[i2] = (unsigned int)ii->data[i2];
    }

    b_stats[0] = (unsigned int)stats->size[0];
    b_stats[1] = 1U;
    for (i2 = 0; i2 < 2; i2++) {
      c_stats[i2] = (int)b_stats[1 - i2];
    }

    i2 = ii->size[0] * ii->size[1];
    ii->size[1] = tmp_E->size[1];
    ii->size[0] = 1;
    emxEnsureCapacity_int32_T1(ii, i2);
    loop_ub = tmp_E->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      ii->data[i2] = (int)tmp_E->data[i2];
    }

    emxInit_struct_T2(&r2, 2);
    loop_ub = tmp_E->size[1];
    i2 = r2->size[0] * r2->size[1];
    r2->size[1] = 1;
    r2->size[0] = loop_ub;
    emxEnsureCapacity_struct_T1(r2, i2);
    for (i2 = 0; i2 < loop_ub; i2++) {
      emxCopyStruct_struct_T1(&r2->data[r2->size[1] * i2], &stats->data[c_stats
        [0] * (ii->data[i2] - 1)]);
    }

    i2 = stats->size[0];
    stats->size[0] = E->size[1];
    emxEnsureCapacity_struct_T2(stats, i2);
    loop_ub = E->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      emxCopyStruct_struct_T1(&stats->data[i2], &r2->data[i2]);
    }

    /* 'ybp_finder_CLS:245' A = zeros(1, length(stats)); */
    i2 = tmp_E->size[0] * tmp_E->size[1];
    tmp_E->size[1] = r2->size[0];
    tmp_E->size[0] = 1;
    emxEnsureCapacity_real_T(tmp_E, i2);
    loop_ub = r2->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      tmp_E->data[i2] = 0.0;
    }

    /* 'ybp_finder_CLS:246' E = zeros(1, length(stats)); */
    i2 = E->size[0] * E->size[1];
    E->size[1] = r2->size[0];
    E->size[0] = 1;
    emxEnsureCapacity_real_T(E, i2);
    loop_ub = r2->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      E->data[i2] = 0.0;
    }

    emxInit_real_T(&O, 2);

    /* 'ybp_finder_CLS:247' O = zeros(1, length(stats)); */
    i2 = O->size[0] * O->size[1];
    O->size[1] = r2->size[0];
    O->size[0] = 1;
    emxEnsureCapacity_real_T(O, i2);
    loop_ub = r2->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      O->data[i2] = 0.0;
    }

    /* 'ybp_finder_CLS:248' for kk=1:length(stats) */
    for (loop_ub = 0; loop_ub < stats->size[0]; loop_ub++) {
      /* 'ybp_finder_CLS:249' A(kk) = stats(kk).Area; */
      tmp_E->data[loop_ub] = r2->data[loop_ub].Area;

      /* 'ybp_finder_CLS:250' E(kk) = stats(kk).Eccentricity; */
      E->data[loop_ub] = r2->data[loop_ub].Eccentricity;

      /* 'ybp_finder_CLS:251' O(kk) = stats(kk).Orientation; */
      O->data[loop_ub] = r2->data[loop_ub].Orientation;
    }

    emxFree_struct_T1(&r2);
    emxInit_boolean_T(&x, 2);

    /* 'ybp_finder_CLS:258' A_min = OBJ.A_tgt_for_lane * size(BW,1)/480; */
    A_min = 100.0 * (double)BW->size[0] / 480.0;

    /* 'ybp_finder_CLS:264' ind   = find(E > OBJ.E_tgt_for_lane  & ... */
    /* 'ybp_finder_CLS:265'                  A > A_min &  ... */
    /* 'ybp_finder_CLS:266'                  ((O > 10 & O < 80) | (O < -10 & O > -80)) ... */
    /* 'ybp_finder_CLS:267'                  ); */
    i2 = x->size[0] * x->size[1];
    x->size[1] = E->size[1];
    x->size[0] = 1;
    emxEnsureCapacity_boolean_T(x, i2);
    loop_ub = E->size[1] * E->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      x->data[i2] = ((E->data[i2] > 0.8) && (tmp_E->data[i2] > A_min) &&
                     (((O->data[i2] > 10.0) && (O->data[i2] < 80.0)) ||
                      ((O->data[i2] < -10.0) && (O->data[i2] > -80.0))));
    }

    emxFree_real_T(&O);
    emxFree_real_T(&E);
    nx = x->size[1];
    idx = 0;
    unnamed_idx_1 = (unsigned int)x->size[1];
    i2 = ii->size[0] * ii->size[1];
    ii->size[1] = (int)unnamed_idx_1;
    ii->size[0] = 1;
    emxEnsureCapacity_int32_T1(ii, i2);
    loop_ub = 1;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= nx)) {
      if (x->data[loop_ub - 1]) {
        idx++;
        ii->data[idx - 1] = loop_ub;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          loop_ub++;
        }
      } else {
        loop_ub++;
      }
    }

    emxInit_int32_T(&r3, 1);
    if (x->size[1] == 1) {
      if (idx == 0) {
        i2 = ii->size[0] * ii->size[1];
        ii->size[1] = 0;
        ii->size[0] = 1;
        emxEnsureCapacity_int32_T1(ii, i2);
      }
    } else {
      if (1 > idx) {
        loop_ub = 0;
      } else {
        loop_ub = idx;
      }

      i2 = r3->size[0];
      r3->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(r3, i2);
      for (i2 = 0; i2 < loop_ub; i2++) {
        r3->data[i2] = i2;
      }

      emxInit_int32_T1(&b_ii, 2);
      loop_ub = r3->size[0];
      i2 = b_ii->size[0] * b_ii->size[1];
      b_ii->size[1] = loop_ub;
      b_ii->size[0] = 1;
      emxEnsureCapacity_int32_T1(b_ii, i2);
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_ii->data[i2] = ii->data[r3->data[i2]];
      }

      i2 = ii->size[0] * ii->size[1];
      ii->size[1] = b_ii->size[1];
      ii->size[0] = 1;
      emxEnsureCapacity_int32_T1(ii, i2);
      loop_ub = b_ii->size[1];
      for (i2 = 0; i2 < loop_ub; i2++) {
        ii->data[i2] = b_ii->data[i2];
      }

      emxFree_int32_T(&b_ii);
    }

    emxFree_boolean_T(&x);
    i2 = tmp_E->size[0] * tmp_E->size[1];
    tmp_E->size[1] = ii->size[1];
    tmp_E->size[0] = 1;
    emxEnsureCapacity_real_T(tmp_E, i2);
    loop_ub = ii->size[1] * ii->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      tmp_E->data[i2] = ii->data[i2];
    }

    /* 'ybp_finder_CLS:269' if( ~isempty(ind) ) */
    if (!(tmp_E->size[1] == 0)) {
      /* 'ybp_finder_CLS:270' IND          = ind(1); */
      /* 'ybp_finder_CLS:271' PixelIdxList = stats(IND).PixelIdxList; */
      /* 'ybp_finder_CLS:272' new_BW(PixelIdxList) = true; */
      i2 = ii->size[0] * ii->size[1];
      ii->size[1] = tmp_E->size[1];
      ii->size[0] = 1;
      emxEnsureCapacity_int32_T1(ii, i2);
      loop_ub = tmp_E->size[1];
      for (i2 = 0; i2 < loop_ub; i2++) {
        ii->data[i2] = (int)tmp_E->data[i2];
      }

      i2 = r3->size[0];
      r3->size[0] = stats->data[ii->data[0] - 1].PixelIdxList->size[0];
      emxEnsureCapacity_int32_T(r3, i2);
      loop_ub = stats->data[ii->data[0] - 1].PixelIdxList->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        r3->data[i2] = (int)stats->data[ii->data[0] - 1].PixelIdxList->data[i2];
      }

      emxInit_int32_T(&r4, 1);
      i2 = r4->size[0];
      r4->size[0] = r3->size[0];
      emxEnsureCapacity_int32_T(r4, i2);
      loop_ub = r3->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        r4->data[i2] = r3->data[i2] - 1;
      }

      i2 = iv2[0];
      loop_ub = r3->size[0];
      for (nx = 0; nx < loop_ub; nx++) {
        new_BW->data[r4->data[nx] % i2 * 320 + r4->data[nx] / i2] = true;
      }

      emxFree_int32_T(&r4);

      /* 'ybp_finder_CLS:273' tf_found_it          = true; */
      *tf_found_it = true;
    }

    emxFree_int32_T(&r3);
    emxFree_int32_T(&ii);
    emxFree_real_T(&tmp_E);
  }

  emxFree_struct_T1(&stats);
}

/*
 * function OBJ = classify(OBJ, DRC_image)
 * Arguments    : ybp_finder_CLS *OBJ
 *                const unsigned char DRC_image[230400]
 * Return Type  : void
 */
void ybp_finder_CLS_classify(ybp_finder_CLS *OBJ, const unsigned char DRC_image
  [230400])
{
  int i10;
  unsigned char row_range_data[145];
  emxArray_uint8_T *rgb;
  unsigned char b_row_range_data[145];
  emxArray_real_T *lab_DRC_image;
  int row;
  int col;
  emxArray_real_T *r6;
  short b_lab_DRC_image[3];
  double R;
  short c_lab_DRC_image[3];
  emxArray_real_T *r7;
  double G;
  double B;
  double fy;
  emxArray_real_T *distance;
  int count;
  emxArray_real_T *ex;
  emxArray_real_T *a;
  emxArray_real_T *r8;
  unsigned int distance_idx_0;
  emxArray_int32_T *idx;
  short b_ex[2];
  int k;
  int b_k;
  short c_ex[2];
  short a_idx_0;
  boolean_T p;

  /* 'ybp_finder_CLS:58' nColors       = OBJ.nColors; */
  /* 'ybp_finder_CLS:59' color_labels  = OBJ.color_labels; */
  /* 'ybp_finder_CLS:60' color_markers = OBJ.color_markers; */
  /* 'ybp_finder_CLS:63' NUM_ROWS = size(DRC_image,1); */
  /* 'ybp_finder_CLS:64' NUM_COLS = size(DRC_image,2); */
  /* 'ybp_finder_CLS:67' rmin      = round(NUM_ROWS*OBJ.fraction_of_img_to_ignore); */
  /* 'ybp_finder_CLS:68' rmax      = NUM_ROWS; */
  /* 'ybp_finder_CLS:69' row_range = rmin:rmax; */
  for (i10 = 0; i10 < 145; i10++) {
    row_range_data[i10] = (unsigned char)(96U + i10);
  }

  /* 'ybp_finder_CLS:73' lab_DRC_image = rgb2lab( DRC_image(row_range,:,:) ); */
  for (i10 = 0; i10 < 145; i10++) {
    b_row_range_data[i10] = row_range_data[i10];
  }

  emxInit_uint8_T(&rgb, 3);
  i10 = rgb->size[0] * rgb->size[1] * rgb->size[2];
  rgb->size[2] = 3;
  rgb->size[1] = 320;
  rgb->size[0] = 145;
  emxEnsureCapacity_uint8_T(rgb, i10);
  for (i10 = 0; i10 < 145; i10++) {
    for (row = 0; row < 320; row++) {
      for (col = 0; col < 3; col++) {
        rgb->data[(col + rgb->size[2] * row) + rgb->size[2] * rgb->size[1] * i10]
          = DRC_image[(col + 3 * row) + 960 * (b_row_range_data[i10] - 1)];
      }
    }
  }

  emxInit_real_T2(&lab_DRC_image, 3);
  i10 = lab_DRC_image->size[0] * lab_DRC_image->size[1] * lab_DRC_image->size[2];
  lab_DRC_image->size[2] = 3;
  lab_DRC_image->size[1] = 320;
  lab_DRC_image->size[0] = 145;
  emxEnsureCapacity_real_T2(lab_DRC_image, i10);
  for (col = 0; col < 320; col++) {
    for (row = 0; row < 145; row++) {
      b_lab_DRC_image[0] = 145;
      b_lab_DRC_image[1] = 320;
      b_lab_DRC_image[2] = 3;
      for (i10 = 0; i10 < 3; i10++) {
        c_lab_DRC_image[i10] = b_lab_DRC_image[2 - i10];
      }

      R = parametricCurveA((double)rgb->data[c_lab_DRC_image[0] * col +
                           c_lab_DRC_image[0] * c_lab_DRC_image[1] * row] /
                           255.0);
      b_lab_DRC_image[0] = 145;
      b_lab_DRC_image[1] = 320;
      b_lab_DRC_image[2] = 3;
      for (i10 = 0; i10 < 3; i10++) {
        c_lab_DRC_image[i10] = b_lab_DRC_image[2 - i10];
      }

      G = parametricCurveA((double)rgb->data[(c_lab_DRC_image[0] * col +
        c_lab_DRC_image[0] * c_lab_DRC_image[1] * row) + 1] / 255.0);
      b_lab_DRC_image[0] = 145;
      b_lab_DRC_image[1] = 320;
      b_lab_DRC_image[2] = 3;
      for (i10 = 0; i10 < 3; i10++) {
        c_lab_DRC_image[i10] = b_lab_DRC_image[2 - i10];
      }

      B = parametricCurveA((double)rgb->data[(c_lab_DRC_image[0] * col +
        c_lab_DRC_image[0] * c_lab_DRC_image[1] * row) + 2] / 255.0);
      fy = f((0.2126728514056225 * R + 0.71515215528781784 * G) +
             0.072174993306559562 * B);
      b_lab_DRC_image[0] = (short)lab_DRC_image->size[0];
      b_lab_DRC_image[1] = 320;
      b_lab_DRC_image[2] = 3;
      for (i10 = 0; i10 < 3; i10++) {
        c_lab_DRC_image[i10] = b_lab_DRC_image[2 - i10];
      }

      lab_DRC_image->data[c_lab_DRC_image[0] * col + c_lab_DRC_image[0] *
        c_lab_DRC_image[1] * row] = 116.0 * fy - 16.0;
      b_lab_DRC_image[0] = (short)lab_DRC_image->size[0];
      b_lab_DRC_image[1] = 320;
      b_lab_DRC_image[2] = 3;
      for (i10 = 0; i10 < 3; i10++) {
        c_lab_DRC_image[i10] = b_lab_DRC_image[2 - i10];
      }

      lab_DRC_image->data[(c_lab_DRC_image[0] * col + c_lab_DRC_image[0] *
                           c_lab_DRC_image[1] * row) + 1] = 500.0 * (f
        (((0.41245643908969215 * R + 0.35757607764390892 * G) +
          0.18043748326639891 * B) / 0.95047) - fy);
      b_lab_DRC_image[0] = (short)lab_DRC_image->size[0];
      b_lab_DRC_image[1] = 320;
      b_lab_DRC_image[2] = 3;
      for (i10 = 0; i10 < 3; i10++) {
        c_lab_DRC_image[i10] = b_lab_DRC_image[2 - i10];
      }

      lab_DRC_image->data[(c_lab_DRC_image[0] * col + c_lab_DRC_image[0] *
                           c_lab_DRC_image[1] * row) + 2] = 200.0 * (fy - f
        (((0.0193338955823293 * R + 0.11919202588130294 * G) +
          0.95030407853636767 * B) / 1.08883));
    }
  }

  emxFree_uint8_T(&rgb);
  emxInit_real_T2(&r6, 3);

  /* 'ybp_finder_CLS:74' a             = double(lab_DRC_image(:,:,2)); */
  col = lab_DRC_image->size[0];
  i10 = r6->size[0] * r6->size[1] * r6->size[2];
  r6->size[2] = 1;
  r6->size[1] = 320;
  r6->size[0] = col;
  emxEnsureCapacity_real_T2(r6, i10);
  for (i10 = 0; i10 < col; i10++) {
    for (row = 0; row < 320; row++) {
      r6->data[r6->size[2] * row + r6->size[2] * r6->size[1] * i10] =
        lab_DRC_image->data[(lab_DRC_image->size[2] * row + lab_DRC_image->size
        [2] * lab_DRC_image->size[1] * i10) + 1];
    }
  }

  emxInit_real_T2(&r7, 3);

  /* 'ybp_finder_CLS:75' b             = double(lab_DRC_image(:,:,3)); */
  col = lab_DRC_image->size[0];
  i10 = r7->size[0] * r7->size[1] * r7->size[2];
  r7->size[2] = 1;
  r7->size[1] = 320;
  r7->size[0] = col;
  emxEnsureCapacity_real_T2(r7, i10);
  for (i10 = 0; i10 < col; i10++) {
    for (row = 0; row < 320; row++) {
      r7->data[r7->size[2] * row + r7->size[2] * r7->size[1] * i10] =
        lab_DRC_image->data[(lab_DRC_image->size[2] * row + lab_DRC_image->size
        [2] * lab_DRC_image->size[1] * i10) + 2];
    }
  }

  emxInit_real_T2(&distance, 3);

  /* 'ybp_finder_CLS:76' distance      = zeros([size(a,1), size(a,2), nColors]); */
  i10 = lab_DRC_image->size[0];
  R = OBJ->nColors;
  row = distance->size[0] * distance->size[1] * distance->size[2];
  distance->size[2] = (int)R;
  distance->size[1] = 320;
  distance->size[0] = i10;
  emxEnsureCapacity_real_T2(distance, row);
  col = (int)R * 320 * i10;
  for (i10 = 0; i10 < col; i10++) {
    distance->data[i10] = 0.0;
  }

  /* 'ybp_finder_CLS:78' for count = 1:nColors */
  count = 0;
  emxInit_real_T(&ex, 2);
  emxInit_real_T(&a, 2);
  emxInit_real_T(&r8, 2);
  while (count <= (int)OBJ->nColors - 1) {
    /* 'ybp_finder_CLS:79' distance(:,:,count) = ( (a - color_markers(count,1)).^2 + ... */
    /* 'ybp_finder_CLS:80'                               (b - color_markers(count,2)).^2 ).^0.5; */
    i10 = lab_DRC_image->size[0];
    row = r8->size[0] * r8->size[1];
    r8->size[1] = 320;
    r8->size[0] = i10;
    emxEnsureCapacity_real_T(r8, row);
    R = OBJ->color_markers[count << 1];
    col = 320 * i10;
    for (i10 = 0; i10 < col; i10++) {
      r8->data[i10] = r6->data[i10] - R;
    }

    power(r8, a);
    i10 = lab_DRC_image->size[0];
    row = r8->size[0] * r8->size[1];
    r8->size[1] = 320;
    r8->size[0] = i10;
    emxEnsureCapacity_real_T(r8, row);
    R = OBJ->color_markers[1 + (count << 1)];
    col = 320 * i10;
    for (i10 = 0; i10 < col; i10++) {
      r8->data[i10] = r7->data[i10] - R;
    }

    power(r8, ex);
    col = a->size[1] * a->size[0] - 1;
    i10 = a->size[0] * a->size[1];
    a->size[1] = 320;
    emxEnsureCapacity_real_T(a, i10);
    for (i10 = 0; i10 <= col; i10++) {
      a->data[i10] += ex->data[i10];
    }

    c_ex[0] = (short)a->size[0];
    c_ex[1] = 320;
    for (i10 = 0; i10 < 2; i10++) {
      b_ex[i10] = c_ex[i10];
    }

    a_idx_0 = (short)a->size[0];
    i10 = ex->size[0] * ex->size[1];
    ex->size[1] = 320;
    ex->size[0] = a_idx_0;
    emxEnsureCapacity_real_T(ex, i10);
    for (k = 1; k <= b_ex[0]; k++) {
      for (b_k = 0; b_k < 320; b_k++) {
        ex->data[b_k + ex->size[1] * (k - 1)] = rt_powd_snf(a->data[b_k +
          a->size[1] * (k - 1)], 0.5);
      }
    }

    col = ex->size[0];
    for (i10 = 0; i10 < col; i10++) {
      for (row = 0; row < 320; row++) {
        distance->data[(count + distance->size[2] * row) + distance->size[2] *
          distance->size[1] * i10] = ex->data[row + 320 * i10];
      }
    }

    count++;
  }

  emxFree_real_T(&r8);
  emxFree_real_T(&a);
  emxFree_real_T(&r7);
  emxFree_real_T(&r6);
  emxFree_real_T(&lab_DRC_image);

  /* 'ybp_finder_CLS:85' [~, ind] = min(distance,[],3); */
  distance_idx_0 = (unsigned int)distance->size[0];
  i10 = ex->size[0] * ex->size[1];
  ex->size[1] = 320;
  ex->size[0] = (int)distance_idx_0;
  emxEnsureCapacity_real_T(ex, i10);
  for (i10 = 0; i10 < 2; i10++) {
    b_ex[i10] = (short)ex->size[i10];
  }

  emxInit_int32_T1(&idx, 2);
  i10 = idx->size[0] * idx->size[1];
  idx->size[1] = 320;
  idx->size[0] = b_ex[0];
  emxEnsureCapacity_int32_T1(idx, i10);
  col = 320 * b_ex[0];
  for (i10 = 0; i10 < col; i10++) {
    idx->data[i10] = 1;
  }

  for (k = 1; k <= distance->size[0]; k++) {
    for (b_k = 0; b_k < 320; b_k++) {
      col = b_k + 1;
      b_ex[0] = (short)ex->size[0];
      b_ex[1] = 320;
      for (i10 = 0; i10 < 2; i10++) {
        c_ex[i10] = b_ex[1 - i10];
      }

      ex->data[b_k + c_ex[0] * (k - 1)] = distance->data[distance->size[2] * b_k
        + distance->size[2] * distance->size[1] * (k - 1)];
      if (2 <= distance->size[2]) {
        col = b_k + 1;
      }

      for (row = 2; row <= distance->size[2]; row++) {
        if (rtIsNaN(distance->data[((row + distance->size[2] * (col - 1)) +
              distance->size[2] * distance->size[1] * (k - 1)) - 1])) {
          p = false;
        } else {
          b_ex[0] = (short)ex->size[0];
          b_ex[1] = 320;
          for (i10 = 0; i10 < 2; i10++) {
            c_ex[i10] = b_ex[1 - i10];
          }

          if (rtIsNaN(ex->data[(col + c_ex[0] * (k - 1)) - 1])) {
            p = true;
          } else {
            b_ex[0] = (short)ex->size[0];
            b_ex[1] = 320;
            for (i10 = 0; i10 < 2; i10++) {
              c_ex[i10] = b_ex[1 - i10];
            }

            p = (ex->data[(col + c_ex[0] * (k - 1)) - 1] > distance->data[((row
                   + distance->size[2] * (col - 1)) + distance->size[2] *
                  distance->size[1] * (k - 1)) - 1]);
          }
        }

        if (p) {
          b_ex[0] = (short)ex->size[0];
          b_ex[1] = 320;
          for (i10 = 0; i10 < 2; i10++) {
            c_ex[i10] = b_ex[1 - i10];
          }

          ex->data[(col + c_ex[0] * (k - 1)) - 1] = distance->data[((row +
            distance->size[2] * (col - 1)) + distance->size[2] * distance->size
            [1] * (k - 1)) - 1];
          b_ex[0] = (short)idx->size[0];
          b_ex[1] = 320;
          for (i10 = 0; i10 < 2; i10++) {
            c_ex[i10] = b_ex[1 - i10];
          }

          idx->data[(col + c_ex[0] * (k - 1)) - 1] = row;
        }
      }
    }
  }

  emxFree_real_T(&distance);
  i10 = ex->size[0] * ex->size[1];
  ex->size[1] = 320;
  ex->size[0] = idx->size[0];
  emxEnsureCapacity_real_T(ex, i10);
  col = idx->size[1] * idx->size[0];
  for (i10 = 0; i10 < col; i10++) {
    ex->data[i10] = idx->data[i10];
  }

  emxFree_int32_T(&idx);

  /* 'ybp_finder_CLS:85' ~ */
  /* 'ybp_finder_CLS:89' label      = color_labels(ind); */
  /* 'ybp_finder_CLS:93' if(rmin>1) */
  /* 'ybp_finder_CLS:94' label      = [ 100*ones((rmin-1),NUM_COLS); */
  /* 'ybp_finder_CLS:95'                        label ]; */
  /* 'ybp_finder_CLS:99' OBJ.label         = label; */
  i10 = OBJ->label->size[0] * OBJ->label->size[1];
  OBJ->label->size[1] = 320;
  OBJ->label->size[0] = 95 + ex->size[0];
  emxEnsureCapacity_real_T(OBJ->label, i10);
  for (i10 = 0; i10 < 95; i10++) {
    for (row = 0; row < 320; row++) {
      OBJ->label->data[row + OBJ->label->size[1] * i10] = 100.0;
    }
  }

  col = ex->size[0];
  for (i10 = 0; i10 < col; i10++) {
    for (row = 0; row < 320; row++) {
      OBJ->label->data[row + OBJ->label->size[1] * (i10 + 95)] =
        OBJ->color_labels[(int)ex->data[row + ex->size[1] * i10] - 1];
    }
  }

  emxFree_real_T(&ex);
}

/*
 * function OBJ =  ybp_finder_CLS(marker_s, tf_do_plots)
 * Arguments    : double marker_s_nColors
 *                const double marker_s_color_labels[5]
 *                const double marker_s_color_markers[10]
 *                double *OBJ_E_tgt_for_lane
 *                double *OBJ_A_tgt_for_lane
 *                double *OBJ_fraction_of_img_to_ignore
 *                double *OBJ_nColors
 *                double OBJ_color_labels[5]
 *                double OBJ_color_markers[10]
 *                emxArray_real_T *OBJ_label
 * Return Type  : void
 */
void ybp_finder_CLS_ybp_finder_CLS(double marker_s_nColors, const double
  marker_s_color_labels[5], const double marker_s_color_markers[10], double
  *OBJ_E_tgt_for_lane, double *OBJ_A_tgt_for_lane, double
  *OBJ_fraction_of_img_to_ignore, double *OBJ_nColors, double OBJ_color_labels[5],
  double OBJ_color_markers[10], emxArray_real_T *OBJ_label)
{
  int i1;
  i1 = OBJ_label->size[0] * OBJ_label->size[1];
  OBJ_label->size[1] = 320;
  OBJ_label->size[0] = 0;
  emxEnsureCapacity_real_T(OBJ_label, i1);

  /* 'ybp_finder_CLS:46' if(1==nargin) */
  /* 'ybp_finder_CLS:47' tf_do_plots = false; */
  /* 'ybp_finder_CLS:50' OBJ.nColors       =  marker_s.nColors; */
  /* 'ybp_finder_CLS:51' OBJ.color_labels  =  marker_s.color_labels; */
  for (i1 = 0; i1 < 5; i1++) {
    OBJ_color_labels[i1] = marker_s_color_labels[i1];
  }

  /* 'ybp_finder_CLS:52' OBJ.color_markers =  marker_s.color_markers; */
  for (i1 = 0; i1 < 10; i1++) {
    OBJ_color_markers[i1] = marker_s_color_markers[i1];
  }

  *OBJ_E_tgt_for_lane = 0.8;
  *OBJ_A_tgt_for_lane = 100.0;
  *OBJ_fraction_of_img_to_ignore = 0.4;
  *OBJ_nColors = marker_s_nColors;
}

/*
 * File trailer for ybp_finder_CLS.c
 *
 * [EOF]
 */
