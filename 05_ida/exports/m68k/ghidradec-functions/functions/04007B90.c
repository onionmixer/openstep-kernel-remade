
undefined4 _groupmember(sword param_1)

{
  int iVar1;
  undefined4 uVar2;
  sword *psVar3;
  
  iVar1 = *(int *)(_active_u + 0x1a);
  if (param_1 == *(sword *)(iVar1 + 4)) {
loc_4007BA8:
    uVar2 = 1;
  }
  else {
    for (psVar3 = (sword *)(iVar1 + 10); (psVar3 < (sword *)(iVar1 + 0x2a) && (*psVar3 != -1));
        psVar3 = psVar3 + 1) {
      if (param_1 == *psVar3) goto loc_4007BA8;
    }
    uVar2 = 0;
  }
  return uVar2;
}
