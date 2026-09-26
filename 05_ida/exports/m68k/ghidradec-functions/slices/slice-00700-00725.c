/* GHIDRADEC_FUNCTION index=700 start=0x401f810 */

byte _in_delmulti(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  undefined auStack_24 [16];
  undefined2 uStack_14;
  undefined4 uStack_10;
  
  uVar2 = param_1[3];
  param_1[3] = uVar2 - 1;
  cVar7 = 1 < uVar2;
  cVar6 = SBORROW4(1,uVar2);
  cVar4 = (int)(1 - uVar2) < 0;
  cVar5 = '\0';
  bVar8 = cVar7;
  if (uVar2 == 1) {
    _igmp_leavegroup(param_1);
    piVar3 = (int *)(param_1[2] + 0x44);
    puVar1 = (undefined4 *)*piVar3;
    while (param_1 != puVar1) {
      piVar3 = (int *)(*piVar3 + 0x14);
      puVar1 = (undefined4 *)*piVar3;
    }
    cVar7 = param_1 < puVar1;
    *piVar3 = *(int *)(*piVar3 + 0x14);
    uStack_14 = 2;
    uStack_10 = *param_1;
    _if_ioctl(param_1[1],0x80206932,auStack_24);
    uVar2 = (uint)param_1 & 0xffffff80;
    cVar4 = (int)uVar2 < 0;
    cVar5 = uVar2 == 0;
    cVar6 = '\0';
    bVar8 = 0;
    _m_free(uVar2);
  }
  return cVar7 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar8;
}
/* GHIDRADEC_FUNCTION index=701 start=0x401f898 */

