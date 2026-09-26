/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11bd6c. */
int __cdecl vno_close(int a1)
{
  int v1; // esi

  v1 = *(_DWORD *)(a1 + 24); /*0x11bd74*/
  if ( *(_WORD *)(a1 + 14) == 1 && (*(_DWORD *)(a1 + 8) & 0x180) != 0 ) /*0x11bd85*/
    vno_bsd_unlock(a1, 384); /*0x11bd8d*/
  *(_BYTE *)(dword_1E875C + 104) = vn_close(v1, *(_DWORD *)(a1 + 8), *(__int16 *)(a1 + 14)); /*0x11bdab*/
  if ( *(_WORD *)(a1 + 14) == 1 ) /*0x11bdb6*/
    vn_rele(v1); /*0x11bdb9*/
  return *(char *)(dword_1E875C + 104); /*0x11bdca*/
}
