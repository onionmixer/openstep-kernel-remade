
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
