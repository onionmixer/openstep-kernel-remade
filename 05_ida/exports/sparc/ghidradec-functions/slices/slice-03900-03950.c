/* GHIDRADEC_FUNCTION index=3900 start=0xf00981d0 */

/* WARNING: Removing unreachable block (ram,0xf0098324) */
/* WARNING: Removing unreachable block (ram,0xf009828c) */
/* WARNING: Removing unreachable block (ram,0xf0098254) */
/* WARNING: Removing unreachable block (ram,0xf0098240) */
/* WARNING: Removing unreachable block (ram,0xf0098224) */
/* WARNING: Removing unreachable block (ram,0xf009824c) */
/* WARNING: Removing unreachable block (ram,0xf0098274) */
/* WARNING: Removing unreachable block (ram,0xf009829c) */
/* WARNING: Removing unreachable block (ram,0xf009832c) */
/* WARNING: Removing unreachable block (ram,0xf00981d4) */

undefined8 sub_F00981D0(int param_1,int param_2,undefined *param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar6;
  undefined *puVar7;
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
  undefined auStack_30 [48];
  
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
  iVar2 = param_1;
  _prom_childnode();
  puVar6 = (undefined *)((int)register0x00000038 + -0x30);
  if (iVar2 != 0) {
    puVar7 = (undefined *)((int)register0x00000038 + -0xd0);
    do {
      puVar4 = (undefined *)((int)register0x00000038 + -0x30);
      iVar3 = 0x27;
      do {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
        bVar1 = 0 < iVar3;
        iVar3 = iVar3 + -1;
      } while (bVar1);
      iVar3 = iVar2;
      _prom_getprop(iVar2,&_psname,puVar6);
      if (iVar3 != -1) {
        sub_F0098348(iVar2,param_2,param_3,puVar6);
      }
      param_1 = iVar2;
      _prom_getproplen(iVar2,&_psrange);
      .udiv();
      iVar3 = param_2;
      puVar4 = param_3;
      if (param_1 - 1U < 7) {
        _prom_getprop(iVar2,&_psrange,puVar7);
        _apply_range_to_range(puVar6,param_2,param_3,param_1,puVar7);
        puVar4 = puVar6;
        _strcmp(puVar6,&aSbus);
        if ((puVar4 == (undefined *)0x0) && (iVar3 = 0, _sbus_numslots = param_1, 0 < param_1)) {
          iVar5 = 0;
          puVar4 = puVar7;
          do {
            iVar3 = iVar3 + 1;
            *(uint *)(_sbus_basepage + iVar5) =
                 *(int *)(puVar4 + 8) << 0x14 | *(uint *)((int)register0x00000038 + -0xc4) >> 0xc;
            *(undefined4 *)(_sbus_slotsize + iVar5) = *(undefined4 *)(puVar4 + 0x10);
            puVar4 = puVar4 + 0x14;
            iVar5 = iVar5 + 4;
          } while (iVar3 < param_1);
        }
        iVar3 = param_1;
        puVar4 = (undefined *)((int)register0x00000038 + -0xd0);
      }
      sub_F00981D0(iVar2,iVar3,puVar4);
      _prom_nextnode();
    } while (iVar2 != 0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3901 start=0xf0098348 */

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
      .udiv();
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
/* GHIDRADEC_FUNCTION index=3902 start=0xf009921c */

/* WARNING: Removing unreachable block (ram,0xf0099254) */
/* WARNING: Removing unreachable block (ram,0xf0099260) */
/* WARNING: Removing unreachable block (ram,0xf0099238) */

undefined8 sub_F009921C(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = param_2;
  }
  else {
    _strcmp(iVar1,param_2);
    if (iVar1 != 0) {
      _printf(aAddionameCanTC,*(undefined4 *)(param_1 + 8),param_2);
      _panic(aAddioname);
    }
  }
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3903 start=0xf0099fc8 */

/* WARNING: Removing unreachable block (ram,0xf0099fe8) */
/* WARNING: Removing unreachable block (ram,0xf0099fcc) */

undefined8 sub_F0099FC8(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _printf(param_1);
  if (_prettyShutdown != 0) {
    _kmGraphicPanelString(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3904 start=0xf009a388 */

/* WARNING: Removing unreachable block (ram,0xf009a450) */
/* WARNING: Removing unreachable block (ram,0xf009a3e8) */

undefined8 sub_F009A388(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
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
  puVar6 = (undefined4 *)0x0;
  if (dword_F0131558 == (undefined4 *)0x0) {
loc_F009A3C0:
    if (dword_F0131554 == (undefined4 *)0x0) {
      if (dword_F0131558 != (undefined4 *)0x0) {
        _panic(aMbqStoreTooMan);
      }
      iVar1 = 8;
      iVar4 = -0xfecead4;
      iVar3 = 0x80;
      do {
        *(int *)(unk_F013149C + iVar3) = iVar4;
        iVar4 = iVar4 + -0x10;
        iVar1 = iVar1 + -1;
        iVar3 = iVar3 + -0x10;
      } while (-1 < iVar1);
      puVar2 = unk_F013149C;
      DAT_f01314a0._0_4_ = param_1;
    }
    else {
      dword_F0131554[1] = param_1;
      puVar2 = (undefined *)dword_F0131554;
    }
    *(undefined4 *)((int)puVar2 + 8) = param_2;
    *(int *)((int)puVar2 + 0xc) = param_3;
    dword_F0131554 = *(undefined4 **)puVar2;
    if (param_3 == 0) {
      _printf(aWarningMbCallb);
    }
    if (puVar6 == (undefined4 *)0x0) {
      *(undefined4 **)puVar2 = dword_F0131558;
      dword_F0131558 = (undefined4 *)puVar2;
    }
    else {
      *(undefined4 *)puVar2 = 0;
      *puVar6 = puVar2;
    }
    dword_F013153C = dword_F013153C + 1;
    dword_F0131550 = dword_F0131550 + 1;
    iVar1 = dword_F0131550;
    if (dword_F0131550 < (int)DAT_f0131540._8_4_) {
      iVar1 = DAT_f0131540._8_4_;
    }
  }
  else {
    iVar1 = dword_F0131558[1];
    puVar6 = dword_F0131558;
    while (iVar1 != param_1) {
      puVar5 = (undefined4 *)*puVar6;
      if (puVar5 == (undefined4 *)0x0) goto loc_F009A3C0;
      puVar6 = puVar5;
      iVar1 = puVar5[1];
    }
    DAT_f0131540._0_4_ = DAT_f0131540._0_4_ + 1;
    iVar1 = DAT_f0131540._8_4_;
  }
  DAT_f0131540._8_4_ = iVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3905 start=0xf009a4d4 */

/* WARNING: Removing unreachable block (ram,0xf009a5ac) */

undefined8 sub_F009A4D4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
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
  puVar6 = (undefined4 *)0x0;
  if (dword_F0131558 != (undefined4 *)0x0) {
    iVar2 = 0;
    iVar1 = dword_F0131558[3];
    puVar4 = dword_F0131558;
    while( true ) {
      if (iVar1 < param_1) {
        puVar5 = (undefined4 *)*puVar4;
        puVar6 = puVar4;
      }
      else {
        pcVar3 = (code *)puVar4[1];
        iVar2 = puVar4[2];
        if (puVar6 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)*puVar4;
          dword_F0131558 = puVar5;
          *puVar4 = dword_F0131554;
        }
        else {
          *puVar6 = *puVar4;
          *puVar4 = dword_F0131554;
          puVar5 = (undefined4 *)*puVar6;
        }
        dword_F0131550 = dword_F0131550 + -1;
        dword_F0131554 = puVar4;
        (*pcVar3)();
        if (iVar2 == -1) goto locret_F009A5B4;
      }
      if (puVar5 == (undefined4 *)0x0) break;
      iVar1 = puVar5[3];
      puVar4 = puVar5;
    }
    if ((iVar2 != -1) && (dword_F0131558 != (undefined4 *)0x0)) {
      _softcall(sub_F009A5BC,0);
    }
  }
locret_F009A5B4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3906 start=0xf009a5bc */

/* WARNING: Removing unreachable block (ram,0xf009a5e0) */
/* WARNING: Removing unreachable block (ram,0xf009a5e8) */
/* WARNING: Removing unreachable block (ram,0xf009a5c0) */

undefined8 sub_F009A5BC(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = param_1;
  _splvm();
  DAT_f013154c = DAT_f013154c + 1;
  sub_F009A4D4(0);
  _splx(uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3907 start=0xf00a3740 */

/* WARNING: Removing unreachable block (ram,0xf00a376c) */
/* WARNING: Removing unreachable block (ram,0xf00a3764) */

undefined8 sub_F00A3740(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (param_1 != 0x72) {
    if (param_1 == 0x80) {
      _p4m35_sys_setfunc();
    }
    _init_all_fsr();
    return CONCAT44(param_2,param_1);
  }
  _p4m50_sys_setfunc();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3908 start=0xf00a377c */

/* WARNING: Removing unreachable block (ram,0xf00a3784) */

undefined8 sub_F00A377C(undefined4 param_1,undefined4 param_2)

{
  undefined7 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  puVar1 = &aText;
  _getsegbyname();
  return CONCAT44(param_2,*(int *)(puVar1 + 3) + *(int *)((int)puVar1 + 0x1c));
}
/* GHIDRADEC_FUNCTION index=3909 start=0xf00a379c */

/* WARNING: Removing unreachable block (ram,0xf00a37d8) */
/* WARNING: Removing unreachable block (ram,0xf00a37b8) */
/* WARNING: Removing unreachable block (ram,0xf00a37e4) */
/* WARNING: Removing unreachable block (ram,0xf00a37a4) */

undefined8 sub_F00A379C(undefined4 param_1,undefined4 param_2)

{
  undefined7 *puVar1;
  undefined7 *puVar2;
  undefined7 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  puVar1 = &aData_2;
  _getsegbyname();
  if (puVar1 != (undefined7 *)0x0) {
    puVar2 = puVar1;
    _firstsect();
    while (puVar2 != (undefined7 *)0x0) {
      if ((*(uint *)(puVar2 + 7) & 1) != 0) {
        _bzero(*(undefined4 *)(puVar2 + 4),*(undefined4 *)((int)puVar2 + 0x24));
      }
      puVar3 = puVar1;
      _nextsect(puVar1,puVar2);
      puVar2 = puVar3;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3910 start=0xf00a3804 */

/* WARNING: Removing unreachable block (ram,0xf00a3808) */

undefined8 sub_F00A3804(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _fpu_probe();
  _machine_slot = 1;
  dword_F013476C = 1;
  dword_F0134764 = 0xe;
  dword_F0134768 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3911 start=0xf00a7380 */

/* WARNING: Removing unreachable block (ram,0xf00a73f4) */
/* WARNING: Removing unreachable block (ram,0xf00a73d4) */
/* WARNING: Removing unreachable block (ram,0xf00a7424) */
/* WARNING: Removing unreachable block (ram,0xf00a7390) */

undefined8 sub_F00A7380(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined (*pauVar2) [9];
  undefined (*pauVar3) [12];
  undefined *puVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined *puVar7;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  undefined (*pauVar9) [9];
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
  pauVar2 = paScsidisk_0;
  _objc_msgSend(paScsidisk_0,paRequiredprotoc);
  uVar8 = 1;
  if ((pauVar2 != (undefined (*) [9])0x0) && (iVar6 = 0, *(int *)*pauVar2 != 0)) {
    puVar7 = (undefined *)((int)register0x00000038 + -0x58);
    do {
      while( true ) {
        pauVar3 = paIodevice_0;
        _objc_msgSend(paIodevice_0,paLookupbyobject_0,iVar6,
                      (undefined *)((int)register0x00000038 + -0xa8),puVar7);
        if ((pauVar3 != (undefined (*) [12])0x0) &&
           (uVar8 = 0, pauVar3 != (undefined (*) [12])0xfffffd29)) goto locret_F00A7468;
        puVar4 = puVar7;
        _IOGetObjectForDeviceName(puVar7,(undefined *)((int)register0x00000038 + -0xac));
        if (puVar4 == (undefined *)0x0) break;
        iVar6 = iVar6 + 1;
      }
      bVar1 = true;
      if (*(int *)*pauVar2 != 0) {
        uVar5 = *(uint *)((int)register0x00000038 + -0xac);
        pauVar9 = pauVar2;
        do {
          _objc_msgSend(uVar5,paConformsto,*(undefined4 *)*pauVar9);
          pauVar9 = (undefined (*) [9])(*pauVar9 + 4);
          if ((uVar5 & 0xff) == 0) {
            bVar1 = false;
            break;
          }
          uVar5 = *(uint *)((int)register0x00000038 + -0xac);
        } while (*(int *)*pauVar9 != 0);
      }
      iVar6 = iVar6 + 1;
    } while (!bVar1);
    uVar8 = 1;
  }
locret_F00A7468:
  return CONCAT44(param_2,uVar8);
}
/* GHIDRADEC_FUNCTION index=3912 start=0xf00a96f0 */

/* WARNING: Removing unreachable block (ram,0xf00a972c) */
/* WARNING: Removing unreachable block (ram,0xf00a9718) */

undefined8 sub_F00A96F0(int param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  if (param_3 == 0) {
    *param_4 = 0;
  }
  else if (param_3 < 0x10) {
    *param_4 = *(int *)(param_1 + param_3 * 4);
  }
  else {
    param_2 = param_2 + param_3 * 4 + -0x40;
    iVar1 = param_2;
    _fuword();
    *param_4 = iVar1;
    if (iVar1 == -1) {
      iVar1 = param_2;
      _fubyte();
      uVar2 = 0;
      if (iVar1 == -1) {
        uVar2 = 0xffffffff;
      }
      goto locret_F00A9754;
    }
  }
  uVar2 = 0;
locret_F00A9754:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3913 start=0xf00a975c */

/* WARNING: Removing unreachable block (ram,0xf00a977c) */

undefined8 sub_F00A975C(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_4 != 0) {
    if (param_4 < 0x10) {
      *(undefined4 *)(param_2 + param_4 * 4) = param_1;
    }
    else {
      param_3 = param_3 + param_4 * 4 + -0x40;
      _suword();
      uVar1 = 0xffffffff;
      if (param_3 != 0) goto locret_F00A979C;
    }
  }
  uVar1 = 0;
locret_F00A979C:
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3914 start=0xf00a9fdc */

/* WARNING: Removing unreachable block (ram,0xf00aa02c) */
/* WARNING: Removing unreachable block (ram,0xf00aa018) */

undefined8 sub_F00A9FDC(int param_1,int param_2,uint param_3,int *param_4,int param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  if (param_3 == 0) {
    *param_4 = 0;
  }
  else {
    iVar1 = param_3 * 4;
    if (param_3 < 0x10) {
      iVar1 = *(int *)(param_1 + iVar1);
    }
    else {
      if (param_5 == 0) {
        param_2 = param_2 + iVar1 + -0x40;
        iVar1 = param_2;
        _fuword();
        *param_4 = iVar1;
        if (iVar1 == -1) {
          iVar1 = param_2;
          _fubyte();
          uVar2 = 0;
          if (iVar1 == -1) {
            uVar2 = 0xffffffff;
          }
          goto locret_F00AA058;
        }
        goto loc_F00AA054;
      }
      iVar1 = *(int *)(iVar1 + param_2 + -0x40);
    }
    *param_4 = iVar1;
  }
loc_F00AA054:
  uVar2 = 0;
locret_F00AA058:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3915 start=0xf00ab068 */

/* WARNING: Removing unreachable block (ram,0xf00ab1dc) */
/* WARNING: Removing unreachable block (ram,0xf00ab1b4) */
/* WARNING: Removing unreachable block (ram,0xf00ab1a0) */
/* WARNING: Removing unreachable block (ram,0xf00ab1c8) */
/* WARNING: Removing unreachable block (ram,0xf00ab1fc) */
/* WARNING: Removing unreachable block (ram,0xf00ab17c) */

undefined8
sub_F00AB068(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 *puVar6;
  undefined4 *puVar7;
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
  if ((int)param_2[1] < (int)param_3[1]) {
    uVar1 = param_3[1];
    puVar6 = param_3;
  }
  else {
    uVar1 = param_2[1];
    puVar6 = param_2;
    param_2 = param_3;
  }
  puVar7 = puVar6;
  if (uVar1 == 2) {
    uVar2 = *puVar6;
  }
  else if (uVar1 < 3) {
    if (uVar1 == 0) {
      uVar2 = *puVar6;
    }
    else {
      iVar3 = param_2[1];
loc_F00AB0CC:
      if (iVar3 != 0) {
        if ((int)puVar6[2] < (int)param_2[2]) {
          uVar2 = param_2[1];
          puVar7 = param_2;
        }
        else {
          uVar2 = puVar6[1];
          puVar6 = param_2;
        }
        param_4[1] = uVar2;
        *param_4 = *puVar7;
        param_4[2] = puVar7[2];
        param_4[8] = 0;
        param_4[7] = 0;
        if (puVar7[2] == puVar6[2]) {
          uVar2 = puVar7[6];
        }
        else {
          _fpu_rightshift(puVar6,param_4[2] - puVar6[2]);
          param_4[7] = puVar6[7];
          param_4[8] = puVar6[8];
          uVar2 = puVar7[6];
        }
        puVar4 = param_4 + 6;
        _fpu_add3wc(puVar4,uVar2,puVar6[6],0);
        puVar5 = param_4 + 5;
        _fpu_add3wc(puVar5,puVar7[5],puVar6[5],puVar4);
        puVar4 = param_4 + 4;
        _fpu_add3wc(puVar4,puVar7[4],puVar6[4],puVar5);
        _fpu_add3wc(param_4 + 3,puVar7[3],puVar6[3],puVar4);
        if (0x1ffff < (uint)param_4[3]) {
          _fpu_rightshift(param_4,1);
          param_4[2] = param_4[2] + 1;
        }
        goto locret_F00AB210;
      }
      uVar2 = *puVar6;
    }
  }
  else {
    if ((5 < uVar1) || (uVar1 < 4)) {
      iVar3 = param_2[1];
      goto loc_F00AB0CC;
    }
    uVar2 = *puVar6;
  }
  *param_4 = uVar2;
  param_4[1] = puVar6[1];
  param_4[2] = puVar6[2];
  param_4[3] = puVar6[3];
  param_4[4] = puVar6[4];
  param_4[5] = puVar6[5];
  param_4[6] = puVar6[6];
  param_4[7] = puVar6[7];
  param_4[8] = puVar6[8];
locret_F00AB210:
  return CONCAT44(puVar7,param_1);
}
/* GHIDRADEC_FUNCTION index=3916 start=0xf00ab218 */

/* WARNING: Removing unreachable block (ram,0xf00ab454) */
/* WARNING: Removing unreachable block (ram,0xf00ab42c) */
/* WARNING: Removing unreachable block (ram,0xf00ab3b4) */
/* WARNING: Removing unreachable block (ram,0xf00ab388) */
/* WARNING: Removing unreachable block (ram,0xf00ab500) */
/* WARNING: Removing unreachable block (ram,0xf00ab4d8) */
/* WARNING: Removing unreachable block (ram,0xf00ab480) */
/* WARNING: Removing unreachable block (ram,0xf00ab46c) */
/* WARNING: Removing unreachable block (ram,0xf00ab4c4) */
/* WARNING: Removing unreachable block (ram,0xf00ab4ec) */
/* WARNING: Removing unreachable block (ram,0xf00ab370) */
/* WARNING: Removing unreachable block (ram,0xf00ab3a0) */
/* WARNING: Removing unreachable block (ram,0xf00ab418) */
/* WARNING: Removing unreachable block (ram,0xf00ab440) */
/* WARNING: Removing unreachable block (ram,0xf00ab59c) */
/* WARNING: Removing unreachable block (ram,0xf00ab2d4) */

undefined8 sub_F00AB218(uint param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint *puVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint *puVar9;
  uint *puVar10;
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
  if ((int)param_2[1] < (int)param_3[1]) {
    uVar1 = *param_3;
    puVar10 = param_3;
  }
  else {
    uVar1 = *param_2;
    puVar10 = param_2;
    param_2 = param_3;
  }
  *param_4 = uVar1;
  param_4[1] = puVar10[1];
  param_4[2] = puVar10[2];
  param_4[3] = puVar10[3];
  param_4[4] = puVar10[4];
  param_4[5] = puVar10[5];
  param_4[6] = puVar10[6];
  uVar1 = param_4[1];
  param_4[7] = puVar10[7];
  param_4[8] = puVar10[8];
  if (uVar1 == 2) {
    if (param_2[1] == 2) {
      _fpu_error_nan(param_1,param_4);
      param_4[1] = 4;
    }
  }
  else {
    if (uVar1 < 3) {
      if (uVar1 == 0) {
        *param_4 = (uint)(*(int *)(param_1 + 4) == 3);
        goto locret_F00AB5A4;
      }
      uVar1 = param_2[1];
    }
    else if (uVar1 < 6) {
      if (3 < uVar1) goto locret_F00AB5A4;
      uVar1 = param_2[1];
    }
    else {
      uVar1 = param_2[1];
    }
    if (uVar1 != 0) {
      if ((int)puVar10[2] < (int)param_2[2]) {
        uVar1 = param_2[1];
        puVar9 = param_2;
      }
      else {
        uVar1 = puVar10[1];
        puVar9 = puVar10;
        puVar10 = param_2;
      }
      param_4[1] = uVar1;
      *param_4 = *puVar9;
      param_4[2] = puVar9[2];
      param_4[7] = 0;
      param_4[8] = 0;
      puVar8 = param_4 + 3;
      if (puVar9[2] == puVar10[2]) {
        puVar2 = param_4 + 6;
        puVar5 = puVar2;
        _fpu_sub3wc(puVar2,puVar9[6],puVar10[6],0);
        puVar3 = param_4 + 5;
        puVar6 = puVar3;
        _fpu_sub3wc(puVar3,puVar9[5],puVar10[5],puVar5);
        puVar4 = param_4 + 4;
        puVar5 = puVar4;
        _fpu_sub3wc(puVar4,puVar9[4],puVar10[4],puVar6);
        _fpu_sub3wc(puVar8,puVar9[3],puVar10[3],puVar5);
        if (((param_4[3] == 0 && param_4[4] == 0) && param_4[5] == 0) && param_4[6] == 0) {
          *param_4 = (uint)(*(int *)(param_1 + 4) == 3);
          param_4[1] = 0;
          puVar10 = puVar9;
          goto locret_F00AB5A4;
        }
        if (0x1ffff < param_4[3]) {
          *param_4 = *puVar10;
          _fpu_neg2wc(puVar2,param_4[6],0);
          _fpu_neg2wc(puVar3,param_4[5],puVar2);
          _fpu_neg2wc(puVar4,param_4[4],puVar3);
          _fpu_neg2wc(puVar8,param_4[3],puVar4);
        }
      }
      else {
        _fpu_rightshift(puVar10,(param_4[2] - puVar10[2]) + -1);
        param_1 = puVar10[7];
        uVar7 = puVar10[8];
        _fpu_rightshift(puVar10,1);
        uVar1 = puVar10[7];
        if (uVar7 != 0) {
          param_1 = (uint)(param_1 == 0);
        }
        if ((param_1 | uVar7) != 0) {
          uVar1 = (uint)(uVar1 == 0);
        }
        puVar5 = param_4 + 6;
        _fpu_sub3wc(puVar5,puVar9[6],puVar10[6],(uVar1 != 0 || param_1 != 0) || uVar7 != 0);
        puVar6 = param_4 + 5;
        _fpu_sub3wc(puVar6,puVar9[5],puVar10[5],puVar5);
        puVar5 = param_4 + 4;
        _fpu_sub3wc(puVar5,puVar9[4],puVar10[4],puVar6);
        _fpu_sub3wc(puVar8,puVar9[3],puVar10[3],puVar5);
        if (0xffff < param_4[3]) {
          param_4[8] = param_1 | uVar7;
          param_4[7] = uVar1;
          puVar10 = puVar9;
          goto locret_F00AB5A4;
        }
        param_4[8] = uVar7;
        param_4[7] = param_1;
        param_4[3] = param_4[3] << 1 | param_4[4] >> 0x1f;
        param_4[4] = param_4[4] << 1 | param_4[5] >> 0x1f;
        param_4[5] = param_4[5] << 1 | param_4[6] >> 0x1f;
        param_4[6] = param_4[6] << 1 | uVar1;
        param_4[2] = param_4[2] - 1;
        puVar10 = puVar9;
        if (0xffff < param_4[3]) goto locret_F00AB5A4;
      }
      _fpu_normalize(param_4);
      puVar10 = puVar9;
    }
  }
locret_F00AB5A4:
  return CONCAT44(puVar10,param_1);
}
/* GHIDRADEC_FUNCTION index=3917 start=0xf00ac318 */

/* WARNING: Removing unreachable block (ram,0xf00ac464) */
/* WARNING: Removing unreachable block (ram,0xf00ac4c0) */
/* WARNING: Removing unreachable block (ram,0xf00ac7a4) */
/* WARNING: Removing unreachable block (ram,0xf00ac77c) */
/* WARNING: Removing unreachable block (ram,0xf00ac51c) */
/* WARNING: Removing unreachable block (ram,0xf00ac588) */
/* WARNING: Removing unreachable block (ram,0xf00ac558) */
/* WARNING: Removing unreachable block (ram,0xf00ac5c4) */
/* WARNING: Removing unreachable block (ram,0xf00ac698) */
/* WARNING: Removing unreachable block (ram,0xf00ac668) */
/* WARNING: Removing unreachable block (ram,0xf00ac6d4) */
/* WARNING: Removing unreachable block (ram,0xf00ac71c) */
/* WARNING: Removing unreachable block (ram,0xf00ac644) */
/* WARNING: Removing unreachable block (ram,0xf00ac618) */
/* WARNING: Removing unreachable block (ram,0xf00ac81c) */
/* WARNING: Removing unreachable block (ram,0xf00ac854) */
/* WARNING: Removing unreachable block (ram,0xf00ac88c) */
/* WARNING: Removing unreachable block (ram,0xf00ac7e4) */
/* WARNING: Removing unreachable block (ram,0xf00ac878) */
/* WARNING: Removing unreachable block (ram,0xf00ac840) */
/* WARNING: Removing unreachable block (ram,0xf00ac808) */
/* WARNING: Removing unreachable block (ram,0xf00ac600) */
/* WARNING: Removing unreachable block (ram,0xf00ac630) */
/* WARNING: Removing unreachable block (ram,0xf00ac704) */
/* WARNING: Removing unreachable block (ram,0xf00ac6bc) */
/* WARNING: Removing unreachable block (ram,0xf00ac734) */
/* WARNING: Removing unreachable block (ram,0xf00ac680) */
/* WARNING: Removing unreachable block (ram,0xf00ac5ac) */
/* WARNING: Removing unreachable block (ram,0xf00ac5dc) */
/* WARNING: Removing unreachable block (ram,0xf00ac570) */
/* WARNING: Removing unreachable block (ram,0xf00ac504) */
/* WARNING: Removing unreachable block (ram,0xf00ac534) */
/* WARNING: Removing unreachable block (ram,0xf00ac790) */
/* WARNING: Removing unreachable block (ram,0xf00ac490) */
/* WARNING: Removing unreachable block (ram,0xf00ac4e0) */
/* WARNING: Removing unreachable block (ram,0xf00ac474) */
/* WARNING: Removing unreachable block (ram,0xf00ac7c8) */

qword sub_F00AC318(uint *param_1,uint *param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  uint uVar5;
  undefined4 unaff_l4;
  uint uVar6;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  undefined4 unaff_i1;
  uint uVar8;
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
  uVar3 = *param_2;
  uVar6 = *param_3;
  uVar2 = uVar3 >> 0xe & 0x1f;
  uVar5 = uVar3 >> 0x19 & 0x1f;
  param_1[3] = 0;
  *param_1 = uVar6 >> 0x17 & 0x1f;
  param_1[1] = uVar6 >> 0x1e;
  param_1[2] = uVar6 >> 0x1c & 3;
  uVar8 = uVar3 & 0x1f;
  switch(uVar3 >> 7 & 0x3f) {
  case :
    __fp_unpack_word(param_1,(undefined *)((int)register0x00000038 + -0x84),uVar8);
    __fp_pack_word(param_1,(undefined *)((int)register0x00000038 + -0x84),uVar5);
    uVar2 = param_1[3];
    break;
  case :
    __fp_unpack_word(param_1,(undefined *)((int)register0x00000038 + -0x84),uVar8);
    uVar2 = *(uint *)((int)register0x00000038 + -0x84) ^ 0x80000000;
    goto loc_F00AC4E0;
  case :
    __fp_unpack_word(param_1,(undefined *)((int)register0x00000038 + -0x84),uVar8);
    uVar2 = *(uint *)((int)register0x00000038 + -0x84) & 0x7fffffff;
loc_F00AC4E0:
    *(uint *)((int)register0x00000038 + -0x84) = uVar2;
    __fp_pack_word(param_1,(uint *)((int)register0x00000038 + -0x84),uVar5);
    uVar2 = param_1[3];
    break;
  :
    uVar7 = 3;
    goto locret_F00AC960;
  case :
    uVar4 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar8,uVar4);
    __fp_sqrt(param_1,(undefined *)((int)register0x00000038 + -0x30),
              (undefined *)((int)register0x00000038 + -0x80));
    goto loc_F00AC79C;
  case :
    uVar4 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar4);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar4);
    __fp_add(param_1,(undefined *)((int)register0x00000038 + -0x30),
             (undefined *)((int)register0x00000038 + -0x58),
             (undefined *)((int)register0x00000038 + -0x80));
    goto loc_F00AC79C;
  case :
    uVar4 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar4);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar4);
    __fp_sub(param_1,(undefined *)((int)register0x00000038 + -0x30),
             (undefined *)((int)register0x00000038 + -0x58),
             (undefined *)((int)register0x00000038 + -0x80));
    goto loc_F00AC79C;
  case :
    uVar4 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar4);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar4);
    __fp_mul(param_1,(undefined *)((int)register0x00000038 + -0x30),
             (undefined *)((int)register0x00000038 + -0x58),
             (undefined *)((int)register0x00000038 + -0x80));
    goto loc_F00AC79C;
  case :
    uVar4 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar4);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar4);
    __fp_div(param_1,(undefined *)((int)register0x00000038 + -0x30),
             (undefined *)((int)register0x00000038 + -0x58),
             (undefined *)((int)register0x00000038 + -0x80));
loc_F00AC79C:
    __fp_pack(param_1,(undefined *)((int)register0x00000038 + -0x80),uVar5,uVar4);
    uVar2 = param_1[3];
    break;
  case :
    uVar5 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar5);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar5);
    uVar7 = 0;
    goto loc_F00AC734;
  case :
    uVar5 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar5);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar5);
    uVar7 = 1;
loc_F00AC734:
    puVar1 = param_1;
    __fp_compare(param_1,(undefined *)((int)register0x00000038 + -0x30),
                 (undefined *)((int)register0x00000038 + -0x58),uVar7);
    if ((param_1[3] & *param_1) == 0) {
      uVar6 = uVar6 & 0xfffff3ff | ((uint)puVar1 & 3) << 10;
      uVar2 = param_1[3];
    }
    else {
      uVar2 = param_1[3];
    }
    break;
  case :
  case :
    uVar4 = uVar3 >> 5 & 3;
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar2,uVar4);
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x58),uVar8,uVar4);
    __fp_mul(param_1,(undefined *)((int)register0x00000038 + -0x30),
             (undefined *)((int)register0x00000038 + -0x58),
             (undefined *)((int)register0x00000038 + -0x80));
    __fp_pack(param_1,(undefined *)((int)register0x00000038 + -0x80),uVar5,uVar4 + 1);
    uVar2 = param_1[3];
    break;
  case :
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar8,uVar3 >> 5 & 3);
    __fp_pack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar5,1);
    uVar2 = param_1[3];
    break;
  case :
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar8,uVar3 >> 5 & 3);
    __fp_pack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar5,2);
    uVar2 = param_1[3];
    break;
  case :
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar8,uVar3 >> 5 & 3);
    __fp_pack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar5,3);
    uVar2 = param_1[3];
    break;
  case :
    __fp_unpack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar8,uVar3 >> 5 & 3);
    param_1[1] = 1;
    __fp_pack(param_1,(undefined *)((int)register0x00000038 + -0x30),uVar5,0);
    uVar2 = param_1[3];
  }
  uVar5 = uVar6 & 0xffffffe0 | uVar2 & 0x1f;
  if (uVar2 != 0) {
    uVar8 = uVar2 & uVar6 >> 0x17 & 0x1f;
    if (uVar8 != 0) {
      if ((uVar8 & 0x10) == 0) {
        if ((uVar8 & 8) == 0) {
          if ((uVar8 & 4) == 0) {
            if ((uVar8 & 2) == 0) {
              if ((uVar8 & 1) == 0) {
                param_1[7] = 0;
              }
              else {
                param_1[7] = 0x607;
              }
            }
            else {
              param_1[7] = 0x608;
            }
          }
          else {
            param_1[7] = 0x609;
          }
        }
        else {
          param_1[7] = 0x60b;
        }
      }
      else {
        param_1[7] = 0x60a;
      }
      *param_3 = uVar5;
      uVar7 = 1;
      goto locret_F00AC960;
    }
    uVar5 = uVar6 & 0xfffffc00 | uVar2 & 0x1f | ((uVar2 | uVar6 >> 5) & 0x1f) << 5;
  }
  *param_3 = uVar5;
  uVar7 = 0;
