/*
 * File: lane_info_CLS.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "lane_info_CLS.h"
#include "bh_MY_CV_ALGORITHMS_emxutil.h"
#include "bh_line_homog_CLS.h"
#include "box_info_CLS.h"
#include "bh_MY_CV_ALGORITHMS_rtwutil.h"

/* Function Definitions */

/*
 * function OBJ = calc_info(OBJ, ulim, vlim)
 * Arguments    : lane_info_CLS_1 *OBJ
 *                const double vlim[2]
 * Return Type  : void
 */
void b_lane_info_CLS_calc_info(lane_info_CLS_1 *OBJ, const double vlim[2])
{
  emxArray_int32_T *ii;
  int idx;
  int i26;
  int i;
  boolean_T exitg1;
  emxArray_int32_T *v1;
  emxArray_int32_T *vk;
  emxArray_real_T *b_vk;
  emxArray_real_T *b_v1;
  double LO_OBJ_a;
  double LO_OBJ_b;
  double LO_OBJ_d;
  char LO_OBJ_line_type_data[6];
  int LO_OBJ_line_type_size[2];
  boolean_T tf_is_valid;
  double mc_col[2];
  double uv_top[2];

  /*  is_detected() */
  /* --------------------------------------------------------------------------  */
  /* 'lane_info_CLS:38' if( ~OBJ.is_detected() ) */
  /* --------------------------------------------------------------------------   */
  /* 'lane_info_CLS:34' tf_detected = OBJ.tf_is_detected; */
  if (OBJ->tf_is_detected) {
    emxInit_int32_T(&ii, 1);

    /* 'lane_info_CLS:42' if(1==nargin) */
    /*  OK: if we're here we have a lane */
    /* 'lane_info_CLS:48' the_size = [OBJ.NUM_ROWS, OBJ.NUM_COLS]; */
    /* 'lane_info_CLS:49' the_ind  = find(OBJ.BW); */
    idx = 0;
    i26 = ii->size[0];
    ii->size[0] = 76800;
    emxEnsureCapacity_int32_T(ii, i26);
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 76801)) {
      if (OBJ->BW[i - 1]) {
        idx++;
        ii->data[idx - 1] = i;
        if (idx >= 76800) {
          exitg1 = true;
        } else {
          i++;
        }
      } else {
        i++;
      }
    }

    emxInit_int32_T(&v1, 1);
    i26 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(ii, i26);

    /* 'lane_info_CLS:50' [y,x]    = ind2sub(the_size,the_ind); */
    i26 = v1->size[0];
    v1->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(v1, i26);
    i = ii->size[0];
    for (i26 = 0; i26 < i; i26++) {
      v1->data[i26] = ii->data[i26] - 1;
    }

    emxFree_int32_T(&ii);
    emxInit_int32_T(&vk, 1);
    i26 = vk->size[0];
    vk->size[0] = v1->size[0];
    emxEnsureCapacity_int32_T(vk, i26);
    i = v1->size[0];
    for (i26 = 0; i26 < i; i26++) {
      vk->data[i26] = v1->data[i26] / 240;
    }

    i26 = v1->size[0];
    emxEnsureCapacity_int32_T(v1, i26);
    i = v1->size[0];
    for (i26 = 0; i26 < i; i26++) {
      v1->data[i26] -= vk->data[i26] * 240;
    }

    emxInit_real_T1(&b_vk, 1);

    /*  convert INDS to SUBSCRIPTS */
    /*  create a homogenous line object */
    /* 'lane_info_CLS:53' LO_OBJ   = bh_line_homog_CLS(x,y); */
    i26 = b_vk->size[0];
    b_vk->size[0] = vk->size[0];
    emxEnsureCapacity_real_T1(b_vk, i26);
    i = vk->size[0];
    for (i26 = 0; i26 < i; i26++) {
      b_vk->data[i26] = (double)vk->data[i26] + 1.0;
    }

    emxFree_int32_T(&vk);
    emxInit_real_T1(&b_v1, 1);
    i26 = b_v1->size[0];
    b_v1->size[0] = v1->size[0];
    emxEnsureCapacity_real_T1(b_v1, i26);
    i = v1->size[0];
    for (i26 = 0; i26 < i; i26++) {
      b_v1->data[i26] = v1->data[i26] + 1;
    }

    emxFree_int32_T(&v1);
    c_bh_line_homog_CLS_bh_line_hom(b_vk, b_v1, &LO_OBJ_a, &LO_OBJ_b, &LO_OBJ_d,
      LO_OBJ_line_type_data, LO_OBJ_line_type_size);

    /* 'lane_info_CLS:55' [tf_is_valid, uv_bot, uv_top] = LO_OBJ.get_roi_intersection_co_ords(ulim, vlim); */
    c_bh_line_homog_CLS_get_roi_int(LO_OBJ_a, LO_OBJ_b, LO_OBJ_d,
      LO_OBJ_line_type_data, LO_OBJ_line_type_size, vlim, &tf_is_valid, mc_col,
      uv_top);

    /*  take care of the OUTPUTS */
    /* 'lane_info_CLS:58' OBJ.tip_upper_xy_col  = uv_top; */
    emxFree_real_T(&b_v1);
    emxFree_real_T(&b_vk);

    /* 'lane_info_CLS:59' OBJ.tip_lower_xy_col  = uv_bot; */
    for (i = 0; i < 2; i++) {
      OBJ->tip_upper_xy_col[i] = uv_top[i];
      OBJ->tip_lower_xy_col[i] = mc_col[i];
    }

    /*  get equation of the line */
    /*  :  y = mx + c */
    /* 'lane_info_CLS:63' mc_col = LO_OBJ.get_mc(); */
    bh_line_homog_CLS_get_mc(LO_OBJ_a, LO_OBJ_b, LO_OBJ_d, LO_OBJ_line_type_data,
      LO_OBJ_line_type_size, mc_col);

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
 * Arguments    : const boolean_T OBJ_BW[76800]
 *                const double OBJ_tip_upper_xy_col[2]
 *                const double OBJ_tip_lower_xy_col[2]
 *                double OBJ_m
 *                double OBJ_c
 *                boolean_T OBJ_tf_is_detected
 *                boolean_T my_S_BW[76800]
 *                double *my_S_NUM_ROWS
 *                double *my_S_NUM_COLS
 *                double my_S_tip_upper_xy_col[2]
 *                double my_S_tip_lower_xy_col[2]
 *                double *my_S_m
 *                double *my_S_c
 *                boolean_T *my_S_tf_is_detected
 * Return Type  : void
 */
