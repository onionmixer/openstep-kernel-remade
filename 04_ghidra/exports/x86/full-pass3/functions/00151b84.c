/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151b84 */

undefined4 _ipc_table_realloc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = _kmem_realloc(_kalloc_map,param_2,param_1,&local_8,param_3);
  if (iVar1 != 0) {
    local_8 = 0;
  }
  return local_8;
}

