
void sub_407AA5C(int param_1)

{
  undefined4 uVar1;
  undefined auStack_30 [44];
  
  uVar1 = _pmap_kernel(0x40000,10,0,0);
  _dma_list(param_1,param_1 + 0xf8,auStack_30,0x20,uVar1);
  _dma_start(param_1,param_1 + 0xf8,0x40000);
  _delay(10);
  _dma_abort(param_1);
  return;
}

