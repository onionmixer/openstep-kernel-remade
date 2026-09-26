/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00169944 */

void _calloutEntryDispatchDelayed(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  
  uVar2 = _splsched();
  do {
  } while (DAT_001e7244 != 0);
  LOCK();
  DAT_001e7244 = 1;
  UNLOCK();
  if (param_1[7] == 0) {
    param_1[3] = param_1[4];
    param_1[5] = param_2;
    param_1[6] = param_3;
    for (piVar4 = DAT_001e7258;
        (((int **)piVar4 != &DAT_001e7258 && ((uint)piVar4[6] <= (uint)param_1[6])) &&
        ((piVar4[6] != param_1[6] || ((uint)piVar4[5] <= (uint)param_1[5]))));
        piVar4 = (int *)*piVar4) {
      if ((param_1[5] == piVar4[5]) && (param_1[6] == piVar4[6])) goto LAB_001699d0;
    }
    piVar4 = (int *)piVar4[1];
LAB_001699d0:
    *param_1 = *piVar4;
    param_1[1] = (int)piVar4;
    *(int **)(*piVar4 + 4) = param_1;
    *piVar4 = (int)param_1;
    param_1[7] = 2;
    if (DAT_001e7258 == param_1) {
      uVar8 = _clock_value(1);
      uVar5 = (uint)((ulonglong)uVar8 >> 0x20);
      uVar7 = (uint)uVar8;
      if (((uint)param_1[6] < uVar5) || ((uVar5 == param_1[6] && ((uint)param_1[5] < uVar7)))) {
        uVar7 = 0;
        uVar6 = 0;
      }
      else {
        puVar3 = (uint *)_timer_attributes(0);
        uVar1 = puVar3[1];
        uVar6 = param_1[5] - uVar7;
        uVar7 = (param_1[6] - uVar5) - (uint)((uint)param_1[5] < uVar7);
        if ((uVar1 < uVar7) || ((uVar1 == uVar7 && (*puVar3 < uVar6)))) {
          uVar7 = uVar1;
          uVar6 = *puVar3;
        }
      }
      _set_timer(0,uVar6,uVar7);
    }
  }
  LOCK();
  DAT_001e7244 = 0;
  UNLOCK();
  _splx(uVar2);
  return;
}

