/* GHIDRADEC_FUNCTION index=725 start=0x4021144 */

byte _ip_slowtimo(void)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined4 *puVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  
  if (_ipq == (undefined4 *)0x0) {
    bVar2 = 4;
  }
  else {
    bVar6 = &_ipq < _ipq;
    bVar5 = SBORROW4(0x40b6884,(int)_ipq);
    puVar3 = (undefined4 *)((int)&_ipq - (int)_ipq);
    bVar4 = (undefined4 **)_ipq == &_ipq;
    puVar1 = _ipq;
    while (!bVar4) {
      *(char *)(puVar1 + 2) = *(char *)(puVar1 + 2) + -1;
      puVar1 = (undefined4 *)*puVar1;
      if (*(char *)(puVar1[1] + 8) == '\0') {
        unk_40B68C0 = unk_40B68C0 + 1;
        _ip_freef(puVar1[1]);
      }
      bVar6 = puVar1 < &_ipq;
      bVar5 = SBORROW4((int)puVar1,0x40b6884);
      puVar3 = puVar1 + -0x102da21;
      bVar4 = (undefined4 **)puVar1 == &_ipq;
    }
    bVar2 = bVar6 << 4 | ((int)puVar3 < 0) << 3 | bVar4 << 2 | bVar5 << 1 | bVar6;
  }
  return bVar2;
}
/* GHIDRADEC_FUNCTION index=726 start=0x40211a6 */

void _ip_drain(void)

