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
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
boolean_T infocheck(const emlrtStack *sp, int32_T info)
{
  boolean_T p;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (info != 0) {
    p = false;
    if (info == -4) {
      p = true;
    }

    if (!p) {
      if (info == -1010) {
        st.site = &cd_emlrtRSI;
        e_error(&st);
      } else {
        st.site = &dd_emlrtRSI;
        g_error(&st, info);
      }
    }

    p = true;
  } else {
    p = false;
  }

  return p;
}

/* End of code generation (infocheck.c) */
