
int sub_406AA0C(undefined4 param_1)

{
  int iVar1;
  sword sVar2;
  sword sVar3;
  
  sVar2 = sRam040c36ca;
  do {
    sVar2 = sVar2 + -1;
    if (sVar2 == -1) {
      return -1;
    }
    iVar1 = sVar2 * 0x28;
    sVar3 = (sword)((uint)param_1 >> 0x10);
  } while ((((sVar3 < *(sword *)(_evScreen + 0xc + iVar1)) ||
            (*(sword *)(_evScreen + 0xe + iVar1) <= sVar3)) ||
           ((sword)param_1 < *(sword *)(_evScreen + 0x10 + iVar1))) ||
          (*(sword *)(_evScreen + 0x12 + iVar1) <= (sword)param_1));
  return (int)sVar2;
}

