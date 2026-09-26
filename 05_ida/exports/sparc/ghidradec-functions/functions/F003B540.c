
/* WARNING: Removing unreachable block (ram,0xf003b614) */
/* WARNING: Removing unreachable block (ram,0xf003b5c0) */
/* WARNING: Removing unreachable block (ram,0xf003b584) */
/* WARNING: Removing unreachable block (ram,0xf003b638) */
/* WARNING: Removing unreachable block (ram,0xf003b644) */
/* WARNING: Removing unreachable block (ram,0xf003b570) */

undefined8 sub_F003B540(int param_1,int *param_2,uint *param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
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
  if ((*(char **)(param_1 + 0x20) == (char *)0x0) || (**(char **)(param_1 + 0x20) == '\0')) {
    *param_2 = 0xd;
    goto locret_F003B64C;
  }
  sub_F003BFCC(param_1 + 0x28,(undefined *)((int)register0x00000038 + -0x48));
  *(undefined4 *)((int)register0x00000038 + -0x48) = 5;
  iVar2 = param_1;
  sub_F003C020(param_1,param_3);
  if (iVar2 == 0) {
    *param_2 = 0x46;
    goto locret_F003B64C;
  }
  if ((*param_3 & 1) == 0) {
    if ((*param_3 & 2) == 0) {
      uVar4 = *(undefined4 *)(param_1 + 0x20);
    }
    else {
      iVar3 = *(int *)(param_4 + 0x1c) + 0x10;
      sub_F003C0BC(iVar3,param_3 + 6);
      if (iVar3 == 0) {
        param_1 = 0x1e;
        goto loc_F003B640;
      }
      uVar4 = *(undefined4 *)(param_1 + 0x20);
    }
    puVar1 = (undefined4 *)(param_1 + 0x24);
    param_1 = iVar2;
    (**(code **)(*(int *)(iVar2 + 0x1c) + 0x40))
              (iVar2,uVar4,(undefined *)((int)register0x00000038 + -0x48),*puVar1,
               *(undefined4 *)(_active_u + 0x1c));
    if (param_1 == 0x11) {
      _svckudp_dup();
      if (param_4 != 0) {
        param_1 = 0;
        goto loc_F003B640;
      }
      *param_2 = 0x11;
    }
    else {
      if (param_1 == 0) {
        _svckudp_dupsave(param_4);
        goto loc_F003B640;
      }
      *param_2 = param_1;
    }
  }
  else {
    param_1 = 0x1e;
loc_F003B640:
    *param_2 = param_1;
  }
  _vn_rele(iVar2);
locret_F003B64C:
  return CONCAT44(param_2,param_1);
}
