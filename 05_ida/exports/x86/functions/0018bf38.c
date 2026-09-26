/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18bf38. */
int splclock()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18bf43*/
  v0 = dword_1E7714; /*0x18bf44*/
  dword_1E7714 = 6; /*0x18bf49*/
  v1 = v0; /*0x18bf53*/
  if ( v0 > 6 ) /*0x18bf57*/
  {
    for ( i = &dword_1E76F4[v0]; i > &dword_1E770C; --i ) /*0x18bf6a*/
    {
      v3 = *i; /*0x18bf6c*/
      if ( *i ) /*0x18bf6c*/
      {
        *i = 0; /*0x18bf72*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18bf7b*/
        _enable(); /*0x18bf81*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, 6); /*0x18bf8c*/
        _disable(); /*0x18bf91*/
      }
    }
    dword_1E7714 = 6; /*0x18bf9d*/
    if ( dword_1E7718 > 6 ) /*0x18bfad*/
    {
      v4 = word_1E771E | word_1E76F0; /*0x18bfb6*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | (unsigned __int16)word_1E76F0) ) /*0x18bfc4*/
      {
        word_1E771C = word_1E771E | word_1E76F0; /*0x18bfc6*/
        __outbyte(0x21u, v4); /*0x18bfd4*/
        _InterlockedIncrement(dword_1E7618); /*0x18bfd5*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18bfe7*/
        _InterlockedIncrement(dword_1E7618); /*0x18bfe8*/
      }
      dword_1E7718 = 6; /*0x18bfef*/
    }
  }
  _enable(); /*0x18bff9*/
  return v1; /*0x18bfff*/
}
