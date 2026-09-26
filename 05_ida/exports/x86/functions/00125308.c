/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125308. */
void __cdecl in_setpeeraddr(int a1, int a2)
{
  _WORD *v2; // ebx

  *(_WORD *)(a2 + 8) = 16; /*0x125313*/
  v2 = (_WORD *)(*(_DWORD *)(a2 + 4) + a2); /*0x125319*/
  bzero(v2, 0x10u); /*0x12531f*/
  *v2 = 2; /*0x125324*/
  v2[1] = *(_WORD *)(a1 + 16); /*0x12532d*/
  *((_DWORD *)v2 + 1) = *(_DWORD *)(a1 + 12); /*0x125334*/
}
