/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151b44 */

undefined4 _ipc_table_alloc(uint param_1)

{
  int iVar1;
  undefined4 local_8;
  
  if (param_1 < _page_size) {
    local_8 = _kalloc(param_1);
  }
  else {
    iVar1 = _kmem_alloc(_kalloc_map,&local_8,param_1);
    if (iVar1 != 0) {
      local_8 = 0;
    }
  }
  return local_8;
}

