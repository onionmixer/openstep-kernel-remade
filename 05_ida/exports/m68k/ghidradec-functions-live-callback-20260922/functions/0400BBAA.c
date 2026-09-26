
void sub_400BBAA(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5,
                int param_6)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  char acStack_10 [12];
  
  if ((param_2 == 10) && ((int)param_1 < 0)) {
    sub_400BDAC(0x2d,param_3,param_4);
    param_1 = -param_1;
  }
  pcVar2 = acStack_10;
  do {
    uVar1 = param_1 % param_2;
    param_1 = param_1 / param_2;
    pcVar3 = pcVar2 + 1;
    *pcVar2 = a0123456789abcd[uVar1];
    pcVar2 = pcVar3;
  } while (param_1 != 0);
  if (param_6 != 0) {
    for (param_6 = param_6 - ((int)pcVar3 - (int)acStack_10); 0 < param_6; param_6 = param_6 + -1) {
      if (param_5 == 0) {
        uVar4 = 0x20;
      }
      else {
        uVar4 = 0x30;
      }
      sub_400BDAC(uVar4,param_3,param_4);
    }
  }
  do {
    pcVar3 = pcVar3 + -1;
    sub_400BDAC((int)*pcVar3,param_3,param_4);
  } while (acStack_10 < pcVar3);
  return;
}

