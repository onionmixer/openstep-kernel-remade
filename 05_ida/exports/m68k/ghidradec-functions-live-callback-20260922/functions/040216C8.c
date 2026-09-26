
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

