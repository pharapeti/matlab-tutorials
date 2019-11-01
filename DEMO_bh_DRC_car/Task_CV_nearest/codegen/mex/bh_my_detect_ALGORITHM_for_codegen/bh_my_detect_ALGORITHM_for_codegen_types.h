/*
 * bh_my_detect_ALGORITHM_for_codegen_types.h
 *
 * Code generation for function 'bh_my_detect_ALGORITHM_for_codegen'
 *
 */

#ifndef BH_MY_DETECT_ALGORITHM_FOR_CODEGEN_TYPES_H
#define BH_MY_DETECT_ALGORITHM_FOR_CODEGEN_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
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
  real_T Orientation;
  real_T Eccentricity;
  real_T Area;
  emxArray_real_T *PixelIdxList;
} c_struct_T;

#endif                                 /*typedef_c_struct_T*/

#ifndef struct_b_emxArray_struct_T
#define struct_b_emxArray_struct_T

struct b_emxArray_struct_T
{
  c_struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
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
  real_T Area;
  real_T Eccentricity;
  emxArray_real_T *PixelIdxList;
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

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

#ifndef struct_sOPkH0WAJHfm3I9UIkvJjAC
#define struct_sOPkH0WAJHfm3I9UIkvJjAC

struct sOPkH0WAJHfm3I9UIkvJjAC
{
  emxArray_boolean_T *BW;
  real_T NUM_ROWS;
  real_T NUM_COLS;
  real_T left_edge_xy_col[2];
  real_T right_edge_xy_col[2];
  real_T centroid_xy_col[2];
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
  real_T Area;
  real_T Centroid[2];
  real_T BoundingBox[4];
  real_T MajorAxisLength;
  real_T MinorAxisLength;
  real_T Eccentricity;
  real_T Orientation;
  emxArray_boolean_T *Image;
  emxArray_boolean_T *FilledImage;
  real_T FilledArea;
  real_T EulerNumber;
  real_T Extrema[16];
  real_T EquivDiameter;
  real_T Extent;
  emxArray_real_T *PixelIdxList;
  emxArray_real_T *PixelList;
  real_T Perimeter;
  emxArray_real_T *PixelValues;
  real_T WeightedCentroid[2];
  real_T MeanIntensity;
  real_T MinIntensity;
  real_T MaxIntensity;
  emxArray_real_T *SubarrayIdx;
  real_T SubarrayIdxLengths[2];
} d_struct_T;

#endif                                 /*typedef_d_struct_T*/

#ifndef struct_c_emxArray_struct_T
#define struct_c_emxArray_struct_T

struct c_emxArray_struct_T
{
  d_struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
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
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
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
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
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
  uint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint8_T*/

#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T

typedef struct emxArray_uint8_T emxArray_uint8_T;

#endif                                 /*typedef_emxArray_uint8_T*/

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

#ifndef struct_s6wgKYuP6EfjbxVSz7SpFkH
#define struct_s6wgKYuP6EfjbxVSz7SpFkH

struct s6wgKYuP6EfjbxVSz7SpFkH
{
  real_T E_tgt_for_lane;
  real_T A_tgt_for_lane;
  real_T fraction_of_img_to_ignore;
  real_T nColors;
  real_T color_labels[5];
  real_T color_markers[10];
  emxArray_real_T *label;
};

#endif                                 /*struct_s6wgKYuP6EfjbxVSz7SpFkH*/

#ifndef typedef_ybp_finder_CLS
#define typedef_ybp_finder_CLS

typedef struct s6wgKYuP6EfjbxVSz7SpFkH ybp_finder_CLS;

#endif                                 /*typedef_ybp_finder_CLS*/
#endif

/* End of code generation (bh_my_detect_ALGORITHM_for_codegen_types.h) */
