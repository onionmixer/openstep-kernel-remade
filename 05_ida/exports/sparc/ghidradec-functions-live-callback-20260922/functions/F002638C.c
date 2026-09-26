
undefined8 _vno_stat(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 uVar2;
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
  iVar1 = param_1;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
            (param_1,(undefined *)((int)register0x00000038 + -0x48),
             *(undefined4 *)(_active_u + 0x1c));
  if (iVar1 != 0) goto locret_F00264FC;
  param_2[4] = *(undefined2 *)((int)register0x00000038 + -0x44);
  param_2[6] = *(undefined2 *)((int)register0x00000038 + -0x42);
  param_2[7] = *(undefined2 *)((int)register0x00000038 + -0x40);
  *param_2 = (sword)*(undefined4 *)((int)register0x00000038 + -0x3c);
  *(undefined4 *)(param_2 + 2) = *(undefined4 *)((int)register0x00000038 + -0x38);
  param_2[5] = *(undefined2 *)((int)register0x00000038 + -0x34);
  *(undefined4 *)(param_2 + 10) = *(undefined4 *)((int)register0x00000038 + -0x30);
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)((int)register0x00000038 + -0x2c);
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)((int)register0x00000038 + -0x28);
  *(undefined4 *)(param_2 + 0xe) = 0;
  iVar3 = *(int *)(param_1 + 0x14);
  iVar1 = *(int *)((int)register0x00000038 + -0x20);
  if ((iVar3 == 0) &&
     (iVar1 = *(int *)((int)register0x00000038 + -0x20), *(int *)(param_1 + 0x18) == 0)) {
loc_F0026460:
    *(int *)(param_2 + 0x10) = iVar1;
  }
  else if (iVar1 < iVar3) {
    *(int *)(param_2 + 0x10) = iVar3;
  }
  else {
    bVar4 = iVar3 != iVar1;
    iVar1 = *(int *)((int)register0x00000038 + -0x20);
    if ((bVar4) ||
       (iVar1 = *(int *)((int)register0x00000038 + -0x20),
       *(int *)(param_1 + 0x18) <= *(int *)((int)register0x00000038 + -0x1c))) goto loc_F0026460;
    *(int *)(param_2 + 0x10) = iVar3;
  }
  *(undefined4 *)(param_2 + 0x12) = 0;
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)((int)register0x00000038 + -0x18);
  *(undefined4 *)(param_2 + 0x16) = 0;
  param_2[8] = *(undefined2 *)((int)register0x00000038 + -0x10);
  *(undefined4 *)(param_2 + 0x1a) = *(undefined4 *)((int)register0x00000038 + -0xc);
  *(undefined4 *)(param_2 + 0x1e) = 0;
  *(undefined4 *)(param_2 + 0x1c) = 0;
  if (*(undefined **)(param_1 + 0x1c) == _ufs_vnodeops) {
    *(undefined4 *)(param_2 + 0x1c) = 0xfeedface;
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xd0);
  }
  else {
    if (*(undefined **)(param_1 + 0x1c) != _nfs_vnodeops) {
      iVar1 = 0;
      goto locret_F00264FC;
    }
    iVar1 = *(int *)(param_1 + 0x30);
    if (*(int *)(iVar1 + 0x4c) != *(int *)(param_2 + 2)) {
      iVar1 = 0;
      goto locret_F00264FC;
    }
    *(undefined4 *)(param_2 + 0x1c) = 0xfeedface;
    uVar2 = *(undefined4 *)(iVar1 + 0x50);
  }
  *(undefined4 *)(param_2 + 0x1e) = uVar2;
  iVar1 = 0;
locret_F00264FC:
  return CONCAT44(param_2,iVar1);
}

