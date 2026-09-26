/* GHIDRADEC_FUNCTION index=3300 start=0xf003a964 */

/* WARNING: Removing unreachable block (ram,0xf003a9f8) */
/* WARNING: Removing unreachable block (ram,0xf003a988) */
/* WARNING: Removing unreachable block (ram,0xf003a994) */
/* WARNING: Removing unreachable block (ram,0xf003aa18) */
/* WARNING: Removing unreachable block (ram,0xf003a96c) */

undefined8 sub_F003A964(int param_1,int *param_2,undefined4 param_3)

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
  sub_F003C020(param_1,param_3);
  if (param_1 == 0) {
    *param_2 = 0x46;
  }
  else {
    iVar1 = 0x400;
    _kalloc();
    param_2[2] = iVar1;
    _bzero();
    *(int *)((int)register0x00000038 + -0x10) = param_2[2];
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0x400;
    *(undefined **)((int)register0x00000038 + -0x28) =
         (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
    *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
    *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
    *(undefined4 *)((int)register0x00000038 + -0x14) = 0x400;
    iVar1 = param_1;
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x44))
              (param_1,(undefined *)((int)register0x00000038 + -0x28),
               *(undefined4 *)(_active_u + 0x1c));
    if (iVar1 == 0) {
      param_2[1] = 0x400 - *(int *)((int)register0x00000038 + -0x14);
    }
    else {
      _kfree(param_2[2],0x400);
      param_2[1] = 0;
      param_2[2] = 0;
    }
    *param_2 = iVar1;
    _vn_rele(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3301 start=0xf003aa28 */

/* WARNING: Removing unreachable block (ram,0xf003aa3c) */

undefined8 sub_F003AA28(int param_1,undefined4 param_2)

{
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
  if (*(int *)(param_1 + 8) != 0) {
    _kfree(*(int *)(param_1 + 8),0x400);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3302 start=0xf003aa4c */

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
/* GHIDRADEC_FUNCTION index=3303 start=0xf003ac20 */

/* WARNING: Removing unreachable block (ram,0xf003ac44) */

undefined8 sub_F003AC20(int param_1,undefined4 param_2)

{
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
  if ((*(int *)(param_1 + 0x50) == 0) && (*(int *)(param_1 + 0x4c) != 0)) {
    _kfree(*(int *)(param_1 + 0x4c),*(undefined4 *)(param_1 + -4));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3304 start=0xf003ac54 */

/* WARNING: Removing unreachable block (ram,0xf003af20) */
/* WARNING: Removing unreachable block (ram,0xf003ae84) */
/* WARNING: Removing unreachable block (ram,0xf003ae58) */
/* WARNING: Removing unreachable block (ram,0xf003ae10) */
/* WARNING: Removing unreachable block (ram,0xf003adb0) */
/* WARNING: Removing unreachable block (ram,0xf003acc4) */
/* WARNING: Removing unreachable block (ram,0xf003ac98) */
/* WARNING: Removing unreachable block (ram,0xf003ad94) */
/* WARNING: Removing unreachable block (ram,0xf003adbc) */
/* WARNING: Removing unreachable block (ram,0xf003ae20) */
/* WARNING: Removing unreachable block (ram,0xf003ae78) */
/* WARNING: Removing unreachable block (ram,0xf003aec0) */
/* WARNING: Removing unreachable block (ram,0xf003af28) */
/* WARNING: Removing unreachable block (ram,0xf003ac5c) */

undefined8 sub_F003AC54(int param_1,int *param_2,uint *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
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
  int iVar4;
  undefined4 unaff_i3;
  int iVar5;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
  bool bVar7;
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
  iVar1 = param_1;
  sub_F003C020(param_1,param_3);
  if (iVar1 == 0) {
    *param_2 = 0x46;
    goto locret_F003AF30;
  }
  if ((*param_3 & 1) == 0) {
    if ((*param_3 & 2) == 0) {
      iVar4 = *(int *)(iVar1 + 0x28);
    }
    else {
      iVar4 = *(int *)(param_4 + 0x1c) + 0x10;
      sub_F003C0BC(iVar4,param_3 + 6);
      if (iVar4 == 0) {
        iVar4 = 0x1e;
        goto loc_F003ACF8;
      }
      iVar4 = *(int *)(iVar1 + 0x28);
    }
    if (iVar4 == 1) {
      iVar4 = iVar1;
      (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))
                (iVar1,(undefined *)((int)register0x00000038 + -0x48),
                 *(undefined4 *)(_active_u + 0x1c));
    }
    else {
      _printf(aRfsWriteAttemp);
      iVar4 = 0x15;
    }
  }
  else {
    iVar4 = 0x1e;
  }
loc_F003ACF8:
  bVar6 = iVar4 == 0;
  if (bVar6) {
    if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) != *(sword *)((int)register0x00000038 + -0x42)) {
      iVar4 = iVar1;
      (**(code **)(*(int *)(iVar1 + 0x1c) + 0x1c))(iVar1,0x80,*(int *)(_active_u + 0x1c));
    }
    bVar7 = false;
    if (iVar4 == 0) {
      if (*(int *)(param_1 + 0x30) == 0) {
        iVar5 = 0;
        for (piVar2 = *(int **)(param_1 + 0x34); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
          iVar5 = iVar5 + 1;
        }
        iVar3 = iVar5 << 3;
        _kalloc();
        sub_F003AF38(*(undefined4 *)(param_1 + 0x34),iVar3);
        *(int *)((int)register0x00000038 + -0x68) = iVar3;
        *(int *)((int)register0x00000038 + -100) = iVar5;
        *(undefined4 *)((int)register0x00000038 + -0x5c) = 1;
        *(undefined4 *)((int)register0x00000038 + -0x60) = *(undefined4 *)(param_1 + 0x24);
        *(undefined4 *)((int)register0x00000038 + -0x54) = *(undefined4 *)(param_1 + 0x2c);
        if (*(int *)(iVar1 + 0x28) == 1) {
          _map_vnode(iVar1);
          iVar4 = iVar1;
          _mfs_io(iVar1,(undefined *)((int)register0x00000038 + -0x68),1,4,
                  *(undefined4 *)(_active_u + 0x1c));
          _unmap_vnode(iVar1);
        }
        else {
          iVar4 = iVar1;
          (**(code **)(*(int *)(iVar1 + 0x1c) + 8))
                    (iVar1,(undefined *)((int)register0x00000038 + -0x68),1,4,
                     *(undefined4 *)(_active_u + 0x1c));
        }
        _kfree(iVar3,iVar5 << 3);
      }
      else {
        *(int *)((int)register0x00000038 + -0x50) = *(int *)(param_1 + 0x30);
        *(undefined4 *)((int)register0x00000038 + -0x4c) = *(undefined4 *)(param_1 + 0x2c);
        *(undefined **)((int)register0x00000038 + -0x68) =
             (undefined *)((int)register0x00000038 + -0x50);
        *(undefined4 *)((int)register0x00000038 + -100) = 1;
        *(undefined4 *)((int)register0x00000038 + -0x5c) = 1;
        *(undefined4 *)((int)register0x00000038 + -0x60) = *(undefined4 *)(param_1 + 0x24);
        *(undefined4 *)((int)register0x00000038 + -0x54) = *(undefined4 *)(param_1 + 0x2c);
        if (*(int *)(iVar1 + 0x28) == 1) {
          _map_vnode(iVar1);
          iVar4 = iVar1;
          _mfs_io(iVar1,(undefined *)((int)register0x00000038 + -0x68),1,4,
                  *(undefined4 *)(_active_u + 0x1c));
          _unmap_vnode(iVar1);
        }
        else {
          iVar4 = iVar1;
          (**(code **)(*(int *)(iVar1 + 0x1c) + 8))
                    (iVar1,(undefined *)((int)register0x00000038 + -0x68),1,4,
                     *(undefined4 *)(_active_u + 0x1c));
        }
      }
      (**(code **)(*(int *)(iVar1 + 0x1c) + 0x48))(iVar1,*(undefined4 *)(_active_u + 0x1c));
      bVar6 = iVar4 == 0;
      goto loc_F003AEE8;
    }
  }
  else {
loc_F003AEE8:
    bVar7 = iVar4 == 0;
    if (bVar6) {
      iVar4 = iVar1;
      (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))
                (iVar1,(undefined *)((int)register0x00000038 + -0x48),
                 *(undefined4 *)(_active_u + 0x1c));
      bVar7 = iVar4 == 0;
    }
  }
  *param_2 = iVar4;
  if (bVar7) {
    _vattr_to_nattr((undefined *)((int)register0x00000038 + -0x48),param_2 + 1);
  }
  _vn_rele(iVar1);
locret_F003AF30:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3305 start=0xf003af38 */

sqword sub_F003AF38(int *param_1,int *param_2)

{
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
  for (; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
    *param_2 = (int)param_1 + param_1[1];
    param_2[1] = (int)*(sword *)(param_1 + 2);
    param_2 = param_2 + 2;
  }
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=3306 start=0xf003af74 */

/* WARNING: Removing unreachable block (ram,0xf003b1c0) */
/* WARNING: Removing unreachable block (ram,0xf003b1a4) */
/* WARNING: Removing unreachable block (ram,0xf003b114) */
/* WARNING: Removing unreachable block (ram,0xf003b06c) */
/* WARNING: Removing unreachable block (ram,0xf003b030) */
/* WARNING: Removing unreachable block (ram,0xf003b098) */
/* WARNING: Removing unreachable block (ram,0xf003b160) */
/* WARNING: Removing unreachable block (ram,0xf003b1b4) */
/* WARNING: Removing unreachable block (ram,0xf003b1cc) */
/* WARNING: Removing unreachable block (ram,0xf003afa4) */

undefined8 sub_F003AF74(undefined4 *param_1,undefined4 *param_2,uint *param_3,int param_4)

{
  code *pcVar1;
  undefined4 *puVar2;
  word wVar4;
  int iVar3;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  char *pcVar6;
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
  pcVar6 = (char *)param_1[8];
  if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) {
    *param_2 = 0xd;
    goto locret_F003B1D4;
  }
  sub_F003BFCC(param_1 + 9,(undefined *)((int)register0x00000038 + -0x48));
  wVar4 = *(word *)((int)register0x00000038 + -0x44) & 0xf000;
  if (wVar4 == 0x2000) {
    iVar3 = *(int *)((int)register0x00000038 + -0x30);
    *(undefined4 *)((int)register0x00000038 + -0x48) = 4;
    if (iVar3 == -1) {
      *(undefined4 *)((int)register0x00000038 + -0x48) = 8;
    }
    else {
loc_F003B000:
      *(sword *)((int)register0x00000038 + -0x10) = (sword)iVar3;
    }
    *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
  }
  else {
    if (wVar4 == 0x6000) {
      iVar3 = *(int *)((int)register0x00000038 + -0x30);
      *(undefined4 *)((int)register0x00000038 + -0x48) = 3;
      goto loc_F003B000;
    }
    uVar5 = 1;
    if (wVar4 == 0xc000) {
      uVar5 = 6;
    }
    *(undefined4 *)((int)register0x00000038 + -0x48) = uVar5;
  }
  *(word *)((int)register0x00000038 + -0x44) = *(word *)((int)register0x00000038 + -0x44) & 0xfff;
  puVar2 = param_1;
  sub_F003C020(param_1,param_3);
  if (puVar2 == (undefined4 *)0x0) {
    *param_2 = 0x46;
    goto locret_F003B1D4;
  }
  param_1 = (undefined4 *)0x1e;
  if ((*param_3 & 1) == 0) {
    if ((*param_3 & 2) == 0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x30);
    }
    else {
      iVar3 = *(int *)(param_4 + 0x1c) + 0x10;
      sub_F003C0BC(iVar3,param_3 + 6);
      if (iVar3 == 0) {
        param_1 = (undefined4 *)0x1e;
        goto loc_F003B16C;
      }
      iVar3 = *(int *)((int)register0x00000038 + -0x30);
    }
    if ((iVar3 == 0) && (iVar3 = param_4, _svckudp_dup(), iVar3 != 0)) {
      uVar5 = *(undefined4 *)(_active_u + 0x1c);
      pcVar1 = *(code **)(puVar2[7] + 0x20);
    }
    else {
      param_1 = puVar2;
      (**(code **)(puVar2[7] + 0x24))
                (puVar2,pcVar6,(undefined *)((int)register0x00000038 + -0x48),0,0x80,
                 (undefined *)((int)register0x00000038 + -0x4c),*(undefined4 *)(_active_u + 0x1c));
      if ((param_1 == (undefined4 *)0x0) || (iVar3 = param_4, _svckudp_dup(), iVar3 == 0)) {
        if (param_1 == (undefined4 *)0x0) {
          _svckudp_dupsave(param_4);
        }
        goto loc_F003B16C;
      }
      uVar5 = *(undefined4 *)(_active_u + 0x1c);
      pcVar1 = *(code **)(puVar2[7] + 0x20);
    }
    param_1 = puVar2;
    (*pcVar1)(puVar2,pcVar6,(undefined *)((int)register0x00000038 + -0x4c),uVar5,0,0);
  }
loc_F003B16C:
  if (param_1 == (undefined4 *)0x0) {
    param_1 = *(undefined4 **)((int)register0x00000038 + -0x4c);
    (**(code **)(param_1[7] + 0x14))
              (param_1,(undefined *)((int)register0x00000038 + -0x48),
               *(undefined4 *)(_active_u + 0x1c));
    if (param_1 == (undefined4 *)0x0) {
      _vattr_to_nattr((undefined *)((int)register0x00000038 + -0x48),param_2 + 9);
      param_1 = param_2 + 1;
      _makefh(param_1,*(undefined4 *)((int)register0x00000038 + -0x4c),param_3);
    }
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
    *param_2 = param_1;
  }
  else {
    *param_2 = param_1;
  }
  _vn_rele(puVar2);
locret_F003B1D4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3307 start=0xf003b1dc */

/* WARNING: Removing unreachable block (ram,0xf003b294) */
/* WARNING: Removing unreachable block (ram,0xf003b248) */
/* WARNING: Removing unreachable block (ram,0xf003b2b8) */
/* WARNING: Removing unreachable block (ram,0xf003b2c4) */
/* WARNING: Removing unreachable block (ram,0xf003b20c) */

undefined8 sub_F003B1DC(int param_1,int *param_2,uint *param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
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
  if ((*(char **)(param_1 + 0x20) == (char *)0x0) || (**(char **)(param_1 + 0x20) == '\0')) {
    *param_2 = 0xd;
    goto locret_F003B2CC;
  }
  iVar2 = param_1;
  sub_F003C020(param_1,param_3);
  if (iVar2 == 0) {
    *param_2 = 0x46;
    goto locret_F003B2CC;
  }
  if ((*param_3 & 1) == 0) {
    if ((*param_3 & 2) == 0) {
      iVar3 = *(int *)(iVar2 + 0x1c);
    }
    else {
      iVar3 = *(int *)(param_4 + 0x1c) + 0x10;
      sub_F003C0BC(iVar3,param_3 + 6);
      if (iVar3 == 0) {
        param_1 = 0x1e;
        goto loc_F003B2C0;
      }
      iVar3 = *(int *)(iVar2 + 0x1c);
    }
    puVar1 = (undefined4 *)(param_1 + 0x20);
    param_1 = iVar2;
    (**(code **)(iVar3 + 0x28))(iVar2,*puVar1,*(undefined4 *)(_active_u + 0x1c));
    if (param_1 == 2) {
      _svckudp_dup();
      if (param_4 != 0) {
        param_1 = 0;
        goto loc_F003B2C0;
      }
      *param_2 = 2;
    }
    else {
      if (param_1 == 0) {
        _svckudp_dupsave(param_4);
        goto loc_F003B2C0;
      }
      *param_2 = param_1;
    }
  }
  else {
    param_1 = 0x1e;
loc_F003B2C0:
    *param_2 = param_1;
  }
  _vn_rele(iVar2);
locret_F003B2CC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3308 start=0xf003b2d4 */

/* WARNING: Removing unreachable block (ram,0xf003b3f8) */
/* WARNING: Removing unreachable block (ram,0xf003b3d0) */
/* WARNING: Removing unreachable block (ram,0xf003b380) */
/* WARNING: Removing unreachable block (ram,0xf003b360) */
/* WARNING: Removing unreachable block (ram,0xf003b39c) */
/* WARNING: Removing unreachable block (ram,0xf003b3d8) */
/* WARNING: Removing unreachable block (ram,0xf003b3ec) */
/* WARNING: Removing unreachable block (ram,0xf003b324) */

undefined8 sub_F003B2D4(int param_1,int *param_2,uint *param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
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
  if ((((*(char **)(param_1 + 0x20) == (char *)0x0) || (**(char **)(param_1 + 0x20) == '\0')) ||
      (*(char **)(param_1 + 0x44) == (char *)0x0)) || (**(char **)(param_1 + 0x44) == '\0')) {
    *param_2 = 0xd;
    goto locret_F003B40C;
  }
  iVar3 = param_1;
  sub_F003C020(param_1,param_3);
  if (iVar3 == 0) {
    *param_2 = 0x46;
    goto locret_F003B40C;
  }
  if ((*param_3 & 1) == 0) {
    if ((*param_3 & 2) != 0) {
      iVar4 = *(int *)(param_4 + 0x1c) + 0x10;
      sub_F003C0BC(iVar4,param_3 + 6);
      if (iVar4 == 0) {
        param_1 = 0x1e;
        goto loc_F003B3D8;
      }
    }
    iVar4 = param_1 + 0x24;
    sub_F003C020(iVar4,param_3);
    if (iVar4 == 0) {
      *param_2 = 0x46;
      _vn_rele(iVar3);
      goto locret_F003B40C;
    }
    puVar1 = (undefined4 *)(param_1 + 0x20);
    puVar2 = (undefined4 *)(param_1 + 0x44);
    param_1 = iVar3;
    (**(code **)(*(int *)(iVar3 + 0x1c) + 0x30))
              (iVar3,*puVar1,iVar4,*puVar2,*(undefined4 *)(_active_u + 0x1c));
    _vn_rele(iVar4);
  }
  else {
    param_1 = 0x1e;
  }
loc_F003B3D8:
  _vn_rele(iVar3);
  *param_2 = param_1;
  if (param_1 == 0) {
    _svckudp_dupsave(param_4);
  }
  else {
    _svckudp_dup();
    if (param_4 != 0) {
      *param_2 = 0;
    }
  }
locret_F003B40C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3309 start=0xf003b414 */

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
/* GHIDRADEC_FUNCTION index=3310 start=0xf003b540 */

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
/* GHIDRADEC_FUNCTION index=3311 start=0xf003b654 */

/* WARNING: Removing unreachable block (ram,0xf003b7d0) */
/* WARNING: Removing unreachable block (ram,0xf003b7b0) */
/* WARNING: Removing unreachable block (ram,0xf003b730) */
/* WARNING: Removing unreachable block (ram,0xf003b698) */
/* WARNING: Removing unreachable block (ram,0xf003b6d4) */
/* WARNING: Removing unreachable block (ram,0xf003b7a0) */
/* WARNING: Removing unreachable block (ram,0xf003b7bc) */
/* WARNING: Removing unreachable block (ram,0xf003b7dc) */
/* WARNING: Removing unreachable block (ram,0xf003b684) */

undefined8 sub_F003B654(undefined4 *param_1,undefined4 *param_2,uint *param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  char *pcVar3;
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
  bool bVar4;
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
  pcVar3 = (char *)param_1[8];
  if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {
    *param_2 = 0xd;
    goto locret_F003B7E4;
  }
  sub_F003BFCC(param_1 + 9,(undefined *)((int)register0x00000038 + -0x48));
  *(undefined4 *)((int)register0x00000038 + -0x48) = 2;
  puVar1 = param_1;
  sub_F003C020(param_1,param_3);
  if (puVar1 == (undefined4 *)0x0) {
    *param_2 = 0x46;
    goto locret_F003B7E4;
  }
  param_1 = (undefined4 *)0x1e;
  if ((*param_3 & 1) == 0) {
    if ((*param_3 & 2) != 0) {
      iVar2 = *(int *)(param_4 + 0x1c) + 0x10;
      sub_F003C0BC(iVar2,param_3 + 6);
      if (iVar2 == 0) {
        param_1 = (undefined4 *)0x1e;
        goto loc_F003B7D8;
      }
    }
    param_1 = puVar1;
    (**(code **)(puVar1[7] + 0x34))
              (puVar1,pcVar3,(undefined *)((int)register0x00000038 + -0x48),
               (undefined *)((int)register0x00000038 + -0x4c),*(undefined4 *)(_active_u + 0x1c));
    bVar4 = param_1 == (undefined4 *)0x0;
    if (param_1 == (undefined4 *)0x11) {
      iVar2 = param_4;
      _svckudp_dup();
      if (iVar2 != 0) {
        param_1 = puVar1;
        (**(code **)(puVar1[7] + 0x20))
                  (puVar1,pcVar3,(undefined *)((int)register0x00000038 + -0x4c),
                   *(undefined4 *)(_active_u + 0x1c),0,0);
        bVar4 = param_1 == (undefined4 *)0x0;
        if (!bVar4) goto loc_F003B794;
        param_1 = puVar1;
        (**(code **)(puVar1[7] + 0x14))
                  (puVar1,(undefined *)((int)register0x00000038 + -0x48),
                   *(undefined4 *)(_active_u + 0x1c));
      }
      bVar4 = param_1 == (undefined4 *)0x0;
    }
loc_F003B794:
    if (bVar4) {
      _vattr_to_nattr((undefined *)((int)register0x00000038 + -0x48),param_2 + 9);
      param_1 = param_2 + 1;
      _makefh(param_1,*(undefined4 *)((int)register0x00000038 + -0x4c),param_3);
      _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
    }
    if (param_1 == (undefined4 *)0x0) {
      _svckudp_dupsave(param_4);
      goto loc_F003B7D8;
    }
    *param_2 = param_1;
  }
  else {
loc_F003B7D8:
    *param_2 = param_1;
  }
  _vn_rele(puVar1);
locret_F003B7E4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3312 start=0xf003b7ec */

/* WARNING: Removing unreachable block (ram,0xf003b8a4) */
/* WARNING: Removing unreachable block (ram,0xf003b858) */
/* WARNING: Removing unreachable block (ram,0xf003b8c8) */
/* WARNING: Removing unreachable block (ram,0xf003b8d4) */
/* WARNING: Removing unreachable block (ram,0xf003b81c) */

undefined8 sub_F003B7EC(int param_1,int *param_2,uint *param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
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
  if ((*(char **)(param_1 + 0x20) == (char *)0x0) || (**(char **)(param_1 + 0x20) == '\0')) {
    *param_2 = 0xd;
    goto locret_F003B8DC;
  }
  iVar2 = param_1;
  sub_F003C020(param_1,param_3);
  if (iVar2 == 0) {
    *param_2 = 0x46;
    goto locret_F003B8DC;
  }
  if ((*param_3 & 1) == 0) {
    if ((*param_3 & 2) == 0) {
      iVar3 = *(int *)(iVar2 + 0x1c);
    }
    else {
      iVar3 = *(int *)(param_4 + 0x1c) + 0x10;
      sub_F003C0BC(iVar3,param_3 + 6);
      if (iVar3 == 0) {
        param_1 = 0x1e;
        goto loc_F003B8D0;
      }
      iVar3 = *(int *)(iVar2 + 0x1c);
    }
    puVar1 = (undefined4 *)(param_1 + 0x20);
    param_1 = iVar2;
    (**(code **)(iVar3 + 0x38))(iVar2,*puVar1,*(undefined4 *)(_active_u + 0x1c));
    if (param_1 == 2) {
      _svckudp_dup();
      if (param_4 != 0) {
        param_1 = 0;
        goto loc_F003B8D0;
      }
      *param_2 = 2;
    }
    else {
      if (param_1 == 0) {
        _svckudp_dupsave(param_4);
        goto loc_F003B8D0;
      }
      *param_2 = param_1;
    }
  }
  else {
    param_1 = 0x1e;
loc_F003B8D0:
    *param_2 = param_1;
  }
  _vn_rele(iVar2);
locret_F003B8DC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3313 start=0xf003b8e4 */

/* WARNING: Removing unreachable block (ram,0xf003b918) */
/* WARNING: Removing unreachable block (ram,0xf003b988) */
/* WARNING: Removing unreachable block (ram,0xf003baec) */
/* WARNING: Removing unreachable block (ram,0xf003bb04) */
/* WARNING: Removing unreachable block (ram,0xf003b8ec) */

undefined8 sub_F003B8E4(int param_1,int *param_2,undefined4 param_3)

{
  word wVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
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
  bool bVar9;
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
  iVar2 = param_1;
  sub_F003C020(param_1,param_3);
  if (iVar2 == 0) {
    param_2[1] = 0x46;
    goto locret_F003BB0C;
  }
  if (*(int *)(iVar2 + 0x28) == 2) {
    iVar8 = iVar2;
    (**(code **)(*(int *)(iVar2 + 0x1c) + 0x1c))(iVar2,0x100,*(undefined4 *)(_active_u + 0x1c));
    if (iVar8 == 0) {
      uVar3 = *(uint *)(param_1 + 0x24);
      if (uVar3 == 0) {
        param_2[3] = 0;
        param_2[4] = 0;
        param_2[5] = 0;
        *param_2 = 0;
        iVar8 = 0;
      }
      else {
        if (0x2000 < uVar3) {
          uVar3 = 0x2000;
        }
        *(uint *)(param_1 + 0x24) = uVar3;
        while( true ) {
          iVar8 = *(int *)(param_1 + 0x24);
          _kalloc();
          param_2[5] = iVar8;
          param_2[-1] = *(int *)(param_1 + 0x24);
          *param_2 = *(int *)(param_1 + 0x24);
          uVar3 = *(uint *)(param_1 + 0x20) & 0xfffffc00;
          param_2[2] = uVar3;
          *(int *)((int)register0x00000038 + -0x10) = param_2[5];
          *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x24);
          *(undefined **)((int)register0x00000038 + -0x28) =
               (undefined *)((int)register0x00000038 + -0x10);
          *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
          *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
          *(uint *)((int)register0x00000038 + -0x20) = uVar3;
          *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_1 + 0x24);
          iVar8 = iVar2;
          (**(code **)(*(int *)(iVar2 + 0x1c) + 0x3c))
                    (iVar2,(undefined *)((int)register0x00000038 + -0x28),
                     *(undefined4 *)(_active_u + 0x1c));
          if (iVar8 != 0) break;
          if (*(int *)((int)register0x00000038 + -0x14) == 0) {
            param_2[3] = *(int *)(param_1 + 0x24);
            param_2[4] = 0;
          }
          else {
            param_2[3] = *(int *)(param_1 + 0x24) - *(int *)((int)register0x00000038 + -0x14);
            param_2[4] = 1;
          }
          uVar7 = 0;
          piVar6 = (int *)param_2[5];
          bVar9 = param_2[3] != 0;
          while (bVar9) {
            if (*(uint *)(param_1 + 0x20) < uVar3 + *(word *)(piVar6 + 1)) {
              if (*piVar6 != 0) break;
              wVar1 = *(word *)(piVar6 + 1);
            }
            else {
              wVar1 = *(word *)(piVar6 + 1);
            }
            uVar4 = (uint)wVar1;
            uVar7 = uVar7 + uVar4;
            uVar3 = uVar3 + uVar4;
            piVar6 = (int *)((int)piVar6 + uVar4);
            bVar9 = uVar7 < (uint)param_2[3];
          }
          if (uVar7 == 0) {
            param_2[1] = 0;
            goto loc_F003BB04;
          }
          param_2[2] = uVar3;
          param_2[3] = param_2[3] - uVar7;
          iVar5 = param_2[5];
          *param_2 = *param_2 - uVar7;
          param_2[5] = iVar5 + uVar7;
          if (param_2[3] != 0) goto loc_F003BB00;
          if (param_2[4] != 0) {
            param_2[1] = 0;
            goto loc_F003BB04;
          }
          _kfree((iVar5 + uVar7 + *param_2) - param_2[-1]);
          *(int *)(param_1 + 0x20) = param_2[2];
        }
        param_2[3] = 0;
      }
      goto loc_F003BB00;
    }
    param_2[1] = iVar8;
  }
  else {
    _printf(aRfsReaddirAtte);
    iVar8 = 0x14;
loc_F003BB00:
    param_2[1] = iVar8;
  }
loc_F003BB04:
  _vn_rele(iVar2);
locret_F003BB0C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3314 start=0xf003bb14 */

/* WARNING: Removing unreachable block (ram,0xf003bb34) */

undefined8 sub_F003BB14(int *param_1,undefined4 param_2)

{
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
  if (param_1[5] != 0) {
    _kfree((param_1[5] + *param_1) - param_1[-1]);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3315 start=0xf003bb44 */

/* WARNING: Removing unreachable block (ram,0xf003bb88) */
/* WARNING: Removing unreachable block (ram,0xf003bbb4) */
/* WARNING: Removing unreachable block (ram,0xf003bb4c) */

undefined8 sub_F003BB44(int param_1,int *param_2,undefined4 param_3)

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
  sub_F003C020(param_1,param_3);
  if (param_1 == 0) {
    *param_2 = 0x46;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x24);
    (**(code **)(*(int *)(iVar1 + 4) + 0xc))(iVar1,(undefined *)((int)register0x00000038 + -0x48));
    *param_2 = iVar1;
    if (iVar1 == 0) {
      _nfstsize();
      param_2[1] = iVar1;
      param_2[2] = *(int *)((int)register0x00000038 + -0x44);
      param_2[3] = *(int *)((int)register0x00000038 + -0x40);
      param_2[4] = *(int *)((int)register0x00000038 + -0x3c);
      param_2[5] = *(int *)((int)register0x00000038 + -0x38);
    }
    _vn_rele(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3316 start=0xf003bbc4 */

sqword sub_F003BBC4(undefined4 param_1,uint param_2)

{
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3317 start=0xf003bbd0 */

undefined8 sub_F003BBD0(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,0x2d);
}
/* GHIDRADEC_FUNCTION index=3318 start=0xf003bbdc */

undefined8 sub_F003BBDC(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3319 start=0xf003bbe8 */

/* WARNING: Removing unreachable block (ram,0xf003bca8) */

undefined8 sub_F003BBE8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
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
  if (_rfssize == 0) {
    iVar1 = 0;
    puVar3 = &_nfs_portmon;
    do {
      puVar2 = (undefined4 *)(_rfsdisptab + iVar1);
      if (puVar2 < puVar3) {
        piVar4 = (int *)(_rfsdisptab + iVar1 + 0x10);
        do {
          if (_rfssize < piVar4[-2]) {
            _rfssize = piVar4[-2];
          }
          if (_rfssize < *piVar4) {
            _rfssize = *piVar4;
          }
          puVar2 = puVar2 + 6;
          piVar4 = piVar4 + 6;
        } while (puVar2 < (undefined4 *)((int)&_nfs_portmon + iVar1));
      }
      puVar3 = puVar3 + 0x6c;
      iVar1 = iVar1 + 0x1b0;
    } while ((int)puVar3 < -0xfef33bb);
  }
  if (_rfsfreesp == (int *)0x0) {
    iVar1 = _rfssize + 4;
    _kalloc(iVar1);
    piVar4 = (int *)(iVar1 + 4);
  }
  else {
    piVar4 = _rfsfreesp;
    _rfsfreesp = (int *)*_rfsfreesp;
  }
  return CONCAT44(param_2,piVar4);
}
/* GHIDRADEC_FUNCTION index=3320 start=0xf003bcbc */

undefined8 sub_F003BCBC(undefined4 *param_1,undefined4 param_2)

{
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
  *param_1 = _rfsfreesp;
  _rfsfreesp = param_1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3321 start=0xf003bcd8 */

/* WARNING: Removing unreachable block (ram,0xf003bf8c) */
/* WARNING: Removing unreachable block (ram,0xf003bf4c) */
/* WARNING: Removing unreachable block (ram,0xf003bf0c) */
/* WARNING: Removing unreachable block (ram,0xf003beec) */
/* WARNING: Removing unreachable block (ram,0xf003be44) */
/* WARNING: Removing unreachable block (ram,0xf003bd44) */
/* WARNING: Removing unreachable block (ram,0xf003be74) */
/* WARNING: Removing unreachable block (ram,0xf003be2c) */
/* WARNING: Removing unreachable block (ram,0xf003be04) */
/* WARNING: Removing unreachable block (ram,0xf003bd98) */
/* WARNING: Removing unreachable block (ram,0xf003bde8) */
/* WARNING: Removing unreachable block (ram,0xf003be18) */
/* WARNING: Removing unreachable block (ram,0xf003be60) */
/* WARNING: Removing unreachable block (ram,0xf003bdc4) */
/* WARNING: Removing unreachable block (ram,0xf003bd14) */
/* WARNING: Removing unreachable block (ram,0xf003be50) */
/* WARNING: Removing unreachable block (ram,0xf003bef8) */
/* WARNING: Removing unreachable block (ram,0xf003bf28) */
/* WARNING: Removing unreachable block (ram,0xf003bf58) */
/* WARNING: Removing unreachable block (ram,0xf003bfa8) */
/* WARNING: Removing unreachable block (ram,0xf003bd84) */

undefined8 sub_F003BCD8(int param_1,undefined *param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined *puVar5;
  int iVar6;
  undefined4 unaff_l3;
  undefined *puVar7;
  undefined4 unaff_l4;
  undefined4 *puVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined *puVar9;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 uVar10;
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
  puVar5 = (undefined *)0x0;
  puVar8 = (undefined4 *)0x0;
  uVar10 = 0;
  puVar9 = (undefined *)0x0;
  puVar7 = (undefined *)0x0;
  _svstat = _svstat + 1;
  uVar4 = *(uint *)(param_1 + 8);
  iVar6 = 0;
  puVar2 = puVar9;
  if (uVar4 < 0x12) {
    if (*(int *)(param_1 + 4) == 2) {
      puVar5 = _rfsdisptab;
      puVar8 = (undefined4 *)(_rfsdisptab + uVar4 * 0x18);
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
      sub_F003BBE8();
      _bzero(puVar5,_rfssize);
      puVar2 = param_2;
      (**(code **)(*(int *)(param_2 + 8) + 8))
                (param_2,*(undefined4 *)(_rfsdisptab + uVar4 * 0x18 + 4),puVar5);
      if (puVar2 != (undefined *)0x0) {
        puVar3 = puVar2;
        if (uVar4 != 0) {
          _crget();
          uVar10 = *(undefined4 *)(_active_u + 0x1c);
          *(undefined **)(_active_u + 0x1c) = puVar2;
          puVar7 = puVar5;
          _findexport(puVar5,puVar5 + 0x14);
          puVar3 = puVar7;
          puVar9 = puVar2;
          if ((puVar7 != (undefined *)0x0) && (sub_F003C118(), puVar3 == (undefined *)0x0)) {
            _svcerr_weakauth(param_2);
            iVar1 = *(int *)(param_1 + 0x1c);
            puVar7 = aNfsServerWeakA;
            goto loc_F003BE44;
          }
        }
        sub_F003BBE8();
        _bzero(puVar3,_rfssize);
        *(int *)(unk_F013A8D8 + uVar4 * 4) = *(int *)(unk_F013A8D8 + uVar4 * 4) + 1;
        (*(code *)*puVar8)(puVar5,puVar3,puVar7,param_1);
        goto loc_F003BEB0;
      }
      _svcerr_decode(param_2);
      iVar1 = *(int *)(param_1 + 0x1c);
      puVar7 = aNfsServerBadGe;
      puVar2 = puVar9;
    }
    else {
      _svcerr_progvers(*(undefined4 *)(param_1 + 0x1c),2,2);
      iVar1 = *(int *)(param_1 + 0x1c);
      puVar7 = aNfsServerBadVe;
    }
  }
  else {
    _svcerr_noproc(*(undefined4 *)(param_1 + 0x1c));
    iVar1 = *(int *)(param_1 + 0x1c);
    puVar7 = aNfsServerBadPr;
  }
loc_F003BE44:
  iVar6 = 1;
  iVar1 = iVar1 + 0x14;
  _inet_ntoa(iVar1);
  _printf(puVar7,iVar1);
  puVar3 = (undefined *)0x0;
  puVar9 = puVar2;
loc_F003BEB0:
  if ((puVar8 != (undefined4 *)0x0) &&
     (puVar2 = param_2, (**(code **)(*(int *)(param_2 + 8) + 0x10))(param_2,puVar8[1],puVar5),
     puVar2 == (undefined *)0x0)) {
    iVar6 = iVar6 + 1;
    iVar1 = *(int *)(param_1 + 0x1c) + 0x14;
    _inet_ntoa(iVar1);
    _printf(aNfsServerBadFr,iVar1);
  }
  if (puVar5 != (undefined *)0x0) {
    sub_F003BCBC(puVar5);
  }
  if ((iVar6 == 0) &&
     (puVar2 = param_2, _svc_sendreply(param_2,puVar8[3],puVar3), puVar2 == (undefined *)0x0)) {
    iVar6 = 1;
    iVar1 = *(int *)(param_1 + 0x1c) + 0x14;
    _inet_ntoa(iVar1);
    _printf(aNfsServerBadSe,iVar1);
  }
  if (puVar3 != (undefined *)0x0) {
    if ((code *)puVar8[5] != sub_F003BBDC) {
      (*(code *)puVar8[5])(puVar3);
    }
    sub_F003BCBC(puVar3);
  }
  if (puVar9 != (undefined *)0x0) {
    *(undefined4 *)(_active_u + 0x1c) = uVar10;
    _crfree(puVar9);
  }
  DAT_f013a8d4 = DAT_f013a8d4 + iVar6;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3322 start=0xf003bfcc */

/* WARNING: Removing unreachable block (ram,0xf003bfd0) */

undefined8 sub_F003BFCC(undefined4 *param_1,int param_2)

{
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
  _vattr_null(param_2);
  *(sword *)(param_2 + 4) = (sword)*param_1;
  *(sword *)(param_2 + 6) = (sword)param_1[1];
  *(sword *)(param_2 + 8) = (sword)param_1[2];
  *(undefined4 *)(param_2 + 0x18) = param_1[3];
  *(undefined4 *)(param_2 + 0x20) = param_1[4];
  *(undefined4 *)(param_2 + 0x24) = param_1[5];
  *(undefined4 *)(param_2 + 0x28) = param_1[6];
  *(undefined4 *)(param_2 + 0x2c) = param_1[7];
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3323 start=0xf003c020 */

/* WARNING: Removing unreachable block (ram,0xf003c030) */

undefined8 sub_F003C020(int param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    _getvfs();
    if (param_1 != 0) {
      (**(code **)(*(int *)(param_1 + 4) + 0x14))();
      iVar1 = 0;
      if ((param_1 != 0) || (iVar1 = *(int *)((int)register0x00000038 + -0xc), iVar1 != 0))
      goto locret_F003C074;
    }
    iVar1 = 0;
  }
locret_F003C074:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3324 start=0xf003c07c */

undefined8 sub_F003C07C(sword *param_1,sword *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
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
  if (*param_1 == *param_2) {
    if (*param_1 == 2) {
      uVar1 = (uint)(*(int *)(param_1 + 2) == *(int *)(param_2 + 2));
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3325 start=0xf003c0bc */

/* WARNING: Removing unreachable block (ram,0xf003c0e0) */

undefined8 sub_F003C0BC(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  uVar2 = 0;
  if (*param_2 == 0) {
    uVar3 = 0;
  }
  else {
    do {
      iVar1 = param_1;
      sub_F003C07C(param_1,param_2[1] + uVar2 * 0x10);
      if (iVar1 != 0) {
        uVar3 = 1;
        goto locret_F003C110;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *param_2);
    uVar3 = 0;
  }
locret_F003C110:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3326 start=0xf003c118 */

/* WARNING: Removing unreachable block (ram,0xf003c1a8) */
/* WARNING: Removing unreachable block (ram,0xf003c148) */
/* WARNING: Removing unreachable block (ram,0xf003c154) */

undefined8 sub_F003C118(int param_1,int param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
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
  if (_nfs_portmon == 0) {
    iVar3 = *(int *)(param_2 + 0xc);
  }
  else {
    iVar3 = *(int *)(param_2 + 0x1c) + 0x14;
    if (0x3ff < *(word *)(*(int *)(param_2 + 0x1c) + 0x12)) {
      _inet_ntoa(iVar3);
      _printf(aNfsRequestFrom,iVar3);
      uVar6 = 0;
      goto locret_F003C250;
    }
    iVar3 = *(int *)(param_2 + 0xc);
  }
  if (iVar3 != *(int *)(param_1 + 8)) {
    iVar3 = 0;
  }
  if (iVar3 == 0) {
loc_F003C1BC:
    *(sword *)(param_3 + 2) = (sword)*(undefined4 *)(param_1 + 4);
    puVar4 = (undefined2 *)(param_3 + 10);
    *(sword *)(param_3 + 4) = (sword)*(undefined4 *)(param_1 + 4);
  }
  else {
    if (iVar3 != 1) {
      uVar6 = 0;
      goto locret_F003C250;
    }
    iVar3 = *(int *)(param_2 + 0x18);
    if (*(int *)(iVar3 + 8) == 0) {
      iVar2 = *(int *)(param_2 + 0x1c) + 0x10;
      sub_F003C0BC(iVar2,param_1 + 0xc);
      if (iVar2 == 0) goto loc_F003C1BC;
      *(sword *)(param_3 + 2) = (sword)*(undefined4 *)(iVar3 + 8);
    }
    else {
      *(sword *)(param_3 + 2) = (sword)*(int *)(iVar3 + 8);
    }
    *(sword *)(param_3 + 4) = (sword)*(undefined4 *)(iVar3 + 0xc);
    iVar2 = *(int *)(iVar3 + 0x10);
    iVar5 = *(int *)(iVar3 + 0x14);
    for (puVar4 = (undefined2 *)(param_3 + 10); puVar4 < (undefined2 *)(param_3 + iVar2 * 2 + 10);
        puVar4 = puVar4 + 1) {
      *puVar4 = *(undefined2 *)(iVar5 + 2);
      iVar5 = iVar5 + 4;
      iVar2 = *(int *)(iVar3 + 0x10);
    }
  }
  if (puVar4 < (undefined2 *)(param_3 + 0x2a)) {
    *puVar4 = 0xffff;
    while (puVar4 = puVar4 + 1, puVar4 < (undefined2 *)(param_3 + 0x2a)) {
      *puVar4 = 0xffff;
    }
    sVar1 = *(sword *)(param_3 + 2);
  }
  else {
    sVar1 = *(sword *)(param_3 + 2);
  }
  uVar6 = (uint)(sVar1 != -1);
locret_F003C250:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=3327 start=0xf003c258 */

/* WARNING: Removing unreachable block (ram,0xf003c2d0) */
/* WARNING: Removing unreachable block (ram,0xf003c298) */
/* WARNING: Removing unreachable block (ram,0xf003c2ec) */
/* WARNING: Removing unreachable block (ram,0xf003c308) */

undefined8 sub_F003C258(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  iVar2 = *(int *)(param_1 + 0x5c);
  while ((1 < iVar2 || (iVar4 = _MAXCLIENTS, iVar2 < 0))) {
    _printf(aAuthgetUnknown);
    iVar2 = 0;
  }
  do {
    iVar2 = _nextunixvictim._0_4_ + 1;
    iVar3 = _nextunixvictim._0_4_ * 8;
    _nextunixvictim._0_4_ = iVar2;
    .urem(iVar2,_MAXCLIENTS);
    _nextunixvictim._0_4_ = iVar2;
    if (*(sword *)(_unixauthtab + iVar3) == 0) break;
    iVar4 = iVar4 + -1;
  } while (0 < iVar4);
  if (*(sword *)(_unixauthtab + iVar3) == 0) {
    uVar1 = 1;
    if (*(int *)(_unixauthtab + iVar3 + 4) == 0) {
      _authkern_create();
      *(undefined4 *)(_unixauthtab + iVar3 + 4) = uVar1;
    }
    *(undefined2 *)(_unixauthtab + iVar3) = 1;
    iVar2 = *(int *)(_unixauthtab + iVar3 + 4);
  }
  else {
    _authkern_create();
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3328 start=0xf003c320 */

/* WARNING: Removing unreachable block (ram,0xf003c39c) */

undefined8 sub_F003C320(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined *puVar2;
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
  if ((*param_1 < 2) && (-1 < *param_1)) {
    puVar2 = _unixauthtab;
    piVar1 = (int *)DAT_f013aba4._0_4_;
    if (_unixauthtab + _MAXCLIENTS * 8 < _unixauthtab + 1) {
loc_F003C380:
      (**(code **)(param_1[8] + 0x10))(param_1);
    }
    else {
      while (piVar1 != param_1) {
        if (_unixauthtab + _MAXCLIENTS * 8 <= (undefined2 *)((int)puVar2 + 8)) goto loc_F003C380;
        piVar1 = *(int **)((int)puVar2 + 0xc);
        puVar2 = (undefined *)((int)puVar2 + 8);
      }
      *(undefined2 *)puVar2 = 0;
    }
  }
  else {
    _printf(aAuthfreeUnknow,*param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3329 start=0xf003c3ac */

/* WARNING: Removing unreachable block (ram,0xf003c5a8) */
/* WARNING: Removing unreachable block (ram,0xf003c570) */
/* WARNING: Removing unreachable block (ram,0xf003c4d4) */
/* WARNING: Removing unreachable block (ram,0xf003c46c) */
/* WARNING: Removing unreachable block (ram,0xf003c454) */
/* WARNING: Removing unreachable block (ram,0xf003c4ac) */
/* WARNING: Removing unreachable block (ram,0xf003c500) */
/* WARNING: Removing unreachable block (ram,0xf003c590) */
/* WARNING: Removing unreachable block (ram,0xf003c5c8) */
/* WARNING: Removing unreachable block (ram,0xf003c558) */
/* WARNING: Removing unreachable block (ram,0xf003c4a0) */

undefined8 sub_F003C3AC(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
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
  if ((param_1[5] & 0x90000000U) == 0x10000000) {
    iVar2 = 1;
  }
  else {
    iVar2 = param_1[0xc];
  }
  puVar3 = _chtable;
  DAT_f013a9b4._0_4_ = DAT_f013a9b4._0_4_ + 1;
  if (_chtable < _chtable + _MAXCLIENTS * 0xc) {
    piVar4 = (int *)(_chtable + 8);
    do {
      if (piVar4[-1] == 0) {
        piVar4[-1] = 1;
        if (*piVar4 == 0) {
          piVar1 = param_1;
          _clntkudp_create(param_1,0x186a3,2,iVar2,param_2);
          *piVar4 = (int)piVar1;
          if (piVar1 == (int *)0x0) {
            _panic(aClgetNullClien);
          }
          (**(code **)(*(int *)(*(int *)*piVar4 + 0x20) + 0x10))();
        }
        else {
          _clntkudp_init(*piVar4,param_1,iVar2,param_2);
        }
        piVar1 = param_1;
        sub_F003C258(param_1,param_2);
        *(int **)*piVar4 = piVar1;
        if (*(int *)*piVar4 == 0) {
          _panic(aClgetNullAuth);
          iVar2 = *(int *)puVar3;
        }
        else {
          iVar2 = *(int *)puVar3;
        }
        *(int *)puVar3 = iVar2 + 1;
        if ((param_1[5] & 0xa0000000U) == 0xa0000000) {
          _clntkudp_interruptable(*piVar4,1);
          piVar4 = (int *)*piVar4;
        }
        else {
          piVar4 = (int *)*piVar4;
        }
        goto locret_F003C5D0;
      }
      puVar3 = (undefined *)((int)puVar3 + 0xc);
      piVar4 = piVar4 + 3;
    } while (puVar3 < _chtable + _MAXCLIENTS * 0xc);
  }
  _cltoomany = _cltoomany + 1;
  piVar4 = param_1;
  _clntkudp_create(param_1,0x186a3,2,iVar2,param_2);
  if (piVar4 == (int *)0x0) {
    _panic(aClgetNullClien_0);
    iVar2 = iRam00000000;
  }
  else {
    iVar2 = *piVar4;
  }
  (**(code **)(*(int *)(iVar2 + 0x20) + 0x10))();
  piVar1 = param_1;
  sub_F003C258(param_1,param_2);
  *piVar4 = (int)piVar1;
  if (piVar1 == (int *)0x0) {
    _panic(aClgetNullAuth_0);
  }
  if ((param_1[5] & 0xa0000000U) == 0xa0000000) {
    _clntkudp_interruptable(piVar4,1);
  }
locret_F003C5D0:
  return CONCAT44(param_2,piVar4);
}
/* GHIDRADEC_FUNCTION index=3330 start=0xf003c6f0 */

/* WARNING: Removing unreachable block (ram,0xf003c6fc) */
/* WARNING: Removing unreachable block (ram,0xf003c6f4) */

undefined8 sub_F003C6F0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
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
  sub_F003C320(*param_1);
  _clntkudp_freecred(param_1);
  *param_1 = 0;
  puVar2 = _chtable;
  if (_chtable < _chtable + _MAXCLIENTS * 0xc) {
    puVar1 = (undefined4 *)(_chtable + 4);
    do {
      puVar2 = puVar2 + 0xc;
      if ((undefined4 *)puVar1[1] == param_1) {
        *puVar1 = 0;
        goto locret_F003C76C;
      }
      puVar1 = puVar1 + 3;
    } while (puVar2 < _chtable + _MAXCLIENTS * 0xc);
  }
  (**(code **)(param_1[1] + 0x10))(param_1);
locret_F003C76C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3331 start=0xf003cef4 */

qword sub_F003CEF4(int param_1)

{
  byte bVar1;
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
  *(undefined4 *)(param_1 + 8) =
       *(undefined4 *)
        (_rtable +
        ((byte)(*(byte *)(param_1 + 0x5b) ^
               *(byte *)(param_1 + 0x5a) ^
               *(byte *)(param_1 + 0x59) ^
               *(byte *)(param_1 + 0x58) ^
               *(byte *)(param_1 + 0x57) ^
               *(byte *)(param_1 + 0x56) ^
               *(byte *)(param_1 + 0x55) ^
               *(byte *)(param_1 + 0x54) ^
               *(byte *)(param_1 + 0x51) ^
               *(byte *)(param_1 + 0x50) ^
               *(byte *)(param_1 + 0x4f) ^
               *(byte *)(param_1 + 0x4e) ^
               *(byte *)(param_1 + 0x4d) ^
               *(byte *)(param_1 + 0x4c) ^ *(byte *)(param_1 + 0x4a) ^ *(byte *)(param_1 + 0x4b)) &
        0x3f) * 4);
  bVar1 = *(byte *)(param_1 + 0x59) ^
          *(byte *)(param_1 + 0x58) ^
          *(byte *)(param_1 + 0x57) ^
          *(byte *)(param_1 + 0x56) ^
          *(byte *)(param_1 + 0x55) ^
          *(byte *)(param_1 + 0x54) ^
          *(byte *)(param_1 + 0x51) ^
          *(byte *)(param_1 + 0x50) ^
          *(byte *)(param_1 + 0x4f) ^
          *(byte *)(param_1 + 0x4e) ^
          *(byte *)(param_1 + 0x4d) ^
          *(byte *)(param_1 + 0x4c) ^ *(byte *)(param_1 + 0x4a) ^ *(byte *)(param_1 + 0x4b);
  *(int *)(_rtable +
          ((byte)(*(byte *)(param_1 + 0x5b) ^ *(byte *)(param_1 + 0x5a) ^ bVar1) & 0x3f) * 4) =
       param_1;
  _rnhash = _rnhash + 1;
  return (qword)CONCAT14(bVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=3332 start=0xf003d1ac */

undefined8 sub_F003D1AC(int *param_1,int param_2)

{
  int *piVar1;
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
  
  piVar1 = _rpfreelist;
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
  if (*param_1 != 0) goto locret_F003D20C;
  if (_rpfreelist == (int *)0x0) {
    *param_1 = (int)param_1;
    param_1[1] = (int)param_1;
loc_F003D1F8:
    _rpfreelist = param_1;
  }
  else {
    *param_1 = (int)_rpfreelist;
    param_1[1] = piVar1[1];
    *(int **)piVar1[1] = param_1;
    piVar1[1] = (int)param_1;
    if (param_2 != 0) goto loc_F003D1F8;
  }
  _rnfree = _rnfree + 1;
locret_F003D20C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3333 start=0xf003d214 */

undefined8 sub_F003D214(int *param_1,undefined *param_2)

{
  int *piVar1;
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
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    param_2 = aNfsServerSOk_0;
    if (piVar1 == param_1) {
      _rpfreelist = (int *)0x0;
    }
    else {
      if (param_1 == _rpfreelist) {
        _rpfreelist = piVar1;
      }
      *(int *)param_1[1] = *param_1;
      *(int *)(*param_1 + 4) = param_1[1];
    }
    param_1[1] = 0;
    *param_1 = 0;
    _rnfree = _rnfree + -1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3334 start=0xf003d2e0 */

/* WARNING: Removing unreachable block (ram,0xf003d3d8) */
/* WARNING: Removing unreachable block (ram,0xf003d40c) */
/* WARNING: Removing unreachable block (ram,0xf003d394) */

undefined8 sub_F003D2E0(int param_1,int param_2)

{
  int iVar1;
  sword sVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  iVar3 = *(int *)(_rtable +
                  ((byte)(*(byte *)(param_1 + 0x1b) ^
                         *(byte *)(param_1 + 0x1a) ^
                         *(byte *)(param_1 + 0x19) ^
                         *(byte *)(param_1 + 0x18) ^
                         *(byte *)(param_1 + 0x17) ^
                         *(byte *)(param_1 + 0x16) ^
                         *(byte *)(param_1 + 0x15) ^
                         *(byte *)(param_1 + 0x14) ^
                         *(byte *)(param_1 + 0x11) ^
                         *(byte *)(param_1 + 0x10) ^
                         *(byte *)(param_1 + 0xf) ^
                         *(byte *)(param_1 + 0xe) ^
                         *(byte *)(param_1 + 0xd) ^
                         *(byte *)(param_1 + 0xc) ^
                         *(byte *)(param_1 + 10) ^ *(byte *)(param_1 + 0xb)) & 0x3f) * 4);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    do {
      iVar1 = iVar3 + 0x40;
      _bcmp(iVar1,param_1,0x20);
      if (iVar1 == 0) {
        if (param_2 == *(int *)(iVar3 + 0x30)) {
          sVar2 = *(sword *)(iVar3 + 0x12) + 1;
          *(sword *)(iVar3 + 0x12) = sVar2;
          if (sVar2 == 1) {
            sub_F003D214(iVar3);
            iVar1 = *(int *)(*(int *)(iVar3 + 0x30) + 0x128);
            _rreactive._0_4_ = _rreactive._0_4_ + 1;
            *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
          }
          else {
            _ractive._0_4_ = _ractive._0_4_ + 1;
          }
          sub_F003D214(iVar3);
          goto locret_F003D428;
        }
        iVar3 = *(int *)(iVar3 + 8);
      }
      else {
        iVar3 = *(int *)(iVar3 + 8);
      }
    } while (iVar3 != 0);
    iVar3 = 0;
  }
locret_F003D428:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=3335 start=0xf003d710 */

/* WARNING: Removing unreachable block (ram,0xf003d72c) */

undefined8 sub_F003D710(int param_1,undefined4 param_2)

{
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
  _rlock_awaken_count = _rlock_awaken_count + 1;
  if (param_1 != 0) {
    _wakeup(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3336 start=0xf003d850 */

/* WARNING: Removing unreachable block (ram,0xf003d908) */
/* WARNING: Removing unreachable block (ram,0xf003dae8) */
/* WARNING: Removing unreachable block (ram,0xf003dc10) */
/* WARNING: Removing unreachable block (ram,0xf003dd20) */
/* WARNING: Removing unreachable block (ram,0xf003dd08) */
/* WARNING: Removing unreachable block (ram,0xf003dcf8) */
/* WARNING: Removing unreachable block (ram,0xf003dcbc) */
/* WARNING: Removing unreachable block (ram,0xf003dc48) */
/* WARNING: Removing unreachable block (ram,0xf003dc38) */
/* WARNING: Removing unreachable block (ram,0xf003dbe8) */
/* WARNING: Removing unreachable block (ram,0xf003db74) */
/* WARNING: Removing unreachable block (ram,0xf003db48) */
/* WARNING: Removing unreachable block (ram,0xf003db00) */
/* WARNING: Removing unreachable block (ram,0xf003da64) */
/* WARNING: Removing unreachable block (ram,0xf003da2c) */
/* WARNING: Removing unreachable block (ram,0xf003da04) */
/* WARNING: Removing unreachable block (ram,0xf003d988) */
/* WARNING: Removing unreachable block (ram,0xf003d940) */
/* WARNING: Removing unreachable block (ram,0xf003d8e0) */
/* WARNING: Removing unreachable block (ram,0xf003d868) */
/* WARNING: Removing unreachable block (ram,0xf003d8a0) */
/* WARNING: Removing unreachable block (ram,0xf003d920) */
/* WARNING: Removing unreachable block (ram,0xf003d954) */
/* WARNING: Removing unreachable block (ram,0xf003d9a0) */
/* WARNING: Removing unreachable block (ram,0xf003da18) */
/* WARNING: Removing unreachable block (ram,0xf003da40) */
/* WARNING: Removing unreachable block (ram,0xf003daa4) */
/* WARNING: Removing unreachable block (ram,0xf003db0c) */
/* WARNING: Removing unreachable block (ram,0xf003db5c) */
/* WARNING: Removing unreachable block (ram,0xf003dba4) */
/* WARNING: Removing unreachable block (ram,0xf003dc30) */
/* WARNING: Removing unreachable block (ram,0xf003dc40) */
/* WARNING: Removing unreachable block (ram,0xf003dca4) */
/* WARNING: Removing unreachable block (ram,0xf003dcec) */
/* WARNING: Removing unreachable block (ram,0xf003dd00) */
/* WARNING: Removing unreachable block (ram,0xf003dd18) */
/* WARNING: Removing unreachable block (ram,0xf003dd2c) */
/* WARNING: Removing unreachable block (ram,0xf003dc1c) */
/* WARNING: Removing unreachable block (ram,0xf003dad4) */
/* WARNING: Removing unreachable block (ram,0xf003dc24) */
/* WARNING: Removing unreachable block (ram,0xf003d860) */

undefined8 sub_F003D850(int param_1,undefined4 *param_2,char *param_3)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar6;
  char *pcVar7;
  undefined4 unaff_l3;
  undefined *puVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  char *pcVar9;
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
  _getfsname(&aRoot,param_3);
  _pn_alloc((undefined *)((int)register0x00000038 + -0x150));
  puVar6 = *(undefined **)((int)register0x00000038 + -0x14c);
  bVar2 = false;
  cVar1 = *param_3;
  while( true ) {
    puVar3 = param_3;
    if (cVar1 == '\0') {
      puVar3 = (undefined *)&aRoot_0;
    }
    sub_F003E1D4(puVar3,(undefined *)((int)register0x00000038 + -0x120),
                 (undefined *)((int)register0x00000038 + -0x18),puVar6);
    if ((puVar3 == (char *)0x3c) && (!bVar2)) {
      pcVar7 = param_3;
      if (*param_3 == '\0') {
        pcVar7 = (char *)&aRoot_1;
      }
      _printf(DAT_f010d0f0._0_4_,pcVar7);
      bVar2 = true;
    }
    if (puVar3 != (char *)0x3c) break;
    cVar1 = *param_3;
  }
  if (puVar3 == (char *)0x0) {
    if (bVar2) {
      _printf(aBootparamRespo);
    }
    pcVar7 = (char *)((int)register0x00000038 + -0x18);
    puVar8 = (undefined *)((int)register0x00000038 + -0x120);
    puVar3 = pcVar7;
    sub_F003E3AC(pcVar7,puVar8,puVar6,(undefined *)((int)register0x00000038 + -0x140));
    if (puVar3 != (char *)0x0) {
      _pn_free((undefined *)((int)register0x00000038 + -0x150));
      puVar8 = aMountRootSSFai;
loc_F003DB70:
      _printf(puVar8,(undefined *)((int)register0x00000038 + -0x120),puVar6,puVar3);
      goto locret_F003DD34;
    }
    puVar3 = (undefined *)((int)register0x00000038 + -0x174);
    sub_F003E87C(puVar3,param_1,pcVar7,(undefined *)((int)register0x00000038 + -0x140),puVar8,0,
                 0xffffffff,0);
    pcVar7 = (char *)0x0;
    if ((puVar3 == (char *)0x0) && (_vfs_add(0,param_1,0), puVar3 = pcVar7, pcVar7 == (char *)0x0))
    {
      *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x60) = 0xe10;
      *(undefined4 *)(*(int *)(param_1 + 0x128) + 100) = 36000;
      bVar2 = false;
      *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x68) = 0xe10;
      *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x6c) = 36000;
      iVar4 = *(int *)((int)register0x00000038 + -0x174);
      *(uint *)(*(int *)(param_1 + 0x128) + 0x14) =
           *(uint *)(*(int *)(param_1 + 0x128) + 0x14) | 0x4000000;
      _vfs_unlock(*(undefined4 *)(iVar4 + 0x24));
      *param_2 = *(undefined4 *)((int)register0x00000038 + -0x174);
      _strcpy(param_3,puVar8);
      *param_3 = ':';
      _strcpy(param_3 + 1,puVar6);
      *(undefined *)((int)register0x00000038 + -0x170) = 0;
      _getfsname(&aPrivate_2,(undefined *)((int)register0x00000038 + -0x170));
      cVar1 = *(char *)((int)register0x00000038 + -0x170);
      while( true ) {
        puVar3 = (undefined *)((int)register0x00000038 + -0x170);
        if (cVar1 == '\0') {
          puVar3 = (undefined *)&aPrivate_3;
        }
        sub_F003E1D4(puVar3,(undefined *)((int)register0x00000038 + -0x120),
                     (undefined *)((int)register0x00000038 + -0x18),puVar6);
        if ((puVar3 == (char *)0x3c) && (!bVar2)) {
          if (*(char *)((int)register0x00000038 + -0x170) == '\0') {
            puVar5 = &aPrivate_4;
          }
          else {
            puVar5 = (undefined8 *)((int)register0x00000038 + -0x170);
          }
          _printf(DAT_f010d0f0._0_4_,puVar5);
          bVar2 = true;
        }
        if (puVar3 != (char *)0x3c) break;
        cVar1 = *(char *)((int)register0x00000038 + -0x170);
      }
      if (puVar3 == (char *)0x0) {
        if (bVar2) {
          _printf(aBootparamRespo_0);
        }
        puVar3 = puVar6;
        _index(puVar6,0x40);
        if (puVar3 == (undefined *)0x0) {
          puVar3 = aPrivate_5;
        }
        else {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        pcVar9 = (char *)((int)register0x00000038 + -0x18);
        pcVar7 = pcVar9;
        sub_F003E3AC(pcVar9,(undefined *)((int)register0x00000038 + -0x120),puVar6,
                     (undefined *)((int)register0x00000038 + -0x140));
        if (pcVar7 != (char *)0x0) {
          _pn_free((undefined *)((int)register0x00000038 + -0x150));
          puVar8 = aMountPrivateSS;
          puVar3 = pcVar7;
          goto loc_F003DB70;
        }
        iVar4 = _rootvfs;
        (**(code **)(*(int *)(_rootvfs + 4) + 8))(_rootvfs,&_rootdir);
        if (iVar4 != 0) {
          _panic(aNfsMountrootCa);
        }
        *(undefined4 *)(_active_u + 0x15c) = _rootdir;
        *(sword *)(*(int *)(_active_u + 0x15c) + 6) =
             *(sword *)(*(int *)(_active_u + 0x15c) + 6) + 1;
        *(undefined4 *)(_active_u + 0x160) = 0;
        _lookupname(puVar3,1,1,0,(undefined *)((int)register0x00000038 + -0x178));
        if ((puVar3 == (char *)0x0) && (*(int *)((int)register0x00000038 + -0x178) != 0)) {
          _vn_rele(*(undefined4 *)(_active_u + 0x15c));
          _vn_rele(_rootdir);
          _dnlc_purge();
          param_2 = (undefined4 *)0x12c;
          _kalloc();
          *param_2 = 0;
          param_2[1] = _nfs_vfsops;
          param_2[3] = 0;
          param_2[7] = 0;
          param_2[0x4a] = 0;
          param_2[0x48] = 0;
          puVar3 = (undefined *)((int)register0x00000038 + -0x174);
          *(undefined2 *)(param_2 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
          sub_F003E87C(puVar3,param_2,pcVar9,(undefined *)((int)register0x00000038 + -0x140),
                       (undefined *)((int)register0x00000038 + -0x120),0,0xffffffff,0);
          pcVar7 = *(char **)((int)register0x00000038 + -0x178);
          if (puVar3 == (char *)0x0) {
            _vfs_add(pcVar7,param_2,0);
            if (pcVar7 == (char *)0x0) {
              *(undefined4 *)(*(int *)(param_1 + 0x128) + 100) = 6000;
              *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x6c) = 6000;
              _strncpy(param_1 + 0x20,*(undefined4 *)((int)register0x00000038 + -0x14c),0xff);
              _vfs_unlock(*(undefined4 *)(*(int *)((int)register0x00000038 + -0x174) + 0x24));
              _nfs_netboot_prealloc(*(undefined4 *)(param_1 + 0x128));
              _pn_free((undefined *)((int)register0x00000038 + -0x150));
              puVar3 = (char *)0x0;
              goto locret_F003DD34;
            }
            sub_F003EAF0(param_2);
            puVar3 = pcVar7;
          }
          _pn_free((undefined *)((int)register0x00000038 + -0x150));
          _kfree(param_2,300);
          goto locret_F003DD34;
        }
        _printf(aNfsMountrootNo);
        _vn_rele(*(undefined4 *)(_active_u + 0x15c));
      }
      else if (puVar3 == (char *)0x16) {
        _printf(aUsingPrivateFr);
        puVar3 = (char *)0x0;
      }
      else {
        _printf(aRpcErrorDuring_0,puVar3);
      }
    }
  }
  else {
    _printf(aRpcErrorDuring,puVar3);
  }
  _pn_free((undefined *)((int)register0x00000038 + -0x150));
locret_F003DD34:
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=3337 start=0xf003dd3c */

/* WARNING: Removing unreachable block (ram,0xf003dd8c) */
/* WARNING: Removing unreachable block (ram,0xf003ddf0) */
/* WARNING: Removing unreachable block (ram,0xf003dd74) */

undefined8
sub_F003DD3C(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_l3;
  undefined4 *puVar4;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  puVar4 = *(undefined4 **)((int)register0x00000038 + 100);
  uVar3 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x60);
  *(undefined2 *)(param_1 + 2) = 0x6f;
  iVar2 = *(int *)((int)register0x00000038 + 0x68);
  _clntkudp_create(param_1,100000,2,5,*(undefined4 *)(_active_u + 0x1c));
  if (param_1 == 0) {
    _panic(aPmapRmtcallCln);
    *(undefined4 *)((int)register0x00000038 + -0x20) = param_2;
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x20) = param_2;
  }
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_6;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_5;
  *(undefined **)((int)register0x00000038 + -0x30) = (undefined *)((int)register0x00000038 + -0x34);
  *(undefined4 *)((int)register0x00000038 + -0x28) = uVar5;
  *(undefined4 *)((int)register0x00000038 + -0x24) = uVar3;
  *(undefined4 *)((int)register0x00000038 + -0x40) = *puVar4;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = puVar4[1];
  iVar1 = param_1;
  _clntkudp_callit_addr
            (param_1,5,_xdr_rmtcall_args,(undefined *)((int)register0x00000038 + -0x20),
             _xdr_rmtcallres,(undefined *)((int)register0x00000038 + -0x30),
             (undefined *)((int)register0x00000038 + -0x40),iVar2);
  if (iVar2 != 0) {
    *(sword *)(iVar2 + 2) = (sword)*(undefined4 *)((int)register0x00000038 + -0x34);
  }
  (**(code **)(*(int *)(param_1 + 4) + 0x10))(param_1);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3338 start=0xf003de24 */

/* WARNING: Removing unreachable block (ram,0xf003e11c) */
/* WARNING: Removing unreachable block (ram,0xf003e0d8) */
/* WARNING: Removing unreachable block (ram,0xf003e0fc) */
/* WARNING: Removing unreachable block (ram,0xf003e0ac) */
/* WARNING: Removing unreachable block (ram,0xf003e04c) */
/* WARNING: Removing unreachable block (ram,0xf003dff8) */
/* WARNING: Removing unreachable block (ram,0xf003dfc0) */
/* WARNING: Removing unreachable block (ram,0xf003df64) */
/* WARNING: Removing unreachable block (ram,0xf003df2c) */
/* WARNING: Removing unreachable block (ram,0xf003def8) */
/* WARNING: Removing unreachable block (ram,0xf003ded0) */
/* WARNING: Removing unreachable block (ram,0xf003dea8) */
/* WARNING: Removing unreachable block (ram,0xf003de78) */
/* WARNING: Removing unreachable block (ram,0xf003de54) */
/* WARNING: Removing unreachable block (ram,0xf003de68) */
/* WARNING: Removing unreachable block (ram,0xf003de8c) */
/* WARNING: Removing unreachable block (ram,0xf003dec4) */
/* WARNING: Removing unreachable block (ram,0xf003dee4) */
/* WARNING: Removing unreachable block (ram,0xf003df14) */
/* WARNING: Removing unreachable block (ram,0xf003df50) */
/* WARNING: Removing unreachable block (ram,0xf003df70) */
/* WARNING: Removing unreachable block (ram,0xf003dfe8) */
/* WARNING: Removing unreachable block (ram,0xf003e028) */
/* WARNING: Removing unreachable block (ram,0xf003e09c) */
/* WARNING: Removing unreachable block (ram,0xf003e0b4) */
/* WARNING: Removing unreachable block (ram,0xf003e084) */
/* WARNING: Removing unreachable block (ram,0xf003e110) */
/* WARNING: Removing unreachable block (ram,0xf003e128) */
/* WARNING: Removing unreachable block (ram,0xf003de4c) */

undefined8 sub_F003DE24(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar8;
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
  puVar8 = (undefined *)0x0;
  if (dword_F010D2C8 != 0) goto locret_F003E130;
  dword_F010D2C8 = 1;
  _bzero((undefined *)((int)register0x00000038 + -0x18),0x10);
  iVar2 = 2;
  _ifb_ifwithaf();
  puVar8 = aNfsServerSOk_0;
  if (iVar2 == 0) {
    _printf(aWhoamiZeroIfp);
    puVar8 = (undefined *)0x41;
    goto locret_F003E130;
  }
  _initrootnet();
  if (puVar8 != (undefined *)0x0) {
    _panic(aWhoamiInitroot);
  }
  puVar8 = (undefined *)0x0;
  _in_control(0,0xc0206912,(undefined *)((int)register0x00000038 + -0x58),iVar2);
  if (puVar8 != (undefined *)0x0) {
    _printf(aWhoamiInContro,puVar8,(int)*(sword *)(iVar2 + 0xc));
    _panic(aBadSiocgifbrda);
  }
  _bcopy((undefined *)((int)register0x00000038 + -0x48),
         (undefined *)((int)register0x00000038 + -0x18),0x10);
  _bcopy((undefined *)((int)register0x00000038 + -0x48),unk_F012F514,0x10);
  *(undefined4 *)((int)register0x00000038 + -0x20) = 1;
  iVar3 = 0;
  _in_control(0,0xc020690d,(undefined *)((int)register0x00000038 + -0x58),iVar2);
  if (iVar3 != 0) {
    _panic(aBadSiocgifaddr);
  }
  bVar1 = false;
  *(undefined4 *)((int)register0x00000038 + -0x5c) =
       *(undefined4 *)((int)register0x00000038 + -0x44);
  _bcopy((undefined *)((int)register0x00000038 + -0x5c),
         (undefined *)((int)register0x00000038 + -0x1c),4);
  *(undefined4 *)((int)register0x00000038 + -0x38) = 3;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0;
  uVar4 = 0x100;
  _kalloc();
  *(undefined4 *)((int)register0x00000038 + -0x30) = uVar4;
  uVar4 = 0x100;
  _kalloc();
  *(undefined4 *)((int)register0x00000038 + -0x2c) = uVar4;
  do {
    puVar5 = (undefined *)((int)register0x00000038 + -0x18);
    *(undefined4 *)((int)register0x00000038 + -0x68) =
         *(undefined4 *)((int)register0x00000038 + -0x38);
    *(undefined4 *)((int)register0x00000038 + -100) =
         *(undefined4 *)((int)register0x00000038 + -0x34);
    sub_F003DD3C(puVar5,0x186ba,1,1,_xdr_bp_whoami_arg,
                 (undefined *)((int)register0x00000038 + -0x20),_xdr_bp_whoami_res,
                 (undefined *)((int)register0x00000038 + -0x30),
                 (undefined *)((int)register0x00000038 + -0x68),0);
    if ((puVar5 == (undefined *)0x5) && (!bVar1)) {
      _printf(aNoBootparamSer);
      _printf(aWhoamiPmapRmtc,5);
      bVar1 = true;
    }
    *(undefined4 *)((int)register0x00000038 + -0x38) = 0x14;
    *(undefined4 *)((int)register0x00000038 + -0x34) = 0;
  } while (puVar5 == (undefined *)0x5);
  if (bVar1) {
    _printf(aBootparamRespo_1);
  }
  if (puVar5 == (undefined *)0x0) {
    uVar7 = *(uint *)((int)register0x00000038 + -0x30);
    _strlen();
    _hostnamelen = uVar7;
    if (uVar7 < 0x101) {
      if ((int)uVar7 < 1) {
        _printf(aWhoamiNoHostNa);
        puVar8 = (undefined *)0x6;
      }
      else {
        _bcopy(*(undefined4 *)((int)register0x00000038 + -0x30),_hostname);
        _printf(aHostnameS,_hostname);
        uVar7 = *(uint *)((int)register0x00000038 + -0x2c);
        _strlen();
        _domainnamelen = uVar7;
        if (0x100 < uVar7) {
          puVar5 = aWhoamiDomainna;
          goto loc_F003E0D8;
        }
        if (0 < (int)uVar7) {
          _bcopy(*(undefined4 *)((int)register0x00000038 + -0x2c),_domainname);
          puVar6 = aDomainnameS;
          puVar5 = _domainname;
          goto loc_F003E110;
        }
      }
      goto loc_F003E118;
    }
    puVar5 = aWhoamiHostname;
loc_F003E0D8:
    puVar8 = (undefined *)0x3f;
    _printf(puVar5);
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0x30);
  }
  else {
    puVar6 = aWhoamiRpcCallF;
    puVar8 = puVar5;
loc_F003E110:
    _printf(puVar6,puVar5);
loc_F003E118:
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0x30);
  }
  _kfree(uVar4,0x100);
  _kfree(*(undefined4 *)((int)register0x00000038 + -0x2c),0x100);
locret_F003E130:
  return CONCAT44(param_2,puVar8);
}
/* GHIDRADEC_FUNCTION index=3339 start=0xf003e138 */

/* WARNING: Removing unreachable block (ram,0xf003e15c) */

undefined8 sub_F003E138(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
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
  _clntkudp_create(param_1,param_2,param_3,5,*(undefined4 *)(_active_u + 0x1c));
  *(undefined4 *)((int)register0x00000038 + -0x10) = 3;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 3;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  piVar1 = param_1;
  (**(code **)param_1[1])();
  (**(code **)(*(int *)(*param_1 + 0x20) + 0x10))(*param_1);
  (**(code **)(param_1[1] + 0x10))(param_1);
  return CONCAT44(param_2,piVar1);
}
/* GHIDRADEC_FUNCTION index=3340 start=0xf003e1d4 */

/* WARNING: Removing unreachable block (ram,0xf003e398) */
/* WARNING: Removing unreachable block (ram,0xf003e314) */
/* WARNING: Removing unreachable block (ram,0xf003e2dc) */
/* WARNING: Removing unreachable block (ram,0xf003e2c4) */
/* WARNING: Removing unreachable block (ram,0xf003e22c) */
/* WARNING: Removing unreachable block (ram,0xf003e204) */
/* WARNING: Removing unreachable block (ram,0xf003e220) */
/* WARNING: Removing unreachable block (ram,0xf003e28c) */
/* WARNING: Removing unreachable block (ram,0xf003e2d0) */
/* WARNING: Removing unreachable block (ram,0xf003e2e8) */
/* WARNING: Removing unreachable block (ram,0xf003e370) */
/* WARNING: Removing unreachable block (ram,0xf003e35c) */
/* WARNING: Removing unreachable block (ram,0xf003e1fc) */

undefined8 sub_F003E1D4(undefined4 param_1,char *param_2,undefined2 *param_3,char *param_4)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar5;
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
  *(undefined4 *)((int)register0x00000038 + -0x28) = 5;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
  *(undefined **)((int)register0x00000038 + -0x10) = _hostname;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x20);
  puVar5 = puVar3;
  _bzero(puVar3,0x10);
  sub_F003DE24();
  if (puVar5 == (undefined *)0x0) {
    uVar1 = 0x100;
    _kalloc();
    *(undefined4 *)((int)register0x00000038 + -0x20) = uVar1;
    uVar1 = 0x100;
    _kalloc();
    *(undefined4 *)((int)register0x00000038 + -0x14) = uVar1;
    iVar4 = 0;
    do {
      puVar2 = unk_F012F514;
      *(undefined4 *)((int)register0x00000038 + -0x30) =
           *(undefined4 *)((int)register0x00000038 + -0x28);
      *(undefined4 *)((int)register0x00000038 + -0x2c) =
           *(undefined4 *)((int)register0x00000038 + -0x24);
      sub_F003DD3C(unk_F012F514,0x186ba,1,2,_xdr_bp_getfile_arg,
                   (undefined *)((int)register0x00000038 + -0x10),_xdr_bp_getfile_res,puVar3,
                   (undefined *)((int)register0x00000038 + -0x30),0);
      if (puVar2 != (undefined *)0x5) break;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
    uVar1 = *(undefined4 *)((int)register0x00000038 + -0x20);
    if (puVar2 == (undefined *)0x0) {
      _strcpy(param_2,*(undefined4 *)((int)register0x00000038 + -0x20));
      _strcpy(param_4,*(undefined4 *)((int)register0x00000038 + -0x14));
      uVar1 = *(undefined4 *)((int)register0x00000038 + -0x20);
    }
    _kfree(uVar1,0x100);
    _kfree(*(undefined4 *)((int)register0x00000038 + -0x14),0x100);
    if (puVar2 == (undefined *)0x0) {
      _bcopy((undefined *)((int)register0x00000038 + -0x18),
             (undefined *)((int)register0x00000038 + -0x34),4);
      if (*param_2 == '\0') {
        puVar5 = (undefined *)0x16;
      }
      else if ((*param_4 == '\0') || (*(int *)((int)register0x00000038 + -0x34) == 0)) {
        puVar5 = (undefined *)0x16;
      }
      else if (*(int *)((int)register0x00000038 + -0x1c) == 1) {
        _bzero(param_3,0x10);
        *param_3 = 2;
        *(undefined4 *)(param_3 + 2) = *(undefined4 *)((int)register0x00000038 + -0x34);
        _printf(aNfsMountingSFr,param_1,param_2,param_4);
        puVar5 = (undefined *)0x0;
      }
      else {
        _printf(aGetfileUnknown);
        puVar5 = (undefined *)0x2b;
      }
    }
    else {
      puVar5 = (undefined *)0x3c;
      if (puVar2 != (undefined *)0x5) {
        puVar5 = puVar2;
      }
    }
  }
  return CONCAT44(param_2,puVar5);
}
/* GHIDRADEC_FUNCTION index=3341 start=0xf003e3ac */

/* WARNING: Removing unreachable block (ram,0xf003e438) */
/* WARNING: Removing unreachable block (ram,0xf003e3f0) */
/* WARNING: Removing unreachable block (ram,0xf003e454) */
/* WARNING: Removing unreachable block (ram,0xf003e3cc) */

undefined8 sub_F003E3AC(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  do {
    iVar1 = param_1;
    _pmap_kgetport(param_1,0x186a5,1,0x11);
    if (iVar1 == -1) {
      iVar1 = 0xf;
locret_F003E4C4:
      return CONCAT44(param_2,iVar1);
    }
    if (iVar1 != 1) {
      while (iVar1 = param_1,
            sub_F003E138(param_1,0x186a5,1,1,_xdr_bp_path_t,
                         (undefined *)((int)register0x00000038 + 0x4c),_xdr_fhstatus,
                         (undefined *)((int)register0x00000038 + -0x30)), iVar1 == 5) {
        _printf(aMountnfsSSMoun,param_2,*(undefined4 *)((int)register0x00000038 + 0x4c));
      }
      if (iVar1 == 0) {
        *(undefined2 *)(param_1 + 2) = 0x801;
        *param_4 = *(undefined4 *)((int)register0x00000038 + -0x2c);
        param_4[1] = *(undefined4 *)((int)register0x00000038 + -0x28);
        param_4[2] = *(undefined4 *)((int)register0x00000038 + -0x24);
        param_4[3] = *(undefined4 *)((int)register0x00000038 + -0x20);
        param_4[4] = *(undefined4 *)((int)register0x00000038 + -0x1c);
        param_4[5] = *(undefined4 *)((int)register0x00000038 + -0x18);
        param_4[6] = *(undefined4 *)((int)register0x00000038 + -0x14);
        param_4[7] = *(undefined4 *)((int)register0x00000038 + -0x10);
        iVar1 = *(int *)((int)register0x00000038 + -0x30);
      }
      goto locret_F003E4C4;
    }
    _printf(aMountnfsSSPort,param_2,*(undefined4 *)((int)register0x00000038 + 0x4c));
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3342 start=0xf003e4cc */

/* WARNING: Removing unreachable block (ram,0xf003e848) */
/* WARNING: Removing unreachable block (ram,0xf003e7e8) */
/* WARNING: Removing unreachable block (ram,0xf003e798) */
/* WARNING: Removing unreachable block (ram,0xf003e738) */
/* WARNING: Removing unreachable block (ram,0xf003e5e0) */
/* WARNING: Removing unreachable block (ram,0xf003e560) */
/* WARNING: Removing unreachable block (ram,0xf003e538) */
/* WARNING: Removing unreachable block (ram,0xf003e510) */
/* WARNING: Removing unreachable block (ram,0xf003e580) */
/* WARNING: Removing unreachable block (ram,0xf003e5a4) */
/* WARNING: Removing unreachable block (ram,0xf003e728) */
/* WARNING: Removing unreachable block (ram,0xf003e780) */
/* WARNING: Removing unreachable block (ram,0xf003e7d8) */
/* WARNING: Removing unreachable block (ram,0xf003e830) */
/* WARNING: Removing unreachable block (ram,0xf003e86c) */
/* WARNING: Removing unreachable block (ram,0xf003e4f4) */

undefined8 sub_F003E4CC(int param_1,undefined4 param_2,undefined *param_3)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
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
  int iVar6;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  uVar1 = *(uint *)(param_1 + 0xc);
  *(undefined4 *)((int)register0x00000038 + -0x19c) = 0;
  if ((uVar1 & 0x40) != 0) {
    param_3 = (undefined *)0x0;
    goto locret_F003E874;
  }
  _copyin(param_3,(undefined *)((int)register0x00000038 + -400),0x34);
  puVar2 = *(undefined **)((int)register0x00000038 + -400);
  bVar7 = false;
  if (param_3 == (undefined *)0x0) {
    _copyin(puVar2,(undefined *)((int)register0x00000038 + -0x38),0x10);
    bVar7 = false;
    param_3 = puVar2;
    if (puVar2 == (undefined *)0x0) {
      param_3 = (undefined *)0x2e;
      if (*(sword *)((int)register0x00000038 + -0x38) != 2) goto loc_F003E854;
      param_3 = *(undefined **)((int)register0x00000038 + -0x18c);
      _copyin(param_3,(undefined *)((int)register0x00000038 + -0x28),0x20);
      bVar7 = false;
      if (param_3 == (undefined *)0x0) {
        param_3 = *(undefined **)((int)register0x00000038 + -0x174);
        if ((*(uint *)((int)register0x00000038 + -0x188) & 0x20) == 0) {
          sub_F003ED40((undefined *)((int)register0x00000038 + -0x38),
                       (undefined *)((int)register0x00000038 + -0x58));
          uVar1 = *(uint *)((int)register0x00000038 + -0x188);
        }
        else {
          _copyinstr(param_3,(undefined *)((int)register0x00000038 + -0x58),0x20,
                     (undefined *)((int)register0x00000038 + -0x194));
          bVar7 = param_3 == (undefined *)0x0;
          if (!bVar7) goto loc_F003E858;
          uVar1 = *(uint *)((int)register0x00000038 + -0x188);
        }
        if ((uVar1 & 0x1000) == 0) {
          *(undefined4 *)((int)register0x00000038 + -0x198) = 0xffffffff;
        }
        else {
          _copyinstr(*(undefined4 *)((int)register0x00000038 + -0x160),
                     (undefined *)((int)register0x00000038 + -0x158),0x100,
                     (undefined *)((int)register0x00000038 + -0x198));
        }
        param_3 = (undefined *)((int)register0x00000038 + -0x19c);
        sub_F003E87C(param_3,param_1,(undefined *)((int)register0x00000038 + -0x38),
                     (undefined *)((int)register0x00000038 + -0x28),
                     (undefined *)((int)register0x00000038 + -0x58),
                     (undefined *)((int)register0x00000038 + -0x158),
                     *(undefined4 *)((int)register0x00000038 + -0x198),
                     *(undefined4 *)((int)register0x00000038 + -0x188));
        if (param_3 != (undefined *)0x0) goto locret_F003E874;
        iVar6 = *(int *)(*(int *)(*(int *)((int)register0x00000038 + -0x19c) + 0x24) + 0x128);
        uVar4 = *(uint *)(iVar6 + 0x14);
        uVar1 = (*(uint *)((int)register0x00000038 + -0x188) >> 7 & 1) << 0x1b;
        *(uint *)(iVar6 + 0x14) = uVar4 & 0xf7ffffff | uVar1;
        *(uint *)(iVar6 + 0x14) =
             uVar4 & 0xf3ffffff | uVar1 |
             (*(uint *)((int)register0x00000038 + -0x188) >> 0xd & 1) << 0x1a;
        if (((*(uint *)((int)register0x00000038 + -0x188) & 0x10) == 0) ||
           (*(undefined4 *)(iVar6 + 0x30) = *(undefined4 *)((int)register0x00000038 + -0x178),
           -1 < *(int *)((int)register0x00000038 + -0x178))) {
          if (((*(uint *)((int)register0x00000038 + -0x188) & 8) == 0) ||
             (*(undefined4 *)(iVar6 + 0x2c) = *(undefined4 *)((int)register0x00000038 + -0x17c),
             0 < *(int *)((int)register0x00000038 + -0x17c))) {
            uVar1 = *(uint *)((int)register0x00000038 + -0x188);
            if ((uVar1 & 4) != 0) {
              iVar5 = *(int *)((int)register0x00000038 + -0x180);
              if (iVar5 < 1) {
                param_3 = (undefined *)0x16;
                goto loc_F003E854;
              }
              iVar3 = *(int *)(iVar6 + 0x1c);
              if (iVar5 < *(int *)(iVar6 + 0x1c)) {
                iVar3 = iVar5;
              }
              *(int *)(iVar6 + 0x1c) = iVar3;
              uVar1 = *(uint *)((int)register0x00000038 + -0x188);
            }
            uVar4 = *(uint *)((int)register0x00000038 + -0x188);
            if ((uVar1 & 2) != 0) {
              iVar5 = *(int *)((int)register0x00000038 + -0x184);
              if (iVar5 < 1) {
                param_3 = (undefined *)0x16;
                goto loc_F003E854;
              }
              iVar3 = *(int *)(iVar6 + 0x20);
              if (iVar5 < *(int *)(iVar6 + 0x20)) {
                iVar3 = iVar5;
              }
              *(int *)(iVar6 + 0x20) = iVar3;
              uVar4 = *(uint *)((int)register0x00000038 + -0x188);
            }
            iVar5 = *(int *)((int)register0x00000038 + -0x170);
            if ((uVar4 & 0x100) != 0) {
              if (iVar5 < 0) {
                iVar5 = 0xe10;
              }
              else {
                if (iVar5 == 0) {
                  param_3 = (undefined *)0x16;
                  _printf(aNfsMountAcregm);
                  bVar7 = false;
                  goto loc_F003E858;
                }
                _min(iVar5,0xe10);
              }
              *(int *)(iVar6 + 0x60) = iVar5;
            }
            uVar1 = *(uint *)((int)register0x00000038 + -0x188);
            if ((uVar1 & 0x200) != 0) {
              uVar1 = *(uint *)((int)register0x00000038 + -0x16c);
              if ((int)uVar1 < 0) {
                uVar1 = 36000;
              }
              else {
                if (uVar1 < *(uint *)(iVar6 + 0x60)) {
                  param_3 = (undefined *)0x16;
                  _printf(aNfsMountAcregm_0);
                  bVar7 = false;
                  goto loc_F003E858;
                }
                _min(uVar1,36000);
              }
              *(uint *)(iVar6 + 100) = uVar1;
              uVar1 = *(uint *)((int)register0x00000038 + -0x188);
            }
            iVar5 = *(int *)((int)register0x00000038 + -0x168);
            if ((uVar1 & 0x400) != 0) {
              if (iVar5 < 0) {
                iVar5 = 0xe10;
              }
              else {
                if (iVar5 == 0) {
                  param_3 = (undefined *)0x16;
                  _printf(aNfsMountAcdirm);
                  bVar7 = false;
                  goto loc_F003E858;
                }
                _min(iVar5,0xe10);
              }
              *(int *)(iVar6 + 0x68) = iVar5;
            }
            bVar7 = true;
            if ((*(uint *)((int)register0x00000038 + -0x188) & 0x800) == 0) goto loc_F003E858;
            uVar1 = *(uint *)((int)register0x00000038 + -0x164);
            if ((int)uVar1 < 0) {
              uVar1 = 36000;
            }
            else {
              if (uVar1 < *(uint *)(iVar6 + 0x68)) {
                param_3 = (undefined *)0x16;
                _printf(aNfsMountAcdirm_0);
                bVar7 = false;
                goto loc_F003E858;
              }
              _min(uVar1,36000);
            }
            *(uint *)(iVar6 + 0x6c) = uVar1;
          }
          else {
            param_3 = (undefined *)0x16;
          }
        }
        else {
          param_3 = (undefined *)0x16;
        }
loc_F003E854:
        bVar7 = param_3 == (undefined *)0x0;
      }
    }
  }
loc_F003E858:
  if ((!bVar7) && (*(int *)((int)register0x00000038 + -0x19c) != 0)) {
    _vn_rele();
  }
locret_F003E874:
  return CONCAT44(param_2,param_3);
}
/* GHIDRADEC_FUNCTION index=3343 start=0xf003e87c */

/* WARNING: Removing unreachable block (ram,0xf003eac8) */
/* WARNING: Removing unreachable block (ram,0xf003ea58) */
/* WARNING: Removing unreachable block (ram,0xf003ea10) */
/* WARNING: Removing unreachable block (ram,0xf003e9f0) */
/* WARNING: Removing unreachable block (ram,0xf003e97c) */
/* WARNING: Removing unreachable block (ram,0xf003e924) */
/* WARNING: Removing unreachable block (ram,0xf003e898) */
/* WARNING: Removing unreachable block (ram,0xf003e910) */
/* WARNING: Removing unreachable block (ram,0xf003e968) */
/* WARNING: Removing unreachable block (ram,0xf003e99c) */
/* WARNING: Removing unreachable block (ram,0xf003ea00) */
/* WARNING: Removing unreachable block (ram,0xf003ea4c) */
/* WARNING: Removing unreachable block (ram,0xf003eabc) */
/* WARNING: Removing unreachable block (ram,0xf003eadc) */
/* WARNING: Removing unreachable block (ram,0xf003e88c) */

undefined8
sub_F003E87C(int *param_1,int param_2,undefined4 *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar7;
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
  iVar7 = *(int *)((int)register0x00000038 + 0x5c);
  uVar5 = *(uint *)((int)register0x00000038 + 0x60);
  puVar1 = (undefined4 *)0x70;
  _kalloc();
  _bzero();
  puVar1[5] = puVar1[5] & 0x5fffffff | (uVar5 ^ 1) << 0x1f | (uVar5 >> 6 & 1) << 0x1d;
  *puVar1 = *param_3;
  iVar6 = 0;
  puVar1[1] = param_3[1];
  puVar2 = unk_F012F4F4;
  puVar1[2] = param_3[2];
  puVar1[3] = param_3[3];
  puVar1[0xc] = 5;
  puVar1[0xb] = 0xb;
  _vfs_getnum(unk_F012F4F4,0x20);
  puVar1[10] = puVar2;
  _bcopy(param_5,puVar1 + 0xd,0x20);
  puVar1[0x18] = 3;
  puVar1[0x19] = 0x3c;
  puVar1[0x1a] = 0x1e;
  puVar1[0x1b] = 0x3c;
  if ((uVar5 & 0x1000) == 0) {
    puVar1[0x17] = 1;
    puVar1[0x16] = iVar7;
    if (-1 < iVar7) {
      iVar6 = iVar7;
      _kalloc();
      puVar1[0x15] = iVar6;
      _bcopy(param_6,iVar6,iVar7);
    }
    *(undefined4 *)(param_2 + 0x14) = puVar1[10];
    *(undefined4 *)(param_2 + 0x18) = 1;
    *(undefined4 **)(param_2 + 0x128) = puVar1;
    iVar6 = param_4;
    _makenfsnode(param_4,0,param_2);
    if ((*(word *)(iVar6 + 4) & 1) != 0) goto loc_F003EAA0;
    *(word *)(iVar6 + 4) = *(word *)(iVar6 + 4) | 1;
    iVar7 = iVar6;
    (**(code **)(*(int *)(iVar6 + 0x1c) + 0x14))
              (iVar6,(undefined *)((int)register0x00000038 + -0x48),
               *(undefined4 *)(_active_u + 0x1c));
    if (iVar7 == 0) {
      _vn_rele(iVar6);
      _vattr_to_nattr((undefined *)((int)register0x00000038 + -0x48),
                      (undefined *)((int)register0x00000038 + -0x90));
      _makenfsnode(param_4,(undefined *)((int)register0x00000038 + -0x90),param_2);
      *(word *)(param_4 + 4) = *(word *)(param_4 + 4) | 1;
      puVar1[4] = param_4;
      iVar3 = param_2;
      (**(code **)(*(int *)(param_2 + 4) + 0xc))
                (param_2,(undefined *)((int)register0x00000038 + -0xd0));
      iVar6 = param_4;
      iVar7 = iVar3;
      if (iVar3 == 0) {
        iVar7 = 0;
        _nfstsize();
        uVar4 = 0x2000;
        _min(0x2000,iVar3);
        puVar1[7] = uVar4;
        puVar1[9] = 0x2000;
        *(undefined4 *)(param_2 + 0x10) = 0x2000;
        **(sword **)(_active_u + 0x1c) = **(sword **)(_active_u + 0x1c) + 1;
        *(undefined4 *)(*(int *)(param_4 + 0x30) + 0x70) = *(undefined4 *)(_active_u + 0x1c);
        *param_1 = param_4;
        goto locret_F003EAE8;
      }
    }
  }
  else {
loc_F003EAA0:
    iVar7 = 0x16;
  }
  if (puVar1 != (undefined4 *)0x0) {
    if (-1 < (int)puVar1[0x16]) {
      _kfree(puVar1[0x15]);
    }
    _kfree(puVar1,0x70);
  }
  if (iVar6 == 0) {
    *param_1 = 0;
  }
  else {
    _vn_rele(iVar6);
    *param_1 = 0;
  }
locret_F003EAE8:
  return CONCAT44(param_2,iVar7);
}
/* GHIDRADEC_FUNCTION index=3344 start=0xf003eaf0 */

/* WARNING: Removing unreachable block (ram,0xf003eb68) */
/* WARNING: Removing unreachable block (ram,0xf003eb40) */
/* WARNING: Removing unreachable block (ram,0xf003eb2c) */
/* WARNING: Removing unreachable block (ram,0xf003eb00) */
/* WARNING: Removing unreachable block (ram,0xf003eb38) */
/* WARNING: Removing unreachable block (ram,0xf003eb50) */
/* WARNING: Removing unreachable block (ram,0xf003eb74) */
/* WARNING: Removing unreachable block (ram,0xf003eaf8) */

undefined8 sub_F003EAF0(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
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
  iVar1 = *(int *)(param_1 + 0x128);
  _rflush(param_1);
  _rinval(param_1);
  uVar2 = 0x10;
  if ((*(int *)(iVar1 + 0x18) == 1) && (*(sword *)(*(int *)(iVar1 + 0x10) + 6) == 1)) {
    _rp_rmhash(*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x30));
    _rinactive(*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x30));
    _vn_rele(*(undefined4 *)(iVar1 + 0x10));
    _vfs_putnum(unk_F012F4F4,*(undefined4 *)(iVar1 + 0x28));
    if (-1 < *(int *)(iVar1 + 0x58)) {
      _kfree(*(undefined4 *)(iVar1 + 0x54));
    }
    _kfree(iVar1,0x70);
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3345 start=0xf003eb88 */

sqword sub_F003EB88(int param_1,int *param_2)

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
  iVar1 = *(int *)(*(int *)(param_1 + 0x128) + 0x10);
  *param_2 = iVar1;
  *(sword *)(iVar1 + 6) = *(sword *)(iVar1 + 6) + 1;
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=3346 start=0xf003ebac */

/* WARNING: Removing unreachable block (ram,0xf003ec68) */
/* WARNING: Removing unreachable block (ram,0xf003ebec) */

undefined8 sub_F003EBAC(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  iVar4 = *(int *)(param_1 + 0x128);
  iVar5 = iVar4;
  _rfscall(iVar4,0x11,_xdr_fhandle,*(int *)(*(int *)(iVar4 + 0x10) + 0x30) + 0x40,_xdr_statfs,
           (undefined *)((int)register0x00000038 + -0x20),*(undefined4 *)(_active_u + 0x1c));
  if (iVar5 == 0) {
    iVar5 = *(int *)((int)register0x00000038 + -0x20);
  }
  if (iVar5 == 0) {
    uVar3 = *(uint *)(iVar4 + 0x20);
    uVar1 = *(uint *)((int)register0x00000038 + -0x1c);
    uVar2 = uVar1;
    if ((uVar3 == 0) || (uVar2 = uVar3, uVar3 < uVar1)) {
      *(uint *)(iVar4 + 0x20) = uVar2;
    }
    else {
      *(uint *)(iVar4 + 0x20) = uVar1;
    }
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)((int)register0x00000038 + -0x14);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)((int)register0x00000038 + -0xc);
    *(undefined4 *)(param_2 + 0x14) = 0xffffffff;
    *(undefined4 *)(param_2 + 0x18) = 0xffffffff;
    _bcopy(param_1 + 0x14,param_2 + 0x1c,8);
  }
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=3347 start=0xf003ec78 */

/* WARNING: Removing unreachable block (ram,0xf003ec94) */

sqword sub_F003EC78(undefined4 param_1,uint param_2)

{
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
  if (dword_F012F4F0 == 0) {
    dword_F012F4F0 = 1;
    _rflush(param_1);
    dword_F012F4F0 = 0;
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3348 start=0xf003ecc0 */

/* WARNING: Removing unreachable block (ram,0xf003ed00) */
/* WARNING: Removing unreachable block (ram,0xf003ecdc) */

undefined8 sub_F003ECC0(uint param_1,undefined *param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar2;
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
  undefined auStack_18 [24];
  
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
  puVar2 = (undefined *)((int)register0x00000038 + -0x18);
  do {
    param_1 = param_1 & 0xffff;
    uVar1 = param_1;
    .urem(param_1,10);
    *puVar2 = a0123456789[uVar1 & 0xffff];
    puVar2 = puVar2 + 1;
    .udiv(param_1,10);
  } while ((param_1 & 0xffff) != 0);
  do {
    puVar2 = puVar2 + -1;
    *param_2 = *puVar2;
    param_2 = param_2 + 1;
  } while ((undefined *)((int)register0x00000038 + -0x18) < puVar2);
  return CONCAT44(param_2,param_2);
}
/* GHIDRADEC_FUNCTION index=3349 start=0xf003ed40 */

/* WARNING: Removing unreachable block (ram,0xf003ed74) */
/* WARNING: Removing unreachable block (ram,0xf003ed60) */
/* WARNING: Removing unreachable block (ram,0xf003ed88) */
/* WARNING: Removing unreachable block (ram,0xf003ed48) */

undefined8 sub_F003ED40(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
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
  puVar1 = (undefined *)(uint)*(byte *)(param_1 + 4);
  sub_F003ECC0(puVar1,param_2);
  *puVar1 = 0x2e;
  puVar2 = (undefined *)(uint)*(byte *)(param_1 + 5);
  sub_F003ECC0(puVar2,puVar1 + 1);
  *puVar2 = 0x2e;
  puVar1 = (undefined *)(uint)*(byte *)(param_1 + 6);
  sub_F003ECC0(puVar1,puVar2 + 1);
  *puVar1 = 0x2e;
  puVar2 = (undefined *)(uint)*(byte *)(param_1 + 7);
  sub_F003ECC0(puVar2,puVar1 + 1);
  *puVar2 = 0;
  return CONCAT44(param_2,param_1);
}

