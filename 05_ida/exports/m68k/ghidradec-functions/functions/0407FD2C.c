
int sub_407FD2C(int *param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined auStack_c [8];
  
  iVar6 = *param_1;
  if (*(char *)(iVar6 + 0x1c) == -1) {
    *(undefined4 *)(param_2 + 0x1c) = 0xb;
    return 0xd;
  }
  _microtime(auStack_c);
  if (*(int *)(param_2 + 0x14) == 0) {
    uStack_10 = 0;
  }
  else {
    iVar5 = _kmem_alloc_wired(_kernel_map,&uStack_10,*(int *)(param_2 + 0x14));
    if (iVar5 != 0) {
      *(undefined4 *)(param_2 + 0x1c) = 8;
      return 0xc;
    }
    if ((*(int *)(param_2 + 0xc) == 1) &&
       (iVar5 = _copyinmsg(*(undefined4 *)(param_2 + 0x10),uStack_10,*(undefined4 *)(param_2 + 0x14)
                          ), iVar5 != 0)) {
      _kmem_free(_kernel_map,uStack_10,*(undefined4 *)(param_2 + 0x14));
      *(undefined4 *)(param_2 + 0x1c) = 9;
      return iVar5;
    }
  }
  uVar1 = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_2 + 0x10) = uStack_10;
  piVar2 = (int *)param_1[3];
  if (piVar2 == param_1 + 2) {
    *piVar2 = param_2;
  }
  else {
    *(int *)((int)piVar2 + 0x4a) = param_2;
  }
  *(int **)(param_2 + 0x4e) = piVar2;
  *(int **)(param_2 + 0x4a) = param_1 + 2;
  param_1[3] = param_2;
  iVar5 = 0;
  *(byte *)(param_2 + 0x48) = *(byte *)(param_2 + 0x48) & 0xfe;
  if ((*(byte *)(iVar6 + 0x24) & 0x20) == 0) {
    iVar5 = _scsi_dstart(iVar6);
  }
  if (iVar5 == 0) {
    bVar4 = *(byte *)(param_2 + 0x48);
    while ((bVar4 & 1) == 0) {
      _sleep(param_2,0x14);
      bVar4 = *(byte *)(param_2 + 0x48);
    }
  }
  *(undefined4 *)(param_2 + 0x10) = uVar1;
  if (((*(int *)(param_2 + 0x3c) == 0) || (*(int *)(param_2 + 0xc) != 0)) ||
     (iVar6 = _copyoutmsg(uStack_10,uVar1,*(int *)(param_2 + 0x3c)), iVar6 == 0)) {
    if (*(int *)(param_2 + 0x14) != 0) {
      _kmem_free(_kernel_map,uStack_10,*(int *)(param_2 + 0x14));
    }
    puVar3 = (undefined4 *)param_1[1];
    *(undefined4 *)(param_2 + 0x22) = *puVar3;
    *(undefined4 *)(param_2 + 0x26) = puVar3[1];
    *(undefined4 *)(param_2 + 0x2a) = puVar3[2];
    *(undefined4 *)(param_2 + 0x2e) = puVar3[3];
    *(undefined4 *)(param_2 + 0x32) = puVar3[4];
    *(undefined4 *)(param_2 + 0x36) = puVar3[5];
    *(undefined2 *)(param_2 + 0x3a) = *(undefined2 *)(puVar3 + 6);
    _microtime(&uStack_18);
    _timevalsub(&uStack_18,auStack_c);
    *(undefined4 *)(param_2 + 0x40) = uStack_18;
    *(undefined4 *)(param_2 + 0x44) = uStack_14;
    iVar6 = 0;
  }
  else {
    _kmem_free(_kernel_map,uStack_10,*(undefined4 *)(param_2 + 0x14));
    *(undefined4 *)(param_2 + 0x1c) = 9;
  }
  return iVar6;
}
