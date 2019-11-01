/*
 * File: _coder_bh_MY_CV_ALGORITHMS_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef _CODER_BH_MY_CV_ALGORITHMS_API_H
#define _CODER_BH_MY_CV_ALGORITHMS_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_bh_MY_CV_ALGORITHMS_api.h"

/* Type Definitions */
#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T nColors;
  real_T color_labels[5];
  real_T color_markers[10];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef struct_stgrDCl7MZLwJNkIVOHC9XH
#define struct_stgrDCl7MZLwJNkIVOHC9XH

struct stgrDCl7MZLwJNkIVOHC9XH
{
  emxArray_boolean_T *BW;
  real_T NUM_ROWS;
  real_T NUM_COLS;
  real_T tip_upper_xy_col[2];
  real_T tip_lower_xy_col[2];
  real_T m;
  real_T c;
  boolean_T tf_is_detected;
};

#endif                                 /*struct_stgrDCl7MZLwJNkIVOHC9XH*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct stgrDCl7MZLwJNkIVOHC9XH struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef struct_se1ZFXlDhhTz1wwbgzj1yk
#define struct_se1ZFXlDhhTz1wwbgzj1yk

struct se1ZFXlDhhTz1wwbgzj1yk
{
  emxArray_boolean_T *BW;
  real_T NUM_ROWS;
  real_T NUM_COLS;
  real_T left_edge_xy_col[2];
  real_T right_edge_xy_col[2];
  real_T centroid_xy_col[2];
  boolean_T tf_is_detected;
};

#endif                                 /*struct_se1ZFXlDhhTz1wwbgzj1yk*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct se1ZFXlDhhTz1wwbgzj1yk struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  boolean_T BW[76800];
  real_T NUM_ROWS;
  real_T NUM_COLS;
  real_T tip_upper_xy_col[2];
  real_T tip_lower_xy_col[2];
  real_T m;
  real_T c;
  boolean_T tf_is_detected;
} struct3_T;

#endif                                 /*typedef_struct3_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void bh_MY_CV_ALGORITHMS_atexit(void);
extern void bh_MY_CV_ALGORITHMS_initialize(void);
extern void bh_MY_CV_ALGORITHMS_terminate(void);
extern void bh_MY_CV_ALGORITHMS_xil_terminate(void);
extern void bh_my_detect_ALGORITHM_for_codegen(uint8_T I[230400], boolean_T
  tf_do_init, struct0_T *marker_s, struct1_T *BLUE_s, struct1_T *YELL_s,
  struct2_T *PURP_s);
extern void bh_my_detect_ALGORITHM_for_codegen_api(const mxArray * const prhs[3],
  const mxArray *plhs[3]);
extern void bh_my_lane_preprocess_mask(struct3_T *BLUE_s, struct3_T *YELL_s,
  real_T fract_for_top_mask, struct3_T *BLUE_out_s, struct3_T *YELL_out_s);
extern void bh_my_lane_preprocess_mask_api(const mxArray * const prhs[3], const
  mxArray *plhs[2]);
extern void bh_my_track_ALGORITHM_for_codegen(struct3_T *BLUE_s, struct3_T
  *YELL_s, boolean_T tf_do_init, real_T BLUE_mc_col[2], real_T YELL_mc_col[2]);
extern void bh_my_track_ALGORITHM_for_codegen_api(const mxArray * const prhs[3],
  const mxArray *plhs[2]);

#endif

/*
 * File trailer for _coder_bh_MY_CV_ALGORITHMS_api.h
 *
 * [EOF]
 */
