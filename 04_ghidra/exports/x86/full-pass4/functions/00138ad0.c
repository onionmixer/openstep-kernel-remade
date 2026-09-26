/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00138ad0 */

undefined4 FUN_00138ad0(int *param_1,uint param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = _set_label((int *)(DAT_001e875c + 0x28));
  if (iVar2 == 0) {
    iVar2 = *(int *)(*param_1 + 0x30);
    if (((param_2 & 1) != 0) &&
       (sVar1 = *(short *)(iVar2 + 0x82), *(short *)(iVar2 + 0x82) = sVar1 + 1, sVar1 == 0)) {
      _wakeup(iVar2 + 0x82);
    }
    if ((param_2 & 2) != 0) {
      if (((param_2 & 4) != 0) && (*(short *)(iVar2 + 0x82) == 0)) {
        return 6;
      }
      sVar1 = *(short *)(iVar2 + 0x80);
      *(short *)(iVar2 + 0x80) = sVar1 + 1;
      if (sVar1 == 0) {
        _wakeup(iVar2 + 0x80);
      }
    }
    if ((param_2 & 1) != 0) {
      sVar1 = *(short *)(iVar2 + 0x80);
      while (sVar1 == 0) {
        if (((param_2 & 4) != 0) || (*(int *)(iVar2 + 0x7c) != 0)) {
          return 0;
        }
        _sleep(iVar2 + 0x80);
        sVar1 = *(short *)(iVar2 + 0x80);
      }
    }
    if (((param_2 & 2) != 0) && (*(short *)(iVar2 + 0x82) == 0)) {
      do {
        _sleep(iVar2 + 0x82);
      } while (*(short *)(iVar2 + 0x82) == 0);
    }
    uVar3 = 0;
  }
  else {
    FUN_00138bfc(*param_1,param_2 & 0x4b,1,param_3);
    uVar3 = 4;
  }
  return uVar3;
}