void b_lane_info_CLS_convert_to_stru(const boolean_T OBJ_BW[76800], const double
  OBJ_tip_upper_xy_col[2], const double OBJ_tip_lower_xy_col[2], double OBJ_m,
  double OBJ_c, boolean_T OBJ_tf_is_detected, boolean_T my_S_BW[76800], double
  *my_S_NUM_ROWS, double *my_S_NUM_COLS, double my_S_tip_upper_xy_col[2], double
  my_S_tip_lower_xy_col[2], double *my_S_m, double *my_S_c, boolean_T
  *my_S_tf_is_detected)
{
  int i;

  /* --------------------------------------------------------------------------   */
  /* 'lane_info_CLS:101' my_S.BW               = OBJ.BW; */
  memcpy(&my_S_BW[0], &OBJ_BW[0], 76800U * sizeof(boolean_T));

  /* 'lane_info_CLS:102' my_S.NUM_ROWS         = OBJ.NUM_ROWS; */
  *my_S_NUM_ROWS = 240.0;

  /* 'lane_info_CLS:103' my_S.NUM_COLS         = OBJ.NUM_COLS; */
  *my_S_NUM_COLS = 320.0;

  /* 'lane_info_CLS:104' my_S.tip_upper_xy_col = OBJ.tip_upper_xy_col; */
  /* 'lane_info_CLS:105' my_S.tip_lower_xy_col = OBJ.tip_lower_xy_col; */
  for (i = 0; i < 2; i++) {
    my_S_tip_upper_xy_col[i] = OBJ_tip_upper_xy_col[i];
    my_S_tip_lower_xy_col[i] = OBJ_tip_lower_xy_col[i];
  }

  /* 'lane_info_CLS:106' my_S.m                = OBJ.m; */
  *my_S_m = OBJ_m;

  /* 'lane_info_CLS:107' my_S.c                = OBJ.c; */
  *my_S_c = OBJ_c;

  /* 'lane_info_CLS:108' my_S.tf_is_detected   = OBJ.tf_is_detected; */
  *my_S_tf_is_detected = OBJ_tf_is_detected;

  /* --------------------------------------------------------------------------   */
  /*  methods() */
  /* _######################################################################### */
  /*  classdef() */
  /* _######################################################################### */
  /*  END CLASSDEF */
  /* _######################################################################### */
}