{
  if ((undefined4 **)_ipq != &_ipq) {
    do {
      dword_40B68BC = dword_40B68BC + 1;
      _ip_freef(_ipq);
    } while ((undefined4 **)_ipq != &_ipq);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=727 start=0x40211dc */

undefined4 _ip_dooptions(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = 0xc;
  pbVar9 = param_1 + 0x14;
  iVar3 = (*param_1 & 0xf) * 4 + -0x14;
  do {
    if ((iVar3 < 1) || (bVar1 = *pbVar9, bVar1 == 0)) {
      return 0;
    }
    if (bVar1 != 1) {
      uVar10 = (uint)pbVar9[1];
      if ((uVar10 != 0) && ((int)uVar10 <= iVar3)) goto loc_402123A;
      pbVar8 = param_1 + -1;
loc_4021494:
      iVar5 = (int)pbVar9 - (int)pbVar8;
      goto loc_4021498;
    }
    uVar10 = 1;
loc_402123A:
    if (bVar1 == 0x44) {
      iVar5 = (int)pbVar9 - (int)param_1;
      if (pbVar9[1] < 5) goto loc_4021498;
      uVar6 = (uint)pbVar9[2];
      uVar7 = (uint)pbVar9[1];
      if (uVar7 - 4 < uVar6) {
        bVar1 = (pbVar9[3] >> 4) + 1;
        pbVar9[3] = pbVar9[3] & 0xf | bVar1 * '\x10';
        if ((bVar1 & 0xf) == 0) goto loc_4021498;
      }
      else {
        bVar1 = pbVar9[3] & 0xf;
        if (bVar1 == 1) {
          if (uVar7 < uVar6 + 8) goto loc_4021498;
          iVar5 = _ifptoia(param_2);
          _bcopy(iVar5 + 4,pbVar9 + (uVar6 - 1),4);
          pbVar9[2] = pbVar9[2] + 4;
        }
        else if (bVar1 < 2) {
          if ((pbVar9[3] & 0xf) != 0) goto loc_4021498;
        }
        else {
          if ((bVar1 != 2) || (uVar7 < uVar6 + 8)) goto loc_4021498;
          _bcopy(pbVar9 + (uVar6 - 1),&dword_40AEB02,4);
          iVar5 = _ifa_ifwithaddr(&_ipaddr);
          if (iVar5 == 0) goto loc_4021476;
          pbVar9[2] = pbVar9[2] + 4;
        }
        uStack_8 = _iptime();
        _bcopy(&uStack_8,pbVar9 + (pbVar9[2] - 1),4);
        pbVar9[2] = pbVar9[2] + 4;
      }
    }
    else if (bVar1 < 0x45) {
      if (bVar1 == 7) {
        if (pbVar9[2] < 4) {
loc_4021490:
          pbVar8 = param_1 + -2;
          goto loc_4021494;
        }
        uVar6 = pbVar9[2] - 1;
        if (uVar6 <= uVar10 - 4) {
          _bcopy(param_1 + 0x10,&dword_40AEB02,4);
          iVar5 = _ip_rtaddr(dword_40AEB02);
          if (iVar5 == 0) {
            uStack_c = 3;
            iVar5 = 1;
            goto loc_4021498;
          }
          _bcopy(iVar5 + 4,pbVar9 + uVar6,4);
          pbVar9[2] = pbVar9[2] + 4;
        }
      }
    }
    else if ((bVar1 == 0x83) || (bVar1 == 0x89)) {
      bVar2 = pbVar9[2];
      if (bVar2 < 4) goto loc_4021490;
      dword_40AEB02 = *(undefined4 *)(param_1 + 0x10);
      iVar5 = _ifa_ifwithaddr(&_ipaddr);
      if (iVar5 == 0) {
        if (bVar1 == 0x89) {
loc_40212F6:
          uStack_c = 3;
          iVar5 = 5;
loc_4021498:
          _icmp_error(param_1,uStack_c,iVar5,param_2,0);
          return 1;
        }
      }
      else {
        uVar6 = bVar2 - 1;
        if (uVar10 - 4 < uVar6) {
          _save_rte(pbVar9,*(undefined4 *)(param_1 + 0xc));
        }
        else {
          _bcopy(pbVar9 + uVar6,&dword_40AEB02,4);
          if (bVar1 == 0x89) {
            uVar4 = _in_netof(dword_40AEB02);
            iVar5 = _in_iaonnetof(uVar4);
            if (iVar5 == 0) goto loc_40212F6;
          }
          iVar5 = _ip_rtaddr(dword_40AEB02);
          if (iVar5 == 0) goto loc_40212F6;
          *(undefined4 *)(param_1 + 0x10) = dword_40AEB02;
          _bcopy(iVar5 + 4,pbVar9 + uVar6,4);
          pbVar9[2] = pbVar9[2] + 4;
        }
      }
    }
loc_4021476:
    iVar3 = iVar3 - uVar10;
    pbVar9 = pbVar9 + uVar10;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=728 start=0x40214b8 */

int _ip_rtaddr(int param_1)

{
  int iVar1;
  
  if (_ipforward_rt != 0) {
    if (param_1 == dword_40B7D94) goto loc_4021514;
    if (*(sword *)(_ipforward_rt + 0x26) == 1) {
      _rtfree(_ipforward_rt);
    }
    else {
      *(sword *)(_ipforward_rt + 0x26) = *(sword *)(_ipforward_rt + 0x26) + -1;
    }
    _ipforward_rt = 0;
  }
  unk_40B7D90._0_2_ = 2;
  dword_40B7D94 = param_1;
  _rtalloc(&_ipforward_rt);
loc_4021514:
  if ((_ipforward_rt != 0) && (_in_ifaddr != 0)) {
    iVar1 = _in_ifaddr;
    do {
      if (*(int *)(_ipforward_rt + 0x2c) == *(int *)(iVar1 + 0x20)) {
        return iVar1;
      }
      iVar1 = *(int *)(iVar1 + 0x40);
    } while (iVar1 != 0);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=729 start=0x4021550 */

void _save_rte(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 1);
  if (uVar1 < 0xa4) {
    _bcopy(param_1,&unk_40B3485,uVar1);
    _ip_nhops = uVar1 - 3 >> 2;
    *(undefined4 *)(unk_40B3488 + _ip_nhops * 4) = param_2;
    _ip_nhops = _ip_nhops + 1;
  }
  else if (_ipprintfs != 0) {
    _printf(aSaveRteOlenD,uVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=730 start=0x40215b6 */

int _ip_srcroute(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if ((_ip_nhops == 0) || (iVar4 = _m_get(0,10), iVar3 = _ip_nhops, iVar4 == 0)) {
    iVar4 = 0;
  }
  else {
    iVar1 = _ip_nhops * 4;
    *(sword *)(iVar4 + 8) = (sword)iVar1 + 4;
    *(undefined4 *)(iVar4 + *(int *)(iVar4 + 4)) = *(undefined4 *)(&unk_40B3484 + iVar1);
    puVar5 = &DAT_40b3480 + iVar3;
    unk_40B3484 = 1;
    _bcopy(&unk_40B3484,*(int *)(iVar4 + 4) + iVar4 + 4,4);
    puVar2 = (undefined4 *)(*(int *)(iVar4 + 4) + iVar4 + 8);
    for (; &DAT_40b3487 < puVar5; puVar5 = puVar5 + -1) {
      *puVar2 = *puVar5;
      puVar2 = puVar2 + 1;
    }
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=731 start=0x4021646 */

void _ip_stripoptions(byte *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (*param_1 & 0xf) * 4 + -0x14;
  uVar3 = (uint)param_1 & 0xffffff80;
  pbVar1 = param_1 + 0x14;
  if (param_2 != 0) {
    *(sword *)(param_2 + 8) = (sword)iVar2;
    *(undefined4 *)(param_2 + 4) = 0xc;
    _bcopy(pbVar1,param_2 + 0xc,iVar2);
  }
  _bcopy(pbVar1 + iVar2,pbVar1,(*(sword *)(uVar3 + 8) + -0x14) - iVar2);
  *(sword *)(uVar3 + 8) = *(sword *)(uVar3 + 8) - (sword)iVar2;
  *param_1 = *param_1 & 0xf5 | 5;
  return;
}
/* GHIDRADEC_FUNCTION index=732 start=0x40216c8 */

void _ip_forward(byte *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_D3;
  int iVar5;
  undefined4 uVar6;
  undefined4 uStack_8;
  
  iVar5 = 0;
  uStack_8 = 0;
  if (_ipprintfs != 0) {
    _printf(aForwardSrcXDst,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),
            param_1[8]);
  }
  if ((_ipforwarding == 0) || (_in_interfaces < 2)) {
    dword_40B68C8 = dword_40B68C8 + 1;
loc_4021730:
    _m_freem((uint)param_1 & 0xffffff80);
    return;
  }
  iVar3 = _in_canforward(*(undefined4 *)(param_1 + 0x10));
  if (iVar3 == 0) goto loc_4021730;
  if (param_1[8] < 2) {
    uVar6 = 0xb;
    unaff_D3 = 0;
    goto loc_4021A5E;
  }
  param_1[8] = param_1[8] - 1;
  uVar6 = _imin((int)*(sword *)(param_1 + 2),0x40);
  iVar3 = _m_copy((uint)param_1 & 0xffffff80,0,uVar6);
  if (_ipforward_rt == 0) {
loc_40217C6:
    unk_40B7D90._0_2_ = 2;
    dword_40B7D94 = *(int *)(param_1 + 0x10);
    _rtalloc(&_ipforward_rt);
  }
  else if (*(int *)(param_1 + 0x10) != dword_40B7D94) {
    if (_ipforward_rt != 0) {
      if (*(sword *)(_ipforward_rt + 0x26) == 1) {
        _rtfree(_ipforward_rt);
      }
      else {
        *(sword *)(_ipforward_rt + 0x26) = *(sword *)(_ipforward_rt + 0x26) + -1;
      }
      _ipforward_rt = 0;
    }
    goto loc_40217C6;
  }
  if (((((_ipforward_rt != 0) && (param_2 == *(int *)(_ipforward_rt + 0x2c))) &&
       ((*(word *)(_ipforward_rt + 0x24) & 0x30) == 0)) &&
      ((*(int *)(_ipforward_rt + 8) != 0 && (_ipsendredirects != 0)))) && ((*param_1 & 0xf) == 5)) {
    uVar1 = *(uint *)(param_1 + 0xc);
    uVar2 = *(uint *)(param_1 + 0x10);
    iVar4 = _ifptoia(param_2);
    if ((iVar4 != 0) && ((*(uint *)(iVar4 + 0x34) & uVar1) == *(uint *)(iVar4 + 0x30))) {
      if ((*(byte *)(_ipforward_rt + 0x25) & 2) == 0) {
        uStack_8 = *(undefined4 *)(param_1 + 0x10);
      }
      else {
        uStack_8 = *(undefined4 *)(_ipforward_rt + 0x18);
      }
      iVar5 = 5;
      unaff_D3 = 0;
      iVar4 = _in_ifaddr;
      if ((*(word *)(_ipforward_rt + 0x24) & 6) == 2) {
        do {
          iVar4 = *(int *)(iVar4 + 0x40);
          if (iVar4 == 0) goto loc_40218A4;
        } while ((*(uint *)(iVar4 + 0x2c) & uVar2) != *(uint *)(iVar4 + 0x28));
        if (*(uint *)(iVar4 + 0x2c) != *(uint *)(iVar4 + 0x34)) goto loc_4021898;
      }
      else {
loc_4021898:
        unaff_D3 = 1;
      }
loc_40218A4:
      if (_ipprintfs != 0) {
        _printf(aRedirectDToX,unaff_D3,uStack_8);
      }
    }
  }
  iVar4 = _ip_output((uint)param_1 & 0xffffff80,0,&_ipforward_rt,1);
  if (iVar4 == 0) {
    if (iVar5 == 0) {
      if (iVar3 != 0) {
        _m_freem(iVar3);
      }
      dword_40B68C4 = dword_40B68C4 + 1;
      return;
    }
    dword_40B68CC = dword_40B68CC + 1;
  }
  else {
    dword_40B68C8 = dword_40B68C8 + 1;
  }
  if (iVar3 == 0) {
    return;
  }
  param_1 = (byte *)(*(int *)(iVar3 + 4) + iVar3);
  uVar6 = 3;
  switch(iVar4) {
  case :
    uVar6 = 5;
    break;
  case :
    unaff_D3 = 3;
    break;
  case :
    unaff_D3 = 4;
    break;
  case :
  case :
    iVar5 = _in_localaddr(*(undefined4 *)(param_1 + 0x10));
    unaff_D3 = 0;
    if (iVar5 == 0) break;
  case :
  case :
    unaff_D3 = 1;
    break;
  case :
    uVar6 = 4;
  }
loc_4021A5E:
  _icmp_error(param_1,uVar6,unaff_D3,param_2,&uStack_8);
  return;
}
/* GHIDRADEC_FUNCTION index=733 start=0x4021a7a */

int _ip_output(int param_1,int param_2,int *param_3,byte param_4,int param_5)

{
  word wVar1;
  undefined4 uVar2;
  undefined2 uVar4;
  int iVar3;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  int *piVar13;
  int iVar14;
  int iStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  uint uStack_1c;
  int aiStack_18 [5];
  
  iVar10 = 0;
  iStack_34 = param_1;
  iVar5 = 0;
  uVar7 = 0x14;
  if (param_2 != 0) {
    iStack_34 = _ip_insertoptions(param_1,param_2,&uStack_30);
    uVar7 = uStack_30;
  }
  puVar12 = (uint *)(*(int *)(iStack_34 + 4) + iStack_34);
  if ((param_4 & 1) == 0) {
    *(byte *)puVar12 = *(byte *)puVar12 & 0x4f | 0x40;
    *(word *)((int)puVar12 + 6) = *(word *)((int)puVar12 + 6) & 0x4000;
    *(sword *)(puVar12 + 1) = _ip_id;
    _ip_id = _ip_id + 1;
    *puVar12 = *puVar12 & 0xf0ffffff | ((uVar7 & 0x3f) >> 2) << 0x18;
  }
  else {
    uVar7 = (*(byte *)puVar12 & 0xf) << 2;
  }
  if (param_3 == (int *)0x0) {
    param_3 = aiStack_18;
    _bzero(param_3,0x14);
  }
  piVar8 = param_3 + 1;
  iVar3 = *param_3;
  if (iVar3 == 0) {
loc_4021B5E:
    *(undefined2 *)piVar8 = 2;
    param_3[2] = puVar12[4];
  }
  else {
    if (((*(byte *)(iVar3 + 0x25) & 1) == 0) || (param_3[2] != puVar12[4])) {
      if (*(sword *)(iVar3 + 0x26) == 1) {
        _rtfree(iVar3);
      }
      else {
        *(sword *)(iVar3 + 0x26) = *(sword *)(iVar3 + 0x26) + -1;
      }
      *param_3 = 0;
    }
    if (*param_3 == 0) goto loc_4021B5E;
  }
  iVar3 = param_1;
  if ((param_4 & 0x10) == 0) {
    if ((*param_3 != 0) || (_rtalloc(param_3), *param_3 != 0)) {
      iVar14 = *(int *)(*param_3 + 0x2c);
      if (iVar14 == 0) goto loc_4021BCA;
      piVar13 = (int *)(*param_3 + 0x28);
      *piVar13 = *piVar13 + 1;
      if ((*(byte *)(*param_3 + 0x25) & 2) != 0) {
        piVar8 = (int *)(*param_3 + 0x14);
      }
      goto loc_4021BF8;
    }
loc_4021BCA:
    iVar10 = _in_localaddr(puVar12[4]);
    iVar5 = 0x33;
    if (iVar10 != 0) {
      iVar5 = 0x41;
    }
    goto loc_4021F5C;
  }
  iVar10 = _ifa_ifwithdstaddr(piVar8);
  if (iVar10 == 0) {
    uVar2 = _in_netof(puVar12[4]);
    iVar10 = _in_iaonnetof(uVar2);
    if (iVar10 == 0) {
      iVar5 = 0x33;
      goto loc_4021F5C;
    }
  }
  iVar14 = *(int *)(iVar10 + 0x20);
loc_4021BF8:
  if ((puVar12[4] & 0xf0000000) == 0xe0000000) {
    piVar8 = param_3 + 1;
    if (((param_4 & 2) == 0) || (param_5 == 0)) {
      piVar13 = (int *)0x0;
      *(byte *)(puVar12 + 2) = 1;
    }
    else {
      piVar13 = (int *)(*(int *)(param_5 + 4) + param_5);
      *(byte *)(puVar12 + 2) = *(byte *)(piVar13 + 1);
      if (*piVar13 != 0) {
        iVar14 = *piVar13;
      }
    }
    iVar3 = iStack_34;
    if (puVar12[3] == 0) {
      iVar10 = _in_ifaddr;
      if (_in_ifaddr != 0) {
        do {
          if (iVar14 == *(int *)(iVar10 + 0x20)) {
            puVar12[3] = *(uint *)(iVar10 + 4);
            break;
          }
          iVar10 = *(int *)(iVar10 + 0x40);
        } while (iVar10 != 0);
        goto loc_4021C5C;
      }
loc_4021C9A:
      if (((_ip_mrouter == 0) || ((param_4 & 1) != 0)) ||
         (iVar10 = _ip_mforward(puVar12,iVar14), iVar10 == 0)) goto loc_4021CC2;
    }
    else {
loc_4021C5C:
      if ((iVar10 == 0) || (puVar9 = *(uint **)(iVar10 + 0x44), puVar9 == (uint *)0x0))
      goto loc_4021C9A;
      do {
        if (puVar12[4] == *puVar9) break;
        puVar9 = (uint *)puVar9[5];
      } while (puVar9 != (uint *)0x0);
      if ((puVar9 == (uint *)0x0) ||
         ((piVar13 != (int *)0x0 && (*(char *)((int)piVar13 + 5) == '\0')))) goto loc_4021C9A;
      _ip_mloopback(iVar14,iStack_34,piVar8);
loc_4021CC2:
      if ((*(byte *)(puVar12 + 2) != 0) && (iVar14 != _loifp)) goto loc_4021D3C;
    }
loc_4021F5C:
    _m_freem(iVar3);
  }
  else {
    iVar10 = _in_ifaddr;
    if (puVar12[3] == 0) {
      for (; iVar10 != 0; iVar10 = *(int *)(iVar10 + 0x40)) {
        if (iVar14 == *(int *)(iVar10 + 0x20)) {
          puVar12[3] = *(uint *)(iVar10 + 4);
          break;
        }
      }
    }
    iVar10 = _in_broadcast(piVar8[1]);
    if (iVar10 == 0) {
loc_4021D3C:
      if (*(sword *)(iVar14 + 10) < (sword)*puVar12) {
        if (((*(byte *)((int)puVar12 + 6) & 0x40) == 0) &&
           (uStack_30 = (int)*(sword *)(iVar14 + 10) - uVar7 & 0xfffffff8, 7 < (int)uStack_30)) {
          iVar10 = (**(code **)(iVar14 + 0x3e))(iVar14);
          if (iVar10 == 0) {
loc_4021F9A:
            iVar5 = 0x37;
            iVar3 = param_1;
          }
          else {
            iVar5 = _nb_map(iVar10);
            _mbuf_read(iStack_34,iVar5,0,uStack_30 + uVar7);
            uStack_20 = puVar12[3];
            uStack_1c = puVar12[4];
            uStack_2c._0_2_ = (undefined2)(*puVar12 >> 0x10);
            uStack_2c = CONCAT22(uStack_2c._0_2_,uStack_30._2_2_ + (sword)uVar7);
            uStack_28._0_2_ = (undefined2)(puVar12[1] >> 0x10);
            uStack_28 = CONCAT22(uStack_28._0_2_,*(undefined2 *)((int)puVar12 + 6)) | 0x2000;
            uStack_24 = puVar12[2] & 0xffff0000;
            _bcopy(&uStack_2c,iVar5,0x14);
            uVar4 = _in_cksum(iVar10,uVar7);
            uStack_24 = CONCAT22(uStack_24._0_2_,uVar4);
            uVar2 = uStack_24;
            uStack_24._2_1_ = (undefined)((word)uVar4 >> 8);
            *(undefined *)(iVar5 + 10) = uStack_24._2_1_;
            uStack_24._3_1_ = (undefined)uVar4;
            *(undefined *)(iVar5 + 0xb) = (undefined)uStack_24;
            uStack_24 = uVar2;
            iVar5 = (**(code **)(iVar14 + 0x32))(iVar14,iVar10,piVar8);
            iVar3 = param_1;
            if (iVar5 == 0) {
              uVar6 = 0x14;
              uVar11 = uVar7;
              do {
                uVar11 = uStack_30 + uVar11;
                iVar3 = param_1;
                if ((int)(sword)*puVar12 <= (int)uVar11) break;
                iVar10 = (**(code **)(iVar14 + 0x3e))(iVar14);
                if (iVar10 == 0) goto loc_4021F9A;
                iVar5 = _nb_map(iVar10);
                uStack_2c = *puVar12;
                uStack_28 = puVar12[1];
                uStack_24 = puVar12[2];
                uStack_20 = puVar12[3];
                uStack_1c = puVar12[4];
                if (0x14 < uVar7) {
                  iVar3 = _ip_optcopy(puVar12,iVar5);
                  uVar6 = iVar3 + 0x14;
                  uStack_2c = uStack_2c & 0xf0ffffff | ((uVar6 & 0x3f) >> 2) << 0x18;
                }
                wVar1 = (sword)((int)(uVar11 - uVar7) >> 3) + (*(word *)((int)puVar12 + 6) & 0xdfff)
                ;
                if ((*(byte *)((int)puVar12 + 6) & 0x20) != 0) {
                  wVar1 = wVar1 | 0x2000;
                }
                uStack_28 = CONCAT22(uStack_28._0_2_,wVar1);
                if ((int)(uStack_30 + uVar11) < (int)(sword)*puVar12) {
                  uStack_28 = CONCAT22(uStack_28._0_2_,wVar1) | 0x2000;
                }
                else {
                  _nb_shrink_bot(iVar10,(uStack_30 + uVar11) - (int)(sword)*puVar12);
                  uStack_30 = (int)(sword)*puVar12 - uVar11;
                }
                uStack_2c = CONCAT22(uStack_2c._0_2_,(sword)uVar6 + (sword)uStack_30);
                _mbuf_read(iStack_34,iVar5 + uVar6,uVar11,uStack_30);
                uStack_24 = uStack_24 & 0xffff0000;
                _bcopy(&uStack_2c,iVar5,0x14);
                uVar4 = _in_cksum(iVar10,uVar6);
                uStack_24 = CONCAT22(uStack_24._0_2_,uVar4);
                uVar2 = uStack_24;
                uStack_24._2_1_ = (undefined)((word)uVar4 >> 8);
                *(undefined *)(iVar5 + 10) = uStack_24._2_1_;
                uStack_24._3_1_ = (undefined)uVar4;
                *(undefined *)(iVar5 + 0xb) = (undefined)uStack_24;
                uStack_24 = uVar2;
                iVar5 = (**(code **)(iVar14 + 0x32))(iVar14,iVar10,piVar8);
                iVar3 = param_1;
              } while (iVar5 == 0);
            }
          }
        }
        else {
loc_4021D36:
          iVar5 = 0x28;
          iVar3 = param_1;
        }
        goto loc_4021F5C;
      }
    }
    else {
      if ((*(byte *)(iVar14 + 0xd) & 2) == 0) {
        iVar5 = 0x31;
        goto loc_4021F5C;
      }
      if ((param_4 & 0x20) == 0) {
        iVar5 = 0xd;
        goto loc_4021F5C;
      }
      if (*(sword *)(iVar14 + 10) < (sword)*puVar12) goto loc_4021D36;
    }
    ((byte *)((int)puVar12 + 10))[0] = 0;
    ((byte *)((int)puVar12 + 10))[1] = 0;
    uVar4 = _in_cksum(iStack_34,uVar7);
    *(undefined2 *)((int)puVar12 + 10) = uVar4;
    iVar5 = _if_output_mbuf(iVar14,iStack_34,piVar8);
  }
  if (((aiStack_18 == param_3) && ((param_4 & 0x10) == 0)) && (iVar10 = *param_3, iVar10 != 0)) {
    if (*(sword *)(iVar10 + 0x26) == 1) {
      _rtfree(iVar10);
    }
    else {
      *(sword *)(iVar10 + 0x26) = *(sword *)(iVar10 + 0x26) + -1;
    }
  }
  return iVar5;
}
/* GHIDRADEC_FUNCTION index=734 start=0x4021fa8 */

undefined4 * _ip_insertoptions(undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  sword *psVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  sword sVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  piVar10 = (int *)(*(int *)(param_2 + 4) + param_2);
  iVar9 = param_1[1] + (int)param_1;
  iVar8 = (int)*(sword *)(param_2 + 8);
  iVar4 = iVar8 + -4;
  iVar1 = *piVar10;
  if (iVar1 != 0) {
    *(int *)(iVar9 + 0x10) = iVar1;
  }
  puVar6 = _mfree;
  uVar2 = param_1[1];
  sVar7 = (sword)iVar4;
  if ((uVar2 < 0x7c) && (iVar8 + 8U <= uVar2)) {
    param_1[1] = uVar2 - iVar4;
    *(sword *)(param_1 + 2) = sVar7 + *(sword *)(param_1 + 2);
    _ovbcopy(iVar9,param_1[1] + (int)param_1,0x14);
  }
  else {
    if (_mfree == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)_m_more(0,2);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)((int)_mfree + 10) = 2;
      word_40B61CC = word_40B61CC + -1;
      word_40B61D0 = word_40B61D0 + 1;
      puVar5 = (undefined4 *)*_mfree;
      *_mfree = 0;
      _mfree = puVar5;
      puVar6[1] = 0xc;
    }
    if (puVar6 == (undefined4 *)0x0) {
      return param_1;
    }
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) + -0x14;
    param_1[1] = param_1[1] + 0x14;
    *puVar6 = param_1;
    puVar6[1] = 0x68 - iVar4;
    *(sword *)(puVar6 + 2) = sVar7 + 0x14;
    _bcopy(iVar9,puVar6[1] + (int)puVar6,0x14);
    param_1 = puVar6;
  }
  iVar1 = param_1[1];
  _bcopy(piVar10 + 1,(int)param_1 + iVar1 + 0x14,iVar4);
  *param_3 = iVar8 + 0x10;
  psVar3 = (sword *)((int)param_1 + iVar1 + 2);
  *psVar3 = sVar7 + *psVar3;
  return param_1;
}
/* GHIDRADEC_FUNCTION index=735 start=0x40220d4 */

undefined * _ip_optcopy(byte *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  undefined *puVar5;
  
  puVar5 = (undefined *)(param_2 + 0x14);
  uVar2 = (*param_1 & 0xf) * 4 - 0x14;
  for (param_1 = param_1 + 0x14; (0 < (int)uVar2 && (bVar1 = *param_1, bVar1 != 0));
      param_1 = param_1 + uVar4) {
    if (bVar1 == 1) {
      uVar4 = 1;
    }
    else {
      uVar4 = (uint)param_1[1];
    }
    if ((int)uVar2 < (int)uVar4) {
      uVar4 = uVar2;
    }
    if ((char)bVar1 < '\0') {
      _bcopy(param_1,puVar5,uVar4);
      puVar5 = puVar5 + uVar4;
    }
    uVar2 = uVar2 - uVar4;
  }
  puVar3 = puVar5 + (-0x14 - param_2);
  for (; ((uint)puVar3 & 3) != 0; puVar3 = puVar3 + 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  return puVar3;
}
/* GHIDRADEC_FUNCTION index=736 start=0x402215c */

undefined4 _ip_ctloutput(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = *(int *)(param_2 + 8);
  if (param_3 == 0) {
    if (param_1 == 0) {
      if (param_4 == 1) {
        iVar2 = _m_get(1,10);
        *param_5 = iVar2;
        if (*(int *)(iVar1 + 0x34) == 0) {
          *(undefined2 *)(iVar2 + 8) = 0;
        }
        else {
          *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(*(int *)(iVar1 + 0x34) + 4);
          *(undefined2 *)(*param_5 + 8) = *(undefined2 *)(*(int *)(iVar1 + 0x34) + 8);
          iVar2 = *param_5;
          _bcopy(*(int *)(*(int *)(iVar1 + 0x34) + 4) + *(int *)(iVar1 + 0x34),
                 *(int *)(iVar2 + 4) + iVar2,(int)*(sword *)(iVar2 + 8));
        }
        goto loc_4022250;
      }
      if (((0 < param_4) && (param_4 < 8)) && (2 < param_4)) {
        uVar3 = _ip_getmoptions(param_4,*(undefined4 *)(iVar1 + 0x38),param_5);
        goto loc_4022250;
      }
    }
    else {
      if (param_1 != 1) {
        return 0;
      }
      if (param_4 == 1) {
        uVar3 = _ip_pcbopts(iVar1 + 0x34,*param_5);
        return uVar3;
      }
      if (((0 < param_4) && (param_4 < 8)) && (2 < param_4)) {
        uVar3 = _ip_setmoptions(param_4,iVar1 + 0x38,*param_5);
        goto loc_4022250;
      }
    }
  }
  uVar3 = 0x16;
loc_4022250:
  if ((param_1 == 1) && (*param_5 != 0)) {
    _m_free(*param_5);
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=737 start=0x402226e */

undefined4 _ip_pcbopts(int *param_1,int param_2)

{
  sword sVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  
  if (*param_1 != 0) {
    _m_free(*param_1);
  }
  *param_1 = 0;
  if (param_2 != 0) {
    sVar1 = *(sword *)(param_2 + 8);
    if (sVar1 == 0) {
      _m_free(param_2);
    }
    else {
      uVar3 = (uint)sVar1;
      if (((uVar3 & 3) != 0) || (0x7c < uVar3 + *(int *)(param_2 + 4) + 4)) {
loc_402237E:
        _m_free(param_2);
        return 0x16;
      }
      *(sword *)(param_2 + 8) = sVar1 + 4;
      iVar5 = *(int *)(param_2 + 4) + param_2;
      pcVar6 = (char *)(iVar5 + 4);
      _ovbcopy(iVar5,pcVar6,uVar3);
      _bzero(*(int *)(param_2 + 4) + param_2,4);
      for (; (0 < (int)uVar3 && (cVar2 = *pcVar6, cVar2 != '\0')); pcVar6 = pcVar6 + uVar4) {
        if (cVar2 == '\x01') {
          uVar4 = 1;
        }
        else {
          uVar4 = (uint)(byte)pcVar6[1];
          if ((uVar4 < 2) || ((int)uVar3 < (int)uVar4)) goto loc_402237E;
        }
        if ((cVar2 == -0x7d) || (uVar7 = uVar3, cVar2 == -0x77)) {
          if (uVar4 < 7) goto loc_402237E;
          *(sword *)(param_2 + 8) = *(sword *)(param_2 + 8) + -4;
          uVar7 = uVar3 - 4;
          uVar4 = uVar4 - 4;
          pcVar6[1] = (char)uVar4;
          _bcopy(pcVar6 + 3,*(int *)(param_2 + 4) + param_2,4);
          _ovbcopy(pcVar6 + 7,pcVar6 + 3,uVar3);
        }
        uVar3 = uVar7 - uVar4;
      }
      *param_1 = param_2;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=738 start=0x4022392 */

undefined4 _ip_setmoptions(undefined4 param_1,int *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint *puVar8;
  int iStack_18;
  undefined2 uStack_14;
  uint uStack_10;
  
  iVar2 = _mfree;
  uVar4 = 0;
  if (*param_2 == 0) {
    *param_2 = _mfree;
    if (iVar2 == 0) {
      iVar2 = _m_more(1,0xe);
      *param_2 = iVar2;
    }
    else {
      if (*(sword *)(iVar2 + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)(*param_2 + 10) = 0xe;
      word_40B61CC = word_40B61CC + -1;
      word_40B61E8 = word_40B61E8 + 1;
      _mfree = *(int *)*param_2;
      *(undefined4 *)*param_2 = 0;
      *(undefined4 *)(*param_2 + 4) = 0xc;
    }
    iVar2 = *param_2;
    if (iVar2 == 0) {
      return 0x37;
    }
    puVar6 = (undefined4 *)(*(int *)(iVar2 + 4) + iVar2);
    *puVar6 = 0;
    *(undefined *)(puVar6 + 1) = 1;
    *(undefined *)((int)puVar6 + 5) = 1;
    *(undefined2 *)((int)puVar6 + 6) = 0;
  }
  piVar7 = (int *)(*(int *)(*param_2 + 4) + *param_2);
  switch(param_1) {
  case :
    if ((param_3 != 0) && (*(sword *)(param_3 + 8) == 4)) {
      iVar2 = *(int *)(param_3 + *(int *)(param_3 + 4));
      iVar3 = _in_ifaddr;
      if (iVar2 == 0) {
        *piVar7 = 0;
        goto loc_40226AE;
      }
      for (; (iVar3 != 0 && (iVar2 != *(int *)(iVar3 + 4))); iVar3 = *(int *)(iVar3 + 0x40)) {
      }
      iVar2 = 0;
      if (iVar3 != 0) {
        iVar2 = *(int *)(iVar3 + 0x20);
      }
      if (iVar2 != 0) {
        *piVar7 = iVar2;
        goto loc_40226AE;
      }
loc_4022678:
      uVar4 = 0x31;
      goto loc_40226AE;
    }
    break;
  case :
    if ((param_3 != 0) && (*(sword *)(param_3 + 8) == 1)) {
      *(undefined *)(piVar7 + 1) = *(undefined *)(param_3 + *(int *)(param_3 + 4));
      goto loc_40226AE;
    }
    break;
  case :
    if (((param_3 != 0) && (*(sword *)(param_3 + 8) == 1)) &&
       (bVar1 = *(byte *)(param_3 + *(int *)(param_3 + 4)), bVar1 < 2)) {
      *(byte *)((int)piVar7 + 5) = bVar1;
      goto loc_40226AE;
    }
    break;
  case :
    if (((param_3 != 0) && (*(sword *)(param_3 + 8) == 8)) &&
       (puVar8 = (uint *)(*(int *)(param_3 + 4) + param_3), (*puVar8 & 0xf0000000) == 0xe0000000)) {
      iVar2 = _in_ifaddr;
      if (puVar8[1] == 0) {
        iStack_18 = 0;
        uStack_14 = 2;
        uStack_10 = *puVar8;
        _rtalloc(&iStack_18);
        if (iStack_18 == 0) goto loc_4022678;
        uVar5 = *(uint *)(iStack_18 + 0x2c);
        _rtfree(iStack_18);
      }
      else {
        for (; (iVar2 != 0 && (puVar8[1] != *(uint *)(iVar2 + 4))); iVar2 = *(int *)(iVar2 + 0x40))
        {
        }
        uVar5 = 0;
        if (iVar2 != 0) {
          uVar5 = *(uint *)(iVar2 + 0x20);
        }
      }
      if (uVar5 != 0) {
        iVar2 = 0;
        if (*(word *)((int)piVar7 + 6) != 0) {
          do {
            if ((uVar5 == ((uint *)piVar7[iVar2 + 2])[1]) && (*(uint *)piVar7[iVar2 + 2] == *puVar8)
               ) break;
            iVar2 = iVar2 + 1;
          } while (iVar2 < (int)(uint)*(word *)((int)piVar7 + 6));
          if (iVar2 < (int)(uint)*(word *)((int)piVar7 + 6)) {
            uVar4 = 0x30;
            goto loc_40226AE;
          }
        }
        if (iVar2 == 0x14) {
          uVar4 = 0x3b;
        }
        else {
          iVar3 = _in_addmulti(*puVar8,uVar5);
          piVar7[iVar2 + 2] = iVar3;
          if (iVar3 == 0) {
            uVar4 = 0x37;
          }
          else {
            *(sword *)((int)piVar7 + 6) = *(sword *)((int)piVar7 + 6) + 1;
          }
        }
        goto loc_40226AE;
      }
      goto loc_4022678;
    }
    break;
  case :
    if (((param_3 != 0) && (*(sword *)(param_3 + 8) == 8)) &&
       (puVar8 = (uint *)(*(int *)(param_3 + 4) + param_3), (*puVar8 & 0xf0000000) == 0xe0000000)) {
      iVar2 = _in_ifaddr;
      if (puVar8[1] == 0) {
        iVar3 = 0;
      }
      else {
        for (; (iVar2 != 0 && (puVar8[1] != *(uint *)(iVar2 + 4))); iVar2 = *(int *)(iVar2 + 0x40))
        {
        }
        iVar3 = 0;
        if (iVar2 != 0) {
          iVar3 = *(int *)(iVar2 + 0x20);
        }
        if (iVar3 == 0) goto loc_4022678;
      }
      uVar5 = 0;
      if (*(word *)((int)piVar7 + 6) != 0) {
        do {
          if (((iVar3 == 0) || (iVar3 == *(int *)(piVar7[uVar5 + 2] + 4))) &&
             (*(uint *)piVar7[uVar5 + 2] == *puVar8)) break;
          uVar5 = uVar5 + 1;
        } while ((int)uVar5 < (int)(uint)*(word *)((int)piVar7 + 6));
      }
      if (*(word *)((int)piVar7 + 6) != uVar5) {
        _in_delmulti(piVar7[uVar5 + 2]);
        iVar2 = uVar5 + 1;
        if (iVar2 < (int)(uint)*(word *)((int)piVar7 + 6)) {
          do {
            piVar7[iVar2 + 1] = piVar7[iVar2 + 2];
            iVar2 = iVar2 + 1;
          } while (iVar2 < (int)(uint)*(word *)((int)piVar7 + 6));
        }
        *(sword *)((int)piVar7 + 6) = *(sword *)((int)piVar7 + 6) + -1;
        goto loc_40226AE;
      }
      goto loc_4022678;
    }
    break;
  :
    uVar4 = 0x2d;
    goto loc_40226AE;
  }
  uVar4 = 0x16;
loc_40226AE:
  if ((*piVar7 == 0) && (piVar7[1] == 0x1010000)) {
    _m_free(*param_2);
    *param_2 = 0;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=739 start=0x40226d2 */

undefined4 _ip_getmoptions(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  
  iVar1 = _m_get(1,0xe);
  *param_3 = iVar1;
  if (param_2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(*(int *)(param_2 + 4) + param_2);
  }
  if (param_1 == 4) {
    iVar1 = *param_3;
    puVar5 = (undefined *)(*(int *)(iVar1 + 4) + iVar1);
    *(undefined2 *)(iVar1 + 8) = 1;
    if (piVar3 == (int *)0x0) {
loc_4022788:
      *puVar5 = 1;
    }
    else {
      *puVar5 = *(undefined *)(piVar3 + 1);
    }
loc_402278C:
    uVar2 = 0;
  }
  else {
    if (param_1 < 5) {
      if (param_1 == 3) {
        iVar1 = *param_3;
        puVar4 = (undefined4 *)(*(int *)(iVar1 + 4) + iVar1);
        *(undefined2 *)(iVar1 + 8) = 4;
        if (((piVar3 != (int *)0x0) && (*piVar3 != 0)) && (iVar1 = _in_ifaddr, _in_ifaddr != 0)) {
          do {
            if (*piVar3 == *(int *)(iVar1 + 0x20)) break;
            iVar1 = *(int *)(iVar1 + 0x40);
          } while (iVar1 != 0);
          if (iVar1 != 0) {
            *puVar4 = *(undefined4 *)(iVar1 + 4);
            goto loc_402278C;
          }
        }
        *puVar4 = 0;
        goto loc_402278C;
      }
    }
    else if (param_1 == 5) {
      iVar1 = *param_3;
      puVar5 = (undefined *)(*(int *)(iVar1 + 4) + iVar1);
      *(undefined2 *)(iVar1 + 8) = 1;
      if (piVar3 == (int *)0x0) goto loc_4022788;
      *puVar5 = *(undefined *)((int)piVar3 + 5);
      goto loc_402278C;
    }
    uVar2 = 0x2d;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=740 start=0x402279c */

void _ip_freemoptions(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 4) + param_1;
    iVar1 = 0;
    if (*(sword *)(iVar2 + 6) != 0) {
      do {
        _in_delmulti(*(undefined4 *)(iVar2 + 8 + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)(uint)*(word *)(iVar2 + 6));
    }
    _m_free(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=741 start=0x40227e4 */

void _ip_mloopback(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 uVar2;
  byte *pbVar3;
  
  iVar1 = _m_copy(param_2,0,1000000000);
  if (iVar1 != 0) {
    pbVar3 = (byte *)(*(int *)(iVar1 + 4) + iVar1);
    pbVar3[10] = 0;
    pbVar3[0xb] = 0;
    uVar2 = _in_cksum(iVar1,(*pbVar3 & 0xf) << 2);
    *(undefined2 *)(pbVar3 + 10) = uVar2;
    _looutput(param_1,iVar1,param_3);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=742 start=0x4022844 */

void _rip_input(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + param_1;
  unk_40AEB52 = (word)*(byte *)(iVar1 + 9);
  unk_40AEB34._0_4_ = *(undefined4 *)(iVar1 + 0x10);
  unk_40AEB44._0_4_ = *(undefined4 *)(iVar1 + 0xc);
  _raw_input(param_1,&_ripproto,&_ripsrc,&_ripdst);
  return;
}
/* GHIDRADEC_FUNCTION index=743 start=0x4022896 */

undefined4 _rip_output(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  sword sVar5;
  undefined4 uVar6;
  
  sVar5 = 0;
  iVar1 = *(int *)(param_2 + 8);
  if ((*(sword *)(iVar1 + 0x2e) == 0xff) || (puVar3 = param_1, *(sword *)(iVar1 + 0x2e) == 2)) {
    iVar4 = *(int *)((int)param_1 + param_1[1] + 0xc);
    iVar2 = _in_ifaddr;
    if (iVar4 != 0) {
      for (; (iVar2 != 0 && (iVar4 != *(int *)(iVar2 + 4))); iVar2 = *(int *)(iVar2 + 0x40)) {
      }
      iVar4 = 0;
      if (iVar2 != 0) {
        iVar4 = *(int *)(iVar2 + 0x20);
      }
      if (iVar4 == 0) {
        uVar6 = 0x31;
        goto loc_40229AC;
      }
    }
    *(undefined4 *)((int)param_1 + param_1[1] + 0x10) = *(undefined4 *)(iVar1 + 0x10);
  }
  else {
    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
      sVar5 = *(sword *)(puVar3 + 2) + sVar5;
    }
    puVar3 = (undefined4 *)_m_get(0,2);
    if (puVar3 == (undefined4 *)0x0) {
      uVar6 = 0x37;
loc_40229AC:
      _m_freem(param_1);
      return uVar6;
    }
    puVar3[1] = 0x68;
    *(undefined2 *)(puVar3 + 2) = 0x14;
    *puVar3 = param_1;
    iVar4 = puVar3[1];
    *(undefined *)((int)puVar3 + iVar4 + 1) = 0;
    *(undefined2 *)((int)puVar3 + iVar4 + 6) = 0;
    *(undefined *)((int)puVar3 + iVar4 + 9) = *(undefined *)(iVar1 + 0x2f);
    *(sword *)((int)puVar3 + iVar4 + 2) = sVar5 + 0x14;
    param_1 = puVar3;
    if ((*(byte *)(iVar1 + 0x4d) & 1) == 0) {
      *(undefined4 *)((int)puVar3 + iVar4 + 0xc) = 0;
    }
    else {
      if (*(sword *)(iVar1 + 0x1c) != 2) {
        uVar6 = 0x2f;
        goto loc_40229AC;
      }
      *(undefined4 *)((int)puVar3 + iVar4 + 0xc) = *(undefined4 *)(iVar1 + 0x20);
    }
    *(undefined4 *)((int)puVar3 + iVar4 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined *)((int)puVar3 + iVar4 + 8) = 0xff;
  }
  uVar6 = _ip_output(param_1,*(undefined4 *)(iVar1 + 0x34),iVar1 + 0x38,
                     *(word *)(param_2 + 2) & 0x32 | 0x22,*(undefined4 *)(iVar1 + 0x4e));
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=744 start=0x40229c0 */

undefined4 _rip_ctloutput(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = *(int *)(param_2 + 8);
  if (param_3 == 0) {
    if (param_1 != 0) {
      if (param_1 != 1) {
        return 0;
      }
      if (param_4 == 1) {
        uVar3 = _ip_pcbopts(iVar1 + 0x34,*param_5);
        return uVar3;
      }
      if (((param_4 < 1) || (7 < param_4)) || (param_4 < 3)) {
        uVar3 = _ip_mrouter_cmd(param_4,param_2,*param_5);
      }
      else {
        uVar3 = _ip_setmoptions(param_4,iVar1 + 0x4e,*param_5);
      }
      goto loc_4022ABE;
    }
    if (param_4 == 1) {
      iVar2 = _m_get(1,10);
      *param_5 = iVar2;
      if (*(int *)(iVar1 + 0x34) == 0) {
        *(undefined2 *)(iVar2 + 8) = 0;
      }
      else {
        *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(*(int *)(iVar1 + 0x34) + 4);
        *(undefined2 *)(*param_5 + 8) = *(undefined2 *)(*(int *)(iVar1 + 0x34) + 8);
        iVar2 = *param_5;
        _bcopy(*(int *)(*(int *)(iVar1 + 0x34) + 4) + *(int *)(iVar1 + 0x34),
               *(int *)(iVar2 + 4) + iVar2,(int)*(sword *)(iVar2 + 8));
      }
      goto loc_4022ABE;
    }
    if (((0 < param_4) && (param_4 < 8)) && (2 < param_4)) {
      uVar3 = _ip_getmoptions(param_4,*(undefined4 *)(iVar1 + 0x4e),param_5);
      goto loc_4022ABE;
    }
  }
  uVar3 = 0x16;
loc_4022ABE:
  if ((param_1 == 1) && (*param_5 != 0)) {
    _m_free(*param_5);
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=745 start=0x4022adc */

void _tcp_trace(undefined2 param_1,undefined2 param_2,int param_3,undefined4 *param_4,
               undefined2 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _tcp_debx * 0xa2;
  _tcp_debx = _tcp_debx + 1;
  if (_tcp_debx == 100) {
    _tcp_debx = 0;
  }
  uVar2 = _iptime();
  *(undefined4 *)(_tcp_debug + iVar1) = uVar2;
  *(undefined2 *)(_tcp_debug + iVar1 + 4) = param_1;
  *(undefined2 *)(_tcp_debug + iVar1 + 6) = param_2;
  *(int *)(_tcp_debug + iVar1 + 8) = param_3;
  if (param_3 == 0) {
    _bzero(iVar1 + 0x40b7e12,0x6c);
  }
  else {
    _bcopy(param_3,iVar1 + 0x40b7e12,0x6c);
  }
  if (param_4 == (undefined4 *)0x0) {
    _bzero(iVar1 + 0x40b7de8,0x28);
  }
  else {
    *(undefined4 *)(_tcp_debug + iVar1 + 0xc) = *param_4;
    *(undefined4 *)(_tcp_debug + iVar1 + 0x10) = param_4[1];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x14) = param_4[2];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x18) = param_4[3];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x1c) = param_4[4];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x20) = param_4[5];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x24) = param_4[6];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x28) = param_4[7];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x2c) = param_4[8];
    *(undefined4 *)(_tcp_debug + iVar1 + 0x30) = param_4[9];
  }
  *(undefined2 *)(_tcp_debug + iVar1 + 0x34) = param_5;
  return;
}
/* GHIDRADEC_FUNCTION index=746 start=0x4022bae */

byte _tcp_reass(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  byte bVar3;
  int iVar4;
  int *piVar5;
  
  iVar1 = *(int *)(param_1[8] + 0x18);
  if (param_2 != (int *)0x0) {
    piVar5 = (int *)*param_1;
    if (param_1 != piVar5) {
      do {
        if (piVar5[6] != param_2[6] && -1 < piVar5[6] - param_2[6]) break;
        piVar5 = (int *)*piVar5;
      } while (param_1 != piVar5);
    }
    piVar2 = (int *)piVar5[1];
    if (param_1 != piVar2) {
      iVar4 = (piVar2[6] + (int)*(sword *)((int)piVar2 + 10)) - param_2[6];
      if (0 < iVar4) {
        if (*(sword *)((int)param_2 + 10) <= iVar4) {
          dword_40BBDA8 = dword_40BBDA8 + 1;
          dword_40BBDAC = *(sword *)((int)param_2 + 10) + dword_40BBDAC;
          _m_freem(param_3);
          return 0;
        }
        _m_adj(param_3,iVar4);
        *(sword *)((int)param_2 + 10) = *(sword *)((int)param_2 + 10) - (sword)iVar4;
        param_2[6] = iVar4 + param_2[6];
      }
      piVar5 = (int *)*piVar2;
    }
    dword_40BBDB8 = dword_40BBDB8 + 1;
    dword_40BBDBC = *(sword *)((int)param_2 + 10) + dword_40BBDBC;
    param_2[5] = param_3;
    while (param_1 != piVar5) {
      iVar4 = (param_2[6] + (int)*(sword *)((int)param_2 + 10)) - piVar5[6];
      if (iVar4 < 1) break;
      if (iVar4 < *(sword *)((int)piVar5 + 10)) {
        piVar5[6] = iVar4 + piVar5[6];
        *(sword *)((int)piVar5 + 10) = *(sword *)((int)piVar5 + 10) - (sword)iVar4;
        _m_adj(piVar5[5],iVar4);
        break;
      }
      piVar5 = (int *)*piVar5;
      piVar2 = (int *)piVar5[1];
      iVar4 = piVar2[5];
      *(int *)(*piVar2 + 4) = piVar2[1];
      *(int *)piVar2[1] = *piVar2;
      _m_freem(iVar4);
    }
    piVar5 = (int *)piVar5[1];
    *param_2 = *piVar5;
    param_2[1] = (int)piVar5;
    *(int **)(*piVar5 + 4) = param_2;
    *piVar5 = (int)param_2;
  }
  if ((((2 < *(sword *)(param_1 + 2)) && (piVar5 = (int *)*param_1, param_1 != piVar5)) &&
      (piVar5[6] == param_1[0x10])) &&
     ((*(sword *)(param_1 + 2) != 3 || (*(sword *)((int)piVar5 + 10) == 0)))) {
    do {
      param_1[0x10] = (int)*(sword *)((int)piVar5 + 10) + param_1[0x10];
      bVar3 = *(byte *)((int)piVar5 + 0x21);
      *(int *)(*piVar5 + 4) = piVar5[1];
      *(int *)piVar5[1] = *piVar5;
      piVar2 = piVar5 + 5;
      piVar5 = (int *)*piVar5;
      if ((*(byte *)(iVar1 + 7) & 0x20) == 0) {
        _sbappend(iVar1 + 0x22,*piVar2);
      }
      else {
        _m_freem(*piVar2);
      }
    } while ((param_1 != piVar5) && (piVar5[6] == param_1[0x10]));
    _sowakeup(iVar1,iVar1 + 0x22);
    return bVar3 & 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=747 start=0x4022d6c */

void _tcp_input(byte *param_1)

{
  word wVar1;
  bool bVar2;
  byte bVar3;
  bool bVar4;
  sword sVar9;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined2 uVar10;
  byte bVar11;
  int iVar12;
  sword sVar13;
  byte *unaff_D6;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte **ppbVar18;
  byte *pbStack_44;
  int iStack_16;
  int iStack_12;
  sword sStack_e;
  byte *pbStack_8;
  
  pbStack_8 = (byte *)0x0;
  pbVar16 = (byte *)0x0;
  bVar4 = false;
  iStack_12 = 0;
  iStack_16 = 0;
  dword_40BBD90 = dword_40BBD90 + 1;
  pbVar17 = param_1 + *(int *)(param_1 + 4);
  if (5 < (*pbVar17 & 0xf)) {
    pbStack_44 = (byte *)0x0;
    _ip_stripoptions(pbVar17);
  }
  if (*(word *)(param_1 + 8) < 0x28) {
    pbStack_44 = (byte *)0x28;
    param_1 = (byte *)_m_pullup(param_1);
    if (param_1 == (byte *)0x0) goto loc_4022E54;
    pbVar17 = param_1 + *(int *)(param_1 + 4);
  }
  sVar13 = *(sword *)(pbVar17 + 2);
  pbVar17[4] = 0;
  pbVar17[5] = 0;
  pbVar17[6] = 0;
  pbVar17[7] = 0;
  pbVar17[0] = 0;
  pbVar17[1] = 0;
  pbVar17[2] = 0;
  pbVar17[3] = 0;
  pbVar17[8] = 0;
  *(sword *)(pbVar17 + 10) = sVar13;
  *(sword *)(pbVar17 + 10) = sVar13;
  pbStack_44 = (byte *)(sVar13 + 0x14);
  sVar9 = _in_cksum(param_1);
  *(sword *)(pbVar17 + 0x24) = sVar9;
  if (sVar9 != 0) {
    dword_40BBD9C = dword_40BBD9C + 1;
    goto loc_4023D06;
  }
  uVar8 = (*(uint *)(pbVar17 + 0x20) >> 0x1c) * 4;
  if ((uVar8 < 0x14) || ((int)sVar13 < (int)uVar8)) {
    dword_40BBDA0 = dword_40BBDA0 + 1;
    goto loc_4023D06;
  }
  *(sword *)(pbVar17 + 10) = sVar13 - (sword)uVar8;
  if (uVar8 < 0x15) {
loc_4022EE0:
    bVar11 = pbVar17[0x21];
    do {
      if ((((*(sword *)(pbVar17 + 0x16) != *(sword *)((int)_tcp_last_inpcb + 0x16)) ||
           (*(sword *)(pbVar17 + 0x14) != *(sword *)(_tcp_last_inpcb + 4))) ||
          (_tcp_last_inpcb[3] != *(int *)(pbVar17 + 0xc))) ||
         (puVar5 = _tcp_last_inpcb,
         *(int *)((int)_tcp_last_inpcb + 0x12) != *(int *)(pbVar17 + 0x10))) {
        pbStack_44 = (byte *)0x1;
        puVar5 = (undefined4 *)
                 _in_pcblookup(&_tcb,*(undefined4 *)(pbVar17 + 0xc),*(undefined2 *)(pbVar17 + 0x14),
                               *(undefined4 *)(pbVar17 + 0x10),*(undefined2 *)(pbVar17 + 0x16));
        if (puVar5 != (undefined4 *)0x0) {
          _tcp_last_inpcb = puVar5;
        }
        _tcppcbcachemiss = _tcppcbcachemiss + 1;
      }
      if ((puVar5 == (undefined4 *)0x0) || (pbVar16 = (byte *)puVar5[7], pbVar16 == (byte *)0x0))
      goto loc_4023C9C;
      if (*(sword *)(pbVar16 + 8) == 0) goto loc_4023D06;
      unaff_D6 = (byte *)puVar5[6];
      if ((*(word *)(unaff_D6 + 2) & 3) != 0) {
        if ((*(word *)(unaff_D6 + 2) & 1) != 0) {
          _tcp_saveti = *(undefined4 *)pbVar17;
          dword_40BBDEC = *(undefined4 *)(pbVar17 + 4);
          dword_40BBDF0 = *(undefined4 *)(pbVar17 + 8);
          dword_40BBDF4 = *(undefined4 *)(pbVar17 + 0xc);
          dword_40BBDF8 = *(undefined4 *)(pbVar17 + 0x10);
          dword_40BBDFC = *(undefined4 *)(pbVar17 + 0x14);
          dword_40BBE00 = *(undefined4 *)(pbVar17 + 0x18);
          dword_40BBE04 = *(undefined4 *)(pbVar17 + 0x1c);
          dword_40BBE08 = *(undefined4 *)(pbVar17 + 0x20);
          dword_40BBE0C = *(undefined4 *)(pbVar17 + 0x24);
          sStack_e = *(sword *)(pbVar16 + 8);
        }
        if ((unaff_D6[3] & 2) != 0) {
          pbStack_44 = (byte *)0x0;
          unaff_D6 = (byte *)_sonewconn(unaff_D6);
          if (unaff_D6 == (byte *)0x0) goto loc_4023D06;
          iStack_12 = iStack_12 + 1;
          puVar5 = *(undefined4 **)(unaff_D6 + 8);
          *(undefined4 *)((int)puVar5 + 0x12) = *(undefined4 *)(pbVar17 + 0x10);
          *(undefined2 *)((int)puVar5 + 0x16) = *(undefined2 *)(pbVar17 + 0x16);
          pbStack_44 = (byte *)0x4022ffc;
          uVar6 = _ip_srcroute();
          puVar5[0xd] = uVar6;
          pbVar16 = (byte *)puVar5[7];
          pbVar16[8] = 0;
          pbVar16[9] = 1;
        }
      }
      pbVar16[0x58] = 0;
      pbVar16[0x59] = 0;
      *(undefined2 *)(pbVar16 + 0xe) = word_40AEB7E;
      if ((pbStack_8 != (byte *)0x0) && (*(sword *)(pbVar16 + 8) != 1)) {
        pbStack_44 = pbVar17;
        _tcp_dooptions(pbVar16,pbStack_8);
        pbStack_8 = (byte *)0x0;
      }
      if ((((*(sword *)(pbVar16 + 8) == 4) && ((bVar11 & 0x37) == 0x10)) &&
          (*(int *)(pbVar17 + 0x18) == *(int *)(pbVar16 + 0x40))) &&
         (((wVar1 = *(word *)(pbVar17 + 0x22), wVar1 != 0 && (wVar1 == *(word *)(pbVar16 + 0x3c)))
          && (iVar12 = *(int *)(pbVar16 + 0x28), iVar12 == *(int *)(pbVar16 + 0x50))))) {
        if (*(sword *)(pbVar17 + 10) == 0) {
          iVar7 = *(int *)(pbVar17 + 0x1c);
          if (((iVar7 != *(int *)(pbVar16 + 0x24) && -1 < iVar7 - *(int *)(pbVar16 + 0x24)) &&
              (iVar7 == iVar12 || iVar7 - iVar12 < 0)) && (wVar1 <= *(word *)(pbVar16 + 0x54))) {
            _tcppredack = _tcppredack + 1;
            if ((*(sword *)(pbVar16 + 0x5a) != 0) &&
               (*(int *)(pbVar17 + 0x1c) != *(int *)(pbVar16 + 0x5c) &&
                -1 < *(int *)(pbVar17 + 0x1c) - *(int *)(pbVar16 + 0x5c))) {
              pbStack_44 = pbVar16;
              _tcp_xmit_timer();
            }
            pbStack_44 = (byte *)(*(int *)(pbVar17 + 0x1c) - *(int *)(pbVar16 + 0x24));
            dword_40BBDD8 = dword_40BBDD8 + 1;
            dword_40BBDDC = pbStack_44 + (int)dword_40BBDDC;
            _sbdrop(unaff_D6 + 0x38);
            *(int *)(pbVar16 + 0x24) = *(int *)(pbVar17 + 0x1c);
            _m_freem(param_1);
            if (*(int *)(pbVar16 + 0x24) == *(int *)(pbVar16 + 0x50)) {
              pbVar16[10] = 0;
              pbVar16[0xb] = 0;
            }
            else if (*(sword *)(pbVar16 + 0xc) == 0) {
              *(undefined2 *)(pbVar16 + 10) = *(undefined2 *)(pbVar16 + 0x14);
            }
            if (((unaff_D6[0x4d] & 4) != 0) || (*(int *)(unaff_D6 + 0x48) != 0)) {
              pbStack_44 = unaff_D6 + 0x38;
              _sowakeup(unaff_D6);
            }
            ppbVar18 = (byte **)&stack0xffffffc0;
            if (*(sword *)(unaff_D6 + 0x38) == 0) {
              return;
            }
            goto loc_4023C90;
          }
        }
        else if ((*(int *)(pbVar17 + 0x1c) == *(int *)(pbVar16 + 0x24)) &&
                (pbVar16 == *(byte **)pbVar16)) {
          iVar12 = (uint)*(word *)(unaff_D6 + 0x24) - (uint)*(word *)(unaff_D6 + 0x22);
          if ((int)((uint)*(word *)(unaff_D6 + 0x28) - (uint)*(word *)(unaff_D6 + 0x26)) <
              (int)((uint)*(word *)(unaff_D6 + 0x24) - (uint)*(word *)(unaff_D6 + 0x22))) {
            iVar12 = (uint)*(word *)(unaff_D6 + 0x28) - (uint)*(word *)(unaff_D6 + 0x26);
          }
          if (*(sword *)(pbVar17 + 10) <= iVar12) {
            _tcppreddat = _tcppreddat + 1;
            *(int *)(pbVar16 + 0x40) = (int)*(sword *)(pbVar17 + 10) + *(int *)(pbVar16 + 0x40);
            dword_40BBD94 = dword_40BBD94 + 1;
            dword_40BBD98 = *(sword *)(pbVar17 + 10) + dword_40BBD98;
            *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x28;
            *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + -0x28;
            pbStack_44 = param_1;
            _sbappend(unaff_D6 + 0x22);
            _sowakeup(unaff_D6,unaff_D6 + 0x22);
            pbVar16[0x1b] = pbVar16[0x1b] | 2;
            return;
          }
        }
      }
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x28;
      *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + -0x28;
      iVar12 = (uint)*(word *)(unaff_D6 + 0x24) - (uint)*(word *)(unaff_D6 + 0x22);
      if ((int)((uint)*(word *)(unaff_D6 + 0x28) - (uint)*(word *)(unaff_D6 + 0x26)) <
          (int)((uint)*(word *)(unaff_D6 + 0x24) - (uint)*(word *)(unaff_D6 + 0x22))) {
        iVar12 = (uint)*(word *)(unaff_D6 + 0x28) - (uint)*(word *)(unaff_D6 + 0x26);
      }
      if (iVar12 < 0) {
        iVar12 = 0;
      }
      sVar13 = (sword)iVar12;
      if (iVar12 <= *(int *)(pbVar16 + 0x4c) - *(int *)(pbVar16 + 0x40)) {
        sVar13 = (sword)*(int *)(pbVar16 + 0x4c) - (sword)*(int *)(pbVar16 + 0x40);
      }
      *(sword *)(pbVar16 + 0x3e) = sVar13;
      sVar13 = *(sword *)(pbVar16 + 8);
      if (sVar13 == 1) {
        if ((bVar11 & 4) != 0) goto loc_4023D06;
        if ((bVar11 & 0x10) != 0) goto loc_4023C9C;
        if ((bVar11 & 2) == 0) goto loc_4023D06;
        pbStack_44 = *(byte **)(pbVar17 + 0x10);
        iVar12 = _in_broadcast();
        if (iVar12 != 0) goto loc_4023D06;
        pbStack_44 = (byte *)0x8;
        pbVar15 = (byte *)_m_get(0);
        if (pbVar15 == (byte *)0x0) goto loc_4023D06;
        pbVar15[8] = 0;
        pbVar15[9] = 0x10;
        pbVar14 = pbVar15 + *(int *)(pbVar15 + 4);
        pbVar14[0] = 0;
        pbVar14[1] = 2;
        *(undefined4 *)(pbVar14 + 4) = *(undefined4 *)(pbVar17 + 0xc);
        *(undefined2 *)(pbVar14 + 2) = *(undefined2 *)(pbVar17 + 0x14);
        iVar12 = *(int *)((int)puVar5 + 0x12);
        if (iVar12 == 0) {
          *(undefined4 *)((int)puVar5 + 0x12) = *(undefined4 *)(pbVar17 + 0x10);
        }
        pbStack_44 = pbVar15;
        iVar7 = _in_pcbconnect(puVar5);
        if (iVar7 != 0) {
          *(int *)((int)puVar5 + 0x12) = iVar12;
          pbStack_44 = pbVar15;
          _m_free();
          goto loc_4023D06;
        }
        pbStack_44 = pbVar15;
        _m_free();
        iVar12 = _tcp_template(pbVar16);
        *(int *)(pbVar16 + 0x1c) = iVar12;
        if (iVar12 == 0) {
          pbStack_44 = (byte *)0x37;
          pbVar16 = (byte *)_tcp_drop(pbVar16);
          iStack_12 = 0;
          goto loc_4023D06;
        }
        if (pbStack_8 != (byte *)0x0) {
          pbStack_44 = pbVar17;
          _tcp_dooptions(pbVar16,pbStack_8);
        }
        if (iStack_16 == 0) {
          *(int *)(pbVar16 + 0x38) = _tcp_iss;
        }
        else {
          *(int *)(pbVar16 + 0x38) = iStack_16;
        }
        _tcp_iss = _tcp_iss + 64000;
        *(int *)(pbVar16 + 0x48) = *(int *)(pbVar17 + 0x18);
        iVar12 = *(int *)(pbVar16 + 0x38);
        *(int *)(pbVar16 + 0x2c) = iVar12;
        *(int *)(pbVar16 + 0x50) = iVar12;
        *(int *)(pbVar16 + 0x28) = iVar12;
        *(int *)(pbVar16 + 0x24) = iVar12;
        *(int *)(pbVar16 + 0x40) = *(int *)(pbVar16 + 0x48) + 1;
        *(int *)(pbVar16 + 0x4c) = *(int *)(pbVar16 + 0x48) + 1;
        pbVar16[0x1b] = pbVar16[0x1b] | 1;
        pbVar16[8] = 0;
        pbVar16[9] = 3;
        pbVar16[0xe] = 0;
        pbVar16[0xf] = 0x96;
        dword_40BBD30 = dword_40BBD30 + 1;
loc_4023456:
        *(int *)(pbVar17 + 0x18) = *(int *)(pbVar17 + 0x18) + 1;
        if ((int)(uint)*(word *)(pbVar16 + 0x3e) < (int)*(sword *)(pbVar17 + 10)) {
          iVar12 = (int)*(sword *)(pbVar17 + 10) - (uint)*(word *)(pbVar16 + 0x3e);
          pbStack_44 = (byte *)-iVar12;
          _m_adj(param_1);
          *(undefined2 *)(pbVar17 + 10) = *(undefined2 *)(pbVar16 + 0x3e);
          bVar11 = bVar11 & 0xfe;
          dword_40BBDC0 = dword_40BBDC0 + 1;
          dword_40BBDC4 = iVar12 + dword_40BBDC4;
        }
        *(int *)(pbVar16 + 0x30) = *(int *)(pbVar17 + 0x18) + -1;
        *(int *)(pbVar16 + 0x44) = *(int *)(pbVar17 + 0x18);
        goto loc_40239E2;
      }
      if ((0 < sVar13) && (sVar13 < 4)) {
        bVar3 = bVar11 & 0x10;
        if ((bVar3 != 0) &&
           ((iVar12 = *(int *)(pbVar17 + 0x1c),
            iVar12 == *(int *)(pbVar16 + 0x38) || iVar12 - *(int *)(pbVar16 + 0x38) < 0 ||
            (iVar12 != *(int *)(pbVar16 + 0x50) && -1 < iVar12 - *(int *)(pbVar16 + 0x50)))))
        goto loc_4023C9C;
        if ((bVar11 & 4) != 0) {
          if (bVar3 != 0) {
            pbStack_44 = (byte *)0x3d;
            pbVar16 = (byte *)_tcp_drop(pbVar16);
          }
          goto loc_4023D06;
        }
        if (*(sword *)(pbVar16 + 8) != 3) {
          if ((bVar11 & 2) != 0) {
            if (bVar3 != 0) {
              *(int *)(pbVar16 + 0x24) = *(int *)(pbVar17 + 0x1c);
              if (*(int *)(pbVar16 + 0x28) - *(int *)(pbVar16 + 0x24) < 0) {
                *(int *)(pbVar16 + 0x28) = *(int *)(pbVar16 + 0x24);
              }
            }
            pbVar16[10] = 0;
            pbVar16[0xb] = 0;
            *(int *)(pbVar16 + 0x48) = *(int *)(pbVar17 + 0x18);
            *(int *)(pbVar16 + 0x40) = *(int *)(pbVar16 + 0x48) + 1;
            *(int *)(pbVar16 + 0x4c) = *(int *)(pbVar16 + 0x48) + 1;
            pbVar16[0x1b] = pbVar16[0x1b] | 1;
            if (((bVar11 & 0x10) == 0) ||
               (*(int *)(pbVar16 + 0x24) == *(int *)(pbVar16 + 0x38) ||
                *(int *)(pbVar16 + 0x24) - *(int *)(pbVar16 + 0x38) < 0)) {
              pbVar16[8] = 0;
              pbVar16[9] = 3;
            }
            else {
              dword_40BBD34 = dword_40BBD34 + 1;
              pbStack_44 = unaff_D6;
              _soisconnected();
              pbVar16[8] = 0;
              pbVar16[9] = 4;
              _tcp_reass(pbVar16,0,0);
              if (*(sword *)(pbVar16 + 0x5a) != 0) {
                pbStack_44 = pbVar16;
                _tcp_xmit_timer();
              }
            }
            goto loc_4023456;
          }
          goto loc_4023D06;
        }
      }
      pbVar15 = (byte *)(*(int *)(pbVar16 + 0x40) - *(int *)(pbVar17 + 0x18));
      if (0 < (int)pbVar15) {
        if ((bVar11 & 2) != 0) {
          *(int *)(pbVar17 + 0x18) = *(int *)(pbVar17 + 0x18) + 1;
          if (*(word *)(pbVar17 + 0x26) < 2) {
            bVar11 = bVar11 & 0xdd;
          }
          else {
            *(word *)(pbVar17 + 0x26) = *(word *)(pbVar17 + 0x26) - 1;
            bVar11 = bVar11 & 0xfd;
          }
          pbVar15 = pbVar15 + -1;
        }
        if (((int)*(sword *)(pbVar17 + 10) < (int)pbVar15) ||
           (((byte *)(int)*(sword *)(pbVar17 + 10) == pbVar15 && ((bVar11 & 1) == 0)))) {
          dword_40BBDA8 = dword_40BBDA8 + 1;
          dword_40BBDAC = *(sword *)(pbVar17 + 10) + dword_40BBDAC;
          if (((bVar11 & 1) == 0) ||
             (sVar13 = *(sword *)(pbVar17 + 10), (byte *)(int)sVar13 + 1 != pbVar15))
          goto loc_4023C7A;
          bVar11 = bVar11 & 0xfe;
          pbVar16[0x1b] = pbVar16[0x1b] | 1;
          pbVar15 = (byte *)(int)sVar13;
        }
        else {
          dword_40BBDB0 = dword_40BBDB0 + 1;
          dword_40BBDB4 = pbVar15 + (int)dword_40BBDB4;
        }
        pbStack_44 = pbVar15;
        _m_adj(param_1);
        *(byte **)(pbVar17 + 0x18) = pbVar15 + *(int *)(pbVar17 + 0x18);
        *(sword *)(pbVar17 + 10) = *(sword *)(pbVar17 + 10) - (sword)pbVar15;
        if ((int)pbVar15 < (int)(uint)*(word *)(pbVar17 + 0x26)) {
          *(word *)(pbVar17 + 0x26) = *(word *)(pbVar17 + 0x26) - (sword)pbVar15;
        }
        else {
          bVar11 = bVar11 & 0xdf;
          pbVar17[0x26] = 0;
          pbVar17[0x27] = 0;
        }
      }
      if ((((unaff_D6[7] & 1) != 0) && (5 < *(sword *)(pbVar16 + 8))) &&
         (*(sword *)(pbVar17 + 10) != 0)) {
        pbStack_44 = pbVar16;
        pbVar16 = (byte *)_tcp_close();
        dword_40BBDC8 = dword_40BBDC8 + 1;
        goto loc_4023C9C;
      }
      iVar12 = (*(int *)(pbVar17 + 0x18) + (int)*(sword *)(pbVar17 + 10)) -
               (*(int *)(pbVar16 + 0x40) + (uint)*(word *)(pbVar16 + 0x3e));
      if (iVar12 < 1) goto loc_4023636;
      dword_40BBDC0 = dword_40BBDC0 + 1;
      if (iVar12 < *(sword *)(pbVar17 + 10)) {
        dword_40BBDC4 = iVar12 + dword_40BBDC4;
        goto loc_402361E;
      }
      dword_40BBDC4 = *(sword *)(pbVar17 + 10) + dword_40BBDC4;
      if ((((bVar11 & 2) == 0) || (*(sword *)(pbVar16 + 8) != 10)) ||
         (iStack_16 = *(int *)(pbVar16 + 0x40),
         *(int *)(pbVar17 + 0x18) == iStack_16 || *(int *)(pbVar17 + 0x18) - iStack_16 < 0))
      goto loc_40235F6;
      iStack_16 = iStack_16 + 0x1f400;
      pbStack_44 = pbVar16;
      pbVar16 = (byte *)_tcp_close();
    } while( true );
  }
  pbStack_44 = (byte *)(uVar8 + 0x14);
  if ((byte *)(int)*(sword *)(param_1 + 8) < pbStack_44) {
    param_1 = (byte *)_m_pullup(param_1);
    if (param_1 == (byte *)0x0) {
loc_4022E54:
      dword_40BBDA4 = dword_40BBDA4 + 1;
      return;
    }
    pbVar17 = param_1 + *(int *)(param_1 + 4);
  }
  pbStack_44 = (byte *)0x1;
  pbStack_8 = (byte *)_m_get(0);
  if (pbStack_8 != (byte *)0x0) {
    sVar13 = (sword)uVar8 + -0x14;
    *(sword *)(pbStack_8 + 8) = sVar13;
    pbVar15 = param_1 + *(int *)(param_1 + 4) + 0x28;
    pbStack_44 = (byte *)(int)sVar13;
    _bcopy(pbVar15,pbStack_8 + *(int *)(pbStack_8 + 4));
    sVar13 = *(sword *)(param_1 + 8);
    sVar9 = *(sword *)(pbStack_8 + 8);
    *(sword *)(param_1 + 8) = sVar13 - sVar9;
    _bcopy(pbVar15 + *(sword *)(pbStack_8 + 8),pbVar15,(sword)(sVar13 - sVar9) + -0x28);
    goto loc_4022EE0;
  }
loc_4023D18:
  if ((pbVar16 != (byte *)0x0) &&
     ((*(byte *)(*(int *)(*(int *)(pbVar16 + 0x20) + 0x18) + 3) & 1) != 0)) {
    pbStack_44 = (byte *)0x0;
    _tcp_trace(4,(int)sStack_e,pbVar16,&_tcp_saveti);
  }
  pbStack_44 = param_1;
  _m_freem();
loc_4023D54:
  if (iStack_12 != 0) {
    pbStack_44 = unaff_D6;
    _soabort();
  }
  return;
loc_40235F6:
  if ((*(sword *)(pbVar16 + 0x3e) != 0) || (*(int *)(pbVar17 + 0x18) != *(int *)(pbVar16 + 0x40)))
  goto loc_4023C7A;
  pbVar16[0x1b] = pbVar16[0x1b] | 1;
  dword_40BBDCC = dword_40BBDCC + 1;
loc_402361E:
  pbStack_44 = (byte *)-iVar12;
  _m_adj(param_1);
  *(sword *)(pbVar17 + 10) = *(sword *)(pbVar17 + 10) - (sword)iVar12;
  bVar11 = bVar11 & 0xf6;
loc_4023636:
  if ((bVar11 & 4) == 0) {
loc_4023696:
    if ((bVar11 & 2) != 0) {
      pbStack_44 = (byte *)0x36;
      pbVar16 = (byte *)_tcp_drop(pbVar16);
loc_4023C9C:
      if (pbStack_8 != (byte *)0x0) {
        pbStack_44 = pbStack_8;
        _m_free();
        pbStack_8 = (byte *)0x0;
      }
      if ((bVar11 & 4) == 0) {
        pbStack_44 = *(byte **)(pbVar17 + 0x10);
        iVar12 = _in_broadcast();
        if (iVar12 == 0) {
          if ((bVar11 & 0x10) == 0) {
            if ((bVar11 & 2) != 0) {
              *(sword *)(pbVar17 + 10) = *(sword *)(pbVar17 + 10) + 1;
            }
            pbStack_44 = (byte *)0x14;
            uVar6 = 0;
            iVar12 = *(int *)(pbVar17 + 0x18) + (int)*(sword *)(pbVar17 + 10);
          }
          else {
            pbStack_44 = (byte *)0x4;
            uVar6 = *(undefined4 *)(pbVar17 + 0x1c);
            iVar12 = 0;
          }
          _tcp_respond(pbVar16,pbVar17,param_1,iVar12,uVar6);
          goto loc_4023D54;
        }
      }
      goto loc_4023D06;
    }
    if ((bVar11 & 0x10) == 0) goto loc_4023D06;
    sVar13 = *(sword *)(pbVar16 + 8);
    if (sVar13 == 3) {
      iVar12 = *(int *)(pbVar17 + 0x1c);
      if ((*(int *)(pbVar16 + 0x24) != iVar12 && -1 < *(int *)(pbVar16 + 0x24) - iVar12) ||
         (iVar12 != *(int *)(pbVar16 + 0x50) && -1 < iVar12 - *(int *)(pbVar16 + 0x50)))
      goto loc_4023C9C;
      dword_40BBD34 = dword_40BBD34 + 1;
      pbStack_44 = unaff_D6;
      _soisconnected();
      pbVar16[8] = 0;
      pbVar16[9] = 4;
      _tcp_reass(pbVar16,0,0);
      *(int *)(pbVar16 + 0x30) = *(int *)(pbVar17 + 0x18) + -1;
loc_402371A:
      if (*(int *)(pbVar17 + 0x1c) == *(int *)(pbVar16 + 0x24) ||
          *(int *)(pbVar17 + 0x1c) - *(int *)(pbVar16 + 0x24) < 0) {
        if ((((*(sword *)(pbVar17 + 10) == 0) &&
             (*(sword *)(pbVar16 + 0x3c) == *(sword *)(pbVar17 + 0x22))) &&
            (dword_40BBDD0 = dword_40BBDD0 + 1, *(sword *)(pbVar16 + 10) != 0)) &&
           (*(int *)(pbVar17 + 0x1c) == *(int *)(pbVar16 + 0x24))) {
          sVar13 = *(sword *)(pbVar16 + 0x16);
          *(sword *)(pbVar16 + 0x16) = sVar13 + 1;
          iVar12 = (int)(sword)(sVar13 + 1);
          if (_tcprexmtthresh == iVar12) {
            iVar12 = *(int *)(pbVar16 + 0x28);
            pbStack_44 = (byte *)(uint)*(word *)(pbVar16 + 0x54);
            uVar8 = _min(*(undefined2 *)(pbVar16 + 0x3c));
            uVar8 = (uVar8 >> 1) / (uint)*(word *)(pbVar16 + 0x18);
            if (uVar8 < 2) {
              uVar8 = 2;
            }
            *(word *)(pbVar16 + 0x56) = *(word *)(pbVar16 + 0x18) * (sword)uVar8;
            pbVar16[10] = 0;
            pbVar16[0xb] = 0;
            pbVar16[0x5a] = 0;
            pbVar16[0x5b] = 0;
            *(int *)(pbVar16 + 0x28) = *(int *)(pbVar17 + 0x1c);
            *(undefined2 *)(pbVar16 + 0x54) = *(undefined2 *)(pbVar16 + 0x18);
            pbStack_44 = pbVar16;
            _tcp_output();
            *(sword *)(pbVar16 + 0x54) =
                 *(sword *)(pbVar16 + 0x56) +
                 *(sword *)(pbVar16 + 0x18) * *(sword *)(pbVar16 + 0x16);
            if (iVar12 != *(int *)(pbVar16 + 0x28) && -1 < iVar12 - *(int *)(pbVar16 + 0x28)) {
              *(int *)(pbVar16 + 0x28) = iVar12;
            }
          }
          else {
            if (iVar12 <= _tcprexmtthresh) goto loc_40239E2;
            *(sword *)(pbVar16 + 0x54) = *(sword *)(pbVar16 + 0x18) + *(sword *)(pbVar16 + 0x54);
            pbStack_44 = pbVar16;
            _tcp_output();
          }
          goto loc_4023D06;
        }
        pbVar16[0x16] = 0;
        pbVar16[0x17] = 0;
      }
      else {
        if ((_tcprexmtthresh < *(sword *)(pbVar16 + 0x16)) &&
           (*(word *)(pbVar16 + 0x56) < *(word *)(pbVar16 + 0x54))) {
          *(word *)(pbVar16 + 0x54) = *(word *)(pbVar16 + 0x56);
        }
        pbVar16[0x16] = 0;
        pbVar16[0x17] = 0;
        iVar12 = *(int *)(pbVar17 + 0x1c);
        if (iVar12 != *(int *)(pbVar16 + 0x50) && -1 < iVar12 - *(int *)(pbVar16 + 0x50)) {
          dword_40BBDD4 = dword_40BBDD4 + 1;
loc_4023C7A:
          if ((bVar11 & 4) == 0) {
            pbStack_44 = param_1;
            _m_freem();
            pbVar16[0x1b] = pbVar16[0x1b] | 1;
            ppbVar18 = &pbStack_44;
            goto loc_4023C90;
          }
          goto loc_4023D06;
        }
        pbVar15 = (byte *)(iVar12 - *(int *)(pbVar16 + 0x24));
        dword_40BBDD8 = dword_40BBDD8 + 1;
        dword_40BBDDC = pbVar15 + (int)dword_40BBDDC;
        if ((*(sword *)(pbVar16 + 0x5a) != 0) &&
           (*(int *)(pbVar17 + 0x1c) != *(int *)(pbVar16 + 0x5c) &&
            -1 < *(int *)(pbVar17 + 0x1c) - *(int *)(pbVar16 + 0x5c))) {
          pbStack_44 = pbVar16;
          _tcp_xmit_timer();
        }
        if (*(int *)(pbVar17 + 0x1c) == *(int *)(pbVar16 + 0x50)) {
          pbVar16[10] = 0;
          pbVar16[0xb] = 0;
          bVar4 = true;
        }
        else if (*(sword *)(pbVar16 + 0xc) == 0) {
          *(undefined2 *)(pbVar16 + 10) = *(undefined2 *)(pbVar16 + 0x14);
        }
        uVar8 = (uint)*(word *)(pbVar16 + 0x18);
        if (*(word *)(pbVar16 + 0x56) < *(word *)(pbVar16 + 0x54)) {
          uVar8 = (uint)(*(word *)(pbVar16 + 0x18) >> 3) +
                  (uVar8 * uVar8) / (uint)*(word *)(pbVar16 + 0x54);
        }
        pbStack_44 = (byte *)0xffff;
        uVar10 = _min(*(word *)(pbVar16 + 0x54) + uVar8);
        *(undefined2 *)(pbVar16 + 0x54) = uVar10;
        bVar2 = (int)pbVar15 <= (int)(uint)*(word *)(unaff_D6 + 0x38);
        if (bVar2) {
          pbStack_44 = pbVar15;
          _sbdrop(unaff_D6 + 0x38);
          *(sword *)(pbVar16 + 0x3c) = *(sword *)(pbVar16 + 0x3c) - (sword)pbVar15;
        }
        else {
          *(word *)(pbVar16 + 0x3c) = *(sword *)(pbVar16 + 0x3c) - *(word *)(unaff_D6 + 0x38);
          pbStack_44 = (byte *)(uint)*(word *)(unaff_D6 + 0x38);
          _sbdrop(unaff_D6 + 0x38);
        }
        if (((unaff_D6[0x4d] & 4) != 0) || (*(int *)(unaff_D6 + 0x48) != 0)) {
          pbStack_44 = unaff_D6 + 0x38;
          _sowakeup(unaff_D6);
        }
        *(int *)(pbVar16 + 0x24) = *(int *)(pbVar17 + 0x1c);
        if (*(int *)(pbVar16 + 0x28) - *(int *)(pbVar16 + 0x24) < 0) {
          *(int *)(pbVar16 + 0x28) = *(int *)(pbVar16 + 0x24);
        }
        sVar13 = *(sword *)(pbVar16 + 8);
        if (sVar13 == 7) {
          if (!bVar2) {
            pbVar16[8] = 0;
            pbVar16[9] = 10;
            pbStack_44 = pbVar16;
            _tcp_canceltimers();
            pbVar16[0x10] = 0;
            pbVar16[0x11] = 0x78;
            _soisdisconnected(unaff_D6);
          }
        }
        else if (sVar13 < 8) {
          if ((sVar13 == 6) && (!bVar2)) {
            if ((unaff_D6[7] & 0x20) != 0) {
              pbStack_44 = unaff_D6;
              _soisdisconnected();
              *(undefined2 *)(pbVar16 + 0x10) = word_40BBDE6;
            }
            pbVar16[8] = 0;
            pbVar16[9] = 9;
          }
        }
        else if (sVar13 == 8) {
          if (!bVar2) goto loc_40239C8;
        }
        else if (sVar13 == 10) {
          pbVar16[0x10] = 0;
          pbVar16[0x11] = 0x78;
          goto loc_4023C7A;
        }
      }
    }
    else if ((2 < sVar13) && (sVar13 < 0xb)) goto loc_402371A;
loc_40239E2:
    if ((bVar11 & 0x10) != 0) {
      if (*(int *)(pbVar16 + 0x30) - *(int *)(pbVar17 + 0x18) < 0) {
loc_4023A16:
        if ((*(sword *)(pbVar17 + 10) == 0) &&
           ((*(int *)(pbVar16 + 0x34) == *(int *)(pbVar17 + 0x1c) &&
            (*(word *)(pbVar16 + 0x3c) < *(word *)(pbVar17 + 0x22))))) {
          dword_40BBDE0 = dword_40BBDE0 + 1;
        }
        *(undefined2 *)(pbVar16 + 0x3c) = *(undefined2 *)(pbVar17 + 0x22);
        *(int *)(pbVar16 + 0x30) = *(int *)(pbVar17 + 0x18);
        *(int *)(pbVar16 + 0x34) = *(int *)(pbVar17 + 0x1c);
        if (*(word *)(pbVar16 + 0x66) < *(word *)(pbVar16 + 0x3c)) {
          *(word *)(pbVar16 + 0x66) = *(word *)(pbVar16 + 0x3c);
        }
        bVar4 = true;
      }
      else if (*(int *)(pbVar17 + 0x18) == *(int *)(pbVar16 + 0x30)) {
        if ((*(int *)(pbVar16 + 0x34) - *(int *)(pbVar17 + 0x1c) < 0) ||
           ((*(int *)(pbVar17 + 0x1c) == *(int *)(pbVar16 + 0x34) &&
            (*(word *)(pbVar16 + 0x3c) < *(word *)(pbVar17 + 0x22))))) goto loc_4023A16;
      }
    }
    if ((((bVar11 & 0x20) == 0) || (wVar1 = *(word *)(pbVar17 + 0x26), wVar1 == 0)) ||
       (9 < *(sword *)(pbVar16 + 8))) {
      iVar12 = *(int *)(pbVar16 + 0x40);
      if (iVar12 != *(int *)(pbVar16 + 0x44) && -1 < iVar12 - *(int *)(pbVar16 + 0x44)) {
        *(int *)(pbVar16 + 0x44) = iVar12;
      }
    }
    else if ((uint)wVar1 + (uint)*(word *)(unaff_D6 + 0x22) < 0x10000) {
      iVar12 = *(int *)(pbVar17 + 0x18) + (uint)wVar1;
      if (iVar12 != *(int *)(pbVar16 + 0x44) && -1 < iVar12 - *(int *)(pbVar16 + 0x44)) {
        *(int *)(pbVar16 + 0x44) = iVar12;
        sVar13 = *(sword *)(unaff_D6 + 0x22) + ((sword)iVar12 - *(sword *)(pbVar16 + 0x42)) + -1;
        *(sword *)(unaff_D6 + 0x52) = sVar13;
        if (sVar13 == 0) {
          *(word *)(unaff_D6 + 6) = *(word *)(unaff_D6 + 6) | 0x40;
        }
        pbStack_44 = unaff_D6;
        _sohasoutofband();
        pbVar16[0x68] = pbVar16[0x68] & 0xfc;
      }
      if (((int)(uint)*(word *)(pbVar17 + 0x26) <= (int)*(sword *)(pbVar17 + 10)) &&
         ((unaff_D6[2] & 1) == 0)) {
        pbStack_44 = param_1;
        _tcp_pulloutofband(unaff_D6,pbVar17);
      }
    }
    else {
      pbVar17[0x26] = 0;
      pbVar17[0x27] = 0;
      bVar11 = bVar11 & 0xdf;
    }
    if (((*(sword *)(pbVar17 + 10) == 0) && ((bVar11 & 1) == 0)) || (9 < *(sword *)(pbVar16 + 8))) {
      pbStack_44 = param_1;
      _m_freem();
      bVar11 = 0;
    }
    else if (((*(int *)(pbVar17 + 0x18) == *(int *)(pbVar16 + 0x40)) &&
             (pbVar16 == *(byte **)pbVar16)) && (*(sword *)(pbVar16 + 8) == 4)) {
      pbVar16[0x1b] = pbVar16[0x1b] | 2;
      *(int *)(pbVar16 + 0x40) = (int)*(sword *)(pbVar17 + 10) + *(int *)(pbVar16 + 0x40);
      bVar11 = pbVar17[0x21] & 1;
      dword_40BBD94 = dword_40BBD94 + 1;
      dword_40BBD98 = *(sword *)(pbVar17 + 10) + dword_40BBD98;
      pbStack_44 = param_1;
      _sbappend(unaff_D6 + 0x22);
      _sowakeup(unaff_D6,unaff_D6 + 0x22);
    }
    else {
      pbStack_44 = param_1;
      bVar11 = _tcp_reass(pbVar16,pbVar17);
      pbVar16[0x1b] = pbVar16[0x1b] | 1;
    }
    if ((bVar11 & 1) != 0) {
      if (*(sword *)(pbVar16 + 8) < 10) {
        pbStack_44 = unaff_D6;
        _socantrcvmore();
        pbVar16[0x1b] = pbVar16[0x1b] | 1;
        *(int *)(pbVar16 + 0x40) = *(int *)(pbVar16 + 0x40) + 1;
      }
      switch(*(undefined2 *)(pbVar16 + 8)) {
      case :
      case :
        pbVar16[8] = 0;
        pbVar16[9] = 5;
        break;
      case :
        pbVar16[8] = 0;
        pbVar16[9] = 7;
        break;
      case :
        pbVar16[8] = 0;
        pbVar16[9] = 10;
        pbStack_44 = pbVar16;
        _tcp_canceltimers();
        pbVar16[0x10] = 0;
        pbVar16[0x11] = 0x78;
        _soisdisconnected(unaff_D6);
        break;
      case :
        pbVar16[0x10] = 0;
        pbVar16[0x11] = 0x78;
      }
    }
    if ((unaff_D6[3] & 1) != 0) {
      pbStack_44 = (byte *)0x0;
      _tcp_trace(0,(int)sStack_e,pbVar16,&_tcp_saveti);
    }
    ppbVar18 = (byte **)&stack0xffffffc0;
    if ((!bVar4) && (ppbVar18 = (byte **)&stack0xffffffc0, (pbVar16[0x1b] & 1) == 0)) {
      return;
    }
loc_4023C90:
    *(byte **)((int)ppbVar18 + -4) = pbVar16;
    *(undefined4 *)((int)ppbVar18 + -8) = 0x4023c98;
    _tcp_output();
    return;
  }
  switch(*(undefined2 *)(pbVar16 + 8)) {
  case :
    unaff_D6[0x50] = 0;
    unaff_D6[0x51] = 0x3d;
    break;
  case :
  case :
  case :
  case :
    unaff_D6[0x50] = 0;
    unaff_D6[0x51] = 0x36;
    break;
  case :
  case :
  case :
    goto loc_40239C8;
  :
    goto loc_4023696;
  }
  pbVar16[8] = 0;
  pbVar16[9] = 0;
  dword_40BBD38 = dword_40BBD38 + 1;
loc_40239C8:
  pbStack_44 = pbVar16;
  pbVar16 = (byte *)_tcp_close();
loc_4023D06:
  if (pbStack_8 != (byte *)0x0) {
    pbStack_44 = pbStack_8;
    _m_free();
  }
  goto loc_4023D18;
}
/* GHIDRADEC_FUNCTION index=748 start=0x4023d6c */

void _tcp_dooptions(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  undefined2 uStack_6;
  
  iVar4 = (int)*(sword *)(param_2 + 8);
  for (pcVar3 = (char *)(*(int *)(param_2 + 4) + param_2);
      (0 < iVar4 && (cVar1 = *pcVar3, cVar1 != '\0')); pcVar3 = pcVar3 + uVar2) {
    if (cVar1 == '\x01') {
      uVar2 = 1;
    }
    else {
      uVar2 = (uint)(byte)pcVar3[1];
      if (pcVar3[1] == 0) break;
    }
    if (((cVar1 == '\x02') && (uVar2 == 4)) && ((*(byte *)(param_3 + 0x21) & 2) != 0)) {
      _bcopy(pcVar3 + 2,&uStack_6,2);
      _tcp_mss(param_1,uStack_6);
    }
    iVar4 = iVar4 - uVar2;
  }
  _m_free(param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=749 start=0x4023dfc */

void _tcp_pulloutofband(int param_1,int param_2,int *param_3)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  undefined *puVar4;
  
  iVar3 = *(word *)(param_2 + 0x26) - 1;
  do {
    if (iVar3 < 0) break;
    if (iVar3 < *(sword *)(param_3 + 2)) {
      puVar4 = (undefined *)((int)param_3 + iVar3 + param_3[1]);
      iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x1c);
      *(undefined *)(iVar1 + 0x69) = *puVar4;
      pbVar2 = (byte *)(iVar1 + 0x68);
      *pbVar2 = *pbVar2 | 1;
      _bcopy(puVar4 + 1,puVar4,(*(sword *)(param_3 + 2) - iVar3) + -1);
      *(sword *)(param_3 + 2) = *(sword *)(param_3 + 2) + -1;
      return;
    }
    iVar3 = iVar3 - *(sword *)(param_3 + 2);
    param_3 = (int *)*param_3;
  } while (param_3 != (int *)0x0);
                    /* WARNING: Subroutine does not return */
  _panic(aTcpPulloutofba);
}

