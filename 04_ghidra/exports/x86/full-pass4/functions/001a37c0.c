/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a37c0 */

/* WARNING: Removing unreachable block (ram,0x001a3926) */

undefined4 FUN_001a37c0(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int in_FS_OFFSET;
  int local_2c;
  byte bStack_13;
  char local_10;
  undefined2 uStack_a;
  undefined1 local_8;
  undefined1 uStack_5;
  
  if ((*(ushort *)(param_2 + 0x3c) & 4) != 0) {
    piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
    iVar5 = 0;
    if (piVar2 != (int *)0x0) {
      iVar5 = *piVar2;
    }
    uVar1 = (uint)(*(ushort *)(param_2 + 0x3c) >> 3) * 8;
    if (uVar1 < *(uint *)(iVar5 + 0x3c)) {
      iVar5 = uVar1 + *(int *)(iVar5 + 0x38);
      *(code **)(param_1 + 0x74) = __analysis_fragment_001a3834;
      uStack_a = (undefined2)((uint)*(undefined4 *)(in_FS_OFFSET + iVar5) >> 0x10);
      uVar1 = *(uint *)(in_FS_OFFSET + iVar5 + 4);
      local_8 = (undefined1)uVar1;
      uStack_5 = (undefined1)(uVar1 >> 0x18);
      *(undefined4 *)(param_1 + 0x74) = 0;
      uVar6 = *(uint *)(param_2 + 0x38);
      if ((uVar1 & 0x400000) == 0) {
        uVar6 = uVar6 & 0xffff;
      }
      *(code **)(param_1 + 0x74) = __analysis_fragment_001a388c;
      uVar3 = *(undefined4 *)(in_FS_OFFSET + CONCAT13(uStack_5,CONCAT12(local_8,uStack_a)) + uVar6);
      *(undefined4 *)(param_1 + 0x74) = 0;
      local_10 = (char)uVar3;
      if (local_10 == -0x33) {
        piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
        local_2c = 0;
        if (piVar2 != (int *)0x0) {
          local_2c = *piVar2;
        }
        if (*(uint *)(local_2c + 0x84) < 8) {
          iVar5 = local_2c + 0x88 + *(uint *)(local_2c + 0x84) * 0x84;
        }
        else {
          iVar5 = 0;
        }
        bStack_13 = (byte)((uint)uVar3 >> 8);
        if (bStack_13 < 0x20) {
          uVar6 = (uint)((*(uint *)(local_2c + 8) & 1 << (bStack_13 & 0x1f)) != 0);
        }
        else {
          iVar4 = (int)(uint)bStack_13 >> 3;
          uVar6 = (int)(uint)*(byte *)(iVar4 + local_2c + 8) >>
                  (bStack_13 - (char)(iVar4 << 3) & 0x1f) & 1;
        }
        if (uVar6 != 0) {
          *(uint *)(iVar5 + 0x4c) = (uint)bStack_13;
          *(undefined4 *)(iVar5 + 0x50) = 0;
          if (bStack_13 < 8) {
            *(undefined4 *)(iVar5 + 0x58) = 1;
          }
          else {
            *(undefined4 *)(iVar5 + 0x58) = 2;
          }
          _PCcallMonitor(param_1,param_2);
        }
        if ((uVar1 & 0x400000) == 0) {
          *(uint *)(param_2 + 0x38) = (uint)(ushort)(*(short *)(param_2 + 0x38) + 2);
        }
        else {
          *(int *)(param_2 + 0x38) = *(int *)(param_2 + 0x38) + 2;
        }
        iVar5 = FUN_001a3160(param_1,param_2,bStack_13,0,1);
        if (iVar5 == 0) {
          if ((uVar1 & 0x400000) != 0) {
            *(int *)(param_2 + 0x38) = *(int *)(param_2 + 0x38) + -2;
            return 0;
          }
          *(uint *)(param_2 + 0x38) = (uint)(ushort)(*(short *)(param_2 + 0x38) - 2);
          return 0;
        }
      }
      else if (local_10 == -6) {
        piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
        iVar5 = 0;
        if (piVar2 != (int *)0x0) {
          iVar5 = *piVar2;
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
        if ((uVar1 & 0x400000) == 0) {
          *(uint *)(param_2 + 0x38) = (uint)(ushort)(*(short *)(param_2 + 0x38) + 1);
        }
        else {
          *(int *)(param_2 + 0x38) = *(int *)(param_2 + 0x38) + 1;
        }
        *(undefined4 *)(iVar5 + 0x68) = 0;
      }
      else {
        if (local_10 != -5) {
          return 0;
        }
        piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
        iVar5 = 0;
        if (piVar2 != (int *)0x0) {
          iVar5 = *piVar2;
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
        if ((uVar1 & 0x400000) == 0) {
          *(uint *)(param_2 + 0x38) = (uint)(ushort)(*(short *)(param_2 + 0x38) + 1);
        }
        else {
          *(int *)(param_2 + 0x38) = *(int *)(param_2 + 0x38) + 1;
        }
        if (*(int *)(iVar5 + 0x68) == 0) {
          *(undefined4 *)(iVar5 + 0x68) = 1;
          *(uint *)(iVar5 + 0x74) = *(uint *)(iVar5 + 0x74) | *(uint *)(iVar5 + 0x5c) & 1;
        }
      }
      return 1;
    }
  }
  return 0;
}

