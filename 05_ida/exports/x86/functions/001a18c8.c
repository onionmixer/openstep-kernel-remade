/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a18c8. */
void __cdecl PCbopFA(int a1, int a2, int a3)
{
  int v3; // ebx

  if ( (*(_BYTE *)(a3 + 4) & 4) != 0 ) /*0x1a18d6*/
  {
    *(_DWORD *)(a2 + 56) = *(_DWORD *)a3; /*0x1a18de*/
    *(_WORD *)(a2 + 60) = *(_WORD *)(a3 + 4); /*0x1a18e5*/
    v3 = *(_DWORD *)(a3 + 8); /*0x1a18e9*/
    *(_DWORD *)(a2 + 64) = v3; /*0x1a18ec*/
    *(_DWORD *)(a2 + 64) = v3 & 0x50DD5 | 0x202; /*0x1a18fb*/
    *(_DWORD *)(a2 + 68) = *(_DWORD *)(a3 + 12); /*0x1a1901*/
    *(_WORD *)(a2 + 72) = *(_WORD *)(a3 + 16); /*0x1a1908*/
    thread_exception_return(); /*0x1a190c*/
  }
}
