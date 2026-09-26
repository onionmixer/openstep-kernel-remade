
void _en_rx_devintr(int param_1)

{
  int iVar1;
  byte bVar3;
  int iVar2;
  
  iVar1 = *(int *)((int)&DAT_40c9132 + param_1 * 0x52c);
  iVar2 = iVar1 + 2;
  bVar3 = sub_408DB8A(iVar2);
  sub_408DBD2(iVar2,0xff);
  if ((bVar3 & 0x40) != 0) {
    iVar2 = _if_collisions((&_en_softc)[param_1 * 0x14b]);
    _if_collisions_set((&_en_softc)[param_1 * 0x14b],iVar2 + 1);
  }
  if ((bVar3 & 1) != 0) {
    iVar1 = iVar1 + 5;
    bVar3 = sub_408DB8A(iVar1);
    sub_408DBD2(iVar1,bVar3 | 0x80);
  }
  return;
}

