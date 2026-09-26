
uint _ipc_kmsg_copyout(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x14);
  uVar2 = _ipc_kmsg_copyout_header(param_1 + 0x14,param_2,param_4);
  if ((uVar2 == 0) && (iVar1 < 0)) {
    uVar3 = _ipc_kmsg_copyout_body
                      (param_1 + 0x2c,param_1 + *(int *)(param_1 + 0x18) + 0x14,param_2,param_3);
    uVar2 = 0;
    if (uVar3 != 0) {
      uVar2 = uVar3 | 0x1000400c;
    }
  }
  return uVar2;
}

