/*
 * File: regionprops.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "regionprops.h"
#include "bh_MY_CV_ALGORITHMS_emxutil.h"
#include "sum.h"
#include "power.h"
#include "box_info_CLS.h"
#include "bwconncomp.h"
#include "bh_MY_CV_ALGORITHMS_rtwutil.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  boolean_T Area;
  boolean_T Centroid;
  boolean_T BoundingBox;
  boolean_T MajorAxisLength;
  boolean_T MinorAxisLength;
  boolean_T Eccentricity;
  boolean_T Orientation;
  boolean_T Image;
  boolean_T FilledImage;
  boolean_T FilledArea;
  boolean_T EulerNumber;
  boolean_T Extrema;
  boolean_T EquivDiameter;
  boolean_T Extent;
  boolean_T PixelIdxList;
  boolean_T PixelList;
  boolean_T Perimeter;
  boolean_T PixelValues;
  boolean_T WeightedCentroid;
  boolean_T MeanIntensity;
  boolean_T MinIntensity;
  boolean_T MaxIntensity;
  boolean_T SubarrayIdx;
} struct_T;

#endif                                 /*typedef_struct_T*/

/* Function Declarations */
static void ComputeArea(c_emxArray_struct_T *stats, struct_T
  *statsAlreadyComputed);
static void ComputeCentroid(const double imageSize[2], c_emxArray_struct_T
  *stats, struct_T *statsAlreadyComputed);
static void ComputeEllipseParams(const double imageSize[2], c_emxArray_struct_T *
  stats, struct_T *statsAlreadyComputed);
static void ComputePixelIdxList(const emxArray_real_T *CC_RegionIndices, const
  emxArray_int32_T *CC_RegionLengths, double numObjs, c_emxArray_struct_T *stats,
  struct_T *statsAlreadyComputed);
static void ComputePixelList(const double imageSize[2], c_emxArray_struct_T
  *stats, struct_T *statsAlreadyComputed);
static void initializeStatsStruct(double numObjs, c_emxArray_struct_T *stats,
  struct_T *statsAlreadyComputed);

/* Function Definitions */

/*
 * Arguments    : c_emxArray_struct_T *stats
 *                struct_T *statsAlreadyComputed
 * Return Type  : void
 */
static void ComputeArea(c_emxArray_struct_T *stats, struct_T
  *statsAlreadyComputed)
{
  int i14;
  int k;
  if (!statsAlreadyComputed->Area) {
    statsAlreadyComputed->Area = true;
    i14 = stats->size[0];
    for (k = 0; k < i14; k++) {
      stats->data[k].Area = stats->data[k].PixelIdxList->size[0];
    }
  }
}

/*
 * Arguments    : const double imageSize[2]
 *                c_emxArray_struct_T *stats
 *                struct_T *statsAlreadyComputed
 * Return Type  : void
 */
static void ComputeCentroid(const double imageSize[2], c_emxArray_struct_T
  *stats, struct_T *statsAlreadyComputed)
{
  c_emxArray_struct_T *b_stats;
  int xpageoffset;
  int loop_ub;
  int k;
  double y[2];
  int b_k;
  if (!statsAlreadyComputed->Centroid) {
    emxInit_struct_T2(&b_stats, 1);
    statsAlreadyComputed->Centroid = true;
    xpageoffset = b_stats->size[0];
    b_stats->size[0] = stats->size[0];
    emxEnsureCapacity_struct_T2(b_stats, xpageoffset);
    loop_ub = stats->size[0];
    for (xpageoffset = 0; xpageoffset < loop_ub; xpageoffset++) {
      emxCopyStruct_struct_T2(&b_stats->data[xpageoffset], &stats->
        data[xpageoffset]);
    }

    ComputePixelList(imageSize, b_stats, statsAlreadyComputed);
    xpageoffset = stats->size[0];
    stats->size[0] = b_stats->size[0];
    emxEnsureCapacity_struct_T2(stats, xpageoffset);
    loop_ub = b_stats->size[0];
    for (xpageoffset = 0; xpageoffset < loop_ub; xpageoffset++) {
      emxCopyStruct_struct_T2(&stats->data[xpageoffset], &b_stats->
        data[xpageoffset]);
    }

    for (k = 0; k < b_stats->size[0]; k++) {
      if (stats->data[k].PixelList->size[0] == 0) {
        for (xpageoffset = 0; xpageoffset < 2; xpageoffset++) {
          y[xpageoffset] = 0.0;
        }
      } else {
        for (loop_ub = 0; loop_ub < 2; loop_ub++) {
          xpageoffset = loop_ub * stats->data[k].PixelList->size[0];
          y[loop_ub] = stats->data[k].PixelList->data[xpageoffset];
          for (b_k = 2; b_k <= stats->data[k].PixelList->size[0]; b_k++) {
            y[loop_ub] += stats->data[k].PixelList->data[(xpageoffset + b_k) - 1];
          }
        }
      }

      loop_ub = stats->data[k].PixelList->size[0];
      for (xpageoffset = 0; xpageoffset < 2; xpageoffset++) {
        stats->data[k].Centroid[xpageoffset] = y[xpageoffset] / (double)loop_ub;
      }
    }

    emxFree_struct_T2(&b_stats);
  }
}

