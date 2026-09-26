/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c15c */

void _ipc_object_copyin_header
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = _ipc_right_lookup_write(param_1,param_2,&local_8);
  if (iVar1 == 0) {
    _ipc_right_copyin_header(param_1,param_2,local_8,param_3,param_4);
  }
  return;
}

