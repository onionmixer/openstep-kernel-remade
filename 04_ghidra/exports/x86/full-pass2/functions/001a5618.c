/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a5618 */

void __IOCopyMemory(undefined4 *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  if (param_2 == (undefined4 *)0x0) {
    return;
  }
  if (param_1 == param_2) {
    return;
  }
  if (param_3 == 0) {
    return;
  }
  if (param_4 == 0) {
    param_4 = 1;
  }
  if (2 < param_4) {
    param_4 = 4;
  }
  if (param_4 == 1) {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)param_2 = *(undefined1 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
    return;
  }
  uVar5 = (uint)param_1 & param_4 - 1;
  if (uVar5 != 0) {
    iVar3 = param_4 - uVar5;
    puVar6 = param_1;
    puVar7 = param_2;
    for (iVar4 = iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    param_3 = param_3 - iVar3;
    param_2 = (undefined4 *)((int)param_2 + iVar3);
    param_1 = (undefined4 *)((int)param_1 + iVar3);
  }
  if (param_4 == 2) {
    puVar6 = param_1;
    puVar7 = param_2;
    for (iVar4 = (int)param_3 >> 1; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined2 *)puVar7 = *(undefined2 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 2);
      puVar7 = (undefined4 *)((int)puVar7 + 2);
    }
  }
  else {
    puVar6 = param_1;
    puVar7 = param_2;
    for (iVar4 = (int)param_3 >> 2; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
  }
  uVar5 = param_3 & param_4 - 1;
  if (uVar5 == 0) {
    return;
  }
  param_3 = ~(param_4 - 1) & param_3;
  puVar1 = (undefined1 *)((int)param_1 + param_3);
  puVar2 = (undefined1 *)((int)param_2 + param_3);
  if (uVar5 != 2) {
    if ((int)uVar5 < 3) {
      if (uVar5 != 1) {
        return;
      }
      goto LAB_001a56fd;
    }
    if (uVar5 != 3) {
      return;
    }
    puVar2[2] = puVar1[2];
  }
  puVar2[1] = puVar1[1];
LAB_001a56fd:
  *puVar2 = *puVar1;
  return;
}

