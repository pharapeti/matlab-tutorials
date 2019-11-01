/*
 * File: combineVectorElements.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "combineVectorElements.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double combineVectorElements(const emxArray_real_T *x)
{
  double y;
  int vlen;
  int k;
  unsigned int b_x[2];
  int i6;
  int c_x[2];
  vlen = x->size[0];
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= vlen; k++) {
      if (vlen >= 2) {
        b_x[0] = (unsigned int)x->size[0];
        b_x[1] = 1U;
        for (i6 = 0; i6 < 2; i6++) {
          c_x[i6] = (int)b_x[1 - i6];
        }

        y += x->data[c_x[0] * (k - 1)];
      }
    }
  }

  return y;
}

/*
 * File trailer for combineVectorElements.c
 *
 * [EOF]
 */
