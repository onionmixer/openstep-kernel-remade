/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108b2c. */
_DWORD *__cdecl ruadd(int a1, int a2)
{
  int v2; // eax
  _DWORD *result; // eax
  _DWORD *v4; // ecx
  int i; // edx

  timevaladd(a1, a2); /*0x108b3a*/
  timevaladd(a1 + 8, a2 + 8); /*0x108b47*/
  v2 = *(_DWORD *)(a2 + 16); /*0x108b4c*/
  if ( *(_DWORD *)(a1 + 16) < v2 ) /*0x108b52*/
    *(_DWORD *)(a1 + 16) = v2; /*0x108b54*/
  result = (_DWORD *)(a1 + 20); /*0x108b57*/
  v4 = (_DWORD *)(a2 + 20); /*0x108b5a*/
  for ( i = 12; i > 0; --i ) /*0x108b5d*/
    *result++ += *v4++; /*0x108b6a*/
  return result; /*0x108b7a*/
}
