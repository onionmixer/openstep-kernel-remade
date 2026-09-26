/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b60c. */
int spl0()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18b614*/
  v0 = dword_1E7714; /*0x18b615*/
  dword_1E7714 = 0; /*0x18b61a*/
  v1 = v0; /*0x18b624*/
  if ( v0 > 0 ) /*0x18b628*/
  {
    for ( i = &dword_1E76F4[v0]; i > dword_1E76F4; --i ) /*0x18b63b*/
    {
      v3 = *i; /*0x18b640*/
      if ( *i ) /*0x18b640*/
      {
        *i = 0; /*0x18b646*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18b64f*/
        _enable(); /*0x18b655*/
        (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD))(v3 + 4))(*(_DWORD *)v3, 0, 0); /*0x18b660*/
        _disable(); /*0x18b665*/
      }
    }
    dword_1E7714 = 0; /*0x18b671*/
    if ( dword_1E7718 > 0 ) /*0x18b681*/
    {
      v4 = word_1E771E | word_1E76E4[0]; /*0x18b68a*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | word_1E76E4[0]) ) /*0x18b698*/
      {
        word_1E771C = word_1E771E | word_1E76E4[0]; /*0x18b69a*/
        __outbyte(0x21u, v4); /*0x18b6a8*/
        _InterlockedIncrement(dword_1E7618); /*0x18b6a9*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18b6bb*/
        _InterlockedIncrement(dword_1E7618); /*0x18b6bc*/
      }
      dword_1E7718 = 0; /*0x18b6c3*/
    }
  }
  _enable(); /*0x18b6cd*/
  return v1; /*0x18b6d3*/
}
