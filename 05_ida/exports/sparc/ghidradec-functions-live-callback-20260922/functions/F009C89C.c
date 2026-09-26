
/* WARNING: Removing unreachable block (ram,0xf009c928) */
/* WARNING: Removing unreachable block (ram,0xf009c8f0) */
/* WARNING: Removing unreachable block (ram,0xf009c8d4) */
/* WARNING: Removing unreachable block (ram,0xf009c914) */
/* WARNING: Removing unreachable block (ram,0xf009c938) */
/* WARNING: Removing unreachable block (ram,0xf009c8b0) */

undefined8 _pmap_destroy(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  dword_F013DEB0 = dword_F013DEB0 + 1;
  _pmap_print_info();
  if ((param_1 != 0) && (param_1 != _kernel_pmap)) {
    iVar1 = _kernel_pmap;
    _splvm();
    do {
      do {
      } while (*(int *)(param_1 + 0x18) != 0);
      piVar2 = (int *)(param_1 + 0x18);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x18) = 0;
    iVar3 = *(int *)(param_1 + 0x1c) + -1;
    *(int *)(param_1 + 0x1c) = iVar3;
    _splx(iVar1);
    if (iVar3 == 0) {
      _pmap_dealloc_reg_entry(param_1);
      _zfree(_pmap_zone,param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}

