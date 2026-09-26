/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016957c */

void _calloutRemove(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  
  uVar2 = _splsched();
  do {
  } while (DAT_001e7244 != 0);
  LOCK();
  UNLOCK();
  for (piVar3 = DAT_001e7250; piVar1 = DAT_001e7258, (int **)piVar3 != &DAT_001e7250;
      piVar3 = (int *)*piVar3) {
    if ((piVar3[2] == param_1) && (piVar3[3] == param_2)) {
      *(int *)(*piVar3 + 4) = piVar3[1];
      *(int *)piVar3[1] = *piVar3;
      DAT_001e7260 = DAT_001e7260 + -1;
      goto LAB_00169615;
    }
  }
  while( true ) {
    piVar3 = piVar1;
    if ((int **)piVar3 == &DAT_001e7258) goto LAB_00169652;
    if ((piVar3[2] == param_1) && (piVar3[3] == param_2)) break;
    piVar1 = (int *)*piVar3;
  }
  *(int *)(*piVar3 + 4) = piVar3[1];
  *(int *)piVar3[1] = *piVar3;
LAB_00169615:
  piVar3[7] = 0;
  if (((int *)0x1e6a43 < piVar3) && (piVar3 < &DAT_001e7244)) {
    *piVar3 = (int)&DAT_001e7248;
    piVar3[1] = (int)DAT_001e724c;
    *(int **)piVar3[1] = piVar3;
    DAT_001e724c = piVar3;
  }
LAB_00169652:
  LOCK();
  DAT_001e7244 = 0;
  UNLOCK();
  _splx(uVar2);
  return;
}

