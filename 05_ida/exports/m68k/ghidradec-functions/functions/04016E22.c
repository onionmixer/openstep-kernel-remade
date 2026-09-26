
void _cstatfs(int param_1,undefined4 param_2)

{
  undefined uVar1;
  undefined auStack_44 [64];
  
  _bzero(auStack_44,0x40);
  uVar1 = (**(code **)(*(int *)(param_1 + 4) + 0xc))(param_1,auStack_44);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uVar1 = _copyoutmsg(auStack_44,param_2,0x40);
    *(undefined *)(dword_40B57D4 + 100) = uVar1;
  }
  return;
}

