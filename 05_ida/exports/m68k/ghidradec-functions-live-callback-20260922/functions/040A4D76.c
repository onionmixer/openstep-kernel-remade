
void sub_40A4D76(void)

{
  byte bVar1;
  sword sVar2;
  byte *pbVar3;
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) == 0) {
    pbVar3 = (byte *)(unaff_A6 + -0xcc);
  }
  else {
    pbVar3 = (byte *)(unaff_A6 + -0x10c);
  }
  bVar1 = *pbVar3;
  *pbVar3 = bVar1 & 0x7f;
  pbVar3[2] = -((bVar1 & 0x80) != 0);
  sVar2 = g_opcls();
  if (sVar2 == 3) {
    *(undefined *)(unaff_A6 + -0x54) = *(undefined *)(unaff_A6 + -0x7c);
    ovf_r_x3();
    *(undefined *)(unaff_A6 + -0x7c) = *(undefined *)(unaff_A6 + -0x54);
    store();
    return;
  }
  ovf_r_x2();
  store();
  return;
}

