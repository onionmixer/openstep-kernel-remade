
/* WARNING: Removing unreachable block (ram,0xf00ae5a8) */
/* WARNING: Removing unreachable block (ram,0xf00ae600) */

undefined8
sub_F00AE504(undefined4 param_1,uint *param_2,uint *param_3,uint param_4,uint param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
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
  uVar1 = *param_3;
  param_2[7] = 0;
  param_2[8] = 0;
  *param_2 = uVar1 >> 0x1f;
  param_2[1] = 1;
  uVar3 = (uVar1 & 0x7fffffff) >> 0x10;
  param_2[2] = uVar3 - 0x3fff;
  uVar2 = uVar1 & 0xffff;
  param_2[3] = uVar2;
  if ((uVar1 & 0x7fff0000) != 0) {
    param_2[3] = uVar2 | 0x10000;
  }
  param_2[4] = param_4;
  param_2[5] = param_5;
  param_2[6] = param_6;
  if (uVar3 < 0x7fff) {
    if (((param_5 == 0 && param_4 == 0) && param_6 == 0) && param_2[3] == 0) {
      param_2[1] = 0;
    }
    else if ((uVar1 & 0x7fff0000) == 0) {
      _fpu_normalize(param_2);
      param_2[2] = param_2[2] + 1;
    }
  }
  else if (((uVar2 == 0 && param_5 == 0) && param_4 == 0) && param_6 == 0) {
    param_2[1] = 2;
  }
  else {
    if ((uVar1 & 0x8000) == 0) {
      param_2[1] = 5;
      _fpu_set_exception(param_1,4);
    }
    else {
      param_2[1] = 4;
    }
    param_2[3] = param_2[3] | 0x8000;
  }
  return CONCAT44(param_2,param_1);
}
