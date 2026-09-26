
int _tcp_newtcpcb(int param_1)

{
  int iVar1;
  
  iVar1 = _kalloc(0x6c);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    _bzero(iVar1,0x6c);
    *(int *)(iVar1 + 4) = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined2 *)(iVar1 + 0x18) = uRam040aeb72;
    *(undefined *)(iVar1 + 0x1b) = 0;
    *(int *)(iVar1 + 0x20) = param_1;
    *(undefined2 *)(iVar1 + 0x60) = 0;
    *(sword *)(iVar1 + 0x62) = (sword)_tcp_rttdflt << 3;
    *(undefined2 *)(iVar1 + 100) = 2;
    *(undefined2 *)(iVar1 + 0x14) = 0xc;
    *(undefined2 *)(iVar1 + 0x54) = 0xffff;
    *(undefined2 *)(iVar1 + 0x56) = 0xffff;
    *(int *)(param_1 + 0x1c) = iVar1;
  }
  return iVar1;
}

