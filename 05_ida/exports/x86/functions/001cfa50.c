/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cfa50. */
char *__cdecl sub_1CFA50(int a1)
{
  char *v1; // esi
  uint32_t v2; // edi
  uint32_t i; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  _DWORD *m; // esi
  unsigned int n; // edi
  char **v9; // ebx
  int v10; // eax
  _DWORD *ii; // esi
  unsigned int jj; // edi
  char **v13; // ebx
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  int v17; // eax
  int v18; // edi
  unsigned int kk; // esi
  char **v20; // ebx
  int v21; // eax
  int v22; // edi
  unsigned int mm; // esi
  char **v24; // ebx
  int v25; // eax
  char *result; // eax
  unsigned int *v27; // edi
  unsigned int i1; // esi
  char **v29; // ebx
  int v30; // eax
  unsigned int *v31; // edi
  unsigned int i2; // esi
  char **v33; // ebx
  int v34; // eax
  uint32_t nn; // [esp+10h] [ebp-20h]
  int v36; // [esp+14h] [ebp-1Ch]
  int v37; // [esp+18h] [ebp-18h]
  unsigned int k; // [esp+1Ch] [ebp-14h]
  unsigned int v39; // [esp+1Ch] [ebp-14h]
  char *v40; // [esp+20h] [ebp-10h]
  unsigned int j; // [esp+24h] [ebp-Ch]
  int v42; // [esp+28h] [ebp-8h]
  uint32_t size; // [esp+2Ch] [ebp-4h] BYREF

  v42 = *(_DWORD *)(a1 + 4); /*0x1cfa5f*/
  v1 = getsectdatafromheaderinfo(a1, "__OBJC", "__message_refs", &size); /*0x1cfa79*/
  if ( v1 ) /*0x1cfa80*/
  {
    v2 = size >> 2; /*0x1cfa85*/
    for ( i = 0; i < v2; ++i ) /*0x1cfa85*/
    {
      v4 = _sel_registerName(*(char **)&v1[4 * i]); /*0x1cfa94*/
      if ( *(_DWORD *)&v1[4 * i] != v4 ) /*0x1cfa9f*/
        *(_DWORD *)&v1[4 * i] = v4; /*0x1cfaa1*/
    }
  }
  for ( j = 0; *(_DWORD *)(a1 + 8) > j; ++j ) /*0x1cfaa9*/
  {
    v5 = 16 * j; /*0x1cfabe*/
    if ( *(_DWORD *)(v42 + 16 * j + 12) ) /*0x1cfac3*/
    {
      for ( k = 0; k < *(unsigned __int16 *)(*(_DWORD *)(v42 + 16 * j + 12) + 8); v5 = 16 * j ) /*0x1cfad9*/
      {
        v6 = *(_DWORD *)(*(_DWORD *)(v42 + v5 + 12) + 4 * k + 12); /*0x1cfaee*/
        v37 = v6; /*0x1cfaf2*/
        if ( *(_DWORD *)(v6 + 28) ) /*0x1cfaf5*/
        {
          for ( m = *(_DWORD **)(v6 + 28); *m; m = (_DWORD *)*m ) /*0x1cfafe*/
            ; /*0x1cfb04*/
          for ( n = 0; m[1] > n; ++n ) /*0x1cfb0d*/
          {
            v9 = (char **)&m[3 * n + 2]; /*0x1cfb17*/
            v10 = _sel_registerName(*v9); /*0x1cfb1e*/
            if ( *v9 != (char *)v10 ) /*0x1cfb28*/
              *v9 = (char *)v10; /*0x1cfb2a*/
          }
        }
        if ( *(_DWORD *)(*(_DWORD *)v37 + 28) ) /*0x1cfb37*/
        {
          for ( ii = *(_DWORD **)(*(_DWORD *)v37 + 28); *ii; ii = (_DWORD *)*ii ) /*0x1cfb40*/
            ; /*0x1cfb48*/
          for ( jj = 0; ii[1] > jj; ++jj ) /*0x1cfb51*/
          {
            v13 = (char **)&ii[3 * jj + 2]; /*0x1cfb5b*/
            v14 = _sel_registerName(*v13); /*0x1cfb62*/
            if ( *v13 != (char *)v14 ) /*0x1cfb6c*/
              *v13 = (char *)v14; /*0x1cfb6e*/
          }
        }
        ++k; /*0x1cfb76*/
      }
      v15 = 16 * j; /*0x1cfb99*/
      v16 = *(_DWORD *)(v42 + 16 * j + 12); /*0x1cfb9e*/
      v39 = *(unsigned __int16 *)(v16 + 8); /*0x1cfba6*/
      if ( v39 < v39 + *(unsigned __int16 *)(v16 + 10) ) /*0x1cfbb1*/
      {
        do /*0x1cfc4e*/
        {
          v17 = *(_DWORD *)(*(_DWORD *)(v42 + v15 + 12) + 4 * v39 + 12); /*0x1cfbc2*/
          v36 = v17; /*0x1cfbc6*/
          if ( *(_DWORD *)(v17 + 8) ) /*0x1cfbc9*/
          {
            v18 = *(_DWORD *)(v17 + 8); /*0x1cfbcf*/
            for ( kk = 0; *(_DWORD *)(v18 + 4) > kk; ++kk ) /*0x1cfbd4*/
            {
              v20 = (char **)(v18 + 12 * kk + 8); /*0x1cfbdf*/
              v21 = _sel_registerName(*v20); /*0x1cfbe6*/
              if ( *v20 != (char *)v21 ) /*0x1cfbf0*/
                *v20 = (char *)v21; /*0x1cfbf2*/
            }
          }
          if ( *(_DWORD *)(v36 + 12) ) /*0x1cfbfd*/
          {
            v22 = *(_DWORD *)(v36 + 12); /*0x1cfc03*/
            for ( mm = 0; *(_DWORD *)(v22 + 4) > mm; ++mm ) /*0x1cfc08*/
            {
              v24 = (char **)(v22 + 12 * mm + 8); /*0x1cfc13*/
              v25 = _sel_registerName(*v24); /*0x1cfc1a*/
              if ( *v24 != (char *)v25 ) /*0x1cfc24*/
                *v24 = (char *)v25; /*0x1cfc26*/
            }
          }
          ++v39; /*0x1cfc2e*/
          v15 = 16 * j; /*0x1cfc34*/
        }
        while ( v39 < *(unsigned __int16 *)(*(_DWORD *)(v42 + 16 * j + 12) + 8) /*0x1cfc4e*/
                    + (unsigned int)*(unsigned __int16 *)(*(_DWORD *)(v42 + 16 * j + 12) + 10) );
      }
    }
  }
  result = getsectdatafromheaderinfo(a1, "__OBJC", "__protocol", &size); /*0x1cfc78*/
  v40 = result; /*0x1cfc7d*/
  if ( result ) /*0x1cfc85*/
  {
    for ( nn = 0; ; ++nn ) /*0x1cfc8b*/
    {
      result = (char *)(size / 0x14); /*0x1cfd13*/
      if ( nn >= size / 0x14 ) /*0x1cfd18*/
        break; /*0x1cfd18*/
      if ( *(_DWORD *)&v40[20 * nn + 12] ) /*0x1cfca0*/
      {
        v27 = *(unsigned int **)&v40[20 * nn + 12]; /*0x1cfca7*/
        for ( i1 = 0; *v27 > i1; ++i1 ) /*0x1cfcad*/
        {
          v29 = (char **)&v27[2 * i1 + 1]; /*0x1cfcb4*/
          v30 = _sel_registerName(*v29); /*0x1cfcbb*/
          if ( *v29 != (char *)v30 ) /*0x1cfcc5*/
            *v29 = (char *)v30; /*0x1cfcc7*/
        }
      }
      if ( *(_DWORD *)&v40[20 * nn + 16] ) /*0x1cfcda*/
      {
        v31 = *(unsigned int **)&v40[20 * nn + 16]; /*0x1cfce1*/
        for ( i2 = 0; *v31 > i2; ++i2 ) /*0x1cfce7*/
        {
          v33 = (char **)&v31[2 * i2 + 1]; /*0x1cfcec*/
          v34 = _sel_registerName(*v33); /*0x1cfcf3*/
          if ( *v33 != (char *)v34 ) /*0x1cfcfd*/
            *v33 = (char *)v34; /*0x1cfcff*/
        }
      }
    }
  }
  return result; /*0x1cfd21*/
}
