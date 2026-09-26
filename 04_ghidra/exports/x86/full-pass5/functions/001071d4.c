/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001071d4 */

void _munmap(void)

{
  uint address;
  uint size;
  kern_return_t kVar1;
  
  address = **(uint **)(DAT_001e875c + 0x24);
  size = (*(uint **)(DAT_001e875c + 0x24))[1];
  if (((_page_mask & address) == 0) && ((_page_mask & size) == 0)) {
    kVar1 = _vm_deallocate(*(vm_map_t *)(*(int *)(_active_threads + 0xc) + 0xc),address,size);
    if (kVar1 != 0) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
    }
  }
  else {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  }
  return;
}

