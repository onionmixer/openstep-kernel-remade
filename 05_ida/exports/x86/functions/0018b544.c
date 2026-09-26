/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b544. */
int __cdecl splx(int a1)
{
  int v1; // eax
  int *i; // ebx
  int v3; // eax
  __int16 v4; // cx
  int v6; // [esp+Ch] [ebp-4h]

  _disable(); /*0x18b550*/
  v1 = dword_1E7714; /*0x18b551*/
  dword_1E7714 = a1; /*0x18b556*/
  v6 = v1; /*0x18b55c*/
  if ( a1 < v1 ) /*0x18b561*/
  {
    for ( i = &dword_1E76F4[v1]; i > &dword_1E76F4[a1]; --i ) /*0x18b577*/
    {
      v3 = *i; /*0x18b57c*/
      if ( *i ) /*0x18b57c*/
      {
        *i = 0; /*0x18b582*/
        dword_1E7714 = *(_DWORD *)(v3 + 8); /*0x18b58b*/
        _enable(); /*0x18b591*/
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(v3 + 4))(*(_DWORD *)v3, 0, a1); /*0x18b59b*/
        _disable(); /*0x18b5a0*/
      }
    }
    dword_1E7714 = a1; /*0x18b5a8*/
    if ( dword_1E7718 > a1 ) /*0x18b5b4*/
    {
      v4 = word_1E771E | word_1E76E4[a1]; /*0x18b5be*/
      if ( word_1E771C != v4 ) /*0x18b5cc*/
      {
        word_1E771C = word_1E771E | word_1E76E4[a1]; /*0x18b5ce*/
        __outbyte(0x21u, v4); /*0x18b5dc*/
        _InterlockedIncrement(dword_1E7618); /*0x18b5dd*/
        __outbyte(0xA1u, HIBYTE(v4)); /*0x18b5ef*/
        _InterlockedIncrement(dword_1E7618); /*0x18b5f0*/
      }
      dword_1E7718 = a1; /*0x18b5f7*/
    }
  }
  _enable(); /*0x18b5fd*/
  return v6; /*0x18b604*/
}
