/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 14-Nov-2015 18:45:41
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

#include "yaapt_Wrapper.h"


/* Function Declarations */

void yaapt_wrapper(double* data, size_t data_length, double Fs, double** pitch, double *numfrms, double *frmrate) {
  yaapt_initialize();
  
  emxArray_real_T *Pitch;
  emxArray_real_T *Data;
  emxInitArray_real_T(&Pitch, 2);

  /* Initialize function 'yaapt' input arguments. */
  /* Initialize function input argument 'Data'. */
  Data = emxCreateWrapper_real_T(data,1,data_length);
  
  /* Call the entry-point 'yaapt'. */
  yaapt(Data, Fs, Pitch, numfrms, frmrate);
  
  *pitch = Pitch->data;

  emxDestroyArray_real_T(Pitch);
  emxDestroyArray_real_T(Data);
  
  yaapt_terminate();
}
/*
 * File trailer for main.c
 *
 * [EOF]
 */
