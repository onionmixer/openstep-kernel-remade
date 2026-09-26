/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19ab88. */
char __cdecl sub_19AB88(int a1, unsigned int a2, int a3, int a4, const char *a5)
{
  int v5; // edi
  int i; // esi
  int j; // esi
  unsigned __int8 v8; // al
  unsigned __int8 v9; // al
  int k; // esi
  unsigned __int8 v11; // cl
  int v12; // esi
  unsigned __int8 v13; // cl
  _BYTE *v14; // ebx
  int ii; // esi
  int m; // esi
  _BYTE *v17; // ecx
  char result; // al
  int v19; // [esp+Ch] [ebp-1Ch]
  int n; // [esp+14h] [ebp-14h]
  unsigned __int8 v21; // [esp+18h] [ebp-10h]
  unsigned __int8 v22; // [esp+1Ch] [ebp-Ch]
  int v23; // [esp+20h] [ebp-8h]

  v5 = *(_DWORD *)(a1 + 28); /*0x19ab97*/
  *(_DWORD *)(v5 + 176) = 3; /*0x19ab9a*/
  *(_DWORD *)(v5 + 188) = 2; /*0x19aba4*/
  *(_DWORD *)(v5 + 184) = 1; /*0x19abae*/
  *(_DWORD *)(v5 + 180) = 0; /*0x19abb8*/
  *(_DWORD *)(v5 + 172) = *(_DWORD *)(v5 + 184); /*0x19abc8*/
  *(_DWORD *)(v5 + 244) = 0; /*0x19abce*/
  for ( i = 2; i >= 0; --i ) /*0x19abd8*/
    *(_BYTE *)(i + v5 + 248) = 0; /*0x19abe0*/
  *(_DWORD *)(v5 + 252) = v5 + 249; /*0x19abf1*/
  for ( j = 0; j <= 8; ++j ) /*0x19abfd*/
  {
    __outbyte(0x3CEu, j); /*0x19ac09*/
    _InterlockedIncrement(&dword_1E8654); /*0x19ac0a*/
    v8 = __inbyte(0x3CFu); /*0x19ac16*/
    *(_BYTE *)(j + v5 + 216) = v8; /*0x19ac17*/
  }
  __outbyte(0x3C4u, 2u); /*0x19ac27*/
  _InterlockedIncrement(&dword_1E8654); /*0x19ac28*/
  v9 = __inbyte(0x3C5u); /*0x19ac34*/
  *(_BYTE *)(v5 + 227) = v9; /*0x19ac35*/
  if ( a2 - 1 <= 1 && a3 ) /*0x19ac43*/
    VGASetGraphicsMode(); /*0x19ac45*/
  __outbyte(0x3C4u, 2u); /*0x19ac51*/
  _InterlockedIncrement(&dword_1E8654); /*0x19ac52*/
  __outbyte(0x3C5u, 0xFu); /*0x19ac60*/
  _InterlockedIncrement(&dword_1E8654); /*0x19ac61*/
  for ( k = 0; k <= 8; ++k ) /*0x19ac68*/
  {
    v11 = byte_1E467C[k]; /*0x19ac71*/
    __outbyte(0x3CEu, k); /*0x19ac7c*/
    _InterlockedIncrement(&dword_1E8654); /*0x19ac7d*/
    __outbyte(0x3CFu, v11); /*0x19ac8b*/
    _InterlockedIncrement(&dword_1E8654); /*0x19ac8c*/
  }
  if ( a3 && *(_DWORD *)v5 != 3 ) /*0x19aca4*/
  {
    v12 = *(_DWORD *)(v5 + 8); /*0x19acaa*/
    v23 = *(_DWORD *)(v5 + 16); /*0x19acb0*/
    v13 = *(_BYTE *)(v5 + 172); /*0x19acb3*/
    __outbyte(0x3CEu, 0); /*0x19acc0*/
    _InterlockedIncrement(&dword_1E8654); /*0x19acc1*/
    __outbyte(0x3CFu, v13); /*0x19accf*/
    _InterlockedIncrement(&dword_1E8654); /*0x19acd0*/
    __outbyte(0x3CEu, 8u); /*0x19acde*/
    _InterlockedIncrement(&dword_1E8654); /*0x19acdf*/
    v22 = byte_1E4685[0]; /*0x19acf5*/
    v21 = byte_1E468D[*(_DWORD *)(v5 + 12) & 7]; /*0x19ad04*/
    v14 = *(_BYTE **)(v5 + 24); /*0x19ad07*/
    v19 = (*(int *)(v5 + 12) >> 3) - 1; /*0x19ad0e*/
    if ( *(int *)(v5 + 12) >> 3 ) /*0x19acec*/
    {
      for ( m = v12 - 1; m >= 0; --m ) /*0x19ad3d*/
      {
        __outbyte(0x3CFu, v22); /*0x19ad4d*/
        _InterlockedIncrement(&dword_1E8654); /*0x19ad4e*/
        *v14 = -1; /*0x19ad55*/
        v17 = v14 + 1; /*0x19ad58*/
        __outbyte(0x3CFu, 0xFFu); /*0x19ad5d*/
        _InterlockedIncrement(&dword_1E8654); /*0x19ad5e*/
        for ( n = v19 - 1; n >= 0; --n ) /*0x19ad6c*/
          *v17++ = -1; /*0x19ad70*/
        __outbyte(0x3CFu, v21); /*0x19ad81*/
        _InterlockedIncrement(&dword_1E8654); /*0x19ad82*/
        *v17 = -1; /*0x19ad8e*/
        v14 += v23; /*0x19ad91*/
      }
    }
    else
    {
      __outbyte(0x3CFu, byte_1E4685[0] & byte_1E468D[*(_DWORD *)(v5 + 12) & 7]); /*0x19ad20*/
      _InterlockedIncrement(&dword_1E8654); /*0x19ad21*/
      for ( ii = v12 - 1; ii >= 0; --ii ) /*0x19ad29*/
      {
        *v14 = -1; /*0x19ad31*/
        v14 += v23; /*0x19ad34*/
      }
    }
    __outbyte(0x3CFu, 0xFFu); /*0x19ad9e*/
    _InterlockedIncrement(&dword_1E8654); /*0x19ad9f*/
  }
  result = a2; /*0x19ada6*/
  *(_DWORD *)v5 = a2; /*0x19ada9*/
  if ( a2 != 2 ) /*0x19adae*/
  {
    if ( a2 > 2 ) /*0x19adb0*/
    {
      if ( a2 != 3 ) /*0x19adc0*/
LABEL_29:
        panic(aVgaconsoleVgai); /*0x19adf8*/
      return sub_1995A4(v5, 320, 200, a5, a4, 1); /*0x19adf1*/
    }
    else
    {
      if ( a2 != 1 ) /*0x19adb5*/
        goto LABEL_29; /*0x19adb5*/
      return sub_1995A4(v5, 600, 450, a5, a4, 0); /*0x19add8*/
    }
  }
  return result; /*0x19ae05*/
}
