/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ee2c. */
int __cdecl ifa_ifwithdstaddr(_WORD *a1)
{
  int v1; // esi
  int v2; // ebx

  v1 = ifnet; /*0x11ee35*/
  if ( !ifnet ) /*0x11ee3d*/
    return 0; /*0x11ee82*/
  while ( 1 ) /*0x11ee40*/
  {
    if ( (*(_BYTE *)(v1 + 12) & 0x10) != 0 ) /*0x11ee44*/
    {
      v2 = *(_DWORD *)(v1 + 24); /*0x11ee46*/
      if ( v2 ) /*0x11ee4b*/
        break; /*0x11ee4b*/
    }
LABEL_8:
    v1 = *(_DWORD *)(v1 + 92); /*0x11ee7b*/
    if ( !v1 ) /*0x11ee80*/
      return 0; /*0x11ee80*/
  }
  while ( *(_WORD *)v2 != *a1 || bcmp((const void *)(v2 + 18), a1 + 1, 0xEu) ) /*0x11ee6c*/
  {
    v2 = *(_DWORD *)(v2 + 36); /*0x11ee74*/
    if ( !v2 ) /*0x11ee79*/
      goto LABEL_8; /*0x11ee79*/
  }
  return v2; /*0x11ee87*/
}
