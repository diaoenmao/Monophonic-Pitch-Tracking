/*
 * File: diff.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "diff.h"
#include "yaapt_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  int orderForDim;
  int iyLead;
  double work_data_idx_0;
  int m;
  double tmp1;
  double tmp2;
  if (x->size[1] - 1 <= 1) {
    orderForDim = x->size[1] - 1;
  } else {
    orderForDim = 1;
  }

  if (orderForDim < 1) {
    iyLead = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)y, iyLead, (int)sizeof(double));
  } else {
    orderForDim = x->size[1] - 1;
    iyLead = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = orderForDim;
    emxEnsureCapacity((emxArray__common *)y, iyLead, (int)sizeof(double));
    if (!(y->size[1] == 0)) {
      orderForDim = 1;
      iyLead = 0;
      work_data_idx_0 = x->data[0];
      for (m = 2; m <= x->size[1]; m++) {
        tmp1 = x->data[orderForDim];
        tmp2 = work_data_idx_0;
        work_data_idx_0 = tmp1;
        tmp1 -= tmp2;
        orderForDim++;
        y->data[iyLead] = tmp1;
        iyLead++;
      }
    }
  }
}

/*
 * File trailer for diff.c
 *
 * [EOF]
 */
