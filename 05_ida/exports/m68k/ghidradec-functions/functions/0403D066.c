
void _ipc_kmsg_clean_partial(int param_1,byte *param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  
  uVar5 = *(uint *)(param_1 + 0x14);
  _ipc_object_destroy(*(undefined4 *)(param_1 + 0x1c),uVar5 & 0xff);
  iVar2 = *(int *)(param_1 + 0x20);
  if ((iVar2 != 0) && (iVar2 != -1)) {
    _ipc_object_destroy(iVar2,(uVar5 & 0xffff) >> 8);
  }
  _ipc_kmsg_clean_body(param_1 + 0x2c,param_2);
  if (param_3 != 0) {
    iVar2 = (uint)param_2[3] << 0x1c;
    if ((param_2[3] & 4) == 0) {
      uVar4 = (uint)*param_2;
      uVar3 = (uint)param_2[1];
      uVar5 = *(uint *)(param_2 + 2) >> 0x14;
      param_2 = param_2 + 4;
    }
    else {
      uVar4 = (uint)*(word *)(param_2 + 4);
      uVar3 = (uint)*(word *)(param_2 + 6);
      uVar5 = *(uint *)(param_2 + 8);
      param_2 = param_2 + 0xc;
    }
    uVar5 = uVar3 * uVar5 + 7 >> 3;
    bVar7 = 5 < uVar4 - 0x10;
    if (!bVar7) {
      pbVar6 = param_2;
      if (-1 < iVar2) {
        pbVar6 = *(byte **)param_2;
      }
      uVar3 = 0;
      if (param_4 != 0) {
        do {
          iVar1 = *(int *)pbVar6;
          if ((iVar1 != 0) && (iVar1 != -1)) {
            _ipc_object_destroy(iVar1,uVar4);
          }
          pbVar6 = pbVar6 + 4;
          uVar3 = uVar3 + 1;
        } while (uVar3 < param_4);
      }
    }
    if ((-1 < iVar2) && (uVar5 != 0)) {
      if (bVar7) {
        _vm_deallocate(_ipc_soft_map,*(int *)param_2,uVar5);
      }
      else {
        _kfree(*(int *)param_2,uVar5);
      }
    }
  }
  return;
}
