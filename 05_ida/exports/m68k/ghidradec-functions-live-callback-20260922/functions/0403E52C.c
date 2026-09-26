
uint _ipc_kmsg_copyout_pseudo(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar4 = *(uint *)(param_1 + 0x14);
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  uVar2 = _ipc_kmsg_copyout_object(param_2,*(undefined4 *)(param_1 + 0x1c),uVar4 & 0xff,&uStack_8);
  uVar3 = _ipc_kmsg_copyout_object(param_2,uVar1,(uVar4 & 0xffff) >> 8,&uStack_c);
  uVar3 = uVar3 | uVar2;
  *(uint *)(param_1 + 0x14) = uVar4 & 0xbfffffff;
  *(undefined4 *)(param_1 + 0x1c) = uStack_8;
  *(undefined4 *)(param_1 + 0x20) = uStack_c;
  if ((int)uVar4 < 0) {
    uVar4 = _ipc_kmsg_copyout_body
                      (param_1 + 0x2c,param_1 + *(int *)(param_1 + 0x18) + 0x14,param_2,param_3);
    uVar3 = uVar4 | uVar3;
  }
  return uVar3;
}

