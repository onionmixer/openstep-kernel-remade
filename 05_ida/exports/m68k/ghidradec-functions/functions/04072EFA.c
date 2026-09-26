
byte _np_setstate(int param_1,uint param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  *(uint *)(param_1 + 0x126) = param_2;
  cVar4 = 1 < param_2;
  if (param_2 == 1) {
    cVar1 = param_1 < 0;
    cVar2 = param_1 == 0;
    cVar3 = '\0';
    bVar5 = 0;
    _callout_dispatch(4,_np_init_printer,param_1);
    goto loc_4072FB6;
  }
  if (param_2 != 0) {
    cVar4 = 2 < param_2;
    if (param_2 == 2) {
      cVar1 = *(int *)(param_1 + 0x11e) < 0;
      cVar3 = '\0';
      cVar2 = '\x01';
      bVar5 = 0;
      if (*(int *)(param_1 + 0x11e) != 0) {
        _selwakeup(*(undefined4 *)(param_1 + 0x11e),*(uint *)(param_1 + 0x106) & 0x40);
        *(uint *)(param_1 + 0x106) = *(uint *)(param_1 + 0x106) & 0xffffffbf;
        _thread_deallocate_interrupt(*(undefined4 *)(param_1 + 0x11e));
        *(undefined4 *)(param_1 + 0x11e) = 0;
        cVar1 = '\0';
        cVar2 = '\x01';
        cVar3 = '\0';
        bVar5 = 0;
      }
      goto loc_4072FB6;
    }
    cVar4 = 6 < param_2;
    cVar3 = SBORROW4(6,param_2);
    cVar1 = (int)(6 - param_2) < 0;
    cVar2 = param_2 == 6;
    bVar5 = cVar4;
    if (!(bool)cVar2) goto loc_4072FB6;
  }
  cVar1 = *(int *)(param_1 + 0x122) < 0;
  cVar3 = '\0';
  cVar2 = '\x01';
  bVar5 = 0;
  if (*(int *)(param_1 + 0x122) != 0) {
    _selwakeup(*(undefined4 *)(param_1 + 0x122),*(uint *)(param_1 + 0x106) & 0x80);
    *(uint *)(param_1 + 0x106) = *(uint *)(param_1 + 0x106) & 0xffffff7f;
    _thread_deallocate_interrupt(*(undefined4 *)(param_1 + 0x11e));
    *(undefined4 *)(param_1 + 0x122) = 0;
    cVar1 = '\0';
    cVar2 = '\x01';
    cVar3 = '\0';
    bVar5 = 0;
  }
loc_4072FB6:
  _wakeup(param_1 + 0x126);
  return cVar4 << 4 | cVar1 << 3 | cVar2 << 2 | cVar3 << 1 | bVar5;
}
