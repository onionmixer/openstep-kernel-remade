/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015bdc4 */

void _set_timeout(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = _splsched();
  do {
  } while (DAT_001e5ba8 != 0);
  LOCK();
  DAT_001e5ba8 = 1;
  UNLOCK();
  uVar2 = _ticks_to_ns_time(param_2);
  uVar2 = _calloutDeadlineFromInterval(uVar2);
  _calloutEntryDispatchDelayed(param_1,uVar2);
  *(undefined4 *)(param_1 + 0x2c) = 1;
  LOCK();
  DAT_001e5ba8 = 0;
  UNLOCK();
  _splx(uVar1);
  return;
}

