/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19b340. */
int __cdecl sub_19B340(int a1, unsigned __int16 *a2)
{
  unsigned int v2; // ebx
  unsigned __int16 v3; // ax
  int v5; // ebx
  int v6; // esi
  int v7; // edx
  unsigned __int8 v8; // dl
  _WORD *v9; // [esp-4h] [ebp-34h]
  int i; // [esp+Ch] [ebp-24h]
  int j; // [esp+Ch] [ebp-24h]
  _WORD *v12; // [esp+14h] [ebp-1Ch]
  int v13; // [esp+18h] [ebp-18h]
  int v14; // [esp+1Ch] [ebp-14h]
  int v15; // [esp+20h] [ebp-10h]
  unsigned __int8 *v16; // [esp+24h] [ebp-Ch]
  int v17; // [esp+2Ch] [ebp-4h] BYREF

  v2 = *(_DWORD *)(a1 + 28); /*0x19b34c*/
  if ( *(_DWORD *)v2 != 2 ) /*0x19b358*/
    return -1; /*0x19b358*/
  if ( *(_DWORD *)(v2 + 4) < (int)a2[2] ) /*0x19b364*/
    return -1; /*0x19b364*/
  if ( *(_DWORD *)(v2 + 8) < (int)a2[3] ) /*0x19b370*/
    return -1; /*0x19b370*/
  *(_BYTE *)a2 &= 0xFCu; /*0x19b375*/
  v3 = a2[2]; /*0x19b378*/
  LOBYTE(v3) = v3 & 0xFC; /*0x19b37c*/
  a2[2] = v3; /*0x19b37e*/
  if ( a2[3] * (v3 >> 2) <= 0 ) /*0x19b395*/
    return -1; /*0x19b39c*/
  __outbyte(0x3CEu, 1u); /*0x19b3ab*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b3ac*/
  __outbyte(0x3CFu, 0); /*0x19b3ba*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b3bb*/
  v16 = *((unsigned __int8 **)a2 + 2); /*0x19b3c8*/
  LOWORD(v2) = *a2; /*0x19b3d7*/
  v14 = (v2 >> 2) & 3; /*0x19b3f2*/
  v15 = (*(_DWORD *)(*(_DWORD *)(a1 + 28) + 4) * a2[1] + *a2 - 4 * v14) / 8 + *(_DWORD *)(*(_DWORD *)(a1 + 28) + 24); /*0x19b40c*/
  v13 = 0; /*0x19b40f*/
  if ( a2[3] ) /*0x19b419*/
  {
    while ( 1 ) /*0x19b428*/
    {
      v5 = 30; /*0x19b428*/
      v17 = 0; /*0x19b42d*/
      v12 = (_WORD *)v15; /*0x19b437*/
      v6 = 0; /*0x19b43a*/
      if ( a2[2] ) /*0x19b43f*/
        break; /*0x19b43f*/
LABEL_17:
      v15 += 80; /*0x19b50b*/
      if ( ++v13 >= a2[3] ) /*0x19b51c*/
        goto LABEL_18; /*0x19b51c*/
    }
    while ( 1 ) /*0x19b44c*/
    {
      if ( !v6 ) /*0x19b44e*/
      {
        for ( i = 0; i < v14; ++i ) /*0x19b45a*/
        {
          v7 = v17 << 8; /*0x19b45f*/
          LOBYTE(v7) = -86; /*0x19b462*/
          v17 = v7; /*0x19b465*/
          v5 -= 8; /*0x19b468*/
        }
      }
      v8 = *v16++; /*0x19b479*/
      for ( j = 0; j <= 7; j += 2 ) /*0x19b47e*/
      {
        v17 |= (((int)v8 >> (6 - j)) & 3) << (30 - v5); /*0x19b4a0*/
        v5 -= 2; /*0x19b4a3*/
      }
      v6 += 4; /*0x19b4b0*/
      if ( v5 < 0 ) /*0x19b4b5*/
        goto LABEL_16; /*0x19b4b5*/
      if ( v6 >= a2[2] ) /*0x19b4c0*/
      {
        do /*0x19b4d8*/
        {
          v17 |= 2 << (30 - v5); /*0x19b4d2*/
          v5 -= 2; /*0x19b4d5*/
        }
        while ( v5 >= 0 ); /*0x19b4d8*/
LABEL_16:
        v9 = v12++; /*0x19b4da*/
        sub_19B0A8(&v17, v9); /*0x19b4e8*/
        v5 = 30; /*0x19b4ed*/
        v17 = 0; /*0x19b4f2*/
        if ( v6 >= a2[2] ) /*0x19b505*/
          goto LABEL_17; /*0x19b505*/
      }
    }
  }
LABEL_18:
  __outbyte(0x3CEu, 1u); /*0x19b522*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b52a*/
  __outbyte(0x3CFu, 0xFu); /*0x19b538*/
  _InterlockedIncrement(&dword_1E8654); /*0x19b539*/
  return 0; /*0x19b545*/
}
