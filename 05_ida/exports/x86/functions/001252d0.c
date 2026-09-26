/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1252d0. */
void __cdecl in_setsockaddr(int a1, int a2)
{
  _WORD *v2; // ebx

  *(_WORD *)(a2 + 8) = 16; /*0x1252db*/
  v2 = (_WORD *)(*(_DWORD *)(a2 + 4) + a2); /*0x1252e1*/
  bzero(v2, 0x10u); /*0x1252e7*/
  *v2 = 2; /*0x1252ec*/
  v2[1] = *(_WORD *)(a1 + 24); /*0x1252f5*/
  *((_DWORD *)v2 + 1) = *(_DWORD *)(a1 + 20); /*0x1252fc*/
}
