
/* WARNING: Removing unreachable block (ram,0xf00a3710) */
/* WARNING: Removing unreachable block (ram,0xf00a3700) */
/* WARNING: Removing unreachable block (ram,0xf00a3664) */
/* WARNING: Removing unreachable block (ram,0xf00a3598) */
/* WARNING: Removing unreachable block (ram,0xf00a3588) */
/* WARNING: Removing unreachable block (ram,0xf00a362c) */
/* WARNING: Removing unreachable block (ram,0xf00a35e0) */
/* WARNING: Removing unreachable block (ram,0xf00a3534) */
/* WARNING: Removing unreachable block (ram,0xf00a350c) */
/* WARNING: Removing unreachable block (ram,0xf00a34bc) */
/* WARNING: Removing unreachable block (ram,0xf00a33d8) */
/* WARNING: Removing unreachable block (ram,0xf00a33b8) */
/* WARNING: Removing unreachable block (ram,0xf00a33a8) */
/* WARNING: Removing unreachable block (ram,0xf00a3398) */
/* WARNING: Removing unreachable block (ram,0xf00a3368) */
/* WARNING: Removing unreachable block (ram,0xf00a3360) */
/* WARNING: Removing unreachable block (ram,0xf00a3384) */
/* WARNING: Removing unreachable block (ram,0xf00a33a0) */
/* WARNING: Removing unreachable block (ram,0xf00a33b0) */
/* WARNING: Removing unreachable block (ram,0xf00a33c0) */
/* WARNING: Removing unreachable block (ram,0xf00a34a8) */
/* WARNING: Removing unreachable block (ram,0xf00a3504) */
/* WARNING: Removing unreachable block (ram,0xf00a3514) */
/* WARNING: Removing unreachable block (ram,0xf00a3550) */
/* WARNING: Removing unreachable block (ram,0xf00a35e8) */
/* WARNING: Removing unreachable block (ram,0xf00a3618) */
/* WARNING: Removing unreachable block (ram,0xf00a3590) */
/* WARNING: Removing unreachable block (ram,0xf00a35bc) */
/* WARNING: Removing unreachable block (ram,0xf00a36dc) */
/* WARNING: Removing unreachable block (ram,0xf00a3708) */
/* WARNING: Removing unreachable block (ram,0xf00a3728) */
/* WARNING: Removing unreachable block (ram,0xf00a333c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _sparc_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
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
  bool bVar8;
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
  sub_F00A379C();
  iVar2 = *(int *)(__bootops + 0x3c);
  if (iVar2 != 0) {
    _bcopy(iVar2,&_static_KERNBOOTSTRUCT,0xd128);
  }
  _getlastaddr();
  iVar2 = iVar2 + *(int *)(__bootops + 0x40);
  _end = iVar2;
  sub_F00A377C();
  _etext = iVar2;
  _prom_init(aNextstep_0);
  _map_wellknown_devices();
  _fill_machinfo();
  _fill_hostidinfo();
  _setcputype();
  sub_F00A3740(_mach_info);
  _cpu = _mach_info;
  _setcpudelay();
  uVar4 = DAT_f0112a7c._20_4_;
  uVar1 = DAT_f0112a7c._16_4_;
  if (DAT_f0112a7c._0_4_ != 0) {
    if (DAT_f0112a7c._8_4_ == 0) {
      _cache = 1;
      _vac = 1;
    }
    else if (DAT_f0112a7c._76_4_ == 0) {
      _cache = 2;
    }
    else {
      _cache = 3;
    }
  }
  _iom = DAT_f0112a44._0_4_;
  _bcopy_buf = DAT_f0112a7c._44_4_;
  if ((_nctxs == 0) && (_nctxs = DAT_f0112a7c._32_4_, 0x1000 < (uint)DAT_f0112a7c._32_4_)) {
    _nctxs = 0x1000;
  }
  uVar3 = 0x1000;
  if (_vac != 0) {
    _vac_linesize = DAT_f0112a7c._16_4_;
    _vac_nlines = DAT_f0112a7c._20_4_;
    .div(0x1000,DAT_f0112a7c._16_4_);
    _vac_pglines = uVar3;
    .umul(uVar4,uVar1);
    _vac_size = uVar4;
  }
  if (_bcopy_buf != 0) {
    if (_use_bcopy == 0) {
      _bcopy_res = 0xffffffff;
    }
    else {
      _bcopy_res = 0;
    }
  }
  _init_mon_clock();
  _splzs();
  _bootflags();
  if (_page_size == 0) {
    _page_size = 0x2000;
  }
  _vm_set_page_size();
  if (dword_F013155C != 0) {
    dword_F013155C = dword_F013155C << 10;
  }
  _srmmu_init(dword_F013155C);
  dword_F013155C = _mem_size;
  if (_vac == 0) {
    if (_use_cache == 0) {
      _vac = 0;
      _cache = 0;
    }
    else {
      _vac_init();
      _setcpudelay();
      if (_no_mix == 0) {
        if (_use_mix == 0) {
          _bpt_reg(0,0x1000);
        }
        else {
          _bpt_reg(0x1000,0);
        }
      }
    }
  }
  else {
    if (_use_cache != 0) {
      _vac_mode = 0;
      _vac_init();
      _cache_on();
      _setcpudelay();
      _shm_alignment = _vac_size;
      goto loc_F00A3650;
    }
    _cache = 0;
    _vac = 0;
    _setcpudelay();
  }
  _shm_alignment = 0x1000;
loc_F00A3650:
  if (_debug_msg != 0) {
    _print_debug_msg();
  }
  iVar2 = _nmod;
  iVar6 = 0;
  if (0 < _nmod) {
    iVar5 = 0;
    do {
      *(undefined4 *)((int)&_a_head + iVar5) = 0x3f;
      *(undefined4 *)((int)&_a_tail + iVar5) = 0x3f;
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar6 < iVar2);
  }
  uVar7 = 1;
  if (dword_F0112A40 != 0) {
    do {
      bVar8 = uVar7 < dword_F0112A40;
      uVar7 = uVar7 + 1;
    } while (bVar8);
  }
  sub_F00A3804();
  _pmap_bootstrap(_mem_region,_num_regions,&_virtual_avail,&_virtual_end);
  _start_mon_clock();
  _memerr_init();
  uVar7 = _page_mask + 0x1000 & ~_page_mask;
  _vm_alloc_from_regions();
  _pmsgbuf = uVar7;
  return CONCAT44(param_2,param_1);
}
