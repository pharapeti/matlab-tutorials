/*
 * File: power.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "power.h"
#include "regionprops.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "bh_my_detect_ALGORITHM_for_codegen_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *a
 *                emxArray_real_T *y
 * Return Type  : void
 */
void b_power(const emxArray_real_T *a, emxArray_real_T *y)
{
  unsigned int a_idx_0;
  int i5;
  int k;
  unsigned int b_a[2];
  int c_a[2];
  int b_y[2];
  a_idx_0 = (unsigned int)a->size[0];
  i5 = y->size[0];
  y->size[0] = (int)a_idx_0;
  emxEnsureCapacity_real_T1(y, i5);
  a_idx_0 = (unsigned int)a->size[0];
  for (k = 1; k <= (int)a_idx_0; k++) {
    b_a[0] = (unsigned int)a->size[0];
    b_a[1] = 1U;
    for (i5 = 0; i5 < 2; i5++) {
      c_a[i5] = (int)b_a[1 - i5];
    }

    b_a[0] = (unsigned int)y->size[0];
    b_a[1] = 1U;
    for (i5 = 0; i5 < 2; i5++) {
      b_y[i5] = (int)b_a[1 - i5];
    }

    y->data[b_y[0] * (k - 1)] = rt_powd_snf(a->data[c_a[0] * (k - 1)], 2.0);
  }
}

/*
 * Arguments    : const emxArray_real_T *a
 *                emxArray_real_T *y
 * Return Type  : void
 */
void power(const emxArray_real_T *a, emxArray_real_T *y)
{
  short b_a[2];
  int k;
  short a_idx_0;
  short iv1[2];
  int b_k;
  b_a[0] = (short)a->size[0];
  b_a[1] = 320;
  for (k = 0; k < 2; k++) {
    iv1[k] = b_a[k];
  }

  a_idx_0 = (short)a->size[0];
  k = y->size[0] * y->size[1];
  y->size[1] = 320;
  y->size[0] = a_idx_0;
  emxEnsureCapacity_real_T(y, k);
  for (k = 1; k <= iv1[0]; k++) {
    for (b_k = 0; b_k < 320; b_k++) {
      y->data[b_k + y->size[1] * (k - 1)] = rt_powd_snf(a->data[b_k + a->size[1]
        * (k - 1)], 2.0);
    }
  }
}

/*
 * File trailer for power.c
 *
 * [EOF]
 */
