/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a20d4 */

/* WARNING: Removing unreachable block (ram,0x001a219e) */

undefined4 FUN_001a20d4(int param_1,int param_2,short param_3)

{
  short sVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  ushort uVar8;
  int in_FS_OFFSET;
  int local_28;
  int local_24;
  undefined2 uStack_1a;
  ushort local_14 [4];
  ushort local_c;
  byte local_5;
  
  piVar3 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  local_28 = 0;
  if (piVar3 != (int *)0x0) {
    local_28 = *piVar3;
  }
  if (*(uint *)(local_28 + 0x84) < 8) {
    iVar6 = local_28 + 0x88 + *(uint *)(local_28 + 0x84) * 0x84;
  }
  else {
    iVar6 = 0;
  }
  sVar1 = *(short *)(param_2 + 0x38);
  local_c = *(ushort *)(param_2 + 0x3c);
  *(code **)(param_1 + 0x74) = __analysis_fragment_001a215c;
  local_5 = *(byte *)(in_FS_OFFSET + (uint)local_c * 0x10 + (uint)(ushort)(param_3 + sVar1 + 1));
  *(undefined4 *)(param_1 + 0x74) = 0;
  if (local_5 < 0x20) {
    uVar5 = (uint)((*(uint *)(local_28 + 8) & 1 << (local_5 & 0x1f)) != 0);
  }
  else {
    iVar4 = (int)(uint)local_5 >> 3;
    uVar5 = (int)(uint)*(byte *)(iVar4 + local_28 + 8) >> (local_5 + (char)iVar4 * -8 & 0x1f) & 1;
  }
  if (uVar5 != 0) {
    *(uint *)(iVar6 + 0x4c) = (uint)local_5;
    *(undefined4 *)(iVar6 + 0x50) = 0;
    if (local_5 < 8) {
      *(undefined4 *)(iVar6 + 0x58) = 1;
    }
    else {
      *(undefined4 *)(iVar6 + 0x58) = 2;
    }
    _PCcallMonitor(param_1,param_2);
  }
  *(uint *)(param_2 + 0x38) = (uint)(ushort)(param_3 + 2 + *(short *)(param_2 + 0x38));
  piVar3 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar6 = 0;
  if (piVar3 != (int *)0x0) {
    iVar6 = *piVar3;
  }
  if (iVar6 == 0) {
    local_24 = 0;
  }
  else if (*(uint *)(iVar6 + 0x84) < 8) {
    local_24 = iVar6 + 0x88 + *(uint *)(iVar6 + 0x84) * 0x84;
  }
  else {
    local_24 = 0;
  }
  local_14[0] = *(ushort *)(param_2 + 0x38);
  local_14[1] = *(undefined2 *)(param_2 + 0x3c);
  if (*(int *)(local_24 + 0x68) == 0) {
    local_14[2] = *(ushort *)(param_2 + 0x40) & 0xfdff;
  }
  else {
    local_14[2] = *(ushort *)(param_2 + 0x40) | 0x200;
  }
  local_14[2] = local_14[2] | *(ushort *)(local_24 + 0x70) & 0x7000;
  uVar2 = *(ushort *)(param_2 + 0x48);
  uVar8 = *(short *)(param_2 + 0x44) - 6;
  puVar7 = local_14;
  iVar6 = 6;
  *(code **)(param_1 + 0x74) = __analysis_fragment_001a22e0;
  do {
    *(ushort *)(in_FS_OFFSET + (uint)uVar8 + (uint)uVar2 * 0x10) = *puVar7;
    puVar7 = puVar7 + 1;
    uVar8 = uVar8 + 2;
    iVar6 = iVar6 + -2;
  } while (iVar6 != 0);
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(code **)(param_1 + 0x74) = __analysis_fragment_001a230c;
  uVar5 = *(uint *)(in_FS_OFFSET + (uint)local_5 * 4);
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(uint *)(param_2 + 0x44) = (uint)(ushort)(*(short *)(param_2 + 0x44) - 6);
  *(uint *)(param_2 + 0x38) = uVar5 & 0xffff;
  uStack_1a = (undefined2)(uVar5 >> 0x10);
  *(undefined2 *)(param_2 + 0x3c) = uStack_1a;
  *(undefined4 *)(local_24 + 0x68) = 0;
  if ((*(byte *)(local_24 + 0x80) & 1) == 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffeff;
  }
  return 1;
}

