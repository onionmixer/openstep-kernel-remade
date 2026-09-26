
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_set_page_size(void)

{
  byte bVar1;
  int iVar2;
  
  _m68k_page_mask = _m68k_page_size + -1;
  _m68k_page_shift = 0;
  iVar2 = 1;
  if (_m68k_page_size != 1) {
    do {
      _m68k_page_shift = _m68k_page_shift + 1;
      iVar2 = iVar2 * 2;
    } while (_m68k_page_size != iVar2);
  }
  _m68k_tic = 5;
  if (_m68k_page_size == 0x1000) {
    _m68k_tic = 6;
  }
  _m68k_pte_elemsize = 4;
  _m68k_pte_entries = 1 << _m68k_tic;
  _m68k_pte_size = _m68k_pte_entries << 2;
  _m68k_pte_shift = _m68k_page_shift;
  _m68k_pte_mask = _m68k_pte_entries + -1 << (_m68k_page_shift & 0x3f);
  _m68k_pte_maps = _m68k_pte_entries << (_m68k_page_shift & 0x3f);
  _m68k_pte_pfn = 0xc;
  if (_cpu_type == '\0') {
    _m68k_pte_pfn = 8;
  }
  _m68k_tib = 7;
  _m68k_pt2_entries = 0x80;
  _m68k_pt2_size = 0x200;
  _m68k_pt2_shift = _m68k_tic + _m68k_page_shift;
  _m68k_pt2_mask = 0x7f << (_m68k_pt2_shift & 0x3f);
  _m68k_pt2_maps = 0x80 << (_m68k_pt2_shift & 0x3f);
  _m68k_pt2_desctype = 2;
  _m68k_pt2_l3ptr = 7;
  _m68k_tia = 7;
  _m68k_pt1_elemsize = 4;
  _m68k_pt1_entries = 0x80;
  _m68k_pt1_size = 0x200;
  _m68k_pt1_shift = _m68k_pt2_shift + 7;
  _m68k_pt1_mask = 0x7f << (_m68k_pt2_shift + 7 & 0x3f);
  _m68k_pt1_desctype = 2;
  _m68k_pt1_l2ptr = 9;
  _m68k_cache = 3;
  if (_cache != 0) {
    _m68k_cache = 1;
  }
  _m68k_cache_inhibit_serial = 2;
  _m68k_cache_inhibit_nonserial = 3;
  bVar1 = bRam040b57ba | 0x80;
  if (_m68k_page_size == 0x2000) {
    bVar1 = bRam040b57ba | 0xc0;
  }
  bRam040b57ba = bVar1;
  if (_cpu_type == '\0') {
    _m68k_cache = -(int)-(_cache == 0);
    _m68k_cache_inhibit_serial = 1;
    _m68k_cache_inhibit_nonserial = 1;
    _m68k_kernel_mmu_030_tc._0_1_ = _m68k_kernel_mmu_030_tc._0_1_ | 0x82;
    _m68k_kernel_mmu_030_tc._1_1_ = (char)_m68k_page_shift << 4;
    _m68k_kernel_mmu_030_tc._2_1_ = 0x77;
    ram0x040b57b3 = ram0x040b57b3 & 0xfffffff | _m68k_tic << 0x1c;
  }
  return;
}

