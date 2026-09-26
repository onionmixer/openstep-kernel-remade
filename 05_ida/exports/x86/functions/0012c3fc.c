/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c3fc. */
int __cdecl nfs_getattr_otw(int a1, int a2, int a3)
{
  int *v3; // edi
  int v4; // ebx
  int v5; // eax

  v3 = (int *)kalloc(0x48u); /*0x12c40f*/
  v4 = rfscall(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 296), 1, xdr_fhandle, *(_DWORD *)(a1 + 48) + 64, xdr_attrstat, v3, a3); /*0x12c435*/
  if ( !v4 ) /*0x12c43c*/
  {
    v4 = *v3; /*0x12c43e*/
    if ( *v3 ) /*0x12c43e*/
    {
      if ( v4 == 70 ) /*0x12c46f*/
      {
        btrash(a1); /*0x12c472*/
        vnode_uncache(a1); /*0x12c47b*/
        mfs_invalidate(a1); /*0x12c481*/
        *(_DWORD *)(*(_DWORD *)(a1 + 48) + 192) = 0; /*0x12c489*/
        dnlc_purge_vp(a1); /*0x12c494*/
        binvalfree(a1); /*0x12c49a*/
      }
    }
    else
    {
      nattr_to_vattr(a1, v3 + 1, a2); /*0x12c44d*/
      v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 296) + 40); /*0x12c45b*/
      BYTE1(v5) = -1; /*0x12c45e*/
      *(_DWORD *)(a2 + 12) = v5; /*0x12c463*/
    }
  }
  kfree((int)v3, 0x48u); /*0x12c4a5*/
  return v4; /*0x12c4af*/
}
