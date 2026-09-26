/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x141014. */
int __cdecl itrunc(unsigned int a1, unsigned int a2)
{
  __int16 v2; // cx
  __int16 v3; // cx
  int i; // ebx
  __int16 v5; // ax
  int v6; // ebx
  int v7; // ecx
  int *v8; // esi
  unsigned int v9; // esi
  __int16 v10; // ax
  int v11; // ecx
  __int16 v12; // dx
  int v13; // ebx
  unsigned int v15; // ecx
  signed int v16; // ebx
  int v17; // eax
  __int16 v18; // cx
  int v19; // ebx
  int v20; // ecx
  int *v21; // eax
  int *v22; // esi
  __int16 v23; // dx
  int v24; // ebx
  int v25; // edi
  char v26; // cl
  int v27; // esi
  int v28; // ebx
  int *v29; // ebx
  int j; // ebx
  int k; // ebx
  __int16 v32; // ax
  int v33; // ebx
  int v34; // ecx
  int *v35; // eax
  int *v36; // esi
  __int16 v37; // dx
  int v38; // ebx
  int v39; // ebx
  int v40; // edi
  int m; // ebx
  int v42; // edi
  unsigned int v43; // esi
  int v44; // edi
  int v45; // esi
  unsigned int v46; // ebx
  int v47; // edi
  unsigned int v48; // ebx
  int n; // ebx
  int ii; // ebx
  int v51; // eax
  __int16 v52; // [esp+2Ch] [ebp-11Ch]
  __int16 v53; // [esp+2Ch] [ebp-11Ch]
  unsigned int v54; // [esp+2Ch] [ebp-11Ch]
  __int16 v55; // [esp+2Ch] [ebp-11Ch]
  int v56; // [esp+30h] [ebp-118h]
  int v57; // [esp+34h] [ebp-114h]
  int v58; // [esp+38h] [ebp-110h]
  int v59; // [esp+3Ch] [ebp-10Ch]
  int v60; // [esp+40h] [ebp-108h]
  unsigned int *v61; // [esp+48h] [ebp-100h]
  int v62; // [esp+4Ch] [ebp-FCh]
  int v63; // [esp+50h] [ebp-F8h] BYREF
  _DWORD v64[58]; // [esp+54h] [ebp-F4h] BYREF
  unsigned int v65; // [esp+13Ch] [ebp-Ch]
  int v66; // [esp+140h] [ebp-8h]
  unsigned int v67; // [esp+144h] [ebp-4h]

  v63 = 0; /*0x141020*/
  v57 = 0; /*0x14102a*/
  v2 = *(_WORD *)(a1 + 68); /*0x141037*/
  *(_WORD *)(a1 + 68) = v2 & 0xFFFE; /*0x141040*/
  if ( (v2 & 0x10) != 0 ) /*0x141047*/
  {
    LOBYTE(v2) = v2 & 0xEE; /*0x141049*/
    *(_WORD *)(a1 + 68) = v2; /*0x14104c*/
    wakeup(a1); /*0x141051*/
  }
  v56 = mfs_trunc(a1 + 12, a2); /*0x141069*/
  while ( 1 ) /*0x14108c*/
  {
    v3 = *(_WORD *)(a1 + 68); /*0x14108c*/
    if ( (v3 & 1) == 0 ) /*0x141093*/
      break; /*0x141093*/
    LOBYTE(v3) = v3 | 0x10; /*0x141074*/
    *(_WORD *)(a1 + 68) = v3; /*0x14107a*/
    sleep(a1); /*0x141081*/
  }
  *(_BYTE *)(a1 + 68) |= 1u; /*0x141098*/
  if ( (*(_WORD *)(a1 + 100) & 0xF000) == 0xA000 && (*(_BYTE *)(a1 + 200) & 1) != 0 ) /*0x1410b5*/
  {
    for ( i = 14; i >= 0; --i ) /*0x1410bb*/
      *(_DWORD *)(a1 + 4 * i + 140) = 0; /*0x1410c3*/
    *(_DWORD *)(a1 + 200) = 0; /*0x1410d1*/
    *(_DWORD *)(a1 + 108) = 0; /*0x1410db*/
    v5 = *(_WORD *)(a1 + 68); /*0x1410e2*/
    LOBYTE(v5) = v5 | 0x42; /*0x1410e6*/
    *(_WORD *)(a1 + 68) = v5; /*0x1410e8*/
    v6 = *(_DWORD *)(a1 + 80); /*0x1410ec*/
    if ( (v5 & 0x4E) == 0 || *(_BYTE *)(v6 + 210) ) /*0x1410f7*/
      return 0; /*0x1410fe*/
    v7 = *(_DWORD *)(a1 + 72) / *(_DWORD *)(v6 + 184); /*0x14111a*/
    v8 = bread( /*0x141177*/
           *(_DWORD *)(a1 + 64),
           ((((unsigned int)(*(_DWORD *)(a1 + 72) % *(_DWORD *)(v6 + 184)) / *(_DWORD *)(v6 + 120)) << *(_DWORD *)(v6 + 96))
          + *(_DWORD *)(v6 + 16)
          + *(_DWORD *)(v6 + 24) * (~*(_DWORD *)(v6 + 28) & v7)
          + v7 * *(_DWORD *)(v6 + 188)) << *(_DWORD *)(v6 + 100),
           *(_DWORD *)(v6 + 48));
    if ( (*(_BYTE *)v8 & 4) == 0 ) /*0x14117f*/
      goto LABEL_19; /*0x14117f*/
LABEL_18:
    brelse((int)v8); /*0x14123a*/
    return 0; /*0x141334*/
  }
  v9 = *(_DWORD *)(a1 + 108); /*0x14118f*/
  if ( a2 == v9 ) /*0x141195*/
  {
    v10 = *(_WORD *)(a1 + 68); /*0x14119b*/
    LOBYTE(v10) = v10 | 0x42; /*0x14119f*/
    *(_WORD *)(a1 + 68) = v10; /*0x1411a1*/
    v6 = *(_DWORD *)(a1 + 80); /*0x1411a5*/
    if ( (v10 & 0x4E) == 0 || *(_BYTE *)(v6 + 210) ) /*0x1411b0*/
      return 0; /*0x1411b7*/
    v11 = *(_DWORD *)(a1 + 72) / *(_DWORD *)(v6 + 184); /*0x1411d3*/
    v8 = bread( /*0x141230*/
           *(_DWORD *)(a1 + 64),
           ((((unsigned int)(*(_DWORD *)(a1 + 72) % *(_DWORD *)(v6 + 184)) / *(_DWORD *)(v6 + 120)) << *(_DWORD *)(v6 + 96))
          + *(_DWORD *)(v6 + 16)
          + *(_DWORD *)(v6 + 24) * (~*(_DWORD *)(v6 + 28) & v11)
          + v11 * *(_DWORD *)(v6 + 188)) << *(_DWORD *)(v6 + 100),
           *(_DWORD *)(v6 + 48));
    if ( (*(_BYTE *)v8 & 4) == 0 ) /*0x141238*/
    {
LABEL_19:
      if ( (*(_BYTE *)(a1 + 68) & 0x46) != 0 ) /*0x14124f*/
      {
        microtime(&iuniqtime); /*0x141256*/
        if ( (*(_BYTE *)(a1 + 68) & 4) != 0 ) /*0x141265*/
          *(_DWORD *)(a1 + 116) = iuniqtime; /*0x14126c*/
        if ( (*(_BYTE *)(a1 + 68) & 2) != 0 ) /*0x141276*/
          *(_DWORD *)(a1 + 124) = iuniqtime; /*0x14127d*/
        if ( (*(_BYTE *)(a1 + 68) & 0x40) != 0 ) /*0x141287*/
        {
          *(_DWORD *)(a1 + 76) = 0; /*0x141289*/
          *(_DWORD *)(a1 + 132) = iuniqtime; /*0x141295*/
        }
      }
      v12 = *(_WORD *)(a1 + 68); /*0x14129e*/
      v52 = v12; /*0x1412a2*/
      LOBYTE(v12) = v12 & 0xB1; /*0x1412a9*/
      *(_WORD *)(a1 + 68) = v12; /*0x1412af*/
      v13 = v8[8] + ((*(_DWORD *)(a1 + 72) % *(_DWORD *)(v6 + 120)) << 7); /*0x1412c2*/
      *(_WORD *)(a1 + 68) = v52 & 0xFDB1; /*0x1412d4*/
      byte_swap_inode_out(a1, v13); /*0x1412da*/
      if ( *(_WORD *)(*(_DWORD *)(a1 + 48) + 292) ) /*0x1412e8*/
      {
        *(_WORD *)(v13 + 4) = _byteswap_ulong(*(__int16 *)(a1 + 228)); /*0x14130b*/
        *(_WORD *)(v13 + 6) = _byteswap_ulong(*(__int16 *)(a1 + 230)); /*0x141328*/
      }
      bwrite(v8); /*0x14132d*/
      return 0; /*0x14132d*/
    }
    goto LABEL_18; /*0x141238*/
  }
  v61 = *(unsigned int **)(a1 + 80); /*0x141342*/
  v59 = a2 & ~v61[18]; /*0x141350*/
  v15 = v61[20]; /*0x141360*/
  v16 = (a2 - 1) >> v15; /*0x141365*/
  if ( a2 <= v9 ) /*0x14136a*/
  {
    v54 = (v61[12] + a2 - 1) >> v15; /*0x1415eb*/
    v62 = v54 - 1; /*0x1415f2*/
    v65 = v54 - 13; /*0x141601*/
    v66 = v54 - 13 - v61[29]; /*0x141613*/
    v67 = v66 - v61[29] * v61[29]; /*0x141624*/
    v58 = (int)v61[12] / (*(int (__cdecl **)(unsigned int))(*(_DWORD *)(a1 + 40) + 128))(a1 + 12); /*0x14164c*/
    v60 = *(_DWORD *)(a1 + 108); /*0x141658*/
    if ( v59 ) /*0x141668*/
    {
      v25 = bmap(a1, v16, 0, v59, nullptr) << v61[25]; /*0x14169a*/
      v26 = *(_BYTE *)(dword_1E875C + 104); /*0x1416a4*/
      if ( v26 || v25 < 0 ) /*0x1416ad*/
        return v26; /*0x1416b2*/
      *(_DWORD *)(a1 + 108) = a2; /*0x1416be*/
      if ( v16 <= 11 && a2 < (v16 + 1) << v61[20] ) /*0x1416dd*/
        v27 = v61[19] & (v61[13] + (a2 & ~v61[18]) - 1); /*0x141706*/
      else
        v27 = v61[12]; /*0x1416e5*/
      v28 = *(_DWORD *)(a1 + 64); /*0x14170c*/
      if ( **(_DWORD **)(a1 + 12) ) /*0x141712*/
        vnode_uncache(a1 + 12); /*0x14171e*/
      if ( !v56 ) /*0x14172d*/
      {
        v29 = bread(v28, v25, v27); /*0x141737*/
        if ( (*(_BYTE *)v29 & 4) != 0 ) /*0x14173f*/
        {
          *(_BYTE *)(dword_1E875C + 104) = 5; /*0x141746*/
          *(_DWORD *)(a1 + 108) = v60; /*0x141753*/
          brelse((int)v29); /*0x141757*/
          return 5; /*0x141761*/
        }
        bzero((void *)(v29[8] + v59), v27 - v59); /*0x14177b*/
        bdwrite((int)v29); /*0x141781*/
      }
    }
    else
    {
      *(_DWORD *)(a1 + 108) = a2; /*0x141670*/
    }
    qmemcpy(v64, (const void *)a1, sizeof(v64)); /*0x141798*/
    v64[27] = v60; /*0x1417a0*/
    for ( j = 2; j >= 0; --j ) /*0x1417a6*/
    {
      if ( (*(&v65 + j) & 0x80000000) != 0 ) /*0x1417b1*/
      {
        *(_DWORD *)(a1 + 4 * j + 188) = 0; /*0x1417b6*/
        *(&v65 + j) = -1; /*0x1417c1*/
      }
    }
    for ( k = 11; v62 < k; --k ) /*0x1417d7*/
      *(_DWORD *)(a1 + 4 * k + 140) = 0; /*0x1417df*/
    *(_DWORD *)(a1 + 108) = a2; /*0x1417f9*/
    v32 = *(_WORD *)(a1 + 68); /*0x1417fc*/
    LOBYTE(v32) = v32 | 0x42; /*0x141800*/
    *(_WORD *)(a1 + 68) = v32; /*0x141805*/
    v33 = *(_DWORD *)(a1 + 80); /*0x141809*/
    if ( (v32 & 0x4E) != 0 && !*(_BYTE *)(v33 + 210) ) /*0x141814*/
    {
      v34 = *(_DWORD *)(a1 + 72) / *(_DWORD *)(v33 + 184); /*0x141834*/
      v35 = bread( /*0x14188c*/
              *(_DWORD *)(a1 + 64),
              ((((unsigned int)(*(_DWORD *)(a1 + 72) % *(_DWORD *)(v33 + 184)) / *(_DWORD *)(v33 + 120)) << *(_DWORD *)(v33 + 96))
             + *(_DWORD *)(v33 + 16)
             + *(_DWORD *)(v33 + 24) * (~*(_DWORD *)(v33 + 28) & v34)
             + v34 * *(_DWORD *)(v33 + 188)) << *(_DWORD *)(v33 + 100),
              *(_DWORD *)(v33 + 48));
      v36 = v35; /*0x141891*/
      if ( (*(_BYTE *)v35 & 4) != 0 ) /*0x141899*/
      {
        brelse((int)v35); /*0x14189c*/
      }
      else
      {
        if ( (*(_BYTE *)(a1 + 68) & 0x46) != 0 ) /*0x1418af*/
        {
          microtime(&iuniqtime); /*0x1418b6*/
          if ( (*(_BYTE *)(a1 + 68) & 4) != 0 ) /*0x1418c5*/
            *(_DWORD *)(a1 + 116) = iuniqtime; /*0x1418cc*/
          if ( (*(_BYTE *)(a1 + 68) & 2) != 0 ) /*0x1418d6*/
            *(_DWORD *)(a1 + 124) = iuniqtime; /*0x1418dd*/
          if ( (*(_BYTE *)(a1 + 68) & 0x40) != 0 ) /*0x1418e7*/
          {
            *(_DWORD *)(a1 + 76) = 0; /*0x1418e9*/
            *(_DWORD *)(a1 + 132) = iuniqtime; /*0x1418f5*/
          }
        }
        v37 = *(_WORD *)(a1 + 68); /*0x1418fe*/
        v55 = v37; /*0x141902*/
        LOBYTE(v37) = v37 & 0xB1; /*0x141909*/
        *(_WORD *)(a1 + 68) = v37; /*0x14190f*/
        v38 = v36[8] + ((*(_DWORD *)(a1 + 72) % *(_DWORD *)(v33 + 120)) << 7); /*0x141922*/
        *(_WORD *)(a1 + 68) = v55 & 0xFDB1; /*0x141934*/
        byte_swap_inode_out(a1, v38); /*0x14193a*/
        if ( *(_WORD *)(*(_DWORD *)(a1 + 48) + 292) ) /*0x141948*/
        {
          *(_WORD *)(v38 + 4) = _byteswap_ulong(*(__int16 *)(a1 + 228)); /*0x14196b*/
          *(_WORD *)(v38 + 6) = _byteswap_ulong(*(__int16 *)(a1 + 230)); /*0x141988*/
        }
        bwrite(v36); /*0x14198d*/
      }
    }
    v39 = 2; /*0x1419a1*/
    while ( 1 ) /*0x1419ae*/
    {
      v40 = v64[v39 + 47]; /*0x1419ae*/
      if ( v40 ) /*0x1419b7*/
      {
        v57 += indirtrunc(v64, v40, *(&v65 + v39), v39); /*0x1419c8*/
        if ( (*(&v65 + v39) & 0x80000000) != 0 ) /*0x1419d6*/
        {
          v64[v39 + 47] = 0; /*0x1419de*/
          free_block((int)v64, v40, v61[12]); /*0x1419f5*/
          v57 += v58; /*0x141a00*/
        }
      }
      if ( (*(&v65 + v39) & 0x80000000) == 0 ) /*0x141a0e*/
        break; /*0x141a0e*/
      if ( --v39 < 0 ) /*0x141a15*/
      {
        for ( m = 11; v62 < m; --m ) /*0x141a22*/
        {
          v42 = v64[m + 35]; /*0x141a2e*/
          if ( v42 ) /*0x141a37*/
          {
            v64[m + 35] = 0; /*0x141a3d*/
            if ( m <= 11 && (unsigned int)((m + 1) << v61[20]) > v64[27] ) /*0x141a70*/
              v43 = v61[19] & (v61[13] + (~v61[18] & v64[27]) - 1); /*0x141a9b*/
            else
              v43 = v61[12]; /*0x141a78*/
            free_block((int)v64, v42, v43); /*0x141aa7*/
            v57 += v43 / (*(int (__cdecl **)(unsigned int))(*(_DWORD *)(a1 + 40) + 128))(a1 + 12); /*0x141acb*/
          }
        }
        if ( v62 >= 0 ) /*0x141ae8*/
        {
          v44 = v64[v62 + 35]; /*0x141afa*/
          if ( v44 ) /*0x141b03*/
          {
            if ( v62 <= 11 && v64[27] < (unsigned int)((v62 + 1) << v61[20]) ) /*0x141b31*/
              v45 = v61[19] & (v61[13] + (~v61[18] & v64[27]) - 1); /*0x141b5b*/
            else
              v45 = v61[12]; /*0x141b39*/
            v64[27] = a2; /*0x141b67*/
            if ( v62 <= 11 && a2 < (v62 + 1) << v61[20] ) /*0x141b88*/
              v46 = v61[19] & (v61[13] + (a2 & ~v61[18]) - 1); /*0x141bb2*/
            else
              v46 = v61[12]; /*0x141b90*/
            if ( !v46 ) /*0x141bb7*/
              panic(aItruncNewspace); /*0x141bbe*/
            if ( v45 != v46 ) /*0x141bc8*/
            {
              v47 = (v46 >> v61[21]) + v44; /*0x141bd7*/
              v48 = v45 - v46; /*0x141bdb*/
              free_block((int)v64, v47, v48); /*0x141be6*/
              v57 += v48 / (*(int (__cdecl **)(unsigned int))(*(_DWORD *)(a1 + 40) + 128))(a1 + 12); /*0x141c0a*/
            }
          }
        }
        break; /*0x141c0a*/
      }
    }
    for ( n = 0; n <= 2; ++n ) /*0x141c13*/
    {
      if ( v64[n + 47] != *(_DWORD *)(a1 + 4 * n + 188) ) /*0x141c2f*/
        panic(aItrunc1); /*0x141c36*/
    }
    for ( ii = 0; ii <= 11; ++ii ) /*0x141c44*/
    {
      if ( v64[ii + 35] != *(_DWORD *)(a1 + 4 * ii + 140) ) /*0x141c5f*/
        panic(aItrunc2); /*0x141c66*/
    }
    v51 = *(_DWORD *)(a1 + 204) - v57; /*0x141c7d*/
    *(_DWORD *)(a1 + 204) = v51; /*0x141c86*/
    if ( v51 < 0 ) /*0x141c8c*/
      *(_DWORD *)(a1 + 204) = 0; /*0x141c8e*/
    *(_BYTE *)(a1 + 68) |= 0x40u; /*0x141c9b*/
    return *(char *)(dword_1E875C + 104); /*0x141ca9*/
  }
  else
  {
    if ( v59 ) /*0x141377*/
      v17 = bmap(a1, (a2 - 1) >> v15, 0, v59, &v63); /*0x1413a5*/
    else
      v17 = bmap(a1, (a2 - 1) >> v15, 0, v61[12], &v63); /*0x14138b*/
    if ( !*(_BYTE *)(dword_1E875C + 104) || v17 >= 0 ) /*0x1413bc*/
    {
      *(_DWORD *)(a1 + 108) = a2; /*0x1413c4*/
      v18 = *(_WORD *)(a1 + 68); /*0x1413c7*/
      *(_WORD *)(a1 + 68) = v18 | 0x40; /*0x1413d3*/
      LOBYTE(v18) = v18 | 0x48; /*0x1413dc*/
      *(_WORD *)(a1 + 68) = v18; /*0x1413df*/
      microtime(&iuniqtime); /*0x1413e8*/
      if ( (*(_BYTE *)(a1 + 68) & 4) != 0 ) /*0x1413f7*/
        *(_DWORD *)(a1 + 116) = iuniqtime; /*0x1413fe*/
      if ( (*(_BYTE *)(a1 + 68) & 2) != 0 ) /*0x141408*/
        *(_DWORD *)(a1 + 124) = iuniqtime; /*0x14140f*/
      if ( (*(_BYTE *)(a1 + 68) & 0x40) != 0 ) /*0x141419*/
      {
        *(_DWORD *)(a1 + 76) = 0; /*0x14141b*/
        *(_DWORD *)(a1 + 132) = iuniqtime; /*0x141427*/
      }
      *(_BYTE *)(a1 + 68) &= 0xB9u; /*0x141430*/
    }
    if ( v63 ) /*0x14143b*/
    {
      v19 = *(_DWORD *)(a1 + 80); /*0x141444*/
      if ( (*(_BYTE *)(a1 + 68) & 0x4E) != 0 && !*(_BYTE *)(v19 + 210) ) /*0x141451*/
      {
        v20 = *(_DWORD *)(a1 + 72) / *(_DWORD *)(v19 + 184); /*0x141471*/
        v21 = bread( /*0x1414c9*/
                *(_DWORD *)(a1 + 64),
                ((((unsigned int)(*(_DWORD *)(a1 + 72) % *(_DWORD *)(v19 + 184)) / *(_DWORD *)(v19 + 120)) << *(_DWORD *)(v19 + 96))
               + *(_DWORD *)(v19 + 16)
               + *(_DWORD *)(v19 + 24) * (~*(_DWORD *)(v19 + 28) & v20)
               + v20 * *(_DWORD *)(v19 + 188)) << *(_DWORD *)(v19 + 100),
                *(_DWORD *)(v19 + 48));
        v22 = v21; /*0x1414ce*/
        if ( (*(_BYTE *)v21 & 4) != 0 ) /*0x1414d6*/
        {
          brelse((int)v21); /*0x1414d9*/
        }
        else
        {
          if ( (*(_BYTE *)(a1 + 68) & 0x46) != 0 ) /*0x1414eb*/
          {
            microtime(&iuniqtime); /*0x1414f2*/
            if ( (*(_BYTE *)(a1 + 68) & 4) != 0 ) /*0x141501*/
              *(_DWORD *)(a1 + 116) = iuniqtime; /*0x141508*/
            if ( (*(_BYTE *)(a1 + 68) & 2) != 0 ) /*0x141512*/
              *(_DWORD *)(a1 + 124) = iuniqtime; /*0x141519*/
            if ( (*(_BYTE *)(a1 + 68) & 0x40) != 0 ) /*0x141523*/
            {
              *(_DWORD *)(a1 + 76) = 0; /*0x141525*/
              *(_DWORD *)(a1 + 132) = iuniqtime; /*0x141531*/
            }
          }
          v23 = *(_WORD *)(a1 + 68); /*0x14153a*/
          v53 = v23; /*0x14153e*/
          LOBYTE(v23) = v23 & 0xB1; /*0x141545*/
          *(_WORD *)(a1 + 68) = v23; /*0x14154b*/
          v24 = v22[8] + ((*(_DWORD *)(a1 + 72) % *(_DWORD *)(v19 + 120)) << 7); /*0x14155e*/
          *(_WORD *)(a1 + 68) = v53 & 0xFDB1; /*0x141570*/
          byte_swap_inode_out(a1, v24); /*0x141576*/
          if ( *(_WORD *)(*(_DWORD *)(a1 + 48) + 292) ) /*0x141584*/
          {
            *(_WORD *)(v24 + 4) = _byteswap_ulong(*(__int16 *)(a1 + 228)); /*0x1415a7*/
            *(_WORD *)(v24 + 6) = _byteswap_ulong(*(__int16 *)(a1 + 230)); /*0x1415c4*/
          }
          bwrite(v22); /*0x1415c9*/
        }
      }
    }
    return *(char *)(dword_1E875C + 104); /*0x1415d3*/
  }
}
