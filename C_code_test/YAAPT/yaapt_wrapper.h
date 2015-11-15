#ifndef __ADD_WRAPPER_H__
#define __ADD_WRAPPER_H__

/* Include Files */
#include <stdio.h>
#include "yaapt.h"
#include "yaapt_terminate.h"
#include "yaapt_emxAPI.h"
#include "yaapt_initialize.h"

/* Function Declarations */
extern void yaapt_wrapper(double* data, size_t data_length, double Fs, double** pitch, double *numfrms, double *frmrate);

#endif

/*
 * File trailer for Add.h
 *
 * [EOF]
 */
