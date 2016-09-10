/*
 * File: Mybesseli.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Mybesseli.h"
#include "yaapt_emxutil.h"
#include "rdivide.h"
#include "any.h"
#include "exp.h"

/* Function Declarations */
static double rt_powd_snf(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_powd_snf(double u0, double u1)
{
  double y;
  double d4;
  double d5;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d4 = fabs(u0);
    d5 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d4 == 1.0) {
        y = rtNaN;
      } else if (d4 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d5 == 0.0) {
      y = 1.0;
    } else if (d5 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/*
 * BESSELI Modified Bessel functions of the first kind.
 *  I = BESSELI(ALPHA,X) computes modified Bessel functions of the
 *  first kind, I_sub_alpha(X) for real, non-negative order ALPHA
 *  and argument X.  In general, both ALPHA and X may be vectors.
 *  The output I is m-by-n with m = length(X), n = length(ALPHA) and
 *      I(k,j) = I_sub_alpha(j)(X(k)).
 *  The elements of X can be any nonnegative real values in any order.
 *  For ALPHA there are two important restrictions: the increment
 *  in ALPHA must be one, i.e. ALPHA = alpha:1:alpha+n-1, and the
 *  elements must also be in the range 0 <= ALPHA(j) <= 1000.
 *
 *  E = BESSELI(ALPHA,X,1) computes I_sub_alpha(X)*EXP(-X).
 *
 *  The relationship between the Bessel functions of the first kind is
 *
 *      I_sub_alpha(x) = i^(-alpha) * J_sub_alpha(i*x)
 *
 *  Examples:
 *
 *      besseli(3:9,[0:.2:9.8 10:.5:20],1) generates the entire
 *      71-by-7 table on page 423 of Abramowitz and Stegun,
 *      "Handbook of Mathematical Functions."
 *
 *  See also: BESSELJ, BESSELY, BESSELK.
 * Arguments    : emxArray_real_T *xx
 *                emxArray_real_T *output
 * Return Type  : void
 */
void Mybesseli(emxArray_real_T *xx, emxArray_real_T *output)
{
  emxArray_real_T *b;
  int i15;
  int ixstart;
  unsigned int resize_idx_0;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  boolean_T exitg8;
  boolean_T guard4 = false;
  emxArray_real_T *v;
  boolean_T exitg7;
  boolean_T guard3 = false;
  emxArray_real_T *c_sum;
  emxArray_real_T *b_x;
  boolean_T exitg2;
  double mtmp;
  boolean_T guard2 = false;
  emxArray_real_T *p;
  boolean_T exitg6;
  double n;
  double en;
  double test;
  emxArray_real_T *a;
  boolean_T exitg5;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *b_b;
  int count;
  emxArray_boolean_T *b_p;
  emxArray_real_T *b_en;
  emxArray_real_T *c_en;
  int exitg4;
  emxArray_real_T *tempa;
  double em;
  double empal;
  double emp2al;
  double nend;
  int count2;
  int l;
  emxArray_real_T *d_en;
  emxArray_real_T *e_en;
  boolean_T exitg3;
  emxArray_real_T *c_b;
  emxArray_real_T *r21;
  emxInit_real_T1(&b, 1);

  /*    Acknowledgement: */
  /*  */
  /* 	This program is based on a Fortran program by W. J. Cody and */
  /* 	L. Stoltz, Applied Mathematics Division, Argonne National */
  /* 	Laboratory, dated May 30, 1989.  Their references include: */
  /*  */
  /* 	   "A Note on backward recurrence algorithms," Olver, F. W. J., */
  /* 	   and Sookne, D. J., Math. Comp. 26, 1972, pp 941-947. */
  /*  */
  /* 	   "Bessel functions of real argument and integer order," */
  /* 	   Sookne, D. J., NBS Jour. of Res. B. 77b, 1973, pp. 125-132. */
  /*  */
  /* 	   "Algorithm 597, Sequence of modified Bessel functions of the */
  /* 	   "first kind," Cody, W. J., Trans. Math. Soft., 1983, pp. 242-245. */
  /*  */
  /* 	MATLAB version: C. Moler, 10/6/92. */
  /* 	Copyright (c) 1984-94 by The MathWorks, Inc. */
  /*  */
  /*   Check for real, non-negative arguments. */
  /*  */
  /*     if nargin < 3, scale = 0; end */
  /*     if any(imag(xx)) | any(xx < 0) | any(imag(alpha)) | any(alpha < 0) */
  /*        error('Input arguments must be real and nonnegative.') */
  /*     end */
  /*     if isempty(alpha) | isempty(xx) */
  /*        bk = [];  */
  /*        return */
  /*     end */
  /*  */
  /*   Break alpha into integer and fractional parts, */
  /*   and initialize result array. */
  /*  */
  i15 = b->size[0];
  b->size[0] = xx->size[0];
  emxEnsureCapacity((emxArray__common *)b, i15, (int)sizeof(double));
  ixstart = xx->size[0];
  for (i15 = 0; i15 < ixstart; i15++) {
    b->data[i15] = rtNaN;
  }

  /*     resize = (length(alpha) == 1); */
  /*     if resize, resize = size(xx); end */
  resize_idx_0 = (unsigned int)xx->size[0];
  ixstart = xx->size[0];
  i15 = xx->size[0];
  xx->size[0] = ixstart;
  emxEnsureCapacity((emxArray__common *)xx, i15, (int)sizeof(double));
  emxInit_boolean_T1(&x, 1);

  /*     b = NaN*ones(length(xx),nb); */
  /*  */
  /*   Asymptotic expansion for large x. */
  /*  */
  i15 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity((emxArray__common *)x, i15, (int)sizeof(boolean_T));
  ixstart = xx->size[0];
  for (i15 = 0; i15 < ixstart; i15++) {
    x->data[i15] = (1000.0 < xx->data[i15]);
  }

  emxInit_int32_T1(&ii, 1);
  nx = x->size[0];
  idx = 0;
  i15 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
  ixstart = 1;
  exitg8 = false;
  while ((!exitg8) && (ixstart <= nx)) {
    guard4 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= nx) {
        exitg8 = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4) {
      ixstart++;
    }
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i15 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
    }
  } else {
    i15 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
  }

  emxInit_real_T1(&v, 1);
  i15 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)v, i15, (int)sizeof(double));
  ixstart = ii->size[0];
  for (i15 = 0; i15 < ixstart; i15++) {
    v->data[i15] = ii->data[i15];
  }

  if (any(v)) {
    ixstart = v->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      b->data[(int)v->data[i15] - 1] = rtInf;
    }
  }

  /*  */
  /*   Three-term backward recurrence for most x. */
  /*  */
  i15 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity((emxArray__common *)x, i15, (int)sizeof(boolean_T));
  ixstart = xx->size[0];
  for (i15 = 0; i15 < ixstart; i15++) {
    x->data[i15] = ((0.0001 <= xx->data[i15]) && (xx->data[i15] <= 1000.0));
  }

  nx = x->size[0];
  idx = 0;
  i15 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
  ixstart = 1;
  exitg7 = false;
  while ((!exitg7) && (ixstart <= nx)) {
    guard3 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= nx) {
        exitg7 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3) {
      ixstart++;
    }
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i15 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
    }
  } else {
    i15 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
  }

  i15 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)v, i15, (int)sizeof(double));
  ixstart = ii->size[0];
  for (i15 = 0; i15 < ixstart; i15++) {
    v->data[i15] = ii->data[i15];
  }

  emxInit_real_T1(&c_sum, 1);
  if (any(v)) {
    emxInit_real_T1(&b_x, 1);
    i15 = b_x->size[0];
    b_x->size[0] = v->size[0];
    emxEnsureCapacity((emxArray__common *)b_x, i15, (int)sizeof(double));
    ixstart = v->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      b_x->data[i15] = xx->data[(int)v->data[i15] - 1];
    }

    i15 = c_sum->size[0];
    c_sum->size[0] = b_x->size[0];
    emxEnsureCapacity((emxArray__common *)c_sum, i15, (int)sizeof(double));
    ixstart = b_x->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      c_sum->data[i15] = b_x->data[i15];
    }

    for (ixstart = 0; ixstart + 1 <= v->size[0]; ixstart++) {
      if (c_sum->data[ixstart] < 0.0) {
        mtmp = ceil(c_sum->data[ixstart]);
      } else {
        mtmp = floor(c_sum->data[ixstart]);
      }

      c_sum->data[ixstart] = mtmp;
    }

    ixstart = 1;
    nx = c_sum->size[0];
    mtmp = c_sum->data[0];
    if (c_sum->size[0] > 1) {
      if (rtIsNaN(c_sum->data[0])) {
        idx = 2;
        exitg6 = false;
        while ((!exitg6) && (idx <= nx)) {
          ixstart = idx;
          if (!rtIsNaN(c_sum->data[idx - 1])) {
            mtmp = c_sum->data[idx - 1];
            exitg6 = true;
          } else {
            idx++;
          }
        }
      }

      if (ixstart < c_sum->size[0]) {
        while (ixstart + 1 <= nx) {
          if (c_sum->data[ixstart] > mtmp) {
            mtmp = c_sum->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    emxInit_real_T1(&p, 1);

    /*  */
    /*      Initialize the forward sweep, the p-sequence of Olver. */
    /*  */
    n = mtmp + 1.0;
    en = (mtmp + 1.0) + (mtmp + 1.0);
    i15 = p->size[0];
    p->size[0] = b_x->size[0];
    emxEnsureCapacity((emxArray__common *)p, i15, (int)sizeof(double));
    ixstart = b_x->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      p->data[i15] = en / b_x->data[i15];
    }

    /*  */
    /*      Calculate general significance test. */
    /*  */
    if (2.0 * mtmp > 80.0) {
      ixstart = 1;
      nx = p->size[0];
      mtmp = p->data[0];
      if (p->size[0] > 1) {
        if (rtIsNaN(p->data[0])) {
          idx = 2;
          exitg5 = false;
          while ((!exitg5) && (idx <= nx)) {
            ixstart = idx;
            if (!rtIsNaN(p->data[idx - 1])) {
              mtmp = p->data[idx - 1];
              exitg5 = true;
            } else {
              idx++;
            }
          }
        }

        if (ixstart < p->size[0]) {
          while (ixstart + 1 <= nx) {
            if (p->data[ixstart] > mtmp) {
              mtmp = p->data[ixstart];
            }

            ixstart++;
          }
        }
      }

      test = sqrt(9.007199254740992E+15 * mtmp);
    } else {
      test = 9.007199254740992E+15 / rt_powd_snf(1.585, mtmp);
    }

    emxInit_real_T1(&a, 1);

    /*        if (nbmx >= 3) */
    /*  % */
    /*  %     Calculate p-sequence until n = nb-1. */
    /*  % */
    /*           tover = eps*realmax; */
    /*           nstart = magx+2; */
    /*           nend = nb - 1; */
    /*           for k = nstart:nend */
    /*              n = k; */
    /*              en = en + 2; */
    /*              pold = plast; */
    /*              plast = p; */
    /*              p = en * plast./x + pold; */
    /*              if any(p > tover) */
    /*  % */
    /*  %           To avoid overflow, divide p-sequence by tover. */
    /*  %           Calculate p-sequence until abs(p) > 1. */
    /*  % */
    /*                 tover = realmax; */
    /*                 p = p / tover; */
    /*                 plast = plast / tover; */
    /*                 psave = p; */
    /*                 psavel = plast; */
    /*                 nstart = n + 1; */
    /*                 while any(p <= 1); */
    /*                    n = n + 1; */
    /*                    en = en + 2; */
    /*                    pold = plast; */
    /*                    plast = p; */
    /*                    p = en * plast./x + pold; */
    /*                 end */
    /*                 tempb = en ./ x; */
    /*  % */
    /*  %              Calculate backward test, and find ncalc, */
    /*  %              the highest n such that the test is passed. */
    /*  % */
    /*                 test = pold*plast*eps; */
    /*                 test = test*(0.5-0.5/min(tempb*tempb)); */
    /*                 p = plast * tover; */
    /*                 n = n - 1; */
    /*                 en = en - 2; */
    /*                 nend = min(nb,n); */
    /*                 ncalc = nend + 1; */
    /*                 for l = nstart:nend */
    /*                    pold = psavel; */
    /*                    psavel = psave; */
    /*                    psave = en * psavel./x + pold; */
    /*                    if any(psave.*psavel > test); */
    /*                       ncalc = l-1; */
    /*                       test = 0; */
    /*                       break */
    /*                    end */
    /*                 end */
    /*                 break */
    /*              end */
    /*           end */
    /*           if ~test */
    /*              n = nend; */
    /*              en = (n+n) + (alpha+alpha); */
    /*  % */
    /*  %           Calculate special significance test for nbmx > 2. */
    /*  % */
    /*              test = max(test,max(sqrt(plast/eps).*sqrt(p+p))); */
    /*           end */
    /*        end */
    /*  */
    /*      Calculate p-sequence until significance test passed. */
    /*  */
    i15 = a->size[0];
    a->size[0] = p->size[0];
    emxEnsureCapacity((emxArray__common *)a, i15, (int)sizeof(double));
    ixstart = p->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      a->data[i15] = p->data[i15];
    }

    count = 0;
    emxInit_boolean_T1(&b_p, 1);
    emxInit_real_T1(&b_en, 1);
    emxInit_real_T1(&c_en, 1);
    do {
      exitg4 = 0;
      i15 = b_p->size[0];
      b_p->size[0] = p->size[0];
      emxEnsureCapacity((emxArray__common *)b_p, i15, (int)sizeof(boolean_T));
      ixstart = p->size[0];
      for (i15 = 0; i15 < ixstart; i15++) {
        b_p->data[i15] = (p->data[i15] < test);
      }

      if (b_any(b_p)) {
        n++;
        en += 2.0;
        if (count == 1) {
          i15 = c_sum->size[0];
          c_sum->size[0] = a->size[0];
          emxEnsureCapacity((emxArray__common *)c_sum, i15, (int)sizeof(double));
          ixstart = a->size[0];
          for (i15 = 0; i15 < ixstart; i15++) {
            c_sum->data[i15] = a->data[i15];
          }

          i15 = a->size[0];
          a->size[0] = p->size[0];
          emxEnsureCapacity((emxArray__common *)a, i15, (int)sizeof(double));
          ixstart = p->size[0];
          for (i15 = 0; i15 < ixstart; i15++) {
            a->data[i15] = p->data[i15];
          }

          i15 = c_en->size[0];
          c_en->size[0] = p->size[0];
          emxEnsureCapacity((emxArray__common *)c_en, i15, (int)sizeof(double));
          ixstart = p->size[0];
          for (i15 = 0; i15 < ixstart; i15++) {
            c_en->data[i15] = en * p->data[i15];
          }

          rdivide(c_en, b_x, p);
          i15 = p->size[0];
          emxEnsureCapacity((emxArray__common *)p, i15, (int)sizeof(double));
          ixstart = p->size[0];
          for (i15 = 0; i15 < ixstart; i15++) {
            p->data[i15] += c_sum->data[i15];
          }
        } else {
          count = 1;
          i15 = a->size[0];
          a->size[0] = p->size[0];
          emxEnsureCapacity((emxArray__common *)a, i15, (int)sizeof(double));
          ixstart = p->size[0];
          for (i15 = 0; i15 < ixstart; i15++) {
            a->data[i15] = p->data[i15];
          }

          i15 = b_en->size[0];
          b_en->size[0] = p->size[0];
          emxEnsureCapacity((emxArray__common *)b_en, i15, (int)sizeof(double));
          ixstart = p->size[0];
          for (i15 = 0; i15 < ixstart; i15++) {
            b_en->data[i15] = en * p->data[i15];
          }

          rdivide(b_en, b_x, c_sum);
          i15 = p->size[0];
          p->size[0] = c_sum->size[0];
          emxEnsureCapacity((emxArray__common *)p, i15, (int)sizeof(double));
          ixstart = c_sum->size[0];
          for (i15 = 0; i15 < ixstart; i15++) {
            p->data[i15] = c_sum->data[i15] + 1.0;
          }
        }

        /*           a = p; */
        /*           p = en * a./x + pold; */
      } else {
        exitg4 = 1;
      }
    } while (exitg4 == 0);

    emxFree_real_T(&c_en);
    emxFree_real_T(&b_en);
    emxFree_boolean_T(&b_p);
    emxInit_real_T1(&tempa, 1);

    /*  */
    /*      Initialize the backward recursion and the normalization sum. */
    /*  */
    n++;
    en += 2.0;
    b_rdivide(p, tempa);
    em = n - 1.0;
    empal = n - 1.0;
    emp2al = (n - 1.0) - 1.0;
    i15 = c_sum->size[0];
    c_sum->size[0] = tempa->size[0];
    emxEnsureCapacity((emxArray__common *)c_sum, i15, (int)sizeof(double));
    ixstart = tempa->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      c_sum->data[i15] = tempa->data[i15] * (n - 1.0) * ((n - 1.0) - 1.0) / (n -
        1.0);
    }

    nend = n - 1.0;
    if (n - 1.0 < 0.0) {
      ixstart = tempa->size[0];
      for (i15 = 0; i15 < ixstart; i15++) {
        b->data[(int)v->data[i15] - 1] = tempa->data[i15];
      }

      i15 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
    } else {
      if (n - 1.0 > 0.0) {
        /*  */
        /*            Recur backward via difference equation, calculating  */
        /*            (but not storing) b(n), until n = nb. */
        /*  */
        i15 = a->size[0];
        a->size[0] = tempa->size[0];
        emxEnsureCapacity((emxArray__common *)a, i15, (int)sizeof(double));
        ixstart = tempa->size[0];
        for (i15 = 0; i15 < ixstart; i15++) {
          a->data[i15] = tempa->data[i15];
        }

        count2 = 0;
        l = 0;
        emxInit_real_T1(&d_en, 1);
        emxInit_real_T1(&e_en, 1);
        exitg3 = false;
        while ((!exitg3) && (l <= (int)nend - 1)) {
          n--;
          en -= 2.0;
          if (count2 == 1) {
            i15 = p->size[0];
            p->size[0] = a->size[0];
            emxEnsureCapacity((emxArray__common *)p, i15, (int)sizeof(double));
            ixstart = a->size[0];
            for (i15 = 0; i15 < ixstart; i15++) {
              p->data[i15] = a->data[i15];
            }

            i15 = a->size[0];
            a->size[0] = tempa->size[0];
            emxEnsureCapacity((emxArray__common *)a, i15, (int)sizeof(double));
            ixstart = tempa->size[0];
            for (i15 = 0; i15 < ixstart; i15++) {
              a->data[i15] = tempa->data[i15];
            }

            i15 = e_en->size[0];
            e_en->size[0] = tempa->size[0];
            emxEnsureCapacity((emxArray__common *)e_en, i15, (int)sizeof(double));
            ixstart = tempa->size[0];
            for (i15 = 0; i15 < ixstart; i15++) {
              e_en->data[i15] = en * tempa->data[i15];
            }

            rdivide(e_en, b_x, tempa);
            i15 = tempa->size[0];
            emxEnsureCapacity((emxArray__common *)tempa, i15, (int)sizeof(double));
            ixstart = tempa->size[0];
            for (i15 = 0; i15 < ixstart; i15++) {
              tempa->data[i15] += p->data[i15];
            }
          } else {
            count2 = 1;
            i15 = a->size[0];
            a->size[0] = tempa->size[0];
            emxEnsureCapacity((emxArray__common *)a, i15, (int)sizeof(double));
            ixstart = tempa->size[0];
            for (i15 = 0; i15 < ixstart; i15++) {
              a->data[i15] = tempa->data[i15];
            }

            i15 = d_en->size[0];
            d_en->size[0] = tempa->size[0];
            emxEnsureCapacity((emxArray__common *)d_en, i15, (int)sizeof(double));
            ixstart = tempa->size[0];
            for (i15 = 0; i15 < ixstart; i15++) {
              d_en->data[i15] = en * tempa->data[i15];
            }

            rdivide(d_en, b_x, tempa);
          }

          /*                 tempc = tempb; */
          /*                 kk = tempa; */
          /*                 tempa = (en*kk) ./ x + tempc; */
          em--;
          emp2al--;
          if (n == 1.0) {
            exitg3 = true;
          } else {
            if (n == 2.0) {
              emp2al = 1.0;
            }

            empal--;
            i15 = c_sum->size[0];
            emxEnsureCapacity((emxArray__common *)c_sum, i15, (int)sizeof(double));
            ixstart = c_sum->size[0];
            for (i15 = 0; i15 < ixstart; i15++) {
              c_sum->data[i15] = (c_sum->data[i15] + tempa->data[i15] * empal) *
                emp2al / em;
            }

            l++;
          }
        }

        emxFree_real_T(&e_en);
        emxFree_real_T(&d_en);
      }

      /*  */
      /*         Store b(nb). */
      /*  */
      ixstart = tempa->size[0];
      for (i15 = 0; i15 < ixstart; i15++) {
        b->data[(int)v->data[i15] - 1] = tempa->data[i15];
      }

      i15 = c_sum->size[0];
      emxEnsureCapacity((emxArray__common *)c_sum, i15, (int)sizeof(double));
      ixstart = c_sum->size[0];
      for (i15 = 0; i15 < ixstart; i15++) {
        c_sum->data[i15] = (c_sum->data[i15] + c_sum->data[i15]) + tempa->
          data[i15];
      }
    }

    emxFree_real_T(&tempa);
    emxFree_real_T(&a);
    emxFree_real_T(&p);

    /*  */
    /*      Calculate b(1) */
    /*  */
    /*        if skip == 0 */
    /*            b(v,1) = 2*empal*b(v,2) ./ x + b(v,3);  */
    /*        end */
    /*        if skip >= 0 */
    /*            sum = (sum + sum) + b(v,1);  */
    /*        end */
    /*  */
    /*      Normalize.  Divide all b(n) by sum. */
    /*  */
    i15 = b_x->size[0];
    emxEnsureCapacity((emxArray__common *)b_x, i15, (int)sizeof(double));
    ixstart = b_x->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      b_x->data[i15] = -b_x->data[i15];
    }

    b_exp(b_x);
    i15 = c_sum->size[0];
    emxEnsureCapacity((emxArray__common *)c_sum, i15, (int)sizeof(double));
    ixstart = c_sum->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      c_sum->data[i15] *= b_x->data[i15];
    }

    emxFree_real_T(&b_x);
    emxInit_real_T1(&c_b, 1);
    i15 = c_b->size[0];
    c_b->size[0] = v->size[0];
    emxEnsureCapacity((emxArray__common *)c_b, i15, (int)sizeof(double));
    ixstart = v->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      c_b->data[i15] = b->data[(int)v->data[i15] - 1];
    }

    emxInit_real_T1(&r21, 1);
    rdivide(c_b, c_sum, r21);
    ixstart = r21->size[0];
    emxFree_real_T(&c_b);
    for (i15 = 0; i15 < ixstart; i15++) {
      b->data[(int)v->data[i15] - 1] = r21->data[i15];
    }

    emxFree_real_T(&r21);
  }

  /*  */
  /*   Two-term ascending series for small x. */
  /*  */
  i15 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity((emxArray__common *)x, i15, (int)sizeof(boolean_T));
  ixstart = xx->size[0];
  for (i15 = 0; i15 < ixstart; i15++) {
    x->data[i15] = ((0.0 < xx->data[i15]) && (xx->data[i15] < 0.0001));
  }

  nx = x->size[0];
  idx = 0;
  i15 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
  ixstart = 1;
  exitg2 = false;
  while ((!exitg2) && (ixstart <= nx)) {
    guard2 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= nx) {
        exitg2 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      ixstart++;
    }
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i15 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
    }
  } else {
    i15 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
  }

  i15 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)v, i15, (int)sizeof(double));
  ixstart = ii->size[0];
  for (i15 = 0; i15 < ixstart; i15++) {
    v->data[i15] = ii->data[i15];
  }

  if (any(v)) {
    i15 = c_sum->size[0];
    c_sum->size[0] = v->size[0];
    emxEnsureCapacity((emxArray__common *)c_sum, i15, (int)sizeof(double));
    ixstart = v->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      c_sum->data[i15] = 0.5 * xx->data[(int)v->data[i15] - 1];
    }

    ixstart = v->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      b->data[(int)v->data[i15] - 1] = 1.0 + c_sum->data[i15] * c_sum->data[i15];
    }
  }

  emxFree_real_T(&c_sum);

  /*  */
  /*   x == 0 */
  /*  */
  i15 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity((emxArray__common *)x, i15, (int)sizeof(boolean_T));
  ixstart = xx->size[0];
  for (i15 = 0; i15 < ixstart; i15++) {
    x->data[i15] = (xx->data[i15] == 0.0);
  }

  nx = x->size[0];
  idx = 0;
  i15 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
  ixstart = 1;
  exitg1 = false;
  while ((!exitg1) && (ixstart <= nx)) {
    guard1 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ixstart++;
    }
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i15 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
    }
  } else {
    i15 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, i15, (int)sizeof(int));
  }

  emxFree_boolean_T(&x);
  i15 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)v, i15, (int)sizeof(double));
  ixstart = ii->size[0];
  for (i15 = 0; i15 < ixstart; i15++) {
    v->data[i15] = ii->data[i15];
  }

  emxFree_int32_T(&ii);
  if (any(v)) {
    /*  if alpha>0, I(alpha,0) = 0; I(0,0) = 1. */
    ixstart = v->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      b->data[(int)v->data[i15] - 1] = 0.0;
    }

    ixstart = v->size[0];
    for (i15 = 0; i15 < ixstart; i15++) {
      b->data[(int)v->data[i15] - 1] = 1.0;
    }
  }

  emxFree_real_T(&v);
  emxInit_real_T1(&b_b, 1);

  /*  */
  /*   Return the requested index range */
  /*  */
  ixstart = b->size[0];
  i15 = b_b->size[0];
  b_b->size[0] = ixstart;
  emxEnsureCapacity((emxArray__common *)b_b, i15, (int)sizeof(double));
  for (i15 = 0; i15 < ixstart; i15++) {
    b_b->data[i15] = b->data[i15];
  }

  i15 = b->size[0];
  b->size[0] = b_b->size[0];
  emxEnsureCapacity((emxArray__common *)b, i15, (int)sizeof(double));
  ixstart = b_b->size[0];
  for (i15 = 0; i15 < ixstart; i15++) {
    b->data[i15] = b_b->data[i15];
  }

  emxFree_real_T(&b_b);

  /*     if resize */
  i15 = output->size[0] * output->size[1];
  output->size[0] = (int)resize_idx_0;
  output->size[1] = 1;
  emxEnsureCapacity((emxArray__common *)output, i15, (int)sizeof(double));
  for (ixstart = 0; ixstart + 1 <= b->size[0]; ixstart++) {
    output->data[ixstart] = b->data[ixstart];
  }

  emxFree_real_T(&b);
}

/*
 * File trailer for Mybesseli.c
 *
 * [EOF]
 */
