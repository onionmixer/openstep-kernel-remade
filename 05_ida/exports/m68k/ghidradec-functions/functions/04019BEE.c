
undefined4 _pn_append(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _strlen(param_2);
  if ((uint)(iVar1 + *(int *)(param_1 + 8)) < 0x400) {
    _bcopy(param_2,*(int *)(param_1 + 4) + *(int *)(param_1 + 8),iVar1 + 1);
    *(int *)(param_1 + 8) = iVar1 + *(int *)(param_1 + 8);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x3f;
  }
  return uVar2;
}
