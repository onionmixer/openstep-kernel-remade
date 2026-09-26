/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146958 */

void _ipc_hash_insert(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = param_3 >> 8;
  if ((uVar1 < *(uint *)(param_1 + 0x18)) && (param_4 == uVar1 * 0x10 + *(int *)(param_1 + 0x14))) {
    _ipc_hash_local_insert(param_1,param_2,uVar1,param_4);
  }
  else {
    _ipc_hash_global_insert(param_1,param_2,param_3,param_4);
  }
  return;
}

