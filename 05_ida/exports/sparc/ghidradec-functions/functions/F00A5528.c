
/* WARNING: Removing unreachable block (ram,0xf00a5848) */
/* WARNING: Removing unreachable block (ram,0xf00a5818) */
/* WARNING: Removing unreachable block (ram,0xf00a57e4) */
/* WARNING: Removing unreachable block (ram,0xf00a57b0) */
/* WARNING: Removing unreachable block (ram,0xf00a577c) */
/* WARNING: Removing unreachable block (ram,0xf00a5748) */
/* WARNING: Removing unreachable block (ram,0xf00a5714) */
/* WARNING: Removing unreachable block (ram,0xf00a56dc) */
/* WARNING: Removing unreachable block (ram,0xf00a56a4) */
/* WARNING: Removing unreachable block (ram,0xf00a5688) */
/* WARNING: Removing unreachable block (ram,0xf00a566c) */
/* WARNING: Removing unreachable block (ram,0xf00a554c) */
/* WARNING: Removing unreachable block (ram,0xf00a5540) */
/* WARNING: Removing unreachable block (ram,0xf00a565c) */
/* WARNING: Removing unreachable block (ram,0xf00a5678) */
/* WARNING: Removing unreachable block (ram,0xf00a5694) */
/* WARNING: Removing unreachable block (ram,0xf00a56bc) */
/* WARNING: Removing unreachable block (ram,0xf00a56f0) */
/* WARNING: Removing unreachable block (ram,0xf00a5728) */
/* WARNING: Removing unreachable block (ram,0xf00a575c) */
/* WARNING: Removing unreachable block (ram,0xf00a5790) */
/* WARNING: Removing unreachable block (ram,0xf00a57c4) */
/* WARNING: Removing unreachable block (ram,0xf00a57f8) */
/* WARNING: Removing unreachable block (ram,0xf00a582c) */
/* WARNING: Removing unreachable block (ram,0xf00a5850) */
/* WARNING: Removing unreachable block (ram,0xf00a552c) */

undefined8 _set_tod(uint param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar10;
  undefined4 unaff_i2;
  uint uVar11;
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
  uVar11 = 2;
  uVar2 = param_1;
  _splusclock();
  uVar10 = param_1;
  .div(param_1,0x15180);
  iVar3 = uVar10 + 2;
  .rem(iVar3,7);
  while (0x1e13380 < param_1) {
    while( true ) {
      iVar4 = -0x1e28500;
      if ((uVar11 & 3) != 0) {
        iVar4 = -0x1e13380;
      }
      param_1 = param_1 + iVar4;
      uVar11 = uVar11 + 1;
      if ((uVar11 & 3) != 0) break;
      if (param_1 < 0x1e28501) goto loc_F00A55BC;
    }
  }
loc_F00A55BC:
  uVar10 = 1;
  if (-1 < (int)param_1) {
    do {
      if (((uVar11 & 3) != 0) || (iVar4 = -0x263b80, (uVar10 & 0xffff) != 2)) {
        iVar4 = -(&_clk_state)[uVar10 & 0xffff];
      }
      param_1 = param_1 + iVar4;
      uVar10 = uVar10 + 1;
    } while (-1 < (int)param_1);
  }
  uVar10 = uVar10 - 1;
  if (((uVar11 & 3) == 0) && ((uVar10 & 0xffff) == 2)) {
    iVar4 = 0x263b80;
  }
  else {
    iVar4 = (&_clk_state)[uVar10 & 0xffff];
  }
  param_1 = param_1 + iVar4;
  uVar7 = param_1;
  .rem(param_1,0x3c);
  .div(param_1,0x3c);
  uVar8 = param_1;
  .rem();
  .div(param_1,0x3c);
  uVar9 = param_1;
  .rem();
  uVar5 = param_1;
  .div(param_1,0x18);
  _pmap_change_prot(0xfefffff8,7);
  bVar1 = bRamfefffff8;
  uVar7 = uVar7 & 0xffff;
  bRamfefffff8 = bRamfefffff8 | 0x80;
  uVar6 = uVar7;
  .udiv(uVar7,10);
  .urem(uVar7,10);
  bRamfefffff9 = (char)uVar7 + (char)uVar6 * '\x10' & 0x7f;
  uVar8 = uVar8 & 0xffff;
  uVar7 = uVar8;
  .udiv(uVar8,10);
  .urem(uVar8,10);
  bRamfefffffa = (char)uVar8 + (char)uVar7 * '\x10' & 0x7f;
  uVar9 = uVar9 & 0xffff;
  uVar7 = uVar9;
  .udiv(uVar9,10);
  .urem(uVar9,10);
  bRamfefffffb = (char)uVar9 + (char)uVar7 * '\x10' & 0x3f;
  uVar7 = iVar3 + 1U & 0xffff;
  .udiv(uVar7,10);
  .urem(uVar7,10);
  bRamfefffffc = (byte)uVar7 & 7;
  uVar8 = uVar5 + 1 & 0xffff;
  uVar7 = uVar8;
  .udiv(uVar8,10);
  .urem(uVar8,10);
  bRamfefffffd = (char)uVar8 + (char)uVar7 * '\x10' & 0x3f;
  uVar8 = uVar10 & 0xffff;
  uVar7 = uVar8;
  .udiv(uVar8,10);
  .urem(uVar8,10);
  bRamfefffffe = (char)uVar8 + (char)uVar7 * '\x10' & 0x1f;
  uVar11 = uVar11 & 0xffff;
  uVar7 = uVar11;
  .udiv(uVar11,10);
  .urem(uVar11,10);
  cRamfeffffff = (char)uVar11 + (char)uVar7 * '\x10';
  bRamfefffff8 = bVar1 & 0x7f;
  _pmap_change_prot(0xfefffff8,1);
  _splx(uVar2);
  return CONCAT44(uVar10,param_1);
}
