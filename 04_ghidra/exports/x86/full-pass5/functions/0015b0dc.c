/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b0dc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _doSwapout(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  
  iVar4 = DAT_001e5ba4;
  iVar3 = DAT_001e5ba0;
  puVar6 = (undefined4 *)(~_page_mask & param_1);
  iVar8 = 0;
  if (0 < DAT_001e5ba4) {
    puVar7 = puVar6 + 1;
    puVar9 = puVar6;
    do {
      if (puVar7[1] == 0) {
        puVar1 = (undefined4 *)*puVar9;
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
      puVar9 = (undefined4 *)((int)puVar9 + iVar3);
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar4);
  }
  *puVar6 = 0xfeedface;
  _vm_map_pageable(_kernel_map,puVar6,(int)puVar6 + _page_mask + DAT_001e5ba0 & ~_page_mask,1);
  _DAT_001f63c0 = _DAT_001f63c0 + 1;
  return;
}

