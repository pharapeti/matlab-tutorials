/*
 * _coder_bh_my_detect_ALGORITHM_for_codegen_mex.c
 *
 * Code generation for function '_coder_bh_my_detect_ALGORITHM_for_codegen_mex'
 *
 */

/* Include files */
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_mex.h"
#include "bh_my_detect_ALGORITHM_for_codegen_terminate.h"
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_api.h"
#include "bh_my_detect_ALGORITHM_for_codegen_initialize.h"
#include "bh_my_detect_ALGORITHM_for_codegen_data.h"

/* Function Declarations */
static void f_bh_my_detect_ALGORITHM_for_co(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */
static void f_bh_my_detect_ALGORITHM_for_co(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3])
{
  int32_T n;
  const mxArray *inputs[3];
  const mxArray *outputs[3];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        34, "bh_my_detect_ALGORITHM_for_codegen");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 34,
                        "bh_my_detect_ALGORITHM_for_codegen");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  bh_my_detect_ALGORITHM_for_codegen_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    n = 1;
  } else {
    n = nlhs;
  }

  emlrtReturnArrays(n, plhs, outputs);

  /* Module termination. */
  bh_my_detect_ALGORITHM_for_codegen_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(bh_my_detect_ALGORITHM_for_codegen_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  bh_my_detect_ALGORITHM_for_codegen_initialize();

  /* Dispatch the entry-point. */
  f_bh_my_detect_ALGORITHM_for_co(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_bh_my_detect_ALGORITHM_for_codegen_mex.c) */
