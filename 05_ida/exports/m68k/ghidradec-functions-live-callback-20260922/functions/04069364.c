
undefined4 sub_4069364(sword *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  pbVar5 = *(byte **)(param_1 + param_2 * 2 + 0x43);
  if (pbVar5 != (byte *)0x0) {
    iVar1 = 0;
    if (*param_1 == 0) {
      pbVar4 = pbVar5 + 1;
      uVar2 = (uint)*pbVar5;
    }
    else {
      pbVar4 = pbVar5 + 2;
      uVar2 = (uint)*(sword *)pbVar5;
    }
    if (0 < (int)uVar2) {
      do {
        if (*param_1 == 0) {
          pbVar5 = pbVar4 + 1;
          uVar3 = (uint)*pbVar4;
        }
        else {
          pbVar5 = pbVar4 + 2;
          uVar3 = (uint)*(sword *)pbVar4;
        }
        if (*(char *)((int)param_1 + uVar3 + 2) < '\0') {
          return 1;
        }
        iVar1 = iVar1 + 1;
        pbVar4 = pbVar5;
      } while (iVar1 < (int)uVar2);
    }
  }
  return 0;
}

