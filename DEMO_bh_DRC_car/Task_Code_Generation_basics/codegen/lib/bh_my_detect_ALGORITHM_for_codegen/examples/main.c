/*
 * File: main.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "main.h"
#include "bh_my_detect_ALGORITHM_for_codegen_terminate.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxAPI.h"
#include "bh_my_detect_ALGORITHM_for_codegen_initialize.h"

/* Function Declarations */
static void argInit_1x5_real_T(double result[5]);
static void argInit_240x320x3_uint8_T(unsigned char result[230400]);
static void argInit_5x2_real_T(double result[10]);
static boolean_T argInit_boolean_T(void);
static double argInit_real_T(void);
static void argInit_struct0_T(struct0_T *result);
static unsigned char argInit_uint8_T(void);
static void main_bh_my_detect_ALGORITHM_for_codegen(void);

/* Function Definitions */

/*
 * Arguments    : double result[5]
 * Return Type  : void
 */
static void argInit_1x5_real_T(double result[5])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 5; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : unsigned char result[230400]
 * Return Type  : void
 */
static void argInit_240x320x3_uint8_T(unsigned char result[230400])
{
  int idx0;
  int idx1;
  int idx2;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 240; idx0++) {
    for (idx1 = 0; idx1 < 320; idx1++) {
      for (idx2 = 0; idx2 < 3; idx2++) {
        /* Set the value of the array element.
           Change this value to the value that the application requires. */
        result[(idx2 + 3 * idx1) + 960 * idx0] = argInit_uint8_T();
      }
    }
  }
}

/*
 * Arguments    : double result[10]
 * Return Type  : void
 */
static void argInit_5x2_real_T(double result[10])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 5; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx1 + (idx0 << 1)] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : boolean_T
 */
static boolean_T argInit_boolean_T(void)
{
  return false;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : struct0_T *result
 * Return Type  : void
 */
static void argInit_struct0_T(struct0_T *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result->nColors = argInit_real_T();
  argInit_1x5_real_T(result->color_labels);
  argInit_5x2_real_T(result->color_markers);
}

/*
 * Arguments    : void
 * Return Type  : unsigned char
 */
static unsigned char argInit_uint8_T(void)
{
  return 0U;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_bh_my_detect_ALGORITHM_for_codegen(void)
{
  struct1_T BLUE_s;
  struct1_T YELL_s;
  struct2_T PURP_s;
  static unsigned char uv0[230400];
  struct0_T r5;
  emxInit_struct1_T(&BLUE_s);
  emxInit_struct1_T(&YELL_s);
  emxInit_struct2_T(&PURP_s);

  /* Initialize function 'bh_my_detect_ALGORITHM_for_codegen' input arguments. */
  /* Initialize function input argument 'I'. */
  /* Initialize function input argument 'marker_s'. */
  /* Call the entry-point 'bh_my_detect_ALGORITHM_for_codegen'. */
  argInit_240x320x3_uint8_T(uv0);
  argInit_struct0_T(&r5);
  bh_my_detect_ALGORITHM_for_codegen(uv0, argInit_boolean_T(), &r5, &BLUE_s,
    &YELL_s, &PURP_s);
  emxDestroy_struct2_T(PURP_s);
  emxDestroy_struct1_T(YELL_s);
  emxDestroy_struct1_T(BLUE_s);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  bh_my_detect_ALGORITHM_for_codegen_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_bh_my_detect_ALGORITHM_for_codegen();

  /* Terminate the application.
     You do not need to do this more than one time. */
  bh_my_detect_ALGORITHM_for_codegen_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
