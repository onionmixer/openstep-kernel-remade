
/* WARNING: Removing unreachable block (ram,0xf009ab30) */

undefined8 _swift_module_setup(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
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
  iVar2 = 0;
  iVar3 = 0;
  uVar1 = param_1;
  _swift_getversion();
  dword_F0117568 = uVar1 >> 0x18;
  _swift = 0;
  _small_4m = 1;
  _no_vme = 0;
  _no_mix = 0;
  _hat_cachesync_bug = 0;
  _v_mmu_writeptp = _swift_mmu_writeptp;
  _v_mmu_print_sfsr = _swift_mmu_print_sfsr;
  _v_mmu_writepte = _swift_mmu_writepte;
  _v_mmu_chk_wdreset = _swift_mmu_chk_wdreset;
  _v_mmu_getasyncflt = _swift_mmu_getasyncflt;
  _v_vac_init = _swift_vac_init;
  _v_cache_on = _swift_cache_on;
  _v_cache_sync = _swift_vac_flushall;
  _v_vac_flushall = _swift_vac_flushall;
  _v_vac_usrflush = _swift_vac_usrflush;
  _v_vac_ctxflush = _swift_vac_ctxflush;
  _v_vac_rgnflush = _swift_vac_rgnflush;
  _v_vac_segflush = _swift_vac_segflush;
  _v_vac_pageflush = _swift_vac_pageflush;
  _v_vac_pagectxflush = _swift_vac_pagectxflush;
  _v_vac_flush = _swift_vac_flush;
  _cache = _cache | 1;
  if (dword_F0117568 != 0x11) {
    if (dword_F0117568 < 0x12) {
      if (dword_F0117568 != 0) goto loc_F009ACD8;
      _v_mmu_flushseg = _srmmu_mmu_flushall;
      _v_mmu_flushrgn = _srmmu_mmu_flushall;
      _v_mmu_flushctx = _srmmu_mmu_flushall;
    }
    else if (dword_F0117568 != 0x20) goto loc_F009ACD8;
  }
  iVar2 = 1;
  iVar3 = 1;
loc_F009ACD8:
  if (_swift_kdnc == -1) {
    _swift_kdnc = iVar2;
  }
  if (_swift_kdnx == -1) {
    _swift_kdnx = iVar3;
  }
  return CONCAT44(param_2,param_1);
}