/*
 * Arguments    : const double imageSize[2]
 *                c_emxArray_struct_T *stats
 *                struct_T *statsAlreadyComputed
 * Return Type  : void
 */
static void ComputeEllipseParams(const double imageSize[2], c_emxArray_struct_T *
  stats, struct_T *statsAlreadyComputed)
{
  boolean_T b0;
  int i17;
  int k;
  emxArray_real_T *x;
  emxArray_real_T *y;
  emxArray_real_T *b_x;
  int loop_ub;
  double common;
  int i18;
  double b_y;
  double c_y;
  double uxy;
  double num;
  if (statsAlreadyComputed->MajorAxisLength &&
      statsAlreadyComputed->MinorAxisLength && statsAlreadyComputed->Orientation
      && statsAlreadyComputed->Eccentricity) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (!b0) {
    statsAlreadyComputed->MajorAxisLength = true;
    statsAlreadyComputed->MinorAxisLength = true;
    statsAlreadyComputed->Eccentricity = true;
    statsAlreadyComputed->Orientation = true;
    ComputePixelList(imageSize, stats, statsAlreadyComputed);
    ComputeCentroid(imageSize, stats, statsAlreadyComputed);
    i17 = stats->size[0];
    k = 0;
    emxInit_real_T1(&x, 1);
    emxInit_real_T1(&y, 1);
    emxInit_real_T1(&b_x, 1);
    while (k <= i17 - 1) {
      if (stats->data[k].PixelList->size[0] == 0) {
        stats->data[k].MajorAxisLength = 0.0;
        stats->data[k].MinorAxisLength = 0.0;
        stats->data[k].Eccentricity = 0.0;
        stats->data[k].Orientation = 0.0;
      } else {
        loop_ub = stats->data[k].PixelList->size[0];
        common = stats->data[k].Centroid[0];
        i18 = x->size[0];
        x->size[0] = loop_ub;
        emxEnsureCapacity_real_T1(x, i18);
        for (i18 = 0; i18 < loop_ub; i18++) {
          x->data[i18] = stats->data[k].PixelList->data[i18] - common;
        }

        loop_ub = stats->data[k].PixelList->size[0];
        common = stats->data[k].Centroid[1];
        i18 = y->size[0];
        y->size[0] = loop_ub;
        emxEnsureCapacity_real_T1(y, i18);
        for (i18 = 0; i18 < loop_ub; i18++) {
          y->data[i18] = -(stats->data[k].PixelList->data[i18 + stats->data[k].
                           PixelList->size[0]] - common);
        }

        b_power(x, b_x);
        common = sum(b_x);
        b_y = common / (double)x->size[0];
        b_power(y, b_x);
        common = sum(b_x);
        c_y = common / (double)x->size[0];
        i18 = b_x->size[0];
        b_x->size[0] = x->size[0];
        emxEnsureCapacity_real_T1(b_x, i18);
        loop_ub = x->size[0];
        for (i18 = 0; i18 < loop_ub; i18++) {
          b_x->data[i18] = x->data[i18] * y->data[i18];
        }

        common = sum(b_x);
        uxy = common / (double)x->size[0];
        common = (b_y + 0.083333333333333329) - (c_y + 0.083333333333333329);
        common = sqrt(common * common + 4.0 * (uxy * uxy));
        stats->data[k].MajorAxisLength = 2.8284271247461903 * sqrt(((b_y +
          0.083333333333333329) + (c_y + 0.083333333333333329)) + common);
        stats->data[k].MinorAxisLength = 2.8284271247461903 * sqrt(((b_y +
          0.083333333333333329) + (c_y + 0.083333333333333329)) - common);
        common = stats->data[k].MajorAxisLength / 2.0;
        num = stats->data[k].MinorAxisLength / 2.0;
        stats->data[k].Eccentricity = 2.0 * sqrt(common * common - num * num) /
          stats->data[k].MajorAxisLength;
        if (c_y + 0.083333333333333329 > b_y + 0.083333333333333329) {
          common = (c_y + 0.083333333333333329) - (b_y + 0.083333333333333329);
          num = ((c_y + 0.083333333333333329) - (b_y + 0.083333333333333329)) +
            sqrt(common * common + 4.0 * (uxy * uxy));
          common = 2.0 * uxy;
        } else {
          num = 2.0 * uxy;
          common = (b_y + 0.083333333333333329) - (c_y + 0.083333333333333329);
          common = ((b_y + 0.083333333333333329) - (c_y + 0.083333333333333329))
            + sqrt(common * common + 4.0 * (uxy * uxy));
        }

        if ((num == 0.0) && (common == 0.0)) {
          stats->data[k].Orientation = 0.0;
        } else {
          stats->data[k].Orientation = 57.295779513082323 * atan(num / common);
        }
      }

      k++;
    }

    emxFree_real_T(&b_x);
    emxFree_real_T(&y);
    emxFree_real_T(&x);
  }
}

