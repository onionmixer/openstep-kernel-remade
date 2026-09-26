/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cee0c. */
int objc_getModules()
{
  size_t i; // ebx
  int zone; // ebx
  int v2; // eax
  size_t v3; // ebx
  _DWORD *j; // esi
  unsigned int k; // ecx
  int v7; // [esp-4h] [ebp-18h]
  int v8; // [esp+10h] [ebp-4h]

  if ( !dword_1E874C ) /*0x1cee1c*/
  {
    for ( i = 0; _nel > i; ++i ) /*0x1cee2a*/
      dword_1E8748 += *((_DWORD *)dword_1E55F8 + 6 * i + 2); /*0x1cee3b*/
    zone = _objc_create_zone(); /*0x1cee4f*/
    v7 = 4 * (dword_1E8748 + 1); /*0x1cee5a*/
    v2 = _objc_create_zone(); /*0x1cee5b*/
    dword_1E874C = (*(int (__cdecl **)(int, int))(zone + 4))(v2, v7); /*0x1cee66*/
    if ( !dword_1E874C ) /*0x1cee70*/
      _objc_fatal("unable to allocate module vector"); /*0x1cee77*/
    v3 = 0; /*0x1cee7c*/
    for ( j = (_DWORD *)dword_1E874C; _nel > v3; ++v3 ) /*0x1cee8a*/
    {
      v8 = *((_DWORD *)dword_1E55F8 + 6 * v3 + 1); /*0x1ceea2*/
      for ( k = 0; *((_DWORD *)dword_1E55F8 + 6 * v3 + 2) > k; ++j ) /*0x1ceea7*/
        *j = v8 + 16 * k++; /*0x1ceec4*/
    }
    *j = 0; /*0x1ceede*/
  }
  return dword_1E874C; /*0x1ceeec*/
}
