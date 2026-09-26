/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ee90. */
int __cdecl ifa_ifwithnet(_WORD *a1)
{
  unsigned int v1; // eax
  int v3; // esi
  int v4; // ebx
  int (*v5)(); // [esp+Ch] [ebp-4h]

  v1 = (unsigned __int16)*a1; /*0x11ee9c*/
  if ( v1 > 0x10 ) /*0x11eea2*/
    return 0; /*0x11eea2*/
  v5 = off_1DB794[2 * v1]; /*0x11eeb3*/
  v3 = ifnet; /*0x11eeb6*/
  if ( !ifnet ) /*0x11eebe*/
    return 0; /*0x11eeec*/
  while ( 1 ) /*0x11eec0*/
  {
    v4 = *(_DWORD *)(v3 + 24); /*0x11eec0*/
    if ( v4 ) /*0x11eec5*/
      break; /*0x11eec5*/
LABEL_9:
    v3 = *(_DWORD *)(v3 + 92); /*0x11eee5*/
    if ( !v3 ) /*0x11eeea*/
      return 0; /*0x11eeea*/
  }
  while ( *(_WORD *)v4 != *a1 || !((int (__cdecl *)(int, _WORD *))v5)(v4, a1) ) /*0x11eedc*/
  {
    v4 = *(_DWORD *)(v4 + 36); /*0x11eede*/
    if ( !v4 ) /*0x11eee3*/
      goto LABEL_9; /*0x11eee3*/
  }
  return v4; /*0x11eef1*/
}
