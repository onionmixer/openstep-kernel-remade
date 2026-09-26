
byte _np_power_off(int *param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  cVar5 = 7 < *(uint *)((int)param_1 + 0x126);
  if (*(uint *)((int)param_1 + 0x126) == 7) {
    _uninstall_scanned_intr(0xb32);
    *(byte *)(*param_1 + 1) = *(byte *)(*param_1 + 1) & 0x7f;
    *(byte *)(*param_1 + 2) = *(byte *)(*param_1 + 2) & 0xfd;
    _np_setstate(param_1,0);
    uVar1 = *(uint *)((int)param_1 + 0x106) & 0xfffffffe;
    *(uint *)((int)param_1 + 0x106) = uVar1;
    cVar2 = (int)uVar1 < 0;
    cVar3 = uVar1 == 0;
    cVar4 = '\0';
    bVar6 = 0;
  }
  else {
    cVar2 = *(int *)((int)param_1 + 0x126) < 0;
    cVar3 = *(int *)((int)param_1 + 0x126) == 0;
    cVar4 = '\0';
    bVar6 = 0;
    if (!(bool)cVar3) {
      _np_setstate(param_1,7);
      cVar2 = (int)param_1 < 0;
      cVar3 = param_1 == (int *)0x0;
      cVar4 = '\0';
      bVar6 = 0;
      _timeout(_np_power_off,param_1,_hz * 5);
    }
  }
  return cVar5 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar6;
}
