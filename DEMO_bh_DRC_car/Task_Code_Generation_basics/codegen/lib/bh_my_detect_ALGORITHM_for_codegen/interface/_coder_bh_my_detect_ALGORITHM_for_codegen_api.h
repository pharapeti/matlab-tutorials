/*
 * File: _coder_bh_my_detect_ALGORITHM_for_codegen_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

#ifndef _CODER_BH_MY_DETECT_ALGORITHM_FOR_CODEGEN_API_H
#define _CODER_BH_MY_DETECT_ALGORITHM_FOR_CODEGEN_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_api.h"

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

#ifndef struct_sMXS9hbI1LSFh4mdcSqTbu_tag
#define struct_sMXS9hbI1LSFh4mdcSqTbu_tag

struct sMXS9hbI1LSFh4mdcSqTbu_tag
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

#endif                                 /*struct_sMXS9hbI1LSFh4mdcSqTbu_tag*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct sMXS9hbI1LSFh4mdcSqTbu_tag struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef struct_srbi8mkMWnVzBlG41YlL7eH_tag
#define struct_srbi8mkMWnVzBlG41YlL7eH_tag

struct srbi8mkMWnVzBlG41YlL7eH_tag
{
  emxArray_boolean_T *BW;
  real_T NUM_ROWS;
  real_T NUM_COLS;
  real_T left_edge_xy_col[2];
  real_T right_edge_xy_col[2];
  real_T centroid_xy_col[2];
  boolean_T tf_is_detected;
};

#endif                                 /*struct_srbi8mkMWnVzBlG41YlL7eH_tag*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct srbi8mkMWnVzBlG41YlL7eH_tag struct2_T;

#endif                                 /*typedef_struct2_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void bh_my_detect_ALGORITHM_for_codegen(uint8_T I[230400], boolean_T
  tf_do_init, struct0_T *marker_s, struct1_T *BLUE_s, struct1_T *YELL_s,
  struct2_T *PURP_s);
extern void bh_my_detect_ALGORITHM_for_codegen_api(const mxArray * const prhs[3],
  int32_T nlhs, const mxArray *plhs[3]);
extern void bh_my_detect_ALGORITHM_for_codegen_atexit(void);
extern void bh_my_detect_ALGORITHM_for_codegen_initialize(void);
extern void bh_my_detect_ALGORITHM_for_codegen_terminate(void);
extern void bh_my_detect_ALGORITHM_for_codegen_xil_terminate(void);

#endif

/*
 * File trailer for _coder_bh_my_detect_ALGORITHM_for_codegen_api.h
 *
 * [EOF]
 */
