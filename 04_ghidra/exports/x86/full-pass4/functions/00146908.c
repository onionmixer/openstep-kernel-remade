/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146908 */

undefined4 _ipc_hash_lookup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = _ipc_hash_local_lookup(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x40) == 0) {
      return 0;
    }
    iVar1 = _ipc_hash_global_lookup(param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

