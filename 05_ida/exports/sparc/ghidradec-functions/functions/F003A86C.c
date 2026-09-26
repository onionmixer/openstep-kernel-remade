
/* WARNING: Removing unreachable block (ram,0xf003a94c) */
/* WARNING: Removing unreachable block (ram,0xf003a924) */
/* WARNING: Removing unreachable block (ram,0xf003a934) */
/* WARNING: Removing unreachable block (ram,0xf003a954) */
/* WARNING: Removing unreachable block (ram,0xf003a89c) */

undefined8 sub_F003A86C(undefined *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
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
  if ((*(char **)((int)param_1 + 0x20) == (char *)0x0) || (**(char **)((int)param_1 + 0x20) == '\0')
     ) {
    *param_2 = 0xd;
    goto locret_F003A95C;
  }
  puVar2 = (undefined4 *)param_1;
  sub_F003C020(param_1,param_3);
  if (puVar2 == (undefined4 *)0x0) {
    *param_2 = 0x46;
    goto locret_F003A95C;
  }
  puVar1 = (undefined4 *)((int)param_1 + 0x20);
  param_1 = DAT_f0133c00;
  puVar3 = puVar2;
  (**(code **)(puVar2[7] + 0x20))
            (puVar2,*puVar1,(undefined *)((int)register0x00000038 + -0x4c),
             *(undefined4 *)(_active_u + 0x1c),0,0);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = *(undefined4 **)((int)register0x00000038 + -0x4c);
    param_1 = (undefined *)((int)register0x00000038 + -0x48);
    (**(code **)(puVar3[7] + 0x14))(puVar3,param_1,*(undefined4 *)(_active_u + 0x1c));
    iVar4 = *(int *)((int)register0x00000038 + -0x4c);
    if (puVar3 == (undefined4 *)0x0) {
      _vattr_to_nattr(param_1,param_2 + 9);
      puVar3 = param_2 + 1;
      _makefh(puVar3,*(undefined4 *)((int)register0x00000038 + -0x4c),param_3);
      goto loc_F003A93C;
    }
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x4c) = 0;
loc_F003A93C:
    iVar4 = *(int *)((int)register0x00000038 + -0x4c);
  }
  *param_2 = puVar3;
  if (iVar4 != 0) {
    _vn_rele(iVar4);
  }
  _vn_rele(puVar2);
locret_F003A95C:
  return CONCAT44(param_2,param_1);
}

