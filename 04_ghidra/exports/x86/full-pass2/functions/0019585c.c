/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019585c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0019585c(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  do {
  } while (DAT_001e7774 != 0);
  LOCK();
  DAT_001e7774 = 1;
  UNLOCK();
  if (_kmId == 0) {
    iVar3 = 1;
    iVar2 = _basicConsole;
    if (_DAT_0001114c != 0) {
      iVar3 = 2;
    }
  }
  else {
    iVar2 = *(int *)(_kmId + 0x10c);
    iVar3 = *(int *)(_kmId + 0x114);
  }
  if (0 < DAT_001e38e8) {
    if (iVar3 == 2) {
      if (iVar2 != 0) {
        (**(code **)(iVar2 + 0xc))(iVar2,DAT_001e38e8 * 0xc + 0x1e384c);
      }
      DAT_001e38e8 = DAT_001e38e8 + 1;
      if (3 < DAT_001e38e8) {
        DAT_001e38e8 = 1;
      }
      _ns_timeout(FUN_0019585c,0,0x69f6bc7,0,4);
    }
    else {
      DAT_001e38e8 = -DAT_001e38e8;
    }
  }
  uVar1 = DAT_001e7774;
  LOCK();
  DAT_001e7774 = 0;
  UNLOCK();
  return uVar1;
}

