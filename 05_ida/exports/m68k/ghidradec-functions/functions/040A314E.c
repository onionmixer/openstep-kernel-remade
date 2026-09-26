
uint sto_cos(void)

{
  uint uVar1;
  byte bVar2;
  int unaff_A6;
  unkbyte10 in_FP1;
  undefined4 uStack_c;
  
  uVar1 = (*(uint *)(unaff_A6 + -0xe4) & 0x7ffff) >> 0x10;
  bVar2 = (byte)((*(uint *)(unaff_A6 + -0xe4) << 0xd) >> 0x1d);
  if (3 < bVar2) {
    uVar1 = 1 << (7 - uVar1 & 0x1f);
    uStack_c = (undefined4)((unkuint10)in_FP1 >> 0x30);
    fmovem(uStack_c,uVar1);
    return uVar1;
  }
  if (bVar2 == 0) {
    *(unkbyte10 *)(unaff_A6 + -0xb0) = in_FP1;
    return uVar1;
  }
  if (bVar2 == 1) {
    *(unkbyte10 *)(unaff_A6 + -0xa4) = in_FP1;
    return uVar1;
  }
  if (bVar2 != 2) {
    *(unkbyte10 *)(unaff_A6 + -0x8c) = in_FP1;
    return uVar1;
  }
  *(unkbyte10 *)(unaff_A6 + -0x98) = in_FP1;
  return uVar1;
}
