
/* WARNING: Removing unreachable block (ram,0xf00a7558) */
/* WARNING: Removing unreachable block (ram,0xf00a75b8) */
/* WARNING: Removing unreachable block (ram,0xf00a75e8) */
/* WARNING: Removing unreachable block (ram,0xf00a7584) */
/* WARNING: Removing unreachable block (ram,0xf00a7544) */
/* WARNING: Removing unreachable block (ram,0xf00a75d4) */
/* WARNING: Removing unreachable block (ram,0xf00a75f8) */
/* WARNING: Removing unreachable block (ram,0xf00a75a8) */
/* WARNING: Removing unreachable block (ram,0xf00a7610) */
/* WARNING: Removing unreachable block (ram,0xf00a74ec) */

undefined8 _initrootnet(undefined4 param_1,undefined4 param_2)

{
  undefined8 **ppuVar1;
  sword sVar2;
  bool bVar3;
  int iVar4;
  undefined *puVar5;
  undefined uVar6;
  undefined4 unaff_l0;
  undefined8 **ppuVar7;
  undefined8 **ppuVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar9;
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
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
  bVar3 = false;
  if ((_in_ifaddr == 0) || ((*(word *)(*(int *)(_in_ifaddr + 0x20) + 0xc) & 8) != 0)) {
    ppuVar8 = dword_F0131560;
    if ((*(sword *)(dword_F0131560 + 1) == -1) ||
       (ppuVar7 = &off_F011B108, ppuVar8 = ppuVar7, sVar2 = DAT_f011b10c._0_2_,
       off_F011B108 == (undefined8 *)0x0)) {
      uVar6 = *(undefined *)*ppuVar8;
    }
    else {
      while( true ) {
        if (sVar2 == -1) {
          _path_findnodebyname(*ppuVar7,0,_top_devinfo);
        }
        ppuVar8 = ppuVar7 + 2;
        uVar6 = uRam00000000;
        if (*ppuVar8 == (undefined8 *)0x0) break;
        ppuVar1 = ppuVar7 + 3;
        ppuVar7 = ppuVar8;
        sVar2 = *(sword *)ppuVar1;
      }
    }
    *(undefined *)((int)register0x00000038 + -0x28) = uVar6;
    iVar9 = 2;
    *(undefined *)((int)register0x00000038 + -0x27) = *(undefined *)((int)*ppuVar8 + 1);
    *(undefined *)((int)register0x00000038 + -0x26) = 0x30;
    *(undefined *)((int)register0x00000038 + -0x25) = 0;
    _socreate(2,(undefined *)((int)register0x00000038 + -0x2c),2,0);
    if (iVar9 == 0) {
      *(undefined2 *)((int)register0x00000038 + -0x18) = 2;
      do {
        iVar9 = *(int *)((int)register0x00000038 + -0x2c);
        do {
          _ifioctl(iVar9,0xc0206921,(undefined *)((int)register0x00000038 + -0x28));
          if (iVar9 == 0) {
            if (bVar3) {
              _printf(aInitrootnetBoo);
            }
            puVar5 = (undefined *)((int)register0x00000038 + -0x14);
            _inet_ntoa(puVar5);
            _printf(aPrimaryNetwork,(undefined *)((int)register0x00000038 + -0x28),puVar5);
            iVar4 = *(int *)((int)register0x00000038 + -0x2c);
            goto loc_F00A7604;
          }
          if (iVar9 != 0x3c) {
            _printf(aInitrootnetAut);
            iVar4 = *(int *)((int)register0x00000038 + -0x2c);
            goto loc_F00A7604;
          }
          iVar9 = *(int *)((int)register0x00000038 + -0x2c);
        } while (bVar3);
        _printf(aInitrootnetBoo_0);
        bVar3 = true;
      } while( true );
    }
    _printf(aInitrootnetSoc);
    iVar4 = *(int *)((int)register0x00000038 + -0x2c);
loc_F00A7604:
    if (iVar4 != 0) {
      _soclose();
    }
  }
  else {
    iVar9 = 0;
  }
  return CONCAT44(param_2,iVar9);
}

