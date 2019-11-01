/*
 * File: box_info_CLS.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "box_info_CLS.h"
#include "bh_MY_CV_ALGORITHMS_emxutil.h"
#include "combineVectorElements.h"
#include "bh_MY_CV_ALGORITHMS_rtwutil.h"

/* Function Declarations */
static void box_info_CLS_calc_info(box_info_CLS *OBJ);

/* Function Definitions */

/*
 * function OBJ = calc_info(OBJ)
 * Arguments    : box_info_CLS *OBJ
 * Return Type  : void
 */
static void box_info_CLS_calc_info(box_info_CLS *OBJ)
{
  emxArray_int32_T *ii;
  double the_size_idx_0;
  int nx;
  int idx;
  int i22;
  int cpsiz;
  boolean_T exitg1;
  emxArray_int32_T *v1;
  emxArray_int32_T *vk;
  emxArray_int32_T *y;
  emxArray_int32_T *x;
  emxArray_real_T *b_y;
  emxArray_real_T *b_x;
  int mtmp;
  int itmp;
  emxArray_boolean_T *c_x;
  emxArray_int32_T *tmp_II;
  emxArray_int32_T *yI;
  int b_itmp;
  double d2;

  /*  is_detected() */
  /* --------------------------------------------------------------------------  */
  /* 'box_info_CLS:37' if( ~OBJ.is_detected() ) */
  /* --------------------------------------------------------------------------   */
  /* 'box_info_CLS:33' tf_detected = OBJ.tf_is_detected; */
  if (OBJ->tf_is_detected) {
    emxInit_int32_T(&ii, 1);

    /*  OK: if we're here we have a box */
    /* 'box_info_CLS:42' the_size = [OBJ.NUM_ROWS, OBJ.NUM_COLS]; */
    the_size_idx_0 = OBJ->NUM_ROWS;

    /* 'box_info_CLS:43' the_ind  = find(OBJ.BW); */
    nx = OBJ->BW->size[0] * 320;
    idx = 0;
    i22 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity_int32_T(ii, i22);
    cpsiz = 1;
    exitg1 = false;
    while ((!exitg1) && (cpsiz <= nx)) {
      if (OBJ->BW->data[cpsiz - 1]) {
        idx++;
        ii->data[idx - 1] = cpsiz;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          cpsiz++;
        }
      } else {
        cpsiz++;
      }
    }

    emxInit_int32_T(&v1, 1);
    i22 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(ii, i22);

    /* 'box_info_CLS:44' [y,x]    = ind2sub(the_size,the_ind); */
    cpsiz = (int)OBJ->NUM_ROWS;
    i22 = v1->size[0];
    v1->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(v1, i22);
    nx = ii->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      v1->data[i22] = ii->data[i22] - 1;
    }

    emxInit_int32_T(&vk, 1);
    i22 = vk->size[0];
    vk->size[0] = v1->size[0];
    emxEnsureCapacity_int32_T(vk, i22);
    nx = v1->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      vk->data[i22] = div_s32(v1->data[i22], (int)the_size_idx_0);
    }

    i22 = v1->size[0];
    emxEnsureCapacity_int32_T(v1, i22);
    nx = v1->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      v1->data[i22] -= vk->data[i22] * cpsiz;
    }

    emxInit_int32_T(&y, 1);
    i22 = y->size[0];
    y->size[0] = v1->size[0];
    emxEnsureCapacity_int32_T(y, i22);
    nx = v1->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      y->data[i22] = v1->data[i22] + 1;
    }

    emxInit_int32_T(&x, 1);
    i22 = x->size[0];
    x->size[0] = vk->size[0];
    emxEnsureCapacity_int32_T(x, i22);
    nx = vk->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      x->data[i22] = vk->data[i22] + 1;
    }

    emxInit_real_T1(&b_y, 1);
    i22 = b_y->size[0];
    b_y->size[0] = v1->size[0];
    emxEnsureCapacity_real_T1(b_y, i22);
    nx = v1->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      b_y->data[i22] = v1->data[i22] + 1;
    }

    emxFree_int32_T(&v1);
    emxInit_real_T1(&b_x, 1);
    i22 = b_x->size[0];
    b_x->size[0] = vk->size[0];
    emxEnsureCapacity_real_T1(b_x, i22);
    nx = vk->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      b_x->data[i22] = vk->data[i22] + 1;
    }

    emxFree_int32_T(&vk);

    /*  convert INDS to SUBSCRIPTS */
    /*  the LEFT edge will have the smallest X-co-ord */
    /* 'box_info_CLS:47' the_left_edge_x  = 1; */
    /* 'box_info_CLS:48' [~,tmp_I]        = min(x); */
    cpsiz = b_x->size[0];
    mtmp = (int)b_x->data[0];
    itmp = 0;
    if (x->size[0] > 1) {
      for (nx = 1; nx + 1 <= cpsiz; nx++) {
        if ((int)b_x->data[nx] < mtmp) {
          mtmp = (int)b_x->data[nx];
          itmp = nx;
        }
      }
    }

    emxInit_boolean_T1(&c_x, 1);

    /* 'box_info_CLS:48' ~ */
    /* 'box_info_CLS:49' the_left_edge_x  =  x(tmp_I(1)); */
    /*  MATLAB CODER friendly */
    /* 'box_info_CLS:50' tmp_II           = find(x==the_left_edge_x); */
    cpsiz = (int)b_x->data[itmp];
    i22 = c_x->size[0];
    c_x->size[0] = x->size[0];
    emxEnsureCapacity_boolean_T1(c_x, i22);
    nx = x->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      c_x->data[i22] = (x->data[i22] == cpsiz);
    }

    nx = c_x->size[0];
    idx = 0;
    i22 = ii->size[0];
    ii->size[0] = c_x->size[0];
    emxEnsureCapacity_int32_T(ii, i22);
    cpsiz = 1;
    exitg1 = false;
    while ((!exitg1) && (cpsiz <= nx)) {
      if (c_x->data[cpsiz - 1]) {
        idx++;
        ii->data[idx - 1] = cpsiz;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          cpsiz++;
        }
      } else {
        cpsiz++;
      }
    }

    if (c_x->size[0] == 1) {
      if (idx == 0) {
        i22 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity_int32_T(ii, i22);
      }
    } else {
      i22 = ii->size[0];
      if (1 > idx) {
        ii->size[0] = 0;
      } else {
        ii->size[0] = idx;
      }

      emxEnsureCapacity_int32_T(ii, i22);
    }

    emxInit_int32_T(&tmp_II, 1);
    i22 = tmp_II->size[0];
    tmp_II->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(tmp_II, i22);
    nx = ii->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      tmp_II->data[i22] = ii->data[i22];
    }

    emxInit_int32_T(&yI, 1);

    /* 'box_info_CLS:51' yI               = y(tmp_II); */
    i22 = yI->size[0];
    yI->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(yI, i22);
    nx = ii->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      yI->data[i22] = y->data[ii->data[i22] - 1];
    }

    /* 'box_info_CLS:52' the_left_edge_y  = min(yI); */
    cpsiz = ii->size[0];
    mtmp = yI->data[0];
    if ((tmp_II->size[0] > 1) && (1 < tmp_II->size[0])) {
      for (nx = 1; nx + 1 <= cpsiz; nx++) {
        if (yI->data[nx] < mtmp) {
          mtmp = yI->data[nx];
        }
      }
    }

    /*  the RIGHT edge will have the biggest X-co-ord */
    /* 'box_info_CLS:55' the_right_edge_x  = 1; */
    /* 'box_info_CLS:56' [~,tmp_I]         = max(x); */
    cpsiz = b_x->size[0];
    idx = (int)b_x->data[0];
    b_itmp = 0;
    if (x->size[0] > 1) {
      for (nx = 1; nx + 1 <= cpsiz; nx++) {
        if ((int)b_x->data[nx] > idx) {
          idx = (int)b_x->data[nx];
          b_itmp = nx;
        }
      }
    }

    /* 'box_info_CLS:56' ~ */
    /* 'box_info_CLS:57' the_right_edge_x  =  x(tmp_I(1)); */
    /*  MATLAB CODER friendly */
    /* 'box_info_CLS:58' tmp_RR            = find(x==the_right_edge_x); */
    cpsiz = (int)b_x->data[b_itmp];
    i22 = c_x->size[0];
    c_x->size[0] = x->size[0];
    emxEnsureCapacity_boolean_T1(c_x, i22);
    nx = x->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      c_x->data[i22] = (x->data[i22] == cpsiz);
    }

    emxFree_int32_T(&x);
    nx = c_x->size[0];
    idx = 0;
    i22 = ii->size[0];
    ii->size[0] = c_x->size[0];
    emxEnsureCapacity_int32_T(ii, i22);
    cpsiz = 1;
    exitg1 = false;
    while ((!exitg1) && (cpsiz <= nx)) {
      if (c_x->data[cpsiz - 1]) {
        idx++;
        ii->data[idx - 1] = cpsiz;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          cpsiz++;
        }
      } else {
        cpsiz++;
      }
    }

    if (c_x->size[0] == 1) {
      if (idx == 0) {
        i22 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity_int32_T(ii, i22);
      }
    } else {
      i22 = ii->size[0];
      if (1 > idx) {
        ii->size[0] = 0;
      } else {
        ii->size[0] = idx;
      }

      emxEnsureCapacity_int32_T(ii, i22);
    }

    emxFree_boolean_T(&c_x);
    i22 = tmp_II->size[0];
    tmp_II->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(tmp_II, i22);
    nx = ii->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      tmp_II->data[i22] = ii->data[i22];
    }

    /* 'box_info_CLS:59' yR                = y(tmp_RR); */
    i22 = yI->size[0];
    yI->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(yI, i22);
    nx = ii->size[0];
    for (i22 = 0; i22 < nx; i22++) {
      yI->data[i22] = y->data[ii->data[i22] - 1];
    }

    emxFree_int32_T(&y);

    /* 'box_info_CLS:60' the_right_edge_y  = min(yR); */
    cpsiz = ii->size[0];
    idx = yI->data[0];
    emxFree_int32_T(&ii);
    if ((tmp_II->size[0] > 1) && (1 < tmp_II->size[0])) {
      for (nx = 1; nx + 1 <= cpsiz; nx++) {
        if (yI->data[nx] < idx) {
          idx = yI->data[nx];
        }
      }
    }

    emxFree_int32_T(&yI);
    emxFree_int32_T(&tmp_II);

    /*  calc the centroid */
    /* 'box_info_CLS:63' xc = mean(x); */
    /* 'box_info_CLS:64' yc = mean(y); */
    /*  take care of the OUTPUTS */
    /* 'box_info_CLS:67' OBJ.left_edge_xy_col   = [the_left_edge_x(1);  the_left_edge_y(1)   ]; */
    OBJ->left_edge_xy_col[0] = b_x->data[itmp];
    OBJ->left_edge_xy_col[1] = mtmp;

    /*  MATLAB CODER friendly */
    /* 'box_info_CLS:68' OBJ.right_edge_xy_col  = [the_right_edge_x(1); the_right_edge_y(1)  ]; */
    OBJ->right_edge_xy_col[0] = b_x->data[b_itmp];
    OBJ->right_edge_xy_col[1] = idx;

    /*  MATLAB CODER friendly */
    /* 'box_info_CLS:70' OBJ.centroid_xy_col    = [xc(1); yc(1) ]; */
    the_size_idx_0 = combineVectorElements(b_x);
    d2 = combineVectorElements(b_y);
    OBJ->centroid_xy_col[0] = the_size_idx_0 / (double)b_x->size[0];
    OBJ->centroid_xy_col[1] = d2 / (double)b_y->size[0];

    /*  MATLAB CODER friendly */
    emxFree_real_T(&b_x);
    emxFree_real_T(&b_y);
  }
}

