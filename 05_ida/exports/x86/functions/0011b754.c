/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b754. */
int *dnlc_purge()
{
  int *result; // eax
  int v1; // ebx

  ++dword_1E9C1C; /*0x11b758*/
  while ( 1 ) /*0x11b75e*/
  {
    result = nc_hash; /*0x11b75e*/
    if ( nc_hash >= (int *)&nc_lru ) /*0x11b768*/
      break; /*0x11b768*/
    while ( 1 ) /*0x11b76c*/
    {
      v1 = *result; /*0x11b76c*/
      if ( (int *)*result != result ) /*0x11b770*/
        break; /*0x11b770*/
      result += 2; /*0x11b798*/
      if ( result >= (int *)&nc_lru ) /*0x11b7a0*/
        return result; /*0x11b7a0*/
    }
    if ( !*(_DWORD *)(v1 + 20) || !*(_DWORD *)(v1 + 16) ) /*0x11b778*/
      panic(aDnlcPurgeZeroV); /*0x11b783*/
    sub_11B830(*result); /*0x11b78c*/
  }
  return result; /*0x11b7a2*/
}
