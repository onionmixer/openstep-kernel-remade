/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x131760. */
int __cdecl nfswrite(int a1, int a2, int a3, int a4, _WORD *a5)
{
  int v5; // ebx
  int v6; // esi
  int v8; // [esp+Ch] [ebp-80h] BYREF
  _BYTE v9[68]; // [esp+10h] [ebp-7Ch] BYREF
  _BYTE v10[32]; // [esp+54h] [ebp-38h] BYREF
  int v11; // [esp+74h] [ebp-18h]
  int v12; // [esp+78h] [ebp-14h]
  int v13; // [esp+7Ch] [ebp-10h]
  int v14; // [esp+80h] [ebp-Ch]
  int v15; // [esp+84h] [ebp-8h]

  while ( 1 ) /*0x131778*/
  {
    v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 296) + 32); /*0x131778*/
    if ( a4 < v5 ) /*0x13177e*/
      v5 = a4; /*0x131780*/
    v15 = a2; /*0x131786*/
    qmemcpy(v10, (const void *)(*(_DWORD *)(a1 + 48) + 64), sizeof(v10)); /*0x13179b*/
    v11 = a3; /*0x1317a0*/
    v13 = v5; /*0x1317a3*/
    v14 = v5; /*0x1317a6*/
    v12 = a3; /*0x1317a9*/
    v6 = rfscall(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 296), 8, (int)xdr_writeargs, (int)v10, (int)xdr_attrstat, &v8, a5); /*0x1317d6*/
    if ( !v6 ) /*0x1317dd*/
    {
      v6 = v8; /*0x1317df*/
      if ( v8 == 70 ) /*0x1317e5*/
      {
        btrash(a1); /*0x1317eb*/
        nfs_invalidate_caches(a1); /*0x1317f4*/
      }
    }
    a4 -= v5; /*0x1317fc*/
    a2 += v5; /*0x1317ff*/
    a3 += v5; /*0x131802*/
    if ( v6 ) /*0x131807*/
      break; /*0x131807*/
    if ( !a4 ) /*0x13180d*/
    {
      nfs_attrcache(a1, (int)v9); /*0x13181b*/
      break; /*0x13181b*/
    }
  }
  if ( v6 == 28 )
  {
    printf(
      "NFS write error: on host %s remote file system full\n",
      (const char *)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 296) + 52));
  }
  else
  {
    if ( v6 > 28 ) /*0x131828*/
    {
      if ( v6 == 69 ) /*0x131833*/
        return v6; /*0x131833*/
      goto LABEL_16; /*0x131833*/
    }
    if ( v6 ) /*0x13182c*/
    {
LABEL_16:
      printf("NFS write error %d on host %s fh ", v6, (const char *)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 296) + 52)); /*0x131854*/
      sub_131898((void *)(*(_DWORD *)(a1 + 48) + 64)); /*0x131879*/
      printf("\n"); /*0x131883*/
    }
  }
  return v6; /*0x131890*/
}
