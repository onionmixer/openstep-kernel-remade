/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c0d8. */
int splhigh()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18c0e3*/
  v0 = dword_1E7714; /*0x18c0e4*/
  dword_1E7714 = 7; /*0x18c0e9*/
  v1 = v0; /*0x18c0f3*/
  if ( v0 > 7 ) /*0x18c0f7*/
  {
    for ( i = &dword_1E76F4[v0]; i > &dword_1E7710; --i ) /*0x18c10a*/
    {
      v3 = *i; /*0x18c10c*/
      if ( *i ) /*0x18c10c*/
      {
        *i = 0; /*0x18c112*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18c11b*/
        _enable(); /*0x18c121*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, 7); /*0x18c12c*/
        _disable(); /*0x18c131*/
      }
    }
    dword_1E7714 = 7; /*0x18c13d*/
    if ( dword_1E7718 > 7 ) /*0x18c14d*/
    {
      v4 = word_1E771E | word_1E76F2; /*0x18c156*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | (unsigned __int16)word_1E76F2) ) /*0x18c164*/
      {
        word_1E771C = word_1E771E | word_1E76F2; /*0x18c166*/
        __outbyte(0x21u, v4); /*0x18c174*/
        _InterlockedIncrement(dword_1E7618); /*0x18c175*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18c187*/
        _InterlockedIncrement(dword_1E7618); /*0x18c188*/
      }
      dword_1E7718 = 7; /*0x18c18f*/
    }
  }
  _enable(); /*0x18c199*/
  return v1; /*0x18c19f*/
}
