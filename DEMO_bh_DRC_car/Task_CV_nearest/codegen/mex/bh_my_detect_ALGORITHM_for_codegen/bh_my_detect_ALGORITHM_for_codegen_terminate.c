/*
 * bh_my_detect_ALGORITHM_for_codegen_terminate.c
 *
 * Code generation for function 'bh_my_detect_ALGORITHM_for_codegen_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_detect_ALGORITHM_for_codegen_terminate.h"
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_mex.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Function Definitions */
void bh_my_detect_ALGORITHM_for_codegen_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  e_bh_my_detect_ALGORITHM_for_co();
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void bh_my_detect_ALGORITHM_for_codegen_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (bh_my_detect_ALGORITHM_for_codegen_terminate.c) */
