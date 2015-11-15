/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lusolve.c
 *
 * Code generation for function 'lusolve'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "lusolve.h"
#include "warning.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
void warn_singular(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (!emlrtSetWarningFlag(sp)) {
    st.site = &nb_emlrtRSI;
    warning(&st);
  }
}

/* End of code generation (lusolve.c) */
