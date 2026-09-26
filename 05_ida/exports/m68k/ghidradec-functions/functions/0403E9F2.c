
void _ipc_kmsg_copyin_compat_from_kernel(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte bVar7;
  bool bVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  byte *pbVar15;
  byte *pbVar16;
  char cStack_19;
  
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  uVar3 = *(undefined4 *)(param_1 + 0x1c);
  iVar4 = *(int *)(param_1 + 0x20);
  uVar5 = *(undefined4 *)(param_1 + 0x24);
  uVar6 = *(undefined4 *)(param_1 + 0x28);
  _ipc_object_copyin_from_kernel(uVar5,0x13);
  if ((iVar4 != 0) && (iVar4 != -1)) {
    _ipc_object_copyin_from_kernel(iVar4,0x14);
  }
  uVar10 = _ipc_object_copyin_type(0x13);
  iVar11 = _ipc_object_copyin_type(0x14);
  *(uint *)(param_1 + 0x14) = iVar11 << 8 | uVar10;
  *(undefined4 *)(param_1 + 0x18) = uVar2;
  *(undefined4 *)(param_1 + 0x1c) = uVar5;
  *(int *)(param_1 + 0x20) = iVar4;
  *(undefined4 *)(param_1 + 0x24) = uVar3;
  *(undefined4 *)(param_1 + 0x28) = uVar6;
  cStack_19 = (char)uVar1;
  if (cStack_19 == '\0') {
    bVar8 = false;
    iVar4 = *(int *)(param_1 + 0x18);
    pbVar16 = (byte *)(param_1 + 0x2c);
    while (pbVar9 = pbVar16, pbVar9 < (byte *)(param_1 + iVar4 + 0x14)) {
      bVar7 = pbVar9[3];
      iVar11 = (uint)bVar7 << 0x1d;
      if (iVar11 < 0) {
        uVar14 = (uint)*(word *)(pbVar9 + 4);
        uVar13 = (uint)*(word *)(pbVar9 + 6);
        uVar10 = *(uint *)(pbVar9 + 8);
        pbVar15 = pbVar9 + 0xc;
      }
      else {
        uVar14 = (uint)*pbVar9;
        uVar13 = (uint)pbVar9[1];
        uVar10 = *(uint *)(pbVar9 + 2) >> 0x14;
        pbVar15 = pbVar9 + 4;
      }
      pbVar9[3] = pbVar9[3] & 0xfe;
      if (iVar11 < 0) {
        *pbVar9 = 0;
        pbVar9[1] = 0;
        *(word *)(pbVar9 + 2) = *(word *)(pbVar9 + 2) & 0xf;
      }
      if ((bVar7 >> 3 & 1) == 0) {
        pbVar16 = pbVar15 + 4;
        pbVar15 = *(byte **)pbVar15;
        bVar8 = true;
      }
      else {
        pbVar16 = pbVar15 + ((uVar13 * uVar10 + 7 >> 3) + 3 & 0xfffffffc);
      }
      if (uVar14 - 5 < 2) {
        iVar12 = _ipc_object_copyin_type(uVar14);
        if (iVar11 < 0) {
          *(sword *)(pbVar9 + 4) = (sword)iVar12;
        }
        else {
          *pbVar9 = (byte)iVar12;
        }
        uVar13 = 0;
        if (uVar10 != 0) {
          do {
            iVar11 = *(int *)pbVar15;
            if ((((iVar11 != 0) && (iVar11 != -1)) &&
                (_ipc_object_copyin_from_kernel(iVar11,uVar14), iVar12 == 0x10)) &&
               (iVar11 = _ipc_port_check_circularity(iVar11,uVar5), iVar11 != 0)) {
              *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x40;
            }
            pbVar15 = pbVar15 + 4;
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar10);
        }
        bVar8 = true;
      }
    }
    if (bVar8) {
      *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x80;
    }
  }
  return;
}
