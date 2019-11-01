/*
 * my_laneKF_CLS.c
 *
 * Code generation for function 'my_laneKF_CLS'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "my_laneKF_CLS.h"
#include "my_KF_general_CLS.h"
#include "lane_info_CLS.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Variable Definitions */
static emlrtRSInfo ll_emlrtRSI = { 65, /* lineNo */
  "my_laneKF_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\my_laneKF_CLS.m"/* pathName */
};

static emlrtRSInfo ml_emlrtRSI = { 69, /* lineNo */
  "my_laneKF_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\my_laneKF_CLS.m"/* pathName */
};

static emlrtRSInfo nl_emlrtRSI = { 71, /* lineNo */
  "my_laneKF_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\my_laneKF_CLS.m"/* pathName */
};

static emlrtRSInfo ol_emlrtRSI = { 63, /* lineNo */
  "my_laneKF_CLS",                     /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\THE_LIBRARY\\my_cv_classes\\my_laneKF_CLS.m"/* pathName */
};

/* Function Definitions */
void my_laneKF_CLS_pred_and_correct(const emlrtStack *sp, my_laneKF_CLS *OBJ,
  const boolean_T BW[76800], boolean_T tf_found)
{
  lane_info_CLS_1 lane_O;
  int32_T i37;
  real_T m_data[1];
  int32_T m_size[2];
  real_T c_data[1];
  int32_T c_size[2];
  boolean_T b7;
  int32_T b_m_size[2];
  int32_T loop_ub;
  real_T b_m_data[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /*  my_laneKF_CLS() */
  /* --------------------------------------------------------------------------  */
  /*  use KF to PREDICT */
  my_KF_general_CLS_predict(&OBJ->KF);

  /*  now do we have a measurement to allow a CORRECT */
  st.site = &ol_emlrtRSI;
  b_lane_info_CLS_lane_info_CLS(&st, BW, tf_found, &lane_O);

  /* --------------------------------------------------------------------------   */
  if (lane_O.tf_is_detected) {
    st.site = &ll_emlrtRSI;
    lane_info_CLS_calc_info(&st, &lane_O);
    lane_info_CLS_get_mc(lane_O.m, lane_O.c, lane_O.tf_is_detected, m_data,
                         m_size, c_data, c_size);
    st.site = &ml_emlrtRSI;
    b_st.site = &sd_emlrtRSI;
    c_st.site = &td_emlrtRSI;
    b7 = true;
    if (c_size[1] != m_size[1]) {
      b7 = false;
    }

    if (!b7) {
      emlrtErrorWithMessageIdR2012b(&c_st, &dg_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    b_m_size[0] = 2;
    b_m_size[1] = m_size[1];
    loop_ub = m_size[1];
    for (i37 = 0; i37 < loop_ub; i37++) {
      b_m_data[i37 << 1] = m_data[m_size[0] * i37];
    }

    loop_ub = c_size[1];
    for (i37 = 0; i37 < loop_ub; i37++) {
      b_m_data[1 + (i37 << 1)] = c_data[c_size[0] * i37];
    }

    st.site = &nl_emlrtRSI;
    my_KF_general_CLS_correct(&st, &OBJ->KF, b_m_data, b_m_size);
  }

  for (i37 = 0; i37 < 2; i37++) {
    OBJ->mc_col[i37] = OBJ->KF.x[i37];
  }

  /* OBJ.x_col_mat = [OBJ.x_col_mat, OBJ.mc_col]; */
  /*  and store the size of the image we're processing */
}

/* End of code generation (my_laneKF_CLS.c) */