/*
 * function OBJ = lane_info_CLS(BW, tf_found)
 * Arguments    : const boolean_T BW[76800]
 *                boolean_T tf_found
 *                lane_info_CLS_1 *OBJ
 * Return Type  : void
 */
void b_lane_info_CLS_lane_info_CLS(const boolean_T BW[76800], boolean_T tf_found,
  lane_info_CLS_1 *OBJ)
{
  int i;
  for (i = 0; i < 2; i++) {
    OBJ->tip_upper_xy_col[i] = 0.0;
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
  memcpy(&OBJ->BW[0], &BW[0], 76800U * sizeof(boolean_T));

  /* 'lane_info_CLS:25' OBJ.NUM_ROWS       = size(BW,1); */
  OBJ->NUM_ROWS = 240.0;

  /* 'lane_info_CLS:26' OBJ.NUM_COLS       = size(BW,2); */
  OBJ->NUM_COLS = 320.0;

  /* 'lane_info_CLS:28' OBJ.tf_is_detected = tf_found; */
  OBJ->tf_is_detected = tf_found;

  /* 'lane_info_CLS:30' OBJ = OBJ.calc_info(); */
  lane_info_CLS_calc_info(OBJ);
}

/*
 * function OBJ = calc_info(OBJ, ulim, vlim)
 * Arguments    : lane_info_CLS_1 *OBJ
 * Return Type  : void
 */
void lane_info_CLS_calc_info(lane_info_CLS_1 *OBJ)
{
  emxArray_int32_T *ii;
  int idx;
  int i25;
  int i;
  boolean_T exitg1;
  emxArray_int32_T *v1;
  emxArray_int32_T *vk;
  emxArray_real_T *b_vk;
  emxArray_real_T *b_v1;
  double LO_OBJ_a;
  double LO_OBJ_b;
  double LO_OBJ_d;
  char LO_OBJ_line_type_data[6];
  int LO_OBJ_line_type_size[2];
  double dv2[2];
  boolean_T tf_is_valid;
  double mc_col[2];
  double uv_top[2];

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
    /* 'lane_info_CLS:49' the_ind  = find(OBJ.BW); */
    idx = 0;
    i25 = ii->size[0];
    ii->size[0] = 76800;
    emxEnsureCapacity_int32_T(ii, i25);
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i < 76801)) {
      if (OBJ->BW[i - 1]) {
        idx++;
        ii->data[idx - 1] = i;
        if (idx >= 76800) {
          exitg1 = true;
        } else {
          i++;
        }
      } else {
        i++;
      }
    }

    emxInit_int32_T(&v1, 1);
    i25 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(ii, i25);

    /* 'lane_info_CLS:50' [y,x]    = ind2sub(the_size,the_ind); */
    i25 = v1->size[0];
    v1->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(v1, i25);
    i = ii->size[0];
    for (i25 = 0; i25 < i; i25++) {
      v1->data[i25] = ii->data[i25] - 1;
    }

    emxFree_int32_T(&ii);
    emxInit_int32_T(&vk, 1);
    i25 = vk->size[0];
    vk->size[0] = v1->size[0];
    emxEnsureCapacity_int32_T(vk, i25);
    i = v1->size[0];
    for (i25 = 0; i25 < i; i25++) {
      vk->data[i25] = v1->data[i25] / 240;
    }

    i25 = v1->size[0];
    emxEnsureCapacity_int32_T(v1, i25);
    i = v1->size[0];
    for (i25 = 0; i25 < i; i25++) {
      v1->data[i25] -= vk->data[i25] * 240;
    }

    emxInit_real_T1(&b_vk, 1);

    /*  convert INDS to SUBSCRIPTS */
    /*  create a homogenous line object */
    /* 'lane_info_CLS:53' LO_OBJ   = bh_line_homog_CLS(x,y); */
    i25 = b_vk->size[0];
    b_vk->size[0] = vk->size[0];
    emxEnsureCapacity_real_T1(b_vk, i25);
    i = vk->size[0];
    for (i25 = 0; i25 < i; i25++) {
      b_vk->data[i25] = (double)vk->data[i25] + 1.0;
    }

    emxFree_int32_T(&vk);
    emxInit_real_T1(&b_v1, 1);
    i25 = b_v1->size[0];
    b_v1->size[0] = v1->size[0];
    emxEnsureCapacity_real_T1(b_v1, i25);
    i = v1->size[0];
    for (i25 = 0; i25 < i; i25++) {
      b_v1->data[i25] = v1->data[i25] + 1;
    }

    emxFree_int32_T(&v1);
    c_bh_line_homog_CLS_bh_line_hom(b_vk, b_v1, &LO_OBJ_a, &LO_OBJ_b, &LO_OBJ_d,
      LO_OBJ_line_type_data, LO_OBJ_line_type_size);

    /* 'lane_info_CLS:55' [tf_is_valid, uv_bot, uv_top] = LO_OBJ.get_roi_intersection_co_ords(ulim, vlim); */
    emxFree_real_T(&b_v1);
    emxFree_real_T(&b_vk);
    for (i25 = 0; i25 < 2; i25++) {
      dv2[i25] = 1.0 + 239.0 * (double)i25;
    }

    c_bh_line_homog_CLS_get_roi_int(LO_OBJ_a, LO_OBJ_b, LO_OBJ_d,
      LO_OBJ_line_type_data, LO_OBJ_line_type_size, dv2, &tf_is_valid, mc_col,
      uv_top);

    /*  take care of the OUTPUTS */
    /* 'lane_info_CLS:58' OBJ.tip_upper_xy_col  = uv_top; */
    /* 'lane_info_CLS:59' OBJ.tip_lower_xy_col  = uv_bot; */
    for (i = 0; i < 2; i++) {
      OBJ->tip_upper_xy_col[i] = uv_top[i];
      OBJ->tip_lower_xy_col[i] = mc_col[i];
    }

    /*  get equation of the line */
    /*  :  y = mx + c */
    /* 'lane_info_CLS:63' mc_col = LO_OBJ.get_mc(); */
    bh_line_homog_CLS_get_mc(LO_OBJ_a, LO_OBJ_b, LO_OBJ_d, LO_OBJ_line_type_data,
      LO_OBJ_line_type_size, mc_col);

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
  my_S_BW->size[0] = OBJ_BW->size[0];
  my_S_BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(my_S_BW, i);
  loop_ub = OBJ_BW->size[0] * OBJ_BW->size[1];
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
 * function [m,c] = get_mc(OBJ)
 * coder.varsize('m','c', [1 1]);
 * Arguments    : double OBJ_m
 *                double OBJ_c
 *                boolean_T OBJ_tf_is_detected
 *                double m_data[]
 *                int m_size[2]
 *                double c_data[]
 *                int c_size[2]
 * Return Type  : void
 */
