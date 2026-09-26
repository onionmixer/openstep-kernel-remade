
undefined8 _vm_statistics(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
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
  
  puVar1 = _page_size;
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
  if (param_1 == 0) {
    uVar2 = 4;
  }
  else {
    _vm_stat = _page_size;
    DAT_f013c244._0_4_ = _vm_page_free_count;
    DAT_f013c244._4_4_ = _vm_page_active_count;
    DAT_f013c244._8_4_ = _vm_page_inactive_count;
    DAT_f013c244._12_4_ = _vm_page_wire_count;
    *param_2 = _page_size;
    param_2[1] = DAT_f013c244._0_4_;
    param_2[2] = DAT_f013c244._4_4_;
    param_2[3] = DAT_f013c244._8_4_;
    param_2[4] = DAT_f013c244._12_4_;
    param_2[5] = DAT_f013c244._16_4_;
    param_2[6] = DAT_f013c244._20_4_;
    param_2[7] = DAT_f013c244._24_4_;
    param_2[8] = DAT_f013c244._28_4_;
    param_2[9] = DAT_f013c244._32_4_;
    param_2[10] = DAT_f013c244._36_4_;
    param_2[0xb] = DAT_f013c244._40_4_;
    uVar2 = 0;
    param_2[0xc] = DAT_f013c244._44_4_;
    param_2 = puVar1;
  }
  return CONCAT44(param_2,uVar2);
}

