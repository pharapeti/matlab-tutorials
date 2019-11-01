/*
 * File: bh_line_homog_CLS.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "bh_line_homog_CLS.h"
#include "abs.h"
#include "diag.h"
#include "eig.h"
#include "bh_MY_CV_ALGORITHMS_emxutil.h"

/* Function Declarations */
static void LOC_classify_line_type(double normal_vec[2], char a_str_data[], int
  a_str_size[2]);
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */

/*
 * function a_str = LOC_classify_line_type(normal_vec)
 * Arguments    : double normal_vec[2]
 *                char a_str_data[]
 *                int a_str_size[2]
 * Return Type  : void
 */
static void LOC_classify_line_type(double normal_vec[2], char a_str_data[], int
  a_str_size[2])
{
  double theta_deg;
  double scale;
  int k;
  double absxk;
  double t;
  boolean_T tf_the_normal_is_horz;
  boolean_T tf_the_normal_is_vert;
  static const char cv3[4] = { 'V', 'E', 'R', 'T' };

  static const char cv4[6] = { 'S', 'L', 'O', 'P', 'E', 'Y' };

  static const char cv5[4] = { 'H', 'O', 'R', 'Z' };

  /* 'bh_line_homog_CLS:197' normal_vec = normal_vec / norm(normal_vec); */
  theta_deg = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 2; k++) {
    absxk = fabs(normal_vec[k]);
    if (absxk > scale) {
      t = scale / absxk;
      theta_deg = 1.0 + theta_deg * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      theta_deg += t * t;
    }
  }

  theta_deg = scale * sqrt(theta_deg);
  for (k = 0; k < 2; k++) {
    normal_vec[k] /= theta_deg;
  }

  /* 'bh_line_homog_CLS:198' Y          = normal_vec(2); */
  /* 'bh_line_homog_CLS:199' X          = normal_vec(1); */
  /* 'bh_line_homog_CLS:201' theta_rad  = atan2(Y,X); */
  /* 'bh_line_homog_CLS:202' theta_deg  = theta_rad * 180/pi; */
  theta_deg = rt_atan2d_snf(normal_vec[1], normal_vec[0]) * 180.0 /
    3.1415926535897931;

  /* 'bh_line_homog_CLS:205' if(theta_deg<0) */
  if (theta_deg < 0.0) {
    /* 'bh_line_homog_CLS:206' theta_deg = 360 + theta_deg; */
    theta_deg += 360.0;
  }

  /* 'bh_line_homog_CLS:210' tf_the_normal_is_horz = false; */
  tf_the_normal_is_horz = false;

  /* 'bh_line_homog_CLS:211' tf_the_normal_is_vert = false; */
  tf_the_normal_is_vert = false;

  /* 'bh_line_homog_CLS:214' TOL_DEG = 2; */
  /* 'bh_line_homog_CLS:215' if(      (theta_deg <= TOL_DEG       )   || ... */
  /* 'bh_line_homog_CLS:216'              (theta_deg >= (360-TOL_DEG) )   || ... */
  /* 'bh_line_homog_CLS:217'          (   (theta_deg >= (180-TOL_DEG) )   && ... */
  /* 'bh_line_homog_CLS:218'              (theta_deg <= (180+TOL_DEG) )   ) ... */
  /* 'bh_line_homog_CLS:219'        ) */
  if ((theta_deg <= 2.0) || (theta_deg >= 358.0) || ((theta_deg >= 178.0) &&
       (theta_deg <= 182.0))) {
    /* 'bh_line_homog_CLS:220' tf_the_normal_is_horz = true; */
    tf_the_normal_is_horz = true;
  } else if (((theta_deg >= 88.0) && (theta_deg <= 92.0)) || ((theta_deg >=
               268.0) && (theta_deg <= 272.0))) {
    /* 'bh_line_homog_CLS:222' elseif(    (theta_deg >= (90-TOL_DEG)  && (theta_deg <= (90+TOL_DEG))) || ... */
    /* 'bh_line_homog_CLS:223'                (theta_deg >= (270-TOL_DEG) && (theta_deg <= (270+TOL_DEG))) ... */
    /* 'bh_line_homog_CLS:224'           ) */
    /* 'bh_line_homog_CLS:225' tf_the_normal_is_vert = true; */
    tf_the_normal_is_vert = true;
  } else {
    /* 'bh_line_homog_CLS:226' else */
  }

  /* 'bh_line_homog_CLS:233' if(true==tf_the_normal_is_horz) */
  if (tf_the_normal_is_horz) {
    /* 'bh_line_homog_CLS:234' a_str = 'VERT'; */
    a_str_size[0] = 1;
    a_str_size[1] = 4;
    for (k = 0; k < 4; k++) {
      a_str_data[k] = cv3[k];
    }
  } else if (tf_the_normal_is_vert) {
    /* 'bh_line_homog_CLS:235' elseif(true==tf_the_normal_is_vert) */
    /* 'bh_line_homog_CLS:236' a_str = 'HORZ'; */
    a_str_size[0] = 1;
    a_str_size[1] = 4;
    for (k = 0; k < 4; k++) {
      a_str_data[k] = cv5[k];
    }
  } else {
    /* 'bh_line_homog_CLS:237' else */
    /* 'bh_line_homog_CLS:238' a_str = 'SLOPEY'; */
    a_str_size[0] = 1;
    a_str_size[1] = 6;
    for (k = 0; k < 6; k++) {
      a_str_data[k] = cv4[k];
    }
  }
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/*
 * function mc_col = get_mc(OBJ)
 * Arguments    : double OBJ_a
 *                double OBJ_b
 *                double OBJ_d
 *                const char OBJ_line_type_data[]
 *                const int OBJ_line_type_size[2]
 *                double mc_col[2]
 * Return Type  : void
 */
