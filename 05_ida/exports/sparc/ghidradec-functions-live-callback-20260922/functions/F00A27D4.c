
/* WARNING: Removing unreachable block (ram,0xf00a2930) */
/* WARNING: Removing unreachable block (ram,0xf00a2884) */
/* WARNING: Removing unreachable block (ram,0xf00a2840) */
/* WARNING: Removing unreachable block (ram,0xf00a2824) */
/* WARNING: Removing unreachable block (ram,0xf00a282c) */
/* WARNING: Removing unreachable block (ram,0xf00a28f0) */
/* WARNING: Removing unreachable block (ram,0xf00a289c) */
/* WARNING: Removing unreachable block (ram,0xf00a2940) */
/* WARNING: Removing unreachable block (ram,0xf00a27fc) */

undefined8 _pmap_dealloc_kseg_entry(int param_1,undefined4 param_2)

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
  dword_F013DF60 = dword_F013DF60 + 1;
  if (*(char *)(param_1 + 0xf) != '\0') {
    _panic(aPmapDeallocKse_1);
  }
  if ((*(int *)(param_1 + 0x10) != 0) || (*(int *)(param_1 + 0x14) != 0)) {
    _panic(aPampDeallocKse);
  }
  iVar1 = param_1;
  _check_ptbl();
  if (iVar1 != 0) {
    _panic(aPmapDeallocKse_2);
  }
  if (*(char *)(param_1 + 0xd) == '\x03') {
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x10) = 0xfff;
    *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
    iVar1 = *(int *)(param_1 + 0x20);
    if (iVar1 == 0) {
loc_F00A28F8:
      *(undefined4 *)(param_1 + 8) = 0;
    }
    else {
      _set_invalidptp(iVar1,*(uint *)(param_1 + 0x24) & 0xfffc0000);
      if (*(char *)(iVar1 + 0xf) == '\0') {
        _pmap_dealloc_seg_entry(iVar1);
        *(undefined4 *)(param_1 + 8) = 0;
      }
      else {
        *(undefined4 *)(param_1 + 8) = 0;
      }
    }
  }
  else {
    if (*(char *)(param_1 + 0xd) == '\x02') {
      if (0xefffffff < *(uint *)(param_1 + 0x24)) goto locret_F00A2950;
      *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = 0xfff;
      *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0;
      if (*(int *)(param_1 + 0x20) != 0) {
        _set_invalidptp(*(int *)(param_1 + 0x20),*(uint *)(param_1 + 0x24) & 0xff000000);
      }
      goto loc_F00A28F8;
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  DAT_f013de84._0_4_ = DAT_f013de84._0_4_ + -1;
  param_1 = *(int *)(param_1 + 4);
  if (*(sword *)(param_1 + 0x1e) == 0) {
    *(undefined2 *)(param_1 + 0x1e) = 1;
    _del_any_pool(&_kseg_active,param_1);
    _add_pool(&_kseg_semi_active,param_1);
  }
  else {
    *(sword *)(param_1 + 0x1e) = *(sword *)(param_1 + 0x1e) + 1;
  }
locret_F00A2950:
  return CONCAT44(param_2,param_1);
}

