
int sub_404C398(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  uint uStack_42;
  undefined4 uStack_3e;
  undefined4 uStack_3a;
  undefined4 uStack_36;
  undefined4 auStack_32 [4];
  undefined auStack_20 [28];
  
  pcVar2 = (char *)(*(int *)(param_1 + 8) + param_1);
  pcVar4 = pcVar2;
  do {
    if ((char *)(*(int *)(param_1 + 4) + param_1) <= pcVar4) {
      return 2;
    }
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar3 = sub_404C5D6(pcVar2,auStack_20,&uStack_36,&uStack_3a,&uStack_3e);
  if (iVar3 == 0) {
    _bzero(auStack_32,0x12);
    auStack_32[0] = 0;
    iVar3 = sub_404BC42(uStack_3e,param_2,auStack_20,uStack_36,uStack_3a,param_3,&uStack_42,
                        auStack_32);
    if ((iVar3 == 0) && (uStack_42 < *(uint *)(param_1 + 0xc))) {
      iVar3 = 3;
    }
    _vn_rele(uStack_3e);
  }
  return iVar3;
}

