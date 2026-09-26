/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13d3f0. */
int __cdecl ifree(int a1, unsigned int a2, __int16 a3)
{
  int v3; // ebx
  int *v4; // eax
  _DWORD *v5; // esi
  int result; // eax
  unsigned int v7; // edi
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // [esp+Ch] [ebp-24h]
  int v14; // [esp+20h] [ebp-10h]
  int v15; // [esp+24h] [ebp-Ch]
  int v16; // [esp+28h] [ebp-8h] BYREF

  v3 = *(_DWORD *)(a1 + 80); /*0x13d3ff*/
  if ( a2 >= *(_DWORD *)(v3 + 44) * *(_DWORD *)(v3 + 184) ) /*0x13d40e*/
  {
    printf("dev = 0x%x, ino = %d, fs = %s\n", *(__int16 *)(a1 + 70), a2, (const char *)(v3 + 212)); /*0x13d422*/
    panic(aIfreeRange); /*0x13d42c*/
  }
  v14 = a2 / *(_DWORD *)(v3 + 184); /*0x13d43e*/
  v4 = bread( /*0x13d475*/
         *(_DWORD *)(a1 + 64),
         (*(_DWORD *)(v3 + 12) + *(_DWORD *)(v3 + 24) * (v14 & ~*(_DWORD *)(v3 + 28)) + *(_DWORD *)(v3 + 188) * v14) << *(_DWORD *)(v3 + 100),
         *(_DWORD *)(v3 + 160));
  v15 = (int)v4; /*0x13d47a*/
  v5 = (_DWORD *)v4[8]; /*0x13d47d*/
  if ( (*(_BYTE *)v4 & 4) != 0 ) /*0x13d486*/
  {
    result = brelse((int)v4); /*0x13d489*/
    v13 = 0; /*0x13d48e*/
  }
  else
  {
    result = byte_swap_cylgroup(v4[8]); /*0x13d49d*/
    if ( v5[245] == 590421 ) /*0x13d4af*/
    {
      v13 = 1; /*0x13d4cc*/
    }
    else
    {
      byte_swap_cylgroup(v5); /*0x13d4b2*/
      result = brelse(v15); /*0x13d4bb*/
      v13 = 0; /*0x13d4c0*/
    }
  }
  if ( v13 ) /*0x13d4d7*/
  {
    getthetime(&v16); /*0x13d4e1*/
    v5[2] = v16; /*0x13d4e9*/
    v7 = a2 % *(_DWORD *)(v3 + 184); /*0x13d4f6*/
    v8 = *((char *)v5 + (v7 >> 3) + 724); /*0x13d4fe*/
    if ( !_bittest(&v8, v7 & 7) ) /*0x13d514*/
    {
      printf("dev = 0x%x, ino = %d, fs = %s\n", *(__int16 *)(a1 + 70), v7, (const char *)(v3 + 212)); /*0x13d52b*/
      panic(aIfreeFreeingFr); /*0x13d535*/
    }
    *((_BYTE *)v5 + (v7 >> 3) + 724) &= __ROL4__(-2, v7 & 7); /*0x13d54a*/
    if ( v5[12] > v7 ) /*0x13d554*/
      v5[12] = v7; /*0x13d556*/
    ++v5[8]; /*0x13d559*/
    ++*(_DWORD *)(v3 + 200); /*0x13d55c*/
    v9 = *(_DWORD *)(v3 + 4 * (v14 >> *(_DWORD *)(v3 + 112)) + 728); /*0x13d572*/
    v10 = 16 * (v14 & ~*(_DWORD *)(v3 + 108)); /*0x13d579*/
    ++*(_DWORD *)(v9 + v10 + 8); /*0x13d57c*/
    if ( (a3 & 0xF000) == 0x4000 ) /*0x13d58d*/
    {
      --v5[6]; /*0x13d58f*/
      --*(_DWORD *)(v3 + 192); /*0x13d592*/
      v11 = *(_DWORD *)(v3 + 4 * (v14 >> *(_DWORD *)(v3 + 112)) + 728); /*0x13d5a8*/
      v12 = 16 * (v14 & ~*(_DWORD *)(v3 + 108)); /*0x13d5af*/
      --*(_DWORD *)(v11 + v12); /*0x13d5b2*/
    }
    ++*(_BYTE *)(v3 + 208); /*0x13d5b5*/
    byte_swap_cylgroup(v5); /*0x13d5bc*/
    result = bdwrite(v15); /*0x13d5c5*/
    if ( (*(_BYTE *)(v3 + 211) & 2) != 0 ) /*0x13d5d4*/
    {
      result = *(_DWORD *)(v3 + 144); /*0x13d5d6*/
      if ( *(_DWORD *)(v3 + 200) > result ) /*0x13d5e2*/
      {
        result = wakeup(v3 + 200); /*0x13d5eb*/
        *(_BYTE *)(v3 + 211) &= ~2u; /*0x13d5f0*/
      }
    }
  }
  return result; /*0x13d5fa*/
}
