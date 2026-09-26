/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00101504 */

void * _memmove(void *param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  pvVar1 = param_1;
  if ((param_2 < param_1) && (puVar7 = (undefined4 *)(param_3 + (int)param_2), param_1 < puVar7)) {
    param_1 = (void *)((int)param_1 + param_3);
    if (0x10 < (int)param_3) {
      uVar5 = (uint)puVar7 & 3;
      uVar4 = uVar5;
      puVar6 = param_1;
      puVar9 = puVar7;
      if (uVar5 != 0) {
        while( true ) {
          if (uVar4 == 0) break;
          puVar6[-1] = *(undefined1 *)((int)puVar9 - 1U);
          uVar4 = uVar4 - 1;
          puVar6 = puVar6 + -1;
          puVar9 = (undefined4 *)((int)puVar9 - 1U);
        }
        param_3 = param_3 - uVar5;
        param_1 = (void *)((int)param_1 + -uVar5);
        puVar7 = (undefined4 *)((int)puVar7 - uVar5);
      }
      iVar3 = (int)param_3 >> 2;
      puVar9 = puVar7;
      puVar10 = param_1;
      while( true ) {
        puVar10 = puVar10 + -1;
        puVar9 = puVar9 + -1;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        *puVar10 = *puVar9;
      }
      if ((param_3 & 3) == 0) {
        return pvVar1;
      }
      puVar7 = (undefined4 *)((int)puVar7 - (param_3 & 0xfffffffc));
      param_1 = (void *)((int)param_1 - (param_3 & 0xfffffffc));
      param_3 = param_3 & 3;
    }
    while( true ) {
      param_1 = (void *)((int)param_1 + -1);
      puVar7 = (undefined4 *)((int)puVar7 - 1);
      if (param_3 == 0) break;
      *(undefined1 *)param_1 = *(undefined1 *)puVar7;
      param_3 = param_3 - 1;
    }
  }
  else {
    if (0xf < (int)param_3) {
      if (((uint)param_2 & 3) != 0) {
        iVar2 = 4 - ((uint)param_2 & 3);
        puVar6 = param_2;
        puVar8 = param_1;
        for (iVar3 = iVar2; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar8 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
        }
        param_3 = param_3 - iVar2;
        param_1 = (void *)((int)param_1 + iVar2);
        param_2 = (void *)((int)param_2 + iVar2);
      }
      puVar7 = param_2;
      puVar9 = param_1;
      for (iVar3 = (int)param_3 >> 2; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      if ((param_3 & 3) == 0) {
        return pvVar1;
      }
      param_2 = (void *)((int)param_2 + (param_3 & 0xfffffffc));
      param_1 = (void *)((int)param_1 + (param_3 & 0xfffffffc));
      param_3 = param_3 & 3;
    }
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      param_2 = (undefined1 *)((int)param_2 + 1);
      param_1 = (undefined1 *)((int)param_1 + 1);
    }
  }
  return pvVar1;
}

