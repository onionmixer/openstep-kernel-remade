
void _dspq_enqueue_syscall(undefined4 *param_1)

{
  undefined4 ***pppuVar1;
  undefined4 ***pppuVar2;
  undefined4 **ppuStack_c;
  undefined4 **ppuStack_8;
  
  ppuStack_c = &ppuStack_c;
  ppuStack_8 = &ppuStack_c;
  pppuVar2 = (undefined4 ***)sub_4082936(0x800c00,0x400);
  *(undefined *)((int)pppuVar2 + 0x21) = 1;
  pppuVar1 = pppuVar2;
  if ((undefined4 ***)ppuStack_8 != &ppuStack_c) {
    ppuStack_8[6] = pppuVar2;
    pppuVar1 = (undefined4 ***)ppuStack_c;
  }
  ppuStack_c = pppuVar1;
  pppuVar2[7] = ppuStack_8;
  pppuVar2[6] = &ppuStack_c;
  ppuStack_8 = pppuVar2;
  pppuVar2 = (undefined4 ***)sub_408288E(0x16);
  *(undefined *)((int)pppuVar2 + 0x21) = 3;
  pppuVar1 = pppuVar2;
  if ((undefined4 ***)ppuStack_8 != &ppuStack_c) {
    ppuStack_8[6] = pppuVar2;
    pppuVar1 = (undefined4 ***)ppuStack_c;
  }
  ppuStack_c = pppuVar1;
  pppuVar2[7] = ppuStack_8;
  pppuVar2[6] = &ppuStack_c;
  ppuStack_8 = pppuVar2;
  pppuVar2 = (undefined4 ***)sub_40828DE();
  *pppuVar2[1] = param_1;
  pppuVar2[2] = (undefined4 **)0x4;
  *(undefined *)((int)pppuVar2 + 0x21) = 2;
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
