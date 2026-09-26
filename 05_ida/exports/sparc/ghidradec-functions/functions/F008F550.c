
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
