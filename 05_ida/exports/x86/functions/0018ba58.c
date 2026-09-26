/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ba58. */
int spl4()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18ba63*/
  v0 = dword_1E7714; /*0x18ba64*/
  dword_1E7714 = 4; /*0x18ba69*/
  v1 = v0; /*0x18ba73*/
  if ( v0 > 4 ) /*0x18ba77*/
  {
    for ( i = &dword_1E76F4[v0]; i > &dword_1E7704; --i ) /*0x18ba8a*/
    {
      v3 = *i; /*0x18ba8c*/
      if ( *i ) /*0x18ba8c*/
      {
        *i = 0; /*0x18ba92*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18ba9b*/
        _enable(); /*0x18baa1*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, 4); /*0x18baac*/
        _disable(); /*0x18bab1*/
      }
    }
    dword_1E7714 = 4; /*0x18babd*/
    if ( dword_1E7718 > 4 ) /*0x18bacd*/
    {
      v4 = word_1E771E | word_1E76EC; /*0x18bad6*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | (unsigned __int16)word_1E76EC) ) /*0x18bae4*/
      {
        word_1E771C = word_1E771E | word_1E76EC; /*0x18bae6*/
        __outbyte(0x21u, v4); /*0x18baf4*/
        _InterlockedIncrement(dword_1E7618); /*0x18baf5*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18bb07*/
        _InterlockedIncrement(dword_1E7618); /*0x18bb08*/
      }
      dword_1E7718 = 4; /*0x18bb0f*/
    }
  }
  _enable(); /*0x18bb19*/
  return v1; /*0x18bb1f*/
}
