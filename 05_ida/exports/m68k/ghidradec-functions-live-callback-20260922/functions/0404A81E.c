
void _doSwapout(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  
  iVar5 = dword_40B371E;
  iVar4 = dword_40B371A;
  puVar3 = (undefined4 *)(~_page_mask & param_1);
  iVar7 = 0;
  puVar8 = puVar3;
  if (0 < dword_40B371E) {
    do {
      if (puVar8[2] == 0) {
        puVar1 = (undefined4 *)*puVar8;
        puVar2 = (undefined4 *)puVar8[1];
        puVar6 = puVar2;
        if (puVar1 != &dword_40B3712) {
          puVar1[1] = puVar2;
          puVar6 = dword_40B3716;
        }
        dword_40B3716 = puVar6;
        *puVar2 = puVar1;
        dword_40AF7D4 = dword_40AF7D4 + -1;
        dword_40C2330 = dword_40C2330 + -1;
      }
      iVar7 = iVar7 + 1;
      puVar8 = (undefined4 *)(iVar4 + (int)puVar8);
    } while (iVar7 < iVar5);
  }
  *puVar3 = 0xfeedface;
  _vm_map_pageable(_kernel_map,puVar3,~_page_mask & (int)puVar3 + _page_mask + dword_40B371A,1);
  dword_40C2338 = dword_40C2338 + 1;
  return;
}

