
/* WARNING: Removing unreachable block (ram,0xf009ad98) */
/* WARNING: Removing unreachable block (ram,0xf009ada8) */
/* WARNING: Removing unreachable block (ram,0xf009ad78) */

undefined8
_swift_mmu_writepte(uint param_1,uint *param_2,uint param_3,undefined4 param_4,int param_5)

{
  undefined4 unaff_l0;
  uint uVar1;
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
  if ((_swift_kdnc == 1) && (_etext < param_3)) {
    param_1 = param_1 & 0xffffff7f;
  }
  uVar1 = *param_2;
  if (uVar1 != param_1) {
    if ((((_swift_kdnx == 1) && ((param_1 & 3) == 2)) && ((param_1 & 0xf000000) != 0)) &&
       ((param_1 & 0x1c) == 0x1c)) {
      param_1 = param_1 & 0xffffffe3 | 0x14;
    }
    _swapl(param_1);
    if (((uVar1 & 3) != 0) && (param_5 != -1)) {
      _srmmu_tlbflush(param_4,param_3,param_5);
      _srmmu_vacflush(param_4,param_3,param_5);
    }
  }
  return CONCAT44(param_2,param_1);
}

