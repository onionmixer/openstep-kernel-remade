/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16c758. */
int __cdecl sub_16C758(int a1, _DWORD *a2)
{
  int v3; // edx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // ebx
  int v11; // eax
  int v12; // [esp+Ch] [ebp-8h]
  _DWORD *v13; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h]

  v12 = -200; /*0x16c76a*/
  if ( !a2 ) /*0x16c773*/
    return -303; /*0x16c77a*/
  v3 = *(_DWORD *)(a1 + 12); /*0x16c783*/
  if ( a2[299] != v3 ) /*0x16c78c*/
  {
    if ( a2[300] == v3 ) /*0x16c7a2*/
    {
      v4 = 4 * a2[301]; /*0x16c7a4*/
      v5 = (int)&a2[v4 + 99]; /*0x16c7a7*/
      if ( !a2[v4 + 102] ) /*0x16c7ae*/
      {
LABEL_7:
        v6 = ((int (__cdecl *)(int, _DWORD))a2[v4 + 100])(a1, a2[v4 + 101]); /*0x16c7b4*/
LABEL_19:
        v12 = v6; /*0x16c8a8*/
        goto LABEL_20; /*0x16c8a8*/
      }
      v13 = (_DWORD *)kalloc(0x2000u); /*0x16c7d2*/
      *(_DWORD *)(a1 + 12) = *(_DWORD *)(v5 + 8); /*0x16c7db*/
      (*(void (__cdecl **)(int, _DWORD *))(v5 + 4))(a1, v13); /*0x16c7e9*/
      if ( v13[7] != -305 ) /*0x16c7f5*/
        goto LABEL_17; /*0x16c7f5*/
    }
    else
    {
      v7 = 0; /*0x16c800*/
      v8 = *(_DWORD *)(a1 + 12); /*0x16c802*/
      v9 = 0; /*0x16c804*/
      do /*0x16c818*/
      {
        if ( a2[v9 + 99] == v8 ) /*0x16c80f*/
          break; /*0x16c80f*/
        v9 += 4; /*0x16c811*/
        ++v7; /*0x16c814*/
      }
      while ( v7 <= 49 ); /*0x16c818*/
      if ( v7 == 50 ) /*0x16c81d*/
        goto LABEL_20; /*0x16c81d*/
      a2[300] = v8; /*0x16c823*/
      a2[301] = v7; /*0x16c829*/
      v4 = 4 * v7; /*0x16c82f*/
      v10 = (int)&a2[v4 + 99]; /*0x16c832*/
      if ( !a2[v4 + 102] ) /*0x16c83d*/
        goto LABEL_7; /*0x16c83d*/
      v13 = (_DWORD *)kalloc(0x2000u); /*0x16c85a*/
      *(_DWORD *)(a1 + 12) = *(_DWORD *)(v10 + 8); /*0x16c863*/
      (*(void (__cdecl **)(int, _DWORD *))(v10 + 4))(a1, v13); /*0x16c871*/
      if ( v13[7] != -305 ) /*0x16c87d*/
      {
LABEL_17:
        v11 = msg_send(v13, 0, 0); /*0x16c884*/
        goto LABEL_18; /*0x16c88c*/
      }
    }
    v11 = 0; /*0x16c87f*/
LABEL_18:
    v14 = v11; /*0x16c894*/
    kfree(v13, 0x2000); /*0x16c8a0*/
    v6 = v14; /*0x16c8a5*/
    goto LABEL_19; /*0x16c8a5*/
  }
  v12 = -303; /*0x16c78e*/
LABEL_20:
  if ( v12 == -200 ) /*0x16c8b2*/
  {
    a2[299] = *(_DWORD *)(a1 + 12); /*0x16c8ba*/
    return -303; /*0x16c8c0*/
  }
  return v12; /*0x16c8cd*/
}
