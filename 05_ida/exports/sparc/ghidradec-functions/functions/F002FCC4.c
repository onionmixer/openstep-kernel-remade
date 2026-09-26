
/* WARNING: Removing unreachable block (ram,0xf002fe44) */
/* WARNING: Removing unreachable block (ram,0xf002fd94) */
/* WARNING: Removing unreachable block (ram,0xf002fd60) */
/* WARNING: Removing unreachable block (ram,0xf002fd54) */
/* WARNING: Removing unreachable block (ram,0xf002fd14) */
/* WARNING: Removing unreachable block (ram,0xf002fd74) */
/* WARNING: Removing unreachable block (ram,0xf002fdd8) */
/* WARNING: Removing unreachable block (ram,0xf002fe70) */
/* WARNING: Removing unreachable block (ram,0xf002fcec) */

undefined8 _in_bootp_bptombuf(undefined *param_1)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 *puVar8;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar9;
  undefined4 unaff_i1;
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
  iVar7 = 0x148;
  puVar3 = DAT_f0134800;
  puVar8 = (undefined4 *)((int)register0x00000038 + -0xc);
  do {
    _spltty();
    puVar4 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x1;
      _m_more(1,1);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
        _panic(&aMget_8);
      }
      *(undefined2 *)((int)puVar4 + 10) = 1;
      word_F0134B0C = word_F0134B0C + -1;
      DAT_f0134b0e._0_2_ = DAT_f0134b0e._0_2_ + 1;
      _mfree = (undefined4 *)*puVar4;
      puVar4[1] = 0xc;
      *puVar4 = 0;
    }
    _splx(puVar3);
    if (iVar7 < 0x200) {
loc_F002FE24:
      iVar1 = iVar7 + -0x70;
      iVar5 = 0x70;
      iVar6 = 0x70;
    }
    else {
      _spltty();
      if (_mclfree == (int *)0x0) {
        _m_clalloc(1,1,0);
      }
      piVar2 = _mclfree;
      if (_mclfree != (int *)0x0) {
        iVar5 = (int)_mclfree - _mbutl >> 10;
        _mclrefcnt[iVar5] = _mclrefcnt[iVar5] + '\x01';
        DAT_f0134afc._0_4_ = DAT_f0134afc._0_4_ + -1;
        _mclfree = (int *)*_mclfree;
      }
      _splx(puVar3);
      if (piVar2 == (int *)0x0) {
        *(undefined2 *)(puVar4 + 2) = 0x70;
      }
      else {
        puVar4[1] = (int)piVar2 - (int)puVar4;
        *(undefined2 *)(puVar4 + 2) = 0x400;
        *(undefined2 *)(puVar4 + 3) = 1;
      }
      if (*(sword *)(puVar4 + 2) != 0x400) goto loc_F002FE24;
      iVar5 = 0x400;
      iVar1 = iVar7 + -0x400;
      iVar6 = 0x400;
    }
    if (iVar1 == 0 || iVar1 < 0 != SBORROW4(iVar7,iVar5)) {
      iVar6 = iVar7;
    }
    iVar7 = iVar7 - iVar6;
    puVar9 = param_1 + iVar6;
    _bcopy(param_1,(int)puVar4 + puVar4[1],iVar6);
    *(sword *)(puVar4 + 2) = (sword)iVar6;
    *puVar8 = puVar4;
    puVar3 = param_1;
    puVar8 = puVar4;
    param_1 = puVar9;
    if (iVar7 < 1) {
      iVar7 = *(int *)((int)register0x00000038 + -0xc);
      iVar5 = iVar7 + *(int *)(iVar7 + 4);
      *(undefined2 *)(iVar5 + 10) = 0;
      _in_cksum(iVar7,0x14);
      *(sword *)(iVar5 + 10) = (sword)iVar7;
      return CONCAT44(1,*(undefined4 *)((int)register0x00000038 + -0xc));
    }
  } while( true );
}
