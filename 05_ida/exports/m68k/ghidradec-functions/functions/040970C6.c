
uint sub_40970C6(uint *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *unaff_D3;
  int iVar5;
  int *piVar6;
  
  iVar5 = 0;
  *param_2 = 0x2a6a6b73;
  uVar4 = 0;
  iVar3 = _pmap_phys_to_index(param_2);
  if ((iVar3 != -1) && ((int)param_1[6] < (int)param_1[5])) {
    unaff_D3 = (int *)(~_page_mask & (uint)param_2);
    for (piVar6 = unaff_D3;
        (piVar6 < (int *)(_page_size + (int)unaff_D3) && (*piVar6 == 0x2a6a6b73));
        piVar6 = (int *)(param_1[2] + (int)piVar6)) {
      uVar4 = uVar4 + 1;
    }
  }
  *param_2 = 0;
  if ((_pmap_gc == 0) || (uVar4 != param_1[6])) {
    if (*param_1 != 0) {
      *(undefined4 **)(*param_1 + 8) = param_2;
    }
    *param_2 = 0x2a6a6b73;
    param_2[1] = *param_1;
    param_2[2] = 0;
    if (*param_1 == 0) {
      param_1[1] = (uint)param_2;
    }
    else {
      *(undefined4 **)(*param_1 + 8) = param_2;
    }
    *param_1 = (uint)param_2;
    param_1[5] = param_1[5] + 1;
  }
  else {
    uVar4 = *param_1;
    if (uVar4 != 0) {
      uVar2 = ~_page_mask;
      do {
        if (unaff_D3 == (int *)(uVar2 & uVar4)) {
          if (*(int *)(uVar4 + 8) == 0) {
            *param_1 = *(uint *)(uVar4 + 4);
          }
          else {
            *(undefined4 *)(*(int *)(uVar4 + 8) + 4) = *(undefined4 *)(uVar4 + 4);
          }
          if (*(int *)(uVar4 + 4) == 0) {
            param_1[1] = *(uint *)(uVar4 + 8);
          }
          else {
            *(undefined4 *)(*(int *)(uVar4 + 4) + 8) = *(undefined4 *)(uVar4 + 8);
          }
        }
        uVar4 = *(uint *)(uVar4 + 4);
      } while (uVar4 != 0);
    }
    iVar3 = _pmap_phys_to_index(param_2);
    iVar5 = _pv_head_table;
    _page_table_alloc_size = _page_table_alloc_size - _page_size;
    param_1[4] = param_1[4] - _page_size;
    param_1[5] = param_1[5] - param_1[6];
    iVar5 = *(int *)(iVar5 + 8 + iVar3 * 0xc);
  }
  _page_table_memory_size = _page_table_memory_size - param_1[2];
  uVar4 = param_1[2];
  uVar2 = param_1[3];
  uVar1 = uVar2 - uVar4;
  param_1[3] = uVar1;
  uVar4 = (uint)(byte)((uVar2 < uVar4) << 4 | ((int)uVar1 < 0) << 3 | (uVar1 == 0) << 2 |
                       SBORROW4(uVar2,uVar4) << 1 | uVar2 < uVar4);
  if (iVar5 != 0) {
    uVar4 = _kmem_free(_kernel_map,iVar5,_page_size);
  }
  return uVar4;
}
