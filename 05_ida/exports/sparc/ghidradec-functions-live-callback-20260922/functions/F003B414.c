
/* WARNING: Removing unreachable block (ram,0xf003b524) */
/* WARNING: Removing unreachable block (ram,0xf003b518) */
/* WARNING: Removing unreachable block (ram,0xf003b464) */
/* WARNING: Removing unreachable block (ram,0xf003b4a8) */
/* WARNING: Removing unreachable block (ram,0xf003b4f4) */
/* WARNING: Removing unreachable block (ram,0xf003b530) */
/* WARNING: Removing unreachable block (ram,0xf003b444) */

undefined8 sub_F003B414(int param_1,int *param_2,uint *param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
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
  if ((*(char **)(param_1 + 0x40) == (char *)0x0) || (**(char **)(param_1 + 0x40) == '\0')) {
    *param_2 = 0xd;
    goto locret_F003B538;
  }
  iVar2 = param_1;
  sub_F003C020(param_1,param_3);
  iVar3 = param_1 + 0x20;
  if (iVar2 == 0) {
    *param_2 = 0x46;
    goto locret_F003B538;
  }
  sub_F003C020(iVar3,param_3);
  if (iVar3 == 0) {
    *param_2 = 0x46;
  }
  else {
    if ((*param_3 & 1) == 0) {
      if ((*param_3 & 2) == 0) {
        iVar4 = *(int *)(iVar3 + 0x1c);
      }
      else {
        iVar4 = *(int *)(param_4 + 0x1c) + 0x10;
        sub_F003C0BC(iVar4,param_3 + 6);
        if (iVar4 == 0) {
          param_1 = 0x1e;
          goto loc_F003B520;
        }
        iVar4 = *(int *)(iVar3 + 0x1c);
      }
      puVar1 = (undefined4 *)(param_1 + 0x40);
      param_1 = iVar2;
      (**(code **)(iVar4 + 0x2c))(iVar2,iVar3,*puVar1,*(undefined4 *)(_active_u + 0x1c));
      if (param_1 == 0x11) {
        _svckudp_dup();
        if (param_4 != 0) {
          param_1 = 0;
          goto loc_F003B520;
        }
        *param_2 = 0x11;
      }
      else {
        if (param_1 == 0) {
          _svckudp_dupsave(param_4);
          goto loc_F003B520;
        }
        *param_2 = param_1;
      }
    }
    else {
      param_1 = 0x1e;
loc_F003B520:
      *param_2 = param_1;
    }
    _vn_rele(iVar2);
    iVar2 = iVar3;
  }
  _vn_rele(iVar2);
locret_F003B538:
  return CONCAT44(param_2,param_1);
}

