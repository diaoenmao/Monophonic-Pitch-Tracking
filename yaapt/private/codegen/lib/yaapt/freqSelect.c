/*
 * File: freqSelect.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2016 23:38:40
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "freqSelect.h"
#include "yaapt_emxutil.h"
#include "rdivide.h"

/* Function Definitions */

/*
 * KEYSELECT Determine input fq as piano key
 *
 *  fq = input frequency
 *  key{i} = output string denotes piano key, a cell array
 *
 *  upper limit is 1000 Hz, 7450 cents, B4 at 7400 cents
 *  lower limit is 65.4064 Hz, 2650 cents, C2 at 2700 cents
 *  key example format:
 *  ... B2 C3 C#3Db3 D3 D#3Eb3 E3 F3 F#3Gb3 G3 G#3Ab3 A3 A#3Bb3 B3 C4 ...
 *  Ex:
 *  >> key = keySelect(200)
 *  cnt = 4.6350e+03
 *  key = 'G3' (1x1 cell)
 * Arguments    : const emxArray_real_T *fq
 *                emxArray_real_T *freq
 *                emxArray_real_T *cent
 * Return Type  : void
 */
void freqSelect(const emxArray_real_T *fq, emxArray_real_T *freq,
                emxArray_real_T *cent)
{
  emxArray_real_T *cnt;
  emxArray_real_T *x;
  int b_cnt;
  int ub_loop;
  int k;
  int b_k;
  double fdbl;
  int eint;
  int inte;
  int i;
  emxInit_real_T(&cnt, 2);
  emxInit_real_T(&x, 2);

  /*  FQ2CNT Transform input frequency to cent unit */
  /*  */
  /*  fq = input frequency */
  /*  cnt = output cent scale with base at 13.75 Hz */
  /*  Each piano key frequency is linearly separated 100 cents  */
  /*  Ex: A4 - Ab4 */
  /*  fq2cnt(440) - fq2cnt(415.305) = 6000 - 5900 = 100 */
  /*  */
  c_rdivide(fq, 13.75, x);
  b_cnt = cnt->size[0] * cnt->size[1];
  cnt->size[0] = 1;
  cnt->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)cnt, b_cnt, (int)sizeof(double));
  ub_loop = x->size[1];

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(b_k,fdbl,inte) \
 firstprivate(eint)

  for (k = 1; k <= ub_loop; k++) {
    b_k = k;
    if (x->data[b_k - 1] == 0.0) {
      fdbl = rtMinusInf;
    } else if (x->data[b_k - 1] < 0.0) {
      fdbl = rtNaN;
    } else if ((!rtIsInf(x->data[b_k - 1])) && (!rtIsNaN(x->data[b_k - 1]))) {
      if ((!rtIsInf(x->data[b_k - 1])) && (!rtIsNaN(x->data[b_k - 1]))) {
        fdbl = frexp(x->data[b_k - 1], &eint);
        inte = eint;
      } else {
        fdbl = x->data[b_k - 1];
        inte = 0;
      }

      if (fdbl == 0.5) {
        fdbl = (double)inte - 1.0;
      } else {
        fdbl = log(fdbl) / 0.69314718055994529 + (double)inte;
      }
    } else {
      fdbl = x->data[b_k - 1];
    }

    cnt->data[b_k - 1] = fdbl;
  }

  emxFree_real_T(&x);
  b_cnt = cnt->size[0] * cnt->size[1];
  cnt->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)cnt, b_cnt, (int)sizeof(double));
  ub_loop = cnt->size[0];
  b_cnt = cnt->size[1];
  ub_loop *= b_cnt;
  for (b_cnt = 0; b_cnt < ub_loop; b_cnt++) {
    cnt->data[b_cnt] *= 1200.0;
  }

  /*  key = cell(1,length(cnt)); */
  b_cnt = cent->size[0] * cent->size[1];
  cent->size[0] = 1;
  cent->size[1] = cnt->size[1];
  emxEnsureCapacity((emxArray__common *)cent, b_cnt, (int)sizeof(double));
  ub_loop = cnt->size[1];
  for (b_cnt = 0; b_cnt < ub_loop; b_cnt++) {
    cent->data[b_cnt] = 0.0;
  }

  b_cnt = freq->size[0] * freq->size[1];
  freq->size[0] = 1;
  freq->size[1] = cnt->size[1];
  emxEnsureCapacity((emxArray__common *)freq, b_cnt, (int)sizeof(double));
  ub_loop = cnt->size[1];
  for (b_cnt = 0; b_cnt < ub_loop; b_cnt++) {
    freq->data[b_cnt] = 0.0;
  }

  for (i = 0; i < cnt->size[1]; i++) {
    if ((cnt->data[i] > 5050.0) && (cnt->data[i] <= 7450.0)) {
      if (cnt->data[i] > 6250.0) {
        if (cnt->data[i] > 6850.0) {
          if (cnt->data[i] > 7150.0) {
            if (cnt->data[i] > 7250.0) {
              if (cnt->data[i] > 7350.0) {
                freq->data[i] = 987.767;

                /*  7400 */
                cent->data[i] = 7400.0;
              } else {
                freq->data[i] = 932.328;

                /*  7300   */
                cent->data[i] = 7300.0;
              }
            } else {
              freq->data[i] = 880.0;

              /*  7200    */
              cent->data[i] = 7200.0;
            }
          } else if (cnt->data[i] > 7050.0) {
            freq->data[i] = 830.609;

            /*  7100  */
            cent->data[i] = 7100.0;
          } else if (cnt->data[i] > 6950.0) {
            freq->data[i] = 783.991;

            /*  7000     */
            cent->data[i] = 7000.0;
          } else {
            freq->data[i] = 739.989;

            /*  6900     */
            cent->data[i] = 6900.0;
          }
        } else if (cnt->data[i] > 6550.0) {
          if (cnt->data[i] > 6750.0) {
            freq->data[i] = 698.456;

            /*  6800 */
            cent->data[i] = 6800.0;
          } else if (cnt->data[i] > 6650.0) {
            freq->data[i] = 659.255;

            /*  6700 */
            cent->data[i] = 6700.0;
          } else {
            freq->data[i] = 622.254;

            /*  6600        */
            cent->data[i] = 6600.0;
          }
        } else if (cnt->data[i] > 6450.0) {
          freq->data[i] = 587.33;

          /*  6500     */
          cent->data[i] = 6500.0;
        } else if (cnt->data[i] > 6350.0) {
          freq->data[i] = 554.365;

          /*  6400   */
          cent->data[i] = 6400.0;
        } else {
          freq->data[i] = 523.251;

          /*  6300       */
          cent->data[i] = 6300.0;
        }
      } else if (cnt->data[i] > 5650.0) {
        if (cnt->data[i] > 5950.0) {
          if (cnt->data[i] > 6150.0) {
            freq->data[i] = 493.883;

            /*  6200  */
            cent->data[i] = 6200.0;
          } else if (cnt->data[i] > 6050.0) {
            freq->data[i] = 466.164;

            /*  6100  */
            cent->data[i] = 6100.0;
          } else {
            freq->data[i] = 440.0;

            /*  6000 */
            cent->data[i] = 6000.0;
          }
        } else if (cnt->data[i] > 5850.0) {
          freq->data[i] = 415.305;

          /*  5900  */
          cent->data[i] = 5900.0;
        } else if (cnt->data[i] > 5750.0) {
          freq->data[i] = 391.995;

          /*  5800  */
          cent->data[i] = 5800.0;
        } else {
          freq->data[i] = 369.994;

          /*  5700 */
          cent->data[i] = 5700.0;
        }
      } else if (cnt->data[i] > 5350.0) {
        if (cnt->data[i] > 5550.0) {
          freq->data[i] = 349.228;

          /*  5600  */
          cent->data[i] = 5600.0;
        } else if (cnt->data[i] > 5450.0) {
          freq->data[i] = 329.628;

          /*  5500  */
          cent->data[i] = 5500.0;
        } else {
          freq->data[i] = 311.127;

          /*  5400  */
          cent->data[i] = 5400.0;
        }
      } else if (cnt->data[i] > 5250.0) {
        freq->data[i] = 293.665;

        /*  5300  */
        cent->data[i] = 5300.0;
      } else if (cnt->data[i] > 5150.0) {
        freq->data[i] = 277.183;

        /*  5200  */
        cent->data[i] = 5200.0;
      } else {
        freq->data[i] = 261.626;

        /*  5100   */
        cent->data[i] = 5100.0;
      }
    } else if ((cnt->data[i] <= 5050.0) && (cnt->data[i] > 2650.0)) {
      if (cnt->data[i] > 3850.0) {
        if (cnt->data[i] > 4450.0) {
          if (cnt->data[i] > 4750.0) {
            if (cnt->data[i] > 4950.0) {
              freq->data[i] = 246.942;

              /*  5000   */
              cent->data[i] = 5000.0;
            } else if (cnt->data[i] > 4850.0) {
              freq->data[i] = 233.082;

              /*  4900 */
              cent->data[i] = 4900.0;
            } else {
              freq->data[i] = 220.0;

              /*  4800   */
              cent->data[i] = 4800.0;
            }
          } else if (cnt->data[i] > 4650.0) {
            freq->data[i] = 207.652;

            /*  4700  */
            cent->data[i] = 4700.0;
          } else if (cnt->data[i] > 4550.0) {
            freq->data[i] = 195.998;

            /*  4600  */
            cent->data[i] = 4600.0;
          } else {
            freq->data[i] = 184.997;

            /*  4500 */
            cent->data[i] = 4500.0;
          }
        } else if (cnt->data[i] > 4150.0) {
          if (cnt->data[i] > 4350.0) {
            freq->data[i] = 174.614;

            /*  4400  */
            cent->data[i] = 4400.0;
          } else if (cnt->data[i] > 4250.0) {
            freq->data[i] = 164.814;

            /*  4300 */
            cent->data[i] = 4300.0;
          } else {
            freq->data[i] = 155.563;

            /*  4200 */
            cent->data[i] = 4200.0;
          }
        } else if (cnt->data[i] > 4050.0) {
          freq->data[i] = 146.832;

          /*  4100  */
          cent->data[i] = 4100.0;
        } else if (cnt->data[i] > 3950.0) {
          freq->data[i] = 138.591;

          /*  4000  */
          cent->data[i] = 4000.0;
        } else {
          freq->data[i] = 130.813;

          /*  3900 */
          cent->data[i] = 3900.0;
        }
      } else if (cnt->data[i] > 3250.0) {
        if (cnt->data[i] > 3550.0) {
          if (cnt->data[i] > 3750.0) {
            freq->data[i] = 123.471;

            /*  3800 */
            cent->data[i] = 3800.0;
          } else if (cnt->data[i] > 3650.0) {
            freq->data[i] = 116.541;

            /*  3700     */
            cent->data[i] = 3700.0;
          } else {
            freq->data[i] = 110.0;

            /*  3600 */
            cent->data[i] = 3600.0;
          }
        } else if (cnt->data[i] > 3450.0) {
          freq->data[i] = 103.826;

          /*  3500  */
          cent->data[i] = 3500.0;
        } else if (cnt->data[i] > 3350.0) {
          freq->data[i] = 97.9989;

          /*  3400 */
          cent->data[i] = 3400.0;
        } else {
          freq->data[i] = 92.4986;

          /*  3300  */
          cent->data[i] = 3300.0;
        }
      } else if (cnt->data[i] > 2950.0) {
        if (cnt->data[i] > 3150.0) {
          freq->data[i] = 87.3071;

          /*  3200  */
          cent->data[i] = 3200.0;
        } else if (cnt->data[i] > 3050.0) {
          freq->data[i] = 82.4069;

          /*  3100    */
          cent->data[i] = 3100.0;
        } else {
          freq->data[i] = 77.7817;

          /*  3000  */
          cent->data[i] = 3000.0;
        }
      } else if (cnt->data[i] > 2850.0) {
        freq->data[i] = 73.4162;

        /*  2900 */
        cent->data[i] = 2900.0;
      } else if (cnt->data[i] > 2750.0) {
        freq->data[i] = 69.2957;

        /*  2800   */
        cent->data[i] = 2800.0;
      } else {
        freq->data[i] = 65.4064;

        /*  2700   */
        cent->data[i] = 2700.0;
      }
    } else {
      cent->data[i] = 0.0;

      /*          display('input frequency out of range, range is from 65 Hz to 1000 Hz'); */
    }
  }

  emxFree_real_T(&cnt);
}

/*
 * File trailer for freqSelect.c
 *
 * [EOF]
 */
