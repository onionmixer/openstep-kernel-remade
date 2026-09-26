/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187068. */
int __cdecl catch_trap(int a1)
{
  int *v1; // eax
  int v2; // edx
  signed int v3; // ecx
  int v4; // eax
  int result; // eax

  if ( (*(_BYTE *)(a1 + 66) & 2) == 0 && (*(_BYTE *)(a1 + 60) & 3) != 3 ) /*0x18707e*/
    return kernel_trap(a1); /*0x1870f9*/
  v1 = *(int **)(*(_DWORD *)(active_threads + 40) + 236); /*0x187089*/
  v2 = 0; /*0x18708f*/
  if ( v1 ) /*0x187093*/
    v2 = *v1; /*0x187095*/
  if ( !v2
    || ((v3 = *(_DWORD *)(a1 + 48), (unsigned int)v3 > 0x1F)
      ? (v4 = ((int)*(unsigned __int8 *)(v3 / 8 + v2 + 44) >> (v3 % 8)) & 1)
      : (v4 = ((1 << v3) & *(_DWORD *)(v2 + 44)) != 0),
        v4) )
  {
    result = 0; /*0x1870e8*/
  }
  else
  {
    result = PCexception(active_threads, a1); /*0x1870de*/
  }
  if ( !result ) /*0x1870ec*/
    return user_trap(a1); /*0x1870ef*/
  return result; /*0x187101*/
}
