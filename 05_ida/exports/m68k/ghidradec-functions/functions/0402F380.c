
undefined4 _svc_register(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined auStack_8 [4];
  
  iVar1 = sub_402F42A(param_2,param_3,auStack_8);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)_kalloc(0x10);
    puVar2[1] = param_2;
    puVar2[2] = param_3;
    puVar2[3] = param_4;
    *puVar2 = dword_40B3596;
    dword_40B3596 = puVar2;
  }
  else if (param_4 != *(int *)(iVar1 + 0xc)) {
    return 0;
  }
  return 1;
}
