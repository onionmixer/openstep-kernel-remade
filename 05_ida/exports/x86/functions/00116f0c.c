/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116f0c. */
int __cdecl accept(int a1, sockaddr *a2, socklen_t *a3)
{
  _DWORD *v3; // edi
  int result; // eax
  int v5; // esi
  int v6; // ebx
  int v7; // esi
  _DWORD *v8; // ebx
  int *v9; // esi
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h] BYREF

  v3 = *(_DWORD **)(dword_1E875C + 36); /*0x116f1a*/
  if ( v3[1] ) /*0x116f1d*/
  {
    *(_BYTE *)(dword_1E875C + 104) = copyin(v3[2], &v11, 4); /*0x116f39*/
    result = dword_1E875C; /*0x116f3c*/
    if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x116f44*/
      return result; /*0x116f48*/
    if ( !useracc(v3[1], v11, 0) ) /*0x116f58*/
    {
      result = dword_1E875C; /*0x116f64*/
      *(_BYTE *)(dword_1E875C + 104) = 14; /*0x116f69*/
      return result; /*0x116f6d*/
    }
  }
  result = getsock(*v3); /*0x116f77*/
  v5 = result; /*0x116f7c*/
  if ( result ) /*0x116f83*/
  {
    v10 = splnet(); /*0x116f8e*/
    v6 = *(_DWORD *)(v5 + 24); /*0x116f91*/
    if ( (*(_BYTE *)(v6 + 2) & 2) == 0 ) /*0x116f98*/
    {
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x116f9f*/
      return splx(v10); /*0x1170eb*/
    }
    if ( (*(_BYTE *)(v6 + 7) & 1) != 0 ) /*0x116fac*/
    {
      if ( !*(_WORD *)(v6 + 32) ) /*0x116fae*/
      {
        *(_BYTE *)(dword_1E875C + 104) = 35; /*0x116fba*/
        return splx(v10); /*0x116fbe*/
      }
    }
    else if ( !*(_WORD *)(v6 + 32) ) /*0x116fcc*/
    {
      if ( *(_WORD *)(v6 + 86) ) /*0x116fd3*/
      {
LABEL_18:
        *(_BYTE *)(dword_1E875C + 104) = *(_BYTE *)(v6 + 86); /*0x117006*/
        *(_WORD *)(v6 + 86) = 0; /*0x117011*/
        return splx(v10); /*0x117017*/
      }
      while ( (*(_BYTE *)(v6 + 6) & 0x20) == 0 ) /*0x116fe4*/
      {
        sleep(v6 + 84); /*0x116fe9*/
        if ( *(_WORD *)(v6 + 32) || *(_WORD *)(v6 + 86) ) /*0x116ff8*/
          goto LABEL_17; /*0x116ffd*/
      }
      *(_WORD *)(v6 + 86) = 53; /*0x116fc4*/
    }
LABEL_17:
    if ( !*(_WORD *)(v6 + 86) ) /*0x117004*/
    {
      v7 = falloc(); /*0x117021*/
      if ( v7 ) /*0x117025*/
      {
        v8 = *(_DWORD **)(v6 + 28); /*0x117048*/
        if ( !soqremque(v8, 1) ) /*0x11704e*/
          panic(aAccept); /*0x11705f*/
        *(_WORD *)(v7 + 12) = 2; /*0x117067*/
        *(_DWORD *)(v7 + 8) = 3; /*0x11706d*/
        *(_DWORD *)(v7 + 20) = &socketops; /*0x117074*/
        *(_DWORD *)(v7 + 24) = v8; /*0x11707b*/
        *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * *(_DWORD *)(dword_1E875C + 96)) = v7; /*0x117092*/
        v9 = m_get(1, 8); /*0x11709e*/
        soaccept((int)v8, (int)v9); /*0x1170a2*/
        if ( v3[1] ) /*0x1170aa*/
        {
          if ( v11 > *((__int16 *)v9 + 4) ) /*0x1170b7*/
            v11 = *((__int16 *)v9 + 4); /*0x1170b9*/
          copyout((char *)v9 + v9[1], v3[1], v11); /*0x1170ca*/
          copyout(&v11, v3[2], 4); /*0x1170d9*/
        }
        m_freem((int)v9); /*0x1170e2*/
      }
      else
      {
        *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * *(_DWORD *)(dword_1E875C + 96)) = 0; /*0x11703b*/
      }
      return splx(v10); /*0x117042*/
    }
    goto LABEL_18; /*0x117004*/
  }
  return result; /*0x1170f3*/
}
