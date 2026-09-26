/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x145848. */
int __cdecl sub_145848(_DWORD *a1, int a2, unsigned int a3)
{
  unsigned int i; // esi
  __int16 v4; // ax
  signed __int32 v5; // edi
  __int16 v6; // ax
  int v7; // edx
  unsigned int v9; // edx
  int v10; // edx
  signed __int32 v11; // eax
  __int16 v12; // ax
  __int16 v13; // ax
  __int16 v14; // ax
  char v15; // [esp+Ch] [ebp-2Ch]
  int *v16; // [esp+Ch] [ebp-2Ch]
  int v17; // [esp+10h] [ebp-28h]
  unsigned int v18; // [esp+14h] [ebp-24h]
  int v19; // [esp+18h] [ebp-20h]
  int v20; // [esp+1Ch] [ebp-1Ch]
  int v21; // [esp+20h] [ebp-18h]
  signed int v22; // [esp+24h] [ebp-14h]
  _DWORD *v23; // [esp+28h] [ebp-10h]
  int v24; // [esp+2Ch] [ebp-Ch]
  int v25; // [esp+30h] [ebp-8h]
  int v26; // [esp+34h] [ebp-4h] BYREF

  for ( i = a1[12]; ; sleep(i) ) /*0x145854*/
  {
    v4 = *(_WORD *)(i + 68); /*0x14586d*/
    if ( (v4 & 1) == 0 ) /*0x145873*/
      break; /*0x145873*/
    LOBYTE(v4) = v4 | 0x10; /*0x14585c*/
    *(_WORD *)(i + 68) = v4; /*0x14585e*/
  }
  *(_BYTE *)(i + 68) |= 5u; /*0x145875*/
  v25 = 0; /*0x145879*/
  v24 = *(_DWORD *)(i + 64); /*0x145883*/
  v23 = *(_DWORD **)(i + 80); /*0x145889*/
  v20 = v23[12]; /*0x14588f*/
  v19 = page_size; /*0x145898*/
  if ( *(_DWORD *)(i + 108) < page_size + a3 ) /*0x1458a3*/
    vm_page_zero_fill(a2); /*0x1458a9*/
  while ( 1 )
  {
    v22 = a3 >> v23[20]; /*0x1458c1*/
    v18 = a3 & ~v23[18]; /*0x1458cf*/
    v5 = v19; /*0x1458d8*/
    if ( v20 - v18 < v19 ) /*0x1458dd*/
      v5 = v20 - v18; /*0x1458df*/
    if ( a3 >= *(_DWORD *)(i + 108) ) /*0x1458ec*/
      break; /*0x1458ec*/
    if ( *(_DWORD *)(i + 108) - a3 < v5 ) /*0x14590a*/
      v5 = *(_DWORD *)(i + 108) - a3; /*0x14590c*/
    v15 = *(_BYTE *)(dword_1E875C + 104); /*0x145917*/
    *(_BYTE *)(dword_1E875C + 104) = 0; /*0x14591a*/
    v21 = bmap(i, v22, 1, v5 + v18, nullptr) << v23[25]; /*0x14593c*/
    v7 = *(char *)(dword_1E875C + 104); /*0x145944*/
    *(_BYTE *)(dword_1E875C + 104) = v15; /*0x14594b*/
    if ( v7 )
    {
      *(_DWORD *)(*a1 + 52) = v7; /*0x14595a*/
      printf("IO error on pagein: error = %d.\n", v7);
      goto LABEL_42; /*0x145968*/
    }
    if ( v21 < 0 ) /*0x145974*/
    {
      v6 = *(_WORD *)(i + 68); /*0x145976*/
      *(_WORD *)(i + 68) = v6 & 0xFFFE; /*0x14597f*/
      goto LABEL_17; /*0x14597f*/
    }
    if ( v22 <= 11 && (v9 = *(_DWORD *)(i + 108), v9 < (v22 + 1) << v23[20]) ) /*0x1459b9*/
      v10 = v23[19] & (v23[13] + (v9 & ~v23[18]) - 1); /*0x1459d4*/
    else
      v10 = v23[12]; /*0x1459be*/
    if ( page_size != v10 || v25 || v18 ) /*0x1459f1*/
    {
      v17 = v10; /*0x145abc*/
      if ( v22 == *(_DWORD *)(i + 88) + 1 ) /*0x145aa3*/
        v16 = breada(v24, v21, v10, rablock, rasize); /*0x145ac4*/
      else
        v16 = bread(v24, v21, v10); /*0x145add*/
      *(_DWORD *)(i + 88) = v22; /*0x145ae9*/
      if ( v5 > v17 - v16[10] ) /*0x145af6*/
        v5 = v17 - v16[10]; /*0x145af8*/
      if ( (*(_BYTE *)v16 & 4) != 0 ) /*0x145b00*/
      {
        *(_DWORD *)(*a1 + 52) = *((__int16 *)v16 + 14); /*0x145b0b*/
        brelse((int)v16); /*0x145b12*/
        printf("IO error on pagein (bread)\n"); /*0x145b1c*/
LABEL_42:
        v13 = *(_WORD *)(i + 68); /*0x145b21*/
        *(_WORD *)(i + 68) = v13 & 0xFFFE; /*0x145b2a*/
        if ( (v13 & 0x10) != 0 ) /*0x145b33*/
        {
          LOBYTE(v13) = v13 & 0xEE; /*0x145b35*/
          *(_WORD *)(i + 68) = v13; /*0x145b37*/
          wakeup(i); /*0x145b3c*/
        }
        return 2; /*0x145b46*/
      }
      copy_to_phys((void *)(v16[8] + v18), (void *)(*(_DWORD *)(a2 + 36) + v25), v5); /*0x145b5d*/
      if ( v20 == v5 ) /*0x145b68*/
        *v16 |= 0x400000u; /*0x145b6a*/
      brelse((int)v16); /*0x145b74*/
    }
    else
    {
      if ( v22 != *(_DWORD *)(i + 88) + 1 ) /*0x1459fe*/
      {
        rablock = 0; /*0x145a00*/
        rasize = 0; /*0x145a0a*/
      }
      v26 = 0; /*0x145a14*/
      v11 = breadDirect(v24, a2, v21, v10, v5, rablock, rasize, &v26); /*0x145a3b*/
      *(_DWORD *)(i + 88) = v22; /*0x145a43*/
      if ( v26 ) /*0x145a4e*/
      {
        *(_DWORD *)(*a1 + 52) = v26; /*0x145a55*/
        v12 = *(_WORD *)(i + 68); /*0x145a58*/
        *(_WORD *)(i + 68) = v12 & 0xFFFE; /*0x145a61*/
        if ( (v12 & 0x10) != 0 ) /*0x145a67*/
        {
          LOBYTE(v12) = v12 & 0xEE; /*0x145a69*/
          *(_WORD *)(i + 68) = v12; /*0x145a6b*/
          wakeup(i); /*0x145a70*/
        }
        printf("IO error on pagein (breadDirect)\n"); /*0x145a7d*/
        return 2; /*0x145a87*/
      }
      if ( v5 > v11 ) /*0x145a8e*/
        v5 = v11; /*0x145a94*/
    }
    v19 -= v5; /*0x145b7c*/
    v25 += v5; /*0x145b7f*/
    a3 += v5; /*0x145b82*/
    if ( v19 <= 0 || !v5 ) /*0x145b8d*/
      goto LABEL_50; /*0x145b8d*/
  }
  if ( !v25 ) /*0x1458f2*/
  {
    v6 = *(_WORD *)(i + 68); /*0x1458f8*/
    *(_WORD *)(i + 68) = v6 & 0xFFFE; /*0x145901*/
LABEL_17:
    if ( (v6 & 0x10) != 0 ) /*0x145985*/
    {
      LOBYTE(v6) = v6 & 0xEE; /*0x145987*/
      *(_WORD *)(i + 68) = v6; /*0x145989*/
      wakeup(i); /*0x14598e*/
    }
    return 1; /*0x145998*/
  }
LABEL_50:
  v14 = *(_WORD *)(i + 68); /*0x145b93*/
  *(_WORD *)(i + 68) = v14 & 0xFFFE; /*0x145b9c*/
  if ( (v14 & 0x10) != 0 ) /*0x145ba2*/
  {
    LOBYTE(v14) = v14 & 0xEE; /*0x145ba4*/
    *(_WORD *)(i + 68) = v14; /*0x145ba6*/
    wakeup(i); /*0x145bab*/
  }
  return 0; /*0x145bb5*/
}
