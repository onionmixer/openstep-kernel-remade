
/* WARNING: Removing unreachable block (ram,0xf0053928) */
/* WARNING: Removing unreachable block (ram,0xf0053908) */
/* WARNING: Removing unreachable block (ram,0xf00538a8) */
/* WARNING: Removing unreachable block (ram,0xf0053868) */
/* WARNING: Removing unreachable block (ram,0xf0053830) */
/* WARNING: Removing unreachable block (ram,0xf0053764) */
/* WARNING: Removing unreachable block (ram,0xf00537a4) */
/* WARNING: Removing unreachable block (ram,0xf005381c) */
/* WARNING: Removing unreachable block (ram,0xf0053874) */
/* WARNING: Removing unreachable block (ram,0xf00538d4) */
/* WARNING: Removing unreachable block (ram,0xf00538f8) */
/* WARNING: Removing unreachable block (ram,0xf00539b0) */
/* WARNING: Removing unreachable block (ram,0xf00536e8) */

undefined8 sub_F00536C0(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined uVar1;
  char cVar2;
  word wVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  uint uVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar9;
  undefined4 unaff_l5;
  uint uVar10;
  undefined4 unaff_l6;
  uint uVar11;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar12;
  undefined4 uVar13;
  undefined4 unaff_i1;
  uint *puVar14;
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
  iVar7 = param_1[0xc];
  wVar3 = *(word *)(iVar7 + 0x44);
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_2;
  while ((wVar3 & 1) != 0) {
    *(word *)(iVar7 + 0x44) = wVar3 | 0x10;
    _sleep(iVar7,10);
    wVar3 = *(word *)(iVar7 + 0x44);
  }
  iVar12 = 0;
  puVar14 = *(uint **)(iVar7 + 0x40);
  iVar9 = *(int *)(iVar7 + 0x50);
  *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 1;
  uVar11 = *(uint *)(iVar9 + 0x30);
  uVar4 = *(uint *)(iVar9 + 0x48);
  do {
    uVar10 = param_4 & ~uVar4;
    uVar8 = param_4 >> ((byte)*(undefined4 *)(iVar9 + 0x50) & 0x1f);
    uVar4 = param_3;
    if (uVar11 - uVar10 < param_3) {
      uVar4 = uVar11 - uVar10;
    }
    uVar1 = *(undefined *)(dword_F0133DDC + 0x38);
    *(undefined *)(dword_F0133DDC + 0x38) = 0;
    iVar6 = iVar7;
    _bmap(iVar7,uVar8,0x20,uVar10 + uVar4,0);
    cVar2 = *(char *)(dword_F0133DDC + 0x38);
    iVar6 = iVar6 << ((byte)*(undefined4 *)(iVar9 + 100) & 0x1f);
    *(undefined *)(dword_F0133DDC + 0x38) = uVar1;
    if ((cVar2 != 0) || (iVar6 < 0)) {
      *(int *)(*param_1 + 0x34) = (int)cVar2;
      _printf(aIoErrorOnPageo);
loc_F0053880:
      wVar3 = *(word *)(iVar7 + 0x44);
      *(word *)(iVar7 + 0x44) = wVar3 & 0xfffe;
      if ((wVar3 & 0x10) != 0) {
        *(word *)(iVar7 + 0x44) = wVar3 & 0xffee;
        _wakeup(iVar7);
      }
      uVar13 = 2;
      goto locret_F00539BC;
    }
    if (*(uint *)(iVar7 + 0x70) < param_4 + uVar4) {
      *(uint *)(iVar7 + 0x70) = param_4 + uVar4;
    }
    if ((int)uVar8 < 0xc) {
      if (*(uint *)(iVar7 + 0x70) < uVar8 + 1 << ((byte)*(undefined4 *)(iVar9 + 0x50) & 0x1f)) {
        uVar8 = ((*(uint *)(iVar7 + 0x70) & ~*(uint *)(iVar9 + 0x48)) + *(int *)(iVar9 + 0x34)) - 1
                & *(uint *)(iVar9 + 0x4c);
      }
      else {
        uVar8 = *(uint *)(iVar9 + 0x30);
      }
    }
    else {
      uVar8 = *(uint *)(iVar9 + 0x30);
    }
    puVar5 = puVar14;
    if (uVar4 == uVar11) {
      _getblk(puVar14,iVar6,uVar8);
    }
    else {
      _bread(puVar14,iVar6,uVar8);
    }
    if ((int)(uVar8 - puVar5[10]) < (int)uVar4) {
      uVar4 = uVar8 - puVar5[10];
    }
    if ((*puVar5 & 4) != 0) {
      *(int *)(*param_1 + 0x34) = (int)*(sword *)(puVar5 + 7);
      _brelse(puVar5);
      _printf(aIoErrorOnPageo_0);
      goto loc_F0053880;
    }
    param_3 = param_3 - uVar4;
    param_4 = param_4 + uVar4;
    iVar6 = *(int *)((int)register0x00000038 + -0xc) + iVar12;
    iVar12 = iVar12 + uVar4;
    _copy_from_phys(iVar6,puVar5[8] + uVar10,uVar4);
    if (uVar4 + uVar10 == uVar11) {
      *puVar5 = *puVar5 | 0x400000;
      _bawrite();
      wVar3 = *(word *)(iVar7 + 0x44);
    }
    else {
      _bdwrite(puVar5);
      wVar3 = *(word *)(iVar7 + 0x44);
    }
    *(word *)(iVar7 + 0x44) = wVar3 | 0x42;
    *(word *)(iVar7 + 100) = *(word *)(iVar7 + 100) & 0xf3ff;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar7 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar7 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar7 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar7 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar7 + 0x44) & 0x40) != 0) {
      *(undefined4 *)(iVar7 + 0x4c) = 0;
      *(undefined4 *)(iVar7 + 0x84) = _iuniqtime;
    }
    if ((param_3 == 0) || (uVar4 == 0)) {
      wVar3 = *(word *)(iVar7 + 0x44);
      *(word *)(iVar7 + 0x44) = wVar3 & 0xfffe;
      if ((wVar3 & 0x10) != 0) {
        *(word *)(iVar7 + 0x44) = wVar3 & 0xffee;
        _wakeup(iVar7);
      }
      uVar13 = 0;
locret_F00539BC:
      return CONCAT44(puVar14,uVar13);
    }
    uVar4 = *(uint *)(iVar9 + 0x48);
  } while( true );
}
