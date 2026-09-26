/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b988. */
int spldevice()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18b993*/
  v0 = dword_1E7714; /*0x18b994*/
  dword_1E7714 = 3; /*0x18b999*/
  v1 = v0; /*0x18b9a3*/
  if ( v0 > 3 ) /*0x18b9a7*/
  {
    for ( i = &dword_1E76F4[v0]; i > &dword_1E7700; --i ) /*0x18b9ba*/
    {
      v3 = *i; /*0x18b9bc*/
      if ( *i ) /*0x18b9bc*/
      {
        *i = 0; /*0x18b9c2*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18b9cb*/
        _enable(); /*0x18b9d1*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, 3); /*0x18b9dc*/
        _disable(); /*0x18b9e1*/
      }
    }
    dword_1E7714 = 3; /*0x18b9ed*/
    if ( dword_1E7718 > 3 ) /*0x18b9fd*/
    {
      v4 = word_1E771E | word_1E76EA; /*0x18ba06*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | (unsigned __int16)word_1E76EA) ) /*0x18ba14*/
      {
        word_1E771C = word_1E771E | word_1E76EA; /*0x18ba16*/
        __outbyte(0x21u, v4); /*0x18ba24*/
        _InterlockedIncrement(dword_1E7618); /*0x18ba25*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18ba37*/
        _InterlockedIncrement(dword_1E7618); /*0x18ba38*/
      }
      dword_1E7718 = 3; /*0x18ba3f*/
    }
  }
  _enable(); /*0x18ba49*/
  return v1; /*0x18ba4f*/
}
