
uint _kmem_mb_alloc(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_8;
  
  if (((param_1 != _mb_map) && (param_1 != _swapfs_bit_map)) && (param_1 != _swapfs_rem_map)) {
                    /* WARNING: Subroutine does not return */
    _panic(aYouFool);
  }
  uVar2 = ~_page_mask & _page_mask + param_2;
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  piVar1 = *(int **)(param_1 + 0xc);
  if ((int *)(param_1 + 8) == piVar1) {
    _lock_done(param_1);
    uStack_8 = *(uint *)(param_1 + 0x10);
    iVar4 = _vm_map_find(param_1,0,0,&uStack_8,uVar2,1);
    if (iVar4 == 0) {
      _vm_map_pageable(param_1,uStack_8,uStack_8 + uVar2,0);
      return uStack_8;
    }
    return 0;
  }
  if (((((piVar1 == *(int **)(param_1 + 8)) && (-1 < *(char *)(piVar1 + 6))) &&
       ((piVar1[2] == *(int *)(param_1 + 0x10) &&
        ((*(int *)((int)piVar1 + 0x1e) == 7 && (*(int *)((int)piVar1 + 0x1a) == 3)))))) &&
      (*(int *)((int)piVar1 + 0x22) == 1)) && (*(sword *)((int)piVar1 + 0x26) != 0)) {
    uVar9 = piVar1[3];
    if (uVar9 <= *(int *)(param_1 + 0x14) - uVar2) {
      iVar4 = piVar1[4];
      uVar7 = piVar1[5] + (uVar9 - piVar1[2]);
      piVar1[3] = uVar2 + piVar1[3];
      uVar8 = uVar2 >> (_page_shift & 0x3f);
      uVar3 = uVar7;
      while( true ) {
        uStack_8 = uVar9;
        if (uVar8 == 0) {
          if (uVar9 < (uint)piVar1[3]) {
            do {
              iVar5 = _vm_page_lookup(iVar4,uVar7);
              _vm_page_wire(iVar5);
              _pmap_enter(*(undefined4 *)(param_1 + 0x20),uVar9,*(undefined4 *)(iVar5 + 0x22),
                          *(undefined4 *)((int)piVar1 + 0x1a),1);
              uVar9 = _page_size + uVar9;
              uVar7 = _page_size + uVar7;
            } while (uVar9 < (uint)piVar1[3]);
          }
          _lock_done(param_1);
          return uStack_8;
        }
        iVar5 = _vm_page_alloc_sequential(iVar4,uVar3,0);
        if (iVar5 == 0) break;
        _vm_page_zero_fill(iVar5);
        *(byte *)(iVar5 + 0x20) = *(byte *)(iVar5 + 0x20) & 0x7f;
        uVar8 = uVar8 - 1;
        uVar3 = _page_size + uVar3;
        uVar9 = uStack_8;
      }
      while (uVar7 < uVar3) {
        uVar3 = uVar3 - _page_size;
        uVar6 = _vm_page_lookup(iVar4,uVar3);
        _vm_page_free(uVar6);
      }
      piVar1[3] = piVar1[3] - uVar2;
    }
    _lock_done(param_1);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aMbMapAbusedEve);
}