/*
 * function OBJ = box_info_CLS(BW, tf_found)
 * Arguments    : const emxArray_boolean_T *BW
 *                boolean_T tf_found
 *                box_info_CLS *OBJ
 * Return Type  : void
 */
void box_info_CLS_box_info_CLS(const emxArray_boolean_T *BW, boolean_T tf_found,
  box_info_CLS *OBJ)
{
  int i;
  int loop_ub;
  for (i = 0; i < 2; i++) {
    OBJ->left_edge_xy_col[i] = 0.0;
  }

  for (i = 0; i < 2; i++) {
    OBJ->right_edge_xy_col[i] = 0.0;
  }

  for (i = 0; i < 2; i++) {
    OBJ->centroid_xy_col[i] = 0.0;
  }

  /*  ATTENTION: */
  /*  I want this class to be MATLAB CODER friendly, hence I have prepopulated */
  /*  some properties with NaNs */
  /* --------------------------------- */
  /* --------------------------------- */
  /* --------------------------------- */
  /* _######################################################################### */
  /* 'box_info_CLS:22' OBJ.BW            = BW; */
  i = OBJ->BW->size[0] * OBJ->BW->size[1];
  OBJ->BW->size[0] = BW->size[0];
  OBJ->BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(OBJ->BW, i);
  loop_ub = BW->size[0] * BW->size[1];
  for (i = 0; i < loop_ub; i++) {
    OBJ->BW->data[i] = BW->data[i];
  }

  /* 'box_info_CLS:24' OBJ.NUM_ROWS       = size(BW,1); */
  OBJ->NUM_ROWS = BW->size[0];

  /* 'box_info_CLS:25' OBJ.NUM_COLS       = size(BW,2); */
  OBJ->NUM_COLS = 320.0;

  /* 'box_info_CLS:27' OBJ.tf_is_detected = tf_found; */
  OBJ->tf_is_detected = tf_found;

  /* 'box_info_CLS:29' OBJ = OBJ.calc_info(); */
  box_info_CLS_calc_info(OBJ);
}

