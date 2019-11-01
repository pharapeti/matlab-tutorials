/*
 * File: lane_info_CLS.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "lane_info_CLS.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "bh_line_homog_CLS.h"
#include "abs.h"
#include "diag.h"
#include "eig.h"
#include "box_info_CLS.h"
#include "bh_my_detect_ALGORITHM_for_codegen_rtwutil.h"

/* Function Declarations */
static void lane_info_CLS_calc_info(lane_info_CLS *OBJ);

/* Function Definitions */

/*
 * function OBJ = calc_info(OBJ, ulim, vlim)
 * Arguments    : lane_info_CLS *OBJ
 * Return Type  : void
 */
static void lane_info_CLS_calc_info(lane_info_CLS *OBJ)
{
  emxArray_int32_T *ii;
  double the_size[2];
  int nx;
  int idx;
  int i22;
  int b_ii;
  boolean_T exitg1;
  emxArray_int32_T *r10;
  emxArray_int32_T *c_ii;
  emxArray_int32_T *v1;
  emxArray_int32_T *vk;
  emxArray_int32_T *y;
  emxArray_int32_T *x;
  emxArray_int32_T *b_x;
  emxArray_int32_T *b_y;
  emxArray_int32_T *A;
  emxArray_int32_T *a;
  double temp;
  int k;
  double eVec_mat[9];
  double b_eVec_mat[9];
  creal_T dcv0[9];
  creal_T dcv1[9];
  double dv3[3];
  double THE_SOL_VEC[3];
  char LO_OBJ_line_type_data[6];
  int LO_OBJ_line_type_size[2];
  boolean_T b_bool;
  int exitg2;
  static const char cv5[6] = { 'S', 'L', 'O', 'P', 'E', 'Y' };

  static const char cv6[4] = { 'V', 'E', 'R', 'T' };

  static const char cv7[4] = { 'H', 'O', 'R', 'Z' };

  double dv4[2];
  double uv_top[2];
  double mc_col[2];

  /*  is_detected() */
  /* --------------------------------------------------------------------------  */
  /* 'lane_info_CLS:38' if( ~OBJ.is_detected() ) */
  /* --------------------------------------------------------------------------   */
  /* 'lane_info_CLS:34' tf_detected = OBJ.tf_is_detected; */
  if (OBJ->tf_is_detected) {
    emxInit_int32_T(&ii, 1);

    /* 'lane_info_CLS:42' if(1==nargin) */
    /* 'lane_info_CLS:43' ulim = [1, OBJ.NUM_COLS]; */
    /* 'lane_info_CLS:44' vlim = [1, OBJ.NUM_ROWS]; */
    /*  OK: if we're here we have a lane */
    /* 'lane_info_CLS:48' the_size = [OBJ.NUM_ROWS, OBJ.NUM_COLS]; */
    the_size[0] = OBJ->NUM_ROWS;

    /* 'lane_info_CLS:49' the_ind  = find(OBJ.BW); */
    nx = OBJ->BW->size[0] * 320;
    idx = 0;
    i22 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity_int32_T(ii, i22);
    b_ii = 1;
    exitg1 = false;
    while ((!exitg1) && (b_ii <= nx)) {
      i22 = OBJ->BW->size[0];
      if (OBJ->BW->data[(b_ii - 1) % i22 * 320 + (b_ii - 1) / i22]) {
        idx++;
        ii->data[idx - 1] = b_ii;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          b_ii++;
        }
      } else {
        b_ii++;
      }
    }

    if (1 > idx) {
      nx = 0;
    } else {
      nx = idx;
    }

    emxInit_int32_T(&r10, 1);
    i22 = r10->size[0];
    r10->size[0] = nx;
    emxEnsureCapacity_int32_T(r10, i22);
    for (i22 = 0; i22 < nx; i22++) {
      r10->data[i22] = i22;
    }

    emxInit_int32_T(&c_ii, 1);
    nx = r10->size[0];
    i22 = c_ii->size[0];
    c_ii->size[0] = nx;
    emxEnsureCapacity_int32_T(c_ii, i22);
    for (i22 = 0; i22 < nx; i22++) {
      c_ii->data[i22] = ii->data[r10->data[i22]];
    }

    emxFree_int32_T(&r10);
    i22 = ii->size[0];
    ii->size[0] = c_ii->size[0];
    emxEnsureCapacity_int32_T(ii, i22);
    nx = c_ii->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      ii->data[i22] = c_ii->data[i22];
    }

    emxFree_int32_T(&c_ii);
    emxInit_int32_T(&v1, 1);

    /* 'lane_info_CLS:50' [y,x]    = ind2sub(the_size,the_ind); */
    i22 = v1->size[0];
    v1->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(v1, i22);
    nx = ii->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      v1->data[i22] = ii->data[i22] - 1;
    }

    emxFree_int32_T(&ii);
    emxInit_int32_T(&vk, 1);
    i22 = vk->size[0];
    vk->size[0] = v1->size[0];
    emxEnsureCapacity_int32_T(vk, i22);
    nx = v1->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      vk->data[i22] = div_s32(v1->data[i22], (int)the_size[0]);
    }

    i22 = v1->size[0];
    emxEnsureCapacity_int32_T(v1, i22);
    nx = v1->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      v1->data[i22] -= vk->data[i22] * (int)the_size[0];
    }

    emxInit_int32_T(&y, 1);
    i22 = y->size[0];
    y->size[0] = v1->size[0];
    emxEnsureCapacity_int32_T(y, i22);
    nx = v1->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      y->data[i22] = v1->data[i22] + 1;
    }

    emxFree_int32_T(&v1);
    emxInit_int32_T(&x, 1);
    i22 = x->size[0];
    x->size[0] = vk->size[0];
    emxEnsureCapacity_int32_T(x, i22);
    nx = vk->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      x->data[i22] = vk->data[i22] + 1;
    }

    emxFree_int32_T(&vk);
    emxInit_int32_T(&b_x, 1);

    /*  convert INDS to SUBSCRIPTS */
    /*  create a homogenous line object */
    /* 'lane_info_CLS:53' LO_OBJ   = bh_line_homog_CLS(x,y); */
    /* 'bh_line_homog_CLS:33' u = u(:); */
    i22 = b_x->size[0];
    b_x->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(b_x, i22);
    nx = x->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      b_x->data[i22] = x->data[i22];
    }

    emxFree_int32_T(&x);
    emxInit_int32_T(&b_y, 1);

    /* 'bh_line_homog_CLS:34' v = v(:); */
    i22 = b_y->size[0];
    b_y->size[0] = y->size[0];
    emxEnsureCapacity_int32_T(b_y, i22);
    nx = y->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      b_y->data[i22] = y->data[i22];
    }

    emxFree_int32_T(&y);
    emxInit_int32_T1(&A, 2);

    /* 'bh_line_homog_CLS:35' A = [u,v, ones(size(u))]; */
    the_size[0] = b_x->size[0];
    nx = b_x->size[0];
    b_ii = b_y->size[0];
    i22 = A->size[0] * A->size[1];
    A->size[1] = 3;
    A->size[0] = nx;
    emxEnsureCapacity_int32_T1(A, i22);
    for (i22 = 0; i22 < nx; i22++) {
      A->data[A->size[1] * i22] = b_x->data[i22];
    }

    emxFree_int32_T(&b_x);
    for (i22 = 0; i22 < b_ii; i22++) {
      A->data[1 + A->size[1] * i22] = b_y->data[i22];
    }

    emxFree_int32_T(&b_y);
    nx = (int)the_size[0];
    for (i22 = 0; i22 < nx; i22++) {
      A->data[2 + A->size[1] * i22] = 1;
    }

    emxInit_int32_T1(&a, 2);

    /* 'bh_line_homog_CLS:36' B = [1,0,0; */
    /* 'bh_line_homog_CLS:37'      0,1,0]; */
    /* 'bh_line_homog_CLS:38' [eVec_mat, eVal_mat] = eig(A'* A,  B'*B); */
    i22 = a->size[0] * a->size[1];
    a->size[1] = A->size[0];
    a->size[0] = 3;
    emxEnsureCapacity_int32_T1(a, i22);
    for (i22 = 0; i22 < 3; i22++) {
      nx = A->size[0];
      for (b_ii = 0; b_ii < nx; b_ii++) {
        a->data[b_ii + a->size[1] * i22] = A->data[i22 + A->size[1] * b_ii];
      }
    }

    if ((a->size[1] == 1) || (A->size[0] == 1)) {
      nx = A->size[0];
      for (i22 = 0; i22 < 3; i22++) {
        for (b_ii = 0; b_ii < 3; b_ii++) {
          eVec_mat[i22 + 3 * b_ii] = 0.0;
          for (k = 0; k < nx; k++) {
            eVec_mat[i22 + 3 * b_ii] += (double)A->data[i22 + A->size[1] * k] *
              (double)a->data[k + a->size[1] * b_ii];
          }
        }
      }
    } else {
      for (b_ii = 0; b_ii < 3; b_ii++) {
        for (nx = 0; nx < 3; nx++) {
          temp = 0.0;
          for (k = 0; k < a->size[1]; k++) {
            temp += (double)a->data[k + a->size[1] * b_ii] * (double)A->data[nx
              + A->size[1] * k];
          }

          eVec_mat[nx + 3 * b_ii] = temp;
        }
      }
    }

    emxFree_int32_T(&a);
    emxFree_int32_T(&A);
    for (i22 = 0; i22 < 3; i22++) {
      for (b_ii = 0; b_ii < 3; b_ii++) {
        b_eVec_mat[b_ii + 3 * i22] = eVec_mat[i22 + 3 * b_ii];
      }
    }

    eig(b_eVec_mat, dcv0, dcv1);

    /* 'bh_line_homog_CLS:41' eVec_mat = real(eVec_mat); */
    /* 'bh_line_homog_CLS:42' eVal_mat = real(eVal_mat); */
    /* 'bh_line_homog_CLS:45' [~,ind]     = min(abs(diag(eVal_mat))); */
    for (i22 = 0; i22 < 3; i22++) {
      for (b_ii = 0; b_ii < 3; b_ii++) {
        eVec_mat[b_ii + 3 * i22] = dcv0[i22 + 3 * b_ii].re;
        b_eVec_mat[b_ii + 3 * i22] = dcv1[i22 + 3 * b_ii].re;
      }
    }

    diag(b_eVec_mat, dv3);
    b_abs(dv3, THE_SOL_VEC);
    if (!rtIsNaN(THE_SOL_VEC[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!rtIsNaN(THE_SOL_VEC[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx != 0) {
      temp = THE_SOL_VEC[idx - 1];
      nx = idx - 1;
      while (idx + 1 < 4) {
        if (temp > THE_SOL_VEC[idx]) {
          temp = THE_SOL_VEC[idx];
          nx = idx;
        }

        idx++;
      }

      idx = nx;
    }

    /* 'bh_line_homog_CLS:45' ~ */
    /* 'bh_line_homog_CLS:47' THE_SOL_VEC = eVec_mat(:,ind); */
    for (i22 = 0; i22 < 3; i22++) {
      THE_SOL_VEC[i22] = dcv0[i22 + 3 * idx].re;
    }

    /* 'bh_line_homog_CLS:48' normal_vec  = THE_SOL_VEC(1:2); */
    /* 'bh_line_homog_CLS:51' OBJ.line_type = LOC_classify_line_type(normal_vec); */
    for (b_ii = 0; b_ii < 2; b_ii++) {
      the_size[b_ii] = THE_SOL_VEC[b_ii];
    }

    LOC_classify_line_type(the_size, LO_OBJ_line_type_data,
      LO_OBJ_line_type_size);

    /* 'bh_line_homog_CLS:53' switch(OBJ.line_type) */
    b_bool = false;
    if (LO_OBJ_line_type_size[1] == 6) {
      nx = 0;
      do {
        exitg2 = 0;
        if (nx + 1 < 7) {
          if (LO_OBJ_line_type_data[nx] != cv5[nx]) {
            exitg2 = 1;
          } else {
            nx++;
          }
        } else {
          b_bool = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }

    if (b_bool) {
      nx = 0;
    } else {
      b_bool = false;
      if (LO_OBJ_line_type_size[1] == 4) {
        nx = 0;
        do {
          exitg2 = 0;
          if (nx + 1 < 5) {
            if (LO_OBJ_line_type_data[nx] != cv6[nx]) {
              exitg2 = 1;
            } else {
              nx++;
            }
          } else {
            b_bool = true;
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }

      if (b_bool) {
        nx = 1;
      } else {
        b_bool = false;
        if (LO_OBJ_line_type_size[1] == 4) {
          nx = 0;
          do {
            exitg2 = 0;
            if (nx + 1 < 5) {
              if (LO_OBJ_line_type_data[nx] != cv7[nx]) {
                exitg2 = 1;
              } else {
                nx++;
              }
            } else {
              b_bool = true;
              exitg2 = 1;
            }
          } while (exitg2 == 0);
        }

        if (b_bool) {
          nx = 2;
        } else {
          nx = -1;
        }
      }
    }

    switch (nx) {
     case 0:
      /* 'bh_line_homog_CLS:54' case 'SLOPEY' */
      /* 'bh_line_homog_CLS:55' THE_SOL_VEC = THE_SOL_VEC / THE_SOL_VEC(2); */
      temp = THE_SOL_VEC[1];
      for (i22 = 0; i22 < 3; i22++) {
        THE_SOL_VEC[i22] = eVec_mat[idx + 3 * i22] / temp;
      }
      break;

     case 1:
      /* 'bh_line_homog_CLS:56' case 'VERT' */
      /* 'bh_line_homog_CLS:57' THE_SOL_VEC = THE_SOL_VEC / THE_SOL_VEC(1); */
      temp = THE_SOL_VEC[0];
      for (i22 = 0; i22 < 3; i22++) {
        THE_SOL_VEC[i22] = eVec_mat[idx + 3 * i22] / temp;
      }
      break;

     case 2:
      /* 'bh_line_homog_CLS:58' case 'HORZ' */
      /* 'bh_line_homog_CLS:59' THE_SOL_VEC = THE_SOL_VEC / THE_SOL_VEC(2); */
      temp = THE_SOL_VEC[1];
      for (i22 = 0; i22 < 3; i22++) {
        THE_SOL_VEC[i22] = eVec_mat[idx + 3 * i22] / temp;
      }
      break;

     default:
      /* 'bh_line_homog_CLS:60' otherwise */
      /* 'bh_line_homog_CLS:61' error('###_ERROR:  unknown line type'); */
      break;
    }

    /* 'bh_line_homog_CLS:64' OBJ.abd_col = THE_SOL_VEC; */
    /* 'bh_line_homog_CLS:65' OBJ.a       = THE_SOL_VEC(1); */
    /* 'bh_line_homog_CLS:66' OBJ.b       = THE_SOL_VEC(2); */
    /* 'bh_line_homog_CLS:67' OBJ.d       = THE_SOL_VEC(3); */
    /* 'lane_info_CLS:55' [tf_is_valid, uv_bot, uv_top] = LO_OBJ.get_roi_intersection_co_ords(ulim, vlim); */
    dv4[0] = 1.0;
    dv4[1] = OBJ->NUM_ROWS;
    c_bh_line_homog_CLS_get_roi_int(THE_SOL_VEC[0], THE_SOL_VEC[1], THE_SOL_VEC
      [2], LO_OBJ_line_type_data, LO_OBJ_line_type_size, dv4, &b_bool, the_size,
      uv_top);

    /*  take care of the OUTPUTS */
    /* 'lane_info_CLS:58' OBJ.tip_upper_xy_col  = uv_top; */
    for (b_ii = 0; b_ii < 2; b_ii++) {
      OBJ->tip_upper_xy_col[b_ii] = uv_top[b_ii];
    }

    /* 'lane_info_CLS:59' OBJ.tip_lower_xy_col  = uv_bot; */
    for (i22 = 0; i22 < 2; i22++) {
      OBJ->tip_lower_xy_col[i22] = the_size[i22];
    }

    /*  get equation of the line */
    /*  :  y = mx + c */
    /* 'lane_info_CLS:63' mc_col = LO_OBJ.get_mc(); */
    /* 'bh_line_homog_CLS:174' mc_col = [NaN;NaN]; */
    /* 'bh_line_homog_CLS:176' if( true==OBJ.isSlopey()  ) */
    /* 'bh_line_homog_CLS:79' tf_val = strcmp(OBJ.line_type,'SLOPEY'); */
    b_bool = false;
    if (LO_OBJ_line_type_size[1] == 6) {
      nx = 0;
      do {
        exitg2 = 0;
        if (nx + 1 < 7) {
          if (LO_OBJ_line_type_data[nx] != cv5[nx]) {
            exitg2 = 1;
          } else {
            nx++;
          }
        } else {
          b_bool = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }

    if (b_bool) {
      /* 'bh_line_homog_CLS:180' mc_col(1) = (-1*OBJ.a) / OBJ.b; */
      mc_col[0] = -THE_SOL_VEC[0] / THE_SOL_VEC[1];

      /* 'bh_line_homog_CLS:181' mc_col(2) = (-1*OBJ.d) / OBJ.b; */
      mc_col[1] = -THE_SOL_VEC[2] / THE_SOL_VEC[1];
    } else {
      /* 'bh_line_homog_CLS:182' else */
      /* 'bh_line_homog_CLS:183' mc_col = [NaN;  NaN]; */
      for (b_ii = 0; b_ii < 2; b_ii++) {
        mc_col[b_ii] = rtNaN;
      }
    }

    /* LOC_get_side_intersect_point */
    /* ========================================================================== */
    /* OBJ.fh_line = @(x) (m*x + c); */
    /* 'lane_info_CLS:66' OBJ.m       = mc_col(1); */
    OBJ->m = mc_col[0];

    /* 'lane_info_CLS:67' OBJ.c       = mc_col(2); */
    OBJ->c = mc_col[1];
  }
}

/*
 * function my_S = convert_to_struct(OBJ)
 * ATTENTION(R2017b):
 *  the following usage is NOT supported by the MATLAB Coder:
 *    >> struct(OBJ)
 * Arguments    : const emxArray_boolean_T *OBJ_BW
 *                double OBJ_NUM_ROWS
 *                const double OBJ_tip_upper_xy_col[2]
 *                const double OBJ_tip_lower_xy_col[2]
 *                double OBJ_m
 *                double OBJ_c
 *                boolean_T OBJ_tf_is_detected
 *                emxArray_boolean_T *my_S_BW
 *                double *my_S_NUM_ROWS
 *                double *my_S_NUM_COLS
 *                double my_S_tip_upper_xy_col[2]
 *                double my_S_tip_lower_xy_col[2]
 *                double *my_S_m
 *                double *my_S_c
 *                boolean_T *my_S_tf_is_detected
 * Return Type  : void
 */
void lane_info_CLS_convert_to_struct(const emxArray_boolean_T *OBJ_BW, double
  OBJ_NUM_ROWS, const double OBJ_tip_upper_xy_col[2], const double
  OBJ_tip_lower_xy_col[2], double OBJ_m, double OBJ_c, boolean_T
  OBJ_tf_is_detected, emxArray_boolean_T *my_S_BW, double *my_S_NUM_ROWS, double
  *my_S_NUM_COLS, double my_S_tip_upper_xy_col[2], double my_S_tip_lower_xy_col
  [2], double *my_S_m, double *my_S_c, boolean_T *my_S_tf_is_detected)
{
  int i;
  int loop_ub;

  /* --------------------------------------------------------------------------   */
  /* 'lane_info_CLS:101' my_S.BW               = OBJ.BW; */
  i = my_S_BW->size[0] * my_S_BW->size[1];
  my_S_BW->size[1] = 320;
  my_S_BW->size[0] = OBJ_BW->size[0];
  emxEnsureCapacity_boolean_T(my_S_BW, i);
  loop_ub = OBJ_BW->size[1] * OBJ_BW->size[0];
  for (i = 0; i < loop_ub; i++) {
    my_S_BW->data[i] = OBJ_BW->data[i];
  }

  /* 'lane_info_CLS:102' my_S.NUM_ROWS         = OBJ.NUM_ROWS; */
  /* 'lane_info_CLS:103' my_S.NUM_COLS         = OBJ.NUM_COLS; */
  /* 'lane_info_CLS:104' my_S.tip_upper_xy_col = OBJ.tip_upper_xy_col; */
  for (i = 0; i < 2; i++) {
    my_S_tip_upper_xy_col[i] = OBJ_tip_upper_xy_col[i];
  }

  /* 'lane_info_CLS:105' my_S.tip_lower_xy_col = OBJ.tip_lower_xy_col; */
  for (i = 0; i < 2; i++) {
    my_S_tip_lower_xy_col[i] = OBJ_tip_lower_xy_col[i];
  }

  /* 'lane_info_CLS:106' my_S.m                = OBJ.m; */
  /* 'lane_info_CLS:107' my_S.c                = OBJ.c; */
  /* 'lane_info_CLS:108' my_S.tf_is_detected   = OBJ.tf_is_detected; */
  /* --------------------------------------------------------------------------   */
  /*  methods() */
  /* _######################################################################### */
  /*  classdef() */
  /* _######################################################################### */
  /*  END CLASSDEF */
  /* _######################################################################### */
  *my_S_NUM_ROWS = OBJ_NUM_ROWS;
  *my_S_NUM_COLS = 320.0;
  *my_S_m = OBJ_m;
  *my_S_c = OBJ_c;
  *my_S_tf_is_detected = OBJ_tf_is_detected;
}

/*
 * function OBJ = lane_info_CLS(BW, tf_found)
 * Arguments    : const emxArray_boolean_T *BW
 *                boolean_T tf_found
 *                lane_info_CLS *OBJ
 * Return Type  : void
 */
void lane_info_CLS_lane_info_CLS(const emxArray_boolean_T *BW, boolean_T
  tf_found, lane_info_CLS *OBJ)
{
  int i;
  int loop_ub;
  for (i = 0; i < 2; i++) {
    OBJ->tip_upper_xy_col[i] = 0.0;
  }

  for (i = 0; i < 2; i++) {
    OBJ->tip_lower_xy_col[i] = 0.0;
  }

  OBJ->m = 0.0;
  OBJ->c = 0.0;

  /*  ATTENTION: */
  /*  I want this class to be MATLAB CODER friendly, hence I have prepopulated */
  /*  some properties with NaNs */
  /* --------------------------------- */
  /*  closest to TOP of image */
  /*  closest to BOTTOM of image */
  /* fh_line; */
  /* --------------------------------- */
  /* _######################################################################### */
  /* 'lane_info_CLS:23' OBJ.BW             = BW; */
  i = OBJ->BW->size[0] * OBJ->BW->size[1];
  OBJ->BW->size[1] = 320;
  OBJ->BW->size[0] = BW->size[0];
  emxEnsureCapacity_boolean_T(OBJ->BW, i);
  loop_ub = BW->size[1] * BW->size[0];
  for (i = 0; i < loop_ub; i++) {
    OBJ->BW->data[i] = BW->data[i];
  }

  /* 'lane_info_CLS:25' OBJ.NUM_ROWS       = size(BW,1); */
  OBJ->NUM_ROWS = BW->size[0];

  /* 'lane_info_CLS:26' OBJ.NUM_COLS       = size(BW,2); */
  OBJ->NUM_COLS = 320.0;

  /* 'lane_info_CLS:28' OBJ.tf_is_detected = tf_found; */
  OBJ->tf_is_detected = tf_found;

  /* 'lane_info_CLS:30' OBJ = OBJ.calc_info(); */
  lane_info_CLS_calc_info(OBJ);
}

/*
 * File trailer for lane_info_CLS.c
 *
 * [EOF]
 */
