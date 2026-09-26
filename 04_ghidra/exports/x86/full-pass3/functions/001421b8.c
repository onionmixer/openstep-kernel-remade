/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001421b8 */

undefined4 FUN_001421b8(byte *param_1)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int local_10;
  int local_c;
  byte *local_8;
  
  while (iVar3 = FUN_001425a4(param_1), iVar3 != 0) {
    local_10 = 0;
    if ((*param_1 & 1) != 0) {
      FUN_0014286c(param_1);
      return 0xb;
    }
    iVar5 = *(int *)(iVar3 + 0xc);
    while ((*(int *)(iVar5 + 0x14) != 0 && (local_10 < 0x32))) {
      iVar5 = *(int *)(*(int *)(*(int *)(iVar5 + 0x14) + 0x14) + 0xc);
      local_10 = local_10 + 1;
      if (*(int *)(param_1 + 0xc) == iVar5) {
        FUN_0014286c(param_1);
        return 0x4e;
      }
    }
    *(int *)(param_1 + 0x14) = iVar3;
    FUN_00142754(iVar3,param_1);
    *(byte **)(*(int *)(param_1 + 0xc) + 0x14) = param_1;
    uVar4 = _sleep((uint)param_1);
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14) = 0;
    if (uVar4 != 0) {
      FUN_00142780(iVar3,param_1);
      FUN_0014286c(param_1);
      return 4;
    }
  }
  local_8 = (byte *)(*(int *)(param_1 + 0x10) + 4);
  uVar6 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
  bVar2 = true;
LAB_0014229c:
  iVar3 = FUN_00142600(uVar6,param_1,1,&local_8,&local_c);
  if (iVar3 != 0) {
    uVar6 = *(undefined4 *)(local_c + 0x14);
  }
  switch(iVar3) {
  case 0:
    if (!bVar2) {
      return 0;
    }
    *(byte **)local_8 = param_1;
    *(int *)(param_1 + 0x14) = local_c;
    return 0;
  case 1:
    if ((*(short *)(param_1 + 2) == 1) && (*(short *)(local_c + 2) == 2)) {
      FUN_0014282c(local_c);
    }
    *(undefined2 *)(local_c + 2) = *(undefined2 *)(param_1 + 2);
    break;
  case 2:
    if (*(short *)(local_c + 2) != *(short *)(param_1 + 2)) {
      if (*(int *)(local_c + 4) == *(int *)(param_1 + 4)) {
        *(byte **)local_8 = param_1;
        *(int *)(param_1 + 0x14) = local_c;
        *(int *)(local_c + 4) = *(int *)(param_1 + 8) + 1;
      }
      else {
        FUN_001427b4(local_c,param_1);
      }
      goto LAB_00142422;
    }
    break;
  case 3:
    if ((*(short *)(param_1 + 2) == 1) && (*(short *)(local_c + 2) == 2)) {
      FUN_0014282c(local_c);
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(local_c + 0x18);
      FUN_00142754(param_1,uVar1);
    }
    if (bVar2) {
      *(byte **)local_8 = param_1;
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(local_c + 0x14);
      local_8 = param_1 + 0x14;
      bVar2 = false;
    }
    else {
      *(undefined4 *)local_8 = *(undefined4 *)(local_c + 0x14);
    }
    FUN_0014286c(local_c);
    goto LAB_0014229c;
  case 4:
    goto switchD_001422c5_caseD_4;
  case 5:
    if (bVar2) {
      *(byte **)local_8 = param_1;
      *(int *)(param_1 + 0x14) = local_c;
    }
    *(int *)(local_c + 4) = *(int *)(param_1 + 8) + 1;
LAB_00142422:
    FUN_0014282c(local_c);
    return 0;
  default:
    return 0;
  }
  FUN_0014286c(param_1);
  return 0;
switchD_001422c5_caseD_4:
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(local_c + 0x14);
  *(byte **)(local_c + 0x14) = param_1;
  *(int *)(local_c + 8) = *(int *)(param_1 + 4) + -1;
  local_8 = param_1 + 0x14;
  FUN_0014282c(local_c);
  bVar2 = false;
  goto LAB_0014229c;
}

