
float10 calc_m(void)

{
  int iVar1;
  sword sVar2;
  uint uVar3;
  byte *in_A0;
  float10 fVar4;
  
  iVar1 = 1;
  fVar4 = (float10)0.0 + (float10)(byte)((uint)(*(int *)in_A0 << 0x1c) >> 0x1c);
  do {
    uVar3 = 0;
    sVar2 = 7;
    do {
      fVar4 = fVar4 * (float10)10.0 +
              (float10)(byte)((uint)(*(int *)(in_A0 + iVar1 * 4) << uVar3) >> 0x1c);
      uVar3 = (uint)(byte)((char)uVar3 + 4);
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  if ((*in_A0 & 0x80) != 0) {
    fVar4 = -fVar4;
  }
  return fVar4;
}
