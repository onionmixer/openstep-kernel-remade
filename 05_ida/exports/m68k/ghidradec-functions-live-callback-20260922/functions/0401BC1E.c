
sword * _ifa_ifwithaddr(sword *param_1)

{
  sword *psVar1;
  int iVar2;
  int iVar3;
  
  if (_ifnet != 0) {
    iVar3 = _ifnet;
    do {
      for (psVar1 = *(sword **)(iVar3 + 0x16); psVar1 != (sword *)0x0;
          psVar1 = *(sword **)(psVar1 + 0x12)) {
        if (*param_1 == *psVar1) {
          iVar2 = _bcmp(psVar1 + 1,param_1 + 1,0xe);
          if (iVar2 == 0) {
            return psVar1;
          }
          if (((*(byte *)(iVar3 + 0xd) & 2) != 0) &&
             (iVar2 = _bcmp(psVar1 + 9,param_1 + 1,0xe), iVar2 == 0)) {
            return psVar1;
          }
        }
      }
      iVar3 = *(int *)(iVar3 + 0x5a);
    } while (iVar3 != 0);
  }
  return (sword *)0x0;
}

