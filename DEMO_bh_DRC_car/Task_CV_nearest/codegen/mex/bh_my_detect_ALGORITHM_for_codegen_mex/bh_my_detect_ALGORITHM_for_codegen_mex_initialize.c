/*
 * bh_my_detect_ALGORITHM_for_codegen_mex_initialize.c
 *
 * Code generation for function 'bh_my_detect_ALGORITHM_for_codegen_mex_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_initialize.h"
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_mex_mex.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Function Declarations */
static void c_bh_my_detect_ALGORITHM_for_co(const emlrtStack *sp);

/* Function Definitions */
static void c_bh_my_detect_ALGORITHM_for_co(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  fr_count_not_empty_init();
  st.site = NULL;
  d_bh_my_detect_ALGORITHM_for_co(&st);
  c_bh_my_track_ALGORITHM_for_cod();
}

void bh_my_detect_ALGORITHM_for_codegen_mex_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "Image_Toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    c_bh_my_detect_ALGORITHM_for_co(&st);
  }
}

/* End of code generation (bh_my_detect_ALGORITHM_for_codegen_mex_initialize.c) */
