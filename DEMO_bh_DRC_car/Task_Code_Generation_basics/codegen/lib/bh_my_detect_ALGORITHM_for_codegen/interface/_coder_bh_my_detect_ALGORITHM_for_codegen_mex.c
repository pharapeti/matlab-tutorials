/*
 * File: _coder_bh_my_detect_ALGORITHM_for_codegen_mex.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_api.h"
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_mex.h"

/* Function Declarations */
static void c_bh_my_detect_ALGORITHM_for_co(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[3]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
static void c_bh_my_detect_ALGORITHM_for_co(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
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

  /* Call the function. */
  bh_my_detect_ALGORITHM_for_codegen_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  bh_my_detect_ALGORITHM_for_codegen_terminate();
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(bh_my_detect_ALGORITHM_for_codegen_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  bh_my_detect_ALGORITHM_for_codegen_initialize();

  /* Dispatch the entry-point. */
  c_bh_my_detect_ALGORITHM_for_co(nlhs, plhs, nrhs, prhs);
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_bh_my_detect_ALGORITHM_for_codegen_mex.c
 *
 * [EOF]
 */
