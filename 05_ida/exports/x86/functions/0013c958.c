/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13c958. */
int __cdecl alloccgblk(int a1, _DWORD *a2, int a3)
{
  int v3; // ecx
  int v4; // ebx
  int v5; // esi
  int v6; // ecx
  int i; // ebx
  int v8; // esi
  int j; // ebx
  unsigned int v10; // ecx
  int v12; // esi
  int v13; // ebx
  int v14; // [esp+Ch] [ebp-14h]
  int v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  int v18; // [esp+18h] [ebp-8h]
  int v19; // [esp+18h] [ebp-8h]
  int v20; // [esp+1Ch] [ebp-4h]
  int v21; // [esp+1Ch] [ebp-4h]
  int v22; // [esp+30h] [ebp+10h]

  if ( a3 ) /*0x13c968*/
  {
    v22 = (-*(_DWORD *)(a1 + 56) & a3) % *(_DWORD *)(a1 + 188); /*0x13c98a*/
    if ( isblock(a1, a2 + 246, v22 >> *(_DWORD *)(a1 + 96)) ) /*0x13c99f*/
    {
      v20 = v22; /*0x13c9ae*/
      goto LABEL_28; /*0x13c9b1*/
    }
    v3 = *(_DWORD *)(a1 + 124); /*0x13c9b8*/
    v15 = *(_DWORD *)(a1 + 172); /*0x13c9c7*/
    v4 = v3 * v22 % v15; /*0x13c9d0*/
    v5 = v3 * v22 / v15; /*0x13c9d2*/
    if ( a2[v5 + 21] ) /*0x13c9d7*/
    {
      if ( *(_DWORD *)(a1 + 856) ) /*0x13c9e2*/
      {
        v6 = (int)&a2[4 * v5 + 53]; /*0x13ca08*/
        v18 = 8 * (v4 % *(_DWORD *)(a1 + 168)) / *(_DWORD *)(a1 + 168); /*0x13ca28*/
        for ( i = v18; i <= 7; ++i ) /*0x13ca31*/
        {
          if ( *(__int16 *)(v6 + 2 * i) > 0 ) /*0x13ca39*/
            break; /*0x13ca39*/
        }
        if ( i == 8 && (i = 0, v18 > 0) ) /*0x13ca4b*/
        {
          while ( *(__int16 *)(v6 + 2 * i) <= 0 ) /*0x13ca55*/
          {
            if ( v18 <= ++i ) /*0x13ca5b*/
              goto LABEL_15; /*0x13ca5b*/
          }
        }
        else
        {
LABEL_15:
          if ( *(__int16 *)(v6 + 2 * i) <= 0 ) /*0x13ca62*/
            goto LABEL_24; /*0x13ca62*/
        }
        v19 = v5 % *(_DWORD *)(a1 + 856); /*0x13ca71*/
        v21 = *(_DWORD *)(a1 + 172) * (v5 - v19) / (*(_DWORD *)(a1 + 124) << *(_DWORD *)(a1 + 96)); /*0x13ca8e*/
        v8 = a1 + 16 * v19 + 860; /*0x13ca97*/
        if ( *(_WORD *)(v8 + 2 * i) == 0xFFFF ) /*0x13caa3*/
        {
          printf("pos = %d, i = %d, fs = %s\n", v19, i, (const char *)(a1 + 212)); /*0x13cab6*/
          panic(aAlloccgblkCylG); /*0x13cac0*/
        }
        for ( j = *(__int16 *)(v8 + 2 * i); !isblock(a1, a2 + 246, j + v21); j += v10 ) /*0x13cac8*/
        {
          v10 = *(unsigned __int8 *)(j + a1 + 1376); /*0x13cae8*/
          if ( !*(_BYTE *)(j + a1 + 1376) || v10 > 6812 - j ) /*0x13cafd*/
          {
            printf("pos = %d, i = %d, fs = %s\n", v19, j, (const char *)(a1 + 212)); /*0x13cb15*/
            panic(aAlloccgblkCanT); /*0x13cb1f*/
          }
        }
        v20 = (j + v21) << *(_DWORD *)(a1 + 96); /*0x13cb51*/
        goto LABEL_28; /*0x13cb54*/
      }
      v22 = (v3 + v5 * v15 - 1) / v3; /*0x13c9f8*/
    }
  }
  else
  {
    v22 = a2[10]; /*0x13c970*/
  }
LABEL_24:
  v20 = mapsearch(a1, a2, v22, *(_DWORD *)(a1 + 56)); /*0x13cb27*/
  if ( v20 < 0 ) /*0x13cb41*/
    return 0; /*0x13cb45*/
  a2[10] = v20; /*0x13cb5e*/
LABEL_28:
  clrblock(a1, a2 + 246, v20 >> *(_DWORD *)(a1 + 96)); /*0x13cb61*/
  --a2[7]; /*0x13cb7d*/
  --*(_DWORD *)(a1 + 196); /*0x13cb80*/
  v14 = a2[3]; /*0x13cb89*/
  v16 = *(_DWORD *)(a1 + 4 * (v14 >> *(_DWORD *)(a1 + 112)) + 728); /*0x13cba4*/
  v17 = 16 * (~*(_DWORD *)(a1 + 108) & v14); /*0x13cbaa*/
  --*(_DWORD *)(v16 + v17 + 4); /*0x13cbad*/
  v12 = *(_DWORD *)(a1 + 124) * v20 / *(_DWORD *)(a1 + 172); /*0x13cbc3*/
  v13 = 8 * (*(_DWORD *)(a1 + 124) * v20 % *(_DWORD *)(a1 + 172) % *(_DWORD *)(a1 + 168)) / *(_DWORD *)(a1 + 168); /*0x13cbec*/
  --*((_WORD *)&a2[4 * v12 + 53] + v13); /*0x13cbf1*/
  --a2[v12 + 21]; /*0x13cbf8*/
  ++*(_BYTE *)(a1 + 208); /*0x13cbfc*/
  return v20 + *(_DWORD *)(a1 + 188) * a2[3]; /*0x13cc16*/
}
