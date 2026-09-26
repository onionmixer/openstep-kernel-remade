/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18bb28. */
int spl5()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18bb33*/
  v0 = dword_1E7714; /*0x18bb34*/
  dword_1E7714 = 5; /*0x18bb39*/
  v1 = v0; /*0x18bb43*/
  if ( v0 > 5 ) /*0x18bb47*/
  {
    for ( i = &dword_1E76F4[v0]; i > &dword_1E7708; --i ) /*0x18bb5a*/
    {
      v3 = *i; /*0x18bb5c*/
      if ( *i ) /*0x18bb5c*/
      {
        *i = 0; /*0x18bb62*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18bb6b*/
        _enable(); /*0x18bb71*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, 5); /*0x18bb7c*/
        _disable(); /*0x18bb81*/
      }
    }
    dword_1E7714 = 5; /*0x18bb8d*/
    if ( dword_1E7718 > 5 ) /*0x18bb9d*/
    {
      v4 = word_1E771E | word_1E76EE; /*0x18bba6*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | (unsigned __int16)word_1E76EE) ) /*0x18bbb4*/
      {
        word_1E771C = word_1E771E | word_1E76EE; /*0x18bbb6*/
        __outbyte(0x21u, v4); /*0x18bbc4*/
        _InterlockedIncrement(dword_1E7618); /*0x18bbc5*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18bbd7*/
        _InterlockedIncrement(dword_1E7618); /*0x18bbd8*/
      }
      dword_1E7718 = 5; /*0x18bbdf*/
    }
  }
  _enable(); /*0x18bbe9*/
  return v1; /*0x18bbef*/
}
