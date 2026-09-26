/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ed10. */
int __cdecl physstrat(_BYTE *a1, int (__cdecl *a2)(_BYTE *))
{
  int result; // eax
  int v3; // esi

  result = a2(a1); /*0x11ed20*/
  if ( (a1[1] & 0x20) == 0 ) /*0x11ed29*/
  {
    v3 = splbio(); /*0x11ed30*/
    while ( (*a1 & 2) == 0 ) /*0x11ed35*/
      sleep((unsigned int)a1); /*0x11ed3a*/
    return splx(v3); /*0x11ed48*/
  }
  return result; /*0x11ed50*/
}
