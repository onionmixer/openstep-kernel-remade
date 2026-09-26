
/* WARNING: Removing unreachable block (ram,0xf009b480) */

undefined8 _vik_module_setup(uint param_1,undefined4 param_2)

{
  code *pcVar1;
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
  _viking = 1;
  if ((param_1 & 0x800) == 0) {
    _mxcc = 1;
    _cache = 3;
    _mod_info = 0x41;
    _v_mmu_log_module_err = _mxcc_mmu_log_module_err;
    _v_vac_parity_chk_dis = _mxcc_vac_parity_chk_dis;
    pcVar1 = _vik_mxcc_pageflush;
  }
  else {
    _cache = 2;
    _mod_info = 0x40;
    _v_mmu_log_module_err = _vik_mmu_log_module_err;
    pcVar1 = _vik_pac_pageflush;
  }
  _v_vac_init = _vik_vac_init;
  _v_cache_on = _vik_cache_on;
  _v_mmu_getasyncflt = _vik_mmu_getasyncflt;
  _v_mmu_chk_wdreset = _vik_mmu_chk_wdreset;
  _v_mmu_print_sfsr = _vik_mmu_print_sfsr;
  _v_mmu_writepte = _vik_mmu_writepte;
  _v_module_wkaround = _vik_module_wkaround;
  if (_cache == 3) {
    _v_mmu_flushctx = _vik_mmu_flushctx;
    _v_mmu_flushrgn = _vik_mmu_flushrgn;
    _v_mmu_flushseg = _vik_mmu_flushseg;
    _v_mmu_flushpage = _vik_mmu_flushpage;
    _v_mmu_flushpagectx = _vik_mmu_flushpagectx;
    if (_use_page_coloring != 0) {
      _do_pg_coloring = 1;
    }
  }
  uVar2 = param_1;
  _v_pac_pageflush = pcVar1;
  _get_vik_rev_level();
  _vik_rev_level = uVar2;
  return CONCAT44(param_2,param_1);
}

