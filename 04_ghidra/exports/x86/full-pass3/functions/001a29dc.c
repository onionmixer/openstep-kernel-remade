/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a29dc */

undefined4 FUN_001a29dc(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  ushort uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  int in_FS_OFFSET;
  ushort local_14;
  ushort local_c [4];
  
  if ((param_4 & 1) == 0) {
    piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
    iVar4 = 0;
    if (piVar2 != (int *)0x0) {
      iVar4 = *piVar2;
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
    uVar1 = *(ushort *)(param_2 + 0x48);
    local_14 = *(ushort *)(param_2 + 0x44);
    puVar5 = local_c;
    iVar6 = 6;
    *(undefined **)(param_1 + 0x74) = &DAT_001a2a9c;
    do {
      *puVar5 = *(ushort *)(in_FS_OFFSET + (uint)local_14 + (uint)uVar1 * 0x10);
      puVar5 = puVar5 + 1;
      local_14 = local_14 + 2;
      iVar6 = iVar6 + -2;
    } while (iVar6 != 0);
    *(undefined4 *)(param_1 + 0x74) = 0;
    *(uint *)(param_2 + 0x38) = (uint)local_c[0];
    *(ushort *)(param_2 + 0x3c) = local_c[1];
    if ((*(byte *)(iVar4 + 0x80) & 1) != 0) {
      local_c[2] = local_c[2] | *(ushort *)(param_2 + 0x40) & 0x100;
    }
    *(uint *)(param_2 + 0x40) = local_c[2] & 0xfd7 | 0x20202;
    *(uint *)(param_2 + 0x44) = (uint)(ushort)(*(short *)(param_2 + 0x44) + 6);
    *(ushort *)(iVar4 + 0x70) = local_c[2] & 0x7000;
    if ((local_c[2] & 0x200) == 0) {
      *(undefined4 *)(iVar4 + 0x68) = 0;
    }
    else {
      if (*(int *)(iVar4 + 0x68) == 0) {
        *(uint *)(iVar4 + 0x74) = *(uint *)(iVar4 + 0x74) | *(uint *)(iVar4 + 0x5c) & 1;
      }
      *(undefined4 *)(iVar4 + 0x68) = 1;
    }
    uVar3 = 1;
  }
  else {
    uVar3 = FUN_001a1f8c(param_1,param_2,param_3,param_4);
  }
  return uVar3;
}

