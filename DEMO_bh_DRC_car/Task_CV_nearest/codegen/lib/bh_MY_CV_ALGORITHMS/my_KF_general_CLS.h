/*
 * File: my_KF_general_CLS.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef MY_KF_GENERAL_CLS_H
#define MY_KF_GENERAL_CLS_H

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
extern void my_KF_general_CLS_correct(my_KF_general_CLS *OBJ, const double
  y_data[]);
extern void my_KF_general_CLS_predict(my_KF_general_CLS *OBJ);

#endif

/*
 * File trailer for my_KF_general_CLS.h
 *
 * [EOF]
 */
