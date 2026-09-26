/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0d4c */

undefined4 __regparm1 _ev_lock(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  do {
    LOCK();
    iVar1 = *param_2;
    *param_2 = iVar2;
    UNLOCK();
    iVar2 = iVar1;
  } while (iVar1 != 0);
  return param_1;
}

