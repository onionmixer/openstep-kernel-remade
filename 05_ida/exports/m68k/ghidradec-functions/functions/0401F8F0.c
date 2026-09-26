
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
