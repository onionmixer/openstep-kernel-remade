/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10f0b4. */
int __cdecl ttymodem(FILE *a1, int a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // ebx
  int (__cdecl *read)(void *, char *, int); // eax
  int v6; // eax
  int v7; // ecx
  int v8; // edi

  v2 = ttynty(a1); /*0x10f0c6*/
  v3 = *(_DWORD *)a1->_ubuf; /*0x10f0c8*/
  if ( (v3 & 2) == 0 && (a1->_ur & 0x100000) != 0 ) /*0x10f0d6*/
  {
    if ( a2 ) /*0x10f0da*/
    {
      BYTE1(v3) &= ~1u; /*0x10f0dc*/
      *(_DWORD *)a1->_ubuf = v3; /*0x10f0df*/
      v4 = spltty(); /*0x10f0e7*/
      if ( (*(_DWORD *)a1->_ubuf & 0x4000121) == 0 ) /*0x10f0f0*/
      {
        read = a1->_read; /*0x10f0f2*/
        if ( read ) /*0x10f0f7*/
          ((void (__cdecl *)(FILE *))read)(a1); /*0x10f0fa*/
      }
      splx(v4); /*0x10f100*/
    }
    else if ( (v3 & 0x100) == 0 ) /*0x10f10f*/
    {
      BYTE1(v3) |= 1u; /*0x10f115*/
      *(_DWORD *)a1->_ubuf = v3; /*0x10f118*/
      ((void (__cdecl *)(FILE *, _DWORD))funcs_10DE95[11 * BYTE1(a1->_extra)])(a1, 0); /*0x10f12f*/
    }
    return 1; /*0x10f105*/
  }
  if ( a2 ) /*0x10f13a*/
  {
    a1->_ubuf[0] |= 0x10u; /*0x10f210*/
    wakeup((int)a1); /*0x10f215*/
    return 1; /*0x10f21a*/
  }
  v6 = *(_DWORD *)a1->_ubuf; /*0x10f140*/
  v7 = v6; /*0x10f143*/
  LOBYTE(v7) = v6 & 0xEF; /*0x10f145*/
  *(_DWORD *)a1->_ubuf = v7; /*0x10f148*/
  if ( (v6 & 4) == 0 ) /*0x10f14d*/
    return 1; /*0x10f14d*/
  if ( *(__int16 *)(v2 + 16) < 0 ) /*0x10f158*/
    return 1; /*0x10f158*/
  ttwakeup(a1); /*0x10f15f*/
  if ( (a1->_ur & 0x1000000) != 0 ) /*0x10f16b*/
    return 1; /*0x10f16b*/
  gsignal((_DWORD *)SLOWORD(a1->_lb._base), (char *)1); /*0x10f178*/
  gsignal((_DWORD *)SLOWORD(a1->_lb._base), (char *)0x13); /*0x10f184*/
  v8 = spltty(); /*0x10f191*/
  while ( getc((FILE *)&a1->_flags) >= 0 ) /*0x10f1a3*/
    ; /*0x10f198*/
  wakeup((int)a1); /*0x10f1a6*/
  wakeup((int)&a1->_lbfsize); /*0x10f1b2*/
  *(_DWORD *)a1->_ubuf &= ~0x100u; /*0x10f1b7*/
  ((void (__cdecl *)(FILE *, int))funcs_10DE95[11 * BYTE1(a1->_extra)])(a1, 3); /*0x10f1d2*/
  while ( getc((FILE *)&a1->_lbfsize) >= 0 ) /*0x10f1e3*/
    ; /*0x10f1d8*/
  while ( getc(a1) >= 0 ) /*0x10f1f3*/
    ; /*0x10f1e8*/
  HIBYTE(a1->_lb._size) = 0; /*0x10f1f5*/
  LOBYTE(a1->_blksize) = 0; /*0x10f1f9*/
  *(_DWORD *)a1->_ubuf &= 0xFF40FFFF; /*0x10f1fd*/
  splx(v8); /*0x10f205*/
  return 0; /*0x10f222*/
}
