/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00169bbc */

void _calloutEntryRemove(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = _splsched();
  do {
  } while (DAT_001e7244 != 0);
  LOCK();
  UNLOCK();
  if (param_1[7] == 1) {
    *(int *)(*param_1 + 4) = param_1[1];
    *(int *)param_1[1] = *param_1;
    DAT_001e7260 = DAT_001e7260 + -1;
  }
  else {
    if (param_1[7] != 2) goto LAB_00169c4d;
    *(int *)(*param_1 + 4) = param_1[1];
    *(int *)param_1[1] = *param_1;
  }
  param_1[7] = 0;
  if (((int *)0x1e6a43 < param_1) && (param_1 < &DAT_001e7244)) {
    *param_1 = (int)&DAT_001e7248;
    param_1[1] = (int)DAT_001e724c;
    *(int **)param_1[1] = param_1;
    DAT_001e724c = param_1;
  }
LAB_00169c4d:
  LOCK();
  DAT_001e7244 = 0;
  UNLOCK();
  _splx(uVar1);
  return;
}

