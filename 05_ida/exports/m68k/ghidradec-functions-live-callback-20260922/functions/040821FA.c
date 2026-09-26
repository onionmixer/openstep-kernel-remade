
void sub_40821FA(int param_1,uint param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_5 != 0x40000) || (param_2 == 0)) {
    uVar1 = 0;
    if ((param_1 == 0) && (param_3 == 4)) {
      uVar1 = param_2;
    }
    uVar1 = uVar1 & 0x1f;
    if (param_5 == 0x40000) {
      uVar2 = uVar1 | 0x10000;
    }
    else {
      uVar2 = uVar1 | 0x20000;
      if ((param_4 == 4) && (_dma_chip == 0x139)) {
        uVar2 = CONCAT22(2,(sword)uVar1) | 0x8000;
      }
    }
    dword_40C6E84 = dword_40C6E84 | 0x40;
    _dspq_enqueue_syscall(uVar2);
    _dspq_enqueue_cond(0x800000,0);
    dword_40C6E84 = dword_40C6E84 & 0xffffffbf;
    _dspq_execute();
  }
  return;
}

