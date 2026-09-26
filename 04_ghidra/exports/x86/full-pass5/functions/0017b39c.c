/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017b39c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0017b39c(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int unaff_EBP;
  
  iVar6 = *(int *)(unaff_EBP + -8);
  *(undefined4 *)(iVar6 + 0x14) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(iVar6 + 0x18) = *(undefined4 *)(unaff_EBP + 0xc);
  piVar1 = (int *)(_vm_page_buckets +
                  ((*(uint *)(unaff_EBP + 0xc) >> ((byte)_page_shift & 0x1f)) +
                   *(int *)(unaff_EBP + 8) & __vm_page_hash_mask) * 8);
  _splimp();
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar6 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar6 == 1);
  iVar6 = *(int *)(unaff_EBP + -8);
  *(int *)(iVar6 + 0x10) = piVar1[1];
  piVar1[1] = iVar6;
  LOCK();
  *piVar1 = 0;
  UNLOCK();
  _splx();
  puVar2 = *(undefined4 **)(unaff_EBP + 8);
  puVar3 = (undefined4 *)puVar2[1];
  if (puVar2 == puVar3) {
    *puVar2 = *(undefined4 *)(unaff_EBP + -8);
  }
  else {
    puVar3[2] = *(undefined4 *)(unaff_EBP + -8);
  }
  iVar6 = *(int *)(unaff_EBP + -8);
  *(undefined4 **)(iVar6 + 0xc) = puVar3;
  iVar4 = *(int *)(unaff_EBP + 8);
  *(int *)(iVar6 + 8) = iVar4;
  *(int *)(iVar4 + 4) = iVar6;
  *(byte *)(iVar6 + 0x20) = *(byte *)(iVar6 + 0x20) | 4;
  *(short *)(iVar4 + 0x1a) = *(short *)(iVar4 + 0x1a) + 1;
  if ((_vm_page_free_count < _vm_page_free_min) ||
     ((_vm_page_free_count < _vm_page_free_target &&
      (_vm_page_inactive_count < _vm_page_inactive_target)))) {
    _thread_wakeup_prim(&_vm_pages_needed,0);
  }
  if (((*(byte *)(*(int *)(unaff_EBP + 8) + 0x48) & 3) != 0) && (*(int *)(unaff_EBP + 0x10) != 0)) {
    uVar5 = *(uint *)(*(int *)(unaff_EBP + 8) + 0x54);
    iVar6 = *(int *)(unaff_EBP + 0xc) - uVar5;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if (_page_size == iVar6) {
      *(uint *)(unaff_EBP + -4) = uVar5;
      *(uint *)(unaff_EBP + -0xc) =
           _vm_page_buckets +
           ((uVar5 >> ((byte)_page_shift & 0x1f)) + *(int *)(unaff_EBP + 8) & __vm_page_hash_mask) *
           8;
      _splimp();
      piVar1 = *(int **)(unaff_EBP + -0xc);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar6 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar6 == 1);
      for (iVar6 = piVar1[1];
          (iVar6 != 0 &&
          ((*(int *)(iVar6 + 0x14) != *(int *)(unaff_EBP + 8) ||
           (*(int *)(iVar6 + 0x18) != *(int *)(unaff_EBP + -4))))); iVar6 = *(int *)(iVar6 + 0x10))
      {
      }
      LOCK();
      *piVar1 = 0;
      UNLOCK();
      _splx();
      if (iVar6 != 0) {
        _vm_policy_apply(*(undefined4 *)(unaff_EBP + 8),iVar6);
      }
    }
  }
  *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x54) = *(undefined4 *)(unaff_EBP + 0xc);
  return *(undefined4 *)(unaff_EBP + -8);
}

