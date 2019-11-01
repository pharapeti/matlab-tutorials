/*
 * File: my_KF_general_CLS.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "my_KF_general_CLS.h"

/* Function Definitions */

/*
 * function  OBJ = correct(OBJ, y)
 * Arguments    : my_KF_general_CLS *OBJ
 *                const double y_data[]
 * Return Type  : void
 */
void my_KF_general_CLS_correct(my_KF_general_CLS *OBJ, const double y_data[])
{
  int i31;
  signed char I_data[4];
  int k;
  double B[4];
  int r1;
  int r2;
  double y[4];
  double a21;
  double b_OBJ[4];
  double a22;
  double d4;
  double K[4];
  double b_y[2];
  signed char b_I_data[4];

  /*  predict() */
  /* --------------------------------------------------------------------------  */
  /* 'my_KF_general_CLS:136' if(1 ==coder.target('MATLAB') ) */
  /* 'my_KF_general_CLS:140' y = y(:); */
  /* 'my_KF_general_CLS:142' assert(length(y)==size(OBJ.C,1), '###_ERROR:  hey your y and C have a dimension INconsistency !') */
  /* 'my_KF_general_CLS:144' x = OBJ.x; */
  /* 'my_KF_general_CLS:145' A = OBJ.A; */
  /* 'my_KF_general_CLS:146' C = OBJ.C; */
  /* 'my_KF_general_CLS:147' P = OBJ.P; */
  /* 'my_KF_general_CLS:148' Q = OBJ.Q; */
  /* 'my_KF_general_CLS:149' R = OBJ.R; */
  /* 'my_KF_general_CLS:150' I = eye(OBJ.Nx); */
  for (i31 = 0; i31 < 4; i31++) {
    I_data[i31] = 0;
  }

  /*  Recall the BACK and FORWARD slash operators */
  /*   A.X=B ---> X=inv(A)*B ---> X = A\B */
  /*   X.A=B ---> X=B*inv(A) ---> X = B/A */
  /*      K[k]     = P[k|k-1].(C'). inv(  C.P[k|k-1].(C') + R  ) */
  /*   xhat[k|k]   = xhat[k|k-1]  +  K[k]*( y[k] - C.xhat[k|k-1]  ) */
  /*      P[k|k]   = (I-K[k].C). P[k|k-1] . (I-K[k].C)'   +  K[k]R.(K[k]') */
  /*                 = (I-K[k].C). P[k|k-1] */
  /* 'my_KF_general_CLS:161' K = (P* (C.')) / (C*P*(C.') + R); */
  for (k = 0; k < 2; k++) {
    I_data[k + (k << 1)] = 1;
    for (i31 = 0; i31 < 2; i31++) {
      y[k + (i31 << 1)] = 0.0;
      b_OBJ[k + (i31 << 1)] = 0.0;
      for (r2 = 0; r2 < 2; r2++) {
        y[k + (i31 << 1)] += OBJ->P[k + (r2 << 1)] * OBJ->C[i31 + (r2 << 1)];
        b_OBJ[k + (i31 << 1)] += OBJ->C[k + (r2 << 1)] * OBJ->P[r2 + (i31 << 1)];
      }
    }

    for (i31 = 0; i31 < 2; i31++) {
      d4 = 0.0;
      for (r2 = 0; r2 < 2; r2++) {
        d4 += b_OBJ[k + (r2 << 1)] * OBJ->C[i31 + (r2 << 1)];
      }

      B[k + (i31 << 1)] = d4 + OBJ->R[k + (i31 << 1)];
    }
  }

  if (fabs(B[1]) > fabs(B[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  a21 = B[r2] / B[r1];
  a22 = B[2 + r2] - a21 * B[2 + r1];

  /* 'my_KF_general_CLS:162' x = x + K*(y - C*x); */
  /* 'my_KF_general_CLS:163' P = (I - K*C)*P; */
  /* 'my_KF_general_CLS:165' OBJ.x = x; */
  for (k = 0; k < 2; k++) {
    K[k + (r1 << 1)] = y[k] / B[r1];
    K[k + (r2 << 1)] = (y[2 + k] - K[k + (r1 << 1)] * B[2 + r1]) / a22;
    K[k + (r1 << 1)] -= K[k + (r2 << 1)] * a21;
    d4 = 0.0;
    for (i31 = 0; i31 < 2; i31++) {
      d4 += OBJ->C[k + (i31 << 1)] * OBJ->x[i31];
    }

    b_y[k] = y_data[k] - d4;
  }

  /* 'my_KF_general_CLS:166' OBJ.P = P; */
  for (i31 = 0; i31 < 2; i31++) {
    d4 = 0.0;
    for (r2 = 0; r2 < 2; r2++) {
      d4 += K[i31 + (r2 << 1)] * b_y[r2];
      b_I_data[r2 + (i31 << 1)] = I_data[r2 + (i31 << 1)];
    }

    OBJ->x[i31] += d4;
  }

  for (i31 = 0; i31 < 2; i31++) {
    for (r2 = 0; r2 < 2; r2++) {
      d4 = 0.0;
      for (r1 = 0; r1 < 2; r1++) {
        d4 += K[i31 + (r1 << 1)] * OBJ->C[r1 + (r2 << 1)];
      }

      b_OBJ[i31 + (r2 << 1)] = (double)b_I_data[i31 + (r2 << 1)] - d4;
    }

    for (r2 = 0; r2 < 2; r2++) {
      B[i31 + (r2 << 1)] = 0.0;
      for (r1 = 0; r1 < 2; r1++) {
        B[i31 + (r2 << 1)] += b_OBJ[i31 + (r1 << 1)] * OBJ->P[r1 + (r2 << 1)];
      }
    }
  }

  for (i31 = 0; i31 < 2; i31++) {
    for (r2 = 0; r2 < 2; r2++) {
      OBJ->P[r2 + (i31 << 1)] = B[r2 + (i31 << 1)];
    }
  }
}

/*
 * function  OBJ = predict(OBJ, varargin)
 * ALLOWED USAGE:
 *  >> OBJ = OBJ.predict()
 *  >> OBJ = OBJ.predict(u)
 * Arguments    : my_KF_general_CLS *OBJ
 * Return Type  : void
 */
void my_KF_general_CLS_predict(my_KF_general_CLS *OBJ)
{
  int i28;
  double b_OBJ[2];
  int i29;
  double c_OBJ[4];
  double d3;
  int i30;

  /*  my_KF_general_CLS() */
  /* --------------------------------------------------------------------------  */
  /* 'my_KF_general_CLS:109' if(2==nargin) */
  /*     xhat[k|k-1] = A.x[k-1]  +  B.u[k-1] */
  /*        P[k|k-1] = A.P[k-1|k-1].(A')  +  Q */
  /* 'my_KF_general_CLS:120' x = OBJ.x; */
  /* 'my_KF_general_CLS:121' A = OBJ.A; */
  /* 'my_KF_general_CLS:122' P = OBJ.P; */
  /* 'my_KF_general_CLS:123' Q = OBJ.Q; */
  /* 'my_KF_general_CLS:124' if(isempty(OBJ.B)) */
  /* 'my_KF_general_CLS:125' x = A*x; */
  /* 'my_KF_general_CLS:131' OBJ.x = x; */
  for (i28 = 0; i28 < 2; i28++) {
    b_OBJ[i28] = 0.0;
    for (i29 = 0; i29 < 2; i29++) {
      b_OBJ[i28] += OBJ->A[i28 + (i29 << 1)] * OBJ->x[i29];
    }
  }

  /* 'my_KF_general_CLS:132' OBJ.P = A*P*(A.') + Q; */
  for (i28 = 0; i28 < 2; i28++) {
    OBJ->x[i28] = b_OBJ[i28];
    for (i29 = 0; i29 < 2; i29++) {
      c_OBJ[i28 + (i29 << 1)] = 0.0;
      for (i30 = 0; i30 < 2; i30++) {
        c_OBJ[i28 + (i29 << 1)] += OBJ->A[i28 + (i30 << 1)] * OBJ->P[i30 + (i29 <<
          1)];
      }
    }
  }

  for (i28 = 0; i28 < 2; i28++) {
    for (i29 = 0; i29 < 2; i29++) {
      d3 = 0.0;
      for (i30 = 0; i30 < 2; i30++) {
        d3 += c_OBJ[i28 + (i30 << 1)] * OBJ->A[i29 + (i30 << 1)];
      }

      OBJ->P[i28 + (i29 << 1)] = d3 + OBJ->Q[i28 + (i29 << 1)];
    }
  }
}

/*
 * File trailer for my_KF_general_CLS.c
 *
 * [EOF]
 */
