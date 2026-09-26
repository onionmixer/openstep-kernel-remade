/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ecc0 */

void FUN_0018ecc0(uint param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  void *local_8;
  
  puVar4 = (uint *)(*_kernel_pmap + ((-_section_size & param_1) >> 0x16) * 4);
  if ((*puVar4 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_pmap_kernel_pt_alloc_001e2488);
  }
  if (_pmap_initialized == 0) {
    local_8 = (void *)_alloc_pages(_page_size);
    if (local_8 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_kernel_pt_alloc_2_001e249d);
    }
    _bzero(local_8,_page_size);
  }
  else {
    iVar1 = _kmem_alloc_wired(_kernel_map,&local_8,_page_size);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_kernel_pt_alloc_3_001e24b4);
    }
    puVar2 = (uint *)(((uint)local_8 >> 0x16) * 4 + *_kernel_pmap);
    if ((((*puVar2 & 1) == 0) ||
        (puVar2 = (uint *)(((uint)local_8 >> 10 & 0xffc) + (*puVar2 & 0xfffff000)),
        puVar2 == (uint *)0x0)) || ((*puVar2 & 1) == 0)) {
      local_8 = (void *)0x0;
    }
    else {
      local_8 = (void *)(((uint)local_8 & 0xfff) + (*puVar2 & 0xfffff000));
    }
  }
  uVar3 = CONCAT31((uint3)((uint)local_8 >> 8) & 0xfffff0,3);
  iVar1 = _ptes_per_vm_page;
  while (0 < iVar1) {
    *puVar4 = uVar3;
    uVar3 = uVar3 & 0xfff | (uVar3 & 0xfffff000) + 0x1000;
    puVar4 = puVar4 + 1;
    iVar1 = iVar1 + -1;
  }
  return;
}

