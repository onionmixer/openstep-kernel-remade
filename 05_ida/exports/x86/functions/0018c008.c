/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c008. */
int spl7()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18c013*/
  v0 = dword_1E7714; /*0x18c014*/
  dword_1E7714 = 7; /*0x18c019*/
  v1 = v0; /*0x18c023*/
  if ( v0 > 7 ) /*0x18c027*/
  {
    for ( i = &dword_1E76F4[v0]; i > &dword_1E7710; --i ) /*0x18c03a*/
    {
      v3 = *i; /*0x18c03c*/
      if ( *i ) /*0x18c03c*/
      {
        *i = 0; /*0x18c042*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18c04b*/
        _enable(); /*0x18c051*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, 7); /*0x18c05c*/
        _disable(); /*0x18c061*/
      }
    }
    dword_1E7714 = 7; /*0x18c06d*/
    if ( dword_1E7718 > 7 ) /*0x18c07d*/
    {
      v4 = word_1E771E | word_1E76F2; /*0x18c086*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | (unsigned __int16)word_1E76F2) ) /*0x18c094*/
      {
        word_1E771C = word_1E771E | word_1E76F2; /*0x18c096*/
        __outbyte(0x21u, v4); /*0x18c0a4*/
        _InterlockedIncrement(dword_1E7618); /*0x18c0a5*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18c0b7*/
        _InterlockedIncrement(dword_1E7618); /*0x18c0b8*/
      }
      dword_1E7718 = 7; /*0x18c0bf*/
    }
  }
  _enable(); /*0x18c0c9*/
  return v1; /*0x18c0cf*/
}
