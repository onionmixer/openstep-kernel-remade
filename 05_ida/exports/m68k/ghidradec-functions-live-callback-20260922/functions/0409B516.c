
void calc_e(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  sword sVar4;
  uint uVar5;
  int unaff_A6;
  
  sVar4 = 2;
  uVar5 = 4;
  puVar1 = (uint *)(unaff_A6 + -0x74);
  *puVar1 = *(uint *)(unaff_A6 + -0xcc);
  *(undefined4 *)(unaff_A6 + -0x70) = *(undefined4 *)(unaff_A6 + -200);
  *(undefined4 *)(unaff_A6 + -0x6c) = *(undefined4 *)(unaff_A6 + -0xc4);
  iVar2 = 0;
  do {
    iVar2 = ((*puVar1 << uVar5) >> 0x1c) + iVar2 * 10;
    uVar5 = (uint)(byte)((char)uVar5 + 4);
    sVar4 = sVar4 + -1;
  } while (sVar4 != -1);
  if ((*puVar1 & 0x40000000) != 0) {
    iVar2 = -iVar2;
  }
  iVar3 = iVar2 + -0x10;
  if (iVar2 < 0x10) {
    iVar3 = -iVar3;
    *puVar1 = *puVar1 | 0x40000000;
  }
  *(int *)(unaff_A6 + -0x54) = iVar3;
  return;
}

