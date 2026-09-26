
/* WARNING: Removing unreachable block (ram,0xf00a60b8) */
/* WARNING: Removing unreachable block (ram,0xf00a6098) */
/* WARNING: Removing unreachable block (ram,0xf00a6080) */
/* WARNING: Removing unreachable block (ram,0xf00a605c) */
/* WARNING: Removing unreachable block (ram,0xf00a602c) */
/* WARNING: Removing unreachable block (ram,0xf00a6004) */
/* WARNING: Removing unreachable block (ram,0xf00a60cc) */
/* WARNING: Removing unreachable block (ram,0xf00a5f78) */
/* WARNING: Removing unreachable block (ram,0xf00a5f44) */
/* WARNING: Removing unreachable block (ram,0xf00a5f14) */
/* WARNING: Removing unreachable block (ram,0xf00a5f2c) */
/* WARNING: Removing unreachable block (ram,0xf00a5f5c) */
/* WARNING: Removing unreachable block (ram,0xf00a5fc4) */
/* WARNING: Removing unreachable block (ram,0xf00a60e4) */
/* WARNING: Removing unreachable block (ram,0xf00a6018) */
/* WARNING: Removing unreachable block (ram,0xf00a6050) */
/* WARNING: Removing unreachable block (ram,0xf00a6070) */
/* WARNING: Removing unreachable block (ram,0xf00a608c) */
/* WARNING: Removing unreachable block (ram,0xf00a60ac) */
/* WARNING: Removing unreachable block (ram,0xf00a60f0) */
/* WARNING: Removing unreachable block (ram,0xf00a5f0c) */

undefined8 _sun4m_l15_async_fault(uint param_1,undefined4 param_2)

{
  word wVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
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
  if (_nofault != 0) {
    _pokefault = 1;
  }
  if ((param_1 & 0x78000000) == 0) {
    _printf(aLevel15ErrorWa);
    _prom_stopcpu(0);
  }
  if ((param_1 & 0x10000000) != 0) {
    _l15_ecc_async_flt();
  }
  if ((param_1 & 0x20000000) != 0) {
    _l15_mts_async_flt();
  }
  if ((param_1 & 0x40000000) != 0) {
    _simple_lock_try(&_module_error);
  }
  if (_module_error != 0) {
    _l15_mod_async_flt();
  }
  uVar6 = DAT_f013ec78._12_4_;
  uVar5 = DAT_f013ec78._8_4_;
  uVar4 = DAT_f013ec78._4_4_;
  uVar3 = DAT_f013ec78._0_4_;
  uVar2 = dword_F013EC74;
  wVar1 = _sys_fatal_flt;
  if ((_nofault != 0) || (_system_fatal == 0)) goto locret_F00A6100;
  _printf(aFatalSystemFau,param_1);
  if (wVar1 == 2) {
    _log_ce_error = 1;
    _log_mem_err(uVar2,uVar3,uVar4,0);
    _printf(aControlRegiste);
    _printf(aEfsr0xXEfar00x,uVar2,uVar3);
    _printf(aEfar10xX,uVar4);
    _panic(aMemoryError);
loc_F00A6098:
    _printf(aAsyncFaultFrom_0);
    _printf(aAfsrXAfarX_0,uVar2,uVar3);
    _log_mtos_err(uVar2,uVar3);
  }
  else {
    if (2 < wVar1) {
      if (wVar1 != 4) goto loc_F00A60C8;
      goto loc_F00A6098;
    }
    if (wVar1 == 1) {
      _printf(aAsyncFaultFrom);
      _printf(aAfsrXAfarX,uVar2,uVar3);
      _mmu_log_module_err(uVar2,uVar3,uVar5,uVar6);
    }
    else {
loc_F00A60C8:
      _printf(aUnknownFaultTy,wVar1);
      _printf(aAfsrXAfarXX,uVar2,uVar3,uVar4);
    }
  }
  _panic(aFatalAsynchron);
  _system_fatal = 0;
locret_F00A6100:
  return CONCAT44(param_2,param_1);
}

