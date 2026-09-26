/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001697c4 */

void _calloutEntryFree(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = _splsched();
  do {
  } while (DAT_001e7244 != 0);
  LOCK();
  UNLOCK();
  if (*(int *)(param_1 + 0x1c) == 0) {
    LOCK();
    DAT_001e7244 = 0;
    UNLOCK();
    _splx(uVar1);
    _kfree(param_1,0x20);
    return;
  }
  LOCK();
  DAT_001e7244 = 0;
  UNLOCK();
                    /* WARNING: Subroutine does not return */
  _panic(s_calloutEntryFree_001dfcd6);
}

