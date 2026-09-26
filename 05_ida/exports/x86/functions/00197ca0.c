/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x197ca0. */
char __cdecl sub_197CA0(int a1)
{
  int v1; // ecx
  unsigned __int8 *v2; // ecx
  int i; // edi
  int v5; // [esp+Ch] [ebp-10h]
  unsigned __int8 v6; // [esp+10h] [ebp-Ch]
  unsigned __int8 v7; // [esp+10h] [ebp-Ch]
  unsigned __int8 v8; // [esp+14h] [ebp-8h]
  unsigned __int8 v9; // [esp+1Bh] [ebp-1h]

  v5 = *(_DWORD *)(a1 + 144) + 12 * *(_DWORD *)(a1 + 164); /*0x197cbe*/
  v1 = *(_DWORD *)(a1 + 140) + 8 * *(_DWORD *)(a1 + 168); /*0x197cd3*/
  __outbyte(0x3CEu, 7u); /*0x197ce0*/
  _InterlockedIncrement(&dword_1E8654); /*0x197ce1*/
  __outbyte(0x3CFu, 0xFu); /*0x197cef*/
  _InterlockedIncrement(&dword_1E8654); /*0x197cf0*/
  __outbyte(0x3CEu, 5u); /*0x197cfe*/
  _InterlockedIncrement(&dword_1E8654); /*0x197cff*/
  __outbyte(0x3CFu, 8u); /*0x197d0d*/
  _InterlockedIncrement(&dword_1E8654); /*0x197d0e*/
  v8 = *(_BYTE *)(a1 + 176); /*0x197d1b*/
  __outbyte(0x3CEu, 2u); /*0x197d25*/
  _InterlockedIncrement(&dword_1E8654); /*0x197d26*/
  __outbyte(0x3CFu, v8); /*0x197d35*/
  _InterlockedIncrement(&dword_1E8654); /*0x197d36*/
  v2 = (unsigned __int8 *)(*(_DWORD *)(a1 + 24) + *(_DWORD *)(a1 + 16) * v5 + (v1 >> 3)); /*0x197d4a*/
  for ( i = v5; i < v5 + 12; ++i ) /*0x197d51*/
  {
    v9 = *v2; /*0x197d5a*/
    v6 = *(_BYTE *)(a1 + 176); /*0x197d63*/
    __outbyte(0x3CEu, 0); /*0x197d6d*/
    _InterlockedIncrement(&dword_1E8654); /*0x197d6e*/
    __outbyte(0x3CFu, v6); /*0x197d7d*/
    _InterlockedIncrement(&dword_1E8654); /*0x197d7e*/
    __outbyte(0x3CEu, 8u); /*0x197d94*/
    _InterlockedIncrement(&dword_1E8654); /*0x197d95*/
    __outbyte(0x3CFu, ~v9); /*0x197da4*/
    _InterlockedIncrement(&dword_1E8654); /*0x197da5*/
    *v2 = -1; /*0x197dac*/
    v7 = *(_BYTE *)(a1 + 180); /*0x197db5*/
    __outbyte(0x3CEu, 0); /*0x197dbf*/
    _InterlockedIncrement(&dword_1E8654); /*0x197dc0*/
    __outbyte(0x3CFu, v7); /*0x197dcf*/
    _InterlockedIncrement(&dword_1E8654); /*0x197dd0*/
    __outbyte(0x3CEu, 8u); /*0x197de4*/
    _InterlockedIncrement(&dword_1E8654); /*0x197de5*/
    __outbyte(0x3CFu, v9); /*0x197df4*/
    _InterlockedIncrement(&dword_1E8654); /*0x197df5*/
    *v2 = -1; /*0x197e01*/
    v2 += *(_DWORD *)(a1 + 16); /*0x197e04*/
  }
  __outbyte(0x3CEu, 5u); /*0x197e17*/
  _InterlockedIncrement(&dword_1E8654); /*0x197e18*/
  __outbyte(0x3CFu, 0); /*0x197e26*/
  _InterlockedIncrement(&dword_1E8654); /*0x197e27*/
  __outbyte(0x3CEu, 8u); /*0x197e35*/
  _InterlockedIncrement(&dword_1E8654); /*0x197e36*/
  __outbyte(0x3CFu, 0xFFu); /*0x197e44*/
  _InterlockedIncrement(&dword_1E8654); /*0x197e45*/
  return -1; /*0x197e4f*/
}
