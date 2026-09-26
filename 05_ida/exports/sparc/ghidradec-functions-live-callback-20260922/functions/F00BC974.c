
/* WARNING: Removing unreachable block (ram,0xf00bca54) */
/* WARNING: Removing unreachable block (ram,0xf00bc9b4) */

undefined8 -[kmDevice drawRect:](int param_1,undefined4 param_2,word *param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  
  iVar1 = _sparcfbs;
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
  if ((*(int *)(param_1 + 0x114) == 3) || (*(int *)(param_1 + 0x114) != 2)) {
    uVar2 = 0x10;
  }
  else {
    if (_first_prettyboot._0_4_ == 0) {
      _sparcfbClearDisplay(0,0x666666);
      _first_prettyboot._0_4_ = 1;
    }
    *param_3 = *param_3 + (sword)((*(int *)(iVar1 + 0x28) + -0x46c) / 2);
    param_3[1] = param_3[1] + (sword)((*(int *)(iVar1 + 0x2c) + -0x340) / 2);
    *param_3 = *param_3 & 0xfffc;
    param_3[2] = param_3[2] + 3 & 0xfffc;
    *(word *)((int)register0x00000038 + -0x18) = *param_3;
    *(word *)((int)register0x00000038 + -0x16) = param_3[1];
    *(word *)((int)register0x00000038 + -0x14) = param_3[2];
    *(word *)((int)register0x00000038 + -0x12) = param_3[3];
    _sparcfbDrawRect(0,(undefined *)((int)register0x00000038 + -0x18),2,*(undefined4 *)(param_3 + 4)
                    );
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}

