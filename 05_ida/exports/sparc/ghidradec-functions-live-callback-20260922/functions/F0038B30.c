
/* WARNING: Removing unreachable block (ram,0xf0038db8) */
/* WARNING: Removing unreachable block (ram,0xf0038c2c) */
/* WARNING: Removing unreachable block (ram,0xf0038c60) */
/* WARNING: Removing unreachable block (ram,0xf0038c84) */
/* WARNING: Removing unreachable block (ram,0xf0038ccc) */
/* WARNING: Removing unreachable block (ram,0xf0038d40) */
/* WARNING: Removing unreachable block (ram,0xf0038cfc) */
/* WARNING: Removing unreachable block (ram,0xf0038db0) */
/* WARNING: Removing unreachable block (ram,0xf0038d68) */
/* WARNING: Removing unreachable block (ram,0xf0038d78) */
/* WARNING: Removing unreachable block (ram,0xf0038d84) */
/* WARNING: Removing unreachable block (ram,0xf0038d50) */
/* WARNING: Removing unreachable block (ram,0xf0038d28) */
/* WARNING: Removing unreachable block (ram,0xf0038d9c) */
/* WARNING: Removing unreachable block (ram,0xf0038cb4) */
/* WARNING: Removing unreachable block (ram,0xf0038c98) */
/* WARNING: Removing unreachable block (ram,0xf0038d58) */
/* WARNING: Removing unreachable block (ram,0xf0038c4c) */
/* WARNING: Removing unreachable block (ram,0xf0038dcc) */
/* WARNING: Removing unreachable block (ram,0xf0038b64) */
/* WARNING: Removing unreachable block (ram,0xf0038b54) */

undefined8 _udp_usrreq(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  uVar3 = 0;
  iVar4 = 0;
  iVar2 = *(int *)(param_1 + 8);
  if (param_2 == 0xb) {
    _in_control(param_1,param_3,param_4,param_5);
    iVar4 = param_1;
    goto locret_F0038DD4;
  }
  iVar1 = param_1;
  _splnet();
  if ((param_5 != 0) && (*(sword *)(param_5 + 8) != 0)) {
    iVar4 = 0x16;
    goto loc_F0038DB8;
  }
  if ((iVar2 == 0) && (param_2 != 0)) {
    iVar4 = 0x16;
    goto loc_F0038DB8;
  }
  switch(param_2) {
  case :
    iVar4 = 0x16;
    if ((iVar2 == 0) && (iVar4 = param_1, _in_pcballoc(param_1,&_udb), iVar4 == 0)) {
      _soreserve(param_1,_udp_sendspace,_udp_recvspace);
      iVar4 = param_1;
    }
    break;
  case :
    _in_pcbbind(iVar2,param_4);
    iVar4 = iVar2;
    break;
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
    iVar4 = 0x2d;
    break;
  case :
    iVar4 = 0x38;
    if ((*(int *)(iVar2 + 0xc) == 0) && (_in_pcbconnect(iVar2,param_4), iVar4 = iVar2, iVar2 == 0))
    {
      _soisconnected(param_1);
    }
    break;
  case :
    if (*(int *)(iVar2 + 0xc) == 0) {
      iVar4 = 0x39;
    }
    else {
      _in_pcbdisconnect(iVar2);
      *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfffd;
    }
    break;
  case :
    _socantsendmore(param_1);
    break;
  case :
  case :
    _splx(iVar1);
    iVar4 = 0x2d;
    goto locret_F0038DD4;
  case :
    if (param_4 == 0) {
      if (*(int *)(iVar2 + 0xc) == 0) {
        iVar4 = 0x39;
      }
      else {
loc_F0038D28:
        iVar4 = iVar2;
        _udp_output(iVar2,param_3);
        param_3 = 0;
        if (param_4 != 0) {
          _in_pcbdisconnect(iVar2);
          *(undefined4 *)(iVar2 + 0x14) = uVar3;
        }
      }
    }
    else {
      uVar3 = *(undefined4 *)(iVar2 + 0x14);
      if (*(int *)(iVar2 + 0xc) == 0) {
        iVar4 = iVar2;
        _in_pcbconnect(iVar2,param_4);
        if (iVar4 == 0) goto loc_F0038D28;
      }
      else {
        iVar4 = 0x38;
      }
    }
    break;
  case :
    _soisdisconnected(param_1);
  case :
    _in_pcbdetach(iVar2);
    break;
  :
    _panic(aUdpUsrreq);
    break;
  case :
    _splx(iVar1);
    iVar4 = 0;
    goto locret_F0038DD4;
  case :
    _in_setsockaddr(iVar2,param_4);
    break;
  case :
    _in_setpeeraddr(iVar2,param_4);
  }
loc_F0038DB8:
  _splx(iVar1);
  if (param_3 != 0) {
    _m_freem(param_3);
  }
locret_F0038DD4:
  return CONCAT44(param_2,iVar4);
}

