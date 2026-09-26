
/* WARNING: Removing unreachable block (ram,0xf00984bc) */
/* WARNING: Removing unreachable block (ram,0xf009841c) */
/* WARNING: Removing unreachable block (ram,0xf00983e4) */
/* WARNING: Removing unreachable block (ram,0xf00983a8) */
/* WARNING: Removing unreachable block (ram,0xf00983a0) */
/* WARNING: Removing unreachable block (ram,0xf00983d0) */
/* WARNING: Removing unreachable block (ram,0xf00983fc) */
/* WARNING: Removing unreachable block (ram,0xf0098478) */
/* WARNING: Removing unreachable block (ram,0xf0098508) */
/* WARNING: Removing unreachable block (ram,0xf009836c) */

undefined8 sub_F0098348(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined6 *puVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined6 **ppuVar5;
  undefined4 unaff_l3;
  undefined4 *puVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar7;
  undefined4 unaff_i2;
  int iVar8;
  int iVar9;
  undefined4 unaff_i3;
  undefined4 uVar10;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar11;
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
  ppuVar5 = &off_F0112DF4;
  puVar6 = (undefined4 *)((int)register0x00000038 + -0x188);
  bVar1 = true;
  puVar2 = off_F0112DF4;
  while (puVar2 != (undefined6 *)0x0) {
    puVar2 = *ppuVar5;
    _strcmp(puVar2,param_4);
    if (puVar2 == (undefined6 *)0x0) {
      piVar3 = param_1;
      _prom_getproplen(param_1,&_psreg);
      udiv();
      if (_debug_fillsysinfo != 0) {
        _prom_printf(aNregForSIsD,param_4,piVar3);
      }
      _prom_getprop(param_1,&_psreg,(undefined *)((int)register0x00000038 + -0x188));
      _apply_range_to_reg(param_4,param_2,param_3,piVar3,
                          (undefined *)((int)register0x00000038 + -0x188));
      if (_debug_fillsysinfo != 0) {
        _prom_printf(aMappingSToX,param_4,ppuVar5[1]);
      }
      iVar8 = 0;
      if (piVar3 == (int *)0x0) goto loc_F009852C;
      param_1 = (int *)((int)register0x00000038 + -0x180);
      goto loc_F0098440;
    }
    ppuVar5 = ppuVar5 + 3;
    puVar2 = *ppuVar5;
  }
  goto locret_F0098538;
loc_F0098440:
  do {
    param_2 = param_1[-1];
    uVar10 = *puVar6;
    iVar4 = (*param_1 - 1U >> 0xc) + 1;
    if ((_small_4m != 0) && (bVar1)) {
      puVar2 = *ppuVar5;
      _strcmp(puVar2,&aCounter);
      if ((puVar2 == (undefined6 *)0x0) && (*param_1 != 0x4000)) {
        iVar4 = 4;
      }
    }
    if (_small_4m == 0) {
loc_F00984E0:
      bVar11 = iVar4 == 0;
    }
    else {
      bVar11 = iVar4 == 0;
      if (bVar1) {
        puVar2 = *ppuVar5;
        _strcmp(puVar2,aInterrupt);
        bVar11 = iVar4 == 0;
        if (puVar2 == (undefined6 *)0x0) {
          if (*param_1 != 0x4000) {
            iVar4 = 4;
          }
          goto loc_F00984E0;
        }
      }
    }
    bVar1 = false;
    iVar7 = param_2;
    iVar9 = iVar8;
    if (!bVar11) {
      do {
        param_2 = iVar7 + 0x1000;
        iVar8 = iVar9 + 1;
        _prom_map(ppuVar5[1] + iVar9 * 0x200,uVar10,iVar7,0x1000);
        iVar4 = iVar4 + -1;
        iVar7 = param_2;
        iVar9 = iVar8;
      } while (iVar4 != 0);
    }
    param_1 = param_1 + 3;
    piVar3 = (int *)((int)piVar3 + -1);
    puVar6 = puVar6 + 3;
  } while (piVar3 != (int *)0x0);
loc_F009852C:
  *(word *)((int)ppuVar5 + 10) = *(word *)((int)ppuVar5 + 10) | 2;
locret_F0098538:
  return CONCAT44(param_2,param_1);
}

