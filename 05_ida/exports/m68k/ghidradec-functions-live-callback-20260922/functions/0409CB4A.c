
unkbyte10 t_ovfl(void)

{
  uint uVar1;
  int unaff_A6;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1248;
  if ((*(byte *)(unaff_A6 + -0x7e) & 0x10) != 0) {
    *(undefined4 *)(unaff_A6 + -0x74) = 0;
    *(undefined4 *)(unaff_A6 + -0x70) = 0;
    *(undefined4 *)(unaff_A6 + -0x6c) = 0;
    *(uint *)(unaff_A6 + -0xe8) = (*(uint *)(unaff_A6 + -0xe8) & 0x7ffffff) >> 0x18;
    *(byte *)(unaff_A6 + -0xdf) = *(byte *)(unaff_A6 + -0xdf) & 0xef;
    *(byte *)(unaff_A6 + -0xe7) = *(byte *)(unaff_A6 + -0xe7) | 0x80;
    *(byte *)(unaff_A6 + -0xdc) = *(byte *)(unaff_A6 + -0xdc) & 0xfb;
  }
  ovf_r_k();
  uVar1 = *(uint *)(unaff_A6 + -0xca) >> 0x18;
  *(uint *)(unaff_A6 + -0xca) = uVar1;
  if (uVar1 != 0) {
    *(byte *)(unaff_A6 + -0xcc) = *(byte *)(unaff_A6 + -0xcc) | 0x80;
    *(byte *)(unaff_A6 + -0x74) = *(byte *)(unaff_A6 + -0x74) | 0x80;
  }
  return *(unkbyte10 *)(unaff_A6 + -0xcc);
}

