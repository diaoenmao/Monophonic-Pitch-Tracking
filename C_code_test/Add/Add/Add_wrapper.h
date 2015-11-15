#ifndef __ADD_WRAPPER_H__
#define __ADD_WRAPPER_H__

/* Include Files */
#include <stdio.h>
#include "Add.h"
#include "Add_terminate.h"
#include "Add_emxAPI.h"
#include "Add_initialize.h"

/* Function Declarations */
extern double* Add_wrapper(double* arr, size_t arr_length, double b);

#endif

/*
 * File trailer for Add.h
 *
 * [EOF]
 */
