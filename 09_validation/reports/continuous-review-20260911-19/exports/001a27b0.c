
undefined4 FUN_001a27b0(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  int *piVar4;
  undefined4 uVar5;
  ushort uVar6;
  int iVar7;
  int in_FS_OFFSET;
  
  if ((param_4 & 1) == 0) {
    piVar4 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
    iVar7 = 0;
    if (piVar4 != (int *)0x0) {
      iVar7 = *piVar4;
    }
    if ((iVar7 == 0) || (7 < *(uint *)(iVar7 + 0x84))) {
      iVar7 = 0;
    }
    else {
      iVar7 = iVar7 + 0x88 + *(uint *)(iVar7 + 0x84) * 0x84;
    }
    if (*(int *)(iVar7 + 0x68) == 0) {
      uVar6 = *(ushort *)(param_2 + 0x40) & 0xfdff;
    }
    else {
      uVar6 = *(ushort *)(param_2 + 0x40) | 0x200;
    }
    uVar1 = *(ushort *)(iVar7 + 0x70);
    sVar2 = *(short *)(param_2 + 0x44);
    uVar3 = *(ushort *)(param_2 + 0x48);
    *(code **)(param_1 + 0x74) = __analysis_fragment_001a2860;
    *(ushort *)(in_FS_OFFSET + (uint)(ushort)(sVar2 - 2) + (uint)uVar3 * 0x10) =
         uVar6 | uVar1 & 0x7000;
    *(undefined4 *)(param_1 + 0x74) = 0;
    *(uint *)(param_2 + 0x38) = (uint)(ushort)((short)param_3 + 1 + *(short *)(param_2 + 0x38));
    *(uint *)(param_2 + 0x44) = (uint)(ushort)(*(short *)(param_2 + 0x44) - 2);
    uVar5 = 1;
  }
  else {
    uVar5 = FUN_001a1d9c(param_1,param_2,param_3,param_4);
  }
  return uVar5;
}

