
int _fdsetattr(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _getvnodefp(param_1,&iStack_8);
  if (iVar1 == 0) {
    iVar1 = *(int *)(iStack_8 + 0x16);
    if ((*(byte *)(*(int *)(iVar1 + 0x24) + 0xf) & 1) == 0) {
      iVar1 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x18))
                        (iVar1,param_2,*(undefined4 *)(iStack_8 + 0x1e));
    }
    else {
      iVar1 = 0x1e;
    }
  }
  return iVar1;
}

