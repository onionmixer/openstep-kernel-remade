/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017a9b4 */

void _vm_set_page_size(void)

{
  _page_mask = _page_size - 1;
  if ((_page_size & _page_mask) == 0) {
    _page_shift = 0;
    if (_page_size != 1) {
      do {
        _page_shift = _page_shift + 1;
      } while (1 << ((byte)_page_shift & 0x1f) != _page_size);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vm_set_page_size__page_size_not_a_001e0d24);
}