locret_F00AC960:
  return CONCAT44(uVar3,uVar7) & 0x1fffffffff;
}
/* GHIDRADEC_FUNCTION index=3918 start=0xf00acb40 */

sqword sub_F00ACB40(uint *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint unaff_g3;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar4;
  undefined4 unaff_i3;
  uint uVar5;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
  bool bVar7;
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
  uVar3 = *param_1;
  uVar4 = *(uint *)(param_3 + 0x80) >> 10 & 3;
  uVar5 = uVar3 >> 0x19 & 0xf;
  switch(uVar5) {
  case :
    unaff_g3 = 0;
    break;
  case :
    unaff_g3 = (uint)(uVar4 != 0);
    break;
  case :
    uVar4 = uVar4 - 1;
    goto loc_F00ACC20;
  case :
    if (uVar4 == 3) goto loc_F00ACCA8;
    bVar6 = true;
    if (uVar4 == 1) {
      unaff_g3 = 1;
      break;
    }
    goto loc_F00ACCB0;
  case :
    uVar4 = uVar4 ^ 1;
    goto loc_F00ACBDC;
  case :
    uVar4 = uVar4 - 2;
loc_F00ACC20:
    bVar6 = 1 < uVar4;
    goto loc_F00ACCB0;
  case :
    uVar4 = uVar4 ^ 2;
    goto loc_F00ACBDC;
  case :
    uVar4 = uVar4 ^ 3;
loc_F00ACBDC:
    unaff_g3 = (uint)(uVar4 == 0);
    break;
  case :
    goto loc_F00ACCA8;
  case :
    unaff_g3 = (uint)(uVar4 == 0);
    break;
  case :
    iVar2 = uVar4 - 3;
    goto loc_F00ACC4C;
  case :
    iVar2 = uVar4 - 2;
loc_F00ACC4C:
    if (iVar2 == 0) {
loc_F00ACCA8:
      unaff_g3 = 1;
    }
    else {
      bVar6 = true;
      if (uVar4 != 0) goto loc_F00ACCB0;
      unaff_g3 = 1;
    }
    break;
  case :
    uVar4 = uVar4 ^ 1;
    goto loc_F00ACC9C;
  case :
    bVar6 = 1 < uVar4;
    goto loc_F00ACCB0;
  case :
    uVar4 = uVar4 ^ 2;
    goto loc_F00ACC9C;
  case :
    uVar4 = uVar4 ^ 3;
loc_F00ACC9C:
    unaff_g3 = (uint)(uVar4 != 0);
  }
  bVar6 = unaff_g3 == 0;
loc_F00ACCB0:
  bVar7 = (uVar3 >> 0x19 & 0x10) == 0;
  if (bVar6) {
    if (!bVar7) {
      *(int *)(param_2 + 4) = *(int *)(param_2 + 8) + 4;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 8;
      goto locret_F00ACD28;
    }
    iVar2 = *(int *)(param_2 + 8);
    *(int *)(param_2 + 4) = *(int *)(param_2 + 8);
loc_F00ACD20:
    iVar2 = iVar2 + 4;
  }
  else {
    iVar2 = *(int *)(param_2 + 4);
    if (bVar7) {
      uVar1 = *(undefined4 *)(param_2 + 8);
    }
    else {
      if (uVar5 == 8) {
        iVar2 = iVar2 + ((int)(uVar3 << 10) >> 8);
        *(int *)(param_2 + 4) = iVar2;
        goto loc_F00ACD20;
      }
      uVar1 = *(undefined4 *)(param_2 + 8);
    }
    *(undefined4 *)(param_2 + 4) = uVar1;
    iVar2 = iVar2 + ((int)(uVar3 << 10) >> 8);
  }
  *(int *)(param_2 + 8) = iVar2;
locret_F00ACD28:
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3919 start=0xf00acd30 */

/* WARNING: Removing unreachable block (ram,0xf00ace70) */
/* WARNING: Removing unreachable block (ram,0xf00acea8) */
/* WARNING: Removing unreachable block (ram,0xf00acf58) */
/* WARNING: Removing unreachable block (ram,0xf00acd6c) */
/* WARNING: Removing unreachable block (ram,0xf00acd90) */
/* WARNING: Removing unreachable block (ram,0xf00acf84) */
/* WARNING: Removing unreachable block (ram,0xf00aced8) */
/* WARNING: Removing unreachable block (ram,0xf00ace44) */
/* WARNING: Removing unreachable block (ram,0xf00acdc8) */

undefined8 sub_F00ACD30(int param_1,uint *param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar7;
  undefined4 unaff_i1;
  uint uVar8;
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
  uVar8 = *param_2;
  uVar3 = uVar8 >> 0xe & 0x1f;
  uVar6 = uVar8 >> 0x19;
  uVar7 = uVar8 & 0x1f;
  if ((uVar8 & 0x2000) == 0) {
    _read_iureg(uVar3,param_3,param_4,(undefined *)((int)register0x00000038 + -0xc),param_1);
    if (uVar3 != 0) {
      uVar2 = 6;
      goto locret_F00ACFC4;
    }
    _read_iureg(uVar7,param_3,param_4,(undefined *)((int)register0x00000038 + -0x10),param_1);
    uVar2 = 6;
    if (uVar7 != 0) goto locret_F00ACFC4;
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
  }
  else {
    *(int *)((int)register0x00000038 + -0xc) = (int)(uVar8 << 0x13) >> 0x13;
    _read_iureg(uVar3,param_3,param_4,(undefined *)((int)register0x00000038 + -0x10),param_1);
    uVar2 = 6;
    if (uVar3 != 0) goto locret_F00ACFC4;
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
  }
  *(int *)((int)register0x00000038 + -0xc) = iVar1 + *(int *)((int)register0x00000038 + -0x10);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)((int)register0x00000038 + -0xc);
  switch(uVar8 >> 0x13 & 7) {
  case :
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    __fp_read_word(uVar2,(undefined *)((int)register0x00000038 + -0x14),param_1);
    if (uVar2 != 0) goto locret_F00ACFC4;
    *(undefined4 *)(param_5 + (uVar6 & 0x1f) * 4) = *(undefined4 *)((int)register0x00000038 + -0x14)
    ;
    break;
  case :
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    __fp_read_word(uVar2,(undefined *)((int)register0x00000038 + -0x14),param_1);
    if (uVar2 != 0) goto locret_F00ACFC4;
    *(undefined4 *)(param_5 + 0x80) = *(undefined4 *)((int)register0x00000038 + -0x14);
    break;
  :
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_3 + 4);
    uVar2 = 3;
    goto locret_F00ACFC4;
  case :
    uVar3 = *(uint *)((int)register0x00000038 + -0xc);
    uVar2 = 5;
    if ((uVar3 & 7) != 0) goto locret_F00ACFC4;
    __fp_read_word(uVar3,(undefined *)((int)register0x00000038 + -0x14),param_1);
    uVar2 = uVar3;
    if (uVar3 != 0) goto locret_F00ACFC4;
    iVar5 = (uVar6 & 0x1e) * 4;
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    *(undefined4 *)(param_5 + iVar5) = *(undefined4 *)((int)register0x00000038 + -0x14);
    uVar2 = iVar1 + 4;
    __fp_read_word(uVar2,(undefined *)((int)register0x00000038 + -0x14),param_1);
    if (uVar2 != 0) goto locret_F00ACFC4;
    *(undefined4 *)(iVar5 + param_5 + 4) = *(undefined4 *)((int)register0x00000038 + -0x14);
    break;
  case :
    uVar3 = *(uint *)(param_5 + (uVar6 & 0x1f) * 4);
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    *(uint *)((int)register0x00000038 + -0x14) = uVar3;
    goto loc_F00ACF84;
  case :
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    uVar3 = *(uint *)(param_5 + 0x80) & 0xffcfefff | 0xe0000;
    *(uint *)((int)register0x00000038 + -0x14) = uVar3;
    goto loc_F00ACF84;
  case :
    uVar3 = *(uint *)((int)register0x00000038 + -0xc);
    uVar2 = 5;
    if ((uVar3 & 7) != 0) goto locret_F00ACFC4;
    iVar1 = (uVar6 & 0x1e) * 4;
    uVar4 = *(undefined4 *)(param_5 + iVar1);
    *(undefined4 *)((int)register0x00000038 + -0x14) = uVar4;
    __fp_write_word(uVar3,uVar4,param_1);
    uVar2 = uVar3;
    if (uVar3 != 0) goto locret_F00ACFC4;
    uVar3 = *(uint *)(iVar1 + param_5 + 4);
    *(uint *)((int)register0x00000038 + -0x14) = uVar3;
    uVar2 = *(int *)((int)register0x00000038 + -0xc) + 4;
loc_F00ACF84:
    __fp_write_word(uVar2,uVar3,param_1);
    if (uVar2 != 0) goto locret_F00ACFC4;
  }
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_3 + 8);
  *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + 4;
  uVar2 = 0;
