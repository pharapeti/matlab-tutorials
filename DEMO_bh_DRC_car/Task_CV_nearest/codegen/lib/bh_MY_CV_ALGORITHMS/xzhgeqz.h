/*
 * File: xzhgeqz.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef XZHGEQZ_H
#define XZHGEQZ_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "bh_MY_CV_ALGORITHMS_types.h"

/* Function Declarations */
extern void xzhgeqz(creal_T A[9], creal_T B[9], int ilo, int ihi, creal_T Z[9],
                    int *info, creal_T alpha1[3], creal_T beta1[3]);

#endif

/*
 * File trailer for xzhgeqz.h
 *
 * [EOF]
 */
