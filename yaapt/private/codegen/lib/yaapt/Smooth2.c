/*
 * File: Smooth2.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Smooth2.h"
#include "yaapt_emxutil.h"
#include "all.h"
#include "mrdivide.h"
#include "isequal.h"
#include "sort1.h"
#include "diff.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *arr
 *                double Prm_smooth_threshold
 *                emxArray_real_T *out
 * Return Type  : void
 */
void Smooth2(const emxArray_real_T *arr, double Prm_smooth_threshold,
             emxArray_real_T *out)
{
  emxArray_real_T *headidx;
  emxArray_real_T *headpitches;
  double pivot;
  int i29;
  int i;
  emxArray_real_T *prev_headidx;
  int idx;
  int ii;
  emxArray_real_T *b_headidx;
  emxArray_real_T *pitcheslength;
  emxArray_real_T *visited;
  emxArray_real_T *sorted_pitcheslength;
  emxArray_real_T *sorted_idx;
  emxArray_int32_T *iidx;
  emxArray_boolean_T *x;
  emxArray_boolean_T *b_visited;
  emxArray_real_T *c_headidx;
  emxArray_real_T *b_headpitches;
  emxArray_int32_T *b_pitcheslength;
  emxArray_real_T *d_headidx;
  emxArray_int32_T *c_pitcheslength;
  emxArray_real_T *c_headpitches;
  emxArray_int32_T *d_pitcheslength;
  emxArray_real_T *c_visited;
  emxArray_int32_T *e_pitcheslength;
  emxArray_real_T *e_headidx;
  emxArray_int32_T *f_pitcheslength;
  emxArray_real_T *d_headpitches;
  emxArray_int32_T *g_pitcheslength;
  emxArray_real_T *d_visited;
  emxArray_int32_T *h_pitcheslength;
  emxArray_real_T *f_headidx;
  emxArray_int32_T *i_pitcheslength;
  emxArray_real_T *e_headpitches;
  emxArray_int32_T *j_pitcheslength;
  emxArray_real_T *e_visited;
  emxArray_int32_T *k_pitcheslength;
  emxArray_real_T *g_headidx;
  emxArray_int32_T *l_pitcheslength;
  emxArray_real_T *f_headpitches;
  emxArray_int32_T *m_pitcheslength;
  emxArray_real_T *f_visited;
  emxArray_int32_T *n_pitcheslength;
  emxArray_real_T *h_headidx;
  emxArray_int32_T *o_pitcheslength;
  emxArray_real_T *g_headpitches;
  emxArray_int32_T *p_pitcheslength;
  emxArray_real_T *g_visited;
  emxArray_int32_T *q_pitcheslength;
  emxArray_real_T *i_headidx;
  emxArray_int32_T *r_pitcheslength;
  emxArray_real_T *h_headpitches;
  emxArray_int32_T *s_pitcheslength;
  emxArray_real_T *h_visited;
  int exitg1;
  boolean_T guard1 = false;
  int k;
  int ii_data[1];
  boolean_T exitg2;
  double index_data[1];
  double check_pitchlength_data[1];
  boolean_T check_idx_data[1];
  double b_check_idx_data[1];
  int check_idx_size[2];
  emxArray_boolean_T c_check_idx_data;
  boolean_T d_check_idx_data[1];
  int left_pitch_size[2];
  int b_check_idx_size[2];
  double left_pitch_data[1];
  int left_pitchlength_size[2];
  double left_pitchlength_data[1];
  emxArray_boolean_T e_check_idx_data;
  int right_pitchlength_size[2];
  double right_pitch_data[1];
  double right_pitchlength_data[1];
  boolean_T headpitches_data[1];
  int headpitches_size[2];
  emxArray_boolean_T b_headpitches_data;
  double anew;
  boolean_T b_left_pitch_data[1];
  int b_left_pitch_size[2];
  emxArray_boolean_T c_left_pitch_data;
  boolean_T b_guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T b_right_pitch_data[1];
  int right_pitch_size[2];
  boolean_T d_left_pitch_data[1];
  int c_left_pitch_size[2];
  boolean_T e_left_pitch_data[1];
  emxArray_boolean_T c_right_pitch_data;
  int d_left_pitch_size[2];
  boolean_T b_left_pitchlength_data[1];
  int b_left_pitchlength_size[2];
  boolean_T b_check_pitchlength_data[1];
  emxArray_boolean_T f_left_pitch_data;
  int check_pitchlength_size[2];
  boolean_T c_check_pitchlength_data[1];
  emxArray_boolean_T g_left_pitch_data;
  boolean_T d_check_pitchlength_data[1];
  int b_check_pitchlength_size[2];
  int c_check_pitchlength_size[2];
  boolean_T e_check_pitchlength_data[1];
  emxArray_boolean_T c_left_pitchlength_data;
  int d_check_pitchlength_size[2];
  emxArray_boolean_T f_check_pitchlength_data;
  boolean_T g_check_pitchlength_data[1];
  boolean_T d_right_pitch_data[1];
  int e_check_pitchlength_size[2];
  emxArray_boolean_T h_check_pitchlength_data;
  int b_right_pitch_size[2];
  emxArray_boolean_T i_check_pitchlength_data;
  boolean_T j_check_pitchlength_data[1];
  boolean_T e_right_pitch_data[1];
  int f_check_pitchlength_size[2];
  emxArray_boolean_T k_check_pitchlength_data;
  int c_right_pitch_size[2];
  boolean_T d_left_pitchlength_data[1];
  emxArray_boolean_T l_check_pitchlength_data;
  int c_left_pitchlength_size[2];
  emxArray_boolean_T f_right_pitch_data;
  emxArray_boolean_T m_check_pitchlength_data;
  emxArray_boolean_T g_right_pitch_data;
  int ndbl;
  int apnd;
  boolean_T h_left_pitch_data[1];
  emxArray_boolean_T e_left_pitchlength_data;
  int e_left_pitch_size[2];
  emxArray_boolean_T i_left_pitch_data;
  boolean_T j_left_pitch_data[1];
  int f_left_pitch_size[2];
  boolean_T k_left_pitch_data[1];
  int g_left_pitch_size[2];
  double f_left_pitchlength_data[1];
  int d_left_pitchlength_size[2];
  boolean_T l_left_pitch_data[1];
  boolean_T n_check_pitchlength_data[1];
  int h_left_pitch_size[2];
  int g_check_pitchlength_size[2];
  emxArray_boolean_T m_left_pitch_data;
  double b_apnd;
  double cdiff;
  emxArray_boolean_T n_left_pitch_data;
  unsigned int u0;
  emxArray_boolean_T o_check_pitchlength_data;
  unsigned int u1;
  boolean_T o_left_pitch_data[1];
  emxArray_boolean_T p_left_pitch_data;
  int i_left_pitch_size[2];
  boolean_T p_check_pitchlength_data[1];
  int h_check_pitchlength_size[2];
  boolean_T q_check_pitchlength_data[1];
  int i_check_pitchlength_size[2];
  emxArray_boolean_T q_left_pitch_data;
  boolean_T r_check_pitchlength_data[1];
  emxArray_boolean_T s_check_pitchlength_data;
  int j_check_pitchlength_size[2];
  emxArray_boolean_T t_check_pitchlength_data;
  emxArray_boolean_T u_check_pitchlength_data;
  boolean_T v_check_pitchlength_data[1];
  int k_check_pitchlength_size[2];
  emxArray_boolean_T w_check_pitchlength_data;
  emxInit_real_T(&headidx, 2);
  emxInit_real_T(&headpitches, 2);
  pivot = arr->data[0];
  i29 = headidx->size[0] * headidx->size[1];
  headidx->size[0] = 1;
  headidx->size[1] = 1;
  emxEnsureCapacity((emxArray__common *)headidx, i29, (int)sizeof(double));
  headidx->data[0] = 1.0;
  i29 = headpitches->size[0] * headpitches->size[1];
  headpitches->size[0] = 1;
  headpitches->size[1] = 1;
  emxEnsureCapacity((emxArray__common *)headpitches, i29, (int)sizeof(double));
  headpitches->data[0] = arr->data[0];
  for (i = 0; i < arr->size[1]; i++) {
    if (arr->data[i] != pivot) {
      idx = headidx->size[1];
      i29 = headidx->size[0] * headidx->size[1];
      headidx->size[1] = idx + 1;
      emxEnsureCapacity((emxArray__common *)headidx, i29, (int)sizeof(double));
      headidx->data[idx] = 1.0 + (double)i;
      idx = headpitches->size[1];
      i29 = headpitches->size[0] * headpitches->size[1];
      headpitches->size[1] = idx + 1;
      emxEnsureCapacity((emxArray__common *)headpitches, i29, (int)sizeof(double));
      headpitches->data[idx] = arr->data[i];
    }

    pivot = arr->data[i];
  }

  emxInit_real_T(&prev_headidx, 2);

  /* idx = 1:length(arr); */
  i29 = prev_headidx->size[0] * prev_headidx->size[1];
  prev_headidx->size[0] = 1;
  prev_headidx->size[1] = headidx->size[1];
  emxEnsureCapacity((emxArray__common *)prev_headidx, i29, (int)sizeof(double));
  ii = headidx->size[0] * headidx->size[1];
  for (i29 = 0; i29 < ii; i29++) {
    prev_headidx->data[i29] = headidx->data[i29];
  }

  emxInit_real_T(&b_headidx, 2);
  i29 = b_headidx->size[0] * b_headidx->size[1];
  b_headidx->size[0] = 1;
  b_headidx->size[1] = headidx->size[1] + 1;
  emxEnsureCapacity((emxArray__common *)b_headidx, i29, (int)sizeof(double));
  ii = headidx->size[1];
  for (i29 = 0; i29 < ii; i29++) {
    b_headidx->data[b_headidx->size[0] * i29] = headidx->data[headidx->size[0] *
      i29];
  }

  emxInit_real_T(&pitcheslength, 2);
  emxInit_real_T(&visited, 2);
  b_headidx->data[b_headidx->size[0] * headidx->size[1]] = arr->size[1];
  diff(b_headidx, pitcheslength);
  i29 = visited->size[0] * visited->size[1];
  visited->size[0] = 1;
  visited->size[1] = pitcheslength->size[1];
  emxEnsureCapacity((emxArray__common *)visited, i29, (int)sizeof(double));
  ii = pitcheslength->size[1];
  emxFree_real_T(&b_headidx);
  for (i29 = 0; i29 < ii; i29++) {
    visited->data[i29] = 0.0;
  }

  emxInit_real_T(&sorted_pitcheslength, 2);
  emxInit_real_T(&sorted_idx, 2);
  emxInit_int32_T(&iidx, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_boolean_T(&b_visited, 2);
  emxInit_real_T(&c_headidx, 2);
  emxInit_real_T2(&b_headpitches, 1);
  emxInit_int32_T(&b_pitcheslength, 2);
  emxInit_real_T(&d_headidx, 2);
  emxInit_int32_T(&c_pitcheslength, 2);
  emxInit_real_T(&c_headpitches, 2);
  emxInit_int32_T(&d_pitcheslength, 2);
  emxInit_real_T(&c_visited, 2);
  emxInit_int32_T(&e_pitcheslength, 2);
  emxInit_real_T(&e_headidx, 2);
  emxInit_int32_T(&f_pitcheslength, 2);
  emxInit_real_T(&d_headpitches, 2);
  emxInit_int32_T(&g_pitcheslength, 2);
  emxInit_real_T(&d_visited, 2);
  emxInit_int32_T(&h_pitcheslength, 2);
  emxInit_real_T(&f_headidx, 2);
  emxInit_int32_T(&i_pitcheslength, 2);
  emxInit_real_T(&e_headpitches, 2);
  emxInit_int32_T(&j_pitcheslength, 2);
  emxInit_real_T(&e_visited, 2);
  emxInit_int32_T(&k_pitcheslength, 2);
  emxInit_real_T(&g_headidx, 2);
  emxInit_int32_T(&l_pitcheslength, 2);
  emxInit_real_T(&f_headpitches, 2);
  emxInit_int32_T(&m_pitcheslength, 2);
  emxInit_real_T(&f_visited, 2);
  emxInit_int32_T(&n_pitcheslength, 2);
  emxInit_real_T(&h_headidx, 2);
  emxInit_int32_T(&o_pitcheslength, 2);
  emxInit_real_T(&g_headpitches, 2);
  emxInit_int32_T(&p_pitcheslength, 2);
  emxInit_real_T(&g_visited, 2);
  emxInit_int32_T(&q_pitcheslength, 2);
  emxInit_real_T(&i_headidx, 2);
  emxInit_int32_T(&r_pitcheslength, 2);
  emxInit_real_T(&h_headpitches, 2);
  emxInit_int32_T(&s_pitcheslength, 2);
  emxInit_real_T(&h_visited, 2);
  do {
    exitg1 = 0;
    i29 = c_headidx->size[0] * c_headidx->size[1];
    c_headidx->size[0] = 1;
    c_headidx->size[1] = headidx->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)c_headidx, i29, (int)sizeof(double));
    ii = headidx->size[1];
    for (i29 = 0; i29 < ii; i29++) {
      c_headidx->data[c_headidx->size[0] * i29] = headidx->data[headidx->size[0]
        * i29];
    }

    c_headidx->data[c_headidx->size[0] * headidx->size[1]] = arr->size[1];
    diff(c_headidx, pitcheslength);
    i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
    sorted_pitcheslength->size[0] = 1;
    sorted_pitcheslength->size[1] = pitcheslength->size[1];
    emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29, (int)sizeof
                      (double));
    ii = pitcheslength->size[0] * pitcheslength->size[1];
    for (i29 = 0; i29 < ii; i29++) {
      sorted_pitcheslength->data[i29] = pitcheslength->data[i29];
    }

    g_sort(sorted_pitcheslength, iidx);
    i29 = sorted_idx->size[0] * sorted_idx->size[1];
    sorted_idx->size[0] = 1;
    sorted_idx->size[1] = iidx->size[1];
    emxEnsureCapacity((emxArray__common *)sorted_idx, i29, (int)sizeof(double));
    ii = iidx->size[0] * iidx->size[1];
    for (i29 = 0; i29 < ii; i29++) {
      sorted_idx->data[i29] = iidx->data[i29];
    }

    i29 = b_visited->size[0] * b_visited->size[1];
    b_visited->size[0] = 1;
    b_visited->size[1] = visited->size[1];
    emxEnsureCapacity((emxArray__common *)b_visited, i29, (int)sizeof(boolean_T));
    ii = visited->size[0] * visited->size[1];
    for (i29 = 0; i29 < ii; i29++) {
      b_visited->data[i29] = (visited->data[i29] == 1.0);
    }

    guard1 = false;
    if (all(b_visited)) {
      /*          if(isequal(prev_headidx,headidx)&& all((diff(tmp_headidx)>min_length | headpitches==0))) */
      if (isequal(prev_headidx, headidx)) {
        exitg1 = 1;
      } else {
        i29 = visited->size[0] * visited->size[1];
        visited->size[0] = 1;
        visited->size[1] = pitcheslength->size[1];
        emxEnsureCapacity((emxArray__common *)visited, i29, (int)sizeof(double));
        ii = pitcheslength->size[1];
        for (i29 = 0; i29 < ii; i29++) {
          visited->data[i29] = 0.0;
        }

        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      i29 = prev_headidx->size[0] * prev_headidx->size[1];
      prev_headidx->size[0] = 1;
      prev_headidx->size[1] = headidx->size[1];
      emxEnsureCapacity((emxArray__common *)prev_headidx, i29, (int)sizeof
                        (double));
      ii = headidx->size[0] * headidx->size[1];
      for (i29 = 0; i29 < ii; i29++) {
        prev_headidx->data[i29] = headidx->data[i29];
      }

      i29 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = visited->size[1];
      emxEnsureCapacity((emxArray__common *)x, i29, (int)sizeof(boolean_T));
      ii = visited->size[0] * visited->size[1];
      for (i29 = 0; i29 < ii; i29++) {
        x->data[i29] = (visited->data[i29] == 0.0);
      }

      k = (1 <= x->size[1]);
      idx = 0;
      ii = 1;
      exitg2 = false;
      while ((!exitg2) && (ii <= x->size[1])) {
        if (x->data[ii - 1]) {
          idx = 1;
          ii_data[0] = ii;
          exitg2 = true;
        } else {
          ii++;
        }
      }

      if (k == 1) {
        if (idx == 0) {
          k = 0;
        }
      } else {
        k = !(1 > idx);
      }

      for (i29 = 0; i29 < k; i29++) {
        index_data[i29] = ii_data[i29];
      }

      for (i29 = 0; i29 < k; i29++) {
        ii_data[i29] = (int)index_data[i29];
      }

      for (i29 = 0; i29 < k; i29++) {
        visited->data[ii_data[i29] - 1] = 1.0;
      }

      /* sorted_headidx = headidx(sorted_idx); */
      for (i29 = 0; i29 < k; i29++) {
        check_pitchlength_data[i29] = sorted_pitcheslength->data[(int)
          index_data[i29] - 1];
      }

      for (i29 = 0; i29 < k; i29++) {
        b_check_idx_data[i29] = sorted_idx->data[(int)index_data[i29] - 1];
      }

      check_idx_size[0] = 1;
      check_idx_size[1] = k;
      for (i29 = 0; i29 < k; i29++) {
        check_idx_data[i29] = (b_check_idx_data[i29] == 1.0);
      }

      c_check_idx_data.data = (boolean_T *)&check_idx_data;
      c_check_idx_data.size = (int *)&check_idx_size;
      c_check_idx_data.allocatedSize = 1;
      c_check_idx_data.numDimensions = 2;
      c_check_idx_data.canFreeData = false;
      if (all(&c_check_idx_data)) {
        left_pitch_size[1] = 1;
        left_pitch_data[0] = 0.0;
        left_pitchlength_size[0] = 1;
        left_pitchlength_size[1] = 1;
        left_pitchlength_data[0] = 0.0;
        idx = k;
        for (i29 = 0; i29 < k; i29++) {
          right_pitch_data[i29] = headpitches->data[(int)(b_check_idx_data[i29]
            + 1.0) - 1];
        }

        right_pitchlength_size[0] = 1;
        right_pitchlength_size[1] = k;
        for (i29 = 0; i29 < k; i29++) {
          right_pitchlength_data[i29] = pitcheslength->data[(int)
            (b_check_idx_data[i29] + 1.0) - 1];
        }
      } else {
        b_check_idx_size[0] = 1;
        b_check_idx_size[1] = k;
        idx = headidx->size[1];
        for (i29 = 0; i29 < k; i29++) {
          d_check_idx_data[i29] = (b_check_idx_data[i29] == idx);
        }

        e_check_idx_data.data = (boolean_T *)&d_check_idx_data;
        e_check_idx_data.size = (int *)&b_check_idx_size;
        e_check_idx_data.allocatedSize = 1;
        e_check_idx_data.numDimensions = 2;
        e_check_idx_data.canFreeData = false;
        if (all(&e_check_idx_data)) {
          left_pitch_size[1] = k;
          for (i29 = 0; i29 < k; i29++) {
            left_pitch_data[i29] = headpitches->data[(int)(b_check_idx_data[i29]
              - 1.0) - 1];
          }

          left_pitchlength_size[0] = 1;
          left_pitchlength_size[1] = k;
          for (i29 = 0; i29 < k; i29++) {
            left_pitchlength_data[i29] = pitcheslength->data[(int)
              (b_check_idx_data[i29] - 1.0) - 1];
          }

          idx = 1;
          right_pitch_data[0] = 0.0;
          right_pitchlength_size[0] = 1;
          right_pitchlength_size[1] = 1;
          right_pitchlength_data[0] = 0.0;
        } else {
          left_pitch_size[1] = k;
          for (i29 = 0; i29 < k; i29++) {
            left_pitch_data[i29] = headpitches->data[(int)(b_check_idx_data[i29]
              - 1.0) - 1];
          }

          left_pitchlength_size[0] = 1;
          left_pitchlength_size[1] = k;
          for (i29 = 0; i29 < k; i29++) {
            left_pitchlength_data[i29] = pitcheslength->data[(int)
              (b_check_idx_data[i29] - 1.0) - 1];
          }

          idx = k;
          for (i29 = 0; i29 < k; i29++) {
            right_pitch_data[i29] = headpitches->data[(int)(b_check_idx_data[i29]
              + 1.0) - 1];
          }

          right_pitchlength_size[0] = 1;
          right_pitchlength_size[1] = k;
          for (i29 = 0; i29 < k; i29++) {
            right_pitchlength_data[i29] = pitcheslength->data[(int)
              (b_check_idx_data[i29] + 1.0) - 1];
          }
        }
      }

      /* Smooth Criteria */
      headpitches_size[0] = 1;
      headpitches_size[1] = k;
      i29 = b_headpitches->size[0];
      b_headpitches->size[0] = sorted_idx->size[1];
      emxEnsureCapacity((emxArray__common *)b_headpitches, i29, (int)sizeof
                        (double));
      ii = sorted_idx->size[1];
      for (i29 = 0; i29 < ii; i29++) {
        b_headpitches->data[i29] = headpitches->data[(int)sorted_idx->data[i29]
          - 1];
      }

      for (i29 = 0; i29 < k; i29++) {
        headpitches_data[i29] = (b_headpitches->data[(int)index_data[i29] - 1]
          != 0.0);
      }

      b_headpitches_data.data = (boolean_T *)&headpitches_data;
      b_headpitches_data.size = (int *)&headpitches_size;
      b_headpitches_data.allocatedSize = 1;
      b_headpitches_data.numDimensions = 2;
      b_headpitches_data.canFreeData = false;
      if (all(&b_headpitches_data)) {
        b_left_pitch_size[0] = 1;
        b_left_pitch_size[1] = left_pitch_size[1];
        ii = left_pitch_size[1];
        for (i29 = 0; i29 < ii; i29++) {
          b_left_pitch_data[i29] = (left_pitch_data[i29] == 0.0);
        }

        c_left_pitch_data.data = (boolean_T *)&b_left_pitch_data;
        c_left_pitch_data.size = (int *)&b_left_pitch_size;
        c_left_pitch_data.allocatedSize = 1;
        c_left_pitch_data.numDimensions = 2;
        c_left_pitch_data.canFreeData = false;
        b_guard1 = false;
        guard2 = false;
        guard3 = false;
        guard4 = false;
        guard5 = false;
        guard6 = false;
        guard7 = false;
        guard8 = false;
        if (all(&c_left_pitch_data)) {
          right_pitch_size[0] = 1;
          right_pitch_size[1] = idx;
          for (i29 = 0; i29 < idx; i29++) {
            b_right_pitch_data[i29] = (right_pitch_data[i29] == 0.0);
          }

          c_right_pitch_data.data = (boolean_T *)&b_right_pitch_data;
          c_right_pitch_data.size = (int *)&right_pitch_size;
          c_right_pitch_data.allocatedSize = 1;
          c_right_pitch_data.numDimensions = 2;
          c_right_pitch_data.canFreeData = false;
          if (all(&c_right_pitch_data)) {
            c_check_pitchlength_size[0] = 1;
            c_check_pitchlength_size[1] = k;
            for (i29 = 0; i29 < k; i29++) {
              d_check_pitchlength_data[i29] = (check_pitchlength_data[i29] <
                Prm_smooth_threshold);
            }

            i_check_pitchlength_data.data = (boolean_T *)
              &d_check_pitchlength_data;
            i_check_pitchlength_data.size = (int *)&c_check_pitchlength_size;
            i_check_pitchlength_data.allocatedSize = 1;
            i_check_pitchlength_data.numDimensions = 2;
            i_check_pitchlength_data.canFreeData = false;
            if (all(&i_check_pitchlength_data)) {
              for (i29 = 0; i29 < k; i29++) {
                left_pitch_data[i29] = b_check_idx_data[i29] - 1.0;
              }

              if ((int)left_pitch_data[0] < 1) {
                ndbl = 0;
                apnd = (int)left_pitch_data[0];
              } else {
                ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
                apnd = ndbl + 1;
                idx = (ndbl - (int)left_pitch_data[0]) + 1;
                ii = (int)left_pitch_data[0];
                if (1 >= ii) {
                  ii = 1;
                }

                if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                  ndbl++;
                  apnd = (int)left_pitch_data[0];
                } else if (idx > 0) {
                  apnd = ndbl;
                } else {
                  ndbl++;
                }

                if (ndbl >= 0) {
                } else {
                  ndbl = 0;
                }
              }

              i29 = pitcheslength->size[0] * pitcheslength->size[1];
              pitcheslength->size[0] = 1;
              pitcheslength->size[1] = ndbl;
              emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                                sizeof(double));
              if (ndbl > 0) {
                pitcheslength->data[0] = 1.0;
                if (ndbl > 1) {
                  pitcheslength->data[ndbl - 1] = apnd;
                  idx = (ndbl - 1) / 2;
                  for (ii = 1; ii < idx; ii++) {
                    pitcheslength->data[ii] = 1.0 + (double)ii;
                    pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                  }

                  if (idx << 1 == ndbl - 1) {
                    pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                  } else {
                    pitcheslength->data[idx] = 1.0 + (double)idx;
                    pitcheslength->data[idx + 1] = apnd - idx;
                  }
                }
              }

              for (i29 = 0; i29 < k; i29++) {
                left_pitch_data[i29] = b_check_idx_data[i29] + 2.0;
              }

              if ((unsigned int)headidx->size[1] < (unsigned int)
                  left_pitch_data[0]) {
                ndbl = 0;
                anew = left_pitch_data[0];
                b_apnd = headidx->size[1];
              } else {
                anew = left_pitch_data[0];
                ndbl = (int)floor(((double)headidx->size[1] - left_pitch_data[0])
                                  + 0.5);
                b_apnd = left_pitch_data[0] + (double)ndbl;
                cdiff = b_apnd - (double)headidx->size[1];
                idx = headidx->size[1];
                u0 = (unsigned int)left_pitch_data[0];
                u1 = (unsigned int)idx;
                if (u0 >= u1) {
                  u1 = u0;
                }

                if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                  ndbl++;
                  b_apnd = headidx->size[1];
                } else if (cdiff > 0.0) {
                  b_apnd = left_pitch_data[0] + ((double)ndbl - 1.0);
                } else {
                  ndbl++;
                }

                if (ndbl >= 0) {
                } else {
                  ndbl = 0;
                }
              }

              i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
              sorted_pitcheslength->size[0] = 1;
              sorted_pitcheslength->size[1] = ndbl;
              emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                                (int)sizeof(double));
              if (ndbl > 0) {
                sorted_pitcheslength->data[0] = anew;
                if (ndbl > 1) {
                  sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                  idx = (ndbl - 1) / 2;
                  for (ii = 1; ii < idx; ii++) {
                    sorted_pitcheslength->data[ii] = anew + (double)ii;
                    sorted_pitcheslength->data[(ndbl - ii) - 1] = b_apnd -
                      (double)ii;
                  }

                  if (idx << 1 == ndbl - 1) {
                    sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                  } else {
                    sorted_pitcheslength->data[idx] = anew + (double)idx;
                    sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                  }
                }
              }

              i29 = q_pitcheslength->size[0] * q_pitcheslength->size[1];
              q_pitcheslength->size[0] = 1;
              q_pitcheslength->size[1] = pitcheslength->size[1] +
                sorted_pitcheslength->size[1];
              emxEnsureCapacity((emxArray__common *)q_pitcheslength, i29, (int)
                                sizeof(int));
              ii = pitcheslength->size[1];
              for (i29 = 0; i29 < ii; i29++) {
                q_pitcheslength->data[q_pitcheslength->size[0] * i29] = (int)
                  pitcheslength->data[pitcheslength->size[0] * i29];
              }

              ii = sorted_pitcheslength->size[1];
              for (i29 = 0; i29 < ii; i29++) {
                q_pitcheslength->data[q_pitcheslength->size[0] * (i29 +
                  pitcheslength->size[1])] = (int)sorted_pitcheslength->
                  data[sorted_pitcheslength->size[0] * i29];
              }

              i29 = i_headidx->size[0] * i_headidx->size[1];
              i_headidx->size[0] = 1;
              i_headidx->size[1] = q_pitcheslength->size[1];
              emxEnsureCapacity((emxArray__common *)i_headidx, i29, (int)sizeof
                                (double));
              ii = q_pitcheslength->size[1];
              for (i29 = 0; i29 < ii; i29++) {
                i_headidx->data[i_headidx->size[0] * i29] = headidx->
                  data[q_pitcheslength->data[q_pitcheslength->size[0] * i29] - 1];
              }

              i29 = headidx->size[0] * headidx->size[1];
              headidx->size[0] = 1;
              headidx->size[1] = i_headidx->size[1];
              emxEnsureCapacity((emxArray__common *)headidx, i29, (int)sizeof
                                (double));
              ii = i_headidx->size[1];
              for (i29 = 0; i29 < ii; i29++) {
                headidx->data[headidx->size[0] * i29] = i_headidx->
                  data[i_headidx->size[0] * i29];
              }

              for (i29 = 0; i29 < k; i29++) {
                left_pitch_data[i29] = b_check_idx_data[i29] - 1.0;
              }

              if ((int)left_pitch_data[0] < 1) {
                ndbl = 0;
                apnd = (int)left_pitch_data[0];
              } else {
                ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
                apnd = ndbl + 1;
                idx = (ndbl - (int)left_pitch_data[0]) + 1;
                ii = (int)left_pitch_data[0];
                if (1 >= ii) {
                  ii = 1;
                }

                if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                  ndbl++;
                  apnd = (int)left_pitch_data[0];
                } else if (idx > 0) {
                  apnd = ndbl;
                } else {
                  ndbl++;
                }

                if (ndbl >= 0) {
                } else {
                  ndbl = 0;
                }
              }

              i29 = pitcheslength->size[0] * pitcheslength->size[1];
              pitcheslength->size[0] = 1;
              pitcheslength->size[1] = ndbl;
              emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                                sizeof(double));
              if (ndbl > 0) {
                pitcheslength->data[0] = 1.0;
                if (ndbl > 1) {
                  pitcheslength->data[ndbl - 1] = apnd;
                  idx = (ndbl - 1) / 2;
                  for (ii = 1; ii < idx; ii++) {
                    pitcheslength->data[ii] = 1.0 + (double)ii;
                    pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                  }

                  if (idx << 1 == ndbl - 1) {
                    pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                  } else {
                    pitcheslength->data[idx] = 1.0 + (double)idx;
                    pitcheslength->data[idx + 1] = apnd - idx;
                  }
                }
              }

              for (i29 = 0; i29 < k; i29++) {
                b_check_idx_data[i29] += 2.0;
              }

              if ((unsigned int)headpitches->size[1] < (unsigned int)
                  b_check_idx_data[0]) {
                ndbl = 0;
                anew = b_check_idx_data[0];
                b_apnd = headpitches->size[1];
              } else {
                anew = b_check_idx_data[0];
                ndbl = (int)floor(((double)headpitches->size[1] -
                                   b_check_idx_data[0]) + 0.5);
                b_apnd = b_check_idx_data[0] + (double)ndbl;
                cdiff = b_apnd - (double)headpitches->size[1];
                idx = headpitches->size[1];
                u0 = (unsigned int)b_check_idx_data[0];
                u1 = (unsigned int)idx;
                if (u0 >= u1) {
                  u1 = u0;
                }

                if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                  ndbl++;
                  b_apnd = headpitches->size[1];
                } else if (cdiff > 0.0) {
                  b_apnd = b_check_idx_data[0] + ((double)ndbl - 1.0);
                } else {
                  ndbl++;
                }

                if (ndbl >= 0) {
                } else {
                  ndbl = 0;
                }
              }

              i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
              sorted_pitcheslength->size[0] = 1;
              sorted_pitcheslength->size[1] = ndbl;
              emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                                (int)sizeof(double));
              if (ndbl > 0) {
                sorted_pitcheslength->data[0] = anew;
                if (ndbl > 1) {
                  sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                  idx = (ndbl - 1) / 2;
                  for (ii = 1; ii < idx; ii++) {
                    sorted_pitcheslength->data[ii] = anew + (double)ii;
                    sorted_pitcheslength->data[(ndbl - ii) - 1] = b_apnd -
                      (double)ii;
                  }

                  if (idx << 1 == ndbl - 1) {
                    sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                  } else {
                    sorted_pitcheslength->data[idx] = anew + (double)idx;
                    sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                  }
                }
              }

              i29 = r_pitcheslength->size[0] * r_pitcheslength->size[1];
              r_pitcheslength->size[0] = 1;
              r_pitcheslength->size[1] = pitcheslength->size[1] +
                sorted_pitcheslength->size[1];
              emxEnsureCapacity((emxArray__common *)r_pitcheslength, i29, (int)
                                sizeof(int));
              ii = pitcheslength->size[1];
              for (i29 = 0; i29 < ii; i29++) {
                r_pitcheslength->data[r_pitcheslength->size[0] * i29] = (int)
                  pitcheslength->data[pitcheslength->size[0] * i29];
              }

              ii = sorted_pitcheslength->size[1];
              for (i29 = 0; i29 < ii; i29++) {
                r_pitcheslength->data[r_pitcheslength->size[0] * (i29 +
                  pitcheslength->size[1])] = (int)sorted_pitcheslength->
                  data[sorted_pitcheslength->size[0] * i29];
              }

              i29 = h_headpitches->size[0] * h_headpitches->size[1];
              h_headpitches->size[0] = 1;
              h_headpitches->size[1] = r_pitcheslength->size[1];
              emxEnsureCapacity((emxArray__common *)h_headpitches, i29, (int)
                                sizeof(double));
              ii = r_pitcheslength->size[1];
              for (i29 = 0; i29 < ii; i29++) {
                h_headpitches->data[h_headpitches->size[0] * i29] =
                  headpitches->data[r_pitcheslength->data[r_pitcheslength->size
                  [0] * i29] - 1];
              }

              i29 = headpitches->size[0] * headpitches->size[1];
              headpitches->size[0] = 1;
              headpitches->size[1] = h_headpitches->size[1];
              emxEnsureCapacity((emxArray__common *)headpitches, i29, (int)
                                sizeof(double));
              ii = h_headpitches->size[1];
              for (i29 = 0; i29 < ii; i29++) {
                headpitches->data[headpitches->size[0] * i29] =
                  h_headpitches->data[h_headpitches->size[0] * i29];
              }

              for (i29 = 0; i29 < k; i29++) {
                left_pitch_data[i29] = index_data[i29] - 1.0;
              }

              if ((int)left_pitch_data[0] < 1) {
                ndbl = 0;
                apnd = (int)left_pitch_data[0];
              } else {
                ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
                apnd = ndbl + 1;
                idx = (ndbl - (int)left_pitch_data[0]) + 1;
                ii = (int)left_pitch_data[0];
                if (1 >= ii) {
                  ii = 1;
                }

                if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                  ndbl++;
                  apnd = (int)left_pitch_data[0];
                } else if (idx > 0) {
                  apnd = ndbl;
                } else {
                  ndbl++;
                }

                if (ndbl >= 0) {
                } else {
                  ndbl = 0;
                }
              }

              i29 = pitcheslength->size[0] * pitcheslength->size[1];
              pitcheslength->size[0] = 1;
              pitcheslength->size[1] = ndbl;
              emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                                sizeof(double));
              if (ndbl > 0) {
                pitcheslength->data[0] = 1.0;
                if (ndbl > 1) {
                  pitcheslength->data[ndbl - 1] = apnd;
                  idx = (ndbl - 1) / 2;
                  for (ii = 1; ii < idx; ii++) {
                    pitcheslength->data[ii] = 1.0 + (double)ii;
                    pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                  }

                  if (idx << 1 == ndbl - 1) {
                    pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                  } else {
                    pitcheslength->data[idx] = 1.0 + (double)idx;
                    pitcheslength->data[idx + 1] = apnd - idx;
                  }
                }
              }

              for (i29 = 0; i29 < k; i29++) {
                index_data[i29] += 2.0;
              }

              if ((unsigned int)visited->size[1] < (unsigned int)index_data[0])
              {
                ndbl = 0;
                anew = index_data[0];
                b_apnd = visited->size[1];
              } else {
                anew = index_data[0];
                ndbl = (int)floor(((double)visited->size[1] - index_data[0]) +
                                  0.5);
                b_apnd = index_data[0] + (double)ndbl;
                cdiff = b_apnd - (double)visited->size[1];
                idx = visited->size[1];
                u0 = (unsigned int)index_data[0];
                u1 = (unsigned int)idx;
                if (u0 >= u1) {
                  u1 = u0;
                }

                if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                  ndbl++;
                  b_apnd = visited->size[1];
                } else if (cdiff > 0.0) {
                  b_apnd = index_data[0] + ((double)ndbl - 1.0);
                } else {
                  ndbl++;
                }

                if (ndbl >= 0) {
                } else {
                  ndbl = 0;
                }
              }

              i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
              sorted_pitcheslength->size[0] = 1;
              sorted_pitcheslength->size[1] = ndbl;
              emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                                (int)sizeof(double));
              if (ndbl > 0) {
                sorted_pitcheslength->data[0] = anew;
                if (ndbl > 1) {
                  sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                  idx = (ndbl - 1) / 2;
                  for (k = 1; k < idx; k++) {
                    sorted_pitcheslength->data[k] = anew + (double)k;
                    sorted_pitcheslength->data[(ndbl - k) - 1] = b_apnd -
                      (double)k;
                  }

                  if (idx << 1 == ndbl - 1) {
                    sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                  } else {
                    sorted_pitcheslength->data[idx] = anew + (double)idx;
                    sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                  }
                }
              }

              i29 = s_pitcheslength->size[0] * s_pitcheslength->size[1];
              s_pitcheslength->size[0] = 1;
              s_pitcheslength->size[1] = pitcheslength->size[1] +
                sorted_pitcheslength->size[1];
              emxEnsureCapacity((emxArray__common *)s_pitcheslength, i29, (int)
                                sizeof(int));
              ii = pitcheslength->size[1];
              for (i29 = 0; i29 < ii; i29++) {
                s_pitcheslength->data[s_pitcheslength->size[0] * i29] = (int)
                  pitcheslength->data[pitcheslength->size[0] * i29];
              }

              ii = sorted_pitcheslength->size[1];
              for (i29 = 0; i29 < ii; i29++) {
                s_pitcheslength->data[s_pitcheslength->size[0] * (i29 +
                  pitcheslength->size[1])] = (int)sorted_pitcheslength->
                  data[sorted_pitcheslength->size[0] * i29];
              }

              i29 = h_visited->size[0] * h_visited->size[1];
              h_visited->size[0] = 1;
              h_visited->size[1] = s_pitcheslength->size[1];
              emxEnsureCapacity((emxArray__common *)h_visited, i29, (int)sizeof
                                (double));
              ii = s_pitcheslength->size[1];
              for (i29 = 0; i29 < ii; i29++) {
                h_visited->data[h_visited->size[0] * i29] = visited->
                  data[s_pitcheslength->data[s_pitcheslength->size[0] * i29] - 1];
              }

              i29 = visited->size[0] * visited->size[1];
              visited->size[0] = 1;
              visited->size[1] = h_visited->size[1];
              emxEnsureCapacity((emxArray__common *)visited, i29, (int)sizeof
                                (double));
              ii = h_visited->size[1];
              for (i29 = 0; i29 < ii; i29++) {
                visited->data[visited->size[0] * i29] = h_visited->
                  data[h_visited->size[0] * i29];
              }
            }
          } else {
            guard8 = true;
          }
        } else {
          guard8 = true;
        }

        if (guard8) {
          c_left_pitch_size[0] = 1;
          c_left_pitch_size[1] = left_pitch_size[1];
          ii = left_pitch_size[1];
          for (i29 = 0; i29 < ii; i29++) {
            d_left_pitch_data[i29] = (left_pitch_data[i29] != 0.0);
          }

          f_left_pitch_data.data = (boolean_T *)&d_left_pitch_data;
          f_left_pitch_data.size = (int *)&c_left_pitch_size;
          f_left_pitch_data.allocatedSize = 1;
          f_left_pitch_data.numDimensions = 2;
          f_left_pitch_data.canFreeData = false;
          if (all(&f_left_pitch_data)) {
            b_right_pitch_size[0] = 1;
            b_right_pitch_size[1] = idx;
            for (i29 = 0; i29 < idx; i29++) {
              d_right_pitch_data[i29] = (right_pitch_data[i29] == 0.0);
            }

            f_right_pitch_data.data = (boolean_T *)&d_right_pitch_data;
            f_right_pitch_data.size = (int *)&b_right_pitch_size;
            f_right_pitch_data.allocatedSize = 1;
            f_right_pitch_data.numDimensions = 2;
            f_right_pitch_data.canFreeData = false;
            if (all(&f_right_pitch_data)) {
              left_pitch_size[0] = 1;
              left_pitch_size[1] = k;
              for (i29 = 0; i29 < k; i29++) {
                left_pitch_data[i29] = check_pitchlength_data[i29];
              }

              mrdivide(left_pitch_data, left_pitch_size, left_pitchlength_data,
                       left_pitchlength_size);
              f_left_pitch_size[0] = 1;
              f_left_pitch_size[1] = left_pitch_size[1];
              ii = left_pitch_size[0] * left_pitch_size[1];
              for (i29 = 0; i29 < ii; i29++) {
                j_left_pitch_data[i29] = (left_pitch_data[i29] < 0.5);
              }

              m_left_pitch_data.data = (boolean_T *)&j_left_pitch_data;
              m_left_pitch_data.size = (int *)&f_left_pitch_size;
              m_left_pitch_data.allocatedSize = 1;
              m_left_pitch_data.numDimensions = 2;
              m_left_pitch_data.canFreeData = false;
              if (all(&m_left_pitch_data)) {
                guard5 = true;
              } else {
                h_check_pitchlength_size[0] = 1;
                h_check_pitchlength_size[1] = k;
                for (i29 = 0; i29 < k; i29++) {
                  p_check_pitchlength_data[i29] = (check_pitchlength_data[i29] <
                    Prm_smooth_threshold);
                }

                s_check_pitchlength_data.data = (boolean_T *)
                  &p_check_pitchlength_data;
                s_check_pitchlength_data.size = (int *)&h_check_pitchlength_size;
                s_check_pitchlength_data.allocatedSize = 1;
                s_check_pitchlength_data.numDimensions = 2;
                s_check_pitchlength_data.canFreeData = false;
                if (all(&s_check_pitchlength_data)) {
                  guard5 = true;
                }
              }
            } else {
              guard7 = true;
            }
          } else {
            guard7 = true;
          }
        }

        if (guard7) {
          d_left_pitch_size[0] = 1;
          d_left_pitch_size[1] = left_pitch_size[1];
          ii = left_pitch_size[1];
          for (i29 = 0; i29 < ii; i29++) {
            e_left_pitch_data[i29] = (left_pitch_data[i29] == 0.0);
          }

          g_left_pitch_data.data = (boolean_T *)&e_left_pitch_data;
          g_left_pitch_data.size = (int *)&d_left_pitch_size;
          g_left_pitch_data.allocatedSize = 1;
          g_left_pitch_data.numDimensions = 2;
          g_left_pitch_data.canFreeData = false;
          if (all(&g_left_pitch_data)) {
            c_right_pitch_size[0] = 1;
            c_right_pitch_size[1] = idx;
            for (i29 = 0; i29 < idx; i29++) {
              e_right_pitch_data[i29] = (right_pitch_data[i29] != 0.0);
            }

            g_right_pitch_data.data = (boolean_T *)&e_right_pitch_data;
            g_right_pitch_data.size = (int *)&c_right_pitch_size;
            g_right_pitch_data.allocatedSize = 1;
            g_right_pitch_data.numDimensions = 2;
            g_right_pitch_data.canFreeData = false;
            if (all(&g_right_pitch_data)) {
              left_pitch_size[0] = 1;
              left_pitch_size[1] = k;
              for (i29 = 0; i29 < k; i29++) {
                left_pitch_data[i29] = check_pitchlength_data[i29];
              }

              mrdivide(left_pitch_data, left_pitch_size, right_pitchlength_data,
                       right_pitchlength_size);
              g_left_pitch_size[0] = 1;
              g_left_pitch_size[1] = left_pitch_size[1];
              ii = left_pitch_size[0] * left_pitch_size[1];
              for (i29 = 0; i29 < ii; i29++) {
                k_left_pitch_data[i29] = (left_pitch_data[i29] < 0.5);
              }

              n_left_pitch_data.data = (boolean_T *)&k_left_pitch_data;
              n_left_pitch_data.size = (int *)&g_left_pitch_size;
              n_left_pitch_data.allocatedSize = 1;
              n_left_pitch_data.numDimensions = 2;
              n_left_pitch_data.canFreeData = false;
              if (all(&n_left_pitch_data)) {
                guard4 = true;
              } else {
                i_check_pitchlength_size[0] = 1;
                i_check_pitchlength_size[1] = k;
                for (i29 = 0; i29 < k; i29++) {
                  q_check_pitchlength_data[i29] = (check_pitchlength_data[i29] <
                    Prm_smooth_threshold);
                }

                t_check_pitchlength_data.data = (boolean_T *)
                  &q_check_pitchlength_data;
                t_check_pitchlength_data.size = (int *)&i_check_pitchlength_size;
                t_check_pitchlength_data.allocatedSize = 1;
                t_check_pitchlength_data.numDimensions = 2;
                t_check_pitchlength_data.canFreeData = false;
                if (all(&t_check_pitchlength_data)) {
                  guard4 = true;
                }
              }
            } else {
              guard6 = true;
            }
          } else {
            guard6 = true;
          }
        }

        if (guard6) {
          b_left_pitchlength_size[0] = 1;
          b_left_pitchlength_size[1] = left_pitchlength_size[1];
          ii = left_pitchlength_size[1];
          for (i29 = 0; i29 < ii; i29++) {
            b_left_pitchlength_data[i29] = (left_pitchlength_data[i29] >
              right_pitchlength_data[i29]);
          }

          c_left_pitchlength_data.data = (boolean_T *)&b_left_pitchlength_data;
          c_left_pitchlength_data.size = (int *)&b_left_pitchlength_size;
          c_left_pitchlength_data.allocatedSize = 1;
          c_left_pitchlength_data.numDimensions = 2;
          c_left_pitchlength_data.canFreeData = false;
          if (all(&c_left_pitchlength_data)) {
            left_pitch_size[0] = 1;
            left_pitch_size[1] = k;
            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = check_pitchlength_data[i29];
            }

            mrdivide(left_pitch_data, left_pitch_size, left_pitchlength_data,
                     left_pitchlength_size);
            e_left_pitch_size[0] = 1;
            e_left_pitch_size[1] = left_pitch_size[1];
            ii = left_pitch_size[0] * left_pitch_size[1];
            for (i29 = 0; i29 < ii; i29++) {
              h_left_pitch_data[i29] = (left_pitch_data[i29] < 0.5);
            }

            i_left_pitch_data.data = (boolean_T *)&h_left_pitch_data;
            i_left_pitch_data.size = (int *)&e_left_pitch_size;
            i_left_pitch_data.allocatedSize = 1;
            i_left_pitch_data.numDimensions = 2;
            i_left_pitch_data.canFreeData = false;
            if (all(&i_left_pitch_data)) {
              guard3 = true;
            } else {
              g_check_pitchlength_size[0] = 1;
              g_check_pitchlength_size[1] = k;
              for (i29 = 0; i29 < k; i29++) {
                n_check_pitchlength_data[i29] = (check_pitchlength_data[i29] <
                  Prm_smooth_threshold);
              }

              o_check_pitchlength_data.data = (boolean_T *)
                &n_check_pitchlength_data;
              o_check_pitchlength_data.size = (int *)&g_check_pitchlength_size;
              o_check_pitchlength_data.allocatedSize = 1;
              o_check_pitchlength_data.numDimensions = 2;
              o_check_pitchlength_data.canFreeData = false;
              if (all(&o_check_pitchlength_data)) {
                guard3 = true;
              }
            }
          } else {
            c_left_pitchlength_size[0] = 1;
            c_left_pitchlength_size[1] = left_pitchlength_size[1];
            ii = left_pitchlength_size[1];
            for (i29 = 0; i29 < ii; i29++) {
              d_left_pitchlength_data[i29] = (left_pitchlength_data[i29] <
                right_pitchlength_data[i29]);
            }

            e_left_pitchlength_data.data = (boolean_T *)&d_left_pitchlength_data;
            e_left_pitchlength_data.size = (int *)&c_left_pitchlength_size;
            e_left_pitchlength_data.allocatedSize = 1;
            e_left_pitchlength_data.numDimensions = 2;
            e_left_pitchlength_data.canFreeData = false;
            if (all(&e_left_pitchlength_data)) {
              left_pitch_size[0] = 1;
              left_pitch_size[1] = k;
              for (i29 = 0; i29 < k; i29++) {
                left_pitch_data[i29] = check_pitchlength_data[i29];
              }

              mrdivide(left_pitch_data, left_pitch_size, left_pitchlength_data,
                       left_pitchlength_size);
              h_left_pitch_size[0] = 1;
              h_left_pitch_size[1] = left_pitch_size[1];
              ii = left_pitch_size[0] * left_pitch_size[1];
              for (i29 = 0; i29 < ii; i29++) {
                l_left_pitch_data[i29] = (left_pitch_data[i29] < 0.5);
              }

              p_left_pitch_data.data = (boolean_T *)&l_left_pitch_data;
              p_left_pitch_data.size = (int *)&h_left_pitch_size;
              p_left_pitch_data.allocatedSize = 1;
              p_left_pitch_data.numDimensions = 2;
              p_left_pitch_data.canFreeData = false;
              if (all(&p_left_pitch_data)) {
                guard2 = true;
              } else {
                j_check_pitchlength_size[0] = 1;
                j_check_pitchlength_size[1] = k;
                for (i29 = 0; i29 < k; i29++) {
                  r_check_pitchlength_data[i29] = (check_pitchlength_data[i29] <
                    Prm_smooth_threshold);
                }

                u_check_pitchlength_data.data = (boolean_T *)
                  &r_check_pitchlength_data;
                u_check_pitchlength_data.size = (int *)&j_check_pitchlength_size;
                u_check_pitchlength_data.allocatedSize = 1;
                u_check_pitchlength_data.numDimensions = 2;
                u_check_pitchlength_data.canFreeData = false;
                if (all(&u_check_pitchlength_data)) {
                  guard2 = true;
                }
              }
            } else {
              left_pitch_size[0] = 1;
              left_pitch_size[1] = k;
              for (i29 = 0; i29 < k; i29++) {
                left_pitch_data[i29] = check_pitchlength_data[i29];
              }

              d_left_pitchlength_size[0] = 1;
              d_left_pitchlength_size[1] = left_pitchlength_size[1];
              ii = left_pitchlength_size[1];
              for (i29 = 0; i29 < ii; i29++) {
                f_left_pitchlength_data[i29] = left_pitchlength_data[i29] +
                  right_pitchlength_data[i29];
              }

              mrdivide(left_pitch_data, left_pitch_size, f_left_pitchlength_data,
                       d_left_pitchlength_size);
              i_left_pitch_size[0] = 1;
              i_left_pitch_size[1] = left_pitch_size[1];
              ii = left_pitch_size[0] * left_pitch_size[1];
              for (i29 = 0; i29 < ii; i29++) {
                o_left_pitch_data[i29] = (left_pitch_data[i29] < 0.5);
              }

              q_left_pitch_data.data = (boolean_T *)&o_left_pitch_data;
              q_left_pitch_data.size = (int *)&i_left_pitch_size;
              q_left_pitch_data.allocatedSize = 1;
              q_left_pitch_data.numDimensions = 2;
              q_left_pitch_data.canFreeData = false;
              if (all(&q_left_pitch_data)) {
                b_guard1 = true;
              } else {
                k_check_pitchlength_size[0] = 1;
                k_check_pitchlength_size[1] = k;
                for (i29 = 0; i29 < k; i29++) {
                  v_check_pitchlength_data[i29] = (check_pitchlength_data[i29] <
                    Prm_smooth_threshold);
                }

                w_check_pitchlength_data.data = (boolean_T *)
                  &v_check_pitchlength_data;
                w_check_pitchlength_data.size = (int *)&k_check_pitchlength_size;
                w_check_pitchlength_data.allocatedSize = 1;
                w_check_pitchlength_data.numDimensions = 2;
                w_check_pitchlength_data.canFreeData = false;
                if (all(&w_check_pitchlength_data)) {
                  b_guard1 = true;
                }
              }
            }
          }
        }

        if (guard5) {
          check_pitchlength_size[0] = 1;
          check_pitchlength_size[1] = k;
          for (i29 = 0; i29 < k; i29++) {
            b_check_pitchlength_data[i29] = (check_pitchlength_data[i29] < 50.0);
          }

          f_check_pitchlength_data.data = (boolean_T *)&b_check_pitchlength_data;
          f_check_pitchlength_data.size = (int *)&check_pitchlength_size;
          f_check_pitchlength_data.allocatedSize = 1;
          f_check_pitchlength_data.numDimensions = 2;
          f_check_pitchlength_data.canFreeData = false;
          if (all(&f_check_pitchlength_data)) {
            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] + 1.0;
            }

            if ((unsigned int)headidx->size[1] < (unsigned int)left_pitch_data[0])
            {
              ndbl = 0;
              anew = left_pitch_data[0];
              b_apnd = headidx->size[1];
            } else {
              anew = left_pitch_data[0];
              ndbl = (int)floor(((double)headidx->size[1] - left_pitch_data[0])
                                + 0.5);
              b_apnd = left_pitch_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)headidx->size[1];
              idx = headidx->size[1];
              u0 = (unsigned int)left_pitch_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = headidx->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = left_pitch_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  sorted_pitcheslength->data[ii] = anew + (double)ii;
                  sorted_pitcheslength->data[(ndbl - ii) - 1] = b_apnd - (double)
                    ii;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = n_pitcheslength->size[0] * n_pitcheslength->size[1];
            n_pitcheslength->size[0] = 1;
            n_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)n_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              n_pitcheslength->data[n_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              n_pitcheslength->data[n_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = h_headidx->size[0] * h_headidx->size[1];
            h_headidx->size[0] = 1;
            h_headidx->size[1] = n_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)h_headidx, i29, (int)sizeof
                              (double));
            ii = n_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              h_headidx->data[h_headidx->size[0] * i29] = headidx->
                data[n_pitcheslength->data[n_pitcheslength->size[0] * i29] - 1];
            }

            i29 = headidx->size[0] * headidx->size[1];
            headidx->size[0] = 1;
            headidx->size[1] = h_headidx->size[1];
            emxEnsureCapacity((emxArray__common *)headidx, i29, (int)sizeof
                              (double));
            ii = h_headidx->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              headidx->data[headidx->size[0] * i29] = h_headidx->data
                [h_headidx->size[0] * i29];
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              b_check_idx_data[i29]++;
            }

            if ((unsigned int)headpitches->size[1] < (unsigned int)
                b_check_idx_data[0]) {
              ndbl = 0;
              anew = b_check_idx_data[0];
              b_apnd = headpitches->size[1];
            } else {
              anew = b_check_idx_data[0];
              ndbl = (int)floor(((double)headpitches->size[1] -
                                 b_check_idx_data[0]) + 0.5);
              b_apnd = b_check_idx_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)headpitches->size[1];
              idx = headpitches->size[1];
              u0 = (unsigned int)b_check_idx_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = headpitches->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = b_check_idx_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  sorted_pitcheslength->data[ii] = anew + (double)ii;
                  sorted_pitcheslength->data[(ndbl - ii) - 1] = b_apnd - (double)
                    ii;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = o_pitcheslength->size[0] * o_pitcheslength->size[1];
            o_pitcheslength->size[0] = 1;
            o_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)o_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              o_pitcheslength->data[o_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              o_pitcheslength->data[o_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = g_headpitches->size[0] * g_headpitches->size[1];
            g_headpitches->size[0] = 1;
            g_headpitches->size[1] = o_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)g_headpitches, i29, (int)
                              sizeof(double));
            ii = o_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              g_headpitches->data[g_headpitches->size[0] * i29] =
                headpitches->data[o_pitcheslength->data[o_pitcheslength->size[0]
                * i29] - 1];
            }

            i29 = headpitches->size[0] * headpitches->size[1];
            headpitches->size[0] = 1;
            headpitches->size[1] = g_headpitches->size[1];
            emxEnsureCapacity((emxArray__common *)headpitches, i29, (int)sizeof
                              (double));
            ii = g_headpitches->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              headpitches->data[headpitches->size[0] * i29] =
                g_headpitches->data[g_headpitches->size[0] * i29];
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = index_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              index_data[i29]++;
            }

            if ((unsigned int)visited->size[1] < (unsigned int)index_data[0]) {
              ndbl = 0;
              anew = index_data[0];
              b_apnd = visited->size[1];
            } else {
              anew = index_data[0];
              ndbl = (int)floor(((double)visited->size[1] - index_data[0]) + 0.5);
              b_apnd = index_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)visited->size[1];
              idx = visited->size[1];
              u0 = (unsigned int)index_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = visited->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = index_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (k = 1; k < idx; k++) {
                  sorted_pitcheslength->data[k] = anew + (double)k;
                  sorted_pitcheslength->data[(ndbl - k) - 1] = b_apnd - (double)
                    k;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = p_pitcheslength->size[0] * p_pitcheslength->size[1];
            p_pitcheslength->size[0] = 1;
            p_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)p_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              p_pitcheslength->data[p_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              p_pitcheslength->data[p_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = g_visited->size[0] * g_visited->size[1];
            g_visited->size[0] = 1;
            g_visited->size[1] = p_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)g_visited, i29, (int)sizeof
                              (double));
            ii = p_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              g_visited->data[g_visited->size[0] * i29] = visited->
                data[p_pitcheslength->data[p_pitcheslength->size[0] * i29] - 1];
            }

            i29 = visited->size[0] * visited->size[1];
            visited->size[0] = 1;
            visited->size[1] = g_visited->size[1];
            emxEnsureCapacity((emxArray__common *)visited, i29, (int)sizeof
                              (double));
            ii = g_visited->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              visited->data[visited->size[0] * i29] = g_visited->data
                [g_visited->size[0] * i29];
            }
          }
        }

        if (guard4) {
          b_check_pitchlength_size[0] = 1;
          b_check_pitchlength_size[1] = k;
          for (i29 = 0; i29 < k; i29++) {
            c_check_pitchlength_data[i29] = (check_pitchlength_data[i29] < 50.0);
          }

          h_check_pitchlength_data.data = (boolean_T *)&c_check_pitchlength_data;
          h_check_pitchlength_data.size = (int *)&b_check_pitchlength_size;
          h_check_pitchlength_data.allocatedSize = 1;
          h_check_pitchlength_data.numDimensions = 2;
          h_check_pitchlength_data.canFreeData = false;
          if (all(&h_check_pitchlength_data)) {
            for (i29 = 0; i29 < k; i29++) {
              right_pitch_data[i29] = headidx->data[(int)b_check_idx_data[i29] -
                1];
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] + 1.0;
            }

            if ((unsigned int)headidx->size[1] < (unsigned int)left_pitch_data[0])
            {
              ndbl = 0;
              anew = left_pitch_data[0];
              b_apnd = headidx->size[1];
            } else {
              anew = left_pitch_data[0];
              ndbl = (int)floor(((double)headidx->size[1] - left_pitch_data[0])
                                + 0.5);
              b_apnd = left_pitch_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)headidx->size[1];
              idx = headidx->size[1];
              u0 = (unsigned int)left_pitch_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = headidx->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = left_pitch_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  sorted_pitcheslength->data[ii] = anew + (double)ii;
                  sorted_pitcheslength->data[(ndbl - ii) - 1] = b_apnd - (double)
                    ii;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = k_pitcheslength->size[0] * k_pitcheslength->size[1];
            k_pitcheslength->size[0] = 1;
            k_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)k_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              k_pitcheslength->data[k_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              k_pitcheslength->data[k_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = g_headidx->size[0] * g_headidx->size[1];
            g_headidx->size[0] = 1;
            g_headidx->size[1] = k_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)g_headidx, i29, (int)sizeof
                              (double));
            ii = k_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              g_headidx->data[g_headidx->size[0] * i29] = headidx->
                data[k_pitcheslength->data[k_pitcheslength->size[0] * i29] - 1];
            }

            i29 = headidx->size[0] * headidx->size[1];
            headidx->size[0] = 1;
            headidx->size[1] = g_headidx->size[1];
            emxEnsureCapacity((emxArray__common *)headidx, i29, (int)sizeof
                              (double));
            ii = g_headidx->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              headidx->data[headidx->size[0] * i29] = g_headidx->data
                [g_headidx->size[0] * i29];
            }

            for (i29 = 0; i29 < k; i29++) {
              headidx->data[(int)b_check_idx_data[i29] - 1] =
                right_pitch_data[i29];
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              b_check_idx_data[i29]++;
            }

            if ((unsigned int)headpitches->size[1] < (unsigned int)
                b_check_idx_data[0]) {
              ndbl = 0;
              anew = b_check_idx_data[0];
              b_apnd = headpitches->size[1];
            } else {
              anew = b_check_idx_data[0];
              ndbl = (int)floor(((double)headpitches->size[1] -
                                 b_check_idx_data[0]) + 0.5);
              b_apnd = b_check_idx_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)headpitches->size[1];
              idx = headpitches->size[1];
              u0 = (unsigned int)b_check_idx_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = headpitches->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = b_check_idx_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  sorted_pitcheslength->data[ii] = anew + (double)ii;
                  sorted_pitcheslength->data[(ndbl - ii) - 1] = b_apnd - (double)
                    ii;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = l_pitcheslength->size[0] * l_pitcheslength->size[1];
            l_pitcheslength->size[0] = 1;
            l_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)l_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              l_pitcheslength->data[l_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              l_pitcheslength->data[l_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = f_headpitches->size[0] * f_headpitches->size[1];
            f_headpitches->size[0] = 1;
            f_headpitches->size[1] = l_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)f_headpitches, i29, (int)
                              sizeof(double));
            ii = l_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              f_headpitches->data[f_headpitches->size[0] * i29] =
                headpitches->data[l_pitcheslength->data[l_pitcheslength->size[0]
                * i29] - 1];
            }

            i29 = headpitches->size[0] * headpitches->size[1];
            headpitches->size[0] = 1;
            headpitches->size[1] = f_headpitches->size[1];
            emxEnsureCapacity((emxArray__common *)headpitches, i29, (int)sizeof
                              (double));
            ii = f_headpitches->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              headpitches->data[headpitches->size[0] * i29] =
                f_headpitches->data[f_headpitches->size[0] * i29];
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = index_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              index_data[i29]++;
            }

            if ((unsigned int)visited->size[1] < (unsigned int)index_data[0]) {
              ndbl = 0;
              anew = index_data[0];
              b_apnd = visited->size[1];
            } else {
              anew = index_data[0];
              ndbl = (int)floor(((double)visited->size[1] - index_data[0]) + 0.5);
              b_apnd = index_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)visited->size[1];
              idx = visited->size[1];
              u0 = (unsigned int)index_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = visited->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = index_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (k = 1; k < idx; k++) {
                  sorted_pitcheslength->data[k] = anew + (double)k;
                  sorted_pitcheslength->data[(ndbl - k) - 1] = b_apnd - (double)
                    k;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = m_pitcheslength->size[0] * m_pitcheslength->size[1];
            m_pitcheslength->size[0] = 1;
            m_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)m_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              m_pitcheslength->data[m_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              m_pitcheslength->data[m_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = f_visited->size[0] * f_visited->size[1];
            f_visited->size[0] = 1;
            f_visited->size[1] = m_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)f_visited, i29, (int)sizeof
                              (double));
            ii = m_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              f_visited->data[f_visited->size[0] * i29] = visited->
                data[m_pitcheslength->data[m_pitcheslength->size[0] * i29] - 1];
            }

            i29 = visited->size[0] * visited->size[1];
            visited->size[0] = 1;
            visited->size[1] = f_visited->size[1];
            emxEnsureCapacity((emxArray__common *)visited, i29, (int)sizeof
                              (double));
            ii = f_visited->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              visited->data[visited->size[0] * i29] = f_visited->data
                [f_visited->size[0] * i29];
            }
          }
        }

        if (guard3) {
          d_check_pitchlength_size[0] = 1;
          d_check_pitchlength_size[1] = k;
          for (i29 = 0; i29 < k; i29++) {
            e_check_pitchlength_data[i29] = (check_pitchlength_data[i29] < 50.0);
          }

          k_check_pitchlength_data.data = (boolean_T *)&e_check_pitchlength_data;
          k_check_pitchlength_data.size = (int *)&d_check_pitchlength_size;
          k_check_pitchlength_data.allocatedSize = 1;
          k_check_pitchlength_data.numDimensions = 2;
          k_check_pitchlength_data.canFreeData = false;
          if (all(&k_check_pitchlength_data)) {
            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] + 1.0;
            }

            if ((unsigned int)headidx->size[1] < (unsigned int)left_pitch_data[0])
            {
              ndbl = 0;
              anew = left_pitch_data[0];
              b_apnd = headidx->size[1];
            } else {
              anew = left_pitch_data[0];
              ndbl = (int)floor(((double)headidx->size[1] - left_pitch_data[0])
                                + 0.5);
              b_apnd = left_pitch_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)headidx->size[1];
              idx = headidx->size[1];
              u0 = (unsigned int)left_pitch_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = headidx->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = left_pitch_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  sorted_pitcheslength->data[ii] = anew + (double)ii;
                  sorted_pitcheslength->data[(ndbl - ii) - 1] = b_apnd - (double)
                    ii;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = h_pitcheslength->size[0] * h_pitcheslength->size[1];
            h_pitcheslength->size[0] = 1;
            h_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)h_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              h_pitcheslength->data[h_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              h_pitcheslength->data[h_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = f_headidx->size[0] * f_headidx->size[1];
            f_headidx->size[0] = 1;
            f_headidx->size[1] = h_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)f_headidx, i29, (int)sizeof
                              (double));
            ii = h_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              f_headidx->data[f_headidx->size[0] * i29] = headidx->
                data[h_pitcheslength->data[h_pitcheslength->size[0] * i29] - 1];
            }

            i29 = headidx->size[0] * headidx->size[1];
            headidx->size[0] = 1;
            headidx->size[1] = f_headidx->size[1];
            emxEnsureCapacity((emxArray__common *)headidx, i29, (int)sizeof
                              (double));
            ii = f_headidx->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              headidx->data[headidx->size[0] * i29] = f_headidx->data
                [f_headidx->size[0] * i29];
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              b_check_idx_data[i29]++;
            }

            if ((unsigned int)headpitches->size[1] < (unsigned int)
                b_check_idx_data[0]) {
              ndbl = 0;
              anew = b_check_idx_data[0];
              b_apnd = headpitches->size[1];
            } else {
              anew = b_check_idx_data[0];
              ndbl = (int)floor(((double)headpitches->size[1] -
                                 b_check_idx_data[0]) + 0.5);
              b_apnd = b_check_idx_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)headpitches->size[1];
              idx = headpitches->size[1];
              u0 = (unsigned int)b_check_idx_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = headpitches->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = b_check_idx_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  sorted_pitcheslength->data[ii] = anew + (double)ii;
                  sorted_pitcheslength->data[(ndbl - ii) - 1] = b_apnd - (double)
                    ii;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = i_pitcheslength->size[0] * i_pitcheslength->size[1];
            i_pitcheslength->size[0] = 1;
            i_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)i_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              i_pitcheslength->data[i_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              i_pitcheslength->data[i_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = e_headpitches->size[0] * e_headpitches->size[1];
            e_headpitches->size[0] = 1;
            e_headpitches->size[1] = i_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)e_headpitches, i29, (int)
                              sizeof(double));
            ii = i_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              e_headpitches->data[e_headpitches->size[0] * i29] =
                headpitches->data[i_pitcheslength->data[i_pitcheslength->size[0]
                * i29] - 1];
            }

            i29 = headpitches->size[0] * headpitches->size[1];
            headpitches->size[0] = 1;
            headpitches->size[1] = e_headpitches->size[1];
            emxEnsureCapacity((emxArray__common *)headpitches, i29, (int)sizeof
                              (double));
            ii = e_headpitches->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              headpitches->data[headpitches->size[0] * i29] =
                e_headpitches->data[e_headpitches->size[0] * i29];
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = index_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              index_data[i29]++;
            }

            if ((unsigned int)visited->size[1] < (unsigned int)index_data[0]) {
              ndbl = 0;
              anew = index_data[0];
              b_apnd = visited->size[1];
            } else {
              anew = index_data[0];
              ndbl = (int)floor(((double)visited->size[1] - index_data[0]) + 0.5);
              b_apnd = index_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)visited->size[1];
              idx = visited->size[1];
              u0 = (unsigned int)index_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = visited->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = index_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (k = 1; k < idx; k++) {
                  sorted_pitcheslength->data[k] = anew + (double)k;
                  sorted_pitcheslength->data[(ndbl - k) - 1] = b_apnd - (double)
                    k;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = j_pitcheslength->size[0] * j_pitcheslength->size[1];
            j_pitcheslength->size[0] = 1;
            j_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)j_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              j_pitcheslength->data[j_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              j_pitcheslength->data[j_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = e_visited->size[0] * e_visited->size[1];
            e_visited->size[0] = 1;
            e_visited->size[1] = j_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)e_visited, i29, (int)sizeof
                              (double));
            ii = j_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              e_visited->data[e_visited->size[0] * i29] = visited->
                data[j_pitcheslength->data[j_pitcheslength->size[0] * i29] - 1];
            }

            i29 = visited->size[0] * visited->size[1];
            visited->size[0] = 1;
            visited->size[1] = e_visited->size[1];
            emxEnsureCapacity((emxArray__common *)visited, i29, (int)sizeof
                              (double));
            ii = e_visited->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              visited->data[visited->size[0] * i29] = e_visited->data
                [e_visited->size[0] * i29];
            }
          }
        }

        if (guard2) {
          e_check_pitchlength_size[0] = 1;
          e_check_pitchlength_size[1] = k;
          for (i29 = 0; i29 < k; i29++) {
            g_check_pitchlength_data[i29] = (check_pitchlength_data[i29] < 50.0);
          }

          l_check_pitchlength_data.data = (boolean_T *)&g_check_pitchlength_data;
          l_check_pitchlength_data.size = (int *)&e_check_pitchlength_size;
          l_check_pitchlength_data.allocatedSize = 1;
          l_check_pitchlength_data.numDimensions = 2;
          l_check_pitchlength_data.canFreeData = false;
          if (all(&l_check_pitchlength_data)) {
            for (i29 = 0; i29 < k; i29++) {
              right_pitch_data[i29] = headidx->data[(int)b_check_idx_data[i29] -
                1];
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] + 1.0;
            }

            if ((unsigned int)headidx->size[1] < (unsigned int)left_pitch_data[0])
            {
              ndbl = 0;
              anew = left_pitch_data[0];
              b_apnd = headidx->size[1];
            } else {
              anew = left_pitch_data[0];
              ndbl = (int)floor(((double)headidx->size[1] - left_pitch_data[0])
                                + 0.5);
              b_apnd = left_pitch_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)headidx->size[1];
              idx = headidx->size[1];
              u0 = (unsigned int)left_pitch_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = headidx->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = left_pitch_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  sorted_pitcheslength->data[ii] = anew + (double)ii;
                  sorted_pitcheslength->data[(ndbl - ii) - 1] = b_apnd - (double)
                    ii;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = e_pitcheslength->size[0] * e_pitcheslength->size[1];
            e_pitcheslength->size[0] = 1;
            e_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)e_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              e_pitcheslength->data[e_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              e_pitcheslength->data[e_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = e_headidx->size[0] * e_headidx->size[1];
            e_headidx->size[0] = 1;
            e_headidx->size[1] = e_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)e_headidx, i29, (int)sizeof
                              (double));
            ii = e_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              e_headidx->data[e_headidx->size[0] * i29] = headidx->
                data[e_pitcheslength->data[e_pitcheslength->size[0] * i29] - 1];
            }

            i29 = headidx->size[0] * headidx->size[1];
            headidx->size[0] = 1;
            headidx->size[1] = e_headidx->size[1];
            emxEnsureCapacity((emxArray__common *)headidx, i29, (int)sizeof
                              (double));
            ii = e_headidx->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              headidx->data[headidx->size[0] * i29] = e_headidx->data
                [e_headidx->size[0] * i29];
            }

            for (i29 = 0; i29 < k; i29++) {
              headidx->data[(int)b_check_idx_data[i29] - 1] =
                right_pitch_data[i29];
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              b_check_idx_data[i29]++;
            }

            if ((unsigned int)headpitches->size[1] < (unsigned int)
                b_check_idx_data[0]) {
              ndbl = 0;
              anew = b_check_idx_data[0];
              b_apnd = headpitches->size[1];
            } else {
              anew = b_check_idx_data[0];
              ndbl = (int)floor(((double)headpitches->size[1] -
                                 b_check_idx_data[0]) + 0.5);
              b_apnd = b_check_idx_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)headpitches->size[1];
              idx = headpitches->size[1];
              u0 = (unsigned int)b_check_idx_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = headpitches->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = b_check_idx_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  sorted_pitcheslength->data[ii] = anew + (double)ii;
                  sorted_pitcheslength->data[(ndbl - ii) - 1] = b_apnd - (double)
                    ii;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = f_pitcheslength->size[0] * f_pitcheslength->size[1];
            f_pitcheslength->size[0] = 1;
            f_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)f_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              f_pitcheslength->data[f_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              f_pitcheslength->data[f_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = d_headpitches->size[0] * d_headpitches->size[1];
            d_headpitches->size[0] = 1;
            d_headpitches->size[1] = f_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)d_headpitches, i29, (int)
                              sizeof(double));
            ii = f_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              d_headpitches->data[d_headpitches->size[0] * i29] =
                headpitches->data[f_pitcheslength->data[f_pitcheslength->size[0]
                * i29] - 1];
            }

            i29 = headpitches->size[0] * headpitches->size[1];
            headpitches->size[0] = 1;
            headpitches->size[1] = d_headpitches->size[1];
            emxEnsureCapacity((emxArray__common *)headpitches, i29, (int)sizeof
                              (double));
            ii = d_headpitches->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              headpitches->data[headpitches->size[0] * i29] =
                d_headpitches->data[d_headpitches->size[0] * i29];
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = index_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              index_data[i29]++;
            }

            if ((unsigned int)visited->size[1] < (unsigned int)index_data[0]) {
              ndbl = 0;
              anew = index_data[0];
              b_apnd = visited->size[1];
            } else {
              anew = index_data[0];
              ndbl = (int)floor(((double)visited->size[1] - index_data[0]) + 0.5);
              b_apnd = index_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)visited->size[1];
              idx = visited->size[1];
              u0 = (unsigned int)index_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = visited->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = index_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (k = 1; k < idx; k++) {
                  sorted_pitcheslength->data[k] = anew + (double)k;
                  sorted_pitcheslength->data[(ndbl - k) - 1] = b_apnd - (double)
                    k;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = g_pitcheslength->size[0] * g_pitcheslength->size[1];
            g_pitcheslength->size[0] = 1;
            g_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)g_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              g_pitcheslength->data[g_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              g_pitcheslength->data[g_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = d_visited->size[0] * d_visited->size[1];
            d_visited->size[0] = 1;
            d_visited->size[1] = g_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)d_visited, i29, (int)sizeof
                              (double));
            ii = g_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              d_visited->data[d_visited->size[0] * i29] = visited->
                data[g_pitcheslength->data[g_pitcheslength->size[0] * i29] - 1];
            }

            i29 = visited->size[0] * visited->size[1];
            visited->size[0] = 1;
            visited->size[1] = d_visited->size[1];
            emxEnsureCapacity((emxArray__common *)visited, i29, (int)sizeof
                              (double));
            ii = d_visited->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              visited->data[visited->size[0] * i29] = d_visited->data
                [d_visited->size[0] * i29];
            }
          }
        }

        if (b_guard1) {
          f_check_pitchlength_size[0] = 1;
          f_check_pitchlength_size[1] = k;
          for (i29 = 0; i29 < k; i29++) {
            j_check_pitchlength_data[i29] = (check_pitchlength_data[i29] < 50.0);
          }

          m_check_pitchlength_data.data = (boolean_T *)&j_check_pitchlength_data;
          m_check_pitchlength_data.size = (int *)&f_check_pitchlength_size;
          m_check_pitchlength_data.allocatedSize = 1;
          m_check_pitchlength_data.numDimensions = 2;
          m_check_pitchlength_data.canFreeData = false;
          if (all(&m_check_pitchlength_data)) {
            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] + 2.0;
            }

            if ((unsigned int)headidx->size[1] < (unsigned int)left_pitch_data[0])
            {
              ndbl = 0;
              anew = left_pitch_data[0];
              b_apnd = headidx->size[1];
            } else {
              anew = left_pitch_data[0];
              ndbl = (int)floor(((double)headidx->size[1] - left_pitch_data[0])
                                + 0.5);
              b_apnd = left_pitch_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)headidx->size[1];
              idx = headidx->size[1];
              u0 = (unsigned int)left_pitch_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = headidx->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = left_pitch_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  sorted_pitcheslength->data[ii] = anew + (double)ii;
                  sorted_pitcheslength->data[(ndbl - ii) - 1] = b_apnd - (double)
                    ii;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = b_pitcheslength->size[0] * b_pitcheslength->size[1];
            b_pitcheslength->size[0] = 1;
            b_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)b_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              b_pitcheslength->data[b_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              b_pitcheslength->data[b_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = d_headidx->size[0] * d_headidx->size[1];
            d_headidx->size[0] = 1;
            d_headidx->size[1] = b_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)d_headidx, i29, (int)sizeof
                              (double));
            ii = b_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              d_headidx->data[d_headidx->size[0] * i29] = headidx->
                data[b_pitcheslength->data[b_pitcheslength->size[0] * i29] - 1];
            }

            i29 = headidx->size[0] * headidx->size[1];
            headidx->size[0] = 1;
            headidx->size[1] = d_headidx->size[1];
            emxEnsureCapacity((emxArray__common *)headidx, i29, (int)sizeof
                              (double));
            ii = d_headidx->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              headidx->data[headidx->size[0] * i29] = d_headidx->data
                [d_headidx->size[0] * i29];
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = b_check_idx_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              b_check_idx_data[i29] += 2.0;
            }

            if ((unsigned int)headpitches->size[1] < (unsigned int)
                b_check_idx_data[0]) {
              ndbl = 0;
              anew = b_check_idx_data[0];
              b_apnd = headpitches->size[1];
            } else {
              anew = b_check_idx_data[0];
              ndbl = (int)floor(((double)headpitches->size[1] -
                                 b_check_idx_data[0]) + 0.5);
              b_apnd = b_check_idx_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)headpitches->size[1];
              idx = headpitches->size[1];
              u0 = (unsigned int)b_check_idx_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = headpitches->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = b_check_idx_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  sorted_pitcheslength->data[ii] = anew + (double)ii;
                  sorted_pitcheslength->data[(ndbl - ii) - 1] = b_apnd - (double)
                    ii;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = c_pitcheslength->size[0] * c_pitcheslength->size[1];
            c_pitcheslength->size[0] = 1;
            c_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)c_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              c_pitcheslength->data[c_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              c_pitcheslength->data[c_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = c_headpitches->size[0] * c_headpitches->size[1];
            c_headpitches->size[0] = 1;
            c_headpitches->size[1] = c_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)c_headpitches, i29, (int)
                              sizeof(double));
            ii = c_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              c_headpitches->data[c_headpitches->size[0] * i29] =
                headpitches->data[c_pitcheslength->data[c_pitcheslength->size[0]
                * i29] - 1];
            }

            i29 = headpitches->size[0] * headpitches->size[1];
            headpitches->size[0] = 1;
            headpitches->size[1] = c_headpitches->size[1];
            emxEnsureCapacity((emxArray__common *)headpitches, i29, (int)sizeof
                              (double));
            ii = c_headpitches->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              headpitches->data[headpitches->size[0] * i29] =
                c_headpitches->data[c_headpitches->size[0] * i29];
            }

            for (i29 = 0; i29 < k; i29++) {
              left_pitch_data[i29] = index_data[i29] - 1.0;
            }

            if ((int)left_pitch_data[0] < 1) {
              ndbl = 0;
              apnd = (int)left_pitch_data[0];
            } else {
              ndbl = (int)floor((left_pitch_data[0] - 1.0) + 0.5);
              apnd = ndbl + 1;
              idx = (ndbl - (int)left_pitch_data[0]) + 1;
              ii = (int)left_pitch_data[0];
              if (1 >= ii) {
                ii = 1;
              }

              if (fabs(idx) < 4.4408920985006262E-16 * (double)ii) {
                ndbl++;
                apnd = (int)left_pitch_data[0];
              } else if (idx > 0) {
                apnd = ndbl;
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = pitcheslength->size[0] * pitcheslength->size[1];
            pitcheslength->size[0] = 1;
            pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)
                              sizeof(double));
            if (ndbl > 0) {
              pitcheslength->data[0] = 1.0;
              if (ndbl > 1) {
                pitcheslength->data[ndbl - 1] = apnd;
                idx = (ndbl - 1) / 2;
                for (ii = 1; ii < idx; ii++) {
                  pitcheslength->data[ii] = 1.0 + (double)ii;
                  pitcheslength->data[(ndbl - ii) - 1] = apnd - ii;
                }

                if (idx << 1 == ndbl - 1) {
                  pitcheslength->data[idx] = (1.0 + (double)apnd) / 2.0;
                } else {
                  pitcheslength->data[idx] = 1.0 + (double)idx;
                  pitcheslength->data[idx + 1] = apnd - idx;
                }
              }
            }

            for (i29 = 0; i29 < k; i29++) {
              index_data[i29] += 2.0;
            }

            if ((unsigned int)visited->size[1] < (unsigned int)index_data[0]) {
              ndbl = 0;
              anew = index_data[0];
              b_apnd = visited->size[1];
            } else {
              anew = index_data[0];
              ndbl = (int)floor(((double)visited->size[1] - index_data[0]) + 0.5);
              b_apnd = index_data[0] + (double)ndbl;
              cdiff = b_apnd - (double)visited->size[1];
              idx = visited->size[1];
              u0 = (unsigned int)index_data[0];
              u1 = (unsigned int)idx;
              if (u0 >= u1) {
                u1 = u0;
              }

              if (fabs(cdiff) < 4.4408920985006262E-16 * (double)u1) {
                ndbl++;
                b_apnd = visited->size[1];
              } else if (cdiff > 0.0) {
                b_apnd = index_data[0] + ((double)ndbl - 1.0);
              } else {
                ndbl++;
              }

              if (ndbl >= 0) {
              } else {
                ndbl = 0;
              }
            }

            i29 = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
            sorted_pitcheslength->size[0] = 1;
            sorted_pitcheslength->size[1] = ndbl;
            emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, i29,
                              (int)sizeof(double));
            if (ndbl > 0) {
              sorted_pitcheslength->data[0] = anew;
              if (ndbl > 1) {
                sorted_pitcheslength->data[ndbl - 1] = b_apnd;
                idx = (ndbl - 1) / 2;
                for (k = 1; k < idx; k++) {
                  sorted_pitcheslength->data[k] = anew + (double)k;
                  sorted_pitcheslength->data[(ndbl - k) - 1] = b_apnd - (double)
                    k;
                }

                if (idx << 1 == ndbl - 1) {
                  sorted_pitcheslength->data[idx] = (anew + b_apnd) / 2.0;
                } else {
                  sorted_pitcheslength->data[idx] = anew + (double)idx;
                  sorted_pitcheslength->data[idx + 1] = b_apnd - (double)idx;
                }
              }
            }

            i29 = d_pitcheslength->size[0] * d_pitcheslength->size[1];
            d_pitcheslength->size[0] = 1;
            d_pitcheslength->size[1] = pitcheslength->size[1] +
              sorted_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)d_pitcheslength, i29, (int)
                              sizeof(int));
            ii = pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              d_pitcheslength->data[d_pitcheslength->size[0] * i29] = (int)
                pitcheslength->data[pitcheslength->size[0] * i29];
            }

            ii = sorted_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              d_pitcheslength->data[d_pitcheslength->size[0] * (i29 +
                pitcheslength->size[1])] = (int)sorted_pitcheslength->
                data[sorted_pitcheslength->size[0] * i29];
            }

            i29 = c_visited->size[0] * c_visited->size[1];
            c_visited->size[0] = 1;
            c_visited->size[1] = d_pitcheslength->size[1];
            emxEnsureCapacity((emxArray__common *)c_visited, i29, (int)sizeof
                              (double));
            ii = d_pitcheslength->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              c_visited->data[c_visited->size[0] * i29] = visited->
                data[d_pitcheslength->data[d_pitcheslength->size[0] * i29] - 1];
            }

            i29 = visited->size[0] * visited->size[1];
            visited->size[0] = 1;
            visited->size[1] = c_visited->size[1];
            emxEnsureCapacity((emxArray__common *)visited, i29, (int)sizeof
                              (double));
            ii = c_visited->size[1];
            for (i29 = 0; i29 < ii; i29++) {
              visited->data[visited->size[0] * i29] = c_visited->data
                [c_visited->size[0] * i29];
            }
          }
        }

        /*      elseif(check_idx~=1&&check_idx~=length(headidx)) */
        /*             if(left_pitchlength>right_pitchlength) */
        /*                 if(((check_pitchlength/left_pitchlength<absorb_threshold)||check_pitchlength<min_length)&&check_pitchlength<stable_length) */
        /*                      headidx = headidx([1:check_idx-1, check_idx+1:end]); */
        /*                      headpitches = headpitches([1:check_idx-1, check_idx+1:end]); */
        /*                      visited = visited([1:index-1, index+1:end]);              */
        /*                 end */
        /*             elseif(left_pitchlength < right_pitchlength) */
        /*                 if(((check_pitchlength/left_pitchlength<absorb_threshold)||check_pitchlength<min_length)&&check_pitchlength<stable_length) */
        /*                      temp = headidx(check_idx); */
        /*                      headidx = headidx([1:check_idx-1, check_idx+1:end]); */
        /*                      headidx(check_idx) = temp; */
        /*                      headpitches = headpitches([1:check_idx-1, check_idx+1:end]); */
        /*                      visited = visited([1:index-1, index+1:end]);                    */
        /*                 end */
        /*             else */
        /*                 if(((check_pitchlength/(left_pitchlength+right_pitchlength)<absorb_threshold)||check_pitchlength<min_length)&&check_pitchlength<stable_length) */
        /*                     headidx = headidx([1:check_idx-1, check_idx+2:end]); */
        /*                     headpitches = headpitches([1:check_idx-1, check_idx+2:end]); */
        /*                     visited = visited([1:index-1, index+2:end]); */
        /*                 end */
        /*             end */
      }
    }
  } while (exitg1 == 0);

  emxFree_real_T(&h_visited);
  emxFree_int32_T(&s_pitcheslength);
  emxFree_real_T(&h_headpitches);
  emxFree_int32_T(&r_pitcheslength);
  emxFree_real_T(&i_headidx);
  emxFree_int32_T(&q_pitcheslength);
  emxFree_real_T(&g_visited);
  emxFree_int32_T(&p_pitcheslength);
  emxFree_real_T(&g_headpitches);
  emxFree_int32_T(&o_pitcheslength);
  emxFree_real_T(&h_headidx);
  emxFree_int32_T(&n_pitcheslength);
  emxFree_real_T(&f_visited);
  emxFree_int32_T(&m_pitcheslength);
  emxFree_real_T(&f_headpitches);
  emxFree_int32_T(&l_pitcheslength);
  emxFree_real_T(&g_headidx);
  emxFree_int32_T(&k_pitcheslength);
  emxFree_real_T(&e_visited);
  emxFree_int32_T(&j_pitcheslength);
  emxFree_real_T(&e_headpitches);
  emxFree_int32_T(&i_pitcheslength);
  emxFree_real_T(&f_headidx);
  emxFree_int32_T(&h_pitcheslength);
  emxFree_real_T(&d_visited);
  emxFree_int32_T(&g_pitcheslength);
  emxFree_real_T(&d_headpitches);
  emxFree_int32_T(&f_pitcheslength);
  emxFree_real_T(&e_headidx);
  emxFree_int32_T(&e_pitcheslength);
  emxFree_real_T(&c_visited);
  emxFree_int32_T(&d_pitcheslength);
  emxFree_real_T(&c_headpitches);
  emxFree_int32_T(&c_pitcheslength);
  emxFree_real_T(&d_headidx);
  emxFree_int32_T(&b_pitcheslength);
  emxFree_real_T(&b_headpitches);
  emxFree_real_T(&c_headidx);
  emxFree_boolean_T(&b_visited);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&iidx);
  emxFree_real_T(&sorted_idx);
  emxFree_real_T(&visited);
  emxFree_real_T(&prev_headidx);
  i29 = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = arr->size[1];
  emxEnsureCapacity((emxArray__common *)out, i29, (int)sizeof(double));
  ii = arr->size[1];
  for (i29 = 0; i29 < ii; i29++) {
    out->data[i29] = 0.0;
  }

  i29 = pitcheslength->size[0] * pitcheslength->size[1];
  pitcheslength->size[0] = 1;
  pitcheslength->size[1] = headidx->size[1] + 1;
  emxEnsureCapacity((emxArray__common *)pitcheslength, i29, (int)sizeof(double));
  ii = headidx->size[1];
  for (i29 = 0; i29 < ii; i29++) {
    pitcheslength->data[pitcheslength->size[0] * i29] = headidx->data
      [headidx->size[0] * i29];
  }

  pitcheslength->data[pitcheslength->size[0] * headidx->size[1]] = arr->size[1];
  for (i = 0; i < headidx->size[1]; i++) {
    if ((int)pitcheslength->data[i] > (int)pitcheslength->data[(int)((1.0 +
          (double)i) + 1.0) - 1]) {
      i29 = 0;
    } else {
      i29 = (int)pitcheslength->data[i] - 1;
    }

    idx = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
    sorted_pitcheslength->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, idx, (int)sizeof
                      (double));
    idx = sorted_pitcheslength->size[0] * sorted_pitcheslength->size[1];
    sorted_pitcheslength->size[1] = (int)((pitcheslength->data[(int)((1.0 +
      (double)i) + 1.0) - 1] - pitcheslength->data[i]) + 1.0);
    emxEnsureCapacity((emxArray__common *)sorted_pitcheslength, idx, (int)sizeof
                      (double));
    anew = headpitches->data[i];
    ii = (int)((pitcheslength->data[(int)((1.0 + (double)i) + 1.0) - 1] -
                pitcheslength->data[i]) + 1.0);
    for (idx = 0; idx < ii; idx++) {
      sorted_pitcheslength->data[idx] = anew;
    }

    ii = sorted_pitcheslength->size[1];
    for (idx = 0; idx < ii; idx++) {
      out->data[i29 + idx] = sorted_pitcheslength->data
        [sorted_pitcheslength->size[0] * idx];
    }
  }

  emxFree_real_T(&sorted_pitcheslength);
  emxFree_real_T(&pitcheslength);
  emxFree_real_T(&headpitches);
  emxFree_real_T(&headidx);
}

/*
 * File trailer for Smooth2.c
 *
 * [EOF]
 */
