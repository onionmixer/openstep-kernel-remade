
undefined4 g_dfmtou(void)

{
  byte bVar1;
  int unaff_A6;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) != 0) {
    return 0;
  }
  bVar1 = (byte)((uint)(*(int *)(unaff_A6 + -0xe4) << 3) >> 0x1d);
  if (bVar1 == 1) {
    return 1;
  }
  if (bVar1 == 5) {
    return 2;
  }
  return 0;
}

