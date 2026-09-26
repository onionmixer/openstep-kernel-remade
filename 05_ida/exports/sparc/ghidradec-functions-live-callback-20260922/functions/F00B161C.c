
/* WARNING: Removing unreachable block (ram,0xf00b168c) */
/* WARNING: Removing unreachable block (ram,0xf00b1668) */
/* WARNING: Removing unreachable block (ram,0xf00b1644) */
/* WARNING: Removing unreachable block (ram,0xf00b1650) */
/* WARNING: Removing unreachable block (ram,0xf00b167c) */
/* WARNING: Removing unreachable block (ram,0xf00b16dc) */
/* WARNING: Removing unreachable block (ram,0xf00b1630) */

undefined8 _map_regs(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  uint uVar3;
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
  uVar1 = param_1;
  if (param_3 != -1) {
    uVar3 = param_1;
    _splusclock();
    uVar1 = param_2 + (param_1 & 0xfff);
    _map_alloc(uVar1,0);
    _splx(uVar3);
    if (uVar1 == 0) {
      _panic(aOutOfKernelMap);
    }
    iVar2 = _page_size;
    uVar3 = param_2;
    udiv(param_2,_page_size);
    urem(param_2,iVar2);
    uVar1 = uVar1 | param_1 & 0xfff;
    if (param_2 != 0) {
      uVar3 = uVar3 + 1;
    }
    iVar2 = 0;
    param_2 = uVar1;
    if (0 < (int)uVar3) {
      do {
        iVar2 = iVar2 + 1;
        _pmap_enter_dev(_kernel_pmap,param_2 & 0xfffff000,param_1,param_3,3,0,1);
        param_2 = param_2 + _page_size;
        param_1 = param_1 + _page_size;
      } while (iVar2 < (int)uVar3);
    }
  }
  return CONCAT44(param_2,uVar1);
}

