/*
 * File: my_laneKF_CLS.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef MY_LANEKF_CLS_H
#define MY_LANEKF_CLS_H

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
extern void my_laneKF_CLS_pred_and_correct(my_laneKF_CLS *OBJ, const boolean_T
  BW[76800], boolean_T tf_found);

#endif

/*
 * File trailer for my_laneKF_CLS.h
 *
 * [EOF]
 */
