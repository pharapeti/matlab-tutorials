/*
 * indexShapeCheck.c
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "indexShapeCheck.h"

/* Variable Definitions */
static emlrtRSInfo ob_emlrtRSI = { 14, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 80, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 18, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\MATLAB\\R2017b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

/* Function Definitions */

/*
 *
 */
void b_indexShapeCheck(const emlrtStack *sp, int32_T matrixSize, const int32_T
  indexSize[2])
{
  boolean_T nonSingletonDimFound;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (!(matrixSize != 1)) {
    nonSingletonDimFound = false;
    if (indexSize[0] != 1) {
      nonSingletonDimFound = true;
    }

    if (indexSize[1] != 1) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
      }
    }

    if (nonSingletonDimFound) {
      nonSingletonDimFound = true;
    } else {
      nonSingletonDimFound = false;
    }
  } else {
    nonSingletonDimFound = false;
  }

  st.site = &tf_emlrtRSI;
  if (nonSingletonDimFound) {
    emlrtErrorWithMessageIdR2012b(&st, &oc_emlrtRTEI,
      "Coder:FE:PotentialVectorVector", 0);
  }
}

/*
 *
 */
void indexShapeCheck(const emlrtStack *sp, const int32_T indexSize[2])
{
  boolean_T nonSingletonDimFound;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nonSingletonDimFound = false;
  if (indexSize[0] != 1) {
    nonSingletonDimFound = true;
  }

  if (indexSize[1] != 1) {
    if (nonSingletonDimFound) {
      nonSingletonDimFound = false;
    } else {
      nonSingletonDimFound = true;
    }
  }

  if (nonSingletonDimFound) {
    st.site = &ob_emlrtRSI;
    b_st.site = &pb_emlrtRSI;
    if (indexSize[0] != 1) {
      emlrtErrorWithMessageIdR2012b(&b_st, &oc_emlrtRTEI,
        "Coder:FE:PotentialMatrixMatrix", 0);
    }
  }
}

/* End of code generation (indexShapeCheck.c) */
