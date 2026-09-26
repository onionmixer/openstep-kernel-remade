/* GHIDRADEC_FUNCTION index=3850 start=0xf008f464 */

/* WARNING: Removing unreachable block (ram,0xf008f4b4) */
/* WARNING: Removing unreachable block (ram,0xf008f488) */
/* WARNING: Removing unreachable block (ram,0xf008f4d0) */
/* WARNING: Removing unreachable block (ram,0xf008f474) */

undefined8
-[KernDeviceDescription allocateResourcesForKey:](int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined (*pauVar3) [32];
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
  iVar1 = param_1;
  _objc_msgSend(param_1,paStringforkey,param_3);
  if (iVar1 != 0) {
    iVar2 = iVar1;
    _strchr(iVar1,0x2d);
    pauVar3 = (undefined (*) [32])paParseitemresou;
    if (iVar2 != 0) {
      pauVar3 = paParserangereso;
    }
    iVar2 = param_1;
    _objc_msgSend(param_1,pauVar3,param_3,iVar1);
    if (iVar2 == 0) {
      param_1 = 0;
    }
    else {
      _objc_msgSend(param_1,paSetresourcesFo,iVar2,param_3);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3851 start=0xf008f4e8 */

/* WARNING: Removing unreachable block (ram,0xf008f51c) */
/* WARNING: Removing unreachable block (ram,0xf008f528) */
/* WARNING: Removing unreachable block (ram,0xf008f504) */

undefined8 sub_F008F4E8(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
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
  uVar2 = 0;
  do {
    uVar3 = param_1;
    _objc_msgSend(param_1,paCount_0);
    if (uVar3 <= uVar2) {
      uVar3 = 0;
      break;
    }
    uVar3 = param_1;
    _objc_msgSend(param_1,paObjectat,uVar2);
    uVar1 = uVar3;
    _objc_msgSend();
    uVar2 = uVar2 + 1;
  } while (uVar1 != param_2);
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3852 start=0xf008f550 */

/* WARNING: Removing unreachable block (ram,0xf008f6cc) */
/* WARNING: Removing unreachable block (ram,0xf008f724) */
/* WARNING: Removing unreachable block (ram,0xf008f6fc) */
/* WARNING: Removing unreachable block (ram,0xf008f670) */
/* WARNING: Removing unreachable block (ram,0xf008f748) */
/* WARNING: Removing unreachable block (ram,0xf008f660) */
/* WARNING: Removing unreachable block (ram,0xf008f614) */
/* WARNING: Removing unreachable block (ram,0xf008f5c4) */
/* WARNING: Removing unreachable block (ram,0xf008f5ac) */
/* WARNING: Removing unreachable block (ram,0xf008f578) */
/* WARNING: Removing unreachable block (ram,0xf008f598) */
/* WARNING: Removing unreachable block (ram,0xf008f5bc) */
/* WARNING: Removing unreachable block (ram,0xf008f5ec) */
/* WARNING: Removing unreachable block (ram,0xf008f644) */
/* WARNING: Removing unreachable block (ram,0xf008f738) */
/* WARNING: Removing unreachable block (ram,0xf008f754) */
/* WARNING: Removing unreachable block (ram,0xf008f6a0) */
/* WARNING: Removing unreachable block (ram,0xf008f714) */
/* WARNING: Removing unreachable block (ram,0xf008f6b8) */
/* WARNING: Removing unreachable block (ram,0xf008f6e4) */
/* WARNING: Removing unreachable block (ram,0xf008f560) */

undefined8
-[KernDeviceDescription allocateItems:numItems:forKey:]
          (uint param_1,undefined4 param_2,undefined4 *param_3,uint param_4,undefined4 param_5)

{
  undefined6 *puVar1;
  undefined (*pauVar2) [11];
  uint uVar3;
  undefined5 *puVar4;
  undefined5 *puVar5;
  uint uVar6;
  undefined5 *puVar7;
  undefined (*pauVar8) [13];
  undefined (*pauVar9) [11];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar10;
  uint uVar11;
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
  uVar11 = param_1;
  _objc_msgSend(param_1,paIsshared,param_5);
  uVar3 = param_1;
  _objc_msgSend(param_1,paResourcesforke,param_5);
  puVar5 = paList;
  puVar1 = paAlloc;
  puVar4 = paList;
  _objc_msgSend(paList,paAlloc);
  uVar10 = 0;
  _objc_msgSend();
  _objc_msgSend(puVar5,puVar1);
  _objc_msgSend();
  pauVar2 = paAddobject;
  if (param_4 != 0) {
    do {
      uVar6 = uVar3;
      sub_F008F4E8(uVar3,*param_3);
      pauVar9 = paAddobject;
      if (uVar6 == 0) {
        uVar6 = *(uint *)(param_1 + 0x1c);
        _objc_msgSend(uVar6,paLookupresource,param_5);
        if (uVar6 != 0) {
          pauVar8 = paReserveitem;
          if ((char)uVar11 != '\0') {
            pauVar8 = (undefined (*) [13])paShareitem;
          }
          _objc_msgSend(uVar6,pauVar8,*param_3);
          if (uVar6 != 0) {
            _objc_msgSend(puVar5,pauVar2,uVar6);
            pauVar9 = pauVar2;
            goto loc_F008F670;
          }
        }
        _objc_msgSend(puVar5,paFreeobjects);
        puVar5 = paFree;
        _objc_msgSend();
        _objc_msgSend(puVar4,puVar5);
        param_1 = 0;
        goto locret_F008F760;
      }
loc_F008F670:
      _objc_msgSend(puVar4,pauVar9,uVar6);
      uVar10 = uVar10 + 1;
      param_3 = param_3 + 1;
    } while (uVar10 < param_4);
  }
  uVar11 = 0;
  while (uVar10 = uVar3, _objc_msgSend(uVar3,paCount_0), uVar11 < uVar10) {
    uVar10 = uVar3;
    _objc_msgSend(uVar3,paObjectat,uVar11);
    puVar7 = puVar4;
    _objc_msgSend(puVar4,paIndexof,uVar10);
    if (puVar7 == (undefined5 *)0xffffffff) {
      _objc_msgSend(uVar10,paFree);
      uVar11 = uVar11 + 1;
    }
    else {
      uVar11 = uVar11 + 1;
    }
  }
  _objc_msgSend(uVar3,paEmpty);
  _objc_msgSend(param_1,paSetresourcesFo,puVar4,param_5);
  _objc_msgSend(puVar5,paFree);
locret_F008F760:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3853 start=0xf008f768 */

/* WARNING: Removing unreachable block (ram,0xf008f7a0) */
/* WARNING: Removing unreachable block (ram,0xf008f7b4) */
/* WARNING: Removing unreachable block (ram,0xf008f788) */

sqword sub_F008F768(int param_1,uint param_2)

{
  code *pcVar1;
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
  iVar2 = param_1;
  _objc_msgSend(param_1,paCount_0);
  if (iVar2 != 0) {
    _objc_msgSend(param_1,paObjectat,0);
    _objc_msgSend((undefined *)((int)register0x00000038 + -0x10));
                    /* WARNING: Does not return */
    pcVar1 = (code *)IllegalInstructionTrap(8);
    (*pcVar1)();
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3854 start=0xf008f7f8 */

/* WARNING: Removing unreachable block (ram,0xf008f9bc) */
/* WARNING: Removing unreachable block (ram,0xf008fa14) */
/* WARNING: Removing unreachable block (ram,0xf008f9ec) */
/* WARNING: Removing unreachable block (ram,0xf008f960) */
/* WARNING: Removing unreachable block (ram,0xf008fa38) */
/* WARNING: Removing unreachable block (ram,0xf008f950) */
/* WARNING: Removing unreachable block (ram,0xf008f8d8) */
/* WARNING: Removing unreachable block (ram,0xf008f86c) */
/* WARNING: Removing unreachable block (ram,0xf008f854) */
/* WARNING: Removing unreachable block (ram,0xf008f820) */
/* WARNING: Removing unreachable block (ram,0xf008f840) */
/* WARNING: Removing unreachable block (ram,0xf008f864) */
/* WARNING: Removing unreachable block (ram,0xf008f8b0) */
/* WARNING: Removing unreachable block (ram,0xf008f934) */
/* WARNING: Removing unreachable block (ram,0xf008fa28) */
/* WARNING: Removing unreachable block (ram,0xf008fa44) */
/* WARNING: Removing unreachable block (ram,0xf008f990) */
/* WARNING: Removing unreachable block (ram,0xf008fa04) */
/* WARNING: Removing unreachable block (ram,0xf008f9a8) */
/* WARNING: Removing unreachable block (ram,0xf008f9d4) */
/* WARNING: Removing unreachable block (ram,0xf008f808) */

undefined8
-[KernDeviceDescription allocateRanges:numRanges:forKey:]
          (uint param_1,int param_2,undefined4 *param_3,uint param_4,undefined4 param_5)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined (*pauVar6) [14];
  undefined4 uVar7;
  undefined *puVar8;
  undefined4 uVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar10;
  uint uVar11;
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
  uVar11 = param_1;
  _objc_msgSend(param_1,paIsshared,param_5);
  uVar2 = param_1;
  _objc_msgSend(param_1,paResourcesforke,param_5);
  iVar4 = paList;
  uVar1 = paAlloc;
  iVar3 = paList;
  _objc_msgSend(paList,paAlloc);
  uVar10 = 0;
  _objc_msgSend();
  _objc_msgSend(iVar4,uVar1);
  _objc_msgSend();
  uVar1 = paAddobject;
  if (param_4 != 0) {
    param_2 = (int)(char)uVar11;
    do {
      uVar9 = *param_3;
      *(undefined4 *)((int)register0x00000038 + -0x18) = uVar9;
      uVar7 = param_3[1];
      *(undefined4 *)((int)register0x00000038 + -0x14) = uVar7;
      *(undefined4 *)((int)register0x00000038 + -0x20) = uVar9;
      *(undefined4 *)((int)register0x00000038 + -0x1c) = uVar7;
      uVar11 = uVar2;
      sub_F008F768(uVar2,(undefined *)((int)register0x00000038 + -0x20));
      uVar7 = paAddobject;
      if (uVar11 == 0) {
        uVar11 = *(uint *)(param_1 + 0x1c);
        _objc_msgSend(uVar11,paLookupresource,param_5);
        if (uVar11 != 0) {
          if (param_2 == 0) {
            puVar8 = (undefined *)((int)register0x00000038 + -0x28);
            *(undefined4 *)((int)register0x00000038 + -0x28) =
                 *(undefined4 *)((int)register0x00000038 + -0x18);
            *(undefined4 *)((int)register0x00000038 + -0x24) =
                 *(undefined4 *)((int)register0x00000038 + -0x14);
            pauVar6 = paReserverange;
          }
          else {
            *(undefined4 *)((int)register0x00000038 + -0x20) =
                 *(undefined4 *)((int)register0x00000038 + -0x18);
            *(undefined4 *)((int)register0x00000038 + -0x1c) =
                 *(undefined4 *)((int)register0x00000038 + -0x14);
            pauVar6 = (undefined (*) [14])paSharerange;
            puVar8 = (undefined *)((int)register0x00000038 + -0x20);
          }
          _objc_msgSend(uVar11,pauVar6,puVar8);
          if (uVar11 != 0) {
            _objc_msgSend(iVar4,uVar1,uVar11);
            uVar7 = uVar1;
            goto loc_F008F960;
          }
        }
        _objc_msgSend(iVar4,paFreeobjects);
        uVar1 = paFree;
        _objc_msgSend();
        _objc_msgSend(iVar3,uVar1);
        param_1 = 0;
        goto locret_F008FA50;
      }
loc_F008F960:
      _objc_msgSend(iVar3,uVar7,uVar11);
      uVar10 = uVar10 + 1;
      param_3 = param_3 + 2;
    } while (uVar10 < param_4);
  }
  uVar11 = 0;
  while (uVar10 = uVar2, _objc_msgSend(uVar2,paCount_0), uVar11 < uVar10) {
    uVar10 = uVar2;
    _objc_msgSend(uVar2,paObjectat,uVar11);
    iVar5 = iVar3;
    _objc_msgSend(iVar3,paIndexof,uVar10);
    if (iVar5 == -1) {
      _objc_msgSend(uVar10,paFree);
      uVar11 = uVar11 + 1;
    }
    else {
      uVar11 = uVar11 + 1;
    }
  }
  _objc_msgSend(uVar2,paEmpty);
  _objc_msgSend(param_1,paSetresourcesFo,iVar3,param_5);
  _objc_msgSend(iVar4,paFree);
locret_F008FA50:
  return CONCAT44(param_2,param_1);
}

