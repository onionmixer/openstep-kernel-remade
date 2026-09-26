
undefined4 sub_409D618(void)

{
  byte bVar1;
  int unaff_A6;
  
  bVar1 = *(byte *)(unaff_A6 + -0xe0) & 0x60;
  if (((bVar1 != 0x40) && (bVar1 != 0x60)) && (bVar1 != 0x20)) {
    return 0;
  }
  return 0xffffffff;
}
