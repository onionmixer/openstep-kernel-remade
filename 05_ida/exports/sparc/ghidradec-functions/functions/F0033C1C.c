
/* WARNING: Removing unreachable block (ram,0xf0033d34) */
/* WARNING: Removing unreachable block (ram,0xf0033c8c) */
/* WARNING: Removing unreachable block (ram,0xf0033cd8) */
/* WARNING: Removing unreachable block (ram,0xf0033ce4) */
/* WARNING: Removing unreachable block (ram,0xf0033d78) */
/* WARNING: Removing unreachable block (ram,0xf0033d60) */
/* WARNING: Removing unreachable block (ram,0xf0033c64) */

undefined8 _ip_insertoptions(undefined4 *param_1,int param_2,int *param_3)

{
  sword sVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar8;
  int iVar9;
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
  iVar7 = *(int *)(param_2 + *(int *)(param_2 + 4));
  iVar8 = (int)param_1 + param_1[1];
  sVar1 = *(sword *)(param_2 + 8);
  iVar3 = (int)sVar1;
  param_2 = param_2 + *(int *)(param_2 + 4);
  iVar9 = iVar3 + -4;
  if (iVar7 != 0) {
    *(int *)(iVar8 + 0x10) = iVar7;
  }
  uVar6 = param_1[1];
  uVar4 = iVar3 + 8;
  if ((uVar6 < 0x7c) && (bVar2 = uVar4 <= uVar6, uVar4 = uVar6 - iVar9, bVar2)) {
    param_1[1] = uVar4;
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) + (sword)iVar9;
    _ovbcopy(iVar8,(int)param_1 + param_1[1],0x14);
  }
  else {
    _spltty();
    puVar5 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
      _m_more(0,2);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
        _panic(&aMget_9);
      }
      *(undefined2 *)((int)puVar5 + 10) = 2;
      word_F0134B0C = word_F0134B0C + -1;
      DAT_f0134b10._0_2_ = DAT_f0134b10._0_2_ + 1;
      _mfree = (undefined4 *)*puVar5;
      puVar5[1] = 0xc;
      *puVar5 = 0;
    }
    _splx(uVar4);
    if (puVar5 == (undefined4 *)0x0) goto locret_F0033D94;
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) + -0x14;
    param_1[1] = param_1[1] + 0x14;
    *puVar5 = param_1;
    puVar5[1] = 0x68 - iVar9;
    *(sword *)(puVar5 + 2) = sVar1 + 0x10;
    _bcopy(iVar8,(int)puVar5 + puVar5[1],0x14);
    param_1 = puVar5;
  }
  iVar7 = param_1[1];
  _bcopy(param_2 + 4,(int)param_1 + iVar7 + 0x14,iVar9);
  *param_3 = iVar3 + 0x10;
  *(sword *)((int)param_1 + iVar7 + 2) = *(sword *)((int)param_1 + iVar7 + 2) + (sword)iVar9;
locret_F0033D94:
  return CONCAT44(param_2,param_1);
}
