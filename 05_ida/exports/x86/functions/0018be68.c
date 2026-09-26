/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18be68. */
int __cdecl splsched()
{
  int v0; // eax
  int v1; // esi
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx

  _disable(); /*0x18be73*/
  v0 = dword_1E7714; /*0x18be74*/
  dword_1E7714 = 6; /*0x18be79*/
  v1 = v0; /*0x18be83*/
  if ( v0 > 6 ) /*0x18be87*/
  {
    for ( i = &dword_1E76F4[v0]; i > &dword_1E770C; --i ) /*0x18be9a*/
    {
      v3 = *i; /*0x18be9c*/
      if ( *i ) /*0x18be9c*/
      {
        *i = 0; /*0x18bea2*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18beab*/
        _enable(); /*0x18beb1*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, 6); /*0x18bebc*/
        _disable(); /*0x18bec1*/
      }
    }
    dword_1E7714 = 6; /*0x18becd*/
    if ( dword_1E7718 > 6 ) /*0x18bedd*/
    {
      v4 = word_1E771E | word_1E76F0; /*0x18bee6*/
      if ( word_1E771C != ((unsigned __int16)word_1E771E | (unsigned __int16)word_1E76F0) ) /*0x18bef4*/
      {
        word_1E771C = word_1E771E | word_1E76F0; /*0x18bef6*/
        __outbyte(0x21u, v4); /*0x18bf04*/
        _InterlockedIncrement(dword_1E7618); /*0x18bf05*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18bf17*/
        _InterlockedIncrement(dword_1E7618); /*0x18bf18*/
      }
      dword_1E7718 = 6; /*0x18bf1f*/
    }
  }
  _enable(); /*0x18bf29*/
  return v1; /*0x18bf2f*/
}
