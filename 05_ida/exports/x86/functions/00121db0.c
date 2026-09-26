/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x121db0. */
int __cdecl rtrequest(int a1, int a2)
{
  char *v2; // esi
  unsigned int v3; // ebx
  char *v5; // eax
  int *v6; // ebx
  const void *v7; // edi
  __int16 v8; // ax
  int v9; // edi
  int v10; // eax
  int *v11; // eax
  char *v12; // esi
  __int16 v13; // ax
  int v14; // [esp+Ch] [ebp-20h]
  int (*v15)(); // [esp+10h] [ebp-1Ch]
  int v16; // [esp+14h] [ebp-18h]
  int v17; // [esp+18h] [ebp-14h]
  int *v18; // [esp+1Ch] [ebp-10h]
  int *v19; // [esp+20h] [ebp-Ch]
  int v20; // [esp+24h] [ebp-8h] BYREF
  int v21; // [esp+28h] [ebp-4h]

  v2 = nullptr; /*0x121db9*/
  v16 = 0; /*0x121dbb*/
  v3 = *(unsigned __int16 *)(a2 + 4); /*0x121dc5*/
  if ( v3 > 0x10 ) /*0x121dcc*/
    return 47; /*0x121dd3*/
  (*(&afswitch + 2 * v3))(a2 + 4, (int)&v20); /*0x121dea*/
  if ( (*(_BYTE *)(a2 + 36) & 4) != 0 ) /*0x121df6*/
  {
    v14 = v20; /*0x121dfb*/
    v5 = (char *)&rthost + 4 * (v20 & 7); /*0x121e03*/
  }
  else
  {
    v14 = v21; /*0x121e0f*/
    v5 = (char *)&rtnet + 4 * (v21 & 7); /*0x121e17*/
  }
  v19 = (int *)v5; /*0x121e1e*/
  v15 = off_1DB794[2 * v3]; /*0x121e28*/
  v17 = splimp(); /*0x121e30*/
  v18 = v19; /*0x121e36*/
  v6 = (int *)*v19; /*0x121e39*/
  if ( *v19 ) /*0x121e39*/
  {
    v7 = (const void *)(a2 + 4); /*0x121e42*/
    do /*0x121e4a*/
    {
      v2 = (char *)v6 + v6[1]; /*0x121e4a*/
      if ( *(_DWORD *)v2 == v14 ) /*0x121e52*/
      {
        if ( (*(_BYTE *)(a2 + 36) & 4) != 0 ) /*0x121e5b*/
        {
          if ( !bcmp(v2 + 4, v7, 0x10u) ) /*0x121e83*/
            goto LABEL_14; /*0x121e8d*/
        }
        else if ( *((_WORD *)v2 + 2) == *(_WORD *)(a2 + 4) && ((int (__cdecl *)(char *, const void *))v15)(v2 + 4, v7) ) /*0x121e6f*/
        {
LABEL_14:
          if ( !bcmp(v2 + 20, (const void *)(a2 + 20), 0x10u) ) /*0x121ea6*/
            break; /*0x121ea6*/
        }
      }
      v19 = v6; /*0x121ea8*/
      v6 = (int *)*v6; /*0x121eab*/
    }
    while ( v6 ); /*0x121e4a*/
  }
  if ( a1 != -2144308726 ) /*0x121eb8*/
  {
    if ( a1 == -2144308725 ) /*0x121ec1*/
    {
      if ( v6 ) /*0x121ec9*/
      {
        *v19 = *v6; /*0x121edd*/
        if ( *((__int16 *)v2 + 19) <= 0 ) /*0x121ee4*/
        {
          m_free((int)v6); /*0x121efd*/
        }
        else
        {
          v2[36] &= ~1u; /*0x121ee6*/
          ++rttrash; /*0x121eea*/
          *v6 = 0; /*0x121ef0*/
        }
      }
      else
      {
        v16 = 3; /*0x121ecb*/
      }
    }
    goto LABEL_37; /*0x121ed2*/
  }
  if ( !v6 ) /*0x121f0e*/
  {
    v8 = *(_WORD *)(a2 + 36); /*0x121f1f*/
    if ( (v8 & 2) != 0 ) /*0x121f25*/
    {
      v10 = ifa_ifwithdstaddr((_WORD *)(a2 + 20)); /*0x121f57*/
    }
    else
    {
      v9 = 0; /*0x121f27*/
      if ( (v8 & 4) != 0 ) /*0x121f2b*/
        v9 = ifa_ifwithdstaddr((_WORD *)(a2 + 4)); /*0x121f38*/
      if ( v9 ) /*0x121f3f*/
        goto LABEL_34; /*0x121f3f*/
      v10 = ifa_ifwithaddr((_WORD *)(a2 + 20)); /*0x121f48*/
    }
    v9 = v10; /*0x121f5c*/
    if ( !v10 ) /*0x121f63*/
    {
      v9 = ifa_ifwithnet((_WORD *)(a2 + 20)); /*0x121f71*/
      if ( !v9 ) /*0x121f78*/
      {
        v16 = 51; /*0x121f7a*/
        goto LABEL_37; /*0x121f81*/
      }
    }
LABEL_34:
    v11 = m_get(0, 5); /*0x121f88*/
    if ( v11 ) /*0x121f98*/
    {
      *v11 = *v18; /*0x121fad*/
      *v18 = (int)v11; /*0x121fb2*/
      v11[1] = 12; /*0x121fb4*/
      *((_WORD *)v11 + 4) = 48; /*0x121fbb*/
      v12 = (char *)v11 + v11[1]; /*0x121fc3*/
      *(_DWORD *)v12 = v14; /*0x121fc9*/
      *((_DWORD *)v12 + 1) = *(_DWORD *)(a2 + 4); /*0x121fd1*/
      *((_DWORD *)v12 + 2) = *(_DWORD *)(a2 + 8); /*0x121fda*/
      *((_DWORD *)v12 + 3) = *(_DWORD *)(a2 + 12); /*0x121fe3*/
      *((_DWORD *)v12 + 4) = *(_DWORD *)(a2 + 16); /*0x121fec*/
      *((_DWORD *)v12 + 5) = *(_DWORD *)(a2 + 20); /*0x121ff5*/
      *((_DWORD *)v12 + 6) = *(_DWORD *)(a2 + 24); /*0x121ffe*/
      *((_DWORD *)v12 + 7) = *(_DWORD *)(a2 + 28); /*0x122007*/
      *((_DWORD *)v12 + 8) = *(_DWORD *)(a2 + 32); /*0x122010*/
      v13 = *(_WORD *)(a2 + 36) & 0x16; /*0x12201a*/
      LOBYTE(v13) = v13 | 1; /*0x12201e*/
      *((_WORD *)v12 + 18) = v13; /*0x122020*/
      *((_WORD *)v12 + 19) = 0; /*0x122024*/
      *((_DWORD *)v12 + 10) = 0; /*0x12202a*/
      *((_DWORD *)v12 + 11) = *(_DWORD *)(v9 + 32); /*0x122034*/
    }
    else
    {
      v16 = 55; /*0x121f9a*/
    }
    goto LABEL_37; /*0x121fa1*/
  }
  v16 = 17; /*0x121f10*/
LABEL_37:
  splx(v17); /*0x122037*/
  return v16; /*0x122046*/
}
