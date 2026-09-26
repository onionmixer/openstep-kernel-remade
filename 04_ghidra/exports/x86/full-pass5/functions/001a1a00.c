/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a1a00 */

void _PCscheduleTimers(int param_1)

{
  undefined8 uVar1;
  
  *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) & 0xfffffffd;
  if ((*(byte *)(param_1 + 0x7c) & 2) != 0) {
    _calloutRemove(FUN_001a19c8,param_1);
  }
  if ((*(byte *)(param_1 + 0x5c) & 2) == 0) {
    *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0xfffffffd;
  }
  else {
    uVar1 = _calloutDeadlineFromInterval(*(int *)(param_1 + 0x60) * 1000,0);
    _calloutDispatchDelayed(FUN_001a19c8,param_1,uVar1);
    *(byte *)(param_1 + 0x7c) = *(byte *)(param_1 + 0x7c) | 2;
  }
  if ((*(byte *)(param_1 + 0x78) & 4) != 0) {
    *(byte *)(param_1 + 0x74) = *(byte *)(param_1 + 0x74) | 4;
    *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) & 0xfffffffb;
  }
  if (((*(byte *)(param_1 + 0x7c) & 4) == 0) && ((*(byte *)(param_1 + 0x5c) & 4) != 0)) {
    uVar1 = _calloutDeadlineFromInterval(*(int *)(param_1 + 100) * 1000,0);
    _calloutDispatchDelayed(FUN_001a19e8,param_1,uVar1);
    *(byte *)(param_1 + 0x7c) = *(byte *)(param_1 + 0x7c) | 4;
  }
  return;
}

