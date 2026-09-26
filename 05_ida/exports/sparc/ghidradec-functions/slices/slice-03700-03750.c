/* GHIDRADEC_FUNCTION index=3700 start=0xf007ff7c */

/* WARNING: Removing unreachable block (ram,0xf0080020) */
/* WARNING: Removing unreachable block (ram,0xf008002c) */
/* WARNING: Removing unreachable block (ram,0xf0080008) */

undefined8 sub_F007FF7C(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
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
  if ((((param_1[1] == 0x38) && (-1 < *param_1)) && (param_1[6] == dword_F0111498)) &&
     (((param_1[8] == dword_F011149C && (param_1[10] == dword_F01114A0)) &&
      (param_1[0xc] == dword_F01114A4)))) {
    iVar1 = param_1[2];
    _convert_port_to_map();
    iVar2 = iVar1;
    _vm_machine_attribute();
    *(int *)(param_2 + 0x1c) = iVar2;
    _vm_map_deallocate(iVar1);
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = dword_F01114A8;
      *(int *)(param_2 + 0x24) = param_1[0xd];
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3701 start=0xf0080064 */

/* WARNING: Removing unreachable block (ram,0xf00800d0) */
/* WARNING: Removing unreachable block (ram,0xf00800dc) */
/* WARNING: Removing unreachable block (ram,0xf00800c0) */

undefined8 sub_F0080064(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
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
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == dword_F01114AC)) &&
     (param_1[8] == dword_F01114B0)) {
    iVar1 = param_1[2];
    _convert_port_to_map();
    iVar2 = iVar1;
    _vm_synchronize();
    *(int *)(param_2 + 0x1c) = iVar2;
    _vm_map_deallocate(iVar1);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3702 start=0xf00800ec */

/* WARNING: Removing unreachable block (ram,0xf0080174) */
/* WARNING: Removing unreachable block (ram,0xf0080180) */
/* WARNING: Removing unreachable block (ram,0xf0080160) */

undefined8 sub_F00800EC(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
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
  if ((((param_1[1] == 0x30) && (-1 < *param_1)) && (param_1[6] == dword_F01114B4)) &&
     ((param_1[8] == dword_F01114B8 && (param_1[10] == dword_F01114BC)))) {
    iVar1 = param_1[2];
    _convert_port_to_map();
    iVar2 = iVar1;
    _vm_set_policy();
    *(int *)(param_2 + 0x1c) = iVar2;
    _vm_map_deallocate(iVar1);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3703 start=0xf0080190 */

/* WARNING: Removing unreachable block (ram,0xf0080218) */
/* WARNING: Removing unreachable block (ram,0xf0080224) */
/* WARNING: Removing unreachable block (ram,0xf0080204) */

undefined8 sub_F0080190(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
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
  if ((((param_1[1] == 0x30) && (-1 < *param_1)) && (param_1[6] == dword_F01114C0)) &&
     ((param_1[8] == dword_F01114C4 && (param_1[10] == dword_F01114C8)))) {
    iVar1 = param_1[2];
    _convert_port_to_map();
    iVar2 = iVar1;
    _vm_deactivate();
    *(int *)(param_2 + 0x1c) = iVar2;
    _vm_map_deallocate(iVar1);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3704 start=0xf0080304 */

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
/* GHIDRADEC_FUNCTION index=3705 start=0xf00804f8 */

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
/* GHIDRADEC_FUNCTION index=3706 start=0xf00806dc */

/* WARNING: Removing unreachable block (ram,0xf0080730) */
/* WARNING: Removing unreachable block (ram,0xf008073c) */
/* WARNING: Removing unreachable block (ram,0xf0080720) */

undefined8 sub_F00806DC(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
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
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == dword_F01116B0)) {
    iVar1 = param_1[2];
    _convert_port_to_space();
    iVar2 = iVar1;
    _mach_port_get_srights();
    *(int *)(param_2 + 0x1c) = iVar2;
    _space_deallocate(iVar1);
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = dword_F01116B4;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3707 start=0xf008076c */

/* WARNING: Removing unreachable block (ram,0xf00807d8) */
/* WARNING: Removing unreachable block (ram,0xf00807cc) */

undefined8 sub_F008076C(int *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  uint *puVar3;
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
  if (((param_1[1] == 0x20) && (-1 < *param_1)) &&
     (puVar3 = param_2 + 0xb, param_1[6] == dword_F01116B8)) {
    *(uint **)((int)register0x00000038 + -0xc) = puVar3;
    uVar1 = param_1[7];
    *(undefined4 *)((int)register0x00000038 + -0x10) = 0x200;
    if (uVar1 < 0x200) {
      *(uint *)((int)register0x00000038 + -0x10) = uVar1;
    }
    uVar1 = param_1[2];
    _convert_port_to_host();
    _host_ipc_hash_info();
    param_2[7] = uVar1;
    if (uVar1 == 0) {
      param_2[8] = dword_F01116BC;
      puVar2 = *(uint **)((int)register0x00000038 + -0xc);
      param_2[9] = DAT_f01116c0._0_4_;
      param_2[10] = DAT_f01116c0._4_4_;
      if (puVar2 != puVar3) {
        param_2[0xb] = (uint)puVar2;
        param_2[8] = param_2[8] & 0xfffffff7 | 2;
      }
      uVar1 = *(uint *)((int)register0x00000038 + -0x10);
      param_2[10] = uVar1;
      if ((param_2[8] & 8) == 0) {
        uVar1 = 0x30;
      }
      else {
        uVar1 = uVar1 * 4 + 0x2c;
      }
      param_2[1] = uVar1;
      if (puVar2 != puVar3) {
        *param_2 = *param_2 | 0x80000000;
      }
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3708 start=0xf008087c */

/* WARNING: Removing unreachable block (ram,0xf00808ec) */
/* WARNING: Removing unreachable block (ram,0xf00808dc) */

undefined8 sub_F008087C(int *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  uint *puVar3;
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
  if (((param_1[1] == 0x20) && (-1 < *param_1)) &&
     (puVar3 = param_2 + 0xd, param_1[6] == dword_F01116C8)) {
    *(uint **)((int)register0x00000038 + -0xc) = puVar3;
    uVar1 = param_1[7];
    *(undefined4 *)((int)register0x00000038 + -0x10) = 0x200;
    if (uVar1 < 0x200) {
      *(uint *)((int)register0x00000038 + -0x10) = uVar1;
    }
    uVar1 = param_1[2];
    _convert_port_to_host();
    _host_ipc_marequest_info();
    param_2[7] = uVar1;
    if (uVar1 == 0) {
      param_2[8] = dword_F01116CC;
      param_2[10] = dword_F01116D0;
      puVar2 = *(uint **)((int)register0x00000038 + -0xc);
      param_2[0xb] = DAT_f01116d4._0_4_;
      param_2[0xc] = DAT_f01116d4._4_4_;
      if (puVar2 != puVar3) {
        param_2[0xd] = (uint)puVar2;
        param_2[10] = param_2[10] & 0xfffffff7 | 2;
      }
      uVar1 = *(uint *)((int)register0x00000038 + -0x10);
      param_2[0xc] = uVar1;
      if ((param_2[10] & 8) == 0) {
        uVar1 = 0x38;
      }
      else {
        uVar1 = uVar1 * 4 + 0x34;
      }
      param_2[1] = uVar1;
      if (puVar2 != puVar3) {
        *param_2 = *param_2 | 0x80000000;
      }
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3709 start=0xf008099c */

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
/* GHIDRADEC_FUNCTION index=3710 start=0xf0080bc4 */

/* WARNING: Removing unreachable block (ram,0xf0080c1c) */
/* WARNING: Removing unreachable block (ram,0xf0080c28) */
/* WARNING: Removing unreachable block (ram,0xf0080c08) */

undefined8 sub_F0080BC4(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
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
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == dword_F0111700)) {
    iVar1 = param_1[2];
    _convert_port_to_space();
    iVar2 = iVar1;
    _mach_port_dnrequest_info();
    *(int *)(param_2 + 0x1c) = iVar2;
    _space_deallocate(iVar1);
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 4) = 0x30;
      *(undefined4 *)(param_2 + 0x20) = dword_F0111704;
      *(undefined4 *)(param_2 + 0x28) = dword_F0111708;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3711 start=0xf0080c64 */

/* WARNING: Removing unreachable block (ram,0xf0080cb0) */
/* WARNING: Removing unreachable block (ram,0xf0080c90) */

undefined8 sub_F0080C64(int *param_1,int param_2)

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
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    iVar1 = param_1[2];
    _convert_port_to_host();
    _host_stack_usage();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 4) = 0x50;
      *(undefined4 *)(param_2 + 0x20) = dword_F011170C;
      *(undefined4 *)(param_2 + 0x28) = dword_F0111710;
      *(undefined4 *)(param_2 + 0x30) = dword_F0111714;
      *(undefined4 *)(param_2 + 0x38) = dword_F0111718;
      *(undefined4 *)(param_2 + 0x40) = dword_F011171C;
      *(undefined4 *)(param_2 + 0x48) = dword_F0111720;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3712 start=0xf0080d1c */

/* WARNING: Removing unreachable block (ram,0xf0080d68) */
/* WARNING: Removing unreachable block (ram,0xf0080d74) */
/* WARNING: Removing unreachable block (ram,0xf0080d4c) */

undefined8 sub_F0080D1C(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
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
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    iVar1 = param_1[2];
    _convert_port_to_pset_name();
    iVar2 = iVar1;
    _processor_set_stack_usage();
    *(int *)(param_2 + 0x1c) = iVar2;
    _pset_deallocate(iVar1);
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 4) = 0x48;
      *(undefined4 *)(param_2 + 0x20) = dword_F0111724;
      *(undefined4 *)(param_2 + 0x28) = dword_F0111728;
      *(undefined4 *)(param_2 + 0x30) = dword_F011172C;
      *(undefined4 *)(param_2 + 0x38) = dword_F0111730;
      *(undefined4 *)(param_2 + 0x40) = dword_F0111734;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3713 start=0xf0080ea4 */

/* WARNING: Removing unreachable block (ram,0xf0081028) */
/* WARNING: Removing unreachable block (ram,0xf0080ff8) */
/* WARNING: Removing unreachable block (ram,0xf0080fac) */
/* WARNING: Removing unreachable block (ram,0xf0080f88) */
/* WARNING: Removing unreachable block (ram,0xf0080f50) */
/* WARNING: Removing unreachable block (ram,0xf0080f2c) */
/* WARNING: Removing unreachable block (ram,0xf0080f0c) */
/* WARNING: Removing unreachable block (ram,0xf0080ee0) */
/* WARNING: Removing unreachable block (ram,0xf0080ef8) */
/* WARNING: Removing unreachable block (ram,0xf0080f18) */
/* WARNING: Removing unreachable block (ram,0xf0080f3c) */
/* WARNING: Removing unreachable block (ram,0xf0080f70) */
/* WARNING: Removing unreachable block (ram,0xf0080f98) */
/* WARNING: Removing unreachable block (ram,0xf0080fdc) */
/* WARNING: Removing unreachable block (ram,0xf0081010) */
/* WARNING: Removing unreachable block (ram,0xf0081040) */
/* WARNING: Removing unreachable block (ram,0xf0080eb8) */

void sub_F0080EA4(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined *puVar5;
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
  iVar4 = *(int *)(_active_threads + 0xc);
  iVar1 = 1;
  *(undefined4 *)(iVar4 + 0x50) = 1;
  _task_self();
  dword_F0130F60 = iVar1;
  do {
    do {
    } while (dword_F0130F5C != 0);
    puVar2 = &dword_F0130F5C;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  iVar1 = dword_F0130F60;
  _port_set_allocate_EXTERNAL(dword_F0130F60,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 != 0) {
    _panic(aUxHandlerPortS);
  }
  iVar1 = dword_F0130F60;
  _port_allocate_EXTERNAL(dword_F0130F60,(undefined *)((int)register0x00000038 + -0x10));
  if (iVar1 != 0) {
    _panic(aUxHandlerPortA);
  }
  iVar1 = dword_F0130F60;
  _port_set_add_EXTERNAL
            (dword_F0130F60,*(undefined4 *)((int)register0x00000038 + -0xc),
             *(undefined4 *)((int)register0x00000038 + -0x10));
  if (iVar1 != 0) {
    _panic(aUxHandlerPortS_0);
  }
  _object_copyin(iVar4,*(undefined4 *)((int)register0x00000038 + -0x10),6,0,&_ux_exception_port);
  if (iVar4 == 0) {
    _panic(aUxHandlerObjec);
  }
  _thread_wakeup_prim(&_ux_exception_port,0,0);
  dword_F0130F5C = 0;
  _task_name(aUxExcept);
  puVar5 = (undefined *)((int)register0x00000038 + -0x90);
  *(undefined4 *)((int)register0x00000038 + -0x8c) = 0x58;
  do {
    while( true ) {
      *(undefined4 *)((int)register0x00000038 + -0x84) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      puVar3 = puVar5;
      _msg_receive(puVar5,0,0);
      if (puVar3 == (undefined *)0x0) break;
      if (puVar3 == (undefined *)0xffffff34) {
        *(undefined4 *)((int)register0x00000038 + -0x8c) = 0x58;
      }
      else {
        _panic(aExceptionHandl_0);
        *(undefined4 *)((int)register0x00000038 + -0x8c) = 0x58;
      }
    }
    iVar1 = *(int *)((int)register0x00000038 + -0x80);
    puVar3 = puVar5;
    _exc_server(puVar5,(undefined *)((int)register0x00000038 + -0x38));
    if (puVar3 != (undefined *)0x0) {
      _msg_send((undefined *)((int)register0x00000038 + -0x38),0,0);
    }
    if (iVar1 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0x8c) = 0x58;
    }
    else {
      _port_deallocate_EXTERNAL(dword_F0130F60,iVar1);
      *(undefined4 *)((int)register0x00000038 + -0x8c) = 0x58;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3714 start=0xf00811ac */

/* WARNING: Removing unreachable block (ram,0xf00811c0) */

undefined8
sub_F00811AC(int param_1,int param_2,undefined4 param_3,undefined4 *param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
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
  iVar1 = param_1;
  _machine_exception(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    switch(param_1) {
    case :
      uVar2 = 10;
      if (param_2 == 1) {
        uVar2 = 0xb;
      }
      break;
    case :
      uVar2 = 4;
      break;
    case :
      uVar2 = 8;
      break;
    case :
      uVar2 = 7;
      break;
    case :
      if (param_2 == 0x10001) {
        uVar2 = 0xd;
      }
      else if (param_2 < 0x10002) {
        uVar2 = 0xc;
        if (param_2 != 0x10000) goto def_F00811EC;
      }
      else {
        uVar2 = 6;
        if (param_2 != 0x10002) goto def_F00811EC;
      }
      break;
    case :
      uVar2 = 5;
      break;
    :
      goto def_F00811EC;
    }
    *param_4 = uVar2;
  }
def_F00811EC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3715 start=0xf0083530 */

/* WARNING: Removing unreachable block (ram,0xf0083648) */
/* WARNING: Removing unreachable block (ram,0xf008367c) */
/* WARNING: Removing unreachable block (ram,0xf008362c) */
/* WARNING: Removing unreachable block (ram,0xf0083610) */
/* WARNING: Removing unreachable block (ram,0xf00835dc) */
/* WARNING: Removing unreachable block (ram,0xf00835d4) */
/* WARNING: Removing unreachable block (ram,0xf00835f8) */
/* WARNING: Removing unreachable block (ram,0xf0083618) */
/* WARNING: Removing unreachable block (ram,0xf0083660) */
/* WARNING: Removing unreachable block (ram,0xf0083684) */
/* WARNING: Removing unreachable block (ram,0xf00835b0) */
/* WARNING: Removing unreachable block (ram,0xf0083588) */

undefined8
sub_F0083530(int param_1,undefined4 *param_2,int param_3,int param_4,uint param_5,undefined4 param_6
            )

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
  uint uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar5;
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
  iVar3 = 0;
  if (param_4 == 0) {
    uVar1 = *param_2;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
  }
  *(undefined4 *)((int)register0x00000038 + -0xc) = uVar1;
  uVar5 = param_3 + _page_mask & ~_page_mask;
  iVar2 = param_1;
  _vm_map_find(param_1,param_5 & -(uint)(param_5 != _kernel_object),0,
               (undefined *)((int)register0x00000038 + -0xc),uVar5,param_4);
  uVar4 = (uint)(iVar2 != 0);
  if (uVar4 == 0) {
    if (param_5 == _kernel_object) {
      iVar3 = *(int *)((int)register0x00000038 + -0xc) + 0x10000000;
      _vm_object_reference();
      _lock_write(param_1);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      _vm_map_delete(param_1,*(int *)((int)register0x00000038 + -0xc),
                     *(int *)((int)register0x00000038 + -0xc) + uVar5);
      _vm_map_insert(param_1,param_5,iVar3,*(int *)((int)register0x00000038 + -0xc),
                     *(int *)((int)register0x00000038 + -0xc) + uVar5);
      _lock_done(param_1);
    }
    sub_F00838B4(param_5,iVar3,uVar5,param_6);
    if (param_5 == 0) {
      _lock_write(param_1);
      iVar3 = *(int *)((int)register0x00000038 + -0xc);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      _vm_map_delete(param_1,iVar3,iVar3 + uVar5);
      _lock_done(param_1);
      uVar4 = 6;
    }
    else {
      _vm_map_pageable(param_1,*(int *)((int)register0x00000038 + -0xc),
                       *(int *)((int)register0x00000038 + -0xc) + uVar5,0);
      uVar4 = 0;
      *param_2 = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
  }
  else if (param_5 != _kernel_object) {
    _vm_object_deallocate(param_5);
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3716 start=0xf00838b4 */

/* WARNING: Removing unreachable block (ram,0xf0083960) */
/* WARNING: Removing unreachable block (ram,0xf0083938) */
/* WARNING: Removing unreachable block (ram,0xf00838fc) */
/* WARNING: Removing unreachable block (ram,0xf0083998) */
/* WARNING: Removing unreachable block (ram,0xf0083950) */
/* WARNING: Removing unreachable block (ram,0xf008397c) */
/* WARNING: Removing unreachable block (ram,0xf00838e4) */

undefined8 sub_F00838B4(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if (param_3 == 0) {
    uVar5 = 1;
  }
  else {
    do {
      do {
        do {
        } while (*(int *)(param_1 + 0x10) != 0);
        piVar2 = (int *)(param_1 + 0x10);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      while (iVar3 = param_1, _vm_page_alloc_sequential(param_1,param_2,1), iVar3 == 0) {
        *(undefined4 *)(param_1 + 0x10) = 0;
        if (param_4 == 0) {
          uVar5 = 0;
          goto locret_F00839C8;
        }
        do {
          do {
          } while (_vm_pages_needed_lock != 0);
          puVar4 = &_vm_pages_needed_lock;
          _simple_lock_try();
        } while (puVar4 == (undefined4 *)0x0);
        _thread_wakeup_prim(&_vm_pages_needed,0,0);
        _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
        do {
          do {
          } while (*(int *)(param_1 + 0x10) != 0);
          piVar2 = (int *)(param_1 + 0x10);
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
      }
      *(undefined4 *)(param_1 + 0x10) = 0;
      _vm_page_zero_fill(iVar3);
      iVar1 = _page_size;
      *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0x7fffffff;
      param_3 = param_3 - iVar1;
      param_2 = param_2 + iVar1;
    } while (param_3 != 0);
    uVar5 = 1;
  }
locret_F00839C8:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=3717 start=0xf008830c */

/* WARNING: Removing unreachable block (ram,0xf008840c) */
/* WARNING: Removing unreachable block (ram,0xf00883e8) */
/* WARNING: Removing unreachable block (ram,0xf0088464) */
/* WARNING: Removing unreachable block (ram,0xf0088310) */

undefined8 sub_F008830C(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
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
  _vm_page_remove(param_1);
  uVar3 = param_1[7];
  if ((uVar3 & 0x1000) == 0) {
    if ((uVar3 & 0x4000) != 0) {
      iVar5 = *param_1;
      piVar4 = (int *)param_1[1];
      *(int **)(iVar5 + 4) = piVar4;
      if (piVar4 != &_vm_page_queue_active) {
        *piVar4 = iVar5;
        iVar5 = _vm_page_queue_active;
      }
      _vm_page_queue_active = iVar5;
      param_1[7] = param_1[7] & 0xffffbfff;
      _vm_page_active_count = _vm_page_active_count + -1;
      uVar3 = param_1[7];
    }
    if ((uVar3 & 0x8000) != 0) {
      iVar5 = *param_1;
      piVar4 = (int *)param_1[1];
      *(int **)(iVar5 + 4) = piVar4;
      if (piVar4 != &_vm_page_queue_inactive) {
        *piVar4 = iVar5;
        iVar5 = _vm_page_queue_inactive;
      }
      _vm_page_queue_inactive = iVar5;
      param_1[7] = param_1[7] & 0xffff7fff;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
    }
    uVar1 = 0x10000000;
    if ((param_1[8] & 0x10000000U) == 0) {
      _spltty();
      do {
        do {
        } while (_vm_page_queue_free_lock != 0);
        puVar2 = &_vm_page_queue_free_lock;
        _simple_lock_try();
      } while (puVar2 == (undefined4 *)0x0);
      _vm_page_queue_free[1] = (int)param_1;
      *param_1 = (int)_vm_page_queue_free;
      param_1[1] = (int)&_vm_page_queue_free;
      _vm_page_queue_free = param_1;
      param_1[7] = param_1[7] | 0x1000;
      _vm_page_queue_free_lock = 0;
      _vm_page_free_count = _vm_page_free_count + 1;
      _splx(uVar1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3718 start=0xf008858c */

/* WARNING: Removing unreachable block (ram,0xf008863c) */
/* WARNING: Removing unreachable block (ram,0xf00885f4) */
/* WARNING: Removing unreachable block (ram,0xf0088650) */
/* WARNING: Removing unreachable block (ram,0xf00885ac) */

undefined8 sub_F008858C(int *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 unaff_l0;
  int *piVar2;
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
  if (param_1 != (int *)0x0) {
    do {
      do {
      } while (param_1[4] != 0);
      piVar2 = param_1 + 4;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    piVar2 = (int *)*param_1;
    if (param_1 == piVar2) {
      uVar1 = param_1[5];
    }
    else {
      uVar1 = piVar2[6];
      while( true ) {
        if (uVar1 < param_2) {
          piVar2 = (int *)piVar2[2];
        }
        else if (uVar1 < param_3) {
          _vm_policy_apply(param_1,piVar2,param_4);
          piVar2 = (int *)piVar2[2];
        }
        else {
          piVar2 = (int *)piVar2[2];
        }
        if (param_1 == piVar2) break;
        uVar1 = piVar2[6];
      }
      uVar1 = param_1[5];
    }
    param_3 = param_3 - param_2;
    if ((uVar1 != 0) && (uVar1 < param_3)) {
      param_3 = uVar1;
    }
    param_2 = param_2 + param_1[9];
    sub_F008858C(param_1[8],param_2,param_2 + param_3,param_4);
    param_1[4] = 0;
    _thread_wakeup_prim(param_1,0,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3719 start=0xf0088660 */

/* WARNING: Removing unreachable block (ram,0xf00886a0) */
/* WARNING: Removing unreachable block (ram,0xf0088704) */
/* WARNING: Removing unreachable block (ram,0xf008871c) */
/* WARNING: Removing unreachable block (ram,0xf0088664) */

undefined8 sub_F0088660(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  _lock_read(param_1);
  iVar5 = *(int *)(param_1 + 0x10);
  if (iVar5 != param_1 + 0xc) {
    uVar1 = *(uint *)(iVar5 + 0x18);
    while( true ) {
      if ((uVar1 & 0xa0000000) == 0) {
        uVar1 = *(uint *)(iVar5 + 8);
        if (param_3 < uVar1) {
          iVar5 = *(int *)(iVar5 + 4);
        }
        else {
          uVar2 = *(uint *)(iVar5 + 0xc);
          if (param_2 < uVar2) {
            if (param_2 < uVar1) {
              param_2 = uVar1;
            }
            uVar4 = param_3;
            if (uVar2 < param_3) {
              uVar4 = uVar2;
            }
            iVar3 = (*(int *)(iVar5 + 0x14) + param_2) - uVar1;
            sub_F008858C(*(undefined4 *)(iVar5 + 0x10),iVar3,(iVar3 + uVar4) - param_2,param_4);
            iVar5 = *(int *)(iVar5 + 4);
          }
          else {
            iVar5 = *(int *)(iVar5 + 4);
          }
        }
      }
      else {
        sub_F0088660(*(undefined4 *)(iVar5 + 0x10),param_2,param_3,param_4);
        iVar5 = *(int *)(iVar5 + 4);
      }
      if (iVar5 == param_1 + 0xc) break;
      uVar1 = *(uint *)(iVar5 + 0x18);
    }
  }
  _lock_done(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3720 start=0xf008872c */

/* WARNING: Removing unreachable block (ram,0xf008876c) */
/* WARNING: Removing unreachable block (ram,0xf00887d0) */
/* WARNING: Removing unreachable block (ram,0xf0088730) */

undefined8 sub_F008872C(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  _lock_read(param_1);
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 != param_1 + 0xc) {
    uVar1 = *(uint *)(iVar3 + 0x18);
    while( true ) {
      if ((uVar1 & 0xa0000000) == 0) {
        if (param_3 < *(uint *)(iVar3 + 8)) {
          iVar3 = *(int *)(iVar3 + 4);
        }
        else if (param_2 < *(uint *)(iVar3 + 0xc)) {
          iVar2 = *(int *)(iVar3 + 0x10);
          if (iVar2 == 0) {
            iVar3 = *(int *)(iVar3 + 4);
          }
          else {
            *(sword *)(iVar2 + 0x48) = (sword)param_4;
            while (iVar2 = *(int *)(iVar2 + 0x20), iVar2 != 0) {
              *(sword *)(iVar2 + 0x48) = (sword)param_4;
            }
            iVar3 = *(int *)(iVar3 + 4);
          }
        }
        else {
          iVar3 = *(int *)(iVar3 + 4);
        }
      }
      else {
        sub_F008872C(*(undefined4 *)(iVar3 + 0x10),param_2,param_3,param_4);
        iVar3 = *(int *)(iVar3 + 4);
      }
      if (iVar3 == param_1 + 0xc) break;
      uVar1 = *(uint *)(iVar3 + 0x18);
    }
  }
  _lock_done(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3721 start=0xf00899a8 */

/* WARNING: Removing unreachable block (ram,0xf00899ec) */
/* WARNING: Removing unreachable block (ram,0xf0089a58) */
/* WARNING: Removing unreachable block (ram,0xf0089a80) */
/* WARNING: Removing unreachable block (ram,0xf00899b4) */

undefined8 sub_F00899A8(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  uVar7 = 0;
  _lock_read(param_1);
  iVar6 = *(int *)(param_1 + 0x10);
  if (iVar6 == param_1 + 0xc) {
loc_F0089A80:
    _lock_done(param_1);
    return CONCAT44(param_2,uVar7);
  }
  uVar1 = *(uint *)(iVar6 + 0x18);
  do {
    if ((uVar1 & 0xa0000000) == 0) {
      uVar1 = *(uint *)(iVar6 + 8);
      if (param_3 < uVar1) {
        iVar6 = *(int *)(iVar6 + 4);
      }
      else {
        uVar3 = *(uint *)(iVar6 + 0xc);
        if (param_2 < uVar3) {
          iVar2 = *(int *)(iVar6 + 0x10);
          if (param_2 < uVar1) {
            param_2 = uVar1;
          }
          uVar5 = param_3;
          if (uVar3 <= param_3) {
            uVar5 = uVar3;
          }
          iVar4 = (*(int *)(iVar6 + 0x14) + param_2) - uVar1;
          sub_F0089CA0(iVar2,iVar4,(iVar4 + uVar5) - param_2);
          if (iVar2 != 0) goto loc_F0089A70;
          iVar6 = *(int *)(iVar6 + 4);
        }
        else {
          iVar6 = *(int *)(iVar6 + 4);
        }
      }
    }
    else {
      iVar2 = *(int *)(iVar6 + 0x10);
      sub_F00899A8(iVar2,param_2,param_3);
      if (iVar2 == 5) {
loc_F0089A70:
        uVar7 = 5;
        iVar6 = *(int *)(iVar6 + 4);
      }
      else {
        iVar6 = *(int *)(iVar6 + 4);
      }
    }
    if (iVar6 == param_1 + 0xc) goto loc_F0089A80;
    uVar1 = *(uint *)(iVar6 + 0x18);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3722 start=0xf0089a90 */

/* WARNING: Removing unreachable block (ram,0xf0089c40) */
/* WARNING: Removing unreachable block (ram,0xf0089bf0) */
/* WARNING: Removing unreachable block (ram,0xf0089ba0) */
/* WARNING: Removing unreachable block (ram,0xf0089b50) */
/* WARNING: Removing unreachable block (ram,0xf0089b2c) */
/* WARNING: Removing unreachable block (ram,0xf0089ad8) */
/* WARNING: Removing unreachable block (ram,0xf0089b38) */
/* WARNING: Removing unreachable block (ram,0xf0089b98) */
/* WARNING: Removing unreachable block (ram,0xf0089ba8) */
/* WARNING: Removing unreachable block (ram,0xf0089c18) */
/* WARNING: Removing unreachable block (ram,0xf0089c7c) */
/* WARNING: Removing unreachable block (ram,0xf0089ab4) */

undefined8 sub_F0089A90(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  iVar5 = *(int *)(param_1 + 0x28);
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    puVar1 = &_vm_page_queue_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  if ((*(uint *)(param_2 + 0x1c) & 0x400) == 0) {
    iVar2 = *(int *)(param_2 + 0x20);
  }
  else {
    iVar2 = *(int *)(param_2 + 0x24);
    _pmap_is_modified();
    if (iVar2 == 0) {
      _vm_page_queue_lock = 0;
      uVar6 = 0;
      goto locret_F0089C98;
    }
    iVar2 = *(int *)(param_2 + 0x20);
  }
  if (iVar2 < 0) {
    _vm_page_queue_lock = 0;
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x40000000;
    _assert_wait(param_2,0);
    *(undefined4 *)(param_1 + 0x10) = 0;
    _thread_block();
    do {
      do {
      } while (*(int *)(param_1 + 0x10) != 0);
      piVar3 = (int *)(param_1 + 0x10);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    uVar6 = 2;
  }
  else {
    *(sword *)(param_1 + 0x44) = *(sword *)(param_1 + 0x44) + 1;
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x80000000;
    if ((*(uint *)(param_2 + 0x1c) & 0x8000) != 0) {
      _vm_page_activate(param_2);
    }
    _vm_page_deactivate(param_2);
    _pmap_remove_all(*(undefined4 *)(param_2 + 0x24));
    _vm_page_queue_lock = 0;
    DAT_f013c260._0_4_ = DAT_f013c260._0_4_ + 1;
    if (iVar5 == 0) {
      uVar6 = 1;
      *(sword *)(param_1 + 0x44) = *(sword *)(param_1 + 0x44) + -1;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = 0;
      _vm_pager_put(iVar5,param_2);
      uVar6 = (uint)(iVar5 != 0);
      do {
        do {
        } while (*(int *)(param_1 + 0x10) != 0);
        piVar3 = (int *)(param_1 + 0x10);
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar1 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar1 == (undefined4 *)0x0);
      uVar4 = *(uint *)(param_2 + 0x20);
      *(uint *)(param_2 + 0x20) = uVar4 & 0x7fffffff;
      if ((uVar4 & 0x40000000) != 0) {
        *(uint *)(param_2 + 0x20) = uVar4 & 0x3fffffff;
        _thread_wakeup_prim(param_2,0,0);
      }
      *(sword *)(param_1 + 0x44) = *(sword *)(param_1 + 0x44) + -1;
      _vm_page_queue_lock = 0;
    }
  }
locret_F0089C98:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=3723 start=0xf0089ca0 */

/* WARNING: Removing unreachable block (ram,0xf0089d78) */
/* WARNING: Removing unreachable block (ram,0xf0089d0c) */
/* WARNING: Removing unreachable block (ram,0xf0089d98) */
/* WARNING: Removing unreachable block (ram,0xf0089cc8) */

undefined8 sub_F0089CA0(undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 *puVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  bVar1 = true;
  iVar7 = 0;
  if (param_1 == (undefined4 *)0x0) {
    uVar8 = 0;
locret_F0089DC0:
    return CONCAT44(param_2,uVar8);
  }
  do {
    do {
    } while (param_1[4] != 0);
    piVar2 = param_1 + 4;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  puVar6 = (undefined4 *)*param_1;
loc_F0089CE0:
  if (param_1 != puVar6) {
    uVar3 = puVar6[6];
    do {
      if (uVar3 < param_2) {
        puVar6 = (undefined4 *)puVar6[2];
      }
      else if (uVar3 < param_3) {
        puVar4 = param_1;
        sub_F0089A90(param_1,puVar6);
        if (puVar4 == (undefined4 *)0x1) {
          bVar1 = false;
          puVar6 = (undefined4 *)puVar6[2];
        }
        else if (puVar4 == (undefined4 *)0x0) {
          puVar6 = (undefined4 *)puVar6[2];
        }
        else {
          if (puVar4 == (undefined4 *)0x2) goto loc_f0089d34;
          puVar6 = (undefined4 *)puVar6[2];
        }
      }
      else {
        puVar6 = (undefined4 *)puVar6[2];
      }
      if (param_1 == puVar6) {
        uVar3 = param_1[5];
        goto loc_F0089D50;
      }
      uVar3 = puVar6[6];
    } while( true );
  }
  uVar3 = param_1[5];
loc_F0089D50:
  param_3 = param_3 - param_2;
  if ((uVar3 != 0) && (uVar3 < param_3)) {
    param_3 = uVar3;
  }
  iVar5 = param_1[8];
  param_2 = param_2 + param_1[9];
  sub_F0089CA0(iVar5,param_2,param_2 + param_3);
  if (iVar5 != 0) {
    iVar7 = 5;
  }
  param_1[4] = 0;
  _thread_wakeup_prim(param_1,0,0);
  if ((iVar7 == 5) || (uVar8 = 0, !bVar1)) {
    uVar8 = 5;
  }
  goto locret_F0089DC0;
loc_f0089d34:
  puVar6 = (undefined4 *)*param_1;
  goto loc_F0089CE0;
}
/* GHIDRADEC_FUNCTION index=3724 start=0xf008aeac */

/* WARNING: Removing unreachable block (ram,0xf008aef4) */
/* WARNING: Removing unreachable block (ram,0xf008af4c) */
/* WARNING: Removing unreachable block (ram,0xf008aedc) */
/* WARNING: Removing unreachable block (ram,0xf008af18) */

undefined8 sub_F008AEAC(uint *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
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
  uVar3 = *param_1;
  if (uVar3 >> 0x18 != 0) {
    iVar2 = *(int *)(unk_F0130F70 + (uVar3 >> 0x18) * 4);
    uVar3 = uVar3 & 0xffffff;
    _lock_write(iVar2 + 0x34);
    if (*(int *)(iVar2 + 0x14) <= (int)uVar3) {
      _panic(aVnodePagerDeal);
    }
    if ((int)uVar3 < *(int *)(iVar2 + 0x24)) {
      *(uint *)(iVar2 + 0x24) = uVar3;
    }
    iVar1 = (int)uVar3 >> 3;
    *(byte *)(*(int *)(iVar2 + 0x10) + iVar1) =
         *(byte *)(*(int *)(iVar2 + 0x10) + iVar1) &
         ~(byte)(1 << ((char)uVar3 + (char)iVar1 * -8 & 0x1fU));
    *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 1;
    _lock_done(iVar2 + 0x34);
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3725 start=0xf008b0a8 */

undefined8 sub_F008B0A8(int param_1,uint param_2,undefined4 *param_3)

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
  param_2 = param_2 >> ((byte)_page_shift & 0x1f);
  if (param_2 < *(uint *)(param_1 + 0x10)) {
    if (*(uint *)(param_1 + 0x10) * 4 < 0x41) {
      param_2 = param_2 * 4;
      if (*(char *)(*(int *)(param_1 + 8) + param_2) == '\0') goto loc_F008B120;
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + param_2);
    }
    else {
      iVar1 = *(int *)(*(int *)(param_1 + 8) + (param_2 >> 4) * 4);
      if (iVar1 == 0) goto loc_F008B120;
      param_2 = (param_2 & 0xf) * 4;
      uVar2 = 0;
      if (*(char *)(iVar1 + param_2) == '\0') goto locret_F008B130;
      uVar2 = *(undefined4 *)(iVar1 + param_2);
    }
    *param_3 = uVar2;
    uVar2 = 1;
  }
  else {
loc_F008B120:
    uVar2 = 0;
  }
locret_F008B130:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3726 start=0xf008b138 */

/* WARNING: Removing unreachable block (ram,0xf008b434) */
/* WARNING: Removing unreachable block (ram,0xf008b3f8) */
/* WARNING: Removing unreachable block (ram,0xf008b240) */
/* WARNING: Removing unreachable block (ram,0xf008b2e0) */
/* WARNING: Removing unreachable block (ram,0xf008b2c4) */
/* WARNING: Removing unreachable block (ram,0xf008b1ec) */
/* WARNING: Removing unreachable block (ram,0xf008b1ac) */
/* WARNING: Removing unreachable block (ram,0xf008b374) */
/* WARNING: Removing unreachable block (ram,0xf008b200) */
/* WARNING: Removing unreachable block (ram,0xf008b2d8) */
/* WARNING: Removing unreachable block (ram,0xf008b2f8) */
/* WARNING: Removing unreachable block (ram,0xf008b254) */
/* WARNING: Removing unreachable block (ram,0xf008b4a0) */
/* WARNING: Removing unreachable block (ram,0xf008b47c) */
/* WARNING: Removing unreachable block (ram,0xf008b150) */

undefined8 sub_F008B138(int param_1,int *param_2,int param_3,uint *param_4)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int *piVar8;
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
  uVar7 = (uint)param_2 >> ((byte)_page_shift & 0x1f);
  iVar4 = param_1;
  sub_F008B0A8(param_1,param_2,param_4);
  piVar2 = param_2;
  if (param_3 == 1) {
    uVar7 = (iVar4 != 0) - 1 & 5;
    goto locret_F008B4C8;
  }
  if (iVar4 != 0) {
    if ((int)(*param_4 & 0xffffff) <=
        *(int *)(*(int *)(unk_F0130F70 + (uint)*(byte *)param_4 * 4) + 0x24)) {
      uVar7 = 0;
      goto locret_F008B4C8;
    }
    *(uint *)((int)register0x00000038 + -0xc) = *param_4;
    sub_F008AEAC((undefined *)((int)register0x00000038 + -0xc));
  }
  uVar5 = *(uint *)(param_1 + 0x10);
  uVar1 = uVar7 + 1;
  if (uVar5 < uVar1) {
    piVar2 = (int *)(uVar1 * 4);
    if (piVar2 < (int *)0x41) {
      _kalloc_noblock();
      iVar4 = 0;
      if (piVar2 != (int *)0x0) {
        if (*(int *)(param_1 + 0x10) < 1) {
          iVar4 = *(int *)(param_1 + 0x10);
        }
        else {
          iVar6 = 0;
          do {
            iVar4 = iVar4 + 1;
            *(undefined4 *)(iVar6 + (int)piVar2) = *(undefined4 *)(*(int *)(param_1 + 8) + iVar6);
            iVar6 = iVar6 + 4;
          } while (iVar4 < *(int *)(param_1 + 0x10));
          iVar4 = *(int *)(param_1 + 0x10);
        }
        if (iVar4 < (int)uVar1) {
          iVar6 = iVar4 << 2;
          do {
            *(undefined *)(iVar6 + (int)piVar2) = 0;
            iVar4 = iVar4 + 1;
            iVar6 = iVar6 + 4;
          } while (iVar4 < (int)uVar1);
          iVar4 = *(int *)(param_1 + 0x10);
        }
        else {
          iVar4 = *(int *)(param_1 + 0x10);
        }
        if (iVar4 < 1) {
          *(int **)(param_1 + 8) = piVar2;
        }
        else {
loc_F008B3F4:
          uVar3 = *(undefined4 *)(param_1 + 8);
loc_F008B3F8:
          _kfree(uVar3,iVar4 << 2);
          *(int **)(param_1 + 8) = piVar2;
        }
loc_F008B404:
        *(uint *)(param_1 + 0x10) = uVar1;
        goto loc_F008B408;
      }
    }
    else if (uVar5 == 0) {
      piVar8 = (int *)(((uVar7 >> 4) + 1) * 4);
      piVar2 = piVar8;
      _kalloc_noblock();
      if (piVar2 != (int *)0x0) {
        _bzero(piVar2,piVar8);
        *(int **)(param_1 + 8) = piVar2;
        goto loc_F008B404;
      }
    }
    else if (uVar5 * 4 < 0x41) {
      piVar8 = (int *)(((uVar7 >> 4) + 1) * 4);
      piVar2 = piVar8;
      _kalloc_noblock();
      if (piVar2 != (int *)0x0) {
        _bzero(piVar2,piVar8);
        iVar4 = 0x40;
        _kalloc_noblock();
        *piVar2 = iVar4;
        if (iVar4 != 0) {
          iVar4 = 0;
          if (*(int *)(param_1 + 0x10) < 1) {
            uVar5 = *(uint *)(param_1 + 0x10);
          }
          else {
            iVar6 = *piVar2;
            while( true ) {
              *(undefined4 *)(iVar6 + iVar4 * 4) =
                   *(undefined4 *)(*(int *)(param_1 + 8) + iVar4 * 4);
              iVar4 = iVar4 + 1;
              if (*(int *)(param_1 + 0x10) <= iVar4) break;
              iVar6 = *piVar2;
            }
            uVar5 = *(uint *)(param_1 + 0x10);
          }
          if (uVar5 < 0x10) {
            do {
              iVar4 = uVar5 * 4;
              uVar5 = uVar5 + 1;
              *(undefined *)(*piVar2 + iVar4) = 0;
            } while (uVar5 < 0x10);
            iVar4 = *(int *)(param_1 + 0x10);
          }
          else {
            iVar4 = *(int *)(param_1 + 0x10);
          }
          goto loc_F008B3F4;
        }
        _kfree(piVar2,piVar8);
      }
    }
    else {
      piVar8 = (int *)(((uVar7 >> 4) + 1) * 4);
      if (piVar8 + -((uVar5 - 1 >> 4) + 1) == (int *)0x0) {
        *(uint *)(param_1 + 0x10) = uVar1;
        piVar2 = param_2;
        goto loc_F008B408;
      }
      piVar2 = piVar8;
      _kalloc_noblock();
      if (piVar2 != (int *)0x0) {
        _bzero(piVar2,piVar8);
        uVar5 = 0;
        if (*(int *)(param_1 + 0x10) - 1U >> 4 != 0xffffffff) {
          iVar4 = 0;
          do {
            uVar5 = uVar5 + 1;
            *(undefined4 *)(iVar4 + (int)piVar2) = *(undefined4 *)(*(int *)(param_1 + 8) + iVar4);
            iVar4 = iVar4 + 4;
          } while (uVar5 < (*(int *)(param_1 + 0x10) - 1U >> 4) + 1);
        }
        uVar3 = *(undefined4 *)(param_1 + 8);
        iVar4 = (*(int *)(param_1 + 0x10) - 1U >> 4) + 1;
        goto loc_F008B3F8;
      }
    }
loc_F008B300:
    uVar7 = 5;
  }
  else {
loc_F008B408:
    uVar1 = uVar7 >> 4;
    if ((uint)(*(int *)(param_1 + 0x10) * 4) < 0x41) {
      iVar4 = *(int *)(param_1 + 4);
      _vnode_pager_findpage(iVar4,param_4);
      if (iVar4 == 5) {
        uVar7 = 5;
        goto locret_F008B4C8;
      }
      iVar4 = *(int *)(param_1 + 8);
    }
    else {
      piVar2 = (int *)(uVar1 * 4);
      uVar7 = uVar7 & 0xf;
      if (*(int *)(*(int *)(param_1 + 8) + (int)piVar2) == 0) {
        uVar3 = 0x40;
        _kalloc_noblock();
        *(undefined4 *)(*(int *)(param_1 + 8) + (int)piVar2) = uVar3;
        uVar5 = 0;
        if (*(int *)(*(int *)(param_1 + 8) + (int)piVar2) == 0) goto loc_F008B300;
        do {
          iVar4 = uVar5 * 4;
          uVar5 = uVar5 + 1;
          *(undefined *)(*(int *)(*(int *)(param_1 + 8) + (int)piVar2) + iVar4) = 0;
        } while (uVar5 < 0x10);
      }
      iVar4 = *(int *)(param_1 + 4);
      _vnode_pager_findpage(iVar4,param_4);
      if (iVar4 == 5) goto loc_F008B300;
      iVar4 = *(int *)(*(int *)(param_1 + 8) + uVar1 * 4);
    }
    *(uint *)(iVar4 + uVar7 * 4) = *param_4;
    uVar7 = 0;
  }
locret_F008B4C8:
  return CONCAT44(piVar2,uVar7);
}
/* GHIDRADEC_FUNCTION index=3727 start=0xf008bf14 */

undefined8 sub_F008BF14(uint *param_1,uint param_2)

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
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  uint uVar3;
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
  uVar3 = *param_1;
  puVar2 = (undefined *)0x0;
  if (uVar3 >> 0x18 != 0) {
    iVar1 = 0;
    if (0 < dword_F0111EA8) {
      param_2 = uVar3 & 0xffffff;
      puVar2 = unk_F0130FB0;
      do {
        iVar1 = iVar1 + 1;
        if ((uint)(byte)*puVar2 == uVar3 >> 0x18) {
          uVar3 = *(uint *)puVar2 & 0xffffff;
          if (uVar3 < param_2) {
            uVar3 = param_2;
          }
          *(uint *)puVar2 = *(uint *)puVar2 & 0xff000000 | uVar3;
          goto locret_F008BFC0;
        }
        puVar2 = (undefined *)((int)puVar2 + 4);
      } while (iVar1 < dword_F0111EA8);
    }
    puVar2 = (undefined *)0xf0111c00;
    iVar1 = dword_F0111EA8 * 4;
    dword_F0111EA8 = dword_F0111EA8 + 1;
    *(uint *)(unk_F0130FB0 + iVar1) = uVar3;
  }
locret_F008BFC0:
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=3728 start=0xf008c44c */

/* WARNING: Removing unreachable block (ram,0xf008c500) */
/* WARNING: Removing unreachable block (ram,0xf008c4c4) */
/* WARNING: Removing unreachable block (ram,0xf008c484) */
/* WARNING: Removing unreachable block (ram,0xf008c490) */
/* WARNING: Removing unreachable block (ram,0xf008c4f4) */
/* WARNING: Removing unreachable block (ram,0xf008c478) */
/* WARNING: Removing unreachable block (ram,0xf008c460) */

undefined8 sub_F008C44C(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
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
  iVar1 = _kernel_task;
  _task_create(_kernel_task,0,&_IOTask_kern);
  if (iVar1 == 0) {
    _task_deallocate(_IOTask_kern,0);
    _vm_map_deallocate(*(undefined4 *)(_IOTask_kern + 0xc));
    iVar1 = _IOTask_kern;
    *(undefined4 *)(_IOTask_kern + 0xc) = _kernel_map;
    *(undefined4 *)(iVar1 + 0x3c) = _kernel_proc;
    *(undefined4 *)(iVar1 + 0x50) = 1;
    _lock_init(*(int *)(iVar1 + 0x38) + 0x20,1);
    iVar1 = _IOTask_kern;
    *(undefined4 *)(*(int *)(_IOTask_kern + 0x38) + 0x1c) = _rootcred;
    **(undefined4 **)(iVar1 + 0x38) = _kernel_proc;
    _processor_set_policy_enable(_default_pset,2);
    uVar2 = *(undefined4 *)(_IOTask_kern + 0x6c);
    _IOTaskGetPort();
    _IOTask = uVar2;
  }
  else {
    _IOLog(aIolibioinitTas);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3729 start=0xf008c65c */

/* WARNING: Removing unreachable block (ram,0xf008c6a4) */
/* WARNING: Removing unreachable block (ram,0xf008c680) */
/* WARNING: Removing unreachable block (ram,0xf008c670) */
/* WARNING: Removing unreachable block (ram,0xf008c668) */
/* WARNING: Removing unreachable block (ram,0xf008c678) */
/* WARNING: Removing unreachable block (ram,0xf008c690) */
/* WARNING: Removing unreachable block (ram,0xf008c6ac) */
/* WARNING: Removing unreachable block (ram,0xf008c660) */

undefined8 sub_F008C65C(undefined4 param_1,undefined4 param_2)

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
  sub_F008C6BC();
  _probeNativeDevices();
  _probeHardware();
  _probeDirectDevices();
  sub_F008C728();
  _objc_msgSend(dword_F0130FF0,paLock);
  _objc_msgSend(dword_F0130FF0,paUnlockwith,1);
  _IOExitThread();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3730 start=0xf008c6bc */

/* WARNING: Removing unreachable block (ram,0xf008c704) */
/* WARNING: Removing unreachable block (ram,0xf008c6f4) */
/* WARNING: Removing unreachable block (ram,0xf008c6dc) */

undefined8 sub_F008C6BC(undefined4 param_1,undefined4 param_2)

{
  undefined (*pauVar1) [9];
  undefined4 unaff_l0;
  undefined (**ppauVar2) [9];
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
  ppauVar2 = &_indirectDevList;
  pauVar1 = _indirectDevList;
  while (pauVar1 != (undefined (*) [9])0x0) {
    pauVar1 = *ppauVar2;
    _objc_getClass();
    if (pauVar1 == (undefined (*) [9])0x0) {
      _IOLog(aRegisterindire,*ppauVar2);
    }
    else {
      _objc_msgSend();
    }
    ppauVar2 = ppauVar2 + 1;
    pauVar1 = *ppauVar2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3731 start=0xf008c728 */

/* WARNING: Removing unreachable block (ram,0xf008c778) */
/* WARNING: Removing unreachable block (ram,0xf008c764) */
/* WARNING: Removing unreachable block (ram,0xf008c74c) */

undefined8 sub_F008C728(undefined4 param_1,undefined4 param_2)

{
  undefined (*pauVar1) [12];
  undefined4 unaff_l0;
  undefined (**ppauVar2) [12];
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
  ppauVar2 = &_pseudoDevList;
  pauVar1 = _pseudoDevList;
  while (pauVar1 != (undefined (*) [12])0x0) {
    pauVar1 = *ppauVar2;
    _objc_getClass();
    if (pauVar1 == (undefined (*) [12])0x0) {
      _IOLog(aProbepseudodev,*ppauVar2);
    }
    else {
      _objc_msgSend(paIodevice_0,paAddloadedclass_0,pauVar1,0);
    }
    ppauVar2 = ppauVar2 + 1;
    pauVar1 = *ppauVar2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3732 start=0xf008c79c */

/* WARNING: Removing unreachable block (ram,0xf008c7f0) */
/* WARNING: Removing unreachable block (ram,0xf008c7e4) */
/* WARNING: Removing unreachable block (ram,0xf008c818) */
/* WARNING: Removing unreachable block (ram,0xf008c7c0) */

undefined8 sub_F008C79C(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = 0;
  while( true ) {
    iVar1 = paIodevice_0;
    _objc_msgSend(paIodevice_0,paLookupbyobject,iVar3,(undefined *)((int)register0x00000038 + -0xc))
    ;
    iVar3 = iVar3 + 1;
    if (iVar1 == -0x2c0) break;
    if (iVar1 != -0x2d7) {
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      _objc_msgSend(uVar2,paClass);
      _objc_msgSend();
      if ((uVar2 & 0xff) != 0) {
        _objc_msgSend(*(undefined4 *)((int)register0x00000038 + -0xc),paPerformWith,param_1,param_2)
        ;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3733 start=0xf008c868 */

/* WARNING: Removing unreachable block (ram,0xf008c894) */

undefined8 -[KernLock initWithLevel:](undefined *param_1,undefined4 param_2,int param_3)

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
  if (param_3 == 0) {
    *(undefined **)((int)register0x00000038 + -0x10) = param_1;
    param_1 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141b00;
    _objc_msgSendSuper(param_1,paFree);
  }
  else {
    *(int *)(param_1 + 8) = param_3;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3734 start=0xf008c8a8 */

/* WARNING: Removing unreachable block (ram,0xf008c8b8) */

undefined8 -[KernLock init](undefined4 param_1,undefined4 param_2)

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
  _objc_msgSend(param_1,paInitwithlevel,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3735 start=0xf008c8c8 */

/* WARNING: Removing unreachable block (ram,0xf008c8e4) */

undefined8 -[KernLock free](undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141b00;
  _objc_msgSendSuper(puVar1,paFree);
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=3736 start=0xf008c8f4 */

undefined8 -[KernLock level](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 8));
}
/* GHIDRADEC_FUNCTION index=3737 start=0xf008c904 */

/* WARNING: Removing unreachable block (ram,0xf008c924) */
/* WARNING: Removing unreachable block (ram,0xf008c92c) */
/* WARNING: Removing unreachable block (ram,0xf008c908) */

undefined8 -[KernLock acquire](int param_1,undefined4 param_2)

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
  iVar1 = param_1;
  _curipl();
  if (iVar1 < *(int *)(param_1 + 8)) {
    _ipltospl(*(int *)(param_1 + 8));
    _splx();
    *(int *)(param_1 + 0xc) = iVar1;
  }
  else {
    *(int *)(param_1 + 0xc) = iVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3738 start=0xf008c940 */

/* WARNING: Removing unreachable block (ram,0xf008c94c) */
/* WARNING: Removing unreachable block (ram,0xf008c944) */

undefined8 -[KernLock release](int param_1,undefined4 param_2)

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
  _ipltospl(*(undefined4 *)(param_1 + 0xc));
  _splx();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3739 start=0xf008c9c8 */

/* WARNING: Removing unreachable block (ram,0xf008ca48) */
/* WARNING: Removing unreachable block (ram,0xf008ca0c) */
/* WARNING: Removing unreachable block (ram,0xf008ca38) */
/* WARNING: Removing unreachable block (ram,0xf008ca5c) */
/* WARNING: Removing unreachable block (ram,0xf008c9e4) */

undefined8
-[KernBusItemResource initWithItemCount:itemBase:itemKind:owner:]
          (int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,undefined4 param_6)

{
  undefined (*pauVar1) [12];
  int iVar2;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141bf0;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  if ((param_3 < 0x401) && (param_4 < param_4 + param_3)) {
    *(undefined4 *)(param_1 + 4) = param_6;
    if (param_5 == 0) {
      pauVar1 = paKernbusitem;
      _objc_msgSend(paKernbusitem,paClass);
      *(undefined (**) [12])(param_1 + 0x10) = pauVar1;
    }
    else {
      *(int *)(param_1 + 0x10) = param_5;
    }
    iVar2 = param_3 << 2;
    _IOMalloc();
    *(int *)(param_1 + 0x18) = iVar2;
    *(undefined4 *)(param_1 + 0x14) = 0;
    _bzero(*(undefined4 *)(param_1 + 0x18),param_3 << 2);
    *(uint *)(param_1 + 8) = param_3;
    *(uint *)(param_1 + 0xc) = param_4;
  }
  else {
    _objc_msgSend(param_1,paFree);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3740 start=0xf008ca74 */

/* WARNING: Removing unreachable block (ram,0xf008ca90) */

undefined8
-[KernBusItemResource initWithItemCount:itemKind:owner:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

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
  _objc_msgSend(param_1,paInitwithitemco_0,param_3,0,param_4,param_5);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3741 start=0xf008caa0 */

/* WARNING: Removing unreachable block (ram,0xf008caac) */

undefined8 -[KernBusItemResource init](undefined4 param_1,undefined4 param_2)

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
  _objc_msgSend(param_1,paFree);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3742 start=0xf008cabc */

/* WARNING: Removing unreachable block (ram,0xf008cb10) */
/* WARNING: Removing unreachable block (ram,0xf008caf0) */

undefined8 -[KernBusItemResource free](undefined *param_1,undefined4 param_2)

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
  if (*(int *)(param_1 + 0x14) < 1) {
    if (*(int *)(param_1 + 8) == 0) {
      *(undefined **)((int)register0x00000038 + -0x10) = param_1;
    }
    else if (*(int *)(param_1 + 0x18) == 0) {
      *(undefined **)((int)register0x00000038 + -0x10) = param_1;
    }
    else {
      _IOFree(*(int *)(param_1 + 0x18),4);
      *(undefined **)((int)register0x00000038 + -0x10) = param_1;
    }
    param_1 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141bf0;
    _objc_msgSendSuper(param_1,paFree);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3743 start=0xf008cb24 */

/* WARNING: Removing unreachable block (ram,0xf008cb88) */
/* WARNING: Removing unreachable block (ram,0xf008cbb8) */
/* WARNING: Removing unreachable block (ram,0xf008cb70) */

undefined8 -[KernBusItemResource reserveItem:](int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
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
  uVar2 = *(uint *)(param_1 + 0xc);
  iVar4 = *(int *)(param_1 + 0x18);
  if ((uVar2 <= param_3) && (param_3 < uVar2 + *(int *)(param_1 + 8))) {
    iVar3 = (param_3 - uVar2) * 4;
    if (*(int *)(iVar4 + iVar3) == 0) {
      iVar1 = *(int *)(param_1 + 0x10);
      _objc_msgSend(iVar1,paAlloc);
      _objc_msgSend();
      *(int *)(iVar4 + iVar3) = iVar1;
      if ((iVar1 != 0) &&
         (iVar1 = *(int *)(param_1 + 0x14) + 1, *(int *)(param_1 + 0x14) = iVar1, iVar1 == 1)) {
        _objc_msgSend(*(undefined4 *)(param_1 + 4),paResourceactive);
      }
      uVar5 = *(undefined4 *)(iVar4 + iVar3);
      goto locret_F008CBC4;
    }
  }
  uVar5 = 0;
locret_F008CBC4:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=3744 start=0xf008cbcc */

/* WARNING: Removing unreachable block (ram,0xf008cc78) */
/* WARNING: Removing unreachable block (ram,0xf008cc48) */
/* WARNING: Removing unreachable block (ram,0xf008cc18) */
/* WARNING: Removing unreachable block (ram,0xf008cc30) */

undefined8 -[KernBusItemResource shareItem:](int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  uVar1 = *(uint *)(param_1 + 0xc);
  iVar3 = *(int *)(param_1 + 0x18);
  if ((param_3 < uVar1) || (uVar1 + *(int *)(param_1 + 8) <= param_3)) {
    iVar4 = 0;
  }
  else {
    iVar2 = (param_3 - uVar1) * 4;
    iVar4 = *(int *)(iVar3 + iVar2);
    if (iVar4 == 0) {
      iVar4 = *(int *)(param_1 + 0x10);
      _objc_msgSend(iVar4,paAlloc);
      _objc_msgSend();
      *(int *)(iVar3 + iVar2) = iVar4;
      if ((iVar4 != 0) &&
         (iVar4 = *(int *)(param_1 + 0x14) + 1, *(int *)(param_1 + 0x14) = iVar4, iVar4 == 1)) {
        _objc_msgSend(*(undefined4 *)(param_1 + 4),paResourceactive);
      }
      iVar4 = *(int *)(iVar3 + iVar2);
    }
    else {
      _objc_msgSend(iVar4,paShare);
    }
  }
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=3745 start=0xf008cc8c */

undefined8 -[KernBusItemResource findFreeItem](int param_1,int param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  uVar1 = 0;
  if (*(uint *)(param_1 + 8) != 0) {
    param_2 = 0;
    do {
      if (*(int *)(param_2 + *(int *)(param_1 + 0x18)) == 0) {
        iVar2 = *(int *)(param_1 + 0xc);
        goto locret_F008CCCC;
      }
      uVar1 = uVar1 + 1;
      param_2 = param_2 + 4;
    } while (uVar1 < *(uint *)(param_1 + 8));
  }
  iVar2 = *(int *)(param_1 + 0xc);
locret_F008CCCC:
  return CONCAT44(param_2,uVar1 + iVar2);
}
/* GHIDRADEC_FUNCTION index=3746 start=0xf008ccd4 */

/* WARNING: Removing unreachable block (ram,0xf008cd44) */
/* WARNING: Removing unreachable block (ram,0xf008cd54) */
/* WARNING: Removing unreachable block (ram,0xf008cce8) */

undefined8 -[KernBusItemResource _destroyItem:](int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = *(int *)(param_1 + 0x18);
  uVar1 = param_3;
  _objc_msgSend(param_3,paIskindof,*(undefined4 *)(param_1 + 0x10));
  if ((uVar1 & 0xff) == 0) {
    param_3 = 0;
  }
  else {
    iVar2 = (*(int *)(param_3 + 8) - *(int *)(param_1 + 0xc)) * 4;
    if (*(int *)(iVar3 + iVar2) == 0) {
      param_3 = 0;
    }
    else {
      *(undefined4 *)(iVar3 + iVar2) = 0;
      iVar3 = *(int *)(param_1 + 0x14) + -1;
      *(int *)(param_1 + 0x14) = iVar3;
      if (iVar3 == 0) {
        _objc_msgSend(*(undefined4 *)(param_1 + 4),paResourceinacti);
      }
      _objc_msgSend(param_3,paDealloc);
    }
  }
  return CONCAT44(param_2,param_3);
}
/* GHIDRADEC_FUNCTION index=3747 start=0xf008cd68 */

/* WARNING: Removing unreachable block (ram,0xf008cd8c) */
/* WARNING: Removing unreachable block (ram,0xf008cdc0) */

undefined8
-[KernBusItem initForResource:item:shareable:]
          (undefined *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined param_5)

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
  if (param_3 == 0) {
    *(undefined **)((int)register0x00000038 + -0x10) = param_1;
    param_1 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141bc8;
    _objc_msgSendSuper(param_1,paFree);
  }
  else {
    *(undefined **)((int)register0x00000038 + -0x10) = param_1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141bc8;
    _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
    *(int *)(param_1 + 4) = param_3;
    *(undefined4 *)(param_1 + 8) = param_4;
    *(undefined4 *)(param_1 + 0xc) = 1;
    param_1[0x10] = param_5;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3748 start=0xf008cdd4 */

/* WARNING: Removing unreachable block (ram,0xf008cdf0) */

undefined8 -[KernBusItem init](undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141bc8;
  _objc_msgSendSuper(puVar1,paFree);
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=3749 start=0xf008ce00 */

/* WARNING: Removing unreachable block (ram,0xf008ce24) */

undefined8 -[KernBusItem free](int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
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
  iVar1 = *(int *)(param_1 + 0xc) + -1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (iVar1 < 1) {
    uVar2 = *(undefined4 *)(param_1 + 4);
    _objc_msgSend(uVar2,paDestroyitem);
  }
  else {
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}

