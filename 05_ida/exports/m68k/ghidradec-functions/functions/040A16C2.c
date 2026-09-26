
void slognd(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_A0;
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x54) = 0xffffff9c;
  iVar2 = *(int *)(in_A0 + 4);
  uVar1 = *(uint *)(in_A0 + 8);
  if (iVar2 == 0) {
    iVar2 = (uint)(uVar1 != 0) * LZCOUNT(uVar1);
    *(undefined4 *)(unaff_A6 + -0x74) = 0;
    *(uint *)(unaff_A6 + -0x70) = uVar1 << iVar2;
    *(undefined4 *)(unaff_A6 + -0x6c) = 0;
    *(int *)(unaff_A6 + -0x54) = -(iVar2 + 0x20);
    func_0x040a1764();
    return;
  }
  iVar3 = (uint)(iVar2 != 0) * LZCOUNT(iVar2);
  *(undefined4 *)(unaff_A6 + -0x74) = 0;
  *(uint *)(unaff_A6 + -0x70) = uVar1 >> (0x20U - iVar3 & 0x3f) | iVar2 << iVar3;
  *(uint *)(unaff_A6 + -0x6c) = uVar1 << iVar3;
  *(int *)(unaff_A6 + -0x54) = -iVar3;
  func_0x040a1764();
  return;
}
