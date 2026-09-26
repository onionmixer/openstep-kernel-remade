
/* WARNING: Removing unreachable block (ram,0xf00bafe0) */
/* WARNING: Removing unreachable block (ram,0xf00bafd4) */
/* WARNING: Removing unreachable block (ram,0xf00baf48) */
/* WARNING: Removing unreachable block (ram,0xf00baebc) */
/* WARNING: Removing unreachable block (ram,0xf00bae80) */
/* WARNING: Removing unreachable block (ram,0xf00bae4c) */
/* WARNING: Removing unreachable block (ram,0xf00bae08) */
/* WARNING: Removing unreachable block (ram,0xf00badd8) */
/* WARNING: Removing unreachable block (ram,0xf00bada8) */
/* WARNING: Removing unreachable block (ram,0xf00bad64) */
/* WARNING: Removing unreachable block (ram,0xf00bacfc) */
/* WARNING: Removing unreachable block (ram,0xf00bace4) */
/* WARNING: Removing unreachable block (ram,0xf00baccc) */
/* WARNING: Removing unreachable block (ram,0xf00bacd4) */
/* WARNING: Removing unreachable block (ram,0xf00bacec) */
/* WARNING: Removing unreachable block (ram,0xf00bad44) */
/* WARNING: Removing unreachable block (ram,0xf00bad8c) */
/* WARNING: Removing unreachable block (ram,0xf00badc0) */
/* WARNING: Removing unreachable block (ram,0xf00badf0) */
/* WARNING: Removing unreachable block (ram,0xf00bae1c) */
/* WARNING: Removing unreachable block (ram,0xf00bae60) */
/* WARNING: Removing unreachable block (ram,0xf00bae94) */
/* WARNING: Removing unreachable block (ram,0xf00baec4) */
/* WARNING: Removing unreachable block (ram,0xf00bafc0) */
/* WARNING: Removing unreachable block (ram,0xf00bacc0) */
/* WARNING: Removing unreachable block (ram,0xf00bb03c) */
/* WARNING: Removing unreachable block (ram,0xf00baff0) */
/* WARNING: Removing unreachable block (ram,0xf00bb024) */
/* WARNING: Removing unreachable block (ram,0xf00bb044) */
/* WARNING: Removing unreachable block (ram,0xf00bafe8) */

undefined8 _zsattach(int param_1,undefined *param_2)

