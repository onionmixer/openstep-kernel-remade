/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aace0 */

void _reserveDebuggerLock(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = __kernDebuggerLock;
  if (param_1 == DAT_001e8700) {
    if (DAT_001e5154 != '\0') {
      _IOLog("reserveDebuggerLock: already locked\n");
      return;
    }
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar1 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    DAT_001e5154 = '\x01';
  }
  return;
}

