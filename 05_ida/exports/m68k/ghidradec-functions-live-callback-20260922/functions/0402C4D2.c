
void _sync_vp(int param_1)

{
  _mfs_fsync(param_1);
  if ((*(byte *)(*(int *)(param_1 + 0x2e) + 0x5f) & 0x10) != 0) {
    sub_402C536(param_1);
  }
  return;
}

