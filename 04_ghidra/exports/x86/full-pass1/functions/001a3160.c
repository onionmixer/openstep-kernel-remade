/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a3160 */

undefined4 FUN_001a3160(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int in_FS_OFFSET;
  int local_50;
  undefined2 *local_4c;
  int local_44;
  undefined2 uStack_3e;
  undefined1 local_3c;
  undefined1 uStack_39;
  undefined2 local_38 [9];
  undefined2 uStack_26;
  undefined1 local_24;
  undefined1 uStack_21;
  undefined2 local_20 [6];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar9 = 0;
  if (piVar1 != (int *)0x0) {
    iVar9 = *piVar1;
  }
  if (iVar9 == 0) {
    local_44 = 0;
  }
  else if (*(uint *)(iVar9 + 0x84) < 8) {
    local_44 = iVar9 + 0x88 + *(uint *)(iVar9 + 0x84) * 0x84;
  }
  else {
    local_44 = 0;
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar9 = 0;
  if (piVar1 != (int *)0x0) {
    iVar9 = *piVar1;
  }
  if (*(uint *)(iVar9 + 0x34) <= (uint)(param_3 * 8)) {
    return 0;
  }
  iVar9 = *(int *)(iVar9 + 0x30) + param_3 * 8;
  *(undefined **)(param_1 + 0x74) = &DAT_001a3200;
  local_c = *(uint *)(in_FS_OFFSET + iVar9);
  uVar2 = *(uint *)(in_FS_OFFSET + iVar9 + 4);
  *(undefined4 *)(param_1 + 0x74) = 0;
  local_8._1_1_ = (byte)(uVar2 >> 8);
  bVar6 = local_8._1_1_ & 0x1f;
  if (bVar6 == 7) {
    bVar4 = false;
LAB_001a3262:
    bVar5 = false;
  }
  else if (bVar6 < 8) {
    if (bVar6 != 6) {
      return 0;
    }
    bVar4 = false;
    bVar5 = true;
  }
  else {
    if (bVar6 != 0xe) {
      if (bVar6 != 0xf) {
        return 0;
      }
      bVar4 = true;
      goto LAB_001a3262;
    }
    bVar4 = true;
    bVar5 = true;
  }
  if ((-1 < (char)local_8._1_1_) || ((local_c & 0x40000) == 0)) {
    return 0;
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar9 = 0;
  if (piVar1 != (int *)0x0) {
    iVar9 = *piVar1;
  }
  uVar8 = (local_c >> 0x13) * 8;
  if (*(uint *)(iVar9 + 0x3c) <= uVar8) {
    return 0;
  }
  iVar9 = uVar8 + *(int *)(iVar9 + 0x38);
  *(undefined **)(param_1 + 0x74) = &DAT_001a32dc;
  local_14 = *(undefined4 *)(in_FS_OFFSET + iVar9);
  uVar3 = *(undefined4 *)(in_FS_OFFSET + iVar9 + 4);
  *(undefined4 *)(param_1 + 0x74) = 0;
  local_10._1_1_ = (byte)((uint)uVar3 >> 8);
  if ((local_10._1_1_ & 0x18) != 0x18) {
    return 0;
  }
  if (-1 < (char)local_10._1_1_) {
    return 0;
  }
  local_8 = uVar2;
  if ((((param_5 == 0) && (7 < param_3)) && (param_3 != 0x10)) && (param_3 < 0x12)) {
    if (!bVar4) {
      local_10 = uVar3;
      iVar9 = FUN_001a2fc8(param_1,param_2,*(undefined4 *)(local_44 + 0x68),param_4);
      if (iVar9 == 0) {
        return 0;
      }
      goto LAB_001a376c;
    }
    if ((*(ushort *)(param_2 + 0x48) & 4) == 0) {
      return 0;
    }
    piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
    iVar9 = 0;
    if (piVar1 != (int *)0x0) {
      iVar9 = *piVar1;
    }
    uVar2 = (uint)(*(ushort *)(param_2 + 0x48) >> 3) * 8;
    if (*(uint *)(iVar9 + 0x3c) <= uVar2) {
      return 0;
    }
    iVar9 = uVar2 + *(int *)(iVar9 + 0x38);
    *(undefined **)(param_1 + 0x74) = &DAT_001a3660;
    uStack_3e = (undefined2)((uint)*(undefined4 *)(in_FS_OFFSET + iVar9) >> 0x10);
    uVar2 = *(uint *)(in_FS_OFFSET + iVar9 + 4);
    local_3c = (undefined1)uVar2;
    uStack_39 = (undefined1)(uVar2 >> 0x18);
    *(undefined4 *)(param_1 + 0x74) = 0;
    uVar10 = *(int *)(param_2 + 0x44) - 0x10;
    local_4c = local_38;
    local_50 = 0x10;
    uVar8 = 0xffff;
    if ((uVar2 & 0x400000) != 0) {
      uVar8 = 0xffffffff;
    }
    *(undefined **)(param_1 + 0x74) = &DAT_001a3718;
    do {
      *(undefined2 *)
       (in_FS_OFFSET + (uVar10 & uVar8) + CONCAT13(uStack_39,CONCAT12(local_3c,uStack_3e))) =
           *local_4c;
      local_4c = local_4c + 1;
      uVar10 = (uVar10 & uVar8) + 2;
      local_50 = local_50 + -2;
    } while (local_50 != 0);
    *(undefined4 *)(param_1 + 0x74) = 0;
    if ((uVar2 & 0x400000) != 0) {
      *(int *)(param_2 + 0x44) = *(int *)(param_2 + 0x44) + -0x10;
      goto LAB_001a376c;
    }
    uVar7 = *(short *)(param_2 + 0x44) - 0x10;
  }
  else {
    if (bVar4) {
      if ((*(ushort *)(param_2 + 0x48) & 4) == 0) {
        return 0;
      }
      piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
      iVar9 = 0;
      if (piVar1 != (int *)0x0) {
        iVar9 = *piVar1;
      }
      uVar2 = (uint)(*(ushort *)(param_2 + 0x48) >> 3) * 8;
      if (*(uint *)(iVar9 + 0x3c) <= uVar2) {
        return 0;
      }
      iVar9 = uVar2 + *(int *)(iVar9 + 0x38);
      *(undefined **)(param_1 + 0x74) = &DAT_001a339c;
      uStack_26 = (undefined2)((uint)*(undefined4 *)(in_FS_OFFSET + iVar9) >> 0x10);
      uVar2 = *(uint *)(in_FS_OFFSET + iVar9 + 4);
      local_24 = (undefined1)uVar2;
      uStack_21 = (undefined1)(uVar2 >> 0x18);
      *(undefined4 *)(param_1 + 0x74) = 0;
      uVar10 = *(int *)(param_2 + 0x44) - 0xc;
      local_4c = local_20;
      local_50 = 0xc;
      uVar8 = 0xffff;
      if ((uVar2 & 0x400000) != 0) {
        uVar8 = 0xffffffff;
      }
      *(undefined **)(param_1 + 0x74) = &DAT_001a3450;
      do {
        *(undefined2 *)
         (in_FS_OFFSET + (uVar10 & uVar8) + CONCAT13(uStack_21,CONCAT12(local_24,uStack_26))) =
             *local_4c;
        local_4c = local_4c + 1;
        uVar10 = (uVar10 & uVar8) + 2;
        local_50 = local_50 + -2;
      } while (local_50 != 0);
      *(undefined4 *)(param_1 + 0x74) = 0;
      if ((uVar2 & 0x400000) == 0) {
        *(uint *)(param_2 + 0x44) = (uint)(ushort)(*(short *)(param_2 + 0x44) - 0xc);
      }
      else {
        *(int *)(param_2 + 0x44) = *(int *)(param_2 + 0x44) + -0xc;
      }
      goto LAB_001a376c;
    }
    if ((*(ushort *)(param_2 + 0x48) & 4) == 0) {
      return 0;
    }
    piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
    iVar9 = 0;
    if (piVar1 != (int *)0x0) {
      iVar9 = *piVar1;
    }
    uVar2 = (uint)(*(ushort *)(param_2 + 0x48) >> 3) * 8;
    if (*(uint *)(iVar9 + 0x3c) <= uVar2) {
      return 0;
    }
    iVar9 = uVar2 + *(int *)(iVar9 + 0x38);
    *(undefined **)(param_1 + 0x74) = &DAT_001a34fc;
    uStack_26 = (undefined2)((uint)*(undefined4 *)(in_FS_OFFSET + iVar9) >> 0x10);
    uVar2 = *(uint *)(in_FS_OFFSET + iVar9 + 4);
    local_24 = (undefined1)uVar2;
    uStack_21 = (undefined1)(uVar2 >> 0x18);
    *(undefined4 *)(param_1 + 0x74) = 0;
    uVar10 = *(int *)(param_2 + 0x44) - 6;
    local_4c = local_20;
    local_50 = 6;
    uVar8 = 0xffff;
    if ((uVar2 & 0x400000) != 0) {
      uVar8 = 0xffffffff;
    }
    *(undefined **)(param_1 + 0x74) = &DAT_001a35b4;
    do {
      *(undefined2 *)
       (in_FS_OFFSET + (uVar10 & uVar8) + CONCAT13(uStack_21,CONCAT12(local_24,uStack_26))) =
           *local_4c;
      local_4c = local_4c + 1;
      uVar10 = (uVar10 & uVar8) + 2;
      local_50 = local_50 + -2;
    } while (local_50 != 0);
    *(undefined4 *)(param_1 + 0x74) = 0;
    if ((uVar2 & 0x400000) != 0) {
      *(int *)(param_2 + 0x44) = *(int *)(param_2 + 0x44) + -6;
      goto LAB_001a376c;
    }
    uVar7 = *(short *)(param_2 + 0x44) - 6;
  }
  *(uint *)(param_2 + 0x44) = (uint)uVar7;
LAB_001a376c:
  uVar2 = *(uint *)(local_44 + 0x80);
  *(uint *)(param_2 + 0x38) = local_c & 0xffff | local_8 & 0xffff0000;
  *(undefined2 *)(param_2 + 0x3c) = local_c._2_2_;
  if ((uVar2 & 1) == 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffeff;
  }
  if (bVar5) {
    *(undefined4 *)(local_44 + 0x68) = 0;
  }
  return 1;
}

