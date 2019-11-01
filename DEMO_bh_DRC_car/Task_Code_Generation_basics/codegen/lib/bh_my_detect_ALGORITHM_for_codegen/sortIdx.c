/*
 * File: sortIdx.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jul-2018 13:26:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "bh_my_detect_ALGORITHM_for_codegen.h"
#include "sortIdx.h"
#include "bh_my_detect_ALGORITHM_for_codegen_emxutil.h"

/* Function Declarations */
static void b_merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_real_T *xwork);
static void merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int np,
                  int nq, emxArray_int32_T *iwork, emxArray_real_T *xwork);
static void merge_block(emxArray_int32_T *idx, emxArray_real_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_real_T *xwork);

/* Function Definitions */

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_real_T *x
 *                int offset
 *                int np
 *                int nq
 *                emxArray_int32_T *iwork
 *                emxArray_real_T *xwork
 * Return Type  : void
 */
static void b_merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  int n;
  int qend;
  int p;
  int iout;
  int exitg1;
  if (nq != 0) {
    n = np + nq;
    for (qend = 0; qend < n; qend++) {
      iwork->data[qend] = idx->data[offset + qend];
      xwork->data[qend] = x->data[offset + qend];
    }

    p = 0;
    n = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] >= xwork->data[n]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[n];
        x->data[iout] = xwork->data[n];
        if (n + 1 < qend) {
          n++;
        } else {
          n = (iout - p) + 1;
          while (p + 1 <= np) {
            idx->data[n + p] = iwork->data[p];
            x->data[n + p] = xwork->data[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_real_T *x
 *                int offset
 *                int np
 *                int nq
 *                emxArray_int32_T *iwork
 *                emxArray_real_T *xwork
 * Return Type  : void
 */
static void merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int np,
                  int nq, emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  int n;
  int qend;
  int p;
  int iout;
  int exitg1;
  if (nq != 0) {
    n = np + nq;
    for (qend = 0; qend < n; qend++) {
      iwork->data[qend] = idx->data[offset + qend];
      xwork->data[qend] = x->data[offset + qend];
    }

    p = 0;
    n = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] <= xwork->data[n]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[n];
        x->data[iout] = xwork->data[n];
        if (n + 1 < qend) {
          n++;
        } else {
          n = (iout - p) + 1;
          while (p + 1 <= np) {
            idx->data[n + p] = iwork->data[p];
            x->data[n + p] = xwork->data[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_real_T *x
 *                int offset
 *                int n
 *                int preSortLevel
 *                emxArray_int32_T *iwork
 *                emxArray_real_T *xwork
 * Return Type  : void
 */
static void merge_block(emxArray_int32_T *idx, emxArray_real_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 1; nTail <= nPairs; nTail++) {
      merge(idx, x, offset + (nTail - 1) * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_real_T *x
 *                int offset
 *                int n
 *                int preSortLevel
 *                emxArray_int32_T *iwork
 *                emxArray_real_T *xwork
 * Return Type  : void
 */
void b_merge_block(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int n,
                   int preSortLevel, emxArray_int32_T *iwork, emxArray_real_T
                   *xwork)
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        b_merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 1; nTail <= nPairs; nTail++) {
      b_merge(idx, x, offset + (nTail - 1) * tailOffset, bLen, bLen, iwork,
              xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    b_merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

/*
 * Arguments    : emxArray_real_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void sortIdx(emxArray_real_T *x, emxArray_int32_T *idx)
{
  int unnamed_idx_0;
  int bLen;
  emxArray_int32_T *r9;
  emxArray_int32_T *b_idx;
  int i;
  int b_x[2];
  emxArray_real_T *c_x;
  int d_x[2];
  int m;
  emxArray_real_T *e_x;
  emxArray_int32_T *iwork;
  double x4[4];
  int idx4[4];
  emxArray_real_T *xwork;
  int nNaNs;
  int ib;
  int k;
  int wOffset;
  signed char perm[4];
  int nNonNaN;
  int i4;
  int nBlocks;
  unsigned int uv1[2];
  int bLen2;
  int nPairs;
  int b_iwork[256];
  double b_xwork[256];
  int exitg1;
  unnamed_idx_0 = x->size[0];
  bLen = idx->size[0];
  idx->size[0] = unnamed_idx_0;
  emxEnsureCapacity_int32_T(idx, bLen);
  for (bLen = 0; bLen < unnamed_idx_0; bLen++) {
    idx->data[bLen] = 0;
  }

  if (x->size[0] != 0) {
    emxInit_int32_T1(&r9, 2);
    bLen = r9->size[0] * r9->size[1];
    r9->size[1] = 1;
    r9->size[0] = unnamed_idx_0;
    emxEnsureCapacity_int32_T1(r9, bLen);
    for (bLen = 0; bLen < unnamed_idx_0; bLen++) {
      r9->data[r9->size[1] * bLen] = 0;
    }

    emxInit_int32_T(&b_idx, 1);
    bLen = b_idx->size[0];
    b_idx->size[0] = unnamed_idx_0;
    emxEnsureCapacity_int32_T(b_idx, bLen);
    for (bLen = 0; bLen < unnamed_idx_0; bLen++) {
      b_idx->data[bLen] = r9->data[bLen];
    }

    emxFree_int32_T(&r9);
    i = x->size[0];
    b_x[0] = x->size[0];
    b_x[1] = 1;
    for (bLen = 0; bLen < 2; bLen++) {
      d_x[bLen] = b_x[1 - bLen];
    }

    emxInit_real_T(&c_x, 2);
    m = x->size[0];
    bLen = c_x->size[0] * c_x->size[1];
    c_x->size[1] = 1;
    c_x->size[0] = m;
    emxEnsureCapacity_real_T(c_x, bLen);
    for (bLen = 0; bLen < m; bLen++) {
      c_x->data[c_x->size[1] * bLen] = x->data[d_x[0] * bLen];
    }

    emxInit_real_T1(&e_x, 1);
    bLen = e_x->size[0];
    e_x->size[0] = i;
    emxEnsureCapacity_real_T1(e_x, bLen);
    for (bLen = 0; bLen < i; bLen++) {
      e_x->data[bLen] = c_x->data[bLen];
    }

    emxFree_real_T(&c_x);
    bLen = x->size[0];
    for (i = 0; i < 4; i++) {
      x4[i] = 0.0;
      idx4[i] = 0;
    }

    emxInit_int32_T(&iwork, 1);
    m = iwork->size[0];
    iwork->size[0] = unnamed_idx_0;
    emxEnsureCapacity_int32_T(iwork, m);
    for (m = 0; m < unnamed_idx_0; m++) {
      iwork->data[m] = 0;
    }

    emxInit_real_T1(&xwork, 1);
    i = x->size[0];
    m = xwork->size[0];
    xwork->size[0] = i;
    emxEnsureCapacity_real_T1(xwork, m);
    for (m = 0; m < i; m++) {
      xwork->data[m] = 0.0;
    }

    nNaNs = 1;
    ib = 0;
    for (k = 0; k < bLen; k++) {
      if (rtIsNaN(e_x->data[k])) {
        b_idx->data[bLen - nNaNs] = k + 1;
        xwork->data[bLen - nNaNs] = e_x->data[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib - 1] = k + 1;
        x4[ib - 1] = e_x->data[k];
        if (ib == 4) {
          i = k - nNaNs;
          if (x4[0] <= x4[1]) {
            m = 1;
            ib = 2;
          } else {
            m = 2;
            ib = 1;
          }

          if (x4[2] <= x4[3]) {
            wOffset = 3;
            i4 = 4;
          } else {
            wOffset = 4;
            i4 = 3;
          }

          if (x4[m - 1] <= x4[wOffset - 1]) {
            if (x4[ib - 1] <= x4[wOffset - 1]) {
              perm[0] = (signed char)m;
              perm[1] = (signed char)ib;
              perm[2] = (signed char)wOffset;
              perm[3] = (signed char)i4;
            } else if (x4[ib - 1] <= x4[i4 - 1]) {
              perm[0] = (signed char)m;
              perm[1] = (signed char)wOffset;
              perm[2] = (signed char)ib;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)m;
              perm[1] = (signed char)wOffset;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)ib;
            }
          } else if (x4[m - 1] <= x4[i4 - 1]) {
            if (x4[ib - 1] <= x4[i4 - 1]) {
              perm[0] = (signed char)wOffset;
              perm[1] = (signed char)m;
              perm[2] = (signed char)ib;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)wOffset;
              perm[1] = (signed char)m;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)ib;
            }
          } else {
            perm[0] = (signed char)wOffset;
            perm[1] = (signed char)i4;
            perm[2] = (signed char)m;
            perm[3] = (signed char)ib;
          }

          b_idx->data[i - 2] = idx4[perm[0] - 1];
          b_idx->data[i - 1] = idx4[perm[1] - 1];
          b_idx->data[i] = idx4[perm[2] - 1];
          b_idx->data[i + 1] = idx4[perm[3] - 1];
          e_x->data[i - 2] = x4[perm[0] - 1];
          e_x->data[i - 1] = x4[perm[1] - 1];
          e_x->data[i] = x4[perm[2] - 1];
          e_x->data[i + 1] = x4[perm[3] - 1];
          ib = 0;
        }
      }
    }

    m = x->size[0];
    wOffset = m - nNaNs;
    if (ib > 0) {
      for (i = 0; i < 4; i++) {
        perm[i] = 0;
      }

      if (ib == 1) {
        perm[0] = 1;
      } else if (ib == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }

      for (k = 1; k <= ib; k++) {
        b_idx->data[(wOffset - ib) + k] = idx4[perm[k - 1] - 1];
        e_x->data[(wOffset - ib) + k] = x4[perm[k - 1] - 1];
      }
    }

    m = ((nNaNs - 1) >> 1) + 1;
    for (k = 1; k < m; k++) {
      i = b_idx->data[wOffset + k];
      b_idx->data[wOffset + k] = b_idx->data[bLen - k];
      b_idx->data[bLen - k] = i;
      e_x->data[wOffset + k] = xwork->data[bLen - k];
      e_x->data[bLen - k] = xwork->data[wOffset + k];
    }

    if (((nNaNs - 1) & 1) != 0) {
      e_x->data[wOffset + m] = xwork->data[wOffset + m];
    }

    bLen = x->size[0];
    nNonNaN = (bLen - nNaNs) + 1;
    m = 2;
    if (nNonNaN > 1) {
      bLen = x->size[0];
      if (bLen >= 256) {
        nBlocks = nNonNaN >> 8;
        if (nBlocks > 0) {
          for (wOffset = 1; wOffset <= nBlocks; wOffset++) {
            i4 = ((wOffset - 1) << 8) - 1;
            for (nNaNs = 0; nNaNs < 6; nNaNs++) {
              bLen = 1 << (nNaNs + 2);
              bLen2 = bLen << 1;
              nPairs = 256 >> (nNaNs + 3);
              for (k = 1; k <= nPairs; k++) {
                m = i4 + (k - 1) * bLen2;
                for (i = 1; i <= bLen2; i++) {
                  b_iwork[i - 1] = b_idx->data[m + i];
                  b_xwork[i - 1] = e_x->data[m + i];
                }

                ib = 0;
                i = bLen;
                do {
                  exitg1 = 0;
                  m++;
                  if (b_xwork[ib] <= b_xwork[i]) {
                    b_idx->data[m] = b_iwork[ib];
                    e_x->data[m] = b_xwork[ib];
                    if (ib + 1 < bLen) {
                      ib++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    b_idx->data[m] = b_iwork[i];
                    e_x->data[m] = b_xwork[i];
                    if (i + 1 < bLen2) {
                      i++;
                    } else {
                      i = m - ib;
                      while (ib + 1 <= bLen) {
                        b_idx->data[(i + ib) + 1] = b_iwork[ib];
                        e_x->data[(i + ib) + 1] = b_xwork[ib];
                        ib++;
                      }

                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }

          m = nBlocks << 8;
          i = nNonNaN - m;
          if (i > 0) {
            merge_block(b_idx, e_x, m, i, 2, iwork, xwork);
          }

          m = 8;
        }
      }

      merge_block(b_idx, e_x, 0, nNonNaN, m, iwork, xwork);
    }

    emxFree_real_T(&xwork);
    emxFree_int32_T(&iwork);
    i = b_idx->size[0];
    uv1[0] = (unsigned int)unnamed_idx_0;
    uv1[1] = 1U;
    for (bLen = 0; bLen < 2; bLen++) {
      b_x[bLen] = (int)uv1[1 - bLen];
    }

    for (bLen = 0; bLen < i; bLen++) {
      idx->data[b_x[0] * bLen] = b_idx->data[bLen];
    }

    emxFree_int32_T(&b_idx);
    i = e_x->size[0];
    m = x->size[0];
    b_x[0] = m;
    b_x[1] = 1;
    for (bLen = 0; bLen < 2; bLen++) {
      d_x[bLen] = b_x[1 - bLen];
    }

    for (bLen = 0; bLen < i; bLen++) {
      x->data[d_x[0] * bLen] = e_x->data[bLen];
    }

    emxFree_real_T(&e_x);
  }
}

/*
 * File trailer for sortIdx.c
 *
 * [EOF]
 */
