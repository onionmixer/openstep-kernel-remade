
void _ipc_kmsg_clean_body(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  int iVar2;
  byte bVar4;
  uint uVar3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  bool bVar9;
  
  while (param_1 < param_2) {
    bVar4 = param_1[3] >> 3;
    if ((param_1[3] & 4) == 0) {
      uVar7 = (uint)*param_1;
      uVar3 = (uint)param_1[1];
      uVar6 = *(uint *)(param_1 + 2) >> 0x14;
      param_1 = param_1 + 4;
    }
    else {
      uVar7 = (uint)*(word *)(param_1 + 4);
      uVar3 = (uint)*(word *)(param_1 + 6);
      uVar6 = *(uint *)(param_1 + 8);
      param_1 = param_1 + 0xc;
    }
    uVar3 = uVar3 * uVar6 + 7 >> 3;
    bVar9 = 5 < uVar7 - 0x10;
    if (!bVar9) {
      if ((bVar4 & 1) == 0) {
        pbVar8 = *(byte **)param_1;
      }
      else {
        for (pbVar1 = param_1 + uVar6 * 4; pbVar8 = param_1, param_2 < pbVar1; pbVar1 = pbVar1 + -4)
        {
          uVar6 = uVar6 - 1;
        }
      }
      uVar5 = 0;
      if (uVar6 != 0) {
        do {
          iVar2 = *(int *)pbVar8;
          if ((iVar2 != 0) && (iVar2 != -1)) {
            _ipc_object_destroy(iVar2,uVar7);
          }
          pbVar8 = pbVar8 + 4;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar6);
      }
    }
    if ((bVar4 & 1) == 0) {
      if (uVar3 != 0) {
        if (bVar9) {
          _vm_deallocate(_ipc_soft_map,*(int *)param_1,uVar3);
        }
        else {
          _kfree(*(int *)param_1,uVar3);
        }
      }
      param_1 = param_1 + 4;
    }
    else {
      param_1 = param_1 + (uVar3 + 3 & 0xfffffffc);
    }
  }
  return;
}

