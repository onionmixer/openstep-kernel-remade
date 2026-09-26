
void _vfs_unlock(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 0xf) & 2) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVfsUnlock);
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar1 & 0xfffffffd;
  if ((uVar1 & 4) != 0) {
    *(uint *)(param_1 + 0xc) = uVar1 & 0xfffffff9;
    _wakeup(param_1);
  }
  return;
}

