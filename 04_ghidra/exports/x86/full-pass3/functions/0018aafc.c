/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018aafc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _i386_init(void)

{
  _cnvmem = _DAT_000110b0;
  _extmem = _DAT_000110b4;
  FUN_0018abd0();
  FUN_0018ac28();
  _intr_initialize();
  _us_spin_calibrate();
  _page_size = 0x2000;
  _vm_set_page_size();
  _getargs(0x11002);
  FUN_0018acf8();
  _num_regions = 1;
  DAT_001f6e74 = DAT_001e7604;
  _DAT_001f6e70 = DAT_001e7604;
  DAT_001f6e78 = DAT_001e7608;
  _pmap_bootstrap(&_mem_region,1,&_virtual_avail,&_virtual_end);
  _locate_gdt(_gdt + -0x40000000);
  _locate_idt(_idt + -0x40000000);
  _dbf_init();
  DAT_001f6e78 = DAT_001f6e78 - (_page_mask + 0x1000 & ~_page_mask);
  _pmsgbuf = DAT_001f6e78;
  return;
}

