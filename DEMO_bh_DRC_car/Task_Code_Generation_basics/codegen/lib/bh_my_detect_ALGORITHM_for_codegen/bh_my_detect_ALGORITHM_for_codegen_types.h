/*
 * File: bh_my_detect_ALGORITHM_for_codegen_types.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

#ifndef BH_MY_DETECT_ALGORITHM_FOR_CODEGEN_TYPES_H
#define BH_MY_DETECT_ALGORITHM_FOR_CODEGEN_TYPES_H

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

#ifndef typedef_b_emxArray_struct_T
#define typedef_b_emxArray_struct_T

typedef struct {
  c_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} b_emxArray_struct_T;

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

#ifndef struct_scctPWU20CrE2ouIEUqll1_tag
#define struct_scctPWU20CrE2ouIEUqll1_tag

struct scctPWU20CrE2ouIEUqll1_tag
{
  emxArray_boolean_T *BW;
  double NUM_ROWS;
  double NUM_COLS;
  double left_edge_xy_col[2];
  double right_edge_xy_col[2];
  double centroid_xy_col[2];
  boolean_T tf_is_detected;
};

#endif                                 /*struct_scctPWU20CrE2ouIEUqll1_tag*/

#ifndef typedef_box_info_CLS
#define typedef_box_info_CLS

typedef struct scctPWU20CrE2ouIEUqll1_tag box_info_CLS;

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

#ifndef typedef_c_emxArray_struct_T
#define typedef_c_emxArray_struct_T

typedef struct {
  d_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} c_emxArray_struct_T;

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

#ifndef typedef_emxArray_struct_T
#define typedef_emxArray_struct_T

typedef struct {
  b_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_struct_T;

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

#ifndef struct_sKPRtTYqOPuyVOlbBEROpw_tag
#define struct_sKPRtTYqOPuyVOlbBEROpw_tag

struct sKPRtTYqOPuyVOlbBEROpw_tag
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

#endif                                 /*struct_sKPRtTYqOPuyVOlbBEROpw_tag*/

#ifndef typedef_lane_info_CLS
#define typedef_lane_info_CLS

typedef struct sKPRtTYqOPuyVOlbBEROpw_tag lane_info_CLS;

#endif                                 /*typedef_lane_info_CLS*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  double nColors;
  double color_labels[5];
  double color_markers[10];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef struct_sMXS9hbI1LSFh4mdcSqTbu_tag
#define struct_sMXS9hbI1LSFh4mdcSqTbu_tag

struct sMXS9hbI1LSFh4mdcSqTbu_tag
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
  double NUM_ROWS;
  double NUM_COLS;
  double left_edge_xy_col[2];
  double right_edge_xy_col[2];
  double centroid_xy_col[2];
  boolean_T tf_is_detected;
};

#endif                                 /*struct_srbi8mkMWnVzBlG41YlL7eH_tag*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct srbi8mkMWnVzBlG41YlL7eH_tag struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef struct_sXcOx1GqHmapCjZPgAI1N5F_tag
#define struct_sXcOx1GqHmapCjZPgAI1N5F_tag

struct sXcOx1GqHmapCjZPgAI1N5F_tag
{
  double E_tgt_for_lane;
  double A_tgt_for_lane;
  double fraction_of_img_to_ignore;
  double nColors;
  double color_labels[5];
  double color_markers[10];
  emxArray_real_T *label;
};

#endif                                 /*struct_sXcOx1GqHmapCjZPgAI1N5F_tag*/

#ifndef typedef_ybp_finder_CLS
#define typedef_ybp_finder_CLS

typedef struct sXcOx1GqHmapCjZPgAI1N5F_tag ybp_finder_CLS;

#endif                                 /*typedef_ybp_finder_CLS*/
#endif

/*
 * File trailer for bh_my_detect_ALGORITHM_for_codegen_types.h
 *
 * [EOF]
 */
