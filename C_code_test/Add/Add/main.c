/*
 * File: main.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 19:57:34
 */
/* Include Files */
#include <stdio.h>
#include "rt_nonfinite.h"
#include "Add.h"
#include "main.h"
#include "Add_terminate.h"
#include "Add_emxAPI.h"
#include "Add_initialize.h"
#include "Add_wrapper.h"

/* Function Declarations */
static emxArray_real_T *argInit_1xUnbounded_real_T(void);
static double argInit_real_T(void);
static void main_Add(void);


/* Function Definitions */

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
  return 1.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_Add(void)
{
  emxArray_real_T *out;
  emxArray_real_T *arr;
  emxInitArray_real_T(&out, 2);

  /* Initialize function 'Add' input arguments. */
  /* Initialize function input argument 'arr'. */
  //arr = argInit_1xUnbounded_real_T();
  double data[] = {1,2,3,4,5};
  arr = emxCreateWrapper_real_T(data,1,5);
  int i;
  for(i=0;i<5;i++){
      printf("%f ", arr->data[i]);
  }
  printf("\n");
  /* Call the entry-point 'Add'. */
  Add(arr, argInit_real_T(), out);

  for(i=0;i<5;i++){
      printf("%f ", out->data[i]);
  }
  emxDestroyArray_real_T(out);
  emxDestroyArray_real_T(arr);
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
  //Add_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  //main_Add();

  /* Terminate the application.
     You do not need to do this more than one time. */
  //Add_terminate();
  double arr[] = {1,2,3,4,5};
  size_t arr_length = sizeof(arr)/sizeof(arr[0]);
  double b = 1;
  double *out = Add_wrapper(arr, arr_length, b);
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
