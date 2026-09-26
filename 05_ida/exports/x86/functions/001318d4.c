/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1318d4. */
int __cdecl sub_1318D4(int *a1, int a2, int a3, int a4, _DWORD *a5, _WORD *a6, int a7)
{
  int v7; // esi
  unsigned int i; // ebx
  int v10; // [esp+10h] [ebp-A8h]
  _DWORD v11[8]; // [esp+14h] [ebp-A4h] BYREF
  int v12; // [esp+34h] [ebp-84h] BYREF
  int v13[17]; // [esp+38h] [ebp-80h] BYREF
  int v14; // [esp+7Ch] [ebp-3Ch]
  int v15; // [esp+80h] [ebp-38h]
  _BYTE v16[32]; // [esp+8Ch] [ebp-2Ch] BYREF
  int v17; // [esp+ACh] [ebp-Ch]
  int v18; // [esp+B0h] [ebp-8h]
  int v19; // [esp+B4h] [ebp-4h]

  do /*0x131a0e*/
  {
    v10 = *(_DWORD *)(*(_DWORD *)(a1[9] + 296) + 28); /*0x1318ef*/
    if ( v10 > a4 ) /*0x1318fa*/
      v10 = a4; /*0x1318fc*/
    v15 = a2; /*0x131905*/
    qmemcpy(v16, (const void *)(a1[12] + 64), sizeof(v16)); /*0x13191a*/
    v17 = a3; /*0x13191f*/
    v19 = v10; /*0x131928*/
    v18 = v10; /*0x13192b*/
    v7 = rfscall(*(_DWORD *)(a1[9] + 296), 6, (int)xdr_readargs, (int)v16, (int)xdr_rdresult, &v12, a6); /*0x13195b*/
    if ( v7 ) /*0x131962*/
      break; /*0x131962*/
    v7 = v12; /*0x131968*/
    if ( v12 == 70 ) /*0x131971*/
    {
      printf("NFS read error ESTALE to host %10s fh ", (const char *)(*(_DWORD *)(a1[9] + 296) + 52)); /*0x131988*/
      bcopy((const void *)(a1[12] + 64), v11, 0x20u); /*0x1319a3*/
      for ( i = 0; i <= 7; ++i ) /*0x1319a8*/
        printf("%x ", v11[i]); /*0x1319bd*/
      printf("\n"); /*0x1319d0*/
      btrash((int)a1); /*0x1319e1*/
      nfs_invalidate_caches((int)a1); /*0x1319ea*/
    }
    if ( v7 ) /*0x1319f4*/
      break; /*0x1319f4*/
    a4 -= v14; /*0x1319f9*/
    a2 += v14; /*0x1319fc*/
    a3 += v14; /*0x1319ff*/
    if ( !a4 ) /*0x131a06*/
      break; /*0x131a06*/
  }
  while ( v10 == v14 ); /*0x131a0e*/
  *a5 = a4; /*0x131a1a*/
  if ( !v7 ) /*0x131a1e*/
    nattr_to_vattr(a1, v13, a7); /*0x131a2c*/
  return v7; /*0x131a39*/
}
