
/* WARNING: Removing unreachable block (ram,0xf007d188) */
/* WARNING: Removing unreachable block (ram,0xf007d14c) */
/* WARNING: Removing unreachable block (ram,0xf007d140) */
/* WARNING: Removing unreachable block (ram,0xf007d158) */
/* WARNING: Removing unreachable block (ram,0xf007d1b4) */
/* WARNING: Removing unreachable block (ram,0xf007d134) */

undefined8 sub_F007D0E8(int *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
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
  if (((param_1[1] == 0x20) && (*param_1 < 0)) && ((param_1[6] & 0xfffffffcU) == 0x11200018)) {
    iVar1 = param_1[7];
    _convert_port_to_pset_name(iVar1);
    uVar2 = param_1[2];
    _convert_port_to_host_priv();
    _host_processor_set_priv();
    param_2[7] = uVar2;
    _pset_deallocate(iVar1);
    if (param_2[7] == 0) {
      if ((param_1[7] != 0) && (param_1[7] != -1)) {
        _ipc_port_release_send();
      }
      param_2[1] = 0x28;
      *param_2 = *param_2 | 0x80000000;
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      param_2[8] = dword_F0111124;
      _convert_pset_to_port();
      param_2[9] = uVar2;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}

