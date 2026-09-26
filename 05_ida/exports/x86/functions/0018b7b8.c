/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b7b8. */
int spl2()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18b7c3*/
  v0 = dword_1E7714; /*0x18b7c4*/
  dword_1E7714 = 2; /*0x18b7c9*/
  v1 = v0; /*0x18b7d3*/
  if ( v0 > 2 ) /*0x18b7d7*/
  {
    for ( i = &dword_1E76F4[v0]; i > &dword_1E76FC; --i ) /*0x18b7ea*/
    {
      v3 = *i; /*0x18b7ec*/
      if ( *i ) /*0x18b7ec*/
      {
        *i = 0; /*0x18b7f2*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18b7fb*/
        _enable(); /*0x18b801*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, 2); /*0x18b80c*/
        _disable(); /*0x18b811*/
      }
    }
    dword_1E7714 = 2; /*0x18b81d*/
    if ( dword_1E7718 > 2 ) /*0x18b82d*/
    {
      v4 = word_1E771E | word_1E76E8; /*0x18b836*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | (unsigned __int16)word_1E76E8) ) /*0x18b844*/
      {
        word_1E771C = word_1E771E | word_1E76E8; /*0x18b846*/
        __outbyte(0x21u, v4); /*0x18b854*/
        _InterlockedIncrement(dword_1E7618); /*0x18b855*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18b867*/
        _InterlockedIncrement(dword_1E7618); /*0x18b868*/
      }
      dword_1E7718 = 2; /*0x18b86f*/
    }
  }
  _enable(); /*0x18b879*/
  return v1; /*0x18b87f*/
}
