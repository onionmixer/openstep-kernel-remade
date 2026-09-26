
/* WARNING: Removing unreachable block (ram,0xf00a4880) */

undefined8 _init_mem_regions(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int iVar6;
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
  if (_phys_avail != 0) {
    uVar1 = *(undefined4 *)(_phys_avail + 4);
    iVar6 = _phys_avail;
    while( true ) {
      _insert_in_mem_regions(uVar1,*(undefined4 *)(iVar6 + 0xc));
      iVar6 = *(int *)(iVar6 + 0x10);
      if (iVar6 == 0) break;
      uVar1 = *(undefined4 *)(iVar6 + 4);
    }
  }
  if ((param_1 != 0) && (param_1 < _mem_size)) {
    uVar5 = _mem_size - param_1;
    puVar3 = &dword_F013CC14 + _num_regions * 7;
    _mem_size = param_1;
    if (uVar5 != 0) {
      piVar4 = (int *)(_num_regions * 0x1c + -0xfec33d4);
      do {
        if (puVar3 < _mem_region) break;
        uVar2 = *piVar4 - piVar4[-1];
        if (uVar5 < uVar2) {
          *piVar4 = *piVar4 - uVar5;
          uVar5 = 0;
        }
        else {
          uVar5 = uVar5 - uVar2;
          piVar4[-2] = 0;
          piVar4[-1] = 0;
          *piVar4 = 0;
          _num_regions = _num_regions + -1;
        }
        piVar4 = piVar4 + -7;
        puVar3 = puVar3 + -7;
      } while (uVar5 != 0);
    }
  }
  return CONCAT44(param_2,param_1);
}
