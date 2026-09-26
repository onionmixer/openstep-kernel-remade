/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a1e70 */

undefined4 FUN_001a1e70(int param_1,int param_2,short param_3)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  int in_FS_OFFSET;
  uint local_8;
  
  piVar3 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar4 = 0;
  if (piVar3 != (int *)0x0) {
    iVar4 = *piVar3;
  }
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else if (*(uint *)(iVar4 + 0x84) < 8) {
    iVar4 = iVar4 + 0x88 + *(uint *)(iVar4 + 0x84) * 0x84;
  }
  else {
    iVar4 = 0;
  }
  uVar1 = *(ushort *)(param_2 + 0x44);
  uVar2 = *(ushort *)(param_2 + 0x48);
  *(undefined **)(param_1 + 0x74) = &DAT_001a1eec;
  local_8 = *(uint *)(in_FS_OFFSET + (uint)uVar2 * 0x10 + (uint)uVar1);
  *(undefined4 *)(param_1 + 0x74) = 0;
  if ((*(byte *)(iVar4 + 0x80) & 1) != 0) {
    local_8 = local_8 | *(uint *)(param_2 + 0x40) & 0x100;
  }
  *(uint *)(param_2 + 0x40) = local_8;
  *(uint *)(param_2 + 0x40) = local_8 & 0x70fd7 | 0x20202;
  *(uint *)(param_2 + 0x38) = (uint)(ushort)(param_3 + 1 + *(short *)(param_2 + 0x38));
  *(uint *)(param_2 + 0x44) = (uint)(ushort)(*(short *)(param_2 + 0x44) + 4);
  *(ushort *)(iVar4 + 0x70) = (ushort)local_8 & 0x7000;
  if ((local_8 & 0x200) == 0) {
    *(undefined4 *)(iVar4 + 0x68) = 0;
  }
  else {
    if (*(int *)(iVar4 + 0x68) == 0) {
      *(uint *)(iVar4 + 0x74) = *(uint *)(iVar4 + 0x74) | *(uint *)(iVar4 + 0x5c) & 1;
    }
    *(undefined4 *)(iVar4 + 0x68) = 1;
  }
  return 1;
}

