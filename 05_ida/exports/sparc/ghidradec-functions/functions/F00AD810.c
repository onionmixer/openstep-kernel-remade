
/* WARNING: Removing unreachable block (ram,0xf00ada24) */
/* WARNING: Removing unreachable block (ram,0xf00ad9d8) */
/* WARNING: Removing unreachable block (ram,0xf00ad9a4) */
/* WARNING: Removing unreachable block (ram,0xf00ad938) */
/* WARNING: Removing unreachable block (ram,0xf00ad8f0) */
/* WARNING: Removing unreachable block (ram,0xf00ad92c) */
/* WARNING: Removing unreachable block (ram,0xf00ad970) */
/* WARNING: Removing unreachable block (ram,0xf00ad9bc) */
/* WARNING: Removing unreachable block (ram,0xf00ada18) */
/* WARNING: Removing unreachable block (ram,0xf00ada4c) */
/* WARNING: Removing unreachable block (ram,0xf00ad8a4) */

undefined8 sub_F00AD810(uint *param_1,int *param_2,uint *param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
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
    uVar4 = *param_3 & 0x80000000;
    goto loc_F00ADAB0;
  case :
    _fpu_rightshift(param_2,0x59);
    iVar1 = param_2[2];
    param_2[2] = iVar1 + 0x7f;
    if (iVar1 + 0x7f < 1) {
      *param_3 = *param_3 & 0x807fffff;
      _fpu_rightshift(param_2,1 - param_2[2]);
      sub_F00AD5F8(param_1,param_2);
      param_2 = (int *)param_2[6];
      if (param_2 == (int *)0x800000) {
        *param_3 = *param_3 & 0x80000000 | 0x800000;
        _fpu_set_exception(param_1,0);
        uVar4 = param_1[3];
      }
      else {
        *param_3 = *param_3 & 0xff800000 | (uint)param_2 & 0x7fffff;
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
    if (param_2[6] == 0x1000000) {
      param_2[6] = 0x800000;
      param_2[2] = param_2[2] + 1;
      uVar4 = param_2[2];
    }
    else {
      uVar4 = param_2[2];
    }
    if (0xfe < (int)uVar4) {
      _fpu_set_exception(param_1,3);
      _fpu_set_exception(param_1,0);
      if ((*param_1 & 8) == 0) {
        iVar1 = *param_2;
      }
      else {
        param_1[3] = param_1[3] & 0xfffffffe;
        iVar1 = *param_2;
      }
      puVar2 = param_1;
      sub_F00AD5B0(param_1,iVar1);
      uVar4 = *param_3;
      if (puVar2 == (uint *)0x0) {
        *param_3 = uVar4 & 0x807fffff | 0x7f7fffff;
        break;
      }
      goto loc_F00AD888;
    }
    uVar3 = *param_3;
    uVar4 = (uVar4 & 0xff) << 0x17;
    *param_3 = uVar3 & 0x807fffff | uVar4;
    uVar4 = uVar3 & 0x80000000 | uVar4 | param_2[6] & 0x7fffffU;
loc_F00ADAB0:
    *param_3 = uVar4;
    break;
  case :
    uVar4 = *param_3;
loc_F00AD888:
    *param_3 = uVar4 & 0xff800000 | 0x7f800000;
    break;
  case :
  case :
    _fpu_rightshift(param_2,0x59);
    uVar4 = *param_3;
    *param_3 = uVar4 | 0x7f800000;
    *param_3 = uVar4 & 0xff800000 | 0x7f800000 | param_2[6] & 0x3fffffU | 0x400000;
  }
  return CONCAT44(param_2,param_1);
}
