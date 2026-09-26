/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c224. */
int __cdecl nfs_invalidate_caches(int a1)
{
  vnode_uncache(a1); /*0x12c22c*/
  mfs_invalidate(a1); /*0x12c232*/
  *(_DWORD *)(*(_DWORD *)(a1 + 48) + 192) = 0; /*0x12c23a*/
  dnlc_purge_vp(a1); /*0x12c245*/
  return binvalfree(a1); /*0x12c250*/
}
