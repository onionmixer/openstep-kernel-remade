
int sub_4089EB6(void)

{
  int iVar1;
  uint uStack_8;
  
  if (_dma_chip == 0x139) {
    uStack_8 = _slot_id + 0xb000000;
  }
  else {
    uStack_8 = _slot_id + 0xc000000;
  }
  uStack_8 = uStack_8 & 0xff000000;
  iVar1 = _vm_allocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),&uStack_8,0x1000000,0);
  if (iVar1 == 0) {
    _pmap_tt(_active_threads,1,uStack_8,0x1000000,0);
    if (_dma_chip == 0x139) {
      iVar1 = _slot_id + 0xb000000;
    }
    else {
      iVar1 = _slot_id + 0xc000000;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
