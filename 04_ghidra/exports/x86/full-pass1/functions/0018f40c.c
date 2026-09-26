/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018f40c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0018f40c(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = _pd_free_queue;
  if ((int **)_pd_free_queue == &_pd_free_queue) {
    piVar4 = (int *)0x0;
  }
  if (piVar4 == (int *)0x0) {
    iVar3 = _kmem_alloc_wired(_kernel_map,param_1,_page_size);
    if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_alloc_pd_001e24e2);
    }
    __pd_alloc_count = __pd_alloc_count + 1;
    uVar1 = *param_1;
    piVar4 = (int *)_zalloc(_pg_exten_zone);
    puVar2 = (uint *)((uVar1 >> 0x16) * 4 + *_kernel_pmap);
    if ((((*puVar2 & 1) == 0) ||
        (puVar2 = (uint *)((uVar1 >> 10 & 0xffc) + (*puVar2 & 0xfffff000)), puVar2 == (uint *)0x0))
       || ((*puVar2 & 1) == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = (uVar1 & 0xfff) + (*puVar2 & 0xfffff000);
    }
    piVar4[3] = iVar3;
    iVar3 = _pg_desc_tbl +
            (((uint)(iVar3 - __pg_first_phys) >> 0xc) >> ((char)_ptes_per_vm_page - 1U & 0x1f)) *
            0x14;
    *(int **)(iVar3 + 0xc) = piVar4;
    piVar4[2] = iVar3;
    *(undefined1 *)(piVar4 + 7) = 0;
    *(undefined1 *)((int)piVar4 + 0x1d) = 0;
    *(undefined2 *)((int)piVar4 + 0x1a) = 0;
    *(undefined2 *)(piVar4 + 6) = 0;
    *(undefined2 *)(piVar4 + 6) = 1;
    if (1 < _ptes_per_vm_page) {
      *piVar4 = (int)_pd_free_queue;
      piVar4[1] = (int)&_pd_free_queue;
      *(int **)(*piVar4 + 4) = piVar4;
      __pd_free_count = __pd_free_count + 1;
      _pd_free_queue = piVar4;
    }
    *(byte *)(piVar4 + 7) = *(byte *)(piVar4 + 7) | 1;
  }
  else {
    iVar3 = piVar4[6];
    *(short *)(piVar4 + 6) = (short)iVar3 + 1;
    if (_ptes_per_vm_page == (ushort)((short)iVar3 + 1)) {
      *(int *)(*piVar4 + 4) = piVar4[1];
      *(int *)piVar4[1] = *piVar4;
      __pd_free_count = __pd_free_count + -1;
    }
    uVar1 = ~(uint)*(byte *)(piVar4 + 7);
    iVar3 = 0;
    if (uVar1 != 0) {
      for (; (uVar1 >> iVar3 & 1) == 0; iVar3 = iVar3 + 1) {
      }
    }
    if (uVar1 == 0) {
      iVar3 = -1;
    }
    *(byte *)(piVar4 + 7) = *(byte *)(piVar4 + 7) | (byte)(1 << ((byte)iVar3 & 0x1f));
    *param_1 = iVar3 * 0x1000 + *(int *)(piVar4[2] + 8);
  }
  return;
}

