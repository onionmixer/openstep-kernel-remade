
void sub_4089F58(void)

{
  uint uVar1;
  
  if (_dma_chip == 0x139) {
    uVar1 = _slot_id + 0xb000000;
  }
  else {
    uVar1 = _slot_id + 0xc000000;
  }
  _vm_deallocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),uVar1 & 0xff000000,0x1000000);
  _pmap_tt(_active_threads,0,0,0,0);
  return;
}
