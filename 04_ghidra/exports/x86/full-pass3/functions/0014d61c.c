/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014d61c */

int _ipc_pset_alloc(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int local_c;
  undefined4 local_8;
  
  iVar1 = _ipc_object_alloc(param_1,1,0x80000,0,&local_8,&local_c);
  if (iVar1 == 0) {
    *(undefined4 *)(local_c + 0xc) = local_8;
    _ipc_mqueue_init(local_c + 0x10);
    *param_2 = local_8;
    *param_3 = local_c;
    iVar1 = 0;
  }
  return iVar1;
}

