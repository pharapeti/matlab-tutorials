/*
 * File: xzggev.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 29-Jan-2018 09:25:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "bh_my_lane_preprocess_mask.h"
#include "bh_my_track_ALGORITHM_for_codegen.h"
#include "xzggev.h"
#include "xzlascl.h"
#include "xzggbak.h"
#include "xztgevc.h"
#include "xzhgeqz.h"
#include "xzgghrd.h"
#include "xzgeqr2.h"
#include "bh_MY_CV_ALGORITHMS_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : creal_T A[9]
 *                creal_T B[9]
 *                int *info
 *                creal_T alpha1[3]
 *                creal_T beta1[3]
 *                creal_T V[9]
 * Return Type  : void
 */
void xzggev(creal_T A[9], creal_T B[9], int *info, creal_T alpha1[3], creal_T
            beta1[3], creal_T V[9])
{
  double anrm;
  int nzcount;
  boolean_T exitg1;
  double absxk;
  boolean_T ilascl;
  int i;
  double anrmto;
  boolean_T ilbscl;
  double bnrm;
  double bnrmto;
  int ilo;
  int rscale[3];
  int ihi;
  int exitg3;
  int j;
  boolean_T found;
  int ii;
  int jj;
  boolean_T exitg4;
  double atmp_im;
  int exitg2;
  creal_T tau[3];
  double wj_re;
  double wj_im;
  double b_wj_re;
  *info = 0;
  anrm = 0.0;
  nzcount = 0;
  exitg1 = false;
  while ((!exitg1) && (nzcount < 9)) {
    absxk = rt_hypotd_snf(A[nzcount].re, A[nzcount].im);
    if (rtIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }

      nzcount++;
    }
  }

  if (!((!rtIsInf(anrm)) && (!rtIsNaN(anrm)))) {
    for (i = 0; i < 3; i++) {
      alpha1[i].re = rtNaN;
      alpha1[i].im = 0.0;
      beta1[i].re = rtNaN;
      beta1[i].im = 0.0;
    }

    for (nzcount = 0; nzcount < 9; nzcount++) {
      V[nzcount].re = rtNaN;
      V[nzcount].im = 0.0;
    }
  } else {
    ilascl = false;
    anrmto = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      anrmto = 6.7178761075670888E-139;
      ilascl = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
      }
    }

    if (ilascl) {
      xzlascl(anrm, anrmto, A);
    }

    ilbscl = false;
    bnrm = 0.0;
    nzcount = 0;
    exitg1 = false;
    while ((!exitg1) && (nzcount < 9)) {
      absxk = rt_hypotd_snf(B[nzcount].re, B[nzcount].im);
      if (rtIsNaN(absxk)) {
        bnrm = rtNaN;
        exitg1 = true;
      } else {
        if (absxk > bnrm) {
          bnrm = absxk;
        }

        nzcount++;
      }
    }

    bnrmto = bnrm;
    if ((bnrm > 0.0) && (bnrm < 6.7178761075670888E-139)) {
      bnrmto = 6.7178761075670888E-139;
      ilbscl = true;
    }

    if (ilbscl) {
      xzlascl(bnrm, bnrmto, B);
    }

    for (i = 0; i < 3; i++) {
      rscale[i] = 1;
    }

    ilo = 0;
    ihi = 3;
    do {
      exitg3 = 0;
      i = -1;
      j = -1;
      found = false;
      ii = ihi - 1;
      exitg1 = false;
      while ((!exitg1) && (ii + 1 > 0)) {
        nzcount = 0;
        i = ii;
        j = ihi - 1;
        jj = 0;
        exitg4 = false;
        while ((!exitg4) && (jj + 1 <= ihi)) {
          if ((A[ii + 3 * jj].re != 0.0) || (A[ii + 3 * jj].im != 0.0) || ((B[ii
                + 3 * jj].re != 0.0) || (B[ii + 3 * jj].im != 0.0))) {
            if (nzcount == 0) {
              j = jj;
              nzcount = 1;
              jj++;
            } else {
              nzcount = 2;
              exitg4 = true;
            }
          } else {
            jj++;
          }
        }

        if (nzcount < 2) {
          found = true;
          exitg1 = true;
        } else {
          ii--;
        }
      }

      if (!found) {
        exitg3 = 2;
      } else {
        if (i + 1 != ihi) {
          for (nzcount = 0; nzcount < 3; nzcount++) {
            absxk = A[i + 3 * nzcount].re;
            atmp_im = A[i + 3 * nzcount].im;
            A[i + 3 * nzcount] = A[(ihi + 3 * nzcount) - 1];
            A[(ihi + 3 * nzcount) - 1].re = absxk;
            A[(ihi + 3 * nzcount) - 1].im = atmp_im;
          }

          for (nzcount = 0; nzcount < 3; nzcount++) {
            absxk = B[i + 3 * nzcount].re;
            atmp_im = B[i + 3 * nzcount].im;
            B[i + 3 * nzcount] = B[(ihi + 3 * nzcount) - 1];
            B[(ihi + 3 * nzcount) - 1].re = absxk;
            B[(ihi + 3 * nzcount) - 1].im = atmp_im;
          }
        }

        if (j + 1 != ihi) {
          for (nzcount = 0; nzcount + 1 <= ihi; nzcount++) {
            absxk = A[nzcount + 3 * j].re;
            atmp_im = A[nzcount + 3 * j].im;
            A[nzcount + 3 * j] = A[nzcount + 3 * (ihi - 1)];
            A[nzcount + 3 * (ihi - 1)].re = absxk;
            A[nzcount + 3 * (ihi - 1)].im = atmp_im;
          }

          for (nzcount = 0; nzcount + 1 <= ihi; nzcount++) {
            absxk = B[nzcount + 3 * j].re;
            atmp_im = B[nzcount + 3 * j].im;
            B[nzcount + 3 * j] = B[nzcount + 3 * (ihi - 1)];
            B[nzcount + 3 * (ihi - 1)].re = absxk;
            B[nzcount + 3 * (ihi - 1)].im = atmp_im;
          }
        }

        rscale[ihi - 1] = j + 1;
        ihi--;
        if (ihi == 1) {
          rscale[0] = 1;
          exitg3 = 1;
        }
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
    } else {
      do {
        exitg2 = 0;
        i = -1;
        j = -1;
        found = false;
        jj = ilo;
        exitg1 = false;
        while ((!exitg1) && (jj + 1 <= ihi)) {
          nzcount = 0;
          i = ihi - 1;
          j = jj;
          ii = ilo;
          exitg4 = false;
          while ((!exitg4) && (ii + 1 <= ihi)) {
            if ((A[ii + 3 * jj].re != 0.0) || (A[ii + 3 * jj].im != 0.0) ||
                ((B[ii + 3 * jj].re != 0.0) || (B[ii + 3 * jj].im != 0.0))) {
              if (nzcount == 0) {
                i = ii;
                nzcount = 1;
                ii++;
              } else {
                nzcount = 2;
                exitg4 = true;
              }
            } else {
              ii++;
            }
          }

          if (nzcount < 2) {
            found = true;
            exitg1 = true;
          } else {
            jj++;
          }
        }

        if (!found) {
          exitg2 = 1;
        } else {
          if (i + 1 != ilo + 1) {
            for (nzcount = ilo; nzcount + 1 < 4; nzcount++) {
              absxk = A[i + 3 * nzcount].re;
              atmp_im = A[i + 3 * nzcount].im;
              A[i + 3 * nzcount] = A[ilo + 3 * nzcount];
              A[ilo + 3 * nzcount].re = absxk;
              A[ilo + 3 * nzcount].im = atmp_im;
            }

            for (nzcount = ilo; nzcount + 1 < 4; nzcount++) {
              absxk = B[i + 3 * nzcount].re;
              atmp_im = B[i + 3 * nzcount].im;
              B[i + 3 * nzcount] = B[ilo + 3 * nzcount];
              B[ilo + 3 * nzcount].re = absxk;
              B[ilo + 3 * nzcount].im = atmp_im;
            }
          }

          if (j + 1 != ilo + 1) {
            for (nzcount = 0; nzcount + 1 <= ihi; nzcount++) {
              absxk = A[nzcount + 3 * j].re;
              atmp_im = A[nzcount + 3 * j].im;
              A[nzcount + 3 * j] = A[nzcount + 3 * ilo];
              A[nzcount + 3 * ilo].re = absxk;
              A[nzcount + 3 * ilo].im = atmp_im;
            }

            for (nzcount = 0; nzcount + 1 <= ihi; nzcount++) {
              absxk = B[nzcount + 3 * j].re;
              atmp_im = B[nzcount + 3 * j].im;
              B[nzcount + 3 * j] = B[nzcount + 3 * ilo];
              B[nzcount + 3 * ilo].re = absxk;
              B[nzcount + 3 * ilo].im = atmp_im;
            }
          }

          rscale[ilo] = j + 1;
          ilo++;
          if (ilo + 1 == ihi) {
            rscale[ilo] = ilo + 1;
            exitg2 = 1;
          }
        }
      } while (exitg2 == 0);
    }

    xzgeqr2(B, ilo + 1, ihi, tau);
    for (i = ilo; i + 1 <= ihi; i++) {
      absxk = tau[i - ilo].re;
      atmp_im = -tau[i - ilo].im;
      for (j = ilo; j + 1 < 4; j++) {
        wj_re = A[i + 3 * j].re;
        wj_im = -A[i + 3 * j].im;
        for (nzcount = i + 1; nzcount + 1 <= ihi; nzcount++) {
          wj_re += A[nzcount + 3 * j].re * B[nzcount + 3 * i].re + A[nzcount + 3
            * j].im * B[nzcount + 3 * i].im;
          wj_im += A[nzcount + 3 * j].re * B[nzcount + 3 * i].im - A[nzcount + 3
            * j].im * B[nzcount + 3 * i].re;
        }

        b_wj_re = wj_re;
        wj_re = absxk * wj_re - atmp_im * -wj_im;
        wj_im = absxk * -wj_im + atmp_im * b_wj_re;
        A[i + 3 * j].re -= wj_re;
        A[i + 3 * j].im -= wj_im;
        for (nzcount = i + 1; nzcount + 1 <= ihi; nzcount++) {
          A[nzcount + 3 * j].re -= B[nzcount + 3 * i].re * wj_re - B[nzcount + 3
            * i].im * wj_im;
          A[nzcount + 3 * j].im -= B[nzcount + 3 * i].re * wj_im + B[nzcount + 3
            * i].im * wj_re;
        }
      }
    }

    xzgghrd(ilo + 1, ihi, A, B, V);
    xzhgeqz(A, B, ilo + 1, ihi, V, info, alpha1, beta1);
    if (*info == 0) {
      xztgevc(A, B, V);
      xzggbak(V, ilo + 1, ihi, rscale);
      for (nzcount = 0; nzcount < 3; nzcount++) {
        absxk = fabs(V[3 * nzcount].re) + fabs(V[3 * nzcount].im);
        for (ii = 0; ii < 2; ii++) {
          atmp_im = fabs(V[(ii + 3 * nzcount) + 1].re) + fabs(V[(ii + 3 *
            nzcount) + 1].im);
          if (atmp_im > absxk) {
            absxk = atmp_im;
          }
        }

        if (absxk >= 6.7178761075670888E-139) {
          absxk = 1.0 / absxk;
          for (ii = 0; ii < 3; ii++) {
            V[ii + 3 * nzcount].re *= absxk;
            V[ii + 3 * nzcount].im *= absxk;
          }
        }
      }

      if (ilascl) {
        b_xzlascl(anrmto, anrm, alpha1);
      }

      if (ilbscl) {
        b_xzlascl(bnrmto, bnrm, beta1);
      }
    }
  }
}

/*
 * File trailer for xzggev.c
 *
 * [EOF]
 */
