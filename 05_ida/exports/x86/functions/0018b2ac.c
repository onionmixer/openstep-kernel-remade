/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b2ac. */
int __cdecl in_cksum(int *a1, int a2)
{
  int v2; // eax
  _DWORD *v3; // esi
  bool v4; // cf
  int v5; // eax
  unsigned int v6; // ecx
  int v7; // edx
  int v8; // ebx
  unsigned int v9; // ecx
  int *v10; // esi
  int v11; // eax
  int v12; // eax
  _BOOL4 v13; // ett
  bool v14; // cf
  int v15; // ebx
  int v16; // ebx
  int v17; // eax
  _BOOL4 v18; // ett
  int v19; // ebx
  int *v20; // eax
  int v21; // eax
  int *v22; // esi
  bool v23; // cf
  int v24; // eax
  unsigned int v25; // ecx
  int v26; // edx
  int v27; // ebx
  unsigned int v28; // ecx
  int *v29; // esi
  int v30; // eax
  int v31; // eax
  _BOOL4 v32; // ett
  bool v33; // cf
  int v34; // ebx
  int v35; // ebx
  int v36; // eax
  _BOOL4 v37; // ett
  int v38; // ebx
  __int16 v39; // dx
  unsigned __int8 *v40; // ecx
  int v41; // eax
  unsigned int v42; // ecx
  unsigned __int8 *v43; // esi
  unsigned int v44; // edx
  bool v45; // cf
  int v46; // eax
  unsigned int v47; // ecx
  int v48; // edx
  int v49; // ebx
  unsigned int v50; // ecx
  int *v51; // esi
  int v52; // eax
  int v53; // eax
  _BOOL4 v54; // ett
  bool v55; // cf
  int v56; // ebx
  int v57; // ebx
  int v58; // eax
  _BOOL4 v59; // ett
  int v60; // ebx
  int *v62; // [esp+10h] [ebp-Ch]
  unsigned __int8 *v63; // [esp+10h] [ebp-Ch]
  unsigned int v64; // [esp+14h] [ebp-8h]
  int v65; // [esp+18h] [ebp-4h]

  v65 = 0; /*0x18b2b5*/
  while ( 1 ) /*0x18b46f*/
  {
    LOWORD(v44) = *((_WORD *)a1 + 4); /*0x18b46f*/
    if ( a2 <= (__int16)v44 ) /*0x18b479*/
      break; /*0x18b479*/
    v44 = (__int16)v44; /*0x18b2c4*/
    v64 = v44; /*0x18b2c7*/
    v2 = v65; /*0x18b2d0*/
    v3 = (int *)((char *)a1 + a1[1]); /*0x18b2d5*/
    if ( (v44 & 1) != 0 ) /*0x18b2da*/
    {
      v14 = 0; /*0x18b326*/
      if ( (v44 & 2) != 0 ) /*0x18b329*/
      {
        v15 = *(unsigned __int16 *)((char *)v3 + (__int16)v44 - 3); /*0x18b32b*/
        v14 = __CFADD__(v15, v65); /*0x18b330*/
        v2 = v15 + v65; /*0x18b330*/
      }
      v16 = *((unsigned __int8 *)v3 + (__int16)v44 - 1); /*0x18b332*/
      v18 = v14; /*0x18b337*/
      v4 = __CFADD__(v14, v2); /*0x18b337*/
      v17 = v18 + v2; /*0x18b337*/
      v4 |= __CFADD__(v16, v17); /*0x18b337*/
      v2 = v16 + v17; /*0x18b337*/
    }
    else
    {
      v4 = 0; /*0x18b2dc*/
      if ( (v44 & 2) != 0 ) /*0x18b2df*/
      {
        v19 = *(unsigned __int16 *)((char *)v3 + (__int16)v44 - 2); /*0x18b33b*/
        v4 = __CFADD__(v19, v65); /*0x18b340*/
        v2 = v19 + v65; /*0x18b340*/
      }
    }
    v5 = v4 + v2; /*0x18b2e1*/
    v6 = (unsigned int)(__int16)v44 >> 3; /*0x18b2e4*/
    if ( (v44 & 4) != 0 ) /*0x18b2e7*/
    {
      v5 += __CFADD__(*v3, v5) + *v3; /*0x18b2eb*/
      ++v3; /*0x18b2ee*/
    }
    if ( v6 ) /*0x18b2f3*/
    {
      v7 = *v3; /*0x18b2f5*/
      v8 = v3[1]; /*0x18b2f7*/
      v9 = v6 - 1; /*0x18b2fa*/
      if ( v9 ) /*0x18b2fb*/
      {
        v10 = v3 + 2; /*0x18b2fd*/
        do /*0x18b310*/
        {
          v4 = __CFADD__(v7, v5); /*0x18b300*/
          v11 = v7 + v5; /*0x18b300*/
          v7 = *v10; /*0x18b302*/
          v13 = v4; /*0x18b304*/
          v4 = __CFADD__(v4, v11); /*0x18b304*/
          v12 = v13 + v11; /*0x18b304*/
          v4 |= __CFADD__(v8, v12); /*0x18b304*/
          v12 += v8; /*0x18b304*/
          v8 = v10[1]; /*0x18b306*/
          v5 = v4 + v12; /*0x18b309*/
          v10 += 2; /*0x18b30c*/
          --v9; /*0x18b30f*/
        }
        while ( v9 ); /*0x18b310*/
      }
      v5 += (__CFADD__(__CFADD__(v7, v5), v7 + v5) | __CFADD__(v8, __CFADD__(v7, v5) + v7 + v5)) /*0x18b316*/
          + v8
          + __CFADD__(v7, v5)
          + v7;
    }
    v65 = (unsigned __int16)(__CFADD__(HIWORD(v5), (_WORD)v5) + HIWORD(v5) + v5); /*0x18b34c*/
    v20 = (int *)*a1; /*0x18b352*/
    a1 = (int *)*a1; /*0x18b354*/
    a2 -= v64; /*0x18b35a*/
    if ( (v64 & 1) != 0 ) /*0x18b360*/
    {
      while ( 1 ) /*0x18b431*/
      {
        v39 = *((_WORD *)v20 + 4); /*0x18b431*/
        if ( a2 <= v39 ) /*0x18b43b*/
          break; /*0x18b43b*/
        v62 = (int *)((char *)a1 + a1[1]); /*0x18b372*/
        if ( (v64 & 1) != 0 ) /*0x18b37b*/
        {
          v64 = v39 - 1; /*0x18b383*/
          --a2; /*0x18b386*/
          v65 += *((unsigned __int8 *)a1 + a1[1]) << 8; /*0x18b38f*/
          v62 = (int *)((char *)v62 + 1); /*0x18b392*/
        }
        else
        {
          v64 = *((__int16 *)a1 + 4); /*0x18b39f*/
        }
        v21 = v65; /*0x18b3a2*/
        v22 = v62; /*0x18b3a8*/
        if ( (v64 & 1) != 0 ) /*0x18b3ae*/
        {
          v33 = 0; /*0x18b3fa*/
          if ( (v64 & 2) != 0 ) /*0x18b3fd*/
          {
            v34 = *(unsigned __int16 *)((char *)v62 + v64 - 3); /*0x18b3ff*/
            v33 = __CFADD__(v34, v65); /*0x18b404*/
            v21 = v34 + v65; /*0x18b404*/
          }
          v35 = *((unsigned __int8 *)v62 + v64 - 1); /*0x18b406*/
          v37 = v33; /*0x18b40b*/
          v4 = __CFADD__(v33, v21); /*0x18b40b*/
          v36 = v37 + v21; /*0x18b40b*/
          v23 = v4 | __CFADD__(v35, v36); /*0x18b40b*/
          v21 = v35 + v36; /*0x18b40b*/
        }
        else
        {
          v23 = 0; /*0x18b3b0*/
          if ( (v64 & 2) != 0 ) /*0x18b3b3*/
          {
            v38 = *(unsigned __int16 *)((char *)v62 + v64 - 2); /*0x18b40f*/
            v23 = __CFADD__(v38, v65); /*0x18b414*/
            v21 = v38 + v65; /*0x18b414*/
          }
        }
        v24 = v23 + v21; /*0x18b3b5*/
        v25 = v64 >> 3; /*0x18b3b8*/
        if ( (v64 & 4) != 0 ) /*0x18b3bb*/
        {
          v24 += __CFADD__(*v62, v24) + *v62; /*0x18b3bf*/
          v22 = v62 + 1; /*0x18b3c2*/
        }
        if ( v25 ) /*0x18b3c7*/
        {
          v26 = *v22; /*0x18b3c9*/
          v27 = v22[1]; /*0x18b3cb*/
          v28 = v25 - 1; /*0x18b3ce*/
          if ( v28 ) /*0x18b3cf*/
          {
            v29 = v22 + 2; /*0x18b3d1*/
            do /*0x18b3e4*/
            {
              v4 = __CFADD__(v26, v24); /*0x18b3d4*/
              v30 = v26 + v24; /*0x18b3d4*/
              v26 = *v29; /*0x18b3d6*/
              v32 = v4; /*0x18b3d8*/
              v4 = __CFADD__(v4, v30); /*0x18b3d8*/
              v31 = v32 + v30; /*0x18b3d8*/
              v4 |= __CFADD__(v27, v31); /*0x18b3d8*/
              v31 += v27; /*0x18b3d8*/
              v27 = v29[1]; /*0x18b3da*/
              v24 = v4 + v31; /*0x18b3dd*/
              v29 += 2; /*0x18b3e0*/
              --v28; /*0x18b3e3*/
            }
            while ( v28 ); /*0x18b3e4*/
          }
          v24 += (__CFADD__(__CFADD__(v26, v24), v26 + v24) | __CFADD__(v27, __CFADD__(v26, v24) + v26 + v24)) /*0x18b3ea*/
               + v27
               + __CFADD__(v26, v24)
               + v26;
        }
        v65 = (unsigned __int16)(__CFADD__(HIWORD(v24), (_WORD)v24) + HIWORD(v24) + v24); /*0x18b420*/
        v20 = (int *)*a1; /*0x18b426*/
        a1 = (int *)*a1; /*0x18b428*/
        a2 -= v64; /*0x18b42e*/
      }
      if ( (v64 & 1) != 0 ) /*0x18b446*/
      {
        v40 = (unsigned __int8 *)a1 + a1[1]; /*0x18b44b*/
        v63 = v40 + 1; /*0x18b458*/
        v41 = (*v40 << 8) + v65; /*0x18b45f*/
        v42 = a2 - 1; /*0x18b462*/
        v43 = v63; /*0x18b464*/
        goto LABEL_40; /*0x18b467*/
      }
    }
  }
  v41 = v65; /*0x18b485*/
  v42 = a2; /*0x18b488*/
  v43 = (unsigned __int8 *)a1 + a1[1]; /*0x18b48b*/
LABEL_40:
  if ( (v42 & 1) != 0 ) /*0x18b490*/
  {
    v55 = 0; /*0x18b4dc*/
    if ( (v42 & 2) != 0 ) /*0x18b4df*/
    {
      v56 = *(unsigned __int16 *)&v43[v42 - 3]; /*0x18b4e1*/
      v55 = __CFADD__(v56, v41); /*0x18b4e6*/
      v41 += v56; /*0x18b4e6*/
    }
    v57 = v43[v42 - 1]; /*0x18b4e8*/
    v59 = v55; /*0x18b4ed*/
    v4 = __CFADD__(v55, v41); /*0x18b4ed*/
    v58 = v59 + v41; /*0x18b4ed*/
    v45 = v4 | __CFADD__(v57, v58); /*0x18b4ed*/
    v41 = v57 + v58; /*0x18b4ed*/
  }
  else
  {
    v45 = 0; /*0x18b492*/
    if ( (v42 & 2) != 0 ) /*0x18b495*/
    {
      v60 = *(unsigned __int16 *)&v43[v42 - 2]; /*0x18b4f1*/
      v45 = __CFADD__(v60, v41); /*0x18b4f6*/
      v41 += v60; /*0x18b4f6*/
    }
  }
  v46 = v45 + v41; /*0x18b497*/
  v4 = __CFSHR__(v42, 3); /*0x18b49a*/
  v47 = v42 >> 3; /*0x18b49a*/
  if ( v4 ) /*0x18b49d*/
  {
    v46 += __CFADD__(*(_DWORD *)v43, v46) + *(_DWORD *)v43; /*0x18b4a1*/
    v43 += 4; /*0x18b4a4*/
  }
  if ( v47 ) /*0x18b4a9*/
  {
    v48 = *(_DWORD *)v43; /*0x18b4ab*/
    v49 = *((_DWORD *)v43 + 1); /*0x18b4ad*/
    v50 = v47 - 1; /*0x18b4b0*/
    if ( v50 ) /*0x18b4b1*/
    {
      v51 = (int *)(v43 + 8); /*0x18b4b3*/
      do /*0x18b4c6*/
      {
        v4 = __CFADD__(v48, v46); /*0x18b4b6*/
        v52 = v48 + v46; /*0x18b4b6*/
        v48 = *v51; /*0x18b4b8*/
        v54 = v4; /*0x18b4ba*/
        v4 = __CFADD__(v4, v52); /*0x18b4ba*/
        v53 = v54 + v52; /*0x18b4ba*/
        v4 |= __CFADD__(v49, v53); /*0x18b4ba*/
        v53 += v49; /*0x18b4ba*/
        v49 = v51[1]; /*0x18b4bc*/
        v46 = v4 + v53; /*0x18b4bf*/
        v51 += 2; /*0x18b4c2*/
        --v50; /*0x18b4c5*/
      }
      while ( v50 ); /*0x18b4c6*/
    }
    v46 += (__CFADD__(__CFADD__(v48, v46), v48 + v46) | __CFADD__(v49, __CFADD__(v48, v46) + v48 + v46)) /*0x18b4cc*/
         + v49
         + __CFADD__(v48, v46)
         + v48;
  }
  return (unsigned __int16)~(__CFADD__(HIWORD(v46), (_WORD)v46) + HIWORD(v46) + v46); /*0x18b50b*/
}
