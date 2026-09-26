/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10de30. */
int __cdecl ttyflush(FILE *a1, int a2)
{
  int v3; // [esp+Ch] [ebp-4h]

  v3 = spltty(); /*0x10de44*/
  if ( (a2 & 1) != 0 ) /*0x10de4d*/
  {
    while ( getc((FILE *)&a1->_flags) >= 0 ) /*0x10de5f*/
      ; /*0x10de54*/
    wakeup((int)a1); /*0x10de62*/
  }
  if ( (a2 & 2) != 0 ) /*0x10de70*/
  {
    wakeup((int)&a1->_lbfsize); /*0x10de76*/
    *(_DWORD *)a1->_ubuf &= ~0x100u; /*0x10de7b*/
    ((void (__cdecl *)(FILE *, int))funcs_10DE95[11 * BYTE1(a1->_extra)])(a1, a2); /*0x10de95*/
    while ( getc((FILE *)&a1->_lbfsize) >= 0 ) /*0x10dea7*/
      ; /*0x10de9c*/
  }
  if ( (a2 & 1) != 0 ) /*0x10deaf*/
  {
    while ( getc(a1) >= 0 ) /*0x10debf*/
      ; /*0x10deb4*/
    HIBYTE(a1->_lb._size) = 0; /*0x10dec1*/
    LOBYTE(a1->_blksize) = 0; /*0x10dec5*/
    *(_DWORD *)a1->_ubuf &= 0xFF40FFFF; /*0x10dec9*/
  }
  return splx(v3); /*0x10dedc*/
}
