/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ed1d */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0018ed1d(void)

{
  int iVar1;
  uint uVar2;
  uint *unaff_EBX;
  int unaff_EBP;
  
  _bzero(*(void **)(unaff_EBP + -4),_page_size);
  uVar2 = CONCAT31((uint3)((uint)*(undefined4 *)(unaff_EBP + -4) >> 8) & 0xfffff0,3);
  iVar1 = _ptes_per_vm_page;
  while (0 < iVar1) {
    *unaff_EBX = uVar2;
    uVar2 = uVar2 & 0xfff | (uVar2 & 0xfffff000) + 0x1000;
    unaff_EBX = unaff_EBX + 1;
    iVar1 = iVar1 + -1;
  }
  return;
}

