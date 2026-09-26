/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b19c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _swapoutStack(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  _DAT_001f63bc = _DAT_001f63bc + 1;
  _lock_write(&_stack_queue_lock);
  *(undefined4 *)(param_1 + -4) = 1;
  iVar4 = DAT_001e5ba4;
  iVar3 = DAT_001e5ba0;
  uVar8 = param_1 - 0xcU & ~_page_mask;
  iVar6 = 0;
  if (0 < DAT_001e5ba4) {
    do {
      if (*(int *)(uVar8 + 8) == 2) goto LAB_0015b2a0;
      uVar8 = uVar8 + DAT_001e5ba0;
      iVar6 = iVar6 + 1;
    } while (iVar6 < DAT_001e5ba4);
  }
  puVar9 = (undefined4 *)(param_1 - 0xcU & ~_page_mask);
  iVar6 = 0;
  if (0 < DAT_001e5ba4) {
    puVar7 = puVar9 + 1;
    puVar10 = puVar9;
    do {
      if (puVar7[1] == 0) {
        puVar1 = (undefined4 *)*puVar10;
        puVar2 = (undefined4 *)*puVar7;
        puVar5 = puVar2;
        if ((undefined4 **)puVar1 != &DAT_001e5b98) {
          puVar1[1] = puVar2;
          puVar5 = DAT_001e5b9c;
        }
        DAT_001e5b9c = puVar5;
        if ((undefined4 **)puVar2 != &DAT_001e5b98) {
          *puVar2 = puVar1;
          puVar1 = DAT_001e5b98;
        }
        DAT_001e5b98 = puVar1;
        DAT_001ded68 = DAT_001ded68 + -1;
        _DAT_001f63b8 = _DAT_001f63b8 + -1;
      }
      puVar7 = (undefined4 *)((int)puVar7 + iVar3);
      puVar10 = (undefined4 *)((int)puVar10 + iVar3);
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar4);
  }
  *puVar9 = 0xfeedface;
  _vm_map_pageable(_kernel_map,puVar9,(int)puVar9 + _page_mask + DAT_001e5ba0 & ~_page_mask,1);
  _DAT_001f63c0 = _DAT_001f63c0 + 1;
LAB_0015b2a0:
  _lock_done(&_stack_queue_lock);
  return;
}

