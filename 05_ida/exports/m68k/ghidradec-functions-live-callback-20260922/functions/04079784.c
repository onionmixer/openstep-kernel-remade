
undefined4 _od_validate_label(int *param_1,int param_2)

{
  int iVar1;
  sword sVar2;
  word wVar3;
  sword sVar4;
  sword *psVar5;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if ((iVar1 == 0x4e655854) || (iVar1 == 0x646c5632)) {
      wVar3 = 0x1c48;
      psVar5 = (sword *)((int)param_1 + 0x1c46);
    }
    else {
      wVar3 = 0x230;
      psVar5 = (sword *)((int)param_1 + 0x22e);
    }
    if (param_1[1] == param_2) {
      sVar2 = *psVar5;
      *psVar5 = 0;
      sVar4 = _checksum_16(param_1,wVar3 >> 1);
      if (sVar2 != sVar4) {
        return 0xffffffff;
      }
      return 0;
    }
  }
  return 0xffffffff;
}

