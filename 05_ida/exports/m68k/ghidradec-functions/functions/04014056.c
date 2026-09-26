
void _sbwakeup(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    _selwakeup(*(int *)(param_1 + 0x10),*(byte *)(param_1 + 0x15) & 0x10);
    _selthreadclear(param_1 + 0x10);
    *(word *)(param_1 + 0x14) = *(word *)(param_1 + 0x14) & 0xffef;
  }
  if ((*(word *)(param_1 + 0x14) & 4) != 0) {
    *(word *)(param_1 + 0x14) = *(word *)(param_1 + 0x14) & 0xfffb;
    if (_nfs_wakeup_one_nfsd == 1) {
      _wakeup_one(param_1);
    }
    else {
      _wakeup(param_1);
    }
  }
  return;
}
