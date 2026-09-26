
void store(void)

{
  word wVar1;
  byte bVar2;
  char cVar4;
  int iVar3;
  byte *in_A0;
  byte *extraout_A0;
  int unaff_A6;
  unkbyte10 in_FP0;
  unkbyte10 extraout_FP0;
  unkbyte10 in_FP1;
  unkbyte10 unaff_FP2;
  unkbyte10 unaff_FP3;
  
  if ((*(byte *)(unaff_A6 + -0xdc) & 2) == 0) {
    cVar4 = g_opcls();
    if (cVar4 == '\x03') {
      iVar3 = g_dfmtou();
      if (iVar3 == 0) {
        return;
      }
      if (iVar3 != 1) {
        return;
      }
      return;
    }
    wVar1 = (word)((uint)*(undefined4 *)(unaff_A6 + -0xe4) >> 0x10);
    in_A0 = extraout_A0;
    in_FP0 = extraout_FP0;
  }
  else {
    wVar1 = (word)((uint)*(undefined4 *)(unaff_A6 + -0xf0) >> 0x10);
  }
  bVar2 = *(byte *)((int)&dword_40A501C + (int)(sword)((wVar1 & 0x3ff) >> 7));
  if (in_A0[2] != 0) {
    *in_A0 = *in_A0 | 0x80;
  }
  fmovem(*(undefined4 *)in_A0,(uint)bVar2);
  if (bVar2 == 0x80) {
    *(unkbyte10 *)(unaff_A6 + -0xb0) = in_FP0;
    return;
  }
  if (bVar2 == 0x40) {
    *(unkbyte10 *)(unaff_A6 + -0xa4) = in_FP1;
    return;
  }
  if (bVar2 == 0x20) {
    *(unkbyte10 *)(unaff_A6 + -0x98) = unaff_FP2;
    return;
  }
  if (bVar2 == 0x10) {
    *(unkbyte10 *)(unaff_A6 + -0x8c) = unaff_FP3;
    return;
  }
  return;
}

