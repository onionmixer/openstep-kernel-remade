/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b3f8. */
int __cdecl timevaladd(_DWORD *a1, _DWORD *a2)
{
  *a1 += *a2; /*0x10b403*/
  a1[1] += a2[1]; /*0x10b408*/
  return timevalfix(a1); /*0x10b413*/
}
