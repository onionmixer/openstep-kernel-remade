/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00190d1a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00190d1a(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int unaff_EBP;
  
  if ((int **)_pt_free_queue == &_pt_free_queue) {
    piVar3 = (int *)0x0;
    piVar1 = _pt_free_queue;
  }
  else {
    *(int ***)(*_pt_free_queue + 4) = &_pt_free_queue;
    piVar3 = _pt_free_queue;
    piVar1 = (int *)*_pt_free_queue;
    if (_pt_free_queue != (int *)0x0) {
      __pt_free_count = __pt_free_count + -1;
    }
  }
  _pt_free_queue = piVar1;
  if (piVar3 == (int *)0x0) {
    iVar2 = _kmem_alloc_wired(_kernel_map,unaff_EBP + -4);
    if (iVar2 != 0) {
      return;
    }
    __pt_alloc_count = __pt_alloc_count + 1;
    uVar5 = *(uint *)(unaff_EBP + -4);
    piVar3 = (int *)_zalloc();
    puVar4 = (uint *)((uVar5 >> 0x16) * 4 + *_kernel_pmap);
    if ((((*puVar4 & 1) == 0) ||
        (puVar4 = (uint *)((uVar5 >> 10 & 0xffc) + (*puVar4 & 0xfffff000)), puVar4 == (uint *)0x0))
       || ((*puVar4 & 1) == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = (uVar5 & 0xfff) + (*puVar4 & 0xfffff000);
    }
    piVar3[3] = iVar2;
    iVar2 = _pg_desc_tbl +
            (((uint)(iVar2 - __pg_first_phys) >> 0xc) >> ((char)_ptes_per_vm_page - 1U & 0x1f)) *
            0x14;
    *(int **)(iVar2 + 0xc) = piVar3;
    piVar3[2] = iVar2;
    *(undefined1 *)(piVar3 + 7) = 0;
    *(undefined1 *)((int)piVar3 + 0x1d) = 0;
    *(undefined2 *)((int)piVar3 + 0x1a) = 0;
    *(undefined2 *)(piVar3 + 6) = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(piVar3[2] + 8);
  }
  _splvm();
  puVar4 = (uint *)((*(uint *)(unaff_EBP + 0xc) >> 0x16) * 4 + **(int **)(unaff_EBP + 8));
  if (((*puVar4 & 1) == 0) ||
     ((*puVar4 & 0xfffff000) + (*(uint *)(unaff_EBP + 0xc) >> 10 & 0xffc) == 0)) {
    piVar3[5] = -_section_size & *(uint *)(unaff_EBP + 0xc);
    piVar3[4] = *(int *)(unaff_EBP + 8);
    *(undefined1 *)((int)piVar3 + 0x1d) = 0;
    *piVar3 = (int)&_pt_active_queue;
    piVar3[1] = (int)DAT_001f7acc;
    *(int **)piVar3[1] = piVar3;
    __pt_active_count = __pt_active_count + 1;
    uVar5 = CONCAT31((uint3)((uint)piVar3[3] >> 8) & 0xfffff0,7);
    puVar4 = (uint *)(**(int **)(unaff_EBP + 8) + ((uint)piVar3[5] >> 0x16) * 4);
    iVar2 = _ptes_per_vm_page;
    DAT_001f7acc = piVar3;
    while (0 < iVar2) {
      *puVar4 = uVar5;
      uVar5 = uVar5 & 0xfff | (uVar5 & 0xfffff000) + 0x1000;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    }
    _splx();
  }
  else {
    _splx();
    *(undefined4 *)(piVar3[2] + 0xc) = 0;
    _zfree(_pg_exten_zone);
    _kmem_free(_kernel_map,*(undefined4 *)(unaff_EBP + -4));
    __pt_alloc_count = __pt_alloc_count + -1;
  }
  return;
}

