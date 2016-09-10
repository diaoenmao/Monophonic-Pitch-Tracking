/*
 * infocheck.c
 *
 * Code generation for function 'infocheck'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "infocheck.h"
#include "error1.h"
#include "yaapt_data.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
boolean_T infocheck(const emlrtStack *sp, int32_T info)
{
  boolean_T p;
  boolean_T b_p;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (info != 0) {
    p = true;
    b_p = false;
    if (info == -4) {
      b_p = true;
    }

    if (!b_p) {
      if (info == -1010) {
        st.site = &bd_emlrtRSI;
        e_error(&st);
      } else {
        st.site = &cd_emlrtRSI;
        g_error(&st, info);
      }
    }
  } else {
    p = false;
  }

  return p;
}

/* End of code generation (infocheck.c) */
