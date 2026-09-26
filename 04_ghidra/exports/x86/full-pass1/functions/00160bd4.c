/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160bd4 */

void _power_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined4 local_8;
  
  if (DAT_001df224 == 0) {
    iVar1 = _PMConnect();
    if (iVar1 == 0) {
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
      uVar2 = _calloutEntryAllocate(_power_callout,0);
      uVar3 = _calloutDeadlineFromInterval(1010000000,0);
      _calloutEntryDispatchDelayed(uVar2,uVar3);
    }
    DAT_001e5e4c = 0;
    DAT_001df224 = 1;
  }
  return;
}

