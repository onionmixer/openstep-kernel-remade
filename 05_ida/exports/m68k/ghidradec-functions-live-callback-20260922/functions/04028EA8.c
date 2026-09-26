
int _setdirgid(int param_1)

{
  sword sVar1;
  
  if (((*(byte *)(*(int *)(param_1 + 0x24) + 0xf) & 0x10) == 0) &&
     ((*(byte *)(*(int *)(param_1 + 0x2e) + 0x80) & 4) == 0)) {
    sVar1 = *(sword *)(*(int *)(_active_u + 0x1a) + 4);
  }
  else {
    sVar1 = *(sword *)(*(int *)(param_1 + 0x2e) + 0x84);
  }
  return (int)sVar1;
}

