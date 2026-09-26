
void _vol_notify_cancel(ushort param_1)

{
  undefined **ppuVar1;
  int *piVar2;
  undefined **ppuVar3;
  int *piVar4;
  
  if (DAT_040b4e81 == '\0') {
    _lock_init(&DAT_040b4e82,1);
    DAT_040b4e81 = '\x01';
  }
  _lock_write(&DAT_040b4e82);
  ppuVar1 = (undefined **)PTR_LOOP_040b06fc;
  while (ppuVar3 = ppuVar1, ppuVar3 != &PTR_LOOP_040b06fc) {
    ppuVar1 = (undefined **)*ppuVar3;
    if (((param_1 & 0xfff8) == *(ushort *)(ppuVar3 + 3)) ||
       ((param_1 & 0xfff8) == *(ushort *)((int)ppuVar3 + 0xe))) {
      piVar2 = (int *)ppuVar3[1];
      piVar4 = piVar2;
      if (ppuVar1 != &PTR_LOOP_040b06fc) {
        ppuVar1[1] = (undefined *)piVar2;
        piVar4 = (int *)PTR_LOOP_040b0700;
      }
      PTR_LOOP_040b0700 = (undefined *)piVar4;
      *piVar2 = (int)ppuVar1;
      _kfree(ppuVar3,0x62);
    }
  }
  _lock_done(&DAT_040b4e82);
  return;
}

