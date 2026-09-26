/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a3ac4 */

bool _PCemulatePROT(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_c;
  int local_8;
  
  if (*(int *)(param_2 + 0x30) == 0xd) {
    iVar2 = FUN_001a37c0(param_1,param_2);
    if (iVar2 != 0) {
      return true;
    }
    piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
    local_c = 0;
    if (piVar1 != (int *)0x0) {
      local_c = *piVar1;
    }
    if (*(uint *)(local_c + 0x84) < 8) {
      local_8 = local_c + 0x88 + *(uint *)(local_c + 0x84) * 0x84;
    }
    else {
      local_8 = 0;
    }
    uVar4 = *(uint *)(param_2 + 0x30);
    if (uVar4 < 0x20) goto LAB_001a3c85;
LAB_001a3c9c:
    uVar3 = uVar4;
    if ((int)uVar4 < 0) {
      uVar3 = uVar4 + 7;
    }
    uVar4 = (int)(uint)*(byte *)(((int)uVar3 >> 3) + local_c + 4) >>
            ((char)uVar4 - (char)(((int)uVar3 >> 3) << 3) & 0x1fU) & 1;
  }
  else {
    if (*(int *)(param_2 + 0x30) == 6) {
      iVar2 = FUN_001a2b40(param_1,param_2);
      if (iVar2 != 0) {
        return true;
      }
      piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
      local_c = 0;
      if (piVar1 != (int *)0x0) {
        local_c = *piVar1;
      }
      if (*(uint *)(local_c + 0x84) < 8) {
        local_8 = local_c + 0x88 + *(uint *)(local_c + 0x84) * 0x84;
      }
      else {
        local_8 = 0;
      }
      uVar4 = *(uint *)(param_2 + 0x30);
      bVar5 = (byte)uVar4;
      if (uVar4 < 0x20) {
        uVar4 = (uint)((*(uint *)(local_c + 4) & 1 << (bVar5 & 0x1f)) != 0);
      }
      else {
        if ((int)uVar4 < 0) {
          uVar4 = uVar4 + 7;
        }
        uVar4 = (int)(uint)*(byte *)(((int)uVar4 >> 3) + local_c + 4) >>
                (bVar5 - (char)(((int)uVar4 >> 3) << 3) & 0x1f) & 1;
      }
      if (uVar4 != 0) {
        *(undefined4 *)(local_8 + 0x4c) = *(undefined4 *)(param_2 + 0x30);
        *(undefined4 *)(local_8 + 0x50) = *(undefined4 *)(param_2 + 0x34);
        *(undefined4 *)(local_8 + 0x58) = 1;
        _PCcallMonitor(param_1,param_2);
      }
      uVar7 = *(undefined4 *)(param_2 + 0x34);
      uVar6 = *(undefined4 *)(param_2 + 0x30);
      goto LAB_001a3cee;
    }
    piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
    local_c = 0;
    if (piVar1 != (int *)0x0) {
      local_c = *piVar1;
    }
    if (*(uint *)(local_c + 0x84) < 8) {
      local_8 = local_c + 0x88 + *(uint *)(local_c + 0x84) * 0x84;
    }
    else {
      local_8 = 0;
    }
    uVar4 = *(uint *)(param_2 + 0x30);
    if (0x1f < uVar4) goto LAB_001a3c9c;
LAB_001a3c85:
    uVar4 = (uint)((*(uint *)(local_c + 4) & 1 << ((byte)uVar4 & 0x1f)) != 0);
  }
  if (uVar4 != 0) {
    *(undefined4 *)(local_8 + 0x4c) = *(undefined4 *)(param_2 + 0x30);
    *(undefined4 *)(local_8 + 0x50) = *(undefined4 *)(param_2 + 0x34);
    *(undefined4 *)(local_8 + 0x58) = 1;
    _PCcallMonitor(param_1,param_2);
  }
  uVar7 = *(undefined4 *)(param_2 + 0x34);
  uVar6 = *(undefined4 *)(param_2 + 0x30);
LAB_001a3cee:
  iVar2 = FUN_001a3160(param_1,param_2,uVar6,uVar7,0);
  return iVar2 != 0;
}

