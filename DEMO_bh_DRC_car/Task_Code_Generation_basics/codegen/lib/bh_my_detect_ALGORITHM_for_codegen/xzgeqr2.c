/*
 * File: xzgeqr2.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "xzgeqr2.h"
#include "recip.h"
#include "xdlapy3.h"
#include "xnrm2.h"

/* Function Definitions */

/*
 * Arguments    : creal_T A[9]
 *                int ijmin
 *                int imax
 *                creal_T tau[3]
 * Return Type  : void
 */
void xzgeqr2(creal_T A[9], int ijmin, int imax, creal_T tau[3])
{
  int i;
  int iA0;
  creal_T work[3];
  int subdiaglen;
  int iAii;
  int iSubdiag;
  creal_T alpha1;
  double tautmp_re;
  double tautmp_im;
  double xnorm;
  double beta1;
  double atmp_im;
  int knt;
  int i24;
  int k;
  int lastv;
  int lastc;
  double A_im;
  boolean_T exitg2;
  int exitg1;
  int ix;
  double c_im;
  creal_T b_alpha1;
  for (i = 0; i < 3; i++) {
    work[i].re = 0.0;
    work[i].im = 0.0;
    tau[i].re = 0.0;
    tau[i].im = 0.0;
  }

  iA0 = (ijmin + 3 * (ijmin - 1)) - 1;
  for (i = ijmin; i <= imax; i++) {
    subdiaglen = imax - i;
    iAii = iA0 + ((i - ijmin) << 2);
    if (i < 3) {
      iSubdiag = iAii + 2;
    } else {
      iSubdiag = iAii + 1;
    }

    alpha1 = A[iAii];
    tautmp_re = 0.0;
    tautmp_im = 0.0;
    if (!(subdiaglen + 1 <= 0)) {
      xnorm = xnrm2(subdiaglen, A, iSubdiag);
      if ((xnorm != 0.0) || (A[iAii].im != 0.0)) {
        beta1 = xdlapy3(A[iAii].re, A[iAii].im, xnorm);
        if (A[iAii].re >= 0.0) {
          beta1 = -beta1;
        }

        if (fabs(beta1) < 1.0020841800044864E-292) {
          knt = 0;
          i24 = (iSubdiag + subdiaglen) - 1;
          do {
            knt++;
            for (k = iSubdiag; k <= i24; k++) {
              xnorm = A[k - 1].re;
              A_im = A[k - 1].im;
              A[k - 1].re = 9.9792015476736E+291 * xnorm - 0.0 * A_im;
              A[k - 1].im = 9.9792015476736E+291 * A_im + 0.0 * xnorm;
            }

            beta1 *= 9.9792015476736E+291;
            alpha1.re *= 9.9792015476736E+291;
            alpha1.im *= 9.9792015476736E+291;
          } while (!(fabs(beta1) >= 1.0020841800044864E-292));

          beta1 = xdlapy3(alpha1.re, alpha1.im, xnrm2(subdiaglen, A, iSubdiag));
          if (alpha1.re >= 0.0) {
            beta1 = -beta1;
          }

          xnorm = beta1 - alpha1.re;
          if (0.0 - alpha1.im == 0.0) {
            tautmp_re = xnorm / beta1;
            tautmp_im = 0.0;
          } else if (xnorm == 0.0) {
            tautmp_re = 0.0;
            tautmp_im = (0.0 - alpha1.im) / beta1;
          } else {
            tautmp_re = xnorm / beta1;
            tautmp_im = (0.0 - alpha1.im) / beta1;
          }

          b_alpha1.re = alpha1.re - beta1;
          b_alpha1.im = alpha1.im;
          alpha1 = recip(b_alpha1);
          i24 = (iSubdiag + subdiaglen) - 1;
          while (iSubdiag <= i24) {
            xnorm = A[iSubdiag - 1].re;
            A_im = A[iSubdiag - 1].im;
            A[iSubdiag - 1].re = alpha1.re * xnorm - alpha1.im * A_im;
            A[iSubdiag - 1].im = alpha1.re * A_im + alpha1.im * xnorm;
            iSubdiag++;
          }

          for (k = 1; k <= knt; k++) {
            beta1 *= 1.0020841800044864E-292;
          }

          alpha1.re = beta1;
          alpha1.im = 0.0;
        } else {
          xnorm = beta1 - A[iAii].re;
          atmp_im = 0.0 - A[iAii].im;
          if (atmp_im == 0.0) {
            tautmp_re = xnorm / beta1;
            tautmp_im = 0.0;
          } else if (xnorm == 0.0) {
            tautmp_re = 0.0;
            tautmp_im = atmp_im / beta1;
          } else {
            tautmp_re = xnorm / beta1;
            tautmp_im = atmp_im / beta1;
          }

          alpha1.re = A[iAii].re - beta1;
          alpha1.im = A[iAii].im;
          alpha1 = recip(alpha1);
          i24 = (iSubdiag + subdiaglen) - 1;
          while (iSubdiag <= i24) {
            xnorm = A[iSubdiag - 1].re;
            A_im = A[iSubdiag - 1].im;
            A[iSubdiag - 1].re = alpha1.re * xnorm - alpha1.im * A_im;
            A[iSubdiag - 1].im = alpha1.re * A_im + alpha1.im * xnorm;
            iSubdiag++;
          }

          alpha1.re = beta1;
          alpha1.im = 0.0;
        }
      }
    }

    A[iAii] = alpha1;
    tau[i - ijmin].re = tautmp_re;
    tau[i - ijmin].im = tautmp_im;
    if (i < 3) {
      xnorm = A[iAii].re;
      atmp_im = A[iAii].im;
      A[iAii].re = 1.0;
      A[iAii].im = 0.0;
      tautmp_im = -tautmp_im;
      if ((tautmp_re != 0.0) || (tautmp_im != 0.0)) {
        lastv = subdiaglen + 1;
        iSubdiag = iAii + subdiaglen;
        while ((lastv > 0) && ((A[iSubdiag].re == 0.0) && (A[iSubdiag].im == 0.0)))
        {
          lastv--;
          iSubdiag--;
        }

        lastc = 3 - i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          iSubdiag = iAii + (lastc - 1) * 3;
          subdiaglen = iSubdiag;
          do {
            exitg1 = 0;
            if (subdiaglen + 4 <= (iSubdiag + lastv) + 3) {
              if ((A[subdiaglen + 3].re != 0.0) || (A[subdiaglen + 3].im != 0.0))
              {
                exitg1 = 1;
              } else {
                subdiaglen++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = 0;
      }

      if (lastv > 0) {
        if (lastc != 0) {
          for (iSubdiag = 1; iSubdiag <= lastc; iSubdiag++) {
            work[iSubdiag - 1].re = 0.0;
            work[iSubdiag - 1].im = 0.0;
          }

          iSubdiag = 0;
          i24 = (iAii + 3 * (lastc - 1)) + 4;
          for (knt = iAii + 4; knt <= i24; knt += 3) {
            ix = iAii;
            beta1 = 0.0;
            c_im = 0.0;
            k = (knt + lastv) - 1;
            for (subdiaglen = knt - 1; subdiaglen < k; subdiaglen++) {
              beta1 += A[subdiaglen].re * A[ix].re + A[subdiaglen].im * A[ix].im;
              c_im += A[subdiaglen].re * A[ix].im - A[subdiaglen].im * A[ix].re;
              ix++;
            }

            work[iSubdiag].re += beta1 - 0.0 * c_im;
            work[iSubdiag].im += c_im + 0.0 * beta1;
            iSubdiag++;
          }
        }

        if (!((-tautmp_re == 0.0) && (-tautmp_im == 0.0))) {
          iSubdiag = iAii + 3;
          knt = 0;
          for (k = 1; k <= lastc; k++) {
            if ((work[knt].re != 0.0) || (work[knt].im != 0.0)) {
              beta1 = work[knt].re * -tautmp_re + work[knt].im * -tautmp_im;
              c_im = work[knt].re * -tautmp_im - work[knt].im * -tautmp_re;
              ix = iAii;
              i24 = lastv + iSubdiag;
              for (subdiaglen = iSubdiag; subdiaglen < i24; subdiaglen++) {
                A_im = A[ix].re * c_im + A[ix].im * beta1;
                A[subdiaglen].re += A[ix].re * beta1 - A[ix].im * c_im;
                A[subdiaglen].im += A_im;
                ix++;
              }
            }

            knt++;
            iSubdiag += 3;
          }
        }
      }

      A[iAii].re = xnorm;
      A[iAii].im = atmp_im;
    }
  }
}

/*
 * File trailer for xzgeqr2.c
 *
 * [EOF]
 */
