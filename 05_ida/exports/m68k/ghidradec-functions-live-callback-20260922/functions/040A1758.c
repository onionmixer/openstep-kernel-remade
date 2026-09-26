
void slogn(void)

{
  int iVar1;
  undefined auVar2 [12];
  float fVar3;
  sword sVar4;
  undefined (*in_A0) [12];
  int unaff_A6;
  int iVar5;
  
  auVar2 = *in_A0;
  *(undefined4 *)(unaff_A6 + -0x54) = 0;
  iVar1 = *(int *)*in_A0;
  sVar4 = (sword)((uint)iVar1 >> 0x10);
  iVar5 = CONCAT22(sVar4,*(undefined2 *)(*in_A0 + 4));
  *(undefined4 *)(unaff_A6 + -0x74) = *(undefined4 *)*in_A0;
  *(undefined4 *)(unaff_A6 + -0x70) = *(undefined4 *)(*in_A0 + 4);
  *(undefined4 *)(unaff_A6 + -0x6c) = *(undefined4 *)(*in_A0 + 8);
  if (iVar1 < 0) {
    t_operr();
    return;
  }
  if (iVar5 < iRam3ffef07d || iRam3ffef081 < iVar5) {
    *(undefined4 *)(unaff_A6 + -0x74) = 0x3fff0000;
    *(undefined4 *)(unaff_A6 + -0x60) = *(undefined4 *)(unaff_A6 + -0x70);
    *(uint *)(unaff_A6 + -0x60) = *(uint *)(unaff_A6 + -0x60) & 0xfe000000;
    *(uint *)(unaff_A6 + -0x60) = *(uint *)(unaff_A6 + -0x60) | 0x1000000;
    *(undefined4 *)(unaff_A6 + -100) = 0x3fff0000;
    *(undefined4 *)(unaff_A6 + -0x5c) = 0;
    *(undefined (*) [12])(unaff_A6 + -0x40) =
         (undefined  [12])
         ((float10)(*(int *)(unaff_A6 + -0x54) + sVar4 + -0x3fff) * (float10)tbyte_40A0E32);
    t_frcinx();
    return;
  }
  fVar3 = (float)auVar2 - 1.0;
  *(undefined (*) [12])(unaff_A6 + -0x30) =
       (undefined  [12])((fVar3 + fVar3) / ((float)auVar2 + 1.0));
  t_frcinx();
  return;
}

