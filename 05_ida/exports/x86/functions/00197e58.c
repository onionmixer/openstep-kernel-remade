/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x197e58. */
char __cdecl sub_197E58(int a1, char a2)
{
  unsigned __int8 v2; // bl
  int v3; // ebx
  int i; // esi
  int j; // esi
  _BYTE *v6; // ecx
  char result; // al
  unsigned __int8 *v8; // ebx
  int v9; // ecx
  _BYTE *v10; // esi
  int v11; // ecx
  unsigned __int8 v12; // al
  int v13; // [esp+Ch] [ebp-24h]
  _BYTE *v14; // [esp+Ch] [ebp-24h]
  unsigned __int8 v15; // [esp+Ch] [ebp-24h]
  int v16; // [esp+10h] [ebp-20h]
  int k; // [esp+10h] [ebp-20h]
  int v18; // [esp+10h] [ebp-20h]
  unsigned __int8 v19; // [esp+18h] [ebp-18h]
  unsigned __int8 v20; // [esp+1Ch] [ebp-14h]
  int v21; // [esp+20h] [ebp-10h]

  v13 = *(_DWORD *)(a1 + 144) + 12 * *(_DWORD *)(a1 + 164); /*0x197e82*/
  v16 = *(_DWORD *)(a1 + 140) + 8 * *(_DWORD *)(a1 + 168); /*0x197e97*/
  v21 = *(_DWORD *)(a1 + 16); /*0x197ea2*/
  v2 = *(_BYTE *)(a1 + 176); /*0x197ea5*/
  __outbyte(0x3CEu, 0); /*0x197eb2*/
  _InterlockedIncrement(&dword_1E8654); /*0x197eb3*/
  __outbyte(0x3CFu, v2); /*0x197ec1*/
  _InterlockedIncrement(&dword_1E8654); /*0x197ec2*/
  __outbyte(0x3CEu, 8u); /*0x197ed0*/
  _InterlockedIncrement(&dword_1E8654); /*0x197ed1*/
  v20 = byte_1E4685[v16 & 7]; /*0x197eef*/
  v19 = byte_1E468D[(v16 + 8) & 7]; /*0x197efb*/
  v14 = (_BYTE *)((v16 >> 3) + *(_DWORD *)(a1 + 24) + v21 * v13); /*0x197f0a*/
  v3 = ((v16 + 8) >> 3) - (v16 >> 3) - 1; /*0x197f0f*/
  if ( (v16 + 8) >> 3 == v16 >> 3 ) /*0x197f0d*/
  {
    __outbyte(0x3CFu, byte_1E4685[v16 & 7] & byte_1E468D[(v16 + 8) & 7]); /*0x197f1e*/
    _InterlockedIncrement(&dword_1E8654); /*0x197f1f*/
    for ( i = 11; i >= 0; --i ) /*0x197f26*/
    {
      *v14 = -1; /*0x197f3a*/
      v14 += v21; /*0x197f42*/
    }
  }
  else
  {
    for ( j = 11; j >= 0; --j ) /*0x197f4c*/
    {
      __outbyte(0x3CFu, v20); /*0x197f67*/
      _InterlockedIncrement(&dword_1E8654); /*0x197f68*/
      *v14 = -1; /*0x197f72*/
      v6 = v14 + 1; /*0x197f78*/
      __outbyte(0x3CFu, 0xFFu); /*0x197f7b*/
      _InterlockedIncrement(&dword_1E8654); /*0x197f7c*/
      for ( k = v3 - 1; k >= 0; --k ) /*0x197f8b*/
        *v6++ = -1; /*0x197f90*/
      __outbyte(0x3CFu, v19); /*0x197fa1*/
      _InterlockedIncrement(&dword_1E8654); /*0x197fa2*/
      *v6 = -1; /*0x197fb1*/
      v14 += v21; /*0x197fb7*/
    }
  }
  result = -1; /*0x197fc2*/
  __outbyte(0x3CFu, 0xFFu); /*0x197fc4*/
  _InterlockedIncrement(&dword_1E8654); /*0x197fc5*/
  if ( a2 > 31 ) /*0x197fd0*/
  {
    v8 = (unsigned __int8 *)&aEreIlComputerA[12 * a2]; /*0x197fe0*/
    v9 = *(_DWORD *)(a1 + 140) + 8 * *(_DWORD *)(a1 + 168); /*0x197ff4*/
    v18 = *(_DWORD *)(a1 + 144) + 12 * *(_DWORD *)(a1 + 164); /*0x19800c*/
    v15 = *(_BYTE *)(a1 + 180); /*0x198015*/
    __outbyte(0x3CEu, 0); /*0x19801f*/
    _InterlockedIncrement(&dword_1E8654); /*0x198020*/
    __outbyte(0x3CFu, v15); /*0x19802f*/
    _InterlockedIncrement(&dword_1E8654); /*0x198030*/
    v10 = (_BYTE *)((v9 >> 3) + *(_DWORD *)(a1 + 24) + *(_DWORD *)(a1 + 16) * v18); /*0x198046*/
    __outbyte(0x3CEu, 8u); /*0x19804f*/
    _InterlockedIncrement(&dword_1E8654); /*0x198050*/
    v11 = 12; /*0x198057*/
    do /*0x198079*/
    {
      v12 = *v8++; /*0x19805c*/
      __outbyte(0x3CFu, v12); /*0x198064*/
      _InterlockedIncrement(&dword_1E8654); /*0x198065*/
      *v10 = -1; /*0x198072*/
      v10 += *(_DWORD *)(a1 + 16); /*0x198075*/
      --v11; /*0x198078*/
    }
    while ( v11 ); /*0x198079*/
    __outbyte(0x3CFu, 0xFFu); /*0x19807d*/
    _InterlockedIncrement(&dword_1E8654); /*0x19807e*/
    ++*(_DWORD *)(a1 + 168); /*0x198085*/
    return -1; /*0x19807b*/
  }
  return result; /*0x19808e*/
}
