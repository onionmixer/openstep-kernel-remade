/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001742ce */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001742ce(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int unaff_EBP;
  uint uVar4;
  uint uVar5;
  
  *(uint *)(unaff_EBP + 0xc) = ~_page_mask & *(int *)(unaff_EBP + 0xc) + _page_mask;
  _lock_write();
  iVar1 = *(int *)(unaff_EBP + 8);
  piVar3 = (int *)(iVar1 + 0x4c);
  *piVar3 = *piVar3 + 1;
  iVar1 = *(int *)(iVar1 + 0x10);
  *(int *)(unaff_EBP + -0xc) = iVar1;
  if (iVar1 == *(int *)(unaff_EBP + 8) + 0xc) {
    _lock_done();
    *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x14);
    iVar1 = _vm_map_find(*(undefined4 *)(unaff_EBP + 8),0,0,unaff_EBP + -4,
                         *(undefined4 *)(unaff_EBP + 0xc),1);
    if (iVar1 == 0) {
      _vm_map_pageable(*(undefined4 *)(unaff_EBP + 8),*(int *)(unaff_EBP + -4),
                       *(int *)(unaff_EBP + 0xc) + *(int *)(unaff_EBP + -4));
      uVar2 = *(undefined4 *)(unaff_EBP + -4);
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    iVar1 = *(int *)(unaff_EBP + -0xc);
    if ((((*(int *)(*(int *)(unaff_EBP + 8) + 0xc) != iVar1) || ((*(byte *)(iVar1 + 0x18) & 1) != 0)
         ) || (*(int *)(iVar1 + 8) != *(int *)(*(int *)(unaff_EBP + 8) + 0x14))) ||
       (((*(int *)(iVar1 + 0x20) != 7 || (*(int *)(iVar1 + 0x1c) != 3)) ||
        ((*(int *)(iVar1 + 0x24) != 1 || (*(short *)(iVar1 + 0x28) == 0)))))) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mb_map_abused_even_more_than_usu_001e0a50);
    }
    uVar4 = *(uint *)(*(int *)(unaff_EBP + -0xc) + 0xc);
    if ((uint)(*(int *)(*(int *)(unaff_EBP + 8) + 0x18) - *(int *)(unaff_EBP + 0xc)) < uVar4) {
      _lock_done();
      uVar2 = 0;
    }
    else {
      *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x10);
      iVar1 = *(int *)(unaff_EBP + -0xc);
      *(uint *)(unaff_EBP + -0x10) = (uVar4 - *(int *)(iVar1 + 8)) + *(int *)(iVar1 + 0x14);
      *(uint *)(unaff_EBP + -4) = uVar4;
      *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + *(int *)(unaff_EBP + 0xc);
      piVar3 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      uVar4 = *(uint *)(unaff_EBP + -0x10);
      for (uVar5 = *(uint *)(unaff_EBP + 0xc) >> ((byte)_page_shift & 0x1f); uVar5 != 0;
          uVar5 = uVar5 - 1) {
        iVar1 = _vm_page_alloc_sequential(*(undefined4 *)(unaff_EBP + -8),uVar4);
        if (iVar1 == 0) {
          if (*(uint *)(unaff_EBP + -0x10) < uVar4) {
            do {
              uVar4 = uVar4 - _page_size;
              uVar2 = _vm_page_lookup(*(undefined4 *)(unaff_EBP + -8));
              _vm_page_free(uVar2);
            } while (*(uint *)(unaff_EBP + -0x10) < uVar4);
          }
          LOCK();
          *(undefined4 *)(*(int *)(unaff_EBP + -8) + 0x10) = 0;
          UNLOCK();
          piVar3 = (int *)(*(int *)(unaff_EBP + -0xc) + 0xc);
          *piVar3 = *piVar3 - *(int *)(unaff_EBP + 0xc);
          _lock_done();
          return 0;
        }
        _vm_page_zero_fill();
        *(byte *)(iVar1 + 0x20) = *(byte *)(iVar1 + 0x20) & 0xfe;
        uVar4 = uVar4 + _page_size;
      }
      iVar1 = *(int *)(unaff_EBP + -8);
      LOCK();
      *(undefined4 *)(iVar1 + 0x10) = 0;
      UNLOCK();
      uVar4 = *(uint *)(unaff_EBP + -4);
      if (uVar4 < *(uint *)(*(int *)(unaff_EBP + -0xc) + 0xc)) {
        *(int *)(unaff_EBP + -0x14) = iVar1 + 0x10;
        do {
          do {
            do {
            } while (**(int **)(unaff_EBP + -0x14) != 0);
            LOCK();
            iVar1 = **(int **)(unaff_EBP + -0x14);
            **(int **)(unaff_EBP + -0x14) = 1;
            UNLOCK();
          } while (iVar1 == 1);
          iVar1 = _vm_page_lookup(*(undefined4 *)(unaff_EBP + -8));
          _vm_page_wire(iVar1);
          LOCK();
          *(undefined4 *)(*(int *)(unaff_EBP + -8) + 0x10) = 0;
          UNLOCK();
          _pmap_enter(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),uVar4,
                      *(undefined4 *)(iVar1 + 0x24),
                      *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0x1c));
          uVar4 = uVar4 + _page_size;
        } while (uVar4 < *(uint *)(*(int *)(unaff_EBP + -0xc) + 0xc));
      }
      _lock_done();
      uVar2 = *(undefined4 *)(unaff_EBP + -4);
    }
  }
  return uVar2;
}

