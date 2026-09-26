
/* WARNING: Removing unreachable block (ram,0xf00bedec) */

undefined8 sub_F00BED74(int param_1,sword *param_2)

{
  sword sVar1;
  sword sVar2;
  sword sVar3;
  undefined4 uVar4;
  int *piVar5;
  word wVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  sVar1 = *param_2;
  piVar5 = *(int **)(param_1 + 0x1c);
  *(sword *)((int)register0x00000038 + -0x10) = sVar1;
  sVar2 = param_2[1];
  *(sword *)((int)register0x00000038 + -0xe) = sVar2;
  sVar3 = param_2[2];
  *(sword *)((int)register0x00000038 + -0xc) = sVar3;
  *(sword *)((int)register0x00000038 + -10) = param_2[3];
  wVar6 = sVar1 + (sword)(*piVar5 - 0x46cU >> 1);
  *(word *)((int)register0x00000038 + -0x10) = wVar6;
  uVar4 = 0;
  *(sword *)((int)register0x00000038 + -0xe) = sVar2 + (sword)(piVar5[1] - 0x340U >> 1);
  *(word *)((int)register0x00000038 + -0x10) = wVar6 & 0xfffc;
  *(word *)((int)register0x00000038 + -0xc) = sVar3 + 3U & 0xfffc;
  _sparcfbDrawRect(0,(undefined *)((int)register0x00000038 + -0x10),2,*(undefined4 *)(param_2 + 4));
  return CONCAT44(param_2,uVar4);
}

