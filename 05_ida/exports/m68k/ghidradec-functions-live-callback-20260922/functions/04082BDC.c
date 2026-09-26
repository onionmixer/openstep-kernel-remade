
void _dspq_enqueue_hf(undefined4 param_1,undefined4 param_2)

{
  undefined4 ***pppuVar1;
  undefined4 ***pppuVar2;
  undefined4 **ppuStack_c;
  undefined4 **ppuStack_8;
  
  ppuStack_c = &ppuStack_c;
  ppuStack_8 = &ppuStack_c;
  pppuVar2 = (undefined4 ***)sub_408298E(param_1,param_2);
  *(undefined *)((int)pppuVar2 + 0x21) = 0;
  pppuVar1 = pppuVar2;
  if ((undefined4 ***)ppuStack_8 != &ppuStack_c) {
    ppuStack_8[6] = pppuVar2;
    pppuVar1 = (undefined4 ***)ppuStack_c;
  }
  ppuStack_c = pppuVar1;
  pppuVar2[7] = ppuStack_8;
  pppuVar2[6] = &ppuStack_c;
  ppuStack_8 = pppuVar2;
  _dspq_enqueue(&ppuStack_c);
  return;
}

