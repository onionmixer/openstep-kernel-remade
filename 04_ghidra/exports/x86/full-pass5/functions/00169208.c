/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00169208 */

void _calloutDispatch(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  
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
    _splx(uVar3);
  }
  return;
}

