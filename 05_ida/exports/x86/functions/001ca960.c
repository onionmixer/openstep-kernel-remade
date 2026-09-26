/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca960. */
_DWORD *__cdecl sub_1CA960(int a1)
{
  _DWORD *v1; // edx

  do /*0x1ca981*/
  {
    while ( dword_1E5534 ) /*0x1ca96f*/
      ; /*0x1ca968*/
  }
  while ( _InterlockedExchange(&dword_1E5534, 1) == 1 ); /*0x1ca981*/
  v1 = &unk_1E551C; /*0x1ca983*/
  if ( &unk_1E551C ) /*0x1ca98a*/
  {
    while ( v1[4] ) /*0x1ca990*/
    {
      v1 = (_DWORD *)v1[5]; /*0x1ca998*/
      if ( !v1 ) /*0x1ca99d*/
        goto LABEL_7; /*0x1ca99d*/
    }
    v1[4] = a1; /*0x1ca992*/
  }
  else
  {
LABEL_7:
    v1 = calloc(0x18u, 1u); /*0x1ca99f*/
    v1[4] = a1; /*0x1ca9aa*/
    v1[5] = dword_1E5530; /*0x1ca9b3*/
    dword_1E5530 = (int)v1; /*0x1ca9b6*/
  }
  _InterlockedExchange(&dword_1E5534, 0); /*0x1ca9be*/
  return v1; /*0x1ca9c6*/
}
