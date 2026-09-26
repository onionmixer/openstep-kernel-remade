
undefined4 FUN_001a1b60(int param_1,undefined2 *param_2)

{
  int *piVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  ushort uVar5;
  int iVar6;
  undefined2 **ppuVar7;
  int in_FS_OFFSET;
  undefined2 *puStack_3c;
  undefined2 *puStack_38;
  undefined2 *local_24;
  undefined2 local_20 [6];
  ushort local_14;
  ushort local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar6 = 0;
  if (piVar1 != (int *)0x0) {
    iVar6 = *piVar1;
  }
  if (iVar6 == 0) {
    puVar2 = (undefined2 *)0x0;
  }
  else if (*(uint *)(iVar6 + 0x84) < 8) {
    puVar2 = (undefined2 *)(iVar6 + 0x88 + *(uint *)(iVar6 + 0x84) * 0x84);
  }
  else {
    puVar2 = (undefined2 *)0x0;
  }
  uVar5 = param_2[0x1c];
  local_c = param_2[0x1e];
  *(code **)(param_1 + 0x74) = __analysis_fragment_001a1bdc;
  uVar4 = *(undefined4 *)(in_FS_OFFSET + (uint)local_c * 0x10 + (uint)uVar5);
  *(undefined4 *)(param_1 + 0x74) = 0;
  local_8._0_2_ = (short)uVar4;
  if ((short)local_8 != -0x3b3c) {
    return 0;
  }
  local_8._2_1_ = (byte)((uint)uVar4 >> 0x10);
  local_8 = uVar4;
  if (local_8._2_1_ == 0xfe) {
    puStack_3c = (undefined2 *)0x1a1c01;
    puStack_38 = puVar2;
    _PCcancelTimers();
    *(undefined4 *)(puVar2 + 0x2c) = 4;
    ppuVar7 = &puStack_3c;
    puStack_3c = param_2;
  }
  else {
    if (local_8._2_1_ == 0xfa) {
      local_c = param_2[0x24];
      uVar5 = param_2[0x22];
      local_24 = local_20;
      iVar6 = 0x14;
      uVar3 = (uint)local_c;
      *(code **)(param_1 + 0x74) = __analysis_fragment_001a1c70;
      do {
        *local_24 = *(undefined2 *)(in_FS_OFFSET + (uint)uVar5 + uVar3 * 0x10);
        local_24 = local_24 + 1;
        uVar5 = uVar5 + 2;
        iVar6 = iVar6 + -2;
      } while (iVar6 != 0);
      *(undefined4 *)(param_1 + 0x74) = 0;
      puStack_38 = local_20;
      puStack_3c = param_2;
      uVar4 = _PCbopFA(param_1);
      return uVar4;
    }
    if (local_8._2_1_ == 0xfc) {
      local_14 = param_2[0x24];
      uVar5 = param_2[0x22];
      local_24 = local_20;
      iVar6 = 10;
      uVar3 = (uint)local_14;
      *(code **)(param_1 + 0x74) = __analysis_fragment_001a1ce8;
      do {
        *local_24 = *(undefined2 *)(in_FS_OFFSET + (uint)uVar5 + uVar3 * 0x10);
        local_24 = local_24 + 1;
        uVar5 = uVar5 + 2;
        iVar6 = iVar6 + -2;
      } while (iVar6 != 0);
      *(undefined4 *)(param_1 + 0x74) = 0;
      puStack_38 = local_20;
      puStack_3c = param_2;
      uVar4 = _PCbopFC(param_1);
      return uVar4;
    }
    if (local_8._2_1_ == 0xfd) {
      local_c = param_2[0x24];
      uVar5 = param_2[0x22];
      local_24 = local_20;
      iVar6 = 0x14;
      uVar3 = (uint)local_c;
      *(code **)(param_1 + 0x74) = __analysis_fragment_001a1d5c;
      do {
        *local_24 = *(undefined2 *)(in_FS_OFFSET + (uint)uVar5 + uVar3 * 0x10);
        local_24 = local_24 + 1;
        uVar5 = uVar5 + 2;
        iVar6 = iVar6 + -2;
      } while (iVar6 != 0);
      *(undefined4 *)(param_1 + 0x74) = 0;
      puStack_38 = local_20;
      puStack_3c = param_2;
      uVar4 = _PCbopFD(param_1);
      return uVar4;
    }
    *(uint *)(puVar2 + 0x26) = (uint)local_8._2_1_;
    *(undefined4 *)(puVar2 + 0x2c) = 3;
    ppuVar7 = &puStack_38;
    puStack_38 = param_2;
  }
  *(int *)((int)ppuVar7 + -4) = param_1;
  *(undefined4 *)((int)ppuVar7 + -8) = 0x1a1d91;
  uVar4 = _PCcallMonitor();
  return uVar4;
}

