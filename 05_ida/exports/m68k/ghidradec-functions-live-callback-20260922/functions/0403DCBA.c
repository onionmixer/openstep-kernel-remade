
void _ipc_kmsg_copyin_from_kernel(int param_1)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  uVar8 = *(uint *)(param_1 + 0x14);
  uVar7 = (uVar8 & 0xffff) >> 8;
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  iVar4 = *(int *)(param_1 + 0x20);
  _ipc_object_copyin_from_kernel(uVar1,uVar8 & 0xff);
  if ((iVar4 != 0) && (iVar4 != -1)) {
    _ipc_object_copyin_from_kernel(iVar4,uVar7);
  }
  if (uVar8 == 0x80000013) {
    *(undefined4 *)(param_1 + 0x14) = 0x80000011;
  }
  else {
    uVar3 = _ipc_object_copyin_type(uVar8 & 0xff);
    iVar4 = _ipc_object_copyin_type(uVar7);
    uVar8 = iVar4 << 8 | uVar3 | uVar8 & 0xffff0000;
    *(uint *)(param_1 + 0x14) = uVar8;
    if (-1 < (int)uVar8) {
      return;
    }
  }
  iVar4 = *(int *)(param_1 + 0x18);
  pbVar10 = (byte *)(param_1 + 0x2c);
  while (pbVar2 = pbVar10, pbVar2 < (byte *)(param_1 + iVar4 + 0x14)) {
    iVar6 = (uint)pbVar2[3] << 0x1d;
    if (iVar6 < 0) {
      uVar3 = (uint)*(word *)(pbVar2 + 4);
      uVar7 = (uint)*(word *)(pbVar2 + 6);
      uVar8 = *(uint *)(pbVar2 + 8);
      pbVar9 = pbVar2 + 0xc;
    }
    else {
      uVar3 = (uint)*pbVar2;
      uVar7 = (uint)pbVar2[1];
      uVar8 = *(uint *)(pbVar2 + 2) >> 0x14;
      pbVar9 = pbVar2 + 4;
    }
    if ((pbVar2[3] >> 3 & 1) == 0) {
      pbVar10 = pbVar9 + 4;
      pbVar9 = *(byte **)pbVar9;
    }
    else {
      pbVar10 = pbVar9 + ((uVar7 * uVar8 + 7 >> 3) + 3 & 0xfffffffc);
    }
    if (uVar3 - 0x10 < 6) {
      iVar5 = _ipc_object_copyin_type(uVar3);
      if (iVar6 < 0) {
        *(sword *)(pbVar2 + 4) = (sword)iVar5;
      }
      else {
        *pbVar2 = (byte)iVar5;
      }
      uVar7 = 0;
      if (uVar8 != 0) {
        do {
          iVar6 = *(int *)pbVar9;
          if ((((iVar6 != 0) && (iVar6 != -1)) &&
              (_ipc_object_copyin_from_kernel(iVar6,uVar3), iVar5 == 0x10)) &&
             (iVar6 = _ipc_port_check_circularity(iVar6,uVar1), iVar6 != 0)) {
            *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x40;
          }
          pbVar9 = pbVar9 + 4;
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar8);
      }
    }
  }
  return;
}

