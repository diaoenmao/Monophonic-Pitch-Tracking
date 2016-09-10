/*
 * File: Myspecgram.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 05-Sep-2016 15:50:20
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Myspecgram.h"
#include "yaapt_emxutil.h"
#include "cmp_rate.h"
#include "any.h"
#include "fft.h"
#include "fix.h"
#include "Myhanning.h"
#include "yaapt_rtwutil.h"

/* Function Definitions */

/*
 * SPECGRAM Calculate spectrogram from signal.
 *    B = SPECGRAM(A,NFFT,Fs,WINDOW,NOVERLAP) calculates the spectrogram for
 *    the signal in vector A.  SPECGRAM splits the signal into overlapping
 *    segments, windows each with the WINDOW vector and forms the columns of
 *    B with their zero-padded, length NFFT discrete Fourier transforms.  Thus
 *    each column of B contains an estimate of the short-term, time-localized
 *    frequency content of the signal A.  Time increases linearly across the
 *    columns of B, from left to right.  Frequency increases linearly down
 *    the rows, starting at 0.  If A is a length NX complex signal, B is a
 *    complex matrix with NFFT rows and
 *         k = fix((NX-NOVERLAP)/(length(WINDOW)-NOVERLAP))
 *    columns.  If A is real, B still has k columns but the higher frequency
 *    components are truncated (because they are redundant); in that case,
 *    SPECGRAM returns B with NFFT/2+1 rows for NFFT even and (NFFT+1)/2 rows
 *    for NFFT odd.  If you specify a scalar for WINDOW, SPECGRAM uses a
 *    Hanning window of that length.  WINDOW must have length smaller than
 *    or equal to NFFT and greater than NOVERLAP.  NOVERLAP is the number of
 *    samples the sections of A overlap.  Fs is the sampling frequency
 *    which does not effect the spectrogram but is used for scaling plots.
 *
 *    [B,F,T] = SPECGRAM(A,NFFT,Fs,WINDOW,NOVERLAP) returns a column of
 *    frequencies F and one of times T at which the spectrogram is computed.
 *    F has length equal to the number of rows of B, T has length k. If you
 *    leave Fs unspecified, SPECGRAM assumes a default of 2 Hz.
 *
 *    B = SPECGRAM(A) produces the spectrogram of the signal A using default
 *    settings; the defaults are NFFT = minimum of 256 and the length of A, a
 *    Hanning window of length NFFT, and NOVERLAP = length(WINDOW)/2.  You
 *    can tell SPECGRAM to use the default for any parameter by leaving it
 *    off or using [] for that parameter, e.g. SPECGRAM(A,[],1000)
 *
 *    SPECGRAM with no output arguments plots the absolute value of the
 *    spectrogram in the current figure, using IMAGESC(T,F,20*log10(ABS(B))),
 *    AXIS XY, COLORMAP(JET) so the low frequency content of the first
 *    portion of the signal is displayed in the lower left corner of the axes.
 *
 *    SPECGRAM(A,F,Fs,WINDOW) where F is a vector of frequencies in Hz
 *    (with 2 or more elements) computes the spectrogram at those frequencies
 *    using either the chirp z-transform for more than 20 evenly spaced
 *    frequencies or a polyphase decimation filterbank.
 *
 *    See also PWELCH, CSD, COHERE and TFE.
 * Arguments    : emxArray_real_T *x
 *                double nfft
 *                double window
 *                double noverlap
 *                emxArray_creal_T *yo
 * Return Type  : void
 */
