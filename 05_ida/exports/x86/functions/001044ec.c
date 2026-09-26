/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1044ec. */
int __cdecl fsetown(int a1, int a2)
{
  int v3; // eax
  int v4; // eax

  if ( *(_WORD *)(a1 + 12) == 2 ) /*0x1044f8*/
  {
    *(_WORD *)(*(_DWORD *)(a1 + 24) + 90) = a2; /*0x104501*/
    return 0; /*0x104507*/
  }
  if ( a2 <= 0 ) /*0x104511*/
  {
    v4 = -a2; /*0x104530*/
  }
  else
  {
    v3 = pfind(a2); /*0x104514*/
    if ( !v3 ) /*0x10451e*/
      return 3; /*0x104525*/
    v4 = *(__int16 *)(v3 + 46); /*0x104528*/
  }
  a2 = v4; /*0x104532*/
  return fioctl(a1, -2147191690, &a2); /*0x104544*/
}
