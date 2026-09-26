/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c290 */

void _nfs_cache_check(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if ((-1 < *(char *)(iVar1 + 0x10)) &&
     (((*(int *)(iVar1 + 0xa8) != param_2 || (*(int *)(iVar1 + 0xac) != param_3)) ||
      (*(int *)(iVar1 + 0x98) != param_4)))) {
    _sync_vp_invalidate(param_1,param_5);
    _vnode_uncache(param_1);
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
    _dnlc_purge_vp(param_1);
    _binvalfree(param_1);
  }
  return;
}

