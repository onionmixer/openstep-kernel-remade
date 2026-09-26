
/* WARNING: Removing unreachable block (ram,0xf00803b0) */
/* WARNING: Removing unreachable block (ram,0xf008049c) */
/* WARNING: Removing unreachable block (ram,0xf008039c) */

undefined8 sub_F0080304(int *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar5;
  undefined4 unaff_l3;
  undefined *puVar6;
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
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == dword_F0111670)) &&
     (puVar5 = param_2 + 0xb, param_1[8] == dword_F0111674)) {
    *(uint **)((int)register0x00000038 + -0x7ec) = puVar5;
    uVar2 = param_1[7];
    *(undefined4 *)((int)register0x00000038 + -0x7f0) = 0x19;
    if (uVar2 < 0x19) {
      *(uint *)((int)register0x00000038 + -0x7f0) = uVar2;
    }
    puVar6 = (undefined *)((int)register0x00000038 + -0x7e8);
    *(undefined **)((int)register0x00000038 + -0x7f4) = puVar6;
    uVar2 = param_1[9];
    *(undefined4 *)((int)register0x00000038 + -0x7f8) = 0x38;
    if (uVar2 < 0x38) {
      *(uint *)((int)register0x00000038 + -0x7f8) = uVar2;
    }
    uVar2 = param_1[2];
    _convert_port_to_host();
    _host_zone_info();
    param_2[7] = uVar2;
    if (uVar2 == 0) {
      param_2[8] = dword_F0111678;
      puVar3 = *(uint **)((int)register0x00000038 + -0x7ec);
      param_2[9] = DAT_f011167c._0_4_;
      param_2[10] = DAT_f011167c._4_4_;
      if (puVar3 != puVar5) {
        param_2[0xb] = (uint)puVar3;
        param_2[8] = param_2[8] & 0xfffffff7 | 2;
      }
      iVar1 = *(int *)((int)register0x00000038 + -0x7f0);
      param_2[10] = iVar1 * 0x50;
      uVar2 = 4;
      if ((param_2[8] & 8) != 0) {
        uVar2 = iVar1 * 0x50;
      }
      *(undefined4 *)((int)param_2 + uVar2 + 0x2c) = dword_F0111684;
      puVar4 = *(undefined **)((int)register0x00000038 + -0x7f4);
      *(undefined4 *)((int)param_2 + uVar2 + 0x30) = DAT_f0111688._0_4_;
      *(undefined4 *)((int)param_2 + uVar2 + 0x34) = DAT_f0111688._4_4_;
      if (puVar4 == puVar6) {
        _memcpy((int)param_2 + uVar2 + 0x38,puVar4,*(int *)((int)register0x00000038 + -0x7f8) * 0x24
               );
      }
      else {
        *(undefined **)((int)param_2 + uVar2 + 0x38) = puVar4;
        *(uint *)((int)param_2 + uVar2 + 0x2c) =
             *(uint *)((int)param_2 + uVar2 + 0x2c) & 0xfffffff7 | 2;
      }
      iVar1 = *(int *)((int)register0x00000038 + -0x7f8);
      *(int *)((int)param_2 + uVar2 + 0x34) = iVar1 * 9;
      if ((*(uint *)((int)param_2 + uVar2 + 0x2c) & 8) == 0) {
        param_1 = (int *)(uVar2 + 0x3c);
      }
      else {
        param_1 = (int *)(uVar2 + 0x38 + iVar1 * 0x24);
      }
      if (puVar4 != puVar6 || puVar3 != puVar5) {
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

