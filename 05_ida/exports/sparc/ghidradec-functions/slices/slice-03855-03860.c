/* GHIDRADEC_FUNCTION index=3855 start=0xf008fa58 */

/* WARNING: Removing unreachable block (ram,0xf008fb34) */
/* WARNING: Removing unreachable block (ram,0xf008fbec) */
/* WARNING: Removing unreachable block (ram,0xf008fb24) */

undefined8 sub_F008FA58(char *param_1,undefined4 *param_2,uint *param_3)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  undefined4 unaff_l3;
  int iVar11;
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
  bool bVar12;
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
  bVar2 = false;
  iVar11 = 0;
  cVar1 = *param_1;
  pcVar8 = param_1;
  while( true ) {
    iVar7 = (int)cVar1;
    pcVar9 = pcVar8 + 1;
    if (((iVar7 == 0x20) || ((iVar7 - 9U & 0xff) < 2)) || (bVar12 = false, iVar7 == 10)) {
      bVar12 = true;
    }
    if (!bVar12) break;
    cVar1 = *pcVar9;
    pcVar8 = pcVar9;
  }
  if (iVar7 == 0x2d) {
    cVar1 = *pcVar9;
    bVar2 = true;
  }
  else {
    if (iVar7 != 0x2b) goto loc_F008FAD8;
    cVar1 = *pcVar9;
  }
  iVar7 = (int)cVar1;
  pcVar9 = pcVar8 + 2;
