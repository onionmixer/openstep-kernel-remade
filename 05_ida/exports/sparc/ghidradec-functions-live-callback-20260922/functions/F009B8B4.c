
/* WARNING: Removing unreachable block (ram,0xf009b918) */
/* WARNING: Removing unreachable block (ram,0xf009b960) */
/* WARNING: Removing unreachable block (ram,0xf009b8e8) */

undefined8 _vik_module_wkaround(uint *param_1,uint param_2,int param_3,uint param_4)

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
  if (_do_work_arounds != 0) {
    if ((_vik_rev_level == 1) && (param_3 == 2)) {
      uVar1 = *param_1;
      _mmu_probe();
      *(uint *)((int)register0x00000038 + -0xc) = uVar1;
      if ((uVar1 & 0x47) == 0x42) {
        _pmap_clear_modify(*(undefined4 *)(*(int *)(*(int *)(_active_threads + 0xc) + 0xc) + 0x24),
                           *param_1);
      }
    }
    if (((param_4 >> 2 & 7) - 2 < 2) &&
       (((*param_1 == *(uint *)(param_2 + 8) || (0xfdf < (*(uint *)(param_2 + 4) & 0xfff))) &&
        (uVar1 = param_2, _fix_addr(param_2,param_4), uVar1 != 0xffffffff)))) {
      *param_1 = uVar1;
    }
  }
  return CONCAT44(param_2,param_1);
}

