/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a8eec */

int FUN_001a8eec(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  _thread_wakeup_prim(iVar1 + 8,1,0);
  _lock_done(*(undefined4 *)(iVar1 + 4));
  return param_1;
}

