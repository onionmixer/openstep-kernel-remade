
/* WARNING: Removing unreachable block (ram,0xf00a4474) */
/* WARNING: Removing unreachable block (ram,0xf00a4430) */
/* WARNING: Removing unreachable block (ram,0xf00a440c) */
/* WARNING: Removing unreachable block (ram,0xf00a43d0) */
/* WARNING: Removing unreachable block (ram,0xf00a4334) */
/* WARNING: Removing unreachable block (ram,0xf00a4300) */
/* WARNING: Removing unreachable block (ram,0xf00a42c4) */
/* WARNING: Removing unreachable block (ram,0xf00a424c) */
/* WARNING: Removing unreachable block (ram,0xf00a4214) */
/* WARNING: Removing unreachable block (ram,0xf00a41c0) */
/* WARNING: Removing unreachable block (ram,0xf00a416c) */
/* WARNING: Removing unreachable block (ram,0xf00a4130) */
/* WARNING: Removing unreachable block (ram,0xf00a40d4) */
/* WARNING: Removing unreachable block (ram,0xf00a409c) */
/* WARNING: Removing unreachable block (ram,0xf00a4078) */
/* WARNING: Removing unreachable block (ram,0xf00a3fe8) */
/* WARNING: Removing unreachable block (ram,0xf00a3fc4) */
/* WARNING: Removing unreachable block (ram,0xf00a3f2c) */
/* WARNING: Removing unreachable block (ram,0xf00a3ef4) */
/* WARNING: Removing unreachable block (ram,0xf00a3e74) */
/* WARNING: Removing unreachable block (ram,0xf00a3e50) */
/* WARNING: Removing unreachable block (ram,0xf00a3e58) */
/* WARNING: Removing unreachable block (ram,0xf00a3eec) */
/* WARNING: Removing unreachable block (ram,0xf00a3f10) */
/* WARNING: Removing unreachable block (ram,0xf00a3f58) */
/* WARNING: Removing unreachable block (ram,0xf00a3fcc) */
/* WARNING: Removing unreachable block (ram,0xf00a4008) */
/* WARNING: Removing unreachable block (ram,0xf00a4080) */
/* WARNING: Removing unreachable block (ram,0xf00a40b4) */
/* WARNING: Removing unreachable block (ram,0xf00a4128) */
/* WARNING: Removing unreachable block (ram,0xf00a414c) */
/* WARNING: Removing unreachable block (ram,0xf00a419c) */
/* WARNING: Removing unreachable block (ram,0xf00a420c) */
/* WARNING: Removing unreachable block (ram,0xf00a4230) */
/* WARNING: Removing unreachable block (ram,0xf00a42bc) */
/* WARNING: Removing unreachable block (ram,0xf00a42e0) */
/* WARNING: Removing unreachable block (ram,0xf00a432c) */
/* WARNING: Removing unreachable block (ram,0xf00a4364) */
/* WARNING: Removing unreachable block (ram,0xf00a43f4) */
/* WARNING: Removing unreachable block (ram,0xf00a4414) */
/* WARNING: Removing unreachable block (ram,0xf00a4444) */
/* WARNING: Removing unreachable block (ram,0xf00a44a8) */
/* WARNING: Removing unreachable block (ram,0xf00a3e44) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _srmmu_init(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l3;
  uint uVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar7;
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
  _mmu_getsyncflt();
  _mmu_getasyncflt(_afsrbuf);
  _init_mem_installed();
  _econtig = _end + 0xfffU & 0xfffff000;
  _fill_pmapinfo();
  if ((_viking == 0) || (uVar4 = _nctxs << 2, uVar4 < 0x4000)) {
    uVar4 = 0x4000;
  }
  uVar3 = __bootops;
  (**(code **)(__bootops + 0x1c))(__bootops,_econtig,_nctxs << 2,uVar4);
  _contexts = uVar3;
  if (uVar3 != _econtig) {
    _panic(aCannotAllocate);
  }
  uVar3 = _contexts;
  _va_to_pa();
  _pcontexts = uVar3;
  if (uVar3 == 0xffffffff) {
    _panic(aInvalidPhysica);
  }
  if ((_pcontexts & uVar4 - 1) != 0) {
    _panic(aPhysicalAddres_0);
  }
  uVar3 = _econtig + (_nctxs + 0x3ffU >> 10) * 0x1000;
  uVar4 = _mem_size;
  _econtig = uVar3;
  udiv(_mem_size,200);
  if (0x400000 < uVar4) {
    uVar4 = 0x400000;
  }
  uVar7 = uVar4 + _page_mask & ~_page_mask;
  iVar5 = (uVar7 >> 8) * 0x100;
  uVar4 = __bootops;
  (**(code **)(__bootops + 0x1c))(__bootops,uVar3,iVar5,_page_size);
  _kernel_seg_tables = uVar4;
  if (uVar4 != _econtig) {
    _panic(aCannotAllocate_0);
  }
  uVar4 = _kernel_seg_tables;
  _va_to_pa();
  _kernel_seg_tables_phys = uVar4;
  if (uVar4 == 0xffffffff) {
    _panic(aInvalidPhysica_0);
  }
  if ((_kernel_seg_tables_phys & _page_size - 1U) != 0) {
    _panic(aPhysicalAddres_1);
  }
  _econtig = _econtig + ((uVar7 >> 8) + 0xf >> 4) * 0x1000;
  _kernel_seg_end = _kernel_seg_tables_phys + iVar5;
  _kernel_seg_tables_end = _kernel_seg_tables + iVar5;
  uVar4 = __bootops;
  (**(code **)(__bootops + 0x1c))(__bootops,_econtig,0x2000,0x1000);
  _kernel_region = uVar4;
  if (uVar4 != _econtig) {
    _panic(aCannotAllocate_1);
  }
  uVar4 = _kernel_region;
  _va_to_pa();
  _Nl1ptbl_addr = uVar4;
  if (uVar4 == 0xffffffff) {
    _panic(aInvalidPhysica_1);
  }
  if ((_Nl1ptbl_addr & 0xfff) != 0) {
    _panic(aPhysicalAddres_2);
  }
  iVar5 = _page_size;
  uVar3 = _econtig + 0x2000;
  _econtig = uVar3;
  udiv(uVar7,_page_size);
  uVar6 = (uVar7 * 0x20 + _page_mask & ~_page_mask) >> 5;
  uVar4 = __bootops;
  (**(code **)(__bootops + 0x1c))(__bootops,uVar3,uVar6 << 5,iVar5);
  _kernel_seg_pools = uVar4;
  if (uVar4 != _econtig) {
    _panic(aCannotAllocate_2);
  }
  uVar4 = _kernel_seg_pools;
  _va_to_pa();
  if (uVar4 == 0xffffffff) {
    _panic(aInvalidPhysica_2);
  }
  if ((uVar4 & _page_size - 1U) != 0) {
    _panic(aPhysicalAddres_3);
  }
  uVar6 = _econtig + (uVar6 + 0x7f >> 7) * 0x1000;
  uVar4 = uVar7;
  _econtig = uVar6;
  DAT_f013de80._0_4_ = uVar7;
  umul(uVar7,word_F013DE74);
  uVar3 = uVar4 * 0x28 + _page_mask & ~_page_mask;
  udiv(uVar3,0x28);
  iVar5 = uVar3 * 0x28;
  uVar3 = __bootops;
  (**(code **)(__bootops + 0x1c))(__bootops,uVar6,iVar5,_page_size);
  _kernel_seg_entries = uVar3;
  if (uVar3 != _econtig) {
    _panic(aCannotAllocate_3);
  }
  uVar3 = _kernel_seg_entries;
  _va_to_pa();
  if (uVar3 == 0xffffffff) {
    _panic(aInvalidPhysica_3);
  }
  if ((uVar3 & _page_size - 1U) != 0) {
    _panic(aPhysicalAddres_4);
  }
  _econtig = _econtig + (iVar5 + 0xfffU & 0xfffff000);
  _kernel_seg_entries_end = _kernel_seg_entries + iVar5;
  uVar3 = __bootops;
  DAT_f013de7c._0_4_ = uVar4;
  (**(code **)(__bootops + 0x1c))(__bootops,_econtig,_nctxs * 0xc,_page_size);
  _context_table = uVar3;
  if (uVar3 != _econtig) {
    _panic(aCannotAllocate_4);
  }
  uVar4 = _context_table;
  _va_to_pa();
  if (uVar4 == 0xffffffff) {
    _panic(aInvalidPhysica_4);
  }
  if ((uVar4 & _page_size - 1U) != 0) {
    _panic(aPhysicalAddres_5);
  }
  _econtig = _econtig + (_nctxs * 0xc + 0xfffU & 0xfffff000);
  _init_kernel_page_tables(uVar7);
  _init_context_table();
  if ((_viking != 0) && (_mxcc == 0)) {
    _bpt_reg(0,0x1000);
  }
  uVar4 = __bootops;
  (**(code **)(__bootops + 0x30))(__bootops,aMemoryUpdate);
  if (uVar4 == 0) {
    (**(code **)(__bootops + 0x34))(__bootops,aMemoryUpdate_0,0);
  }
  _phys_avail = _cur_memlist;
  _copy_memlist(*(undefined4 *)(*(int *)(__bootops + 8) + 4),&_cur_memlist,_old_memlist);
  _virt_avail = _cur_memlist;
  _copy_memlist(*(undefined4 *)(*(int *)(__bootops + 8) + 8),&_cur_memlist,_old_memlist);
  (**(code **)(__bootops + 0x2c))();
  _init_mem_regions(param_1);
  _copy_page_tables();
  uVar1 = 0x2000;
  if (_iom != 0) {
    _get_from_mem_regions(0x2000,4);
    uVar2 = 0x4000;
    _first_page = uVar1;
    _get_from_mem_regions(0x4000,0x4000);
    _ioptes = _econtig;
    _phys_iopte = uVar2;
    _pmap_map(_econtig,uVar2,0,0x4000,7,0);
    _econtig = _ioptes + 0x4000;
    _eioptes = _econtig;
    if (_viking != 0) {
      _pac_flush(_ioptes,_econtig - _ioptes);
    }
  }
  return CONCAT44(DAT_f0134000,uVar7);
}

