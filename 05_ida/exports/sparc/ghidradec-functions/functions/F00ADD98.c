
/* WARNING: Removing unreachable block (ram,0xf00adf3c) */
/* WARNING: Removing unreachable block (ram,0xf00adef4) */
/* WARNING: Removing unreachable block (ram,0xf00adec4) */
/* WARNING: Removing unreachable block (ram,0xf00ade78) */
/* WARNING: Removing unreachable block (ram,0xf00adedc) */
/* WARNING: Removing unreachable block (ram,0xf00adf30) */
/* WARNING: Removing unreachable block (ram,0xf00adf64) */
/* WARNING: Removing unreachable block (ram,0xf00adf10) */
/* WARNING: Removing unreachable block (ram,0xf00ade6c) */

undefined8
sub_F00ADD98(uint *param_1,int *param_2,uint *param_3,int *param_4,int *param_5,int *param_6)

{
  uint uVar1;
  word wVar4;
  uint *puVar2;
  int iVar3;
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
    uVar1 = *param_3 & 0x8000ffff;
    break;
  case :
    iVar3 = param_2[2] + 0x3fff;
    param_2[2] = iVar3;
    if (iVar3 < 1) {
      _fpu_rightshift(param_2,1 - iVar3);
      sub_F00AD5F8(param_1,param_2);
      if ((uint)param_2[3] < 0x10000) {
        *param_3 = *param_3 & 0x8000ffff;
      }
      else {
        *param_3 = *param_3 & 0x8000ffff | 0x10000;
        _fpu_set_exception(param_1,0);
      }
      if ((param_1[3] & 1) != 0) {
        _fpu_set_exception(param_1,2);
      }
      if ((*param_1 & 4) != 0) {
        _fpu_set_exception(param_1,2);
        param_1[3] = param_1[3] & 0xfffffffe;
      }
loc_F00ADFC8:
      wVar4 = (word)param_2[3];
      goto loc_F00ADFCC;
    }
    sub_F00AD5F8(param_1,param_2);
    if (param_2[2] < 0x7fff) {
      *param_3 = *param_3 & 0x8000ffff | (param_2[2] & 0x7fffU) << 0x10;
      goto loc_F00ADFC8;
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
    puVar2 = param_1;
    sub_F00AD5B0(param_1,iVar3);
    if (puVar2 != (uint *)0x0) {
      uVar1 = *param_3;
      goto loc_F00ADE08;
    }
    *param_3 = *param_3 & 0x8000ffff | 0x7ffe0000;
    *(undefined2 *)((int)param_3 + 2) = 0xffff;
    iVar3 = -1;
    *param_4 = -1;
    *param_5 = -1;
    goto loc_F00ADFE4;
  case :
    uVar1 = *param_3;
loc_F00ADE08:
    uVar1 = uVar1 | 0x7fff0000;
    break;
  :
    goto def_F00ADDD4;
  case :
  case :
    *param_3 = *param_3 | 0x7fff0000;
    wVar4 = (word)param_2[3] | 0x8000;
loc_F00ADFCC:
    *(word *)((int)param_3 + 2) = wVar4;
    *param_4 = param_2[4];
    *param_5 = param_2[5];
    iVar3 = param_2[6];
loc_F00ADFE4:
    *param_6 = iVar3;
    goto def_F00ADDD4;
  }
  *param_3 = uVar1;
  *(undefined2 *)((int)param_3 + 2) = 0;
  *param_5 = 0;
  *param_4 = 0;
  *param_6 = 0;
def_F00ADDD4:
  return CONCAT44(param_2,param_1);
}
