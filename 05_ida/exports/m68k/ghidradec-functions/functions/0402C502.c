
void _sync_vp_invalidate(int param_1,undefined4 param_2)

{
  _mfs_fsync_invalidate(param_1,param_2);
  if ((*(byte *)(*(int *)(param_1 + 0x2e) + 0x5f) & 0x10) != 0) {
    sub_402C536(param_1);
  }
  return;
}
