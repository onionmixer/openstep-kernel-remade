
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
