/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x112934. */
int __cdecl ptyioctl(unsigned __int16 a1, int a2, int *a3, int a4)
{
  int v4; // ecx
  int v5; // eax
  int v6; // edi
  _BYTE *v7; // ebx
  int v8; // eax
  int v9; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  __int16 v14; // dx
  _DWORD *v15; // ebx
  int v16; // ecx
  __int16 v17; // dx
  _DWORD *v18; // ebx
  int v19; // ecx
  __int16 v20; // dx
  _DWORD *v21; // ebx
  int v22; // ecx
  char v23; // [esp+0h] [ebp-1Ch]
  FILE *v24; // [esp+Ch] [ebp-10h]
  _BOOL4 v25; // [esp+Ch] [ebp-10h]
  FILE *v26; // [esp+Ch] [ebp-10h]
  int v27; // [esp+10h] [ebp-Ch]
  int v28; // [esp+10h] [ebp-Ch]
  int v29; // [esp+14h] [ebp-8h]
  int v30; // [esp+14h] [ebp-8h]

  v4 = a2; /*0x11293d*/
  v5 = 4 * (unsigned __int8)a1; /*0x11294c*/
  v6 = dword_1E56D0[v5]; /*0x11294f*/
  v7 = (_BYTE *)dword_1E56D4[v5]; /*0x112955*/
  if ( a2 == -2147191711 ) /*0x112961*/
  {
    if ( *a3 ) /*0x112966*/
    {
      if ( (*v7 & 8) != 0 ) /*0x11296e*/
      {
        v7[12] |= 0x40u; /*0x112970*/
        ptcwakeup(v6, v23); /*0x112975*/
      }
      *(_DWORD *)(v6 + 64) |= 0x400000u; /*0x11297a*/
    }
    else
    {
      if ( (*(_BYTE *)(v6 + 66) & 0x40) != 0 && (*v7 & 8) != 0 ) /*0x112991*/
      {
        v7[12] |= 0x40u; /*0x112993*/
        ptcwakeup(v6, v23); /*0x112998*/
      }
      *(_DWORD *)(v6 + 64) &= ~0x400000u; /*0x11299d*/
    }
    return 0; /*0x112981*/
  }
  if ( (char *)*(&cdevsw + 11 * HIBYTE(a1)) != (char *)ptcopen ) /*0x1129c6*/
    goto LABEL_49; /*0x1129c6*/
  if ( a2 == -2147191696 ) /*0x1129d2*/
  {
    if ( !*a3 ) /*0x112a6a*/
    {
      *(_DWORD *)v7 &= ~8u; /*0x112a80*/
      return 0; /*0x112a83*/
    }
    v8 = *(_DWORD *)v7; /*0x112a6c*/
    if ( (*(_DWORD *)v7 & 0x80u) == 0 ) /*0x112a70*/
    {
      LOBYTE(v8) = v8 | 8; /*0x112a76*/
      *(_DWORD *)v7 = v8; /*0x112a78*/
      return 0; /*0x112a7a*/
    }
    return 22; /*0x112a70*/
  }
  if ( a2 > -2147191696 ) /*0x1129d8*/
  {
    if ( a2 <= -2145094634 ) /*0x112a22*/
    {
      if ( a2 >= -2145094636 || a2 <= -2147060726 && a2 >= -2147060727 ) /*0x112a42*/
        goto LABEL_42; /*0x112a42*/
LABEL_49:
      v28 = v4; /*0x112b44*/
      v29 = ((int (__cdecl *)(int, int, int *, int))*(&off_1DAFF8 + 12 * *(char *)(v6 + 71)))(v6, v4, a3, a4); /*0x112b63*/
      if ( v29 >= 0 ) /*0x112b6e*/
        return v29; /*0x112b73*/
      v30 = ttioctl((FILE *)v6, v28, a3, a4); /*0x112b8a*/
      v12 = v28; /*0x112b9a*/
      if ( dword_1DB014[12 * *(char *)(v6 + 71)] ) /*0x112b9d*/
      {
        (*(&off_1DAFEC + 12 * *(char *)(v6 + 71)))((FILE *)v6); /*0x112bb0*/
        *(_BYTE *)(v6 + 71) = 0; /*0x112bb2*/
        linesw(a1, (FILE *)v6); /*0x112bc1*/
        v30 = 25; /*0x112bc3*/
        v12 = v28; /*0x112bcd*/
      }
      if ( v30 < 0 ) /*0x112bd4*/
      {
        if ( (char)*v7 < 0 ) /*0x112bd9*/
        {
          v13 = v12; /*0x112bdb*/
          LOBYTE(v13) = 0; /*0x112bdd*/
          if ( v13 == 536900864 ) /*0x112be4*/
          {
            if ( (_BYTE)v12 ) /*0x112be8*/
            {
              v7[13] = v12; /*0x112bea*/
              v14 = *(_WORD *)(v6 + 56); /*0x112bed*/
              v15 = (_DWORD *)dword_1E56D4[4 * (unsigned __int8)v14]; /*0x112bf7*/
              if ( v14 ) /*0x112c00*/
              {
                v24 = (FILE *)spltty(v12); /*0x112c07*/
                v16 = v15[1]; /*0x112c0a*/
                if ( v16 ) /*0x112c0f*/
                {
                  selwakeup(v16, *v15 & 1); /*0x112c18*/
                  selthreadclear(v15 + 1); /*0x112c21*/
                  *v15 &= ~1u; /*0x112c26*/
                }
                splx(v24); /*0x112c30*/
                wakeup(v6 + 28); /*0x112c39*/
              }
            }
            return 0; /*0x112c39*/
          }
        }
        v30 = 25; /*0x112c48*/
      }
      if ( (*(_BYTE *)(v6 + 66) & 0x40) != 0 && (*v7 & 8) != 0 ) /*0x112c58*/
      {
        if ( v12 > -2147060726 ) /*0x112c60*/
        {
          if ( v12 == -2147060619 ) /*0x112c82*/
            goto LABEL_76; /*0x112c82*/
          if ( v12 <= -2147060619 ) /*0x112c84*/
          {
            if ( v12 != -2147060719 ) /*0x112c8c*/
              goto LABEL_77; /*0x112c8c*/
            goto LABEL_76; /*0x112c8c*/
          }
          if ( v12 <= -2145094634 && v12 >= -2145094636 ) /*0x112c9e*/
LABEL_76:
            v7[12] |= 0x40u; /*0x112ca0*/
        }
        else if ( v12 >= -2147060727 || v12 <= -2147191681 && v12 >= -2147191683 ) /*0x112c78*/
        {
          goto LABEL_76; /*0x112c78*/
        }
      }
LABEL_77:
      v25 = 0; /*0x112ca4*/
      if ( (*(_BYTE *)(v6 + 60) & 0x20) == 0 && (*(_BYTE *)(ttynty(v6) + 19) & 4) != 0 ) /*0x112cbe*/
        v25 = (*(_DWORD *)(v6 + 80) & 0xFFFF00) == 1249536; /*0x112ccf*/
      if ( (*v7 & 0x40) != 0 ) /*0x112cd9*/
      {
        if ( !v25 ) /*0x112cdf*/
          return v30; /*0x112cdf*/
        v7[12] = v7[12] & 0xCF | 0x20; /*0x112cec*/
        *(_DWORD *)v7 &= ~0x40u; /*0x112cef*/
        v17 = *(_WORD *)(v6 + 56); /*0x112cf2*/
        v18 = (_DWORD *)dword_1E56D4[4 * (unsigned __int8)v17]; /*0x112cfc*/
        if ( !v17 ) /*0x112d05*/
          return v30; /*0x112d05*/
        v26 = (FILE *)spltty(v12); /*0x112d10*/
        v19 = v18[1]; /*0x112d13*/
        if ( v19 ) /*0x112d18*/
        {
          selwakeup(v19, *v18 & 1); /*0x112d21*/
          selthreadclear(v18 + 1); /*0x112d2a*/
          *v18 &= ~1u; /*0x112d2f*/
        }
      }
      else
      {
        if ( v25 ) /*0x112d40*/
          return v30; /*0x112d40*/
        v7[12] = v7[12] & 0xCF | 0x10; /*0x112d49*/
        *v7 |= 0x40u; /*0x112d4c*/
        v20 = *(_WORD *)(v6 + 56); /*0x112d4f*/
        v21 = (_DWORD *)dword_1E56D4[4 * (unsigned __int8)v20]; /*0x112d59*/
        if ( !v20 ) /*0x112d62*/
          return v30; /*0x112d62*/
        v26 = (FILE *)spltty(v12); /*0x112d69*/
        v22 = v21[1]; /*0x112d6c*/
        if ( v22 ) /*0x112d71*/
        {
          selwakeup(v22, *v21 & 1); /*0x112d7a*/
          selthreadclear(v21 + 1); /*0x112d83*/
          *v21 &= ~1u; /*0x112d88*/
        }
      }
      splx(v26); /*0x112d92*/
      wakeup(v6 + 28); /*0x112d9b*/
      return v30; /*0x112da0*/
    }
    if ( a2 != 536900703 ) /*0x112a56*/
      goto LABEL_49; /*0x112a56*/
    if ( (unsigned int)*a3 <= 0x1F ) /*0x112b0e*/
    {
      if ( *(int *)(v6 + 60) >= 0 ) /*0x112b20*/
        ttyflush((FILE *)v6, 3); /*0x112b25*/
      gsignal((_DWORD *)*(__int16 *)(v6 + 68), (char *)*a3); /*0x112b38*/
      return 0; /*0x112b3f*/
    }
    return 22; /*0x112b15*/
  }
  if ( a2 == -2147191807 ) /*0x1129e0*/
  {
    do /*0x112b04*/
    {
LABEL_42:
      v27 = v4; /*0x112af0*/
      v11 = getc((FILE *)(v6 + 24)); /*0x112af7*/
      v4 = v27; /*0x112aff*/
    }
    while ( v11 >= 0 ); /*0x112b04*/
    goto LABEL_49; /*0x112b04*/
  }
  if ( a2 <= -2147191807 ) /*0x1129e6*/
  {
    if ( a2 != -2147195266 ) /*0x1129ee*/
      goto LABEL_49; /*0x1129ee*/
    if ( *a3 ) /*0x112ad3*/
      *v7 |= 4u; /*0x112ad8*/
    else
      *(_DWORD *)v7 &= ~4u; /*0x112ae0*/
    return 0; /*0x112c40*/
  }
  if ( a2 == -2147191706 ) /*0x112a02*/
  {
    if ( !*a3 ) /*0x112a8e*/
    {
      *(_DWORD *)v7 &= ~0x80u; /*0x112aa0*/
      return 0; /*0x112aa6*/
    }
    v9 = *(_DWORD *)v7; /*0x112a90*/
    if ( (*(_DWORD *)v7 & 8) == 0 ) /*0x112a94*/
    {
      LOBYTE(v9) = v9 | 0x80; /*0x112a96*/
      *(_DWORD *)v7 = v9; /*0x112a98*/
      return 0; /*0x112a9a*/
    }
    return 22; /*0x112a94*/
  }
  if ( a2 != -2147191703 ) /*0x112a0e*/
    goto LABEL_49; /*0x112a0e*/
  if ( *a3 ) /*0x112aaf*/
    *v7 |= 0x20u; /*0x112ab4*/
  else
    *(_DWORD *)v7 &= ~0x20u; /*0x112abc*/
  ttyflush((FILE *)v6, 3); /*0x112ac2*/
  return 0; /*0x112da6*/
}
