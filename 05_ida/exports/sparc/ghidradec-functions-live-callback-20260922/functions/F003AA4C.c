
/* WARNING: Removing unreachable block (ram,0xf003ab40) */
/* WARNING: Removing unreachable block (ram,0xf003abc8) */
/* WARNING: Removing unreachable block (ram,0xf003ab50) */
/* WARNING: Removing unreachable block (ram,0xf003aa88) */
/* WARNING: Removing unreachable block (ram,0xf003ab88) */
/* WARNING: Removing unreachable block (ram,0xf003abfc) */
/* WARNING: Removing unreachable block (ram,0xf003ac10) */
/* WARNING: Removing unreachable block (ram,0xf003aa5c) */

undefined8 sub_F003AA4C(int param_1,int *param_2,undefined4 param_3)

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
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar3;
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
  param_2[0x13] = 0;
  param_2[0x12] = 0;
  iVar1 = param_1;
  sub_F003C020(param_1,param_3);
  if (iVar1 == 0) {
    *param_2 = 0x46;
    goto locret_F003AC18;
  }
  if (*(int *)(iVar1 + 0x28) == 1) {
    iVar2 = iVar1;
    (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))
              (iVar1,(undefined *)((int)register0x00000038 + -0x48),
               *(undefined4 *)(_active_u + 0x1c));
  }
  else {
    _printf(aRfsReadAttempt);
    iVar2 = 0x15;
  }
  bVar3 = iVar2 == 0;
  if (bVar3) {
    iVar2 = 0;
    if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) != *(sword *)((int)register0x00000038 + -0x42)) {
      iVar2 = iVar1;
      (**(code **)(*(int *)(iVar1 + 0x1c) + 0x1c))(iVar1,0x100,*(int *)(_active_u + 0x1c));
      bVar3 = iVar2 == 0;
      iVar2 = 0;
      if (!bVar3) {
        iVar2 = iVar1;
        (**(code **)(*(int *)(iVar1 + 0x1c) + 0x1c))(iVar1,0x40,*(undefined4 *)(_active_u + 0x1c));
        bVar3 = iVar2 == 0;
      }
      if (!bVar3) goto loc_F003ABE4;
    }
    if (*(uint *)(param_1 + 0x20) < *(uint *)((int)register0x00000038 + -0x30)) {
      iVar2 = *(int *)(param_1 + 0x24);
      _kalloc();
      param_2[0x13] = iVar2;
      iVar2 = 0;
      param_2[-1] = *(int *)(param_1 + 0x24);
      _vn_rdwr(0,iVar1,param_2[0x13],*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x20)
               ,1,4,(undefined *)((int)register0x00000038 + -0x4c));
      bVar3 = false;
      if (iVar2 == 0) {
        iVar2 = iVar1;
        (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))
                  (iVar1,(undefined *)((int)register0x00000038 + -0x48),
                   *(undefined4 *)(_active_u + 0x1c));
        bVar3 = false;
        if (iVar2 == 0) {
          _vattr_to_nattr((undefined *)((int)register0x00000038 + -0x48),param_2 + 1);
          param_2[0x12] = *(int *)(param_1 + 0x24) - *(int *)((int)register0x00000038 + -0x4c);
          bVar3 = true;
        }
      }
      goto loc_F003ABE4;
    }
    param_2[0x12] = 0;
    _vattr_to_nattr((undefined *)((int)register0x00000038 + -0x48),param_2 + 1);
    *param_2 = iVar2;
  }
  else {
loc_F003ABE4:
    if (bVar3) {
      *param_2 = iVar2;
    }
    else if (param_2[0x13] == 0) {
      *param_2 = iVar2;
    }
    else {
      _kfree(param_2[0x13],param_2[-1]);
      param_2[0x13] = 0;
      param_2[0x12] = 0;
      *param_2 = iVar2;
    }
  }
  _vn_rele(iVar1);
locret_F003AC18:
  return CONCAT44(param_2,param_1);
}

