/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014b928 */

int _ipc_object_alloc_dead(int param_1,undefined4 param_2)

{
  int iVar1;
  uint *local_8;
  
  iVar1 = _ipc_entry_alloc(param_1,param_2,&local_8);
  if (iVar1 == 0) {
    *local_8 = *local_8 | 0x100001;
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    iVar1 = 0;
  }
  return iVar1;
}

