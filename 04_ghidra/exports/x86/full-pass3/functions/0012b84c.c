/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012b84c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _udp_usrreq(int param_1,int param_2,undefined4 *param_3,int param_4,int param_5)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_10;
  undefined4 local_c;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar6 = 0;
  if (param_2 == 0xb) {
    iVar2 = _in_control(param_1,param_3,param_4,param_5);
    return iVar2;
  }
  uVar3 = _splnet();
  if (((param_5 != 0) && (*(short *)(param_5 + 8) != 0)) || ((iVar2 == 0 && (param_2 != 0)))) {
LAB_0012b910:
    iVar6 = 0x16;
    goto LAB_0012bc05;
  }
  switch(param_2) {
  case 0:
    if (iVar2 == 0) {
      iVar6 = _in_pcballoc(param_1,&_udb);
      if (iVar6 == 0) {
        iVar6 = _soreserve(param_1,_udp_sendspace,_udp_recvspace);
      }
      break;
    }
    goto LAB_0012b910;
  case 1:
    _in_pcbdetach(iVar2);
    break;
  case 2:
    iVar6 = _in_pcbbind(iVar2,param_4);
    break;
  case 3:
  case 5:
  case 0xe:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
    iVar6 = 0x2d;
    break;
  case 4:
    if (*(int *)(iVar2 + 0xc) == 0) {
      iVar6 = _in_pcbconnect(iVar2,param_4);
      if (iVar6 == 0) {
        _soisconnected(param_1);
      }
      break;
    }
    goto LAB_0012b9de;
  case 6:
    if (*(int *)(iVar2 + 0xc) != 0) {
      _in_pcbdisconnect(iVar2);
      *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) & 0xfd;
      break;
    }
LAB_0012ba0a:
    iVar6 = 0x39;
    break;
  case 7:
    _socantsendmore(param_1);
    break;
  case 8:
  case 0xd:
    _splx(uVar3);
    return 0x2d;
  case 9:
    if (param_4 == 0) {
      if (*(int *)(iVar2 + 0xc) != 0) goto LAB_0012ba14;
      goto LAB_0012ba0a;
    }
    local_c = *(undefined4 *)(iVar2 + 0x14);
    if (*(int *)(iVar2 + 0xc) == 0) {
      iVar6 = _in_pcbconnect(iVar2,param_4);
      if (iVar6 != 0) break;
LAB_0012ba14:
      local_10 = 0;
      for (puVar5 = param_3; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
        local_10 = local_10 + *(short *)(puVar5 + 2);
      }
      uVar4 = _splimp();
      puVar5 = _mfree;
      if (_mfree == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)_m_more(0,2);
      }
      else {
        if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(&DAT_001dbf04);
        }
        *(undefined2 *)((int)_mfree + 10) = 2;
        _DAT_001e917c = _DAT_001e917c + -1;
        _DAT_001e9180 = _DAT_001e9180 + 1;
        puVar7 = (undefined4 *)*_mfree;
        *_mfree = 0;
        _mfree = puVar7;
        puVar5[1] = 0xc;
      }
      _splx(uVar4);
      if (puVar5 == (undefined4 *)0x0) {
        _m_freem(param_3);
        iVar6 = 0x37;
      }
      else {
        puVar5[1] = 0x60;
        *(undefined2 *)(puVar5 + 2) = 0x1c;
        *puVar5 = param_3;
        puVar7 = (undefined4 *)((int)puVar5 + puVar5[1]);
        puVar7[1] = 0;
        *puVar7 = 0;
        *(undefined1 *)(puVar7 + 2) = 0;
        *(undefined1 *)((int)puVar7 + 9) = 0x11;
        *(ushort *)((int)puVar7 + 10) =
             (ushort)((short)local_10 + 8U) >> 8 | ((short)local_10 + 8U) * 0x100;
        puVar7[3] = *(undefined4 *)(iVar2 + 0x14);
        puVar7[4] = *(undefined4 *)(iVar2 + 0xc);
        *(undefined2 *)(puVar7 + 5) = *(undefined2 *)(iVar2 + 0x18);
        *(undefined2 *)((int)puVar7 + 0x16) = *(undefined2 *)(iVar2 + 0x10);
        *(undefined2 *)(puVar7 + 6) = *(undefined2 *)((int)puVar7 + 10);
        *(undefined2 *)((int)puVar7 + 0x1a) = 0;
        if (_udpcksum != 0) {
          sVar1 = _in_cksum(puVar5,local_10 + 0x1c);
          *(short *)((int)puVar7 + 0x1a) = sVar1;
          if (sVar1 == 0) {
            *(undefined2 *)((int)puVar7 + 0x1a) = 0xffff;
          }
        }
        *(short *)((int)puVar7 + 2) = (short)local_10 + 0x1c;
        *(undefined1 *)(puVar7 + 2) = _udp_ttl;
        iVar6 = _ip_output(puVar5,*(undefined4 *)(iVar2 + 0x38),iVar2 + 0x24,
                           (byte)*(undefined2 *)(*(int *)(iVar2 + 0x1c) + 2) & 0x32 | 2,
                           *(undefined4 *)(iVar2 + 0x3c));
      }
      param_3 = (undefined4 *)0x0;
      if (param_4 != 0) {
        _in_pcbdisconnect(iVar2);
        *(undefined4 *)(iVar2 + 0x14) = local_c;
      }
      break;
    }
LAB_0012b9de:
    iVar6 = 0x38;
    break;
  case 10:
    _soisdisconnected(param_1);
    _in_pcbdetach(iVar2);
    break;
  default:
                    /* WARNING: Subroutine does not return */
    _panic(s_udp_usrreq_001dbf14);
  case 0xc:
    _splx(uVar3);
    return 0;
  case 0xf:
    _in_setsockaddr(iVar2,param_4);
    break;
  case 0x10:
    _in_setpeeraddr(iVar2,param_4);
  }
LAB_0012bc05:
  _splx(uVar3);
  if (param_3 != (undefined4 *)0x0) {
    _m_freem(param_3);
  }
  return iVar6;
}

