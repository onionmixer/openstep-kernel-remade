
undefined4 _uninstall_polled_intr(undefined8 param_1)

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
      if ((int)param_1 == *(int *)puVar4) break;
      puVar4 = (undefined *)((int)puVar4 + 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    if (iVar3 < 8) {
      for (; (iVar3 < 7 && (*(int *)puVar4 != 0)); puVar4 = (undefined *)((int)puVar4 + 4)) {
        *(int *)puVar4 = *(int *)((int)puVar4 + 4);
        iVar3 = iVar3 + 1;
      }
      *(int *)puVar4 = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    _printf(aIllegalPolling,uVar1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

