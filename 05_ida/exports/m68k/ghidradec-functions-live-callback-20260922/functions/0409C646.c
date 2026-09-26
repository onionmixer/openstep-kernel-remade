
void sub_409C646(void)

{
  byte bVar1;
  uint uVar2;
  byte *in_A0;
  byte *extraout_A0;
  byte *extraout_A0_00;
  byte *extraout_A0_01;
  byte *pbVar3;
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x54) = 0;
  bVar1 = *in_A0;
  *in_A0 = bVar1 & 0x7f;
  in_A0[2] = -((bVar1 & 0x80) != 0);
  if (*(char *)(unaff_A6 + 0xb) == ',') {
    sub_409C6F2();
    pbVar3 = extraout_A0;
  }
  else if ((*(byte *)(unaff_A6 + -0xe4) & 0x20) == 0) {
    sub_409C6D0();
    pbVar3 = extraout_A0_00;
  }
  else {
    sub_409C6B0();
    pbVar3 = extraout_A0_01;
  }
  if (*(sword *)pbVar3 < 0x4000) {
    *(byte *)(unaff_A6 + -0x54) = *(byte *)(unaff_A6 + -0x54) | 0x10;
  }
  uVar2 = *(uint *)(pbVar3 + 2) >> 0x18;
  *(uint *)(pbVar3 + 2) = uVar2;
  if (uVar2 != 0) {
    *pbVar3 = *pbVar3 | 0x80;
  }
  return;
}

