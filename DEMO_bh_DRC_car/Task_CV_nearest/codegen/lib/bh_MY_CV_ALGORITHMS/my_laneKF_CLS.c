/*
 * File: my_laneKF_CLS.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "my_laneKF_CLS.h"
#include "my_KF_general_CLS.h"
#include "lane_info_CLS.h"

/* Function Definitions */

/*
 * function  OBJ = pred_and_correct(OBJ, BW, tf_found)
 * use KF to PREDICT
 * Arguments    : my_laneKF_CLS *OBJ
 *                const boolean_T BW[76800]
 *                boolean_T tf_found
 * Return Type  : void
 */
void my_laneKF_CLS_pred_and_correct(my_laneKF_CLS *OBJ, const boolean_T BW[76800],
  boolean_T tf_found)
{
  lane_info_CLS_1 lane_O;
  int i27;
  double m_data[1];
  int m_size[2];
  double c_data[1];
  int c_size[2];
  int loop_ub;
  double b_m_data[2];

  /*  my_laneKF_CLS() */
  /* --------------------------------------------------------------------------  */
  /* 'my_laneKF_CLS:60' OBJ.KF     = OBJ.KF.predict(); */
  my_KF_general_CLS_predict(&OBJ->KF);

  /*  now do we have a measurement to allow a CORRECT */
  /* 'my_laneKF_CLS:63' lane_O = lane_info_CLS(BW, tf_found); */
  b_lane_info_CLS_lane_info_CLS(BW, tf_found, &lane_O);

  /* 'my_laneKF_CLS:64' if( lane_O.is_detected() ) */
  /* --------------------------------------------------------------------------   */
  /* 'lane_info_CLS:34' tf_detected = OBJ.tf_is_detected; */
  if (lane_O.tf_is_detected) {
    /* 'my_laneKF_CLS:65' lane_O = lane_O.calc_info(); */
    lane_info_CLS_calc_info(&lane_O);

    /* 'my_laneKF_CLS:67' [m,c]  = lane_O.get_mc(); */
    lane_info_CLS_get_mc(lane_O.m, lane_O.c, lane_O.tf_is_detected, m_data,
                         m_size, c_data, c_size);

    /* 'my_laneKF_CLS:69' y_meas = [m;c]; */
    /* 'my_laneKF_CLS:71' OBJ.KF = OBJ.KF.correct(y_meas); */
    loop_ub = m_size[1];
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_m_data[i27 << 1] = m_data[m_size[0] * i27];
    }

    loop_ub = c_size[1];
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_m_data[1 + (i27 << 1)] = c_data[c_size[0] * i27];
    }

    my_KF_general_CLS_correct(&OBJ->KF, b_m_data);
  }

  /* 'my_laneKF_CLS:74' OBJ.mc_col    = OBJ.KF.x; */
  for (i27 = 0; i27 < 2; i27++) {
    OBJ->mc_col[i27] = OBJ->KF.x[i27];
  }

  /* OBJ.x_col_mat = [OBJ.x_col_mat, OBJ.mc_col]; */
  /*  and store the size of the image we're processing */
  /* 'my_laneKF_CLS:78' OBJ.img_num_rows = size(BW,1); */
  /* 'my_laneKF_CLS:79' OBJ.img_num_cols = size(BW,2); */
}

/*
 * File trailer for my_laneKF_CLS.c
 *
 * [EOF]
 */