{
  sword sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  undefined4 unaff_l0;
  int iVar9;
  int iVar10;
  int *piVar11;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  sword *psVar12;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined *puVar13;
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
  bool bVar14;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  sword asStack_10 [8];
  
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
  bVar14 = _zscom == 0;
  *(int *)(param_1 + 0x2c) = dword_F011FB10;
  if (bVar14) {
    iVar9 = _nzs << 7;
    _kalloc();
    _zscom = iVar9;
    _bzero();
    iVar9 = 4;
    _kalloc();
    _zssoftCAR = iVar9;
    _bzero();
    iVar9 = 0x10;
    _kalloc();
    _zsinfo = iVar9;
    _bzero();
    _zscurr = _zscom + 0x40;
    _zslast = _zscom;
    if (((_zscom == 0) || (_zssoftCAR == 0)) || (_zsinfo == 0)) {
      _printf(aZsNoSpaceForSt);
      uVar6 = 0xffffffff;
      goto locret_F00BB060;
    }
    iVar9 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar9 = *(int *)(param_1 + 0x2c);
  }
  iVar9 = _zscom + iVar9 * 0x80;
  _stop_mon_clock();
  if (*(int *)(param_1 + 0x10) - 1U < 2) {
    puVar8 = *(undefined4 **)(param_1 + 0x14);
    uVar3 = puVar8[1];
    iVar10 = 0;
    _map_regs(uVar3,puVar8[2],*puVar8);
    *(uint *)(iVar9 + 0x10) = uVar3;
    do {
      uVar4 = *(uint *)(iVar9 + 0x10) | 4;
      _zszread(uVar4,1);
      uVar6 = 1;
      if ((uVar4 & 1) != 0) {
        uVar4 = *(uint *)(iVar9 + 0x10) & 0xfffffffb;
        _zszread(uVar4,1);
        uVar6 = 0;
        if ((uVar4 & 1) != 0) {
          uVar4 = *(uint *)(iVar9 + 0x10) | 4;
          _zszread(uVar4,0);
          uVar6 = 0;
          if ((uVar4 & 4) != 0) {
            uVar4 = *(uint *)(iVar9 + 0x10) & 0xfffffffb;
            _zszread(uVar4,0);
            uVar6 = 0xc;
            if ((uVar4 & 4) != 0) break;
          }
        }
      }
      _us_spin(1000,uVar6);
      bVar14 = iVar10 < 0x1f5;
      iVar10 = iVar10 + 1;
    } while (bVar14);
    iVar10 = 0;
    param_2 = _zs_proto;
    psVar12 = (sword *)(iVar9 + 0x14);
    uVar4 = *(uint *)(iVar9 + 0x10) | 4;
    _zszread(uVar4,0xc);
    *(sword *)((int)register0x00000038 + -0x10) = (sword)uVar4;
    uVar4 = *(uint *)(iVar9 + 0x10) | 4;
    _zszread(uVar4,0xd);
    *(word *)((int)register0x00000038 + -0x10) =
         *(word *)((int)register0x00000038 + -0x10) | (word)(uVar4 << 8);
    uVar4 = *(uint *)(iVar9 + 0x10) & 0xfffffffb;
    _zszread(uVar4,0xc);
    *(sword *)((int)register0x00000038 + -0xe) = (sword)uVar4;
    uVar4 = *(uint *)(iVar9 + 0x10) & 0xfffffffb;
    _zszread(uVar4,0xd);
    *(word *)((int)register0x00000038 + -0xe) =
         *(word *)((int)register0x00000038 + -0xe) | (word)(uVar4 << 8);
    *(undefined *)(iVar9 + 0x29) = 0xc0;
    _zszwrite(*(undefined4 *)(iVar9 + 0x10),9,0xc0);
    _us_spin(10);
    *(undefined *)(iVar9 + 0x29) = 0;
    puVar13 = (undefined *)((int)register0x00000038 + -8);
    do {
      if (iVar10 == 0) {
        *(uint *)(psVar12 + -2) = uVar3 | 4;
      }
      else {
        iVar9 = iVar9 + 0x40;
        *(uint *)(psVar12 + 0x1e) = uVar3 & 0xfffffffb;
        psVar12 = psVar12 + 0x20;
        _zscurr = iVar9;
      }
      iVar2 = _zsinfo;
      iVar5 = *(int *)(param_1 + 0x2c) * 2 + iVar10;
      *psVar12 = (sword)iVar5;
      *(int *)(iVar2 + (iVar5 * 0x10000 >> 0xe)) = param_1;
      uVar6 = *(undefined4 *)(param_1 + 0x28);
      if (iVar10 == 0) {
        puVar7 = aPortAIgnoreCd;
      }
      else {
        puVar7 = aPortBIgnoreCd;
      }
      _getprop(uVar6,puVar7,0);
      *(char *)(_zssoftCAR + *psVar12) = (char)uVar6;
      if (_zs_proto._0_4_ != 0) {
        sVar1 = *(sword *)(puVar13 + -8);
        piVar11 = (int *)param_2;
        while( true ) {
          puVar8 = (undefined4 *)*piVar11;
          piVar11 = piVar11 + 1;
          (*(code *)*puVar8)(iVar9,(int)sVar1);
          if (*piVar11 == 0) break;
          sVar1 = *(sword *)(puVar13 + -8);
        }
      }
      iVar10 = iVar10 + 1;
      puVar13 = puVar13 + 2;
    } while (iVar10 < 2);
    *(undefined *)(iVar9 + 0x29) = 9;
    _zszwrite(*(undefined4 *)(iVar9 + 0x10),9,9);
    _us_spin(4000);
    _start_mon_clock();
    _zslast = iVar9;
    if (*(int *)(param_1 + 0x18) != 0) {
      _addintr(**(undefined4 **)(param_1 + 0x1c),_zsintr_hi,*(undefined4 *)(param_1 + 0xc),
               dword_F011FB10);
      _addintr(0x16,_zsintr,*(undefined4 *)(param_1 + 0xc),dword_F011FB10);
    }
    _report_dev(param_1);
    uVar6 = 0;
    dword_F011FB10 = dword_F011FB10 + 1;
  }
  else {
    _printf(aZsDWarningBadR,dword_F011FB10);
    uVar6 = 0xffffffff;
  }
locret_F00BB060:
  return CONCAT44(param_2,uVar6);
}