/*
 * Arguments    : const emxArray_real_T *CC_RegionIndices
 *                const emxArray_int32_T *CC_RegionLengths
 *                double numObjs
 *                c_emxArray_struct_T *stats
 *                struct_T *statsAlreadyComputed
 * Return Type  : void
 */
static void ComputePixelIdxList(const emxArray_real_T *CC_RegionIndices, const
  emxArray_int32_T *CC_RegionLengths, double numObjs, c_emxArray_struct_T *stats,
  struct_T *statsAlreadyComputed)
{
  emxArray_int32_T *regionLengths;
  int i12;
  int loop_ub;
  int vstride;
  emxArray_int32_T *idxCount;
  int k;
  int i13;
  statsAlreadyComputed->PixelIdxList = true;
  if (numObjs != 0.0) {
    emxInit_int32_T(&regionLengths, 1);
    i12 = regionLengths->size[0];
    regionLengths->size[0] = CC_RegionLengths->size[0];
    emxEnsureCapacity_int32_T(regionLengths, i12);
    loop_ub = CC_RegionLengths->size[0];
    for (i12 = 0; i12 < loop_ub; i12++) {
      regionLengths->data[i12] = CC_RegionLengths->data[i12];
    }

    loop_ub = 2;
    if (CC_RegionLengths->size[0] != 1) {
      loop_ub = 1;
    }

    if (loop_ub <= 1) {
      i12 = CC_RegionLengths->size[0];
    } else {
      i12 = 1;
    }

    if ((!(CC_RegionLengths->size[0] == 0)) && (i12 > 1)) {
      vstride = 1;
      k = 1;
      while (k <= loop_ub - 1) {
        vstride *= CC_RegionLengths->size[0];
        k = 2;
      }

      for (loop_ub = 0; loop_ub + 1 <= vstride; loop_ub++) {
        for (k = 1; k < i12; k++) {
          regionLengths->data[loop_ub + k * vstride] += regionLengths->
            data[loop_ub + (k - 1) * vstride];
        }
      }
    }

    emxInit_int32_T(&idxCount, 1);
    i12 = idxCount->size[0];
    idxCount->size[0] = 1 + regionLengths->size[0];
    emxEnsureCapacity_int32_T(idxCount, i12);
    idxCount->data[0] = 0;
    loop_ub = regionLengths->size[0];
    for (i12 = 0; i12 < loop_ub; i12++) {
      idxCount->data[i12 + 1] = regionLengths->data[i12];
    }

    emxFree_int32_T(&regionLengths);
    i12 = stats->size[0];
    for (k = 0; k < i12; k++) {
      if (idxCount->data[k] + 1 > idxCount->data[(int)((1.0 + (double)k) + 1.0)
          - 1]) {
        vstride = 1;
        i13 = 0;
      } else {
        vstride = idxCount->data[k] + 1;
        i13 = idxCount->data[(int)((1.0 + (double)k) + 1.0) - 1];
      }

      loop_ub = stats->data[k].PixelIdxList->size[0];
      stats->data[k].PixelIdxList->size[0] = (i13 - vstride) + 1;
      emxEnsureCapacity_real_T1(stats->data[k].PixelIdxList, loop_ub);
      loop_ub = (i13 - vstride) + 1;
      for (i13 = 0; i13 < loop_ub; i13++) {
        stats->data[k].PixelIdxList->data[i13] = CC_RegionIndices->data[(vstride
          + i13) - 1];
      }
    }

    emxFree_int32_T(&idxCount);
  }
}

