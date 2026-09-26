
undefined4 t_resdnrm(void)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *in_A0;
  byte *extraout_A0;
  byte *pbVar4;
  byte *extraout_A0_00;
  int unaff_A6;
  
  *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x800;
  if ((*(byte *)(unaff_A6 + -0x7e) & 8) != 0) {
    *(undefined4 *)(unaff_A6 + -0x74) = *(undefined4 *)in_A0;
    *(undefined4 *)(unaff_A6 + -0x70) = *(undefined4 *)(in_A0 + 4);
    *(undefined4 *)(unaff_A6 + -0x6c) = *(undefined4 *)(in_A0 + 8);
    pbVar4 = (byte *)(unaff_A6 + -0x74);
    bVar1 = *pbVar4;
    *pbVar4 = bVar1 & 0x7f;
    *(char *)(unaff_A6 + -0x72) = -((bVar1 & 0x80) != 0);
    if (*(sword *)pbVar4 != 0) {
      nrm_set();
      pbVar4 = extraout_A0;
    }
    *pbVar4 = *pbVar4 & 0x7f;
    uVar2 = *(uint *)(pbVar4 + 2) >> 0x18;
    *(uint *)(pbVar4 + 2) = uVar2;
    if (uVar2 != 0) {
      *pbVar4 = *pbVar4 | 0x80;
    }
    *(uint *)(unaff_A6 + -0xe8) = (*(uint *)(unaff_A6 + -0xe8) & 0x7ffffff) >> 0x18;
    *(byte *)(unaff_A6 + -0xdf) = *(byte *)(unaff_A6 + -0xdf) | 0x10;
    *(byte *)(unaff_A6 + -0xe7) = *(byte *)(unaff_A6 + -0xe7) & 0x7f;
    *(byte *)(unaff_A6 + -0xdc) = *(byte *)(unaff_A6 + -0xdc) & 0xfb;
  }
  if (*(uint *)(unaff_A6 + -0x7d) >> 0x1e == 0) {
    uVar3 = 0;
    if ((*in_A0 & 0x80) != 0) {
      *(byte *)(unaff_A6 + -0x7c) = *(byte *)(unaff_A6 + -0x7c) | 8;
    }
  }
  else {
    bVar1 = *in_A0;
    *in_A0 = bVar1 & 0x7f;
    in_A0[2] = -((bVar1 & 0x80) != 0);
    uVar3 = unf_sub();
    uVar2 = *(uint *)(extraout_A0_00 + 2) >> 0x18;
    *(uint *)(extraout_A0_00 + 2) = uVar2;
    if (uVar2 != 0) {
      *extraout_A0_00 = *extraout_A0_00 | 0x80;
    }
  }
  return uVar3;
}
