
/* WARNING: Removing unreachable block (ram,0xf009a1f0) */
/* WARNING: Removing unreachable block (ram,0xf009a244) */
/* WARNING: Removing unreachable block (ram,0xf009a1a8) */
/* WARNING: Removing unreachable block (ram,0xf009a110) */
/* WARNING: Removing unreachable block (ram,0xf009a0fc) */
/* WARNING: Removing unreachable block (ram,0xf009a188) */
/* WARNING: Removing unreachable block (ram,0xf009a220) */
/* WARNING: Removing unreachable block (ram,0xf009a1d0) */
/* WARNING: Removing unreachable block (ram,0xf009a210) */
/* WARNING: Removing unreachable block (ram,0xf009a0e4) */

undefined8 _mb_mapalloc(undefined *param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar4;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
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
  uVar5 = *(uint *)(param_2 + 0x20) & 0xfff;
  uVar4 = *(int *)(param_2 + 0x14) + uVar5 + 0xfff >> 0xc;
  iVar3 = param_2;
  _buscheck();
  if (iVar3 < 0) {
    _panic(aMbMapallocBusc);
  }
  if (0 < iVar3) {
    _bustype();
    uVar6 = 0;
    if (iVar3 == 3) goto locret_F009A258;
    if (iVar3 < 4) {
      if (iVar3 == 1) goto locret_F009A258;
    }
    else if (((iVar3 != 4) && (iVar3 == 5)) && (param_1 == _mbutlmap)) {
      uVar6 = 0;
      goto locret_F009A258;
    }
  }
  puVar1 = _dvmamap;
  if ((param_1 == _dvmamap) && (puVar1 = DAT_f013d800, (param_3 & 0x40) != 0)) {
    param_1 = _bigsbusmap;
  }
  _splvm();
  while( true ) {
    puVar2 = param_1;
    _bp_alloc(param_1,param_2,uVar4 + 1);
    if (puVar2 != (undefined *)0x0) break;
    if ((param_3 & 1) != 0) {
      iVar3 = DAT_f0131544._0_4_;
      if (param_4 != 0) {
        sub_F009A388(param_4,param_5,(int)puVar1 >> 8 & 0xf);
        iVar3 = uVar4 * 0x1000;
        if (iVar3 < (int)DAT_f0131544._0_4_) {
          iVar3 = DAT_f0131544._0_4_;
        }
      }
      DAT_f0131544._0_4_ = iVar3;
      _splx(puVar1);
      uVar6 = 0;
      goto locret_F009A258;
    }
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    _sleep(param_1,0);
  }
  _splx(puVar1);
  if (_iom != 0) {
    _bp_iom_map(param_2,puVar2,param_3,param_1);
  }
  uVar6 = (int)puVar2 << 0xc | uVar5;
  *(uint *)((int)register0x00000038 + -0xc) = uVar6;
locret_F009A258:
  return CONCAT44(param_2,uVar6);
}