/*
 * Arguments    : const double imageSize[2]
 *                c_emxArray_struct_T *stats
 *                struct_T *statsAlreadyComputed
 * Return Type  : void
 */
static void ComputePixelList(const double imageSize[2], c_emxArray_struct_T
  *stats, struct_T *statsAlreadyComputed)
{
  int i15;
  int k;
  emxArray_int32_T *v1;
  emxArray_int32_T *vk;
  int i16;
  int loop_ub;
  if (!statsAlreadyComputed->PixelList) {
    statsAlreadyComputed->PixelList = true;
    i15 = stats->size[0];
    k = 0;
    emxInit_int32_T(&v1, 1);
    emxInit_int32_T(&vk, 1);
    while (k <= i15 - 1) {
      if (!(stats->data[k].PixelIdxList->size[0] == 0)) {
        i16 = v1->size[0];
        v1->size[0] = stats->data[k].PixelIdxList->size[0];
        emxEnsureCapacity_int32_T(v1, i16);
        loop_ub = stats->data[k].PixelIdxList->size[0];
        for (i16 = 0; i16 < loop_ub; i16++) {
          v1->data[i16] = (int)stats->data[k].PixelIdxList->data[i16] - 1;
        }

        i16 = vk->size[0];
        vk->size[0] = v1->size[0];
        emxEnsureCapacity_int32_T(vk, i16);
        loop_ub = v1->size[0];
        for (i16 = 0; i16 < loop_ub; i16++) {
          vk->data[i16] = div_s32(v1->data[i16], (int)imageSize[0]);
        }

        i16 = v1->size[0];
        emxEnsureCapacity_int32_T(v1, i16);
        loop_ub = v1->size[0];
        for (i16 = 0; i16 < loop_ub; i16++) {
          v1->data[i16] -= vk->data[i16] * (int)imageSize[0];
        }

        i16 = stats->data[k].PixelList->size[0] * stats->data[k].PixelList->
          size[1];
        stats->data[k].PixelList->size[0] = vk->size[0];
        stats->data[k].PixelList->size[1] = 2;
        emxEnsureCapacity_real_T(stats->data[k].PixelList, i16);
        loop_ub = vk->size[0];
        for (i16 = 0; i16 < loop_ub; i16++) {
          stats->data[k].PixelList->data[i16] = vk->data[i16] + 1;
        }

        loop_ub = v1->size[0];
        for (i16 = 0; i16 < loop_ub; i16++) {
          stats->data[k].PixelList->data[i16 + stats->data[k].PixelList->size[0]]
            = v1->data[i16] + 1;
        }
      } else {
        i16 = stats->data[k].PixelList->size[0] * stats->data[k].PixelList->
          size[1];
        stats->data[k].PixelList->size[0] = 0;
        stats->data[k].PixelList->size[1] = 2;
        emxEnsureCapacity_real_T(stats->data[k].PixelList, i16);
      }

      k++;
    }

    emxFree_int32_T(&vk);
    emxFree_int32_T(&v1);
  }
}

