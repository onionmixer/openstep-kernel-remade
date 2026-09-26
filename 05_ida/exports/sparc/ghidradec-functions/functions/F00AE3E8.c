
/* WARNING: Removing unreachable block (ram,0xf00ae450) */
/* WARNING: Removing unreachable block (ram,0xf00ae4a0) */

undefined8 _unpackdouble(undefined4 param_1,uint *param_2,uint *param_3,uint param_4)

{
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar2;
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
  uVar2 = *param_3;
  param_2[7] = 0;
  param_2[8] = 0;
  *param_2 = uVar2 >> 0x1f;
  param_2[4] = param_4;
  param_2[5] = 0;
  uVar1 = uVar2 & 0xfffff;
  param_2[6] = 0;
  if ((uVar2 & 0x7ff00000) == 0) {
    if (uVar1 == 0) {
      if (param_4 == 0) {
        param_2[1] = 0;
        goto locret_F00AE4FC;
      }
      param_2[1] = 1;
    }
    else {
      param_2[1] = 1;
    }
    param_2[2] = 0xfffffbfe;
    param_2[3] = uVar1;
    _fpu_normalize(param_2);
  }
  else {
    if ((uVar2 & 0x7ff00000) == 0x7ff00000) {
      if (uVar1 == 0 && param_4 == 0) {
        param_2[1] = 2;
        goto locret_F00AE4FC;
      }
      if ((uVar2 & 0x80000) == 0) {
        param_2[1] = 5;
        _fpu_set_exception(param_1,4);
      }
      else {
        param_2[1] = 4;
      }
      param_2[3] = uVar1 >> 4 | 0x18000;
    }
    else {
      param_2[2] = (uVar2 >> 0x14 & 0x7ff) - 0x3ff;
      param_2[1] = 1;
      param_2[3] = uVar1 >> 4 | 0x10000;
      uVar1 = uVar2;
    }
    param_2[4] = uVar1 << 0x1c | param_4 >> 4;
    param_2[5] = param_4 << 0x1c;
  }
locret_F00AE4FC:
  return CONCAT44(param_2,param_1);
}
