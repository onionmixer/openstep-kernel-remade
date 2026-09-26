
/* WARNING: Removing unreachable block (ram,0xf009b264) */
/* WARNING: Removing unreachable block (ram,0xf009b234) */
/* WARNING: Removing unreachable block (ram,0xf009b2a4) */
/* WARNING: Removing unreachable block (ram,0xf009b100) */

undefined8 _vik_vac_init(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
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
  bVar1 = false;
  if (_cache != 3) {
    _vac_mode = aSupersparc;
    goto loc_F009B124;
  }
  if ((_use_cache != 0) && (_use_ec != 0)) {
    bVar1 = true;
    dword_F01176E8 = dword_F01176E8 | 4;
  }
  if (_use_mxcc_prefetch == 0) {
    dword_F01176EC = dword_F01176EC | 0x20;
  }
  else {
    dword_F01176E8 = dword_F01176E8 | 0x20;
  }
  if (_use_multiple_cmd == 0) {
loc_F009B0B8:
    dword_F01176EC = dword_F01176EC | 0x10;
  }
  else {
    if ((_nmod != 1) && (_use_multiple_cmd != 2)) {
      _use_multiple_cmd = 0;
      goto loc_F009B0B8;
    }
    dword_F01176E8 = dword_F01176E8 | 0x10;
  }
  if (_use_rdref_only == 0) {
    dword_F01176EC = dword_F01176EC | 0x200;
  }
  else {
    dword_F01176E8 = dword_F01176E8 | 0x200;
  }
  _vik_mxcc_init_asm(dword_F01176EC,dword_F01176E8);
  _vac_mode = aSupersparcSupe;
loc_F009B124:
  dword_F01176E8 = 0x4000;
  if (_use_cache != 0) {
    if (_use_ic != 0) {
      dword_F01176E8 = 0x4200;
    }
    if (_use_dc != 0) {
      dword_F01176E8 = dword_F01176E8 | 0x100;
    }
  }
  dword_F01176EC = 0x40000;
  if (((_use_table_walk == 0) || (_use_ec == 0)) || (_cache != 3)) {
    dword_F01176EC = 0x50000;
  }
  else {
    dword_F01176E8 = dword_F01176E8 | 0x10000;
  }
  if (_use_store_buffer == 0) {
    dword_F01176EC = dword_F01176EC | 0x400;
  }
  else {
    dword_F01176E8 = dword_F01176E8 | 0x400;
  }
  _vik_vac_init_asm(dword_F01176EC,dword_F01176E8);
  if ((_vik_rev_level - 1U < 2) && (_do_work_arounds = 1, !bVar1)) {
    _SMbuf_syncmode();
  }
  if (((_vik_rev_level == 3) && (_enable_sm_wa != 0)) || (_require_sm_wa != 0)) {
    _vik_1137125_wa();
  }
  return CONCAT44(param_2,param_1);
}
