
undefined4 _ipc_kmsg_copyout_compat(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte bVar6;
  int iVar4;
  undefined2 uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  bool bVar12;
  uint uStack_30;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar9 = *(uint *)(param_1 + 0x14);
  piVar1 = *(int **)(param_1 + 0x1c);
  iVar2 = *(int *)(param_1 + 0x20);
  if (piVar1[1] < 0) {
    _ipc_object_copyout_dest(param_2,piVar1,uVar9 & 0xff,&uStack_20);
  }
  else {
    iVar3 = *piVar1;
    *piVar1 = iVar3 + -1;
    if (iVar3 == 1) {
      _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
    }
    uStack_20 = 0;
  }
  if ((iVar2 == 0) || (iVar2 == -1)) {
    uStack_24 = 0;
  }
  else {
    uVar8 = (uVar9 & 0xffff) >> 8;
    iVar3 = _ipc_object_copyout_compat(param_2,iVar2,uVar8,&uStack_24);
    if (iVar3 != 0) {
      _ipc_object_destroy(iVar2,uVar8);
      uStack_24 = 0;
    }
  }
  uStack_1c = CARRY4(uVar9,uVar9) ^ 1;
  uStack_18 = *(undefined4 *)(param_1 + 0x18);
  uStack_14 = *(undefined4 *)(param_1 + 0x24);
  uStack_8 = *(undefined4 *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x14) = uStack_1c;
  *(undefined4 *)(param_1 + 0x18) = uStack_18;
  *(undefined4 *)(param_1 + 0x1c) = uStack_14;
  *(undefined4 *)(param_1 + 0x20) = uStack_20;
  *(undefined4 *)(param_1 + 0x24) = uStack_24;
  *(undefined4 *)(param_1 + 0x28) = uStack_8;
  pbVar11 = (byte *)(param_1 + 0x2c);
  if ((char)uStack_1c == '\0') {
    iVar2 = *(int *)(param_1 + 0x18);
    uStack_10 = uStack_20;
    uStack_c = uStack_24;
    while (pbVar11 < (byte *)(iVar2 + 0x14 + param_1)) {
      bVar6 = pbVar11[3] >> 3;
      iVar3 = (uint)pbVar11[3] << 0x1d;
      if (iVar3 < 0) {
        uVar8 = (uint)*(word *)(pbVar11 + 4);
        uVar9 = (uint)*(word *)(pbVar11 + 6);
        uStack_30 = *(uint *)(pbVar11 + 8);
        pbVar10 = pbVar11 + 0xc;
      }
      else {
        uVar8 = (uint)*pbVar11;
        uVar9 = (uint)pbVar11[1];
        uStack_30 = *(uint *)(pbVar11 + 2) >> 0x14;
        pbVar10 = pbVar11 + 4;
      }
      uVar9 = uVar9 * uStack_30 + 7 >> 3;
      bVar12 = 5 < uVar8 - 0x10;
      if (bVar12) {
loc_403EDEE:
        if ((bVar6 & 1) == 0) {
          iVar3 = *(int *)pbVar10;
          if (uVar9 == 0) goto loc_403EE60;
          if (bVar12) {
            iVar4 = _vm_move(_ipc_soft_map,iVar3,param_3,uVar9,0,&iStack_28);
            _vm_deallocate(_ipc_soft_map,iVar3,uVar9);
            if (iVar4 != 0) goto loc_403EE60;
          }
          else {
            _copyoutmap(param_3,iVar3,iStack_28,uVar9);
            _kfree(iVar3,uVar9);
          }
          goto loc_403EE64;
        }
        pbVar11 = pbVar10 + (uVar9 + 3 & 0xfffffffc);
      }
      else {
        if ((((bVar6 & 1) != 0) || (uVar9 == 0)) ||
           (iVar4 = _vm_allocate(param_3,&iStack_28,uVar9,1), iVar4 == 0)) {
          uVar5 = _ipc_object_copyout_type_compat(uVar8);
          if (iVar3 < 0) {
            *(undefined2 *)(pbVar11 + 4) = uVar5;
          }
          else {
            *pbVar11 = (byte)uVar5;
          }
          pbVar11 = pbVar10;
          if ((bVar6 & 1) == 0) {
            pbVar11 = *(byte **)pbVar10;
          }
          uVar7 = 0;
          if (uStack_30 != 0) {
            do {
              iVar3 = *(int *)pbVar11;
              if ((iVar3 == 0) || (iVar3 == -1)) {
                pbVar11[0] = 0;
                pbVar11[1] = 0;
                pbVar11[2] = 0;
                pbVar11[3] = 0;
              }
              else {
                iVar4 = _ipc_object_copyout_compat(param_2,iVar3,uVar8,pbVar11);
                if (iVar4 != 0) {
                  _ipc_object_destroy(iVar3,uVar8);
                  pbVar11[0] = 0;
                  pbVar11[1] = 0;
                  pbVar11[2] = 0;
                  pbVar11[3] = 0;
                }
              }
              pbVar11 = pbVar11 + 4;
              uVar7 = uVar7 + 1;
            } while (uVar7 < uStack_30);
          }
          goto loc_403EDEE;
        }
        _ipc_kmsg_clean_body(pbVar11,pbVar10);
loc_403EE60:
        iStack_28 = 0;
loc_403EE64:
        pbVar11 = pbVar10 + 4;
        *(int *)pbVar10 = iStack_28;
      }
    }
  }
  return 0;
}

