/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00149a64 */

void _ipc_kmsg_copyin_compat_from_kernel(int param_1)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined2 local_44;
  uint local_40;
  uint local_30;
  uint local_2c;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar9 = (undefined4 *)(param_1 + 0x14);
  puVar11 = &local_1c;
  for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar11 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar11 = puVar11 + 1;
  }
  _ipc_object_copyin_from_kernel(local_c,0x13);
  if ((local_10 != 0) && (local_10 != -1)) {
    _ipc_object_copyin_from_kernel(local_10,0x14);
  }
  uVar4 = _ipc_object_copyin_type(0x13);
  iVar8 = _ipc_object_copyin_type(0x14);
  *(uint *)(param_1 + 0x14) = uVar4 | iVar8 << 8;
  *(undefined4 *)(param_1 + 0x18) = local_18;
  *(undefined4 *)(param_1 + 0x1c) = local_c;
  *(int *)(param_1 + 0x20) = local_10;
  *(undefined4 *)(param_1 + 0x24) = local_14;
  *(undefined4 *)(param_1 + 0x28) = local_8;
  if (local_1c._3_1_ == '\0') {
    bVar2 = false;
    iVar8 = *(int *)(param_1 + 0x18);
    pbVar13 = (byte *)(param_1 + 0x2c);
    while (pbVar3 = pbVar13, pbVar3 < (byte *)(iVar8 + 0x14 + param_1)) {
      bVar1 = pbVar3[3];
      bVar7 = pbVar3[3] >> 5;
      if ((bVar7 & 1) == 0) {
        local_2c = (uint)*pbVar3;
        local_40 = (uint)pbVar3[1];
        local_30 = *(ushort *)(pbVar3 + 2) & 0xfff;
        pbVar12 = pbVar3 + 4;
      }
      else {
        local_2c = (uint)*(ushort *)(pbVar3 + 4);
        local_40 = (uint)*(ushort *)(pbVar3 + 6);
        local_30 = *(uint *)(pbVar3 + 8);
        pbVar12 = pbVar3 + 0xc;
      }
      pbVar3[3] = pbVar3[3] & 0x7f;
      if ((bVar7 & 1) != 0) {
        *pbVar3 = 0;
        pbVar3[1] = 0;
        *(ushort *)(pbVar3 + 2) = *(ushort *)(pbVar3 + 2) & 0xf000;
      }
      if ((bVar1 >> 4 & 1) == 0) {
        pbVar10 = *(byte **)pbVar12;
        pbVar13 = pbVar12 + 4;
        bVar2 = true;
      }
      else {
        pbVar13 = pbVar12 + ((local_30 * local_40 + 7 >> 3) + 3 & 0xfffffffc);
        pbVar10 = pbVar12;
      }
      if (local_2c - 5 < 2) {
        iVar5 = _ipc_object_copyin_type(local_2c);
        if ((bVar7 & 1) == 0) {
          local_44._0_1_ = (byte)iVar5;
          *pbVar3 = (byte)local_44;
        }
        else {
          local_44 = (undefined2)iVar5;
          *(undefined2 *)(pbVar3 + 4) = local_44;
        }
        uVar4 = 0;
        if (local_30 != 0) {
          do {
            iVar6 = *(int *)(pbVar10 + uVar4 * 4);
            if ((((iVar6 != 0) && (iVar6 != -1)) &&
                (_ipc_object_copyin_from_kernel(iVar6,local_2c), iVar5 == 0x10)) &&
               (iVar6 = _ipc_port_check_circularity(iVar6,local_c), iVar6 != 0)) {
              *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < local_30);
        }
        bVar2 = true;
      }
    }
    if (bVar2) {
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x80000000;
    }
  }
  return;
}

