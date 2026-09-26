
undefined4 _svckudp_recv(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)((int)param_1 + 0x2e);
  _rsstat = _rsstat + 1;
  iVar2 = _ku_recvfrom(*param_1,(int)param_1 + 0xe);
  if (iVar2 == 0) {
    dword_40BC1F4 = dword_40BC1F4 + 1;
  }
  else {
    if (*(word *)(iVar2 + 8) < 0x10) {
      dword_40BC1F8 = dword_40BC1F8 + 1;
    }
    else {
      _xdrmbuf_init(iVar1 + 0xc,iVar2,1);
      iVar3 = _xdr_callmsg(iVar1 + 0xc,param_2);
      if (iVar3 != 0) {
        *(undefined4 *)(iVar1 + 4) = *param_2;
        *(int *)(iVar1 + 8) = iVar2;
        return 1;
      }
      dword_40BC1FC = dword_40BC1FC + 1;
    }
    _m_freem(iVar2);
    *(undefined4 *)(iVar1 + 8) = 0;
    dword_40BC1F0 = dword_40BC1F0 + 1;
  }
  return 0;
}

