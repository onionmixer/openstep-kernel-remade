
int _tcp_attach(int param_1)

{
  undefined4 uVar1;
  word wVar2;
  int iVar3;
  
  if (((*(sword *)(param_1 + 0x3a) == 0) || (*(sword *)(param_1 + 0x24) == 0)) &&
     (iVar3 = _soreserve(param_1,_tcp_sendspace,_tcp_recvspace), iVar3 != 0)) {
    return iVar3;
  }
  iVar3 = _in_pcballoc(param_1,&_tcb);
  if (iVar3 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 8);
    iVar3 = _tcp_newtcpcb(uVar1);
    if (iVar3 == 0) {
      wVar2 = *(word *)(param_1 + 6);
      *(word *)(param_1 + 6) = wVar2 & 0xfffe;
      _in_pcbdetach(uVar1);
      *(word *)(param_1 + 6) = wVar2 & 1 | *(word *)(param_1 + 6);
      iVar3 = 0x37;
    }
    else {
      *(undefined2 *)(iVar3 + 8) = 0;
      iVar3 = 0;
    }
  }
  return iVar3;
}
