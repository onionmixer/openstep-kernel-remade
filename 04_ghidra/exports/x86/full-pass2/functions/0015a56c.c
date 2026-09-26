/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a56c */

undefined4
_object_copyin(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  int iVar1;
  
  iVar1 = _ipc_object_copyin_compat(*(undefined4 *)(param_1 + 0x88),param_2,param_3,param_4,param_5)
  ;
  if (iVar1 == 0) {
    return 1;
  }
  return 0;
}

