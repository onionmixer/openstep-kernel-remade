/* GHIDRADEC_FUNCTION index=775 start=0x40257bc */

void _udp_notify(int param_1)

{
  _sowakeup(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18) + 0x22);
  _sowakeup(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18) + 0x38);
  return;
}
/* GHIDRADEC_FUNCTION index=776 start=0x40257f2 */

void _udp_ctlinput(uint param_1,undefined4 param_2,byte *param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  
  if ((param_1 == 1) || ((param_1 < 0x16 && (_inetctlerrmap[param_1] != '\0')))) {
    if (param_3 == (byte *)0x0) {
      uVar3 = 0;
      uVar1 = 0;
      uVar2 = _zeroin_addr;
    }
    else {
      uVar3 = *(undefined2 *)(param_3 + (*param_3 & 0xf) * 4);
      uVar1 = *(undefined2 *)(param_3 + (*param_3 & 0xf) * 4 + 2);
      uVar2 = *(undefined4 *)(param_3 + 0xc);
    }
    _in_pcbnotify(&_udb,param_2,uVar1,uVar2,uVar3,param_1,_udp_notify);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=777 start=0x4025874 */

undefined4 _udp_output(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  sword sVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar1 = _mfree;
  iVar5 = 0;
  for (puVar4 = param_2; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    iVar5 = *(sword *)(puVar4 + 2) + iVar5;
  }
  if (_mfree == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)_m_more(0,2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMget);
    }
    *(undefined2 *)((int)_mfree + 10) = 2;
    word_40B61CC = word_40B61CC + -1;
    word_40B61D0 = word_40B61D0 + 1;
    puVar4 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar4;
    puVar1[1] = 0xc;
  }
  if (puVar1 == (undefined4 *)0x0) {
    _m_freem(param_2);
    uVar2 = 0x37;
  }
  else {
    puVar1[1] = 0x60;
    *(undefined2 *)(puVar1 + 2) = 0x1c;
    *puVar1 = param_2;
    puVar4 = (undefined4 *)(puVar1[1] + (int)puVar1);
    puVar4[1] = 0;
    *puVar4 = 0;
    *(undefined *)(puVar4 + 2) = 0;
    *(undefined *)((int)puVar4 + 9) = 0x11;
    *(sword *)((int)puVar4 + 10) = (sword)iVar5 + 8;
    puVar4[3] = *(undefined4 *)(param_1 + 0x12);
    puVar4[4] = *(undefined4 *)(param_1 + 0xc);
    *(undefined2 *)(puVar4 + 5) = *(undefined2 *)(param_1 + 0x16);
    *(undefined2 *)((int)puVar4 + 0x16) = *(undefined2 *)(param_1 + 0x10);
    *(undefined2 *)(puVar4 + 6) = *(undefined2 *)((int)puVar4 + 10);
    *(undefined2 *)((int)puVar4 + 0x1a) = 0;
    if (_udpcksum != 0) {
      sVar3 = _in_cksum(puVar1,iVar5 + 0x1c);
      *(sword *)((int)puVar4 + 0x1a) = sVar3;
      if (sVar3 == 0) {
        *(undefined2 *)((int)puVar4 + 0x1a) = 0xffff;
      }
    }
    *(sword *)((int)puVar4 + 2) = (sword)iVar5 + 0x1c;
    *(undefined *)(puVar4 + 2) = byte_40AEBC7;
    uVar2 = _ip_output(puVar1,*(undefined4 *)(param_1 + 0x34),param_1 + 0x20,
                       *(word *)(*(int *)(param_1 + 0x18) + 2) & 0x32 | 2,
                       *(undefined4 *)(param_1 + 0x38));
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=778 start=0x40259b8 */

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
/* GHIDRADEC_FUNCTION index=779 start=0x4025be0 */

void _igmp_init(void)

{
  dword_40B3528 = 0xe0000001;
  return;
}
/* GHIDRADEC_FUNCTION index=780 start=0x4025bf2 */

void _igmp_input(int param_1,int param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  
  _igmpstat = _igmpstat + 1;
  pbVar1 = (byte *)(param_1 + *(uint *)(param_1 + 4));
  uVar5 = *pbVar1 & 0xf;
  iVar9 = uVar5 * 4;
  iVar8 = (int)*(sword *)(pbVar1 + 2);
  if (iVar8 < 8) {
    dword_40BBE20 = dword_40BBE20 + 1;
  }
  else {
    if (((0x7c < *(uint *)(param_1 + 4)) || ((int)*(sword *)(param_1 + 8) < iVar9 + 8)) &&
       (param_1 = _m_pullup(param_1,iVar9 + 8), param_1 == 0)) {
      dword_40BBE20 = dword_40BBE20 + 1;
      return;
    }
    *(int *)(param_1 + 4) = iVar9 + *(int *)(param_1 + 4);
    *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) - (sword)iVar9;
    pcVar4 = (char *)(*(int *)(param_1 + 4) + param_1);
    iVar8 = _in_cksum(param_1,iVar8);
    if (iVar8 == 0) {
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + uVar5 * -4;
      *(sword *)(param_1 + 8) = (sword)iVar9 + *(sword *)(param_1 + 8);
      iVar8 = _in_ifaddr;
      iVar9 = dword_40B3528;
      iVar12 = *(int *)(param_1 + 4) + param_1;
      if (*pcVar4 == '\x11') {
        dword_40BBE28 = dword_40BBE28 + 1;
        if (param_2 != _loifp) {
          if (*(int *)(iVar12 + 0x10) != dword_40B3528) {
            dword_40BBE2C = dword_40BBE2C + 1;
            goto loc_4025DC8;
          }
          piVar11 = (int *)0x0;
          piVar10 = (int *)0x0;
          iVar3 = _in_ifaddr;
          do {
            iVar6 = 0;
            if (iVar3 == 0) goto joined_r0x04025d06;
            piVar10 = *(int **)(iVar3 + 0x44);
            iVar3 = *(int *)(iVar3 + 0x40);
          } while (piVar10 == (int *)0x0);
          piVar11 = (int *)piVar10[5];
          iVar6 = iVar3;
joined_r0x04025d06:
          if (piVar10 != (int *)0x0) {
            iVar3 = iVar6;
            piVar7 = piVar11;
            if (((param_2 == piVar10[1]) && (piVar10[4] == 0)) && (iVar9 != *piVar10)) {
              piVar10[4] = (uint)(*piVar10 + *(int *)(iVar8 + 4) + _ipstat) % 0x32 + 1;
              dword_40AEC04 = 1;
            }
            while (piVar10 = piVar7, piVar10 == (int *)0x0) {
              iVar6 = 0;
              if (iVar3 == 0) goto joined_r0x04025d06;
              puVar2 = (undefined4 *)(iVar3 + 0x44);
              iVar3 = *(int *)(iVar3 + 0x40);
              piVar7 = (int *)*puVar2;
            }
            piVar11 = (int *)piVar10[5];
            iVar6 = iVar3;
            goto joined_r0x04025d06;
          }
        }
      }
      else if ((*pcVar4 == '\x12') && (dword_40BBE30 = dword_40BBE30 + 1, param_2 != _loifp)) {
        if (((*(uint *)(pcVar4 + 4) & 0xf0000000) != 0xe0000000) ||
           (*(uint *)(pcVar4 + 4) != *(uint *)(iVar12 + 0x10))) {
          dword_40BBE34 = dword_40BBE34 + 1;
          goto loc_4025DC8;
        }
        if (((*(uint *)(iVar12 + 0xc) & 0xff000000) == 0) && (iVar9 = _in_ifaddr, _in_ifaddr != 0))
        {
          do {
            if (param_2 == *(int *)(iVar9 + 0x20)) break;
            iVar9 = *(int *)(iVar9 + 0x40);
          } while (iVar9 != 0);
          if (iVar9 != 0) {
            *(undefined4 *)(iVar12 + 0xc) = *(undefined4 *)(iVar9 + 0x30);
          }
        }
        iVar9 = _in_ifaddr;
        if (_in_ifaddr != 0) {
          do {
            if (param_2 == *(int *)(iVar9 + 0x20)) break;
            iVar9 = *(int *)(iVar9 + 0x40);
          } while (iVar9 != 0);
          if ((iVar9 != 0) && (piVar11 = *(int **)(iVar9 + 0x44), piVar11 != (int *)0x0)) {
            do {
              if (*(int *)(pcVar4 + 4) == *piVar11) break;
              piVar11 = (int *)piVar11[5];
            } while (piVar11 != (int *)0x0);
            if (piVar11 != (int *)0x0) {
              piVar11[4] = 0;
              dword_40BBE38 = dword_40BBE38 + 1;
            }
          }
        }
      }
      unk_40AEBE8._0_4_ = *(undefined4 *)(iVar12 + 0xc);
      unk_40AEBF8._0_4_ = *(undefined4 *)(iVar12 + 0x10);
      _raw_input(param_1,&unk_40AEBE0,0x40aebe4,0x40aebf4);
      return;
    }
    dword_40BBE24 = dword_40BBE24 + 1;
  }
loc_4025DC8:
  _m_freem(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=781 start=0x4025e86 */

undefined4 _igmp_joingroup(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined4 in_D0;
  uint uVar4;
  char cVar5;
  bool bVar6;
  
  uVar3 = (undefined2)((uint)in_D0 >> 0x10);
  bVar6 = *param_1 < dword_40B3528;
  if ((*param_1 == dword_40B3528) || (bVar6 = param_1[1] < _loifp, param_1[1] == _loifp)) {
    param_1[4] = 0;
    cVar5 = '\x01';
  }
  else {
    _igmp_sendreport(param_1);
    uVar1 = *param_1 + *(int *)(_in_ifaddr + 4) + _ipstat;
    uVar4 = uVar1 / 0x32;
    uVar2 = uVar4 * 0x19;
    bVar6 = CARRY4(uVar2,uVar2);
    uVar3 = (undefined2)(uVar4 * 0x32 >> 0x10);
    param_1[4] = uVar1 % 0x32 + 1;
    dword_40AEC04 = 1;
    cVar5 = '\0';
  }
  return CONCAT22(uVar3,(word)(byte)(bVar6 << 4 | cVar5 << 2));
}
/* GHIDRADEC_FUNCTION index=782 start=0x4025f0e */

void _igmp_leavegroup(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=783 start=0x4025f6a */

void _igmp_fasttimo(void)

{
  int iVar1;
  int iVar2;
  undefined auStack_c [8];
  
  if (dword_40AEC04 != 0) {
    dword_40AEC04 = 0;
    iVar2 = sub_4025F4C(auStack_c);
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x10);
      if (iVar1 != 0) {
        *(int *)(iVar2 + 0x10) = iVar1 + -1;
        if (iVar1 == 1) {
          _igmp_sendreport(iVar2);
        }
        else {
          dword_40AEC04 = 1;
        }
      }
      iVar2 = sub_4025F16(auStack_c);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=784 start=0x4025fe2 */

uint _igmp_sendreport(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte bVar12;
  
  puVar2 = _mfree;
  cVar8 = '\0';
  if (_mfree == (undefined4 *)0x0) {
    cVar9 = '\0';
    cVar10 = '\x01';
    cVar11 = '\0';
    bVar12 = 0;
    puVar2 = (undefined4 *)_m_more(0,2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMget);
    }
    *(undefined2 *)((int)_mfree + 10) = 2;
    word_40B61CC = word_40B61CC + -1;
    cVar8 = 0xfffe < word_40B61D0;
    word_40B61D0 = word_40B61D0 + 1;
    puVar3 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar3;
    puVar2[1] = 0xc;
    cVar9 = '\0';
    cVar10 = '\0';
    cVar11 = '\0';
    bVar12 = 0;
  }
  puVar3 = _mfree;
  uVar4 = (uint)(byte)(cVar8 << 4 | cVar9 << 3 | cVar10 << 2 | cVar11 << 1 | bVar12);
  if (puVar2 != (undefined4 *)0x0) {
    if (_mfree == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)_m_more(0,0xe);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)((int)_mfree + 10) = 0xe;
      word_40B61CC = word_40B61CC + -1;
      word_40B61E8 = word_40B61E8 + 1;
      puVar6 = (undefined4 *)*_mfree;
      *_mfree = 0;
      _mfree = puVar6;
      puVar3[1] = 0xc;
    }
    if (puVar3 == (undefined4 *)0x0) {
      uVar4 = _m_free(puVar2);
    }
    else {
      puVar2[1] = 0x74;
      *(undefined2 *)(puVar2 + 2) = 8;
      puVar7 = (undefined *)(puVar2[1] + (int)puVar2);
      *puVar7 = 0x12;
      puVar7[1] = 0;
      *(undefined4 *)(puVar7 + 4) = *param_1;
      *(undefined2 *)(puVar7 + 2) = 0;
      uVar5 = _in_cksum(puVar2,8);
      *(undefined2 *)(puVar7 + 2) = uVar5;
      puVar2[1] = puVar2[1] + -0x14;
      *(sword *)(puVar2 + 2) = *(sword *)(puVar2 + 2) + 0x14;
      iVar1 = puVar2[1];
      *(undefined *)((int)puVar2 + iVar1 + 1) = 0;
      *(undefined2 *)((int)puVar2 + iVar1 + 2) = 0x1c;
      *(undefined2 *)((int)puVar2 + iVar1 + 6) = 0;
      *(undefined *)((int)puVar2 + iVar1 + 9) = 2;
      *(undefined4 *)((int)puVar2 + iVar1 + 0xc) = 0;
      *(undefined4 *)((int)puVar2 + iVar1 + 0x10) = *(undefined4 *)(puVar7 + 4);
      puVar6 = (undefined4 *)(puVar3[1] + (int)puVar3);
      *puVar6 = param_1[1];
      *(undefined *)(puVar6 + 1) = 1;
      *(bool *)((int)puVar6 + 5) = _ip_mrouter != 0;
      _ip_output(puVar2,0,0,2,puVar3);
      uVar4 = _m_free(puVar3);
      dword_40BBE3C = dword_40BBE3C + 1;
    }
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=785 start=0x402616c */

undefined4 _ip_mrouter_cmd(void)

{
  return 0x2d;
}
/* GHIDRADEC_FUNCTION index=786 start=0x4026176 */

undefined4 _ip_mrouter_done(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=787 start=0x4026180 */

undefined4 _ip_mforward(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=788 start=0x402618a */

void _nfs_validate_caches(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_3e [58];
  
  _nfsgetattr(param_1,auStack_3e,param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=789 start=0x40261a8 */

void _nfs_invalidate_caches(int param_1)

{
  _vnode_uncache(param_1);
  _mfs_invalidate(param_1);
  *(undefined4 *)(*(int *)(param_1 + 0x2e) + 0xb6) = 0;
  _dnlc_purge_vp(param_1);
  _binvalfree(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=790 start=0x40261e2 */

void _nfs_purge_caches(int param_1,undefined4 param_2)

{
  _sync_vp_invalidate(param_1,param_2);
  _vnode_uncache(param_1);
  *(undefined4 *)(*(int *)(param_1 + 0x2e) + 0xb6) = 0;
  _dnlc_purge_vp(param_1);
  _binvalfree(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=791 start=0x4026220 */

void _nfs_cache_check(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  if ((-1 < *(char *)(iVar1 + 0x11)) &&
     (((param_2 != *(int *)(iVar1 + 0xa0) || (param_3 != *(int *)(iVar1 + 0xa4))) ||
      (param_4 != *(int *)(iVar1 + 0x90))))) {
    _nfs_purge_caches(param_1,param_5);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=792 start=0x4026266 */

void _nfs_attrcache(int param_1,undefined4 param_2)

{
  if (((*(byte *)(param_1 + 5) & 0x40) == 0) &&
     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x14) & 8) == 0)) {
    _nattr_to_vattr(param_1,param_2,*(int *)(param_1 + 0x2e) + 0x7c);
    sub_4026304(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=793 start=0x40262ac */

void _nfs_attrcache_va(int param_1,undefined4 *param_2)

{
  if (((*(byte *)(param_1 + 5) & 0x40) == 0) &&
     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x14) & 8) == 0)) {
    _bcopy(param_2,*(int *)(param_1 + 0x2e) + 0x7c,0x3a);
    *(undefined4 *)(param_1 + 0x28) = *param_2;
    sub_4026304(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=794 start=0x402640a */

int _nfs_getattr_otw(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)_kalloc(0x48);
  iVar2 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x126),1,_xdr_fhandle,
                   *(int *)(param_1 + 0x2e) + 0x3e,_xdr_attrstat,piVar1,param_3);
  if (iVar2 == 0) {
    iVar2 = *piVar1;
    if (iVar2 == 0) {
      _nattr_to_vattr(param_1,piVar1 + 1,param_2);
      *(uint *)(param_2 + 10) =
           *(uint *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x26) | 0xff00;
    }
    else if (iVar2 == 0x46) {
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
  }
  _kfree(piVar1,0x48);
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=795 start=0x40264b8 */

int _nfsgetattr(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = sub_402637E(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = _nfs_getattr_otw(param_1,param_2,param_3);
    if (iVar1 == 0) {
      _nfs_cache_check(param_1,*(undefined4 *)(param_2 + 0x24),*(undefined4 *)(param_2 + 0x28),
                       *(undefined4 *)(param_2 + 0x14),param_4);
      _nfs_attrcache_va(param_1,param_2);
    }
  }
  else {
    iVar1 = 0;
  }
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0x2e) + 0x90);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=796 start=0x402652a */

void _nattr_to_vattr(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  undefined uVar3;
  
  iVar1 = *(int *)((int)param_1 + 0x2e);
  *param_3 = *param_2;
  *(undefined2 *)(param_3 + 1) = *(undefined2 *)((int)param_2 + 6);
  *(undefined2 *)((int)param_3 + 6) = *(undefined2 *)((int)param_2 + 0xe);
  *(undefined2 *)(param_3 + 2) = *(undefined2 *)((int)param_2 + 0x12);
  uVar3 = _vfs_fixedmajor(param_1[9]);
  *(uint *)((int)param_3 + 10) =
       (uint)CONCAT11(uVar3,*(undefined *)(*(int *)(param_1[9] + 0x126) + 0x29));
  *(int *)((int)param_3 + 0xe) = param_2[10];
  *(undefined2 *)((int)param_3 + 0x12) = *(undefined2 *)((int)param_2 + 10);
  uVar2 = *(uint *)(*param_1 + 0x14);
  if (((uint)param_2[5] < uVar2) &&
     (((*(byte *)(*param_1 + 0x34) & 0x40) != 0 || ((*(byte *)(iVar1 + 0x5f) & 0x10) != 0)))) {
    param_3[5] = uVar2;
  }
  else {
    param_3[5] = param_2[5];
  }
  if ((*(uint *)(iVar1 + 0x90) < (uint)param_3[5]) || ((*(byte *)(iVar1 + 0x5f) & 0x10) == 0)) {
    *(int *)(iVar1 + 0x90) = param_3[5];
  }
  param_3[7] = param_2[0xb];
  param_3[8] = param_2[0xc];
  param_3[9] = param_2[0xd];
  param_3[10] = param_2[0xe];
  param_3[0xb] = param_2[0xf];
  param_3[0xc] = param_2[0x10];
  *(undefined2 *)(param_3 + 0xd) = *(undefined2 *)((int)param_2 + 0x1e);
  *(int *)((int)param_3 + 0x36) = param_2[8];
  if (*param_2 == 3) {
    param_3[6] = 0x800;
  }
  else if (*param_2 == 4) {
    param_3[6] = 0x2000;
  }
  else {
    param_3[6] = param_2[6];
  }
  if ((*param_2 == 4) && (param_2[7] == -1)) {
    *param_3 = 8;
    *(word *)(param_3 + 1) = *(word *)(param_3 + 1) & 0xfff | 0x1000;
    *(undefined2 *)(param_3 + 0xd) = 0;
    param_3[6] = param_2[6];
  }
  return;
}
/* GHIDRADEC_FUNCTION index=797 start=0x4026652 */

undefined4 _nfstsize(void)

{
  return 0x2000;
}
/* GHIDRADEC_FUNCTION index=798 start=0x4026660 */

void _vattr_to_nattr(int *param_1,int *param_2)

{
  sword sVar1;
  
  *param_2 = *param_1;
  sVar1 = *(sword *)(param_1 + 1);
  if (sVar1 == -1) {
    param_2[1] = -1;
  }
  else {
    *(undefined2 *)(param_2 + 1) = 0;
    *(sword *)((int)param_2 + 6) = sVar1;
  }
  if (*(sword *)((int)param_1 + 6) == -1) {
    param_2[3] = -1;
  }
  else {
    param_2[3] = (int)*(sword *)((int)param_1 + 6);
  }
  if (*(sword *)(param_1 + 2) == -1) {
    param_2[4] = -1;
  }
  else {
    param_2[4] = (int)*(sword *)(param_1 + 2);
  }
  param_2[9] = *(int *)((int)param_1 + 10);
  param_2[10] = *(int *)((int)param_1 + 0xe);
  param_2[2] = (int)*(sword *)((int)param_1 + 0x12);
  param_2[5] = param_1[5];
  param_2[0xb] = param_1[7];
  param_2[0xc] = param_1[8];
  param_2[0xd] = param_1[9];
  param_2[0xe] = param_1[10];
  param_2[0xf] = param_1[0xb];
  param_2[0x10] = param_1[0xc];
  param_2[7] = (int)*(sword *)(param_1 + 0xd);
  param_2[8] = *(int *)((int)param_1 + 0x36);
  param_2[6] = param_1[6];
  if (*param_1 == 8) {
    *param_2 = 4;
    param_2[7] = -1;
    param_2[1] = param_2[1] & 0xffff0fffU | 0x2000;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=799 start=0x4026734 */

uint _exportfs(void)

{
  undefined4 *puVar1;
  word wVar2;
  int iVar3;
  uint uVar4;
  undefined uVar6;
  uint *puVar5;
  int *piVar7;
  word *pwStack_c;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar3 = _suser();
  if (iVar3 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 1;
    return 0;
  }
  uVar4 = _lookupname(*puVar1,0,1,0,&iStack_8);
  *(char *)(dword_40B57D4 + 100) = (char)uVar4;
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return uVar4;
  }
  uVar6 = (**(code **)(*(int *)(iStack_8 + 0x1c) + 100))(iStack_8,&pwStack_c);
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  iVar3 = *(int *)(iStack_8 + 0x24);
  uVar4 = _vn_rele(iStack_8);
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return uVar4;
  }
  if (puVar1[1] == 0) {
    uVar6 = _unexport(iVar3 + 0x14,pwStack_c);
    *(undefined *)(dword_40B57D4 + 100) = uVar6;
    uVar4 = _kfree(pwStack_c,*pwStack_c + 2);
    return uVar4;
  }
  puVar5 = (uint *)_kalloc(0x30);
  puVar5[8] = *(uint *)(iVar3 + 0x14);
  puVar5[9] = *(uint *)(iVar3 + 0x18);
  puVar5[10] = (uint)pwStack_c;
  uVar6 = _copyinmsg(puVar1[1],puVar5,0x20);
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if ((*puVar5 & 0xfffffffc) == 0) {
      uVar4 = 0;
      if ((*puVar5 & 2) != 0) {
        uVar4 = _loadaddrs(puVar5 + 6);
        *(char *)(dword_40B57D4 + 100) = (char)uVar4;
        if (*(char *)(dword_40B57D4 + 100) != '\0') goto loc_4026938;
      }
      if (puVar5[2] == 1) {
        uVar4 = _loadaddrs(puVar5 + 3);
        *(char *)(dword_40B57D4 + 100) = (char)uVar4;
      }
      else {
        *(undefined *)(dword_40B57D4 + 100) = 0x16;
      }
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        piVar7 = &_exported;
        iVar3 = _exported;
        do {
          if (iVar3 == 0) {
            puVar5[0xb] = 0;
            *piVar7 = (int)puVar5;
            return uVar4;
          }
          uVar4 = _bcmp(*piVar7 + 0x20,puVar5 + 8,8);
          if (uVar4 == 0) {
            wVar2 = **(word **)(*piVar7 + 0x28);
            uVar4 = (uint)wVar2;
            if ((wVar2 != *(word *)puVar5[10]) ||
               (uVar4 = _bcmp(*(word **)(*piVar7 + 0x28) + 1,(word *)puVar5[10] + 1,wVar2),
               uVar4 != 0)) goto loc_4026926;
            iVar3 = *piVar7;
            *piVar7 = *(int *)(iVar3 + 0x2c);
            uVar4 = _exportfree(iVar3);
          }
          else {
loc_4026926:
            piVar7 = (int *)(*piVar7 + 0x2c);
          }
          iVar3 = *piVar7;
        } while( true );
      }
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
loc_4026938:
  _kfree((word *)puVar5[10],*(word *)puVar5[10] + 2);
  uVar4 = _kfree(puVar5,0x30);
  return uVar4;
}

