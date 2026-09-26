
/* WARNING: Removing unreachable block (ram,0xf00865a8) */
/* WARNING: Removing unreachable block (ram,0xf00865ec) */
/* WARNING: Removing unreachable block (ram,0xf0086518) */

undefined8 _vm_alloc_from_regions(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined *puVar4;
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
  if (_pmap_initialized != 0) {
    _panic(aVmMemAllocFrom);
  }
  puVar4 = _mem_region;
  if (_mem_region < _mem_region + _num_regions * 0x1c) {
    puVar3 = (uint *)(_mem_region + 0x14);
    do {
      uVar1 = (*puVar3 - 1) + param_2 & -param_2;
      uVar2 = uVar1 + param_1;
      if (uVar2 <= puVar3[1]) {
        *puVar3 = uVar2;
        _econtig = _econtig + -1 + param_2 & -param_2;
        _pmap_map(_econtig,uVar1,0,param_1,3,1);
        _virtual_avail = _econtig + param_1;
        param_1 = _econtig;
        _econtig = _virtual_avail;
        goto locret_F00865F4;
      }
      puVar4 = puVar4 + 0x1c;
      puVar3 = puVar3 + 7;
    } while (puVar4 < _mem_region + _num_regions * 0x1c);
  }
  _panic(aVmMemAllocFrom_0);
locret_F00865F4:
  return CONCAT44(param_2,param_1);
}

