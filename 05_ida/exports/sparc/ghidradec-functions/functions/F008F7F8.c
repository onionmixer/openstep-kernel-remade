
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

