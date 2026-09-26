
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
  undefined6 *puVar1;
  undefined (*pauVar2) [11];
  uint uVar3;
  undefined5 *puVar4;
  undefined5 *puVar5;
  undefined5 *puVar6;
  undefined (*pauVar7) [14];
  undefined (*pauVar8) [11];
  undefined4 uVar9;
  undefined *puVar10;
  undefined4 uVar11;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar12;
  uint uVar13;
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
  uVar13 = param_1;
  _objc_msgSend(param_1,paIsshared,param_5);
  uVar3 = param_1;
  _objc_msgSend(param_1,paResourcesforke,param_5);
  puVar5 = paList;
  puVar1 = paAlloc;
  puVar4 = paList;
  _objc_msgSend(paList,paAlloc);
  uVar12 = 0;
  _objc_msgSend();
  _objc_msgSend(puVar5,puVar1);
  _objc_msgSend();
  pauVar2 = paAddobject;
  if (param_4 != 0) {
    param_2 = (int)(char)uVar13;
    do {
      uVar11 = *param_3;
      *(undefined4 *)((int)register0x00000038 + -0x18) = uVar11;
      uVar9 = param_3[1];
      *(undefined4 *)((int)register0x00000038 + -0x14) = uVar9;
      *(undefined4 *)((int)register0x00000038 + -0x20) = uVar11;
      *(undefined4 *)((int)register0x00000038 + -0x1c) = uVar9;
      uVar13 = uVar3;
      sub_F008F768(uVar3,(undefined *)((int)register0x00000038 + -0x20));
      pauVar8 = paAddobject;
      if (uVar13 == 0) {
        uVar13 = *(uint *)(param_1 + 0x1c);
        _objc_msgSend(uVar13,paLookupresource,param_5);
        if (uVar13 != 0) {
          if (param_2 == 0) {
            puVar10 = (undefined *)((int)register0x00000038 + -0x28);
            *(undefined4 *)((int)register0x00000038 + -0x28) =
                 *(undefined4 *)((int)register0x00000038 + -0x18);
            *(undefined4 *)((int)register0x00000038 + -0x24) =
                 *(undefined4 *)((int)register0x00000038 + -0x14);
            pauVar7 = paReserverange;
          }
          else {
            *(undefined4 *)((int)register0x00000038 + -0x20) =
                 *(undefined4 *)((int)register0x00000038 + -0x18);
            *(undefined4 *)((int)register0x00000038 + -0x1c) =
                 *(undefined4 *)((int)register0x00000038 + -0x14);
            pauVar7 = (undefined (*) [14])paSharerange;
            puVar10 = (undefined *)((int)register0x00000038 + -0x20);
          }
          _objc_msgSend(uVar13,pauVar7,puVar10);
          if (uVar13 != 0) {
            _objc_msgSend(puVar5,pauVar2,uVar13);
            pauVar8 = pauVar2;
            goto loc_F008F960;
          }
        }
        _objc_msgSend(puVar5,paFreeobjects);
        puVar5 = paFree;
        _objc_msgSend();
        _objc_msgSend(puVar4,puVar5);
        param_1 = 0;
        goto locret_F008FA50;
      }
loc_F008F960:
      _objc_msgSend(puVar4,pauVar8,uVar13);
      uVar12 = uVar12 + 1;
      param_3 = param_3 + 2;
    } while (uVar12 < param_4);
  }
  uVar13 = 0;
  while (uVar12 = uVar3, _objc_msgSend(uVar3,paCount_0), uVar13 < uVar12) {
    uVar12 = uVar3;
    _objc_msgSend(uVar3,paObjectat,uVar13);
    puVar6 = puVar4;
    _objc_msgSend(puVar4,paIndexof,uVar12);
    if (puVar6 == (undefined5 *)0xffffffff) {
      _objc_msgSend(uVar12,paFree);
      uVar13 = uVar13 + 1;
    }
    else {
      uVar13 = uVar13 + 1;
    }
  }
  _objc_msgSend(uVar3,paEmpty);
  _objc_msgSend(param_1,paSetresourcesFo,puVar4,param_5);
  _objc_msgSend(puVar5,paFree);
locret_F008FA50:
  return CONCAT44(param_2,param_1);
}

