
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
