
/* WARNING: Removing unreachable block (ram,0xf00ad784) */
/* WARNING: Removing unreachable block (ram,0xf00ad800) */
/* WARNING: Removing unreachable block (ram,0xf00ad778) */

undefined8 sub_F00AD718(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
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
  switch(param_2[1]) {
  case :
    *param_3 = 0;
    goto def_F00AD738;
  case :
    if (param_2[2] < 0x20) {
      _fpu_rightshift(param_2,0x70 - param_2[2]);
      sub_F00AD5F8(param_1,param_2);
      uVar2 = param_2[6];
      if ((int)uVar2 < 0) {
        if (*param_2 == 0) goto loc_F00AD7D4;
        if (0x80000000 < uVar2) {
          iVar1 = *param_2;
          break;
        }
        *param_3 = uVar2;
      }
      else {
        *param_3 = uVar2;
      }
      if (*param_2 != 0) {
        *param_3 = -uVar2;
      }
      goto def_F00AD738;
    }
    iVar1 = *param_2;
    break;
  case :
  case :
  case :
loc_F00AD7D4:
    iVar1 = *param_2;
    break;
  :
    goto def_F00AD738;
  }
  uVar2 = 0x80000000;
  if (iVar1 == 0) {
    uVar2 = 0x7fffffff;
  }
  *param_3 = uVar2;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffffe;
  _fpu_set_exception(param_1,4);
def_F00AD738:
  return CONCAT44(param_2,param_1);
}

