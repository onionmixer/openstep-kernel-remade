/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a2b40 */

undefined4 FUN_001a2b40(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined2 **ppuVar8;
  int in_FS_OFFSET;
  undefined2 *puStack_40;
  undefined2 uStack_2a;
  undefined1 local_28;
  undefined1 uStack_25;
  undefined2 local_24 [10];
  undefined4 local_10;
  undefined2 local_c;
  undefined2 uStack_a;
  undefined1 local_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  
  ppuVar8 = (undefined2 **)&stack0xffffffc4;
  piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  iVar6 = 0;
  if (piVar2 != (int *)0x0) {
    iVar6 = *piVar2;
  }
  if (iVar6 == 0) {
    puVar3 = (undefined2 *)0x0;
  }
  else if (*(uint *)(iVar6 + 0x84) < 8) {
    puVar3 = (undefined2 *)(iVar6 + 0x88 + *(uint *)(iVar6 + 0x84) * 0x84);
  }
  else {
    puVar3 = (undefined2 *)0x0;
  }
  if ((*(ushort *)(param_2 + 0x3c) & 4) != 0) {
    piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
    iVar6 = 0;
    if (piVar2 != (int *)0x0) {
      iVar6 = *piVar2;
    }
    uVar1 = (uint)(*(ushort *)(param_2 + 0x3c) >> 3) * 8;
    if (uVar1 < *(uint *)(iVar6 + 0x3c)) {
      iVar6 = uVar1 + *(int *)(iVar6 + 0x38);
      *(undefined **)(param_1 + 0x74) = &DAT_001a2bf0;
      uVar5 = *(undefined4 *)(in_FS_OFFSET + iVar6);
      local_c = (undefined2)uVar5;
      uStack_a = (undefined2)((uint)uVar5 >> 0x10);
      uVar1 = *(uint *)(in_FS_OFFSET + iVar6 + 4);
      local_8 = (undefined1)uVar1;
      uStack_7 = (undefined1)(uVar1 >> 8);
      uStack_6 = (undefined1)(uVar1 >> 0x10);
      uStack_5 = (undefined1)(uVar1 >> 0x18);
      *(undefined4 *)(param_1 + 0x74) = 0;
      uVar7 = *(uint *)(param_2 + 0x38);
      if ((uVar1 & 0x400000) == 0) {
        uVar7 = uVar7 & 0xffff;
      }
      *(undefined **)(param_1 + 0x74) = &DAT_001a2c4c;
      uVar5 = *(undefined4 *)(in_FS_OFFSET + CONCAT13(uStack_5,CONCAT12(local_8,uStack_a)) + uVar7);
      *(undefined4 *)(param_1 + 0x74) = 0;
      local_10._0_2_ = (short)uVar5;
      if ((short)local_10 == -0x3b3c) {
        local_10._2_1_ = (byte)((uint)uVar5 >> 0x10);
        local_10 = uVar5;
        if (local_10._2_1_ == 0xfe) {
          ppuVar8 = &puStack_40;
          puStack_40 = puVar3;
          _PCcancelTimers();
          *(undefined4 *)(puVar3 + 0x2c) = 4;
LAB_001a2faf:
          *(int *)((int)ppuVar8 + -4) = param_2;
          *(int *)((int)ppuVar8 + -8) = param_1;
          *(undefined4 *)((int)ppuVar8 + -0xc) = 0x1a2fbc;
          uVar5 = _PCcallMonitor();
          return uVar5;
        }
        if (local_10._2_1_ == 0xfa) {
          if ((*(ushort *)(param_2 + 0x48) & 4) != 0) {
            piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
            iVar6 = 0;
            if (piVar2 != (int *)0x0) {
              iVar6 = *piVar2;
            }
            uVar1 = (uint)(*(ushort *)(param_2 + 0x48) >> 3) * 8;
            if (uVar1 < *(uint *)(iVar6 + 0x3c)) {
              iVar6 = uVar1 + *(int *)(iVar6 + 0x38);
              *(undefined **)(param_1 + 0x74) = &DAT_001a2cf0;
              uStack_2a = (undefined2)((uint)*(undefined4 *)(in_FS_OFFSET + iVar6) >> 0x10);
              uVar1 = *(uint *)(in_FS_OFFSET + iVar6 + 4);
              local_28 = (undefined1)uVar1;
              uStack_25 = (undefined1)(uVar1 >> 0x18);
              *(undefined4 *)(param_1 + 0x74) = 0;
              uVar7 = *(uint *)(param_2 + 0x44);
              puVar3 = local_24;
              iVar6 = 0x14;
              uVar4 = 0xffff;
              if ((uVar1 & 0x400000) != 0) {
                uVar4 = 0xffffffff;
              }
              *(undefined **)(param_1 + 0x74) = &DAT_001a2d68;
              do {
                *puVar3 = *(undefined2 *)
                           (in_FS_OFFSET +
                           (uVar7 & uVar4) + CONCAT13(uStack_25,CONCAT12(local_28,uStack_2a)));
                puVar3 = puVar3 + 1;
                uVar7 = (uVar7 & uVar4) + 2;
                iVar6 = iVar6 + -2;
              } while (iVar6 != 0);
              *(undefined4 *)(param_1 + 0x74) = 0;
              puStack_40 = local_24;
              uVar5 = _PCbopFA(param_1,param_2);
              return uVar5;
            }
          }
        }
        else if (local_10._2_1_ == 0xfc) {
          if ((*(ushort *)(param_2 + 0x48) & 4) != 0) {
            piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
            iVar6 = 0;
            if (piVar2 != (int *)0x0) {
              iVar6 = *piVar2;
            }
            uVar1 = (uint)(*(ushort *)(param_2 + 0x48) >> 3) * 8;
            if (uVar1 < *(uint *)(iVar6 + 0x3c)) {
              iVar6 = uVar1 + *(int *)(iVar6 + 0x38);
              *(undefined **)(param_1 + 0x74) = &DAT_001a2dfc;
              uStack_2a = (undefined2)((uint)*(undefined4 *)(in_FS_OFFSET + iVar6) >> 0x10);
              uVar1 = *(uint *)(in_FS_OFFSET + iVar6 + 4);
              local_28 = (undefined1)uVar1;
              uStack_25 = (undefined1)(uVar1 >> 0x18);
              *(undefined4 *)(param_1 + 0x74) = 0;
              uVar7 = *(uint *)(param_2 + 0x44);
              puVar3 = local_24;
              iVar6 = 10;
              uVar4 = 0xffff;
              if ((uVar1 & 0x400000) != 0) {
                uVar4 = 0xffffffff;
              }
              *(undefined **)(param_1 + 0x74) = &DAT_001a2e74;
              do {
                *puVar3 = *(undefined2 *)
                           (in_FS_OFFSET +
                           (uVar7 & uVar4) + CONCAT13(uStack_25,CONCAT12(local_28,uStack_2a)));
                puVar3 = puVar3 + 1;
                uVar7 = (uVar7 & uVar4) + 2;
                iVar6 = iVar6 + -2;
              } while (iVar6 != 0);
              *(undefined4 *)(param_1 + 0x74) = 0;
              puStack_40 = local_24;
              uVar5 = _PCbopFC(param_1,param_2);
              return uVar5;
            }
          }
        }
        else {
          if (local_10._2_1_ != 0xfd) {
            *(uint *)(puVar3 + 0x26) = (uint)local_10._2_1_;
            *(undefined4 *)(puVar3 + 0x2c) = 3;
            goto LAB_001a2faf;
          }
          if ((*(ushort *)(param_2 + 0x48) & 4) != 0) {
            piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
            iVar6 = 0;
            if (piVar2 != (int *)0x0) {
              iVar6 = *piVar2;
            }
            uVar1 = (uint)(*(ushort *)(param_2 + 0x48) >> 3) * 8;
            if (uVar1 < *(uint *)(iVar6 + 0x3c)) {
              iVar6 = uVar1 + *(int *)(iVar6 + 0x38);
              *(undefined **)(param_1 + 0x74) = &DAT_001a2f08;
              uStack_2a = (undefined2)((uint)*(undefined4 *)(in_FS_OFFSET + iVar6) >> 0x10);
              uVar1 = *(uint *)(in_FS_OFFSET + iVar6 + 4);
              local_28 = (undefined1)uVar1;
              uStack_25 = (undefined1)(uVar1 >> 0x18);
              *(undefined4 *)(param_1 + 0x74) = 0;
              uVar7 = *(uint *)(param_2 + 0x44);
              puVar3 = local_24;
              iVar6 = 0x14;
              uVar4 = 0xffff;
              if ((uVar1 & 0x400000) != 0) {
                uVar4 = 0xffffffff;
              }
              *(undefined **)(param_1 + 0x74) = &DAT_001a2f7c;
              do {
                *puVar3 = *(undefined2 *)
                           (in_FS_OFFSET +
                           (uVar7 & uVar4) + CONCAT13(uStack_25,CONCAT12(local_28,uStack_2a)));
                puVar3 = puVar3 + 1;
                uVar7 = (uVar7 & uVar4) + 2;
                iVar6 = iVar6 + -2;
              } while (iVar6 != 0);
              *(undefined4 *)(param_1 + 0x74) = 0;
              puStack_40 = local_24;
              uVar5 = _PCbopFD(param_1,param_2);
              return uVar5;
            }
          }
        }
      }
    }
  }
  return 0;
}

