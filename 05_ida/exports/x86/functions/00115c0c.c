/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x115c0c. */
int __cdecl soshutdown(int a1, char a2)
{
  int v2; // edi

  v2 = *(_DWORD *)(a1 + 12); /*0x115c15*/
  if ( ((a2 + 1) & 1) != 0 ) /*0x115c1f*/
    sorflush(a1); /*0x115c22*/
  if ( ((a2 + 1) & 2) != 0 ) /*0x115c2d*/
    return (*(int (__stdcall **)(int, int, _DWORD, _DWORD, _DWORD))(v2 + 28))(a1, 7, 0, 0, 0); /*0x115c3b*/
  else
    return 0; /*0x115c40*/
}
