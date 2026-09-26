/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ef6c. */
int __cdecl ttyclose(FILE *a1)
{
  int v1; // edi
  int v2; // ebx
  int v4; // [esp+Ch] [ebp-4h]

  v4 = ttynty(a1); /*0x10ef7e*/
  if ( (FILE *)cons_tp == a1 ) /*0x10ef8a*/
  {
    cons_tp = (int)&cons; /*0x10ef8c*/
    (*(&funcs_10EA24 + 11 * BYTE1(a1->_extra)))(SLOWORD(a1->_extra), 536898312, 0, 0); /*0x10efb5*/
  }
  v1 = spltty(); /*0x10efbf*/
  while ( getc((FILE *)&a1->_flags) >= 0 ) /*0x10efcf*/
    ; /*0x10efc4*/
  wakeup((int)a1); /*0x10efd2*/
  wakeup((int)&a1->_lbfsize); /*0x10efde*/
  *(_DWORD *)a1->_ubuf &= ~0x100u; /*0x10efe3*/
  ((void (__cdecl *)(FILE *, int))funcs_10DE95[11 * BYTE1(a1->_extra)])(a1, 3); /*0x10effe*/
  while ( getc((FILE *)&a1->_lbfsize) >= 0 ) /*0x10f00f*/
    ; /*0x10f004*/
  while ( getc(a1) >= 0 ) /*0x10f01f*/
    ; /*0x10f014*/
  HIBYTE(a1->_lb._size) = 0; /*0x10f021*/
  LOBYTE(a1->_blksize) = 0; /*0x10f025*/
  *(_DWORD *)a1->_ubuf &= 0xFF40FFFF; /*0x10f029*/
  splx(v1); /*0x10f031*/
  if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x10f044*/
  {
    *(_DWORD *)(v4 + 8) = 0; /*0x10f049*/
    *(_DWORD *)(v4 + 12) = 0; /*0x10f050*/
  }
  if ( *(FILE **)(active_u + 360) == a1 ) /*0x10f062*/
    *(_DWORD *)(*(_DWORD *)active_u + 40) &= ~0x40000000u; /*0x10f066*/
  LOWORD(a1->_lb._base) = 0; /*0x10f06d*/
  *(_DWORD *)a1->_ubuf = 0; /*0x10f073*/
  HIBYTE(a1->_lb._base) = 0; /*0x10f07a*/
  a1[1]._write = nullptr; /*0x10f07e*/
  v2 = spltty(); /*0x10f08d*/
  selthreadclear(&a1->_write); /*0x10f093*/
  selthreadclear(&a1->_seek); /*0x10f09c*/
  return splx(v2); /*0x10f0aa*/
}
