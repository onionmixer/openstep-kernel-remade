
undefined4 _isrofile(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((1 < *(int *)(param_1 + 0x28) - 3U) && (*(int *)(param_1 + 0x28) != 8)) &&
     ((*(byte *)(*(int *)(param_1 + 0x24) + 0xf) & 1) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

