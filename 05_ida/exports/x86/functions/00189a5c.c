/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x189a5c. */
int __cdecl copyin(unsigned int a1, unsigned int a2, int a3)
{
  int v3; // ebx
  int v4; // ecx
  unsigned int v5; // edi
  unsigned int v6; // esi
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  unsigned int v11; // edi
  unsigned int v12; // esi
  int v13; // ecx
  unsigned int v14; // edi
  unsigned int v15; // esi
  int v16; // edx
  int v17; // eax
  unsigned int v18; // [esp+14h] [ebp+8h]
  _BYTE *v19; // [esp+18h] [ebp+Ch]

  v3 = a3; /*0x189a62*/
  *(_DWORD *)(active_threads + 116) = &loc_189B18; /*0x189a6a*/
  if ( a3 > 15 ) /*0x189a74*/
  {
    v8 = a1 & 3; /*0x189a8b*/
    if ( (a1 & 3) != 0 ) /*0x189a8e*/
    {
      v9 = 4 - v8; /*0x189a95*/
      v10 = 4 - v8; /*0x189a97*/
      v11 = a2; /*0x189a99*/
      v12 = a1; /*0x189a9c*/
      while ( v9 ) /*0x189a9f*/
      {
        __writefsbyte(v11++, __readfsbyte(v12++)); /*0x189a9f*/
        --v9; /*0x189a9f*/
      }
      v3 = a3 - v10; /*0x189aa2*/
      a2 += v10; /*0x189aa4*/
      a1 += v10; /*0x189aa7*/
    }
    v13 = v3 >> 2; /*0x189aaf*/
    v14 = a2; /*0x189ab1*/
    v15 = a1; /*0x189ab4*/
    while ( v13 ) /*0x189ab7*/
    {
      __writefsdword(v14, __readfsdword(v15)); /*0x189ab7*/
      v15 += 4; /*0x189ab7*/
      v14 += 4; /*0x189ab7*/
      --v13; /*0x189ab7*/
    }
    v16 = v3 & 3; /*0x189abc*/
    if ( (v3 & 3) == 0 ) /*0x189abf*/
      goto LABEL_23; /*0x189abf*/
    v17 = v3; /*0x189ac1*/
    LOBYTE(v17) = v3 & 0xFC; /*0x189ac3*/
    v18 = v17 + a1; /*0x189ac5*/
    v19 = (_BYTE *)(v17 + a2); /*0x189ac8*/
    if ( v16 != 2 ) /*0x189ace*/
    {
      if ( (v3 & 3u) <= 2 ) /*0x189ad0*/
      {
        if ( v16 != 1 ) /*0x189ad5*/
          goto LABEL_23; /*0x189ad5*/
        goto LABEL_22; /*0x189ad5*/
      }
      if ( v16 != 3 ) /*0x189adf*/
      {
LABEL_23:
        *(_DWORD *)(active_threads + 116) = 0; /*0x189b08*/
        return 0; /*0x189b14*/
      }
      v19[2] = __readfsbyte(v18 + 2); /*0x189aed*/
    }
    v19[1] = __readfsbyte(v18 + 1); /*0x189afa*/
LABEL_22:
    *v19 = __readfsbyte(v18); /*0x189afd*/
    goto LABEL_23; /*0x189b06*/
  }
  v4 = a3; /*0x189a76*/
  v5 = a2; /*0x189a78*/
  v6 = a1; /*0x189a7b*/
  while ( v4 ) /*0x189a7e*/
  {
    __writefsbyte(v5++, __readfsbyte(v6++)); /*0x189a7e*/
    --v4; /*0x189a7e*/
  }
  return 0; /*0x189b2c*/
}
