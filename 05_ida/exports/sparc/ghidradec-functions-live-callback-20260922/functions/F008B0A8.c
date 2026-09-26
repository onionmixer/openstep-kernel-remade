
undefined8 sub_F008B0A8(int param_1,uint param_2,undefined4 *param_3)

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
  param_2 = param_2 >> ((byte)_page_shift & 0x1f);
  if (param_2 < *(uint *)(param_1 + 0x10)) {
    if (*(uint *)(param_1 + 0x10) * 4 < 0x41) {
      param_2 = param_2 * 4;
      if (*(char *)(*(int *)(param_1 + 8) + param_2) == '\0') goto loc_F008B120;
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + param_2);
    }
    else {
      iVar1 = *(int *)(*(int *)(param_1 + 8) + (param_2 >> 4) * 4);
      if (iVar1 == 0) goto loc_F008B120;
      param_2 = (param_2 & 0xf) * 4;
      uVar2 = 0;
      if (*(char *)(iVar1 + param_2) == '\0') goto locret_F008B130;
      uVar2 = *(undefined4 *)(iVar1 + param_2);
    }
    *param_3 = uVar2;
    uVar2 = 1;
  }
  else {
loc_F008B120:
    uVar2 = 0;
  }
locret_F008B130:
  return CONCAT44(param_2,uVar2);
}