void lane_info_CLS_get_mc(double OBJ_m, double OBJ_c, boolean_T
  OBJ_tf_is_detected, double m_data[], int m_size[2], double c_data[], int
  c_size[2])
{
  /*  get_xy() */
  /* --------------------------------------------------------------------------   */
  /* 'lane_info_CLS:85' m = zeros(1,0); */
  m_size[0] = 1;
  m_size[1] = 0;

  /*  [] */
  /* 'lane_info_CLS:86' c = zeros(1,0); */
  c_size[0] = 1;
  c_size[1] = 0;

  /*  [] */
  /* 'lane_info_CLS:88' if( ~OBJ.is_detected() ) */
  /* --------------------------------------------------------------------------   */
  /* 'lane_info_CLS:34' tf_detected = OBJ.tf_is_detected; */
  if (OBJ_tf_is_detected) {
    /* 'lane_info_CLS:92' m = OBJ.m; */
    m_size[0] = 1;
    m_size[1] = 1;
    m_data[0] = OBJ_m;

    /* 'lane_info_CLS:93' c = OBJ.c; */
    c_size[0] = 1;
    c_size[1] = 1;
    c_data[0] = OBJ_c;
  }
}

/*
 * function OBJ = lane_info_CLS(BW, tf_found)
 * Arguments    : const emxArray_boolean_T *BW
 *                boolean_T tf_found
 *                emxArray_boolean_T *OBJ_BW
 *                double *OBJ_NUM_ROWS
 *                double *OBJ_NUM_COLS
 *                double OBJ_tip_upper_xy_col[2]
 *                double OBJ_tip_lower_xy_col[2]
 *                double *OBJ_m
 *                double *OBJ_c
 *                boolean_T *OBJ_tf_is_detected
 * Return Type  : void
 */
