
/* WARNING: Removing unreachable block (ram,0xf00805a4) */
/* WARNING: Removing unreachable block (ram,0xf0080684) */
/* WARNING: Removing unreachable block (ram,0xf0080590) */

undefined8 sub_F00804F8(int *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar6;
  undefined4 unaff_l3;
  undefined *puVar7;
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
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == dword_F0111690)) &&
     (puVar6 = param_2 + 0xb, param_1[8] == dword_F0111694)) {
    *(uint **)((int)register0x00000038 + -0x80c) = puVar6;
    uVar2 = param_1[7];
    *(undefined4 *)((int)register0x00000038 + -0x810) = 0xaa;
    if (uVar2 < 0xaa) {
      *(uint *)((int)register0x00000038 + -0x810) = uVar2;
    }
    puVar7 = (undefined *)((int)register0x00000038 + -0x808);
    *(undefined **)((int)register0x00000038 + -0x814) = puVar7;
    uVar2 = param_1[9];
    *(undefined4 *)((int)register0x00000038 + -0x818) = 0x100;
    if (uVar2 < 0x100) {
      *(uint *)((int)register0x00000038 + -0x818) = uVar2;
    }
    uVar2 = param_1[2];
    _convert_port_to_host();
    _host_zone_free_space_info();
    param_2[7] = uVar2;
    if (uVar2 == 0) {
      param_2[8] = dword_F0111698;
      puVar3 = *(uint **)((int)register0x00000038 + -0x80c);
      param_2[9] = DAT_f011169c._0_4_;
      param_2[10] = DAT_f011169c._4_4_;
      if (puVar3 != puVar6) {
        param_2[0xb] = (uint)puVar3;
        param_2[8] = param_2[8] & 0xfffffff7 | 2;
      }
      iVar1 = *(int *)((int)register0x00000038 + -0x810);
      iVar4 = 4;
      param_2[10] = iVar1 * 3;
      if ((param_2[8] & 8) != 0) {
        iVar4 = iVar1 * 0xc;
      }
      *(undefined4 *)((int)param_2 + iVar4 + 0x2c) = dword_F01116A4;
      puVar5 = *(undefined **)((int)register0x00000038 + -0x814);
      *(undefined4 *)((int)param_2 + iVar4 + 0x30) = DAT_f01116a8._0_4_;
      *(undefined4 *)((int)param_2 + iVar4 + 0x34) = DAT_f01116a8._4_4_;
      if (puVar5 == puVar7) {
        _memcpy((int)param_2 + iVar4 + 0x38,puVar5,*(int *)((int)register0x00000038 + -0x818) << 3);
      }
      else {
        *(undefined **)((int)param_2 + iVar4 + 0x38) = puVar5;
        *(uint *)((int)param_2 + iVar4 + 0x2c) =
             *(uint *)((int)param_2 + iVar4 + 0x2c) & 0xfffffff7 | 2;
      }
      iVar1 = *(int *)((int)register0x00000038 + -0x818);
      *(int *)((int)param_2 + iVar4 + 0x34) = iVar1 << 1;
      if ((*(uint *)((int)param_2 + iVar4 + 0x2c) & 8) == 0) {
        param_1 = (int *)(iVar4 + 0x3c);
      }
      else {
        param_1 = (int *)(iVar4 + 0x38 + iVar1 * 8);
      }
      if (puVar5 != puVar7 || puVar3 != puVar6) {
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

