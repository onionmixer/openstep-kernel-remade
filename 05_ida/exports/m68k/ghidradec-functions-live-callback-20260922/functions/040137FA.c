
undefined4 _soshutdown(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if ((param_2 + 1U & 1) != 0) {
    _sorflush(param_1);
  }
  if ((param_2 + 1U & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(iVar1 + 0x1a))(param_1,7,0,0,0);
  }
  return uVar2;
}

