
void satan(void)

{
  word wVar1;
  undefined auVar2 [12];
  uint uVar3;
  int iVar4;
  word wVar5;
  undefined (*in_A0) [12];
  int unaff_A6;
  
  auVar2 = *in_A0;
  wVar1 = *(word *)(*in_A0 + 4);
  wVar5 = (word)((uint)*(undefined4 *)*in_A0 >> 0x10);
  *(undefined (*) [12])(unaff_A6 + -0x74) = (undefined  [12])(float)auVar2;
  uVar3 = CONCAT22(wVar5,wVar1) & 0x7fffffff;
  if (uVar3 < 0x3ffb8000) {
    if (0x3fd77fff < uVar3) {
      *(undefined2 *)(unaff_A6 + -0x72) = 0;
      t_frcinx();
      return;
    }
    *(undefined2 *)(unaff_A6 + -0x72) = 0;
    t_frcinx();
    return;
  }
  if (uVar3 < 0x40030000) {
    *(undefined2 *)(unaff_A6 + -0x72) = 0;
    *(uint *)(unaff_A6 + -0x70) = *(uint *)(unaff_A6 + -0x70) & 0xf8000000;
    *(uint *)(unaff_A6 + -0x70) = *(uint *)(unaff_A6 + -0x70) | 0x4000000;
    *(undefined4 *)(unaff_A6 + -0x6c) = 0;
    iVar4 = (int)(((int)((wVar5 & 0x7fff) * 0x10000 + -0x3ffb0000) >> 1) + (wVar1 & 0x7800)) >> 7;
    *(undefined4 *)(unaff_A6 + -100) = *(undefined4 *)(dword_409EE60 + iVar4);
    *(undefined4 *)(unaff_A6 + -0x60) = *(undefined4 *)(dword_409EE60 + iVar4 + 4);
    *(undefined4 *)(unaff_A6 + -0x5c) = *(undefined4 *)(dword_409EE60 + iVar4 + 8);
    *(uint *)(unaff_A6 + -100) =
         *(uint *)(unaff_A6 + -0x74) & 0x80000000 | *(uint *)(unaff_A6 + -100);
    t_frcinx();
    return;
  }
  if (uVar3 < 0x40638001) {
    *(undefined (*) [12])(unaff_A6 + -0x74) = (undefined  [12])(-1.0 / (float)auVar2);
    if (((*in_A0)[0] & 0x80) != 0) {
      t_frcinx();
      return;
    }
    t_frcinx();
    return;
  }
  if (((*in_A0)[0] & 0x80) != 0) {
    t_frcinx();
    return;
  }
  t_frcinx();
  return;
}

