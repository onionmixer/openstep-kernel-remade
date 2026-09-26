
void _nfs_invalidate_caches(int param_1)

{
  _vnode_uncache(param_1);
  _mfs_invalidate(param_1);
  *(undefined4 *)(*(int *)(param_1 + 0x2e) + 0xb6) = 0;
  _dnlc_purge_vp(param_1);
  _binvalfree(param_1);
  return;
}
