/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160d24 */

int _kern_PMGetPowerEvent(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  undefined4 local_8;
  
  if (param_1 != &_realhost) {
    return 0x16;
  }
  puStack_14 = &local_8;
  uStack_18 = 0x160d4d;
  iVar1 = _PMGetPowerEvent();
  if (iVar1 != 0) {
    return iVar1;
  }
  switch(local_8) {
  case 1:
  case 9:
    DAT_001e5e4c = 1;
    ppuVar2 = &puStack_14;
    puStack_14 = (undefined4 *)0x1;
    break;
  case 2:
  case 8:
  case 10:
    DAT_001e5e4c = 2;
    puStack_14 = (undefined4 *)0x2;
    uStack_18 = 1;
    uStack_1c = 0x160dbf;
    _PMSetPowerState();
    DAT_001e5e4c = 0;
    ppuVar2 = (undefined4 **)&uStack_1c;
    uStack_1c = 0;
    break;
  case 3:
  case 4:
  case 0xb:
    if (DAT_001e5e4c != 0) {
      DAT_001e5e4c = 0;
      puStack_14 = (undefined4 *)0x0;
      uStack_18 = 1;
      uStack_1c = 0x160df0;
      _PMSetPowerState();
    }
  case 7:
    puStack_14 = (undefined4 *)0x160df8;
    _PMUpdateClock();
  default:
    goto switchD_00160d67_caseD_5;
  }
  *(undefined4 *)((int)ppuVar2 + -4) = 1;
  *(undefined4 *)((int)ppuVar2 + -8) = 0x160dd2;
  _PMSetPowerState();
switchD_00160d67_caseD_5:
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = local_8;
  }
  return 0;
}

