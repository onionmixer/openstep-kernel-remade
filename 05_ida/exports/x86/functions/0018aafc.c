/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18aafc. */
int i386_init()
{
  int result; // eax

  cnvmem = MEMORY[0x110B0]; /*0x18ab05*/
  extmem = MEMORY[0x110B4]; /*0x18ab11*/
  sub_18ABD0(); /*0x18ab17*/
  sub_18AC28(); /*0x18ab1c*/
  intr_initialize(); /*0x18ab21*/
  us_spin_calibrate(); /*0x18ab26*/
  page_size = 0x2000; /*0x18ab2b*/
  vm_set_page_size(); /*0x18ab35*/
  getargs((char *)0x11002); /*0x18ab3f*/
  sub_18ACF8(); /*0x18ab44*/
  num_regions = 1; /*0x18ab49*/
  dword_1F6E74 = (void *)dword_1E7604; /*0x18ab58*/
  dword_1F6E70 = dword_1E7604; /*0x18ab5d*/
  dword_1F6E78 = dword_1E7608; /*0x18ab68*/
  pmap_bootstrap(&mem_region, 1, &virtual_avail, &virtual_end); /*0x18ab7f*/
  locate_gdt((char *)gdt - 0x40000000); /*0x18ab8f*/
  locate_idt(idt - 0x10000000); /*0x18ab9f*/
  dbf_init(); /*0x18aba4*/
  result = dword_1F6E78 - (~page_mask & (page_mask + 4096)); /*0x18abbd*/
  dword_1F6E78 = result; /*0x18abbf*/
  pmsgbuf = result; /*0x18abc4*/
  return result; /*0x18abcb*/
}
