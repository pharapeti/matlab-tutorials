/*
 * File: xzgghrd.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "xzgghrd.h"
#include "xzlartg.h"

/* Function Definitions */

/*
 * Arguments    : int ilo
 *                int ihi
 *                creal_T A[9]
 *                creal_T B[9]
 *                creal_T Z[9]
 * Return Type  : void
 */
void xzgghrd(int ilo, int ihi, creal_T A[9], creal_T B[9], creal_T Z[9])
{
  int jcol;
  signed char I[9];
  int jrow;
  double c;
  creal_T s;
  double stemp_re;
  double stemp_im;
  double A_im;
  double A_re;
  for (jcol = 0; jcol < 9; jcol++) {
    I[jcol] = 0;
  }

  for (jcol = 0; jcol < 3; jcol++) {
    I[jcol + 3 * jcol] = 1;
  }

  for (jcol = 0; jcol < 9; jcol++) {
    Z[jcol].re = I[jcol];
    Z[jcol].im = 0.0;
  }

  for (jcol = ilo; jcol < ihi; jcol++) {
    for (jrow = jcol; jrow + 1 <= ihi; jrow++) {
      B[jrow + 3 * (jcol - 1)].re = 0.0;
      B[jrow + 3 * (jcol - 1)].im = 0.0;
    }
  }

  if (!(ihi < ilo + 2)) {
    jcol = ilo;
    while (jcol < 2) {
      xzlartg(A[1], A[2], &c, &s, &A[1]);
      A[2].re = 0.0;
      A[2].im = 0.0;
      for (jcol = 0; jcol < 2; jcol++) {
        stemp_re = c * A[1 + 3 * (jcol + 1)].re + (s.re * A[2 + 3 * (jcol + 1)].
          re - s.im * A[2 + 3 * (jcol + 1)].im);
        stemp_im = c * A[1 + 3 * (jcol + 1)].im + (s.re * A[2 + 3 * (jcol + 1)].
          im + s.im * A[2 + 3 * (jcol + 1)].re);
        A_im = A[1 + 3 * (jcol + 1)].im;
        A_re = A[1 + 3 * (jcol + 1)].re;
        A[2 + 3 * (jcol + 1)].re = c * A[2 + 3 * (jcol + 1)].re - (s.re * A[1 +
          3 * (jcol + 1)].re + s.im * A[1 + 3 * (jcol + 1)].im);
        A[2 + 3 * (jcol + 1)].im = c * A[2 + 3 * (jcol + 1)].im - (s.re * A_im -
          s.im * A_re);
        A[1 + 3 * (jcol + 1)].re = stemp_re;
        A[1 + 3 * (jcol + 1)].im = stemp_im;
      }

      for (jcol = 0; jcol < 2; jcol++) {
        stemp_re = c * B[1 + 3 * (jcol + 1)].re + (s.re * B[2 + 3 * (jcol + 1)].
          re - s.im * B[2 + 3 * (jcol + 1)].im);
        stemp_im = c * B[1 + 3 * (jcol + 1)].im + (s.re * B[2 + 3 * (jcol + 1)].
          im + s.im * B[2 + 3 * (jcol + 1)].re);
        A_im = B[1 + 3 * (jcol + 1)].im;
        A_re = B[1 + 3 * (jcol + 1)].re;
        B[2 + 3 * (jcol + 1)].re = c * B[2 + 3 * (jcol + 1)].re - (s.re * B[1 +
          3 * (jcol + 1)].re + s.im * B[1 + 3 * (jcol + 1)].im);
        B[2 + 3 * (jcol + 1)].im = c * B[2 + 3 * (jcol + 1)].im - (s.re * A_im -
          s.im * A_re);
        B[1 + 3 * (jcol + 1)].re = stemp_re;
        B[1 + 3 * (jcol + 1)].im = stemp_im;
      }

      xzlartg(B[8], B[5], &c, &s, &B[8]);
      B[5].re = 0.0;
      B[5].im = 0.0;
      for (jcol = 0; jcol < 2; jcol++) {
        stemp_re = c * B[6 + jcol].re + (s.re * B[3 + jcol].re - s.im * B[3 +
          jcol].im);
        stemp_im = c * B[6 + jcol].im + (s.re * B[3 + jcol].im + s.im * B[3 +
          jcol].re);
        A_im = B[6 + jcol].im;
        A_re = B[6 + jcol].re;
        B[3 + jcol].re = c * B[3 + jcol].re - (s.re * B[6 + jcol].re + s.im * B
          [6 + jcol].im);
        B[3 + jcol].im = c * B[3 + jcol].im - (s.re * A_im - s.im * A_re);
        B[6 + jcol].re = stemp_re;
        B[6 + jcol].im = stemp_im;
      }

      for (jcol = 0; jcol < 3; jcol++) {
        stemp_re = c * A[6 + jcol].re + (s.re * A[3 + jcol].re - s.im * A[3 +
          jcol].im);
        stemp_im = c * A[6 + jcol].im + (s.re * A[3 + jcol].im + s.im * A[3 +
          jcol].re);
        A_im = A[6 + jcol].im;
        A_re = A[6 + jcol].re;
        A[3 + jcol].re = c * A[3 + jcol].re - (s.re * A[6 + jcol].re + s.im * A
          [6 + jcol].im);
        A[3 + jcol].im = c * A[3 + jcol].im - (s.re * A_im - s.im * A_re);
        A[6 + jcol].re = stemp_re;
        A[6 + jcol].im = stemp_im;
      }

      for (jcol = 0; jcol < 3; jcol++) {
        stemp_re = c * Z[6 + jcol].re + (s.re * Z[3 + jcol].re - s.im * Z[3 +
          jcol].im);
        stemp_im = c * Z[6 + jcol].im + (s.re * Z[3 + jcol].im + s.im * Z[3 +
          jcol].re);
        A_im = Z[6 + jcol].re;
        Z[3 + jcol].re = c * Z[3 + jcol].re - (s.re * Z[6 + jcol].re + s.im * Z
          [6 + jcol].im);
        Z[3 + jcol].im = c * Z[3 + jcol].im - (s.re * Z[6 + jcol].im - s.im *
          A_im);
        Z[6 + jcol].re = stemp_re;
        Z[6 + jcol].im = stemp_im;
      }

      jcol = 2;
    }
  }
}

/*
 * File trailer for xzgghrd.c
 *
 * [EOF]
 */
