/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c1a8. */
int __cdecl spln(int a1)
{
  int v1; // eax
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx
  int v6; // [esp+Ch] [ebp-4h]

  _disable(); /*0x18c1b4*/
  v1 = dword_1E7714; /*0x18c1b5*/
  dword_1E7714 = a1; /*0x18c1ba*/
  v6 = v1; /*0x18c1c0*/
  if ( a1 < v1 ) /*0x18c1c5*/
  {
    for ( i = &dword_1E76F4[v1]; i > &dword_1E76F4[a1]; --i ) /*0x18c1db*/
    {
      v3 = *i; /*0x18c1e0*/
      if ( *i ) /*0x18c1e0*/
      {
        *i = 0; /*0x18c1e6*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18c1ef*/
        _enable(); /*0x18c1f5*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, a1); /*0x18c1ff*/
        _disable(); /*0x18c204*/
      }
    }
    dword_1E7714 = a1; /*0x18c20c*/
    if ( dword_1E7718 > a1 ) /*0x18c218*/
    {
      v4 = word_1E771E | word_1E76E4[a1]; /*0x18c222*/
      if ( word_1E771C != v4 ) /*0x18c230*/
      {
        word_1E771C = word_1E771E | word_1E76E4[a1]; /*0x18c232*/
        __outbyte(0x21u, v4); /*0x18c240*/
        _InterlockedIncrement(dword_1E7618); /*0x18c241*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18c253*/
        _InterlockedIncrement(dword_1E7618); /*0x18c254*/
      }
      dword_1E7718 = a1; /*0x18c25b*/
    }
  }
  _enable(); /*0x18c261*/
  return v6; /*0x18c268*/
}
