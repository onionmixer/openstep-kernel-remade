
/* WARNING: Removing unreachable block (ram,0xf0068450) */
/* WARNING: Removing unreachable block (ram,0xf0068508) */
/* WARNING: Removing unreachable block (ram,0xf0068464) */
/* WARNING: Removing unreachable block (ram,0xf00684d8) */

undefined8 sub_F00683EC(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  bVar4 = true;
  iVar6 = 0;
  piVar5 = (int *)(param_1 & ~_page_mask);
  piVar3 = piVar5;
  if (0 < dword_F012F67C) {
    do {
      if (piVar3[2] != 0) {
        bVar4 = false;
      }
      iVar6 = iVar6 + 1;
      piVar3 = (int *)((int)piVar3 + dword_F012F678);
    } while (iVar6 < dword_F012F67C);
  }
  if (bVar4) {
    iVar6 = 0;
    if (0 < dword_F012F67C) {
      do {
        iVar2 = *piVar5;
        piVar3 = (int *)piVar5[1];
        *(int **)(iVar2 + 4) = piVar3;
        if (piVar3 != &dword_F012F670) {
          *piVar3 = iVar2;
          iVar2 = dword_F012F670;
        }
        dword_F012F670 = iVar2;
        dword_F010FB00 = dword_F010FB00 + -1;
        iRamf013c0c8 = iRamf013c0c8 + -1;
        _stack_finalize(piVar5 + 3);
        iVar6 = iVar6 + 1;
        piVar5 = (int *)((int)piVar5 + dword_F012F678);
      } while (iVar6 < dword_F012F67C);
    }
    _kmem_free(_kernel_map,param_1,dword_F012F678);
    _stackStats = _stackStats + -1;
  }
  else {
    uVar1 = param_1;
    _canSwap();
    if (uVar1 != 0) {
      _doSwapout(param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}

