
/* WARNING: Removing unreachable block (ram,0xf00910cc) */
/* WARNING: Removing unreachable block (ram,0xf009107c) */
/* WARNING: Removing unreachable block (ram,0xf0091044) */
/* WARNING: Removing unreachable block (ram,0xf0090ff4) */
/* WARNING: Removing unreachable block (ram,0xf0091008) */
/* WARNING: Removing unreachable block (ram,0xf0091050) */
/* WARNING: Removing unreachable block (ram,0xf0091090) */
/* WARNING: Removing unreachable block (ram,0xf00910dc) */
/* WARNING: Removing unreachable block (ram,0xf0090fdc) */

undefined8
_kern_IOGetDeviceConfig(int param_1,int param_2,int *param_3,undefined4 param_4,int *param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
  int iVar7;
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
  if (param_1 == 0) {
    uVar6 = 0xfffffd3f;
  }
  else {
    _objc_msgSend(param_1,paDevicedescript_1);
    iVar5 = param_1;
    _objc_msgSend();
    iVar4 = iVar5;
    _objc_msgSend(iVar5,paCount_0);
    if (0x80 < iVar4) {
      iVar4 = 0x80;
    }
    iVar7 = 0;
    if (iVar4 < 1) {
      *param_3 = iVar4;
    }
    else {
      iVar3 = 0;
      do {
        iVar2 = iVar5;
        _objc_msgSend(iVar5,paObjectat,iVar7);
        iVar7 = iVar7 + 1;
        _objc_msgSend();
        *(int *)(iVar3 + param_2) = iVar2;
        iVar3 = iVar3 + 4;
      } while (iVar7 < iVar4);
      *param_3 = iVar4;
    }
    _objc_msgSend(param_1,paResourcesforke,aMemoryMaps_2);
    iVar5 = param_1;
    _objc_msgSend(param_1,paCount_0);
    if (0x10 < iVar5) {
      iVar5 = 0x10;
    }
    uVar6 = 0;
    if (0 < iVar5) {
      _objc_msgSend(param_1,paObjectat,0);
      _objc_msgSend((undefined *)((int)register0x00000038 + -0x10));
                    /* WARNING: Does not return */
      pcVar1 = (code *)IllegalInstructionTrap(8);
      (*pcVar1)();
    }
    *param_5 = iVar5;
  }
  return CONCAT44(param_2,uVar6);
}

