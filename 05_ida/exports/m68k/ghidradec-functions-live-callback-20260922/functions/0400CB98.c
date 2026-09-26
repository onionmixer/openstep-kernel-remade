
undefined4 _soo_close(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x16) != 0) {
    uVar1 = _soclose(*(int *)(param_1 + 0x16));
  }
  *(undefined4 *)(param_1 + 0x16) = 0;
  return uVar1;
}

