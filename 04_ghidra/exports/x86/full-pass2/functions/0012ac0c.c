/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012ac0c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _tcp_usrreq(int param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  int unaff_EBX;
  int iVar4;
  int iVar5;
  int local_c;
  
  iVar5 = 0;
  if (param_2 == 0xb) {
    iVar5 = _in_control(param_1,param_3,param_4,param_5);
    return iVar5;
  }
  if ((param_5 != 0) && (*(short *)(param_5 + 8) != 0)) {
    return 0x16;
  }
  uVar2 = _splnet();
  iVar4 = *(int *)(param_1 + 8);
  if (iVar4 == 0) {
    if (param_2 != 0) {
      _splx(uVar2);
      return 0x16;
    }
    local_c = 0;
  }
  else {
    unaff_EBX = *(int *)(iVar4 + 0x20);
    local_c = (int)*(short *)(unaff_EBX + 8);
  }
  switch(param_2) {
  case 0:
    if (iVar4 == 0) {
      iVar5 = _tcp_attach(param_1);
      if (iVar5 == 0) {
        if ((*(char *)(param_1 + 2) < '\0') && (*(short *)(param_1 + 4) == 0)) {
          *(undefined2 *)(param_1 + 4) = 0x78;
        }
        unaff_EBX = *(int *)(*(int *)(param_1 + 8) + 0x20);
      }
    }
    else {
      iVar5 = 0x38;
    }
    break;
  case 1:
    if (*(short *)(unaff_EBX + 8) < 2) {
      unaff_EBX = _tcp_close(unaff_EBX);
    }
    else {
      unaff_EBX = _tcp_disconnect(unaff_EBX);
    }
    break;
  case 2:
    iVar5 = _in_pcbbind(iVar4,param_4);
    break;
  case 3:
    if (*(short *)(iVar4 + 0x18) == 0) {
      iVar5 = _in_pcbbind(iVar4,0);
    }
    if (iVar5 == 0) {
      *(undefined2 *)(unaff_EBX + 8) = 1;
    }
    break;
  case 4:
    if (((*(short *)(iVar4 + 0x18) != 0) || (iVar5 = _in_pcbbind(iVar4,0), iVar5 == 0)) &&
       (iVar5 = _in_pcbconnect(iVar4,param_4), iVar5 == 0)) {
      iVar5 = _tcp_template(unaff_EBX);
      *(int *)(unaff_EBX + 0x1c) = iVar5;
      if (iVar5 == 0) {
        _in_pcbdisconnect(iVar4);
        iVar5 = 0x37;
      }
      else {
        _soisconnecting(param_1);
        __tcpstat = __tcpstat + 1;
        *(undefined2 *)(unaff_EBX + 8) = 2;
        *(undefined2 *)(unaff_EBX + 0xe) = 0x96;
        *(int *)(unaff_EBX + 0x38) = _tcp_iss;
        _tcp_iss = _tcp_iss + 64000;
        uVar1 = *(undefined4 *)(unaff_EBX + 0x38);
        *(undefined4 *)(unaff_EBX + 0x2c) = uVar1;
        *(undefined4 *)(unaff_EBX + 0x50) = uVar1;
        *(undefined4 *)(unaff_EBX + 0x28) = uVar1;
        *(undefined4 *)(unaff_EBX + 0x24) = uVar1;
        iVar5 = _tcp_output(unaff_EBX);
      }
    }
    break;
  case 5:
    puVar3 = (undefined2 *)(param_4 + *(int *)(param_4 + 4));
    *(undefined2 *)(param_4 + 8) = 0x10;
    *puVar3 = 2;
    puVar3[1] = *(undefined2 *)(iVar4 + 0x10);
    *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(iVar4 + 0xc);
    break;
  case 6:
    unaff_EBX = _tcp_disconnect(unaff_EBX);
    break;
  case 7:
    _socantsendmore(param_1);
    unaff_EBX = _tcp_usrclosed(unaff_EBX);
    if (unaff_EBX == 0) goto LAB_0012b04b;
    iVar5 = _tcp_output(unaff_EBX);
    break;
  case 8:
    _tcp_output(unaff_EBX);
    break;
  case 9:
    _sbappend(param_1 + 0x3c,param_3);
    iVar5 = _tcp_output(unaff_EBX);
    break;
  case 10:
    unaff_EBX = _tcp_drop(unaff_EBX,0x35);
    break;
  default:
                    /* WARNING: Subroutine does not return */
    _panic(s_tcp_usrreq_001dbed8);
  case 0xc:
    *(uint *)(param_3 + 0x30) = (uint)*(ushort *)(param_1 + 0x3e);
    _splx(uVar2);
    return 0;
  case 0xd:
    if ((((*(short *)(param_1 + 0x58) == 0) && ((*(byte *)(param_1 + 6) & 0x40) == 0)) ||
        ((*(byte *)(param_1 + 3) & 1) != 0)) || ((*(byte *)(unaff_EBX + 0x68) & 2) != 0)) {
      iVar5 = 0x16;
    }
    else if ((*(byte *)(unaff_EBX + 0x68) & 1) == 0) {
      iVar5 = 0x23;
    }
    else {
      *(undefined2 *)(param_3 + 8) = 1;
      *(undefined1 *)(*(int *)(param_3 + 4) + param_3) = *(undefined1 *)(unaff_EBX + 0x69);
      if ((param_4 & 2) == 0) {
        *(byte *)(unaff_EBX + 0x68) = *(byte *)(unaff_EBX + 0x68) ^ 3;
      }
    }
    break;
  case 0xe:
    iVar4 = (uint)*(ushort *)(param_1 + 0x42) - (uint)*(ushort *)(param_1 + 0x40);
    iVar5 = (uint)*(ushort *)(param_1 + 0x3e) - (uint)*(ushort *)(param_1 + 0x3c);
    if (iVar4 < iVar5) {
      iVar5 = iVar4;
    }
    if (iVar5 < -0x200) {
      _m_freem(param_3);
      iVar5 = 0x37;
    }
    else {
      _sbappend(param_1 + 0x3c,param_3);
      *(uint *)(unaff_EBX + 0x2c) = (uint)*(ushort *)(param_1 + 0x3c) + *(int *)(unaff_EBX + 0x24);
      *(undefined1 *)(unaff_EBX + 0x1a) = 1;
      iVar5 = _tcp_output(unaff_EBX);
      *(undefined1 *)(unaff_EBX + 0x1a) = 0;
    }
    break;
  case 0xf:
    _in_setsockaddr(iVar4,param_4);
    break;
  case 0x10:
    _in_setpeeraddr(iVar4,param_4);
    break;
  case 0x11:
    iVar5 = 0x2d;
    break;
  case 0x13:
    unaff_EBX = _tcp_timers(unaff_EBX,param_4);
    param_2 = param_2 | param_4 << 8;
  }
  if ((unaff_EBX != 0) && ((*(byte *)(param_1 + 2) & 1) != 0)) {
    _tcp_trace(2,local_c,unaff_EBX,0,param_2);
  }
LAB_0012b04b:
  _splx(uVar2);
  return iVar5;
}

