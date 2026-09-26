
void _fsync(void)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _getvnodefp(**(undefined4 **)(dword_40B57D4 + 0x24),&iStack_8);
  if (iVar1 == 0) {
    iVar1 = _mfs_fsync(*(undefined4 *)(iStack_8 + 0x16));
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*(int *)(*(int *)(iStack_8 + 0x16) + 0x1c) + 0x48))
                        (*(int *)(iStack_8 + 0x16),*(undefined4 *)(iStack_8 + 0x1e));
    }
  }
  *(char *)(dword_40B57D4 + 100) = (char)iVar1;
  return;
}

