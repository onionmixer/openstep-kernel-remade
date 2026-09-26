
void sub_408ABCA(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  
  puVar2 = (undefined *)(_slot_id_bmap + 0x2018180);
  puVar1 = (undefined4 *)(_slot_id + 0x2200080);
  if (_dma_chip == 0x139) {
    *puVar2 = 5;
  }
  else {
    *puVar1 = 0x5000000;
  }
  if (dword_40B2286 != (code *)0x0) {
    (*dword_40B2286)(dword_40B5188);
  }
  if (_dma_chip == 0x139) {
    *puVar2 = 6;
  }
  else {
    *puVar1 = 0x6000000;
  }
  return;
}
