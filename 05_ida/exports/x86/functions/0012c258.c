/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c258. */
int __cdecl nfs_purge_caches(int a1, int a2)
{
  sync_vp_invalidate(a1, a2); /*0x12c264*/
  vnode_uncache(a1); /*0x12c26a*/
  *(_DWORD *)(*(_DWORD *)(a1 + 48) + 192) = 0; /*0x12c272*/
  dnlc_purge_vp(a1); /*0x12c27d*/
  return binvalfree(a1); /*0x12c288*/
}
