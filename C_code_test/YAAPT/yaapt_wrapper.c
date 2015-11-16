/*
 * File: yaapt_wrapper.c
 *
 */
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
