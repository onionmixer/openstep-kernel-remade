
/* WARNING: Removing unreachable block (ram,0xf0038110) */
/* WARNING: Removing unreachable block (ram,0xf0037dcc) */
/* WARNING: Removing unreachable block (ram,0xf0037de0) */
/* WARNING: Removing unreachable block (ram,0xf0037e74) */
/* WARNING: Removing unreachable block (ram,0xf0037e84) */
/* WARNING: Removing unreachable block (ram,0xf0037e4c) */
/* WARNING: Removing unreachable block (ram,0xf0037f30) */
/* WARNING: Removing unreachable block (ram,0xf0037f48) */
/* WARNING: Removing unreachable block (ram,0xf0037f7c) */
/* WARNING: Removing unreachable block (ram,0xf0037f94) */
/* WARNING: Removing unreachable block (ram,0xf0038084) */
/* WARNING: Removing unreachable block (ram,0xf003809c) */
/* WARNING: Removing unreachable block (ram,0xf00380c4) */
/* WARNING: Removing unreachable block (ram,0xf0037cdc) */
/* WARNING: Removing unreachable block (ram,0xf00380b0) */
/* WARNING: Removing unreachable block (ram,0xf0038064) */
/* WARNING: Removing unreachable block (ram,0xf0038054) */
/* WARNING: Removing unreachable block (ram,0xf00380e0) */
/* WARNING: Removing unreachable block (ram,0xf0037f5c) */
/* WARNING: Removing unreachable block (ram,0xf0037f28) */
/* WARNING: Removing unreachable block (ram,0xf0037e34) */
/* WARNING: Removing unreachable block (ram,0xf0037e60) */
/* WARNING: Removing unreachable block (ram,0xf0037f68) */
/* WARNING: Removing unreachable block (ram,0xf0037e04) */
/* WARNING: Removing unreachable block (ram,0xf0037eec) */
/* WARNING: Removing unreachable block (ram,0xf0037d74) */
/* WARNING: Removing unreachable block (ram,0xf0038118) */
/* WARNING: Removing unreachable block (ram,0xf0037cb8) */
/* WARNING: Removing unreachable block (ram,0xf0037c84) */

