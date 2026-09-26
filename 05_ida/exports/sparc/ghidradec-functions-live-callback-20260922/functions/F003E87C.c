
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

