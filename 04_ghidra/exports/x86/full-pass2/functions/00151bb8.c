/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151bb8 */

void _ipc_table_free(uint param_1,undefined4 param_2)

{
  if (param_1 < _page_size) {
    _kfree(param_2,param_1);
    return;
  }
  _kmem_free(_kalloc_map,param_2,param_1);
  return;
}

