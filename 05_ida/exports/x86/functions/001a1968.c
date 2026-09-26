/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1968. */
void __cdecl PCbopFD(int a1, int a2, int a3)
{
  int v3; // ebx

  *(_DWORD *)(a2 + 56) = *(_DWORD *)a3; /*0x1a1974*/
  *(_WORD *)(a2 + 60) = *(_WORD *)(a3 + 4); /*0x1a197b*/
  v3 = *(_DWORD *)(a3 + 8); /*0x1a197f*/
  *(_DWORD *)(a2 + 64) = v3; /*0x1a1982*/
  *(_DWORD *)(a2 + 64) = v3 & 0x50DD5 | 0x20202; /*0x1a1993*/
  *(_DWORD *)(a2 + 68) = *(_DWORD *)(a3 + 12); /*0x1a1999*/
  *(_WORD *)(a2 + 72) = *(_WORD *)(a3 + 16); /*0x1a19a0*/
  *(_WORD *)(a2 + 12) = 0; /*0x1a19a4*/
  *(_WORD *)(a2 + 8) = 0; /*0x1a19aa*/
  *(_WORD *)(a2 + 4) = 0; /*0x1a19b0*/
  *(_WORD *)a2 = 0; /*0x1a19b6*/
  thread_exception_return(); /*0x1a19bb*/
}
