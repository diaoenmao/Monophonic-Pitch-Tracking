/*
 * File: main.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
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
#include "yaapt.h"
#include "main.h"
#include "yaapt_terminate.h"
#include "yaapt_emxAPI.h"
#include "yaapt_initialize.h"

/* Function Declarations */
static void argInit_1x34_real_T(double result[34]);
static emxArray_real_T *argInit_1xUnbounded_real_T(void);
static double argInit_real_T(void);
static void main_yaapt(void);

/* Function Definitions */

/*
 * Arguments    : double result[34]
 * Return Type  : void
 */
static void argInit_1x34_real_T(double result[34])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 34; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_1xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  static int iv0[2] = { 1, 2 };

  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv0);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[result->size[0] * idx1] = argInit_real_T();
  }

  return result;
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
 * Arguments    : void
 * Return Type  : void
 */
static void main_yaapt(void)
{
  emxArray_real_T *Pitch;
  emxArray_real_T *Data;
  double dv0[34];
  double numfrms;
  double frmrate;
  emxInitArray_real_T(&Pitch, 2);

  /* Initialize function 'yaapt' input arguments. */
  /* Initialize function input argument 'Data'. */
  Data = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'Parameter'. */
  /* Call the entry-point 'yaapt'. */
  argInit_1x34_real_T(dv0);
  yaapt(Data, argInit_real_T(), dv0, Pitch, &numfrms, &frmrate);
  emxDestroyArray_real_T(Pitch);
  emxDestroyArray_real_T(Data);
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
  yaapt_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_yaapt();

  /* Terminate the application.
     You do not need to do this more than one time. */
  yaapt_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