/*
 * Arguments    : double numObjs
 *                c_emxArray_struct_T *stats
 *                struct_T *statsAlreadyComputed
 * Return Type  : void
 */
static void initializeStatsStruct(double numObjs, c_emxArray_struct_T *stats,
  struct_T *statsAlreadyComputed)
{
  d_struct_T statsOneObj;
  int i5;
  int loop_ub;
  emxInitStruct_struct_T2(&statsOneObj);
  statsAlreadyComputed->Area = false;
  statsOneObj.Area = 0.0;
  statsAlreadyComputed->Centroid = false;
  for (i5 = 0; i5 < 2; i5++) {
    statsOneObj.Centroid[i5] = 0.0;
  }

  statsAlreadyComputed->BoundingBox = false;
  for (i5 = 0; i5 < 4; i5++) {
    statsOneObj.BoundingBox[i5] = 0.0;
  }

  statsAlreadyComputed->MajorAxisLength = false;
  statsOneObj.MajorAxisLength = 0.0;
  statsAlreadyComputed->MinorAxisLength = false;
  statsOneObj.MinorAxisLength = 0.0;
  statsAlreadyComputed->Eccentricity = false;
  statsOneObj.Eccentricity = 0.0;
  statsAlreadyComputed->Orientation = false;
  statsOneObj.Orientation = 0.0;
  statsAlreadyComputed->Image = false;
  i5 = statsOneObj.Image->size[0] * statsOneObj.Image->size[1];
  statsOneObj.Image->size[0] = 0;
  statsOneObj.Image->size[1] = 0;
  emxEnsureCapacity_boolean_T(statsOneObj.Image, i5);
  statsAlreadyComputed->FilledImage = false;
  i5 = statsOneObj.FilledImage->size[0] * statsOneObj.FilledImage->size[1];
  statsOneObj.FilledImage->size[0] = 0;
  statsOneObj.FilledImage->size[1] = 0;
  emxEnsureCapacity_boolean_T(statsOneObj.FilledImage, i5);
  statsAlreadyComputed->FilledArea = false;
  statsOneObj.FilledArea = 0.0;
  statsAlreadyComputed->EulerNumber = false;
  statsOneObj.EulerNumber = 0.0;
  statsAlreadyComputed->Extrema = false;
  memset(&statsOneObj.Extrema[0], 0, sizeof(double) << 4);
  statsAlreadyComputed->EquivDiameter = false;
  statsOneObj.EquivDiameter = 0.0;
  statsAlreadyComputed->Extent = false;
  statsOneObj.Extent = 0.0;
  statsAlreadyComputed->PixelIdxList = false;
  i5 = statsOneObj.PixelIdxList->size[0];
  statsOneObj.PixelIdxList->size[0] = 0;
  emxEnsureCapacity_real_T1(statsOneObj.PixelIdxList, i5);
  statsAlreadyComputed->PixelList = false;
  i5 = statsOneObj.PixelList->size[0] * statsOneObj.PixelList->size[1];
  statsOneObj.PixelList->size[0] = 0;
  statsOneObj.PixelList->size[1] = 2;
  emxEnsureCapacity_real_T(statsOneObj.PixelList, i5);
  statsAlreadyComputed->Perimeter = false;
  statsOneObj.Perimeter = 0.0;
  statsAlreadyComputed->PixelValues = false;
  i5 = statsOneObj.PixelValues->size[0];
  statsOneObj.PixelValues->size[0] = 0;
  emxEnsureCapacity_real_T1(statsOneObj.PixelValues, i5);
  statsAlreadyComputed->WeightedCentroid = false;
  for (i5 = 0; i5 < 2; i5++) {
    statsOneObj.WeightedCentroid[i5] = 0.0;
  }

  statsAlreadyComputed->MeanIntensity = false;
  statsOneObj.MeanIntensity = 0.0;
  statsAlreadyComputed->MinIntensity = false;
  statsOneObj.MinIntensity = 0.0;
  statsAlreadyComputed->MaxIntensity = false;
  statsOneObj.MaxIntensity = 0.0;
  statsAlreadyComputed->SubarrayIdx = false;
  i5 = statsOneObj.SubarrayIdx->size[0] * statsOneObj.SubarrayIdx->size[1];
  statsOneObj.SubarrayIdx->size[0] = 1;
  statsOneObj.SubarrayIdx->size[1] = 0;
  emxEnsureCapacity_real_T(statsOneObj.SubarrayIdx, i5);
  for (i5 = 0; i5 < 2; i5++) {
    statsOneObj.SubarrayIdxLengths[i5] = 0.0;
  }

  i5 = stats->size[0];
  stats->size[0] = (int)numObjs;
  emxEnsureCapacity_struct_T2(stats, i5);
  loop_ub = (int)numObjs;
  for (i5 = 0; i5 < loop_ub; i5++) {
    emxCopyStruct_struct_T2(&stats->data[i5], &statsOneObj);
  }

  emxFreeStruct_struct_T2(&statsOneObj);
}

