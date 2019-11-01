/*
 * File: bwconncomp.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bwconncomp.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"

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
  int lastRunOnPreviousColumn;
  emxArray_int32_T *regionLengths;
  emxArray_int32_T *startRow;
  emxArray_int32_T *endRow;
  int k;
  emxArray_int32_T *startCol;
  int currentColumn;
  int runCounter;
  int row;
  double numComponents;
  int firstRunOnThisColumn;
  emxArray_int32_T *labelsRenumbered;
  int p;
  int root_k;
  int root_p;
  unsigned int b_regionLengths[2];
  double y;
  unsigned int c_regionLengths[2];
  emxArray_real_T *pixelIdxList;
  emxArray_int32_T *x;
  int d_regionLengths[2];
  int e_regionLengths[2];
  emxArray_int32_T *idxCount;
  numRuns = 0;
  for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < 320;
       lastRunOnPreviousColumn++) {
    if (varargin_1->data[lastRunOnPreviousColumn]) {
      numRuns++;
    }

    for (k = 0; k <= varargin_1->size[0] - 2; k++) {
      if (varargin_1->data[lastRunOnPreviousColumn + varargin_1->size[1] * (1 +
           k)] && (!varargin_1->data[lastRunOnPreviousColumn + varargin_1->size
                   [1] * k])) {
        numRuns++;
      }
    }
  }

  emxInit_int32_T(&regionLengths, 1);
  emxInit_int32_T(&startRow, 1);
  emxInit_int32_T(&endRow, 1);
  emxInit_int32_T(&startCol, 1);
  if (numRuns == 0) {
    lastRunOnPreviousColumn = startRow->size[0];
    startRow->size[0] = 0;
    emxEnsureCapacity_int32_T(startRow, lastRunOnPreviousColumn);
    lastRunOnPreviousColumn = endRow->size[0];
    endRow->size[0] = 0;
    emxEnsureCapacity_int32_T(endRow, lastRunOnPreviousColumn);
    lastRunOnPreviousColumn = startCol->size[0];
    startCol->size[0] = 0;
    emxEnsureCapacity_int32_T(startCol, lastRunOnPreviousColumn);
    lastRunOnPreviousColumn = regionLengths->size[0];
    regionLengths->size[0] = 0;
    emxEnsureCapacity_int32_T(regionLengths, lastRunOnPreviousColumn);
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < 2;
         lastRunOnPreviousColumn++) {
      CC_ImageSize[lastRunOnPreviousColumn] = varargin_1->
        size[lastRunOnPreviousColumn];
    }

    numComponents = 0.0;
    lastRunOnPreviousColumn = CC_RegionIndices->size[0];
    CC_RegionIndices->size[0] = 0;
    emxEnsureCapacity_real_T1(CC_RegionIndices, lastRunOnPreviousColumn);
    lastRunOnPreviousColumn = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = 1;
    emxEnsureCapacity_int32_T(CC_RegionLengths, lastRunOnPreviousColumn);
    CC_RegionLengths->data[0] = 0;
  } else {
    lastRunOnPreviousColumn = startRow->size[0];
    startRow->size[0] = numRuns;
    emxEnsureCapacity_int32_T(startRow, lastRunOnPreviousColumn);
    lastRunOnPreviousColumn = endRow->size[0];
    endRow->size[0] = numRuns;
    emxEnsureCapacity_int32_T(endRow, lastRunOnPreviousColumn);
    lastRunOnPreviousColumn = startCol->size[0];
    startCol->size[0] = numRuns;
    emxEnsureCapacity_int32_T(startCol, lastRunOnPreviousColumn);
    currentColumn = varargin_1->size[0];
    runCounter = 0;
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < 320;
         lastRunOnPreviousColumn++) {
      row = 1;
      while (row <= currentColumn) {
        while ((row <= currentColumn) && (!varargin_1->
                data[lastRunOnPreviousColumn + varargin_1->size[1] * (row - 1)]))
        {
          row++;
        }

        if ((row <= currentColumn) && varargin_1->data[lastRunOnPreviousColumn +
            varargin_1->size[1] * (row - 1)]) {
          startCol->data[runCounter] = lastRunOnPreviousColumn + 1;
          startRow->data[runCounter] = row;
          while ((row <= currentColumn) && varargin_1->
                 data[lastRunOnPreviousColumn + varargin_1->size[1] * (row - 1)])
          {
            row++;
          }

          endRow->data[runCounter] = row - 1;
          runCounter++;
        }
      }
    }

    lastRunOnPreviousColumn = regionLengths->size[0];
    regionLengths->size[0] = numRuns;
    emxEnsureCapacity_int32_T(regionLengths, lastRunOnPreviousColumn);
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < numRuns;
         lastRunOnPreviousColumn++) {
      regionLengths->data[lastRunOnPreviousColumn] = 0;
    }

    k = 0;
    currentColumn = 1;
    runCounter = 1;
    row = -1;
    lastRunOnPreviousColumn = -1;
    firstRunOnThisColumn = 0;
    while (k + 1 <= numRuns) {
      if (startCol->data[k] == currentColumn + 1) {
        row = firstRunOnThisColumn + 1;
        firstRunOnThisColumn = k;
        lastRunOnPreviousColumn = k;
        currentColumn = startCol->data[k];
      } else {
        if (startCol->data[k] > currentColumn + 1) {
          row = -1;
          lastRunOnPreviousColumn = -1;
          firstRunOnThisColumn = k;
          currentColumn = startCol->data[k];
        }
      }

      if (row >= 0) {
        for (p = row - 1; p < lastRunOnPreviousColumn; p++) {
          if ((endRow->data[k] >= startRow->data[p] - 1) && (startRow->data[k] <=
               endRow->data[p] + 1)) {
            if (regionLengths->data[k] == 0) {
              regionLengths->data[k] = regionLengths->data[p];
              runCounter++;
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
        regionLengths->data[k] = runCounter;
        runCounter++;
      }

      k++;
    }

    emxInit_int32_T(&labelsRenumbered, 1);
    lastRunOnPreviousColumn = labelsRenumbered->size[0];
    labelsRenumbered->size[0] = regionLengths->size[0];
    emxEnsureCapacity_int32_T(labelsRenumbered, lastRunOnPreviousColumn);
    numComponents = 0.0;
    for (k = 0; k < numRuns; k++) {
      if (regionLengths->data[k] == k + 1) {
        numComponents++;
        labelsRenumbered->data[k] = (int)numComponents;
      }

      labelsRenumbered->data[k] = labelsRenumbered->data[regionLengths->data[k]
        - 1];
    }

    lastRunOnPreviousColumn = regionLengths->size[0];
    regionLengths->size[0] = (int)numComponents;
    emxEnsureCapacity_int32_T(regionLengths, lastRunOnPreviousColumn);
    currentColumn = (int)numComponents;
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < currentColumn;
         lastRunOnPreviousColumn++) {
      regionLengths->data[lastRunOnPreviousColumn] = 0;
    }

    for (k = 0; k < numRuns; k++) {
      if (labelsRenumbered->data[k] > 0) {
        b_regionLengths[0] = (unsigned int)regionLengths->size[0];
        b_regionLengths[1] = 1U;
        c_regionLengths[0] = (unsigned int)regionLengths->size[0];
        c_regionLengths[1] = 1U;
        for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < 2;
             lastRunOnPreviousColumn++) {
          e_regionLengths[lastRunOnPreviousColumn] = (int)b_regionLengths[1 -
            lastRunOnPreviousColumn];
          d_regionLengths[lastRunOnPreviousColumn] = (int)c_regionLengths[1 -
            lastRunOnPreviousColumn];
        }

        regionLengths->data[d_regionLengths[0] * (labelsRenumbered->data[k] - 1)]
          = ((regionLengths->data[e_regionLengths[0] * (labelsRenumbered->data[k]
               - 1)] + endRow->data[k]) - startRow->data[k]) + 1;
      }
    }

    currentColumn = regionLengths->size[0];
    if (regionLengths->size[0] == 0) {
      y = 0.0;
    } else {
      y = regionLengths->data[0];
      for (k = 2; k <= currentColumn; k++) {
        if (currentColumn >= 2) {
          b_regionLengths[0] = (unsigned int)regionLengths->size[0];
          b_regionLengths[1] = 1U;
          for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < 2;
               lastRunOnPreviousColumn++) {
            e_regionLengths[lastRunOnPreviousColumn] = (int)b_regionLengths[1 -
              lastRunOnPreviousColumn];
          }

          y += (double)regionLengths->data[e_regionLengths[0] * (k - 1)];
        }
      }
    }

    emxInit_real_T1(&pixelIdxList, 1);
    emxInit_int32_T(&x, 1);
    lastRunOnPreviousColumn = pixelIdxList->size[0];
    pixelIdxList->size[0] = (int)y;
    emxEnsureCapacity_real_T1(pixelIdxList, lastRunOnPreviousColumn);
    lastRunOnPreviousColumn = x->size[0];
    x->size[0] = regionLengths->size[0];
    emxEnsureCapacity_int32_T(x, lastRunOnPreviousColumn);
    currentColumn = regionLengths->size[0];
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < currentColumn;
         lastRunOnPreviousColumn++) {
      x->data[lastRunOnPreviousColumn] = regionLengths->
        data[lastRunOnPreviousColumn];
    }

    currentColumn = 2;
    if (regionLengths->size[0] != 1) {
      currentColumn = 1;
    }

    if ((1 == currentColumn) && (regionLengths->size[0] != 0) &&
        (regionLengths->size[0] != 1)) {
      for (k = 1; k < regionLengths->size[0]; k++) {
        x->data[k] += x->data[k - 1];
      }
    }

    emxInit_int32_T(&idxCount, 1);
    lastRunOnPreviousColumn = idxCount->size[0];
    idxCount->size[0] = 1 + x->size[0];
    emxEnsureCapacity_int32_T(idxCount, lastRunOnPreviousColumn);
    idxCount->data[0] = 0;
    currentColumn = x->size[0];
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < currentColumn;
         lastRunOnPreviousColumn++) {
      idxCount->data[lastRunOnPreviousColumn + 1] = x->
        data[lastRunOnPreviousColumn];
    }

    emxFree_int32_T(&x);
    for (k = 0; k < numRuns; k++) {
      currentColumn = (startCol->data[k] - 1) * varargin_1->size[0];
      runCounter = labelsRenumbered->data[k] - 1;
      if (labelsRenumbered->data[k] > 0) {
        for (row = startRow->data[k]; row <= endRow->data[k]; row++) {
          idxCount->data[runCounter]++;
          b_regionLengths[0] = (unsigned int)pixelIdxList->size[0];
          b_regionLengths[1] = 1U;
          for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < 2;
               lastRunOnPreviousColumn++) {
            e_regionLengths[lastRunOnPreviousColumn] = (int)b_regionLengths[1 -
              lastRunOnPreviousColumn];
          }

          pixelIdxList->data[e_regionLengths[0] * (idxCount->data[runCounter] -
            1)] = row + currentColumn;
        }
      }
    }

    emxFree_int32_T(&idxCount);
    emxFree_int32_T(&labelsRenumbered);
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < 2;
         lastRunOnPreviousColumn++) {
      CC_ImageSize[lastRunOnPreviousColumn] = varargin_1->
        size[lastRunOnPreviousColumn];
    }

    lastRunOnPreviousColumn = CC_RegionIndices->size[0];
    CC_RegionIndices->size[0] = pixelIdxList->size[0];
    emxEnsureCapacity_real_T1(CC_RegionIndices, lastRunOnPreviousColumn);
    currentColumn = pixelIdxList->size[0];
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < currentColumn;
         lastRunOnPreviousColumn++) {
      CC_RegionIndices->data[lastRunOnPreviousColumn] = pixelIdxList->
        data[lastRunOnPreviousColumn];
    }

    emxFree_real_T(&pixelIdxList);
    lastRunOnPreviousColumn = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = regionLengths->size[0];
    emxEnsureCapacity_int32_T(CC_RegionLengths, lastRunOnPreviousColumn);
    currentColumn = regionLengths->size[0];
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < currentColumn;
         lastRunOnPreviousColumn++) {
      CC_RegionLengths->data[lastRunOnPreviousColumn] = regionLengths->
        data[lastRunOnPreviousColumn];
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
