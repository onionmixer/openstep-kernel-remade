/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10abec. */
int __cdecl settimeofday(const timeval *a1, const timezone *a2)
{
  int result; // eax
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  result = **(_DWORD **)(dword_1E875C + 36); /*0x10abfb*/
  if ( result ) /*0x10abff*/
  {
    *(_BYTE *)(dword_1E875C + 104) = copyin(result, v3, 8); /*0x10ac14*/
    result = dword_1E875C; /*0x10ac17*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x10ac1f*/
      return setthetime(v3); /*0x10ac26*/
  }
  return result; /*0x10ac2b*/
}
