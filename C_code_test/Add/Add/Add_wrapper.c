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

#include "Add_Wrapper.h"


/* Function Declarations */

double *Add_wrapper(double* data, size_t arr_length, double b) {
  Add_initialize();
  
  emxArray_real_T *out;
  emxArray_real_T *arr;
  emxInitArray_real_T(&out, 2);

  /* Initialize function 'Add' input arguments. */
  /* Initialize function input argument 'arr'. */
  //arr = argInit_1xUnbounded_real_T();
  arr = emxCreateWrapper_real_T(data,1,arr_length);
  int i;
  for(i=0;i<arr_length;i++){
      printf("%f ", arr->data[i]);
  }
  printf("\n");
  /* Call the entry-point 'Add'. */
  Add(arr, b, out);

  for(i=0;i<arr_length;i++){
      printf("%f ", out->data[i]);
  }
  emxDestroyArray_real_T(out);
  emxDestroyArray_real_T(arr); 
  
  Add_terminate();
  return out->data;
}
/*
 * File trailer for main.c
 *
 * [EOF]
 */
