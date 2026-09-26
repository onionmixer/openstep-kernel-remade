/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015637c */

int _port_set_allocate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *local_8;
  
  if (param_1 == 0) {
    iVar1 = 4;
  }
  else {
    iVar1 = _ipc_pset_alloc(param_1,param_2,&local_8);
    if (iVar1 == 0) {
      LOCK();
      *local_8 = 0;
      UNLOCK();
    }
    else if (iVar1 != 6) {
      iVar1 = 4;
    }
  }
  return iVar1;
}

