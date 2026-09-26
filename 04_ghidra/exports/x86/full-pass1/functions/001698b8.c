/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001698b8 */

void _calloutEntryDispatchWithArgument(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = _splsched();
  do {
  } while (DAT_001e7244 != 0);
  LOCK();
  DAT_001e7244 = 1;
  UNLOCK();
  if (param_1[7] == 0) {
    param_1[3] = param_2;
    param_1[5] = 0;
    param_1[6] = 0;
    *param_1 = &DAT_001e7250;
    param_1[1] = DAT_001e7254;
    *(undefined4 **)param_1[1] = param_1;
    DAT_001e7254 = param_1;
    DAT_001e7260 = DAT_001e7260 + 1;
    param_1[7] = 1;
    FUN_00169c64();
  }
  else {
    LOCK();
    DAT_001e7244 = 0;
    UNLOCK();
  }
  _splx(uVar1);
  return;
}

