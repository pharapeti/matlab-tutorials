/*
 * File: xzhgeqz.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "xzhgeqz.h"
#include "xzlartg.h"
#include "sqrt.h"
#include "mod.h"
#include "xzlanhs.h"
#include "bh_MY_CV_ALGORITHMS_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : creal_T A[9]
 *                creal_T B[9]
 *                int ilo
 *                int ihi
 *                creal_T Z[9]
 *                int *info
 *                creal_T alpha1[3]
 *                creal_T beta1[3]
 * Return Type  : void
 */
void xzhgeqz(creal_T A[9], creal_T B[9], int ilo, int ihi, creal_T Z[9], int
             *info, creal_T alpha1[3], creal_T beta1[3])
{
  int i;
  double eshift_re;
  double eshift_im;
  creal_T ctemp;
  double anorm;
  double temp2;
  double b_atol;
  double ascale;
  double btol;
  double bscale;
  boolean_T failed;
  int j;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  double ar;
  int ifirst;
  double ai;
  int istart;
  int ilast;
  double B_re;
  int ilastm1;
  double B_im;
  int iiter;
  int jp1;
  boolean_T goto50;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  int jiter;
  int exitg1;
  boolean_T ilazro;
  boolean_T exitg2;
  double tempr;
  creal_T shift;
  creal_T b_ascale;
  boolean_T ilazr2;
  double stemp_re;
  double stemp_im;
  int jchm1;
  boolean_T exitg3;
  double brm;
  double ad22_re;
  double ad22_im;
  double abi22_re;
  double abi22_im;
  double t1_re;
  double t1_im;
  *info = 0;
  for (i = 0; i < 3; i++) {
    alpha1[i].re = 0.0;
    alpha1[i].im = 0.0;
    beta1[i].re = 1.0;
    beta1[i].im = 0.0;
  }

  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  anorm = xzlanhs(A, ilo, ihi);
  temp2 = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (temp2 > 2.2250738585072014E-308) {
    b_atol = temp2;
  }

  temp2 = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    temp2 = anorm;
  }

  ascale = 1.0 / temp2;
  anorm = xzlanhs(B, ilo, ihi);
  temp2 = 2.2204460492503131E-16 * anorm;
  btol = 2.2250738585072014E-308;
  if (temp2 > 2.2250738585072014E-308) {
    btol = temp2;
  }

  temp2 = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    temp2 = anorm;
  }

  bscale = 1.0 / temp2;
  failed = true;
  for (j = ihi; j + 1 < 4; j++) {
    anorm = rt_hypotd_snf(B[j + 3 * j].re, B[j + 3 * j].im);
    if (anorm > 2.2250738585072014E-308) {
      ar = B[j + 3 * j].re;
      ai = B[j + 3 * j].im;
      if (ai == 0.0) {
        B_re = ar / anorm;
        B_im = 0.0;
      } else if (ar == 0.0) {
        B_re = 0.0;
        B_im = ai / anorm;
      } else {
        B_re = ar / anorm;
        B_im = ai / anorm;
      }

      B[j + 3 * j].re = anorm;
      B[j + 3 * j].im = 0.0;
      for (jp1 = 0; jp1 + 1 <= j; jp1++) {
        anorm = B[jp1 + 3 * j].re;
        temp2 = B[jp1 + 3 * j].im;
        B[jp1 + 3 * j].re = anorm * B_re - temp2 * -B_im;
        B[jp1 + 3 * j].im = anorm * -B_im + temp2 * B_re;
      }

      for (jp1 = 0; jp1 + 1 <= j + 1; jp1++) {
        temp2 = A[jp1 + 3 * j].re;
        anorm = A[jp1 + 3 * j].im;
        A[jp1 + 3 * j].re = temp2 * B_re - anorm * -B_im;
        A[jp1 + 3 * j].im = temp2 * -B_im + anorm * B_re;
      }

      for (jp1 = 0; jp1 < 3; jp1++) {
        temp2 = Z[jp1 + 3 * j].re;
        anorm = Z[jp1 + 3 * j].im;
        Z[jp1 + 3 * j].re = temp2 * B_re - anorm * -B_im;
        Z[jp1 + 3 * j].im = temp2 * -B_im + anorm * B_re;
      }
    } else {
      B[j + 3 * j].re = 0.0;
      B[j + 3 * j].im = 0.0;
    }

    beta1[j] = B[j + 3 * j];
    alpha1[j] = A[j + 3 * j];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    ifirst = ilo - 1;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    iiter = 0;
    goto50 = false;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 1;
    do {
      exitg1 = 0;
      if (jiter <= 30 * ((ihi - ilo) + 1)) {
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else if (fabs(A[ilast + 3 * ilastm1].re) + fabs(A[ilast + 3 * ilastm1]
                    .im) <= b_atol) {
          A[ilast + 3 * ilastm1].re = 0.0;
          A[ilast + 3 * ilastm1].im = 0.0;
          goto60 = true;
        } else if (rt_hypotd_snf(B[ilast + 3 * ilast].re, B[ilast + 3 * ilast].
                    im) <= btol) {
          B[ilast + 3 * ilast].re = 0.0;
          B[ilast + 3 * ilast].im = 0.0;
          goto50 = true;
        } else {
          j = ilastm1;
          jp1 = ilastm1 + 1;
          exitg2 = false;
          while ((!exitg2) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              ilazro = true;
            } else if (fabs(A[j + 3 * (j - 1)].re) + fabs(A[j + 3 * (j - 1)].im)
                       <= b_atol) {
              A[j + 3 * (j - 1)].re = 0.0;
              A[j + 3 * (j - 1)].im = 0.0;
              ilazro = true;
            } else {
              ilazro = false;
            }

            if (rt_hypotd_snf(B[j + 3 * j].re, B[j + 3 * j].im) < btol) {
              B[j + 3 * j].re = 0.0;
              B[j + 3 * j].im = 0.0;
              if ((!ilazro) && ((fabs(A[j + 3 * (j - 1)].re) + fabs(A[j + 3 * (j
                      - 1)].im)) * (ascale * (fabs(A[jp1 + 3 * j].re) + fabs
                     (A[jp1 + 3 * j].im))) <= (fabs(A[j + 3 * j].re) + fabs(A[j
                     + 3 * j].im)) * (ascale * b_atol))) {
                ilazr2 = true;
              } else {
                ilazr2 = false;
              }

              if (ilazro || ilazr2) {
                jchm1 = j - 1;
                exitg3 = false;
                while ((!exitg3) && (j + 1 < ilast + 1)) {
                  xzlartg(A[j + 3 * j], A[(j + 3 * j) + 1], &tempr, &shift, &A[j
                          + 3 * j]);
                  A[(j + 3 * j) + 1].re = 0.0;
                  A[(j + 3 * j) + 1].im = 0.0;
                  for (jp1 = j; jp1 + 1 < 4; jp1++) {
                    stemp_re = tempr * A[j + 3 * jp1].re + (shift.re * A[(j + 3 *
                      jp1) + 1].re - shift.im * A[(j + 3 * jp1) + 1].im);
                    stemp_im = tempr * A[j + 3 * jp1].im + (shift.re * A[(j + 3 *
                      jp1) + 1].im + shift.im * A[(j + 3 * jp1) + 1].re);
                    anorm = A[j + 3 * jp1].im;
                    temp2 = A[j + 3 * jp1].re;
                    A[(j + 3 * jp1) + 1].re = tempr * A[(j + 3 * jp1) + 1].re -
                      (shift.re * A[j + 3 * jp1].re + shift.im * A[j + 3 * jp1].
                       im);
                    A[(j + 3 * jp1) + 1].im = tempr * A[(j + 3 * jp1) + 1].im -
                      (shift.re * anorm - shift.im * temp2);
                    A[j + 3 * jp1].re = stemp_re;
                    A[j + 3 * jp1].im = stemp_im;
                  }

                  for (jp1 = j; jp1 + 1 < 4; jp1++) {
                    stemp_re = tempr * B[j + 3 * jp1].re + (shift.re * B[(j + 3 *
                      jp1) + 1].re - shift.im * B[(j + 3 * jp1) + 1].im);
                    stemp_im = tempr * B[j + 3 * jp1].im + (shift.re * B[(j + 3 *
                      jp1) + 1].im + shift.im * B[(j + 3 * jp1) + 1].re);
                    B_im = B[j + 3 * jp1].im;
                    B_re = B[j + 3 * jp1].re;
                    B[(j + 3 * jp1) + 1].re = tempr * B[(j + 3 * jp1) + 1].re -
                      (shift.re * B[j + 3 * jp1].re + shift.im * B[j + 3 * jp1].
                       im);
                    B[(j + 3 * jp1) + 1].im = tempr * B[(j + 3 * jp1) + 1].im -
                      (shift.re * B_im - shift.im * B_re);
                    B[j + 3 * jp1].re = stemp_re;
                    B[j + 3 * jp1].im = stemp_im;
                  }

                  if (ilazr2) {
                    A[j + 3 * jchm1].re *= tempr;
                    A[j + 3 * jchm1].im *= tempr;
                  }

                  ilazr2 = false;
                  if (fabs(B[(j + 3 * (j + 1)) + 1].re) + fabs(B[(j + 3 * (j + 1))
                       + 1].im) >= btol) {
                    if (j + 2 >= ilast + 1) {
                      goto60 = true;
                    } else {
                      ifirst = 1;
                      goto70 = true;
                    }

                    exitg3 = true;
                  } else {
                    B[(j + 3 * (j + 1)) + 1].re = 0.0;
                    B[(j + 3 * (j + 1)) + 1].im = 0.0;
                    jchm1 = j;
                    j++;
                  }
                }

                if (goto60 || goto70) {
                  ilazro = true;
                } else {
                  ilazro = false;
                }

                if (!ilazro) {
                  goto50 = true;
                }
              } else {
                jchm1 = j - 1;
                while (j + 1 < ilast + 1) {
                  xzlartg(B[j + 3 * (j + 1)], B[(j + 3 * (j + 1)) + 1], &tempr,
                          &shift, &B[j + 3 * (j + 1)]);
                  B[(j + 3 * (j + 1)) + 1].re = 0.0;
                  B[(j + 3 * (j + 1)) + 1].im = 0.0;
                  if (j + 1 < 2) {
                    for (jp1 = j + 2; jp1 + 1 < 4; jp1++) {
                      stemp_re = tempr * B[3 * jp1].re + (shift.re * B[(j + 3 *
                        jp1) + 1].re - shift.im * B[(j + 3 * jp1) + 1].im);
                      stemp_im = tempr * B[3 * jp1].im + (shift.re * B[(j + 3 *
                        jp1) + 1].im + shift.im * B[(j + 3 * jp1) + 1].re);
                      B_im = B[3 * jp1].im;
                      B_re = B[3 * jp1].re;
                      B[(j + 3 * jp1) + 1].re = tempr * B[(j + 3 * jp1) + 1].re
                        - (shift.re * B[3 * jp1].re + shift.im * B[3 * jp1].im);
                      B[(j + 3 * jp1) + 1].im = tempr * B[(j + 3 * jp1) + 1].im
                        - (shift.re * B_im - shift.im * B_re);
                      B[3 * jp1].re = stemp_re;
                      B[3 * jp1].im = stemp_im;
                    }
                  }

                  for (jp1 = jchm1; jp1 + 1 < 4; jp1++) {
                    stemp_re = tempr * A[j + 3 * jp1].re + (shift.re * A[(j + 3 *
                      jp1) + 1].re - shift.im * A[(j + 3 * jp1) + 1].im);
                    stemp_im = tempr * A[j + 3 * jp1].im + (shift.re * A[(j + 3 *
                      jp1) + 1].im + shift.im * A[(j + 3 * jp1) + 1].re);
                    anorm = A[j + 3 * jp1].im;
                    temp2 = A[j + 3 * jp1].re;
                    A[(j + 3 * jp1) + 1].re = tempr * A[(j + 3 * jp1) + 1].re -
                      (shift.re * A[j + 3 * jp1].re + shift.im * A[j + 3 * jp1].
                       im);
                    A[(j + 3 * jp1) + 1].im = tempr * A[(j + 3 * jp1) + 1].im -
                      (shift.re * anorm - shift.im * temp2);
                    A[j + 3 * jp1].re = stemp_re;
                    A[j + 3 * jp1].im = stemp_im;
                  }

                  xzlartg(A[(j + 3 * j) + 1], A[(j + 3 * jchm1) + 1], &tempr,
                          &shift, &A[(j + 3 * j) + 1]);
                  A[(j + 3 * jchm1) + 1].re = 0.0;
                  A[(j + 3 * jchm1) + 1].im = 0.0;
                  for (i = 0; i + 1 <= j + 1; i++) {
                    stemp_re = tempr * A[i + 3 * j].re + (shift.re * A[i + 3 *
                      jchm1].re - shift.im * A[i + 3 * jchm1].im);
                    stemp_im = tempr * A[i + 3 * j].im + (shift.re * A[i + 3 *
                      jchm1].im + shift.im * A[i + 3 * jchm1].re);
                    anorm = A[i + 3 * j].im;
                    temp2 = A[i + 3 * j].re;
                    A[i + 3 * jchm1].re = tempr * A[i + 3 * jchm1].re -
                      (shift.re * A[i + 3 * j].re + shift.im * A[i + 3 * j].im);
                    A[i + 3 * jchm1].im = tempr * A[i + 3 * jchm1].im -
                      (shift.re * anorm - shift.im * temp2);
                    A[i + 3 * j].re = stemp_re;
                    A[i + 3 * j].im = stemp_im;
                  }

                  for (i = 0; i + 1 <= jchm1 + 1; i++) {
                    stemp_re = tempr * B[i + 3 * j].re + (shift.re * B[i + 3 *
                      jchm1].re - shift.im * B[i + 3 * jchm1].im);
                    stemp_im = tempr * B[i + 3 * j].im + (shift.re * B[i + 3 *
                      jchm1].im + shift.im * B[i + 3 * jchm1].re);
                    B_im = B[i + 3 * j].im;
                    B_re = B[i + 3 * j].re;
                    B[i + 3 * jchm1].re = tempr * B[i + 3 * jchm1].re -
                      (shift.re * B[i + 3 * j].re + shift.im * B[i + 3 * j].im);
                    B[i + 3 * jchm1].im = tempr * B[i + 3 * jchm1].im -
                      (shift.re * B_im - shift.im * B_re);
                    B[i + 3 * j].re = stemp_re;
                    B[i + 3 * j].im = stemp_im;
                  }

                  for (i = 0; i < 3; i++) {
                    stemp_re = tempr * Z[i + 3 * j].re + (shift.re * Z[i + 3 *
                      jchm1].re - shift.im * Z[i + 3 * jchm1].im);
                    stemp_im = tempr * Z[i + 3 * j].im + (shift.re * Z[i + 3 *
                      jchm1].im + shift.im * Z[i + 3 * jchm1].re);
                    anorm = Z[i + 3 * j].im;
                    temp2 = Z[i + 3 * j].re;
                    Z[i + 3 * jchm1].re = tempr * Z[i + 3 * jchm1].re -
                      (shift.re * Z[i + 3 * j].re + shift.im * Z[i + 3 * j].im);
                    Z[i + 3 * jchm1].im = tempr * Z[i + 3 * jchm1].im -
                      (shift.re * anorm - shift.im * temp2);
                    Z[i + 3 * j].re = stemp_re;
                    Z[i + 3 * j].im = stemp_im;
                  }

                  jchm1 = j;
                  j++;
                }

                goto50 = true;
              }

              exitg2 = true;
            } else if (ilazro) {
              ifirst = j;
              goto70 = true;
              exitg2 = true;
            } else {
              jp1 = j;
              j--;
            }
          }
        }

        if (goto50 || goto60 || goto70) {
          ilazro = true;
        } else {
          ilazro = false;
        }

        if (!ilazro) {
          for (i = 0; i < 3; i++) {
            alpha1[i].re = rtNaN;
            alpha1[i].im = 0.0;
            beta1[i].re = rtNaN;
            beta1[i].im = 0.0;
          }

          for (jp1 = 0; jp1 < 9; jp1++) {
            Z[jp1].re = rtNaN;
            Z[jp1].im = 0.0;
          }

          *info = 1;
          exitg1 = 1;
        } else {
          if (goto50) {
            goto50 = false;
            xzlartg(A[ilast + 3 * ilast], A[ilast + 3 * ilastm1], &tempr, &shift,
                    &A[ilast + 3 * ilast]);
            A[ilast + 3 * ilastm1].re = 0.0;
            A[ilast + 3 * ilastm1].im = 0.0;
            for (i = 0; i + 1 <= ilastm1 + 1; i++) {
              stemp_re = tempr * A[i + 3 * ilast].re + (shift.re * A[i + 3 *
                ilastm1].re - shift.im * A[i + 3 * ilastm1].im);
              stemp_im = tempr * A[i + 3 * ilast].im + (shift.re * A[i + 3 *
                ilastm1].im + shift.im * A[i + 3 * ilastm1].re);
              anorm = A[i + 3 * ilast].im;
              temp2 = A[i + 3 * ilast].re;
              A[i + 3 * ilastm1].re = tempr * A[i + 3 * ilastm1].re - (shift.re *
                A[i + 3 * ilast].re + shift.im * A[i + 3 * ilast].im);
              A[i + 3 * ilastm1].im = tempr * A[i + 3 * ilastm1].im - (shift.re *
                anorm - shift.im * temp2);
              A[i + 3 * ilast].re = stemp_re;
              A[i + 3 * ilast].im = stemp_im;
            }

            for (i = 0; i + 1 <= ilastm1 + 1; i++) {
              stemp_re = tempr * B[i + 3 * ilast].re + (shift.re * B[i + 3 *
                ilastm1].re - shift.im * B[i + 3 * ilastm1].im);
              stemp_im = tempr * B[i + 3 * ilast].im + (shift.re * B[i + 3 *
                ilastm1].im + shift.im * B[i + 3 * ilastm1].re);
              B_im = B[i + 3 * ilast].im;
              B_re = B[i + 3 * ilast].re;
              B[i + 3 * ilastm1].re = tempr * B[i + 3 * ilastm1].re - (shift.re *
                B[i + 3 * ilast].re + shift.im * B[i + 3 * ilast].im);
              B[i + 3 * ilastm1].im = tempr * B[i + 3 * ilastm1].im - (shift.re *
                B_im - shift.im * B_re);
              B[i + 3 * ilast].re = stemp_re;
              B[i + 3 * ilast].im = stemp_im;
            }

            for (i = 0; i < 3; i++) {
              stemp_re = tempr * Z[i + 3 * ilast].re + (shift.re * Z[i + 3 *
                ilastm1].re - shift.im * Z[i + 3 * ilastm1].im);
              stemp_im = tempr * Z[i + 3 * ilast].im + (shift.re * Z[i + 3 *
                ilastm1].im + shift.im * Z[i + 3 * ilastm1].re);
              anorm = Z[i + 3 * ilast].im;
              temp2 = Z[i + 3 * ilast].re;
              Z[i + 3 * ilastm1].re = tempr * Z[i + 3 * ilastm1].re - (shift.re *
                Z[i + 3 * ilast].re + shift.im * Z[i + 3 * ilast].im);
              Z[i + 3 * ilastm1].im = tempr * Z[i + 3 * ilastm1].im - (shift.re *
                anorm - shift.im * temp2);
              Z[i + 3 * ilast].re = stemp_re;
              Z[i + 3 * ilast].im = stemp_im;
            }

            goto60 = true;
          }

          if (goto60) {
            goto60 = false;
            anorm = rt_hypotd_snf(B[ilast + 3 * ilast].re, B[ilast + 3 * ilast].
                                  im);
            if (anorm > 2.2250738585072014E-308) {
              ar = B[ilast + 3 * ilast].re;
              ai = B[ilast + 3 * ilast].im;
              if (ai == 0.0) {
                B_re = ar / anorm;
                B_im = 0.0;
              } else if (ar == 0.0) {
                B_re = 0.0;
                B_im = ai / anorm;
              } else {
                B_re = ar / anorm;
                B_im = ai / anorm;
              }

              B[ilast + 3 * ilast].re = anorm;
              B[ilast + 3 * ilast].im = 0.0;
              for (jp1 = 0; jp1 + 1 <= ilastm1 + 1; jp1++) {
                anorm = B[jp1 + 3 * ilast].re;
                temp2 = B[jp1 + 3 * ilast].im;
                B[jp1 + 3 * ilast].re = anorm * B_re - temp2 * -B_im;
                B[jp1 + 3 * ilast].im = anorm * -B_im + temp2 * B_re;
              }

              for (jp1 = 0; jp1 < 3; jp1++) {
                temp2 = A[jp1 + 3 * ilast].re;
                anorm = A[jp1 + 3 * ilast].im;
                A[jp1 + 3 * ilast].re = temp2 * B_re - anorm * -B_im;
                A[jp1 + 3 * ilast].im = temp2 * -B_im + anorm * B_re;
                temp2 = Z[jp1 + 3 * ilast].re;
                anorm = Z[jp1 + 3 * ilast].im;
                Z[jp1 + 3 * ilast].re = temp2 * B_re - anorm * -B_im;
                Z[jp1 + 3 * ilast].im = temp2 * -B_im + anorm * B_re;
              }
            } else {
              B[ilast + 3 * ilast].re = 0.0;
              B[ilast + 3 * ilast].im = 0.0;
            }

            beta1[ilast] = B[ilast + 3 * ilast];
            alpha1[ilast] = A[ilast + 3 * ilast];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              jiter++;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              if (b_mod(iiter) != 0) {
                ar = ascale * A[ilastm1 + 3 * ilastm1].re;
                ai = ascale * A[ilastm1 + 3 * ilastm1].im;
                B_im = bscale * B[ilastm1 + 3 * ilastm1].re;
                B_re = bscale * B[ilastm1 + 3 * ilastm1].im;
                if (B_re == 0.0) {
                  if (ai == 0.0) {
                    shift.re = ar / B_im;
                    shift.im = 0.0;
                  } else if (ar == 0.0) {
                    shift.re = 0.0;
                    shift.im = ai / B_im;
                  } else {
                    shift.re = ar / B_im;
                    shift.im = ai / B_im;
                  }
                } else if (B_im == 0.0) {
                  if (ar == 0.0) {
                    shift.re = ai / B_re;
                    shift.im = 0.0;
                  } else if (ai == 0.0) {
                    shift.re = 0.0;
                    shift.im = -(ar / B_re);
                  } else {
                    shift.re = ai / B_re;
                    shift.im = -(ar / B_re);
                  }
                } else {
                  brm = fabs(B_im);
                  anorm = fabs(B_re);
                  if (brm > anorm) {
                    temp2 = B_re / B_im;
                    anorm = B_im + temp2 * B_re;
                    shift.re = (ar + temp2 * ai) / anorm;
                    shift.im = (ai - temp2 * ar) / anorm;
                  } else if (anorm == brm) {
                    if (B_im > 0.0) {
                      temp2 = 0.5;
                    } else {
                      temp2 = -0.5;
                    }

                    if (B_re > 0.0) {
                      anorm = 0.5;
                    } else {
                      anorm = -0.5;
                    }

                    shift.re = (ar * temp2 + ai * anorm) / brm;
                    shift.im = (ai * temp2 - ar * anorm) / brm;
                  } else {
                    temp2 = B_im / B_re;
                    anorm = B_re + temp2 * B_im;
                    shift.re = (temp2 * ar + ai) / anorm;
                    shift.im = (temp2 * ai - ar) / anorm;
                  }
                }

                ar = ascale * A[ilast + 3 * ilastm1].re;
                ai = ascale * A[ilast + 3 * ilastm1].im;
                B_im = bscale * B[ilastm1 + 3 * ilastm1].re;
                B_re = bscale * B[ilastm1 + 3 * ilastm1].im;
                if (B_re == 0.0) {
                  if (ai == 0.0) {
                    stemp_re = ar / B_im;
                    stemp_im = 0.0;
                  } else if (ar == 0.0) {
                    stemp_re = 0.0;
                    stemp_im = ai / B_im;
                  } else {
                    stemp_re = ar / B_im;
                    stemp_im = ai / B_im;
                  }
                } else if (B_im == 0.0) {
                  if (ar == 0.0) {
                    stemp_re = ai / B_re;
                    stemp_im = 0.0;
                  } else if (ai == 0.0) {
                    stemp_re = 0.0;
                    stemp_im = -(ar / B_re);
                  } else {
                    stemp_re = ai / B_re;
                    stemp_im = -(ar / B_re);
                  }
                } else {
                  brm = fabs(B_im);
                  anorm = fabs(B_re);
                  if (brm > anorm) {
                    temp2 = B_re / B_im;
                    anorm = B_im + temp2 * B_re;
                    stemp_re = (ar + temp2 * ai) / anorm;
                    stemp_im = (ai - temp2 * ar) / anorm;
                  } else if (anorm == brm) {
                    if (B_im > 0.0) {
                      temp2 = 0.5;
                    } else {
                      temp2 = -0.5;
                    }

                    if (B_re > 0.0) {
                      anorm = 0.5;
                    } else {
                      anorm = -0.5;
                    }

                    stemp_re = (ar * temp2 + ai * anorm) / brm;
                    stemp_im = (ai * temp2 - ar * anorm) / brm;
                  } else {
                    temp2 = B_im / B_re;
                    anorm = B_re + temp2 * B_im;
                    stemp_re = (temp2 * ar + ai) / anorm;
                    stemp_im = (temp2 * ai - ar) / anorm;
                  }
                }

                ar = ascale * A[ilast + 3 * ilast].re;
                ai = ascale * A[ilast + 3 * ilast].im;
                B_im = bscale * B[ilast + 3 * ilast].re;
                B_re = bscale * B[ilast + 3 * ilast].im;
                if (B_re == 0.0) {
                  if (ai == 0.0) {
                    ad22_re = ar / B_im;
                    ad22_im = 0.0;
                  } else if (ar == 0.0) {
                    ad22_re = 0.0;
                    ad22_im = ai / B_im;
                  } else {
                    ad22_re = ar / B_im;
                    ad22_im = ai / B_im;
                  }
                } else if (B_im == 0.0) {
                  if (ar == 0.0) {
                    ad22_re = ai / B_re;
                    ad22_im = 0.0;
                  } else if (ai == 0.0) {
                    ad22_re = 0.0;
                    ad22_im = -(ar / B_re);
                  } else {
                    ad22_re = ai / B_re;
                    ad22_im = -(ar / B_re);
                  }
                } else {
                  brm = fabs(B_im);
                  anorm = fabs(B_re);
                  if (brm > anorm) {
                    temp2 = B_re / B_im;
                    anorm = B_im + temp2 * B_re;
                    ad22_re = (ar + temp2 * ai) / anorm;
                    ad22_im = (ai - temp2 * ar) / anorm;
                  } else if (anorm == brm) {
                    if (B_im > 0.0) {
                      temp2 = 0.5;
                    } else {
                      temp2 = -0.5;
                    }

                    if (B_re > 0.0) {
                      anorm = 0.5;
                    } else {
                      anorm = -0.5;
                    }

                    ad22_re = (ar * temp2 + ai * anorm) / brm;
                    ad22_im = (ai * temp2 - ar * anorm) / brm;
                  } else {
                    temp2 = B_im / B_re;
                    anorm = B_re + temp2 * B_im;
                    ad22_re = (temp2 * ar + ai) / anorm;
                    ad22_im = (temp2 * ai - ar) / anorm;
                  }
                }

                ar = bscale * B[ilastm1 + 3 * ilast].re;
                ai = bscale * B[ilastm1 + 3 * ilast].im;
                B_im = bscale * B[ilast + 3 * ilast].re;
                B_re = bscale * B[ilast + 3 * ilast].im;
                if (B_re == 0.0) {
                  if (ai == 0.0) {
                    tempr = ar / B_im;
                    anorm = 0.0;
                  } else if (ar == 0.0) {
                    tempr = 0.0;
                    anorm = ai / B_im;
                  } else {
                    tempr = ar / B_im;
                    anorm = ai / B_im;
                  }
                } else if (B_im == 0.0) {
                  if (ar == 0.0) {
                    tempr = ai / B_re;
                    anorm = 0.0;
                  } else if (ai == 0.0) {
                    tempr = 0.0;
                    anorm = -(ar / B_re);
                  } else {
                    tempr = ai / B_re;
                    anorm = -(ar / B_re);
                  }
                } else {
                  brm = fabs(B_im);
                  anorm = fabs(B_re);
                  if (brm > anorm) {
                    temp2 = B_re / B_im;
                    anorm = B_im + temp2 * B_re;
                    tempr = (ar + temp2 * ai) / anorm;
                    anorm = (ai - temp2 * ar) / anorm;
                  } else if (anorm == brm) {
                    if (B_im > 0.0) {
                      temp2 = 0.5;
                    } else {
                      temp2 = -0.5;
                    }

                    if (B_re > 0.0) {
                      anorm = 0.5;
                    } else {
                      anorm = -0.5;
                    }

                    tempr = (ar * temp2 + ai * anorm) / brm;
                    anorm = (ai * temp2 - ar * anorm) / brm;
                  } else {
                    temp2 = B_im / B_re;
                    anorm = B_re + temp2 * B_im;
                    tempr = (temp2 * ar + ai) / anorm;
                    anorm = (temp2 * ai - ar) / anorm;
                  }
                }

                abi22_re = ad22_re - (tempr * stemp_re - anorm * stemp_im);
                abi22_im = ad22_im - (tempr * stemp_im + anorm * stemp_re);
                t1_re = 0.5 * (shift.re + abi22_re);
                t1_im = 0.5 * (shift.im + abi22_im);
                ar = ascale * A[ilastm1 + 3 * ilast].re;
                ai = ascale * A[ilastm1 + 3 * ilast].im;
                B_im = bscale * B[ilast + 3 * ilast].re;
                B_re = bscale * B[ilast + 3 * ilast].im;
                if (B_re == 0.0) {
                  if (ai == 0.0) {
                    tempr = ar / B_im;
                    anorm = 0.0;
                  } else if (ar == 0.0) {
                    tempr = 0.0;
                    anorm = ai / B_im;
                  } else {
                    tempr = ar / B_im;
                    anorm = ai / B_im;
                  }
                } else if (B_im == 0.0) {
                  if (ar == 0.0) {
                    tempr = ai / B_re;
                    anorm = 0.0;
                  } else if (ai == 0.0) {
                    tempr = 0.0;
                    anorm = -(ar / B_re);
                  } else {
                    tempr = ai / B_re;
                    anorm = -(ar / B_re);
                  }
                } else {
                  brm = fabs(B_im);
                  anorm = fabs(B_re);
                  if (brm > anorm) {
                    temp2 = B_re / B_im;
                    anorm = B_im + temp2 * B_re;
                    tempr = (ar + temp2 * ai) / anorm;
                    anorm = (ai - temp2 * ar) / anorm;
                  } else if (anorm == brm) {
                    if (B_im > 0.0) {
                      temp2 = 0.5;
                    } else {
                      temp2 = -0.5;
                    }

                    if (B_re > 0.0) {
                      anorm = 0.5;
                    } else {
                      anorm = -0.5;
                    }

                    tempr = (ar * temp2 + ai * anorm) / brm;
                    anorm = (ai * temp2 - ar * anorm) / brm;
                  } else {
                    temp2 = B_im / B_re;
                    anorm = B_re + temp2 * B_im;
                    tempr = (temp2 * ar + ai) / anorm;
                    anorm = (temp2 * ai - ar) / anorm;
                  }
                }

                temp2 = shift.re * ad22_im + shift.im * ad22_re;
                shift.re = ((t1_re * t1_re - t1_im * t1_im) + (tempr * stemp_re
                  - anorm * stemp_im)) - (shift.re * ad22_re - shift.im *
                  ad22_im);
                shift.im = ((t1_re * t1_im + t1_im * t1_re) + (tempr * stemp_im
                  + anorm * stemp_re)) - temp2;
                b_sqrt(&shift);
                if ((t1_re - abi22_re) * shift.re + (t1_im - abi22_im) *
                    shift.im <= 0.0) {
                  shift.re += t1_re;
                  shift.im += t1_im;
                } else {
                  shift.re = t1_re - shift.re;
                  shift.im = t1_im - shift.im;
                }
              } else {
                ar = ascale * A[ilast + 3 * ilastm1].re;
                ai = ascale * A[ilast + 3 * ilastm1].im;
                B_im = bscale * B[ilastm1 + 3 * ilastm1].re;
                B_re = bscale * B[ilastm1 + 3 * ilastm1].im;
                if (B_re == 0.0) {
                  if (ai == 0.0) {
                    tempr = ar / B_im;
                    anorm = 0.0;
                  } else if (ar == 0.0) {
                    tempr = 0.0;
                    anorm = ai / B_im;
                  } else {
                    tempr = ar / B_im;
                    anorm = ai / B_im;
                  }
                } else if (B_im == 0.0) {
                  if (ar == 0.0) {
                    tempr = ai / B_re;
                    anorm = 0.0;
                  } else if (ai == 0.0) {
                    tempr = 0.0;
                    anorm = -(ar / B_re);
                  } else {
                    tempr = ai / B_re;
                    anorm = -(ar / B_re);
                  }
                } else {
                  brm = fabs(B_im);
                  anorm = fabs(B_re);
                  if (brm > anorm) {
                    temp2 = B_re / B_im;
                    anorm = B_im + temp2 * B_re;
                    tempr = (ar + temp2 * ai) / anorm;
                    anorm = (ai - temp2 * ar) / anorm;
                  } else if (anorm == brm) {
                    if (B_im > 0.0) {
                      temp2 = 0.5;
                    } else {
                      temp2 = -0.5;
                    }

                    if (B_re > 0.0) {
                      anorm = 0.5;
                    } else {
                      anorm = -0.5;
                    }

                    tempr = (ar * temp2 + ai * anorm) / brm;
                    anorm = (ai * temp2 - ar * anorm) / brm;
                  } else {
                    temp2 = B_im / B_re;
                    anorm = B_re + temp2 * B_im;
                    tempr = (temp2 * ar + ai) / anorm;
                    anorm = (temp2 * ai - ar) / anorm;
                  }
                }

                eshift_re += tempr;
                eshift_im += anorm;
                shift.re = eshift_re;
                shift.im = eshift_im;
              }

              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > ifirst + 1)) {
                istart = j + 1;
                tempr = bscale * B[j + 3 * j].re;
                anorm = bscale * B[j + 3 * j].im;
                ctemp.re = ascale * A[j + 3 * j].re - (shift.re * tempr -
                  shift.im * anorm);
                ctemp.im = ascale * A[j + 3 * j].im - (shift.re * anorm +
                  shift.im * tempr);
                anorm = fabs(ctemp.re) + fabs(ctemp.im);
                temp2 = ascale * (fabs(A[jp1 + 3 * j].re) + fabs(A[jp1 + 3 * j].
                  im));
                tempr = anorm;
                if (temp2 > anorm) {
                  tempr = temp2;
                }

                if ((tempr < 1.0) && (tempr != 0.0)) {
                  anorm /= tempr;
                  temp2 /= tempr;
                }

                if ((fabs(A[j + 3 * (j - 1)].re) + fabs(A[j + 3 * (j - 1)].im)) *
                    temp2 <= anorm * b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }

              if (!goto90) {
                istart = ifirst + 1;
                tempr = bscale * B[ifirst + 3 * ifirst].re;
                anorm = bscale * B[ifirst + 3 * ifirst].im;
                ctemp.re = ascale * A[ifirst + 3 * ifirst].re - (shift.re *
                  tempr - shift.im * anorm);
                ctemp.im = ascale * A[ifirst + 3 * ifirst].im - (shift.re *
                  anorm + shift.im * tempr);
                goto90 = true;
              }
            }

            if (goto90) {
              goto90 = false;
              b_ascale.re = ascale * A[istart + 3 * (istart - 1)].re;
              b_ascale.im = ascale * A[istart + 3 * (istart - 1)].im;
              b_xzlartg(ctemp, b_ascale, &tempr, &shift);
              j = istart;
              jp1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  xzlartg(A[1 + 3 * jp1], A[j + 3 * jp1], &tempr, &shift, &A[1 +
                          3 * jp1]);
                  A[j + 3 * jp1].re = 0.0;
                  A[j + 3 * jp1].im = 0.0;
                }

                for (jp1 = j - 1; jp1 + 1 < 4; jp1++) {
                  stemp_re = tempr * A[(j + 3 * jp1) - 1].re + (shift.re * A[j +
                    3 * jp1].re - shift.im * A[j + 3 * jp1].im);
                  stemp_im = tempr * A[(j + 3 * jp1) - 1].im + (shift.re * A[j +
                    3 * jp1].im + shift.im * A[j + 3 * jp1].re);
                  anorm = A[(j + 3 * jp1) - 1].im;
                  temp2 = A[(j + 3 * jp1) - 1].re;
                  A[j + 3 * jp1].re = tempr * A[j + 3 * jp1].re - (shift.re * A
                    [(j + 3 * jp1) - 1].re + shift.im * A[(j + 3 * jp1) - 1].im);
                  A[j + 3 * jp1].im = tempr * A[j + 3 * jp1].im - (shift.re *
                    anorm - shift.im * temp2);
                  A[(j + 3 * jp1) - 1].re = stemp_re;
                  A[(j + 3 * jp1) - 1].im = stemp_im;
                }

                for (jp1 = j - 1; jp1 + 1 < 4; jp1++) {
                  stemp_re = tempr * B[(j + 3 * jp1) - 1].re + (shift.re * B[j +
                    3 * jp1].re - shift.im * B[j + 3 * jp1].im);
                  stemp_im = tempr * B[(j + 3 * jp1) - 1].im + (shift.re * B[j +
                    3 * jp1].im + shift.im * B[j + 3 * jp1].re);
                  B_im = B[(j + 3 * jp1) - 1].im;
                  B_re = B[(j + 3 * jp1) - 1].re;
                  B[j + 3 * jp1].re = tempr * B[j + 3 * jp1].re - (shift.re * B
                    [(j + 3 * jp1) - 1].re + shift.im * B[(j + 3 * jp1) - 1].im);
                  B[j + 3 * jp1].im = tempr * B[j + 3 * jp1].im - (shift.re *
                    B_im - shift.im * B_re);
                  B[(j + 3 * jp1) - 1].re = stemp_re;
                  B[(j + 3 * jp1) - 1].im = stemp_im;
                }

                xzlartg(B[j + 3 * j], B[j + 3 * (j - 1)], &tempr, &shift, &B[j +
                        3 * j]);
                B[j + 3 * (j - 1)].re = 0.0;
                B[j + 3 * (j - 1)].im = 0.0;
                for (i = 0; i + 1 <= j; i++) {
                  stemp_re = tempr * B[i + 3 * j].re + (shift.re * B[i + 3 * (j
                    - 1)].re - shift.im * B[i + 3 * (j - 1)].im);
                  stemp_im = tempr * B[i + 3 * j].im + (shift.re * B[i + 3 * (j
                    - 1)].im + shift.im * B[i + 3 * (j - 1)].re);
                  B_im = B[i + 3 * j].im;
                  B_re = B[i + 3 * j].re;
                  B[i + 3 * (j - 1)].re = tempr * B[i + 3 * (j - 1)].re -
                    (shift.re * B[i + 3 * j].re + shift.im * B[i + 3 * j].im);
                  B[i + 3 * (j - 1)].im = tempr * B[i + 3 * (j - 1)].im -
                    (shift.re * B_im - shift.im * B_re);
                  B[i + 3 * j].re = stemp_re;
                  B[i + 3 * j].im = stemp_im;
                }

                jp1 = j;
                if (ilast + 1 < j + 2) {
                  jp1 = ilast - 1;
                }

                for (i = 0; i + 1 <= jp1 + 2; i++) {
                  stemp_re = tempr * A[i + 3 * j].re + (shift.re * A[i + 3 * (j
                    - 1)].re - shift.im * A[i + 3 * (j - 1)].im);
                  stemp_im = tempr * A[i + 3 * j].im + (shift.re * A[i + 3 * (j
                    - 1)].im + shift.im * A[i + 3 * (j - 1)].re);
                  anorm = A[i + 3 * j].im;
                  temp2 = A[i + 3 * j].re;
                  A[i + 3 * (j - 1)].re = tempr * A[i + 3 * (j - 1)].re -
                    (shift.re * A[i + 3 * j].re + shift.im * A[i + 3 * j].im);
                  A[i + 3 * (j - 1)].im = tempr * A[i + 3 * (j - 1)].im -
                    (shift.re * anorm - shift.im * temp2);
                  A[i + 3 * j].re = stemp_re;
                  A[i + 3 * j].im = stemp_im;
                }

                for (i = 0; i < 3; i++) {
                  stemp_re = tempr * Z[i + 3 * j].re + (shift.re * Z[i + 3 * (j
                    - 1)].re - shift.im * Z[i + 3 * (j - 1)].im);
                  stemp_im = tempr * Z[i + 3 * j].im + (shift.re * Z[i + 3 * (j
                    - 1)].im + shift.im * Z[i + 3 * (j - 1)].re);
                  anorm = Z[i + 3 * j].im;
                  temp2 = Z[i + 3 * j].re;
                  Z[i + 3 * (j - 1)].re = tempr * Z[i + 3 * (j - 1)].re -
                    (shift.re * Z[i + 3 * j].re + shift.im * Z[i + 3 * j].im);
                  Z[i + 3 * (j - 1)].im = tempr * Z[i + 3 * (j - 1)].im -
                    (shift.re * anorm - shift.im * temp2);
                  Z[i + 3 * j].re = stemp_re;
                  Z[i + 3 * j].im = stemp_im;
                }

                jp1 = j - 1;
                j++;
              }
            }

            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      for (jp1 = 0; jp1 + 1 <= ilast + 1; jp1++) {
        alpha1[jp1].re = rtNaN;
        alpha1[jp1].im = 0.0;
        beta1[jp1].re = rtNaN;
        beta1[jp1].im = 0.0;
      }

      for (jp1 = 0; jp1 < 9; jp1++) {
        Z[jp1].re = rtNaN;
        Z[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    for (j = 0; j + 1 < ilo; j++) {
      anorm = rt_hypotd_snf(B[j + 3 * j].re, B[j + 3 * j].im);
      if (anorm > 2.2250738585072014E-308) {
        ar = B[j + 3 * j].re;
        ai = B[j + 3 * j].im;
        if (ai == 0.0) {
          B_re = ar / anorm;
          B_im = 0.0;
        } else if (ar == 0.0) {
          B_re = 0.0;
          B_im = ai / anorm;
        } else {
          B_re = ar / anorm;
          B_im = ai / anorm;
        }

        B[j + 3 * j].re = anorm;
        B[j + 3 * j].im = 0.0;
        for (jp1 = 0; jp1 + 1 <= j; jp1++) {
          anorm = B[jp1 + 3 * j].re;
          temp2 = B[jp1 + 3 * j].im;
          B[jp1 + 3 * j].re = anorm * B_re - temp2 * -B_im;
          B[jp1 + 3 * j].im = anorm * -B_im + temp2 * B_re;
        }

        for (jp1 = 0; jp1 + 1 <= j + 1; jp1++) {
          temp2 = A[jp1 + 3 * j].re;
          anorm = A[jp1 + 3 * j].im;
          A[jp1 + 3 * j].re = temp2 * B_re - anorm * -B_im;
          A[jp1 + 3 * j].im = temp2 * -B_im + anorm * B_re;
        }

        for (jp1 = 0; jp1 < 3; jp1++) {
          temp2 = Z[jp1 + 3 * j].re;
          anorm = Z[jp1 + 3 * j].im;
          Z[jp1 + 3 * j].re = temp2 * B_re - anorm * -B_im;
          Z[jp1 + 3 * j].im = temp2 * -B_im + anorm * B_re;
        }
      } else {
        B[j + 3 * j].re = 0.0;
        B[j + 3 * j].im = 0.0;
      }

      beta1[j] = B[j + 3 * j];
      alpha1[j] = A[j + 3 * j];
    }
  }
}

/*
 * File trailer for xzhgeqz.c
 *
 * [EOF]
 */
