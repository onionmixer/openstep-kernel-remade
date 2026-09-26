
void sub_406B2D4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined auStack_20 [28];
  
  uVar1 = _pmap_kernel(0x40000,10,0,0);
  iVar2 = param_1 + 0x26;
  _dma_list(iVar2,param_1 + 0x11e,auStack_20,0x10,uVar1);
  _dma_start(iVar2,param_1 + 0x11e,0x40000);
  _delay(10);
  _dma_abort(iVar2);
  return;
}

