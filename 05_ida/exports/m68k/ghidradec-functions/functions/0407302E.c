
undefined4 _np_power_on(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined auStack_c [4];
  int iStack_8;
  
  iVar1 = *param_1;
  if (*(int *)((int)param_1 + 0x126) == 7) {
    do {
      _sleep((int *)((int)param_1 + 0x126),0x14);
    } while (*(int *)((int)param_1 + 0x126) == 7);
  }
  *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) & 0xfd;
  *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) | 2;
  *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) | 0x80;
  _np_nap(_hz * 3,param_1);
  _np_send(iVar1,0xff,0xffffffff);
  _delay(10);
  do {
    iVar2 = _np_recv(iVar1,&iStack_8,auStack_c);
  } while (iVar2 != 0);
  _np_send(iVar1,4,0);
  iVar2 = 0x28;
  do {
    iVar3 = _np_recv(iVar1,&iStack_8,auStack_c);
    if ((iVar3 != 0) && (iStack_8 == 0xc4)) break;
    iVar2 = iVar2 + -1;
  } while (0 < iVar2);
  if (iVar2 < 1) {
    *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) & 0x7f;
    *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) & 0xfd;
    uVar4 = 0x13;
  }
  else {
    param_1[0x3f] = 0;
    _install_scanned_intr(0xb32,_np_dev_intr,param_1);
    _np_setstate(param_1,1);
    uVar4 = 0;
  }
  return uVar4;
}