void Myspecgram(emxArray_real_T *x, double nfft, double window, double noverlap,
                emxArray_creal_T *yo)
{
  emxArray_real_T *b_window;
  int nx;
  int varargin_1;
  int nwind;
  emxArray_real_T *b_x;
  int i12;
  int cdiff;
  int nm1d2;
  double ncol;
  int n;
  double anew;
  double apnd;
  double ndbl;
  emxArray_real_T *colindex;
  double b_cdiff;
  double absb;
  int b_apnd;
  emxArray_real_T *y;
  emxArray_real_T *rowindex;
  emxArray_real_T *r15;
  emxArray_creal_T *c_window;
  emxArray_real_T *c_x;
  boolean_T d_x;
  double b_y;
  emxArray_creal_T *b_yo;
  emxInit_real_T1(&b_window, 1);

  /*    Author(s): L. Shure, 1-1-91 */
  /*               T. Krauss, 4-2-93, updated */
  /*    Copyright 1988-2002 The MathWorks, Inc. */
  /*    $Revision: 1.8 $  $Date: 2002/03/28 17:30:53 $ */
  /*  error(nargchk(1,5,nargin)) */
  /*  [msg,x,nfft,Fs,window,noverlap]=specgramchk(varargin); */
  /*  error(msg) */
  Myhanning(window, b_window);

  /*  window = hanning(window); */
  nx = x->size[1];
  varargin_1 = b_window->size[0];
  nwind = b_window->size[0];
  if (x->size[1] < b_window->size[0]) {
    /*  zero-pad x if it has length less than the window length */
    x->data[b_window->size[0] - 1] = 0.0;
    nx = b_window->size[0];
  }

  emxInit_real_T1(&b_x, 1);
  i12 = b_x->size[0];
  b_x->size[0] = x->size[1];
  emxEnsureCapacity((emxArray__common *)b_x, i12, (int)sizeof(double));
  cdiff = x->size[1];
  for (i12 = 0; i12 < cdiff; i12++) {
    b_x->data[i12] = x->data[i12];
  }

  /*  make a column vector for ease later */
  nm1d2 = b_window->size[0];
  i12 = b_window->size[0];
  b_window->size[0] = nm1d2;
  emxEnsureCapacity((emxArray__common *)b_window, i12, (int)sizeof(double));

  /*  be consistent with data set */
  ncol = ((double)nx - noverlap) / ((double)varargin_1 - noverlap);
  b_fix(&ncol);
  if (rtIsNaN(ncol - 1.0)) {
    n = 1;
    anew = rtNaN;
    apnd = ncol - 1.0;
  } else if (ncol - 1.0 < 0.0) {
    n = 0;
    anew = 0.0;
    apnd = ncol - 1.0;
  } else if (rtIsInf(ncol - 1.0)) {
    n = 1;
    anew = rtNaN;
    apnd = ncol - 1.0;
  } else {
    anew = 0.0;
    ndbl = floor((ncol - 1.0) + 0.5);
    apnd = ndbl;
    b_cdiff = ndbl - (ncol - 1.0);
    if (fabs(b_cdiff) < 4.4408920985006262E-16 * fabs(ncol - 1.0)) {
      ndbl++;
      apnd = ncol - 1.0;
    } else if (b_cdiff > 0.0) {
      apnd = ndbl - 1.0;
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }
  }

  emxInit_real_T(&colindex, 2);
  i12 = colindex->size[0] * colindex->size[1];
  colindex->size[0] = 1;
  colindex->size[1] = n;
  emxEnsureCapacity((emxArray__common *)colindex, i12, (int)sizeof(double));
  if (n > 0) {
    colindex->data[0] = anew;
    if (n > 1) {
      colindex->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (cdiff = 1; cdiff < nm1d2; cdiff++) {
        colindex->data[cdiff] = anew + (double)cdiff;
        colindex->data[(n - cdiff) - 1] = apnd - (double)cdiff;
      }

      if (nm1d2 << 1 == n - 1) {
        colindex->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        colindex->data[nm1d2] = anew + (double)nm1d2;
        colindex->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  absb = (double)varargin_1 - noverlap;
  i12 = colindex->size[0] * colindex->size[1];
  colindex->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)colindex, i12, (int)sizeof(double));
  nm1d2 = colindex->size[0];
  cdiff = colindex->size[1];
  cdiff *= nm1d2;
  for (i12 = 0; i12 < cdiff; i12++) {
    colindex->data[i12] = 1.0 + colindex->data[i12] * absb;
  }

  if (varargin_1 < 1) {
    n = 0;
    b_apnd = 0;
  } else {
    nm1d2 = (int)floor(((double)nwind - 1.0) + 0.5);
    b_apnd = nm1d2 + 1;
    cdiff = (nm1d2 - varargin_1) + 1;
    if (fabs(cdiff) < 4.4408920985006262E-16 * (double)varargin_1) {
      nm1d2++;
      b_apnd = varargin_1;
    } else if (cdiff > 0) {
      b_apnd = nm1d2;
    } else {
      nm1d2++;
    }

    if (nm1d2 >= 0) {
      n = nm1d2;
    } else {
      n = 0;
    }
  }

  emxInit_real_T(&y, 2);
  i12 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity((emxArray__common *)y, i12, (int)sizeof(double));
  if (n > 0) {
    y->data[0] = 1.0;
    if (n > 1) {
      y->data[n - 1] = b_apnd;
      nm1d2 = (n - 1) / 2;
      for (cdiff = 1; cdiff < nm1d2; cdiff++) {
        y->data[cdiff] = 1.0 + (double)cdiff;
        y->data[(n - cdiff) - 1] = b_apnd - cdiff;
      }

      if (nm1d2 << 1 == n - 1) {
        y->data[nm1d2] = (1.0 + (double)b_apnd) / 2.0;
      } else {
        y->data[nm1d2] = 1.0 + (double)nm1d2;
        y->data[nm1d2 + 1] = b_apnd - nm1d2;
      }
    }
  }

  emxInit_real_T1(&rowindex, 1);
  i12 = rowindex->size[0];
  rowindex->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)rowindex, i12, (int)sizeof(double));
  cdiff = y->size[1];
  for (i12 = 0; i12 < cdiff; i12++) {
    rowindex->data[i12] = y->data[y->size[0] * i12];
  }

  emxFree_real_T(&y);
  nm1d2 = x->size[1];
  if (nm1d2 < ((double)varargin_1 + colindex->data[(int)ncol - 1]) - 1.0) {
    b_x->data[(int)(((double)varargin_1 + colindex->data[(int)ncol - 1]) - 1.0)
      - 1] = 0.0;

    /*  zero-pad x */
  }

  emxInit_real_T(&r15, 2);

  /*  put x into columns of y with the proper offset */
  /*  should be able to do this with fancy indexing! */
  cdiff = rowindex->size[0];
  i12 = r15->size[0] * r15->size[1];
  r15->size[0] = cdiff;
  r15->size[1] = (int)ncol;
  emxEnsureCapacity((emxArray__common *)r15, i12, (int)sizeof(double));
  nm1d2 = (int)ncol;
  for (i12 = 0; i12 < nm1d2; i12++) {
    for (n = 0; n < cdiff; n++) {
      r15->data[n + r15->size[0] * i12] = b_x->data[(int)((rowindex->data[n] +
        colindex->data[colindex->size[0] * i12]) - 1.0) - 1];
    }
  }

  emxFree_real_T(&rowindex);
  emxInit_creal_T(&c_window, 2);

  /*  Apply the window to the array of offset signal segments. */
  /*  USE FFT */
  /*  now fft y which does the columns */
  cdiff = b_window->size[0];
  i12 = c_window->size[0] * c_window->size[1];
  c_window->size[0] = cdiff;
  c_window->size[1] = (int)ncol;
  emxEnsureCapacity((emxArray__common *)c_window, i12, (int)sizeof(creal_T));
  nm1d2 = (int)ncol;
  for (i12 = 0; i12 < nm1d2; i12++) {
    for (n = 0; n < cdiff; n++) {
      absb = r15->data[n + r15->size[0] * i12];
      c_window->data[n + c_window->size[0] * i12].re = b_window->data[n] * absb;
      c_window->data[n + c_window->size[0] * i12].im = b_window->data[n] * 0.0;
    }
  }

  emxFree_real_T(&r15);
  emxFree_real_T(&b_window);
  emxInit_real_T1(&c_x, 1);
  fft(c_window, nfft, yo);
  i12 = c_x->size[0];
  c_x->size[0] = b_x->size[0];
  emxEnsureCapacity((emxArray__common *)c_x, i12, (int)sizeof(double));
  cdiff = b_x->size[0];
  emxFree_creal_T(&c_window);
  for (i12 = 0; i12 < cdiff; i12++) {
    c_x->data[i12] = 0.0;
  }

  emxFree_real_T(&b_x);
  d_x = any(c_x);
  emxFree_real_T(&c_x);
  if (!!!d_x) {
    /*  x purely real */
    if (rt_remd_snf(nfft, 2.0) != 0.0) {
      /*  nfft odd */
      b_y = (nfft + 1.0) / 2.0;
      if (rtIsNaN(b_y)) {
        n = 1;
        anew = rtNaN;
        apnd = b_y;
      } else if (b_y < 1.0) {
        n = 0;
        anew = 1.0;
        apnd = b_y;
      } else if (rtIsInf(b_y)) {
        n = 1;
        anew = rtNaN;
        apnd = b_y;
      } else {
        anew = 1.0;
        ndbl = floor((b_y - 1.0) + 0.5);
        apnd = 1.0 + ndbl;
        b_cdiff = (1.0 + ndbl) - b_y;
        if (fabs(b_cdiff) < 4.4408920985006262E-16 * b_y) {
          ndbl++;
          apnd = b_y;
        } else if (b_cdiff > 0.0) {
          apnd = 1.0 + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          n = (int)ndbl;
        } else {
          n = 0;
        }
      }

      i12 = colindex->size[0] * colindex->size[1];
      colindex->size[0] = 1;
      colindex->size[1] = n;
      emxEnsureCapacity((emxArray__common *)colindex, i12, (int)sizeof(double));
      if (n > 0) {
        colindex->data[0] = anew;
        if (n > 1) {
          colindex->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (cdiff = 1; cdiff < nm1d2; cdiff++) {
            colindex->data[cdiff] = anew + (double)cdiff;
            colindex->data[(n - cdiff) - 1] = apnd - (double)cdiff;
          }

          if (nm1d2 << 1 == n - 1) {
            colindex->data[nm1d2] = (anew + apnd) / 2.0;
          } else {
            colindex->data[nm1d2] = anew + (double)nm1d2;
            colindex->data[nm1d2 + 1] = apnd - (double)nm1d2;
          }
        }
      }
    } else {
      b_y = nfft / 2.0;
      absb = nfft / 2.0 + 1.0;
      if (rtIsNaN(absb)) {
        n = 1;
        anew = rtNaN;
        apnd = b_y + 1.0;
      } else if (b_y + 1.0 < 1.0) {
        n = 0;
        anew = 1.0;
        apnd = b_y + 1.0;
      } else if (rtIsInf(absb)) {
        n = 1;
        anew = rtNaN;
        apnd = b_y + 1.0;
      } else {
        anew = 1.0;
        ndbl = floor((absb - 1.0) + 0.5);
        apnd = 1.0 + ndbl;
        b_cdiff = (1.0 + ndbl) - (b_y + 1.0);
        absb = fabs(b_y + 1.0);
        if ((1.0 >= absb) || rtIsNaN(absb)) {
          absb = 1.0;
        }

        if (fabs(b_cdiff) < 4.4408920985006262E-16 * absb) {
          ndbl++;
          apnd = b_y + 1.0;
        } else if (b_cdiff > 0.0) {
          apnd = 1.0 + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          n = (int)ndbl;
        } else {
          n = 0;
        }
      }

      i12 = colindex->size[0] * colindex->size[1];
      colindex->size[0] = 1;
      colindex->size[1] = n;
      emxEnsureCapacity((emxArray__common *)colindex, i12, (int)sizeof(double));
      if (n > 0) {
        colindex->data[0] = anew;
        if (n > 1) {
          colindex->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (cdiff = 1; cdiff < nm1d2; cdiff++) {
            colindex->data[cdiff] = anew + (double)cdiff;
            colindex->data[(n - cdiff) - 1] = apnd - (double)cdiff;
          }

          if (nm1d2 << 1 == n - 1) {
            colindex->data[nm1d2] = (anew + apnd) / 2.0;
          } else {
            colindex->data[nm1d2] = anew + (double)nm1d2;
            colindex->data[nm1d2 + 1] = apnd - (double)nm1d2;
          }
        }
      }
    }

    emxInit_creal_T(&b_yo, 2);
    nm1d2 = colindex->size[1];
    cdiff = yo->size[1];
    i12 = b_yo->size[0] * b_yo->size[1];
    b_yo->size[0] = nm1d2;
    b_yo->size[1] = cdiff;
    emxEnsureCapacity((emxArray__common *)b_yo, i12, (int)sizeof(creal_T));
    for (i12 = 0; i12 < cdiff; i12++) {
      for (n = 0; n < nm1d2; n++) {
        b_yo->data[n + b_yo->size[0] * i12] = yo->data[((int)colindex->data[n] +
          yo->size[0] * i12) - 1];
      }
    }

    i12 = yo->size[0] * yo->size[1];
    yo->size[0] = b_yo->size[0];
    yo->size[1] = b_yo->size[1];
    emxEnsureCapacity((emxArray__common *)yo, i12, (int)sizeof(creal_T));
    cdiff = b_yo->size[1];
    for (i12 = 0; i12 < cdiff; i12++) {
      nm1d2 = b_yo->size[0];
      for (n = 0; n < nm1d2; n++) {
        yo->data[n + yo->size[0] * i12] = b_yo->data[n + b_yo->size[0] * i12];
      }
    }

    emxFree_creal_T(&b_yo);
  }

  emxFree_real_T(&colindex);

  /*  take abs, and use image to display results */
  /*  if nargout == 0 */
  /*      newplot; */
  /*      if length(t)==1 */
  /*          imagesc([0 1/f(2)],f,20*log10(abs(y)+eps));axis xy; colormap(jet) */
  /*      else */
  /*          imagesc(t,f,20*log10(abs(y)+eps));axis xy; colormap(jet) */
  /*      end */
  /*      xlabel('Time') */
  /*      ylabel('Frequency') */
  /*  function [msg,x,nfft,Fs,window,noverlap] = specgramchk(P) */
  /*  %SPECGRAMCHK Helper function for SPECGRAM. */
  /*  %   SPECGRAMCHK(P) takes the cell array P and uses each cell as  */
  /*  %   an input argument.  Assumes P has between 1 and 5 elements. */
  /*   */
  /*  msg = []; */
  /*   */
  /*  x = P{1};  */
  /*  if (length(P) > 1) & ~isempty(P{2}) */
  /*      nfft = P{2}; */
  /*  else */
  /*      nfft = min(length(x),256); */
  /*  end */
  /*  if (length(P) > 2) & ~isempty(P{3}) */
  /*      Fs = P{3}; */
  /*  else */
  /*      Fs = 2; */
  /*  end */
  /*  if length(P) > 3 & ~isempty(P{4}) */
  /*      window = P{4};  */
  /*  else */
  /*      if length(nfft) == 1 */
  /*          window = hanning(nfft); */
  /*      else */
  /*          msg = 'You must specify a window function.'; */
  /*      end */
  /*  end */
  /*  if length(window) == 1, window = hanning(window); end */
  /*  if (length(P) > 4) & ~isempty(P{5}) */
  /*      noverlap = P{5}; */
  /*  else */
  /*      noverlap = ceil(length(window)/2); */
  /*  end */
  /*   */
  /*  % NOW do error checking */
  /*  if (length(nfft)==1) & (nfft<length(window)),  */
  /*      msg = 'Requires window''s length to be no greater than the FFT length.'; */
  /*  end */
  /*  if (noverlap >= length(window)), */
  /*      msg = 'Requires NOVERLAP to be strictly less than the window length.'; */
  /*  end */
  /*  if (length(nfft)==1) & (nfft ~= abs(round(nfft))) */
  /*      msg = 'Requires positive integer values for NFFT.'; */
  /*  end */
  /*  if (noverlap ~= abs(round(noverlap))), */
  /*      msg = 'Requires positive integer value for NOVERLAP.'; */
  /*  end */
  /*  if min(size(x))~=1, */
  /*      msg = 'Requires vector (either row or column) input.'; */
  /*  end */
  /*  end */
}

/*
 * File trailer for Myspecgram.c
 *
 * [EOF]
 */
