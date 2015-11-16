/*
 * File: main.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 19:51:15
 */
/* Include Files */
#include <stdio.h>
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "main.h"
#include "yaapt_terminate.h"
#include "yaapt_emxAPI.h"
#include "yaapt_initialize.h"

/* Function Declarations */
static emxArray_real_T *argInit_1xUnbounded_real_T(void);
static double argInit_real_T(void);
static void main_yaapt(void);
static double *getData(void);
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
  double frmrate;
  double numfrms;
  emxInitArray_real_T(&Pitch, 2);

  /* Initialize function 'yaapt' input arguments. */
  /* Initialize function input argument 'Data'. */
  Data = argInit_1xUnbounded_real_T();

  /* Call the entry-point 'yaapt'. */
  yaapt(Data, argInit_real_T(), Pitch, &numfrms, &frmrate);
  emxDestroyArray_real_T(Pitch);
  emxDestroyArray_real_T(Data);
}

static double *getData(void)
{
    FILE* stream = fopen("data.csv", "r");

    char line[1024];
    double* data = NULL;
    double* data_prev = NULL;
    int count = 0;
    while (fgets(line, 1024, stream))
    {
      count++;
      double tmp = strtod(line, NULL);
      data = (double*) realloc (data_prev, count * sizeof(double));
      if (data!=NULL) {
       data_prev=data;
       data[count-1]=tmp;
      } else {
       free (data_prev);
       puts ("Error (re)allocating memory");
       exit (1);
      }
    }
    printf("%d\n",count);
     return data;
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
  //yaapt_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  //main_yaapt();

  /* Terminate the application.
     You do not need to do this more than one time. */
  //yaapt_terminate();
  double *data = getData();
   /*
    int i;
    for(i=0;i<340547;i++){
      printf("%f\n",data[i]);
    }
    */
  double Fs = 44100;
  double *out;
  double frmrate;
  double numfrms;
  yaapt_wrapper(data, 340547, Fs, &out, &numfrms, &frmrate);
  int i ;
  for(i=0;i<numfrms;i++){
      printf("%f\n",out[i]);
  }
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
