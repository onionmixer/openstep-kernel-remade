/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a1f8c */

undefined4 FUN_001a1f8c(int param_1,int param_2)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_FS_OFFSET;
  ushort local_18;
  undefined4 local_10;
  undefined2 local_c;
  uint local_8;
  
  piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar3 = 0;
  if (piVar2 != (int *)0x0) {
    iVar3 = *piVar2;
  }
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else if (*(uint *)(iVar3 + 0x84) < 8) {
    iVar3 = iVar3 + 0x88 + *(uint *)(iVar3 + 0x84) * 0x84;
  }
  else {
    iVar3 = 0;
  }
  uVar1 = *(ushort *)(param_2 + 0x48);
  local_18 = *(ushort *)(param_2 + 0x44);
  puVar4 = &local_10;
  iVar5 = 0xc;
  *(undefined **)(param_1 + 0x74) = &DAT_001a202c;
  do {
    *(undefined2 *)puVar4 = *(undefined2 *)(in_FS_OFFSET + (uint)local_18 + (uint)uVar1 * 0x10);
    puVar4 = (undefined4 *)((int)puVar4 + 2);
    local_18 = local_18 + 2;
    iVar5 = iVar5 + -2;
  } while (iVar5 != 0);
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_2 + 0x38) = local_10;
  *(undefined2 *)(param_2 + 0x3c) = local_c;
  if ((*(byte *)(iVar3 + 0x80) & 1) != 0) {
    local_8 = local_8 | *(uint *)(param_2 + 0x40) & 0x100;
  }
  *(uint *)(param_2 + 0x40) = local_8;
  *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0x70fd7 | 0x20202;
  *(uint *)(param_2 + 0x44) = (uint)(ushort)(*(short *)(param_2 + 0x44) + 0xc);
  *(ushort *)(iVar3 + 0x70) = (ushort)local_8 & 0x7000;
  if ((local_8 & 0x200) == 0) {
    *(undefined4 *)(iVar3 + 0x68) = 0;
  }
  else {
    if (*(int *)(iVar3 + 0x68) == 0) {
      *(uint *)(iVar3 + 0x74) = *(uint *)(iVar3 + 0x74) | *(uint *)(iVar3 + 0x5c) & 1;
    }
    *(undefined4 *)(iVar3 + 0x68) = 1;
  }
  return 1;
}

