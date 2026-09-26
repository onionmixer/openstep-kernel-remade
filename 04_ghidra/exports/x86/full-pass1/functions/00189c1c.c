/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00189c1c */

undefined4 _copywithin(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  *(undefined **)(_active_threads + 0x74) = &DAT_00189cd0;
  if ((int)param_3 < 0x10) {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)param_2 = *(undefined1 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
    return 0;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar3 = 4 - ((uint)param_1 & 3);
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
  puVar6 = param_1;
  puVar7 = param_2;
  for (iVar4 = (int)param_3 >> 2; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  uVar5 = param_3 & 3;
  if (uVar5 == 0) goto LAB_00189cbf;
  puVar1 = (undefined1 *)((int)param_1 + (param_3 & 0xfffffffc));
  puVar2 = (undefined1 *)((int)param_2 + (param_3 & 0xfffffffc));
  if (uVar5 == 2) {
LAB_00189ca9:
    puVar2[1] = puVar1[1];
  }
  else {
    if (2 < uVar5) {
      if (uVar5 != 3) goto LAB_00189cbf;
      puVar2[2] = puVar1[2];
      goto LAB_00189ca9;
    }
    if (uVar5 != 1) goto LAB_00189cbf;
  }
  *puVar2 = *puVar1;
LAB_00189cbf:
  *(undefined4 *)(_active_threads + 0x74) = 0;
  return 0;
}

