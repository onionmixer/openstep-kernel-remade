
uint _checksum_16(word *param_1,int param_2)

{
  word wVar1;
  sword sVar2;
  uint uVar3;
  word *pwVar4;
  
  uVar3 = 0;
  param_2 = param_2 + -1;
  if (param_2 != -1) {
    do {
      do {
        pwVar4 = param_1 + 1;
        uVar3 = *param_1 + uVar3;
        wVar1 = (word)((uint)param_2 >> 0x10);
        sVar2 = (sword)param_2 + -1;
        param_2 = CONCAT22(wVar1,sVar2);
        param_1 = pwVar4;
      } while (sVar2 != -1);
      param_2 = (uint)wVar1 * 0x10000 + -1;
    } while (wVar1 != 0);
  }
  uVar3 = (uVar3 & 0xffff) + (uVar3 >> 0x10);
  if (0xffff < uVar3) {
    uVar3 = uVar3 - 0xffff;
  }
  return uVar3 & 0xffff;
}