void bh_line_homog_CLS_get_mc(double OBJ_a, double OBJ_b, double OBJ_d, const
  char OBJ_line_type_data[], const int OBJ_line_type_size[2], double mc_col[2])
{
  boolean_T tf_val;
  int i;
  int exitg1;
  static const char cv8[6] = { 'S', 'L', 'O', 'P', 'E', 'Y' };

  /* 'bh_line_homog_CLS:174' mc_col = [NaN;NaN]; */
  /* 'bh_line_homog_CLS:176' if( true==OBJ.isSlopey()  ) */
  /* 'bh_line_homog_CLS:79' tf_val = strcmp(OBJ.line_type,'SLOPEY'); */
  tf_val = false;
  if (OBJ_line_type_size[1] == 6) {
    i = 0;
    do {
      exitg1 = 0;
      if (i + 1 < 7) {
        if (OBJ_line_type_data[i] != cv8[i]) {
          exitg1 = 1;
        } else {
          i++;
        }
      } else {
        tf_val = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (tf_val) {
    /* 'bh_line_homog_CLS:180' mc_col(1) = (-1*OBJ.a) / OBJ.b; */
    mc_col[0] = -OBJ_a / OBJ_b;

    /* 'bh_line_homog_CLS:181' mc_col(2) = (-1*OBJ.d) / OBJ.b; */
    mc_col[1] = -OBJ_d / OBJ_b;
  } else {
    /* 'bh_line_homog_CLS:182' else */
    /* 'bh_line_homog_CLS:183' mc_col = [NaN;  NaN]; */
    for (i = 0; i < 2; i++) {
      mc_col[i] = rtNaN;
    }
  }

  /* LOC_get_side_intersect_point */
  /* ========================================================================== */
}

/*
 * function OBJ = bh_line_homog_CLS(u,v)
 * Arguments    : emxArray_real_T *u
 *                emxArray_real_T *v
 *                double *OBJ_a
 *                double *OBJ_b
 *                double *OBJ_d
 *                char OBJ_line_type_data[]
 *                int OBJ_line_type_size[2]
 * Return Type  : void
 */
void c_bh_line_homog_CLS_bh_line_hom(emxArray_real_T *u, emxArray_real_T *v,
  double *OBJ_a, double *OBJ_b, double *OBJ_d, char OBJ_line_type_data[], int
  OBJ_line_type_size[2])
{
  int k;
  int i8;
  emxArray_real_T *A;
  int loop_ub;
  emxArray_real_T *a;
  double eVec_mat[9];
  int cr;
  int br;
  creal_T b_eVec_mat[9];
  creal_T eVal_mat[9];
  int ar;
  int ib;
  double b_eVal_mat[9];
  double dv1[3];
  double THE_SOL_VEC[3];
  int ia;
  double mtmp;
  boolean_T exitg1;
  double b_THE_SOL_VEC[2];
  boolean_T b_bool;
  int exitg2;
  static const char cv0[6] = { 'S', 'L', 'O', 'P', 'E', 'Y' };

  static const char cv1[4] = { 'V', 'E', 'R', 'T' };

  static const char cv2[4] = { 'H', 'O', 'R', 'Z' };

  /* 'bh_line_homog_CLS:33' u = u(:); */
  k = u->size[0];
  i8 = u->size[0];
  u->size[0] = k;
  emxEnsureCapacity_real_T1(u, i8);

  /* 'bh_line_homog_CLS:34' v = v(:); */
  k = v->size[0];
  i8 = v->size[0];
  v->size[0] = k;
  emxEnsureCapacity_real_T1(v, i8);
  emxInit_real_T(&A, 2);

  /* 'bh_line_homog_CLS:35' A = [u,v, ones(size(u))]; */
  k = u->size[0];
  i8 = A->size[0] * A->size[1];
  A->size[0] = u->size[0];
  A->size[1] = 3;
  emxEnsureCapacity_real_T(A, i8);
  loop_ub = u->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    A->data[i8] = u->data[i8];
  }

  loop_ub = v->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    A->data[i8 + A->size[0]] = v->data[i8];
  }

  for (i8 = 0; i8 < k; i8++) {
    A->data[i8 + (A->size[0] << 1)] = 1.0;
  }

  emxInit_real_T(&a, 2);

  /* 'bh_line_homog_CLS:36' B = [1,0,0; */
  /* 'bh_line_homog_CLS:37'      0,1,0]; */
  /* 'bh_line_homog_CLS:38' [eVec_mat, eVal_mat] = eig(A'* A,  B'*B); */
  i8 = a->size[0] * a->size[1];
  a->size[0] = 3;
  a->size[1] = A->size[0];
  emxEnsureCapacity_real_T(a, i8);
  loop_ub = A->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (k = 0; k < 3; k++) {
      a->data[k + a->size[0] * i8] = A->data[i8 + A->size[0] * k];
    }
  }

  if ((a->size[1] == 1) || (A->size[0] == 1)) {
    for (i8 = 0; i8 < 3; i8++) {
      for (k = 0; k < 3; k++) {
        eVec_mat[i8 + 3 * k] = 0.0;
        loop_ub = a->size[1];
        for (cr = 0; cr < loop_ub; cr++) {
          eVec_mat[i8 + 3 * k] += a->data[i8 + a->size[0] * cr] * A->data[cr +
            A->size[0] * k];
        }
      }
    }
  } else {
    k = a->size[1];
    memset(&eVec_mat[0], 0, 9U * sizeof(double));
    for (cr = 0; cr <= 7; cr += 3) {
      for (loop_ub = cr; loop_ub + 1 <= cr + 3; loop_ub++) {
        eVec_mat[loop_ub] = 0.0;
      }
    }

    br = 0;
    for (cr = 0; cr <= 7; cr += 3) {
      ar = -1;
      i8 = br + k;
      for (ib = br; ib + 1 <= i8; ib++) {
        if (A->data[ib] != 0.0) {
          ia = ar;
          for (loop_ub = cr; loop_ub + 1 <= cr + 3; loop_ub++) {
            ia++;
            eVec_mat[loop_ub] += A->data[ib] * a->data[ia];
          }
        }

        ar += 3;
      }

      br += k;
    }
  }

  emxFree_real_T(&a);
  emxFree_real_T(&A);
  eig(eVec_mat, b_eVec_mat, eVal_mat);

  /* 'bh_line_homog_CLS:41' eVec_mat = real(eVec_mat); */
  /* 'bh_line_homog_CLS:42' eVal_mat = real(eVal_mat); */
  /* 'bh_line_homog_CLS:45' [~,ind]     = min(abs(diag(eVal_mat))); */
  for (i8 = 0; i8 < 9; i8++) {
    eVec_mat[i8] = b_eVec_mat[i8].re;
    b_eVal_mat[i8] = eVal_mat[i8].re;
  }

  diag(b_eVal_mat, dv1);
  b_abs(dv1, THE_SOL_VEC);
  k = 1;
  mtmp = THE_SOL_VEC[0];
  loop_ub = 0;
  if (rtIsNaN(THE_SOL_VEC[0])) {
    cr = 1;
    exitg1 = false;
    while ((!exitg1) && (cr + 1 < 4)) {
      k = cr + 1;
      if (!rtIsNaN(THE_SOL_VEC[cr])) {
        mtmp = THE_SOL_VEC[cr];
        loop_ub = cr;
        exitg1 = true;
      } else {
        cr++;
      }
    }
  }

  if (k < 3) {
    while (k + 1 < 4) {
      if (THE_SOL_VEC[k] < mtmp) {
        mtmp = THE_SOL_VEC[k];
        loop_ub = k;
      }

      k++;
    }
  }

  /* 'bh_line_homog_CLS:45' ~ */
  /* 'bh_line_homog_CLS:47' THE_SOL_VEC = eVec_mat(:,ind); */
  for (i8 = 0; i8 < 3; i8++) {
    THE_SOL_VEC[i8] = b_eVec_mat[i8 + 3 * loop_ub].re;
  }

  /* 'bh_line_homog_CLS:48' normal_vec  = THE_SOL_VEC(1:2); */
  /* 'bh_line_homog_CLS:51' OBJ.line_type = LOC_classify_line_type(normal_vec); */
  for (k = 0; k < 2; k++) {
    b_THE_SOL_VEC[k] = THE_SOL_VEC[k];
  }

  LOC_classify_line_type(b_THE_SOL_VEC, OBJ_line_type_data, OBJ_line_type_size);

  /* 'bh_line_homog_CLS:53' switch(OBJ.line_type) */
  b_bool = false;
  if (OBJ_line_type_size[1] == 6) {
    k = 0;
    do {
      exitg2 = 0;
      if (k + 1 < 7) {
        if (OBJ_line_type_data[k] != cv0[k]) {
          exitg2 = 1;
        } else {
          k++;
        }
      } else {
        b_bool = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }

  if (b_bool) {
    k = 0;
  } else {
    b_bool = false;
    if (OBJ_line_type_size[1] == 4) {
      k = 0;
      do {
        exitg2 = 0;
        if (k + 1 < 5) {
          if (OBJ_line_type_data[k] != cv1[k]) {
            exitg2 = 1;
          } else {
            k++;
          }
        } else {
          b_bool = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }

    if (b_bool) {
      k = 1;
    } else {
      b_bool = false;
      if (OBJ_line_type_size[1] == 4) {
        k = 0;
        do {
          exitg2 = 0;
          if (k + 1 < 5) {
            if (OBJ_line_type_data[k] != cv2[k]) {
              exitg2 = 1;
            } else {
              k++;
            }
          } else {
            b_bool = true;
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }

      if (b_bool) {
        k = 2;
      } else {
        k = -1;
      }
    }
  }

  switch (k) {
   case 0:
    /* 'bh_line_homog_CLS:54' case 'SLOPEY' */
    /* 'bh_line_homog_CLS:55' THE_SOL_VEC = THE_SOL_VEC / THE_SOL_VEC(2); */
    mtmp = THE_SOL_VEC[1];
    for (i8 = 0; i8 < 3; i8++) {
      THE_SOL_VEC[i8] = eVec_mat[i8 + 3 * loop_ub] / mtmp;
    }
    break;

   case 1:
    /* 'bh_line_homog_CLS:56' case 'VERT' */
    /* 'bh_line_homog_CLS:57' THE_SOL_VEC = THE_SOL_VEC / THE_SOL_VEC(1); */
    mtmp = THE_SOL_VEC[0];
    for (i8 = 0; i8 < 3; i8++) {
      THE_SOL_VEC[i8] = eVec_mat[i8 + 3 * loop_ub] / mtmp;
    }
    break;

   case 2:
    /* 'bh_line_homog_CLS:58' case 'HORZ' */
    /* 'bh_line_homog_CLS:59' THE_SOL_VEC = THE_SOL_VEC / THE_SOL_VEC(2); */
    mtmp = THE_SOL_VEC[1];
    for (i8 = 0; i8 < 3; i8++) {
      THE_SOL_VEC[i8] = eVec_mat[i8 + 3 * loop_ub] / mtmp;
    }
    break;

   default:
    /* 'bh_line_homog_CLS:60' otherwise */
    /* 'bh_line_homog_CLS:61' error('###_ERROR:  unknown line type'); */
    break;
  }

  /* 'bh_line_homog_CLS:64' OBJ.abd_col = THE_SOL_VEC; */
  /* 'bh_line_homog_CLS:65' OBJ.a       = THE_SOL_VEC(1); */
  *OBJ_a = THE_SOL_VEC[0];

  /* 'bh_line_homog_CLS:66' OBJ.b       = THE_SOL_VEC(2); */
  *OBJ_b = THE_SOL_VEC[1];

  /* 'bh_line_homog_CLS:67' OBJ.d       = THE_SOL_VEC(3); */
  *OBJ_d = THE_SOL_VEC[2];
}

/*
 * function [tf_is_valid, uv_bot, uv_top] = get_roi_intersection_co_ords(OBJ, ulim, vlim)
 * Arguments    : double OBJ_a
 *                double OBJ_b
 *                double OBJ_d
 *                const char OBJ_line_type_data[]
 *                const int OBJ_line_type_size[2]
 *                const double vlim[2]
 *                boolean_T *tf_is_valid
 *                double uv_bot[2]
 *                double uv_top[2]
 * Return Type  : void
 */
void c_bh_line_homog_CLS_get_roi_int(double OBJ_a, double OBJ_b, double OBJ_d,
  const char OBJ_line_type_data[], const int OBJ_line_type_size[2], const double
  vlim[2], boolean_T *tf_is_valid, double uv_bot[2], double uv_top[2])
{
  int i;
  boolean_T b_bool;
  int exitg1;
  static const char cv6[4] = { 'V', 'E', 'R', 'T' };

  double u;
  double v;
  static const char cv7[4] = { 'H', 'O', 'R', 'Z' };

  boolean_T tf_east;
  double b_v;
  boolean_T tf_north;
  boolean_T tf_south;
  double b_u;
  boolean_T the_tf_mat[4];
  double the_UV_mat[8];
  int k;
  int trueCount;
  int tmp_data[4];
  double the_UV_mat_data[8];
  int b_trueCount;
  int b_tmp_data[4];
  double UV_B[2];
  double b_the_UV_mat_data[8];

  /* 'bh_line_homog_CLS:128' [tf_is_valid, uv_bot, uv_top] = LOC_get_roi_intersection_co_ords(OBJ, ulim, vlim); */
  /* 'bh_line_homog_CLS:244' if(1 == coder.target('MATLAB') ) */
  /* 'bh_line_homog_CLS:249' tf_is_valid = false; */
  *tf_is_valid = false;

  /* 'bh_line_homog_CLS:250' uv_bot = [NaN;NaN]; */
  /* 'bh_line_homog_CLS:251' uv_top = [NaN;NaN]; */
  for (i = 0; i < 2; i++) {
    uv_bot[i] = rtNaN;
    uv_top[i] = rtNaN;
  }

  /* 'bh_line_homog_CLS:253' switch(OBJ.line_type) */
  b_bool = false;
  if (OBJ_line_type_size[1] == 4) {
    i = 0;
    do {
      exitg1 = 0;
      if (i + 1 < 5) {
        if (OBJ_line_type_data[i] != cv6[i]) {
          exitg1 = 1;
        } else {
          i++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    i = 0;
  } else {
    b_bool = false;
    if (OBJ_line_type_size[1] == 4) {
      i = 0;
      do {
        exitg1 = 0;
        if (i + 1 < 5) {
          if (OBJ_line_type_data[i] != cv7[i]) {
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      i = 1;
    } else {
      i = -1;
    }
  }

  switch (i) {
   case 0:
    /* 'bh_line_homog_CLS:254' case 'VERT' */
    /* 'bh_line_homog_CLS:255' u = (-1*OBJ.d/OBJ.a); */
    u = -OBJ_d / OBJ_a;

    /* 'bh_line_homog_CLS:256' if( (u <= ulim(2)) && (u>=ulim(1)) ) */
    if ((u <= 320.0) && (u >= 1.0)) {
      /* 'bh_line_homog_CLS:257' uv_bot = [u;vlim(2)]; */
      uv_bot[0] = u;
      uv_bot[1] = vlim[1];

      /* 'bh_line_homog_CLS:258' uv_top = [u;vlim(1)]; */
      uv_top[0] = u;
      uv_top[1] = vlim[0];

      /* 'bh_line_homog_CLS:259' tf_is_valid = true; */
      *tf_is_valid = true;
    }
    break;

   case 1:
    /* 'bh_line_homog_CLS:263' case 'HORZ' */
    /* 'bh_line_homog_CLS:264' v = (-OBJ.d/OBJ.b); */
    v = -OBJ_d / OBJ_b;

    /* 'bh_line_homog_CLS:265' if( (v <= vlim(2)) && (v>=vlim(1)) ) */
    if ((v <= vlim[1]) && (v >= vlim[0])) {
      /* 'bh_line_homog_CLS:266' uv_bot = [ulim(1);v]; */
      uv_bot[0] = 1.0;
      uv_bot[1] = v;

      /* 'bh_line_homog_CLS:267' uv_top = [ulim(2);v]; */
      uv_top[0] = 320.0;
      uv_top[1] = v;

      /* 'bh_line_homog_CLS:268' tf_is_valid = true; */
      *tf_is_valid = true;
    }
    break;

   default:
    /* 'bh_line_homog_CLS:276' my_Vf = @(U) (-1*(OBJ.d + OBJ.a*U)/OBJ.b); */
    /* 'bh_line_homog_CLS:277' my_Uf = @(V) (-1*(OBJ.d + OBJ.b*V)/OBJ.a); */
    /* 'bh_line_homog_CLS:279' [tf_west,  UV_west ] = LOC_get_side_intersect_point('WEST',  my_Vf, my_Uf, ulim, vlim); */
    /*  SUMMARY: */
    /*    for a specified side of an ROI box, where (if at all) */
    /*    does our line intersect that side of teh ROI box */
    /*  BH_LINE_HOMOG_CLS - Regression fit for Homogeneous co-ordinate representation of a line */
    /* ========================================================================== */
    /*  The Homogeneous representation of a line is: */
    /*  */
    /*      a.U + b.V + d = 0 */
    /* ========================================================================== */
    /*  USAGE: */
    /*     OBJ   = bh_line_homog_CLS(u,v); */
    /*   */
    /*     hax = OBJ.plot_simple(u,v);   axis equal; grid on; */
    /*   */
    /*     ulim = [5, 10]; */
    /*     vlim = [-4, 10]; */
    /*   */
    /*     [tf_is_valid, uv_bot, uv_top] = OBJ.get_roi_intersection_co_ords(ulim, vlim); */
    /*   */
    /*     */
    /*     OBJ.plot_intersection(hax, 'r', ulim, vlim, true); */
    /* ========================================================================== */
    /* char {mustBeMember(line_type,{'HORZ','VERT','SLOPEY','UNKNOWN'})} = 'UNKNOWN'; */
    /*  for codegen */
    /*  where's the smallest eigenvalue */
    /*  classify the type of line */
    /*  bh_line_homog_CLS */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*  a.U + b.V + d = 0 */
    /*  then we have a VERTICAL ||| line */
    /*  a COL        */
    /*  a.U + b.V + d = 0 */
    /*  then we have a HORIZONTAL --- line */
    /*  a COL */
    /*  a.U + b.V + d = 0 */
    /*  then we have a SLOPEY ///\\\ line */
    /* ==========================================================================  */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* plot(hax,u,v,'-m','LineWidth',2); */
    /*  plot the line    */
    /*  plot an o for the TOP point */
    /*  plot an o for the BOT point       */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*   b.V = -a.U + -d */
    /*  m */
    /*  c */
    /* ========================================================================== */
    /*  methods */
    /* ========================================================================== */
    /*  classdef */
    /* _######################################################################### */
    /*  Local HELPER functions */
    /* _######################################################################### */
    /*  V */
    /*  U */
    /*  [-pi , pi] */
    /*  [-180, 180] */
    /*  convert angle from [-180,180] to [0, 360] */
    /*  first categorise the NORMAL to the line */
    /*   so we have   0 <= theta_deg <= 360 */
    /*  a tolerence */
    /*  do NOTHING */
    /*  OK: so we know the orientation of the NORMAL vector */
    /*      now we can classify the actual LINE */
    /* LOC_classify_line_type */
    /* ========================================================================== */
    /*  RETURN */
    /*  RETURN */
    /*  so if we made it to here then we have a SLOPEY line */
    /*   a.U + b.V + d = 0 */
    /*  OK: so our line has intersected our ROI box */
    /*  LOC_get_roi_intersection_co_ords() */
    /* ========================================================================== */
    /*  LOC_UV_is_in_box(() */
    /* ========================================================================== */
    /* 'bh_line_homog_CLS:332' UV = [0;0]; */
    /* 'bh_line_homog_CLS:333' tf_valid_intersection = false; */
    b_bool = false;

    /*  assert that our side_str INPUT argument is a valid */
    /* mustBeMember(side_str, ["NORTH","SOUTH","EAST","WEST"] ); */
    /*   */
    /*           0------------------------------> U */
    /*           | */
    /*           |               NORTH */
    /*           |           *-------------* */
    /*           |          |              | */
    /*           |          |              | */
    /*           |    WEST  |              |  EAST */
    /*           |          |              |  */
    /*           |          |              | */
    /*           |          *--------------* */
    /*           |               SOUTH     */
    /*       V   V    */
    /* 'bh_line_homog_CLS:352' FH_in_V_zone = @(V) ( (V <= vlim(2)) & (V >= vlim(1)) ); */
    /* 'bh_line_homog_CLS:353' FH_in_U_zone = @(U) ( (U <= ulim(2)) & (U >= ulim(1)) ); */
    /* 'bh_line_homog_CLS:355' switch(side_str) */
    /* 'bh_line_homog_CLS:356' case 'WEST' */
    /* 'bh_line_homog_CLS:357' u = ulim(1); */
    /* 'bh_line_homog_CLS:357' v = my_Vf(u); */
    v = -(OBJ_d + OBJ_a) / OBJ_b;

    /* 'bh_line_homog_CLS:358' UV = [u;v]; */
    /* 'bh_line_homog_CLS:359' if( FH_in_V_zone(v) ) */
    if ((v <= vlim[1]) && (v >= vlim[0])) {
      /* 'bh_line_homog_CLS:360' tf_valid_intersection = true; */
      b_bool = true;
    }

    /* 'bh_line_homog_CLS:280' [tf_east,  UV_east ] = LOC_get_side_intersect_point('EAST',  my_Vf, my_Uf, ulim, vlim); */
    /*  SUMMARY: */
    /*    for a specified side of an ROI box, where (if at all) */
    /*    does our line intersect that side of teh ROI box */
    /*  BH_LINE_HOMOG_CLS - Regression fit for Homogeneous co-ordinate representation of a line */
    /* ========================================================================== */
    /*  The Homogeneous representation of a line is: */
    /*  */
    /*      a.U + b.V + d = 0 */
    /* ========================================================================== */
    /*  USAGE: */
    /*     OBJ   = bh_line_homog_CLS(u,v); */
    /*   */
    /*     hax = OBJ.plot_simple(u,v);   axis equal; grid on; */
    /*   */
    /*     ulim = [5, 10]; */
    /*     vlim = [-4, 10]; */
    /*   */
    /*     [tf_is_valid, uv_bot, uv_top] = OBJ.get_roi_intersection_co_ords(ulim, vlim); */
    /*   */
    /*     */
    /*     OBJ.plot_intersection(hax, 'r', ulim, vlim, true); */
    /* ========================================================================== */
    /* char {mustBeMember(line_type,{'HORZ','VERT','SLOPEY','UNKNOWN'})} = 'UNKNOWN'; */
    /*  for codegen */
    /*  where's the smallest eigenvalue */
    /*  classify the type of line */
    /*  bh_line_homog_CLS */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*  a.U + b.V + d = 0 */
    /*  then we have a VERTICAL ||| line */
    /*  a COL        */
    /*  a.U + b.V + d = 0 */
    /*  then we have a HORIZONTAL --- line */
    /*  a COL */
    /*  a.U + b.V + d = 0 */
    /*  then we have a SLOPEY ///\\\ line */
    /* ==========================================================================  */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* plot(hax,u,v,'-m','LineWidth',2); */
    /*  plot the line    */
    /*  plot an o for the TOP point */
    /*  plot an o for the BOT point       */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*   b.V = -a.U + -d */
    /*  m */
    /*  c */
    /* ========================================================================== */
    /*  methods */
    /* ========================================================================== */
    /*  classdef */
    /* _######################################################################### */
    /*  Local HELPER functions */
    /* _######################################################################### */
    /*  V */
    /*  U */
    /*  [-pi , pi] */
    /*  [-180, 180] */
    /*  convert angle from [-180,180] to [0, 360] */
    /*  first categorise the NORMAL to the line */
    /*   so we have   0 <= theta_deg <= 360 */
    /*  a tolerence */
    /*  do NOTHING */
    /*  OK: so we know the orientation of the NORMAL vector */
    /*      now we can classify the actual LINE */
    /* LOC_classify_line_type */
    /* ========================================================================== */
    /*  RETURN */
    /*  RETURN */
    /*  so if we made it to here then we have a SLOPEY line */
    /*   a.U + b.V + d = 0 */
    /*  OK: so our line has intersected our ROI box */
    /*  LOC_get_roi_intersection_co_ords() */
    /* ========================================================================== */
    /*  LOC_UV_is_in_box(() */
    /* ========================================================================== */
    /* 'bh_line_homog_CLS:332' UV = [0;0]; */
    /* 'bh_line_homog_CLS:333' tf_valid_intersection = false; */
    tf_east = false;

    /*  assert that our side_str INPUT argument is a valid */
    /* mustBeMember(side_str, ["NORTH","SOUTH","EAST","WEST"] ); */
    /*   */
    /*           0------------------------------> U */
    /*           | */
    /*           |               NORTH */
    /*           |           *-------------* */
    /*           |          |              | */
    /*           |          |              | */
    /*           |    WEST  |              |  EAST */
    /*           |          |              |  */
    /*           |          |              | */
    /*           |          *--------------* */
    /*           |               SOUTH     */
    /*       V   V    */
    /* 'bh_line_homog_CLS:352' FH_in_V_zone = @(V) ( (V <= vlim(2)) & (V >= vlim(1)) ); */
    /* 'bh_line_homog_CLS:353' FH_in_U_zone = @(U) ( (U <= ulim(2)) & (U >= ulim(1)) ); */
    /* 'bh_line_homog_CLS:355' switch(side_str) */
    /* 'bh_line_homog_CLS:362' case 'EAST' */
    /* 'bh_line_homog_CLS:363' u = ulim(2); */
    /* 'bh_line_homog_CLS:363' v = my_Vf(u); */
    b_v = -(OBJ_d + OBJ_a * 320.0) / OBJ_b;

    /* 'bh_line_homog_CLS:364' UV = [u;v]; */
    /* 'bh_line_homog_CLS:365' if( FH_in_V_zone(v) ) */
    if ((b_v <= vlim[1]) && (b_v >= vlim[0])) {
      /* 'bh_line_homog_CLS:366' tf_valid_intersection = true; */
      tf_east = true;
    }

    /* 'bh_line_homog_CLS:281' [tf_north, UV_north] = LOC_get_side_intersect_point('NORTH', my_Vf, my_Uf, ulim, vlim); */
    /*  SUMMARY: */
    /*    for a specified side of an ROI box, where (if at all) */
    /*    does our line intersect that side of teh ROI box */
    /*  BH_LINE_HOMOG_CLS - Regression fit for Homogeneous co-ordinate representation of a line */
    /* ========================================================================== */
    /*  The Homogeneous representation of a line is: */
    /*  */
    /*      a.U + b.V + d = 0 */
    /* ========================================================================== */
    /*  USAGE: */
    /*     OBJ   = bh_line_homog_CLS(u,v); */
    /*   */
    /*     hax = OBJ.plot_simple(u,v);   axis equal; grid on; */
    /*   */
    /*     ulim = [5, 10]; */
    /*     vlim = [-4, 10]; */
    /*   */
    /*     [tf_is_valid, uv_bot, uv_top] = OBJ.get_roi_intersection_co_ords(ulim, vlim); */
    /*   */
    /*     */
    /*     OBJ.plot_intersection(hax, 'r', ulim, vlim, true); */
    /* ========================================================================== */
    /* char {mustBeMember(line_type,{'HORZ','VERT','SLOPEY','UNKNOWN'})} = 'UNKNOWN'; */
    /*  for codegen */
    /*  where's the smallest eigenvalue */
    /*  classify the type of line */
    /*  bh_line_homog_CLS */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*  a.U + b.V + d = 0 */
    /*  then we have a VERTICAL ||| line */
    /*  a COL        */
    /*  a.U + b.V + d = 0 */
    /*  then we have a HORIZONTAL --- line */
    /*  a COL */
    /*  a.U + b.V + d = 0 */
    /*  then we have a SLOPEY ///\\\ line */
    /* ==========================================================================  */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* plot(hax,u,v,'-m','LineWidth',2); */
    /*  plot the line    */
    /*  plot an o for the TOP point */
    /*  plot an o for the BOT point       */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*   b.V = -a.U + -d */
    /*  m */
    /*  c */
    /* ========================================================================== */
    /*  methods */
    /* ========================================================================== */
    /*  classdef */
    /* _######################################################################### */
    /*  Local HELPER functions */
    /* _######################################################################### */
    /*  V */
    /*  U */
    /*  [-pi , pi] */
    /*  [-180, 180] */
    /*  convert angle from [-180,180] to [0, 360] */
    /*  first categorise the NORMAL to the line */
    /*   so we have   0 <= theta_deg <= 360 */
    /*  a tolerence */
    /*  do NOTHING */
    /*  OK: so we know the orientation of the NORMAL vector */
    /*      now we can classify the actual LINE */
    /* LOC_classify_line_type */
    /* ========================================================================== */
    /*  RETURN */
    /*  RETURN */
    /*  so if we made it to here then we have a SLOPEY line */
    /*   a.U + b.V + d = 0 */
    /*  OK: so our line has intersected our ROI box */
    /*  LOC_get_roi_intersection_co_ords() */
    /* ========================================================================== */
    /*  LOC_UV_is_in_box(() */
    /* ========================================================================== */
    /* 'bh_line_homog_CLS:332' UV = [0;0]; */
    /* 'bh_line_homog_CLS:333' tf_valid_intersection = false; */
    tf_north = false;

    /*  assert that our side_str INPUT argument is a valid */
    /* mustBeMember(side_str, ["NORTH","SOUTH","EAST","WEST"] ); */
    /*   */
    /*           0------------------------------> U */
    /*           | */
    /*           |               NORTH */
    /*           |           *-------------* */
    /*           |          |              | */
    /*           |          |              | */
    /*           |    WEST  |              |  EAST */
    /*           |          |              |  */
    /*           |          |              | */
    /*           |          *--------------* */
    /*           |               SOUTH     */
    /*       V   V    */
    /* 'bh_line_homog_CLS:352' FH_in_V_zone = @(V) ( (V <= vlim(2)) & (V >= vlim(1)) ); */
    /* 'bh_line_homog_CLS:353' FH_in_U_zone = @(U) ( (U <= ulim(2)) & (U >= ulim(1)) ); */
    /* 'bh_line_homog_CLS:355' switch(side_str) */
    /* 'bh_line_homog_CLS:368' case 'NORTH' */
    /* 'bh_line_homog_CLS:369' v = vlim(1); */
    /* 'bh_line_homog_CLS:369' u = my_Uf(v); */
    u = -(OBJ_d + OBJ_b * vlim[0]) / OBJ_a;

    /* 'bh_line_homog_CLS:370' UV = [u;v]; */
    /* 'bh_line_homog_CLS:371' if( FH_in_U_zone(u) ) */
    if ((u <= 320.0) && (u >= 1.0)) {
      /* 'bh_line_homog_CLS:372' tf_valid_intersection = true; */
      tf_north = true;
    }

    /* 'bh_line_homog_CLS:282' [tf_south, UV_south] = LOC_get_side_intersect_point('SOUTH', my_Vf, my_Uf, ulim, vlim); */
    /*  SUMMARY: */
    /*    for a specified side of an ROI box, where (if at all) */
    /*    does our line intersect that side of teh ROI box */
    /*  BH_LINE_HOMOG_CLS - Regression fit for Homogeneous co-ordinate representation of a line */
    /* ========================================================================== */
    /*  The Homogeneous representation of a line is: */
    /*  */
    /*      a.U + b.V + d = 0 */
    /* ========================================================================== */
    /*  USAGE: */
    /*     OBJ   = bh_line_homog_CLS(u,v); */
    /*   */
    /*     hax = OBJ.plot_simple(u,v);   axis equal; grid on; */
    /*   */
    /*     ulim = [5, 10]; */
    /*     vlim = [-4, 10]; */
    /*   */
    /*     [tf_is_valid, uv_bot, uv_top] = OBJ.get_roi_intersection_co_ords(ulim, vlim); */
    /*   */
    /*     */
    /*     OBJ.plot_intersection(hax, 'r', ulim, vlim, true); */
    /* ========================================================================== */
    /* char {mustBeMember(line_type,{'HORZ','VERT','SLOPEY','UNKNOWN'})} = 'UNKNOWN'; */
    /*  for codegen */
    /*  where's the smallest eigenvalue */
    /*  classify the type of line */
    /*  bh_line_homog_CLS */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*  a.U + b.V + d = 0 */
    /*  then we have a VERTICAL ||| line */
    /*  a COL        */
    /*  a.U + b.V + d = 0 */
    /*  then we have a HORIZONTAL --- line */
    /*  a COL */
    /*  a.U + b.V + d = 0 */
    /*  then we have a SLOPEY ///\\\ line */
    /* ==========================================================================  */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* ========================================================================== */
    /* ========================================================================== */
    /*  this is purely a visualization method */
    /*  so NONE of it is releveant for a CODER deployment */
    /* plot(hax,u,v,'-m','LineWidth',2); */
    /*  plot the line    */
    /*  plot an o for the TOP point */
    /*  plot an o for the BOT point       */
    /* ========================================================================== */
    /*  a.U + b.V + d = 0 */
    /*   b.V = -a.U + -d */
    /*  m */
    /*  c */
    /* ========================================================================== */
    /*  methods */
    /* ========================================================================== */
    /*  classdef */
    /* _######################################################################### */
    /*  Local HELPER functions */
    /* _######################################################################### */
    /*  V */
    /*  U */
    /*  [-pi , pi] */
    /*  [-180, 180] */
    /*  convert angle from [-180,180] to [0, 360] */
    /*  first categorise the NORMAL to the line */
    /*   so we have   0 <= theta_deg <= 360 */
    /*  a tolerence */
    /*  do NOTHING */
    /*  OK: so we know the orientation of the NORMAL vector */
    /*      now we can classify the actual LINE */
    /* LOC_classify_line_type */
    /* ========================================================================== */
    /*  RETURN */
    /*  RETURN */
    /*  so if we made it to here then we have a SLOPEY line */
    /*   a.U + b.V + d = 0 */
    /*  OK: so our line has intersected our ROI box */
    /*  LOC_get_roi_intersection_co_ords() */
    /* ========================================================================== */
    /*  LOC_UV_is_in_box(() */
    /* ========================================================================== */
    /* 'bh_line_homog_CLS:332' UV = [0;0]; */
    /* 'bh_line_homog_CLS:333' tf_valid_intersection = false; */
    tf_south = false;

    /*  assert that our side_str INPUT argument is a valid */
    /* mustBeMember(side_str, ["NORTH","SOUTH","EAST","WEST"] ); */
    /*   */
    /*           0------------------------------> U */
    /*           | */
    /*           |               NORTH */
    /*           |           *-------------* */
    /*           |          |              | */
    /*           |          |              | */
    /*           |    WEST  |              |  EAST */
    /*           |          |              |  */
    /*           |          |              | */
    /*           |          *--------------* */
    /*           |               SOUTH     */
    /*       V   V    */
    /* 'bh_line_homog_CLS:352' FH_in_V_zone = @(V) ( (V <= vlim(2)) & (V >= vlim(1)) ); */
    /* 'bh_line_homog_CLS:353' FH_in_U_zone = @(U) ( (U <= ulim(2)) & (U >= ulim(1)) ); */
    /* 'bh_line_homog_CLS:355' switch(side_str) */
    /* 'bh_line_homog_CLS:374' case 'SOUTH' */
    /* 'bh_line_homog_CLS:375' v = vlim(2); */
    /* 'bh_line_homog_CLS:375' u = my_Uf(v); */
    b_u = -(OBJ_d + OBJ_b * vlim[1]) / OBJ_a;

    /* 'bh_line_homog_CLS:376' UV = [u;v]; */
    /* 'bh_line_homog_CLS:377' if( FH_in_U_zone(u) ) */
    if ((b_u <= 320.0) && (b_u >= 1.0)) {
      /* 'bh_line_homog_CLS:378' tf_valid_intersection = true; */
      tf_south = true;
    }

    /* 'bh_line_homog_CLS:284' the_tf_mat = [tf_west, tf_east, tf_north, tf_south]; */
    the_tf_mat[0] = b_bool;
    the_tf_mat[1] = tf_east;
    the_tf_mat[2] = tf_north;
    the_tf_mat[3] = tf_south;

    /* 'bh_line_homog_CLS:285' the_UV_mat = [UV_west, UV_east, UV_north, UV_south]; */
    the_UV_mat[0] = 1.0;
    the_UV_mat[1] = v;
    the_UV_mat[2] = 320.0;
    the_UV_mat[3] = b_v;
    the_UV_mat[4] = u;
    the_UV_mat[5] = vlim[0];
    the_UV_mat[6] = b_u;
    the_UV_mat[7] = vlim[1];

    /* 'bh_line_homog_CLS:287' if(2 ~= nnz(the_tf_mat) ) */
    i = 0;
    for (k = 0; k < 4; k++) {
      if (the_tf_mat[k]) {
        i++;
      }
    }

    if (2 == i) {
      /* 'bh_line_homog_CLS:293' THE_SOL_UV_mat = the_UV_mat(:,the_tf_mat ); */
      /* 'bh_line_homog_CLS:295' UV_A = THE_SOL_UV_mat(:,1); */
      trueCount = 0;
      for (i = 0; i < 4; i++) {
        if (the_tf_mat[i]) {
          trueCount++;
        }
      }

      k = 0;
      for (i = 0; i < 4; i++) {
        if (the_tf_mat[i]) {
          tmp_data[k] = i + 1;
          k++;
        }
      }

      for (k = 0; k < trueCount; k++) {
        for (i = 0; i < 2; i++) {
          the_UV_mat_data[i + (k << 1)] = the_UV_mat[i + ((tmp_data[k] - 1) << 1)];
        }
      }

      for (k = 0; k < 2; k++) {
        uv_top[k] = the_UV_mat_data[k];
      }

      /* 'bh_line_homog_CLS:296' UV_B = THE_SOL_UV_mat(:,2); */
      b_trueCount = 0;
      for (i = 0; i < 4; i++) {
        if (the_tf_mat[i]) {
          b_trueCount++;
        }
      }

      k = 0;
      for (i = 0; i < 4; i++) {
        if (the_tf_mat[i]) {
          b_tmp_data[k] = i + 1;
          k++;
        }
      }

      for (k = 0; k < b_trueCount; k++) {
        for (i = 0; i < 2; i++) {
          the_UV_mat_data[i + (k << 1)] = the_UV_mat[i + ((b_tmp_data[k] - 1) <<
            1)];
        }
      }

      for (k = 0; k < 2; k++) {
        UV_B[k] = the_UV_mat_data[k + 2];
      }

      /* 'bh_line_homog_CLS:298' if( UV_A(2) > UV_B(2)) */
      for (k = 0; k < trueCount; k++) {
        for (i = 0; i < 2; i++) {
          the_UV_mat_data[i + (k << 1)] = the_UV_mat[i + ((tmp_data[k] - 1) << 1)];
        }
      }

      for (k = 0; k < b_trueCount; k++) {
        for (i = 0; i < 2; i++) {
          b_the_UV_mat_data[i + (k << 1)] = the_UV_mat[i + ((b_tmp_data[k] - 1) <<
            1)];
        }
      }

      if (the_UV_mat_data[1] > b_the_UV_mat_data[3]) {
        /* 'bh_line_homog_CLS:299' uv_bot = UV_A; */
        /* 'bh_line_homog_CLS:300' uv_top = UV_B; */
        for (i = 0; i < 2; i++) {
          uv_bot[i] = uv_top[i];
          uv_top[i] = UV_B[i];
        }
      } else {
        /* 'bh_line_homog_CLS:301' else */
        /* 'bh_line_homog_CLS:302' uv_bot = UV_B; */
        for (i = 0; i < 2; i++) {
          uv_bot[i] = UV_B[i];
        }

        /* 'bh_line_homog_CLS:303' uv_top = UV_A; */
      }

      /* 'bh_line_homog_CLS:305' tf_is_valid = true; */
      *tf_is_valid = true;
    }
    break;
  }
}

/*
 * File trailer for bh_line_homog_CLS.c
 *
 * [EOF]
 */
