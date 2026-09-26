/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018adf0 */

void _alloc_pages(int param_1)

{
  if (_pmap_initialized != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_alloc_pages_001e19f7);
  }
  DAT_001f6e74 = (_page_mask + param_1 & ~_page_mask) + DAT_001f6e74;
  return;
}

