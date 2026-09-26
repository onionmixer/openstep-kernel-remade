/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18bcc8. */
int spldma()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18bcd3*/
  v0 = dword_1E7714; /*0x18bcd4*/
  dword_1E7714 = 6; /*0x18bcd9*/
  v1 = v0; /*0x18bce3*/
  if ( v0 > 6 ) /*0x18bce7*/
  {
    for ( i = &dword_1E76F4[v0]; i > &dword_1E770C; --i ) /*0x18bcfa*/
    {
      v3 = *i; /*0x18bcfc*/
      if ( *i ) /*0x18bcfc*/
      {
        *i = 0; /*0x18bd02*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18bd0b*/
        _enable(); /*0x18bd11*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, 6); /*0x18bd1c*/
        _disable(); /*0x18bd21*/
      }
    }
    dword_1E7714 = 6; /*0x18bd2d*/
    if ( dword_1E7718 > 6 ) /*0x18bd3d*/
    {
      v4 = word_1E771E | word_1E76F0; /*0x18bd46*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | (unsigned __int16)word_1E76F0) ) /*0x18bd54*/
      {
        word_1E771C = word_1E771E | word_1E76F0; /*0x18bd56*/
        __outbyte(0x21u, v4); /*0x18bd64*/
        _InterlockedIncrement(dword_1E7618); /*0x18bd65*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18bd77*/
        _InterlockedIncrement(dword_1E7618); /*0x18bd78*/
      }
      dword_1E7718 = 6; /*0x18bd7f*/
    }
  }
  _enable(); /*0x18bd89*/
  return v1; /*0x18bd8f*/
}
