/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ecf1 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0018ecf1(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *unaff_EBX;
  int unaff_EBP;
  
  if (_pmap_initialized == 0) {
    iVar1 = _alloc_pages();
    *(int *)(unaff_EBP + -4) = iVar1;
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_kernel_pt_alloc_2_001e249d);
    }
    _bzero(*(void **)(unaff_EBP + -4),_page_size);
    iVar1 = *(int *)(unaff_EBP + -4);
  }
  else {
    iVar1 = _kmem_alloc_wired(_kernel_map,unaff_EBP + -4);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_kernel_pt_alloc_3_001e24b4);
    }
    uVar3 = *(uint *)(unaff_EBP + -4);
    puVar2 = (uint *)((uVar3 >> 0x16) * 4 + *_kernel_pmap);
    if ((((*puVar2 & 1) == 0) ||
        (puVar2 = (uint *)((uVar3 >> 10 & 0xffc) + (*puVar2 & 0xfffff000)), puVar2 == (uint *)0x0))
       || ((*puVar2 & 1) == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = (uVar3 & 0xfff) + (*puVar2 & 0xfffff000);
    }
  }
  uVar3 = CONCAT31((uint3)((uint)iVar1 >> 8) & 0xfffff0,3);
  iVar1 = _ptes_per_vm_page;
  while (0 < iVar1) {
    *unaff_EBX = uVar3;
    uVar3 = uVar3 & 0xfff | (uVar3 & 0xfffff000) + 0x1000;
    unaff_EBX = unaff_EBX + 1;
    iVar1 = iVar1 + -1;
  }
  return;
}

