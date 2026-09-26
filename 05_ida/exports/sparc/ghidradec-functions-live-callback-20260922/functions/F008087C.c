
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

