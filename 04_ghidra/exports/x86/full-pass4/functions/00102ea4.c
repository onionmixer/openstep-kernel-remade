/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00102ea4 */

void _lightning_bolt(undefined4 param_1,int param_2)

{
  undefined8 uVar1;
  
  _thread_wakeup_prim(&_lbolt,0,0);
  if (param_2 == 0) {
    param_2 = _calloutEntryAllocate(_lightning_bolt,0);
  }
  uVar1 = _calloutDeadlineFromInterval(1000000000,0);
  _calloutEntryDispatchDelayed(param_2,uVar1);
  return;
}

