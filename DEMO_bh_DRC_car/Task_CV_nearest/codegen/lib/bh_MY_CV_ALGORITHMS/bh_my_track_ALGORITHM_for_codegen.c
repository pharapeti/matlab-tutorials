/*
 * File: bh_my_track_ALGORITHM_for_codegen.c
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

/* Variable Definitions */
static my_laneKF_CLS KF_b_OBJ;
static boolean_T KF_b_OBJ_not_empty;
static my_laneKF_CLS KF_y_OBJ;
static boolean_T KF_y_OBJ_not_empty;

/* Function Definitions */

/*
 * function [BLUE_mc_col, YELL_mc_col] = ...
 *      bh_my_track_ALGORITHM_for_codegen(BLUE_s, YELL_s, tf_do_init)
 * ALLOWED USAGE:
 *   >> [BLUE_LT_s, YELL_LT_s] = bh_my_track_ALGORITHM_for_codegen(BLUE_s, YELL_s, tf_do_init)
 * Arguments    : const struct3_T *BLUE_s
 *                const struct3_T *YELL_s
 *                boolean_T tf_do_init
 *                double BLUE_mc_col[2]
 *                double YELL_mc_col[2]
 * Return Type  : void
 */
void bh_my_track_ALGORITHM_for_codegen(const struct3_T *BLUE_s, const struct3_T *
  YELL_s, boolean_T tf_do_init, double BLUE_mc_col[2], double YELL_mc_col[2])
{
  int i;
  static const signed char A[4] = { 1, 0, 0, 1 };

  static const signed char Noise_proc_var_mat[4] = { 100, 0, 0, 100 };

  static const signed char Noise_meas_var_mat[4] = { 4, 0, 0, 4 };

  /*  ************************************************************************* */
  /*       do OBJECT INITIALIZATION */
  /*  ************************************************************************* */
  /* 'bh_my_track_ALGORITHM_for_codegen:13' if(true==tf_do_init || isempty(KF_b_OBJ) || isempty(KF_y_OBJ) ) */
  if (tf_do_init || (!KF_b_OBJ_not_empty) || (!KF_y_OBJ_not_empty)) {
    /*  create an instance of the Kalman filter */
    /* 'bh_my_track_ALGORITHM_for_codegen:16' Initial_mc_col      = [0;120]; */
    /*  [x,y] */
    /* 'bh_my_track_ALGORITHM_for_codegen:17' Initial_mc_var_mat  = [10,0; 0,10].^2; */
    /*  variance of initial estimates */
    /* 'bh_my_track_ALGORITHM_for_codegen:18' Noise_proc_var_mat  = [10,0; 0,10].^2; */
    /*  process noise covariance matrix */
    /* 'bh_my_track_ALGORITHM_for_codegen:19' Noise_meas_var_mat  = [ 2,0; 0, 2].^2; */
    /*  measurement noise covariance matrix */
    /* Noise_meas_var_mat  = [ 1,0; 0, 1].^2; % measurement noise covariance matrix */
    /* 'bh_my_track_ALGORITHM_for_codegen:22' KF_b_OBJ = my_laneKF_CLS( Initial_mc_col,      ... */
    /* 'bh_my_track_ALGORITHM_for_codegen:23'                               Initial_mc_var_mat, ... */
    /* 'bh_my_track_ALGORITHM_for_codegen:24'                               Noise_proc_var_mat, ... */
    /* 'bh_my_track_ALGORITHM_for_codegen:25'                               Noise_meas_var_mat ); */
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
    /* 'my_laneKF_CLS:34' if(1 ==coder.target('MATLAB') ) */
    /*   x = [m,c] */
    /*  KF = my_KF_general_CLS( A, B, C, Q, R, x0, P0 ); */
    /* 'my_laneKF_CLS:44' A  = [1,0; */
    /* 'my_laneKF_CLS:45'           0,1;]; */
    /* 'my_laneKF_CLS:46' B  = []; */
    /* 'my_laneKF_CLS:47' C  = [1,0; */
    /* 'my_laneKF_CLS:48'           0,1]; */
    /* 'my_laneKF_CLS:49' Q  = Noise_proc_var_mat; */
    /* 'my_laneKF_CLS:50' R  = Noise_meas_var_mat; */
    /* 'my_laneKF_CLS:51' x0 = Initial_mc_col; */
    /* 'my_laneKF_CLS:52' P0 = Initial_mc_var_mat; */
    /* 'my_laneKF_CLS:54' OBJ.KF = my_KF_general_CLS( A, B, C, Q, R, x0, P0 ); */
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
    /* 'my_KF_general_CLS:78' if(1 ==coder.target('MATLAB') ) */
    /* 'my_KF_general_CLS:84' Nx     = size(A,1); */
    /* 'my_KF_general_CLS:85' Nu     = size(B,2); */
    /* 'my_KF_general_CLS:86' Ny     = size(C,1); */
    /* 'my_KF_general_CLS:88' OBJ.A  = A; */
    /* 'my_KF_general_CLS:89' OBJ.B  = B; */
    /* 'my_KF_general_CLS:90' OBJ.C  = C; */
    /* 'my_KF_general_CLS:91' OBJ.Q  = Q; */
    /* 'my_KF_general_CLS:92' OBJ.R  = R; */
    for (i = 0; i < 4; i++) {
      KF_b_OBJ.KF.A[i] = A[i];
      KF_b_OBJ.KF.C[i] = A[i];
      KF_b_OBJ.KF.Q[i] = Noise_proc_var_mat[i];
      KF_b_OBJ.KF.R[i] = Noise_meas_var_mat[i];
    }

    /* 'my_KF_general_CLS:93' OBJ.x0 = x0(:); */
    /* 'my_KF_general_CLS:94' OBJ.P0 = P0; */
    /* 'my_KF_general_CLS:96' OBJ.Nx = Nx; */
    KF_b_OBJ.KF.Nx = 2.0;

    /* 'my_KF_general_CLS:97' OBJ.Ny = Ny; */
    /* 'my_KF_general_CLS:98' OBJ.Nu = Nu; */
    /* 'my_KF_general_CLS:100' OBJ.x  = OBJ.x0; */
    for (i = 0; i < 2; i++) {
      KF_b_OBJ.KF.x0[i] = 120.0 * (double)i;
      KF_b_OBJ.KF.x[i] = KF_b_OBJ.KF.x0[i];
    }

    /* 'my_KF_general_CLS:101' OBJ.P  = P0; */
    KF_b_OBJ_not_empty = true;

    /* 'bh_my_track_ALGORITHM_for_codegen:26' KF_b_OBJ.plot_TAG = 'TAG_KF_b'; */
    /* 'bh_my_track_ALGORITHM_for_codegen:28' KF_y_OBJ = my_laneKF_CLS( Initial_mc_col,      ... */
    /* 'bh_my_track_ALGORITHM_for_codegen:29'                               Initial_mc_var_mat, ... */
    /* 'bh_my_track_ALGORITHM_for_codegen:30'                               Noise_proc_var_mat, ... */
    /* 'bh_my_track_ALGORITHM_for_codegen:31'                               Noise_meas_var_mat ); */
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
    /* 'my_laneKF_CLS:34' if(1 ==coder.target('MATLAB') ) */
    /*   x = [m,c] */
    /*  KF = my_KF_general_CLS( A, B, C, Q, R, x0, P0 ); */
    /* 'my_laneKF_CLS:44' A  = [1,0; */
    /* 'my_laneKF_CLS:45'           0,1;]; */
    /* 'my_laneKF_CLS:46' B  = []; */
    /* 'my_laneKF_CLS:47' C  = [1,0; */
    /* 'my_laneKF_CLS:48'           0,1]; */
    /* 'my_laneKF_CLS:49' Q  = Noise_proc_var_mat; */
    /* 'my_laneKF_CLS:50' R  = Noise_meas_var_mat; */
    /* 'my_laneKF_CLS:51' x0 = Initial_mc_col; */
    /* 'my_laneKF_CLS:52' P0 = Initial_mc_var_mat; */
    /* 'my_laneKF_CLS:54' OBJ.KF = my_KF_general_CLS( A, B, C, Q, R, x0, P0 ); */
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
    /* 'my_KF_general_CLS:78' if(1 ==coder.target('MATLAB') ) */
    /* 'my_KF_general_CLS:84' Nx     = size(A,1); */
    /* 'my_KF_general_CLS:85' Nu     = size(B,2); */
    /* 'my_KF_general_CLS:86' Ny     = size(C,1); */
    /* 'my_KF_general_CLS:88' OBJ.A  = A; */
    /* 'my_KF_general_CLS:89' OBJ.B  = B; */
    /* 'my_KF_general_CLS:90' OBJ.C  = C; */
    /* 'my_KF_general_CLS:91' OBJ.Q  = Q; */
    /* 'my_KF_general_CLS:92' OBJ.R  = R; */
    for (i = 0; i < 4; i++) {
      KF_b_OBJ.KF.P[i] = Noise_proc_var_mat[i];
      KF_y_OBJ.KF.A[i] = A[i];
      KF_y_OBJ.KF.C[i] = A[i];
      KF_y_OBJ.KF.Q[i] = Noise_proc_var_mat[i];
      KF_y_OBJ.KF.R[i] = Noise_meas_var_mat[i];
    }

    /* 'my_KF_general_CLS:93' OBJ.x0 = x0(:); */
    /* 'my_KF_general_CLS:94' OBJ.P0 = P0; */
    /* 'my_KF_general_CLS:96' OBJ.Nx = Nx; */
    KF_y_OBJ.KF.Nx = 2.0;

    /* 'my_KF_general_CLS:97' OBJ.Ny = Ny; */
    /* 'my_KF_general_CLS:98' OBJ.Nu = Nu; */
    /* 'my_KF_general_CLS:100' OBJ.x  = OBJ.x0; */
    for (i = 0; i < 2; i++) {
      KF_y_OBJ.KF.x0[i] = 120.0 * (double)i;
      KF_y_OBJ.KF.x[i] = KF_y_OBJ.KF.x0[i];
    }

    /* 'my_KF_general_CLS:101' OBJ.P  = P0; */
    for (i = 0; i < 4; i++) {
      KF_y_OBJ.KF.P[i] = Noise_proc_var_mat[i];
    }

    KF_y_OBJ_not_empty = true;

    /* 'bh_my_track_ALGORITHM_for_codegen:33' KF_y_OBJ.plot_TAG = 'TAG_KF_y'; */
  }

  /*  if(true==tf_do_init) */
  /*  ************************************************************************* */
  /*       FILTER stuff */
  /*  ************************************************************************* */
  /*   propagate the Kalman Filter */
  /* 'bh_my_track_ALGORITHM_for_codegen:42' KF_b_OBJ = KF_b_OBJ.pred_and_correct(BLUE_s.BW, BLUE_s.tf_is_detected); */
  my_laneKF_CLS_pred_and_correct(&KF_b_OBJ, BLUE_s->BW, BLUE_s->tf_is_detected);

  /* 'bh_my_track_ALGORITHM_for_codegen:43' KF_y_OBJ = KF_y_OBJ.pred_and_correct(YELL_s.BW, YELL_s.tf_is_detected); */
  my_laneKF_CLS_pred_and_correct(&KF_y_OBJ, YELL_s->BW, YELL_s->tf_is_detected);

  /*  ************************************************************************* */
  /*       Take care of the outputs */
  /*  ************************************************************************* */
  /* 'bh_my_track_ALGORITHM_for_codegen:49' BLUE_mc_col = KF_b_OBJ.get_mc_col(); */
  /*  pred_and_correct() */
  /* --------------------------------------------------------------------------  */
  /* 'my_laneKF_CLS:83' mc_col = OBJ.mc_col; */
  /* 'bh_my_track_ALGORITHM_for_codegen:50' YELL_mc_col = KF_y_OBJ.get_mc_col(); */
  /*  pred_and_correct() */
  /* --------------------------------------------------------------------------  */
  /* 'my_laneKF_CLS:83' mc_col = OBJ.mc_col; */
  for (i = 0; i < 2; i++) {
    BLUE_mc_col[i] = KF_b_OBJ.mc_col[i];
    YELL_mc_col[i] = KF_y_OBJ.mc_col[i];
  }

  /*  ************************************************************************* */
  /*       VISUALIZE  stuff */
  /*  ************************************************************************* */
  /* 'bh_my_track_ALGORITHM_for_codegen:55' if(1 ==coder.target('MATLAB') ) */
  /*  bh_my_track_ALGORITHM_for_codegen() */
  /* -######################################################################### */
  /*  E N D    O F    M A I N    F U N C T I O N */
  /* -######################################################################### */
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void c_bh_my_track_ALGORITHM_for_cod(void)
{
  KF_y_OBJ_not_empty = false;
  KF_b_OBJ_not_empty = false;
}

/*
 * File trailer for bh_my_track_ALGORITHM_for_codegen.c
 *
 * [EOF]
 */
