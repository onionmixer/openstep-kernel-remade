/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017b9b4 */

void _vm_page_copy(int param_1,int param_2)

{
  _pmap_copy_page(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 0x24));
  return;
}

