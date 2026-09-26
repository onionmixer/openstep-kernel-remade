/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x130d00. */
int __cdecl sub_130D00(int **a1, _DWORD *a2, _DWORD *a3, void *a4, void *a5, void *a6, signed __int32 a7, __int16 a8)
{
  int *v8; // esi
  _DWORD *v9; // edi
  void *v10; // eax
  __int16 v11; // ax
  int v12; // ebx
  unsigned int v13; // eax
  _BYTE v15[64]; // [esp+18h] [ebp-C4h] BYREF
  int v16[17]; // [esp+58h] [ebp-84h] BYREF
  _BYTE v17[64]; // [esp+9Ch] [ebp-40h] BYREF

  v8 = nullptr; /*0x130d0f*/
  v9 = (_DWORD *)kalloc(0x70u); /*0x130d18*/
  bzero(v9, 0x70u); /*0x130d1d*/
  *((_BYTE *)v9 + 20) = (4 * ((a8 & 0x40) != 0)) | (a8 ^ 1) & 1 | v9[5] & 0xFA; /*0x130d56*/
  *v9 = *a3; /*0x130d5b*/
  v9[1] = a3[1]; /*0x130d60*/
  v9[2] = a3[2]; /*0x130d66*/
  v9[3] = a3[3]; /*0x130d6c*/
  v9[12] = 5; /*0x130d6f*/
  v9[11] = 11; /*0x130d76*/
  v9[10] = vfs_getnum((unsigned int)&unk_1E59B8, 32); /*0x130d89*/
  bcopy(a5, v9 + 13, 0x20u); /*0x130d96*/
  v9[24] = 3; /*0x130d9b*/
  v9[25] = 60; /*0x130da2*/
  v9[26] = 30; /*0x130da9*/
  v9[27] = 60; /*0x130db0*/
  if ( (a8 & 0x1000) != 0 ) /*0x130dc0*/
    goto LABEL_8; /*0x130dc0*/
  v9[23] = 1; /*0x130dc6*/
  v9[22] = a7; /*0x130dd0*/
  if ( a7 >= 0 ) /*0x130dd5*/
  {
    v10 = (void *)kalloc(a7); /*0x130dd8*/
    v9[21] = v10; /*0x130ddd*/
    bcopy(a6, v10, a7); /*0x130de9*/
  }
  a2[5] = v9[10]; /*0x130df7*/
  a2[6] = 1; /*0x130dfa*/
  a2[74] = v9; /*0x130e01*/
  v8 = makenfsnode(a4, nullptr, (int)a2); /*0x130e13*/
  v11 = *((_WORD *)v8 + 2); /*0x130e15*/
  if ( (v11 & 1) != 0 ) /*0x130e1e*/
  {
LABEL_8:
    v12 = 22; /*0x130eec*/
  }
  else
  {
    LOBYTE(v11) = v11 | 1; /*0x130e24*/
    *((_WORD *)v8 + 2) = v11; /*0x130e26*/
    v12 = (*(int (__cdecl **)(int *, _BYTE *, _DWORD))(v8[7] + 20))(v8, v17, *(_DWORD *)(active_u + 28)); /*0x130e47*/
    if ( !v12 ) /*0x130e4e*/
    {
      vn_rele((int)v8); /*0x130e55*/
      vattr_to_nattr((int)v17, v16); /*0x130e68*/
      v8 = makenfsnode(a4, v16, (int)a2); /*0x130e7b*/
      *((_BYTE *)v8 + 4) |= 1u; /*0x130e7d*/
      v9[4] = v8; /*0x130e81*/
      v12 = (*(int (__cdecl **)(_DWORD *, _BYTE *))(a2[1] + 12))(a2, v15); /*0x130e9a*/
      if ( !v12 ) /*0x130ea1*/
      {
        v13 = nfstsize(); /*0x130ea3*/
        v9[7] = min(0x2000u, v13); /*0x130eb3*/
        v9[9] = 0x2000; /*0x130eb6*/
        a2[4] = 0x2000; /*0x130ec0*/
        ++**(_WORD **)(active_u + 28); /*0x130ecf*/
        *(_DWORD *)(v8[12] + 112) = *(_DWORD *)(active_u + 28); /*0x130edd*/
        *a1 = v8; /*0x130ee3*/
        return 0; /*0x130ee7*/
      }
    }
  }
  if ( v9 ) /*0x130ef3*/
  {
    if ( (int)v9[22] >= 0 ) /*0x130efa*/
      kfree(v9[21], v9[22]); /*0x130f01*/
    kfree((int)v9, 0x70u); /*0x130f0c*/
  }
  if ( v8 ) /*0x130f16*/
    vn_rele((int)v8); /*0x130f19*/
  *a1 = nullptr; /*0x130f21*/
  return v12; /*0x130f2f*/
}
