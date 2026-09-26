/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018f4b1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0018f4b1(void)

{
  uint uVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  uint *unaff_ESI;
  
  __pd_alloc_count = __pd_alloc_count + 1;
  uVar1 = *unaff_ESI;
  piVar2 = (int *)_zalloc();
  puVar3 = (uint *)((uVar1 >> 0x16) * 4 + *_kernel_pmap);
  if ((((*puVar3 & 1) == 0) ||
      (puVar3 = (uint *)((uVar1 >> 10 & 0xffc) + (*puVar3 & 0xfffff000)), puVar3 == (uint *)0x0)) ||
     ((*puVar3 & 1) == 0)) {
    iVar4 = 0;
  }
  else {
    iVar4 = (uVar1 & 0xfff) + (*puVar3 & 0xfffff000);
  }
  piVar2[3] = iVar4;
  iVar4 = _pg_desc_tbl +
          (((uint)(iVar4 - __pg_first_phys) >> 0xc) >> ((char)_ptes_per_vm_page - 1U & 0x1f)) * 0x14
  ;
  *(int **)(iVar4 + 0xc) = piVar2;
  piVar2[2] = iVar4;
  *(undefined1 *)(piVar2 + 7) = 0;
  *(undefined1 *)((int)piVar2 + 0x1d) = 0;
  *(undefined2 *)((int)piVar2 + 0x1a) = 0;
  *(undefined2 *)(piVar2 + 6) = 0;
  *(undefined2 *)(piVar2 + 6) = 1;
  if (1 < _ptes_per_vm_page) {
    *piVar2 = (int)_pd_free_queue;
    piVar2[1] = (int)&_pd_free_queue;
    *(int **)(*piVar2 + 4) = piVar2;
    __pd_free_count = __pd_free_count + 1;
    _pd_free_queue = piVar2;
  }
  *(byte *)(piVar2 + 7) = *(byte *)(piVar2 + 7) | 1;
  return;
}

