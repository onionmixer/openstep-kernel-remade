
int _tcp_usrreq(int param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int unaff_A3;
  
  iVar3 = 0;
  if (param_2 == 0xb) {
    iVar3 = _in_control(param_1,param_3,param_4,param_5);
  }
  else if ((param_5 == 0) || (*(sword *)(param_5 + 8) == 0)) {
    iVar2 = *(int *)(param_1 + 8);
    if (iVar2 == 0) {
      if (param_2 != 0) {
        return 0x16;
      }
      iVar4 = 0;
    }
    else {
      unaff_A3 = *(int *)(iVar2 + 0x1c);
      iVar4 = (int)*(sword *)(unaff_A3 + 8);
    }
    switch(param_2) {
    case :
      if (iVar2 == 0) {
        iVar3 = _tcp_attach(param_1);
        if (iVar3 == 0) {
          if ((*(char *)(param_1 + 3) < '\0') && (*(sword *)(param_1 + 4) == 0)) {
            *(undefined2 *)(param_1 + 4) = 0x78;
          }
          unaff_A3 = *(int *)(*(int *)(param_1 + 8) + 0x1c);
        }
      }
      else {
        iVar3 = 0x38;
      }
      break;
    case :
      if (*(sword *)(unaff_A3 + 8) < 2) {
        unaff_A3 = _tcp_close(unaff_A3);
      }
      else {
        unaff_A3 = _tcp_disconnect(unaff_A3);
      }
      break;
    case :
      iVar3 = _in_pcbbind(iVar2,param_4);
      break;
    case :
      if (*(sword *)(iVar2 + 0x16) == 0) {
        iVar3 = _in_pcbbind(iVar2,0);
      }
      if (iVar3 == 0) {
        *(undefined2 *)(unaff_A3 + 8) = 1;
      }
      break;
    case :
      if (((*(sword *)(iVar2 + 0x16) != 0) || (iVar3 = _in_pcbbind(iVar2,0), iVar3 == 0)) &&
         (iVar3 = _in_pcbconnect(iVar2,param_4), iVar3 == 0)) {
        iVar3 = _tcp_template(unaff_A3);
        *(int *)(unaff_A3 + 0x1c) = iVar3;
        if (iVar3 == 0) {
          _in_pcbdisconnect(iVar2);
          iVar3 = 0x37;
        }
        else {
          _soisconnecting(param_1);
          _tcpstat = _tcpstat + 1;
          *(undefined2 *)(unaff_A3 + 8) = 2;
          *(undefined2 *)(unaff_A3 + 0xe) = 0x96;
          *(int *)(unaff_A3 + 0x38) = _tcp_iss;
          _tcp_iss = _tcp_iss + 64000;
          uVar1 = *(undefined4 *)(unaff_A3 + 0x38);
          *(undefined4 *)(unaff_A3 + 0x2c) = uVar1;
          *(undefined4 *)(unaff_A3 + 0x50) = uVar1;
          *(undefined4 *)(unaff_A3 + 0x28) = uVar1;
          *(undefined4 *)(unaff_A3 + 0x24) = uVar1;
          iVar3 = _tcp_output(unaff_A3);
        }
      }
      break;
    case :
      puVar5 = (undefined2 *)(*(int *)(param_4 + 4) + param_4);
      *(undefined2 *)(param_4 + 8) = 0x10;
      *puVar5 = 2;
      puVar5[1] = *(undefined2 *)(iVar2 + 0x10);
      *(undefined4 *)(puVar5 + 2) = *(undefined4 *)(iVar2 + 0xc);
      break;
    case :
      unaff_A3 = _tcp_disconnect(unaff_A3);
      break;
    case :
      _socantsendmore(param_1);
      unaff_A3 = _tcp_usrclosed(unaff_A3);
      if (unaff_A3 == 0) {
        return 0;
      }
      iVar3 = _tcp_output(unaff_A3);
      break;
    case :
      _tcp_output(unaff_A3);
      break;
    case :
      _sbappend(param_1 + 0x38,param_3);
      iVar3 = _tcp_output(unaff_A3);
      break;
    case :
      unaff_A3 = _tcp_drop(unaff_A3,0x35);
      break;
    :
                    /* WARNING: Subroutine does not return */
      _panic(aTcpUsrreq);
    case :
      *(uint *)(param_3 + 0x2c) = (uint)*(word *)(param_1 + 0x3a);
      return 0;
    case :
      if ((((*(sword *)(param_1 + 0x52) == 0) && ((*(byte *)(param_1 + 7) & 0x40) == 0)) ||
          ((*(byte *)(param_1 + 2) & 1) != 0)) || ((*(byte *)(unaff_A3 + 0x68) & 2) != 0)) {
        iVar3 = 0x16;
      }
      else if ((*(byte *)(unaff_A3 + 0x68) & 1) == 0) {
        iVar3 = 0x23;
      }
      else {
        *(undefined2 *)(param_3 + 8) = 1;
        *(undefined *)(param_3 + *(int *)(param_3 + 4)) = *(undefined *)(unaff_A3 + 0x69);
        if ((param_4 & 2) == 0) {
          *(byte *)(unaff_A3 + 0x68) = *(byte *)(unaff_A3 + 0x68) ^ 3;
        }
      }
      break;
    case :
      iVar3 = (uint)*(word *)(param_1 + 0x3e) - (uint)*(word *)(param_1 + 0x3c);
      iVar2 = (uint)*(word *)(param_1 + 0x3a) - (uint)*(word *)(param_1 + 0x38);
      if (iVar3 < iVar2) {
        iVar2 = iVar3;
      }
      if (iVar2 < -0x200) {
        _m_freem(param_3);
        iVar3 = 0x37;
      }
      else {
        _sbappend((word *)(param_1 + 0x38),param_3);
        *(uint *)(unaff_A3 + 0x2c) = *(int *)(unaff_A3 + 0x24) + (uint)*(word *)(param_1 + 0x38);
        *(undefined *)(unaff_A3 + 0x1a) = 1;
        iVar3 = _tcp_output(unaff_A3);
        *(undefined *)(unaff_A3 + 0x1a) = 0;
      }
      break;
    case :
      _in_setsockaddr(iVar2,param_4);
      break;
    case :
      _in_setpeeraddr(iVar2,param_4);
      break;
    case :
      iVar3 = 0x2d;
      break;
    case :
      unaff_A3 = _tcp_timers(unaff_A3,param_4);
      param_2 = param_4 << 8 | param_2;
    }
    if ((unaff_A3 != 0) && ((*(byte *)(param_1 + 3) & 1) != 0)) {
      _tcp_trace(2,iVar4,unaff_A3,0,param_2);
    }
  }
  else {
    iVar3 = 0x16;
  }
  return iVar3;
}
