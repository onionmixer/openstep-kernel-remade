
float10 smovcr(void)

{
  byte bVar3;
  uint uVar1;
  int iVar2;
  byte bVar4;
  code *pcVar5;
  float10 *extraout_A0;
  int unaff_A6;
  
  uVar1 = (*(uint *)(unaff_A6 + -0xe4) & 0x7fffff) >> 0x10;
  bVar3 = (byte)((*(uint *)(unaff_A6 + -0xe4) << 9) >> 0x19);
  bVar4 = (byte)((*(uint *)(unaff_A6 + -0x80) << 0x1a) >> 0x1e);
  if (bVar3 == 0) {
    if (bVar4 == 0) {
      pcVar5 = pirn;
    }
    else if (bVar4 == 3) {
      pcVar5 = pirp;
    }
    else {
      pcVar5 = pirzrm;
    }
  }
  else {
    if (bVar3 < 0xb) {
loc_40A1AD6:
      return (float10)0.0;
    }
    if (bVar3 < 0xf) {
      uVar1 = uVar1 - 0xb;
      if (bVar4 == 0) {
        pcVar5 = (code *)&smalrn;
      }
      else if (bVar4 == 3) {
        pcVar5 = (code *)&smalrp;
      }
      else {
        pcVar5 = (code *)&smalrzrm;
      }
      if ('\x02' < (char)uVar1) goto loc_40A1BEA;
    }
    else {
      if ((bVar3 < 0x30) || (0x3f < bVar3)) goto loc_40A1AD6;
      uVar1 = uVar1 - 0x30;
      if (bVar4 == 0) {
        pcVar5 = (code *)&bigrn;
      }
      else if (bVar4 == 3) {
        pcVar5 = (code *)&bigrp;
      }
      else {
        pcVar5 = (code *)&bigrzrm;
      }
      if (('\x01' < (char)uVar1) && ((char)uVar1 < '\b')) goto loc_40A1BEA;
    }
  }
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x208;
loc_40A1BEA:
  iVar2 = uVar1 * 0xc;
  *(uint *)(unaff_A6 + -0x54) = (*(uint *)(unaff_A6 + -0x80) & 0x3f) >> 4;
  if ((*(uint *)(unaff_A6 + -0x80) & 0xff) >> 6 != 0) {
    *(undefined4 *)(unaff_A6 + -0x74) = *(undefined4 *)(pcVar5 + iVar2);
    *(undefined4 *)(unaff_A6 + -0x70) = *(undefined4 *)(pcVar5 + iVar2 + 4);
    *(undefined4 *)(unaff_A6 + -0x6c) = *(undefined4 *)(pcVar5 + iVar2 + 8);
    *(char *)(unaff_A6 + -0x72) = -((*(byte *)(unaff_A6 + -0x74) & 0x80) != 0);
    round();
    uVar1 = *(uint *)((int)extraout_A0 + 2) >> 0x18;
    *(uint *)((int)extraout_A0 + 2) = uVar1;
    if (uVar1 != 0) {
      *(byte *)extraout_A0 = *(byte *)extraout_A0 | 0x80;
    }
    return *extraout_A0;
  }
  return *(float10 *)(pcVar5 + iVar2);
}
