
/* WARNING: Removing unreachable block (ram,0xf00a62b8) */
/* WARNING: Removing unreachable block (ram,0xf00a61dc) */
/* WARNING: Removing unreachable block (ram,0xf00a61d4) */
/* WARNING: Removing unreachable block (ram,0xf00a6230) */
/* WARNING: Removing unreachable block (ram,0xf00a62ac) */
/* WARNING: Removing unreachable block (ram,0xf00a61cc) */

undefined8 _l15_ecc_async_flt(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
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
  uVar1 = param_1;
  _get_efsr_vaddr();
  uVar2 = uVar1;
  _get_efar0_vaddr();
  uVar3 = uVar2;
  _get_efar1_vaddr();
  uRamfefef008 = 0;
  if (_nofault != 0) goto locret_F00A62F0;
  if ((_cpu == 0x72) && ((uVar1 & 0x20002) != 0)) {
    puVar4 = &_system_fatal;
    _simple_lock_try();
    if (puVar4 == (undefined4 *)0x0) {
      _sys_fatal_flt = 2;
      DAT_f013ec72 = 0;
      DAT_f013ec78._8_4_ = 0;
      DAT_f013ec78._12_4_ = 0;
      dword_F013EC74 = uVar1;
      DAT_f013ec78._0_4_ = uVar2;
      DAT_f013ec78._4_4_ = uVar3;
    }
    goto locret_F00A62F0;
  }
  if ((uVar1 & 8) == 0) {
    if ((uVar1 & 1) == 0) goto loc_F00A62B8;
  }
  else if ((uVar2 & 0x8000000) != 0) {
loc_F00A62B8:
    puVar4 = &_system_fatal;
    _simple_lock_try();
    if (puVar4 == (undefined4 *)0x0) {
      _sys_fatal_flt = 2;
      DAT_f013ec72 = 0;
      DAT_f013ec78._8_4_ = 0;
      DAT_f013ec78._12_4_ = 0;
      dword_F013EC74 = uVar1;
      DAT_f013ec78._0_4_ = uVar2;
      DAT_f013ec78._4_4_ = uVar3;
    }
    goto locret_F00A62F0;
  }
  _handle_aflt(_cpuid,2,uVar1,uVar2,uVar3);
locret_F00A62F0:
  return CONCAT44(param_2,param_1);
}
