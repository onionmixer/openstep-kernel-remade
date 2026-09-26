
sword _oc_cksum(int *param_1,uint param_2,int param_3)

{
  sword sVar1;
  uint uVar2;
  word wVar3;
  int *piVar4;
  
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) != 0) {
      param_3 = (uint)*(word *)((int)param_1 + (param_2 - 2)) + param_3;
    }
  }
  else {
    if ((param_2 & 2) != 0) {
      param_3 = (uint)*(word *)((int)param_1 + (param_2 - 3)) + param_3;
    }
    param_3 = (uint)*(byte *)((int)param_1 + (param_2 - 1)) * 0x100 + param_3;
  }
  uVar2 = param_2 >> 6;
  piVar4 = param_1;
  switch(param_2 & 0x3c) {
  case :
    goto loc_4092918;
  case :
    goto loc_4092914;
  case :
    goto loc_4092910;
  case :
    goto loc_409290c;
  case :
    goto loc_4092908;
  case :
    goto loc_4092904;
  case :
    goto loc_4092900;
  case :
    goto loc_40928fc;
  case :
    goto loc_40928f8;
  case :
    goto loc_40928f4;
  case :
    goto loc_40928f0;
  case :
    goto loc_40928ec;
  case :
    goto loc_40928e8;
  case :
    goto loc_40928e4;
  case :
    goto loc_40928e0;
  }
  while (wVar3 = (sword)uVar2 - 1, uVar2 = (uint)wVar3, wVar3 != 0xffff) {
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_40928e0:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_40928e4:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_40928e8:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_40928ec:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_40928f0:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_40928f4:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_40928f8:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_40928fc:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_4092900:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_4092904:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_4092908:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_409290c:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_4092910:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
loc_4092914:
    param_1 = piVar4 + 1;
    param_3 = *piVar4 + param_3;
loc_4092918:
    piVar4 = param_1 + 1;
    param_3 = *param_1 + param_3;
  }
  wVar3 = (word)((uint)param_3 >> 0x10);
  sVar1 = wVar3 + (word)param_3;
  if (CARRY2(wVar3,(word)param_3)) {
    sVar1 = sVar1 + 1;
  }
  return sVar1;
}
