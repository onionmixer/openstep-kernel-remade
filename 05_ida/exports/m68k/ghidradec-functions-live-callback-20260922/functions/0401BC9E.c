
sword * _ifa_ifwithdstaddr(sword *param_1)

{
  sword *psVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _ifnet;
  do {
    if (iVar2 == 0) {
      return (sword *)0x0;
    }
    if ((*(byte *)(iVar2 + 0xd) & 0x10) != 0) {
      for (psVar1 = *(sword **)(iVar2 + 0x16); psVar1 != (sword *)0x0;
          psVar1 = *(sword **)(psVar1 + 0x12)) {
        if ((*param_1 == *psVar1) && (iVar3 = _bcmp(psVar1 + 9,param_1 + 1,0xe), iVar3 == 0)) {
          return psVar1;
        }
      }
    }
    iVar2 = *(int *)(iVar2 + 0x5a);
  } while( true );
}

