
undefined4 FUN_001a1d9c(int param_1,int param_2,short param_3)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int in_FS_OFFSET;
  
  piVar4 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar5 = 0;
  if (piVar4 != (int *)0x0) {
    iVar5 = *piVar4;
  }
  if ((iVar5 == 0) || (7 < *(uint *)(iVar5 + 0x84))) {
    iVar5 = 0;
  }
  else {
    iVar5 = iVar5 + 0x88 + *(uint *)(iVar5 + 0x84) * 0x84;
  }
  if (*(int *)(iVar5 + 0x68) == 0) {
    uVar6 = *(uint *)(param_2 + 0x40) & 0xfffffdff;
  }
  else {
    uVar6 = *(uint *)(param_2 + 0x40) | 0x200;
  }
  uVar1 = *(ushort *)(iVar5 + 0x70);
  sVar2 = *(short *)(param_2 + 0x44);
  uVar3 = *(ushort *)(param_2 + 0x48);
  *(code **)(param_1 + 0x74) = __analysis_fragment_001a1e2c;
  *(uint *)(in_FS_OFFSET + (uint)(ushort)(sVar2 - 4) + (uint)uVar3 * 0x10) = uVar6 | uVar1 & 0x7000;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(uint *)(param_2 + 0x38) = (uint)(ushort)(param_3 + 1 + *(short *)(param_2 + 0x38));
  *(uint *)(param_2 + 0x44) = (uint)(ushort)(*(short *)(param_2 + 0x44) - 4);
  return 1;
}

