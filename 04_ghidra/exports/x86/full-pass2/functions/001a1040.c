/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a1040 */

void _PCdestroy(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x28) + 0xec);
  _pmap_remove(*(undefined4 *)(puVar1[1] + 0x24),puVar1[2],
               puVar1[2] + 0x51c + _page_mask & ~_page_mask);
  _vm_map_remove(puVar1[1],puVar1[2],puVar1[2] + 0x51c + _page_mask & ~_page_mask);
  _vm_map_deallocate(puVar1[1]);
  _PCcancelAllTimers(param_1);
  _kmem_free(_kernel_map,*puVar1,_page_mask + 0x51c & ~_page_mask);
  _kfree(puVar1,0xc);
  return;
}

