/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10f4a4. */
int __cdecl ttyblkin(unsigned __int8 *a1, size_t a2, FILE *a3)
{
  unsigned __int8 *v3; // edi
  size_t v4; // ebx
  int result; // eax
  int ur; // eax
  int v7; // eax
  unsigned __int8 *p; // edx
  int v9; // eax
  char v10; // al
  int i; // ebx
  int v12; // edx
  int v13; // eax
  char v14; // dl
  int v15; // ebx
  int (__cdecl *read)(void *, char *, int); // eax
  int v17; // ebx
  int (__cdecl *v18)(void *, char *, int); // eax
  long double v19; // [esp-Ch] [ebp-2Ch]
  int v20; // [esp-8h] [ebp-28h]
  int v21; // [esp+10h] [ebp-10h]
  _DWORD v22[3]; // [esp+14h] [ebp-Ch] BYREF

  v3 = a1; /*0x10f4ad*/
  v4 = a2; /*0x10f4b0*/
  result = ttynty(a3); /*0x10f4b7*/
  v21 = result; /*0x10f4bc*/
  if ( (*(_BYTE *)(result + 17) & 8) != 0 ) /*0x10f4c6*/
  {
    ur = a3->_ur; /*0x10f4cc*/
    if ( (ur & 0x20000000) != 0 ) /*0x10f4d4*/
    {
      a3->_ur = ur & 0xDFFFFFFF; /*0x10f4db*/
      *(_DWORD *)a3->_ubuf |= 0x100000u; /*0x10f4de*/
      v22[0] = a3->_p; /*0x10f4e7*/
      v22[1] = a3->_r; /*0x10f4ed*/
      v22[2] = a3->_w; /*0x10f4f3*/
      a3->_p = nullptr; /*0x10f4f6*/
      a3->_w = 0; /*0x10f4fc*/
      a3->_r = 0; /*0x10f503*/
      while ( 1 ) /*0x10f514*/
      {
        v7 = getc((FILE *)v22); /*0x10f514*/
        if ( v7 < 0 ) /*0x10f51e*/
          break; /*0x10f51e*/
        ttyinput(v7, a3); /*0x10f522*/
      }
      *(_DWORD *)a3->_ubuf &= ~0x100000u; /*0x10f52c*/
    }
    tk_nin += a2; /*0x10f533*/
    if ( (a3->_ur & 0x20) != 0 ) /*0x10f53d*/
    {
      p = a3->_p; /*0x10f543*/
      if ( (int)&a3->_p[a2] > 1024 ) /*0x10f54d*/
      {
        v4 = 1024 - (_DWORD)p; /*0x10f554*/
        if ( 1024 - (int)p < 0 ) /*0x10f556*/
          v4 = 0; /*0x10f558*/
        DWORD2(v19) = SLOWORD(a3->_extra); /*0x10f55e*/
        DWORD1(v19) = aTtyDRawInputOv_0; /*0x10f55f*/
        LODWORD(v19) = 4; /*0x10f564*/
        log(v19); /*0x10f566*/
      }
      if ( (int)(v4 - b_to_q(a1, v4, (int)a3)) > 0 && ttcheckwakeup(v21) ) /*0x10f587*/
        ttwakeup(a3); /*0x10f594*/
      v9 = a3->_ur; /*0x10f59c*/
      a3->_ur = v9 & 0xFF7FFFFF; /*0x10f5a7*/
      if ( (v9 & 8) != 0 ) /*0x10f5ac*/
        tk_nout += b_to_q(a1, v4, (int)&a3->_lbfsize); /*0x10f5b9*/
      if ( (*(_BYTE *)(v21 + 16) & 0x10) != 0 ) /*0x10f5c9*/
      {
        if ( (a3->_ur & 0x40000000) == 0 || (v10 = BYTE2(a3->_offset), v10 != -1) && BYTE1(a3->_offset) == v10 ) /*0x10f5db*/
          *(_DWORD *)a3->_ubuf &= ~0x100u; /*0x10f5dd*/
      }
    }
    else
    {
      for ( i = a2 - 1; i >= 0; --i ) /*0x10f5e9*/
      {
        v20 = *v3++; /*0x10f5f3*/
        ttcooked(v20, v21); /*0x10f5f5*/
      }
    }
    v12 = *(_DWORD *)&a3->_flags; /*0x10f600*/
    if ( (int)&a3->_p[v12] > 511 ) /*0x10f60c*/
    {
      v13 = a3->_ur; /*0x10f60e*/
      if ( (v13 & 0x22) != 0 || v12 > 0 ) /*0x10f617*/
      {
        if ( (v13 & 1) != 0 ) /*0x10f61b*/
        {
          v14 = BYTE2(a3->_offset); /*0x10f61d*/
          if ( v14 != -1 && !putc(v14, (FILE *)&a3->_lbfsize) ) /*0x10f62d*/
          {
            *(_DWORD *)a3->_ubuf |= 0x400u; /*0x10f639*/
            v15 = spltty(); /*0x10f645*/
            if ( (*(_DWORD *)a3->_ubuf & 0x4000121) == 0 ) /*0x10f64e*/
            {
              read = a3->_read; /*0x10f650*/
              if ( read ) /*0x10f655*/
                ((void (__cdecl *)(FILE *))read)(a3); /*0x10f658*/
            }
            splx(v15); /*0x10f65e*/
          }
        }
        *(_DWORD *)a3->_ubuf |= 0x800000u; /*0x10f666*/
      }
    }
    v17 = spltty(); /*0x10f672*/
    if ( (*(_DWORD *)a3->_ubuf & 0x4000121) == 0 ) /*0x10f67b*/
    {
      v18 = a3->_read; /*0x10f67d*/
      if ( v18 ) /*0x10f682*/
        ((void (__cdecl *)(FILE *))v18)(a3); /*0x10f685*/
    }
    return splx(v17); /*0x10f68b*/
  }
  return result; /*0x10f693*/
}
