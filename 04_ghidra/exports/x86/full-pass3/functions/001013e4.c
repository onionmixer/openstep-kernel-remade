/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001013e4 */

void * _memcpy(void *param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  pvVar1 = param_1;
  puVar6 = param_1;
  if ((int)param_3 < 0x10) {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *puVar6 = *(undefined1 *)param_2;
      param_2 = (undefined1 *)((int)param_2 + 1);
      puVar6 = puVar6 + 1;
    }
    return param_1;
  }
  if (((uint)param_2 & 3) != 0) {
    iVar2 = 4 - ((uint)param_2 & 3);
    puVar6 = param_2;
    puVar5 = param_1;
    for (iVar3 = iVar2; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
    }
    param_3 = param_3 - iVar2;
    param_1 = (void *)((int)param_1 + iVar2);
    param_2 = (void *)((int)param_2 + iVar2);
  }
  puVar7 = param_2;
  puVar8 = param_1;
  for (iVar3 = (int)param_3 >> 2; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  uVar4 = param_3 & 3;
  if (uVar4 == 0) {
    return pvVar1;
  }
  puVar5 = (undefined1 *)((int)param_2 + (param_3 & 0xfffffffc));
  puVar6 = (undefined1 *)((int)param_1 + (param_3 & 0xfffffffc));
  if (uVar4 != 2) {
    if (uVar4 < 3) {
      if (uVar4 != 1) {
        return pvVar1;
      }
      goto LAB_00101473;
    }
    if (uVar4 != 3) {
      return pvVar1;
    }
    puVar6[2] = puVar5[2];
  }
  puVar6[1] = puVar5[1];
LAB_00101473:
  *puVar6 = *puVar5;
  return pvVar1;
}

