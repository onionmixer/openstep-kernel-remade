
/* WARNING: Removing unreachable block (ram,0xf00680d8) */
/* WARNING: Removing unreachable block (ram,0xf00680f0) */

undefined8 _kalloc(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
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
  iVar3 = 0;
  uVar4 = param_1;
  if ((param_1 <= _k_zone_maxsize) && (uVar4 = _k_zone_elemsize, _k_zone_elemsize < param_1)) {
    iVar1 = 0;
    do {
      uVar4 = *(uint *)(DAT_f010faac + iVar1);
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 4;
    } while (uVar4 < param_1);
  }
  if (_k_zone_maxsize < uVar4) {
    iVar3 = _kalloc_map;
    _kmem_alloc_wired(_kalloc_map,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar3 != 0) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    }
  }
  else {
    uVar2 = *(undefined4 *)(_k_zone + iVar3 * 4);
    _zalloc();
    *(undefined4 *)((int)register0x00000038 + -0xc) = uVar2;
  }
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
}

