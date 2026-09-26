/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160adc */

void _power_callout(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_8;
  
  iVar1 = _PMGetPowerEvent(&local_8);
  if (iVar1 == 0) {
    switch(local_8) {
    case 1:
    case 9:
      DAT_001e5e4c = 1;
      _PMSetPowerState(1,1);
      break;
    case 2:
    case 8:
    case 10:
      DAT_001e5e4c = 2;
      _PMSetPowerState(1,2);
      DAT_001e5e4c = 0;
      _PMSetPowerState(1,0);
      break;
    case 3:
    case 4:
    case 0xb:
      if (DAT_001e5e4c != 0) {
        DAT_001e5e4c = 0;
        _PMSetPowerState(1,0);
      }
    case 7:
      _PMUpdateClock();
    }
  }
  if (param_2 == 0) {
    param_2 = _calloutEntryAllocate(_power_callout,0);
  }
  uVar2 = _calloutDeadlineFromInterval(1010000000,0);
  _calloutEntryDispatchDelayed(param_2,uVar2);
  return;
}