/*
 * Arguments    : const emxArray_boolean_T *varargin_1
 *                emxArray_struct_T *outstats
 * Return Type  : void
 */
void b_regionprops(const emxArray_boolean_T *varargin_1, emxArray_struct_T
                   *outstats)
{
  emxArray_real_T *CC_RegionIndices;
  emxArray_int32_T *CC_RegionLengths;
  b_struct_T statsOneObj;
  double expl_temp;
  double CC_ImageSize[2];
  double CC_NumObjects;
  int i6;
  int loop_ub;
  c_emxArray_struct_T *stats;
  struct_T statsAlreadyComputed;
  int vIdx;
  emxInit_real_T1(&CC_RegionIndices, 1);
  emxInit_int32_T(&CC_RegionLengths, 1);
  emxInitStruct_struct_T(&statsOneObj);
  bwconncomp(varargin_1, &expl_temp, CC_ImageSize, &CC_NumObjects,
             CC_RegionIndices, CC_RegionLengths);
  statsOneObj.Area = 0.0;
  statsOneObj.Eccentricity = 0.0;
  i6 = statsOneObj.PixelIdxList->size[0];
  statsOneObj.PixelIdxList->size[0] = 0;
  emxEnsureCapacity_real_T1(statsOneObj.PixelIdxList, i6);
  i6 = outstats->size[0];
  outstats->size[0] = (int)CC_NumObjects;
  emxEnsureCapacity_struct_T(outstats, i6);
  loop_ub = (int)CC_NumObjects;
  for (i6 = 0; i6 < loop_ub; i6++) {
    emxCopyStruct_struct_T(&outstats->data[i6], &statsOneObj);
  }

  emxFreeStruct_struct_T(&statsOneObj);
  emxInit_struct_T2(&stats, 1);
  initializeStatsStruct(CC_NumObjects, stats, &statsAlreadyComputed);
  ComputePixelIdxList(CC_RegionIndices, CC_RegionLengths, CC_NumObjects, stats,
                      &statsAlreadyComputed);
  ComputeArea(stats, &statsAlreadyComputed);
  ComputeEllipseParams(CC_ImageSize, stats, &statsAlreadyComputed);
  loop_ub = 0;
  emxFree_int32_T(&CC_RegionLengths);
  emxFree_real_T(&CC_RegionIndices);
  while (loop_ub <= stats->size[0] - 1) {
    outstats->data[loop_ub].Area = stats->data[loop_ub].Area;
    outstats->data[loop_ub].Eccentricity = stats->data[loop_ub].Eccentricity;
    i6 = outstats->data[loop_ub].PixelIdxList->size[0];
    outstats->data[loop_ub].PixelIdxList->size[0] = stats->data[loop_ub].
      PixelIdxList->size[0];
    emxEnsureCapacity_real_T1(outstats->data[loop_ub].PixelIdxList, i6);
    i6 = outstats->data[loop_ub].PixelIdxList->size[0];
    for (vIdx = 0; vIdx < i6; vIdx++) {
      outstats->data[loop_ub].PixelIdxList->data[vIdx] = stats->data[loop_ub].
        PixelIdxList->data[vIdx];
    }

    loop_ub++;
  }

  emxFree_struct_T2(&stats);
}

