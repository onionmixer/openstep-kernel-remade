/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10f2d0. */
int __cdecl ttyinput(int a1, FILE *a2)
{
  int result; // eax
  int v3; // edi
  int ur; // eax
  int v5; // eax
  int v6; // eax
  char v7; // al
  int v8; // edx
  int v9; // eax
  char v10; // dl
  int v11; // esi
  int (__cdecl *read)(void *, char *, int); // eax
  int v13; // esi
  int (__cdecl *v14)(void *, char *, int); // eax
  long double v15; // [esp-Ch] [ebp-24h]
  _DWORD v16[3]; // [esp+Ch] [ebp-Ch] BYREF

  result = ttynty(a2); /*0x10f2dd*/
  v3 = result; /*0x10f2e2*/
  if ( (*(_BYTE *)(result + 17) & 8) != 0 ) /*0x10f2eb*/
  {
    ur = a2->_ur; /*0x10f2f1*/
    if ( (ur & 0x20000000) != 0 ) /*0x10f2f9*/
    {
      a2->_ur = ur & 0xDFFFFFFF; /*0x10f300*/
      *(_DWORD *)a2->_ubuf |= 0x100000u; /*0x10f303*/
      v16[0] = a2->_p; /*0x10f30c*/
      v16[1] = a2->_r; /*0x10f312*/
      v16[2] = a2->_w; /*0x10f318*/
      a2->_p = nullptr; /*0x10f31b*/
      a2->_w = 0; /*0x10f321*/
      a2->_r = 0; /*0x10f328*/
      while ( 1 ) /*0x10f335*/
      {
        v5 = getc((FILE *)v16); /*0x10f335*/
        if ( v5 < 0 ) /*0x10f33f*/
          break; /*0x10f33f*/
        ttyinput(v5, a2); /*0x10f343*/
      }
      *(_DWORD *)a2->_ubuf &= ~0x100000u; /*0x10f350*/
    }
    ++tk_nin; /*0x10f357*/
    if ( HIBYTE(a1) || (a2->_ur & 0x20) == 0 ) /*0x10f36b*/
    {
      ttcooked(a1, v3); /*0x10f401*/
    }
    else
    {
      if ( (int)a2->_p <= 1024 ) /*0x10f377*/
      {
        if ( putc(a1, a2) >= 0 ) /*0x10f3a7*/
        {
          if ( ttcheckwakeup(v3) ) /*0x10f3aa*/
            ttwakeup(a2); /*0x10f3b7*/
          ttyecho(a1, v3); /*0x10f3c4*/
        }
      }
      else
      {
        DWORD2(v15) = SLOWORD(a2->_extra); /*0x10f37d*/
        DWORD1(v15) = aTtyDRawInputOv; /*0x10f37e*/
        LODWORD(v15) = 4; /*0x10f383*/
        log(v15); /*0x10f385*/
        ttwakeup(a2); /*0x10f38b*/
      }
      v6 = a2->_ur; /*0x10f3cc*/
      a2->_ur = v6 & 0xFF7FFFFF; /*0x10f3d7*/
      if ( (*(_BYTE *)(v3 + 16) & 0x10) != 0 ) /*0x10f3de*/
      {
        if ( (v6 & 0x40000000) == 0 || (v7 = BYTE2(a2->_offset), v7 != -1) && BYTE1(a2->_offset) == v7 ) /*0x10f3f1*/
          *(_DWORD *)a2->_ubuf &= ~0x100u; /*0x10f3f3*/
      }
    }
    v8 = *(_DWORD *)&a2->_flags; /*0x10f409*/
    if ( (int)&a2->_p[v8] > 511 ) /*0x10f415*/
    {
      v9 = a2->_ur; /*0x10f417*/
      if ( (v9 & 0x22) != 0 || v8 > 0 ) /*0x10f420*/
      {
        if ( (v9 & 1) != 0 ) /*0x10f424*/
        {
          v10 = BYTE2(a2->_offset); /*0x10f426*/
          if ( v10 != -1 && !putc(v10, (FILE *)&a2->_lbfsize) ) /*0x10f436*/
          {
            *(_DWORD *)a2->_ubuf |= 0x400u; /*0x10f442*/
            v11 = spltty(); /*0x10f44e*/
            if ( (*(_DWORD *)a2->_ubuf & 0x4000121) == 0 ) /*0x10f457*/
            {
              read = a2->_read; /*0x10f459*/
              if ( read ) /*0x10f45e*/
                ((void (__cdecl *)(FILE *))read)(a2); /*0x10f461*/
            }
            splx(v11); /*0x10f467*/
          }
        }
        *(_DWORD *)a2->_ubuf |= 0x800000u; /*0x10f46f*/
      }
    }
    v13 = spltty(); /*0x10f47b*/
    if ( (*(_DWORD *)a2->_ubuf & 0x4000121) == 0 ) /*0x10f484*/
    {
      v14 = a2->_read; /*0x10f486*/
      if ( v14 ) /*0x10f48b*/
        ((void (__cdecl *)(FILE *))v14)(a2); /*0x10f48e*/
    }
    return splx(v13); /*0x10f494*/
  }
  return result; /*0x10f49c*/
}
