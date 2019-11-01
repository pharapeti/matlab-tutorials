/*
 * File: _coder_bh_MY_CV_ALGORITHMS_mex.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "_coder_bh_MY_CV_ALGORITHMS_api.h"
#include "_coder_bh_MY_CV_ALGORITHMS_mex.h"

/* Variable Definitions */
static const char * emlrtEntryPoints[3] = { "bh_my_detect_ALGORITHM_for_codegen",
  "bh_my_lane_preprocess_mask", "bh_my_track_ALGORITHM_for_codegen" };

/* Function Declarations */
static void c_bh_my_detect_ALGORITHM_for_co(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3]);
static void c_bh_my_lane_preprocess_mask_me(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[3]);
static void c_bh_my_track_ALGORITHM_for_cod(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[3]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
static void c_bh_my_detect_ALGORITHM_for_co(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3])
{
  const mxArray *inputs[3];
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

  /* Temporary copy for mex inputs. */
  if (0 <= nrhs - 1) {
    memcpy((void *)&inputs[0], (void *)&prhs[0], (uint32_T)(nrhs * (int32_T)
            sizeof(const mxArray *)));
  }

  /* Call the function. */
  bh_my_detect_ALGORITHM_for_codegen_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  bh_MY_CV_ALGORITHMS_terminate();
}

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[2]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
static void c_bh_my_lane_preprocess_mask_me(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[3])
{
  const mxArray *inputs[3];
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        26, "bh_my_lane_preprocess_mask");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 26,
                        "bh_my_lane_preprocess_mask");
  }

  /* Temporary copy for mex inputs. */
  if (0 <= nrhs - 1) {
    memcpy((void *)&inputs[0], (void *)&prhs[0], (uint32_T)(nrhs * (int32_T)
            sizeof(const mxArray *)));
  }

  /* Call the function. */
  bh_my_lane_preprocess_mask_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  bh_MY_CV_ALGORITHMS_terminate();
}

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[2]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
static void c_bh_my_track_ALGORITHM_for_cod(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[3])
{
  const mxArray *inputs[3];
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        33, "bh_my_track_ALGORITHM_for_codegen");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 33,
                        "bh_my_track_ALGORITHM_for_codegen");
  }

  /* Temporary copy for mex inputs. */
  if (0 <= nrhs - 1) {
    memcpy((void *)&inputs[0], (void *)&prhs[0], (uint32_T)(nrhs * (int32_T)
            sizeof(const mxArray *)));
  }

  /* Call the function. */
  bh_my_track_ALGORITHM_for_codegen_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  bh_MY_CV_ALGORITHMS_terminate();
}

/*
 * Arguments    : int32_T nlhs
 *                const mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexAtExit(bh_MY_CV_ALGORITHMS_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  bh_MY_CV_ALGORITHMS_initialize();
  st.tls = emlrtRootTLSGlobal;

  /* Dispatch the entry-point. */
  switch (emlrtGetEntryPointIndexR2016a(&st, nrhs, prhs, emlrtEntryPoints, 3)) {
   case 0:
    c_bh_my_detect_ALGORITHM_for_co(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;

   case 1:
    c_bh_my_lane_preprocess_mask_me(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;

   case 2:
    c_bh_my_track_ALGORITHM_for_cod(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  }
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
 * File trailer for _coder_bh_MY_CV_ALGORITHMS_mex.c
 *
 * [EOF]
 */
