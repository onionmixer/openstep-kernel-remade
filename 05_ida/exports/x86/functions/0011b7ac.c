/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b7ac. */
int __cdecl dnlc_purge_vp(int a1)
{
  int v1; // edx
  int result; // eax

  do /*0x11b7ec*/
  {
    v1 = 0; /*0x11b7b4*/
    result = dword_1E9BE8; /*0x11b7b6*/
    if ( (_UNKNOWN *)dword_1E9BE8 != &nc_lru ) /*0x11b7c0*/
    {
      while ( *(_DWORD *)(result + 20) != a1 && *(_DWORD *)(result + 16) != a1 ) /*0x11b7cc*/
      {
        result = *(_DWORD *)(result + 8); /*0x11b7e0*/
        if ( (_UNKNOWN *)result == &nc_lru ) /*0x11b7e8*/
          goto LABEL_6; /*0x11b7e8*/
      }
      result = sub_11B830(result); /*0x11b7cf*/
      v1 = 1; /*0x11b7d4*/
    }
LABEL_6:
    ; /*0x11b7ea*/
  }
  while ( v1 ); /*0x11b7ec*/
  return result; /*0x11b7ee*/
}
