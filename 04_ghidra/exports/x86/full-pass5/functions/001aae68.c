/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aae68 */

void FUN_001aae68(int param_1)

{
  if ((param_1 == DAT_001e8700) && (DAT_001e5154 != '\0')) {
    LOCK();
    *__kernDebuggerLock = 0;
    UNLOCK();
    DAT_001e5154 = '\0';
    _splx(DAT_001e8704);
  }
  return;
}

