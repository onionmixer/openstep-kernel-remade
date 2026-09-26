
void _enintsetup(void)

{
  int iVar1;
  
  iVar1 = _slot_id_bmap;
  if (_dma_chip != 0x139) {
    *(undefined *)(_slot_id_bmap + 0x2006004) = 4;
    _delay(500000);
    *(undefined *)(iVar1 + 0x2006001) = 0;
    sub_408DBD2(iVar1 + 0x2006003,0);
  }
  return;
}