/*
 * function my_S = convert_to_struct(OBJ)
 * ATTENTION(R2017b):
 *  the following usage is NOT supported by the MATLAB Coder:
 *    >> struct(OBJ)
 * Arguments    : const emxArray_boolean_T *OBJ_BW
 *                double OBJ_NUM_ROWS
 *                const double OBJ_left_edge_xy_col[2]
 *                const double OBJ_right_edge_xy_col[2]
 *                const double OBJ_centroid_xy_col[2]
 *                boolean_T OBJ_tf_is_detected
 *                emxArray_boolean_T *my_S_BW
 *                double *my_S_NUM_ROWS
 *                double *my_S_NUM_COLS
 *                double my_S_left_edge_xy_col[2]
 *                double my_S_right_edge_xy_col[2]
 *                double my_S_centroid_xy_col[2]
 *                boolean_T *my_S_tf_is_detected
 * Return Type  : void
 */
void box_info_CLS_convert_to_struct(const emxArray_boolean_T *OBJ_BW, double
  OBJ_NUM_ROWS, const double OBJ_left_edge_xy_col[2], const double
  OBJ_right_edge_xy_col[2], const double OBJ_centroid_xy_col[2], boolean_T
  OBJ_tf_is_detected, emxArray_boolean_T *my_S_BW, double *my_S_NUM_ROWS, double
  *my_S_NUM_COLS, double my_S_left_edge_xy_col[2], double
  my_S_right_edge_xy_col[2], double my_S_centroid_xy_col[2], boolean_T
  *my_S_tf_is_detected)
{
  int i;
  int loop_ub;

  /*  get_xy() */
  /* --------------------------------------------------------------------------   */
  /* 'box_info_CLS:90' my_S.BW                = OBJ.BW; */
  i = my_S_BW->size[0] * my_S_BW->size[1];
  my_S_BW->size[0] = OBJ_BW->size[0];
  my_S_BW->size[1] = 320;
  emxEnsureCapacity_boolean_T(my_S_BW, i);
  loop_ub = OBJ_BW->size[0] * OBJ_BW->size[1];
  for (i = 0; i < loop_ub; i++) {
    my_S_BW->data[i] = OBJ_BW->data[i];
  }

  /* 'box_info_CLS:91' my_S.NUM_ROWS          = OBJ.NUM_ROWS; */
  /* 'box_info_CLS:92' my_S.NUM_COLS          = OBJ.NUM_COLS; */
  /* 'box_info_CLS:93' my_S.left_edge_xy_col  = OBJ.left_edge_xy_col; */
  for (i = 0; i < 2; i++) {
    my_S_left_edge_xy_col[i] = OBJ_left_edge_xy_col[i];
  }

  /* 'box_info_CLS:94' my_S.right_edge_xy_col = OBJ.right_edge_xy_col; */
  for (i = 0; i < 2; i++) {
    my_S_right_edge_xy_col[i] = OBJ_right_edge_xy_col[i];
  }

  /* 'box_info_CLS:95' my_S.centroid_xy_col   = OBJ.centroid_xy_col; */
  for (i = 0; i < 2; i++) {
    my_S_centroid_xy_col[i] = OBJ_centroid_xy_col[i];
  }

  /* 'box_info_CLS:96' my_S.tf_is_detected    = OBJ.tf_is_detected; */
  /* --------------------------------------------------------------------------   */
  /*  methods() */
  /* _######################################################################### */
  /*  classdef() */
  /* _######################################################################### */
  /*  END CLASSDEF */
  /* _######################################################################### */
  *my_S_NUM_ROWS = OBJ_NUM_ROWS;
  *my_S_NUM_COLS = 320.0;
  *my_S_tf_is_detected = OBJ_tf_is_detected;
}

/*
 * File trailer for box_info_CLS.c
 *
 * [EOF]
 */
