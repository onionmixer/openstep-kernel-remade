/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1313c0. */
int __cdecl sub_1313C0(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v5; // ebx
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  unsigned int v11; // edi
  int v12; // edx
  int v13; // esi
  int v14; // eax
  int *v15; // ebx
  int v16; // ebx
  int *v17; // eax
  int v18; // eax
  unsigned int v19; // eax
  int v20; // [esp+18h] [ebp-60h]
  int v21; // [esp+1Ch] [ebp-5Ch]
  int v22; // [esp+20h] [ebp-58h]
  int v23; // [esp+24h] [ebp-54h]
  unsigned int v24; // [esp+28h] [ebp-50h]
  int v25; // [esp+2Ch] [ebp-4Ch] BYREF
  int v26; // [esp+30h] [ebp-48h] BYREF
  int v27; // [esp+34h] [ebp-44h] BYREF
  _BYTE v28[64]; // [esp+38h] [ebp-40h] BYREF

  v22 = 0; /*0x1313c9*/
  v21 = 0; /*0x1313d0*/
  v5 = a2[5]; /*0x1313da*/
  if ( !v5 ) /*0x1313df*/
    return 0; /*0x1313e3*/
  v7 = a2[2]; /*0x1313eb*/
  if ( v7 < 0 ) /*0x1313f0*/
    return 22; /*0x1313f0*/
  v8 = v7 + v5; /*0x1313f2*/
  if ( v8 < 0 ) /*0x1313f4*/
    return 22; /*0x1313fb*/
  if ( a3 == 1 && *(_DWORD *)(a1 + 40) == 1 && *(_DWORD *)(active_u + 620) < (unsigned int)v8 ) /*0x13141a*/
  {
    psignal(*(_DWORD *)active_u, (const char *)0x19); /*0x131421*/
    return 27; /*0x13142b*/
  }
  v24 = *(_DWORD *)(a1 + 48); /*0x13146e*/
  rlock(v24); /*0x131472*/
  v10 = *(_DWORD *)(*(_DWORD *)(a1 + 36) + 296); /*0x13147d*/
  v11 = *(_DWORD *)(v10 + 36) & 0xFFFFFC00; /*0x131486*/
  if ( *(int *)(v10 + 36) < 0 || v11 == 0 ) /*0x13148f*/
    panic(aRwvpZeroSize); /*0x131498*/
  do /*0x131731*/
  {
    v12 = a2[2] % v11; /*0x1314b0*/
    v23 = v12; /*0x1314b2*/
    v20 = a2[2] / v11; /*0x1314b5*/
    v13 = a2[5]; /*0x1314bf*/
    if ( v11 - v12 < v13 ) /*0x1314c4*/
      v13 = v11 - v12; /*0x1314c6*/
    (*(void (__cdecl **)(int, int, int *, int *))(*(_DWORD *)(a1 + 28) + 80))(a1, v20, &v27, &v26); /*0x1314e1*/
    if ( (*(_BYTE *)(a1 + 4) & 0x40) == 0 ) /*0x1314ed*/
    {
      if ( a3 ) /*0x131548*/
      {
        LOWORD(v9) = *(_WORD *)(v24 + 98); /*0x1315f7*/
        if ( (_WORD)v9 ) /*0x1315fe*/
        {
          v9 = (__int16)v9; /*0x131430*/
          goto LABEL_54; /*0x131431*/
        }
        if ( v13 == v11 ) /*0x131606*/
        {
          v17 = (int *)getblk(v27, v26, v11); /*0x131611*/
LABEL_33:
          v15 = v17; /*0x131626*/
          goto LABEL_34; /*0x131626*/
        }
      }
      else
      {
        if ( v20 < 0 ) /*0x131552*/
        {
          v15 = (int *)geteblk(v11); /*0x13155a*/
          blkclr((void *)v15[8], v15[5]); /*0x131564*/
          v15[10] = 0; /*0x131569*/
          goto LABEL_34; /*0x131570*/
        }
        if ( incore(v27, v26) ) /*0x131580*/
          nfs_validate_caches(v27, a5, 0); /*0x131596*/
        v16 = *(_DWORD *)(v24 + 100); /*0x1315a1*/
        if ( v20 == v16 + 1 ) /*0x1315aa*/
        {
          (*(void (__cdecl **)(int, int, int *, int *))(*(_DWORD *)(a1 + 28) + 80))(a1, v16 + 2, &v27, &v25); /*0x1315cb*/
          v15 = breada(v27, v26, v11, v25, v11); /*0x1315e0*/
          goto LABEL_34; /*0x1315e5*/
        }
      }
      v17 = bread(v27, v26, v11); /*0x131621*/
      goto LABEL_33; /*0x131621*/
    }
    v14 = geteblk(v11); /*0x1314f0*/
    v15 = (int *)v14; /*0x1314f5*/
    if ( !a3 ) /*0x1314fe*/
    {
      v22 = sub_1318D4(a1, *(_DWORD *)(v14 + 32) + v23, a2[2], v13, v14 + 40, a5, v28); /*0x131528*/
      if ( v22 ) /*0x131530*/
      {
        brelse((int)v15); /*0x131537*/
        goto LABEL_55; /*0x13153f*/
      }
    }
LABEL_34:
    if ( (*(_BYTE *)v15 & 4) != 0 ) /*0x13162e*/
    {
      v22 = geterror((int)v15); /*0x13143e*/
      brelse((int)v15); /*0x131442*/
      goto LABEL_55; /*0x13144a*/
    }
    if ( !a3 ) /*0x131638*/
    {
      *(_DWORD *)(v24 + 100) = v20; /*0x131640*/
      v18 = *(_DWORD *)(v24 + 152) - a2[2]; /*0x13164c*/
      if ( v18 <= 0 ) /*0x131651*/
      {
        brelse((int)v15); /*0x131451*/
        v22 = 0; /*0x131456*/
        goto LABEL_55; /*0x131460*/
      }
      if ( v18 < v13 ) /*0x131659*/
      {
        v13 = *(_DWORD *)(v24 + 152) - a2[2]; /*0x13165b*/
        v21 = 1; /*0x13165d*/
      }
    }
    *(_BYTE *)(dword_1E875C + 104) = uiomove(v15[8] + v23, v13, a3, a2); /*0x131684*/
    if ( a3 ) /*0x13168e*/
    {
      v19 = a2[2]; /*0x13169b*/
      if ( *(_DWORD *)(v24 + 152) < v19 ) /*0x1316a7*/
      {
        *(_DWORD *)(v24 + 152) = v19; /*0x1316a9*/
        if ( *(_DWORD *)(*(_DWORD *)a1 + 20) < v19 ) /*0x1316ba*/
          *(_DWORD *)(*(_DWORD *)a1 + 20) = v19; /*0x1316bc*/
      }
      if ( (*(_BYTE *)(a1 + 4) & 0x40) != 0 ) /*0x1316c6*/
      {
        v22 = nfswrite(a1, v15[8] + v23, a2[2] - v13, v13, a5); /*0x1316e6*/
        brelse((int)v15); /*0x1316ea*/
      }
      else
      {
        *(_BYTE *)(v24 + 96) |= 0x10u; /*0x1316f7*/
        if ( v13 + v23 == v11 ) /*0x131702*/
        {
          *(_BYTE *)v15 |= 0x80u; /*0x131704*/
          bawrite((unsigned int *)v15); /*0x131708*/
        }
        else
        {
          bdwrite((int)v15); /*0x131711*/
        }
      }
    }
    else
    {
      brelse((int)v15); /*0x131691*/
    }
  }
  while ( !*(_BYTE *)(dword_1E875C + 104) && (int)a2[5] > 0 && !v21 ); /*0x131731*/
  if ( v22 ) /*0x13173b*/
    goto LABEL_55; /*0x13173b*/
  v9 = *(char *)(dword_1E875C + 104); /*0x131742*/
LABEL_54:
  v22 = v9; /*0x131746*/
LABEL_55:
  runlock(v24); /*0x131749*/
  return v22; /*0x131758*/
}