undefined8 _tcp_usrreq(int param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  word wVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  int iVar8;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar5 = 0;
  iVar7 = 0;
  if (param_2 == 0xb) {
    _in_control(param_1,param_3,param_4);
    iVar7 = param_1;
    goto locret_F0038120;
  }
  iVar2 = param_1;
  if ((param_5 != 0) && (iVar2 = 0, *(sword *)(param_5 + 8) != 0)) {
    iVar7 = 0x16;
    goto locret_F0038120;
  }
  _splnet();
  iVar8 = *(int *)(param_1 + 8);
  if ((iVar8 == 0) && (param_2 != 0)) {
    iVar7 = 0x16;
    _splx();
    goto locret_F0038120;
  }
  iVar6 = 0;
  if (iVar8 != 0) {
    iVar5 = *(int *)(iVar8 + 0x20);
    iVar6 = (int)*(sword *)(iVar5 + 8);
  }
  switch(param_2) {
  case :
    iVar7 = 0x38;
    if (iVar8 == 0) {
      iVar7 = param_1;
      _tcp_attach();
      bVar9 = iVar5 == 0;
      if (iVar7 != 0) goto loc_F00380EC;
      if ((*(word *)(param_1 + 2) & 0x80) == 0) {
        iVar5 = *(int *)(param_1 + 8);
      }
      else if (*(sword *)(param_1 + 4) == 0) {
        *(undefined2 *)(param_1 + 4) = 0x78;
        iVar5 = *(int *)(param_1 + 8);
      }
      else {
        iVar5 = *(int *)(param_1 + 8);
      }
      iVar5 = *(int *)(iVar5 + 0x20);
    }
    break;
  case :
    if (1 < *(sword *)(iVar5 + 8)) goto loc_F0037EEC;
    _tcp_close();
    break;
  case :
    _in_pcbbind(iVar8,param_4);
    iVar7 = iVar8;
    break;
  case :
    if (*(sword *)(iVar8 + 0x18) == 0) {
      _in_pcbbind(iVar8,0);
      iVar7 = iVar8;
    }
    bVar9 = iVar5 == 0;
    if (iVar7 == 0) {
      *(undefined2 *)(iVar5 + 8) = 1;
    }
    goto loc_F00380EC;
  case :
    if (*(sword *)(iVar8 + 0x18) == 0) {
      iVar7 = iVar8;
      _in_pcbbind(iVar8,0);
      bVar9 = iVar5 == 0;
      if (iVar7 != 0) goto loc_F00380EC;
    }
    iVar7 = iVar8;
    _in_pcbconnect(iVar8,param_4);
    bVar9 = iVar5 == 0;
    if (iVar7 == 0) {
      iVar7 = iVar5;
      _tcp_template();
      *(int *)(iVar5 + 0x1c) = iVar7;
      if (iVar7 != 0) {
        _soisconnecting(param_1);
        _tcpstat = _tcpstat + 1;
        *(undefined2 *)(iVar5 + 8) = 2;
        *(undefined2 *)(iVar5 + 0xe) = 0x96;
        *(int *)(iVar5 + 0x38) = _tcp_iss;
        _tcp_iss = _tcp_iss + 64000;
        uVar3 = *(undefined4 *)(iVar5 + 0x38);
        *(undefined4 *)(iVar5 + 0x2c) = uVar3;
        *(undefined4 *)(iVar5 + 0x50) = uVar3;
        *(undefined4 *)(iVar5 + 0x28) = uVar3;
        *(undefined4 *)(iVar5 + 0x24) = uVar3;
        goto loc_F0037F68;
      }
      _in_pcbdisconnect(iVar8);
      iVar7 = 0x37;
      break;
    }
    goto loc_F00380EC;
  case :
    *(undefined2 *)(param_4 + 8) = 0x10;
    iVar4 = *(int *)(param_4 + 4);
    *(undefined2 *)(param_4 + iVar4) = 2;
    iVar4 = param_4 + iVar4;
    *(undefined2 *)(iVar4 + 2) = *(undefined2 *)(iVar8 + 0x10);
    *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar8 + 0xc);
    break;
  case :
loc_F0037EEC:
    _tcp_disconnect();
    break;
  case :
    _socantsendmore(param_1);
    _tcp_usrclosed();
    bVar9 = iVar5 == 0;
    if (!bVar9) goto loc_F0037F68;
    goto loc_F00380EC;
  case :
    _tcp_output(iVar5);
    bVar9 = iVar5 == 0;
    goto loc_F00380EC;
  case :
    _sbappend(param_1 + 0x3c,param_3);
loc_F0037F68:
    iVar7 = iVar5;
    _tcp_output();
    break;
  case :
    _tcp_drop(iVar5,0x35);
    break;
  :
    _panic(aTcpUsrreq);
    break;
  case :
    *(uint *)(param_3 + 0x30) = (uint)*(word *)(param_1 + 0x3e);
    _splx(iVar2);
    iVar7 = 0;
    goto locret_F0038120;
  case :
    if (*(sword *)(param_1 + 0x58) == 0) {
      if ((*(word *)(param_1 + 6) & 0x40) == 0) {
        iVar7 = 0x16;
        break;
      }
      wVar1 = *(word *)(param_1 + 2);
    }
    else {
      wVar1 = *(word *)(param_1 + 2);
    }
    if ((wVar1 & 0x100) == 0) {
      if ((*(byte *)(iVar5 + 0x68) & 2) == 0) {
        if ((*(byte *)(iVar5 + 0x68) & 1) == 0) {
          iVar7 = 0x23;
        }
        else {
          *(undefined2 *)(param_3 + 8) = 1;
          *(undefined *)(param_3 + *(int *)(param_3 + 4)) = *(undefined *)(iVar5 + 0x69);
          if ((param_4 & 2) == 0) {
            *(byte *)(iVar5 + 0x68) = *(byte *)(iVar5 + 0x68) ^ 3;
          }
        }
      }
      else {
        iVar7 = 0x16;
      }
    }
    else {
      iVar7 = 0x16;
    }
    break;
  case :
    iVar7 = (uint)*(word *)(param_1 + 0x3e) - (uint)*(word *)(param_1 + 0x3c);
    iVar8 = (uint)*(word *)(param_1 + 0x42) - (uint)*(word *)(param_1 + 0x40);
    if (iVar8 < iVar7) {
      iVar7 = iVar8;
    }
    if (iVar7 < -0x200) {
      _m_freem(param_3);
      iVar7 = 0x37;
    }
    else {
      _sbappend(param_1 + 0x3c,param_3);
      *(uint *)(iVar5 + 0x2c) = *(int *)(iVar5 + 0x24) + (uint)*(word *)(param_1 + 0x3c);
      *(undefined *)(iVar5 + 0x1a) = 1;
      iVar7 = iVar5;
      _tcp_output(iVar5);
      *(undefined *)(iVar5 + 0x1a) = 0;
    }
    break;
  case :
    _in_setsockaddr(iVar8,param_4);
    bVar9 = iVar5 == 0;
    goto loc_F00380EC;
  case :
    _in_setpeeraddr(iVar8,param_4);
    bVar9 = iVar5 == 0;
    goto loc_F00380EC;
  case :
    iVar7 = 0x2d;
    break;
  case :
    _tcp_timers(iVar5,param_4);
    param_2 = param_2 | param_4 << 8;
  }
  bVar9 = iVar5 == 0;
loc_F00380EC:
  if ((!bVar9) && ((*(word *)(param_1 + 2) & 1) != 0)) {
    _tcp_trace(2,iVar6,iVar5,0,param_2);
  }
  _splx(iVar2);
locret_F0038120:
  return CONCAT44(param_2,iVar7);
}

