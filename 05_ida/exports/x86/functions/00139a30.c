/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x139a30. */
int __cdecl sub_139A30(__int16 a1, int a2, int a3)
{
  int v3; // ecx
  int i; // ebx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v9; // [esp+Ch] [ebp-4h]

  LOWORD(v3) = a1; /*0x139a3f*/
  for ( i = stable[((_BYTE)a1 + HIBYTE(a1)) & 0xF]; i; i = *(_DWORD *)i ) /*0x139a58*/
  {
    if ( *(_WORD *)(i + 66) == (_WORD)v3 && *(_DWORD *)(i + 44) == a3 ) /*0x139a65*/
    {
      v5 = *(_DWORD *)(i + 56); /*0x139a67*/
      if ( !v5 ) /*0x139a6c*/
        goto LABEL_10; /*0x139a6c*/
      if ( a2 ) /*0x139a70*/
      {
        if ( v5 == a2 /*0x139a94*/
          || (v6 = *(_DWORD *)(v5 + 28), *(_DWORD *)(a2 + 28) == v6)
          && (v9 = v3, v7 = (*(int (__cdecl **)(int, int))(v6 + 108))(v5, a2), v3 = v9, v7) )
        {
LABEL_11:
          ++*(_WORD *)(i + 10); /*0x139aa0*/
          return i; /*0x139aa6*/
        }
      }
      if ( !*(_DWORD *)(i + 56) ) /*0x139a96*/
      {
LABEL_10:
        if ( !a2 ) /*0x139a9e*/
          goto LABEL_11; /*0x139a9e*/
      }
    }
  }
  return 0; /*0x139ab3*/
}
