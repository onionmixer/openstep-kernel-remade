/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19b860. */
int __cdecl sub_19B860(int a1, unsigned __int16 *a2)
{
  int v2; // edi
  int v3; // ebx
  int v4; // esi
  unsigned __int8 v6; // cl
  _BYTE *v7; // ebx
  int i; // esi
  int j; // esi
  _BYTE *v10; // edi
  int k; // ecx
  int v12; // [esp+Ch] [ebp-20h]
  int v13; // [esp+Ch] [ebp-20h]
  unsigned __int8 v14; // [esp+14h] [ebp-18h]
  unsigned __int8 v15; // [esp+18h] [ebp-14h]
  int v16; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+20h] [ebp-Ch]
  _DWORD *v18; // [esp+24h] [ebp-8h]

  v18 = *(_DWORD **)(a1 + 28); /*0x19b872*/
  v2 = *a2; /*0x19b875*/
  v3 = v2 + a2[2]; /*0x19b87e*/
  if ( v18[1] < v3 ) /*0x19b883*/
    return -1; /*0x19b883*/
  v17 = a2[1]; /*0x19b889*/
  v4 = a2[3]; /*0x19b88c*/
  if ( v18[2] < v4 + v17 ) /*0x19b898*/
    return -1; /*0x19b89a*/
  v16 = v18[4]; /*0x19b8b3*/
  v6 = 3 - (a2[4] & 3); /*0x19b8b8*/
  __outbyte(0x3CEu, 0); /*0x19b8c2*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b8c3*/
  __outbyte(0x3CFu, v6); /*0x19b8d1*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b8d2*/
  __outbyte(0x3CEu, 8u); /*0x19b8e0*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b8e1*/
  v12 = v3 >> 3; /*0x19b8f2*/
  v15 = byte_1E4685[v2 & 7]; /*0x19b901*/
  v14 = byte_1E468D[v3 & 7]; /*0x19b910*/
  v7 = (_BYTE *)((v2 >> 3) + v18[6] + v16 * v17); /*0x19b922*/
  v13 = v12 - (v2 >> 3) - 1; /*0x19b92a*/
  if ( v13 == -1 ) /*0x19b930*/
  {
    __outbyte(0x3CFu, v15 & v14); /*0x19b93d*/
    _InterlockedIncrement(&dword_1E8654); /*0x19b93e*/
    for ( i = v4 - 1; i >= 0; --i ) /*0x19b946*/
    {
      *v7 = -1; /*0x19b94d*/
      v7 += v16; /*0x19b950*/
    }
  }
  else
  {
    for ( j = v4 - 1; j >= 0; --j ) /*0x19b959*/
    {
      __outbyte(0x3CFu, v15); /*0x19b969*/
      _InterlockedIncrement(&dword_1E8654); /*0x19b96a*/
      *v7 = -1; /*0x19b971*/
      v10 = v7 + 1; /*0x19b974*/
      __outbyte(0x3CFu, 0xFFu); /*0x19b979*/
      _InterlockedIncrement(&dword_1E8654); /*0x19b97a*/
      for ( k = v13 - 1; k >= 0; --k ) /*0x19b985*/
        *v10++ = -1; /*0x19b988*/
      __outbyte(0x3CFu, v14); /*0x19b997*/
      _InterlockedIncrement(&dword_1E8654); /*0x19b998*/
      *v10 = -1; /*0x19b9a4*/
      v7 += v16; /*0x19b9a7*/
    }
  }
  __outbyte(0x3CFu, 0xFFu); /*0x19b9b4*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b9b5*/
  return 0; /*0x19b9c1*/
}
