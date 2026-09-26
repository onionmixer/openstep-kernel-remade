
unkbyte10 t_unfl(void)

{
  byte bVar1;
  uint uVar2;
  char *in_A0;
  byte *extraout_A0;
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x74) = 0;
  *(undefined4 *)(unaff_A6 + -0x70) = 0;
  *(undefined4 *)(unaff_A6 + -0x6c) = 0;
  if (*in_A0 < '\0') {
    *(byte *)(unaff_A6 + -0x74) = *(byte *)(unaff_A6 + -0x74) | 0x80;
  }
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xa28;
  if ((*(byte *)(unaff_A6 + -0x7e) & 8) != 0) {
    *(uint *)(unaff_A6 + -0xe8) = (*(uint *)(unaff_A6 + -0xe8) & 0x7ffffff) >> 0x18;
    *(byte *)(unaff_A6 + -0xdf) = *(byte *)(unaff_A6 + -0xdf) | 0x10;
    *(byte *)(unaff_A6 + -0xe7) = *(byte *)(unaff_A6 + -0xe7) | 0x80;
    *(byte *)(unaff_A6 + -0xdc) = *(byte *)(unaff_A6 + -0xdc) & 0xfb;
  }
  bVar1 = *(byte *)(unaff_A6 + -0x74);
  *(byte *)(unaff_A6 + -0x74) = bVar1 & 0x7f;
  *(char *)(unaff_A6 + -0x72) = -((bVar1 & 0x80) != 0);
  unf_sub();
  uVar2 = *(uint *)(extraout_A0 + 2) >> 0x18;
  *(uint *)(extraout_A0 + 2) = uVar2;
  if (uVar2 != 0) {
    *extraout_A0 = *extraout_A0 | 0x80;
    *(byte *)(unaff_A6 + -0x74) = *(byte *)(unaff_A6 + -0x74) | 0x80;
  }
  return *(unkbyte10 *)extraout_A0;
}

