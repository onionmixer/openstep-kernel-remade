
word _in_cksum(int *param_1,int param_2)

{
  sword sVar1;
  word wVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    do {
      if (param_2 <= *(sword *)(param_1 + 2)) {
        pbVar4 = (byte *)(param_1[1] + (int)param_1);
        goto loc_4092890;
      }
      uVar3 = (uint)*(sword *)(param_1 + 2);
      iVar5 = _oc_cksum(param_1[1] + (int)param_1,uVar3,iVar5);
      param_1 = (int *)*param_1;
      param_2 = param_2 - uVar3;
    } while ((uVar3 & 1) == 0);
    sVar1 = *(sword *)(param_1 + 2);
    if (sVar1 < param_2) {
      do {
        pbVar4 = (byte *)(param_1[1] + (int)param_1);
        if ((uVar3 & 1) == 0) {
          uVar3 = (uint)*(sword *)(param_1 + 2);
        }
        else {
          uVar3 = (int)sVar1 - 1;
          param_2 = param_2 + -1;
          iVar5 = (uint)*pbVar4 + iVar5;
          pbVar4 = pbVar4 + 1;
        }
        iVar5 = _oc_cksum(pbVar4,uVar3,iVar5);
        param_1 = (int *)*param_1;
        param_2 = param_2 - uVar3;
        sVar1 = *(sword *)(param_1 + 2);
      } while (sVar1 < param_2);
    }
  } while ((uVar3 & 1) == 0);
  pbVar4 = (byte *)(param_1[1] + (int)param_1) + 1;
  iVar5 = iVar5 + (uint)*(byte *)(param_1[1] + (int)param_1);
  param_2 = param_2 + -1;
loc_4092890:
  wVar2 = _oc_cksum(pbVar4,param_2,iVar5);
  return ~wVar2;
}

