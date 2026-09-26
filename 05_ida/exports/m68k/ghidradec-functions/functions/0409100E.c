
uint sub_409100E(int param_1,uint param_2,int param_3,word param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  sword sVar4;
  word *pwVar5;
  word *pwVar6;
  
  if (param_2 == 0) {
    _bcopy(param_1,param_3,param_5 * 2);
    uVar2 = 0;
  }
  else {
    uVar2 = (uint)param_4;
    param_5 = param_5 + -1;
    if (-1 < param_5) {
      pwVar6 = (word *)(param_3 + param_5 * 2);
      pwVar5 = (word *)(param_1 + param_5 * 2);
      do {
        do {
          uVar1 = (uint)*pwVar5 << (param_2 & 0x3f);
          *pwVar6 = (word)uVar1 | (word)uVar2;
          uVar2 = uVar1 >> 0x10;
          pwVar6 = pwVar6 + -1;
          pwVar5 = pwVar5 + -1;
          wVar3 = (word)((uint)param_5 >> 0x10);
          sVar4 = (sword)param_5 + -1;
          param_5 = CONCAT22(wVar3,sVar4);
        } while (sVar4 != -1);
        param_5 = (uint)wVar3 * 0x10000 + -1;
      } while (wVar3 != 0);
    }
  }
  return uVar2;
}
