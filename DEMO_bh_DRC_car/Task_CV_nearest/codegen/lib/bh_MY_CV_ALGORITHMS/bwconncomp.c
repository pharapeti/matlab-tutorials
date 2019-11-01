/*
 * File: bwconncomp.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "bwconncomp.h"
#include "bh_MY_CV_ALGORITHMS_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_boolean_T *varargin_1
 *                double *CC_Connectivity
 *                double CC_ImageSize[2]
 *                double *CC_NumObjects
 *                emxArray_real_T *CC_RegionIndices
 *                emxArray_int32_T *CC_RegionLengths
 * Return Type  : void
 */
void bwconncomp(const emxArray_boolean_T *varargin_1, double *CC_Connectivity,
                double CC_ImageSize[2], double *CC_NumObjects, emxArray_real_T
                *CC_RegionIndices, emxArray_int32_T *CC_RegionLengths)
{
  int numRuns;
  int firstRunOnPreviousColumn;
  int lastRunOnPreviousColumn;
  emxArray_int32_T *regionLengths;
  int offset;
  emxArray_int32_T *startRow;
  emxArray_int32_T *endRow;
  emxArray_int32_T *startCol;
  int row;
  int k;
  int runCounter;
  double numComponents;
  emxArray_int32_T *labelsRenumbered;
  int p;
  int root_k;
  int root_p;
  double y;
  emxArray_real_T *pixelIdxList;
  emxArray_int32_T *x;
  emxArray_int32_T *idxCount;
  numRuns = 0;
  firstRunOnPreviousColumn = varargin_1->size[0];
  for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < 320;
       lastRunOnPreviousColumn++) {
    offset = lastRunOnPreviousColumn * firstRunOnPreviousColumn;
    if (varargin_1->data[offset]) {
      numRuns++;
    }

    row = (firstRunOnPreviousColumn + offset) - offset;
    for (k = 0; k <= row - 2; k++) {
      runCounter = offset + k;
      if (varargin_1->data[runCounter + 1] && (!varargin_1->data[runCounter])) {
        numRuns++;
      }
    }
  }

  emxInit_int32_T(&regionLengths, 1);
  emxInit_int32_T(&startRow, 1);
  emxInit_int32_T(&endRow, 1);
  emxInit_int32_T(&startCol, 1);
  if (numRuns == 0) {
    row = startRow->size[0];
    startRow->size[0] = 0;
    emxEnsureCapacity_int32_T(startRow, row);
    row = endRow->size[0];
    endRow->size[0] = 0;
    emxEnsureCapacity_int32_T(endRow, row);
    row = startCol->size[0];
    startCol->size[0] = 0;
    emxEnsureCapacity_int32_T(startCol, row);
    row = regionLengths->size[0];
    regionLengths->size[0] = 0;
    emxEnsureCapacity_int32_T(regionLengths, row);
    for (row = 0; row < 2; row++) {
      CC_ImageSize[row] = varargin_1->size[row];
    }

    numComponents = 0.0;
    row = CC_RegionIndices->size[0];
    CC_RegionIndices->size[0] = 0;
    emxEnsureCapacity_real_T1(CC_RegionIndices, row);
    row = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = 1;
    emxEnsureCapacity_int32_T(CC_RegionLengths, row);
    CC_RegionLengths->data[0] = 0;
  } else {
    row = startRow->size[0];
    startRow->size[0] = numRuns;
    emxEnsureCapacity_int32_T(startRow, row);
    row = endRow->size[0];
    endRow->size[0] = numRuns;
    emxEnsureCapacity_int32_T(endRow, row);
    row = startCol->size[0];
    startCol->size[0] = numRuns;
    emxEnsureCapacity_int32_T(startCol, row);
    firstRunOnPreviousColumn = varargin_1->size[0];
    runCounter = 0;
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < 320;
         lastRunOnPreviousColumn++) {
      offset = lastRunOnPreviousColumn * firstRunOnPreviousColumn - 1;
      row = 1;
      while (row <= firstRunOnPreviousColumn) {
        while ((row <= firstRunOnPreviousColumn) && (!varargin_1->data[row +
                offset])) {
          row++;
        }

        if ((row <= firstRunOnPreviousColumn) && varargin_1->data[row + offset])
        {
          startCol->data[runCounter] = lastRunOnPreviousColumn + 1;
          startRow->data[runCounter] = row;
          while ((row <= firstRunOnPreviousColumn) && varargin_1->data[row +
                 offset]) {
            row++;
          }

          endRow->data[runCounter] = row - 1;
          runCounter++;
        }
      }
    }

    row = regionLengths->size[0];
    regionLengths->size[0] = numRuns;
    emxEnsureCapacity_int32_T(regionLengths, row);
    for (row = 0; row < numRuns; row++) {
      regionLengths->data[row] = 0;
    }

    k = 0;
    runCounter = 1;
    row = 1;
    firstRunOnPreviousColumn = -1;
    lastRunOnPreviousColumn = -1;
    offset = 0;
    while (k + 1 <= numRuns) {
      if (startCol->data[k] == runCounter + 1) {
        firstRunOnPreviousColumn = offset + 1;
        offset = k;
        lastRunOnPreviousColumn = k;
        runCounter = startCol->data[k];
      } else {
        if (startCol->data[k] > runCounter + 1) {
          firstRunOnPreviousColumn = -1;
          lastRunOnPreviousColumn = -1;
          offset = k;
          runCounter = startCol->data[k];
        }
      }

      if (firstRunOnPreviousColumn >= 0) {
        for (p = firstRunOnPreviousColumn - 1; p + 1 <= lastRunOnPreviousColumn;
             p++) {
          if ((endRow->data[k] >= startRow->data[p] - 1) && (startRow->data[k] <=
               endRow->data[p] + 1)) {
            if (regionLengths->data[k] == 0) {
              regionLengths->data[k] = regionLengths->data[p];
              row++;
            } else {
              if (regionLengths->data[k] != regionLengths->data[p]) {
                for (root_k = k; root_k + 1 != regionLengths->data[root_k];
                     root_k = regionLengths->data[root_k] - 1) {
                  regionLengths->data[root_k] = regionLengths->
                    data[regionLengths->data[root_k] - 1];
                }

                for (root_p = p; root_p + 1 != regionLengths->data[root_p];
                     root_p = regionLengths->data[root_p] - 1) {
                  regionLengths->data[root_p] = regionLengths->
                    data[regionLengths->data[root_p] - 1];
                }

                if (root_k + 1 != root_p + 1) {
                  if (root_p + 1 < root_k + 1) {
                    regionLengths->data[root_k] = root_p + 1;
                    regionLengths->data[k] = root_p + 1;
                  } else {
                    regionLengths->data[root_p] = root_k + 1;
                    regionLengths->data[p] = root_k + 1;
                  }
                }
              }
            }
          }
        }
      }

      if (regionLengths->data[k] == 0) {
        regionLengths->data[k] = row;
        row++;
      }

      k++;
    }

    emxInit_int32_T(&labelsRenumbered, 1);
    row = labelsRenumbered->size[0];
    labelsRenumbered->size[0] = regionLengths->size[0];
    emxEnsureCapacity_int32_T(labelsRenumbered, row);
    numComponents = 0.0;
    for (k = 0; k + 1 <= numRuns; k++) {
      if (regionLengths->data[k] == k + 1) {
        numComponents++;
        labelsRenumbered->data[k] = (int)numComponents;
      }

      labelsRenumbered->data[k] = labelsRenumbered->data[regionLengths->data[k]
        - 1];
    }

    row = regionLengths->size[0];
    regionLengths->size[0] = (int)numComponents;
    emxEnsureCapacity_int32_T(regionLengths, row);
    runCounter = (int)numComponents;
    for (row = 0; row < runCounter; row++) {
      regionLengths->data[row] = 0;
    }

    for (k = 0; k + 1 <= numRuns; k++) {
      if (labelsRenumbered->data[k] > 0) {
        regionLengths->data[labelsRenumbered->data[k] - 1] =
          ((regionLengths->data[labelsRenumbered->data[k] - 1] + endRow->data[k])
           - startRow->data[k]) + 1;
      }
    }

    if (regionLengths->size[0] == 0) {
      y = 0.0;
    } else {
      y = regionLengths->data[0];
      for (k = 2; k <= regionLengths->size[0]; k++) {
        y += (double)regionLengths->data[k - 1];
      }
    }

    emxInit_real_T1(&pixelIdxList, 1);
    emxInit_int32_T(&x, 1);
    row = pixelIdxList->size[0];
    pixelIdxList->size[0] = (int)y;
    emxEnsureCapacity_real_T1(pixelIdxList, row);
    row = x->size[0];
    x->size[0] = regionLengths->size[0];
    emxEnsureCapacity_int32_T(x, row);
    runCounter = regionLengths->size[0];
    for (row = 0; row < runCounter; row++) {
      x->data[row] = regionLengths->data[row];
    }

    runCounter = 2;
    if (regionLengths->size[0] != 1) {
      runCounter = 1;
    }

    if (runCounter <= 1) {
      row = regionLengths->size[0];
    } else {
      row = 1;
    }

    if ((!(regionLengths->size[0] == 0)) && (row > 1)) {
      firstRunOnPreviousColumn = 1;
      k = 1;
      while (k <= runCounter - 1) {
        firstRunOnPreviousColumn *= regionLengths->size[0];
        k = 2;
      }

      for (runCounter = 0; runCounter + 1 <= firstRunOnPreviousColumn;
           runCounter++) {
        for (k = 1; k < row; k++) {
          x->data[runCounter + k * firstRunOnPreviousColumn] += x->
            data[runCounter + (k - 1) * firstRunOnPreviousColumn];
        }
      }
    }

    emxInit_int32_T(&idxCount, 1);
    row = idxCount->size[0];
    idxCount->size[0] = 1 + x->size[0];
    emxEnsureCapacity_int32_T(idxCount, row);
    idxCount->data[0] = 0;
    runCounter = x->size[0];
    for (row = 0; row < runCounter; row++) {
      idxCount->data[row + 1] = x->data[row];
    }

    emxFree_int32_T(&x);
    for (k = 0; k + 1 <= numRuns; k++) {
      runCounter = (startCol->data[k] - 1) * varargin_1->size[0];
      row = labelsRenumbered->data[k] - 1;
      if (labelsRenumbered->data[k] > 0) {
        for (firstRunOnPreviousColumn = startRow->data[k];
             firstRunOnPreviousColumn <= endRow->data[k];
             firstRunOnPreviousColumn++) {
          idxCount->data[row]++;
          pixelIdxList->data[idxCount->data[row] - 1] = firstRunOnPreviousColumn
            + runCounter;
        }
      }
    }

    emxFree_int32_T(&idxCount);
    emxFree_int32_T(&labelsRenumbered);
    for (row = 0; row < 2; row++) {
      CC_ImageSize[row] = varargin_1->size[row];
    }

    row = CC_RegionIndices->size[0];
    CC_RegionIndices->size[0] = pixelIdxList->size[0];
    emxEnsureCapacity_real_T1(CC_RegionIndices, row);
    runCounter = pixelIdxList->size[0];
    for (row = 0; row < runCounter; row++) {
      CC_RegionIndices->data[row] = pixelIdxList->data[row];
    }

    emxFree_real_T(&pixelIdxList);
    row = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = regionLengths->size[0];
    emxEnsureCapacity_int32_T(CC_RegionLengths, row);
    runCounter = regionLengths->size[0];
    for (row = 0; row < runCounter; row++) {
      CC_RegionLengths->data[row] = regionLengths->data[row];
    }
  }

  emxFree_int32_T(&startCol);
  emxFree_int32_T(&endRow);
  emxFree_int32_T(&startRow);
  emxFree_int32_T(&regionLengths);
  *CC_Connectivity = 8.0;
  *CC_NumObjects = numComponents;
}

/*
 * File trailer for bwconncomp.c
 *
 * [EOF]
 */