undefined4 _in_pcballoc(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)_kalloc(0x3c);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0x37;
  }
  else {
    _bzero(piVar1,0x3c);
    piVar1[2] = (int)param_2;
    piVar1[6] = param_1;
    *piVar1 = *param_2;
    piVar1[1] = (int)param_2;
    *(int **)(*param_2 + 4) = piVar1;
    *param_2 = (int)piVar1;
    *(int **)(param_1 + 8) = piVar1;
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=702 start=0x401f8f0 */

undefined4 _in_pcbbind(int param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  word wVar6;
  int iVar7;
  
  iVar5 = *(int *)(param_1 + 0x18);
  iVar1 = *(int *)(param_1 + 8);
  wVar6 = 0;
  if (_in_ifaddr == 0) {
    return 0x31;
  }
  if ((*(sword *)(param_1 + 0x16) == 0) && (*(int *)(param_1 + 0x12) == 0)) {
    if (param_2 != 0) {
      iVar7 = *(int *)(param_2 + 4) + param_2;
      if (*(sword *)(param_2 + 8) != 0x10) goto loc_401F932;
      if (*(int *)(iVar7 + 4) != 0) {
        uVar2 = *(undefined2 *)(iVar7 + 2);
        *(undefined2 *)(iVar7 + 2) = 0;
        iVar4 = _ifa_ifwithaddr(iVar7);
        if (iVar4 == 0) {
          return 0x31;
        }
        *(undefined2 *)(iVar7 + 2) = uVar2;
      }
      wVar6 = *(word *)(iVar7 + 2);
      if (wVar6 != 0) {
        uVar3 = 0;
        if (((wVar6 < 0x400) && (*(sword *)(*(int *)(_active_u + 0x1a) + 2) != 0)) &&
           (-1 < *(char *)(iVar5 + 7))) {
          return 0xd;
        }
        if (((*(word *)(iVar5 + 2) & 4) == 0) &&
           (((*(byte *)(*(int *)(iVar5 + 0xc) + 9) & 4) == 0 || ((*(word *)(iVar5 + 2) & 2) == 0))))
        {
          uVar3 = 1;
        }
        iVar5 = _in_pcblookup(iVar1,_zeroin_addr,0,*(undefined4 *)(iVar7 + 4),wVar6,uVar3);
        if (iVar5 != 0) {
          return 0x30;
        }
      }
      *(undefined4 *)(param_1 + 0x12) = *(undefined4 *)(iVar7 + 4);
    }
    if (wVar6 == 0) {
      do {
        wVar6 = *(word *)(iVar1 + 0x16);
        *(sword *)(iVar1 + 0x16) = *(sword *)(iVar1 + 0x16) + 1;
        if ((wVar6 < 0xa00) || (5000 < *(word *)(iVar1 + 0x16))) {
          *(undefined2 *)(iVar1 + 0x16) = 0xa00;
        }
        wVar6 = *(word *)(iVar1 + 0x16);
        iVar5 = _in_pcblookup(iVar1,_zeroin_addr,0,*(undefined4 *)(param_1 + 0x12),wVar6,0);
      } while (iVar5 != 0);
    }
    *(word *)(param_1 + 0x16) = wVar6;
    uVar3 = 0;
  }
  else {
loc_401F932:
    uVar3 = 0x16;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=703 start=0x401fa2c */

undefined4 _in_pcbconnect(int param_1,int param_2)

{
  sword sVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  sword *psVar6;
  
  iVar5 = 0;
  psVar6 = (sword *)(*(int *)(param_2 + 4) + param_2);
  if (*(sword *)(param_2 + 8) != 0x10) {
    return 0x16;
  }
  if (*psVar6 != 2) {
    return 0x2f;
  }
  if (psVar6[1] == 0) {
    return 0x31;
  }
  if (_in_ifaddr != 0) {
    if (*(int *)(psVar6 + 2) == 0) {
      *(undefined4 *)(psVar6 + 2) = *(undefined4 *)(_in_ifaddr + 4);
    }
    else if ((*(int *)(psVar6 + 2) == -1) &&
            ((*(byte *)(*(int *)(_in_ifaddr + 0x20) + 0xd) & 2) != 0)) {
      *(undefined4 *)(psVar6 + 2) = *(undefined4 *)(_in_ifaddr + 0x14);
    }
  }
  if (*(int *)(param_1 + 0x12) != 0) goto loc_401FBC6;
  iVar5 = 0;
  piVar2 = (int *)(param_1 + 0x20);
  iVar4 = *piVar2;
  if (iVar4 == 0) {
loc_401FADE:
    if ((*(byte *)(*(int *)(param_1 + 0x18) + 3) & 0x10) == 0) goto loc_401FAEA;
  }
  else {
    if ((*(int *)(param_1 + 0x28) != *(int *)(psVar6 + 2)) ||
       ((*(byte *)(*(int *)(param_1 + 0x18) + 3) & 0x10) != 0)) {
      if (*(sword *)(iVar4 + 0x26) == 1) {
        _rtfree(iVar4);
      }
      else {
        *(sword *)(iVar4 + 0x26) = *(sword *)(iVar4 + 0x26) + -1;
      }
      *piVar2 = 0;
      goto loc_401FADE;
    }
loc_401FAEA:
    if ((*piVar2 == 0) || (*(int *)(*piVar2 + 0x2c) == 0)) {
      *(undefined2 *)(param_1 + 0x24) = 2;
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(psVar6 + 2);
      _rtalloc(piVar2);
    }
  }
  if (((*piVar2 == 0) || (iVar4 = *(int *)(*piVar2 + 0x2c), iVar4 == 0)) ||
     ((*(byte *)(iVar4 + 0xd) & 8) != 0)) {
loc_401FB3A:
    if (iVar5 == 0) goto loc_401FB3E;
  }
  else {
    iVar5 = _in_ifaddr;
    if (_in_ifaddr != 0) {
      do {
        if (iVar4 == *(int *)(iVar5 + 0x20)) break;
        iVar5 = *(int *)(iVar5 + 0x40);
      } while (iVar5 != 0);
      goto loc_401FB3A;
    }
loc_401FB3E:
    sVar1 = psVar6[1];
    psVar6[1] = 0;
    iVar5 = _ifa_ifwithdstaddr(psVar6);
    psVar6[1] = sVar1;
    if (iVar5 == 0) {
      uVar3 = _in_netof(*(undefined4 *)(psVar6 + 2));
      iVar5 = _in_iaonnetof(uVar3);
      if ((iVar5 == 0) && (iVar5 = _in_ifaddr, _in_ifaddr == 0)) {
        return 0x31;
      }
    }
  }
  if ((((*(uint *)(psVar6 + 2) & 0xf0000000) == 0xe0000000) &&
      (iVar4 = *(int *)(param_1 + 0x38), iVar4 != 0)) &&
     (iVar4 = *(int *)(*(int *)(iVar4 + 4) + iVar4), iVar4 != 0)) {
    iVar5 = _in_ifaddr;
    if (_in_ifaddr != 0) {
      do {
        if (iVar4 == *(int *)(iVar5 + 0x20)) break;
        iVar5 = *(int *)(iVar5 + 0x40);
      } while (iVar5 != 0);
      if (iVar5 != 0) goto loc_401FBC6;
    }
    return 0x31;
  }
loc_401FBC6:
  iVar4 = *(int *)(param_1 + 0x12);
  if (iVar4 == 0) {
    iVar4 = *(int *)(iVar5 + 4);
  }
  iVar4 = _in_pcblookup(*(undefined4 *)(param_1 + 8),*(undefined4 *)(psVar6 + 2),psVar6[1],iVar4,
                        *(undefined2 *)(param_1 + 0x16),0);
  if (iVar4 == 0) {
    if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x18) + 0xc) + 9) & 4) != 0) &&
       (*(sword *)(param_1 + 0x16) == psVar6[1])) {
      iVar4 = *(int *)(param_1 + 0x12);
      if (iVar4 == 0) {
        iVar4 = *(int *)(iVar5 + 4);
      }
      if (*(int *)(psVar6 + 2) == iVar4) {
        return 0x3d;
      }
    }
    if (*(int *)(param_1 + 0x12) == 0) {
      if (*(sword *)(param_1 + 0x16) == 0) {
        _in_pcbbind(param_1,0);
      }
      *(undefined4 *)(param_1 + 0x12) = *(undefined4 *)(iVar5 + 4);
    }
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(psVar6 + 2);
    *(sword *)(param_1 + 0x10) = psVar6[1];
    uVar3 = 0;
  }
  else {
    uVar3 = 0x30;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=704 start=0x401fc66 */

void _in_pcbdisconnect(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined2 *)(param_1 + 0x10) = 0;
  if ((*(byte *)(*(int *)(param_1 + 0x18) + 7) & 1) != 0) {
    _in_pcbdetach(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=705 start=0x401fc8e */

void _in_pcbdetach(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[6];
  *(undefined4 *)(iVar1 + 8) = 0;
  _sofree(iVar1);
  if (param_1[0xd] != 0) {
    _m_free(param_1[0xd]);
  }
  if (param_1[8] != 0) {
    _rtfree(param_1[8]);
  }
  _ip_freemoptions(param_1[0xe]);
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  _kfree(param_1,0x3c);
  return;
}
/* GHIDRADEC_FUNCTION index=706 start=0x401fcf8 */

void _in_setsockaddr(int param_1,int param_2)

{
  undefined2 *puVar1;
  
  *(undefined2 *)(param_2 + 8) = 0x10;
  puVar1 = (undefined2 *)(*(int *)(param_2 + 4) + param_2);
  _bzero(puVar1,0x10);
  *puVar1 = 2;
  puVar1[1] = *(undefined2 *)(param_1 + 0x16);
  *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(param_1 + 0x12);
  return;
}
/* GHIDRADEC_FUNCTION index=707 start=0x401fd3a */

void _in_setpeeraddr(int param_1,int param_2)

{
  undefined2 *puVar1;
  
  *(undefined2 *)(param_2 + 8) = 0x10;
  puVar1 = (undefined2 *)(*(int *)(param_2 + 4) + param_2);
  _bzero(puVar1,0x10);
  *puVar1 = 2;
  puVar1[1] = *(undefined2 *)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(param_1 + 0xc);
  return;
}
/* GHIDRADEC_FUNCTION index=708 start=0x401fd7c */

void _in_pcbnotify(undefined4 *param_1,sword *param_2,sword param_3,int param_4,sword param_5,
                  uint param_6,code *param_7)

{
  undefined4 *puVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  
  if (((param_6 < 0x16) && (*param_2 == 2)) && (iVar2 = *(int *)(param_2 + 2), iVar2 != 0)) {
    if (((param_6 - 0xe < 4) || (param_6 == 6)) || (param_6 == 1)) {
      param_3 = 0;
      param_5 = 0;
      param_4 = 0;
      if (param_6 != 6) {
        param_7 = _in_rtchange;
      }
    }
    bVar3 = _inetctlerrmap[param_6];
    puVar1 = (undefined4 *)*param_1;
    while (puVar4 = puVar1, param_1 != puVar4) {
      if ((((iVar2 == puVar4[3]) && (puVar4[6] != 0)) &&
          (((param_5 == 0 || (param_5 == *(sword *)((int)puVar4 + 0x16))) &&
           ((param_4 == 0 || (param_4 == *(int *)((int)puVar4 + 0x12))))))) &&
         ((param_3 == 0 || (param_3 == *(sword *)(puVar4 + 4))))) {
        if (bVar3 != 0) {
          *(word *)(puVar4[6] + 0x50) = (word)bVar3;
        }
        puVar1 = (undefined4 *)*puVar4;
        if (param_7 != (code *)0x0) {
          (*param_7)(puVar4);
        }
      }
      else {
        puVar1 = (undefined4 *)*puVar4;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=709 start=0x401fe46 */

void _in_losing(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 != 0) {
    if ((*(byte *)(iVar1 + 0x25) & 0x10) != 0) {
      _rtrequest(0x8030720b,iVar1);
    }
    _rtfree(iVar1);
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=710 start=0x401fe8a */

void _in_rtchange(int param_1)

{
  if (*(int *)(param_1 + 0x20) != 0) {
    _rtfree(*(int *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=711 start=0x401feae */

undefined4 *
_in_pcblookup(undefined4 *param_1,uint param_2,sword param_3,int param_4,sword param_5,byte param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  puVar4 = (undefined4 *)0x0;
  uVar3 = 3;
  puVar1 = (undefined4 *)*param_1;
  do {
    if (param_1 == puVar1) {
      return puVar4;
    }
    if (param_5 == *(sword *)((int)puVar1 + 0x16)) {
      uVar5 = 0;
      if (*(int *)((int)puVar1 + 0x12) == 0) {
        if (param_4 != 0) goto loc_401FEF0;
      }
      else {
        if (param_4 != 0) {
          if (param_4 == *(int *)((int)puVar1 + 0x12)) goto loc_401FEF4;
          goto loc_401FF36;
        }
loc_401FEF0:
        uVar5 = 1;
      }
loc_401FEF4:
      uVar2 = puVar1[3];
      if (uVar2 == 0) {
        if (param_2 != 0) goto loc_401FF1E;
      }
      else {
        if (param_2 != 0) {
          if (((param_3 == *(sword *)(puVar1 + 4)) && ((uVar2 & 0xf0000000) != 0xe0000000)) &&
             (param_2 == uVar2)) goto loc_401FF20;
          goto loc_401FF36;
        }
loc_401FF1E:
        uVar5 = uVar5 + 1;
      }
loc_401FF20:
      if (((uVar5 == 0) || ((param_6 & 1) != 0)) &&
         ((uVar5 < uVar3 && (uVar3 = uVar5, puVar4 = puVar1, uVar5 == 0)))) {
        return puVar1;
      }
    }
loc_401FF36:
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=712 start=0x401ff48 */

void _icmp_error(byte *param_1,uint param_2,undefined param_3,undefined4 param_4,undefined4 *param_5
                )

{
  undefined *puVar1;
  byte bVar2;
  sword sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = (*param_1 & 0xf) * 4;
  if (param_2 != 5) {
    _icmpstat = _icmpstat + 1;
  }
  if ((*(word *)(param_1 + 6) & 0x9fff) == 0) {
    if ((((param_1[9] == 1) && (param_2 != 5)) && (bVar2 = param_1[iVar5], bVar2 != 0)) &&
       (((bVar2 != 8 && (1 < (byte)(bVar2 - 0xd))) &&
        ((1 < (byte)(bVar2 - 0xf) && (1 < (byte)(bVar2 - 0x11))))))) {
      dword_40B7BDC = dword_40B7BDC + 1;
    }
    else if ((*(uint *)(param_1 + 0x10) & 0xf0000000) != 0xe0000000) {
      iVar4 = _in_broadcast(*(uint *)(param_1 + 0x10));
      if (iVar4 == 0) {
        iVar4 = _m_get(0,2);
        if (iVar4 != 0) {
          if (*(sword *)(param_1 + 2) < 9) {
            iVar7 = iVar5 + *(sword *)(param_1 + 2);
          }
          else {
            iVar7 = iVar5 + 8;
          }
          sVar3 = (sword)iVar7 + 8;
          *(sword *)(iVar4 + 8) = sVar3;
          iVar6 = 0x7c - sVar3;
          *(int *)(iVar4 + 4) = iVar6;
          puVar1 = (undefined *)(iVar4 + iVar6);
          if (0x12 < param_2) {
                    /* WARNING: Subroutine does not return */
            _panic(aIcmpError);
          }
          *(int *)(unk_40B7BE0 + param_2 * 4) = *(int *)(unk_40B7BE0 + param_2 * 4) + 1;
          *puVar1 = (char)param_2;
          if (param_2 == 5) {
            *(undefined4 *)(puVar1 + 4) = *param_5;
          }
          else {
            *(undefined4 *)(puVar1 + 4) = 0;
          }
          if (param_2 == 0xc) {
            puVar1[4] = param_3;
            param_3 = 0;
          }
          puVar1[1] = param_3;
          _bcopy(param_1,puVar1 + 8,iVar7);
          *(sword *)(puVar1 + 10) = (sword)iVar5 + *(sword *)(puVar1 + 10);
          if (0x70 < (uint)(*(sword *)(iVar4 + 8) + iVar5)) {
            iVar5 = 0x14;
          }
          if (0x70 < (uint)(iVar5 + *(sword *)(iVar4 + 8))) {
                    /* WARNING: Subroutine does not return */
            _panic(aIcmpLen);
          }
          *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) - iVar5;
          *(sword *)(iVar4 + 8) = (sword)iVar5 + *(sword *)(iVar4 + 8);
          iVar7 = *(int *)(iVar4 + 4) + iVar4;
          _bcopy(param_1,iVar7,iVar5);
          *(undefined2 *)(iVar7 + 2) = *(undefined2 *)(iVar4 + 8);
          *(undefined *)(iVar7 + 9) = 1;
          _icmp_reflect(iVar7,param_4);
        }
      }
    }
  }
  _m_freem((uint)param_1 & 0xffffff80);
  return;
}
/* GHIDRADEC_FUNCTION index=713 start=0x40200fe */

void _icmp_input(int param_1,undefined4 *param_2)

{
  code *pcVar1;
  word wVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  sword sVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  pbVar3 = (byte *)(*(int *)(param_1 + 4) + param_1);
  uVar9 = (uint)*(sword *)(pbVar3 + 2);
  uVar8 = *pbVar3 & 0xf;
  iVar4 = uVar8 * 4;
  if ((int)uVar9 < 8) {
    dword_40B7C30 = dword_40B7C30 + 1;
    goto loc_402057E;
  }
  if (uVar9 < 0x24) {
    iVar10 = uVar9 + iVar4;
  }
  else {
    iVar10 = iVar4 + 0x24;
  }
  if (((0x7c < *(uint *)(param_1 + 4)) || (*(sword *)(param_1 + 8) < iVar10)) &&
     (param_1 = _m_pullup(param_1,iVar10), param_1 == 0)) {
    dword_40B7C30 = dword_40B7C30 + 1;
    return;
  }
  iVar10 = *(int *)(param_1 + 4) + param_1;
  sVar7 = (sword)iVar4;
  *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) - sVar7;
  iVar4 = iVar4 + *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = iVar4;
  pbVar3 = (byte *)(param_1 + iVar4);
  iVar4 = _in_cksum(param_1,uVar9);
  if (iVar4 != 0) {
    dword_40B7C34 = dword_40B7C34 + 1;
    goto loc_402057E;
  }
  *(sword *)(param_1 + 8) = sVar7 + *(sword *)(param_1 + 8);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + uVar8 * -4;
  if (0x12 < *pbVar3) goto loc_4020550;
  *(int *)(unk_40B7C40 + (uint)*pbVar3 * 4) = *(int *)(unk_40B7C40 + (uint)*pbVar3 * 4) + 1;
  uVar8 = (uint)pbVar3[1];
  switch(*pbVar3) {
  :
    goto loc_4020550;
  case :
    if (5 < uVar8) {
loc_40202C6:
      dword_40B7C2C = dword_40B7C2C + 1;
      goto loc_4020550;
    }
    iVar4 = uVar8 + 8;
    break;
  case :
    if (uVar8 != 0) goto loc_40202C6;
    iVar4 = 4;
    break;
  case :
    if ((0x23 < uVar9) && ((int)((pbVar3[8] & 0xf) * 4 + 0x10) <= (int)uVar9)) {
      unk_40AEAD8._16_4_ = *(undefined4 *)(iVar10 + 0xc);
      unk_40AEAD8._0_4_ = *(undefined4 *)(pbVar3 + 4);
      if ((uVar8 == 0) || (uVar8 == 2)) {
        uVar6 = _in_netof(*(undefined4 *)(pbVar3 + 0x18),0);
        dword_40AEAC8 = _in_makeaddr(uVar6);
        _rtredirect(&unk_40AEAC4,&DAT_40aead4,2,0x40aeae4);
        dword_40AEAC8 = *(undefined4 *)(pbVar3 + 0x18);
        _pfctlinput(0xe,&unk_40AEAC4);
      }
      else {
        dword_40AEAC8 = *(undefined4 *)(pbVar3 + 0x18);
        _rtredirect(&unk_40AEAC4,&DAT_40aead4,6,0x40aeae4);
        _pfctlinput(0xf,&unk_40AEAC4);
      }
      goto loc_4020550;
    }
    goto loc_40203DC;
  case :
    *pbVar3 = 0;
    goto loc_402039C;
  case :
    if (1 < uVar8) goto loc_40202C6;
    iVar4 = uVar8 + 0x12;
    break;
  case :
    if (uVar8 != 0) goto loc_40202C6;
    iVar4 = 0x14;
    break;
  case :
    if (0x13 < uVar9) {
      *pbVar3 = 0xe;
      uVar6 = _iptime();
      *(undefined4 *)(pbVar3 + 0xc) = uVar6;
      *(undefined4 *)(pbVar3 + 0x10) = uVar6;
      goto loc_402039C;
    }
loc_40203DC:
    dword_40B7C38 = dword_40B7C38 + 1;
    goto loc_4020550;
  case :
    iVar4 = _in_netof(*(undefined4 *)(iVar10 + 0xc));
    if ((iVar4 == 0) && (iVar4 = _ifptoia(param_2), iVar4 != 0)) {
      uVar6 = _in_lnaof(*(undefined4 *)(iVar10 + 0xc));
      uVar6 = _in_netof(*(undefined4 *)(iVar4 + 4),uVar6);
      uVar6 = _in_makeaddr(uVar6);
      *(undefined4 *)(iVar10 + 0xc) = uVar6;
    }
    *pbVar3 = 0x10;
loc_402039C:
    *(sword *)(iVar10 + 2) = sVar7 + *(sword *)(iVar10 + 2);
    dword_40B7C3C = dword_40B7C3C + 1;
    *(int *)(unk_40B7BE0 + (uint)*pbVar3 * 4) = *(int *)(unk_40B7BE0 + (uint)*pbVar3 * 4) + 1;
    _icmp_reflect(iVar10,param_2);
    return;
  case :
    if (((0xb < (int)uVar9) && (iVar4 = _ifptoia(param_2), iVar4 != 0)) &&
       ((*(byte *)(iVar4 + 0x3f) & 2) != 0)) {
      *pbVar3 = 0x12;
      *(undefined4 *)(pbVar3 + 8) = *(undefined4 *)(iVar4 + 0x34);
      if (*(int *)(iVar10 + 0xc) == 0) {
        wVar2 = *(word *)(*(int *)(iVar4 + 0x20) + 0xc);
        if ((wVar2 & 2) == 0) {
          if ((wVar2 & 0x10) != 0) {
            *(undefined4 *)(iVar10 + 0xc) = *(undefined4 *)(iVar4 + 0x14);
          }
        }
        else {
          *(undefined4 *)(iVar10 + 0xc) = *(undefined4 *)(iVar4 + 0x14);
        }
      }
      goto loc_402039C;
    }
    goto loc_4020550;
  case :
    iVar4 = _ifptoia(param_2);
    if ((((iVar4 != 0) && ((*(uint *)(iVar4 + 0x3c) & 4) != 0)) &&
        ((*(uint *)(pbVar3 + 8) != 0xffffffff &&
         (((*(uint *)(pbVar3 + 8) & 0xff000000) == 0xff000000 &&
          (*(uint *)(iVar4 + 0x3c) = *(uint *)(iVar4 + 0x3c) & 0xfffffffb,
          (*(byte *)((int)param_2 + 0xd) & 8) == 0)))))) &&
       ((*(uint *)(pbVar3 + 8) | *(uint *)(iVar4 + 0x34)) != *(uint *)(iVar4 + 0x34))) {
      *(uint *)(iVar4 + 0x34) = *(uint *)(pbVar3 + 8);
      iVar5 = _in_ifinit(param_2,iVar4,iVar4);
      if (iVar5 == 0) {
        uVar6 = _inet_ntoa(iVar10 + 0xc);
        _printf(aSDSettingNetma,*param_2,(int)*(sword *)(param_2 + 2),*(undefined4 *)(iVar4 + 0x34),
                uVar6);
        _wakeup(iVar4 + 0x34);
      }
      else {
        _printf(aIcmpInputCanTS);
      }
    }
    goto loc_4020550;
  }
  if ((uVar9 < 0x24) || ((int)uVar9 < (int)((pbVar3[8] & 0xf) * 4 + 0x10))) {
    dword_40B7C38 = dword_40B7C38 + 1;
loc_402057E:
    _m_freem(param_1);
    return;
  }
  dword_40AEAC8 = *(undefined4 *)(pbVar3 + 0x18);
  pcVar1 = *(code **)((int)&dword_40AE970 + (uint)(byte)_ip_protox[pbVar3[0x11]] * 0x2e);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(iVar4,&unk_40AEAC4,pbVar3 + 8);
  }
loc_4020550:
  dword_40AEAC8 = *(undefined4 *)(iVar10 + 0xc);
  unk_40AEAD8._0_4_ = *(undefined4 *)(iVar10 + 0x10);
  _raw_input(param_1,&unk_40AEAC0,&unk_40AEAC4,&DAT_40aead4);
  return;
}
/* GHIDRADEC_FUNCTION index=714 start=0x4020590 */

void _icmp_reflect(byte *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = (*param_1 & 0xf) * 4 + -0x14;
  iVar1 = *(int *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0xc);
  iVar3 = _in_ifaddr;
  if (_in_ifaddr != 0) {
    while (iVar1 != *(int *)(iVar3 + 4)) {
      if ((((*(byte *)(*(int *)(iVar3 + 0x20) + 0xd) & 2) != 0) && (iVar1 == *(int *)(iVar3 + 0x14))
          ) || (iVar3 = *(int *)(iVar3 + 0x40), iVar3 == 0)) break;
    }
    if (iVar3 != 0) goto loc_40205FA;
  }
  iVar3 = _ifptoia(param_2);
  if (iVar3 == 0) {
    iVar3 = _in_ifaddr;
  }
loc_40205FA:
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar3 + 4);
  param_1[8] = 0xff;
  if (0 < iVar2) {
    iVar4 = _ip_srcroute();
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) - (sword)iVar2;
    _ip_stripoptions(param_1,0);
  }
  _icmp_send(param_1,iVar4);
  if (iVar4 != 0) {
    _m_free(iVar4);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=715 start=0x4020644 */

int _ifptoia(int param_1)

{
  int iVar1;
  
  iVar1 = _in_ifaddr;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (param_1 == *(int *)(iVar1 + 0x20)) break;
    iVar1 = *(int *)(iVar1 + 0x40);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=716 start=0x402066e */

void _icmp_send(byte *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  sword sVar5;
  
  uVar2 = (uint)param_1 & 0xffffff80;
  uVar3 = *param_1 & 0xf;
  *(uint *)(uVar2 + 4) = uVar3 * 4 + *(int *)(uVar2 + 4);
  sVar5 = (sword)(uVar3 * 4);
  *(sword *)(uVar2 + 8) = *(sword *)(uVar2 + 8) - sVar5;
  iVar1 = uVar2 + *(int *)(uVar2 + 4);
  *(undefined2 *)(iVar1 + 2) = 0;
  uVar4 = _in_cksum(uVar2,(int)*(sword *)(param_1 + 2) + uVar3 * -4);
  *(undefined2 *)(iVar1 + 2) = uVar4;
  *(uint *)(uVar2 + 4) = *(int *)(uVar2 + 4) + uVar3 * -4;
  *(sword *)(uVar2 + 8) = sVar5 + *(sword *)(uVar2 + 8);
  _ip_output(uVar2,param_2,0,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=717 start=0x40206f0 */

int _iptime(void)

{
  int iStack_c;
  int iStack_8;
  
  _microtime(&iStack_c);
  return iStack_8 / 1000 +
         (iStack_c +
         ((int)(sword)((sword)(iStack_c / 0x15180) + (sword)(iStack_c >> 0x1f)) - (iStack_c >> 0x1f)
         ) * -0x15180) * 1000;
}
/* GHIDRADEC_FUNCTION index=718 start=0x402075c */

undefined4 _icmp_sendMaskPacket(int param_1,char param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 uStack_14;
  undefined2 uStack_12;
  undefined4 uStack_10;
  
  iVar6 = 0;
  if (((*(word *)(param_1 + 0xc) & 1) == 0) || ((*(word *)(param_1 + 0xc) & 8) != 0)) {
    return 0;
  }
  iVar2 = _ifptoia(param_1);
  if (iVar2 == 0) {
    uVar5 = 0x33;
  }
  else {
    iVar6 = _m_get(1,2);
    if (iVar6 == 0) {
      uVar5 = 0x37;
    }
    else {
      *(undefined2 *)(iVar6 + 8) = 0x20;
      *(undefined4 *)(iVar6 + 4) = 0x5c;
      _bzero(iVar6 + 0x5c,(int)*(sword *)(iVar6 + 8));
      *(sword *)(iVar6 + 8) = *(sword *)(iVar6 + 8) + -0x14;
      iVar1 = *(int *)(iVar6 + 4) + 0x14;
      *(int *)(iVar6 + 4) = iVar1;
      puVar4 = (undefined *)(iVar6 + iVar1);
      if (param_2 == '\x12') {
        *puVar4 = 0x12;
        iVar1 = *(int *)(iVar2 + 0x34);
        *(int *)(puVar4 + 8) = iVar1;
        if (iVar1 == 0) {
          uVar5 = 0x16;
          goto loc_402090A;
        }
      }
      else {
        *puVar4 = 0x11;
      }
      puVar4[1] = 0;
      *(undefined2 *)(puVar4 + 2) = 0;
      *(undefined4 *)(puVar4 + 4) = 0;
      uVar3 = _in_cksum(iVar6,0xc);
      *(undefined2 *)(puVar4 + 2) = uVar3;
      *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + -0x14;
      *(sword *)(iVar6 + 8) = *(sword *)(iVar6 + 8) + 0x14;
      puVar4 = (undefined *)(*(int *)(iVar6 + 4) + iVar6);
      *puVar4 = 0x45;
      *(sword *)(puVar4 + 4) = _ip_id;
      _ip_id = _ip_id + 1;
      puVar4[8] = 0xff;
      puVar4[9] = 1;
      *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(puVar4 + 0x10) = 0xffffffff;
      *(undefined2 *)(puVar4 + 2) = 0x20;
      *(undefined2 *)(puVar4 + 10) = 0;
      uVar3 = _in_cksum(iVar6,0x14);
      *(undefined2 *)(puVar4 + 10) = uVar3;
      uStack_14 = 2;
      uStack_12 = 0;
      uStack_10 = 0xffffffff;
      if (0 < param_3) {
        _timeout(_wakeup,iVar2 + 0x34,_hz * param_3);
        _sleep(iVar2 + 0x34,0x19);
      }
      uVar5 = _if_output_mbuf(param_1,iVar6,&uStack_14);
      iVar6 = 0;
      if (param_2 == '\x11') {
        _timeout(_wakeup,iVar2 + 0x34,_hz);
        _sleep(iVar2 + 0x34,0x19);
      }
    }
  }
loc_402090A:
  if (iVar6 != 0) {
    _m_freem(iVar6);
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=719 start=0x4020922 */

void _ip_init(void)

{
  undefined (*pauVar1) [18];
  int iVar2;
  word wVar3;
  sword sVar5;
  undefined *puVar6;
  undefined (*pauVar7) [18];
  undefined auStack_c [2];
  undefined2 uStack_a;
  int iVar4;
  
  iVar2 = _pffindproto(2,0xff,3);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aIpInit);
  }
  iVar4 = 0xff;
  puVar6 = &unk_40B7D8B;
  do {
    do {
      *puVar6 = (char)((iVar2 + -0x40ae95e) * -0x1642c859 >> 1);
      puVar6 = puVar6 + -1;
      wVar3 = (word)((uint)iVar4 >> 0x10);
      sVar5 = (sword)iVar4 + -1;
      iVar4 = CONCAT22(wVar3,sVar5);
    } while (sVar5 != -1);
    iVar4 = (uint)wVar3 * 0x10000 + -1;
  } while (wVar3 != 0);
  pauVar7 = off_40AEAB4;
  if (off_40AEAB4 < unk_40AEAB8) {
    do {
      if (((**(int **)(*pauVar7 + 2) == 2) && (sVar5 = *(sword *)(*pauVar7 + 6), sVar5 != 0)) &&
         (sVar5 != 0xff)) {
        _ip_protox[sVar5] = (char)((int)(pauVar7[-0x397ebf] + 0x10) * -0x1642c859 >> 1);
      }
      pauVar1 = pauVar7 + 2;
      pauVar7 = (undefined (*) [18])(*pauVar1 + 10);
    } while ((undefined (*) [18])(*pauVar1 + 10) < unk_40AEAB8);
  }
  dword_40B6888 = &_ipq;
  _ipq = &_ipq;
  _getthetime(auStack_c);
  _ip_id = uStack_a;
  dword_40B7BC4 = _ipqmaxlen;
  return;
}
/* GHIDRADEC_FUNCTION index=720 start=0x4020a00 */

undefined4 _ipintr(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 extraout_D0u;
  int in_D0;
  int *piVar6;
  sword sVar8;
  int iVar7;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  int iVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  byte bVar18;
  int *piStack_8;
  
  iVar13 = 0;
loc_4020A0A:
  do {
    while( true ) {
      piVar10 = _ipintrq;
      uVar5 = (undefined2)((uint)in_D0 >> 0x10);
      cVar14 = '\0';
      cVar17 = '\0';
      bVar18 = 0;
      cVar15 = (int)_ipintrq < 0;
      cVar16 = _ipintrq == (int *)0x0;
      piVar6 = piVar10;
      if (!(bool)cVar16) {
        piVar2 = (int *)_ipintrq[0x1f];
        if (piVar2 == (int *)0x0) {
          dword_40B7BBC = 0;
        }
        piVar1 = _ipintrq + 0x1f;
        _ipintrq = piVar2;
        *piVar1 = 0;
        dword_40B7BC0 = dword_40B7BC0 + -1;
        iVar13 = *(int *)(piVar10[1] + (int)piVar10);
        piVar10[1] = piVar10[1] + 4;
        uVar5 = (undefined2)((uint)piVar2 >> 0x10);
        cVar14 = *(word *)(piVar10 + 2) < 4;
        sVar8 = *(word *)(piVar10 + 2) - 4;
        *(sword *)(piVar10 + 2) = sVar8;
        cVar15 = sVar8 < 0;
        cVar17 = '\0';
        bVar18 = 0;
        cVar16 = '\0';
        if (sVar8 == 0) {
          if (*(sword *)((int)piVar10 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(&aMfree);
          }
          (&word_40B61CC)[*(sword *)((int)piVar10 + 10)] =
               (&word_40B61CC)[*(sword *)((int)piVar10 + 10)] + -1;
          word_40B61CC = word_40B61CC + 1;
          *(undefined2 *)((int)piVar10 + 10) = 0;
          if (0x7f < (uint)piVar10[1]) {
            _mclput(piVar10);
          }
          piVar6 = (int *)*piVar10;
          *piVar10 = (int)_mfree;
          piVar10[1] = 0;
          piVar10[0x1f] = 0;
          _mfree = piVar10;
          uVar5 = 0;
          cVar17 = '\0';
          bVar18 = 0;
          cVar15 = _m_want < 0;
          cVar16 = _m_want == 0;
          if (!(bool)cVar16) {
            _m_want = 0;
            cVar15 = '\0';
            cVar16 = '\x01';
            cVar17 = '\0';
            bVar18 = 0;
            _wakeup(&_mfree);
            uVar5 = extraout_D0u;
          }
        }
      }
      if (piVar6 == (int *)0x0) {
        return CONCAT22(uVar5,(word)(byte)(cVar14 << 4 | cVar15 << 3 | cVar16 << 2 | cVar17 << 1 |
                                          bVar18));
      }
      if (_in_ifaddr != 0) break;
loc_4020E38:
      in_D0 = _m_freem(piVar6);
    }
    _ipstat = _ipstat + 1;
    if (((0x7c < (uint)piVar6[1]) || (*(word *)(piVar6 + 2) < 0x14)) &&
       (piVar6 = (int *)_m_pullup(piVar6,0x14), piVar6 == (int *)0x0)) {
      dword_40B68AC = dword_40B68AC + 1;
      in_D0 = 0;
      goto loc_4020A0A;
    }
    pbVar12 = (byte *)(piVar6[1] + (int)piVar6);
    uVar4 = (*pbVar12 & 0xf) * 4;
    if (uVar4 < 0x14) {
      dword_40B68B0 = dword_40B68B0 + 1;
      goto loc_4020E38;
    }
    if ((int)uVar4 <= (int)*(sword *)(piVar6 + 2)) {
loc_4020B62:
      if (_ipcksum != '\0') {
        sVar8 = _in_cksum(piVar6,uVar4);
        *(sword *)(pbVar12 + 10) = sVar8;
        if (sVar8 != 0) {
          dword_40B68A4 = dword_40B68A4 + 1;
          goto loc_4020E38;
        }
      }
      if ((int)*(sword *)(pbVar12 + 2) < (int)uVar4) {
        dword_40B68B4 = dword_40B68B4 + 1;
        goto loc_4020E38;
      }
      iVar9 = (int)*(sword *)(piVar6 + 2) - (uint)*(word *)(pbVar12 + 2);
      iVar7 = *piVar6;
      piVar10 = piVar6;
      while (iVar7 != 0) {
        piVar10 = (int *)*piVar10;
        iVar9 = *(sword *)(piVar10 + 2) + iVar9;
        iVar7 = *piVar10;
      }
      piStack_8 = piVar6;
      if (iVar9 != 0) {
        if (iVar9 < 0) {
          dword_40B68A8 = dword_40B68A8 + 1;
          goto loc_4020E38;
        }
        if (*(sword *)(piVar10 + 2) < iVar9) {
          _m_adj(piVar6,-iVar9);
        }
        else {
          *(sword *)(piVar10 + 2) = *(sword *)(piVar10 + 2) - (sword)iVar9;
        }
      }
      piVar6 = piStack_8;
      _ip_nhops = 0;
      if ((uVar4 < 0x15) || (in_D0 = _ip_dooptions(pbVar12,iVar13), in_D0 == 0)) {
        if ((((*(byte *)(iVar13 + 0xc) & 0x40) == 0) ||
            (((0x7c < (uint)piVar6[1] || (*(word *)(piVar6 + 2) < 0x1c)) &&
             (piVar6 = (int *)_m_pullup(piVar6,0x1c), piVar6 == (int *)0x0)))) ||
           ((*(char *)((int)piVar6 + piVar6[1] + 9) != '\x11' ||
            (*(sword *)((int)piVar6 + piVar6[1] + 0x16) != 0x44)))) {
          if (_in_ifaddr != 0) {
            iVar7 = *(int *)(pbVar12 + 0x10);
            iVar9 = _in_ifaddr;
            do {
              if ((iVar7 == *(int *)(iVar9 + 4)) ||
                 (((*(byte *)(*(int *)(iVar9 + 0x20) + 0xd) & 2) != 0 &&
                  ((((iVar7 == *(int *)(iVar9 + 0x14) || (iVar7 == *(int *)(iVar9 + 0x38))) ||
                    (iVar7 == *(int *)(iVar9 + 0x30))) || (iVar7 == *(int *)(iVar9 + 0x28)))))))
              goto loc_4020D3E;
              iVar9 = *(int *)(iVar9 + 0x40);
            } while (iVar9 != 0);
          }
          uVar3 = *(uint *)(pbVar12 + 0x10);
          if ((uVar3 & 0xf0000000) == 0xe0000000) {
            if (_ip_mrouter != 0) {
              iVar7 = _ip_mforward(pbVar12,iVar13);
              if (iVar7 != 0) {
                piVar6 = (int *)((uint)pbVar12 & 0xffffff80);
                goto loc_4020E38;
              }
              if (pbVar12[9] == 2) goto loc_4020D3E;
            }
            iVar7 = _in_ifaddr;
            if (_in_ifaddr != 0) {
              do {
                if (iVar13 == *(int *)(iVar7 + 0x20)) break;
                iVar7 = *(int *)(iVar7 + 0x40);
              } while (iVar7 != 0);
              if ((iVar7 != 0) && (piVar10 = *(int **)(iVar7 + 0x44), piVar10 != (int *)0x0)) {
                do {
                  if (*(int *)(pbVar12 + 0x10) == *piVar10) break;
                  piVar10 = (int *)piVar10[5];
                } while (piVar10 != (int *)0x0);
                if (piVar10 != (int *)0x0) goto loc_4020D3E;
              }
            }
            piVar6 = (int *)((uint)pbVar12 & 0xffffff80);
            goto loc_4020E38;
          }
          if ((uVar3 != 0xffffffff) && (uVar3 != 0)) {
            in_D0 = _ip_forward(pbVar12,iVar13);
            goto loc_4020A0A;
          }
        }
loc_4020D3E:
        if ((*(word *)(pbVar12 + 6) & 0xbfff) == 0) {
          *(sword *)(pbVar12 + 2) = *(sword *)(pbVar12 + 2) - (sword)uVar4;
        }
        else {
          if ((undefined4 **)_ipq != &_ipq) {
            puVar11 = _ipq;
            do {
              if ((((*(sword *)(pbVar12 + 4) == *(sword *)((int)puVar11 + 10)) &&
                   (*(int *)(pbVar12 + 0xc) == puVar11[5])) &&
                  (*(int *)(pbVar12 + 0x10) == puVar11[6])) &&
                 (pbVar12[9] == *(byte *)((int)puVar11 + 9))) goto loc_4020D88;
              puVar11 = (undefined4 *)*puVar11;
            } while ((undefined4 **)puVar11 != &_ipq);
          }
          puVar11 = (undefined4 *)0x0;
loc_4020D88:
          *(sword *)(pbVar12 + 2) = *(sword *)(pbVar12 + 2) - (sword)uVar4;
          pbVar12[1] = 0;
          if ((pbVar12[6] & 0x20) != 0) {
            pbVar12[1] = 1;
          }
          sVar8 = *(sword *)(pbVar12 + 6);
          *(sword *)(pbVar12 + 6) = sVar8 << 3;
          if ((pbVar12[1] == 0) && ((sword)(sVar8 << 3) == 0)) {
            if (puVar11 != (undefined4 *)0x0) {
              _ip_freef(puVar11);
            }
          }
          else {
            dword_40B68B8 = dword_40B68B8 + 1;
            pbVar12 = (byte *)_ip_reass(pbVar12,puVar11);
            in_D0 = 0;
            if (pbVar12 == (byte *)0x0) goto loc_4020A0A;
            piVar6 = (int *)((uint)pbVar12 & 0xffffff80);
          }
        }
        piStack_8 = piVar6;
        in_D0 = _receive_ip_datagram(&piStack_8);
        if (in_D0 == 0) {
          in_D0 = (**(code **)((int)&DAT_40ae968 + (uint)(byte)_ip_protox[pbVar12[9]] * 0x2e))
                            (piStack_8,iVar13);
        }
      }
      goto loc_4020A0A;
    }
    piVar6 = (int *)_m_pullup(piVar6,uVar4);
    if (piVar6 != (int *)0x0) {
      pbVar12 = (byte *)(piVar6[1] + (int)piVar6);
      goto loc_4020B62;
    }
    dword_40B68B0 = dword_40B68B0 + 1;
    in_D0 = 0;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=721 start=0x4020e4e */

byte * _ip_reass(byte *param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined *puVar8;
  uint uStack_2c;
  uint uStack_28;
  uint *puVar9;
  
  puVar8 = &stack0xffffffdc;
  uVar4 = (uint)param_1 & 0xffffff80;
  iVar6 = (*param_1 & 0xf) * 4;
  *(int *)(uVar4 + 4) = iVar6 + *(int *)(uVar4 + 4);
  *(sword *)(uVar4 + 8) = *(sword *)(uVar4 + 8) - (sword)iVar6;
  if (param_2 == (int *)0x0) {
    uStack_28 = 0xb;
    uStack_2c = 0;
    iVar6 = _m_get();
    puVar8 = &stack0xffffffdc;
    if (iVar6 == 0) {
loc_4021082:
      dword_40B68BC = dword_40B68BC + 1;
      uStack_2c = 0x4021090;
      uStack_28 = uVar4;
      _m_freem();
      return (byte *)0x0;
    }
    piVar7 = (int *)(*(int *)(iVar6 + 4) + iVar6);
    *piVar7 = (int)_ipq;
    piVar7[1] = (int)&_ipq;
    _ipq[1] = (int)piVar7;
    _ipq = piVar7;
    *(undefined *)(piVar7 + 2) = 0x3c;
    *(byte *)((int)piVar7 + 9) = param_1[9];
    *(undefined2 *)((int)piVar7 + 10) = *(undefined2 *)(param_1 + 4);
    piVar7[4] = (int)piVar7;
    piVar7[3] = (int)piVar7;
    piVar7[5] = *(int *)(param_1 + 0xc);
    piVar7[6] = *(int *)(param_1 + 0x10);
    param_2 = piVar7;
  }
  else {
    piVar7 = (int *)param_2[3];
    if (param_2 != piVar7) {
      do {
        if (*(sword *)(param_1 + 6) < *(sword *)((int)piVar7 + 6)) break;
        piVar7 = (int *)piVar7[3];
      } while (param_2 != piVar7);
    }
    piVar2 = (int *)piVar7[4];
    if (param_2 == piVar2) goto loc_4020FAA;
    iVar6 = ((int)(sword)*piVar2 + (int)*(sword *)((int)piVar2 + 6)) - (int)*(sword *)(param_1 + 6);
    if (iVar6 < 1) goto loc_4020FAA;
    if (*(sword *)(param_1 + 2) <= iVar6) goto loc_4021082;
    uStack_2c = (uint)param_1 & 0xffffff80;
    puVar9 = &uStack_2c;
    uStack_28 = iVar6;
    _m_adj();
    *(sword *)(param_1 + 6) = (sword)iVar6 + *(sword *)(param_1 + 6);
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) - (sword)iVar6;
    while( true ) {
      puVar8 = (undefined *)((int)puVar9 + 8);
loc_4020FAA:
      if (param_2 == piVar7) goto loc_4020FAE;
      if ((int)*(sword *)(param_1 + 2) + (int)*(sword *)(param_1 + 6) <=
          (int)*(sword *)((int)piVar7 + 6)) goto loc_4020FAE;
      iVar6 = ((int)*(sword *)(param_1 + 2) + (int)*(sword *)(param_1 + 6)) -
              (int)*(sword *)((int)piVar7 + 6);
      if (iVar6 < (sword)*piVar7) break;
      piVar7 = (int *)piVar7[3];
      *(uint *)(puVar8 + -4) = piVar7[4] & 0xffffff80;
      *(undefined4 *)(puVar8 + -8) = 0x4020f9e;
      _m_freem();
      puVar9 = (uint *)(puVar8 + -8);
      *(int *)(puVar8 + -8) = piVar7[4];
      *(undefined4 *)(puVar8 + -0xc) = 0x4020fa8;
      _ip_deq();
    }
    *(sword *)((int)piVar7 + 2) = (sword)*piVar7 - (sword)iVar6;
    *(sword *)((int)piVar7 + 6) = (sword)iVar6 + *(sword *)((int)piVar7 + 6);
    *(int *)(puVar8 + -4) = iVar6;
    *(uint *)(puVar8 + -8) = (uint)piVar7 & 0xffffff80;
    *(undefined4 *)(puVar8 + -0xc) = 0x4020f08;
    _m_adj();
  }
loc_4020FAE:
  *(int *)(puVar8 + -4) = piVar7[4];
  *(byte **)(puVar8 + -8) = param_1;
  *(undefined4 *)(puVar8 + -0xc) = 0x4020fba;
  _ip_enq();
  iVar6 = 0;
  for (piVar7 = (int *)param_2[3]; param_2 != piVar7; piVar7 = (int *)piVar7[3]) {
    if (iVar6 != *(sword *)((int)piVar7 + 6)) {
      return (byte *)0x0;
    }
    iVar6 = (sword)*piVar7 + iVar6;
  }
  if (*(char *)(piVar7[4] + 1) != '\0') {
    return (byte *)0x0;
  }
  uVar4 = param_2[3];
  puVar5 = (undefined4 *)(uVar4 & 0xffffff80);
  uVar1 = *puVar5;
  *puVar5 = 0;
  *(undefined4 *)(puVar8 + -4) = uVar1;
  *(undefined4 **)(puVar8 + -8) = puVar5;
  *(undefined4 *)(puVar8 + -0xc) = 0x4021004;
  _m_cat();
  piVar7 = *(int **)(uVar4 + 0xc);
  while (param_2 != piVar7) {
    uVar4 = (uint)piVar7 & 0xffffff80;
    piVar7 = (int *)piVar7[3];
    *(uint *)(puVar8 + -4) = uVar4;
    *(undefined4 **)(puVar8 + -8) = puVar5;
    *(undefined4 *)(puVar8 + -0xc) = 0x402101e;
    _m_cat();
  }
  pbVar3 = (byte *)param_2[3];
  *(sword *)(pbVar3 + 2) = (sword)iVar6;
  *(int *)(pbVar3 + 0xc) = param_2[5];
  *(int *)(pbVar3 + 0x10) = param_2[6];
  *(int *)(*param_2 + 4) = param_2[1];
  *(int *)param_2[1] = *param_2;
  *(uint *)(puVar8 + -4) = (uint)param_2 & 0xffffff80;
  *(undefined4 *)(puVar8 + -8) = 0x4021054;
  _m_free();
  uVar4 = (uint)pbVar3 & 0xffffff80;
  *(word *)(uVar4 + 8) = (*pbVar3 & 0xf) * 4 + *(sword *)(uVar4 + 8);
  *(uint *)(uVar4 + 4) = *(int *)(uVar4 + 4) + (*pbVar3 & 0xf) * -4;
  return pbVar3;
}
/* GHIDRADEC_FUNCTION index=722 start=0x402109c */

void _ip_freef(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1[3];
  while (param_1 != piVar2) {
    piVar1 = (int *)piVar2[3];
    _ip_deq(piVar2);
    _m_freem((uint)piVar2 & 0xffffff80);
    piVar2 = piVar1;
  }
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  _m_free((uint)param_1 & 0xffffff80);
  return;
}
/* GHIDRADEC_FUNCTION index=723 start=0x40210f8 */

void _ip_enq(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(int *)(*(int *)(param_2 + 0xc) + 0x10) = param_1;
  *(int *)(param_2 + 0xc) = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=724 start=0x4021124 */

void _ip_deq(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10) = *(undefined4 *)(param_1 + 0x10);
  return;
}

