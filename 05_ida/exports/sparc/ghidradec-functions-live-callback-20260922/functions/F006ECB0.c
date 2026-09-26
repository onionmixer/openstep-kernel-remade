
/* WARNING: Removing unreachable block (ram,0xf006ece8) */
/* WARNING: Removing unreachable block (ram,0xf006ecbc) */

undefined8 _pset_sys_bootstrap(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined *puVar1;
  undefined4 unaff_l1;
  int iVar2;
  int iVar3;
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
  _pset_init(_default_pset);
  DAT_f01350e8._0_4_ = 0;
  iVar2 = 0;
  puVar1 = _processor_array;
  iVar3 = 0;
  do {
    *(undefined **)((int)&_processor_ptr + iVar3) = puVar1;
    _processor_init(puVar1,iVar2);
    puVar1 = puVar1 + 0x148;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar2 < 1);
  _master_processor = (&_processor_ptr)[_master_cpu];
  _all_psets_lock = 0;
  _all_psets = _default_pset;
  DAT_f0135110._0_4_ = &_all_psets;
  DAT_f013510c._0_4_ = &_all_psets;
  DAT_f0134fb4 = _default_pset;
  _all_psets_count = 1;
  DAT_f0135110._4_4_ = 1;
  DAT_f01350e8._0_4_ = 0;
  return CONCAT44(param_2,param_1);
}

