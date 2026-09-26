/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001693ec */

void _calloutDispatchDelayed(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint *puVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  
  if (DAT_001dfcbc != 0) {
    uVar3 = _splsched();
    piVar2 = DAT_001e7248;
    do {
    } while (DAT_001e7244 != 0);
    LOCK();
    DAT_001e7244 = 1;
    UNLOCK();
    if ((int **)DAT_001e7248 == &DAT_001e7248) {
                    /* WARNING: Subroutine does not return */
      _panic(s_internalEntryAllocate_001dfcc0);
    }
    *(int ***)(*DAT_001e7248 + 4) = &DAT_001e7248;
    piVar5 = DAT_001e7248 + 2;
    DAT_001e7248 = (int *)*DAT_001e7248;
    *piVar5 = param_1;
    piVar2[3] = param_2;
    piVar2[4] = 0;
    piVar2[5] = param_3;
    piVar2[6] = param_4;
    for (piVar5 = DAT_001e7258;
        (((int **)piVar5 != &DAT_001e7258 && ((uint)piVar5[6] <= (uint)piVar2[6])) &&
        ((piVar5[6] != piVar2[6] || ((uint)piVar5[5] <= (uint)piVar2[5])))); piVar5 = (int *)*piVar5
        ) {
      if ((piVar2[5] == piVar5[5]) && (piVar2[6] == piVar5[6])) goto LAB_001694cc;
    }
    piVar5 = (int *)piVar5[1];
LAB_001694cc:
    *piVar2 = *piVar5;
    piVar2[1] = (int)piVar5;
    *(int **)(*piVar5 + 4) = piVar2;
    *piVar5 = (int)piVar2;
    piVar2[7] = 2;
    if (DAT_001e7258 == piVar2) {
      uVar9 = _clock_value(1);
      uVar6 = (uint)((ulonglong)uVar9 >> 0x20);
      uVar8 = (uint)uVar9;
      if (((uint)piVar2[6] < uVar6) || ((uVar6 == piVar2[6] && ((uint)piVar2[5] < uVar8)))) {
        uVar8 = 0;
        uVar7 = 0;
      }
      else {
        puVar4 = (uint *)_timer_attributes(0);
        uVar1 = puVar4[1];
        uVar7 = piVar2[5] - uVar8;
        uVar8 = (piVar2[6] - uVar6) - (uint)((uint)piVar2[5] < uVar8);
        if ((uVar1 < uVar8) || ((uVar1 == uVar8 && (*puVar4 < uVar7)))) {
          uVar8 = uVar1;
          uVar7 = *puVar4;
        }
      }
      _set_timer(0,uVar7,uVar8);
    }
    LOCK();
    DAT_001e7244 = 0;
    UNLOCK();
    _splx(uVar3);
  }
  return;
}

