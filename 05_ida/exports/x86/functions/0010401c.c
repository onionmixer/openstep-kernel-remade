/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10401c. */
int __cdecl dupit(int a1, int a2, char a3)
{
  int result; // eax

  expand_fdlist(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 56), a1); /*0x104034*/
  *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * a1) = a2; /*0x104044*/
  *(_BYTE *)(a1 + *(_DWORD *)(active_u + 340)) = a3 & 0xFE; /*0x104058*/
  ++*(_WORD *)(a2 + 14); /*0x10405b*/
  result = active_u; /*0x10405f*/
  if ( *(_DWORD *)(active_u + 344) < a1 ) /*0x10406a*/
    *(_DWORD *)(active_u + 344) = a1; /*0x10406c*/
  return result; /*0x104075*/
}
