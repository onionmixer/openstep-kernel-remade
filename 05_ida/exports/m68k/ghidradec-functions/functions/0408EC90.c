
void _en_tx_devintr(int param_1)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = *(byte **)((int)&DAT_40c9132 + param_1 * 0x52c);
  if ((*pbVar1 & 4) != 0) {
    iVar2 = _if_collisions((&_en_softc)[param_1 * 0x14b]);
    _if_collisions_set((&_en_softc)[param_1 * 0x14b],iVar2 + 1);
  }
  if (_dma_chip == 0x139) {
    *pbVar1 = *pbVar1 | 4;
  }
  else {
    *(byte *)(&DAT_40c945e + param_1 * 0x296) = *pbVar1;
    *pbVar1 = 0xff;
    _callout_dispatch(1,_en_tx_dmaintr,param_1);
  }
  return;
}
