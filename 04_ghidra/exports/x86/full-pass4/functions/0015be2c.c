/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015be2c */

bool _reset_timeout(int param_1)

{
  undefined4 uVar1;
  bool bVar2;
  
  uVar1 = _splsched();
  do {
  } while (DAT_001e5ba8 != 0);
  LOCK();
  DAT_001e5ba8 = 1;
  UNLOCK();
  bVar2 = *(int *)(param_1 + 0x2c) == 0;
  if (bVar2) {
    LOCK();
    DAT_001e5ba8 = 0;
    UNLOCK();
    _splx(uVar1);
  }
  else {
    _calloutEntryRemove(param_1);
    *(undefined4 *)(param_1 + 0x2c) = 0;
    LOCK();
    DAT_001e5ba8 = 0;
    UNLOCK();
    _splx(uVar1);
  }
  return !bVar2;
}

