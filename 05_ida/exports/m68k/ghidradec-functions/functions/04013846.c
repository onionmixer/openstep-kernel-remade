
void _sorflush(int param_1)

{
  int iVar1;
  code *pcVar2;
  word wVar3;
  undefined4 uStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  undefined4 uStack_a;
  undefined2 uStack_6;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if ((*(byte *)(param_1 + 0x37) & 1) != 0) {
    do {
      *(word *)(param_1 + 0x36) = *(word *)(param_1 + 0x36) | 2;
      _sleep(param_1 + 0x36,0x1a);
    } while ((*(byte *)(param_1 + 0x37) & 1) != 0);
  }
  *(word *)(param_1 + 0x36) = *(word *)(param_1 + 0x36) | 1;
  _socantrcvmore(param_1);
  wVar3 = *(word *)(param_1 + 0x36);
  *(word *)(param_1 + 0x36) = wVar3 & 0xfffe;
  if ((wVar3 & 2) != 0) {
    *(word *)(param_1 + 0x36) = wVar3 & 0xfffc;
    _wakeup(param_1 + 0x36);
  }
  uStack_1a = *(undefined4 *)(param_1 + 0x22);
  uStack_16 = *(undefined4 *)(param_1 + 0x26);
  uStack_12 = *(undefined4 *)(param_1 + 0x2a);
  uStack_e = *(undefined4 *)(param_1 + 0x2e);
  uStack_a = *(undefined4 *)(param_1 + 0x32);
  uStack_6 = *(undefined2 *)(param_1 + 0x36);
  _bzero((undefined4 *)(param_1 + 0x22),0x16);
  if (((*(byte *)(iVar1 + 9) & 0x10) != 0) &&
     (pcVar2 = *(code **)(*(int *)(iVar1 + 2) + 0x10), pcVar2 != (code *)0x0)) {
    (*pcVar2)(uStack_e);
  }
  _sbrelease(&uStack_1a);
  return;
}
