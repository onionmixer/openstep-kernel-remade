/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119e00. */
size_t __cdecl breadDirect(int a1, int a2, int a3, int a4, size_t a5, int a6, int a7, _DWORD *a8)
{
  int *v8; // esi
  int v9; // eax
  _DWORD *v10; // ebx
  _DWORD *v11; // ebx
  int v12; // eax
  _DWORD *v13; // eax
  int v14; // ebx
  char *v16; // eax
  _DWORD *v17; // ebx
  int v18; // [esp+Ch] [ebp-44h] BYREF
  int v19; // [esp+10h] [ebp-40h]
  char *v20; // [esp+14h] [ebp-3Ch]
  vm_size_t v21; // [esp+20h] [ebp-30h]
  vm_size_t v22; // [esp+24h] [ebp-2Ch]
  __int16 v23; // [esp+28h] [ebp-28h]
  __int16 v24; // [esp+2Ah] [ebp-26h]
  int v25; // [esp+2Ch] [ebp-24h]
  int v26; // [esp+30h] [ebp-20h]
  int v27; // [esp+34h] [ebp-1Ch]
  int v28; // [esp+48h] [ebp-8h]
  int v29; // [esp+4Ch] [ebp-4h]
  size_t v30; // [esp+68h] [ebp+18h]

  v29 = 0; /*0x119e0c*/
  if ( incore(a1, a3) ) /*0x119e18*/
  {
    ++dword_1E99C8; /*0x119e28*/
    v8 = nullptr; /*0x119e2e*/
    if ( !incore(a1, a3) ) /*0x119e35*/
    {
      v8 = (int *)getblk(a1, a3, a4); /*0x119e4f*/
      v9 = *v8; /*0x119e51*/
      if ( (*v8 & 2) != 0 ) /*0x119e58*/
      {
        ++dword_1E99CC; /*0x119e90*/
      }
      else
      {
        LOBYTE(v9) = v9 | 1; /*0x119e5a*/
        *v8 = v9; /*0x119e5c*/
        if ( v8[5] > v8[6] ) /*0x119e64*/
          panic(aBreada); /*0x119e6b*/
        (*(void (__cdecl **)(int *))(*(_DWORD *)(v8[16] + 28) + 84))(v8); /*0x119e7d*/
        ++*(_DWORD *)(active_u + 412); /*0x119e84*/
      }
    }
    if ( a6 && !incore(a1, a6) ) /*0x119ea1*/
    {
      v10 = (_DWORD *)getblk(a1, a6, a7); /*0x119ebb*/
      if ( (*v10 & 2) != 0 ) /*0x119ec4*/
      {
        brelse((int)v10); /*0x119ec7*/
        ++dword_1E99D0; /*0x119ecc*/
      }
      else
      {
        *v10 |= 0x101u; /*0x119ed9*/
        if ( v10[5] > v10[6] ) /*0x119ee1*/
          panic(aBreadrabp); /*0x119ee8*/
        (*(void (__cdecl **)(_DWORD *))(*(_DWORD *)(v10[16] + 28) + 84))(v10); /*0x119efa*/
        ++*(_DWORD *)(active_u + 412); /*0x119f01*/
      }
    }
    if ( v8 ) /*0x119f0c*/
    {
      biowait((unsigned int)v8); /*0x119f8d*/
      v14 = (int)v8; /*0x119f92*/
    }
    else
    {
      ++bstats; /*0x119f0e*/
      if ( !a4 ) /*0x119f18*/
        panic(aBreadSize0); /*0x119f1f*/
      v11 = (_DWORD *)getblk(a1, a3, a4); /*0x119f35*/
      v12 = *v11; /*0x119f37*/
      if ( (*v11 & 2) != 0 ) /*0x119f3e*/
      {
        ++dword_1E99C4; /*0x119f40*/
        v13 = v11; /*0x119f46*/
      }
      else
      {
        LOBYTE(v12) = v12 | 1; /*0x119f4c*/
        *v11 = v12; /*0x119f4e*/
        if ( v11[5] > v11[6] ) /*0x119f56*/
          panic(aBread); /*0x119f5d*/
        (*(void (__cdecl **)(_DWORD *))(*(_DWORD *)(v11[16] + 28) + 84))(v11); /*0x119f6f*/
        ++*(_DWORD *)(active_u + 412); /*0x119f76*/
        biowait((unsigned int)v11); /*0x119f7d*/
        v13 = v11; /*0x119f82*/
      }
      v14 = (int)v13; /*0x119f87*/
    }
    if ( (*(_BYTE *)v14 & 4) != 0 ) /*0x119f9a*/
    {
      brelse(v14); /*0x119fcd*/
      *a8 = *(__int16 *)(v14 + 28); /*0x119fd9*/
      return 0; /*0x119fdb*/
    }
    else
    {
      copy_to_phys(*(void **)(v14 + 32), *(void **)(a2 + 36), a5); /*0x119fab*/
      *a8 = 0; /*0x119fb3*/
      brelse(v14); /*0x119fba*/
      return a4 - *(_DWORD *)(v14 + 40); /*0x119fc2*/
    }
  }
  else
  {
    v29 = 0; /*0x119fe7*/
    sub_11B244(&v18, a1); /*0x119ff0*/
    v24 = *(_WORD *)(a1 + 44); /*0x119ff9*/
    v18 = 33554433; /*0x119ffd*/
    v26 = a3; /*0x11a007*/
    v22 = page_size; /*0x11a010*/
    v21 = page_size; /*0x11a019*/
    v23 = 0; /*0x11a01c*/
    v27 = 0; /*0x11a022*/
    v25 = *(_DWORD *)(a2 + 36); /*0x11a02f*/
    v28 = 0; /*0x11a032*/
    ++*(_DWORD *)(active_u + 412); /*0x11a03e*/
    v16 = (char *)&bufhash + 12 * (((_BYTE)a1 + (unsigned __int8)(a3 / 8)) & 0xF); /*0x11a059*/
    v19 = *((_DWORD *)v16 + 1); /*0x11a063*/
    v20 = v16; /*0x11a066*/
    *(_DWORD *)(*((_DWORD *)v16 + 1) + 8) = &v18; /*0x11a06c*/
    *((_DWORD *)v16 + 1) = &v18; /*0x11a06f*/
    (*(void (__cdecl **)(int *))(*(_DWORD *)(v29 + 28) + 84))(&v18); /*0x11a07c*/
    if ( a6 && !incore(a1, a6) ) /*0x11a08c*/
    {
      v17 = (_DWORD *)getblk(a1, a6, a7); /*0x11a0a6*/
      if ( (*v17 & 2) != 0 ) /*0x11a0af*/
      {
        brelse((int)v17); /*0x11a0b2*/
      }
      else
      {
        *v17 |= 0x101u; /*0x11a0c1*/
        if ( v17[5] > v17[6] ) /*0x11a0c9*/
          panic(aBreadrabp_0); /*0x11a0d0*/
        (*(void (__cdecl **)(_DWORD *))(*(_DWORD *)(v17[16] + 28) + 84))(v17); /*0x11a0e2*/
        ++*(_DWORD *)(active_u + 412); /*0x11a0e9*/
      }
    }
    biowait((unsigned int)&v18); /*0x11a0f6*/
    if ( (v18 & 4) != 0 ) /*0x11a102*/
    {
      *a8 = v23; /*0x11a137*/
      v30 = a4 - v27; /*0x11a13f*/
      *((_DWORD *)v20 + 1) = v19; /*0x11a148*/
      *(_DWORD *)(v19 + 8) = v20; /*0x11a151*/
      sub_11B26C((int)&v18); /*0x11a155*/
      return v30; /*0x11a15a*/
    }
    else
    {
      *((_DWORD *)v20 + 1) = v19; /*0x11a10a*/
      *(_DWORD *)(v19 + 8) = v20; /*0x11a113*/
      sub_11B26C((int)&v18); /*0x11a117*/
      *a8 = 0; /*0x11a11f*/
      return a4 - v27; /*0x11a128*/
    }
  }
}
