/*
 * File: box_info_CLS.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "box_info_CLS.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"
#include "combineVectorElements.h"
#include "bh_my_detect_ALGORITHM_for_codegen_rtwutil.h"

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
  int i26;
  int the_right_edge_y;
  boolean_T exitg1;
  emxArray_int32_T *r11;
  emxArray_int32_T *b_ii;
  emxArray_int32_T *v1;
  emxArray_int32_T *vk;
  emxArray_int32_T *y;
  emxArray_int32_T *x;
  emxArray_real_T *b_y;
  emxArray_real_T *b_x;
  emxArray_boolean_T *c_x;
  int b_idx;
  emxArray_int32_T *tmp_II;
  emxArray_int32_T *yI;
  int the_left_edge_y;
  int c_idx;
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
    i26 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity_int32_T(ii, i26);
    the_right_edge_y = 1;
    exitg1 = false;
    while ((!exitg1) && (the_right_edge_y <= nx)) {
      i26 = OBJ->BW->size[0];
      if (OBJ->BW->data[(the_right_edge_y - 1) % i26 * 320 + (the_right_edge_y -
           1) / i26]) {
        idx++;
        ii->data[idx - 1] = the_right_edge_y;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          the_right_edge_y++;
        }
      } else {
        the_right_edge_y++;
      }
    }

    if (1 > idx) {
      the_right_edge_y = 0;
    } else {
      the_right_edge_y = idx;
    }

    emxInit_int32_T(&r11, 1);
    i26 = r11->size[0];
    r11->size[0] = the_right_edge_y;
    emxEnsureCapacity_int32_T(r11, i26);
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      r11->data[i26] = i26;
    }

    emxInit_int32_T(&b_ii, 1);
    the_right_edge_y = r11->size[0];
    i26 = b_ii->size[0];
    b_ii->size[0] = the_right_edge_y;
    emxEnsureCapacity_int32_T(b_ii, i26);
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      b_ii->data[i26] = ii->data[r11->data[i26]];
    }

    i26 = ii->size[0];
    ii->size[0] = b_ii->size[0];
    emxEnsureCapacity_int32_T(ii, i26);
    the_right_edge_y = b_ii->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      ii->data[i26] = b_ii->data[i26];
    }

    emxInit_int32_T(&v1, 1);

    /* 'box_info_CLS:44' [y,x]    = ind2sub(the_size,the_ind); */
    i26 = v1->size[0];
    v1->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(v1, i26);
    the_right_edge_y = ii->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      v1->data[i26] = ii->data[i26] - 1;
    }

    emxInit_int32_T(&vk, 1);
    i26 = vk->size[0];
    vk->size[0] = v1->size[0];
    emxEnsureCapacity_int32_T(vk, i26);
    the_right_edge_y = v1->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      vk->data[i26] = div_s32(v1->data[i26], (int)the_size_idx_0);
    }

    i26 = v1->size[0];
    emxEnsureCapacity_int32_T(v1, i26);
    the_right_edge_y = v1->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      v1->data[i26] -= vk->data[i26] * (int)the_size_idx_0;
    }

    emxInit_int32_T(&y, 1);
    i26 = y->size[0];
    y->size[0] = v1->size[0];
    emxEnsureCapacity_int32_T(y, i26);
    the_right_edge_y = v1->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      y->data[i26] = v1->data[i26] + 1;
    }

    emxInit_int32_T(&x, 1);
    i26 = x->size[0];
    x->size[0] = vk->size[0];
    emxEnsureCapacity_int32_T(x, i26);
    the_right_edge_y = vk->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      x->data[i26] = vk->data[i26] + 1;
    }

    emxInit_real_T1(&b_y, 1);
    i26 = b_y->size[0];
    b_y->size[0] = v1->size[0];
    emxEnsureCapacity_real_T1(b_y, i26);
    the_right_edge_y = v1->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      b_y->data[i26] = v1->data[i26] + 1;
    }

    emxFree_int32_T(&v1);
    emxInit_real_T1(&b_x, 1);
    i26 = b_x->size[0];
    b_x->size[0] = vk->size[0];
    emxEnsureCapacity_real_T1(b_x, i26);
    the_right_edge_y = vk->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      b_x->data[i26] = vk->data[i26] + 1;
    }

    emxFree_int32_T(&vk);

    /*  convert INDS to SUBSCRIPTS */
    /*  the LEFT edge will have the smallest X-co-ord */
    /* 'box_info_CLS:47' the_left_edge_x  = 1; */
    /* 'box_info_CLS:48' [~,tmp_I]        = min(x); */
    if (b_x->size[0] <= 2) {
      if (b_x->size[0] == 1) {
        idx = 0;
      } else {
        idx = (x->data[0] > x->data[1]);
      }
    } else {
      the_right_edge_y = (int)b_x->data[0];
      idx = 0;
      for (nx = 2; nx <= x->size[0]; nx++) {
        if (the_right_edge_y > (int)b_x->data[nx - 1]) {
          the_right_edge_y = (int)b_x->data[nx - 1];
          idx = nx - 1;
        }
      }
    }

    emxInit_boolean_T1(&c_x, 1);

    /* 'box_info_CLS:48' ~ */
    /* 'box_info_CLS:49' the_left_edge_x  =  x(tmp_I(1)); */
    /*  MATLAB CODER friendly */
    /* 'box_info_CLS:50' tmp_II           = find(x==the_left_edge_x); */
    nx = (int)b_x->data[idx];
    i26 = c_x->size[0];
    c_x->size[0] = x->size[0];
    emxEnsureCapacity_boolean_T1(c_x, i26);
    the_right_edge_y = x->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      c_x->data[i26] = (x->data[i26] == nx);
    }

    nx = c_x->size[0];
    b_idx = 0;
    the_right_edge_y = c_x->size[0];
    i26 = ii->size[0];
    ii->size[0] = the_right_edge_y;
    emxEnsureCapacity_int32_T(ii, i26);
    the_right_edge_y = 1;
    exitg1 = false;
    while ((!exitg1) && (the_right_edge_y <= nx)) {
      if (c_x->data[the_right_edge_y - 1]) {
        b_idx++;
        ii->data[b_idx - 1] = the_right_edge_y;
        if (b_idx >= nx) {
          exitg1 = true;
        } else {
          the_right_edge_y++;
        }
      } else {
        the_right_edge_y++;
      }
    }

    if (c_x->size[0] == 1) {
      if (b_idx == 0) {
        i26 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity_int32_T(ii, i26);
      }
    } else {
      if (1 > b_idx) {
        the_right_edge_y = 0;
      } else {
        the_right_edge_y = b_idx;
      }

      i26 = r11->size[0];
      r11->size[0] = the_right_edge_y;
      emxEnsureCapacity_int32_T(r11, i26);
      for (i26 = 0; i26 < the_right_edge_y; i26++) {
        r11->data[i26] = i26;
      }

      the_right_edge_y = r11->size[0];
      i26 = b_ii->size[0];
      b_ii->size[0] = the_right_edge_y;
      emxEnsureCapacity_int32_T(b_ii, i26);
      for (i26 = 0; i26 < the_right_edge_y; i26++) {
        b_ii->data[i26] = ii->data[r11->data[i26]];
      }

      i26 = ii->size[0];
      ii->size[0] = b_ii->size[0];
      emxEnsureCapacity_int32_T(ii, i26);
      the_right_edge_y = b_ii->size[0];
      for (i26 = 0; i26 < the_right_edge_y; i26++) {
        ii->data[i26] = b_ii->data[i26];
      }
    }

    emxInit_int32_T(&tmp_II, 1);
    i26 = tmp_II->size[0];
    tmp_II->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(tmp_II, i26);
    the_right_edge_y = ii->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      tmp_II->data[i26] = ii->data[i26];
    }

    emxInit_int32_T(&yI, 1);

    /* 'box_info_CLS:51' yI               = y(tmp_II); */
    i26 = yI->size[0];
    yI->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(yI, i26);
    the_right_edge_y = ii->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      yI->data[i26] = y->data[ii->data[i26] - 1];
    }

    /* 'box_info_CLS:52' the_left_edge_y  = min(yI); */
    if (tmp_II->size[0] <= 2) {
      if (tmp_II->size[0] == 1) {
        the_left_edge_y = yI->data[0];
      } else if (yI->data[0] > yI->data[1]) {
        the_left_edge_y = yI->data[1];
      } else {
        the_left_edge_y = yI->data[0];
      }
    } else {
      the_left_edge_y = yI->data[0];
      for (nx = 1; nx < ii->size[0]; nx++) {
        if (the_left_edge_y > yI->data[nx]) {
          the_left_edge_y = yI->data[nx];
        }
      }
    }

    /*  the RIGHT edge will have the biggest X-co-ord */
    /* 'box_info_CLS:55' the_right_edge_x  = 1; */
    /* 'box_info_CLS:56' [~,tmp_I]         = max(x); */
    if (b_x->size[0] <= 2) {
      if (b_x->size[0] == 1) {
        b_idx = 0;
      } else {
        b_idx = (x->data[0] < x->data[1]);
      }
    } else {
      the_right_edge_y = (int)b_x->data[0];
      b_idx = 0;
      for (nx = 2; nx <= x->size[0]; nx++) {
        if (the_right_edge_y < (int)b_x->data[nx - 1]) {
          the_right_edge_y = (int)b_x->data[nx - 1];
          b_idx = nx - 1;
        }
      }
    }

    /* 'box_info_CLS:56' ~ */
    /* 'box_info_CLS:57' the_right_edge_x  =  x(tmp_I(1)); */
    /*  MATLAB CODER friendly */
    /* 'box_info_CLS:58' tmp_RR            = find(x==the_right_edge_x); */
    nx = (int)b_x->data[b_idx];
    i26 = c_x->size[0];
    c_x->size[0] = x->size[0];
    emxEnsureCapacity_boolean_T1(c_x, i26);
    the_right_edge_y = x->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      c_x->data[i26] = (x->data[i26] == nx);
    }

    emxFree_int32_T(&x);
    nx = c_x->size[0];
    c_idx = 0;
    the_right_edge_y = c_x->size[0];
    i26 = ii->size[0];
    ii->size[0] = the_right_edge_y;
    emxEnsureCapacity_int32_T(ii, i26);
    the_right_edge_y = 1;
    exitg1 = false;
    while ((!exitg1) && (the_right_edge_y <= nx)) {
      if (c_x->data[the_right_edge_y - 1]) {
        c_idx++;
        ii->data[c_idx - 1] = the_right_edge_y;
        if (c_idx >= nx) {
          exitg1 = true;
        } else {
          the_right_edge_y++;
        }
      } else {
        the_right_edge_y++;
      }
    }

    if (c_x->size[0] == 1) {
      if (c_idx == 0) {
        i26 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity_int32_T(ii, i26);
      }
    } else {
      if (1 > c_idx) {
        the_right_edge_y = 0;
      } else {
        the_right_edge_y = c_idx;
      }

      i26 = r11->size[0];
      r11->size[0] = the_right_edge_y;
      emxEnsureCapacity_int32_T(r11, i26);
      for (i26 = 0; i26 < the_right_edge_y; i26++) {
        r11->data[i26] = i26;
      }

      the_right_edge_y = r11->size[0];
      i26 = b_ii->size[0];
      b_ii->size[0] = the_right_edge_y;
      emxEnsureCapacity_int32_T(b_ii, i26);
      for (i26 = 0; i26 < the_right_edge_y; i26++) {
        b_ii->data[i26] = ii->data[r11->data[i26]];
      }

      i26 = ii->size[0];
      ii->size[0] = b_ii->size[0];
      emxEnsureCapacity_int32_T(ii, i26);
      the_right_edge_y = b_ii->size[0];
      for (i26 = 0; i26 < the_right_edge_y; i26++) {
        ii->data[i26] = b_ii->data[i26];
      }
    }

    emxFree_int32_T(&b_ii);
    emxFree_boolean_T(&c_x);
    emxFree_int32_T(&r11);
    i26 = tmp_II->size[0];
    tmp_II->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(tmp_II, i26);
    the_right_edge_y = ii->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      tmp_II->data[i26] = ii->data[i26];
    }

    /* 'box_info_CLS:59' yR                = y(tmp_RR); */
    i26 = yI->size[0];
    yI->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(yI, i26);
    the_right_edge_y = ii->size[0];
    for (i26 = 0; i26 < the_right_edge_y; i26++) {
      yI->data[i26] = y->data[ii->data[i26] - 1];
    }

    emxFree_int32_T(&y);

    /* 'box_info_CLS:60' the_right_edge_y  = min(yR); */
    if (tmp_II->size[0] <= 2) {
      if (tmp_II->size[0] == 1) {
        the_right_edge_y = yI->data[0];
      } else if (yI->data[0] > yI->data[1]) {
        the_right_edge_y = yI->data[1];
      } else {
        the_right_edge_y = yI->data[0];
      }
    } else {
      the_right_edge_y = yI->data[0];
      for (nx = 1; nx < ii->size[0]; nx++) {
        if (the_right_edge_y > yI->data[nx]) {
          the_right_edge_y = yI->data[nx];
        }
      }
    }

    emxFree_int32_T(&ii);
    emxFree_int32_T(&yI);
    emxFree_int32_T(&tmp_II);

    /*  calc the centroid */
    /* 'box_info_CLS:63' xc = mean(x); */
    /* 'box_info_CLS:64' yc = mean(y); */
    /*  take care of the OUTPUTS */
    /* 'box_info_CLS:67' OBJ.left_edge_xy_col   = [the_left_edge_x(1);  the_left_edge_y(1)   ]; */
    OBJ->left_edge_xy_col[0] = b_x->data[idx];
    OBJ->left_edge_xy_col[1] = the_left_edge_y;

    /*  MATLAB CODER friendly */
    /* 'box_info_CLS:68' OBJ.right_edge_xy_col  = [the_right_edge_x(1); the_right_edge_y(1)  ]; */
    OBJ->right_edge_xy_col[0] = b_x->data[b_idx];
    OBJ->right_edge_xy_col[1] = the_right_edge_y;

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
  OBJ->BW->size[1] = 320;
  OBJ->BW->size[0] = BW->size[0];
  emxEnsureCapacity_boolean_T(OBJ->BW, i);
  loop_ub = BW->size[1] * BW->size[0];
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
  my_S_BW->size[1] = 320;
  my_S_BW->size[0] = OBJ_BW->size[0];
  emxEnsureCapacity_boolean_T(my_S_BW, i);
  loop_ub = OBJ_BW->size[1] * OBJ_BW->size[0];
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
