
/* WARNING: Removing unreachable block (ram,0xf00adcf4) */
/* WARNING: Removing unreachable block (ram,0xf00adca8) */
/* WARNING: Removing unreachable block (ram,0xf00adc74) */
/* WARNING: Removing unreachable block (ram,0xf00adbf0) */
/* WARNING: Removing unreachable block (ram,0xf00adba8) */
/* WARNING: Removing unreachable block (ram,0xf00adbe4) */
/* WARNING: Removing unreachable block (ram,0xf00adc2c) */
/* WARNING: Removing unreachable block (ram,0xf00adc8c) */
/* WARNING: Removing unreachable block (ram,0xf00adce8) */
/* WARNING: Removing unreachable block (ram,0xf00add1c) */
/* WARNING: Removing unreachable block (ram,0xf00adb5c) */

undefined8 sub_F00ADABC(uint *param_1,int *param_2,uint *param_3,int *param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
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
  *param_3 = *param_3 & 0x7fffffff | *param_2 << 0x1f;
  switch(param_2[1]) {
  case :
    *param_3 = *param_3 & 0x80000000;
    *param_4 = 0;
    break;
  case :
    _fpu_rightshift(param_2,0x3c);
    iVar3 = param_2[2];
    param_2[2] = iVar3 + 0x3ff;
    if (iVar3 + 0x3ff < 1) {
      *param_3 = *param_3 & 0x800fffff;
      _fpu_rightshift(param_2,1 - param_2[2]);
      sub_F00AD5F8(param_1,param_2);
      if (param_2[5] == 0x100000) {
        *param_3 = *param_3 & 0x80000000 | 0x100000;
        *param_4 = 0;
        _fpu_set_exception(param_1,0);
        uVar4 = param_1[3];
      }
      else {
        uVar4 = *param_3;
        *param_3 = uVar4 & 0x800fffff;
        *param_3 = uVar4 & 0x80000000 | param_2[5] & 0xfffffU;
        *param_4 = param_2[6];
        uVar4 = param_1[3];
      }
      if ((uVar4 & 1) != 0) {
        _fpu_set_exception(param_1,2);
      }
      if ((*param_1 & 4) != 0) {
        _fpu_set_exception(param_1,2);
        param_1[3] = param_1[3] & 0xfffffffe;
      }
      break;
    }
    sub_F00AD5F8(param_1,param_2);
    if (param_2[5] == 0x200000) {
      param_2[5] = 0x100000;
      param_2[2] = param_2[2] + 1;
      uVar4 = param_2[2];
    }
    else {
      uVar4 = param_2[2];
    }
    if ((int)uVar4 < 0x7ff) {
      uVar2 = *param_3;
      uVar4 = (uVar4 & 0x7ff) << 0x14;
      *param_3 = uVar2 & 0x800fffff | uVar4;
      *param_3 = uVar2 & 0x80000000 | uVar4 | param_2[5] & 0xfffffU;
      goto loc_F00ADD88;
    }
    _fpu_set_exception(param_1,3);
    _fpu_set_exception(param_1,0);
    if ((*param_1 & 8) == 0) {
      iVar3 = *param_2;
    }
    else {
      param_1[3] = param_1[3] & 0xfffffffe;
      iVar3 = *param_2;
    }
    puVar1 = param_1;
    sub_F00AD5B0(param_1,iVar3);
    uVar4 = *param_3;
    if (puVar1 != (uint *)0x0) goto loc_F00ADB3C;
    *param_3 = uVar4 & 0x800fffff | 0x7fefffff;
    iVar3 = -1;
    goto loc_F00ADD8C;
  case :
    uVar4 = *param_3;
loc_F00ADB3C:
    *param_3 = uVar4 & 0xfff00000 | 0x7ff00000;
    *param_4 = 0;
    break;
  case :
  case :
    _fpu_rightshift(param_2,0x3c);
    uVar4 = *param_3;
    *param_3 = uVar4 | 0x7ff00000;
    *param_3 = uVar4 & 0xfff00000 | 0x7ff00000 | param_2[5] & 0x7ffffU | 0x80000;
loc_F00ADD88:
    iVar3 = param_2[6];
loc_F00ADD8C:
    *param_4 = iVar3;
  }
  return CONCAT44(param_2,param_1);
}

