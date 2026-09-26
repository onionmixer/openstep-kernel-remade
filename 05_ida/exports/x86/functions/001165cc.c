/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1165cc. */
int __cdecl sbrelease(int a1)
{
  int v1; // esi

  sbflush(a1); /*0x1165d5*/
  *(_WORD *)(a1 + 6) = 0; /*0x1165da*/
  *(_WORD *)(a1 + 2) = 0; /*0x1165e0*/
  v1 = splimp(); /*0x1165eb*/
  if ( *(_DWORD *)(a1 + 16) ) /*0x1165f0*/
    selthreadclear((_DWORD *)(a1 + 16)); /*0x1165fa*/
  return splx(v1); /*0x11660b*/
}