void lane_info_CLS_lane_info_CLS(const emxArray_boolean_T *BW, boolean_T
  tf_found, emxArray_boolean_T *OBJ_BW, double *OBJ_NUM_ROWS, double
  *OBJ_NUM_COLS, double OBJ_tip_upper_xy_col[2], double OBJ_tip_lower_xy_col[2],
  double *OBJ_m, double *OBJ_c, boolean_T *OBJ_tf_is_detected)
{
  int i;
  double b_OBJ_m;
  double b_OBJ_c;
  int i7;
  int b_OBJ_NUM_ROWS;
  emxArray_int32_T *ii;
  double the_size[2];
  int nx;
  int idx;
  boolean_T exitg1;
  emxArray_int32_T *v1;
  short BW_idx_0;
  emxArray_int32_T *vk;
  emxArray_real_T *b_vk;
  emxArray_real_T *b_v1;
  double LO_OBJ_d;
  char LO_OBJ_line_type_data[6];
  int LO_OBJ_line_type_size[2];
  double dv0[2];
  boolean_T tf_is_valid;
  double uv_top[2];
  for (i = 0; i < 2; i++) {
    OBJ_tip_upper_xy_col[i] = 0.0;
  }

  for (i = 0; i < 2; i++) {
    OBJ_tip_lower_xy_col[i] = 0.0;
  }

  b_OBJ_m = 0.0;
  b_OBJ_c = 0.0;

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
  i7 = OBJ_BW->size[0] * OBJ_BW->size[1];
  OBJ_BW->size[0] = BW->size[0];
  OBJ_BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(OBJ_BW, i7);
  i = BW->size[0] * BW->size[1];
  for (i7 = 0; i7 < i; i7++) {
    OBJ_BW->data[i7] = BW->data[i7];
  }

  /* 'lane_info_CLS:25' OBJ.NUM_ROWS       = size(BW,1); */
  b_OBJ_NUM_ROWS = BW->size[0];

  /* 'lane_info_CLS:26' OBJ.NUM_COLS       = size(BW,2); */
  /* 'lane_info_CLS:28' OBJ.tf_is_detected = tf_found; */
  /* 'lane_info_CLS:30' OBJ = OBJ.calc_info(); */
  /*  is_detected() */
  /* --------------------------------------------------------------------------  */
  /* 'lane_info_CLS:38' if( ~OBJ.is_detected() ) */
  /* --------------------------------------------------------------------------   */
  /* 'lane_info_CLS:34' tf_detected = OBJ.tf_is_detected; */
  if (tf_found) {
    emxInit_int32_T(&ii, 1);

    /* 'lane_info_CLS:42' if(1==nargin) */
    /* 'lane_info_CLS:43' ulim = [1, OBJ.NUM_COLS]; */
    /* 'lane_info_CLS:44' vlim = [1, OBJ.NUM_ROWS]; */
    /*  OK: if we're here we have a lane */
    /* 'lane_info_CLS:48' the_size = [OBJ.NUM_ROWS, OBJ.NUM_COLS]; */
    the_size[0] = BW->size[0];

    /* 'lane_info_CLS:49' the_ind  = find(OBJ.BW); */
    nx = BW->size[0] * 320;
    idx = 0;
    i7 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity_int32_T(ii, i7);
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i <= nx)) {
      if (BW->data[i - 1]) {
        idx++;
        ii->data[idx - 1] = i;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          i++;
        }
      } else {
        i++;
      }
    }

    emxInit_int32_T(&v1, 1);
    i7 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(ii, i7);

    /* 'lane_info_CLS:50' [y,x]    = ind2sub(the_size,the_ind); */
    BW_idx_0 = (short)BW->size[0];
    i7 = v1->size[0];
    v1->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(v1, i7);
    i = ii->size[0];
    for (i7 = 0; i7 < i; i7++) {
      v1->data[i7] = ii->data[i7] - 1;
    }

    emxFree_int32_T(&ii);
    emxInit_int32_T(&vk, 1);
    i7 = vk->size[0];
    vk->size[0] = v1->size[0];
    emxEnsureCapacity_int32_T(vk, i7);
    i = v1->size[0];
    for (i7 = 0; i7 < i; i7++) {
      vk->data[i7] = div_s32(v1->data[i7], (short)the_size[0]);
    }

    i7 = v1->size[0];
    emxEnsureCapacity_int32_T(v1, i7);
    i = v1->size[0];
    for (i7 = 0; i7 < i; i7++) {
      v1->data[i7] -= vk->data[i7] * BW_idx_0;
    }

    emxInit_real_T1(&b_vk, 1);

    /*  convert INDS to SUBSCRIPTS */
    /*  create a homogenous line object */
    /* 'lane_info_CLS:53' LO_OBJ   = bh_line_homog_CLS(x,y); */
    i7 = b_vk->size[0];
    b_vk->size[0] = vk->size[0];
    emxEnsureCapacity_real_T1(b_vk, i7);
    i = vk->size[0];
    for (i7 = 0; i7 < i; i7++) {
      b_vk->data[i7] = vk->data[i7] + 1;
    }

    emxFree_int32_T(&vk);
    emxInit_real_T1(&b_v1, 1);
    i7 = b_v1->size[0];
    b_v1->size[0] = v1->size[0];
    emxEnsureCapacity_real_T1(b_v1, i7);
    i = v1->size[0];
    for (i7 = 0; i7 < i; i7++) {
      b_v1->data[i7] = v1->data[i7] + 1;
    }

    emxFree_int32_T(&v1);
    c_bh_line_homog_CLS_bh_line_hom(b_vk, b_v1, &b_OBJ_m, &b_OBJ_c, &LO_OBJ_d,
      LO_OBJ_line_type_data, LO_OBJ_line_type_size);

    /* 'lane_info_CLS:55' [tf_is_valid, uv_bot, uv_top] = LO_OBJ.get_roi_intersection_co_ords(ulim, vlim); */
    emxFree_real_T(&b_v1);
    emxFree_real_T(&b_vk);
    dv0[0] = 1.0;
    dv0[1] = BW->size[0];
    c_bh_line_homog_CLS_get_roi_int(b_OBJ_m, b_OBJ_c, LO_OBJ_d,
      LO_OBJ_line_type_data, LO_OBJ_line_type_size, dv0, &tf_is_valid, the_size,
      uv_top);

    /*  take care of the OUTPUTS */
    /* 'lane_info_CLS:58' OBJ.tip_upper_xy_col  = uv_top; */
    for (i = 0; i < 2; i++) {
      OBJ_tip_upper_xy_col[i] = uv_top[i];
    }

    /* 'lane_info_CLS:59' OBJ.tip_lower_xy_col  = uv_bot; */
    for (i7 = 0; i7 < 2; i7++) {
      OBJ_tip_lower_xy_col[i7] = the_size[i7];
    }

    /*  get equation of the line */
    /*  :  y = mx + c */
    /* 'lane_info_CLS:63' mc_col = LO_OBJ.get_mc(); */
    bh_line_homog_CLS_get_mc(b_OBJ_m, b_OBJ_c, LO_OBJ_d, LO_OBJ_line_type_data,
      LO_OBJ_line_type_size, dv0);
    for (i7 = 0; i7 < 2; i7++) {
      the_size[i7] = dv0[i7];
    }

    /* OBJ.fh_line = @(x) (m*x + c); */
    /* 'lane_info_CLS:66' OBJ.m       = mc_col(1); */
    b_OBJ_m = the_size[0];

    /* 'lane_info_CLS:67' OBJ.c       = mc_col(2); */
    b_OBJ_c = the_size[1];
  }

  *OBJ_NUM_ROWS = b_OBJ_NUM_ROWS;
  *OBJ_NUM_COLS = 320.0;
  *OBJ_m = b_OBJ_m;
  *OBJ_c = b_OBJ_c;
  *OBJ_tf_is_detected = tf_found;
}

/*
 * File trailer for lane_info_CLS.c
 *
 * [EOF]
 */
