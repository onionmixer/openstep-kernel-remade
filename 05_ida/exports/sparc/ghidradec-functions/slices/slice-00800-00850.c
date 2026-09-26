/* GHIDRADEC_FUNCTION index=800 start=0xf00388c0 */

/* WARNING: Removing unreachable block (ram,0xf00388d4) */
/* WARNING: Removing unreachable block (ram,0xf00388c8) */

undefined8 _udp_notify(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  _sowakeup(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) + 0x24);
  _sowakeup(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) + 0x3c);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=801 start=0xf00388e4 */

/* WARNING: Removing unreachable block (ram,0xf003897c) */

undefined8 _udp_ctlinput(uint param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  if ((param_1 == 1) || ((param_1 < 0x16 && (_inetctlerrmap[param_1] != '\0')))) {
    if (param_3 == (byte *)0x0) {
      uVar2 = 0;
      uVar4 = 0;
      *(undefined4 *)((int)register0x00000038 + -0xc) = _zeroin_addr;
    }
    else {
      bVar1 = *param_3;
      *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_3 + 0xc);
      iVar3 = (bVar1 & 0xf) * 4;
      uVar2 = *(undefined2 *)(param_3 + iVar3 + 2);
      uVar4 = *(undefined2 *)(param_3 + iVar3);
    }
    _in_pcbnotify(&_udb,param_2,uVar2,(undefined *)((int)register0x00000038 + -0xc),uVar4,param_1,
                  _udp_notify);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=802 start=0xf003898c */

/* WARNING: Removing unreachable block (ram,0xf0038ac8) */
/* WARNING: Removing unreachable block (ram,0xf0038a30) */
/* WARNING: Removing unreachable block (ram,0xf0038a24) */
/* WARNING: Removing unreachable block (ram,0xf00389d8) */
/* WARNING: Removing unreachable block (ram,0xf0038a44) */
/* WARNING: Removing unreachable block (ram,0xf0038b1c) */
/* WARNING: Removing unreachable block (ram,0xf00389b0) */

undefined8 _udp_output(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  iVar5 = 0;
  iVar2 = param_1;
  for (piVar4 = (int *)param_2; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    iVar2 = (int)*(sword *)(piVar4 + 2);
    iVar5 = iVar5 + iVar2;
  }
  _spltty();
  piVar4 = _mfree;
  if (_mfree == (int *)0x0) {
    piVar4 = (int *)0x0;
    _m_more(0,2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
      _panic(&aMget_12);
    }
    *(undefined2 *)((int)piVar4 + 10) = 2;
    word_F0134B0C = word_F0134B0C + -1;
    DAT_f0134b10._0_2_ = DAT_f0134b10._0_2_ + 1;
    _mfree = (int *)*piVar4;
    piVar4[1] = 0xc;
    *piVar4 = 0;
  }
  _splx(iVar2);
  if (piVar4 == (int *)0x0) {
    _m_freem(param_2);
    piVar4 = (int *)0x37;
  }
  else {
    piVar4[1] = 0x60;
    *(undefined2 *)(piVar4 + 2) = 0x1c;
    iVar2 = piVar4[1];
    *piVar4 = param_2;
    param_2 = (int)piVar4 + iVar2;
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)((int)piVar4 + iVar2) = 0;
    *(undefined *)(param_2 + 8) = 0;
    *(undefined *)(param_2 + 9) = 0x11;
    *(sword *)(param_2 + 10) = (sword)iVar5 + 8;
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0xc);
    iVar2 = _udpcksum;
    *(undefined2 *)(param_2 + 0x14) = *(undefined2 *)(param_1 + 0x18);
    *(undefined2 *)(param_2 + 0x16) = *(undefined2 *)(param_1 + 0x10);
    *(undefined2 *)(param_2 + 0x18) = *(undefined2 *)(param_2 + 10);
    *(undefined2 *)(param_2 + 0x1a) = 0;
    if (iVar2 != 0) {
      piVar3 = piVar4;
      _in_cksum(piVar4,iVar5 + 0x1c);
      *(sword *)(param_2 + 0x1a) = (sword)piVar3;
      if (((uint)piVar3 & 0xffff) == 0) {
        *(undefined2 *)(param_2 + 0x1a) = 0xffff;
      }
    }
    uVar1 = _udp_ttl;
    *(sword *)(param_2 + 2) = (sword)iVar5 + 0x1c;
    *(char *)(param_2 + 8) = (char)uVar1;
    _ip_output(piVar4,*(undefined4 *)(param_1 + 0x38),param_1 + 0x24,
               *(word *)(*(int *)(param_1 + 0x1c) + 2) & 0x30 | 2,*(undefined4 *)(param_1 + 0x3c));
  }
  return CONCAT44(param_2,piVar4);
}
/* GHIDRADEC_FUNCTION index=803 start=0xf0038b30 */

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
/* GHIDRADEC_FUNCTION index=804 start=0xf0038ddc */

undefined8 _igmp_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  dword_F012F4E8 = 0xe0000001;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=805 start=0xf0038df8 */

/* WARNING: Removing unreachable block (ram,0xf00390e0) */
/* WARNING: Removing unreachable block (ram,0xf0038f5c) */
/* WARNING: Removing unreachable block (ram,0xf0038ea4) */
/* WARNING: Removing unreachable block (ram,0xf0038ecc) */
/* WARNING: Removing unreachable block (ram,0xf0039010) */
/* WARNING: Removing unreachable block (ram,0xf0039200) */
/* WARNING: Removing unreachable block (ram,0xf0038e64) */
/* WARNING: Removing unreachable block (ram,0xf0038e3c) */

undefined8 _igmp_input(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  int *piVar6;
  undefined4 unaff_l1;
  int iVar7;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  _igmpstat = _igmpstat + 1;
  uVar4 = *(uint *)(param_1 + 4);
  iVar8 = (int)*(sword *)(param_1 + uVar4 + 2);
  uVar2 = *(byte *)(param_1 + uVar4) & 0xf;
  iVar5 = uVar2 * 4;
  if (iVar8 < 8) {
    DAT_f013a8a4._0_4_ = DAT_f013a8a4._0_4_ + 1;
    _m_freem(param_1);
    goto locret_F0039208;
  }
  if (((0x7c < uVar4) || ((int)*(sword *)(param_1 + 8) < iVar5 + 8)) && (_m_pullup(), param_1 == 0))
  {
    DAT_f013a8a4._0_4_ = DAT_f013a8a4._0_4_ + 1;
    goto locret_F0039208;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iVar5;
  iVar7 = *(int *)(param_1 + 4);
  *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + (sword)uVar2 * -4;
  iVar3 = param_1;
  _in_cksum(param_1,iVar8);
  iVar8 = param_1 + iVar7;
  if (iVar3 != 0) {
    DAT_f013a8a4._4_4_ = DAT_f013a8a4._4_4_ + 1;
    _m_freem(param_1);
    goto locret_F0039208;
  }
  *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + uVar2 * -4;
  *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + (sword)iVar5;
  cVar1 = *(char *)(param_1 + iVar7);
  iVar5 = param_1 + *(int *)(param_1 + 4);
  if (cVar1 == '\x11') {
    DAT_f013a8a4._8_4_ = DAT_f013a8a4._8_4_ + 1;
    if (param_2 != _loifp) {
      if (*(int *)(iVar5 + 0x10) != dword_F012F4E8) {
        DAT_f013a8a4._12_4_ = DAT_f013a8a4._12_4_ + 1;
        _m_freem(param_1);
        goto locret_F0039208;
      }
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      piVar6 = (int *)0x0;
      *(int *)((int)register0x00000038 + -0x10) = _in_ifaddr;
      if (_in_ifaddr != 0) {
        iVar8 = *(int *)((int)register0x00000038 + -0x10);
        do {
          piVar6 = *(int **)(iVar8 + 0x44);
          iVar3 = *(int *)(iVar8 + 0x40);
          *(int *)((int)register0x00000038 + -0x10) = iVar3;
          if (piVar6 != (int *)0x0) {
            *(int *)((int)register0x00000038 + -0xc) = piVar6[5];
            break;
          }
          iVar8 = *(int *)((int)register0x00000038 + -0x10);
        } while (iVar3 != 0);
      }
      if (piVar6 != (int *)0x0) {
        iVar8 = piVar6[1];
        do {
          if (iVar8 == param_2) {
            if (piVar6[4] == 0) {
              if (*piVar6 != dword_F012F4E8) {
                iVar8 = _ipstat + *(int *)(_in_ifaddr + 4) + *piVar6;
                .urem(iVar8,0x32);
                piVar6[4] = iVar8 + 1;
                dword_F010C9CC = 1;
              }
              piVar6 = *(int **)((int)register0x00000038 + -0xc);
            }
            else {
              piVar6 = *(int **)((int)register0x00000038 + -0xc);
            }
          }
          else {
            piVar6 = *(int **)((int)register0x00000038 + -0xc);
          }
          if (piVar6 == (int *)0x0) {
            if (*(int *)((int)register0x00000038 + -0x10) != 0) {
              iVar8 = *(int *)((int)register0x00000038 + -0x10);
              do {
                piVar6 = *(int **)(iVar8 + 0x44);
                iVar3 = *(int *)(iVar8 + 0x40);
                *(int *)((int)register0x00000038 + -0x10) = iVar3;
                if (piVar6 != (int *)0x0) goto loc_F0039038;
                iVar8 = *(int *)((int)register0x00000038 + -0x10);
              } while (iVar3 != 0);
            }
          }
          else {
loc_F0039038:
            *(int *)((int)register0x00000038 + -0xc) = piVar6[5];
          }
          if (piVar6 == (int *)0x0) break;
          iVar8 = piVar6[1];
        } while( true );
      }
    }
  }
  else if ((cVar1 == '\x12') && (DAT_f013a8a4._16_4_ = DAT_f013a8a4._16_4_ + 1, param_2 != _loifp))
  {
    uVar2 = *(uint *)(iVar8 + 4);
    if (((uVar2 & 0xf0000000) != 0xe0000000) || (uVar2 != *(uint *)(iVar5 + 0x10))) {
      DAT_f013a8a4._20_4_ = DAT_f013a8a4._20_4_ + 1;
      _m_freem(param_1);
      goto locret_F0039208;
    }
    if (((*(uint *)(iVar5 + 0xc) & 0xff000000) == 0) && (_in_ifaddr != 0)) {
      iVar7 = *(int *)(_in_ifaddr + 0x20);
      iVar3 = _in_ifaddr;
      while ((iVar7 != param_2 && (iVar3 = *(int *)(iVar3 + 0x40), iVar3 != 0))) {
        iVar7 = *(int *)(iVar3 + 0x20);
      }
      if (iVar3 != 0) {
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar3 + 0x30);
      }
    }
    bVar9 = _in_ifaddr == 0;
    iVar3 = _in_ifaddr;
    if (!bVar9) {
      iVar7 = *(int *)(_in_ifaddr + 0x20);
      while (bVar9 = iVar3 == 0, iVar7 != param_2) {
        iVar3 = *(int *)(iVar3 + 0x40);
        if (iVar3 == 0) {
          bVar9 = true;
          break;
        }
        iVar7 = *(int *)(iVar3 + 0x20);
      }
    }
    if (bVar9) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = *(int **)(iVar3 + 0x44);
      if (piVar6 == (int *)0x0) goto loc_F00391DC;
      iVar3 = *piVar6;
      while ((iVar3 != *(int *)(iVar8 + 4) && (piVar6 = (int *)piVar6[5], piVar6 != (int *)0x0))) {
        iVar3 = *piVar6;
      }
    }
    if (piVar6 != (int *)0x0) {
      piVar6[4] = 0;
      DAT_f013a8a4._24_4_ = DAT_f013a8a4._24_4_ + 1;
    }
  }
