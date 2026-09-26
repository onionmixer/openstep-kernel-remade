/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11a1e0. */
int __cdecl bdwrite(int a1)
{
  if ( (*(_BYTE *)(a1 + 1) & 2) == 0 ) /*0x11a1ea*/
    ++*(_DWORD *)(active_u + 416); /*0x11a1f1*/
  *(_DWORD *)a1 |= 0x202u; /*0x11a1f7*/
  return brelse(a1); /*0x11a205*/
}
