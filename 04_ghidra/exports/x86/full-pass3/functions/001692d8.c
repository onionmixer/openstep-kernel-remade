/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001692d8 */

void _calloutDispatchUnique(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (DAT_001dfcbc == 0) {
    return;
  }
  uVar3 = _splsched();
  piVar2 = DAT_001e7248;
  do {
  } while (DAT_001e7244 != 0);
  LOCK();
  DAT_001e7244 = 1;
  UNLOCK();
  puVar4 = DAT_001e7250;
  if ((undefined4 **)DAT_001e7250 != &DAT_001e7250) {
    do {
      if ((puVar4[2] == param_1) && (puVar4[3] == param_2)) break;
      puVar4 = (undefined4 *)*puVar4;
    } while ((undefined4 **)puVar4 != &DAT_001e7250);
    if ((undefined4 **)puVar4 != &DAT_001e7250) {
      LOCK();
      DAT_001e7244 = 0;
      UNLOCK();
      goto LAB_001693dc;
    }
  }
  if ((int **)DAT_001e7248 == &DAT_001e7248) {
                    /* WARNING: Subroutine does not return */
    _panic(s_internalEntryAllocate_001dfcc0);
  }
  *(int ***)(*DAT_001e7248 + 4) = &DAT_001e7248;
  piVar1 = DAT_001e7248 + 2;
  DAT_001e7248 = (int *)*DAT_001e7248;
  *piVar1 = param_1;
  piVar2[3] = param_2;
  piVar2[4] = 0;
  piVar2[5] = 0;
  piVar2[6] = 0;
  *piVar2 = (int)&DAT_001e7250;
  piVar2[1] = (int)DAT_001e7254;
  *(int **)piVar2[1] = piVar2;
  DAT_001e7254 = piVar2;
  DAT_001e7260 = DAT_001e7260 + 1;
  piVar2[7] = 1;
  FUN_00169c64();
LAB_001693dc:
  _splx(uVar3);
  return;
}

