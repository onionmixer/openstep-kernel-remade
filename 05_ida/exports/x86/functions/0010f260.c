/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10f260. */
int __cdecl ttypend(FILE *a1)
{
  int result; // eax
  _DWORD v2[3]; // [esp+8h] [ebp-Ch] BYREF

  a1->_ur &= ~0x20000000u; /*0x10f26b*/
  *(_DWORD *)a1->_ubuf |= 0x100000u; /*0x10f272*/
  v2[0] = a1->_p; /*0x10f27b*/
  v2[1] = a1->_r; /*0x10f281*/
  v2[2] = a1->_w; /*0x10f287*/
  a1->_p = nullptr; /*0x10f28a*/
  a1->_w = 0; /*0x10f290*/
  a1->_r = 0; /*0x10f297*/
  while ( 1 ) /*0x10f2a5*/
  {
    result = getc((FILE *)v2); /*0x10f2a5*/
    if ( result < 0 ) /*0x10f2af*/
      break; /*0x10f2af*/
    ttyinput(result, a1); /*0x10f2b3*/
  }
  *(_DWORD *)a1->_ubuf &= ~0x100000u; /*0x10f2c0*/
  return result; /*0x10f2ca*/
}
