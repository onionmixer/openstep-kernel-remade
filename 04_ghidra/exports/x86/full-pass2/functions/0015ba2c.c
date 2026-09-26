/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015ba2c */

undefined4 _lock_try_write(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 2;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (*param_1 == _active_threads) {
    *(ushort *)((int)param_1 + 6) =
         *(ushort *)((int)param_1 + 6) & 0xf | (*(ushort *)((int)param_1 + 6) & 0xfff0) + 0x10;
  }
  else {
    if ((param_1[1] & 0x3ffffU) != 0) {
      LOCK();
      param_1[2] = 0;
      UNLOCK();
      return 0;
    }
    *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 2;
  }
  LOCK();
  param_1[2] = 0;
  UNLOCK();
  return 1;
}

