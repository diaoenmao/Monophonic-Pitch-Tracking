/*
 * File: Mybesseli.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 26-Oct-2015 23:41:06
 */

/* Include files */
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
  int i5;
  int loop_ub;
  unsigned int resize_idx_0;
  int ixstart;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int idx;
  boolean_T exitg8;
  boolean_T guard4 = false;
  emxArray_int32_T *b_ii;
  emxArray_real_T *v;
  boolean_T exitg7;
  boolean_T guard3 = false;
  emxArray_int32_T *c_ii;
  emxArray_real_T *plast;
  emxArray_real_T *b_x;
  double test;
  boolean_T exitg6;
  emxArray_real_T *p;
  double n;
  double en;
  boolean_T exitg5;
  emxArray_real_T *a;
  emxArray_boolean_T *b_p;
  emxArray_real_T *b_en;
  int32_T exitg4;
  emxArray_real_T *tempb;
  double empal;
  double emp2al;
  double nend;
  emxArray_real_T *c_en;
  boolean_T exitg3;
  emxArray_real_T *b_b;
  boolean_T exitg2;
  boolean_T guard2 = false;
  emxArray_int32_T *d_ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_int32_T *e_ii;
  emxArray_real_T *c_b;
  b_emxInit_real_T(&b, 1);

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
  i5 = b->size[0];
  b->size[0] = xx->size[0];
  emxEnsureCapacity((emxArray__common *)b, i5, (int)sizeof(double));
  loop_ub = xx->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b->data[i5] = rtNaN;
  }

  /*     resize = (length(alpha) == 1); */
  /*     if resize, resize = size(xx); end */
  resize_idx_0 = (unsigned int)xx->size[0];
  ixstart = xx->size[0];
  i5 = xx->size[0];
  xx->size[0] = ixstart;
  emxEnsureCapacity((emxArray__common *)xx, i5, (int)sizeof(double));
  b_emxInit_boolean_T(&x, 1);

  /*     b = NaN*ones(length(xx),nb); */
  /*  */
  /*   Asymptotic expansion for large x. */
  /*  */
  i5 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity((emxArray__common *)x, i5, (int)sizeof(boolean_T));
  loop_ub = xx->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    x->data[i5] = (1000.0 < xx->data[i5]);
  }

  b_emxInit_int32_T(&ii, 1);
  idx = 0;
  i5 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
  ixstart = 1;
  exitg8 = false;
  while ((!exitg8) && (ixstart <= x->size[0])) {
    guard4 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= x->size[0]) {
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
      i5 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
    }
  } else {
    if (1 > idx) {
      loop_ub = 0;
    } else {
      loop_ub = idx;
    }

    b_emxInit_int32_T(&b_ii, 1);
    i5 = b_ii->size[0];
    b_ii->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)b_ii, i5, (int)sizeof(int));
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_ii->data[i5] = ii->data[i5];
    }

    i5 = ii->size[0];
    ii->size[0] = b_ii->size[0];
    emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
    loop_ub = b_ii->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      ii->data[i5] = b_ii->data[i5];
    }

    emxFree_int32_T(&b_ii);
  }

  b_emxInit_real_T(&v, 1);
  i5 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)v, i5, (int)sizeof(double));
  loop_ub = ii->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    v->data[i5] = ii->data[i5];
  }

  if (any(v)) {
    ixstart = v->size[0];
    for (i5 = 0; i5 < ixstart; i5++) {
      b->data[(int)v->data[i5] - 1] = rtInf;
    }
  }

  /*  */
  /*   Three-term backward recurrence for most x. */
  /*  */
  i5 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity((emxArray__common *)x, i5, (int)sizeof(boolean_T));
  loop_ub = xx->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    x->data[i5] = ((0.0001 <= xx->data[i5]) && (xx->data[i5] <= 1000.0));
  }

  idx = 0;
  i5 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
  ixstart = 1;
  exitg7 = false;
  while ((!exitg7) && (ixstart <= x->size[0])) {
    guard3 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= x->size[0]) {
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
      i5 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
    }
  } else {
    if (1 > idx) {
      loop_ub = 0;
    } else {
      loop_ub = idx;
    }

    b_emxInit_int32_T(&c_ii, 1);
    i5 = c_ii->size[0];
    c_ii->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)c_ii, i5, (int)sizeof(int));
    for (i5 = 0; i5 < loop_ub; i5++) {
      c_ii->data[i5] = ii->data[i5];
    }

    i5 = ii->size[0];
    ii->size[0] = c_ii->size[0];
    emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
    loop_ub = c_ii->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      ii->data[i5] = c_ii->data[i5];
    }

    emxFree_int32_T(&c_ii);
  }

  i5 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)v, i5, (int)sizeof(double));
  loop_ub = ii->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    v->data[i5] = ii->data[i5];
  }

  b_emxInit_real_T(&plast, 1);
  if (any(v)) {
    b_emxInit_real_T(&b_x, 1);
    i5 = b_x->size[0];
    b_x->size[0] = v->size[0];
    emxEnsureCapacity((emxArray__common *)b_x, i5, (int)sizeof(double));
    loop_ub = v->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_x->data[i5] = xx->data[(int)v->data[i5] - 1];
    }

    i5 = plast->size[0];
    plast->size[0] = b_x->size[0];
    emxEnsureCapacity((emxArray__common *)plast, i5, (int)sizeof(double));
    loop_ub = b_x->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      plast->data[i5] = b_x->data[i5];
    }

    i5 = v->size[0];
    for (ixstart = 0; ixstart < i5; ixstart++) {
      if (plast->data[ixstart] < 0.0) {
        test = ceil(plast->data[ixstart]);
      } else {
        test = floor(plast->data[ixstart]);
      }

      plast->data[ixstart] = test;
    }

    ixstart = 1;
    test = plast->data[0];
    if (plast->size[0] > 1) {
      if (rtIsNaN(plast->data[0])) {
        idx = 2;
        exitg6 = false;
        while ((!exitg6) && (idx <= plast->size[0])) {
          ixstart = idx;
          if (!rtIsNaN(plast->data[idx - 1])) {
            test = plast->data[idx - 1];
            exitg6 = true;
          } else {
            idx++;
          }
        }
      }

      if (ixstart < plast->size[0]) {
        while (ixstart + 1 <= plast->size[0]) {
          if (plast->data[ixstart] > test) {
            test = plast->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    b_emxInit_real_T(&p, 1);

    /*  */
    /*      Initialize the forward sweep, the p-sequence of Olver. */
    /*  */
    n = test + 1.0;
    en = (test + 1.0) + (test + 1.0);
    i5 = plast->size[0];
    plast->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)plast, i5, (int)sizeof(double));
    plast->data[0] = 1.0;
    d_rdivide(en, b_x, p);

    /*  */
    /*      Calculate general significance test. */
    /*  */
    if (2.0 * test > 80.0) {
      ixstart = 1;
      test = p->data[0];
      if (p->size[0] > 1) {
        if (rtIsNaN(p->data[0])) {
          idx = 2;
          exitg5 = false;
          while ((!exitg5) && (idx <= p->size[0])) {
            ixstart = idx;
            if (!rtIsNaN(p->data[idx - 1])) {
              test = p->data[idx - 1];
              exitg5 = true;
            } else {
              idx++;
            }
          }
        }

        if (ixstart < p->size[0]) {
          while (ixstart + 1 <= p->size[0]) {
            if (p->data[ixstart] > test) {
              test = p->data[ixstart];
            }

            ixstart++;
          }
        }
      }

      test = sqrt(9.007199254740992E+15 * test);
    } else {
      test = 9.007199254740992E+15 / rt_powd_snf(1.585, test);
    }

    b_emxInit_real_T(&a, 1);

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
    i5 = a->size[0];
    a->size[0] = p->size[0];
    emxEnsureCapacity((emxArray__common *)a, i5, (int)sizeof(double));
    loop_ub = p->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      a->data[i5] = p->data[i5];
    }

    ixstart = 0;
    b_emxInit_boolean_T(&b_p, 1);
    b_emxInit_real_T(&b_en, 1);
    do {
      exitg4 = 0;
      i5 = b_p->size[0];
      b_p->size[0] = p->size[0];
      emxEnsureCapacity((emxArray__common *)b_p, i5, (int)sizeof(boolean_T));
      loop_ub = p->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        b_p->data[i5] = (p->data[i5] < test);
      }

      if (b_any(b_p)) {
        n++;
        en += 2.0;
        if (ixstart == 1) {
          i5 = plast->size[0];
          plast->size[0] = a->size[0];
          emxEnsureCapacity((emxArray__common *)plast, i5, (int)sizeof(double));
          loop_ub = a->size[0];
          for (i5 = 0; i5 < loop_ub; i5++) {
            plast->data[i5] = a->data[i5];
          }
        } else {
          ixstart = 1;
        }

        i5 = a->size[0];
        a->size[0] = p->size[0];
        emxEnsureCapacity((emxArray__common *)a, i5, (int)sizeof(double));
        loop_ub = p->size[0];
        for (i5 = 0; i5 < loop_ub; i5++) {
          a->data[i5] = p->data[i5];
        }

        i5 = b_en->size[0];
        b_en->size[0] = p->size[0];
        emxEnsureCapacity((emxArray__common *)b_en, i5, (int)sizeof(double));
        loop_ub = p->size[0];
        for (i5 = 0; i5 < loop_ub; i5++) {
          b_en->data[i5] = en * p->data[i5];
        }

        e_rdivide(b_en, b_x, p);
        i5 = p->size[0];
        emxEnsureCapacity((emxArray__common *)p, i5, (int)sizeof(double));
        loop_ub = p->size[0];
        for (i5 = 0; i5 < loop_ub; i5++) {
          p->data[i5] += plast->data[i5];
        }
      } else {
        exitg4 = 1;
      }
    } while (exitg4 == 0);

    emxFree_real_T(&b_en);
    emxFree_boolean_T(&b_p);
    b_emxInit_real_T(&tempb, 1);

    /*  */
    /*      Initialize the backward recursion and the normalization sum. */
    /*  */
    n++;
    en += 2.0;
    i5 = tempb->size[0];
    tempb->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)tempb, i5, (int)sizeof(double));
    tempb->data[0] = 0.0;
    d_rdivide(1.0, p, plast);
    test = n - 1.0;
    empal = n - 1.0;
    emp2al = (n - 1.0) - 1.0;
    i5 = a->size[0];
    a->size[0] = plast->size[0];
    emxEnsureCapacity((emxArray__common *)a, i5, (int)sizeof(double));
    loop_ub = plast->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      a->data[i5] = plast->data[i5] * (n - 1.0) * ((n - 1.0) - 1.0) / (n - 1.0);
    }

    nend = n - 1.0;
    if (n - 1.0 < 0.0) {
      loop_ub = plast->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        b->data[(int)v->data[i5] - 1] = plast->data[i5];
      }

      i5 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
    } else {
      if (n - 1.0 > 0.0) {
        /*  */
        /*            Recur backward via difference equation, calculating  */
        /*            (but not storing) b(n), until n = nb. */
        /*  */
        i5 = p->size[0];
        p->size[0] = plast->size[0];
        emxEnsureCapacity((emxArray__common *)p, i5, (int)sizeof(double));
        loop_ub = plast->size[0];
        for (i5 = 0; i5 < loop_ub; i5++) {
          p->data[i5] = plast->data[i5];
        }

        ixstart = 0;
        idx = 0;
        b_emxInit_real_T(&c_en, 1);
        exitg3 = false;
        while ((!exitg3) && (idx <= (int)nend - 1)) {
          n--;
          en -= 2.0;
          if (ixstart == 1) {
            i5 = tempb->size[0];
            tempb->size[0] = p->size[0];
            emxEnsureCapacity((emxArray__common *)tempb, i5, (int)sizeof(double));
            loop_ub = p->size[0];
            for (i5 = 0; i5 < loop_ub; i5++) {
              tempb->data[i5] = p->data[i5];
            }
          } else {
            ixstart = 1;
          }

          i5 = p->size[0];
          p->size[0] = plast->size[0];
          emxEnsureCapacity((emxArray__common *)p, i5, (int)sizeof(double));
          loop_ub = plast->size[0];
          for (i5 = 0; i5 < loop_ub; i5++) {
            p->data[i5] = plast->data[i5];
          }

          i5 = c_en->size[0];
          c_en->size[0] = plast->size[0];
          emxEnsureCapacity((emxArray__common *)c_en, i5, (int)sizeof(double));
          loop_ub = plast->size[0];
          for (i5 = 0; i5 < loop_ub; i5++) {
            c_en->data[i5] = en * plast->data[i5];
          }

          e_rdivide(c_en, b_x, plast);
          i5 = plast->size[0];
          emxEnsureCapacity((emxArray__common *)plast, i5, (int)sizeof(double));
          loop_ub = plast->size[0];
          for (i5 = 0; i5 < loop_ub; i5++) {
            plast->data[i5] += tempb->data[i5];
          }

          test--;
          emp2al--;
          if (n == 1.0) {
            exitg3 = true;
          } else {
            if (n == 2.0) {
              emp2al = 1.0;
            }

            empal--;
            i5 = a->size[0];
            emxEnsureCapacity((emxArray__common *)a, i5, (int)sizeof(double));
            loop_ub = a->size[0];
            for (i5 = 0; i5 < loop_ub; i5++) {
              a->data[i5] = (a->data[i5] + plast->data[i5] * empal) * emp2al /
                test;
            }

            idx++;
          }
        }

        emxFree_real_T(&c_en);
      }

      /*  */
      /*         Store b(nb). */
      /*  */
      loop_ub = plast->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        b->data[(int)v->data[i5] - 1] = plast->data[i5];
      }

      i5 = a->size[0];
      emxEnsureCapacity((emxArray__common *)a, i5, (int)sizeof(double));
      loop_ub = a->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        a->data[i5] = (a->data[i5] + a->data[i5]) + plast->data[i5];
      }
    }

    emxFree_real_T(&tempb);
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
    i5 = b_x->size[0];
    emxEnsureCapacity((emxArray__common *)b_x, i5, (int)sizeof(double));
    loop_ub = b_x->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_x->data[i5] = -b_x->data[i5];
    }

    b_exp(b_x);
    i5 = a->size[0];
    emxEnsureCapacity((emxArray__common *)a, i5, (int)sizeof(double));
    loop_ub = a->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      a->data[i5] *= b_x->data[i5];
    }

    emxFree_real_T(&b_x);
    b_emxInit_real_T(&b_b, 1);
    i5 = b_b->size[0];
    b_b->size[0] = v->size[0];
    emxEnsureCapacity((emxArray__common *)b_b, i5, (int)sizeof(double));
    loop_ub = v->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_b->data[i5] = b->data[(int)v->data[i5] - 1];
    }

    e_rdivide(b_b, a, plast);
    loop_ub = plast->size[0];
    emxFree_real_T(&b_b);
    emxFree_real_T(&a);
    for (i5 = 0; i5 < loop_ub; i5++) {
      b->data[(int)v->data[i5] - 1] = plast->data[i5];
    }
  }

  /*  */
  /*   Two-term ascending series for small x. */
  /*  */
  i5 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity((emxArray__common *)x, i5, (int)sizeof(boolean_T));
  loop_ub = xx->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    x->data[i5] = ((0.0 < xx->data[i5]) && (xx->data[i5] < 0.0001));
  }

  idx = 0;
  i5 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
  ixstart = 1;
  exitg2 = false;
  while ((!exitg2) && (ixstart <= x->size[0])) {
    guard2 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= x->size[0]) {
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
      i5 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
    }
  } else {
    if (1 > idx) {
      loop_ub = 0;
    } else {
      loop_ub = idx;
    }

    b_emxInit_int32_T(&d_ii, 1);
    i5 = d_ii->size[0];
    d_ii->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)d_ii, i5, (int)sizeof(int));
    for (i5 = 0; i5 < loop_ub; i5++) {
      d_ii->data[i5] = ii->data[i5];
    }

    i5 = ii->size[0];
    ii->size[0] = d_ii->size[0];
    emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
    loop_ub = d_ii->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      ii->data[i5] = d_ii->data[i5];
    }

    emxFree_int32_T(&d_ii);
  }

  i5 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)v, i5, (int)sizeof(double));
  loop_ub = ii->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    v->data[i5] = ii->data[i5];
  }

  if (any(v)) {
    ixstart = v->size[0];
    i5 = plast->size[0];
    plast->size[0] = v->size[0];
    emxEnsureCapacity((emxArray__common *)plast, i5, (int)sizeof(double));
    loop_ub = v->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      plast->data[i5] = 0.5 * xx->data[(int)v->data[i5] - 1];
    }

    for (i5 = 0; i5 < ixstart; i5++) {
      b->data[(int)v->data[i5] - 1] = 1.0 + plast->data[i5] * plast->data[i5];
    }
  }

  emxFree_real_T(&plast);

  /*  */
  /*   x == 0 */
  /*  */
  i5 = x->size[0];
  x->size[0] = xx->size[0];
  emxEnsureCapacity((emxArray__common *)x, i5, (int)sizeof(boolean_T));
  loop_ub = xx->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    x->data[i5] = (xx->data[i5] == 0.0);
  }

  idx = 0;
  i5 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
  ixstart = 1;
  exitg1 = false;
  while ((!exitg1) && (ixstart <= x->size[0])) {
    guard1 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= x->size[0]) {
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
      i5 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
    }
  } else {
    if (1 > idx) {
      loop_ub = 0;
    } else {
      loop_ub = idx;
    }

    b_emxInit_int32_T(&e_ii, 1);
    i5 = e_ii->size[0];
    e_ii->size[0] = loop_ub;
    emxEnsureCapacity((emxArray__common *)e_ii, i5, (int)sizeof(int));
    for (i5 = 0; i5 < loop_ub; i5++) {
      e_ii->data[i5] = ii->data[i5];
    }

    i5 = ii->size[0];
    ii->size[0] = e_ii->size[0];
    emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
    loop_ub = e_ii->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      ii->data[i5] = e_ii->data[i5];
    }

    emxFree_int32_T(&e_ii);
  }

  emxFree_boolean_T(&x);
  i5 = v->size[0];
  v->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)v, i5, (int)sizeof(double));
  loop_ub = ii->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    v->data[i5] = ii->data[i5];
  }

  emxFree_int32_T(&ii);
  if (any(v)) {
    /*  if alpha>0, I(alpha,0) = 0; I(0,0) = 1. */
    ixstart = v->size[0];
    for (i5 = 0; i5 < ixstart; i5++) {
      b->data[(int)v->data[i5] - 1] = 0.0;
    }

    ixstart = v->size[0];
    for (i5 = 0; i5 < ixstart; i5++) {
      b->data[(int)v->data[i5] - 1] = 1.0;
    }
  }

  emxFree_real_T(&v);
  b_emxInit_real_T(&c_b, 1);

  /*  */
  /*   Return the requested index range */
  /*  */
  ixstart = b->size[0];
  i5 = c_b->size[0];
  c_b->size[0] = ixstart;
  emxEnsureCapacity((emxArray__common *)c_b, i5, (int)sizeof(double));
  for (i5 = 0; i5 < ixstart; i5++) {
    c_b->data[i5] = b->data[i5];
  }

  i5 = b->size[0];
  b->size[0] = c_b->size[0];
  emxEnsureCapacity((emxArray__common *)b, i5, (int)sizeof(double));
  loop_ub = c_b->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b->data[i5] = c_b->data[i5];
  }

  emxFree_real_T(&c_b);

  /*     if resize */
  i5 = output->size[0] * output->size[1];
  output->size[0] = (int)resize_idx_0;
  output->size[1] = 1;
  emxEnsureCapacity((emxArray__common *)output, i5, (int)sizeof(double));
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
