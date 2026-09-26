
uint _ipc_kmsg_copyout_body(byte *param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar5;
  int iVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  bool bVar13;
  undefined4 uStack_8;
  
  uVar9 = 0;
  do {
    while( true ) {
      if (param_2 <= param_1) {
        return uVar9;
      }
      bVar5 = param_1[3] >> 3;
      iVar2 = (uint)param_1[3] << 0x1d;
      if (iVar2 < 0) {
        uVar8 = (uint)*(word *)(param_1 + 4);
        uVar7 = (uint)*(word *)(param_1 + 6);
        uVar10 = *(uint *)(param_1 + 8);
        pbVar12 = param_1 + 0xc;
      }
      else {
        uVar8 = (uint)*param_1;
        uVar7 = (uint)param_1[1];
        uVar10 = *(uint *)(param_1 + 2) >> 0x14;
        pbVar12 = param_1 + 4;
      }
      uVar7 = uVar7 * uVar10 + 7 >> 3;
      bVar13 = 5 < uVar8 - 0x10;
      if (bVar13) break;
      if ((((bVar5 & 1) != 0) || (uVar7 == 0)) ||
         (iVar3 = _vm_allocate(param_4,&uStack_8,uVar7,1), iVar3 == 0)) {
        pbVar11 = pbVar12;
        if ((bVar5 & 1) == 0) {
          pbVar11 = *(byte **)pbVar12;
        }
        uVar6 = 0;
        if (uVar10 != 0) {
          do {
            uVar4 = _ipc_kmsg_copyout_object(param_3,*(undefined4 *)pbVar11,uVar8,pbVar11);
            uVar9 = uVar4 | uVar9;
            pbVar11 = pbVar11 + 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar10);
        }
        break;
      }
      _ipc_kmsg_clean_body(param_1,pbVar12);
loc_403E48C:
      uStack_8 = 0;
      if (iVar2 < 0) {
        param_1[6] = 0;
        param_1[7] = 0;
      }
      else {
        param_1[1] = 0;
      }
      if (iVar3 == 6) {
        uVar9 = uVar9 | 0x400;
      }
      else {
        uVar9 = uVar9 | 0x1000;
      }
loc_403E4B0:
      param_1[3] = param_1[3] | 2;
      param_1 = pbVar12 + 4;
      *(undefined4 *)pbVar12 = uStack_8;
    }
    if ((bVar5 & 1) == 0) {
      uVar1 = *(undefined4 *)pbVar12;
      if (uVar7 == 0) {
        uStack_8 = 0;
      }
      else if (bVar13) {
        iVar3 = _vm_move(_ipc_soft_map,uVar1,param_4,uVar7,0,&uStack_8);
        _vm_deallocate(_ipc_soft_map,uVar1,uVar7);
        if (iVar3 != 0) goto loc_403E48C;
      }
      else {
        _copyoutmap(param_4,uVar1,uStack_8,uVar7);
        _kfree(uVar1,uVar7);
      }
      goto loc_403E4B0;
    }
    param_1[3] = param_1[3] & 0xfd;
    param_1 = pbVar12 + (uVar7 + 3 & 0xfffffffc);
  } while( true );
}
