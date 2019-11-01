/*
 * File: regionprops.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "regionprops.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "sum.h"
#include "power.h"
#include "box_info_CLS.h"
#include "sort1.h"
#include "bwconncomp.h"
#include "bh_my_detect_ALGORITHM_for_codegen_rtwutil.h"

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
static void populateOutputStatsStructure(b_emxArray_struct_T *outstats, const
  c_emxArray_struct_T *stats);

/* Function Definitions */

/*
 * Arguments    : c_emxArray_struct_T *stats
 *                struct_T *statsAlreadyComputed
 * Return Type  : void
 */
static void ComputeArea(c_emxArray_struct_T *stats, struct_T
  *statsAlreadyComputed)
{
  int i15;
  int k;
  if (!statsAlreadyComputed->Area) {
    statsAlreadyComputed->Area = true;
    i15 = stats->size[0];
    for (k = 0; k < i15; k++) {
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
  int k;
  int vlen;
  int b_k;
  double y[2];
  int c_k;
  if (!statsAlreadyComputed->Centroid) {
    emxInit_struct_T3(&b_stats, 1);
    statsAlreadyComputed->Centroid = true;
    k = b_stats->size[0];
    b_stats->size[0] = stats->size[0];
    emxEnsureCapacity_struct_T3(b_stats, k);
    vlen = stats->size[0];
    for (k = 0; k < vlen; k++) {
      emxCopyStruct_struct_T2(&b_stats->data[k], &stats->data[k]);
    }

    ComputePixelList(imageSize, b_stats, statsAlreadyComputed);
    k = stats->size[0];
    stats->size[0] = b_stats->size[0];
    emxEnsureCapacity_struct_T3(stats, k);
    vlen = b_stats->size[0];
    for (k = 0; k < vlen; k++) {
      emxCopyStruct_struct_T2(&stats->data[k], &b_stats->data[k]);
    }

    for (b_k = 0; b_k < b_stats->size[0]; b_k++) {
      vlen = stats->data[b_k].PixelList->size[0];
      if (stats->data[b_k].PixelList->size[0] == 0) {
        for (k = 0; k < 2; k++) {
          y[k] = 0.0;
        }
      } else {
        for (k = 0; k < 2; k++) {
          y[k] = stats->data[b_k].PixelList->data[k];
        }

        for (k = 1; k < vlen; k++) {
          for (c_k = 0; c_k < 2; c_k++) {
            if (vlen >= 2) {
              y[c_k] += stats->data[b_k].PixelList->data[c_k + stats->data[b_k].
                PixelList->size[1] * k];
            }
          }
        }
      }

      vlen = stats->data[b_k].PixelList->size[0];
      for (k = 0; k < 2; k++) {
        stats->data[b_k].Centroid[k] = y[k] / (double)vlen;
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
  int i18;
  int k;
  emxArray_real_T *x;
  emxArray_real_T *y;
  emxArray_real_T *b_x;
  emxArray_real_T *b_stats;
  int loop_ub;
  int b_loop_ub;
  int i19;
  double common;
  double b_y;
  double c_y;
  double uxy;
  double num;
  if (statsAlreadyComputed->MajorAxisLength &&
      statsAlreadyComputed->MinorAxisLength && statsAlreadyComputed->Orientation
      && statsAlreadyComputed->Eccentricity) {
  } else {
    statsAlreadyComputed->MajorAxisLength = true;
    statsAlreadyComputed->MinorAxisLength = true;
    statsAlreadyComputed->Eccentricity = true;
    statsAlreadyComputed->Orientation = true;
    ComputePixelList(imageSize, stats, statsAlreadyComputed);
    ComputeCentroid(imageSize, stats, statsAlreadyComputed);
    i18 = stats->size[0];
    k = 0;
    emxInit_real_T1(&x, 1);
    emxInit_real_T1(&y, 1);
    emxInit_real_T1(&b_x, 1);
    emxInit_real_T(&b_stats, 2);
    while (k <= i18 - 1) {
      if (stats->data[k].PixelList->size[0] == 0) {
        stats->data[k].MajorAxisLength = 0.0;
        stats->data[k].MinorAxisLength = 0.0;
        stats->data[k].Eccentricity = 0.0;
        stats->data[k].Orientation = 0.0;
      } else {
        loop_ub = stats->data[k].PixelList->size[0];
        b_loop_ub = stats->data[k].PixelList->size[0];
        i19 = b_stats->size[0] * b_stats->size[1];
        b_stats->size[1] = 1;
        b_stats->size[0] = b_loop_ub;
        emxEnsureCapacity_real_T(b_stats, i19);
        for (i19 = 0; i19 < b_loop_ub; i19++) {
          b_stats->data[b_stats->size[1] * i19] = stats->data[k].PixelList->
            data[stats->data[k].PixelList->size[1] * i19];
        }

        common = stats->data[k].Centroid[0];
        i19 = x->size[0];
        x->size[0] = loop_ub;
        emxEnsureCapacity_real_T1(x, i19);
        for (i19 = 0; i19 < loop_ub; i19++) {
          x->data[i19] = b_stats->data[i19] - common;
        }

        loop_ub = stats->data[k].PixelList->size[0];
        b_loop_ub = stats->data[k].PixelList->size[0];
        i19 = b_stats->size[0] * b_stats->size[1];
        b_stats->size[1] = 1;
        b_stats->size[0] = b_loop_ub;
        emxEnsureCapacity_real_T(b_stats, i19);
        for (i19 = 0; i19 < b_loop_ub; i19++) {
          b_stats->data[b_stats->size[1] * i19] = stats->data[k].PixelList->
            data[1 + stats->data[k].PixelList->size[1] * i19];
        }

        common = stats->data[k].Centroid[1];
        i19 = y->size[0];
        y->size[0] = loop_ub;
        emxEnsureCapacity_real_T1(y, i19);
        for (i19 = 0; i19 < loop_ub; i19++) {
          y->data[i19] = -(b_stats->data[i19] - common);
        }

        b_power(x, b_x);
        b_y = sum(b_x) / (double)x->size[0];
        b_power(y, b_x);
        c_y = sum(b_x) / (double)x->size[0];
        i19 = b_x->size[0];
        b_x->size[0] = x->size[0];
        emxEnsureCapacity_real_T1(b_x, i19);
        loop_ub = x->size[0];
        for (i19 = 0; i19 < loop_ub; i19++) {
          b_x->data[i19] = x->data[i19] * y->data[i19];
        }

        uxy = sum(b_x) / (double)x->size[0];
        common = sqrt(rt_powd_snf((b_y + 0.083333333333333329) - (c_y +
          0.083333333333333329), 2.0) + 4.0 * rt_powd_snf(uxy, 2.0));
        stats->data[k].MajorAxisLength = 2.8284271247461903 * sqrt(((b_y +
          0.083333333333333329) + (c_y + 0.083333333333333329)) + common);
        stats->data[k].MinorAxisLength = 2.8284271247461903 * sqrt(((b_y +
          0.083333333333333329) + (c_y + 0.083333333333333329)) - common);
        stats->data[k].Eccentricity = 2.0 * sqrt(rt_powd_snf(stats->data[k].
          MajorAxisLength / 2.0, 2.0) - rt_powd_snf(stats->data[k].
          MinorAxisLength / 2.0, 2.0)) / stats->data[k].MajorAxisLength;
        if (c_y + 0.083333333333333329 > b_y + 0.083333333333333329) {
          num = ((c_y + 0.083333333333333329) - (b_y + 0.083333333333333329)) +
            sqrt(rt_powd_snf((c_y + 0.083333333333333329) - (b_y +
                   0.083333333333333329), 2.0) + 4.0 * rt_powd_snf(uxy, 2.0));
          common = 2.0 * uxy;
        } else {
          num = 2.0 * uxy;
          common = ((b_y + 0.083333333333333329) - (c_y + 0.083333333333333329))
            + sqrt(rt_powd_snf((b_y + 0.083333333333333329) - (c_y +
                     0.083333333333333329), 2.0) + 4.0 * rt_powd_snf(uxy, 2.0));
        }

        if ((num == 0.0) && (common == 0.0)) {
          stats->data[k].Orientation = 0.0;
        } else {
          stats->data[k].Orientation = 57.295779513082323 * atan(num / common);
        }
      }

      k++;
    }

    emxFree_real_T(&b_stats);
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
  int k;
  emxArray_int32_T *idxCount;
  emxArray_real_T *b_CC_RegionIndices;
  int i13;
  int regionLengths_idx_0;
  unsigned int c_CC_RegionIndices[2];
  int d_CC_RegionIndices[2];
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

    if ((1 == loop_ub) && (CC_RegionLengths->size[0] != 0) &&
        (CC_RegionLengths->size[0] != 1)) {
      for (k = 1; k < CC_RegionLengths->size[0]; k++) {
        regionLengths->data[k] += regionLengths->data[k - 1];
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

    i12 = stats->size[0];
    k = 0;
    emxInit_real_T(&b_CC_RegionIndices, 2);
    while (k <= i12 - 1) {
      if (idxCount->data[k] + 1 > idxCount->data[(int)((1.0 + (double)k) + 1.0)
          - 1]) {
        i13 = 1;
        regionLengths_idx_0 = 0;
      } else {
        i13 = idxCount->data[k] + 1;
        regionLengths_idx_0 = idxCount->data[(int)((1.0 + (double)k) + 1.0) - 1];
      }

      loop_ub = regionLengths->size[0];
      regionLengths->size[0] = (regionLengths_idx_0 - i13) + 1;
      emxEnsureCapacity_int32_T(regionLengths, loop_ub);
      loop_ub = (regionLengths_idx_0 - i13) + 1;
      for (regionLengths_idx_0 = 0; regionLengths_idx_0 < loop_ub;
           regionLengths_idx_0++) {
        regionLengths->data[regionLengths_idx_0] = (i13 + regionLengths_idx_0) -
          1;
      }

      c_CC_RegionIndices[0] = (unsigned int)CC_RegionIndices->size[0];
      c_CC_RegionIndices[1] = 1U;
      for (i13 = 0; i13 < 2; i13++) {
        d_CC_RegionIndices[i13] = (int)c_CC_RegionIndices[1 - i13];
      }

      loop_ub = regionLengths->size[0];
      regionLengths_idx_0 = regionLengths->size[0];
      i13 = b_CC_RegionIndices->size[0] * b_CC_RegionIndices->size[1];
      b_CC_RegionIndices->size[1] = 1;
      b_CC_RegionIndices->size[0] = loop_ub;
      emxEnsureCapacity_real_T(b_CC_RegionIndices, i13);
      for (i13 = 0; i13 < loop_ub; i13++) {
        b_CC_RegionIndices->data[b_CC_RegionIndices->size[1] * i13] =
          CC_RegionIndices->data[d_CC_RegionIndices[0] * regionLengths->data[i13]];
      }

      i13 = stats->data[k].PixelIdxList->size[0];
      stats->data[k].PixelIdxList->size[0] = regionLengths_idx_0;
      emxEnsureCapacity_real_T1(stats->data[k].PixelIdxList, i13);
      for (i13 = 0; i13 < regionLengths_idx_0; i13++) {
        stats->data[k].PixelIdxList->data[i13] = b_CC_RegionIndices->data[i13];
      }

      sort(stats->data[k].PixelIdxList);
      k++;
    }

    emxFree_real_T(&b_CC_RegionIndices);
    emxFree_int32_T(&idxCount);
    emxFree_int32_T(&regionLengths);
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
  int i16;
  int k;
  emxArray_int32_T *i;
  emxArray_int32_T *j;
  emxArray_int32_T *v1;
  emxArray_int32_T *vk;
  int i17;
  int loop_ub;
  int unnamed_idx_1;
  if (!statsAlreadyComputed->PixelList) {
    statsAlreadyComputed->PixelList = true;
    i16 = stats->size[0];
    k = 0;
    emxInit_int32_T(&i, 1);
    emxInit_int32_T(&j, 1);
    emxInit_int32_T(&v1, 1);
    emxInit_int32_T(&vk, 1);
    while (k <= i16 - 1) {
      if (!(stats->data[k].PixelIdxList->size[0] == 0)) {
        i17 = v1->size[0];
        v1->size[0] = stats->data[k].PixelIdxList->size[0];
        emxEnsureCapacity_int32_T(v1, i17);
        loop_ub = stats->data[k].PixelIdxList->size[0];
        for (i17 = 0; i17 < loop_ub; i17++) {
          v1->data[i17] = (int)stats->data[k].PixelIdxList->data[i17] - 1;
        }

        i17 = vk->size[0];
        vk->size[0] = v1->size[0];
        emxEnsureCapacity_int32_T(vk, i17);
        loop_ub = v1->size[0];
        for (i17 = 0; i17 < loop_ub; i17++) {
          vk->data[i17] = div_s32(v1->data[i17], (int)imageSize[0]);
        }

        i17 = v1->size[0];
        emxEnsureCapacity_int32_T(v1, i17);
        loop_ub = v1->size[0];
        for (i17 = 0; i17 < loop_ub; i17++) {
          v1->data[i17] -= vk->data[i17] * (int)imageSize[0];
        }

        i17 = i->size[0];
        i->size[0] = v1->size[0];
        emxEnsureCapacity_int32_T(i, i17);
        loop_ub = v1->size[0];
        for (i17 = 0; i17 < loop_ub; i17++) {
          i->data[i17] = v1->data[i17] + 1;
        }

        i17 = j->size[0];
        j->size[0] = vk->size[0];
        emxEnsureCapacity_int32_T(j, i17);
        loop_ub = vk->size[0];
        for (i17 = 0; i17 < loop_ub; i17++) {
          j->data[i17] = vk->data[i17] + 1;
        }

        loop_ub = j->size[0];
        unnamed_idx_1 = i->size[0];
        i17 = stats->data[k].PixelList->size[0] * stats->data[k].PixelList->
          size[1];
        stats->data[k].PixelList->size[1] = 2;
        stats->data[k].PixelList->size[0] = loop_ub;
        emxEnsureCapacity_real_T(stats->data[k].PixelList, i17);
        for (i17 = 0; i17 < loop_ub; i17++) {
          stats->data[k].PixelList->data[stats->data[k].PixelList->size[1] * i17]
            = j->data[i17];
        }

        for (i17 = 0; i17 < unnamed_idx_1; i17++) {
          stats->data[k].PixelList->data[1 + stats->data[k].PixelList->size[1] *
            i17] = i->data[i17];
        }
      } else {
        i17 = stats->data[k].PixelList->size[0] * stats->data[k].PixelList->
          size[1];
        stats->data[k].PixelList->size[1] = 2;
        stats->data[k].PixelList->size[0] = 0;
        emxEnsureCapacity_real_T(stats->data[k].PixelList, i17);
      }

      k++;
    }

    emxFree_int32_T(&vk);
    emxFree_int32_T(&v1);
    emxFree_int32_T(&j);
    emxFree_int32_T(&i);
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
  int i4;
  int loop_ub;
  emxInitStruct_struct_T2(&statsOneObj);
  statsAlreadyComputed->Area = false;
  statsOneObj.Area = 0.0;
  statsAlreadyComputed->Centroid = false;
  for (i4 = 0; i4 < 2; i4++) {
    statsOneObj.Centroid[i4] = 0.0;
  }

  statsAlreadyComputed->BoundingBox = false;
  for (i4 = 0; i4 < 4; i4++) {
    statsOneObj.BoundingBox[i4] = 0.0;
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
  i4 = statsOneObj.Image->size[0] * statsOneObj.Image->size[1];
  statsOneObj.Image->size[1] = 0;
  statsOneObj.Image->size[0] = 0;
  emxEnsureCapacity_boolean_T(statsOneObj.Image, i4);
  statsAlreadyComputed->FilledImage = false;
  i4 = statsOneObj.FilledImage->size[0] * statsOneObj.FilledImage->size[1];
  statsOneObj.FilledImage->size[1] = 0;
  statsOneObj.FilledImage->size[0] = 0;
  emxEnsureCapacity_boolean_T(statsOneObj.FilledImage, i4);
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
  i4 = statsOneObj.PixelIdxList->size[0];
  statsOneObj.PixelIdxList->size[0] = 0;
  emxEnsureCapacity_real_T1(statsOneObj.PixelIdxList, i4);
  statsAlreadyComputed->PixelList = false;
  i4 = statsOneObj.PixelList->size[0] * statsOneObj.PixelList->size[1];
  statsOneObj.PixelList->size[1] = 2;
  statsOneObj.PixelList->size[0] = 0;
  emxEnsureCapacity_real_T(statsOneObj.PixelList, i4);
  statsAlreadyComputed->Perimeter = false;
  statsOneObj.Perimeter = 0.0;
  statsAlreadyComputed->PixelValues = false;
  i4 = statsOneObj.PixelValues->size[0];
  statsOneObj.PixelValues->size[0] = 0;
  emxEnsureCapacity_real_T1(statsOneObj.PixelValues, i4);
  statsAlreadyComputed->WeightedCentroid = false;
  for (i4 = 0; i4 < 2; i4++) {
    statsOneObj.WeightedCentroid[i4] = 0.0;
  }

  statsAlreadyComputed->MeanIntensity = false;
  statsOneObj.MeanIntensity = 0.0;
  statsAlreadyComputed->MinIntensity = false;
  statsOneObj.MinIntensity = 0.0;
  statsAlreadyComputed->MaxIntensity = false;
  statsOneObj.MaxIntensity = 0.0;
  statsAlreadyComputed->SubarrayIdx = false;
  i4 = statsOneObj.SubarrayIdx->size[0] * statsOneObj.SubarrayIdx->size[1];
  statsOneObj.SubarrayIdx->size[1] = 0;
  statsOneObj.SubarrayIdx->size[0] = 1;
  emxEnsureCapacity_real_T(statsOneObj.SubarrayIdx, i4);
  for (i4 = 0; i4 < 2; i4++) {
    statsOneObj.SubarrayIdxLengths[i4] = 0.0;
  }

  i4 = stats->size[0];
  stats->size[0] = (int)numObjs;
  emxEnsureCapacity_struct_T3(stats, i4);
  loop_ub = (int)numObjs;
  for (i4 = 0; i4 < loop_ub; i4++) {
    emxCopyStruct_struct_T2(&stats->data[i4], &statsOneObj);
  }

  emxFreeStruct_struct_T2(&statsOneObj);
}

/*
 * Arguments    : b_emxArray_struct_T *outstats
 *                const c_emxArray_struct_T *stats
 * Return Type  : void
 */
static void populateOutputStatsStructure(b_emxArray_struct_T *outstats, const
  c_emxArray_struct_T *stats)
{
  int k;
  int stats_idx_0;
  int i20;
  int b_stats[2];
  int i21;
  int c_stats[2];
  int b_outstats[2];
  for (k = 0; k < stats->size[0]; k++) {
    outstats->data[k].Orientation = stats->data[k].Orientation;
    outstats->data[k].Eccentricity = stats->data[k].Eccentricity;
    outstats->data[k].Area = stats->data[k].Area;
    stats_idx_0 = stats->data[k].PixelIdxList->size[0];
    i20 = outstats->data[k].PixelIdxList->size[0];
    outstats->data[k].PixelIdxList->size[0] = stats_idx_0;
    emxEnsureCapacity_real_T1(outstats->data[k].PixelIdxList, i20);
    i20 = outstats->data[k].PixelIdxList->size[0];
    for (stats_idx_0 = 0; stats_idx_0 < i20; stats_idx_0++) {
      b_stats[0] = stats->data[k].PixelIdxList->size[0];
      b_stats[1] = 1;
      for (i21 = 0; i21 < 2; i21++) {
        c_stats[i21] = b_stats[1 - i21];
      }

      b_stats[0] = outstats->data[k].PixelIdxList->size[0];
      b_stats[1] = 1;
      for (i21 = 0; i21 < 2; i21++) {
        b_outstats[i21] = b_stats[1 - i21];
      }

      outstats->data[k].PixelIdxList->data[b_outstats[0] * stats_idx_0] =
        stats->data[k].PixelIdxList->data[c_stats[0] * stats_idx_0];
    }
  }
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
  int i7;
  int loop_ub;
  c_emxArray_struct_T *stats;
  struct_T statsAlreadyComputed;
  int uIdx;
  int b_stats[2];
  int i8;
  unsigned int b_outstats[2];
  int c_stats[2];
  emxInit_real_T1(&CC_RegionIndices, 1);
  emxInit_int32_T(&CC_RegionLengths, 1);
  emxInitStruct_struct_T(&statsOneObj);
  bwconncomp(varargin_1, &expl_temp, CC_ImageSize, &CC_NumObjects,
             CC_RegionIndices, CC_RegionLengths);
  statsOneObj.Area = 0.0;
  statsOneObj.Eccentricity = 0.0;
  i7 = statsOneObj.PixelIdxList->size[0];
  statsOneObj.PixelIdxList->size[0] = 0;
  emxEnsureCapacity_real_T1(statsOneObj.PixelIdxList, i7);
  i7 = outstats->size[0];
  outstats->size[0] = (int)CC_NumObjects;
  emxEnsureCapacity_struct_T(outstats, i7);
  loop_ub = (int)CC_NumObjects;
  for (i7 = 0; i7 < loop_ub; i7++) {
    emxCopyStruct_struct_T(&outstats->data[i7], &statsOneObj);
  }

  emxFreeStruct_struct_T(&statsOneObj);
  emxInit_struct_T3(&stats, 1);
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
    i7 = outstats->data[loop_ub].PixelIdxList->size[0];
    outstats->data[loop_ub].PixelIdxList->size[0] = stats->data[loop_ub].
      PixelIdxList->size[0];
    emxEnsureCapacity_real_T1(outstats->data[loop_ub].PixelIdxList, i7);
    i7 = outstats->data[loop_ub].PixelIdxList->size[0];
    for (uIdx = 0; uIdx < i7; uIdx++) {
      b_stats[0] = stats->data[loop_ub].PixelIdxList->size[0];
      b_stats[1] = 1;
      for (i8 = 0; i8 < 2; i8++) {
        c_stats[i8] = b_stats[1 - i8];
      }

      b_outstats[0] = (unsigned int)outstats->data[loop_ub].PixelIdxList->size[0];
      b_outstats[1] = 1U;
      for (i8 = 0; i8 < 2; i8++) {
        b_stats[i8] = (int)b_outstats[1 - i8];
      }

      outstats->data[loop_ub].PixelIdxList->data[b_stats[0] * uIdx] =
        stats->data[loop_ub].PixelIdxList->data[c_stats[0] * uIdx];
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
  c_emxArray_struct_T *stats;
  c_struct_T statsOneObj;
  double expl_temp;
  double CC_ImageSize[2];
  double CC_NumObjects;
  int i3;
  struct_T statsAlreadyComputed;
  int loop_ub;
  emxInit_real_T1(&CC_RegionIndices, 1);
  emxInit_int32_T(&CC_RegionLengths, 1);
  emxInit_struct_T3(&stats, 1);
  emxInitStruct_struct_T1(&statsOneObj);
  bwconncomp(varargin_2, &expl_temp, CC_ImageSize, &CC_NumObjects,
             CC_RegionIndices, CC_RegionLengths);
  statsOneObj.Orientation = 0.0;
  statsOneObj.Eccentricity = 0.0;
  statsOneObj.Area = 0.0;
  i3 = statsOneObj.PixelIdxList->size[0];
  statsOneObj.PixelIdxList->size[0] = 0;
  emxEnsureCapacity_real_T1(statsOneObj.PixelIdxList, i3);
  initializeStatsStruct(CC_NumObjects, stats, &statsAlreadyComputed);
  ComputePixelIdxList(CC_RegionIndices, CC_RegionLengths, CC_NumObjects, stats,
                      &statsAlreadyComputed);
  ComputeEllipseParams(CC_ImageSize, stats, &statsAlreadyComputed);
  ComputeEllipseParams(CC_ImageSize, stats, &statsAlreadyComputed);
  ComputeArea(stats, &statsAlreadyComputed);
  i3 = outstats->size[0];
  outstats->size[0] = (int)CC_NumObjects;
  emxEnsureCapacity_struct_T2(outstats, i3);
  loop_ub = (int)CC_NumObjects;
  emxFree_int32_T(&CC_RegionLengths);
  emxFree_real_T(&CC_RegionIndices);
  for (i3 = 0; i3 < loop_ub; i3++) {
    emxCopyStruct_struct_T1(&outstats->data[i3], &statsOneObj);
  }

  emxFreeStruct_struct_T1(&statsOneObj);
  populateOutputStatsStructure(outstats, stats);
  emxFree_struct_T2(&stats);
}

/*
 * File trailer for regionprops.c
 *
 * [EOF]
 */
