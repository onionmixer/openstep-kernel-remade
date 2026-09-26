
/* WARNING: Removing unreachable block (ram,0xf00a6424) */
/* WARNING: Removing unreachable block (ram,0xf00a64f0) */
/* WARNING: Removing unreachable block (ram,0xf00a63b4) */
/* WARNING: Removing unreachable block (ram,0xf00a63ac) */
/* WARNING: Removing unreachable block (ram,0xf00a6484) */
/* WARNING: Removing unreachable block (ram,0xf00a63fc) */
/* WARNING: Removing unreachable block (ram,0xf00a653c) */
/* WARNING: Removing unreachable block (ram,0xf00a6394) */

undefined8 _l15_mod_async_flt(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 uVar5;
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
  iVar1 = param_1;
  _mmu_chk_wdreset();
  if (iVar1 != 0) {
    _prom_stopcpu(0);
  }
  _mmu_getasyncflt((undefined *)((int)register0x00000038 + -0x18));
  bVar3 = true;
  if (_mod_info != 0x40) {
    uVar4 = *(uint *)((int)register0x00000038 + -0x18);
    if (_mod_info == 0x41) {
      uVar4 = *(uint *)((int)register0x00000038 + -0x10);
      if ((uVar4 == 0xffffffff) ||
         (uVar5 = *(undefined4 *)((int)register0x00000038 + -0xc), (uVar4 & 0x2000000) == 0))
      goto loc_F00A6530;
      iVar1 = *(int *)((int)register0x00000038 + -0x18);
      _vac_parity_chk_dis(iVar1,uVar4);
      if ((_nofault != 0) && (bVar3 = false, iVar1 == 0)) goto loc_F00A6530;
      puVar2 = &_system_fatal;
      _simple_lock_try();
      bVar3 = false;
      if (puVar2 != (undefined4 *)0x0) goto loc_F00A6530;
      _sys_fatal_flt = 1;
      DAT_f013ec72 = 0;
      DAT_f013ec78._4_4_ = 0;
      DAT_f013ec78._8_4_ = 0;
      DAT_f013ec78._12_4_ = 0;
      dword_F013EC74 = uVar4;
      DAT_f013ec78._0_4_ = uVar5;
    }
    else {
      if ((uVar4 & 1) != 0) {
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x14);
        if (_nofault == 0) {
          puVar2 = &_system_fatal;
          _simple_lock_try();
          bVar3 = false;
          if (puVar2 != (undefined4 *)0x0) goto loc_F00A64C4;
          _sys_fatal_flt = 1;
          DAT_f013ec72 = 0;
          DAT_f013ec78._4_4_ = 0;
          DAT_f013ec78._8_4_ = 0;
          DAT_f013ec78._12_4_ = 0;
          dword_F013EC74 = uVar4;
          DAT_f013ec78._0_4_ = uVar5;
        }
        bVar3 = false;
      }
loc_F00A64C4:
      uVar4 = *(uint *)((int)register0x00000038 + -0x10);
      if ((uVar4 == 0xffffffff) || ((uVar4 & 1) == 0)) goto loc_F00A6530;
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0xc);
      if (_nofault == 0) {
        puVar2 = &_system_fatal;
        _simple_lock_try();
        bVar3 = false;
        if (puVar2 != (undefined4 *)0x0) goto loc_F00A6530;
        _sys_fatal_flt = 1;
        DAT_f013ec72 = 1;
        DAT_f013ec78._4_4_ = 0;
        DAT_f013ec78._8_4_ = 0;
        DAT_f013ec78._12_4_ = 0;
        dword_F013EC74 = uVar4;
        DAT_f013ec78._0_4_ = uVar5;
      }
    }
  }
  bVar3 = false;
loc_F00A6530:
  if (bVar3) {
    _prom_stopcpu(0);
  }
  return CONCAT44(param_2,param_1);
}

