
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 _led_msg(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    puVar1 = (undefined1 *)(iVar2 + param_1);
    out(0xcaf - (short)iVar2,*puVar1);
    LOCK();
    _DAT_001e7730 = _DAT_001e7730 + 1;
    UNLOCK();
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return *puVar1;
}

