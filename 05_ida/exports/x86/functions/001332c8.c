/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1332c8. */
int __cdecl sub_1332C8(int a1)
{
  int *v1; // eax
  int v2; // eax
  int v3; // esi
  unsigned int i; // ebx
  int v5; // ebx
  int v6; // eax
  __int16 v7; // ax
  int v8; // ebx
  int v9; // ebx
  int v10; // esi
  int v11; // eax
  _WORD *v13; // [esp+10h] [ebp-11Ch]
  int v14; // [esp+14h] [ebp-118h]
  int v15; // [esp+18h] [ebp-114h]
  int v16; // [esp+1Ch] [ebp-110h]
  int v17; // [esp+20h] [ebp-10Ch]
  _WORD *v18; // [esp+28h] [ebp-104h]
  int v19; // [esp+30h] [ebp-FCh]
  int v20; // [esp+34h] [ebp-F8h]
  int v21; // [esp+38h] [ebp-F4h]
  int v22; // [esp+3Ch] [ebp-F0h]
  int *v23; // [esp+40h] [ebp-ECh]
  int v24; // [esp+44h] [ebp-E8h]
  int v25; // [esp+48h] [ebp-E4h] BYREF
  char v26[28]; // [esp+4Ch] [ebp-E0h] BYREF
  int v27; // [esp+68h] [ebp-C4h] BYREF
  int v28[9]; // [esp+6Ch] [ebp-C0h] BYREF
  _BYTE v29[32]; // [esp+90h] [ebp-9Ch] BYREF
  int v30; // [esp+B0h] [ebp-7Ch]
  int v31; // [esp+B4h] [ebp-78h]
  int v32; // [esp+B8h] [ebp-74h]
  int v33; // [esp+BCh] [ebp-70h]
  _DWORD v34[11]; // [esp+C0h] [ebp-6Ch] BYREF
  char v35[64]; // [esp+ECh] [ebp-40h] BYREF

  v1 = *(int **)(a1 + 64); /*0x1332d7*/
  v24 = v1[12]; /*0x1332dd*/
  v23 = v1; /*0x1332e3*/
  v2 = (*(int (__cdecl **)(int *))(v1[7] + 128))(v1); /*0x1332f9*/
  v22 = v2; /*0x1332fb*/
  if ( (*(_BYTE *)a1 & 1) == 0 )
  {
    v7 = *(_WORD *)(v24 + 98); /*0x133552*/
    if ( v7 ) /*0x133559*/
    {
      *(_WORD *)(a1 + 28) = v7; /*0x13374f*/
      v5 = v7; /*0x133753*/
      goto LABEL_46; /*0x133753*/
    }
    v8 = *(_DWORD *)(v24 + 152) - *(_DWORD *)(a1 + 36) * v22; /*0x133575*/
    if ( *(_DWORD *)(a1 + 20) < (unsigned int)v8 ) /*0x133579*/
      v8 = *(_DWORD *)(a1 + 20); /*0x13357b*/
    if ( v8 < 0 ) /*0x13357f*/
      panic(aDoBioWriteCoun); /*0x133586*/
    v16 = *(_DWORD *)(a1 + 32); /*0x133594*/
    v15 = *(_DWORD *)(a1 + 36) * v22; /*0x1335a7*/
    v14 = v8; /*0x1335ad*/
    v13 = *(_WORD **)(v24 + 112); /*0x1335bc*/
    while ( 1 ) /*0x1335d3*/
    {
      v9 = *(_DWORD *)(*(_DWORD *)(v23[9] + 296) + 32); /*0x1335d3*/
      if ( v14 < v9 ) /*0x1335dc*/
        v9 = v14; /*0x1335de*/
      v34[0] = v16; /*0x1335ea*/
      qmemcpy(v29, (const void *)(v23[12] + 64), sizeof(v29)); /*0x133605*/
      v30 = v15; /*0x13360d*/
      v32 = v9; /*0x133610*/
      v33 = v9; /*0x133613*/
      v31 = v15; /*0x133616*/
      v10 = rfscall(*(_DWORD *)(v23[9] + 296), 8, (int)xdr_writeargs, (int)v29, (int)xdr_attrstat, &v25, v13); /*0x13364f*/
      if ( !v10 ) /*0x133656*/
      {
        v10 = v25; /*0x133658*/
        if ( v25 == 70 ) /*0x133661*/
        {
          btrash((int)v23); /*0x13366a*/
          nfs_invalidate_caches((int)v23); /*0x133676*/
        }
      }
      v14 -= v9; /*0x13367e*/
      v16 += v9; /*0x133684*/
      v15 += v9; /*0x13368a*/
      if ( v10 ) /*0x133692*/
        break; /*0x133692*/
      if ( !v14 ) /*0x13369b*/
      {
        nfs_attrcache((int)v23, (int)v26); /*0x1336af*/
        break; /*0x1336af*/
      }
    }
    if ( v10 == 28 )
    {
      printf("NFS write error: on host %s remote file system full\n", (const char *)(*(_DWORD *)(v23[9] + 296) + 52));
      goto LABEL_43; /*0x1336ec*/
    }
    if ( v10 > 28 ) /*0x1336bc*/
    {
      if ( v10 == 69 ) /*0x1336c7*/
      {
LABEL_43:
        *(_WORD *)(a1 + 28) = v10; /*0x13372d*/
        v5 = (__int16)v10; /*0x133736*/
        if ( (*(_BYTE *)(a1 + 1) & 1) != 0 ) /*0x13373d*/
          *(_WORD *)(v24 + 98) = v10; /*0x133745*/
        goto LABEL_46; /*0x133749*/
      }
    }
    else if ( !v10 ) /*0x1336c0*/
    {
      goto LABEL_43; /*0x1336c0*/
    }
    printf("NFS write error %d on host %s fh ", v10, (const char *)(*(_DWORD *)(v23[9] + 296) + 52)); /*0x133709*/
    sub_131898((void *)(v23[12] + 64)); /*0x13371b*/
    printf("\n"); /*0x133725*/
    goto LABEL_43; /*0x133725*/
  }
  v21 = *(_DWORD *)(a1 + 32); /*0x133313*/
  v20 = *(_DWORD *)(a1 + 36) * v2; /*0x13331f*/
  v19 = *(_DWORD *)(a1 + 20); /*0x133328*/
  v18 = *(_WORD **)(v24 + 112); /*0x133343*/
  do /*0x1334b0*/
  {
    v17 = *(_DWORD *)(*(_DWORD *)(v23[9] + 296) + 28); /*0x133366*/
    if ( v17 > v19 ) /*0x133374*/
      v17 = v19; /*0x133376*/
    v31 = v21; /*0x133382*/
    qmemcpy(v34, (const void *)(v23[12] + 64), 0x20u); /*0x13339a*/
    v34[8] = v20; /*0x1333a2*/
    v34[10] = v17; /*0x1333ab*/
    v34[9] = v17; /*0x1333ae*/
    v3 = rfscall(*(_DWORD *)(v23[9] + 296), 6, (int)xdr_readargs, (int)v34, (int)xdr_rdresult, &v27, v18); /*0x1333e4*/
    if ( v3 ) /*0x1333eb*/
      break; /*0x1333eb*/
    v3 = v27; /*0x1333f1*/
    if ( v27 == 70 ) /*0x1333fa*/
    {
      printf("NFS read error ESTALE to host %10s fh ", (const char *)(*(_DWORD *)(v23[9] + 296) + 52)); /*0x133418*/
      bcopy((const void *)(v23[12] + 64), &v25, 0x20u); /*0x133436*/
      for ( i = 0; i <= 7; ++i ) /*0x13343b*/
        printf("%x ", *(_DWORD *)&v26[4 * i - 4]); /*0x13344d*/
      printf("\n"); /*0x133460*/
      btrash((int)v23); /*0x133474*/
      nfs_invalidate_caches((int)v23); /*0x133480*/
    }
    if ( v3 ) /*0x13348a*/
      break; /*0x13348a*/
    v19 -= v30; /*0x13348f*/
    v21 += v30; /*0x133495*/
    v20 += v30; /*0x13349b*/
    if ( !v19 ) /*0x1334a8*/
      break; /*0x1334a8*/
  }
  while ( v17 == v30 ); /*0x1334b0*/
  *(_DWORD *)(a1 + 40) = v19; /*0x1334c2*/
  if ( !v3 ) /*0x1334c6*/
    nattr_to_vattr(v23, v28, (int)v35); /*0x1334dd*/
  *(_WORD *)(a1 + 28) = v3; /*0x1334ea*/
  v5 = (__int16)v3; /*0x1334ee*/
  if ( (_WORD)v3 ) /*0x1334f3*/
    goto LABEL_47; /*0x1334f3*/
  v6 = *(_DWORD *)(a1 + 40); /*0x1334f9*/
  if ( v6 ) /*0x1334fe*/
    bzero((void *)(*(_DWORD *)(a1 + 32) + *(_DWORD *)(a1 + 20) - v6), *(_DWORD *)(a1 + 40)); /*0x13350c*/
  if ( *(_DWORD *)(a1 + 40) != *(_DWORD *)(a1 + 20) /*0x133539*/
    || *(_DWORD *)(v24 + 152) > (unsigned int)(*(_DWORD *)(a1 + 36) * v22) )
  {
LABEL_46:
    if ( !v5 ) /*0x133758*/
      goto LABEL_51; /*0x133758*/
    goto LABEL_47; /*0x133758*/
  }
  v5 = -98; /*0x13353f*/
LABEL_47:
  if ( v5 != -98 ) /*0x13375d*/
  {
    *(_BYTE *)a1 |= 4u; /*0x133762*/
    v11 = *v23; /*0x13376b*/
    if ( *v23 ) /*0x13376b*/
    {
      if ( !*(_DWORD *)(v11 + 52) ) /*0x133771*/
        *(_DWORD *)(v11 + 52) = v5; /*0x133777*/
    }
  }
LABEL_51:
  biodone(a1); /*0x13377a*/
  return v5; /*0x13378b*/
}
