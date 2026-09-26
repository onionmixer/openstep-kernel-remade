
void sub_408A352(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = _slot_id;
  puVar3 = (undefined4 *)(_slot_id + 0x2200080);
  uVar2 = 0x538;
  if (_dma_chip != 0x139) {
    uVar2 = 0xd30;
  }
  _install_scanned_intr(uVar2,sub_408A3BC,0);
  if (_dma_chip == 0x139) {
    *(undefined4 *)(iVar1 + 0x2004184) = 0xea;
  }
  else {
    *puVar3 = 0x6000000;
  }
  return;
}

