/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x127cc8. */
int __cdecl ip_setmoptions(int a1, int *a2, int a3)
{
  int v3; // edi
  int v4; // eax
  int v6; // edi
  int v7; // edi
  int v8; // edx
  _DWORD *v9; // eax
  unsigned __int8 v10; // al
  unsigned int v11; // edx
  _DWORD *v12; // eax
  int v13; // ebx
  _DWORD *v14; // edx
  _DWORD *v15; // eax
  unsigned int v16; // edx
  _DWORD *v17; // eax
  int v18; // ebx
  int i; // ebx
  int v20; // [esp+Ch] [ebp-2Ch]
  int v21; // [esp+Ch] [ebp-2Ch]
  int v22; // [esp+Ch] [ebp-2Ch]
  unsigned int *v23; // [esp+10h] [ebp-28h]
  unsigned int *v24; // [esp+10h] [ebp-28h]
  int v25; // [esp+20h] [ebp-18h]
  int v26; // [esp+24h] [ebp-14h] BYREF
  __int16 v27; // [esp+28h] [ebp-10h]
  unsigned int v28; // [esp+2Ch] [ebp-Ch]

  v25 = 0; /*0x127cd4*/
  if ( !*a2 ) /*0x127cde*/
  {
    v3 = splimp(); /*0x127cec*/
    v4 = mfree; /*0x127cee*/
    *a2 = mfree; /*0x127cf6*/
    if ( v4 ) /*0x127cfa*/
    {
      if ( *(_WORD *)(v4 + 10) ) /*0x127cfc*/
        panic(aMget_10); /*0x127d08*/
      *(_WORD *)(*a2 + 10) = 14; /*0x127d15*/
      --word_1E917C[0]; /*0x127d1b*/
      ++word_1E9198; /*0x127d22*/
      mfree = *(_DWORD *)*a2; /*0x127d2d*/
      *(_DWORD *)*a2 = 0; /*0x127d34*/
      *(_DWORD *)(*a2 + 4) = 12; /*0x127d3c*/
    }
    else
    {
      *a2 = (int)m_more(1, 14); /*0x127d54*/
    }
    splx(v3); /*0x127d5a*/
    if ( !*a2 ) /*0x127d65*/
      return 55; /*0x127d70*/
    v6 = *(_DWORD *)(*a2 + 4) + *a2; /*0x127d7a*/
    *(_DWORD *)v6 = 0; /*0x127d7d*/
    *(_BYTE *)(v6 + 4) = 1; /*0x127d83*/
    *(_BYTE *)(v6 + 5) = 1; /*0x127d87*/
    *(_WORD *)(v6 + 6) = 0; /*0x127d8b*/
  }
  v7 = *(_DWORD *)(*a2 + 4) + *a2; /*0x127d98*/
  switch ( a1 ) /*0x127daa*/
  {
    case 3: /*0x127daa*/
      if ( !a3 || *(_WORD *)(a3 + 8) != 4 ) /*0x127dd5*/
        goto LABEL_55; /*0x127dd5*/
      v8 = *(_DWORD *)(*(_DWORD *)(a3 + 4) + a3); /*0x127dde*/
      if ( v8 ) /*0x127de3*/
      {
        v9 = (_DWORD *)in_ifaddr; /*0x127df0*/
        if ( in_ifaddr ) /*0x127df7*/
        {
          do /*0x127e06*/
          {
            if ( v9[1] == v8 ) /*0x127dff*/
              break; /*0x127dff*/
            v9 = (_DWORD *)v9[16]; /*0x127e01*/
          }
          while ( v9 ); /*0x127e06*/
        }
        v20 = 0; /*0x127e08*/
        if ( v9 ) /*0x127e11*/
          v20 = v9[8]; /*0x127e16*/
        if ( !v20 ) /*0x127e1d*/
          goto LABEL_70; /*0x127e1d*/
        *(_DWORD *)v7 = v20; /*0x127e26*/
      }
      else
      {
        *(_DWORD *)v7 = 0; /*0x127de5*/
      }
      goto LABEL_76; /*0x127deb*/
    case 4: /*0x127daa*/
      if ( !a3 || *(_WORD *)(a3 + 8) != 1 ) /*0x127e3d*/
        goto LABEL_55; /*0x127e3d*/
      *(_BYTE *)(v7 + 4) = *(_BYTE *)(*(_DWORD *)(a3 + 4) + a3); /*0x127e49*/
      goto LABEL_76; /*0x127e4c*/
    case 5: /*0x127daa*/
      if ( !a3 ) /*0x127e56*/
        goto LABEL_55; /*0x127e56*/
      if ( *(_WORD *)(a3 + 8) != 1 ) /*0x127e61*/
        goto LABEL_55; /*0x127e61*/
      v10 = *(_BYTE *)(*(_DWORD *)(a3 + 4) + a3); /*0x127e6a*/
      if ( v10 > 1u ) /*0x127e6f*/
        goto LABEL_55; /*0x127e6f*/
      *(_BYTE *)(v7 + 5) = v10; /*0x127e75*/
      goto LABEL_76; /*0x127e78*/
    case 6: /*0x127daa*/
      if ( !a3 ) /*0x127e82*/
        goto LABEL_55; /*0x127e82*/
      if ( *(_WORD *)(a3 + 8) != 8 ) /*0x127e8d*/
        goto LABEL_55; /*0x127e8d*/
      v23 = (unsigned int *)(*(_DWORD *)(a3 + 4) + a3); /*0x127e96*/
      if ( (_byteswap_ulong(*v23) & 0xF0000000) != 0xE0000000 ) /*0x127ea7*/
        goto LABEL_55; /*0x127ea7*/
      v11 = v23[1]; /*0x127eb0*/
      if ( v11 ) /*0x127eb5*/
      {
        v12 = (_DWORD *)in_ifaddr; /*0x127ef4*/
        if ( in_ifaddr ) /*0x127efb*/
        {
          do /*0x127f0a*/
          {
            if ( v12[1] == v11 ) /*0x127f03*/
              break; /*0x127f03*/
            v12 = (_DWORD *)v12[16]; /*0x127f05*/
          }
          while ( v12 ); /*0x127f0a*/
        }
        v21 = 0; /*0x127f0c*/
        if ( v12 ) /*0x127f15*/
          v21 = v12[8]; /*0x127f1a*/
      }
      else
      {
        v26 = 0; /*0x127eb7*/
        v27 = 2; /*0x127ec1*/
        v28 = *v23; /*0x127ec9*/
        rtalloc(&v26); /*0x127ecd*/
        if ( !v26 ) /*0x127eda*/
          goto LABEL_70; /*0x127eda*/
        v21 = *(_DWORD *)(v26 + 44); /*0x127ee3*/
        rtfree(v26); /*0x127ee7*/
      }
      if ( !v21 ) /*0x127f21*/
        goto LABEL_70; /*0x127f21*/
      v13 = 0; /*0x127f27*/
      if ( !*(_WORD *)(v7 + 6) ) /*0x127f29*/
        goto LABEL_47; /*0x127f29*/
      do /*0x127f4d*/
      {
        v14 = *(_DWORD **)(v7 + 4 * v13 + 8); /*0x127f34*/
        if ( v14[1] == v21 && *v14 == *v23 ) /*0x127f47*/
          break; /*0x127f47*/
        ++v13; /*0x127f49*/
      }
      while ( *(unsigned __int16 *)(v7 + 6) > v13 ); /*0x127f4d*/
      if ( v13 < *(unsigned __int16 *)(v7 + 6) ) /*0x127f55*/
      {
        v25 = 48; /*0x127f57*/
      }
      else
      {
LABEL_47:
        if ( v13 == 20 ) /*0x127f67*/
        {
          v25 = 59; /*0x127f69*/
        }
        else
        {
          v15 = in_addmulti(*v23, v21); /*0x127f82*/
          *(_DWORD *)(v7 + 4 * v13 + 8) = v15; /*0x127f87*/
          if ( v15 ) /*0x127f90*/
            ++*(_WORD *)(v7 + 6); /*0x127fa0*/
          else
            v25 = 55; /*0x127f92*/
        }
      }
      goto LABEL_76; /*0x127f5e*/
    case 7: /*0x127daa*/
      if ( !a3 /*0x127fcb*/
        || *(_WORD *)(a3 + 8) != 8
        || (v24 = (unsigned int *)(*(_DWORD *)(a3 + 4) + a3), (_byteswap_ulong(*v24) & 0xF0000000) != 0xE0000000) )
      {
LABEL_55:
        v25 = 22; /*0x127fcd*/
        goto LABEL_76; /*0x127fd4*/
      }
      v16 = v24[1]; /*0x127fdf*/
      if ( v16 ) /*0x127fe4*/
      {
        v17 = (_DWORD *)in_ifaddr; /*0x127ff0*/
        if ( in_ifaddr ) /*0x127ff7*/
        {
          do /*0x128006*/
          {
            if ( v17[1] == v16 ) /*0x127fff*/
              break; /*0x127fff*/
            v17 = (_DWORD *)v17[16]; /*0x128001*/
          }
          while ( v17 ); /*0x128006*/
        }
        v22 = 0; /*0x128008*/
        if ( v17 ) /*0x128011*/
          v22 = v17[8]; /*0x128016*/
        if ( !v22 ) /*0x12801d*/
          goto LABEL_70; /*0x12801d*/
      }
      else
      {
        v22 = 0; /*0x127fe6*/
      }
      v18 = 0; /*0x12801f*/
      if ( *(_WORD *)(v7 + 6) ) /*0x128021*/
      {
        do /*0x12804f*/
        {
          if ( (!v22 || *(_DWORD *)(*(_DWORD *)(v7 + 4 * v18 + 8) + 4) == v22) /*0x128049*/
            && **(_DWORD **)(v7 + 4 * v18 + 8) == *v24 )
          {
            break; /*0x128049*/
          }
          ++v18; /*0x12804b*/
        }
        while ( *(unsigned __int16 *)(v7 + 6) > v18 ); /*0x12804f*/
      }
      if ( v18 == *(unsigned __int16 *)(v7 + 6) ) /*0x128057*/
      {
LABEL_70:
        v25 = 49; /*0x128059*/
        goto LABEL_76; /*0x128060*/
      }
      in_delmulti(*(int **)(v7 + 4 * v18 + 8)); /*0x128069*/
      for ( i = v18 + 1; i < *(unsigned __int16 *)(v7 + 6); ++i ) /*0x12806e*/
        *(_DWORD *)(v7 + 4 * i + 4) = *(_DWORD *)(v7 + 4 * i + 8); /*0x128078*/
      --*(_WORD *)(v7 + 6); /*0x128085*/
LABEL_76:
      if ( !*(_DWORD *)v7 && *(_DWORD *)(v7 + 4) == 257 ) /*0x12809f*/
      {
        m_free(*a2); /*0x1280a7*/
        *a2 = 0; /*0x1280af*/
      }
      return v25;
    default:
      v25 = 45; /*0x12808c*/
      goto LABEL_76; /*0x12808c*/
  }
}
