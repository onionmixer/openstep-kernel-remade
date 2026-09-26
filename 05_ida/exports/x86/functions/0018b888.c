/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b888. */
int spl3()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18b893*/
  v0 = dword_1E7714; /*0x18b894*/
  dword_1E7714 = 3; /*0x18b899*/
  v1 = v0; /*0x18b8a3*/
  if ( v0 > 3 ) /*0x18b8a7*/
  {
    for ( i = &dword_1E76F4[v0]; i > &dword_1E7700; --i ) /*0x18b8ba*/
    {
      v3 = *i; /*0x18b8bc*/
      if ( *i ) /*0x18b8bc*/
      {
        *i = 0; /*0x18b8c2*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18b8cb*/
        _enable(); /*0x18b8d1*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, 3); /*0x18b8dc*/
        _disable(); /*0x18b8e1*/
      }
    }
    dword_1E7714 = 3; /*0x18b8ed*/
    if ( dword_1E7718 > 3 ) /*0x18b8fd*/
    {
      v4 = word_1E771E | word_1E76EA; /*0x18b906*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | (unsigned __int16)word_1E76EA) ) /*0x18b914*/
      {
        word_1E771C = word_1E771E | word_1E76EA; /*0x18b916*/
        __outbyte(0x21u, v4); /*0x18b924*/
        _InterlockedIncrement(dword_1E7618); /*0x18b925*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18b937*/
        _InterlockedIncrement(dword_1E7618); /*0x18b938*/
      }
      dword_1E7718 = 3; /*0x18b93f*/
    }
  }
  _enable(); /*0x18b949*/
  return v1; /*0x18b94f*/
}
