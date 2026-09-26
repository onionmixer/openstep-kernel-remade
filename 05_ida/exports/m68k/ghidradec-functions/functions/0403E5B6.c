
void _ipc_kmsg_copyout_dest(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uStack_8;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  piVar3 = *(int **)(param_1 + 0x1c);
  iVar5 = *(int *)(param_1 + 0x20);
  uVar4 = (uVar2 & 0xffff) >> 8;
  if (piVar3[1] < 0) {
    _ipc_object_copyout_dest(param_2,piVar3,uVar2 & 0xff,&uStack_8);
  }
  else {
    iVar1 = *piVar3;
    *piVar3 = iVar1 + -1;
    if (iVar1 == 1) {
      _zfree((&_ipc_object_zones)[*(word *)(piVar3 + 1) & 0x7fff],piVar3);
    }
    uStack_8 = 0xffffffff;
  }
  if ((iVar5 != 0) && (iVar5 != -1)) {
    _ipc_object_destroy(iVar5,uVar4);
    iVar5 = 0;
  }
  *(uint *)(param_1 + 0x14) = uVar4 | (uVar2 & 0xff) << 8 | uVar2 & 0xffff0000;
  *(undefined4 *)(param_1 + 0x20) = uStack_8;
  *(int *)(param_1 + 0x1c) = iVar5;
  if ((int)uVar2 < 0) {
    _ipc_kmsg_clean_body(param_1 + 0x2c,param_1 + *(int *)(param_1 + 0x18) + 0x14);
  }
  return;
}
