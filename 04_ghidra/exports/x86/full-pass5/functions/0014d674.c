/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014d674 */

int _ipc_pset_alloc_name(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int local_8;
  
  iVar1 = _ipc_object_alloc_name(param_1,1,0x80000,0,param_2,&local_8);
  if (iVar1 == 0) {
    *(undefined4 *)(local_8 + 0xc) = param_2;
    _ipc_mqueue_init(local_8 + 0x10);
    *param_3 = local_8;
    iVar1 = 0;
  }
  return iVar1;
}

