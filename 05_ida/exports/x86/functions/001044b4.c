/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1044b4. */
int __cdecl fgetown(int a1, _DWORD *a2)
{
  int result; // eax

  if ( *(_WORD *)(a1 + 12) == 2 ) /*0x1044c3*/
  {
    *a2 = *(__int16 *)(*(_DWORD *)(a1 + 24) + 90); /*0x1044df*/
    return 0; /*0x1044e1*/
  }
  else
  {
    result = fioctl(a1, 1074033783, a2); /*0x1044cc*/
    *a2 = -*a2; /*0x1044d1*/
  }
  return result; /*0x1044e3*/
}
