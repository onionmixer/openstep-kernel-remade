/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b7f8. */
int dnlc_purge1()
{
  int v0; // eax

  v0 = dword_1E9BE8; /*0x11b7fb*/
  if ( (_UNKNOWN *)dword_1E9BE8 == &nc_lru ) /*0x11b805*/
    return 0; /*0x11b82a*/
  while ( !*(_DWORD *)(v0 + 20) ) /*0x11b80c*/
  {
    v0 = *(_DWORD *)(v0 + 8); /*0x11b820*/
    if ( (_UNKNOWN *)v0 == &nc_lru ) /*0x11b828*/
      return 0; /*0x11b828*/
  }
  sub_11B830(v0); /*0x11b80f*/
  return 1; /*0x11b81b*/
}
