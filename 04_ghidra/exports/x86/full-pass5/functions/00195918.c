/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00195918 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __regparm3 _kmEnableAnimation(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_001e7778 == 0) {
    DAT_001e7774 = 0;
    DAT_001e7778 = 1;
  }
  if (_DAT_0001114c != 0) {
    do {
    } while (DAT_001e7774 != 0);
    LOCK();
    UNLOCK();
    DAT_001e38e8 = 1;
    LOCK();
    UNLOCK();
    LOCK();
    DAT_001e7774 = 1;
    UNLOCK();
    if (_kmId == 0) {
      iVar2 = 1;
      iVar1 = _basicConsole;
      if (_DAT_0001114c != 0) {
        iVar2 = 2;
      }
    }
    else {
      iVar1 = *(int *)(_kmId + 0x10c);
      iVar2 = *(int *)(_kmId + 0x114);
    }
    if (iVar2 == 2) {
      if (iVar1 != 0) {
        (**(code **)(iVar1 + 0xc))(iVar1,&DAT_001e3858);
      }
      DAT_001e38e8 = DAT_001e38e8 + 1;
      if (3 < DAT_001e38e8) {
        DAT_001e38e8 = 1;
      }
      _ns_timeout(FUN_0019585c,0,0x69f6bc7,0,4);
    }
    else {
      DAT_001e38e8 = -1;
    }
    param_1 = DAT_001e7774;
    LOCK();
    DAT_001e7774 = 0;
    UNLOCK();
  }
  return param_1;
}

