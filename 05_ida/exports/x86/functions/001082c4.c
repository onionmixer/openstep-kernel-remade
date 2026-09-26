/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1082c4. */
int __cdecl groupmember(__int16 a1)
{
  int v1; // eax
  _WORD *v3; // edx
  unsigned int i; // eax

  v1 = *(_DWORD *)(active_u + 28); /*0x1082d1*/
  if ( *(_WORD *)(v1 + 4) == a1 ) /*0x1082d8*/
    return 1; /*0x1082da*/
  v3 = (_WORD *)(v1 + 10); /*0x1082e4*/
  for ( i = v1 + 42; (unsigned int)v3 < i; ++v3 ) /*0x1082ec*/
  {
    if ( *v3 == 0xFFFF ) /*0x1082f7*/
      break; /*0x1082f7*/
    if ( *v3 == a1 ) /*0x1082fc*/
      return 1; /*0x1082fc*/
  }
  return 0; /*0x108307*/
}