loc_F008FAD8:
  bVar12 = true;
  if ((iVar7 == 0x30) && ((*pcVar9 == 'x' || (bVar12 = true, *pcVar9 == 'X')))) {
    iVar7 = (int)pcVar9[1];
    iVar11 = 0x10;
    pcVar9 = pcVar9 + 2;
    bVar12 = false;
  }
  if ((bVar12) && (iVar11 = 10, iVar7 == 0x30)) {
    iVar11 = 8;
  }
  uVar3 = 0xffffffff;
  .udiv(0xffffffff,iVar11);
  iVar4 = -1;
  .urem(0xffffffff,iVar11);
  uVar6 = 0;
  iVar10 = 0;
  do {
    uVar5 = iVar7 - 0x30;
    if (9 < (uVar5 & 0xff)) {
      if (((iVar7 - 0x41U & 0xff) < 0x1a) || (bVar12 = false, (iVar7 - 0x61U & 0xff) < 0x1a)) {
        bVar12 = true;
      }
      if (!bVar12) {
loc_F008FC08:
        if (iVar10 < 0) {
          uVar6 = 0xffffffff;
        }
        else if (bVar2) {
          uVar6 = -uVar6;
        }
        if (param_2 != (undefined4 *)0x0) {
          if (iVar10 != 0) {
            param_1 = pcVar9 + -1;
          }
          *param_2 = param_1;
        }
        if (param_3 != (uint *)0x0) {
          *param_3 = uVar6;
        }
        return CONCAT44(param_2,(uint)(0 < iVar10));
      }
      uVar5 = iVar7 - 0x37;
      if (0x19 < (iVar7 - 0x41U & 0xff)) {
        uVar5 = iVar7 - 0x57;
      }
    }
    if (iVar11 <= (int)uVar5) goto loc_F008FC08;
    if (iVar10 < 0) {
loc_F008FBE0:
      iVar10 = -1;
    }
    else if (uVar3 < uVar6) {
      iVar10 = -1;
    }
    else {
      iVar10 = 1;
      if ((uVar6 == uVar3) && (iVar4 < (int)uVar5)) goto loc_F008FBE0;
      .umul(uVar6,iVar11);
      uVar6 = uVar6 + uVar5;
    }
    iVar7 = (int)*pcVar9;
    pcVar9 = pcVar9 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3856 start=0xf008fc60 */

/* WARNING: Removing unreachable block (ram,0xf008fc88) */
/* WARNING: Removing unreachable block (ram,0xf008fc74) */

undefined8 -[KernDeviceDescription _isShared:](char *param_1,undefined4 param_2,undefined4 param_3)

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
  _sprintf((undefined *)((int)register0x00000038 + -0x90),aShareS,param_3);
  _objc_msgSend(param_1,paStringforkey,(undefined *)((int)register0x00000038 + -0x90));
  if (param_1 == (char *)0x0) {
    uVar1 = 0;
  }
  else if ((*param_1 == 'y') || (uVar1 = 0, *param_1 == 'Y')) {
    uVar1 = 1;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3857 start=0xf008fcc0 */

/* WARNING: Removing unreachable block (ram,0xf008fe34) */
/* WARNING: Removing unreachable block (ram,0xf008fe18) */
/* WARNING: Removing unreachable block (ram,0xf008fde0) */
/* WARNING: Removing unreachable block (ram,0xf008fd54) */
/* WARNING: Removing unreachable block (ram,0xf008fd14) */
/* WARNING: Removing unreachable block (ram,0xf008fd08) */
/* WARNING: Removing unreachable block (ram,0xf008fd38) */
/* WARNING: Removing unreachable block (ram,0xf008fd74) */
/* WARNING: Removing unreachable block (ram,0xf008fdf4) */
/* WARNING: Removing unreachable block (ram,0xf008fe28) */
/* WARNING: Removing unreachable block (ram,0xf008fcf0) */
/* WARNING: Removing unreachable block (ram,0xf008fcd4) */

undefined8
-[KernDeviceDescription _parseRangeResourceByKey:value:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined5 *puVar3;
  int iVar4;
  undefined (*pauVar5) [14];
  undefined *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined5 *puVar7;
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
  iVar1 = *(int *)(param_1 + 0x1c);
  _objc_msgSend(iVar1,paLookupresource,param_3);
  if (iVar1 == 0) {
    _printf(aSCouldnTLocate,param_3);
    puVar7 = (undefined5 *)0x0;
  }
  else {
    puVar7 = paList;
    _objc_msgSend(paList,paAlloc);
    _objc_msgSend();
    *(int *)((int)register0x00000038 + -0x14) = param_4;
    if (param_4 != 0) {
      _objc_msgSend(param_1,paIsshared,param_3);
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
      while (sub_F008FA58(iVar2,(undefined *)((int)register0x00000038 + -0x14),
                          (undefined *)((int)register0x00000038 + -0x18)), iVar2 != 0) {
        iVar2 = *(int *)((int)register0x00000038 + -0x14) + 1;
        *(int *)((int)register0x00000038 + -0x14) = iVar2;
        sub_F008FA58(iVar2,(undefined *)((int)register0x00000038 + -0x14),
                     (undefined *)((int)register0x00000038 + -0x1c));
        iVar4 = *(int *)((int)register0x00000038 + -0x18);
        if (iVar2 == 0) break;
        *(int *)((int)register0x00000038 + -0x30) = iVar4;
        iVar2 = (*(int *)((int)register0x00000038 + -0x1c) - iVar4) + 1;
        *(int *)((int)register0x00000038 + -0x2c) = iVar2;
        *(int *)((int)register0x00000038 + -0x28) = iVar4;
        *(int *)((int)register0x00000038 + -0x24) = iVar2;
        if ((char)param_1 == '\0') {
          *(int *)((int)register0x00000038 + -0x38) = iVar4;
          *(int *)((int)register0x00000038 + -0x34) = iVar2;
          puVar6 = (undefined *)((int)register0x00000038 + -0x38);
          pauVar5 = paReserverange;
        }
        else {
          *(int *)((int)register0x00000038 + -0x30) = iVar4;
          *(int *)((int)register0x00000038 + -0x2c) = iVar2;
          puVar6 = (undefined *)((int)register0x00000038 + -0x30);
          pauVar5 = (undefined (*) [14])paSharerange;
        }
        iVar2 = iVar1;
        _objc_msgSend(iVar1,pauVar5,puVar6);
        puVar3 = puVar7;
        _objc_msgSend(puVar7,paAddobject,iVar2);
        if (puVar3 == (undefined5 *)0x0) {
          _printf(aSCouldnTReserv,param_3,*(undefined4 *)((int)register0x00000038 + -0x18),
                  *(undefined4 *)((int)register0x00000038 + -0x1c));
          _objc_msgSend(puVar7,paFreeobjects);
          _objc_msgSend();
          break;
        }
        iVar2 = *(int *)((int)register0x00000038 + -0x14);
      }
    }
  }
  return CONCAT44(param_2,puVar7);
}
/* GHIDRADEC_FUNCTION index=3858 start=0xf008fe48 */

/* WARNING: Removing unreachable block (ram,0xf008ff58) */
/* WARNING: Removing unreachable block (ram,0xf008ff3c) */
/* WARNING: Removing unreachable block (ram,0xf008ff08) */
/* WARNING: Removing unreachable block (ram,0xf008fec0) */
/* WARNING: Removing unreachable block (ram,0xf008fe90) */
/* WARNING: Removing unreachable block (ram,0xf008fe9c) */
/* WARNING: Removing unreachable block (ram,0xf008fed8) */
/* WARNING: Removing unreachable block (ram,0xf008ff1c) */
/* WARNING: Removing unreachable block (ram,0xf008ff4c) */
/* WARNING: Removing unreachable block (ram,0xf008fe78) */
/* WARNING: Removing unreachable block (ram,0xf008fe5c) */

undefined8
-[KernDeviceDescription _parseItemResourceByKey:value:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined (*pauVar4) [13];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  iVar1 = *(int *)(param_1 + 0x1c);
  _objc_msgSend(iVar1,paLookupresource,param_3);
  if (iVar1 == 0) {
    _printf(aSCouldnTLocate_0,param_3);
    iVar5 = 0;
  }
  else {
    iVar5 = paList;
    _objc_msgSend(paList,paAlloc);
    _objc_msgSend();
    *(int *)((int)register0x00000038 + -0x14) = param_4;
    if (param_4 != 0) {
      _objc_msgSend(param_1,paIsshared,param_3);
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
      while( true ) {
        sub_F008FA58(iVar2,(undefined *)((int)register0x00000038 + -0x14),
                     (undefined *)((int)register0x00000038 + -0x18));
        if (iVar2 == 0) break;
        pauVar4 = (undefined (*) [13])paShareitem;
        if ((char)param_1 == '\0') {
          pauVar4 = paReserveitem;
        }
        iVar2 = iVar1;
        _objc_msgSend(iVar1,pauVar4,*(undefined4 *)((int)register0x00000038 + -0x18));
        iVar3 = iVar5;
        _objc_msgSend(iVar5,paAddobject,iVar2);
        if (iVar3 == 0) {
          _printf(aSCouldnTReserv_0,param_3,*(undefined4 *)((int)register0x00000038 + -0x18));
          _objc_msgSend(iVar5,paFreeobjects);
          _objc_msgSend();
          break;
        }
        iVar2 = *(int *)((int)register0x00000038 + -0x14);
      }
    }
  }
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=3859 start=0xf008ff6c */

/* WARNING: Removing unreachable block (ram,0xf008ff70) */

undefined8 sub_F008FF6C(undefined4 param_1,undefined4 param_2)

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
  _IOMalloc(param_1);
  return CONCAT44(param_2,param_1);
}

