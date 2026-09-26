/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00189a5c */

undefined4 _copyin(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_FS_OFFSET;
  
  *(undefined **)(_active_threads + 0x74) = &DAT_00189b18;
  if ((int)param_3 < 0x10) {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)param_2 = *(undefined1 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
    return 0;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar2 = 4 - ((uint)param_1 & 3);
    puVar5 = param_1;
    puVar6 = param_2;
    for (iVar3 = iVar2; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    param_3 = param_3 - iVar2;
    param_2 = (undefined4 *)((int)param_2 + iVar2);
    param_1 = (undefined4 *)((int)param_1 + iVar2);
  }
  puVar5 = param_1;
  puVar6 = param_2;
  for (iVar3 = (int)param_3 >> 2; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  uVar4 = param_3 & 3;
  if (uVar4 == 0) goto LAB_00189b08;
  param_3 = param_3 & 0xfffffffc;
  puVar1 = (undefined1 *)((int)param_2 + param_3);
  if (uVar4 == 2) {
LAB_00189af0:
    puVar1[1] = *(undefined1 *)((int)param_1 + in_FS_OFFSET + param_3 + 1);
  }
  else {
    if (2 < uVar4) {
      if (uVar4 != 3) goto LAB_00189b08;
      puVar1[2] = *(undefined1 *)((int)param_1 + in_FS_OFFSET + param_3 + 2);
      goto LAB_00189af0;
    }
    if (uVar4 != 1) goto LAB_00189b08;
  }
  *puVar1 = *(undefined1 *)((int)param_1 + in_FS_OFFSET + param_3);
LAB_00189b08:
  *(undefined4 *)(_active_threads + 0x74) = 0;
  return 0;
}

