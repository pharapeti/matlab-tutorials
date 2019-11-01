/*
 * File: bh_MY_CV_ALGORITHMS_types.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

#ifndef BH_MY_CV_ALGORITHMS_TYPES_H
#define BH_MY_CV_ALGORITHMS_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_c_struct_T
#define typedef_c_struct_T

typedef struct {
  double Orientation;
  double Eccentricity;
  double Area;
  emxArray_real_T *PixelIdxList;
} c_struct_T;

#endif                                 /*typedef_c_struct_T*/

#ifndef struct_b_emxArray_struct_T
#define struct_b_emxArray_struct_T

struct b_emxArray_struct_T
{
  c_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_b_emxArray_struct_T*/

#ifndef typedef_b_emxArray_struct_T
#define typedef_b_emxArray_struct_T

typedef struct b_emxArray_struct_T b_emxArray_struct_T;

#endif                                 /*typedef_b_emxArray_struct_T*/

#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  double Area;
  double Eccentricity;
  emxArray_real_T *PixelIdxList;
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef struct_sOPkH0WAJHfm3I9UIkvJjAC
#define struct_sOPkH0WAJHfm3I9UIkvJjAC

struct sOPkH0WAJHfm3I9UIkvJjAC
{
  emxArray_boolean_T *BW;
  double NUM_ROWS;
  double NUM_COLS;
  double left_edge_xy_col[2];
  double right_edge_xy_col[2];
  double centroid_xy_col[2];
  boolean_T tf_is_detected;
};

#endif                                 /*struct_sOPkH0WAJHfm3I9UIkvJjAC*/

#ifndef typedef_box_info_CLS
#define typedef_box_info_CLS

typedef struct sOPkH0WAJHfm3I9UIkvJjAC box_info_CLS;

#endif                                 /*typedef_box_info_CLS*/

#ifndef typedef_d_struct_T
#define typedef_d_struct_T

typedef struct {
  double Area;
  double Centroid[2];
  double BoundingBox[4];
  double MajorAxisLength;
  double MinorAxisLength;
  double Eccentricity;
  double Orientation;
  emxArray_boolean_T *Image;
  emxArray_boolean_T *FilledImage;
  double FilledArea;
  double EulerNumber;
  double Extrema[16];
  double EquivDiameter;
  double Extent;
  emxArray_real_T *PixelIdxList;
  emxArray_real_T *PixelList;
  double Perimeter;
  emxArray_real_T *PixelValues;
  double WeightedCentroid[2];
  double MeanIntensity;
  double MinIntensity;
  double MaxIntensity;
  emxArray_real_T *SubarrayIdx;
  double SubarrayIdxLengths[2];
} d_struct_T;

#endif                                 /*typedef_d_struct_T*/

#ifndef struct_c_emxArray_struct_T
#define struct_c_emxArray_struct_T

struct c_emxArray_struct_T
{
  d_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_c_emxArray_struct_T*/

#ifndef typedef_c_emxArray_struct_T
#define typedef_c_emxArray_struct_T

typedef struct c_emxArray_struct_T c_emxArray_struct_T;

#endif                                 /*typedef_c_emxArray_struct_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_struct_T
#define struct_emxArray_struct_T

struct emxArray_struct_T
{
  b_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_struct_T*/

#ifndef typedef_emxArray_struct_T
#define typedef_emxArray_struct_T

typedef struct emxArray_struct_T emxArray_struct_T;

#endif                                 /*typedef_emxArray_struct_T*/

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T

struct emxArray_uint8_T
{
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint8_T*/

#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T

typedef struct emxArray_uint8_T emxArray_uint8_T;

#endif                                 /*typedef_emxArray_uint8_T*/

#ifndef typedef_lane_info_CLS_1
#define typedef_lane_info_CLS_1

typedef struct {
  boolean_T BW[76800];
  double NUM_ROWS;
  double NUM_COLS;
  double tip_upper_xy_col[2];
  double tip_lower_xy_col[2];
  double m;
  double c;
  boolean_T tf_is_detected;
} lane_info_CLS_1;

#endif                                 /*typedef_lane_info_CLS_1*/

#ifndef typedef_my_KF_general_CLS
#define typedef_my_KF_general_CLS

typedef struct {
  double A[4];
  double C[4];
  double Q[4];
  double R[4];
  double x0[2];
  double Nx;
  double x[2];
  double P[4];
} my_KF_general_CLS;

#endif                                 /*typedef_my_KF_general_CLS*/

#ifndef typedef_my_laneKF_CLS
#define typedef_my_laneKF_CLS

typedef struct {
  my_KF_general_CLS KF;
  double mc_col[2];
} my_laneKF_CLS;

#endif                                 /*typedef_my_laneKF_CLS*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  double nColors;
  double color_labels[5];
  double color_markers[10];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef struct_stgrDCl7MZLwJNkIVOHC9XH
#define struct_stgrDCl7MZLwJNkIVOHC9XH

struct stgrDCl7MZLwJNkIVOHC9XH
{
  emxArray_boolean_T *BW;
  double NUM_ROWS;
  double NUM_COLS;
  double tip_upper_xy_col[2];
  double tip_lower_xy_col[2];
  double m;
  double c;
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
  double NUM_ROWS;
  double NUM_COLS;
  double left_edge_xy_col[2];
  double right_edge_xy_col[2];
  double centroid_xy_col[2];
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
  double NUM_ROWS;
  double NUM_COLS;
  double tip_upper_xy_col[2];
  double tip_lower_xy_col[2];
  double m;
  double c;
  boolean_T tf_is_detected;
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef struct_s6wgKYuP6EfjbxVSz7SpFkH
#define struct_s6wgKYuP6EfjbxVSz7SpFkH

struct s6wgKYuP6EfjbxVSz7SpFkH
{
  double E_tgt_for_lane;
  double A_tgt_for_lane;
  double fraction_of_img_to_ignore;
  double nColors;
  double color_labels[5];
  double color_markers[10];
  emxArray_real_T *label;
};

#endif                                 /*struct_s6wgKYuP6EfjbxVSz7SpFkH*/

#ifndef typedef_ybp_finder_CLS
#define typedef_ybp_finder_CLS

typedef struct s6wgKYuP6EfjbxVSz7SpFkH ybp_finder_CLS;

#endif                                 /*typedef_ybp_finder_CLS*/
#endif

/*
 * File trailer for bh_MY_CV_ALGORITHMS_types.h
 *
 * [EOF]
 */
