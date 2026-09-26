
uint _tcp_mss(int param_1,word param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = *(int *)(param_1 + 0x20);
  piVar3 = (int *)(iVar1 + 0x20);
  iVar4 = *piVar3;
  if (iVar4 == 0) {
    if (*(int *)(iVar1 + 0xc) != 0) {
      *(undefined2 *)(iVar1 + 0x24) = 2;
      *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar1 + 0xc);
      _rtalloc(piVar3);
    }
    iVar4 = *piVar3;
    if (iVar4 == 0) {
      return _tcp_mssdflt;
    }
  }
  iVar2 = *(int *)(iVar1 + 0x18);
  uVar5 = (int)*(sword *)(*(int *)(iVar4 + 0x2c) + 10) - 0x28;
  if (0x400 < (int)uVar5) {
    uVar5 = uVar5 & 0xfffffc00;
  }
  iVar4 = _in_localaddr(*(undefined4 *)(iVar1 + 0xc));
  if (iVar4 == 0) {
    uVar5 = _min(uVar5,_tcp_mssdflt);
  }
  if ((param_2 != 0) && ((int)(uint)param_2 < (int)uVar5)) {
    uVar5 = (uint)param_2;
  }
  if ((int)uVar5 < 0x20) {
    uVar5 = 0x20;
  }
  if (((int)uVar5 < (int)(uint)*(word *)(param_1 + 0x18)) || (uVar6 = uVar5, param_2 != 0)) {
    uVar6 = (uint)*(word *)(iVar2 + 0x3a);
    if (uVar5 <= uVar6) {
      uVar6 = _min(uVar6,0xffff);
      _sbreserve(iVar2 + 0x38,uVar5 * (uVar6 / uVar5));
      uVar6 = uVar5;
    }
    *(sword *)(param_1 + 0x18) = (sword)uVar6;
    if (uVar6 < *(word *)(iVar2 + 0x24)) {
      uVar5 = _min((uint)*(word *)(iVar2 + 0x24),0xffff);
      _sbreserve(iVar2 + 0x22,uVar6 * (uVar5 / uVar6));
    }
  }
  *(sword *)(param_1 + 0x54) = (sword)uVar6;
  return uVar6;
}

