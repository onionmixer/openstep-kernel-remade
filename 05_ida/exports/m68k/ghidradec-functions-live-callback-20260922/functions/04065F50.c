
undefined4 _install_polled_intr(undefined8 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar1 = (param_1._3_4_ & 0x7fffffff) >> 0x1c;
  if (uVar1 == 5) {
    puVar4 = _poll_intr;
    iVar3 = 0;
    do {
      if (*(int *)puVar4 == 0) break;
      puVar4 = (undefined *)((int)puVar4 + 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    if (7 < iVar3) {
                    /* WARNING: Subroutine does not return */
      _panic(aTooManyPolledI);
    }
    *(int *)puVar4 = *(int *)((int)puVar4 + -4);
    *(int *)((int)puVar4 + -4) = (int)param_1;
    uVar2 = 0;
  }
  else {
    _printf(aIllegalPolling,uVar1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

