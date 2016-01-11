/*
 * xtrsm.c
 *
 * Code generation for function 'xtrsm'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "xtrsm.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
void b_xtrsm(const real_T A[5776], real_T B[76])
{
  real_T alpha1;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  alpha1 = 1.0;
  DIAGA = 'N';
  TRANSA = 'N';
  UPLO = 'U';
  SIDE = 'L';
  m_t = (ptrdiff_t)76;
  n_t = (ptrdiff_t)1;
  lda_t = (ptrdiff_t)76;
  ldb_t = (ptrdiff_t)76;
  dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &alpha1, &A[0], &lda_t, &B[0],
        &ldb_t);
}

/*
 *
 */
void xtrsm(const real_T A[5776], real_T B[76])
{
  real_T alpha1;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  alpha1 = 1.0;
  DIAGA = 'U';
  TRANSA = 'N';
  UPLO = 'L';
  SIDE = 'L';
  m_t = (ptrdiff_t)76;
  n_t = (ptrdiff_t)1;
  lda_t = (ptrdiff_t)76;
  ldb_t = (ptrdiff_t)76;
  dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &alpha1, &A[0], &lda_t, &B[0],
        &ldb_t);
}

/* End of code generation (xtrsm.c) */
