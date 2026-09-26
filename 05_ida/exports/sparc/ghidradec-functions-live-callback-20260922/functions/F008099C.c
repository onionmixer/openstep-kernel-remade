
/* WARNING: Removing unreachable block (ram,0xf0080a64) */
/* WARNING: Removing unreachable block (ram,0xf0080a58) */
/* WARNING: Removing unreachable block (ram,0xf0080b60) */
/* WARNING: Removing unreachable block (ram,0xf00809f8) */

undefined8 sub_F008099C(int *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar7;
  undefined4 unaff_l3;
  undefined *puVar8;
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
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == dword_F01116DC)) &&
     (param_1[8] == dword_F01116E0)) {
    uVar1 = param_1[2];
    _convert_port_to_space();
    puVar7 = param_2 + 0x12;
    *(uint **)((int)register0x00000038 + -0x7f4) = puVar7;
    *(undefined4 *)((int)register0x00000038 + -0x7f8) = 0x38;
    if ((uint)param_1[7] < 0x38) {
      *(int *)((int)register0x00000038 + -0x7f8) = param_1[7];
    }
    puVar8 = (undefined *)((int)register0x00000038 + -0x7f0);
    *(undefined **)((int)register0x00000038 + -0x7fc) = puVar8;
    param_1 = (int *)param_1[9];
    *(undefined4 *)((int)register0x00000038 + -0x800) = 0x2e;
    if (param_1 < (int *)0x2e) {
      *(int **)((int)register0x00000038 + -0x800) = param_1;
    }
    uVar2 = uVar1;
    _mach_port_space_info
              (uVar1,param_2 + 9,(undefined *)((int)register0x00000038 + -0x7f4),
               (undefined *)((int)register0x00000038 + -0x7f8),
               (undefined *)((int)register0x00000038 + -0x7fc),
               (undefined *)((int)register0x00000038 + -0x800));
    param_2[7] = uVar2;
    _space_deallocate(uVar1);
    if (param_2[7] == 0) {
      param_2[8] = dword_F01116E4;
      param_2[0xf] = dword_F01116E8;
      puVar4 = *(uint **)((int)register0x00000038 + -0x7f4);
      param_2[0x10] = DAT_f01116ec._0_4_;
      param_2[0x11] = DAT_f01116ec._4_4_;
      if (puVar4 != puVar7) {
        param_2[0x12] = (uint)puVar4;
        param_2[0xf] = param_2[0xf] & 0xfffffff7 | 2;
      }
      iVar3 = *(int *)((int)register0x00000038 + -0x7f8);
      iVar5 = 4;
      param_2[0x11] = iVar3 * 9;
      if ((param_2[0xf] & 8) != 0) {
        iVar5 = iVar3 * 0x24;
      }
      *(undefined4 *)((int)param_2 + iVar5 + 0x48) = dword_F01116F4;
      puVar6 = *(undefined **)((int)register0x00000038 + -0x7fc);
      *(undefined4 *)((int)param_2 + iVar5 + 0x4c) = DAT_f01116f8._0_4_;
      *(undefined4 *)((int)param_2 + iVar5 + 0x50) = DAT_f01116f8._4_4_;
      if (puVar6 == puVar8) {
        _memcpy((int)param_2 + iVar5 + 0x54,puVar6,*(int *)((int)register0x00000038 + -0x800) * 0x2c
               );
      }
      else {
        *(undefined **)((int)param_2 + iVar5 + 0x54) = puVar6;
        *(uint *)((int)param_2 + iVar5 + 0x48) =
             *(uint *)((int)param_2 + iVar5 + 0x48) & 0xfffffff7 | 2;
      }
      iVar3 = *(int *)((int)register0x00000038 + -0x800);
      *(int *)((int)param_2 + iVar5 + 0x50) = iVar3 * 0xb;
      if ((*(uint *)((int)param_2 + iVar5 + 0x48) & 8) == 0) {
        param_1 = (int *)(iVar5 + 0x58);
      }
      else {
        param_1 = (int *)(iVar5 + 0x54 + iVar3 * 0x2c);
      }
      if (puVar6 != puVar8 || puVar4 != puVar7) {
        *param_2 = *param_2 | 0x80000000;
      }
      param_2[1] = (uint)param_1;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}

