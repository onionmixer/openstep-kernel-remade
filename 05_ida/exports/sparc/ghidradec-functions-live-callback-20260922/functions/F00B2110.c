
/* WARNING: Removing unreachable block (ram,0xf00b224c) */
/* WARNING: Removing unreachable block (ram,0xf00b223c) */
/* WARNING: Removing unreachable block (ram,0xf00b2154) */
/* WARNING: Removing unreachable block (ram,0xf00b21c8) */
/* WARNING: Removing unreachable block (ram,0xf00b2244) */
/* WARNING: Removing unreachable block (ram,0xf00b21e8) */
/* WARNING: Removing unreachable block (ram,0xf00b2130) */

undefined8 _dmaattach(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  if (_dma_map == 0) {
    iVar2 = _ndma_map << 4;
    _kalloc();
    _dma_map = iVar2;
    if (iVar2 != 0) {
      _bzero();
      goto loc_F00B2160;
    }
    iVar5 = *(int *)(param_1 + 0x2c);
    puVar3 = aDmaDNoSpaceFor;
  }
  else {
loc_F00B2160:
    iVar5 = (int)DAT_f011d214._0_1_;
    bVar1 = iVar5 < _ndma_map;
    DAT_f011d214._0_1_ = DAT_f011d214._0_1_ + '\x01';
    *(int *)(param_1 + 0x2c) = iVar5;
    iVar2 = _dma_map;
    if (bVar1) {
      iVar7 = _dma_map + iVar5 * 0x10;
      if (*(int *)(param_1 + 0x10) < 3) {
        puVar6 = *(undefined4 **)(param_1 + 0x14);
        iVar4 = puVar6[1];
        _map_regs(iVar4,puVar6[2],*puVar6);
        *(int *)(iVar2 + iVar5 * 0x10) = iVar4;
        if (iVar4 != 0) {
          *(undefined4 *)(iVar7 + 4) = **(undefined4 **)(param_1 + 0x14);
          *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 4);
          *(undefined *)(iVar7 + 0xc) = 1;
          if (*(int *)(param_1 + 0x18) != 0) {
            _addintr(**(undefined4 **)(param_1 + 0x1c),_dmaintr,*(undefined4 *)(param_1 + 0xc),
                     *(undefined4 *)(param_1 + 0x2c),0,0);
          }
          _report_dev(param_1);
          _attach_devs(param_1);
          uVar8 = 0;
          goto locret_F00B2258;
        }
        iVar5 = *(int *)(param_1 + 0x2c);
        puVar3 = aDmaDUnableToMa;
      }
      else {
        puVar3 = aDmaDBadRegiste;
      }
    }
    else {
      puVar3 = aDmaDBadUnitNum;
    }
  }
  uVar8 = 0xffffffff;
  _printf(puVar3,iVar5);
locret_F00B2258:
  return CONCAT44(param_2,uVar8);
}

