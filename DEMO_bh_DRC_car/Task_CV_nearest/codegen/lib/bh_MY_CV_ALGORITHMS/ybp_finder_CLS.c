/*
 * File: ybp_finder_CLS.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "ybp_finder_CLS.h"
#include "bh_MY_CV_ALGORITHMS_emxutil.h"
#include "sort1.h"
#include "regionprops.h"
#include "power.h"
#include "XYZToLAB.h"
#include "linearizeSRGB.h"

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
  int i3;
  short iv1[2];
  int loop_ub;
  b_emxArray_struct_T *stats;
  boolean_T b_tf_found_it;
  emxArray_real_T *tmp_E;
  emxArray_int32_T *ii;
  b_emxArray_struct_T *b_stats;
  emxArray_real_T *E;
  emxArray_real_T *O;
  emxArray_boolean_T *x;
  double A_min;
  int nx;
  int idx;
  boolean_T exitg1;
  emxArray_int32_T *r1;

  /* 'ybp_finder_CLS:224' new_BW      = false( size(BW) ); */
  for (i3 = 0; i3 < 2; i3++) {
    iv1[i3] = (short)BW->size[i3];
  }

  i3 = new_BW->size[0] * new_BW->size[1];
  new_BW->size[0] = iv1[0];
  new_BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(new_BW, i3);
  loop_ub = iv1[0] * 320;
  for (i3 = 0; i3 < loop_ub; i3++) {
    new_BW->data[i3] = false;
  }

  emxInit_struct_T1(&stats, 1);

  /* 'ybp_finder_CLS:225' tf_found_it = false; */
  b_tf_found_it = false;

  /* 'ybp_finder_CLS:228' stats = regionprops('struct', BW, 'Orientation','Eccentricity','Area','PixelIdxList' ); */
  regionprops(BW, stats);

  /* 'ybp_finder_CLS:229' if( isempty(stats) ) */
  if (stats->size[0] != 0) {
    emxInit_real_T(&tmp_E, 2);

    /* 'ybp_finder_CLS:238' tmp_E = zeros(1, length(stats)); */
    i3 = tmp_E->size[0] * tmp_E->size[1];
    tmp_E->size[0] = 1;
    tmp_E->size[1] = stats->size[0];
    emxEnsureCapacity_real_T(tmp_E, i3);
    loop_ub = stats->size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      tmp_E->data[i3] = 0.0;
    }

    /* 'ybp_finder_CLS:239' for kk=1:length(stats) */
    for (loop_ub = 0; loop_ub < stats->size[0]; loop_ub++) {
      /* 'ybp_finder_CLS:240' tmp_E(kk) = stats(kk).Eccentricity; */
      tmp_E->data[loop_ub] = stats->data[loop_ub].Eccentricity;
    }

    emxInit_int32_T1(&ii, 2);
    emxInit_struct_T1(&b_stats, 1);

    /* 'ybp_finder_CLS:242' [~,ind] = sort( tmp_E, 'descend' ); */
    sort(tmp_E, ii);

    /* 'ybp_finder_CLS:242' ~ */
    /* 'ybp_finder_CLS:243' stats   = stats(ind,:); */
    i3 = b_stats->size[0];
    b_stats->size[0] = ii->size[1];
    emxEnsureCapacity_struct_T1(b_stats, i3);
    loop_ub = ii->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      emxCopyStruct_struct_T1(&b_stats->data[i3], &stats->data[ii->data[ii->
        size[0] * i3] - 1]);
    }

    i3 = stats->size[0];
    stats->size[0] = b_stats->size[0];
    emxEnsureCapacity_struct_T1(stats, i3);
    loop_ub = b_stats->size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      emxCopyStruct_struct_T1(&stats->data[i3], &b_stats->data[i3]);
    }

    emxFree_struct_T1(&b_stats);

    /* 'ybp_finder_CLS:245' A = zeros(1, length(stats)); */
    i3 = tmp_E->size[0] * tmp_E->size[1];
    tmp_E->size[0] = 1;
    tmp_E->size[1] = stats->size[0];
    emxEnsureCapacity_real_T(tmp_E, i3);
    loop_ub = stats->size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      tmp_E->data[i3] = 0.0;
    }

    emxInit_real_T(&E, 2);

    /* 'ybp_finder_CLS:246' E = zeros(1, length(stats)); */
    i3 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = stats->size[0];
    emxEnsureCapacity_real_T(E, i3);
    loop_ub = stats->size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      E->data[i3] = 0.0;
    }

    emxInit_real_T(&O, 2);

    /* 'ybp_finder_CLS:247' O = zeros(1, length(stats)); */
    i3 = O->size[0] * O->size[1];
    O->size[0] = 1;
    O->size[1] = stats->size[0];
    emxEnsureCapacity_real_T(O, i3);
    loop_ub = stats->size[0];
    for (i3 = 0; i3 < loop_ub; i3++) {
      O->data[i3] = 0.0;
    }

    /* 'ybp_finder_CLS:248' for kk=1:length(stats) */
    for (loop_ub = 0; loop_ub < stats->size[0]; loop_ub++) {
      /* 'ybp_finder_CLS:249' A(kk) = stats(kk).Area; */
      tmp_E->data[loop_ub] = stats->data[loop_ub].Area;

      /* 'ybp_finder_CLS:250' E(kk) = stats(kk).Eccentricity; */
      E->data[loop_ub] = stats->data[loop_ub].Eccentricity;

      /* 'ybp_finder_CLS:251' O(kk) = stats(kk).Orientation; */
      O->data[loop_ub] = stats->data[loop_ub].Orientation;
    }

    emxInit_boolean_T(&x, 2);

    /* 'ybp_finder_CLS:258' A_min = OBJ.A_tgt_for_lane * size(BW,1)/480; */
    A_min = 100.0 * (double)BW->size[0] / 480.0;

    /* 'ybp_finder_CLS:264' ind   = find(E > OBJ.E_tgt_for_lane  & ... */
    /* 'ybp_finder_CLS:265'                  A > A_min &  ... */
    /* 'ybp_finder_CLS:266'                  ((O > 10 & O < 80) | (O < -10 & O > -80)) ... */
    /* 'ybp_finder_CLS:267'                  ); */
    i3 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = E->size[1];
    emxEnsureCapacity_boolean_T(x, i3);
    loop_ub = E->size[0] * E->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      x->data[i3] = ((E->data[i3] > 0.8) && (tmp_E->data[i3] > A_min) &&
                     (((O->data[i3] > 10.0) && (O->data[i3] < 80.0)) ||
                      ((O->data[i3] < -10.0) && (O->data[i3] > -80.0))));
    }

    emxFree_real_T(&O);
    emxFree_real_T(&E);
    nx = x->size[1];
    idx = 0;
    i3 = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = x->size[1];
    emxEnsureCapacity_int32_T1(ii, i3);
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

    if (x->size[1] == 1) {
      if (idx == 0) {
        i3 = ii->size[0] * ii->size[1];
        ii->size[0] = 1;
        ii->size[1] = 0;
        emxEnsureCapacity_int32_T1(ii, i3);
      }
    } else {
      i3 = ii->size[0] * ii->size[1];
      if (1 > idx) {
        ii->size[1] = 0;
      } else {
        ii->size[1] = idx;
      }

      emxEnsureCapacity_int32_T1(ii, i3);
    }

    emxFree_boolean_T(&x);
    i3 = tmp_E->size[0] * tmp_E->size[1];
    tmp_E->size[0] = 1;
    tmp_E->size[1] = ii->size[1];
    emxEnsureCapacity_real_T(tmp_E, i3);
    loop_ub = ii->size[0] * ii->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      tmp_E->data[i3] = ii->data[i3];
    }

    /* 'ybp_finder_CLS:269' if( ~isempty(ind) ) */
    if (!(tmp_E->size[1] == 0)) {
      /* 'ybp_finder_CLS:270' IND          = ind(1); */
      /* 'ybp_finder_CLS:271' PixelIdxList = stats(IND).PixelIdxList; */
      /* 'ybp_finder_CLS:272' new_BW(PixelIdxList) = true; */
      i3 = ii->size[0] * ii->size[1];
      ii->size[0] = 1;
      ii->size[1] = tmp_E->size[1];
      emxEnsureCapacity_int32_T1(ii, i3);
      loop_ub = tmp_E->size[1];
      for (i3 = 0; i3 < loop_ub; i3++) {
        ii->data[ii->size[0] * i3] = (int)tmp_E->data[tmp_E->size[0] * i3];
      }

      emxInit_int32_T(&r1, 1);
      i3 = r1->size[0];
      r1->size[0] = stats->data[ii->data[0] - 1].PixelIdxList->size[0];
      emxEnsureCapacity_int32_T(r1, i3);
      loop_ub = stats->data[ii->data[0] - 1].PixelIdxList->size[0];
      for (i3 = 0; i3 < loop_ub; i3++) {
        r1->data[i3] = (int)stats->data[ii->data[0] - 1].PixelIdxList->data[i3];
      }

      loop_ub = r1->size[0];
      for (i3 = 0; i3 < loop_ub; i3++) {
        new_BW->data[r1->data[i3] - 1] = true;
      }

      emxFree_int32_T(&r1);

      /* 'ybp_finder_CLS:273' tf_found_it          = true; */
      b_tf_found_it = true;
    }

    emxFree_int32_T(&ii);
    emxFree_real_T(&tmp_E);
  }

  emxFree_struct_T1(&stats);
  *tf_found_it = b_tf_found_it;
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
  emxArray_uint8_T *rgb;
  int ixstart;
  emxArray_real_T *lab_DRC_image;
  int ixstop;
  int nx;
  int k;
  emxArray_real_T *a;
  double R;
  double G;
  double B;
  double fy;
  emxArray_real_T *b;
  emxArray_real_T *distance;
  int cindx;
  emxArray_real_T *indx;
  emxArray_real_T *b_a;
  emxArray_real_T *b_b;
  emxArray_int32_T *iindx;
  int n;
  int vstride;
  int ix;
  boolean_T exitg1;
  short a_idx_0;
  emxInit_uint8_T(&rgb, 3);

  /* 'ybp_finder_CLS:58' nColors       = OBJ.nColors; */
  /* 'ybp_finder_CLS:59' color_labels  = OBJ.color_labels; */
  /* 'ybp_finder_CLS:60' color_markers = OBJ.color_markers; */
  /* 'ybp_finder_CLS:63' NUM_ROWS = size(DRC_image,1); */
  /* 'ybp_finder_CLS:64' NUM_COLS = size(DRC_image,2); */
  /* 'ybp_finder_CLS:67' rmin      = round(NUM_ROWS*OBJ.fraction_of_img_to_ignore); */
  /* 'ybp_finder_CLS:68' rmax      = NUM_ROWS; */
  /* 'ybp_finder_CLS:69' row_range = rmin:rmax; */
  /* 'ybp_finder_CLS:73' lab_DRC_image = rgb2lab( DRC_image(row_range,:,:) ); */
  ixstart = rgb->size[0] * rgb->size[1] * rgb->size[2];
  rgb->size[0] = 145;
  rgb->size[1] = 320;
  rgb->size[2] = 3;
  emxEnsureCapacity_uint8_T(rgb, ixstart);
  for (ixstart = 0; ixstart < 3; ixstart++) {
    for (ixstop = 0; ixstop < 320; ixstop++) {
      for (nx = 0; nx < 145; nx++) {
        rgb->data[(nx + rgb->size[0] * ixstop) + rgb->size[0] * rgb->size[1] *
          ixstart] = DRC_image[((nx + 240 * ixstop) + 76800 * ixstart) + 95];
      }
    }
  }

  emxInit_real_T2(&lab_DRC_image, 3);
  ixstart = lab_DRC_image->size[0] * lab_DRC_image->size[1] *
    lab_DRC_image->size[2];
  lab_DRC_image->size[0] = 145;
  lab_DRC_image->size[1] = 320;
  lab_DRC_image->size[2] = 3;
  emxEnsureCapacity_real_T2(lab_DRC_image, ixstart);
  for (nx = 0; nx < 320; nx++) {
    for (k = 0; k < 145; k++) {
      R = parametricCurveA((double)rgb->data[k + 145 * nx] / 255.0);
      G = parametricCurveA((double)rgb->data[(k + 145 * nx) + 46400] / 255.0);
      B = parametricCurveA((double)rgb->data[(k + 145 * nx) + 92800] / 255.0);
      fy = f((0.2126728514056225 * R + 0.71515215528781784 * G) +
             0.072174993306559562 * B);
      lab_DRC_image->data[k + 145 * nx] = 116.0 * fy - 16.0;
      lab_DRC_image->data[(k + 145 * nx) + 46400] = 500.0 * (f
        (((0.41245643908969215 * R + 0.35757607764390892 * G) +
          0.18043748326639891 * B) / 0.95047) - fy);
      lab_DRC_image->data[(k + 145 * nx) + 92800] = 200.0 * (fy - f
        (((0.0193338955823293 * R + 0.11919202588130294 * G) +
          0.95030407853636767 * B) / 1.08883));
    }
  }

  emxFree_uint8_T(&rgb);
  emxInit_real_T(&a, 2);

  /* 'ybp_finder_CLS:74' a             = double(lab_DRC_image(:,:,2)); */
  ixstart = a->size[0] * a->size[1];
  a->size[0] = 145;
  a->size[1] = 320;
  emxEnsureCapacity_real_T(a, ixstart);
  for (ixstart = 0; ixstart < 320; ixstart++) {
    for (ixstop = 0; ixstop < 145; ixstop++) {
      a->data[ixstop + a->size[0] * ixstart] = lab_DRC_image->data[(ixstop +
        lab_DRC_image->size[0] * ixstart) + lab_DRC_image->size[0] *
        lab_DRC_image->size[1]];
    }
  }

  emxInit_real_T(&b, 2);

  /* 'ybp_finder_CLS:75' b             = double(lab_DRC_image(:,:,3)); */
  ixstart = b->size[0] * b->size[1];
  b->size[0] = 145;
  b->size[1] = 320;
  emxEnsureCapacity_real_T(b, ixstart);
  for (ixstart = 0; ixstart < 320; ixstart++) {
    for (ixstop = 0; ixstop < 145; ixstop++) {
      b->data[ixstop + b->size[0] * ixstart] = lab_DRC_image->data[(ixstop +
        lab_DRC_image->size[0] * ixstart) + ((lab_DRC_image->size[0] *
        lab_DRC_image->size[1]) << 1)];
    }
  }

  emxFree_real_T(&lab_DRC_image);
  emxInit_real_T2(&distance, 3);

  /* 'ybp_finder_CLS:76' distance      = zeros([size(a,1), size(a,2), nColors]); */
  R = OBJ->nColors;
  ixstart = distance->size[0] * distance->size[1] * distance->size[2];
  distance->size[0] = 145;
  distance->size[1] = 320;
  distance->size[2] = (int)R;
  emxEnsureCapacity_real_T2(distance, ixstart);
  k = 46400 * (int)R;
  for (ixstart = 0; ixstart < k; ixstart++) {
    distance->data[ixstart] = 0.0;
  }

  /* 'ybp_finder_CLS:78' for count = 1:nColors */
  cindx = 0;
  emxInit_real_T(&indx, 2);
  emxInit_real_T(&b_a, 2);
  emxInit_real_T(&b_b, 2);
  while (cindx <= (int)OBJ->nColors - 1) {
    /* 'ybp_finder_CLS:79' distance(:,:,count) = ( (a - color_markers(count,1)).^2 + ... */
    /* 'ybp_finder_CLS:80'                               (b - color_markers(count,2)).^2 ).^0.5; */
    ixstart = indx->size[0] * indx->size[1];
    indx->size[0] = a->size[0];
    indx->size[1] = 320;
    emxEnsureCapacity_real_T(indx, ixstart);
    R = OBJ->color_markers[cindx];
    k = a->size[0] * a->size[1];
    for (ixstart = 0; ixstart < k; ixstart++) {
      indx->data[ixstart] = a->data[ixstart] - R;
    }

    power(indx, b_a);
    ixstart = b_b->size[0] * b_b->size[1];
    b_b->size[0] = b->size[0];
    b_b->size[1] = 320;
    emxEnsureCapacity_real_T(b_b, ixstart);
    R = OBJ->color_markers[5 + cindx];
    k = b->size[0] * b->size[1];
    for (ixstart = 0; ixstart < k; ixstart++) {
      b_b->data[ixstart] = b->data[ixstart] - R;
    }

    power(b_b, indx);
    ixstart = b_a->size[0] * b_a->size[1];
    b_a->size[1] = 320;
    emxEnsureCapacity_real_T(b_a, ixstart);
    nx = b_a->size[0];
    k = b_a->size[1];
    k *= nx;
    for (ixstart = 0; ixstart < k; ixstart++) {
      b_a->data[ixstart] += indx->data[ixstart];
    }

    ixstart = indx->size[0] * indx->size[1];
    indx->size[0] = (short)b_a->size[0];
    indx->size[1] = 320;
    emxEnsureCapacity_real_T(indx, ixstart);
    a_idx_0 = (short)b_a->size[0];
    nx = a_idx_0 * 320;
    for (k = 0; k + 1 <= nx; k++) {
      indx->data[k] = sqrt(b_a->data[k]);
    }

    for (ixstart = 0; ixstart < 320; ixstart++) {
      k = indx->size[0];
      for (ixstop = 0; ixstop < k; ixstop++) {
        distance->data[(ixstop + distance->size[0] * ixstart) + distance->size[0]
          * distance->size[1] * cindx] = indx->data[ixstop + indx->size[0] *
          ixstart];
      }
    }

    cindx++;
  }

  emxFree_real_T(&b_b);
  emxFree_real_T(&b_a);
  emxFree_real_T(&b);
  emxFree_real_T(&a);
  emxInit_int32_T1(&iindx, 2);

  /* 'ybp_finder_CLS:85' [~, ind] = min(distance,[],3); */
  ixstart = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 145;
  iindx->size[1] = 320;
  emxEnsureCapacity_int32_T1(iindx, ixstart);
  for (ixstart = 0; ixstart < 46400; ixstart++) {
    iindx->data[ixstart] = 1;
  }

  n = distance->size[2];
  k = 3;
  while ((k > 2) && (distance->size[2] == 1)) {
    k = 2;
  }

  if (3 > k) {
    vstride = 46400 * distance->size[2];
  } else {
    vstride = 1;
    for (k = 0; k < 2; k++) {
      vstride *= distance->size[k];
    }
  }

  for (nx = 1; nx <= vstride; nx++) {
    ixstart = nx;
    ixstop = nx + (n - 1) * vstride;
    R = distance->data[nx - 1];
    k = 1;
    if (n > 1) {
      cindx = 1;
      if (rtIsNaN(distance->data[nx - 1])) {
        ix = nx + vstride;
        exitg1 = false;
        while ((!exitg1) && (((vstride > 0) && (ix <= ixstop)) || ((vstride < 0)
                 && (ix >= ixstop)))) {
          cindx++;
          ixstart = ix;
          if (!rtIsNaN(distance->data[ix - 1])) {
            R = distance->data[ix - 1];
            k = cindx;
            exitg1 = true;
          } else {
            ix += vstride;
          }
        }
      }

      if (ixstart < ixstop) {
        ix = ixstart + vstride;
        while (((vstride > 0) && (ix <= ixstop)) || ((vstride < 0) && (ix >=
                 ixstop))) {
          cindx++;
          if (distance->data[ix - 1] < R) {
            R = distance->data[ix - 1];
            k = cindx;
          }

          ix += vstride;
        }
      }
    }

    iindx->data[nx - 1] = k;
  }

  emxFree_real_T(&distance);
  ixstart = indx->size[0] * indx->size[1];
  indx->size[0] = iindx->size[0];
  indx->size[1] = 320;
  emxEnsureCapacity_real_T(indx, ixstart);
  k = iindx->size[0] * iindx->size[1];
  for (ixstart = 0; ixstart < k; ixstart++) {
    indx->data[ixstart] = iindx->data[ixstart];
  }

  emxFree_int32_T(&iindx);

  /* 'ybp_finder_CLS:85' ~ */
  /* 'ybp_finder_CLS:89' label      = color_labels(ind); */
  /* 'ybp_finder_CLS:93' if(rmin>1) */
  /* 'ybp_finder_CLS:94' label      = [ 100*ones((rmin-1),NUM_COLS); */
  /* 'ybp_finder_CLS:95'                        label ]; */
  /* 'ybp_finder_CLS:99' OBJ.label         = label; */
  ixstart = OBJ->label->size[0] * OBJ->label->size[1];
  OBJ->label->size[0] = 95 + indx->size[0];
  OBJ->label->size[1] = 320;
  emxEnsureCapacity_real_T(OBJ->label, ixstart);
  for (ixstart = 0; ixstart < 320; ixstart++) {
    for (ixstop = 0; ixstop < 95; ixstop++) {
      OBJ->label->data[ixstop + OBJ->label->size[0] * ixstart] = 100.0;
    }
  }

  for (ixstart = 0; ixstart < 320; ixstart++) {
    k = indx->size[0];
    for (ixstop = 0; ixstop < k; ixstop++) {
      OBJ->label->data[(ixstop + OBJ->label->size[0] * ixstart) + 95] =
        OBJ->color_labels[(int)indx->data[ixstop + indx->size[0] * ixstart] - 1];
    }
  }

  emxFree_real_T(&indx);
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
  int i2;
  i2 = OBJ_label->size[0] * OBJ_label->size[1];
  OBJ_label->size[0] = 0;
  OBJ_label->size[1] = 320;
  emxEnsureCapacity_real_T(OBJ_label, i2);

  /* 'ybp_finder_CLS:46' if(1==nargin) */
  /* 'ybp_finder_CLS:47' tf_do_plots = false; */
  /* 'ybp_finder_CLS:50' OBJ.nColors       =  marker_s.nColors; */
  /* 'ybp_finder_CLS:51' OBJ.color_labels  =  marker_s.color_labels; */
  for (i2 = 0; i2 < 5; i2++) {
    OBJ_color_labels[i2] = marker_s_color_labels[i2];
  }

  /* 'ybp_finder_CLS:52' OBJ.color_markers =  marker_s.color_markers; */
  for (i2 = 0; i2 < 10; i2++) {
    OBJ_color_markers[i2] = marker_s_color_markers[i2];
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
