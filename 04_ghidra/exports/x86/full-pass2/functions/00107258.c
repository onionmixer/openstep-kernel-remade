/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107258 */

void _obreak(void)

{
  vm_map_t target_task;
  int iVar1;
  kern_return_t kVar2;
  uint uVar3;
  vm_address_t local_c;
  int local_8;
  
  uVar3 = **(int **)(DAT_001e875c + 0x24) + _page_mask & ~_page_mask;
  if (*(int *)(_active_u + 0x274) < (int)uVar3) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0xc;
  }
  else {
    target_task = *(vm_map_t *)(*(int *)(_active_threads + 0xc) + 0xc);
    _lock_write(target_task);
    *(int *)(target_task + 0x4c) = *(int *)(target_task + 0x4c) + 1;
    iVar1 = _vm_map_lookup_entry(target_task,uVar3,&local_8);
    if (iVar1 == 0) {
      local_c = *(vm_address_t *)(local_8 + 0xc);
      _lock_done(target_task);
      kVar2 = _vm_allocate(target_task,&local_c,uVar3 - local_c,0);
      if (kVar2 != 0) {
        _uprintf(s_could_not_sbrk__return____d_001da889,kVar2);
      }
    }
    else {
      _lock_done(target_task);
    }
  }
  return;
}

