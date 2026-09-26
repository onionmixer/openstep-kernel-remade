/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x189e8c. */
int __cdecl copyoutmsg(unsigned __int16 *a1, unsigned int a2, int a3)
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
  unsigned int v17; // [esp+Ch] [ebp-Ch]
  unsigned int v18; // [esp+Ch] [ebp-Ch]
  unsigned int v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+14h] [ebp-4h]

  v3 = (unsigned __int8 *)a1; /*0x189e95*/
  v17 = a2; /*0x189e9b*/
  v21 = a3; /*0x189ea1*/
  *(_DWORD *)(active_threads + 116) = &loc_18A018; /*0x189ea9*/
  if ( a3 > 15 ) /*0x189eb3*/
  {
    if ( ((unsigned __int8)a1 & 3) != 0 ) /*0x189f09*/
    {
      v8 = 4 - ((unsigned __int8)a1 & 3); /*0x189f12*/
      v19 = a2; /*0x189f17*/
      v9 = a1; /*0x189f1a*/
      if ( (v8 & 1) != 0 ) /*0x189f1f*/
      {
        __writefsbyte(a2, *(_BYTE *)a1); /*0x189f23*/
        v19 = a2 + 1; /*0x189f27*/
        v9 = (unsigned __int16 *)((char *)a1 + 1); /*0x189f2a*/
      }
      if ( (v8 & 2) != 0 ) /*0x189f30*/
      {
        __writefsword(v19, *v9); /*0x189f38*/
        v19 += 2; /*0x189f3f*/
        ++v9; /*0x189f42*/
      }
      v10 = v8 >> 2; /*0x189f47*/
      while ( --v10 != -1 ) /*0x189f5d*/
      {
        __writefsdword(v19, *(_DWORD *)v9); /*0x189f51*/
        v19 += 4; /*0x189f57*/
        v9 += 2; /*0x189f5a*/
      }
      v21 = a3 - v8; /*0x189f63*/
      v17 = v8 + a2; /*0x189f66*/
      v3 = (unsigned __int8 *)a1 + v8; /*0x189f69*/
    }
    v20 = v21; /*0x189f6e*/
    v11 = v21 & 0xC; /*0x189f73*/
    v12 = (unsigned int *)&v3[v11 - 16]; /*0x189f76*/
    v13 = v11 + v17 - 16; /*0x189f7d*/
    if ( v11 == 4 ) /*0x189f84*/
      goto LABEL_29; /*0x189f84*/
    if ( (v21 & 0xCu) > 4 ) /*0x189f86*/
    {
      if ( v11 == 8 ) /*0x189f93*/
        goto LABEL_28; /*0x189f93*/
      if ( v11 == 12 ) /*0x189f98*/
        goto LABEL_27; /*0x189f98*/
    }
    else if ( (v21 & 0xC) == 0 ) /*0x189f8a*/
    {
      while ( 1 ) /*0x189fbc*/
      {
        v20 -= 16; /*0x189fbc*/
        if ( v20 < 0 ) /*0x189fc0*/
          break; /*0x189fc0*/
        v12 += 4; /*0x189f9c*/
        v13 += 16; /*0x189f9f*/
        __writefsdword(v13, *v12); /*0x189fa4*/
LABEL_27:
        __writefsdword(v13 + 4, v12[1]); /*0x189fa7*/
LABEL_28:
        __writefsdword(v13 + 8, v12[2]); /*0x189fae*/
LABEL_29:
        __writefsdword(v13 + 12, v12[3]); /*0x189fb5*/
      }
    }
    v14 = v21 & 3; /*0x189fc5*/
    if ( (v21 & 3) == 0 ) /*0x189fc8*/
      goto LABEL_40; /*0x189fc8*/
    v15 = v21; /*0x189fca*/
    LOBYTE(v15) = v21 & 0xFC; /*0x189fcd*/
    v16 = &v3[v15]; /*0x189fcf*/
    v18 = v15 + v17; /*0x189fd1*/
    if ( v14 != 2 ) /*0x189fd7*/
    {
      if ( (v21 & 3u) <= 2 ) /*0x189fd9*/
      {
        if ( v14 != 1 ) /*0x189fde*/
          goto LABEL_40; /*0x189fde*/
        goto LABEL_39; /*0x189fde*/
      }
      if ( v14 != 3 ) /*0x189fe7*/
      {
LABEL_40:
        *(_DWORD *)(active_threads + 116) = 0; /*0x18a005*/
        return 0; /*0x18a011*/
      }
      __writefsbyte(v18 + 2, v16[2]); /*0x189fef*/
    }
    __writefsbyte(v18 + 1, v16[1]); /*0x189ff9*/
LABEL_39:
    __writefsbyte(v18, *v16); /*0x189ffd*/
    goto LABEL_40; /*0x18a002*/
  }
  v4 = a2; /*0x189eb5*/
  v5 = a1; /*0x189eb8*/
  if ( (a3 & 1) != 0 ) /*0x189ec0*/
  {
    __writefsbyte(a2, *(_BYTE *)a1); /*0x189ec4*/
    v4 = a2 + 1; /*0x189ec7*/
    v5 = (unsigned __int16 *)((char *)a1 + 1); /*0x189ec8*/
  }
  if ( (a3 & 2) != 0 ) /*0x189ed4*/
  {
    __writefsword(v4, *v5); /*0x189ed9*/
    v4 += 2; /*0x189edd*/
    ++v5; /*0x189ee0*/
  }
  v6 = a3 >> 2; /*0x189ee6*/
  while ( --v6 != -1 ) /*0x189ef7*/
  {
    __writefsdword(v4, *(_DWORD *)v5); /*0x189eee*/
    v4 += 4; /*0x189ef1*/
    v5 += 2; /*0x189ef4*/
  }
  return 0; /*0x18a02c*/
}
