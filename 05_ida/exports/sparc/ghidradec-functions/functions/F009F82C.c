
/* WARNING: Removing unreachable block (ram,0xf009f920) */
/* WARNING: Removing unreachable block (ram,0xf009f8f8) */
/* WARNING: Removing unreachable block (ram,0xf009f868) */
/* WARNING: Removing unreachable block (ram,0xf009f8c8) */
/* WARNING: Removing unreachable block (ram,0xf009f90c) */
/* WARNING: Removing unreachable block (ram,0xf009f92c) */
/* WARNING: Removing unreachable block (ram,0xf009f830) */

undefined8 _pmap_copy_page(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 *puVar5;
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
  uVar4 = param_1;
  _splvm();
  dword_F013DF18 = dword_F013DF18 + 1;
  do {
    do {
    } while (unk_F013E004._0_4_ != 0);
    puVar5 = &unk_F013E004;
    _simple_lock_try();
    uVar3 = unk_F013DFF4._12_4_;
    uVar2 = unk_F013DFF4._8_4_;
    uVar1 = unk_F013DFF4._0_4_;
  } while (puVar5 == (undefined8 *)0x0);
  *(undefined4 *)((int)register0x00000038 + -0xc) = _tmp_maps;
  _set_pte((undefined *)((int)register0x00000038 + -0xc),unk_F013DFF4._0_4_,
           (param_1 & ~_page_mask) >> 0xc,7,1,0,0);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uVar2;
  _set_pte((undefined *)((int)register0x00000038 + -0xc),uVar3,(param_2 & ~_page_mask) >> 0xc,7,1,0,
           0);
  _bcopy(uVar1,uVar3,_page_size);
  _pmap_vacflush((param_2 & ~_page_mask) >> 0xc);
  unk_F013E004._0_4_ = 0;
  _splx(uVar4);
  return CONCAT44(param_2,param_1);
}
