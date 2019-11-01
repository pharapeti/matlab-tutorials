/*
 * _coder_bh_my_detect_ALGORITHM_for_codegen_mex_mex.c
 *
 * Code generation for function '_coder_bh_my_detect_ALGORITHM_for_codegen_mex_mex'
 *
 */

/* Include files */
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_mex_mex.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_terminate.h"
#include "_coder_bh_my_detect_ALGORITHM_for_codegen_mex_api.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_initialize.h"
#include "bh_my_detect_ALGORITHM_for_codegen_mex_data.h"

/* Variable Definitions */
static const char * emlrtEntryPoints[3] = { "bh_my_detect_ALGORITHM_for_codegen",
  "bh_my_lane_preprocess_mask", "bh_my_track_ALGORITHM_for_codegen" };

/* Function Declarations */
static void c_bh_my_lane_preprocess_mask_me(g_bh_my_detect_ALGORITHM_for_co *SD,
  int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const mxArray *prhs[3]);
static void d_bh_my_track_ALGORITHM_for_cod(g_bh_my_detect_ALGORITHM_for_co *SD,
  int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const mxArray *prhs[3]);
static void f_bh_my_detect_ALGORITHM_for_co(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */
static void c_bh_my_lane_preprocess_mask_me(g_bh_my_detect_ALGORITHM_for_co *SD,
  int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const mxArray *prhs[3])
{
  int32_T n;
  const mxArray *inputs[3];
  const mxArray *outputs[2];
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
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  bh_my_lane_preprocess_mask_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    n = 1;
  } else {
    n = nlhs;
  }

  emlrtReturnArrays(n, plhs, outputs);

  /* Module termination. */
  bh_my_detect_ALGORITHM_for_codegen_mex_terminate();
}

static void d_bh_my_track_ALGORITHM_for_cod(g_bh_my_detect_ALGORITHM_for_co *SD,
  int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const mxArray *prhs[3])
{
  int32_T n;
  const mxArray *inputs[3];
  const mxArray *outputs[2];
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
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  bh_my_track_ALGORITHM_for_codegen_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    n = 1;
  } else {
    n = nlhs;
  }

  emlrtReturnArrays(n, plhs, outputs);

  /* Module termination. */
  bh_my_detect_ALGORITHM_for_codegen_mex_terminate();
}

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
  bh_my_detect_ALGORITHM_for_codegen_mex_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  g_bh_my_detect_ALGORITHM_for_co *h_bh_my_detect_ALGORITHM_for_co = NULL;
  h_bh_my_detect_ALGORITHM_for_co = (g_bh_my_detect_ALGORITHM_for_co *)
    emlrtMxCalloc(1, 1U * sizeof(g_bh_my_detect_ALGORITHM_for_co));
  mexAtExit(bh_my_detect_ALGORITHM_for_codegen_mex_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  bh_my_detect_ALGORITHM_for_codegen_mex_initialize();
  st.tls = emlrtRootTLSGlobal;

  /* Dispatch the entry-point. */
  switch (emlrtGetEntryPointIndexR2016a(&st, nrhs, prhs, emlrtEntryPoints, 3)) {
   case 0:
    f_bh_my_detect_ALGORITHM_for_co(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;

   case 1:
    c_bh_my_lane_preprocess_mask_me(h_bh_my_detect_ALGORITHM_for_co, nlhs, plhs,
      nrhs - 1, &prhs[1]);
    break;

   case 2:
    d_bh_my_track_ALGORITHM_for_cod(h_bh_my_detect_ALGORITHM_for_co, nlhs, plhs,
      nrhs - 1, &prhs[1]);
    break;
  }

  emlrtMxFree(h_bh_my_detect_ALGORITHM_for_co);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_bh_my_detect_ALGORITHM_for_codegen_mex_mex.c) */
