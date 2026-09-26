/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11edb4. */
int __cdecl ifa_ifwithaddr(_WORD *a1)
{
  int v1; // esi
  const void *v2; // edi
  int v3; // ebx

  v1 = ifnet; /*0x11edba*/
  if ( !ifnet ) /*0x11edc2*/
    return 0; /*0x11ee1e*/
  v2 = a1 + 1; /*0x11edc7*/
  while ( 1 ) /*0x11edcc*/
  {
    v3 = *(_DWORD *)(v1 + 24); /*0x11edcc*/
    if ( v3 ) /*0x11edd1*/
      break; /*0x11edd1*/
LABEL_10:
    v1 = *(_DWORD *)(v1 + 92); /*0x11ee17*/
    if ( !v1 ) /*0x11ee1c*/
      return 0; /*0x11ee1c*/
  }
  while ( *(_WORD *)v3 != *a1 /*0x11ee09*/
       || bcmp((const void *)(v3 + 2), v2, 0xEu)
       && ((*(_BYTE *)(v1 + 12) & 2) == 0 || bcmp((const void *)(v3 + 18), v2, 0xEu)) )
  {
    v3 = *(_DWORD *)(v3 + 36); /*0x11ee10*/
    if ( !v3 ) /*0x11ee15*/
      goto LABEL_10; /*0x11ee15*/
  }
  return v3; /*0x11ee23*/
}
