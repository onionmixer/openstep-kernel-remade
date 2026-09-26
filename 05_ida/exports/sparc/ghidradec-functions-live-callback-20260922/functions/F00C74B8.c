
/* WARNING: Removing unreachable block (ram,0xf00c7550) */
/* WARNING: Removing unreachable block (ram,0xf00c7674) */
/* WARNING: Removing unreachable block (ram,0xf00c760c) */
/* WARNING: Removing unreachable block (ram,0xf00c75e0) */
/* WARNING: Removing unreachable block (ram,0xf00c75ac) */
/* WARNING: Removing unreachable block (ram,0xf00c7510) */
/* WARNING: Removing unreachable block (ram,0xf00c74e4) */
/* WARNING: Removing unreachable block (ram,0xf00c74f8) */
/* WARNING: Removing unreachable block (ram,0xf00c7570) */
/* WARNING: Removing unreachable block (ram,0xf00c75b8) */
/* WARNING: Removing unreachable block (ram,0xf00c75ec) */
/* WARNING: Removing unreachable block (ram,0xf00c7634) */
/* WARNING: Removing unreachable block (ram,0xf00c7694) */
/* WARNING: Removing unreachable block (ram,0xf00c7560) */
/* WARNING: Removing unreachable block (ram,0xf00c74d0) */

undefined8 -[IODiskPartition readLabel:](uint param_1,uint param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar9;
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
  uVar2 = param_1;
  _objc_msgSend(param_1,paPhysicaldisk_0);
  uVar3 = param_1;
  _objc_msgSend(param_1,paPhysicalblocks_0);
  uVar4 = param_1;
  _objc_msgSend(param_1,paName);
  uVar9 = uVar2;
  _objc_msgSend(uVar2,paIsdiskready,1);
  if (uVar9 == 0xfffffbb2) {
    uVar9 = 0xfffffbb2;
  }
  else if (uVar9 == 0) {
    uVar4 = uVar2;
    _objc_msgSend(uVar2,paIsformatted);
    if ((uVar3 == 0) || ((char)uVar4 == '\0')) {
      uVar9 = 0xfffffbb3;
    }
    else {
      uVar5 = uVar3 + 0x1c47;
      udiv(uVar5,uVar3);
      uVar3 = uVar5;
      umul();
      iVar8 = 0;
      iVar7 = 0;
      param_2 = uVar3 + _page_mask & ~_page_mask;
      uVar4 = param_2;
      _IOMalloc();
      uVar6 = uVar4;
      do {
        _IOVmTaskSelf();
        uVar9 = uVar2;
        _objc_msgSend(uVar2,paReadatLengthBu,iVar7,uVar3,uVar4,
                      (undefined *)((int)register0x00000038 + -0x14),uVar6);
        uVar6 = uVar9;
        if (((uVar9 == 0) && (uVar6 = *(uint *)((int)register0x00000038 + -0x14), uVar6 == uVar3))
           && (uVar6 = uVar4, _check_label(uVar4,iVar7), uVar6 == 0)) {
          bVar1 = true;
          break;
        }
        bVar1 = false;
        if (uVar9 == 0xfffffbb2) break;
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + uVar5;
        bVar1 = false;
      } while (iVar8 < 4);
      if (bVar1) {
        *(undefined *)(param_1 + 0x1a8) = 1;
        _get_disk_label(uVar4,param_3);
        uVar9 = 0;
      }
      else if (uVar9 != 0xfffffbb2) {
        uVar9 = 0xfffffbb4;
      }
      _IOFree(uVar4,param_2);
    }
  }
  else {
    _objc_msgSend(param_1,paStringfromretu,uVar9);
    _IOLog(aSReadlabelBogu,uVar4,param_1);
  }
  return CONCAT44(param_2,uVar9);
}