locret_F00ACFC4:
  return CONCAT44(uVar8,uVar2);
}
/* GHIDRADEC_FUNCTION index=3920 start=0xf00ad5b0 */

undefined8 sub_F00AD5B0(int param_1,uint param_2)

{
  uint uVar1;
  uint unaff_g3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = *(uint *)(param_1 + 4);
  if (uVar1 == 1) {
    unaff_g3 = 0;
  }
  else if (uVar1 < 2) {
    unaff_g3 = 1;
  }
  else if (uVar1 == 2) {
    unaff_g3 = (uint)(param_2 == 0);
  }
  else if (uVar1 == 3) {
    unaff_g3 = param_2;
  }
  return CONCAT44(param_2,unaff_g3);
}
/* GHIDRADEC_FUNCTION index=3921 start=0xf00ad5f8 */

/* WARNING: Removing unreachable block (ram,0xf00ad610) */

undefined8 sub_F00AD5F8(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
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
  uVar3 = 0;
  if (param_2[8] != 0 || param_2[7] != 0) {
    _fpu_set_exception(param_1,0);
    uVar1 = *(uint *)(param_1 + 4);
    if (uVar1 == 1) {
      uVar3 = 0;
    }
    else if (uVar1 < 2) {
      uVar3 = param_2[7];
    }
    else if (uVar1 == 2) {
      uVar3 = (uint)(*param_2 == 0);
    }
    else if (uVar1 == 3) {
      uVar3 = (uint)(*param_2 != 0);
    }
    if (uVar3 == 0) {
      iVar2 = *(int *)(param_1 + 4);
    }
    else {
      iVar2 = param_2[6];
      param_2[6] = iVar2 + 1;
      if ((((iVar2 + 1 == 0) && (iVar2 = param_2[5], param_2[5] = iVar2 + 1, iVar2 + 1 == 0)) &&
          (iVar2 = param_2[4], param_2[4] = iVar2 + 1, iVar2 + 1 == 0)) &&
         (iVar2 = param_2[3], param_2[3] = iVar2 + 1, iVar2 + 1 == 0x20000)) {
        param_2[3] = 0x10000;
        param_2[2] = param_2[2] + 1;
      }
      iVar2 = *(int *)(param_1 + 4);
    }
    if (((iVar2 == 0) && (param_2[8] == 0)) && (uVar3 != 0)) {
      param_2[6] = param_2[6] & 0xfffffffe;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3922 start=0xf00ad718 */

/* WARNING: Removing unreachable block (ram,0xf00ad784) */
/* WARNING: Removing unreachable block (ram,0xf00ad800) */
/* WARNING: Removing unreachable block (ram,0xf00ad778) */

undefined8 sub_F00AD718(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  switch(param_2[1]) {
  case :
    *param_3 = 0;
    goto def_F00AD738;
  case :
    if (param_2[2] < 0x20) {
      _fpu_rightshift(param_2,0x70 - param_2[2]);
      sub_F00AD5F8(param_1,param_2);
      uVar2 = param_2[6];
      if ((int)uVar2 < 0) {
        if (*param_2 == 0) goto loc_F00AD7D4;
        if (0x80000000 < uVar2) {
          iVar1 = *param_2;
          break;
        }
        *param_3 = uVar2;
      }
      else {
        *param_3 = uVar2;
      }
      if (*param_2 != 0) {
        *param_3 = -uVar2;
      }
      goto def_F00AD738;
    }
    iVar1 = *param_2;
    break;
  case :
  case :
  case :
loc_F00AD7D4:
    iVar1 = *param_2;
    break;
  :
    goto def_F00AD738;
  }
  uVar2 = 0x80000000;
  if (iVar1 == 0) {
    uVar2 = 0x7fffffff;
  }
  *param_3 = uVar2;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffffe;
  _fpu_set_exception(param_1,4);
def_F00AD738:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3923 start=0xf00ad810 */

/* WARNING: Removing unreachable block (ram,0xf00ada24) */
/* WARNING: Removing unreachable block (ram,0xf00ad9d8) */
/* WARNING: Removing unreachable block (ram,0xf00ad9a4) */
/* WARNING: Removing unreachable block (ram,0xf00ad938) */
/* WARNING: Removing unreachable block (ram,0xf00ad8f0) */
/* WARNING: Removing unreachable block (ram,0xf00ad92c) */
/* WARNING: Removing unreachable block (ram,0xf00ad970) */
/* WARNING: Removing unreachable block (ram,0xf00ad9bc) */
/* WARNING: Removing unreachable block (ram,0xf00ada18) */
/* WARNING: Removing unreachable block (ram,0xf00ada4c) */
/* WARNING: Removing unreachable block (ram,0xf00ad8a4) */

undefined8 sub_F00AD810(uint *param_1,int *param_2,uint *param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  *param_3 = *param_3 & 0x7fffffff | *param_2 << 0x1f;
  switch(param_2[1]) {
  case :
    uVar4 = *param_3 & 0x80000000;
    goto loc_F00ADAB0;
  case :
    _fpu_rightshift(param_2,0x59);
    iVar1 = param_2[2];
    param_2[2] = iVar1 + 0x7f;
    if (iVar1 + 0x7f < 1) {
      *param_3 = *param_3 & 0x807fffff;
      _fpu_rightshift(param_2,1 - param_2[2]);
      sub_F00AD5F8(param_1,param_2);
      param_2 = (int *)param_2[6];
      if (param_2 == (int *)0x800000) {
        *param_3 = *param_3 & 0x80000000 | 0x800000;
        _fpu_set_exception(param_1,0);
        uVar4 = param_1[3];
      }
      else {
        *param_3 = *param_3 & 0xff800000 | (uint)param_2 & 0x7fffff;
        uVar4 = param_1[3];
      }
      if ((uVar4 & 1) != 0) {
        _fpu_set_exception(param_1,2);
      }
      if ((*param_1 & 4) != 0) {
        _fpu_set_exception(param_1,2);
        param_1[3] = param_1[3] & 0xfffffffe;
      }
      break;
    }
    sub_F00AD5F8(param_1,param_2);
    if (param_2[6] == 0x1000000) {
      param_2[6] = 0x800000;
      param_2[2] = param_2[2] + 1;
      uVar4 = param_2[2];
    }
    else {
      uVar4 = param_2[2];
    }
    if (0xfe < (int)uVar4) {
      _fpu_set_exception(param_1,3);
      _fpu_set_exception(param_1,0);
      if ((*param_1 & 8) == 0) {
        iVar1 = *param_2;
      }
      else {
        param_1[3] = param_1[3] & 0xfffffffe;
        iVar1 = *param_2;
      }
      puVar2 = param_1;
      sub_F00AD5B0(param_1,iVar1);
      uVar4 = *param_3;
      if (puVar2 == (uint *)0x0) {
        *param_3 = uVar4 & 0x807fffff | 0x7f7fffff;
        break;
      }
      goto loc_F00AD888;
    }
    uVar3 = *param_3;
    uVar4 = (uVar4 & 0xff) << 0x17;
    *param_3 = uVar3 & 0x807fffff | uVar4;
    uVar4 = uVar3 & 0x80000000 | uVar4 | param_2[6] & 0x7fffffU;
loc_F00ADAB0:
    *param_3 = uVar4;
    break;
  case :
    uVar4 = *param_3;
loc_F00AD888:
    *param_3 = uVar4 & 0xff800000 | 0x7f800000;
    break;
  case :
  case :
    _fpu_rightshift(param_2,0x59);
    uVar4 = *param_3;
    *param_3 = uVar4 | 0x7f800000;
    *param_3 = uVar4 & 0xff800000 | 0x7f800000 | param_2[6] & 0x3fffffU | 0x400000;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3924 start=0xf00adabc */

/* WARNING: Removing unreachable block (ram,0xf00adcf4) */
/* WARNING: Removing unreachable block (ram,0xf00adca8) */
/* WARNING: Removing unreachable block (ram,0xf00adc74) */
/* WARNING: Removing unreachable block (ram,0xf00adbf0) */
/* WARNING: Removing unreachable block (ram,0xf00adba8) */
/* WARNING: Removing unreachable block (ram,0xf00adbe4) */
/* WARNING: Removing unreachable block (ram,0xf00adc2c) */
/* WARNING: Removing unreachable block (ram,0xf00adc8c) */
/* WARNING: Removing unreachable block (ram,0xf00adce8) */
/* WARNING: Removing unreachable block (ram,0xf00add1c) */
/* WARNING: Removing unreachable block (ram,0xf00adb5c) */

undefined8 sub_F00ADABC(uint *param_1,int *param_2,uint *param_3,int *param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  *param_3 = *param_3 & 0x7fffffff | *param_2 << 0x1f;
  switch(param_2[1]) {
  case :
    *param_3 = *param_3 & 0x80000000;
    *param_4 = 0;
    break;
  case :
    _fpu_rightshift(param_2,0x3c);
    iVar3 = param_2[2];
    param_2[2] = iVar3 + 0x3ff;
    if (iVar3 + 0x3ff < 1) {
      *param_3 = *param_3 & 0x800fffff;
      _fpu_rightshift(param_2,1 - param_2[2]);
      sub_F00AD5F8(param_1,param_2);
      if (param_2[5] == 0x100000) {
        *param_3 = *param_3 & 0x80000000 | 0x100000;
        *param_4 = 0;
        _fpu_set_exception(param_1,0);
        uVar4 = param_1[3];
      }
      else {
        uVar4 = *param_3;
        *param_3 = uVar4 & 0x800fffff;
        *param_3 = uVar4 & 0x80000000 | param_2[5] & 0xfffffU;
        *param_4 = param_2[6];
        uVar4 = param_1[3];
      }
      if ((uVar4 & 1) != 0) {
        _fpu_set_exception(param_1,2);
      }
      if ((*param_1 & 4) != 0) {
        _fpu_set_exception(param_1,2);
        param_1[3] = param_1[3] & 0xfffffffe;
      }
      break;
    }
    sub_F00AD5F8(param_1,param_2);
    if (param_2[5] == 0x200000) {
      param_2[5] = 0x100000;
      param_2[2] = param_2[2] + 1;
      uVar4 = param_2[2];
    }
    else {
      uVar4 = param_2[2];
    }
    if ((int)uVar4 < 0x7ff) {
      uVar2 = *param_3;
      uVar4 = (uVar4 & 0x7ff) << 0x14;
      *param_3 = uVar2 & 0x800fffff | uVar4;
      *param_3 = uVar2 & 0x80000000 | uVar4 | param_2[5] & 0xfffffU;
      goto loc_F00ADD88;
    }
    _fpu_set_exception(param_1,3);
    _fpu_set_exception(param_1,0);
    if ((*param_1 & 8) == 0) {
      iVar3 = *param_2;
    }
    else {
      param_1[3] = param_1[3] & 0xfffffffe;
      iVar3 = *param_2;
    }
    puVar1 = param_1;
    sub_F00AD5B0(param_1,iVar3);
    uVar4 = *param_3;
    if (puVar1 != (uint *)0x0) goto loc_F00ADB3C;
    *param_3 = uVar4 & 0x800fffff | 0x7fefffff;
    iVar3 = -1;
    goto loc_F00ADD8C;
  case :
    uVar4 = *param_3;
loc_F00ADB3C:
    *param_3 = uVar4 & 0xfff00000 | 0x7ff00000;
    *param_4 = 0;
    break;
  case :
  case :
    _fpu_rightshift(param_2,0x3c);
    uVar4 = *param_3;
    *param_3 = uVar4 | 0x7ff00000;
    *param_3 = uVar4 & 0xfff00000 | 0x7ff00000 | param_2[5] & 0x7ffffU | 0x80000;
loc_F00ADD88:
    iVar3 = param_2[6];
loc_F00ADD8C:
    *param_4 = iVar3;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3925 start=0xf00add98 */

/* WARNING: Removing unreachable block (ram,0xf00adf3c) */
/* WARNING: Removing unreachable block (ram,0xf00adef4) */
/* WARNING: Removing unreachable block (ram,0xf00adec4) */
/* WARNING: Removing unreachable block (ram,0xf00ade78) */
/* WARNING: Removing unreachable block (ram,0xf00adedc) */
/* WARNING: Removing unreachable block (ram,0xf00adf30) */
/* WARNING: Removing unreachable block (ram,0xf00adf64) */
/* WARNING: Removing unreachable block (ram,0xf00adf10) */
/* WARNING: Removing unreachable block (ram,0xf00ade6c) */

undefined8
sub_F00ADD98(uint *param_1,int *param_2,uint *param_3,int *param_4,int *param_5,int *param_6)

{
  uint uVar1;
  word wVar4;
  uint *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  *param_3 = *param_3 & 0x7fffffff | *param_2 << 0x1f;
  switch(param_2[1]) {
  case :
    uVar1 = *param_3 & 0x8000ffff;
    break;
  case :
    iVar3 = param_2[2] + 0x3fff;
    param_2[2] = iVar3;
    if (iVar3 < 1) {
      _fpu_rightshift(param_2,1 - iVar3);
      sub_F00AD5F8(param_1,param_2);
      if ((uint)param_2[3] < 0x10000) {
        *param_3 = *param_3 & 0x8000ffff;
      }
      else {
        *param_3 = *param_3 & 0x8000ffff | 0x10000;
        _fpu_set_exception(param_1,0);
      }
      if ((param_1[3] & 1) != 0) {
        _fpu_set_exception(param_1,2);
      }
      if ((*param_1 & 4) != 0) {
        _fpu_set_exception(param_1,2);
        param_1[3] = param_1[3] & 0xfffffffe;
      }
loc_F00ADFC8:
      wVar4 = (word)param_2[3];
      goto loc_F00ADFCC;
    }
    sub_F00AD5F8(param_1,param_2);
    if (param_2[2] < 0x7fff) {
      *param_3 = *param_3 & 0x8000ffff | (param_2[2] & 0x7fffU) << 0x10;
      goto loc_F00ADFC8;
    }
    _fpu_set_exception(param_1,3);
    _fpu_set_exception(param_1,0);
    if ((*param_1 & 8) == 0) {
      iVar3 = *param_2;
    }
    else {
      param_1[3] = param_1[3] & 0xfffffffe;
      iVar3 = *param_2;
    }
    puVar2 = param_1;
    sub_F00AD5B0(param_1,iVar3);
    if (puVar2 != (uint *)0x0) {
      uVar1 = *param_3;
      goto loc_F00ADE08;
    }
    *param_3 = *param_3 & 0x8000ffff | 0x7ffe0000;
    *(undefined2 *)((int)param_3 + 2) = 0xffff;
    iVar3 = -1;
    *param_4 = -1;
    *param_5 = -1;
    goto loc_F00ADFE4;
  case :
    uVar1 = *param_3;
loc_F00ADE08:
    uVar1 = uVar1 | 0x7fff0000;
    break;
  :
    goto def_F00ADDD4;
  case :
  case :
    *param_3 = *param_3 | 0x7fff0000;
    wVar4 = (word)param_2[3] | 0x8000;
loc_F00ADFCC:
    *(word *)((int)param_3 + 2) = wVar4;
    *param_4 = param_2[4];
    *param_5 = param_2[5];
    iVar3 = param_2[6];
loc_F00ADFE4:
    *param_6 = iVar3;
    goto def_F00ADDD4;
  }
  *param_3 = uVar1;
  *(undefined2 *)((int)param_3 + 2) = 0;
  *param_5 = 0;
  *param_4 = 0;
  *param_6 = 0;
def_F00ADDD4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3926 start=0xf00ae27c */

/* WARNING: Removing unreachable block (ram,0xf00ae2d8) */

undefined8 sub_F00AE27C(uint *param_1,uint param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  param_1[7] = 0;
  param_1[8] = 0;
  if (param_2 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    *param_1 = param_2 >> 0x1f;
    param_1[1] = 1;
    param_1[2] = 0x1f;
    if ((int)param_2 < 0) {
      param_2 = -param_2;
    }
    param_1[3] = param_2 >> 0xf;
    param_1[4] = param_2 << 0x11;
    param_1[5] = 0;
    param_1[6] = 0;
    _fpu_normalize(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3927 start=0xf00ae504 */

/* WARNING: Removing unreachable block (ram,0xf00ae5a8) */
/* WARNING: Removing unreachable block (ram,0xf00ae600) */

undefined8
sub_F00AE504(undefined4 param_1,uint *param_2,uint *param_3,uint param_4,uint param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  uVar1 = *param_3;
  param_2[7] = 0;
  param_2[8] = 0;
  *param_2 = uVar1 >> 0x1f;
  param_2[1] = 1;
  uVar3 = (uVar1 & 0x7fffffff) >> 0x10;
  param_2[2] = uVar3 - 0x3fff;
  uVar2 = uVar1 & 0xffff;
  param_2[3] = uVar2;
  if ((uVar1 & 0x7fff0000) != 0) {
    param_2[3] = uVar2 | 0x10000;
  }
  param_2[4] = param_4;
  param_2[5] = param_5;
  param_2[6] = param_6;
  if (uVar3 < 0x7fff) {
    if (((param_5 == 0 && param_4 == 0) && param_6 == 0) && param_2[3] == 0) {
      param_2[1] = 0;
    }
    else if ((uVar1 & 0x7fff0000) == 0) {
      _fpu_normalize(param_2);
      param_2[2] = param_2[2] + 1;
    }
  }
  else if (((uVar2 == 0 && param_5 == 0) && param_4 == 0) && param_6 == 0) {
    param_2[1] = 2;
  }
  else {
    if ((uVar1 & 0x8000) == 0) {
      param_2[1] = 5;
      _fpu_set_exception(param_1,4);
    }
    else {
      param_2[1] = 4;
    }
    param_2[3] = param_2[3] | 0x8000;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3928 start=0xf00b045c */

/* WARNING: Removing unreachable block (ram,0xf00b04ac) */
/* WARNING: Removing unreachable block (ram,0xf00b0488) */
/* WARNING: Removing unreachable block (ram,0xf00b04c0) */
/* WARNING: Removing unreachable block (ram,0xf00b0460) */

undefined8 sub_F00B045C(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar2 = param_1;
  _prom_childnode();
  if (iVar2 == 0) {
    param_1 = 0;
  }
  else {
    iVar1 = iVar2 - param_2;
    iVar3 = iVar2;
    do {
      if (iVar1 == 0) goto locret_F00B04D8;
      _prom_nextnode();
      iVar1 = iVar3 - param_2;
    } while (iVar3 != 0);
    if (iVar2 == 0) {
      param_1 = 0;
    }
    else {
      do {
        param_1 = iVar2;
        sub_F00B045C(iVar2,param_2);
        if (param_1 != 0) goto locret_F00B04D8;
        _prom_nextnode();
      } while (iVar2 != 0);
      param_1 = 0;
    }
  }
locret_F00B04D8:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3929 start=0xf00b07e4 */

/* WARNING: Removing unreachable block (ram,0xf00b0950) */
/* WARNING: Removing unreachable block (ram,0xf00b0920) */
/* WARNING: Removing unreachable block (ram,0xf00b08d0) */
/* WARNING: Removing unreachable block (ram,0xf00b08a0) */
/* WARNING: Removing unreachable block (ram,0xf00b0868) */
/* WARNING: Removing unreachable block (ram,0xf00b0808) */
/* WARNING: Removing unreachable block (ram,0xf00b0838) */
/* WARNING: Removing unreachable block (ram,0xf00b088c) */
/* WARNING: Removing unreachable block (ram,0xf00b08b4) */
/* WARNING: Removing unreachable block (ram,0xf00b0910) */
/* WARNING: Removing unreachable block (ram,0xf00b0934) */
/* WARNING: Removing unreachable block (ram,0xf00b0990) */
/* WARNING: Removing unreachable block (ram,0xf00b07f4) */

undefined8 sub_F00B07E4(int *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined3 *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
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
  uVar5 = param_1[10];
  uVar1 = uVar5;
  _getlongprop(uVar5,&aName_1);
  param_1[3] = uVar1;
  puVar2 = &aZs_1;
  _strcmp();
  if (puVar2 == (undefined3 *)0x0) {
    iVar3 = dword_F011C478 + 1;
    param_1[0xb] = dword_F011C478;
    dword_F011C478 = iVar3;
  }
  uVar1 = uVar5;
  _getproplen(uVar5,&aIntr);
  if ((int)uVar1 < 1) {
    uVar1 = uVar5;
    _getproplen(uVar5,aInterrupts_0);
    if (0 < (int)uVar1) {
      param_1[6] = uVar1 >> 3;
      puVar4 = aInterrupts_1;
      goto loc_F00B088C;
    }
  }
  else {
    param_1[6] = uVar1 >> 3;
    puVar4 = (undefined *)&aIntr_0;
loc_F00B088C:
    uVar1 = uVar5;
    _getlongprop(uVar5,puVar4);
    param_1[7] = uVar1;
  }
  uVar1 = uVar5;
  _getproplen(uVar5,&aReg_0);
  if (0 < (int)uVar1) {
    .udiv();
    param_1[4] = uVar1;
    if (0 < (int)uVar1) {
      uVar1 = uVar5;
      _getlongprop(uVar5,&aReg_1);
      iVar3 = *param_1;
      param_1[5] = uVar1;
      if (((iVar3 != 0) && (0 < *(int *)(iVar3 + 0x30))) && (*(int *)(iVar3 + 0x34) != 0)) {
        _apply_range_to_reg(param_1[3],*(int *)(iVar3 + 0x30),*(int *)(iVar3 + 0x34),param_1[4]);
      }
    }
  }
  uVar1 = uVar5;
  _getproplen(uVar5,&aRanges_2);
  if ((int)uVar1 < 1) {
    if (*param_1 != 0) {
      iVar3 = *(int *)(*param_1 + 0x30);
loc_F00B09C4:
      param_1[0xc] = iVar3;
      param_1[0xd] = *(int *)(*param_1 + 0x34);
      goto locret_F00B09DC;
    }
    param_1[0xc] = 0;
  }
  else {
    .udiv();
    param_1[0xc] = uVar1;
    if (0 < (int)uVar1) {
      _getlongprop(uVar5,&aRanges_1);
      iVar3 = *param_1;
      param_1[0xd] = uVar5;
      if (((iVar3 != 0) && (0 < *(int *)(iVar3 + 0x30))) && (*(int *)(iVar3 + 0x34) != 0)) {
        _apply_range_to_range(param_1[3],*(int *)(iVar3 + 0x30),*(int *)(iVar3 + 0x34),param_1[0xc])
        ;
      }
      goto locret_F00B09DC;
    }
    if (*param_1 != 0) {
      iVar3 = *(int *)(*param_1 + 0x30);
      goto loc_F00B09C4;
    }
    param_1[0xc] = 0;
  }
  param_1[0xd] = 0;
locret_F00B09DC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3930 start=0xf00b09e4 */

undefined8 sub_F00B09E4(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  puVar2 = _dev_opslist;
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
  do {
    if (puVar2[1] == 0) {
      uVar3 = 0;
locret_F00B0A24:
      return CONCAT44(param_2,uVar3);
    }
    iVar1 = param_1;
    (**(code **)(puVar2[1] + 4))();
    if (iVar1 != 0) {
      uVar3 = puVar2[1];
      goto locret_F00B0A24;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3931 start=0xf00b0a2c */

undefined8 sub_F00B0A2C(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  iVar2 = *(int *)(param_1 + 8);
  uVar3 = 0;
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x28);
    while (iVar1 != param_2) {
      iVar2 = *(int *)(iVar2 + 4);
      if (iVar2 == 0) {
        uVar3 = 0;
        goto locret_F00B0A68;
      }
      iVar1 = *(int *)(iVar2 + 0x28);
    }
    uVar3 = 1;
  }
locret_F00B0A68:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3932 start=0xf00b0a70 */

undefined8 sub_F00B0A70(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = param_2;
  }
  else {
    for (; *(int *)(iVar1 + 4) != 0; iVar1 = *(int *)(iVar1 + 4)) {
    }
    *(undefined4 *)(iVar1 + 4) = param_2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3933 start=0xf00b0aa8 */

undefined8 sub_F00B0AA8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == param_2) {
    uVar3 = 0;
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 4);
  }
  else {
    do {
      iVar2 = iVar1;
      if (iVar2 == 0) {
        uVar3 = 0xffffffff;
        goto locret_F00B0AFC;
      }
      iVar1 = *(int *)(iVar2 + 4);
    } while (iVar1 != param_2);
    uVar3 = 0;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 4);
  }
locret_F00B0AFC:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3934 start=0xf00b0b04 */

undefined8 sub_F00B0B04(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  piVar1 = (int *)_av_opstab;
  iVar2 = DAT_f011d2a4._0_4_;
  while (iVar2 != 0) {
    *piVar1 = (int)(piVar1 + 2);
    iVar2 = piVar1[3];
    piVar1 = piVar1 + 2;
  }
  _dev_opslist = _av_opstab;
  return CONCAT44(param_2,piVar1);
}
/* GHIDRADEC_FUNCTION index=3935 start=0xf00b2d58 */

undefined8 sub_F00B2D58(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  cVar1 = *param_1;
  do {
    if (cVar1 == '\0') {
      *param_2 = '\0';
locret_F00B2DB0:
      return CONCAT44(param_2,param_1);
    }
    iVar3 = (int)*param_1;
    if (iVar3 == 0x3a) {
      *param_2 = '\0';
      goto locret_F00B2DB0;
    }
    iVar2 = iVar3 + -0x40;
    if (iVar3 < 0x3b) {
      iVar2 = iVar3 + -0x2f;
    }
    if (iVar2 == 0) {
      *param_2 = '\0';
      goto locret_F00B2DB0;
    }
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    param_2 = param_2 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3936 start=0xf00b2db8 */

/* WARNING: Removing unreachable block (ram,0xf00b2e24) */
/* WARNING: Removing unreachable block (ram,0xf00b2df4) */
/* WARNING: Removing unreachable block (ram,0xf00b2e0c) */
/* WARNING: Removing unreachable block (ram,0xf00b2e4c) */
/* WARNING: Removing unreachable block (ram,0xf00b2de4) */

undefined8 sub_F00B2DB8(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  int *piVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
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
  piVar6 = (int *)param_2[3];
  if ((int *)param_2[3] != (int *)0x0) goto locret_F00B2E8C;
  if (dword_F011DDA0 != 0) {
    _printf(aCheckingS,param_1[3]);
  }
  iVar1 = *param_2;
  _strcmp(iVar1,&aSd);
  iVar2 = param_1[3];
  if (iVar1 == 0) {
    _strcmp(iVar2,&aSr);
    if (iVar2 != 0) {
      iVar2 = param_1[3];
      goto loc_F00B2E24;
    }
    pcVar3 = (char *)param_2[1];
  }
  else {
loc_F00B2E24:
    _strcmp(iVar2,*param_2);
    piVar6 = (int *)0x0;
    if (iVar2 != 0) goto locret_F00B2E8C;
    pcVar3 = (char *)param_2[1];
  }
  piVar6 = param_1;
  if (*pcVar3 == '\0') {
    param_2[3] = (int)param_1;
  }
  else {
    pcVar4 = (code *)*param_1;
    _path_getmatchfunc();
    if (pcVar4 == (code *)0x0) {
      pcVar4 = _obio_match;
    }
    piVar5 = param_1;
    (*pcVar4)(param_1,param_2[1]);
    if (piVar5 == (int *)0x0) {
      param_2[3] = 0;
      piVar6 = (int *)0x0;
    }
    else {
      param_2[3] = (int)param_1;
    }
  }
locret_F00B2E8C:
  return CONCAT44(param_2,piVar6);
}
/* GHIDRADEC_FUNCTION index=3937 start=0xf00b2e94 */

/* WARNING: Removing unreachable block (ram,0xf00b2edc) */
/* WARNING: Removing unreachable block (ram,0xf00b2ec8) */

undefined8 sub_F00B2E94(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  if (dword_F011DDA0 != 0) {
    _printf(aWalkLayerAtXSL,param_3,*(undefined4 *)(param_3 + 0xc));
  }
  _walk_layer(*(undefined4 *)(param_3 + 8),sub_F00B2DB8,
              (undefined *)((int)register0x00000038 + -0x18));
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
}
/* GHIDRADEC_FUNCTION index=3938 start=0xf00b3124 */

/* WARNING: Removing unreachable block (ram,0xf00b3168) */
/* WARNING: Removing unreachable block (ram,0xf00b315c) */

undefined8 sub_F00B3124(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = param_2[3];
  if (iVar1 == 0) {
    if (dword_F011DDA0 != 0) {
      _printf(aCheckingDeviXU,param_1,*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0xc)
             );
    }
    iVar1 = *(int *)(param_1 + 0xc);
    _strcmp(iVar1,*param_2);
    if (iVar1 == 0) {
      iVar1 = param_1;
      if (param_2[2] == -1) {
        param_2[3] = param_1;
      }
      else if (param_2[2] == *(int *)(param_1 + 0x2c)) {
        param_2[3] = param_1;
      }
      else {
        param_2[3] = 0;
        iVar1 = 0;
      }
    }
    else {
      iVar1 = 0;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3939 start=0xf00b3488 */

/* WARNING: Removing unreachable block (ram,0xf00b34d4) */
/* WARNING: Removing unreachable block (ram,0xf00b350c) */
/* WARNING: Removing unreachable block (ram,0xf00b34b0) */

undefined8 sub_F00B3488(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  piVar2 = &_hex_unit_devices;
  iVar1 = _hex_unit_devices;
  do {
    if (iVar1 == 0) {
      uVar3 = 0;
      if (dword_F011DDA0 != 0) {
        _printf(aSUnitsAreNotIn);
        uVar3 = 0;
      }
locret_F00B3518:
      return CONCAT44(param_2,uVar3);
    }
    _strncmp(iVar1,param_1,2);
    if (iVar1 == 0) {
      uVar3 = 1;
      if (dword_F011DDA0 != 0) {
        _printf(aSUnitsAreInHex);
        uVar3 = 1;
      }
      goto locret_F00B3518;
    }
    piVar2 = piVar2 + 1;
    iVar1 = *piVar2;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3940 start=0xf00b8244 */

/* WARNING: Removing unreachable block (ram,0xf00b8374) */
/* WARNING: Removing unreachable block (ram,0xf00b8440) */
/* WARNING: Removing unreachable block (ram,0xf00b83b4) */
/* WARNING: Removing unreachable block (ram,0xf00b82bc) */
/* WARNING: Removing unreachable block (ram,0xf00b82a0) */
/* WARNING: Removing unreachable block (ram,0xf00b8270) */
/* WARNING: Removing unreachable block (ram,0xf00b828c) */
/* WARNING: Removing unreachable block (ram,0xf00b82b4) */
/* WARNING: Removing unreachable block (ram,0xf00b82e8) */
/* WARNING: Removing unreachable block (ram,0xf00b8424) */
/* WARNING: Removing unreachable block (ram,0xf00b8368) */
/* WARNING: Removing unreachable block (ram,0xf00b8380) */
/* WARNING: Removing unreachable block (ram,0xf00b8268) */

undefined8
sub_F00B8244(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  uVar4 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  if ((_scsi_options & 2) != 0) {
    _printf(aMakeDeviceSD,param_4,param_5);
  }
  piVar1 = (int *)0x20;
  _kalloc();
  if (piVar1 == (int *)0x0) {
    uVar5 = 0;
  }
  else {
    _bzero(piVar1,0x20);
    piVar1[1] = (int)param_1;
    *(sword *)(piVar1 + 2) = (sword)param_6;
    *(char *)((int)piVar1 + 10) = (char)uVar4;
    iVar2 = 0x38;
    _kalloc();
    piVar1[3] = iVar2;
    if (iVar2 != 0) {
      _bzero();
      uVar5 = 8;
      _kalloc();
      *(undefined4 *)(piVar1[3] + 0x1c) = uVar5;
      iVar2 = piVar1[3];
      if (*(int *)(iVar2 + 0x1c) != 0) {
        _bzero(*(int *)(iVar2 + 0x1c),8);
        *(int *)piVar1[3] = param_2;
        iVar2 = piVar1[3];
        if (*(int *)(param_2 + 8) != 0) {
          *(int *)(iVar2 + 4) = *(int *)(param_2 + 8);
          iVar2 = piVar1[3];
        }
        *(int *)(param_2 + 8) = iVar2;
        *(undefined4 *)(piVar1[3] + 0xc) = param_4;
        *(undefined4 *)(piVar1[3] + 0x2c) = param_5;
        **(uint **)(piVar1[3] + 0x1c) = *param_1 >> 8 & 0xf;
        piVar3 = piVar1;
        (**(code **)(param_3 + 4))();
        if (-1 < (int)piVar3) {
          if (*(char *)(piVar1 + 7) != '\0') {
            _printf(aSDAtSDTargetDL,param_4,param_5,*(undefined4 *)(param_2 + 0xc),
                    *(undefined4 *)(param_2 + 0x2c),param_6,uVar4);
            (**(code **)(param_3 + 8))(piVar1);
          }
          if (_sd_root != (int *)0x0) {
            iVar2 = *_sd_root;
            piVar3 = _sd_root;
            while (iVar2 != 0) {
              piVar3 = (int *)*piVar3;
              iVar2 = *piVar3;
            }
            *piVar3 = (int)piVar1;
            piVar1 = _sd_root;
          }
          _sd_root = piVar1;
          uVar4 = _scsi_ncmds_per_dev;
          if ((code *)param_1[6] == _scsi_std_pktalloc) {
            iVar2 = _nscsi_devices + 1;
            .umul(iVar2,_scsi_ncmds_per_dev);
            uVar5 = 1;
            if (_scsi_ncmds < iVar2) {
              _scsi_addcmds(uVar4);
              uVar5 = 1;
            }
          }
          else {
            uVar5 = 1;
          }
          goto locret_F00B844C;
        }
        *(undefined4 *)(param_2 + 8) = *(undefined4 *)(piVar1[3] + 4);
        _kfree(*(undefined4 *)(piVar1[3] + 0x1c),8);
        iVar2 = piVar1[3];
      }
      _kfree(iVar2,0x38);
    }
    _kfree(piVar1,0x20);
    uVar5 = 0;
  }
locret_F00B844C:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=3941 start=0xf00b8d20 */

/* WARNING: Removing unreachable block (ram,0xf00b8d8c) */
/* WARNING: Removing unreachable block (ram,0xf00b8d5c) */
/* WARNING: Removing unreachable block (ram,0xf00b8db4) */
/* WARNING: Removing unreachable block (ram,0xf00b8d28) */

undefined8 sub_F00B8D20(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  code *pcVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  uVar3 = _scsi_spl;
  _splr(_scsi_spl);
  dword_F01317E4 = 1;
  do {
    uVar1 = dword_F01317D4;
    dword_F01317D4 = uVar1;
    if (uVar1 == 0) {
      dword_F01317E4 = 0;
      _splx(uVar3);
      uVar3 = 0;
      goto locret_F00B8DC0;
    }
    pcVar2 = (code *)&dword_F01317D4;
    sub_F00B8E84();
    (*pcVar2)();
  } while ((pcVar2 != (code *)0x0) || (dword_F01317D4 < uVar1));
  dword_F01317E4 = 0;
  _splx(uVar3);
  uVar3 = 0xffffffff;
locret_F00B8DC0:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3942 start=0xf00b8e1c */

undefined8 sub_F00B8E1C(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar2;
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
  iVar2 = 0;
  piVar1 = param_1;
  do {
    iVar2 = iVar2 + 1;
    if (piVar1[5] == param_2) goto locret_F00B8E7C;
    piVar1 = piVar1 + 1;
  } while (iVar2 < 8);
  param_1[3] = param_1[3] + 1;
  *param_1 = *param_1 + 1;
  param_1[param_1[1] + 5] = param_2;
  param_1[1] = param_1[1] + 1U & 7;
locret_F00B8E7C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3943 start=0xf00b8e84 */

undefined8 sub_F00B8E84(int *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  *param_1 = *param_1 + -1;
  uVar1 = param_1[2] + 1U & 7;
  param_1[2] = uVar1;
  iVar2 = param_1[uVar1 + 5];
  param_1[uVar1 + 5] = 0;
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3944 start=0xf00bbdb4 */

/* WARNING: Removing unreachable block (ram,0xf00bbe90) */
/* WARNING: Removing unreachable block (ram,0xf00bbe0c) */
/* WARNING: Removing unreachable block (ram,0xf00bbe98) */
/* WARNING: Removing unreachable block (ram,0xf00bbe74) */
/* WARNING: Removing unreachable block (ram,0xf00bbe2c) */

sqword sub_F00BBDB4(int param_1,uint param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (((*(uint *)(param_1 + 0x40) & 0x121) == 0) && (*(int *)(param_1 + 0x18) != 0)) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x20;
    if ((int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2) <
        *(int *)(param_1 + 0x18)) {
      _callout_dispatch(4,sub_F00BBEB8,param_1);
    }
    else {
      _ns_timeout(sub_F00BBEB8,param_1,0,1000,4);
    }
  }
  else if (*(int *)(param_1 + 0x18) <=
           (int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2)) {
    if ((*(uint *)(param_1 + 0x40) & 0x40) != 0) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffffbf;
      _wakeup(param_1 + 0x18);
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      _selwakeup(*(int *)(param_1 + 0x2c),*(uint *)(param_1 + 0x40) & 0x1000);
      _selthreadclear(param_1 + 0x2c);
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffefff;
    }
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3945 start=0xf00bbeb8 */

/* WARNING: Removing unreachable block (ram,0xf00bc05c) */
/* WARNING: Removing unreachable block (ram,0xf00bbfc8) */
/* WARNING: Removing unreachable block (ram,0xf00bbff8) */
/* WARNING: Removing unreachable block (ram,0xf00bbf88) */
/* WARNING: Removing unreachable block (ram,0xf00bbf2c) */
/* WARNING: Removing unreachable block (ram,0xf00bbf04) */
/* WARNING: Removing unreachable block (ram,0xf00bbf48) */
/* WARNING: Removing unreachable block (ram,0xf00bbfa0) */
/* WARNING: Removing unreachable block (ram,0xf00bbfb4) */
/* WARNING: Removing unreachable block (ram,0xf00bc040) */
/* WARNING: Removing unreachable block (ram,0xf00bc078) */
/* WARNING: Removing unreachable block (ram,0xf00bbebc) */

undefined8 sub_F00BBEB8(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined *puVar6;
  undefined4 unaff_l1;
  int iVar7;
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
  iVar7 = -1;
  iVar1 = param_1;
  _spl1();
  puVar6 = unk_F0131848;
  iVar2 = *(int *)(param_1 + 0x18);
  uVar4 = 0;
  while (0 < iVar2) {
    iVar7 = param_1 + 0x18;
    if ((*(uint *)(param_1 + 0x3c) & 0x200020) == 0) {
      uVar5 = 0x80;
    }
    else {
      uVar5 = 0;
    }
    _ndqb(iVar7,uVar5);
    if (iVar7 == 0) break;
    if (0x800 < uVar4 + iVar7) break;
    _q_to_b(param_1 + 0x18,puVar6,iVar7);
    puVar6 = puVar6 + iVar7;
    uVar4 = uVar4 + iVar7;
    iVar2 = *(int *)(param_1 + 0x18);
  }
  _splx(iVar1);
  pbVar3 = (byte *)&DAT_f0131800;
  if (0 < (int)uVar4) {
    pbVar3 = unk_F0131848 + uVar4;
    for (puVar6 = unk_F0131848; puVar6 < unk_F0131848 + uVar4; puVar6 = puVar6 + 1) {
      _objc_msgSend(_kmId,paKmputc,*puVar6 & 0x7f);
      pbVar3 = _kmId;
    }
  }
  _spl1();
  if (iVar7 == 0) {
    uVar4 = param_1 + 0x18;
    _getc(uVar4);
    _timeout(_ttrstrt,param_1,uVar4 & 0x7f);
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 1;
  }
  else if (0 < *(int *)(param_1 + 0x18)) {
    _callout_dispatch(4,sub_F00BBEB8,param_1);
  }
  uVar4 = *(uint *)(param_1 + 0x40);
  *(uint *)(param_1 + 0x40) = uVar4 & 0xffffffdf;
  if (*(int *)(param_1 + 0x18) <= (int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2)
     ) {
    if ((uVar4 & 0x40) != 0) {
      *(uint *)(param_1 + 0x40) = uVar4 & 0xffffff9f;
      _wakeup(param_1 + 0x18);
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      _selwakeup(*(int *)(param_1 + 0x2c),*(uint *)(param_1 + 0x40) & 0x1000);
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffefff;
    }
  }
  _splx(pbVar3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3946 start=0xf00bc2bc */

/* WARNING: Removing unreachable block (ram,0xf00bc348) */
/* WARNING: Removing unreachable block (ram,0xf00bc32c) */
/* WARNING: Removing unreachable block (ram,0xf00bc358) */
/* WARNING: Removing unreachable block (ram,0xf00bc2fc) */

undefined8 +[kmDevice probe:](int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  if ((_kmId == 0) || (iVar3 = _kmId, dword_F0132060 != 0)) {
    _objc_msgSend(param_1,paNew);
    iVar3 = param_1;
  }
  uVar2 = 1;
  if (DAT_f0121588._0_4_ != 0) {
    uVar2 = 2;
  }
  iVar1 = iVar3;
  _objc_msgSend(iVar3,paInitFbMode,1,uVar2);
  if (iVar1 == 0) {
    _IOLog(DAT_f011fe88);
    _objc_msgSend(iVar3,paFree);
    _kmId = 0;
  }
  return CONCAT44(param_2,(uint)(iVar1 != 0));
}
/* GHIDRADEC_FUNCTION index=3947 start=0xf00bc374 */

undefined8 +[kmDevice deviceStyle](undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  return CONCAT44(param_2,2);
}
/* GHIDRADEC_FUNCTION index=3948 start=0xf00bc380 */

/* WARNING: Removing unreachable block (ram,0xf00bc4ac) */
/* WARNING: Removing unreachable block (ram,0xf00bc480) */
/* WARNING: Removing unreachable block (ram,0xf00bc400) */
/* WARNING: Removing unreachable block (ram,0xf00bc3c8) */
/* WARNING: Removing unreachable block (ram,0xf00bc3e4) */
/* WARNING: Removing unreachable block (ram,0xf00bc460) */
/* WARNING: Removing unreachable block (ram,0xf00bc494) */
/* WARNING: Removing unreachable block (ram,0xf00bc4c0) */
/* WARNING: Removing unreachable block (ram,0xf00bc3b0) */

undefined8 +[kmDevice new](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [11];
  undefined (*pauVar2) [9];
  undefined7 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (dword_F0132074 == 0) {
    dword_F0132070 = 0;
    dword_F0132074 = 1;
  }
  _objc_msgSend(param_1,paAlloc);
  puVar3 = paNxlock;
  _objc_msgSend(paNxlock,paNew);
  pauVar1 = paMethodfor;
  *(undefined7 **)(param_1 + 0x108) = puVar3;
  _objc_msgSend();
  uVar4 = *(undefined4 *)(param_1 + 0x108);
  dword_F0132068 = puVar3;
  _objc_msgSend(uVar4,pauVar1,paUnlock);
  dword_F013206C = uVar4;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  iVar5 = param_1 + 4;
  while (pauVar2 = paSetunit, param_1 <= iVar5 + -4) {
    *(undefined4 *)(iVar5 + 0x108) = 0;
    iVar5 = iVar5 + -4;
  }
  if (dword_F0132060 == 0) {
    _kmId = param_1;
  }
  iVar5 = _kmId;
  *(undefined4 *)(param_1 + 0x10c) = _basicConsole;
  _objc_msgSend(iVar5,pauVar2);
  dword_F0132060 = dword_F0132060 + 1;
  _sprintf((undefined *)((int)register0x00000038 + -0x28),aKmdeviceD);
  _objc_msgSend(_kmId,paSetname,(undefined *)((int)register0x00000038 + -0x28));
  _objc_msgSend(_kmId,paSetdevicekind,aKmdevice_0);
  _objc_msgSend(_kmId,paSetlocation,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3949 start=0xf00bc4d0 */

/* WARNING: Removing unreachable block (ram,0xf00bc578) */
/* WARNING: Removing unreachable block (ram,0xf00bc538) */
/* WARNING: Removing unreachable block (ram,0xf00bc520) */
/* WARNING: Removing unreachable block (ram,0xf00bc558) */
/* WARNING: Removing unreachable block (ram,0xf00bc590) */
/* WARNING: Removing unreachable block (ram,0xf00bc4e0) */

undefined8 -[kmDevice init:fb_mode:](int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x108),paLock);
  *(undefined4 *)(param_1 + 0x16c) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x114) = param_4;
  *(undefined4 *)(param_1 + 0x170) = 0;
  *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) & 0x7fffffff;
  if ((param_3 & 0xff) != 0) {
    iVar1 = param_1;
    _objc_msgSend(param_1,paInitkb);
    if (iVar1 != 0) {
      *(int *)((int)register0x00000038 + -0x10) = param_1;
      goto loc_F00BC544;
    }
    _IOLog(aKmdeviceNoKeyb);
  }
  *(int *)((int)register0x00000038 + -0x10) = param_1;
loc_F00BC544:
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d30;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  if (*(char *)(param_1 + 0x174) == '\0') {
    _objc_msgSend(param_1,paRegisterdevice);
    *(undefined *)(param_1 + 0x174) = 1;
    uVar2 = *(undefined4 *)(param_1 + 0x108);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x108);
  }
  _objc_msgSend(uVar2,paUnlock);
  return CONCAT44(param_2,param_1);
}

