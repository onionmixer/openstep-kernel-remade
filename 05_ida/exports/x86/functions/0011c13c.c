/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11c13c. */
int __cdecl lookuppn(int a1, int a2, int *a3, _DWORD *a4)
{
  char v4; // al
  int v6; // eax
  _DWORD *v7; // edi
  int v8; // esi
  int v9; // eax
  int v10; // edx
  int v11; // edx
  unsigned int v12; // ebx
  int v13; // eax
  _DWORD *v14; // edi
  int v15; // eax
  unsigned int v16; // ebx
  _BYTE *i; // eax
  int v18; // eax
  int v19; // [esp+Ch] [ebp-120h]
  int v20; // [esp+10h] [ebp-11Ch]
  int v21; // [esp+10h] [ebp-11Ch]
  int v22; // [esp+10h] [ebp-11Ch]
  int v23; // [esp+14h] [ebp-118h]
  _DWORD *v24; // [esp+18h] [ebp-114h]
  int v25; // [esp+18h] [ebp-114h]
  int v26[3]; // [esp+1Ch] [ebp-110h] BYREF
  _DWORD *v27; // [esp+28h] [ebp-104h] BYREF
  char __s2[256]; // [esp+2Ch] [ebp-100h] BYREF

  v23 = 0; /*0x11c148*/
  v24 = nullptr; /*0x11c152*/
  v19 = *(_DWORD *)(active_u + 352); /*0x11c167*/
  ++*(_WORD *)(v19 + 6); /*0x11c16d*/
  while ( 2 ) /*0x11c171*/
  {
    __s2[0] = 0; /*0x11c171*/
    if ( *(_DWORD *)(a1 + 8) ) /*0x11c17b*/
    {
      v4 = **(_BYTE **)(a1 + 4); /*0x11c184*/
      if ( v4 == 47 ) /*0x11c188*/
      {
        vn_rele(v19); /*0x11c191*/
        pn_skipslash(a1); /*0x11c197*/
        if ( *(_DWORD *)(active_u + 356) ) /*0x11c1a4*/
          v19 = *(_DWORD *)(active_u + 356); /*0x11c1ae*/
        else
          v19 = rootdir; /*0x11c1be*/
        ++*(_WORD *)(v19 + 6); /*0x11c1ca*/
        goto LABEL_11; /*0x11c1ce*/
      }
      if ( v4 ) /*0x11c1d2*/
        goto LABEL_11; /*0x11c1d2*/
    }
    if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x11c1df*/
      return 2; /*0x11c1e6*/
LABEL_11:
    if ( *(_DWORD *)(v19 + 40) != 2 ) /*0x11c1f6*/
    {
      v6 = 20; /*0x11c1f8*/
LABEL_91:
      if ( v24 ) /*0x11c71b*/
      {
        v21 = v6; /*0x11c724*/
        vn_rele((int)v24); /*0x11c72a*/
        v6 = v21; /*0x11c732*/
      }
      v22 = v6; /*0x11c73f*/
      vn_rele(v19); /*0x11c745*/
      return v22; /*0x11c74a*/
    }
    v6 = pn_getcomponent(a1, __s2); /*0x11c211*/
    if ( v6 ) /*0x11c21b*/
      goto LABEL_91; /*0x11c21b*/
    if ( __s2[0] ) /*0x11c228*/
    {
      if ( strcmp(__s2, asc_1DB77F) ) /*0x11c289*/
        goto LABEL_36; /*0x11c28b*/
      while ( 1 ) /*0x11c296*/
      {
        v9 = *(_DWORD *)(active_u + 356); /*0x11c296*/
        if ( v19 == v9 /*0x11c2fa*/
          || v19
          && v9
          && (v10 = *(_DWORD *)(v19 + 28), *(_DWORD *)(v9 + 28) == v10)
          && (*(int (__cdecl **)(int, _DWORD))(v10 + 108))(v19, *(_DWORD *)(active_u + 356))
          || v19 == rootdir
          || v19
          && rootdir
          && (v11 = *(_DWORD *)(v19 + 28), *(_DWORD *)(rootdir + 28) == v11)
          && (*(int (__cdecl **)(int, int))(v11 + 108))(v19, rootdir) )
        {
          v24 = (_DWORD *)v19; /*0x11c309*/
          ++*(_WORD *)(v19 + 6); /*0x11c30f*/
          goto LABEL_67; /*0x11c313*/
        }
        if ( (*(_BYTE *)(v19 + 4) & 1) == 0 ) /*0x11c322*/
          break; /*0x11c322*/
        v25 = v19; /*0x11c324*/
        v19 = *(_DWORD *)(*(_DWORD *)(v19 + 36) + 8); /*0x11c330*/
        ++*(_WORD *)(v19 + 6); /*0x11c336*/
        vn_rele(v25); /*0x11c341*/
        if ( !*(_DWORD *)(v19 + 12) ) /*0x11c34f*/
        {
          v24 = (_DWORD *)v19; /*0x11c355*/
          ++*(_WORD *)(v19 + 6); /*0x11c35b*/
LABEL_67:
          if ( *(_DWORD *)(a1 + 8) ) /*0x11c5d7*/
          {
            if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x11c5e8*/
            {
              for ( i = *(_BYTE **)(a1 + 4); *i == 47; ++i ) /*0x11c5f0*/
                ; /*0x11c5f4*/
              if ( !*i && v24[10] == 2 ) /*0x11c609*/
              {
                **(_BYTE **)(a1 + 4) = 0; /*0x11c611*/
                *(_DWORD *)(a1 + 8) = 0; /*0x11c614*/
              }
            }
            if ( *(_DWORD *)(a1 + 8) ) /*0x11c61e*/
            {
              pn_skipslash(a1); /*0x11c6e4*/
              vn_rele(v19); /*0x11c6f0*/
              v19 = (int)v24; /*0x11c6fb*/
              v24 = nullptr; /*0x11c701*/
              goto LABEL_11; /*0x11c70e*/
            }
          }
LABEL_75:
          pn_set(a1, __s2); /*0x11c628*/
          if ( a3 ) /*0x11c63f*/
          {
            if ( (_DWORD *)v19 == v24 /*0x11c66f*/
              || v19
              && v24
              && (v18 = *(_DWORD *)(v19 + 28), v24[7] == v18)
              && (*(int (__cdecl **)(int, _DWORD *))(v18 + 108))(v19, v24) )
            {
              vn_rele(v19); /*0x11c67f*/
              vn_rele((int)v24); /*0x11c68b*/
              return 17; /*0x11c695*/
            }
            *a3 = v19; /*0x11c6a5*/
          }
          else
          {
            vn_rele(v19); /*0x11c6b3*/
          }
          if ( a4 ) /*0x11c6bf*/
          {
            v7 = v24; /*0x11c6c1*/
            goto LABEL_86; /*0x11c6c1*/
          }
          v8 = (int)v24; /*0x11c6d0*/
          goto LABEL_88; /*0x11c6d0*/
        }
        v24 = nullptr; /*0x11c364*/
      }
LABEL_36:
      while ( *(_DWORD *)(v19 + 16) ) /*0x11c37a*/
      {
        v6 = (*(int (__cdecl **)(int, int, _DWORD))(*(_DWORD *)(v19 + 28) + 28))(v19, 64, *(_DWORD *)(active_u + 28)); /*0x11c397*/
        if ( v6 ) /*0x11c39e*/
          goto LABEL_91; /*0x11c39e*/
        v12 = *(_DWORD *)(v19 + 16); /*0x11c3a4*/
        if ( !v12 ) /*0x11c3a9*/
          break; /*0x11c3a9*/
        while ( strncmp((const char *)(v12 + 32), __s2, 0xFFu) ) /*0x11c3c6*/
        {
          v12 = *(_DWORD *)(v12 + 288); /*0x11c410*/
          if ( !v12 ) /*0x11c418*/
            goto LABEL_45; /*0x11c418*/
        }
        v13 = *(_DWORD *)(v12 + 12); /*0x11c3c8*/
        if ( (v13 & 2) == 0 ) /*0x11c3cd*/
        {
          v6 = (*(int (__cdecl **)(unsigned int, _DWORD **))(*(_DWORD *)(v12 + 4) + 8))(v12, &v27); /*0x11c3f2*/
          if ( v6 ) /*0x11c3f9*/
            goto LABEL_91; /*0x11c3f9*/
          v24 = v27; /*0x11c405*/
          goto LABEL_67; /*0x11c40b*/
        }
        LOBYTE(v13) = v13 | 4; /*0x11c3cf*/
        *(_DWORD *)(v12 + 12) = v13; /*0x11c3d1*/
        sleep(v12); /*0x11c3d7*/
      }
LABEL_45:
      v6 = (*(int (__cdecl **)(int, char *, _DWORD **, _DWORD, int, _DWORD))(*(_DWORD *)(v19 + 28) + 32))( /*0x11c41a*/
             v19,
             __s2,
             &v27,
             *(_DWORD *)(active_u + 28),
             a1,
             0);
      v24 = v27; /*0x11c44c*/
      if ( v6 ) /*0x11c457*/
      {
        v24 = nullptr; /*0x11c459*/
        if ( *(_DWORD *)(a1 + 8) || !a3 || v6 == 13 ) /*0x11c47a*/
          goto LABEL_91; /*0x11c47a*/
        pn_set(a1, __s2); /*0x11c482*/
        *a3 = v19; /*0x11c490*/
        if ( a4 ) /*0x11c496*/
          *a4 = 0; /*0x11c49f*/
        return 0; /*0x11c4a5*/
      }
LABEL_51:
      v14 = v24; /*0x11c4ac*/
      while ( 1 ) /*0x11c509*/
      {
        v16 = v14[3]; /*0x11c509*/
        if ( !v16 ) /*0x11c50e*/
          break; /*0x11c50e*/
        v15 = *(_DWORD *)(v16 + 12); /*0x11c4b4*/
        if ( (v15 & 2) != 0 ) /*0x11c4b9*/
        {
          LOBYTE(v15) = v15 | 4; /*0x11c4bb*/
          *(_DWORD *)(v16 + 12) = v15; /*0x11c4bd*/
          sleep(v16); /*0x11c4c3*/
          goto LABEL_51; /*0x11c4cb*/
        }
        v6 = (*(int (__cdecl **)(_DWORD, _DWORD **))(*(_DWORD *)(v24[3] + 4) + 8))(v24[3], &v27); /*0x11c4e7*/
        if ( v6 ) /*0x11c4ee*/
          goto LABEL_91; /*0x11c4ee*/
        vn_rele((int)v24); /*0x11c4f5*/
        v14 = v27; /*0x11c4fa*/
        v24 = v27; /*0x11c500*/
      }
      if ( v24[10] != 5 ) /*0x11c51a*/
        goto LABEL_67; /*0x11c51a*/
      if ( a2 != 1 && !*(_DWORD *)(a1 + 8) ) /*0x11c52d*/
        goto LABEL_75; /*0x11c52d*/
      if ( ++v23 > 20 ) /*0x11c540*/
      {
        v6 = 62; /*0x11c542*/
        goto LABEL_91; /*0x11c547*/
      }
      v6 = sub_11C760((int)v24, __s2, v19, (int)v26); /*0x11c568*/
      if ( !v6 ) /*0x11c572*/
      {
        if ( !v26[2] ) /*0x11c57f*/
          pn_set(v26, asc_1DB782); /*0x11c587*/
        v20 = pn_combine(a1, v26); /*0x11c59a*/
        pn_free(v26); /*0x11c5a0*/
        v6 = v20; /*0x11c5a8*/
        if ( !v20 ) /*0x11c5b0*/
        {
          vn_rele((int)v24); /*0x11c5bd*/
          v24 = nullptr; /*0x11c5c2*/
          continue; /*0x11c5cf*/
        }
      }
      goto LABEL_91; /*0x11c5b0*/
    }
    break;
  }
  if ( a3 ) /*0x11c22e*/
  {
    vn_rele(v19); /*0x11c237*/
    return 17; /*0x11c23c*/
  }
  else
  {
    pn_set(a1, asc_1DB77D); /*0x11c251*/
    if ( a4 ) /*0x11c25d*/
    {
      v7 = (_DWORD *)v19; /*0x11c25f*/
LABEL_86:
      *a4 = v7; /*0x11c6c7*/
    }
    else
    {
      v8 = v19; /*0x11c26c*/
LABEL_88:
      vn_rele(v8); /*0x11c6d6*/
    }
    return 0; /*0x11c6dc*/
  }
}
