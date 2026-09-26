
undefined4 _vfs_lock(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0xc) & 2) == 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 2;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10;
  }
  return uVar1;
}

