
/* WARNING: Removing unreachable block (ram,0xf00505b4) */
/* WARNING: Removing unreachable block (ram,0xf0050590) */
/* WARNING: Removing unreachable block (ram,0xf0050564) */
/* WARNING: Removing unreachable block (ram,0xf0050520) */
/* WARNING: Removing unreachable block (ram,0xf00504fc) */
/* WARNING: Removing unreachable block (ram,0xf005053c) */
/* WARNING: Removing unreachable block (ram,0xf0050580) */
/* WARNING: Removing unreachable block (ram,0xf00505d8) */
/* WARNING: Removing unreachable block (ram,0xf00505c4) */
/* WARNING: Removing unreachable block (ram,0xf00504a8) */

undefined8 _bufstats(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 *puVar6;
  undefined4 unaff_l1;
  uint uVar7;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 *puVar9;
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
  int aiStack_8 [2];
  
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
  iVar2 = 0x2000;
  udiv(0x2000,_page_size);
  uVar3 = iVar2 * 4 + 0x6eU & 0xfffffff8;
  puVar9 = &_bfreelist;
  iVar2 = 0;
  do {
    iVar8 = 0;
    uVar7 = 0;
    iVar5 = 0;
    while( true ) {
      uVar4 = 0x2000;
      udiv(0x2000,_page_size);
      if (uVar4 < uVar7) break;
      *(undefined4 *)((int)aiStack_8 + (iVar5 - uVar3)) = 0;
      iVar5 = iVar5 + 4;
      uVar7 = uVar7 + 1;
    }
    _spltty();
    for (puVar6 = (undefined4 *)puVar9[3]; puVar6 != puVar9; puVar6 = (undefined4 *)puVar6[3]) {
      iVar5 = puVar6[6];
      udiv(iVar5,_page_size);
      *(int *)((int)aiStack_8 + (iVar5 * 4 - uVar3)) =
           *(int *)((int)aiStack_8 + (iVar5 * 4 - uVar3)) + 1;
      iVar8 = iVar8 + 1;
    }
    _splx(uVar4);
    uVar7 = 0;
    iVar5 = 0;
    _printf(aSTotalD,*(undefined4 *)(unk_F010EDCC + iVar2),iVar8);
    while( true ) {
      uVar1 = _page_size;
      uVar4 = 0x2000;
      udiv(0x2000,_page_size);
      if (uVar4 < uVar7) break;
      iVar8 = *(int *)((int)aiStack_8 + (iVar5 - uVar3));
      if (iVar8 != 0) {
        uVar4 = uVar7;
        umul(uVar7,uVar1);
        _printf(&aDD,uVar4,iVar8);
      }
      iVar5 = iVar5 + 4;
      uVar7 = uVar7 + 1;
    }
    _printf(&DAT_f010ee18);
    puVar9 = puVar9 + 0x11;
    iVar2 = iVar2 + 4;
  } while (puVar9 < &_buf);
  return 0xf010edccf010ec00;
}

