
/* WARNING: Removing unreachable block (ram,0xf00aaef4) */
/* WARNING: Removing unreachable block (ram,0xf00aaec0) */
/* WARNING: Removing unreachable block (ram,0xf00aae8c) */
/* WARNING: Removing unreachable block (ram,0xf00aae40) */
/* WARNING: Removing unreachable block (ram,0xf00aad94) */
/* WARNING: Removing unreachable block (ram,0xf00aace8) */
/* WARNING: Removing unreachable block (ram,0xf00aac8c) */
/* WARNING: Removing unreachable block (ram,0xf00aac4c) */
/* WARNING: Removing unreachable block (ram,0xf00aac08) */
/* WARNING: Removing unreachable block (ram,0xf00aabd8) */
/* WARNING: Removing unreachable block (ram,0xf00aab84) */
/* WARNING: Removing unreachable block (ram,0xf00aab44) */
/* WARNING: Removing unreachable block (ram,0xf00aab2c) */
/* WARNING: Removing unreachable block (ram,0xf00aab34) */
/* WARNING: Removing unreachable block (ram,0xf00aab50) */
/* WARNING: Removing unreachable block (ram,0xf00aabb0) */
/* WARNING: Removing unreachable block (ram,0xf00aabf4) */
/* WARNING: Removing unreachable block (ram,0xf00aac3c) */
/* WARNING: Removing unreachable block (ram,0xf00aac78) */
/* WARNING: Removing unreachable block (ram,0xf00aaca8) */
/* WARNING: Removing unreachable block (ram,0xf00aad08) */
/* WARNING: Removing unreachable block (ram,0xf00aadd8) */
/* WARNING: Removing unreachable block (ram,0xf00aae84) */
/* WARNING: Removing unreachable block (ram,0xf00aae94) */
/* WARNING: Removing unreachable block (ram,0xf00aaeec) */
/* WARNING: Removing unreachable block (ram,0xf00aaefc) */
/* WARNING: Removing unreachable block (ram,0xf00aab10) */

undefined8 _startup(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  undefined *puVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar12;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  _cons_tp = _cons;
  DAT_f01351c8._0_2_ = 0xc00;
  _kminit();
  _kmpopup(_mach_title,0,0,0,0);
  _startup_early();
  *(undefined4 *)((int)register0x00000038 + 0x44) = _virtual_avail;
  _panic_init();
  _printf(_version);
  uVar9 = _mem_size >> 0x14;
  uVar7 = _mem_size & 0xfffff;
  uVar1 = _mem_size;
  urem(_mem_size,0x19999);
  _printf(aPhysicalMemory,uVar9,uVar7 * 10 >> 0x14,(uVar1 * 0x19 & 0x3fffffff) >> 0x12);
  uVar3 = _kernel_map;
  uVar2 = 0;
  *(uint *)((int)register0x00000038 + 0x44) =
       *(int *)((int)register0x00000038 + 0x44) + _page_mask & ~_page_mask;
  _vm_object_allocate(0);
  _vm_map_find(uVar3,uVar2,0,(undefined *)((int)register0x00000038 + 0x44),0x800000,1);
  _vm_map_remove(_kernel_map,*(int *)((int)register0x00000038 + 0x44),
                 *(int *)((int)register0x00000038 + 0x44) + 0x800000);
  uVar1 = _bufpages;
  iVar4 = _nbuf;
  iVar10 = *(int *)((int)register0x00000038 + 0x44);
  iVar5 = _nbuf * 0x2000;
  uVar7 = _bufpages;
  _buffers = iVar10;
  div(_bufpages,_nbuf);
  rem(uVar1,iVar4);
  puVar11 = (undefined *)(iVar10 + iVar5 + _page_mask & ~_page_mask);
  iVar10 = (int)puVar11 - iVar10;
  uVar3 = _kernel_map;
  _kmem_suballoc(_kernel_map,(undefined *)((int)register0x00000038 + 0x44),
                 (undefined *)((int)register0x00000038 + -0xc),iVar10,1);
  iVar4 = iVar10;
  _buffer_map = uVar3;
  _vm_object_allocate(iVar10);
  _vm_map_find(uVar3,iVar4,0,(undefined *)((int)register0x00000038 + 0x44),iVar10,0);
  uVar9 = 0;
  if (_nbuf != 0) {
    puVar11 = DAT_f013ec00;
    bVar12 = uVar1 != 0;
    do {
      uVar6 = uVar7;
      if (bVar12) {
        uVar6 = uVar7 + 1;
      }
      iVar4 = _page_size;
      umul(_page_size,uVar6);
      iVar5 = _buffers + uVar9 * 0x2000;
      _vm_map_pageable(_buffer_map,iVar5,iVar5 + iVar4,0);
      uVar9 = uVar9 + 1;
      bVar12 = true;
    } while (uVar9 < uVar1);
  }
  iVar4 = _nbuf;
  iVar10 = _bufpages << ((byte)_page_shift & 0x1f);
  iVar5 = iVar10;
  if (iVar10 < 0) {
    iVar5 = iVar10 + 0xfffff;
  }
  iVar8 = (iVar10 + (iVar5 >> 0x14) * -0x100000) * 10;
  if (iVar8 < 0) {
    iVar8 = iVar8 + 0xfffff;
  }
  rem(iVar10,0x19999);
  iVar10 = iVar10 * 100;
  if (iVar10 < 0) {
    iVar10 = iVar10 + 0xfffff;
  }
  _printf(aUsingDBuffersC,iVar4,iVar5 >> 0x14,iVar8 >> 0x14,iVar10 >> 0x14);
  iVar4 = _vm_page_free_count;
  iVar10 = _vm_page_free_count << ((byte)_page_shift & 0x1f);
  iVar5 = iVar10;
  if (iVar10 < 0) {
    iVar5 = iVar10 + 0xfffff;
  }
  iVar8 = (iVar10 + (iVar5 >> 0x14) * -0x100000) * 10;
  if (iVar8 < 0) {
    iVar8 = iVar8 + 0xfffff;
  }
  rem(iVar10,0x19999);
  iVar10 = iVar10 * 100;
  if (iVar10 < 0) {
    iVar10 = iVar10 + 0xfffff;
  }
  _printf(aAvailableMemor,iVar5 >> 0x14,iVar8 >> 0x14,iVar10 >> 0x14,iVar4);
  _callout_init();
  _clock_timer_init();
  uVar3 = _kernel_map;
  _kmem_suballoc(_kernel_map,&_mbutl,_embutl,_nmbclusters << 10,0);
  _debug_init_done = 1;
  _mb_map = uVar3;
  if (_iom != 0) {
    _iom_init();
  }
  _configure();
  _spl0();
  return CONCAT44(param_2,puVar11);
}

