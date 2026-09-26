/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014839c */

void _ipc_kmsg_copyin_from_kernel(int param_1)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint local_1c;
  uint local_18;
  
  uVar6 = *(uint *)(param_1 + 0x14);
  uVar3 = (uVar6 & 0xff00) >> 8;
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  iVar5 = *(int *)(param_1 + 0x20);
  _ipc_object_copyin_from_kernel(uVar1,uVar6 & 0xff);
  if ((iVar5 != 0) && (iVar5 != -1)) {
    _ipc_object_copyin_from_kernel(iVar5,uVar3);
  }
  if (uVar6 == 0x80000013) {
    *(undefined4 *)(param_1 + 0x14) = 0x80000011;
  }
  else {
    uVar4 = _ipc_object_copyin_type(uVar6 & 0xff);
    iVar5 = _ipc_object_copyin_type(uVar3);
    uVar6 = uVar6 & 0xffff0000 | iVar5 << 8 | uVar4;
    *(uint *)(param_1 + 0x14) = uVar6;
    if (-1 < (int)uVar6) {
      return;
    }
  }
  iVar5 = *(int *)(param_1 + 0x18);
  pbVar12 = (byte *)(param_1 + 0x2c);
  while (pbVar2 = pbVar12, pbVar2 < (byte *)(iVar5 + 0x14 + param_1)) {
    bVar9 = pbVar2[3] >> 5;
    if ((bVar9 & 1) == 0) {
      local_18 = (uint)*pbVar2;
      uVar6 = (uint)pbVar2[1];
      local_1c = *(ushort *)(pbVar2 + 2) & 0xfff;
      pbVar11 = pbVar2 + 4;
    }
    else {
      local_18 = (uint)*(ushort *)(pbVar2 + 4);
      uVar6 = (uint)*(ushort *)(pbVar2 + 6);
      local_1c = *(uint *)(pbVar2 + 8);
      pbVar11 = pbVar2 + 0xc;
    }
    if ((pbVar2[3] >> 4 & 1) == 0) {
      pbVar10 = *(byte **)pbVar11;
      pbVar12 = pbVar11 + 4;
    }
    else {
      pbVar12 = pbVar11 + ((uVar6 * local_1c + 7 >> 3) + 3 & 0xfffffffc);
      pbVar10 = pbVar11;
    }
    if (local_18 - 0x10 < 6) {
      iVar7 = _ipc_object_copyin_type(local_18);
      if ((bVar9 & 1) == 0) {
        *pbVar2 = (byte)iVar7;
      }
      else {
        *(short *)(pbVar2 + 4) = (short)iVar7;
      }
      uVar6 = 0;
      if (local_1c != 0) {
        do {
          iVar8 = *(int *)(pbVar10 + uVar6 * 4);
          if ((((iVar8 != 0) && (iVar8 != -1)) &&
              (_ipc_object_copyin_from_kernel(iVar8,local_18), iVar7 == 0x10)) &&
             (iVar8 = _ipc_port_check_circularity(iVar8,uVar1), iVar8 != 0)) {
            *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < local_1c);
      }
    }
  }
  return;
}

