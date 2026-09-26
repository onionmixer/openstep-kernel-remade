
int _udp_usrreq(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_D6;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = 0;
  if (param_2 == 0xb) {
    iVar1 = _in_control(param_1,param_3,param_4,param_5);
    return iVar1;
  }
  if (((param_5 != 0) && (*(sword *)(param_5 + 8) != 0)) || ((iVar1 == 0 && (param_2 != 0)))) {
loc_4025A7E:
    iVar2 = 0x16;
    goto loc_4025BC4;
  }
  switch(param_2) {
  case :
    if (iVar1 == 0) {
      iVar2 = _in_pcballoc(param_1,&_udb);
      if (iVar2 == 0) {
        iVar2 = _soreserve(param_1,_udp_sendspace,_udp_recvspace);
      }
      break;
    }
    goto loc_4025A7E;
  case :
    _in_pcbdetach(iVar1);
    break;
  case :
    iVar2 = _in_pcbbind(iVar1,param_4);
    break;
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
    iVar2 = 0x2d;
    break;
  case :
    if (*(int *)(iVar1 + 0xc) == 0) {
      iVar2 = _in_pcbconnect(iVar1,param_4);
      if (iVar2 == 0) {
        _soisconnected(param_1);
      }
      break;
    }
    goto loc_4025B2C;
  case :
    if (*(int *)(iVar1 + 0xc) != 0) {
      _in_pcbdisconnect(iVar1);
      *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfffd;
      break;
    }
loc_4025B4C:
    iVar2 = 0x39;
    break;
  case :
    _socantsendmore(param_1);
    break;
  case :
  case :
    return 0x2d;
  case :
    if (param_4 == 0) {
      if (*(int *)(iVar1 + 0xc) != 0) goto loc_4025B50;
      goto loc_4025B4C;
    }
    unaff_D6 = *(undefined4 *)(iVar1 + 0x12);
    if (*(int *)(iVar1 + 0xc) == 0) {
      iVar2 = _in_pcbconnect(iVar1,param_4);
      if (iVar2 != 0) break;
loc_4025B50:
      iVar2 = _udp_output(iVar1,param_3);
      param_3 = 0;
      if (param_4 != 0) {
        _in_pcbdisconnect(iVar1);
        *(undefined4 *)(iVar1 + 0x12) = unaff_D6;
      }
      break;
    }
loc_4025B2C:
    iVar2 = 0x38;
    break;
  case :
    _soisdisconnected(param_1);
    _in_pcbdetach(iVar1);
    break;
  :
                    /* WARNING: Subroutine does not return */
    _panic(aUdpUsrreq);
  case :
    return 0;
  case :
    _in_setsockaddr(iVar1,param_4);
    break;
  case :
    _in_setpeeraddr(iVar1,param_4);
  }
loc_4025BC4:
  if (param_3 != 0) {
    _m_freem(param_3);
  }
  return iVar2;
}
