/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18bbf8. */
int spl6()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18bc03*/
  v0 = dword_1E7714; /*0x18bc04*/
  dword_1E7714 = 6; /*0x18bc09*/
  v1 = v0; /*0x18bc13*/
  if ( v0 > 6 ) /*0x18bc17*/
  {
    for ( i = &dword_1E76F4[v0]; i > &dword_1E770C; --i ) /*0x18bc2a*/
    {
      v3 = *i; /*0x18bc2c*/
      if ( *i ) /*0x18bc2c*/
      {
        *i = 0; /*0x18bc32*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18bc3b*/
        _enable(); /*0x18bc41*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, 6); /*0x18bc4c*/
        _disable(); /*0x18bc51*/
      }
    }
    dword_1E7714 = 6; /*0x18bc5d*/
    if ( dword_1E7718 > 6 ) /*0x18bc6d*/
    {
      v4 = word_1E771E | word_1E76F0; /*0x18bc76*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | (unsigned __int16)word_1E76F0) ) /*0x18bc84*/
      {
        word_1E771C = word_1E771E | word_1E76F0; /*0x18bc86*/
        __outbyte(0x21u, v4); /*0x18bc94*/
        _InterlockedIncrement(dword_1E7618); /*0x18bc95*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18bca7*/
        _InterlockedIncrement(dword_1E7618); /*0x18bca8*/
      }
      dword_1E7718 = 6; /*0x18bcaf*/
    }
  }
  _enable(); /*0x18bcb9*/
  return v1; /*0x18bcbf*/
}
