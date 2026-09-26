/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x132a04. */
int __cdecl sub_132A04(int a1, char *a2, int a3, char *a4, _WORD *a5)
{
  int v5; // ebx
  int v7; // [esp+Ch] [ebp-4Ch] BYREF
  _BYTE v8[36]; // [esp+10h] [ebp-48h] BYREF
  _BYTE v9[36]; // [esp+34h] [ebp-24h] BYREF

  if ( !strcmp(a2, ".") || !strcmp(a2, "..") || !strcmp(a4, ".") || !strcmp(a4, "..") ) /*0x132a5c*/
    return 22; /*0x132a60*/
  rlock(*(_DWORD *)(a1 + 48)); /*0x132a73*/
  dnlc_remove(a1, a2); /*0x132a7d*/
  dnlc_remove(a3, a4); /*0x132a8a*/
  if ( a3 != a1 ) /*0x132a98*/
    rlock(*(_DWORD *)(a3 + 48)); /*0x132aa1*/
  setdiropargs(v8, (int)a2, a1); /*0x132ab2*/
  setdiropargs(v9, (int)a4, a3); /*0x132ac3*/
  v5 = rfscall(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 296), 11, (int)xdr_rnmargs, (int)v8, (int)xdr_enum, &v7, a5); /*0x132aef*/
  *(_DWORD *)(*(_DWORD *)(a1 + 48) + 192) = 0; /*0x132af7*/
  *(_DWORD *)(*(_DWORD *)(a3 + 48) + 192) = 0; /*0x132b07*/
  runlock(*(_DWORD *)(a1 + 48)); /*0x132b18*/
  if ( a3 != a1 ) /*0x132b26*/
    runlock(*(_DWORD *)(a3 + 48)); /*0x132b2f*/
  if ( !v5 ) /*0x132b39*/
  {
    v5 = v7; /*0x132b3b*/
    if ( v7 == 70 ) /*0x132b41*/
    {
      btrash(a1); /*0x132b47*/
      nfs_invalidate_caches(a1); /*0x132b50*/
      btrash(a3); /*0x132b5c*/
      nfs_invalidate_caches(a3); /*0x132b65*/
    }
  }
  return v5; /*0x132b6f*/
}
