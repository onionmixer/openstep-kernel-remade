
undefined4 _ipc_kmsg_get_from_kernel(undefined4 param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _kalloc(param_2 + 0x14);
  if (iVar1 == 0) {
    uVar2 = 0x1000000d;
  }
  else {
    *(int *)(iVar1 + 8) = param_2 + 0x14;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    _bcopy(param_1,iVar1 + 0x14,param_3 + param_2);
    *(int *)(iVar1 + 0x10) = param_3;
    *(int *)(iVar1 + 0x18) = param_2;
    *param_4 = iVar1;
    uVar2 = 0;
  }
  return uVar2;
}
