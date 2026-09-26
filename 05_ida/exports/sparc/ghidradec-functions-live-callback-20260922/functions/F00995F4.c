
/* WARNING: Removing unreachable block (ram,0xf009974c) */
/* WARNING: Removing unreachable block (ram,0xf009973c) */
/* WARNING: Removing unreachable block (ram,0xf00996fc) */
/* WARNING: Removing unreachable block (ram,0xf00996c4) */
/* WARNING: Removing unreachable block (ram,0xf0099698) */
/* WARNING: Removing unreachable block (ram,0xf009967c) */
/* WARNING: Removing unreachable block (ram,0xf0099660) */
/* WARNING: Removing unreachable block (ram,0xf0099648) */
/* WARNING: Removing unreachable block (ram,0xf0099640) */
/* WARNING: Removing unreachable block (ram,0xf0099658) */
/* WARNING: Removing unreachable block (ram,0xf0099670) */
/* WARNING: Removing unreachable block (ram,0xf009968c) */
/* WARNING: Removing unreachable block (ram,0xf00996a8) */
/* WARNING: Removing unreachable block (ram,0xf00996e0) */
/* WARNING: Removing unreachable block (ram,0xf009971c) */
/* WARNING: Removing unreachable block (ram,0xf0099744) */
/* WARNING: Removing unreachable block (ram,0xf0099764) */
/* WARNING: Removing unreachable block (ram,0xf0099610) */

undefined8 _iom_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar2;
  undefined4 unaff_l7;
  int iVar3;
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
  uVar2 = 0;
  iVar3 = -0x100000;
  _bzero(_ioptes,0x4000);
  _pmap_enter_dev(_kernel_pmap,0xfff00000,_first_page,0,3,0,1);
  uVar1 = 0x200;
  _kalloc();
  _iopbmap = uVar1;
  _bzero();
  uVar1 = 0x7f0;
  _kalloc();
  _sbusmap = uVar1;
  _bzero();
  uVar1 = 0x3000;
  _kalloc();
  _bigsbusmap = uVar1;
  _bzero();
  uVar1 = 0x1000;
  _kalloc();
  _mbutlmap = uVar1;
  _bzero();
  _rminit(_iopbmap,0x2000,0xfff00000,aIopbSpace,0x40);
  _rminit(_sbusmap,0xfe,2,aSbusMapSpace,0x54);
  _rminit(_bigsbusmap,0x600,0xff000,aBigsbusMapSpac,0x200);
  _rminit(_mbutlmap,0x200,0xff600,aMbutlMapSpace,0xaa);
  _dvmamap = _sbusmap;
  _iommu_set_base((_phys_iopte >> 0xe) << 10);
  _iommu_set_ctl(1);
  _iommu_flush_all();
  do {
    _iom_dvma_pteload((_first_page >> 0xc) + uVar2,iVar3,1);
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + 0x1000;
  } while (uVar2 < 2);
  return CONCAT44(param_2,DAT_f013d800);
}

