
/* WARNING: Removing unreachable block (ram,0xf00a5518) */
/* WARNING: Removing unreachable block (ram,0xf00a5388) */

undefined8 _set_clk_mode(uint param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_l0;
  int iVar7;
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
  iVar7 = 4;
  if (_small_4m != 0) {
    iVar7 = 1;
  }
  iVar2 = _small_4m;
  _splaudio();
  param_1 = param_1 & ~_clk_state;
  param_2 = param_2 & _clk_state;
  _clk_state = _clk_state ^ param_1 ^ param_2;
  if ((param_2 & 0x80000) != 0) {
    _clk10_limit = uRamfeffd000;
    uRamfeffd000 = 0;
  }
  if ((param_2 & 0x80) != 0) {
    iVar5 = 0;
    _clk14_config = uRamfeffd010;
    if (iVar7 != 0) {
      iVar6 = 0;
      iVar3 = 0;
      do {
        iVar5 = iVar5 + 1;
        *(undefined4 *)(_clk14_lim + iVar3) = *(undefined4 *)(iVar6 + -0x1007000);
        iVar6 = iVar6 + 0x1000;
        iVar3 = iVar3 + 4;
      } while (iVar5 < iVar7);
    }
    iVar5 = 0;
    uRamfeffd010 = 0xf;
    if (iVar7 != 0) {
      puVar4 = (undefined4 *)0xfeff9000;
      do {
        puVar4[1] = 0;
        *puVar4 = 0x42900000;
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 0x400;
      } while (iVar5 < iVar7);
    }
  }
  if (iVar7 != 0) {
    iVar5 = 1;
    do {
      bVar1 = iVar5 < iVar7;
      iVar5 = iVar5 + 1;
    } while (bVar1);
  }
  if ((param_1 & 0x80000) != 0) {
    uRamfeffd000 = _clk10_limit;
  }
  iVar5 = 0;
  if (((param_1 & 0x80) != 0) && (uRamfeffd010 = _clk14_config, iVar7 != 0)) {
    iVar6 = 0;
    iVar3 = 0;
    do {
      iVar5 = iVar5 + 1;
      *(undefined4 *)(iVar3 + -0x1007000) = *(undefined4 *)(_clk14_lim + iVar6);
      iVar6 = iVar6 + 4;
      iVar3 = iVar3 + 0x1000;
    } while (iVar5 < iVar7);
  }
  _splx(iVar2);
  return CONCAT44(param_2,param_1);
}

