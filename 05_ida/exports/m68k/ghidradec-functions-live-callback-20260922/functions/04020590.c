
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

