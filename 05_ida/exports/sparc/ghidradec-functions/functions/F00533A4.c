
/* WARNING: Removing unreachable block (ram,0xf0053658) */
/* WARNING: Removing unreachable block (ram,0xf0053614) */
/* WARNING: Removing unreachable block (ram,0xf00535e4) */
/* WARNING: Removing unreachable block (ram,0xf00535a8) */
/* WARNING: Removing unreachable block (ram,0xf00534e0) */
/* WARNING: Removing unreachable block (ram,0xf005341c) */
/* WARNING: Removing unreachable block (ram,0xf00534a8) */
/* WARNING: Removing unreachable block (ram,0xf0053518) */
/* WARNING: Removing unreachable block (ram,0xf0053594) */
/* WARNING: Removing unreachable block (ram,0xf00535f0) */
/* WARNING: Removing unreachable block (ram,0xf0053638) */
/* WARNING: Removing unreachable block (ram,0xf00536ac) */
/* WARNING: Removing unreachable block (ram,0xf00533cc) */

undefined8 sub_F00533A4(int *param_1,undefined4 param_2,uint param_3)

{
  undefined uVar1;
  char cVar2;
  word wVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar9;
  undefined4 unaff_l5;
  uint uVar10;
  undefined4 unaff_l6;
  uint uVar11;
  undefined4 unaff_l7;
  uint uVar12;
  undefined4 unaff_i0;
  int iVar13;
  undefined4 uVar14;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  uint uVar15;
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
  iVar8 = param_1[0xc];
  wVar3 = *(word *)(iVar8 + 0x44);
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_2;
  uVar11 = _page_size;
  while (_page_size = uVar11, (wVar3 & 1) != 0) {
    *(word *)(iVar8 + 0x44) = wVar3 | 0x10;
    _sleep(iVar8,10);
    uVar11 = _page_size;
    wVar3 = *(word *)(iVar8 + 0x44);
  }
  iVar9 = *(int *)(iVar8 + 0x50);
  uVar5 = *(uint *)(iVar8 + 0x70);
  iVar13 = 0;
  wVar3 = *(word *)(iVar8 + 0x44);
  *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(iVar8 + 0x40);
  *(word *)(iVar8 + 0x44) = wVar3 | 5;
  uVar15 = *(uint *)(iVar9 + 0x30);
  if (uVar5 < param_3 + uVar11) {
    _vm_page_zero_fill(*(undefined4 *)((int)register0x00000038 + -0xc));
  }
  uVar5 = *(uint *)(iVar9 + 0x48);
  do {
    uVar12 = param_3 & ~uVar5;
    uVar6 = uVar15 - uVar12;
    uVar10 = param_3 >> ((byte)*(undefined4 *)(iVar9 + 0x50) & 0x1f);
    uVar5 = uVar11;
    if (uVar6 < uVar11) {
      uVar5 = uVar6;
    }
    uVar6 = *(uint *)(iVar8 + 0x70) - param_3;
    if (*(uint *)(iVar8 + 0x70) <= param_3) {
      if (iVar13 != 0) {
        wVar3 = *(word *)(iVar8 + 0x44);
        goto loc_F0053684;
      }
      wVar3 = *(word *)(iVar8 + 0x44);
loc_F0053500:
      *(word *)(iVar8 + 0x44) = wVar3 & 0xfffe;
      if ((wVar3 & 0x10) != 0) {
        *(word *)(iVar8 + 0x44) = wVar3 & 0xffee;
        _wakeup(iVar8);
      }
      uVar14 = 1;
      goto locret_F00536B8;
    }
    if (uVar6 < uVar5) {
      uVar5 = uVar6;
    }
    uVar1 = *(undefined *)(dword_F0133DDC + 0x38);
    *(undefined *)(dword_F0133DDC + 0x38) = 0;
    iVar7 = iVar8;
    _bmap(iVar8,uVar10,1,uVar12 + uVar5,0);
    cVar2 = *(char *)(dword_F0133DDC + 0x38);
    iVar7 = iVar7 << ((byte)*(undefined4 *)(iVar9 + 100) & 0x1f);
    *(undefined *)(dword_F0133DDC + 0x38) = uVar1;
    if (cVar2 != 0) {
      *(int *)(*param_1 + 0x34) = (int)cVar2;
      _printf(aIoErrorOnPagei);
      wVar3 = *(word *)(iVar8 + 0x44);
loc_F00535FC:
      *(word *)(iVar8 + 0x44) = wVar3 & 0xfffe;
      if ((wVar3 & 0x10) != 0) {
        *(word *)(iVar8 + 0x44) = wVar3 & 0xffee;
        _wakeup(iVar8);
      }
      uVar14 = 2;
      goto locret_F00536B8;
    }
    if (iVar7 < 0) {
      wVar3 = *(word *)(iVar8 + 0x44);
      goto loc_F0053500;
    }
    if ((int)uVar10 < 0xc) {
      if (*(uint *)(iVar8 + 0x70) < uVar10 + 1 << ((byte)*(undefined4 *)(iVar9 + 0x50) & 0x1f)) {
        uVar6 = ((*(uint *)(iVar8 + 0x70) & ~*(uint *)(iVar9 + 0x48)) + *(int *)(iVar9 + 0x34)) - 1
                & *(uint *)(iVar9 + 0x4c);
      }
      else {
        uVar6 = *(uint *)(iVar9 + 0x30);
      }
    }
    else {
      uVar6 = *(uint *)(iVar9 + 0x30);
    }
    puVar4 = *(uint **)((int)register0x00000038 + -0x14);
    if (*(int *)(iVar8 + 0x58) + 1U == uVar10) {
      _breada(puVar4,iVar7,uVar6,_rablock,_rasize);
    }
    else {
      _bread(puVar4,iVar7,uVar6);
    }
    *(uint *)(iVar8 + 0x58) = uVar10;
    if ((int)(uVar6 - puVar4[10]) < (int)uVar5) {
      uVar5 = uVar6 - puVar4[10];
    }
    if ((*puVar4 & 4) != 0) {
      *(int *)(*param_1 + 0x34) = (int)*(sword *)(puVar4 + 7);
      _brelse(puVar4);
      _printf(aIoErrorOnPagei_0);
      wVar3 = *(word *)(iVar8 + 0x44);
      goto loc_F00535FC;
    }
    _copy_to_phys(puVar4[8] + uVar12,
                  *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x24) + iVar13,uVar5);
    if (uVar5 == uVar15) {
      *puVar4 = *puVar4 | 0x400000;
    }
    _brelse(puVar4);
    uVar11 = uVar11 - uVar5;
    iVar13 = iVar13 + uVar5;
    param_3 = param_3 + uVar5;
    if (((int)uVar11 < 1) || (uVar5 == 0)) {
      wVar3 = *(word *)(iVar8 + 0x44);
loc_F0053684:
      *(word *)(iVar8 + 0x44) = wVar3 & 0xfffe;
      if ((wVar3 & 0x10) != 0) {
        *(word *)(iVar8 + 0x44) = wVar3 & 0xffee;
        _wakeup(iVar8);
      }
      uVar14 = 0;
locret_F00536B8:
      return CONCAT44(0xfffe,uVar14);
    }
    uVar5 = *(uint *)(iVar9 + 0x48);
  } while( true );
}
