/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c290. */
int __cdecl nfs_cache_check(int a1, int a2, int a3, int a4, int a5)
{
  int result; // eax
  int v6; // edx

  result = a4; /*0x12c29f*/
  v6 = *(_DWORD *)(a1 + 48); /*0x12c2a2*/
  if ( *(char *)(v6 + 16) >= 0 /*0x12c2c1*/
    && (*(_DWORD *)(v6 + 168) != a2 || *(_DWORD *)(v6 + 172) != a3 || *(_DWORD *)(v6 + 152) != a4) )
  {
    sync_vp_invalidate(a1, a5); /*0x12c2c8*/
    vnode_uncache(a1); /*0x12c2ce*/
    *(_DWORD *)(*(_DWORD *)(a1 + 48) + 192) = 0; /*0x12c2d6*/
    dnlc_purge_vp(a1); /*0x12c2e1*/
    return binvalfree(a1); /*0x12c2e7*/
  }
  return result; /*0x12c2ef*/
}
