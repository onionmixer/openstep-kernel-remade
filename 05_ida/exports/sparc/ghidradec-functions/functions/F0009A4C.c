
/* WARNING: Removing unreachable block (ram,0xf0009b2c) */
/* WARNING: Removing unreachable block (ram,0xf0009c64) */
/* WARNING: Removing unreachable block (ram,0xf0009c20) */
/* WARNING: Removing unreachable block (ram,0xf0009bf8) */
/* WARNING: Removing unreachable block (ram,0xf0009b9c) */
/* WARNING: Removing unreachable block (ram,0xf0009b7c) */
/* WARNING: Removing unreachable block (ram,0xf0009b00) */
/* WARNING: Removing unreachable block (ram,0xf0009ab4) */
/* WARNING: Removing unreachable block (ram,0xf0009a8c) */
/* WARNING: Removing unreachable block (ram,0xf0009af8) */
/* WARNING: Removing unreachable block (ram,0xf0009b6c) */
/* WARNING: Removing unreachable block (ram,0xf0009b8c) */
/* WARNING: Removing unreachable block (ram,0xf0009ba8) */
/* WARNING: Removing unreachable block (ram,0xf0009c08) */
/* WARNING: Removing unreachable block (ram,0xf0009c44) */
/* WARNING: Removing unreachable block (ram,0xf0009cd4) */
/* WARNING: Removing unreachable block (ram,0xf0009cf4) */
/* WARNING: Removing unreachable block (ram,0xf0009a84) */

undefined8 _acct(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined uVar7;
  uint uVar8;
  int iVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar10;
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
  if (_savacctp != 0) {
    (**(code **)(*(int *)(*(int *)(_savacctp + 0x24) + 4) + 0xc))
              (*(int *)(_savacctp + 0x24),(undefined *)((int)register0x00000038 + -0x48));
    iVar2 = _acctresume;
    .umul(_acctresume,*(undefined4 *)((int)register0x00000038 + -0x40));
    .div();
    if (iVar2 < *(int *)((int)register0x00000038 + -0x38)) {
      _acctp = _savacctp;
      _savacctp = 0;
      _printf(aAccountingResu);
    }
  }
  iVar2 = _acctp;
  if (_acctp != 0) {
    piVar1 = (int *)(_acctp + 0x24);
    *(sword *)(_acctp + 6) = *(sword *)(_acctp + 6) + 1;
    (**(code **)(*(int *)(*piVar1 + 4) + 0xc))
              (*piVar1,(undefined *)((int)register0x00000038 + -0x48));
    iVar6 = _acctsuspend;
    .umul(_acctsuspend,*(undefined4 *)((int)register0x00000038 + -0x40));
    .div();
    uVar8 = 0;
    if (iVar6 < *(int *)((int)register0x00000038 + -0x38)) {
      do {
        _acctbuf[uVar8] = *(undefined *)(_active_u + uVar8 + 8);
        iVar6 = _active_u;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 10);
      uVar3 = *(undefined4 *)(_active_u + 0x16c);
      _compress(uVar3,*(undefined4 *)(_active_u + 0x170));
      DAT_f01349fa._0_2_ = (undefined2)uVar3;
      uVar3 = *(undefined4 *)(iVar6 + 0x174);
      _compress(uVar3,*(undefined4 *)(iVar6 + 0x178));
      DAT_f01349fa._2_2_ = (undefined2)uVar3;
      puVar10 = (undefined *)((int)register0x00000038 + -0x50);
      _microtime(puVar10);
      _timevalsub(puVar10,_active_u + 0x238);
      uVar3 = *(undefined4 *)((int)register0x00000038 + -0x50);
      _compress(uVar3,*(undefined4 *)((int)register0x00000038 + -0x4c));
      DAT_f01349fa._4_2_ = (undefined2)uVar3;
      DAT_f01349fa._6_4_ = *(undefined4 *)(_active_u + 0x238);
      DAT_f01349fa._10_2_ = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 6);
      DAT_f01349fa._12_2_ = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 8);
      *(undefined4 *)((int)register0x00000038 + -0x50) = *(undefined4 *)(iVar6 + 0x174);
      *(undefined4 *)((int)register0x00000038 + -0x4c) = *(undefined4 *)(iVar6 + 0x178);
      _timevaladd(puVar10,iVar6 + 0x16c);
      iVar4 = *(int *)((int)register0x00000038 + -0x50);
      .umul(iVar4,_hz);
      iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      .div(iVar9,_tick);
      if (iVar4 + iVar9 == 0) {
        DAT_f01349fa._14_2_ = 0;
      }
      else {
        iVar5 = *(int *)(iVar6 + 0x180) + *(int *)(iVar6 + 0x184) + *(int *)(iVar6 + 0x188);
        .div(iVar5,iVar4 + iVar9);
        DAT_f01349fa._14_2_ = (undefined2)iVar5;
      }
      iVar6 = *(int *)(iVar6 + 0x198) + *(int *)(iVar6 + 0x19c);
      _compress(iVar6,0);
      DAT_f01349fa._16_2_ = (undefined2)iVar6;
      DAT_f01349fa._18_2_ = 0xffff;
      if (*(int *)(_active_u + 0x164) != 0) {
        DAT_f01349fa._18_2_ = *(undefined2 *)(_active_u + 0x168);
      }
      DAT_f01349fa[0x14] = (undefined)*(undefined2 *)(_active_u + 0x240);
      uVar7 = 1;
      uVar3 = *(undefined4 *)(_active_u + 0x1c);
      *(undefined4 *)(_active_u + 0x1c) = _acctcred;
      _vn_rdwr(1,iVar2,_acctbuf,0x20,0,1,3,0);
      *(undefined *)(dword_F0133DDC + 0x38) = uVar7;
      *(undefined4 *)(_active_u + 0x1c) = uVar3;
    }
    else {
      _savacctp = _acctp;
      _acctp = 0;
      _printf(aAccountingSusp);
    }
    _vn_rele(iVar2);
  }
  return CONCAT44(param_2,param_1);
}