/*
 * Arguments    : const emxArray_boolean_T *varargin_2
 *                b_emxArray_struct_T *outstats
 * Return Type  : void
 */
void regionprops(const emxArray_boolean_T *varargin_2, b_emxArray_struct_T
                 *outstats)
{
  emxArray_real_T *CC_RegionIndices;
  emxArray_int32_T *CC_RegionLengths;
  c_struct_T statsOneObj;
  double expl_temp;
  double CC_ImageSize[2];
  double CC_NumObjects;
  int i4;
  int loop_ub;
  c_emxArray_struct_T *stats;
  struct_T statsAlreadyComputed;
  int vIdx;
  emxInit_real_T1(&CC_RegionIndices, 1);
  emxInit_int32_T(&CC_RegionLengths, 1);
  emxInitStruct_struct_T1(&statsOneObj);
  bwconncomp(varargin_2, &expl_temp, CC_ImageSize, &CC_NumObjects,
             CC_RegionIndices, CC_RegionLengths);
  statsOneObj.Orientation = 0.0;
  statsOneObj.Eccentricity = 0.0;
  statsOneObj.Area = 0.0;
  i4 = statsOneObj.PixelIdxList->size[0];
  statsOneObj.PixelIdxList->size[0] = 0;
  emxEnsureCapacity_real_T1(statsOneObj.PixelIdxList, i4);
  i4 = outstats->size[0];
  outstats->size[0] = (int)CC_NumObjects;
  emxEnsureCapacity_struct_T1(outstats, i4);
  loop_ub = (int)CC_NumObjects;
  for (i4 = 0; i4 < loop_ub; i4++) {
    emxCopyStruct_struct_T1(&outstats->data[i4], &statsOneObj);
  }

  emxFreeStruct_struct_T1(&statsOneObj);
  emxInit_struct_T2(&stats, 1);
  initializeStatsStruct(CC_NumObjects, stats, &statsAlreadyComputed);
  ComputePixelIdxList(CC_RegionIndices, CC_RegionLengths, CC_NumObjects, stats,
                      &statsAlreadyComputed);
  ComputeEllipseParams(CC_ImageSize, stats, &statsAlreadyComputed);
  ComputeEllipseParams(CC_ImageSize, stats, &statsAlreadyComputed);
  ComputeArea(stats, &statsAlreadyComputed);
  loop_ub = 0;
  emxFree_int32_T(&CC_RegionLengths);
  emxFree_real_T(&CC_RegionIndices);
  while (loop_ub <= stats->size[0] - 1) {
    outstats->data[loop_ub].Orientation = stats->data[loop_ub].Orientation;
    outstats->data[loop_ub].Eccentricity = stats->data[loop_ub].Eccentricity;
    outstats->data[loop_ub].Area = stats->data[loop_ub].Area;
    i4 = outstats->data[loop_ub].PixelIdxList->size[0];
    outstats->data[loop_ub].PixelIdxList->size[0] = stats->data[loop_ub].
      PixelIdxList->size[0];
    emxEnsureCapacity_real_T1(outstats->data[loop_ub].PixelIdxList, i4);
    i4 = outstats->data[loop_ub].PixelIdxList->size[0];
    for (vIdx = 0; vIdx < i4; vIdx++) {
      outstats->data[loop_ub].PixelIdxList->data[vIdx] = stats->data[loop_ub].
        PixelIdxList->data[vIdx];
    }

    loop_ub++;
  }

  emxFree_struct_T2(&stats);
}

/*
 * File trailer for regionprops.c
 *
 * [EOF]
 */
