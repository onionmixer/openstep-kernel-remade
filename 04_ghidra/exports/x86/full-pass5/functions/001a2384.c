/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a2384 */

undefined4 FUN_001a2384(int param_1,int param_2)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  ushort *puVar7;
  ushort uVar8;
  int in_FS_OFFSET;
  int local_24;
  int local_20;
  int local_1c;
  undefined2 uStack_12;
  ushort local_c [4];
  
  piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  local_24 = 0;
  if (piVar2 != (int *)0x0) {
    local_24 = *piVar2;
  }
  if (*(uint *)(local_24 + 0x84) < 8) {
    local_20 = local_24 + 0x88 + *(uint *)(local_24 + 0x84) * 0x84;
  }
  else {
    local_20 = 0;
  }
  uVar4 = *(uint *)(param_2 + 0x30);
  bVar5 = (byte)uVar4;
  if (uVar4 < 0x20) {
    uVar4 = (uint)((*(uint *)(local_24 + 4) & 1 << (bVar5 & 0x1f)) != 0);
  }
  else {
    if ((int)uVar4 < 0) {
      uVar4 = uVar4 + 7;
    }
    uVar4 = (int)(uint)*(byte *)(((int)uVar4 >> 3) + local_24 + 4) >>
            (bVar5 + (char)((int)uVar4 >> 3) * -8 & 0x1f) & 1;
  }
  if (uVar4 != 0) {
    *(undefined4 *)(local_20 + 0x4c) = *(undefined4 *)(param_2 + 0x30);
    *(undefined4 *)(local_20 + 0x50) = *(undefined4 *)(param_2 + 0x34);
    *(undefined4 *)(local_20 + 0x58) = 1;
    _PCcallMonitor(param_1,param_2);
  }
  iVar3 = *(int *)(param_2 + 0x30);
  piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar6 = 0;
  if (piVar2 != (int *)0x0) {
    iVar6 = *piVar2;
  }
  if (iVar6 == 0) {
    local_1c = 0;
  }
  else if (*(uint *)(iVar6 + 0x84) < 8) {
    local_1c = iVar6 + 0x88 + *(uint *)(iVar6 + 0x84) * 0x84;
  }
  else {
    local_1c = 0;
  }
  local_c[0] = *(ushort *)(param_2 + 0x38);
  local_c[1] = *(undefined2 *)(param_2 + 0x3c);
  if (*(int *)(local_1c + 0x68) == 0) {
    local_c[2] = *(ushort *)(param_2 + 0x40) & 0xfdff;
  }
  else {
    local_c[2] = *(ushort *)(param_2 + 0x40) | 0x200;
  }
  local_c[2] = local_c[2] | *(ushort *)(local_1c + 0x70) & 0x7000;
  uVar1 = *(ushort *)(param_2 + 0x48);
  uVar8 = *(short *)(param_2 + 0x44) - 6;
  puVar7 = local_c;
  iVar6 = 6;
  *(code **)(param_1 + 0x74) = __analysis_fragment_001a2520;
  do {
    *(ushort *)(in_FS_OFFSET + (uint)uVar8 + (uint)uVar1 * 0x10) = *puVar7;
    puVar7 = puVar7 + 1;
    uVar8 = uVar8 + 2;
    iVar6 = iVar6 + -2;
  } while (iVar6 != 0);
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(code **)(param_1 + 0x74) = __analysis_fragment_001a2548;
  uVar4 = *(uint *)(in_FS_OFFSET + iVar3 * 4);
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(uint *)(param_2 + 0x44) = (uint)(ushort)(*(short *)(param_2 + 0x44) - 6);
  *(uint *)(param_2 + 0x38) = uVar4 & 0xffff;
  uStack_12 = (undefined2)(uVar4 >> 0x10);
  *(undefined2 *)(param_2 + 0x3c) = uStack_12;
  *(undefined4 *)(local_1c + 0x68) = 0;
  if ((*(byte *)(local_1c + 0x80) & 1) == 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffeff;
  }
  return 1;
}

