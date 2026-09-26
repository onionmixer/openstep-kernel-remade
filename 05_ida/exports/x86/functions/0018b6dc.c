/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b6dc. */
int spl1()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18b6e7*/
  v0 = dword_1E7714; /*0x18b6e8*/
  dword_1E7714 = 1; /*0x18b6ed*/
  v1 = v0; /*0x18b6f7*/
  if ( v0 > 1 ) /*0x18b6fb*/
  {
    for ( i = &dword_1E76F4[v0]; i > &dword_1E76F8; --i ) /*0x18b70e*/
    {
      v3 = *i; /*0x18b710*/
      if ( *i ) /*0x18b710*/
      {
        *i = 0; /*0x18b716*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18b71f*/
        _enable(); /*0x18b725*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, 1); /*0x18b730*/
        _disable(); /*0x18b735*/
      }
    }
    dword_1E7714 = 1; /*0x18b741*/
    if ( dword_1E7718 > 1 ) /*0x18b751*/
    {
      v4 = word_1E771E | word_1E76E6; /*0x18b75a*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | (unsigned __int16)word_1E76E6) ) /*0x18b768*/
      {
        word_1E771C = word_1E771E | word_1E76E6; /*0x18b76a*/
        __outbyte(0x21u, v4); /*0x18b778*/
        _InterlockedIncrement(dword_1E7618); /*0x18b779*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18b78b*/
        _InterlockedIncrement(dword_1E7618); /*0x18b78c*/
      }
      dword_1E7718 = 1; /*0x18b793*/
    }
  }
  _enable(); /*0x18b79d*/
  return v1; /*0x18b7a3*/
}
