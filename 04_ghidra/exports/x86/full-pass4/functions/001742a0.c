/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001742a0 */

uint _kmem_mb_alloc(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_8;
  
  if (((_mb_map != param_1) && (_swapfs_bit_map != param_1)) && (_swapfs_rem_map != param_1)) {
                    /* WARNING: Subroutine does not return */
    _panic(s_You_fool__001e0a46);
  }
  uVar2 = ~_page_mask & param_2 + _page_mask;
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 == param_1 + 0xc) {
    _lock_done(param_1);
    local_8 = *(uint *)(param_1 + 0x14);
    iVar3 = _vm_map_find(param_1,0,0,&local_8,uVar2,1);
    if (iVar3 == 0) {
      _vm_map_pageable(param_1,local_8,uVar2 + local_8,0);
    }
    else {
      local_8 = 0;
    }
  }
  else {
    if (((((*(int *)(param_1 + 0xc) != iVar3) || ((*(byte *)(iVar3 + 0x18) & 1) != 0)) ||
         ((*(int *)(iVar3 + 8) != *(int *)(param_1 + 0x14) ||
          ((*(int *)(iVar3 + 0x20) != 7 || (*(int *)(iVar3 + 0x1c) != 3)))))) ||
        (*(int *)(iVar3 + 0x24) != 1)) || (*(short *)(iVar3 + 0x28) == 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mb_map_abused_even_more_than_usu_001e0a50);
    }
    uVar10 = *(uint *)(iVar3 + 0xc);
    if (*(int *)(param_1 + 0x18) - uVar2 < uVar10) {
      _lock_done(param_1);
      local_8 = 0;
    }
    else {
      iVar1 = *(int *)(iVar3 + 0x10);
      uVar4 = (uVar10 - *(int *)(iVar3 + 8)) + *(int *)(iVar3 + 0x14);
      *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + uVar2;
      piVar7 = (int *)(iVar1 + 0x10);
      do {
        do {
        } while (*piVar7 != 0);
        LOCK();
        iVar5 = *piVar7;
        *piVar7 = 1;
        UNLOCK();
      } while (iVar5 == 1);
      uVar8 = uVar4;
      for (uVar9 = uVar2 >> ((byte)_page_shift & 0x1f); local_8 = uVar10, uVar9 != 0;
          uVar9 = uVar9 - 1) {
        iVar5 = _vm_page_alloc_sequential(iVar1,uVar8,0);
        if (iVar5 == 0) {
          while (uVar4 < uVar8) {
            uVar8 = uVar8 - _page_size;
            uVar6 = _vm_page_lookup(iVar1,uVar8);
            _vm_page_free(uVar6);
          }
          LOCK();
          *(undefined4 *)(iVar1 + 0x10) = 0;
          UNLOCK();
          *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) - uVar2;
          _lock_done(param_1);
          return 0;
        }
        _vm_page_zero_fill(iVar5);
        *(byte *)(iVar5 + 0x20) = *(byte *)(iVar5 + 0x20) & 0xfe;
        uVar8 = uVar8 + _page_size;
        uVar10 = local_8;
      }
      LOCK();
      *(undefined4 *)(iVar1 + 0x10) = 0;
      UNLOCK();
      if (uVar10 < *(uint *)(iVar3 + 0xc)) {
        piVar7 = (int *)(iVar1 + 0x10);
        do {
          do {
            do {
            } while (*piVar7 != 0);
            LOCK();
            iVar5 = *piVar7;
            *piVar7 = 1;
            UNLOCK();
          } while (iVar5 == 1);
          iVar5 = _vm_page_lookup(iVar1,uVar4);
          _vm_page_wire(iVar5);
          LOCK();
          *(undefined4 *)(iVar1 + 0x10) = 0;
          UNLOCK();
          _pmap_enter(*(undefined4 *)(param_1 + 0x24),uVar10,*(undefined4 *)(iVar5 + 0x24),
                      *(undefined4 *)(iVar3 + 0x1c),1);
          uVar10 = uVar10 + _page_size;
          uVar4 = uVar4 + _page_size;
        } while (uVar10 < *(uint *)(iVar3 + 0xc));
      }
      _lock_done(param_1);
    }
  }
  return local_8;
}

