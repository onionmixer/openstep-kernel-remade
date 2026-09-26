
void sub_408A3BC(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(_slot_id + 0x2200080);
  if (_dma_chip == 0x139) {
    *(undefined4 *)(_slot_id + 0x2000180) = 0x100000;
  }
  else {
    *puVar1 = 0x5000000;
  }
  if (dword_40B2286 != (code *)0x0) {
    (*dword_40B2286)(dword_40B5188);
  }
  if (_dma_chip != 0x139) {
    *puVar1 = 0x6000000;
  }
  return;
}
