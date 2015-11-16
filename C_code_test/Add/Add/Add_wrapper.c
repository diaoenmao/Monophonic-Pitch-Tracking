/*
 * File: Add_wrapper.c
 *
 */

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
