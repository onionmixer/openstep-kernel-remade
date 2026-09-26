
/* WARNING: Removing unreachable block (ram,0xf0083518) */
/* WARNING: Removing unreachable block (ram,0xf0083508) */
/* WARNING: Removing unreachable block (ram,0xf00834f4) */
/* WARNING: Removing unreachable block (ram,0xf00834dc) */
/* WARNING: Removing unreachable block (ram,0xf00834d4) */
/* WARNING: Removing unreachable block (ram,0xf00834e4) */
/* WARNING: Removing unreachable block (ram,0xf0083500) */
/* WARNING: Removing unreachable block (ram,0xf0083510) */
/* WARNING: Removing unreachable block (ram,0xf0083520) */
/* WARNING: Removing unreachable block (ram,0xf00834cc) */

undefined8 _vm_mem_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar1;
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
  puVar1 = _mem_region;
  _vm_page_startup(_mem_region,_num_regions,_virtual_avail);
  _virtual_avail = puVar1;
  _zone_bootstrap();
  _vm_object_init();
  _vm_map_init();
  _kmem_init(_virtual_avail,_virtual_end);
  _pmap_init(_mem_region,_num_regions);
  _zone_init();
  _kalloc_init();
  _vm_pager_init();
  _vm_user_init();
  return CONCAT44(param_2,param_1);
}
