/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c258 */

void _nfs_purge_caches(int param_1,undefined4 param_2)

{
  _sync_vp_invalidate(param_1,param_2);
  _vnode_uncache(param_1);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  _dnlc_purge_vp(param_1);
  _binvalfree(param_1);
  return;
}

