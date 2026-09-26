
sword denorm(void)

{
  int in_D0;
  sword sVar1;
  char extraout_D1b;
  sword sVar2;
  char extraout_D1b_00;
  char extraout_D1b_01;
  char cVar3;
  byte *in_A0;
  int unaff_A6;
  
  if ((*in_A0 & 0x40) != 0) {
    *in_A0 = *in_A0 | 0x80;
  }
  if ((char)in_D0 == '\0') {
    sVar1 = dnrm_lp();
    cVar3 = extraout_D1b;
  }
  else if (in_D0 == 1) {
    sVar2 = 0x3f81;
    sVar1 = -*(sword *)in_A0 + 0x3f81;
    if (-1 < (sword)(-*(sword *)in_A0 + 0x3f3e)) goto loc_409EA20;
    sVar1 = dnrm_lp();
    cVar3 = extraout_D1b_01;
  }
  else {
    sVar2 = 0x3c01;
    sVar1 = -*(sword *)in_A0 + 0x3c01;
    if (-1 < (sword)(-*(sword *)in_A0 + 0x3bbe)) {
loc_409EA20:
      if ((*(int *)(in_A0 + 4) != 0) || (*(int *)(in_A0 + 8) != 0)) {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x208;
        sVar1 = 0;
      }
      *(sword *)in_A0 = sVar2;
      in_A0[4] = 0;
      in_A0[5] = 0;
      in_A0[6] = 0;
      in_A0[7] = 0;
      in_A0[8] = 0;
      in_A0[9] = 0;
      in_A0[10] = 0;
      in_A0[0xb] = 0;
      return sVar1;
    }
    sVar1 = dnrm_lp();
    cVar3 = extraout_D1b_00;
  }
  if (cVar3 != '\0') {
    *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x208;
  }
  return sVar1;
}

