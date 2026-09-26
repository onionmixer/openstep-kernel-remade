/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016966c */

void _calloutRemoveAll(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = _splsched();
  do {
  } while (DAT_001e7244 != 0);
  LOCK();
  UNLOCK();
  puVar1 = DAT_001e7250;
  while (puVar3 = puVar1, puVar1 = DAT_001e7258, (undefined4 **)puVar3 != &DAT_001e7250) {
    if ((puVar3[2] == param_1) && (puVar3[3] == param_2)) {
      puVar1 = (undefined4 *)*puVar3;
      puVar1[1] = puVar3[1];
      *(undefined4 *)puVar3[1] = *puVar3;
      DAT_001e7260 = DAT_001e7260 + -1;
      puVar3[7] = 0;
      if (((undefined4 *)0x1e6a43 < puVar3) && (puVar3 < &DAT_001e7244)) {
        *puVar3 = &DAT_001e7248;
        puVar3[1] = DAT_001e724c;
        *(undefined4 **)puVar3[1] = puVar3;
        DAT_001e724c = puVar3;
      }
    }
    else {
      puVar1 = (undefined4 *)*puVar3;
    }
  }
  while (puVar3 = puVar1, (undefined4 **)puVar3 != &DAT_001e7258) {
    if ((puVar3[2] == param_1) && (puVar3[3] == param_2)) {
      puVar1 = (undefined4 *)*puVar3;
      puVar1[1] = puVar3[1];
      *(undefined4 *)puVar3[1] = *puVar3;
      puVar3[7] = 0;
      if (((undefined4 *)0x1e6a43 < puVar3) && (puVar3 < &DAT_001e7244)) {
        *puVar3 = &DAT_001e7248;
        puVar3[1] = DAT_001e724c;
        *(undefined4 **)puVar3[1] = puVar3;
        DAT_001e724c = puVar3;
      }
    }
    else {
      puVar1 = (undefined4 *)*puVar3;
    }
  }
  LOCK();
  DAT_001e7244 = 0;
  UNLOCK();
  _splx(uVar2);
  return;
}

