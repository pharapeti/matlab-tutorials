/*
 * bh_my_track_ALGORITHM_for_codegen.c
 *
 * Code generation for function 'bh_my_track_ALGORITHM_for_codegen'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "my_laneKF_CLS.h"

/* Variable Definitions */
static my_laneKF_CLS KF_b_OBJ;
static boolean_T KF_b_OBJ_not_empty;
static my_laneKF_CLS KF_y_OBJ;
static boolean_T KF_y_OBJ_not_empty;
static emlrtRSInfo jl_emlrtRSI = { 42, /* lineNo */
  "bh_my_track_ALGORITHM_for_codegen", /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_track_ALGORITHM_for_codegen.m"/* pathName */
};

static emlrtRSInfo kl_emlrtRSI = { 43, /* lineNo */
  "bh_my_track_ALGORITHM_for_codegen", /* fcnName */
  "C:\\bh\\users_EV\\sandpit\\bh_car_models\\devel\\Task_CV_nearest\\bh_my_track_ALGORITHM_for_codegen.m"/* pathName */
};

/* Function Definitions */
void bh_my_track_ALGORITHM_for_codegen(const emlrtStack *sp, const struct3_T
  *BLUE_s, const struct3_T *YELL_s, boolean_T tf_do_init, real_T BLUE_mc_col[2],
  real_T YELL_mc_col[2])
{
  my_laneKF_CLS r7;
  int32_T i;
  static const int8_T A[4] = { 1, 0, 0, 1 };

  static const int8_T Noise_proc_var_mat[4] = { 100, 0, 0, 100 };

  static const int8_T Noise_meas_var_mat[4] = { 4, 0, 0, 4 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  ALLOWED USAGE: */
  /*   >> [BLUE_LT_s, YELL_LT_s] = bh_my_track_ALGORITHM_for_codegen(BLUE_s, YELL_s, tf_do_init) */
  /*  ************************************************************************* */
  /*       do OBJECT INITIALIZATION */
  /*  ************************************************************************* */
  if (tf_do_init || (!KF_b_OBJ_not_empty) || (!KF_y_OBJ_not_empty)) {
    /*  create an instance of the Kalman filter */
    /*  [x,y] */
    /*  variance of initial estimates */
    /*  process noise covariance matrix */
    /*  measurement noise covariance matrix */
    /* Noise_meas_var_mat  = [ 1,0; 0, 1].^2; % measurement noise covariance matrix */
    /*  ATTENTION: */
    /*  I want this class to be MATLAB CODER friendly, hence I have prepopulated */
    /*  some properties with NaNs */
    /* ------------------------------ */
    /* ------------------------------ */
    /* ------------------------------ */
    /* ------------------------------ */
    /* x_col_mat = []; */
    /* ------------------------------ */
    /* -------------------------------------------------------------------------- */
    /*  used in plot()  */
    /* _######################################################################### */
    /*   x = [m,c] */
    /*  KF = my_KF_general_CLS( A, B, C, Q, R, x0, P0 ); */
    /*  MY_KF_GENERAL_CLS - a vanilla implementation of a Kalman Filter */
    /* -------------------------------------------------------------------------- */
    /*  REF:  */
    /*   1.) https://cse.sc.edu/~terejanu/files/tutorialKF.pdf */
    /*       - "Discrete Time Kalman Filter tutorial" - Gabriel A. Terejanu */
    /*   2.) https://au.mathworks.com/videos/series/understanding-kalman-filters.html */
    /* -------------------------------------------------------------------------- */
    /*  Discrete plant: */
    /*      x[k] = A.x[k-1]  +  B.u[k-1]   +  w[k-1] */
    /*      y[k] = C.x[k]                  +  v[k] */
    /*  */
    /*    where: */
    /*            Q = cov(w) ==PROCESS_NOISE covariance matrix */
    /*            R = cov(v) ==MEASUREMENT_NOISE covariance matrix */
    /* -------------------------------------------------------------------------- */
    /*  PREDICT: */
    /*     xhat[k|k-1] = A.x[k-1|k-l]       +  B.u[k-1] */
    /*        P[k|k-1] = A.P[k-1|k-1].(A')  +  Q */
    /*  CORRECT: */
    /*        K[k]     = P[k|k-1].(C'). inv(  C.P[k|k-1].(C') + R  ) */
    /*     xhat[k|k]   = xhat[k|k-1]  +  K[k]*( y[k] - C.xhat[k|k-1]  ) */
    /*        P[k|k]   = (I-K[k].C). P[k|k-1] . (I-K[k].C)'   +  K[k]R.(K[k]') */
    /*                 = (I-K[k].C). P[k|k-1] */
    /* -------------------------------------------------------------------------- */
    /*  INITIAL conditions: */
    /*      x[0] - state value at time ZERO */
    /*      P[0] - covariance matrix of the state estimate */
    /* -------------------------------------------------------------------------- */
    /*  VECTOR description: */
    /*      x[k] - Nx_x_1 , STATE  vector at time k */
    /*      u[k] - Nu_x_1 , INPUT  vector at time k */
    /*      y[k] - Ny_x_1 , OUTPUT vector at time k */
    /*   */
    /*      w[k] - Nx_x_1 , PROCESS_NOISE     vector at time k */
    /*      v[k] - Ny_x_1 , MEASUREMENT_NOISE vector at time k */
    /* -------------------------------------------------------------------------- */
    /*  MATRIX description: */
    /*      A    - Nx_x_Nx */
    /*      B    - Nx_x_Nu */
    /*      C    - Ny_x_Nx */
    /*   */
    /*      Q    - Nx_x_Nx, PROCESS_NOISE     covariance matrix */
    /*      R    - Ny_x_Ny, MEASUREMENT_NOISE covariance matrix */
    /*      P    - Nx_x_Nx, covariance matrix of the state estimate */
    /*      K    - Nx_x_Ny, Kalman gain matrix */
    /* -------------------------------------------------------------------------- */
    /*  EXPECTED_USAGE_#1: */
    /*    >> OBJ = my_KF_general_CLS( A, B, C, Q, R, x0, P0 ); */
    /*    >> OBJ = OBJ.predict(u_k_minus_1); */
    /*    >> OBJ = OBJ.correct(y_k); */
    /* -------------------------------------------------------------------------- */
    /*  EXPECTED_USAGE_#2: */
    /*    >> OBJ = my_KF_general_CLS( A, B, C, Q, R, x0, P0 ); */
    /*    >> [xo_mat, yo_mat] = OBJ.batch_step(u_mat, y_meas_mat, do_plots); */
    /* -------------------------------------------------------------------------- */
    /* ------------------------------ */
    /* ------------------------------ */
    /* -------------------------------------------------------------------------- */
    /* _######################################################################### */
    for (i = 0; i < 4; i++) {
      KF_b_OBJ.KF.A[i] = A[i];
      KF_b_OBJ.KF.C[i] = A[i];
      KF_b_OBJ.KF.Q[i] = Noise_proc_var_mat[i];
      KF_b_OBJ.KF.R[i] = Noise_meas_var_mat[i];
    }

    KF_b_OBJ.KF.Nx = 2.0;
    for (i = 0; i < 2; i++) {
      KF_b_OBJ.KF.x0[i] = 120.0 * (real_T)i;
      KF_b_OBJ.KF.x[i] = KF_b_OBJ.KF.x0[i];
    }

    KF_b_OBJ_not_empty = true;

    /*  ATTENTION: */
    /*  I want this class to be MATLAB CODER friendly, hence I have prepopulated */
    /*  some properties with NaNs */
    /* ------------------------------ */
    /* ------------------------------ */
    /* ------------------------------ */
    /* ------------------------------ */
    /* x_col_mat = []; */
    /* ------------------------------ */
    /* -------------------------------------------------------------------------- */
    /*  used in plot()  */
    /* _######################################################################### */
    /*   x = [m,c] */
    /*  KF = my_KF_general_CLS( A, B, C, Q, R, x0, P0 ); */
    /*  MY_KF_GENERAL_CLS - a vanilla implementation of a Kalman Filter */
    /* -------------------------------------------------------------------------- */
    /*  REF:  */
    /*   1.) https://cse.sc.edu/~terejanu/files/tutorialKF.pdf */
    /*       - "Discrete Time Kalman Filter tutorial" - Gabriel A. Terejanu */
    /*   2.) https://au.mathworks.com/videos/series/understanding-kalman-filters.html */
    /* -------------------------------------------------------------------------- */
    /*  Discrete plant: */
    /*      x[k] = A.x[k-1]  +  B.u[k-1]   +  w[k-1] */
    /*      y[k] = C.x[k]                  +  v[k] */
    /*  */
    /*    where: */
    /*            Q = cov(w) ==PROCESS_NOISE covariance matrix */
    /*            R = cov(v) ==MEASUREMENT_NOISE covariance matrix */
    /* -------------------------------------------------------------------------- */
    /*  PREDICT: */
    /*     xhat[k|k-1] = A.x[k-1|k-l]       +  B.u[k-1] */
    /*        P[k|k-1] = A.P[k-1|k-1].(A')  +  Q */
    /*  CORRECT: */
    /*        K[k]     = P[k|k-1].(C'). inv(  C.P[k|k-1].(C') + R  ) */
    /*     xhat[k|k]   = xhat[k|k-1]  +  K[k]*( y[k] - C.xhat[k|k-1]  ) */
    /*        P[k|k]   = (I-K[k].C). P[k|k-1] . (I-K[k].C)'   +  K[k]R.(K[k]') */
    /*                 = (I-K[k].C). P[k|k-1] */
    /* -------------------------------------------------------------------------- */
    /*  INITIAL conditions: */
    /*      x[0] - state value at time ZERO */
    /*      P[0] - covariance matrix of the state estimate */
    /* -------------------------------------------------------------------------- */
    /*  VECTOR description: */
    /*      x[k] - Nx_x_1 , STATE  vector at time k */
    /*      u[k] - Nu_x_1 , INPUT  vector at time k */
    /*      y[k] - Ny_x_1 , OUTPUT vector at time k */
    /*   */
    /*      w[k] - Nx_x_1 , PROCESS_NOISE     vector at time k */
    /*      v[k] - Ny_x_1 , MEASUREMENT_NOISE vector at time k */
    /* -------------------------------------------------------------------------- */
    /*  MATRIX description: */
    /*      A    - Nx_x_Nx */
    /*      B    - Nx_x_Nu */
    /*      C    - Ny_x_Nx */
    /*   */
    /*      Q    - Nx_x_Nx, PROCESS_NOISE     covariance matrix */
    /*      R    - Ny_x_Ny, MEASUREMENT_NOISE covariance matrix */
    /*      P    - Nx_x_Nx, covariance matrix of the state estimate */
    /*      K    - Nx_x_Ny, Kalman gain matrix */
    /* -------------------------------------------------------------------------- */
    /*  EXPECTED_USAGE_#1: */
    /*    >> OBJ = my_KF_general_CLS( A, B, C, Q, R, x0, P0 ); */
    /*    >> OBJ = OBJ.predict(u_k_minus_1); */
    /*    >> OBJ = OBJ.correct(y_k); */
    /* -------------------------------------------------------------------------- */
    /*  EXPECTED_USAGE_#2: */
    /*    >> OBJ = my_KF_general_CLS( A, B, C, Q, R, x0, P0 ); */
    /*    >> [xo_mat, yo_mat] = OBJ.batch_step(u_mat, y_meas_mat, do_plots); */
    /* -------------------------------------------------------------------------- */
    /* ------------------------------ */
    /* ------------------------------ */
    /* -------------------------------------------------------------------------- */
    /* _######################################################################### */
    for (i = 0; i < 4; i++) {
      KF_b_OBJ.KF.P[i] = Noise_proc_var_mat[i];
      KF_y_OBJ.KF.A[i] = A[i];
      KF_y_OBJ.KF.C[i] = A[i];
      KF_y_OBJ.KF.Q[i] = Noise_proc_var_mat[i];
      KF_y_OBJ.KF.R[i] = Noise_meas_var_mat[i];
    }

    KF_y_OBJ.KF.Nx = 2.0;
    for (i = 0; i < 2; i++) {
      KF_y_OBJ.KF.x0[i] = 120.0 * (real_T)i;
      KF_y_OBJ.KF.x[i] = KF_y_OBJ.KF.x0[i];
    }

    for (i = 0; i < 4; i++) {
      KF_y_OBJ.KF.P[i] = Noise_proc_var_mat[i];
    }

    KF_y_OBJ_not_empty = true;
  }

  /*  if(true==tf_do_init) */
  /*  ************************************************************************* */
  /*       FILTER stuff */
  /*  ************************************************************************* */
  /*   propagate the Kalman Filter */
  r7 = KF_b_OBJ;
  st.site = &jl_emlrtRSI;
  my_laneKF_CLS_pred_and_correct(&st, &r7, BLUE_s->BW, BLUE_s->tf_is_detected);
  KF_b_OBJ = r7;
  r7 = KF_y_OBJ;
  st.site = &kl_emlrtRSI;
  my_laneKF_CLS_pred_and_correct(&st, &r7, YELL_s->BW, YELL_s->tf_is_detected);
  KF_y_OBJ = r7;

  /*  ************************************************************************* */
  /*       Take care of the outputs */
  /*  ************************************************************************* */
  /*  pred_and_correct() */
  /* --------------------------------------------------------------------------  */
  /*  pred_and_correct() */
  /* --------------------------------------------------------------------------  */
  for (i = 0; i < 2; i++) {
    BLUE_mc_col[i] = KF_b_OBJ.mc_col[i];
    YELL_mc_col[i] = KF_y_OBJ.mc_col[i];
  }

  /*  ************************************************************************* */
  /*       VISUALIZE  stuff */
  /*  ************************************************************************* */
  /*  bh_my_track_ALGORITHM_for_codegen() */
  /* -######################################################################### */
  /*  E N D    O F    M A I N    F U N C T I O N */
  /* -######################################################################### */
}

void c_bh_my_track_ALGORITHM_for_cod(void)
{
  KF_y_OBJ_not_empty = false;
  KF_b_OBJ_not_empty = false;
}

/* End of code generation (bh_my_track_ALGORITHM_for_codegen.c) */
