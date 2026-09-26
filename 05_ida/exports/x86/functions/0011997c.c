/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11997c. */
_DWORD *__cdecl getvfs(_DWORD *a1)
{
  _DWORD *v1; // edx

  v1 = (_DWORD *)rootvfs; /*0x119983*/
  if ( rootvfs ) /*0x11998b*/
  {
    do /*0x1199a1*/
    {
      if ( v1[5] == *a1 && v1[6] == a1[1] ) /*0x11999b*/
        break; /*0x11999b*/
      v1 = (_DWORD *)*v1; /*0x11999d*/
    }
    while ( v1 ); /*0x1199a1*/
  }
  return v1; /*0x1199a5*/
}