loc_F00391DC:
  DAT_f010c9b0._0_4_ = *(undefined4 *)(iVar5 + 0xc);
  DAT_f010c9c0._0_4_ = *(undefined4 *)(iVar5 + 0x10);
  _raw_input(param_1,&unk_F010C9A8);
locret_F0039208:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=806 start=0xf0039210 */

/* WARNING: Removing unreachable block (ram,0xf003927c) */
/* WARNING: Removing unreachable block (ram,0xf0039254) */
/* WARNING: Removing unreachable block (ram,0xf0039298) */
/* WARNING: Removing unreachable block (ram,0xf0039214) */

undefined8 _igmp_joingroup(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  piVar1 = param_1;
  _splnet();
  if ((*param_1 == dword_F012F4E8) || (param_1[1] == _loifp)) {
    param_1[4] = 0;
  }
  else {
    _igmp_sendreport(param_1);
    iVar2 = _ipstat + *(int *)(_in_ifaddr + 4) + *param_1;
    .urem(iVar2,0x32);
    param_1[4] = iVar2 + 1;
    dword_F010C9CC = 1;
  }
  _splx(piVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=807 start=0xf00392a8 */

undefined8 _igmp_leavegroup(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=808 start=0xf0039330 */

/* WARNING: Removing unreachable block (ram,0xf00393a0) */
/* WARNING: Removing unreachable block (ram,0xf0039358) */
/* WARNING: Removing unreachable block (ram,0xf0039390) */
/* WARNING: Removing unreachable block (ram,0xf00393b4) */
/* WARNING: Removing unreachable block (ram,0xf0039348) */

undefined8 _igmp_fasttimo(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  if (dword_F010C9CC != 0) {
    iVar1 = dword_F010C9CC;
    _splnet();
    dword_F010C9CC = 0;
    puVar2 = (undefined *)((int)register0x00000038 + -0x10);
    sub_F003930C();
    if (puVar2 != (undefined *)0x0) {
      iVar3 = *(int *)(puVar2 + 0x10);
      while( true ) {
        if (iVar3 != 0) {
          *(int *)(puVar2 + 0x10) = iVar3 + -1;
          if (iVar3 + -1 == 0) {
            _igmp_sendreport(puVar2);
          }
          else {
            dword_F010C9CC = 1;
          }
        }
        puVar2 = (undefined *)((int)register0x00000038 + -0x10);
        sub_F00392B4();
        if (puVar2 == (undefined *)0x0) break;
        iVar3 = *(int *)(puVar2 + 0x10);
      }
    }
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=809 start=0xf00393c4 */

/* WARNING: Removing unreachable block (ram,0xf00395c0) */
/* WARNING: Removing unreachable block (ram,0xf003952c) */
/* WARNING: Removing unreachable block (ram,0xf0039484) */
/* WARNING: Removing unreachable block (ram,0xf003945c) */
/* WARNING: Removing unreachable block (ram,0xf00393f0) */
/* WARNING: Removing unreachable block (ram,0xf003943c) */
/* WARNING: Removing unreachable block (ram,0xf0039448) */
/* WARNING: Removing unreachable block (ram,0xf00394d0) */
/* WARNING: Removing unreachable block (ram,0xf00394dc) */
/* WARNING: Removing unreachable block (ram,0xf00395b8) */
/* WARNING: Removing unreachable block (ram,0xf00394f0) */
/* WARNING: Removing unreachable block (ram,0xf00393c8) */

undefined8 _igmp_sendreport(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  puVar1 = param_1;
  _spltty();
  puVar2 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
    _m_more(0,2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
      _panic(&aMget_13);
    }
    *(undefined2 *)((int)puVar2 + 10) = 2;
    word_F0134B0C = word_F0134B0C + -1;
    DAT_f0134b10._0_2_ = DAT_f0134b10._0_2_ + 1;
    _mfree = (undefined4 *)*puVar2;
    puVar2[1] = 0xc;
    *puVar2 = 0;
  }
  _splx(puVar1);
  if (puVar2 != (undefined4 *)0x0) {
    _spltty();
    puVar3 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
      _m_more(0,0xe);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
        _panic(&aMget_14);
      }
      *(undefined2 *)((int)puVar3 + 10) = 0xe;
      word_F0134B0C = word_F0134B0C + -1;
      DAT_f0134b10._24_2_ = DAT_f0134b10._24_2_ + 1;
      _mfree = (undefined4 *)*puVar3;
      puVar3[1] = 0xc;
      *puVar3 = 0;
    }
    _splx(puVar1);
    if (puVar3 == (undefined4 *)0x0) {
      _m_free(puVar2);
    }
    else {
      puVar2[1] = 0x74;
      *(undefined2 *)(puVar2 + 2) = 8;
      iVar5 = puVar2[1];
      *(undefined *)((int)puVar2 + iVar5) = 0x12;
      *(undefined *)((int)puVar2 + iVar5 + 1) = 0;
      *(undefined4 *)((int)puVar2 + iVar5 + 4) = *param_1;
      *(undefined2 *)((int)puVar2 + iVar5 + 2) = 0;
      puVar1 = puVar2;
      _in_cksum(puVar2,8);
      *(sword *)((int)puVar2 + iVar5 + 2) = (sword)puVar1;
      puVar2[1] = puVar2[1] + -0x14;
      *(sword *)(puVar2 + 2) = *(sword *)(puVar2 + 2) + 0x14;
      iVar4 = puVar2[1];
      *(undefined *)((int)puVar2 + iVar4 + 1) = 0;
      *(undefined2 *)((int)puVar2 + iVar4 + 2) = 0x1c;
      *(undefined2 *)((int)puVar2 + iVar4 + 6) = 0;
      *(undefined *)((int)puVar2 + iVar4 + 9) = 2;
      *(undefined4 *)((int)puVar2 + iVar4 + 0xc) = 0;
      *(undefined4 *)((int)puVar2 + iVar4 + 0x10) = *(undefined4 *)((int)puVar2 + iVar5 + 4);
      iVar4 = puVar3[1];
      *(undefined4 *)((int)puVar3 + iVar4) = param_1[1];
      *(undefined *)((int)puVar3 + iVar4 + 4) = 1;
      *(bool *)((int)puVar3 + iVar4 + 5) = _ip_mrouter != 0;
      _ip_output(puVar2,0,0,2,puVar3);
      _m_free(puVar3);
      DAT_f013a8c0._0_4_ = DAT_f013a8c0._0_4_ + 1;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=810 start=0xf00395e4 */

undefined8 _ip_mrouter_cmd(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  return CONCAT44(param_2,0x2d);
}
/* GHIDRADEC_FUNCTION index=811 start=0xf00395f0 */

sqword _ip_mrouter_done(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=812 start=0xf00395fc */

sqword _ip_mforward(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=813 start=0xf0039608 */

/* WARNING: Removing unreachable block (ram,0xf0039618) */

undefined8 _nfs_validate_caches(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  _nfsgetattr(param_1,(undefined *)((int)register0x00000038 + -0x48),param_2,param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=814 start=0xf0039628 */

/* WARNING: Removing unreachable block (ram,0xf0039644) */
/* WARNING: Removing unreachable block (ram,0xf0039634) */
/* WARNING: Removing unreachable block (ram,0xf003964c) */
/* WARNING: Removing unreachable block (ram,0xf003962c) */

undefined8 _nfs_invalidate_caches(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  _vnode_uncache(param_1);
  _mfs_invalidate(param_1);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  _dnlc_purge_vp(param_1);
  _binvalfree(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=815 start=0xf003965c */

/* WARNING: Removing unreachable block (ram,0xf003967c) */
/* WARNING: Removing unreachable block (ram,0xf003966c) */
/* WARNING: Removing unreachable block (ram,0xf0039684) */
/* WARNING: Removing unreachable block (ram,0xf0039664) */

undefined8 _nfs_purge_caches(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  _sync_vp_invalidate(param_1,param_2);
  _vnode_uncache(param_1);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  _dnlc_purge_vp(param_1);
  _binvalfree(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=816 start=0xf0039694 */

/* WARNING: Removing unreachable block (ram,0xf00396e4) */

undefined8 _nfs_cache_check(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  iVar1 = *(int *)(param_1 + 0x30);
  if (((*(word *)(iVar1 + 0x10) & 0x80) == 0) &&
     (((*param_2 != *(int *)(iVar1 + 0xa8) || (param_2[1] != *(int *)(iVar1 + 0xac))) ||
      (param_3 != *(int *)(iVar1 + 0x98))))) {
    _nfs_purge_caches(param_1,param_4);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=817 start=0xf00396f4 */

/* WARNING: Removing unreachable block (ram,0xf0039734) */
/* WARNING: Removing unreachable block (ram,0xf003972c) */

undefined8 _nfs_attrcache(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  if (((*(word *)(param_1 + 4) & 0x40) == 0) &&
     ((*(uint *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x14) & 0x8000000) == 0)) {
    _nattr_to_vattr(param_1,param_2,*(int *)(param_1 + 0x30) + 0x80);
    sub_F003979C(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=818 start=0xf0039744 */

/* WARNING: Removing unreachable block (ram,0xf003978c) */
/* WARNING: Removing unreachable block (ram,0xf003977c) */

undefined8 _nfs_attrcache_va(int param_1,undefined4 *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  if (((*(word *)(param_1 + 4) & 0x40) == 0) &&
     ((*(uint *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x14) & 0x8000000) == 0)) {
    _memcpy(*(int *)(param_1 + 0x30) + 0x80,param_2,0x40);
    *(undefined4 *)(param_1 + 0x28) = *param_2;
    sub_F003979C();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=819 start=0xf00398ec */

/* WARNING: Removing unreachable block (ram,0xf0039954) */
/* WARNING: Removing unreachable block (ram,0xf0039984) */
/* WARNING: Removing unreachable block (ram,0xf0039928) */
/* WARNING: Removing unreachable block (ram,0xf003998c) */
/* WARNING: Removing unreachable block (ram,0xf0039998) */
/* WARNING: Removing unreachable block (ram,0xf00398f0) */

undefined8 _nfs_getattr_otw(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  piVar1 = (int *)0x48;
  _kalloc();
  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x128);
  _rfscall(iVar2,1,_xdr_fhandle,*(int *)(param_1 + 0x30) + 0x40,_xdr_attrstat,piVar1,param_3);
  if (iVar2 == 0) {
    iVar2 = *piVar1;
    if (iVar2 == 0) {
      _nattr_to_vattr(param_1,piVar1 + 1,param_2);
      *(uint *)(param_2 + 0xc) =
           *(uint *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x28) | 0xff00;
    }
    else if (iVar2 == 0x46) {
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
  }
  _kfree(piVar1,0x48);
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=820 start=0xf00399a8 */

/* WARNING: Removing unreachable block (ram,0xf0039a00) */
/* WARNING: Removing unreachable block (ram,0xf00399d0) */
/* WARNING: Removing unreachable block (ram,0xf0039a0c) */
/* WARNING: Removing unreachable block (ram,0xf00399b0) */

undefined8 _nfsgetattr(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar2 = param_1;
  sub_F0039838(param_1,param_2);
  if (iVar2 == 0) {
    iVar2 = param_1;
    _nfs_getattr_otw(param_1,param_2,param_3);
    if (iVar2 != 0) {
      iVar1 = *(int *)(param_1 + 0x30);
      goto loc_F0039A18;
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(param_2 + 0x28);
    *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_2 + 0x2c);
    _nfs_cache_check(param_1,(undefined *)((int)register0x00000038 + -0x10),
                     *(undefined4 *)(param_2 + 0x18),param_4);
    _nfs_attrcache_va(param_1,param_2);
  }
  else {
    iVar2 = 0;
  }
  iVar1 = *(int *)(param_1 + 0x30);
loc_F0039A18:
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(iVar1 + 0x98);
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=821 start=0xf0039a28 */

/* WARNING: Removing unreachable block (ram,0xf0039a50) */

undefined8 _nattr_to_vattr(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  iVar4 = param_1[0xc];
  *param_3 = *param_2;
  *(sword *)(param_3 + 1) = (sword)param_2[1];
  *(sword *)((int)param_3 + 6) = (sword)param_2[3];
  *(sword *)(param_3 + 2) = (sword)param_2[4];
  iVar1 = param_1[9];
  _vfs_fixedmajor();
  param_3[3] = (uint)(word)((word)(iVar1 << 8) |
                           (word)*(byte *)(*(int *)(param_1[9] + 0x128) + 0x2b));
  param_3[4] = param_2[10];
  *(sword *)(param_3 + 5) = (sword)param_2[2];
  iVar1 = *param_1;
  uVar3 = *(uint *)(iVar1 + 0x14);
  if ((uint)param_2[5] < uVar3) {
    if ((*(uint *)(iVar1 + 0x38) & 0x40000000) == 0) {
      if ((*(word *)(iVar4 + 0x60) & 0x10) == 0) {
        iVar2 = param_2[5];
        goto loc_F0039AD8;
      }
      param_3[6] = uVar3;
    }
    else {
      param_3[6] = uVar3;
    }
  }
  else {
    iVar2 = param_2[5];
loc_F0039AD8:
    param_3[6] = iVar2;
  }
  uVar3 = param_3[6];
  if (*(uint *)(iVar4 + 0x98) < uVar3) {
    *(uint *)(iVar4 + 0x98) = uVar3;
  }
  else {
    if ((*(word *)(iVar4 + 0x60) & 0x10) != 0) {
      iVar4 = param_2[0xb];
      goto loc_F0039B08;
    }
    *(uint *)(iVar4 + 0x98) = uVar3;
  }
  iVar4 = param_2[0xb];
loc_F0039B08:
  param_3[8] = iVar4;
  param_3[9] = param_2[0xc];
  param_3[10] = param_2[0xd];
  param_3[0xb] = param_2[0xe];
  param_3[0xc] = param_2[0xf];
  param_3[0xd] = param_2[0x10];
  *(sword *)(param_3 + 0xe) = (sword)param_2[7];
  param_3[0xf] = param_2[8];
  if (*param_2 == 3) {
    iVar4 = 0x800;
  }
  else {
    iVar4 = 0x2000;
    if (*param_2 != 4) {
      iVar4 = param_2[6];
    }
  }
  param_3[7] = iVar4;
  if ((*param_2 == 4) && (param_2[7] == -1)) {
    *param_3 = 8;
    *(undefined2 *)(param_3 + 0xe) = 0;
    *(word *)(param_3 + 1) = *(word *)(param_3 + 1) & 0xfff | 0x1000;
    param_3[7] = param_2[6];
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=822 start=0xf0039bb8 */

undefined8 _nfstsize(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  return CONCAT44(param_2,0x2000);
}
/* GHIDRADEC_FUNCTION index=823 start=0xf0039bc8 */

undefined8 _vattr_to_nattr(int *param_1,int *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  *param_2 = *param_1;
  if (*(word *)(param_1 + 1) == 0xffff) {
    param_2[1] = -1;
  }
  else {
    param_2[1] = (uint)*(word *)(param_1 + 1);
  }
  param_2[3] = (int)*(sword *)((int)param_1 + 6);
  param_2[4] = (int)*(sword *)(param_1 + 2);
  param_2[9] = param_1[3];
  param_2[10] = param_1[4];
  param_2[2] = (int)*(sword *)(param_1 + 5);
  param_2[5] = param_1[6];
  param_2[0xb] = param_1[8];
  param_2[0xc] = param_1[9];
  param_2[0xd] = param_1[10];
  param_2[0xe] = param_1[0xb];
  param_2[0xf] = param_1[0xc];
  param_2[0x10] = param_1[0xd];
  param_2[7] = (int)*(sword *)(param_1 + 0xe);
  param_2[8] = param_1[0xf];
  param_2[6] = param_1[7];
  if (*param_1 == 8) {
    *param_2 = 4;
    param_2[7] = -1;
    param_2[1] = param_2[1] & 0xffff0fffU | 0x2000;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=824 start=0xf0039ca8 */

/* WARNING: Removing unreachable block (ram,0xf0039d50) */
/* WARNING: Removing unreachable block (ram,0xf0039eb4) */
/* WARNING: Removing unreachable block (ram,0xf0039e68) */
/* WARNING: Removing unreachable block (ram,0xf0039de4) */
/* WARNING: Removing unreachable block (ram,0xf0039d70) */
/* WARNING: Removing unreachable block (ram,0xf0039ce4) */
/* WARNING: Removing unreachable block (ram,0xf0039d24) */
/* WARNING: Removing unreachable block (ram,0xf0039d9c) */
/* WARNING: Removing unreachable block (ram,0xf0039e18) */
/* WARNING: Removing unreachable block (ram,0xf0039e9c) */
/* WARNING: Removing unreachable block (ram,0xf0039eec) */
/* WARNING: Removing unreachable block (ram,0xf0039efc) */
/* WARNING: Removing unreachable block (ram,0xf0039cb4) */

undefined8 _exportfs(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  char cVar8;
  uint *puVar3;
  uint uVar4;
  word *pwVar5;
  int iVar6;
  sword *psVar7;
  undefined4 unaff_l0;
  int *piVar9;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 *puVar10;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  puVar10 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar2 = dword_F0133DDC;
  _suser();
  if (iVar2 == 0) {
    *(undefined *)(dword_F0133DDC + 0x38) = 1;
    goto locret_F0039F04;
  }
  uVar1 = *puVar10;
  _lookupname(uVar1,0,1,0,(undefined *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0039F04;
  (**(code **)(*(int *)(iVar2 + 0x1c) + 100))(iVar2,(undefined *)((int)register0x00000038 + -0x10));
  *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
  iVar2 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x24);
  _vn_rele();
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0039F04;
  if (puVar10[1] == 0) {
    cVar8 = (char)iVar2 + '\x14';
    _unexport();
    *(char *)(dword_F0133DDC + 0x38) = cVar8;
    puVar3 = *(uint **)((int)register0x00000038 + -0x10);
    iVar2 = *(word *)puVar3 + 2;
  }
  else {
    puVar3 = (uint *)0x30;
    _kalloc(0x30,*(undefined4 *)((int)register0x00000038 + -0x10));
    uVar4 = *(uint *)((int)register0x00000038 + -0x10);
    puVar3[8] = *(uint *)(iVar2 + 0x14);
    puVar3[9] = *(uint *)(iVar2 + 0x18);
    puVar3[10] = uVar4;
    uVar1 = puVar10[1];
    _copyin(uVar1,puVar3,0x20);
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      if ((*puVar3 & 0xfffffffc) == 0) {
        if ((*puVar3 & 2) == 0) {
          uVar4 = puVar3[2];
        }
        else {
          cVar8 = (char)puVar3 + '\x18';
          _loadaddrs();
          *(char *)(dword_F0133DDC + 0x38) = cVar8;
          if (*(char *)(dword_F0133DDC + 0x38) != '\0') {
            pwVar5 = (word *)puVar3[10];
            goto loc_F0039EE8;
          }
          uVar4 = puVar3[2];
        }
        if (uVar4 == 1) {
          cVar8 = (char)puVar3 + '\f';
          _loadaddrs();
        }
        else {
          cVar8 = '\x16';
        }
        *(char *)(dword_F0133DDC + 0x38) = cVar8;
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          piVar9 = &_exported;
          iVar2 = _exported;
joined_r0xf0039e54:
          do {
            if (iVar2 == 0) goto loc_F0039ED8;
            iVar2 = *piVar9 + 0x20;
            _bcmp(iVar2,puVar3 + 8,8);
            iVar6 = *piVar9;
            if (iVar2 == 0) {
              if (**(sword **)(iVar6 + 0x28) == *(sword *)puVar3[10]) {
                psVar7 = *(sword **)(iVar6 + 0x28) + 1;
                _bcmp(psVar7,(sword *)puVar3[10] + 1);
                iVar6 = *piVar9;
                if (psVar7 == (sword *)0x0) {
                  *piVar9 = *(int *)(iVar6 + 0x2c);
                  _exportfree();
                  iVar2 = *piVar9;
                  goto joined_r0xf0039e54;
                }
              }
              else {
                iVar6 = *piVar9;
              }
            }
            piVar9 = (int *)(iVar6 + 0x2c);
            iVar2 = *piVar9;
          } while( true );
        }
        pwVar5 = (word *)puVar3[10];
      }
      else {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        pwVar5 = (word *)puVar3[10];
      }
    }
    else {
      pwVar5 = (word *)puVar3[10];
    }
loc_F0039EE8:
    _kfree(pwVar5,*pwVar5 + 2);
    iVar2 = 0x30;
  }
  _kfree(puVar3,iVar2);
locret_F0039F04:
  return CONCAT44(param_2,param_1);
loc_F0039ED8:
  puVar3[0xb] = 0;
  *piVar9 = (int)puVar3;
  goto locret_F0039F04;
}
/* GHIDRADEC_FUNCTION index=825 start=0xf0039f0c */

/* WARNING: Removing unreachable block (ram,0xf0039f60) */
/* WARNING: Removing unreachable block (ram,0xf0039f78) */
/* WARNING: Removing unreachable block (ram,0xf0039f30) */

undefined8 _unexport(undefined4 param_1,sword *param_2)

{
  int iVar1;
  int iVar2;
  sword *psVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  piVar4 = &_exported;
  iVar1 = _exported;
  do {
    if (iVar1 == 0) {
      uVar5 = 0x16;
locret_F0039F9C:
      return CONCAT44(param_2,uVar5);
    }
    iVar1 = *piVar4 + 0x20;
    _bcmp(iVar1,param_1,8);
    iVar2 = *piVar4;
    if (iVar1 == 0) {
      if (**(sword **)(iVar2 + 0x28) == *param_2) {
        psVar3 = *(sword **)(iVar2 + 0x28) + 1;
        _bcmp(psVar3,param_2 + 1);
        iVar2 = *piVar4;
        if (psVar3 == (sword *)0x0) {
          *piVar4 = *(int *)(iVar2 + 0x2c);
          _exportfree();
          uVar5 = 0;
          goto locret_F0039F9C;
        }
      }
      else {
        iVar2 = *piVar4;
      }
    }
    iVar1 = *(int *)(iVar2 + 0x2c);
    piVar4 = (int *)(iVar2 + 0x2c);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=826 start=0xf0039fa4 */

/* WARNING: Removing unreachable block (ram,0xf003a138) */
/* WARNING: Removing unreachable block (ram,0xf003a104) */
/* WARNING: Removing unreachable block (ram,0xf0039fe4) */
/* WARNING: Removing unreachable block (ram,0xf003a068) */
/* WARNING: Removing unreachable block (ram,0xf003a034) */
/* WARNING: Removing unreachable block (ram,0xf003a0b0) */
/* WARNING: Removing unreachable block (ram,0xf003a0e4) */
/* WARNING: Removing unreachable block (ram,0xf003a120) */
/* WARNING: Removing unreachable block (ram,0xf003a150) */
/* WARNING: Removing unreachable block (ram,0xf0039fb4) */

undefined8 _nfs_getfh(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar6;
  uint *puVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  puVar7 = *(uint **)(dword_F0133DDC + 0x24);
  bVar1 = false;
  iVar2 = dword_F0133DDC;
  _suser();
  if (iVar2 == 0) {
    *(undefined *)(dword_F0133DDC + 0x38) = 1;
  }
  else {
    uVar3 = *puVar7;
    if (uVar3 < 0x100) {
      bVar1 = true;
      _getf();
      if ((uVar3 == 0) || (*(undefined **)(uVar3 + 0x14) != _vnodefops)) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        goto locret_F003A164;
      }
      uVar4 = *(undefined4 *)(uVar3 + 0x18);
      *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x30) = uVar4;
    }
    else {
      _lookupname(uVar3,0,1,(undefined *)((int)register0x00000038 + -0x2c),
                  (undefined *)((int)register0x00000038 + -0x30));
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar3;
      if (*(char *)(dword_F0133DDC + 0x38) == '\x11') {
        uVar3 = *puVar7;
        _lookupname(uVar3,0,1,0,(undefined *)((int)register0x00000038 + -0x30));
        *(char *)(dword_F0133DDC + 0x38) = (char)uVar3;
        *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
      }
      if ((*(char *)(dword_F0133DDC + 0x38) == '\0') &&
         (*(int *)((int)register0x00000038 + -0x30) == 0)) {
        if (*(int *)((int)register0x00000038 + -0x2c) != 0) {
          _vn_rele();
        }
        *(undefined *)(dword_F0133DDC + 0x38) = 2;
      }
      if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F003A164;
    }
    puVar5 = (undefined *)((int)register0x00000038 + -0x34);
    _findexivp(puVar5,*(undefined4 *)((int)register0x00000038 + -0x2c),
               *(undefined4 *)((int)register0x00000038 + -0x30));
    if (puVar5 == (undefined *)0x0) {
      puVar6 = (undefined *)((int)register0x00000038 + -0x28);
      puVar5 = puVar6;
      _makefh(puVar6,*(undefined4 *)((int)register0x00000038 + -0x30),
              *(undefined4 *)((int)register0x00000038 + -0x34));
      if (puVar5 == (undefined *)0x0) {
        _copyout(puVar6,puVar7[1],0x20);
        puVar5 = puVar6;
      }
    }
    if ((!bVar1) &&
       (_vn_rele(*(undefined4 *)((int)register0x00000038 + -0x30)),
       *(int *)((int)register0x00000038 + -0x2c) != 0)) {
      _vn_rele();
    }
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar5;
  }
locret_F003A164:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=827 start=0xf003a16c */

/* WARNING: Removing unreachable block (ram,0xf003a26c) */
/* WARNING: Removing unreachable block (ram,0xf003a1d0) */
/* WARNING: Removing unreachable block (ram,0xf003a254) */
/* WARNING: Removing unreachable block (ram,0xf003a240) */
/* WARNING: Removing unreachable block (ram,0xf003a1bc) */

undefined8 _findexivp(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *(int *)((int)register0x00000038 + 0x48) = param_2;
  *(sword *)(param_3 + 6) = *(sword *)(param_3 + 6) + 1;
  if (param_2 != 0) {
    *(sword *)(param_2 + 6) = *(sword *)(param_2 + 6) + 1;
  }
  while( true ) {
    iVar2 = param_3;
    (**(code **)(*(int *)(param_3 + 0x1c) + 100))
              (param_3,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar2 != 0) break;
    iVar1 = *(int *)(param_3 + 0x24) + 0x14;
    _findexport(iVar1,*(undefined4 *)((int)register0x00000038 + -0xc));
    *param_1 = iVar1;
    _kfree(*(word **)((int)register0x00000038 + -0xc),
           **(word **)((int)register0x00000038 + -0xc) + 2);
    if (((*param_1 != 0) || (iVar2 = 0x16, (*(word *)(param_3 + 4) & 1) != 0)) ||
       ((*(int *)((int)register0x00000038 + 0x48) == 0 &&
        (iVar2 = param_3,
        (**(code **)(*(int *)(param_3 + 0x1c) + 0x20))
                  (param_3,&unk_F010C9E8,(undefined *)((int)register0x00000038 + 0x48),
                   *(undefined4 *)(_active_u + 0x1c),0,0), iVar2 != 0)))) break;
    _vn_rele(param_3);
    param_3 = *(int *)((int)register0x00000038 + 0x48);
    *(undefined4 *)((int)register0x00000038 + 0x48) = 0;
  }
  _vn_rele(param_3);
  if (*(int *)((int)register0x00000038 + 0x48) != 0) {
    _vn_rele();
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=828 start=0xf003a27c */

/* WARNING: Removing unreachable block (ram,0xf003a320) */
/* WARNING: Removing unreachable block (ram,0xf003a2d0) */
/* WARNING: Removing unreachable block (ram,0xf003a304) */
/* WARNING: Removing unreachable block (ram,0xf003a330) */
/* WARNING: Removing unreachable block (ram,0xf003a344) */

undefined8 _makefh(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  word *pwVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar1 = param_2;
  (**(code **)(*(int *)(param_2 + 0x1c) + 100))
            (param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    pwVar3 = *(word **)((int)register0x00000038 + -0xc);
    if (pwVar3 == (word *)0x0) {
      uVar4 = 0x47;
    }
    else if ((uint)*pwVar3 + (uint)**(word **)(param_3 + 0x28) + 8 < 0x21) {
      _bzero(param_1,0x20);
      *param_1 = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x14);
      puVar2 = *(undefined2 **)((int)register0x00000038 + -0xc);
      param_1[1] = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x18);
      *(undefined2 *)(param_1 + 2) = *puVar2;
      _bcopy(puVar2 + 1,(int)param_1 + 10,*puVar2);
      *(undefined2 *)(param_1 + 5) = **(undefined2 **)(param_3 + 0x28);
      _bcopy(*(int *)(param_3 + 0x28) + 2,(int)param_1 + 0x16);
      _kfree(*(word **)((int)register0x00000038 + -0xc),
             **(word **)((int)register0x00000038 + -0xc) + 2);
      uVar4 = 0;
    }
    else {
      _kfree(pwVar3,*pwVar3 + 2);
      uVar4 = 0x47;
    }
  }
  else {
    uVar4 = 0x47;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=829 start=0xf003a358 */

/* WARNING: Removing unreachable block (ram,0xf003a3ac) */
/* WARNING: Removing unreachable block (ram,0xf003a37c) */

undefined8 _findexport(undefined4 param_1,sword *param_2)

{
  int iVar1;
  sword *psVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  iVar3 = _exported;
  if (_exported == 0) {
    iVar3 = 0;
  }
  else {
    do {
      iVar1 = iVar3 + 0x20;
      _bcmp(iVar1,param_1,8);
      if (iVar1 == 0) {
        if (**(sword **)(iVar3 + 0x28) == *param_2) {
          psVar2 = *(sword **)(iVar3 + 0x28) + 1;
          _bcmp(psVar2,param_2 + 1);
          if (psVar2 == (sword *)0x0) goto locret_F003A3D4;
          iVar3 = *(int *)(iVar3 + 0x2c);
        }
        else {
          iVar3 = *(int *)(iVar3 + 0x2c);
        }
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x2c);
      }
    } while (iVar3 != 0);
    iVar3 = 0;
  }
locret_F003A3D4:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=830 start=0xf003a3dc */

/* WARNING: Removing unreachable block (ram,0xf003a424) */
/* WARNING: Removing unreachable block (ram,0xf003a43c) */
/* WARNING: Removing unreachable block (ram,0xf003a410) */

undefined8 _loadaddrs(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
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
  uVar2 = *param_1 * 0x10;
  if (*param_1 < 0x401) {
    uVar3 = param_1[1];
    if (uVar2 == 0) {
      param_1[1] = 0;
      uVar3 = 0;
    }
    else {
      uVar1 = uVar2;
      _kalloc();
      param_1[1] = uVar1;
      _copyin(uVar3,uVar1,uVar2);
      if (uVar3 != 0) {
        _kfree(param_1[1],uVar2);
      }
    }
  }
  else {
    uVar3 = 0x16;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=831 start=0xf003a450 */

/* WARNING: Removing unreachable block (ram,0xf003a4b4) */
/* WARNING: Removing unreachable block (ram,0xf003a4a4) */
/* WARNING: Removing unreachable block (ram,0xf003a4c0) */
/* WARNING: Removing unreachable block (ram,0xf003a478) */

undefined8 _exportfree(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  word *pwVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  if (param_1[2] == 1) {
    if (param_1[3] == 0) {
      uVar1 = *param_1;
      goto loc_F003A484;
    }
    _kfree(param_1[4],param_1[3] << 4);
  }
  uVar1 = *param_1;
loc_F003A484:
  if ((uVar1 & 2) == 0) {
    pwVar2 = (word *)param_1[10];
  }
  else if (param_1[6] == 0) {
    pwVar2 = (word *)param_1[10];
  }
  else {
    _kfree(param_1[7],param_1[6] << 4);
    pwVar2 = (word *)param_1[10];
  }
  _kfree(pwVar2,*pwVar2 + 2);
  _kfree(param_1,0x30);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=832 start=0xf003a4d0 */

/* WARNING: Removing unreachable block (ram,0xf003a5c8) */
/* WARNING: Removing unreachable block (ram,0xf003a56c) */
/* WARNING: Removing unreachable block (ram,0xf003a518) */
/* WARNING: Removing unreachable block (ram,0xf003a548) */
/* WARNING: Removing unreachable block (ram,0xf003a590) */
/* WARNING: Removing unreachable block (ram,0xf003a620) */
/* WARNING: Removing unreachable block (ram,0xf003a4e4) */

undefined8 _nfs_svc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined uStack_1d;
  uint uStack_1c;
  
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
  iVar1 = **(int **)(dword_F0133DDC + 0x24);
  _getsock();
  if (iVar1 == 0) {
    *(undefined *)(dword_F0133DDC + 0x38) = 9;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x18);
    iVar1 = iVar2;
    _soreserve(iVar2,_nfs_chars,_nfs_chars + 0x20);
    if (iVar1 == 0) {
      _svckudp_create(iVar2,0x801);
      uStack_1c = 2;
      do {
        _svc_register(iVar2,0x186a3,uStack_1c,sub_F003BCD8,0);
        uStack_1c = uStack_1c + 1;
      } while (uStack_1c < 3);
      iVar1 = dword_F0133DDC + 0x28;
      _setjmp();
      if (iVar1 != 0) {
        _nfsd_count = _nfsd_count + -1;
        if (_nfsd_count == 0) {
          uStack_1c = 2;
          do {
            _svc_unregister(0x186a3,uStack_1c);
            uStack_1c = uStack_1c + 1;
          } while (uStack_1c < 3);
        }
        (**(code **)(*(int *)(iVar2 + 8) + 0x14))();
                    /* WARNING: Subroutine does not return */
        *(undefined *)(dword_F0133DDC + 0x38) = 4;
        _exit(0);
      }
      _nfsd_count = _nfsd_count + 1;
      _svc_run(iVar2);
    }
    else {
      uStack_1d = (undefined)iVar1;
      *(undefined *)(dword_F0133DDC + 0x38) = uStack_1d;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=833 start=0xf003c5d8 */

/* WARNING: Removing unreachable block (ram,0xf003c698) */
/* WARNING: Removing unreachable block (ram,0xf003c658) */
/* WARNING: Removing unreachable block (ram,0xf003c6d0) */
/* WARNING: Removing unreachable block (ram,0xf003c610) */

undefined8 _nfs_netboot_prealloc(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  undefined *puVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  int aiStack_20 [8];
  
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
  _MAXCLIENTS = _MAXCLIENTS + 3;
  if (_MAXCLIENTS != 0) {
    puVar4 = (undefined *)((int)register0x00000038 + -8);
    do {
      uVar3 = uVar3 + 1;
      uVar1 = param_1;
      sub_F003C3AC(param_1,*(undefined4 *)(_active_u + 0x1c));
      *(undefined4 *)(puVar4 + -0x18) = uVar1;
      puVar4 = puVar4 + 4;
    } while (uVar3 < _MAXCLIENTS);
  }
  uVar3 = 0;
  puVar4 = (undefined *)((int)register0x00000038 + -8);
  if (_MAXCLIENTS != 0) {
    do {
      if (*(int *)(puVar4 + -0x18) != 0) {
        sub_F003C6F0();
      }
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 4;
    } while (uVar3 < _MAXCLIENTS);
  }
  puVar4 = DAT_f010cc00;
  uVar3 = 0;
  iVar2 = _MAXCLIENTS * 0x2260;
  _kalloc(iVar2);
  if (_MAXCLIENTS != 0) {
    puVar4 = _chtable;
    do {
      uVar3 = uVar3 + 1;
      _clntkudp_realloc(*(undefined4 *)(puVar4 + 8),iVar2);
      puVar4 = puVar4 + 0xc;
      iVar2 = iVar2 + 0x2260;
    } while (uVar3 < _MAXCLIENTS);
  }
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=834 start=0xf003c774 */

/* WARNING: Removing unreachable block (ram,0xf003caa0) */
/* WARNING: Removing unreachable block (ram,0xf003cb60) */
/* WARNING: Removing unreachable block (ram,0xf003cb24) */
/* WARNING: Removing unreachable block (ram,0xf003cae8) */
/* WARNING: Removing unreachable block (ram,0xf003ca38) */
/* WARNING: Removing unreachable block (ram,0xf003c9f8) */
/* WARNING: Removing unreachable block (ram,0xf003c980) */
/* WARNING: Removing unreachable block (ram,0xf003c810) */
/* WARNING: Removing unreachable block (ram,0xf003c7e8) */
/* WARNING: Removing unreachable block (ram,0xf003c7fc) */
/* WARNING: Removing unreachable block (ram,0xf003c94c) */
/* WARNING: Removing unreachable block (ram,0xf003c998) */
/* WARNING: Removing unreachable block (ram,0xf003ca10) */
/* WARNING: Removing unreachable block (ram,0xf003ca4c) */
/* WARNING: Removing unreachable block (ram,0xf003cb10) */
/* WARNING: Removing unreachable block (ram,0xf003cb38) */
/* WARNING: Removing unreachable block (ram,0xf003cb6c) */
/* WARNING: Removing unreachable block (ram,0xf003cab8) */
/* WARNING: Removing unreachable block (ram,0xf003c7d4) */

undefined8
_rfscall(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
        int *param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 uVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  int iVar10;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar11;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  DAT_f013a9b8._0_4_ = DAT_f013a9b8._0_4_ + 1;
  iVar2 = *(int *)(DAT_f013a9b8 + param_2 * 4 + 8);
  *(undefined4 *)((int)register0x00000038 + -0x2c) = param_3;
  *(int *)(DAT_f013a9b8 + param_2 * 4 + 8) = iVar2 + 1;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  bVar1 = false;
  iVar10 = *(int *)((int)register0x00000038 + 0x5c);
  iVar2 = *(int *)(param_1 + 0x2c) << ((byte)*(undefined2 *)(unk_F010CF0E + param_2 * 2) & 0x1f);
  iVar9 = 0;
  do {
    iVar3 = param_1;
    sub_F003C3AC(param_1,iVar10);
    if (param_2 == 9) {
      _clntkudp_once();
    }
    do {
      iVar7 = 0;
      iVar4 = iVar2;
      .div(iVar2,10);
      *(int *)((int)register0x00000038 + -0x20) = iVar4;
      iVar5 = iVar2;
      .rem(iVar2,10);
      *(int *)((int)register0x00000038 + -0x1c) = iVar5 * 100000;
      *(int *)((int)register0x00000038 + -0x28) = iVar4;
      *(int *)((int)register0x00000038 + -0x24) = iVar5 * 100000;
      iVar4 = iVar3;
      (*(code *)**(undefined4 **)(iVar3 + 4))
                (iVar3,param_2,*(undefined4 *)((int)register0x00000038 + -0x2c),param_4,param_5,
                 param_6,(undefined *)((int)register0x00000038 + -0x28));
      switch(iVar4) {
      case :
      case :
      case :
      case :
      case :
      case :
      case :
loc_F003C988:
        bVar11 = iVar7 == 0;
        break;
      :
        if (iVar4 == 0x12) {
          bVar11 = (*(uint *)(param_1 + 0x14) & 0xa0000000) != 0x80000000;
          if (bVar11) {
            *(undefined4 *)((int)register0x00000038 + -0x18) = 0x12;
            *(undefined4 *)((int)register0x00000038 + -0x14) = 4;
            iVar7 = 0;
            goto loc_F003C910;
          }
        }
        else {
          iVar7 = -(*(int *)(param_1 + 0x14) >> 0x1f);
          bVar11 = iVar7 == 0;
loc_F003C910:
          if (!bVar11) {
            iVar5 = iVar2 * 4;
            iVar2 = 300;
            if (iVar5 < 0x12d) {
              iVar2 = iVar5;
            }
            if ((*(uint *)(param_1 + 0x14) & 0x40000000) == 0) {
              *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
              _printf(aNfsServerSNotR,param_1 + 0x34);
            }
            bVar11 = iVar7 == 0;
            if (!bVar1) {
              if (*(int *)(_active_u + 0x164) != 0) {
                bVar1 = true;
                _uprintf(aNfsServerSNotR_0,param_1 + 0x34);
              }
              goto loc_F003C988;
            }
          }
        }
      }
    } while (!bVar11);
    _clntkudp_once(iVar3,0);
    if (iVar4 != 0) {
      DAT_f013a9b8._4_4_ = DAT_f013a9b8._4_4_ + 1;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x10000000;
      if (iVar4 != 0x12) {
        *(int *)((int)register0x00000038 + -0x18) = iVar4;
        *(undefined4 *)((int)register0x00000038 + -0x14) = 0x16;
        param_2 = param_2 * 4;
        uVar8 = *(undefined4 *)(_rfsnames + param_2);
        iVar2 = iVar4;
        _clnt_sperrno(iVar4);
        _printf(aNfsSFailedForS,uVar8,param_1 + 0x34,iVar2);
        if (*(int *)(_active_u + 0x164) != 0) {
          uVar8 = *(undefined4 *)(_rfsnames + param_2);
          _clnt_sperrno(iVar4);
          _uprintf(aNfsSFailedForS_0,uVar8,param_1 + 0x34,iVar4);
        }
      }
      goto loc_F003CB24;
    }
    if (param_6 == (int *)0x0) {
      uVar6 = *(uint *)(param_1 + 0x14);
      goto loc_F003CAC8;
    }
    if (*param_6 != 0xd) {
      uVar6 = *(uint *)(param_1 + 0x14);
      goto loc_F003CAC8;
    }
    if (iVar9 != 0) {
      uVar6 = *(uint *)(param_1 + 0x14);
      goto loc_F003CAC8;
    }
    if (*(sword *)(iVar10 + 2) != 0) {
      uVar6 = *(uint *)(param_1 + 0x14);
      goto loc_F003CAC8;
    }
    if (*(sword *)(iVar10 + 6) == 0) {
      uVar6 = *(uint *)(param_1 + 0x14);
loc_F003CAC8:
      if ((int)uVar6 < 0) {
        if ((uVar6 & 0x40000000) != 0) {
          _printf(aNfsServerSOk,param_1 + 0x34);
          *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xbfffffff;
        }
        if (bVar1) {
          _uprintf(aNfsServerSOk_0,param_1 + 0x34);
        }
      }
      else {
        *(uint *)(param_1 + 0x14) = uVar6 & 0xefffffff;
      }
loc_F003CB24:
      sub_F003C6F0(iVar3);
      iVar2 = *(int *)((int)register0x00000038 + -0x18);
      if (iVar9 != 0) {
        _crfree(iVar9);
        iVar2 = *(int *)((int)register0x00000038 + -0x18);
      }
      uVar8 = *(undefined4 *)((int)register0x00000038 + -0x14);
      if ((iVar2 != 0) && (*(int *)((int)register0x00000038 + -0x14) == 0)) {
        _printf(aRfscallReStatu);
        _panic(&aRfscall);
        uVar8 = *(undefined4 *)((int)register0x00000038 + -0x14);
      }
      return CONCAT44(param_2,uVar8);
    }
    _crdup();
    *(undefined2 *)(iVar10 + 2) = *(undefined2 *)(iVar10 + 6);
    sub_F003C6F0(iVar3);
    iVar9 = iVar10;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=835 start=0xf003cb80 */

undefined8 _vattr_to_sattr(int param_1,uint *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  if (*(word *)(param_1 + 4) == 0xffff) {
    *param_2 = 0xffffffff;
  }
  else {
    *param_2 = (uint)*(word *)(param_1 + 4);
  }
  param_2[1] = (int)*(sword *)(param_1 + 6);
  param_2[2] = (int)*(sword *)(param_1 + 8);
  param_2[3] = *(uint *)(param_1 + 0x18);
  param_2[4] = *(uint *)(param_1 + 0x20);
  param_2[5] = *(uint *)(param_1 + 0x24);
  param_2[6] = *(uint *)(param_1 + 0x28);
  param_2[7] = *(uint *)(param_1 + 0x2c);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=836 start=0xf003cbe4 */

/* WARNING: Removing unreachable block (ram,0xf003cbf4) */

undefined8 _setdiropargs(int param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  _bcopy(*(int *)(param_3 + 0x30) + 0x40,param_1,0x20);
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=837 start=0xf003cc08 */

undefined8 _setdirgid(int param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  iVar2 = *(int *)(param_1 + 0x30);
  if ((*(uint *)(*(int *)(param_1 + 0x24) + 0xc) & 0x10) == 0) {
    if ((*(word *)(iVar2 + 0x84) & 0x400) == 0) {
      sVar1 = *(sword *)(*(int *)(_active_u + 0x1c) + 4);
      goto locret_F003CC48;
    }
    iVar2 = *(int *)(param_1 + 0x30);
  }
  sVar1 = *(sword *)(iVar2 + 0x88);
locret_F003CC48:
  return CONCAT44(param_2,(int)sVar1);
}
/* GHIDRADEC_FUNCTION index=838 start=0xf003cc50 */

undefined8 _setdirmode(int param_1,uint param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
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
  uVar1 = param_2 & 0xfffffbff;
  if ((*(word *)(*(int *)(param_1 + 0x30) + 0x84) & 0x400) != 0) {
    uVar1 = uVar1 | 0x400;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=839 start=0xf003cc74 */

/* WARNING: Removing unreachable block (ram,0xf003ccc4) */
/* WARNING: Removing unreachable block (ram,0xf003ccb0) */
/* WARNING: Removing unreachable block (ram,0xf003cca8) */
/* WARNING: Removing unreachable block (ram,0xf003ccb8) */
/* WARNING: Removing unreachable block (ram,0xf003ccd0) */
/* WARNING: Removing unreachable block (ram,0xf003cca0) */

undefined8 _rnode_cache_clear(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  piVar1 = _rpfreelist;
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
  while (piVar1 != (int *)0x0) {
    _rpfreelist = (int *)*piVar1;
    sub_F003D214(piVar1);
    _rp_rmhash(piVar1);
    _rinactive(piVar1);
    _mfs_uncache(piVar1 + 3);
    _zfree(_vm_info_zone,piVar1[3]);
    _zfree(_rnode_zone,piVar1);
    piVar1 = _rpfreelist;
  }
  _rpfreelist = piVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=840 start=0xf003ccf0 */

/* WARNING: Removing unreachable block (ram,0xf003ced8) */
/* WARNING: Removing unreachable block (ram,0xf003ce0c) */
/* WARNING: Removing unreachable block (ram,0xf003cddc) */
/* WARNING: Removing unreachable block (ram,0xf003cd50) */
/* WARNING: Removing unreachable block (ram,0xf003cdb8) */
/* WARNING: Removing unreachable block (ram,0xf003cd9c) */
/* WARNING: Removing unreachable block (ram,0xf003cda8) */
/* WARNING: Removing unreachable block (ram,0xf003cd48) */
/* WARNING: Removing unreachable block (ram,0xf003cd58) */
/* WARNING: Removing unreachable block (ram,0xf003cde8) */
/* WARNING: Removing unreachable block (ram,0xf003ce88) */
/* WARNING: Removing unreachable block (ram,0xf003cee4) */
/* WARNING: Removing unreachable block (ram,0xf003cd00) */

undefined8 _makenfsnode(int *param_1,int *param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  undefined2 uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  bVar1 = false;
  piVar2 = param_1;
  sub_F003D2E0(param_1,param_3);
  piVar3 = _rpfreelist;
  if (piVar2 == (int *)0x0) {
    if ((_rpfreelist == (int *)0x0) || (_rnew < _nrnode)) {
      if (_rnode_zone == (int *)0x0) {
        piVar3 = (int *)0xc8;
        _zinit(200,2000000,0,0,aRnodeStructure);
        _rnode_zone = piVar3;
      }
      piVar3 = _rnode_zone;
      _zalloc();
      piVar3[3] = 0;
      _vm_info_init(piVar3 + 3);
      _rnew = _rnew + 1;
    }
    else {
      _rpfreelist = (int *)*_rpfreelist;
      sub_F003D214(piVar3);
      _rp_rmhash(piVar3);
      _rinactive(piVar3);
      _rreuse = _rreuse + 1;
    }
    iVar5 = piVar3[3];
    _bzero(piVar3,200);
    piVar3[3] = iVar5;
    _mfs_uncache(piVar3 + 3);
    *(undefined4 *)piVar3[3] = 0;
    *(int *)(piVar3[3] + 0x14) = piVar3[0x26];
    _bcopy(param_1,piVar3 + 0x10,0x20);
    *(undefined2 *)((int)piVar3 + 0x12) = 1;
    piVar3[10] = (int)_nfs_vnodeops;
    if (param_2 != (int *)0x0) {
      iVar5 = *param_2;
      if ((iVar5 == 4) && (param_2[7] == -1)) {
        iVar5 = 8;
      }
      piVar3[0xd] = iVar5;
      if (*param_2 == 4) {
        if (param_2[7] == -1) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(undefined2 *)((int)param_2 + 0x1e);
        }
      }
      else {
        uVar4 = *(undefined2 *)((int)param_2 + 0x1e);
      }
      *(undefined2 *)(piVar3 + 0xe) = uVar4;
    }
    piVar3[0xf] = (int)piVar3;
    piVar3[0xc] = param_3;
    sub_F003CEF4(piVar3);
    bVar1 = true;
    *(int *)(*(int *)(param_3 + 0x128) + 0x18) = *(int *)(*(int *)(param_3 + 0x128) + 0x18) + 1;
    piVar2 = piVar3;
  }
  piVar2 = piVar2 + 3;
  if (param_2 != (int *)0x0) {
    if (!bVar1) {
      *(int *)((int)register0x00000038 + -0x10) = param_2[0xd];
      *(int *)((int)register0x00000038 + -0xc) = param_2[0xe];
      _nfs_cache_check(piVar2,(undefined *)((int)register0x00000038 + -0x10),param_2[5],0);
    }
    _nfs_attrcache(piVar2,param_2);
  }
  return CONCAT44(param_2,piVar2);
}
/* GHIDRADEC_FUNCTION index=841 start=0xf003d02c */

undefined8 _rp_rmhash(int param_1)

{
  int iVar1;
  byte bVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined4 unaff_i1;
  uint uVar4;
  undefined4 unaff_i2;
  uint uVar5;
  uint uVar6;
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
  bVar2 = *(byte *)(param_1 + 0x59) ^
          *(byte *)(param_1 + 0x58) ^
          *(byte *)(param_1 + 0x57) ^
          *(byte *)(param_1 + 0x56) ^
          *(byte *)(param_1 + 0x55) ^
          *(byte *)(param_1 + 0x54) ^
          *(byte *)(param_1 + 0x51) ^
          *(byte *)(param_1 + 0x50) ^
          *(byte *)(param_1 + 0x4f) ^
          *(byte *)(param_1 + 0x4e) ^
          *(byte *)(param_1 + 0x4d) ^
          *(byte *)(param_1 + 0x4c) ^ *(byte *)(param_1 + 0x4a) ^ *(byte *)(param_1 + 0x4b);
  uVar4 = (uint)bVar2;
  uVar5 = *(uint *)(_rtable +
                   ((byte)(*(byte *)(param_1 + 0x5b) ^ *(byte *)(param_1 + 0x5a) ^ bVar2) & 0x3f) *
                   4);
  uVar3 = 0;
  if (uVar5 != 0) {
    iVar1 = uVar5 - param_1;
    do {
      if (iVar1 == 0) {
        if (uVar3 == 0) {
          bVar2 = *(byte *)(uVar5 + 0x58) ^
                  *(byte *)(uVar5 + 0x57) ^
                  *(byte *)(uVar5 + 0x56) ^
                  *(byte *)(uVar5 + 0x55) ^
                  *(byte *)(uVar5 + 0x54) ^
                  *(byte *)(uVar5 + 0x51) ^
                  *(byte *)(uVar5 + 0x50) ^
                  *(byte *)(uVar5 + 0x4f) ^
                  *(byte *)(uVar5 + 0x4e) ^
                  *(byte *)(uVar5 + 0x4d) ^
                  *(byte *)(uVar5 + 0x4c) ^ *(byte *)(uVar5 + 0x4a) ^ *(byte *)(uVar5 + 0x4b);
          uVar3 = (uint)bVar2;
          bVar2 = *(byte *)(uVar5 + 0x59) ^ bVar2;
          uVar4 = (uint)bVar2;
          *(undefined4 *)
           (_rtable + ((byte)(*(byte *)(uVar5 + 0x5b) ^ *(byte *)(uVar5 + 0x5a) ^ bVar2) & 0x3f) * 4
           ) = *(undefined4 *)(uVar5 + 8);
        }
        else {
          *(undefined4 *)(uVar3 + 8) = *(undefined4 *)(uVar5 + 8);
        }
        _rnhash = _rnhash + -1;
        break;
      }
      uVar6 = *(uint *)(uVar5 + 8);
      iVar1 = uVar6 - param_1;
      uVar3 = uVar5;
      uVar5 = uVar6;
    } while (uVar6 != 0);
  }
  return CONCAT44(uVar4,uVar3);
}
/* GHIDRADEC_FUNCTION index=842 start=0xf003d284 */

/* WARNING: Removing unreachable block (ram,0xf003d298) */

undefined8 _rinactive(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  if (*(int *)(param_1 + 0x70) != 0) {
    _crfree();
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=843 start=0xf003d2ac */

/* WARNING: Removing unreachable block (ram,0xf003d2d0) */
/* WARNING: Removing unreachable block (ram,0xf003d2c4) */

undefined8 _rfree(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  iVar1 = *(int *)(*(int *)(param_1 + 0x30) + 0x128);
  *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -1;
  _rinactive(param_1);
  sub_F003D1AC(param_1,1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=844 start=0xf003d430 */

/* WARNING: Removing unreachable block (ram,0xf003d4a4) */
/* WARNING: Removing unreachable block (ram,0xf003d484) */
/* WARNING: Removing unreachable block (ram,0xf003d48c) */
/* WARNING: Removing unreachable block (ram,0xf003d4ac) */
/* WARNING: Removing unreachable block (ram,0xf003d470) */

undefined8 _rinval(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  int iVar3;
  undefined *puVar4;
  undefined4 unaff_l3;
  int iVar5;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  puVar4 = _rtable;
  iVar2 = _rtable._0_4_;
  while( true ) {
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x30);
      while( true ) {
        iVar3 = iVar2 + 0xc;
        iVar5 = *(int *)(iVar2 + 8);
        if (iVar1 == param_1) {
          _rp_rmhash(iVar2);
          *(sword *)(iVar2 + 0x12) = *(sword *)(iVar2 + 0x12) + 1;
          _binvalfree(iVar3);
          _dnlc_purge_vp(iVar3);
          if (1 < *(word *)(iVar2 + 0x12)) {
            sub_F003CEF4(iVar2);
          }
          _vn_rele(iVar3);
        }
        if (iVar5 == 0) break;
        iVar1 = *(int *)(iVar5 + 0x30);
        iVar2 = iVar5;
      }
    }
    puVar4 = (undefined *)((int)puVar4 + 4);
    if (_rtable + 0xff < puVar4) break;
    iVar2 = *(int *)puVar4;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=845 start=0xf003d4d8 */

/* WARNING: Removing unreachable block (ram,0xf003d53c) */

undefined8 _rflush(int param_1,undefined4 param_2)

{
  word wVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined *puVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  puVar3 = _rtable;
  iVar2 = _rtable._0_4_;
  while (iVar2 == 0) {
loc_F003D558:
    puVar3 = (undefined *)((int)puVar3 + 4);
    if (_rtable + 0xff < puVar3) {
      return CONCAT44(param_2,param_1);
    }
    iVar2 = *(int *)puVar3;
  }
  wVar1 = *(word *)(iVar2 + 0x10);
  do {
    if ((wVar1 & 0x80) == 0) {
      if ((*(uint *)(*(int *)(iVar2 + 0x30) + 0xc) & 1) == 0) {
        if ((param_1 == 0) || (*(int *)(iVar2 + 0x30) == param_1)) {
          _sync_vp(iVar2 + 0xc);
          goto loc_F003D544;
        }
        iVar2 = *(int *)(iVar2 + 8);
      }
      else {
        iVar2 = *(int *)(iVar2 + 8);
      }
    }
    else {
loc_F003D544:
      iVar2 = *(int *)(iVar2 + 8);
    }
    if (iVar2 == 0) goto loc_F003D558;
    wVar1 = *(word *)(iVar2 + 0x10);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=846 start=0xf003d56c */

/* WARNING: Removing unreachable block (ram,0xf003d5c4) */
/* WARNING: Removing unreachable block (ram,0xf003d570) */

undefined8 _newname(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined5 *puVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined *puVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  puVar2 = (undefined *)0xff;
  _kalloc();
  puVar3 = &aNfs;
  puVar5 = puVar2;
  do {
    *puVar5 = *(undefined *)puVar3;
    puVar3 = (undefined5 *)((int)puVar3 + 1);
    puVar5 = puVar5 + 1;
  } while (puVar3 < (undefined5 *)((int)&aNfs + 4));
  if (dword_F012F4EC == 0) {
    _getthetime((undefined *)((int)register0x00000038 + -0x10));
    dword_F012F4EC = *(uint *)((int)register0x00000038 + -0x10) & 0xffff;
  }
  iVar1 = dword_F012F4EC + 1;
  for (uVar4 = dword_F012F4EC; dword_F012F4EC = iVar1, uVar4 != 0; uVar4 = (int)uVar4 >> 4) {
    *puVar5 = a0123456789abcd_0[uVar4 & 0xf];
    puVar5 = puVar5 + 1;
    iVar1 = dword_F012F4EC;
  }
  *puVar5 = 0;
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=847 start=0xf003d624 */

/* WARNING: Removing unreachable block (ram,0xf003d658) */

undefined8 _rlock(int param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  wVar1 = *(word *)(param_1 + 0x60);
  if ((wVar1 & 1) != 0) {
    iVar2 = *(int *)(param_1 + 0x68);
    while (iVar2 != _active_threads) {
      *(word *)(param_1 + 0x60) = wVar1 | 2;
      _sleep(param_1,10);
      wVar1 = *(word *)(param_1 + 0x60);
      if ((wVar1 & 1) == 0) break;
      iVar2 = *(int *)(param_1 + 0x68);
    }
  }
  *(int *)(param_1 + 0x68) = _active_threads;
  *(sword *)(param_1 + 0x6c) = *(sword *)(param_1 + 0x6c) + 1;
  *(word *)(param_1 + 0x60) = *(word *)(param_1 + 0x60) | 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=848 start=0xf003d69c */

/* WARNING: Removing unreachable block (ram,0xf003d700) */
/* WARNING: Removing unreachable block (ram,0xf003d6c0) */

undefined8 _runlock(int param_1,undefined4 param_2)

{
  sword sVar1;
  word wVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  wVar2 = *(sword *)(param_1 + 0x6c) - 1;
  *(word *)(param_1 + 0x6c) = wVar2;
  if ((int)((uint)wVar2 * 0x10000) < 0) {
    _panic(&aRunlock);
    sVar1 = *(sword *)(param_1 + 0x6c);
  }
  else {
    sVar1 = *(sword *)(param_1 + 0x6c);
  }
  if (sVar1 == 0) {
    wVar2 = *(word *)(param_1 + 0x60);
    *(word *)(param_1 + 0x60) = wVar2 & 0xffde;
    if ((wVar2 & 2) != 0) {
      *(word *)(param_1 + 0x60) = wVar2 & 0xffdc;
      _wakeup(param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=849 start=0xf003d73c */

/* WARNING: Removing unreachable block (ram,0xf003d7f8) */
/* WARNING: Removing unreachable block (ram,0xf003d7c4) */
/* WARNING: Removing unreachable block (ram,0xf003d7a8) */
/* WARNING: Removing unreachable block (ram,0xf003d7b8) */
/* WARNING: Removing unreachable block (ram,0xf003d7d0) */
/* WARNING: Removing unreachable block (ram,0xf003d808) */
/* WARNING: Removing unreachable block (ram,0xf003d794) */

undefined8 _rlock_timeout(int param_1,undefined4 param_2)

{
  word wVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  wVar1 = *(word *)(param_1 + 0x60);
  if ((wVar1 & 1) != 0) {
    iVar4 = *(int *)(param_1 + 0x68);
    while( true ) {
      if (iVar4 == _active_threads) break;
      uVar5 = 1;
      if ((wVar1 & 0x20) != 0) {
        _rlockretimeout._0_4_ = _rlockretimeout._0_4_ + 1;
        goto locret_F003D848;
      }
      uVar2 = wVar1 | 2;
      *(sword *)(param_1 + 0x60) = (sword)uVar2;
      _splusclock();
      uVar5 = param_2;
      .umul(param_2,_hz);
      _timeout(sub_F003D710,param_1,uVar5);
      _sleep(param_1,10);
      pcVar3 = sub_F003D710;
      _untimeout(sub_F003D710,param_1);
      if (pcVar3 == (code *)0x0) {
        _rlocktimeout._0_4_ = _rlocktimeout._0_4_ + 1;
        *(word *)(param_1 + 0x60) = *(word *)(param_1 + 0x60) | 0x20;
        _splx(uVar2);
        uVar5 = 1;
        goto locret_F003D848;
      }
      _splx(uVar2);
      wVar1 = *(word *)(param_1 + 0x60);
      if ((wVar1 & 1) == 0) break;
      iVar4 = *(int *)(param_1 + 0x68);
    }
  }
  uVar5 = 0;
  *(int *)(param_1 + 0x68) = _active_threads;
  *(sword *)(param_1 + 0x6c) = *(sword *)(param_1 + 0x6c) + 1;
  *(word *)(param_1 + 0x60) = *(word *)(param_1 + 0x60) | 1;
locret_F003D848:
  return CONCAT44(param_2,uVar5);
}

