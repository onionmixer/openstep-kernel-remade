
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
