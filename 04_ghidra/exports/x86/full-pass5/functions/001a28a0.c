/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a28a0 */

undefined4 FUN_001a28a0(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int in_FS_OFFSET;
  ushort local_6;
  
  if ((param_4 & 1) == 0) {
    piVar3 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
    iVar5 = 0;
    if (piVar3 != (int *)0x0) {
      iVar5 = *piVar3;
    }
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else if (*(uint *)(iVar5 + 0x84) < 8) {
      iVar5 = iVar5 + 0x88 + *(uint *)(iVar5 + 0x84) * 0x84;
    }
    else {
      iVar5 = 0;
    }
    uVar1 = *(ushort *)(param_2 + 0x44);
    uVar2 = *(ushort *)(param_2 + 0x48);
    *(code **)(param_1 + 0x74) = __analysis_fragment_001a2940;
    local_6 = *(ushort *)(in_FS_OFFSET + (uint)uVar2 * 0x10 + (uint)uVar1);
    *(undefined4 *)(param_1 + 0x74) = 0;
    if ((*(byte *)(iVar5 + 0x80) & 1) != 0) {
      local_6 = local_6 | *(ushort *)(param_2 + 0x40) & 0x100;
    }
    *(uint *)(param_2 + 0x40) = local_6 & 0xfd7 | 0x20202;
    *(uint *)(param_2 + 0x38) = (uint)(ushort)((short)param_3 + 1 + *(short *)(param_2 + 0x38));
    *(uint *)(param_2 + 0x44) = (uint)(ushort)(*(short *)(param_2 + 0x44) + 2);
    *(ushort *)(iVar5 + 0x70) = local_6 & 0x7000;
    if ((local_6 & 0x200) == 0) {
      *(undefined4 *)(iVar5 + 0x68) = 0;
    }
    else {
      if (*(int *)(iVar5 + 0x68) == 0) {
        *(uint *)(iVar5 + 0x74) = *(uint *)(iVar5 + 0x74) | *(uint *)(iVar5 + 0x5c) & 1;
      }
      *(undefined4 *)(iVar5 + 0x68) = 1;
    }
    uVar4 = 1;
  }
  else {
    uVar4 = FUN_001a1e70(param_1,param_2,param_3,param_4);
  }
  return uVar4;
}

