
/* WARNING: Removing unreachable block (ram,0xf00a4dcc) */
/* WARNING: Removing unreachable block (ram,0xf00a4db0) */
/* WARNING: Removing unreachable block (ram,0xf00a4cd4) */
/* WARNING: Removing unreachable block (ram,0xf00a4c7c) */
/* WARNING: Removing unreachable block (ram,0xf00a4ca0) */
/* WARNING: Removing unreachable block (ram,0xf00a4d30) */
/* WARNING: Removing unreachable block (ram,0xf00a4dc4) */
/* WARNING: Removing unreachable block (ram,0xf00a4dd4) */
/* WARNING: Removing unreachable block (ram,0xf00a4c14) */

undefined8 _copy_page_tables(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 uVar7;
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
  uVar6 = 0xf0000;
  uVar4 = 0xf0000000;
  do {
    uVar1 = uVar4;
    _mmu_probe(uVar4,0);
    if ((uVar1 != 0) && ((uVar1 & 3) == 2)) {
      uVar7 = 7;
      uVar5 = uVar1 >> 7 & 1;
      if ((0xefffffff < uVar4) && (uVar4 <= _etext)) {
        uVar7 = 5;
      }
      if ((0xefffffff < uVar4) && (uVar4 <= _econtig)) {
        uVar5 = uVar4;
        _is_cacheable();
      }
      _pmap_map(uVar4,(uVar1 >> 8) << 0xc,uVar1 >> 0x1c,0x1000,uVar7,uVar5);
      if (((_viking != 0) && ((uVar1 & 0x80) != 0)) && (uVar5 == 0)) {
        _pac_pageflush(uVar1 >> 8);
      }
    }
    uVar6 = uVar6 + 1;
    uVar4 = uVar6 * 0x1000;
  } while (uVar6 < 0xfffff);
  uVar4 = 0xf0000;
  iVar2 = -0x10000000;
  do {
    *(int *)((int)register0x00000038 + -0xc) = iVar2;
    if (*(int *)(_kernel_region + (uint)*(byte *)((int)register0x00000038 + -0xc) * 4) == 0) {
      _pmap_expand(_kernel_pmap,iVar2,2);
    }
    uVar4 = uVar4 + 0x1000;
    iVar2 = uVar4 * 0x1000;
  } while (uVar4 < 0x100000);
  uVar6 = 0;
  uVar4 = _Nl1ptbl_addr >> 6;
  puVar3 = _contexts;
  if (_nctxs != 0) {
    do {
      *puVar3 = uVar4 << 2 | 1;
      uVar6 = uVar6 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar6 < _nctxs);
  }
  if (_vac != 0) {
    _vac_flush(_contexts,_econtig - (int)_contexts);
  }
  _mmu_setctp((_pcontexts >> 6) << 2);
  _mmu_flushall();
  _vac_flushall();
  return CONCAT44(param_2,param_1);
}
