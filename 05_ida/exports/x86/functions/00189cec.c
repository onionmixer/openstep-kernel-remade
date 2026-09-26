/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x189cec. */
int __cdecl copyout(unsigned __int16 *a1, unsigned int a2, int a3)
{
  unsigned __int8 *v3; // esi
  unsigned int v4; // ecx
  unsigned __int16 *v5; // edx
  int v6; // eax
  int v8; // edx
  unsigned __int16 *v9; // ecx
  int v10; // eax
  int v11; // eax
  unsigned int *v12; // ecx
  unsigned int v13; // edx
  int v14; // edx
  int v15; // eax
  unsigned __int8 *v16; // esi
  unsigned int v17; // [esp+Ch] [ebp-8h]
  int v18; // [esp+Ch] [ebp-8h]
  int v19; // [esp+10h] [ebp-4h]
  unsigned int v20; // [esp+20h] [ebp+Ch]

  v3 = (unsigned __int8 *)a1; /*0x189cf5*/
  v19 = a3; /*0x189cfb*/
  *(_DWORD *)(active_threads + 116) = &loc_189E70; /*0x189d03*/
  if ( a3 > 15 ) /*0x189d0d*/
  {
    if ( ((unsigned __int8)a1 & 3) != 0 ) /*0x189d61*/
    {
      v8 = 4 - ((unsigned __int8)a1 & 3); /*0x189d6a*/
      v17 = a2; /*0x189d6f*/
      v9 = a1; /*0x189d72*/
      if ( (v8 & 1) != 0 ) /*0x189d77*/
      {
        __writefsbyte(a2, *(_BYTE *)a1); /*0x189d7b*/
        v17 = a2 + 1; /*0x189d7f*/
        v9 = (unsigned __int16 *)((char *)a1 + 1); /*0x189d82*/
      }
      if ( (v8 & 2) != 0 ) /*0x189d88*/
      {
        __writefsword(v17, *v9); /*0x189d90*/
        v17 += 2; /*0x189d97*/
        ++v9; /*0x189d9a*/
      }
      v10 = v8 >> 2; /*0x189d9f*/
      while ( --v10 != -1 ) /*0x189db5*/
      {
        __writefsdword(v17, *(_DWORD *)v9); /*0x189da9*/
        v17 += 4; /*0x189daf*/
        v9 += 2; /*0x189db2*/
      }
      v19 = a3 - v8; /*0x189dbb*/
      a2 += v8; /*0x189dbe*/
      v3 = (unsigned __int8 *)a1 + v8; /*0x189dc1*/
    }
    v18 = v19; /*0x189dc6*/
    v11 = v19 & 0xC; /*0x189dcb*/
    v12 = (unsigned int *)&v3[v11 - 16]; /*0x189dce*/
    v13 = v11 + a2 - 16; /*0x189dd5*/
    if ( v11 == 4 ) /*0x189ddc*/
      goto LABEL_29; /*0x189ddc*/
    if ( (v19 & 0xCu) > 4 ) /*0x189dde*/
    {
      if ( v11 == 8 ) /*0x189deb*/
        goto LABEL_28; /*0x189deb*/
      if ( v11 == 12 ) /*0x189df0*/
        goto LABEL_27; /*0x189df0*/
    }
    else if ( (v19 & 0xC) == 0 ) /*0x189de2*/
    {
      while ( 1 ) /*0x189e14*/
      {
        v18 -= 16; /*0x189e14*/
        if ( v18 < 0 ) /*0x189e18*/
          break; /*0x189e18*/
        v12 += 4; /*0x189df4*/
        v13 += 16; /*0x189df7*/
        __writefsdword(v13, *v12); /*0x189dfc*/
LABEL_27:
        __writefsdword(v13 + 4, v12[1]); /*0x189dff*/
LABEL_28:
        __writefsdword(v13 + 8, v12[2]); /*0x189e06*/
LABEL_29:
        __writefsdword(v13 + 12, v12[3]); /*0x189e0d*/
      }
    }
    v14 = v19 & 3; /*0x189e1d*/
    if ( (v19 & 3) == 0 ) /*0x189e20*/
      goto LABEL_40; /*0x189e20*/
    v15 = v19; /*0x189e22*/
    LOBYTE(v15) = v19 & 0xFC; /*0x189e25*/
    v16 = &v3[v15]; /*0x189e27*/
    v20 = v15 + a2; /*0x189e29*/
    if ( v14 != 2 ) /*0x189e2f*/
    {
      if ( (v19 & 3u) <= 2 ) /*0x189e31*/
      {
        if ( v14 != 1 ) /*0x189e36*/
          goto LABEL_40; /*0x189e36*/
        goto LABEL_39; /*0x189e36*/
      }
      if ( v14 != 3 ) /*0x189e3f*/
      {
LABEL_40:
        *(_DWORD *)(active_threads + 116) = 0; /*0x189e5d*/
        return 0; /*0x189e69*/
      }
      __writefsbyte(v20 + 2, v16[2]); /*0x189e47*/
    }
    __writefsbyte(v20 + 1, v16[1]); /*0x189e51*/
LABEL_39:
    __writefsbyte(v20, *v16); /*0x189e55*/
    goto LABEL_40; /*0x189e5a*/
  }
  v4 = a2; /*0x189d0f*/
  v5 = a1; /*0x189d12*/
  if ( (a3 & 1) != 0 ) /*0x189d17*/
  {
    __writefsbyte(a2, *(_BYTE *)a1); /*0x189d1b*/
    v4 = a2 + 1; /*0x189d1e*/
    v5 = (unsigned __int16 *)((char *)a1 + 1); /*0x189d1f*/
  }
  if ( (a3 & 2) != 0 ) /*0x189d2b*/
  {
    __writefsword(v4, *v5); /*0x189d30*/
    v4 += 2; /*0x189d34*/
    ++v5; /*0x189d37*/
  }
  v6 = a3 >> 2; /*0x189d3d*/
  while ( --v6 != -1 ) /*0x189d4f*/
  {
    __writefsdword(v4, *(_DWORD *)v5); /*0x189d46*/
    v4 += 4; /*0x189d49*/
    v5 += 2; /*0x189d4c*/
  }
  return 0; /*0x189e84*/
}
